//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.114
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sat Apr 12 17:48:33 2025
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
  static const char_T ParameterNameStr[18] = "DOUBLET_MAX_ANGLE";
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
void FLIGHT_hexacopter_ReadParameter(DW_ReadParameter_FLIGHT_hexac_T *localDW)
{
  real32_T ParamStep;

  // MATLABSystem: '<S18>/Read Parameter'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);

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
void FLIGHT_hex_ReadParameter_e_Init(DW_ReadParameter_FLIGHT_hex_f_T *localDW)
{
  static const char_T ParameterNameStr[14] = "MPC_THR_HOVER";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter'
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

  // End of Start for MATLABSystem: '<S19>/Read Parameter'
}

// Output and update for atomic system:
void FLIGHT_hexacopt_ReadParameter_p(B_ReadParameter_FLIGHT_hexa_c_T *localB,
  DW_ReadParameter_FLIGHT_hex_f_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter'
}

// Termination for atomic system:
void FLIGHT_hex_ReadParameter_a_Term(DW_ReadParameter_FLIGHT_hex_f_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter'
}

// System initialize for atomic system:
void FLIGHT_hexa_ReadParameter1_Init(DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_P_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter1'
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

  // End of Start for MATLABSystem: '<S19>/Read Parameter1'
}

// Output and update for atomic system:
void FLIGHT_hexacopte_ReadParameter1(B_ReadParameter1_FLIGHT_hexac_T *localB,
  DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter1'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter1'
}

// Termination for atomic system:
void FLIGHT_hexa_ReadParameter1_Term(DW_ReadParameter1_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter1'
}

// System initialize for atomic system:
void FLIGHT_hexa_ReadParameter2_Init(DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_I_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter2'
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

  // End of Start for MATLABSystem: '<S19>/Read Parameter2'
}

// Output and update for atomic system:
void FLIGHT_hexacopte_ReadParameter2(B_ReadParameter2_FLIGHT_hexac_T *localB,
  DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter2'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter2'
}

// Termination for atomic system:
void FLIGHT_hexa_ReadParameter2_Term(DW_ReadParameter2_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter2'
}

// System initialize for atomic system:
void FLIGHT_hexa_ReadParameter3_Init(DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MPC_Z_VEL_D_ACC";
  real_T tmp;

  // Start for MATLABSystem: '<S19>/Read Parameter3'
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

  // End of Start for MATLABSystem: '<S19>/Read Parameter3'
}

// Output and update for atomic system:
void FLIGHT_hexacopte_ReadParameter3(B_ReadParameter3_FLIGHT_hexac_T *localB,
  DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S19>/Read Parameter3'
  if (localDW->obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
    localDW->obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
  }

  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter3_o1);
  if (b_varargout_2) {
    localB->ReadParameter3_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S19>/Read Parameter3'
}

// Termination for atomic system:
void FLIGHT_hexa_ReadParameter3_Term(DW_ReadParameter3_FLIGHT_hexa_T *localDW)
{
  // Terminate for MATLABSystem: '<S19>/Read Parameter3'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter3'
}

// System initialize for atomic system:
void FLIGHT_hexaco_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW)
{
  // Start for MATLABSystem: '<S11>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_hexacopter_PX4Timestamp(B_PX4Timestamp_FLIGHT_hexacop_T *localB)
{
  // MATLABSystem: '<S11>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void FLIGHT_hexaco_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW)
{
  // Terminate for MATLABSystem: '<S11>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/PX4 Timestamp'
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
  int32_T ParamStep;
  int32_T i;
  real32_T rtb_IProdOut_c;
  real32_T rtb_IProdOut_p;
  real32_T rtb_NProdOut_a;
  real32_T rtb_NProdOut_g;
  real32_T rtb_Saturation3;
  real32_T rtb_SinCos_o1;
  real32_T rtb_SinCos_o2;
  real32_T tmp_2;
  uint32_T tmp;
  uint16_T Output_Limits1;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T b_varargout_1;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_a;

  // MATLABSystem: '<S413>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_p2.eventStructObj, &FLIGHT_hexacopter_B.r2, false,
    5000.0);

  // Outputs for Enabled SubSystem: '<S413>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S414>/Enable'

  // Start for MATLABSystem: '<S413>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S414>/In1'
    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_B.r2;
  }

  // End of Outputs for SubSystem: '<S413>/Enabled Subsystem'

  // RelationalOperator: '<S412>/Compare' incorporates:
  //   Constant: '<S412>/Constant'
  //   SignalConversion generated from: '<S411>/Bus Selector'

  rtb_Compare = (FLIGHT_hexacopter_B.In1_n.values[4] >=
                 FLIGHT_hexacopter_P.CompareToConstant3_const);

  // MATLABSystem: '<S403>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_kk.eventStructObj, &FLIGHT_hexacopter_B.r, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S403>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S406>/Enable'

  // Start for MATLABSystem: '<S403>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S406>/In1'
    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_B.r;
  }

  // End of Outputs for SubSystem: '<S403>/Enabled Subsystem'

  // If: '<Root>/If' incorporates:
  //   Constant: '<S17>/Constant'
  //   Constant: '<S568>/Constant'
  //   RelationalOperator: '<S17>/Compare'
  //   RelationalOperator: '<S568>/Compare'
  //   SignalConversion generated from: '<S411>/Bus Selector'

  if ((FLIGHT_hexacopter_B.In1_n.values[5] > 1400) &&
      (FLIGHT_hexacopter_B.In1_n.values[5] < 1800)) {
    // Outputs for IfAction SubSystem: '<Root>/Altitude_Mode' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S18>/Enable'

    if (FLIGHT_hexacopter_P.CompareToConstant_const <= 0.0F) {
      // FromWorkspace: '<S21>/fromWS_Signal 1'
      {
        real_T t = ((FLIGHT_hexacopter_M->Timing.clockTick0) * 0.0025);
        real_T *pTimeValues = static_cast<real_T *>
          (FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK_i.TimePtr);
        real_T *pDataValues = static_cast<real_T *>
          (FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK_i.DataPtr);
        if (t < pTimeValues[0]) {
          FLIGHT_hexacopter_B.Signal_a = 0.0;
        } else if (t == pTimeValues[7]) {
          FLIGHT_hexacopter_B.Signal_a = pDataValues[7];
        } else if (t > pTimeValues[7]) {
          FLIGHT_hexacopter_B.Signal_a = 0.0;
        } else {
          int_T currTimeIndex =
            FLIGHT_hexacopter_DW.fromWS_Signal1_IWORK_n.PrevIndex;
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }

          FLIGHT_hexacopter_B.Signal_a = pDataValues[currTimeIndex];
          FLIGHT_hexacopter_DW.fromWS_Signal1_IWORK_n.PrevIndex = currTimeIndex;
        }
      }

      // Product: '<S18>/Product' incorporates:
      //   Constant: '<S18>/Constant'
      //   Gain: '<S20>/Gain1'

      FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Gain1_Gain_d *
        FLIGHT_hexacopter_P.Constant_Value_h * FLIGHT_hexacopter_B.Signal_a;

      // Sum: '<S22>/Sum' incorporates:
      //   Gain: '<S22>/Gain'
      //   Sum: '<S22>/Diff'
      //   UnitDelay: '<S22>/UD'
      //
      //  Block description for '<S22>/Sum':
      //
      //   Add in CPU
      //
      //  Block description for '<S22>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S22>/UD':
      //
      //   Store in Global RAM

      FLIGHT_hexacopter_DW.UD_DSTATE_j = (FLIGHT_hexacopter_DW.UD_DSTATE_j -
        FLIGHT_hexacopter_B.Product_k) *
        FLIGHT_hexacopter_P.TransferFcnFirstOrder_PoleZ +
        FLIGHT_hexacopter_B.Product_k;
      FLIGHT_hexacopter_ReadParameter(&FLIGHT_hexacopter_DW.ReadParameter_p);

      // Switch: '<S1>/Switch' incorporates:
      //   Merge: '<Root>/Merge1'
      //   UnitDelay: '<S22>/UD'
      //
      //  Block description for '<S22>/UD':
      //
      //   Store in Global RAM

      FLIGHT_hexacopter_B.Merge1[0] = static_cast<real32_T>
        (FLIGHT_hexacopter_DW.UD_DSTATE_j);
    } else {
      // Fcn: '<S16>/Fcn2' incorporates:
      //   DataTypeConversion: '<S16>/Data Type Conversion1'
      //   Switch: '<S1>/Switch'

      rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values
        [0]) - 1514.0F) / 500.0F;

      // DeadZone: '<S16>/Dead Zone3' incorporates:
      //   Switch: '<S1>/Switch'

      if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone3_End) {
        rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone3_End;
      } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone3_Start) {
        rtb_Saturation3 = 0.0F;
      } else {
        rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone3_Start;
      }

      // End of DeadZone: '<S16>/Dead Zone3'

      // Saturate: '<S16>/Saturation9' incorporates:
      //   Switch: '<S1>/Switch'

      if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation9_UpperSat) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation9_UpperSat;
      } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation9_LowerSat) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation9_LowerSat;
      }

      // Switch: '<S1>/Switch' incorporates:
      //   Gain: '<S16>/Gain1'
      //   Merge: '<Root>/Merge1'
      //   Saturate: '<S16>/Saturation9'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL
        * rtb_Saturation3;
    }

    // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'

    // Fcn: '<S16>/Fcn7' incorporates:
    //   Constant: '<S17>/Constant'
    //   DataTypeConversion: '<S16>/Data Type Conversion10'
    //   RelationalOperator: '<S17>/Compare'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[3])
                       - 1514.0F) / 500.0F;

    // DeadZone: '<S16>/Dead Zone2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone2_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone2_Start) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone2_Start;
    }

    // End of DeadZone: '<S16>/Dead Zone2'

    // Saturate: '<S16>/Saturation3'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation3_UpperSat) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation3_UpperSat;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation3_LowerSat) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation3_LowerSat;
    }

    // SignalConversion generated from: '<S1>/des_r' incorporates:
    //   Gain: '<S16>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S16>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * rtb_Saturation3;

    // Fcn: '<S16>/Fcn3' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion11'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[2])
                       - 1514.0F) / 500.0F;

    // DeadZone: '<S16>/Dead Zone4'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone4_End) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone4_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone4_Start) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone4_Start;
    }

    // End of DeadZone: '<S16>/Dead Zone4'

    // Saturate: '<S16>/Saturation10'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation10_UpperSat) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation10_UpperSat;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation10_LowerSat) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation10_LowerSat;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Saturate: '<S16>/Saturation10'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_P.Gain_Gain_e *
      rtb_Saturation3;

    // Outputs for Enabled SubSystem: '<S1>/Vz Controller' incorporates:
    //   EnablePort: '<S19>/Enable'

    if (rtb_Compare) {
      // Gain: '<S19>/Gain' incorporates:
      //   Sum: '<S19>/Sum3'

      rtb_IProdOut_p = (FLIGHT_hexacopter_B.Merge - FLIGHT_hexacopter_B.In1.vz) *
        FLIGHT_hexacopter_P.Gain_Gain_d;
      FLIGHT_hexacopte_ReadParameter3(&FLIGHT_hexacopter_B.ReadParameter3_p,
        &FLIGHT_hexacopter_DW.ReadParameter3_p);

      // Product: '<S62>/NProd Out' incorporates:
      //   Constant: '<S19>/Constant'
      //   DiscreteIntegrator: '<S54>/Filter'
      //   Product: '<S52>/DProd Out'
      //   Sum: '<S54>/SumD'

      rtb_SinCos_o1 = (rtb_IProdOut_p *
                       FLIGHT_hexacopter_B.ReadParameter3_p.ReadParameter3_o1 -
                       FLIGHT_hexacopter_DW.Filter_DSTATE_i) *
        FLIGHT_hexacopter_P.Constant_Value_bi;
      FLIGHT_hexacopte_ReadParameter1(&FLIGHT_hexacopter_B.ReadParameter1_pn,
        &FLIGHT_hexacopter_DW.ReadParameter1_pn);

      // Sum: '<S68>/Sum' incorporates:
      //   DiscreteIntegrator: '<S59>/Integrator'
      //   Product: '<S64>/PProd Out'

      rtb_SinCos_o2 = (rtb_IProdOut_p *
                       FLIGHT_hexacopter_B.ReadParameter1_pn.ReadParameter1_o1 +
                       FLIGHT_hexacopter_DW.Integrator_DSTATE_e) + rtb_SinCos_o1;
      FLIGHT_hexacopt_ReadParameter_p(&FLIGHT_hexacopter_B.ReadParameter_pn,
        &FLIGHT_hexacopter_DW.ReadParameter_pn);

      // Saturate: '<S66>/Saturation'
      if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.PIDController4_UpperSaturationL) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.PIDController4_UpperSaturationL;
      } else if (rtb_SinCos_o2 <
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturationL) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.PIDController4_LowerSaturationL;
      } else {
        rtb_Saturation3 = rtb_SinCos_o2;
      }

      // Sum: '<S19>/Sum6' incorporates:
      //   Saturate: '<S66>/Saturation'

      FLIGHT_hexacopter_B.Saturation1_i = rtb_Saturation3 +
        FLIGHT_hexacopter_B.ReadParameter_pn.ReadParameter_o1;

      // Saturate: '<S19>/Saturation1'
      if (FLIGHT_hexacopter_B.Saturation1_i >
          FLIGHT_hexacopter_P.Saturation1_UpperSat) {
        // Sum: '<S19>/Sum6' incorporates:
        //   Saturate: '<S19>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1_i =
          FLIGHT_hexacopter_P.Saturation1_UpperSat;
      } else if (FLIGHT_hexacopter_B.Saturation1_i <
                 FLIGHT_hexacopter_P.Saturation1_LowerSat) {
        // Sum: '<S19>/Sum6' incorporates:
        //   Saturate: '<S19>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1_i =
          FLIGHT_hexacopter_P.Saturation1_LowerSat;
      }

      // End of Saturate: '<S19>/Saturation1'

      // DeadZone: '<S51>/DeadZone'
      if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.PIDController4_UpperSaturationL) {
        rtb_SinCos_o2 -= FLIGHT_hexacopter_P.PIDController4_UpperSaturationL;
      } else if (rtb_SinCos_o2 >=
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturationL) {
        rtb_SinCos_o2 = 0.0F;
      } else {
        rtb_SinCos_o2 -= FLIGHT_hexacopter_P.PIDController4_LowerSaturationL;
      }

      // End of DeadZone: '<S51>/DeadZone'
      FLIGHT_hexacopte_ReadParameter2(&FLIGHT_hexacopter_B.ReadParameter2_p,
        &FLIGHT_hexacopter_DW.ReadParameter2_p);

      // Product: '<S56>/IProd Out'
      rtb_IProdOut_p *= FLIGHT_hexacopter_B.ReadParameter2_p.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S54>/Filter'
      FLIGHT_hexacopter_DW.Filter_DSTATE_i += FLIGHT_hexacopter_P.Filter_gainval
        * rtb_SinCos_o1;

      // Switch: '<S49>/Switch1' incorporates:
      //   Constant: '<S49>/Clamping_zero'
      //   Constant: '<S49>/Constant'
      //   Constant: '<S49>/Constant2'
      //   RelationalOperator: '<S49>/fix for DT propagation issue'

      if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.Clamping_zero_Value) {
        tmp_0 = FLIGHT_hexacopter_P.Constant_Value_jc;
      } else {
        tmp_0 = FLIGHT_hexacopter_P.Constant2_Value_mj;
      }

      // Switch: '<S49>/Switch2' incorporates:
      //   Constant: '<S49>/Clamping_zero'
      //   Constant: '<S49>/Constant3'
      //   Constant: '<S49>/Constant4'
      //   RelationalOperator: '<S49>/fix for DT propagation issue1'

      if (rtb_IProdOut_p > FLIGHT_hexacopter_P.Clamping_zero_Value) {
        tmp_1 = FLIGHT_hexacopter_P.Constant3_Value_es;
      } else {
        tmp_1 = FLIGHT_hexacopter_P.Constant4_Value_j;
      }

      // Switch: '<S49>/Switch' incorporates:
      //   Constant: '<S49>/Clamping_zero'
      //   Constant: '<S49>/Constant1'
      //   Logic: '<S49>/AND3'
      //   RelationalOperator: '<S49>/Equal1'
      //   RelationalOperator: '<S49>/Relational Operator'
      //   Switch: '<S49>/Switch1'
      //   Switch: '<S49>/Switch2'

      if ((FLIGHT_hexacopter_P.Clamping_zero_Value != rtb_SinCos_o2) && (tmp_0 ==
           tmp_1)) {
        rtb_IProdOut_p = FLIGHT_hexacopter_P.Constant1_Value_n;
      }

      // Update for DiscreteIntegrator: '<S59>/Integrator' incorporates:
      //   Switch: '<S49>/Switch'

      FLIGHT_hexacopter_DW.Integrator_DSTATE_e +=
        FLIGHT_hexacopter_P.Integrator_gainval * rtb_IProdOut_p;
    }

    // End of Outputs for SubSystem: '<S1>/Vz Controller'

    // SignalConversion generated from: '<S1>/throttle' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.Saturation1_i;

    // Fcn: '<S16>/Fcn1' incorporates:
    //   DataTypeConversion: '<S16>/Data Type Conversion2'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[1])
                       - 1514.0F) / 500.0F;

    // DeadZone: '<S16>/Dead Zone1'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone1_End) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone1_End;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone1_Start) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone1_Start;
    }

    // End of DeadZone: '<S16>/Dead Zone1'

    // Saturate: '<S16>/Saturation1'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation1_UpperSat_d) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation1_UpperSat_d;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation1_LowerSat_b) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation1_LowerSat_b;
    }

    // SignalConversion generated from: '<S1>/des_pitch' incorporates:
    //   Gain: '<S16>/Gain2'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S16>/Saturation1'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH *
      rtb_Saturation3;

    // End of Outputs for SubSystem: '<Root>/Altitude_Mode'
  } else if (FLIGHT_hexacopter_B.In1_n.values[5] >= 1800) {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
    //   ActionPort: '<S4>/Action Port'

    // Outputs for Enabled SubSystem: '<S4>/XY Pos Controller' incorporates:
    //   EnablePort: '<S192>/Enable'

    if (rtb_Compare) {
      // MATLABSystem: '<S192>/Read Parameter'
      if (FLIGHT_hexacopter_DW.obj_eq.SampleTime !=
          FLIGHT_hexacopter_P.SampleTime) {
        FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
      }

      b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE,
        MW_SINGLE, &rtb_Saturation3);
      if (b_varargout_1) {
        rtb_Saturation3 = 0.0F;
      }

      // Product: '<S337>/PProd Out' incorporates:
      //   Constant: '<S4>/Constant'
      //   MATLABSystem: '<S192>/Read Parameter'
      //   Sum: '<S192>/Sum'
      //
      FLIGHT_hexacopter_B.PProdOut[0] = (FLIGHT_hexacopter_P.Constant_Value_k[0]
        - FLIGHT_hexacopter_B.In1.x) * rtb_Saturation3;
      FLIGHT_hexacopter_B.PProdOut[1] = (FLIGHT_hexacopter_P.Constant_Value_k[1]
        - FLIGHT_hexacopter_B.In1.y) * rtb_Saturation3;
    }

    // End of Outputs for SubSystem: '<S4>/XY Pos Controller'

    // SignalConversion generated from: '<S4>/des_xy' incorporates:
    //   Constant: '<S4>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0] =
      FLIGHT_hexacopter_P.Constant_Value_k[0];
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1] =
      FLIGHT_hexacopter_P.Constant_Value_k[1];

    // Outputs for Enabled SubSystem: '<S4>/XY Velocity Controller' incorporates:
    //   EnablePort: '<S193>/Enable'

    if (rtb_Compare) {
      // Trigonometry: '<S351>/SinCos'
      rtb_SinCos_o1 = static_cast<real32_T>(sin(static_cast<real_T>
        (FLIGHT_hexacopter_B.In1.heading)));
      rtb_SinCos_o2 = static_cast<real32_T>(cos(static_cast<real_T>
        (FLIGHT_hexacopter_B.In1.heading)));

      // MATLABSystem: '<S193>/Read Parameter'
      if (FLIGHT_hexacopter_DW.obj_pi.SampleTime !=
          FLIGHT_hexacopter_P.SampleTime) {
        FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
      }

      b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE,
        MW_SINGLE, &rtb_Saturation3);
      if (b_varargout_1) {
        rtb_Saturation3 = 0.0F;
      }

      // Sum: '<S193>/Sum'
      rtb_NProdOut_g = FLIGHT_hexacopter_B.PProdOut[0] -
        FLIGHT_hexacopter_B.In1.vx;
      rtb_IProdOut_c = FLIGHT_hexacopter_B.PProdOut[1] -
        FLIGHT_hexacopter_B.In1.vy;

      // Saturate: '<S193>/Saturation' incorporates:
      //   Gain: '<S351>/Gain'
      //   MATLABSystem: '<S193>/Read Parameter'
      //   Product: '<S349>/MatrixMultiply'
      //   Product: '<S390>/PProd Out'
      //   Reshape: '<S351>/Reshape'
      //   Reshape: '<S351>/Reshape1'
      //
      rtb_IProdOut_p = (rtb_SinCos_o2 * rtb_NProdOut_g + rtb_SinCos_o1 *
                        rtb_IProdOut_c) * rtb_Saturation3;
      if (rtb_IProdOut_p > FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
        // Saturate: '<S193>/Saturation'
        FLIGHT_hexacopter_B.Saturation[0] =
          FLIGHT_hexacopter_P.Saturation_UpperSat_e;
      } else if (rtb_IProdOut_p < FLIGHT_hexacopter_P.Saturation_LowerSat_a) {
        // Saturate: '<S193>/Saturation'
        FLIGHT_hexacopter_B.Saturation[0] =
          FLIGHT_hexacopter_P.Saturation_LowerSat_a;
      } else {
        // Saturate: '<S193>/Saturation'
        FLIGHT_hexacopter_B.Saturation[0] = rtb_IProdOut_p;
      }

      rtb_IProdOut_p = (FLIGHT_hexacopter_P.Gain_Gain_a * rtb_SinCos_o1 *
                        rtb_NProdOut_g + rtb_SinCos_o2 * rtb_IProdOut_c) *
        rtb_Saturation3;
      if (rtb_IProdOut_p > FLIGHT_hexacopter_P.Saturation_UpperSat_e) {
        // Saturate: '<S193>/Saturation'
        FLIGHT_hexacopter_B.Saturation[1] =
          FLIGHT_hexacopter_P.Saturation_UpperSat_e;
      } else if (rtb_IProdOut_p < FLIGHT_hexacopter_P.Saturation_LowerSat_a) {
        // Saturate: '<S193>/Saturation'
        FLIGHT_hexacopter_B.Saturation[1] =
          FLIGHT_hexacopter_P.Saturation_LowerSat_a;
      } else {
        // Saturate: '<S193>/Saturation'
        FLIGHT_hexacopter_B.Saturation[1] = rtb_IProdOut_p;
      }

      // End of Saturate: '<S193>/Saturation'

      // Gain: '<S193>/Gain1'
      FLIGHT_hexacopter_B.Gain1 = FLIGHT_hexacopter_P.Gain1_Gain_i *
        FLIGHT_hexacopter_B.Saturation[0];
    }

    // End of Outputs for SubSystem: '<S4>/XY Velocity Controller'

    // SignalConversion generated from: '<S4>/des_pitch' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_B.Gain1;

    // SignalConversion generated from: '<S4>/des_roll' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_B.Saturation[1];

    // Fcn: '<S190>/Fcn3' incorporates:
    //   DataTypeConversion: '<S190>/Data Type Conversion11'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[2])
                       - 1514.0F) / 500.0F;

    // DeadZone: '<S190>/Dead Zone4'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone4_End_l) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone4_End_l;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone4_Start_d) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone4_Start_d;
    }

    // End of DeadZone: '<S190>/Dead Zone4'

    // Saturate: '<S190>/Saturation10'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation10_UpperSat_m) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation10_UpperSat_m;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation10_LowerSat_n) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation10_LowerSat_n;
    }

    // Sum: '<S4>/Add' incorporates:
    //   Gain: '<S190>/Gain'
    //   Saturate: '<S190>/Saturation10'

    FLIGHT_hexacopter_B.Add = FLIGHT_hexacopter_P.Gain_Gain_o * rtb_Saturation3
      + FLIGHT_hexacopter_B.In1.z;

    // Outputs for Enabled SubSystem: '<S4>/Vz Controller' incorporates:
    //   EnablePort: '<S191>/Enable'

    // Outputs for Enabled SubSystem: '<S4>/Altitude Controller' incorporates:
    //   EnablePort: '<S189>/Enable'

    if (rtb_Compare) {
      // MATLABSystem: '<S189>/Read Parameter1'
      if (FLIGHT_hexacopter_DW.obj_m.SampleTime !=
          FLIGHT_hexacopter_P.SampleTime) {
        FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
      }

      b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE,
        MW_SINGLE, &rtb_Saturation3);
      if (b_varargout_1) {
        rtb_Saturation3 = 0.0F;
      }

      // Product: '<S233>/PProd Out' incorporates:
      //   MATLABSystem: '<S189>/Read Parameter1'
      //   Sum: '<S189>/Sum'
      //
      FLIGHT_hexacopter_B.des_vz = (FLIGHT_hexacopter_B.Add -
        FLIGHT_hexacopter_B.In1.z) * rtb_Saturation3;

      // Saturate: '<S235>/Saturation'
      if (FLIGHT_hexacopter_B.des_vz >
          FLIGHT_hexacopter_P.PIDController4_UpperSaturatio_h) {
        // Product: '<S233>/PProd Out' incorporates:
        //   SignalConversion generated from: '<S191>/des_vz'

        FLIGHT_hexacopter_B.des_vz =
          FLIGHT_hexacopter_P.PIDController4_UpperSaturatio_h;
      } else if (FLIGHT_hexacopter_B.des_vz <
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_a) {
        // Product: '<S233>/PProd Out' incorporates:
        //   SignalConversion generated from: '<S191>/des_vz'

        FLIGHT_hexacopter_B.des_vz =
          FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_a;
      }

      // End of Saturate: '<S235>/Saturation'

      // Gain: '<S191>/Gain' incorporates:
      //   Sum: '<S191>/Sum3'

      rtb_IProdOut_p = (FLIGHT_hexacopter_B.des_vz - FLIGHT_hexacopter_B.In1.vz)
        * FLIGHT_hexacopter_P.Gain_Gain_b;
      FLIGHT_hexacopte_ReadParameter3(&FLIGHT_hexacopter_B.ReadParameter3_pn,
        &FLIGHT_hexacopter_DW.ReadParameter3_pn);

      // DiscreteIntegrator: '<S276>/Filter'
      if ((FLIGHT_hexacopter_B.des_vz > 0.0F) &&
          (FLIGHT_hexacopter_DW.Filter_PrevResetState <= 0)) {
        FLIGHT_hexacopter_DW.Filter_DSTATE_g =
          FLIGHT_hexacopter_P.PIDController4_InitialConditi_l;
      }

      // Product: '<S284>/NProd Out' incorporates:
      //   Constant: '<S191>/Constant'
      //   DiscreteIntegrator: '<S276>/Filter'
      //   Product: '<S274>/DProd Out'
      //   Sum: '<S276>/SumD'

      rtb_SinCos_o1 = (rtb_IProdOut_p *
                       FLIGHT_hexacopter_B.ReadParameter3_pn.ReadParameter3_o1 -
                       FLIGHT_hexacopter_DW.Filter_DSTATE_g) *
        FLIGHT_hexacopter_P.Constant_Value_e;
      FLIGHT_hexacopte_ReadParameter1(&FLIGHT_hexacopter_B.ReadParameter1_pnae,
        &FLIGHT_hexacopter_DW.ReadParameter1_pnae);

      // DiscreteIntegrator: '<S281>/Integrator'
      if ((FLIGHT_hexacopter_B.des_vz > 0.0F) &&
          (FLIGHT_hexacopter_DW.Integrator_PrevResetState <= 0)) {
        FLIGHT_hexacopter_DW.Integrator_DSTATE_k =
          FLIGHT_hexacopter_P.PIDController4_InitialConditi_i;
      }

      // Sum: '<S290>/Sum' incorporates:
      //   DiscreteIntegrator: '<S281>/Integrator'
      //   Product: '<S286>/PProd Out'

      rtb_SinCos_o2 = (rtb_IProdOut_p *
                       FLIGHT_hexacopter_B.ReadParameter1_pnae.ReadParameter1_o1
                       + FLIGHT_hexacopter_DW.Integrator_DSTATE_k) +
        rtb_SinCos_o1;
      FLIGHT_hexacopt_ReadParameter_p(&FLIGHT_hexacopter_B.ReadParameter_pna,
        &FLIGHT_hexacopter_DW.ReadParameter_pna);

      // Saturate: '<S288>/Saturation'
      if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy;
      } else if (rtb_SinCos_o2 <
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f;
      } else {
        rtb_Saturation3 = rtb_SinCos_o2;
      }

      // Sum: '<S191>/Sum6' incorporates:
      //   Saturate: '<S288>/Saturation'

      FLIGHT_hexacopter_B.Saturation1 = rtb_Saturation3 +
        FLIGHT_hexacopter_B.ReadParameter_pna.ReadParameter_o1;

      // Saturate: '<S191>/Saturation1'
      if (FLIGHT_hexacopter_B.Saturation1 >
          FLIGHT_hexacopter_P.Saturation1_UpperSat_e) {
        // Sum: '<S191>/Sum6' incorporates:
        //   Saturate: '<S191>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1 =
          FLIGHT_hexacopter_P.Saturation1_UpperSat_e;
      } else if (FLIGHT_hexacopter_B.Saturation1 <
                 FLIGHT_hexacopter_P.Saturation1_LowerSat_bn) {
        // Sum: '<S191>/Sum6' incorporates:
        //   Saturate: '<S191>/Saturation1'

        FLIGHT_hexacopter_B.Saturation1 =
          FLIGHT_hexacopter_P.Saturation1_LowerSat_bn;
      }

      // End of Saturate: '<S191>/Saturation1'

      // DeadZone: '<S273>/DeadZone'
      if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy) {
        rtb_SinCos_o2 -= FLIGHT_hexacopter_P.PIDController4_UpperSaturati_hy;
      } else if (rtb_SinCos_o2 >=
                 FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f) {
        rtb_SinCos_o2 = 0.0F;
      } else {
        rtb_SinCos_o2 -= FLIGHT_hexacopter_P.PIDController4_LowerSaturatio_f;
      }

      // End of DeadZone: '<S273>/DeadZone'
      FLIGHT_hexacopte_ReadParameter2(&FLIGHT_hexacopter_B.ReadParameter2_pn,
        &FLIGHT_hexacopter_DW.ReadParameter2_pn);

      // Product: '<S278>/IProd Out'
      rtb_IProdOut_p *= FLIGHT_hexacopter_B.ReadParameter2_pn.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S276>/Filter'
      FLIGHT_hexacopter_DW.Filter_DSTATE_g +=
        FLIGHT_hexacopter_P.Filter_gainval_h * rtb_SinCos_o1;
      if (FLIGHT_hexacopter_B.des_vz > 0.0F) {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = 1;
      } else if (FLIGHT_hexacopter_B.des_vz < 0.0F) {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = -1;
      } else if (FLIGHT_hexacopter_B.des_vz == 0.0F) {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = 0;
      } else {
        FLIGHT_hexacopter_DW.Filter_PrevResetState = 2;
      }

      // End of Update for DiscreteIntegrator: '<S276>/Filter'

      // Switch: '<S271>/Switch1' incorporates:
      //   Constant: '<S271>/Clamping_zero'
      //   Constant: '<S271>/Constant'
      //   Constant: '<S271>/Constant2'
      //   RelationalOperator: '<S271>/fix for DT propagation issue'

      if (rtb_SinCos_o2 > FLIGHT_hexacopter_P.Clamping_zero_Value_f) {
        tmp_0 = FLIGHT_hexacopter_P.Constant_Value_mn;
      } else {
        tmp_0 = FLIGHT_hexacopter_P.Constant2_Value_p;
      }

      // Switch: '<S271>/Switch2' incorporates:
      //   Constant: '<S271>/Clamping_zero'
      //   Constant: '<S271>/Constant3'
      //   Constant: '<S271>/Constant4'
      //   RelationalOperator: '<S271>/fix for DT propagation issue1'

      if (rtb_IProdOut_p > FLIGHT_hexacopter_P.Clamping_zero_Value_f) {
        tmp_1 = FLIGHT_hexacopter_P.Constant3_Value_n;
      } else {
        tmp_1 = FLIGHT_hexacopter_P.Constant4_Value_i;
      }

      // Switch: '<S271>/Switch' incorporates:
      //   Constant: '<S271>/Clamping_zero'
      //   Constant: '<S271>/Constant1'
      //   Logic: '<S271>/AND3'
      //   RelationalOperator: '<S271>/Equal1'
      //   RelationalOperator: '<S271>/Relational Operator'
      //   Switch: '<S271>/Switch1'
      //   Switch: '<S271>/Switch2'

      if ((FLIGHT_hexacopter_P.Clamping_zero_Value_f != rtb_SinCos_o2) && (tmp_0
           == tmp_1)) {
        rtb_IProdOut_p = FLIGHT_hexacopter_P.Constant1_Value_m;
      }

      // Update for DiscreteIntegrator: '<S281>/Integrator' incorporates:
      //   Switch: '<S271>/Switch'

      FLIGHT_hexacopter_DW.Integrator_DSTATE_k +=
        FLIGHT_hexacopter_P.Integrator_gainval_l * rtb_IProdOut_p;
      if (FLIGHT_hexacopter_B.des_vz > 0.0F) {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = 1;
      } else if (FLIGHT_hexacopter_B.des_vz < 0.0F) {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = -1;
      } else if (FLIGHT_hexacopter_B.des_vz == 0.0F) {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = 0;
      } else {
        FLIGHT_hexacopter_DW.Integrator_PrevResetState = 2;
      }

      // End of Update for DiscreteIntegrator: '<S281>/Integrator'
    }

    // End of Outputs for SubSystem: '<S4>/Altitude Controller'
    // End of Outputs for SubSystem: '<S4>/Vz Controller'

    // Gain: '<S16>/Gain' incorporates:
    //   Merge: '<Root>/Merge'
    //   SignalConversion generated from: '<S4>/des_vz'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_B.des_vz;

    // SignalConversion generated from: '<S4>/throttle' incorporates:
    //   Merge: '<Root>/Merge1'

    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_B.Saturation1;

    // Fcn: '<S190>/Fcn7' incorporates:
    //   DataTypeConversion: '<S190>/Data Type Conversion10'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[3])
                       - 1514.0F) / 500.0F;

    // DeadZone: '<S190>/Dead Zone2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End_k) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone2_End_k;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone2_Start_k) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone2_Start_k;
    }

    // End of DeadZone: '<S190>/Dead Zone2'

    // Saturate: '<S190>/Saturation3'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation3_UpperSat_b) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation3_UpperSat_b;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation3_LowerSat_a) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation3_LowerSat_a;
    }

    // SignalConversion generated from: '<S4>/des_r' incorporates:
    //   Gain: '<S190>/Gain3'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S190>/Saturation3'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * rtb_Saturation3;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/Stabilized_Mode' incorporates:
    //   ActionPort: '<S9>/Action Port'

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S569>/Enable'

    if (FLIGHT_hexacopter_B.In1_n.values[6] >=
        FLIGHT_hexacopter_P.CompareToConstant_const_l) {
      // FromWorkspace: '<S571>/fromWS_Signal 1'
      {
        real_T t = ((FLIGHT_hexacopter_M->Timing.clockTick0) * 0.0025);
        real_T *pTimeValues = static_cast<real_T *>
          (FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK.TimePtr);
        real_T *pDataValues = static_cast<real_T *>
          (FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK.DataPtr);
        if (t < pTimeValues[0]) {
          FLIGHT_hexacopter_B.Signal = 0.0;
        } else if (t == pTimeValues[7]) {
          FLIGHT_hexacopter_B.Signal = pDataValues[7];
        } else if (t > pTimeValues[7]) {
          FLIGHT_hexacopter_B.Signal = 0.0;
        } else {
          int_T currTimeIndex =
            FLIGHT_hexacopter_DW.fromWS_Signal1_IWORK.PrevIndex;
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }

          FLIGHT_hexacopter_B.Signal = pDataValues[currTimeIndex];
          FLIGHT_hexacopter_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
        }
      }

      // Product: '<S569>/Product' incorporates:
      //   Constant: '<S569>/Constant'
      //   Gain: '<S570>/Gain1'

      FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Gain1_Gain_p *
        FLIGHT_hexacopter_P.Constant_Value_gq * FLIGHT_hexacopter_B.Signal;

      // Sum: '<S572>/Sum' incorporates:
      //   Gain: '<S572>/Gain'
      //   Sum: '<S572>/Diff'
      //   UnitDelay: '<S572>/UD'
      //
      //  Block description for '<S572>/Sum':
      //
      //   Add in CPU
      //
      //  Block description for '<S572>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S572>/UD':
      //
      //   Store in Global RAM

      FLIGHT_hexacopter_DW.UD_DSTATE = (FLIGHT_hexacopter_DW.UD_DSTATE -
        FLIGHT_hexacopter_B.Product_k) *
        FLIGHT_hexacopter_P.TransferFcnFirstOrder_PoleZ_o +
        FLIGHT_hexacopter_B.Product_k;
      FLIGHT_hexacopter_ReadParameter(&FLIGHT_hexacopter_DW.ReadParameter_pnaevv);

      // Switch: '<S9>/Switch' incorporates:
      //   Merge: '<Root>/Merge1'
      //   UnitDelay: '<S572>/UD'
      //
      //  Block description for '<S572>/UD':
      //
      //   Store in Global RAM

      FLIGHT_hexacopter_B.Merge1[0] = static_cast<real32_T>
        (FLIGHT_hexacopter_DW.UD_DSTATE);
    } else {
      // Gain: '<S9>/Gain3' incorporates:
      //   Constant: '<S9>/Constant3'
      //   Sum: '<S9>/Sum3'
      //   Switch: '<S9>/Switch'

      rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values
        [0]) - FLIGHT_hexacopter_P.Constant3_Value_e) *
        FLIGHT_hexacopter_P.Gain3_Gain;

      // DeadZone: '<S9>/Dead Zone' incorporates:
      //   Switch: '<S9>/Switch'

      if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone_End) {
        rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone_End;
      } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone_Start) {
        rtb_Saturation3 = 0.0F;
      } else {
        rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone_Start;
      }

      // End of DeadZone: '<S9>/Dead Zone'

      // Saturate: '<S9>/Saturation3' incorporates:
      //   Switch: '<S9>/Switch'

      if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation3_UpperSat_b4) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation3_UpperSat_b4;
      } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation3_LowerSat_j) {
        rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation3_LowerSat_j;
      }

      // Switch: '<S9>/Switch' incorporates:
      //   Gain: '<S9>/Gain4'
      //   Merge: '<Root>/Merge1'
      //   Saturate: '<S9>/Saturation3'

      FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_ROLL
        * rtb_Saturation3;
    }

    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'

    // Gain: '<S9>/Gain' incorporates:
    //   Constant: '<S9>/Constant'
    //   Sum: '<S9>/Sum'

    rtb_Saturation3 = static_cast<real32_T>((static_cast<real_T>
      (FLIGHT_hexacopter_B.In1_n.values[2]) -
      FLIGHT_hexacopter_P.Constant_Value_c) * FLIGHT_hexacopter_P.Gain_Gain);

    // DeadZone: '<S9>/Dead Zone3'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone3_End_l) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone3_End_l;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone3_Start_p) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone3_Start_p;
    }

    // End of DeadZone: '<S9>/Dead Zone3'

    // Saturate: '<S9>/Saturation'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation_UpperSat_o) {
      // SignalConversion generated from: '<S9>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation_UpperSat_o;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation_LowerSat_el) {
      // SignalConversion generated from: '<S9>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Saturation_LowerSat_el;
    } else {
      // SignalConversion generated from: '<S9>/throttle' incorporates:
      //   Merge: '<Root>/Merge1'

      FLIGHT_hexacopter_B.Merge1[3] = rtb_Saturation3;
    }

    // End of Saturate: '<S9>/Saturation'

    // Gain: '<S9>/Gain2' incorporates:
    //   Constant: '<S9>/Constant1'
    //   Sum: '<S9>/Sum1'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[3])
                       - FLIGHT_hexacopter_P.Constant1_Value_l) *
      FLIGHT_hexacopter_P.Gain2_Gain;

    // DeadZone: '<S9>/Dead Zone2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone2_End_e) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone2_End_e;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone2_Start_o) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone2_Start_o;
    }

    // End of DeadZone: '<S9>/Dead Zone2'

    // Saturate: '<S9>/Saturation1'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation1_UpperSat_l) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation1_UpperSat_l;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation1_LowerSat_i) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation1_LowerSat_i;
    }

    // SignalConversion generated from: '<S9>/des_r' incorporates:
    //   Gain: '<S9>/Gain6'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S9>/Saturation1'

    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_RATE_Y
      * rtb_Saturation3;

    // Gain: '<S9>/Gain1' incorporates:
    //   Constant: '<S9>/Constant2'
    //   Sum: '<S9>/Sum2'

    rtb_Saturation3 = (static_cast<real32_T>(FLIGHT_hexacopter_B.In1_n.values[1])
                       - FLIGHT_hexacopter_P.Constant2_Value_i) *
      FLIGHT_hexacopter_P.Gain1_Gain_m;

    // DeadZone: '<S9>/Dead Zone1'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.DeadZone1_End_m) {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone1_End_m;
    } else if (rtb_Saturation3 >= FLIGHT_hexacopter_P.DeadZone1_Start_c) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 -= FLIGHT_hexacopter_P.DeadZone1_Start_c;
    }

    // End of DeadZone: '<S9>/Dead Zone1'

    // Saturate: '<S9>/Saturation2'
    if (rtb_Saturation3 > FLIGHT_hexacopter_P.Saturation2_UpperSat) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation2_UpperSat;
    } else if (rtb_Saturation3 < FLIGHT_hexacopter_P.Saturation2_LowerSat) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation2_LowerSat;
    }

    // SignalConversion generated from: '<S9>/des_P' incorporates:
    //   Gain: '<S9>/Gain5'
    //   Merge: '<Root>/Merge1'
    //   Saturate: '<S9>/Saturation2'

    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.MAX_CONTROL_ANGLE_PITCH *
      rtb_Saturation3;

    // End of Outputs for SubSystem: '<Root>/Stabilized_Mode'
  }

  // End of If: '<Root>/If'

  // MATLABSystem: '<S408>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_ab.eventStructObj, &FLIGHT_hexacopter_B.r1, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S408>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S409>/Enable'

  // Start for MATLABSystem: '<S408>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S409>/In1'
    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_B.r1;
  }

  // End of Outputs for SubSystem: '<S408>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/CAS' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (rtb_Compare) {
    // MATLABSystem: '<S2>/Read Parameter9'
    if (FLIGHT_hexacopter_DW.obj_k.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_k.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_k.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Gain: '<S76>/Gain1' incorporates:
    //   MATLABSystem: '<S2>/Read Parameter9'
    //
    rtb_IProdOut_p = FLIGHT_hexacopter_P.Gain1_Gain_g * rtb_Saturation3;

    // MATLABSystem: '<S2>/Read Parameter'
    if (FLIGHT_hexacopter_DW.obj_jz.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S169>/PProd Out' incorporates:
    //   MATLAB Function: '<Root>/quat2eul'
    //   MATLABSystem: '<S2>/Read Parameter'
    //   Sum: '<S2>/Sum3'
    //
    FLIGHT_hexacopter_B.Switch2 = (FLIGHT_hexacopter_B.Merge1[0] - rt_atan2f_snf
      ((FLIGHT_hexacopter_B.In1_k.q[0] * FLIGHT_hexacopter_B.In1_k.q[1] +
        FLIGHT_hexacopter_B.In1_k.q[2] * FLIGHT_hexacopter_B.In1_k.q[3]) * 2.0F,
       ((FLIGHT_hexacopter_B.In1_k.q[0] * FLIGHT_hexacopter_B.In1_k.q[0] -
         FLIGHT_hexacopter_B.In1_k.q[1] * FLIGHT_hexacopter_B.In1_k.q[1]) -
        FLIGHT_hexacopter_B.In1_k.q[2] * FLIGHT_hexacopter_B.In1_k.q[2]) +
       FLIGHT_hexacopter_B.In1_k.q[3] * FLIGHT_hexacopter_B.In1_k.q[3])) *
      rtb_Saturation3;

    // Switch: '<S172>/Switch2' incorporates:
    //   RelationalOperator: '<S172>/LowerRelop1'

    if (FLIGHT_hexacopter_B.Switch2 > rtb_IProdOut_p) {
      // Product: '<S169>/PProd Out' incorporates:
      //   Switch: '<S172>/Switch2'

      FLIGHT_hexacopter_B.Switch2 = rtb_IProdOut_p;
    } else {
      // Gain: '<S2>/Gain'
      rtb_Saturation3 = FLIGHT_hexacopter_P.Gain_Gain_m3 * rtb_IProdOut_p;

      // Switch: '<S172>/Switch' incorporates:
      //   RelationalOperator: '<S172>/UpperRelop'

      if (FLIGHT_hexacopter_B.Switch2 < rtb_Saturation3) {
        // Product: '<S169>/PProd Out' incorporates:
        //   Switch: '<S172>/Switch2'

        FLIGHT_hexacopter_B.Switch2 = rtb_Saturation3;
      }

      // End of Switch: '<S172>/Switch'
    }

    // End of Switch: '<S172>/Switch2'

    // MATLABSystem: '<S2>/Read Parameter10'
    if (FLIGHT_hexacopter_DW.obj_ds.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_ds.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ds.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Gain: '<S77>/Gain1' incorporates:
    //   MATLABSystem: '<S2>/Read Parameter10'
    //
    rtb_IProdOut_p = FLIGHT_hexacopter_P.Gain1_Gain_c * rtb_Saturation3;

    // MATLABSystem: '<S2>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_o.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S118>/PProd Out' incorporates:
    //   MATLAB Function: '<Root>/quat2eul'
    //   MATLABSystem: '<S2>/Read Parameter1'
    //   Sum: '<S2>/Sum2'
    //
    FLIGHT_hexacopter_B.Switch2_i = (FLIGHT_hexacopter_B.Merge1[1] -
      static_cast<real32_T>(asin(static_cast<real_T>
      ((FLIGHT_hexacopter_B.In1_k.q[1] * FLIGHT_hexacopter_B.In1_k.q[3] -
        FLIGHT_hexacopter_B.In1_k.q[0] * FLIGHT_hexacopter_B.In1_k.q[2]) * -2.0F))))
      * rtb_Saturation3;

    // Switch: '<S121>/Switch2' incorporates:
    //   RelationalOperator: '<S121>/LowerRelop1'

    if (FLIGHT_hexacopter_B.Switch2_i > rtb_IProdOut_p) {
      // Product: '<S118>/PProd Out' incorporates:
      //   Switch: '<S121>/Switch2'

      FLIGHT_hexacopter_B.Switch2_i = rtb_IProdOut_p;
    } else {
      // Gain: '<S2>/Gain1'
      rtb_Saturation3 = FLIGHT_hexacopter_P.Gain1_Gain * rtb_IProdOut_p;

      // Switch: '<S121>/Switch' incorporates:
      //   RelationalOperator: '<S121>/UpperRelop'

      if (FLIGHT_hexacopter_B.Switch2_i < rtb_Saturation3) {
        // Product: '<S118>/PProd Out' incorporates:
        //   Switch: '<S121>/Switch2'

        FLIGHT_hexacopter_B.Switch2_i = rtb_Saturation3;
      }

      // End of Switch: '<S121>/Switch'
    }

    // End of Switch: '<S121>/Switch2'
  }

  // End of Outputs for SubSystem: '<Root>/CAS'

  // MATLABSystem: '<S404>/SourceBlock'
  b_varargout_1 = uORB_read_step(FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj,
    &FLIGHT_hexacopter_DW.obj_pe.eventStructObj, &FLIGHT_hexacopter_B.r3, false,
    1.0);

  // Outputs for Enabled SubSystem: '<S404>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S407>/Enable'

  // Start for MATLABSystem: '<S404>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S407>/In1'
    FLIGHT_hexacopter_B.In1_h = FLIGHT_hexacopter_B.r3;
  }

  // End of Outputs for SubSystem: '<S404>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/Mixer' incorporates:
  //   EnablePort: '<S5>/Enable'

  // Outputs for Enabled SubSystem: '<Root>/SAS' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (rtb_Compare) {
    // Sum: '<S8>/Sum1'
    rtb_IProdOut_p = FLIGHT_hexacopter_B.Switch2 -
      FLIGHT_hexacopter_B.In1_h.xyz[0];

    // MATLABSystem: '<S8>/Read Parameter2'
    if (FLIGHT_hexacopter_DW.obj_d.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S504>/NProd Out' incorporates:
    //   Constant: '<S8>/Constant'
    //   DiscreteIntegrator: '<S496>/Filter'
    //   MATLABSystem: '<S8>/Read Parameter2'
    //   Product: '<S494>/DProd Out'
    //   Sum: '<S496>/SumD'
    //
    rtb_SinCos_o1 = (rtb_IProdOut_p * rtb_Saturation3 -
                     FLIGHT_hexacopter_DW.Filter_DSTATE) *
      FLIGHT_hexacopter_P.Constant_Value_j4;

    // MATLABSystem: '<S8>/Read Parameter'
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Sum: '<S510>/Sum' incorporates:
    //   DiscreteIntegrator: '<S501>/Integrator'
    //   MATLABSystem: '<S8>/Read Parameter'
    //   Product: '<S506>/PProd Out'
    //
    FLIGHT_hexacopter_B.Sum_cc = (rtb_IProdOut_p * rtb_Saturation3 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE) + rtb_SinCos_o1;

    // MATLABSystem: '<S8>/Read Parameter1'
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S498>/IProd Out' incorporates:
    //   MATLABSystem: '<S8>/Read Parameter1'
    //
    rtb_SinCos_o2 = rtb_IProdOut_p * rtb_Saturation3;

    // Sum: '<S8>/Sum'
    rtb_IProdOut_p = FLIGHT_hexacopter_B.Switch2_i -
      FLIGHT_hexacopter_B.In1_h.xyz[1];

    // MATLABSystem: '<S8>/Read Parameter5'
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S454>/NProd Out' incorporates:
    //   Constant: '<S8>/Constant1'
    //   DiscreteIntegrator: '<S446>/Filter'
    //   MATLABSystem: '<S8>/Read Parameter5'
    //   Product: '<S444>/DProd Out'
    //   Sum: '<S446>/SumD'
    //
    rtb_NProdOut_g = (rtb_IProdOut_p * rtb_Saturation3 -
                      FLIGHT_hexacopter_DW.Filter_DSTATE_j) *
      FLIGHT_hexacopter_P.Constant1_Value_f;

    // MATLABSystem: '<S8>/Read Parameter3'
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Sum: '<S460>/Sum' incorporates:
    //   DiscreteIntegrator: '<S451>/Integrator'
    //   MATLABSystem: '<S8>/Read Parameter3'
    //   Product: '<S456>/PProd Out'
    //
    FLIGHT_hexacopter_B.Sum_a = (rtb_IProdOut_p * rtb_Saturation3 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_c) + rtb_NProdOut_g;

    // MATLABSystem: '<S8>/Read Parameter4'
    if (FLIGHT_hexacopter_DW.obj_p.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_p.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_p.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S448>/IProd Out' incorporates:
    //   MATLABSystem: '<S8>/Read Parameter4'
    //
    rtb_IProdOut_c = rtb_IProdOut_p * rtb_Saturation3;

    // Sum: '<S8>/Sum4'
    rtb_IProdOut_p = FLIGHT_hexacopter_B.Merge1[2] -
      FLIGHT_hexacopter_B.In1_h.xyz[2];

    // MATLABSystem: '<S8>/Read Parameter8'
    if (FLIGHT_hexacopter_DW.obj.SampleTime != FLIGHT_hexacopter_P.SampleTime) {
      FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Product: '<S554>/NProd Out' incorporates:
    //   Constant: '<S8>/Constant2'
    //   DiscreteIntegrator: '<S546>/Filter'
    //   MATLABSystem: '<S8>/Read Parameter8'
    //   Product: '<S544>/DProd Out'
    //   Sum: '<S546>/SumD'
    //
    rtb_NProdOut_a = (rtb_IProdOut_p * rtb_Saturation3 -
                      FLIGHT_hexacopter_DW.Filter_DSTATE_h) *
      FLIGHT_hexacopter_P.Constant2_Value_m;

    // MATLABSystem: '<S8>/Read Parameter6'
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Sum: '<S560>/Sum' incorporates:
    //   DiscreteIntegrator: '<S551>/Integrator'
    //   MATLABSystem: '<S8>/Read Parameter6'
    //   Product: '<S556>/PProd Out'
    //
    FLIGHT_hexacopter_B.Sum_i = (rtb_IProdOut_p * rtb_Saturation3 +
      FLIGHT_hexacopter_DW.Integrator_DSTATE_l) + rtb_NProdOut_a;

    // MATLABSystem: '<S8>/Read Parameter7'
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime != FLIGHT_hexacopter_P.SampleTime)
    {
      FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    }

    b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE,
      MW_SINGLE, &rtb_Saturation3);
    if (b_varargout_1) {
      rtb_Saturation3 = 0.0F;
    }

    // Update for DiscreteIntegrator: '<S496>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE += FLIGHT_hexacopter_P.Filter_gainval_o *
      rtb_SinCos_o1;

    // Update for DiscreteIntegrator: '<S501>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE +=
      FLIGHT_hexacopter_P.Integrator_gainval_i * rtb_SinCos_o2;

    // Update for DiscreteIntegrator: '<S446>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_j += FLIGHT_hexacopter_P.Filter_gainval_f
      * rtb_NProdOut_g;

    // Update for DiscreteIntegrator: '<S451>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c +=
      FLIGHT_hexacopter_P.Integrator_gainval_im * rtb_IProdOut_c;

    // Update for DiscreteIntegrator: '<S546>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_h += FLIGHT_hexacopter_P.Filter_gainval_m
      * rtb_NProdOut_a;

    // Update for DiscreteIntegrator: '<S551>/Integrator' incorporates:
    //   MATLABSystem: '<S8>/Read Parameter7'
    //   Product: '<S548>/IProd Out'
    //
    FLIGHT_hexacopter_DW.Integrator_DSTATE_l += rtb_IProdOut_p * rtb_Saturation3
      * FLIGHT_hexacopter_P.Integrator_gainval_e;

    // MATLAB Function: '<S5>/pwm_out2'
    rtb_Saturation3 = rt_roundf_snf(((-FLIGHT_hexacopter_B.Sum_cc -
      FLIGHT_hexacopter_B.Sum_i) * FLIGHT_hexacopter_B.Merge1[3] / 3.0F +
      FLIGHT_hexacopter_B.Merge1[3]) * 1000.0F);
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    tmp = Output_Limits1 + 1000U;
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    if (Output_Limits1 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S5>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S5>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[0] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S5>/pwm_out2'
    rtb_Saturation3 = rt_roundf_snf(((FLIGHT_hexacopter_B.Sum_cc +
      FLIGHT_hexacopter_B.Sum_i) * FLIGHT_hexacopter_B.Merge1[3] / 3.0F +
      FLIGHT_hexacopter_B.Merge1[3]) * 1000.0F);
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    tmp = Output_Limits1 + 1000U;
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    if (Output_Limits1 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S5>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S5>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[1] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S5>/pwm_out2'
    rtb_Saturation3 = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum_cc / 2.0F +
      FLIGHT_hexacopter_B.Sum_a) - FLIGHT_hexacopter_B.Sum_i) *
      FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
      1000.0F);
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    tmp = Output_Limits1 + 1000U;
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    if (Output_Limits1 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S5>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S5>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[2] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S5>/pwm_out2'
    rtb_Saturation3 = rt_roundf_snf((((-FLIGHT_hexacopter_B.Sum_a -
      FLIGHT_hexacopter_B.Sum_cc / 2.0F) + FLIGHT_hexacopter_B.Sum_i) *
      FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
      1000.0F);
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    tmp = Output_Limits1 + 1000U;
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    if (Output_Limits1 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S5>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S5>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[3] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S5>/pwm_out2'
    rtb_Saturation3 = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum_a -
      FLIGHT_hexacopter_B.Sum_cc / 2.0F) + FLIGHT_hexacopter_B.Sum_i) *
      FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
      1000.0F);
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    tmp = Output_Limits1 + 1000U;
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    if (Output_Limits1 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S5>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S5>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[4] = static_cast<uint16_T>(tmp);
    }

    // MATLAB Function: '<S5>/pwm_out2'
    rtb_Saturation3 = rt_roundf_snf((((FLIGHT_hexacopter_B.Sum_cc / 2.0F -
      FLIGHT_hexacopter_B.Sum_a) - FLIGHT_hexacopter_B.Sum_i) *
      FLIGHT_hexacopter_B.Merge1[3] / 3.0F + FLIGHT_hexacopter_B.Merge1[3]) *
      1000.0F);
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    tmp = Output_Limits1 + 1000U;
    if (rtb_Saturation3 < 65536.0F) {
      if (rtb_Saturation3 >= 0.0F) {
        Output_Limits1 = static_cast<uint16_T>(rtb_Saturation3);
      } else {
        Output_Limits1 = 0U;
      }
    } else {
      Output_Limits1 = MAX_uint16_T;
    }

    if (Output_Limits1 + 1000U > 65535U) {
      tmp = 65535U;
    }

    // Saturate: '<S5>/Output_Limits1' incorporates:
    //   MATLAB Function: '<S5>/pwm_out2'

    if (static_cast<uint16_T>(tmp) > FLIGHT_hexacopter_P.Output_Limits1_UpperSat)
    {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] =
        FLIGHT_hexacopter_P.Output_Limits1_UpperSat;
    } else if (static_cast<uint16_T>(tmp) <
               FLIGHT_hexacopter_P.Output_Limits1_LowerSat) {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] =
        FLIGHT_hexacopter_P.Output_Limits1_LowerSat;
    } else {
      // Saturate: '<S5>/Output_Limits1'
      FLIGHT_hexacopter_B.Output_Limits1[5] = static_cast<uint16_T>(tmp);
    }
  }

  // End of Outputs for SubSystem: '<Root>/SAS'
  // End of Outputs for SubSystem: '<Root>/Mixer'
  for (i = 0; i < 6; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    Output_Limits1 = FLIGHT_hexacopter_B.Output_Limits1[i];
    FLIGHT_hexacopter_B.DataTypeConversion_j[i] = Output_Limits1;

    // DataTypeConversion: '<S3>/Data Type Conversion6'
    FLIGHT_hexacopter_B.DataTypeConversion6[i] = Output_Limits1;
  }

  // MATLABSystem: '<S3>/Read Parameter13'
  if (FLIGHT_hexacopter_DW.obj_g.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter13_SampleTime) {
    FLIGHT_hexacopter_DW.obj_g.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter13_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE,
    MW_INT32, &i);
  if (b_varargout_1) {
    i = 0;
  }

  // RelationalOperator: '<S182>/Compare' incorporates:
  //   Constant: '<S182>/Constant'
  //   SignalConversion generated from: '<S411>/Bus Selector'

  rtb_Compare_a = (FLIGHT_hexacopter_B.In1_n.values[7] >=
                   FLIGHT_hexacopter_P.CompareToConstant_const_g);

  // MATLABSystem: '<S3>/Read Parameter1'
  if (FLIGHT_hexacopter_DW.obj_j5.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter1_SampleTime) {
    FLIGHT_hexacopter_DW.obj_j5.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter1_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_j5.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep = 0;
  }

  // MATLABSystem: '<S3>/Read Parameter2'
  if (FLIGHT_hexacopter_DW.obj_ao.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter2_SampleTime) {
    FLIGHT_hexacopter_DW.obj_ao.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter2_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_ao.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_c);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_c = 0;
  }

  // MATLABSystem: '<S3>/Read Parameter3'
  if (FLIGHT_hexacopter_DW.obj_n.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter3_SampleTime) {
    FLIGHT_hexacopter_DW.obj_n.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter3_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_n.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_k);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_k = 0;
  }

  // MATLABSystem: '<S3>/Read Parameter4'
  if (FLIGHT_hexacopter_DW.obj_c.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter4_SampleTime) {
    FLIGHT_hexacopter_DW.obj_c.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter4_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_c.MW_PARAMHANDLE,
    MW_INT32, &FLIGHT_hexacopter_B.ParamStep_cx);
  if (b_varargout_1) {
    FLIGHT_hexacopter_B.ParamStep_cx = 0;
  }

  // MATLABSystem: '<S3>/Read Parameter5'
  if (FLIGHT_hexacopter_DW.obj_aq.SampleTime !=
      FLIGHT_hexacopter_P.ReadParameter5_SampleTime) {
    FLIGHT_hexacopter_DW.obj_aq.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter5_SampleTime;
  }

  b_varargout_1 = MW_Param_Step(FLIGHT_hexacopter_DW.obj_aq.MW_PARAMHANDLE,
    MW_INT32, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0;
  }

  // Switch: '<S3>/Switch' incorporates:
  //   Constant: '<S3>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion3'
  //   MATLABSystem: '<S3>/Read Parameter13'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Product_k = i;
  } else {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Constant_Value_mc;
  }

  // Gain: '<S183>/Gain' incorporates:
  //   Switch: '<S3>/Switch'

  FLIGHT_hexacopter_B.Product_k *= FLIGHT_hexacopter_P.Gain_Gain_j;

  // Saturate: '<S183>/Saturation'
  if (FLIGHT_hexacopter_B.Product_k > FLIGHT_hexacopter_P.Saturation_UpperSat) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_UpperSat;
  } else if (FLIGHT_hexacopter_B.Product_k <
             FLIGHT_hexacopter_P.Saturation_LowerSat) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
  //   Constant: '<S183>/Constant'
  //   Product: '<S183>/Product'
  //   Saturate: '<S183>/Saturation'
  //   Sum: '<S183>/Sum'
  //   Sum: '<S183>/Sum1'

  FLIGHT_hexacopter_B.Product_k = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[0]) -
    FLIGHT_hexacopter_P.Constant_Value_kf) * FLIGHT_hexacopter_B.Product_k +
    FLIGHT_hexacopter_P.Constant_Value_kf);
  if (rtIsNaN(FLIGHT_hexacopter_B.Product_k) || rtIsInf
      (FLIGHT_hexacopter_B.Product_k)) {
    FLIGHT_hexacopter_B.Product_k = 0.0;
  } else {
    FLIGHT_hexacopter_B.Product_k = fmod(FLIGHT_hexacopter_B.Product_k, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[0] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Product_k < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_hexacopter_B.Product_k)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_hexacopter_B.Product_k)));

  // Switch: '<S3>/Switch1' incorporates:
  //   Constant: '<S3>/Constant1'
  //   DataTypeConversion: '<S3>/Data Type Conversion2'
  //   MATLABSystem: '<S3>/Read Parameter1'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_B.ParamStep;
  } else {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Constant1_Value;
  }

  // Gain: '<S184>/Gain' incorporates:
  //   Switch: '<S3>/Switch1'

  FLIGHT_hexacopter_B.Product_k *= FLIGHT_hexacopter_P.Gain_Gain_h;

  // Saturate: '<S184>/Saturation'
  if (FLIGHT_hexacopter_B.Product_k > FLIGHT_hexacopter_P.Saturation_UpperSat_m)
  {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_UpperSat_m;
  } else if (FLIGHT_hexacopter_B.Product_k <
             FLIGHT_hexacopter_P.Saturation_LowerSat_o) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_LowerSat_o;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
  //   Constant: '<S184>/Constant'
  //   Product: '<S184>/Product'
  //   Saturate: '<S184>/Saturation'
  //   Sum: '<S184>/Sum'
  //   Sum: '<S184>/Sum1'

  FLIGHT_hexacopter_B.Product_k = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[1]) -
    FLIGHT_hexacopter_P.Constant_Value_ms) * FLIGHT_hexacopter_B.Product_k +
    FLIGHT_hexacopter_P.Constant_Value_ms);
  if (rtIsNaN(FLIGHT_hexacopter_B.Product_k) || rtIsInf
      (FLIGHT_hexacopter_B.Product_k)) {
    FLIGHT_hexacopter_B.Product_k = 0.0;
  } else {
    FLIGHT_hexacopter_B.Product_k = fmod(FLIGHT_hexacopter_B.Product_k, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[1] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Product_k < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_hexacopter_B.Product_k)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_hexacopter_B.Product_k)));

  // Switch: '<S3>/Switch2' incorporates:
  //   Constant: '<S3>/Constant2'
  //   DataTypeConversion: '<S3>/Data Type Conversion'
  //   MATLABSystem: '<S3>/Read Parameter2'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_B.ParamStep_c;
  } else {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Constant2_Value;
  }

  // Gain: '<S185>/Gain' incorporates:
  //   Switch: '<S3>/Switch2'

  FLIGHT_hexacopter_B.Product_k *= FLIGHT_hexacopter_P.Gain_Gain_c;

  // Saturate: '<S185>/Saturation'
  if (FLIGHT_hexacopter_B.Product_k > FLIGHT_hexacopter_P.Saturation_UpperSat_b)
  {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_UpperSat_b;
  } else if (FLIGHT_hexacopter_B.Product_k <
             FLIGHT_hexacopter_P.Saturation_LowerSat_g) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_LowerSat_g;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
  //   Constant: '<S185>/Constant'
  //   Product: '<S185>/Product'
  //   Saturate: '<S185>/Saturation'
  //   Sum: '<S185>/Sum'
  //   Sum: '<S185>/Sum1'

  FLIGHT_hexacopter_B.Product_k = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[2]) -
    FLIGHT_hexacopter_P.Constant_Value_ii) * FLIGHT_hexacopter_B.Product_k +
    FLIGHT_hexacopter_P.Constant_Value_ii);
  if (rtIsNaN(FLIGHT_hexacopter_B.Product_k) || rtIsInf
      (FLIGHT_hexacopter_B.Product_k)) {
    FLIGHT_hexacopter_B.Product_k = 0.0;
  } else {
    FLIGHT_hexacopter_B.Product_k = fmod(FLIGHT_hexacopter_B.Product_k, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[2] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Product_k < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_hexacopter_B.Product_k)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_hexacopter_B.Product_k)));

  // Switch: '<S3>/Switch3' incorporates:
  //   Constant: '<S3>/Constant3'
  //   DataTypeConversion: '<S3>/Data Type Conversion4'
  //   MATLABSystem: '<S3>/Read Parameter3'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_B.ParamStep_k;
  } else {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Constant3_Value;
  }

  // Gain: '<S186>/Gain' incorporates:
  //   Switch: '<S3>/Switch3'

  FLIGHT_hexacopter_B.Product_k *= FLIGHT_hexacopter_P.Gain_Gain_n;

  // Saturate: '<S186>/Saturation'
  if (FLIGHT_hexacopter_B.Product_k > FLIGHT_hexacopter_P.Saturation_UpperSat_be)
  {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_UpperSat_be;
  } else if (FLIGHT_hexacopter_B.Product_k <
             FLIGHT_hexacopter_P.Saturation_LowerSat_e) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_LowerSat_e;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
  //   Constant: '<S186>/Constant'
  //   Product: '<S186>/Product'
  //   Saturate: '<S186>/Saturation'
  //   Sum: '<S186>/Sum'
  //   Sum: '<S186>/Sum1'

  FLIGHT_hexacopter_B.Product_k = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[3]) -
    FLIGHT_hexacopter_P.Constant_Value_j4x) * FLIGHT_hexacopter_B.Product_k +
    FLIGHT_hexacopter_P.Constant_Value_j4x);
  if (rtIsNaN(FLIGHT_hexacopter_B.Product_k) || rtIsInf
      (FLIGHT_hexacopter_B.Product_k)) {
    FLIGHT_hexacopter_B.Product_k = 0.0;
  } else {
    FLIGHT_hexacopter_B.Product_k = fmod(FLIGHT_hexacopter_B.Product_k, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[3] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Product_k < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_hexacopter_B.Product_k)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_hexacopter_B.Product_k)));

  // Switch: '<S3>/Switch4' incorporates:
  //   Constant: '<S3>/Constant4'
  //   DataTypeConversion: '<S3>/Data Type Conversion1'
  //   MATLABSystem: '<S3>/Read Parameter4'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_B.ParamStep_cx;
  } else {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Constant4_Value;
  }

  // Gain: '<S187>/Gain' incorporates:
  //   Switch: '<S3>/Switch4'

  FLIGHT_hexacopter_B.Product_k *= FLIGHT_hexacopter_P.Gain_Gain_f;

  // Saturate: '<S187>/Saturation'
  if (FLIGHT_hexacopter_B.Product_k > FLIGHT_hexacopter_P.Saturation_UpperSat_d)
  {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_UpperSat_d;
  } else if (FLIGHT_hexacopter_B.Product_k <
             FLIGHT_hexacopter_P.Saturation_LowerSat_l) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_LowerSat_l;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
  //   Constant: '<S187>/Constant'
  //   Product: '<S187>/Product'
  //   Saturate: '<S187>/Saturation'
  //   Sum: '<S187>/Sum'
  //   Sum: '<S187>/Sum1'

  FLIGHT_hexacopter_B.Product_k = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[4]) -
    FLIGHT_hexacopter_P.Constant_Value_l) * FLIGHT_hexacopter_B.Product_k +
    FLIGHT_hexacopter_P.Constant_Value_l);
  if (rtIsNaN(FLIGHT_hexacopter_B.Product_k) || rtIsInf
      (FLIGHT_hexacopter_B.Product_k)) {
    FLIGHT_hexacopter_B.Product_k = 0.0;
  } else {
    FLIGHT_hexacopter_B.Product_k = fmod(FLIGHT_hexacopter_B.Product_k, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[4] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Product_k < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_hexacopter_B.Product_k)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_hexacopter_B.Product_k)));

  // Switch: '<S3>/Switch5' incorporates:
  //   Constant: '<S3>/Constant5'
  //   DataTypeConversion: '<S3>/Data Type Conversion5'
  //   MATLABSystem: '<S3>/Read Parameter5'
  //
  if (rtb_Compare_a) {
    FLIGHT_hexacopter_B.Product_k = ParamStep;
  } else {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Constant5_Value;
  }

  // Gain: '<S188>/Gain' incorporates:
  //   Switch: '<S3>/Switch5'

  FLIGHT_hexacopter_B.Product_k *= FLIGHT_hexacopter_P.Gain_Gain_m;

  // Saturate: '<S188>/Saturation'
  if (FLIGHT_hexacopter_B.Product_k > FLIGHT_hexacopter_P.Saturation_UpperSat_i)
  {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_UpperSat_i;
  } else if (FLIGHT_hexacopter_B.Product_k <
             FLIGHT_hexacopter_P.Saturation_LowerSat_n) {
    FLIGHT_hexacopter_B.Product_k = FLIGHT_hexacopter_P.Saturation_LowerSat_n;
  }

  // DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
  //   Constant: '<S188>/Constant'
  //   Product: '<S188>/Product'
  //   Saturate: '<S188>/Saturation'
  //   Sum: '<S188>/Sum'
  //   Sum: '<S188>/Sum1'

  FLIGHT_hexacopter_B.Product_k = floor((static_cast<real_T>
    (FLIGHT_hexacopter_B.DataTypeConversion6[5]) -
    FLIGHT_hexacopter_P.Constant_Value_o) * FLIGHT_hexacopter_B.Product_k +
    FLIGHT_hexacopter_P.Constant_Value_o);
  if (rtIsNaN(FLIGHT_hexacopter_B.Product_k) || rtIsInf
      (FLIGHT_hexacopter_B.Product_k)) {
    FLIGHT_hexacopter_B.Product_k = 0.0;
  } else {
    FLIGHT_hexacopter_B.Product_k = fmod(FLIGHT_hexacopter_B.Product_k, 65536.0);
  }

  FLIGHT_hexacopter_B.DataTypeConversion7[5] = static_cast<uint16_T>
    (FLIGHT_hexacopter_B.Product_k < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_hexacopter_B.Product_k)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_hexacopter_B.Product_k)));

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
  if (rtb_Compare) {
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
    if (!rtb_Compare) {
      pwm_disarm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_hexacopter_DW.obj_dl.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'

  // Gain: '<S582>/1//2' incorporates:
  //   Constant: '<Root>/Constant'

  rtb_SinCos_o1 = FLIGHT_hexacopter_P.u2_Gain *
    FLIGHT_hexacopter_P.Constant_Value_a;
  rtb_NProdOut_g = FLIGHT_hexacopter_P.u2_Gain * FLIGHT_hexacopter_B.Merge1[1];
  rtb_Saturation3 = FLIGHT_hexacopter_P.u2_Gain * FLIGHT_hexacopter_B.Merge1[0];

  // Trigonometry: '<S582>/sincos'
  rtb_IProdOut_p = static_cast<real32_T>(cos(static_cast<real_T>(rtb_SinCos_o1)));
  rtb_SinCos_o1 = static_cast<real32_T>(sin(static_cast<real_T>(rtb_SinCos_o1)));
  rtb_SinCos_o2 = static_cast<real32_T>(cos(static_cast<real_T>(rtb_NProdOut_g)));
  rtb_NProdOut_g = static_cast<real32_T>(sin(static_cast<real_T>(rtb_NProdOut_g)));
  rtb_IProdOut_c = static_cast<real32_T>(cos(static_cast<real_T>(rtb_Saturation3)));
  rtb_NProdOut_a = static_cast<real32_T>(sin(static_cast<real_T>(rtb_Saturation3)));
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_p);

  // BusAssignment: '<S12>/Bus Assignment' incorporates:
  //   Constant: '<S580>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_d = FLIGHT_hexacopter_P.Constant_Value_j;

  // BusAssignment: '<S12>/Bus Assignment' incorporates:
  //   Constant: '<S12>/Constant'
  //   MATLABSystem: '<S12>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_d.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_p.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_d.roll_body = FLIGHT_hexacopter_B.Merge1[0];
  FLIGHT_hexacopter_B.BusAssignment_d.pitch_body = FLIGHT_hexacopter_B.Merge1[1];
  FLIGHT_hexacopter_B.BusAssignment_d.yaw_sp_move_rate =
    FLIGHT_hexacopter_B.Merge1[2];
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_gqy;
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_gqy;
  FLIGHT_hexacopter_B.BusAssignment_d.thrust_body[2] =
    FLIGHT_hexacopter_B.Merge1[3];

  // Fcn: '<S582>/q0' incorporates:
  //   Fcn: '<S582>/q1'
  //   Trigonometry: '<S582>/sincos'

  rtb_Saturation3 = rtb_IProdOut_p * rtb_SinCos_o2;
  tmp_2 = rtb_SinCos_o1 * rtb_NProdOut_g;

  // BusAssignment: '<S12>/Bus Assignment' incorporates:
  //   Fcn: '<S582>/q0'
  //   Fcn: '<S582>/q1'
  //   Trigonometry: '<S582>/sincos'

  FLIGHT_hexacopter_B.BusAssignment_d.q_d[0] = rtb_Saturation3 * rtb_IProdOut_c
    + tmp_2 * rtb_NProdOut_a;
  FLIGHT_hexacopter_B.BusAssignment_d.q_d[1] = rtb_Saturation3 * rtb_NProdOut_a
    - tmp_2 * rtb_IProdOut_c;

  // Fcn: '<S582>/q2' incorporates:
  //   Fcn: '<S582>/q3'
  //   Trigonometry: '<S582>/sincos'

  rtb_Saturation3 = rtb_SinCos_o1 * rtb_SinCos_o2;
  tmp_2 = rtb_IProdOut_p * rtb_NProdOut_g;

  // BusAssignment: '<S12>/Bus Assignment' incorporates:
  //   Fcn: '<S582>/q2'
  //   Fcn: '<S582>/q3'
  //   Trigonometry: '<S582>/sincos'

  FLIGHT_hexacopter_B.BusAssignment_d.q_d[2] = tmp_2 * rtb_IProdOut_c +
    rtb_Saturation3 * rtb_NProdOut_a;
  FLIGHT_hexacopter_B.BusAssignment_d.q_d[3] = rtb_Saturation3 * rtb_IProdOut_c
    - tmp_2 * rtb_NProdOut_a;

  // MATLABSystem: '<S581>/SinkBlock' incorporates:
  //   BusAssignment: '<S12>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_d);
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_o);

  // BusAssignment: '<S575>/Bus Assignment' incorporates:
  //   Constant: '<S11>/Constant'
  //   Constant: '<S11>/Constant2'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   MATLABSystem: '<S575>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_o.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment.noutputs =
    FLIGHT_hexacopter_P.Constant2_Value_e;
  for (i = 0; i < 6; i++) {
    FLIGHT_hexacopter_B.BusAssignment.output[i] =
      FLIGHT_hexacopter_B.DataTypeConversion_j[i];
    FLIGHT_hexacopter_B.BusAssignment.output[i + 6] =
      FLIGHT_hexacopter_B.DataTypeConversion7[i];
  }

  FLIGHT_hexacopter_B.BusAssignment.output[12] =
    FLIGHT_hexacopter_P.Constant_Value_bm[0];
  FLIGHT_hexacopter_B.BusAssignment._padding0[0] = 0U;
  FLIGHT_hexacopter_B.BusAssignment.output[13] =
    FLIGHT_hexacopter_P.Constant_Value_bm[1];
  FLIGHT_hexacopter_B.BusAssignment._padding0[1] = 0U;
  FLIGHT_hexacopter_B.BusAssignment.output[14] =
    FLIGHT_hexacopter_P.Constant_Value_bm[2];
  FLIGHT_hexacopter_B.BusAssignment._padding0[2] = 0U;
  FLIGHT_hexacopter_B.BusAssignment.output[15] =
    FLIGHT_hexacopter_P.Constant_Value_bm[3];
  FLIGHT_hexacopter_B.BusAssignment._padding0[3] = 0U;

  // End of BusAssignment: '<S575>/Bus Assignment'

  // MATLABSystem: '<S579>/SinkBlock' incorporates:
  //   BusAssignment: '<S575>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_px.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_px.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment);
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_n);
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp);

  // BusAssignment: '<S574>/Bus Assignment' incorporates:
  //   Constant: '<S573>/Constant'
  //   Gain: '<S573>/Gain'
  //   MATLABSystem: '<S11>/PX4 Timestamp'
  //   MATLABSystem: '<S574>/PX4 Timestamp'
  //   Saturate: '<S573>/Saturation'
  //   Sum: '<S573>/Subtract'

  FLIGHT_hexacopter_B.BusAssignment_f.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_n.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_f.timestamp_sample =
    FLIGHT_hexacopter_B.PX4Timestamp.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_f.reversible_flags = 0U;
  for (i = 0; i < 6; i++) {
    // Saturate: '<S573>/Saturation'
    FLIGHT_hexacopter_B.ParamStep = FLIGHT_hexacopter_B.DataTypeConversion_j[i];
    if (FLIGHT_hexacopter_B.ParamStep >
        FLIGHT_hexacopter_P.Saturation_UpperSat_ep) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation_UpperSat_ep;
    } else if (FLIGHT_hexacopter_B.ParamStep <
               FLIGHT_hexacopter_P.Saturation_LowerSat_p) {
      rtb_Saturation3 = FLIGHT_hexacopter_P.Saturation_LowerSat_p;
    } else {
      rtb_Saturation3 = static_cast<real32_T>(FLIGHT_hexacopter_B.ParamStep);
    }

    FLIGHT_hexacopter_B.BusAssignment_f.control[i] = (rtb_Saturation3 -
      FLIGHT_hexacopter_P.Constant_Value_ez) * FLIGHT_hexacopter_P.Gain_Gain_mg;

    // Saturate: '<S573>/Saturation' incorporates:
    //   Constant: '<S11>/Constant1'
    //   Constant: '<S573>/Constant'
    //   Gain: '<S573>/Gain'
    //   Sum: '<S573>/Subtract'

    rtb_IProdOut_p = FLIGHT_hexacopter_P.Constant1_Value_i[i];
    if (rtb_IProdOut_p > FLIGHT_hexacopter_P.Saturation_UpperSat_ep) {
      rtb_IProdOut_p = FLIGHT_hexacopter_P.Saturation_UpperSat_ep;
    } else if (rtb_IProdOut_p < FLIGHT_hexacopter_P.Saturation_LowerSat_p) {
      rtb_IProdOut_p = FLIGHT_hexacopter_P.Saturation_LowerSat_p;
    }

    FLIGHT_hexacopter_B.BusAssignment_f.control[i + 6] = (rtb_IProdOut_p -
      FLIGHT_hexacopter_P.Constant_Value_ez) * FLIGHT_hexacopter_P.Gain_Gain_mg;
    FLIGHT_hexacopter_B.BusAssignment_f._padding0[i] = 0U;
  }

  // End of BusAssignment: '<S574>/Bus Assignment'

  // MATLABSystem: '<S577>/SinkBlock' incorporates:
  //   BusAssignment: '<S574>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_f);

  // BusAssignment: '<S15>/Bus Assignment' incorporates:
  //   Constant: '<S587>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_n = FLIGHT_hexacopter_P.Constant_Value_n1;

  // BusAssignment: '<S15>/Bus Assignment'
  FLIGHT_hexacopter_B.BusAssignment_n.xyz[0] = FLIGHT_hexacopter_B.Sum_cc;
  FLIGHT_hexacopter_B.BusAssignment_n.xyz[1] = FLIGHT_hexacopter_B.Sum_a;
  FLIGHT_hexacopter_B.BusAssignment_n.xyz[2] = FLIGHT_hexacopter_B.Sum_i;

  // MATLABSystem: '<S588>/SinkBlock' incorporates:
  //   BusAssignment: '<S15>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_my.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_my.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_n);
  FLIGHT_hexacopter_PX4Timestamp(&FLIGHT_hexacopter_B.PX4Timestamp_pna);

  // BusAssignment: '<S14>/Bus Assignment' incorporates:
  //   Constant: '<S585>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_e = FLIGHT_hexacopter_P.Constant_Value_i;

  // BusAssignment: '<S14>/Bus Assignment' incorporates:
  //   Constant: '<S14>/Constant'
  //   MATLABSystem: '<S14>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_e.timestamp =
    FLIGHT_hexacopter_B.PX4Timestamp_pna.PX4Timestamp;
  FLIGHT_hexacopter_B.BusAssignment_e.roll = FLIGHT_hexacopter_B.Switch2;
  FLIGHT_hexacopter_B.BusAssignment_e.pitch = FLIGHT_hexacopter_B.Switch2_i;
  FLIGHT_hexacopter_B.BusAssignment_e.yaw = FLIGHT_hexacopter_B.Merge1[2];
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[0] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[1] =
    FLIGHT_hexacopter_P.Constant_Value_ll;
  FLIGHT_hexacopter_B.BusAssignment_e.thrust_body[2] =
    FLIGHT_hexacopter_B.Merge1[3];

  // MATLABSystem: '<S586>/SinkBlock' incorporates:
  //   BusAssignment: '<S14>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_e);

  // MATLABSystem: '<S13>/PX4 Timestamp'
  FLIGHT_hexacopter_B.rtb_PX4Timestamp_m = hrt_absolute_time();

  // BusAssignment: '<S13>/Bus Assignment' incorporates:
  //   Constant: '<S583>/Constant'

  FLIGHT_hexacopter_B.BusAssignment_g = FLIGHT_hexacopter_P.Constant_Value_n;

  // BusAssignment: '<S13>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S13>/PX4 Timestamp'

  FLIGHT_hexacopter_B.BusAssignment_g.timestamp =
    FLIGHT_hexacopter_B.rtb_PX4Timestamp_m;
  FLIGHT_hexacopter_B.BusAssignment_g.vx = FLIGHT_hexacopter_B.PProdOut[0];
  FLIGHT_hexacopter_B.BusAssignment_g.vy = FLIGHT_hexacopter_B.PProdOut[1];
  FLIGHT_hexacopter_B.BusAssignment_g.vz = FLIGHT_hexacopter_B.Merge;
  FLIGHT_hexacopter_B.BusAssignment_g.x =
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0];
  FLIGHT_hexacopter_B.BusAssignment_g.y =
    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1];
  FLIGHT_hexacopter_B.BusAssignment_g.z = FLIGHT_hexacopter_B.Add;

  // MATLABSystem: '<S584>/SinkBlock' incorporates:
  //   BusAssignment: '<S13>/Bus Assignment'

  uORB_write_step(FLIGHT_hexacopter_DW.obj_pa.orbMetadataObj,
                  &FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj,
                  &FLIGHT_hexacopter_B.BusAssignment_g);

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.0025, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  FLIGHT_hexacopter_M->Timing.clockTick0++;
}

// Model initialize function
void FLIGHT_hexacopter_initialize(void)
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
    static const char_T ParameterNameStr_5[16] = "MC_ROLLRATE_MAX";
    static const char_T ParameterNameStr_6[10] = "MC_ROLL_P";
    static const char_T ParameterNameStr_7[17] = "MC_PITCHRATE_MAX";
    static const char_T ParameterNameStr_8[11] = "MC_PITCH_P";
    static const char_T ParameterNameStr_9[14] = "MC_ROLLRATE_D";
    static const char_T ParameterNameStr_a[14] = "MC_ROLLRATE_P";
    static const char_T ParameterNameStr_b[14] = "MC_ROLLRATE_I";
    static const char_T ParameterNameStr_c[15] = "MC_PITCHRATE_D";
    static const char_T ParameterNameStr_d[15] = "MC_PITCHRATE_P";
    static const char_T ParameterNameStr_e[15] = "MC_PITCHRATE_I";
    static const char_T ParameterNameStr_f[13] = "MC_YAWRATE_D";
    static const char_T ParameterNameStr_g[13] = "MC_YAWRATE_P";
    static const char_T ParameterNameStr_h[13] = "MC_YAWRATE_I";
    static const char_T ParameterNameStr_i[9] = "MPC_XY_P";
    static const char_T ParameterNameStr_j[17] = "MPC_XY_VEL_P_ACC";
    static const char_T ParameterNameStr_k[8] = "MPC_Z_P";
    real_T tmp;
    int32_T i;

    // SystemInitialize for Enabled SubSystem: '<S413>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S414>/In1' incorporates:
    //   Outport: '<S414>/Out1'

    FLIGHT_hexacopter_B.In1_n = FLIGHT_hexacopter_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S413>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S403>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S406>/In1' incorporates:
    //   Outport: '<S406>/Out1'

    FLIGHT_hexacopter_B.In1 = FLIGHT_hexacopter_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S403>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem'
    // SystemInitialize for Enabled SubSystem: '<S4>/XY Pos Controller'
    // Start for MATLABSystem: '<S192>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_eq.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_eq.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_eq.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_eq.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_eq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_eq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S192>/Read Parameter'

    // SystemInitialize for Product: '<S337>/PProd Out' incorporates:
    //   Outport: '<S192>/des_vxvy'

    FLIGHT_hexacopter_B.PProdOut[0] = FLIGHT_hexacopter_P.des_vxvy_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/XY Pos Controller'

    // SystemInitialize for SignalConversion generated from: '<S4>/des_xy' incorporates:
    //   Constant: '<S4>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[0] =
      FLIGHT_hexacopter_P.Constant_Value_k[0];

    // SystemInitialize for Enabled SubSystem: '<S4>/XY Pos Controller'
    // SystemInitialize for Product: '<S337>/PProd Out' incorporates:
    //   Outport: '<S192>/des_vxvy'

    FLIGHT_hexacopter_B.PProdOut[1] = FLIGHT_hexacopter_P.des_vxvy_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/XY Pos Controller'

    // SystemInitialize for SignalConversion generated from: '<S4>/des_xy' incorporates:
    //   Constant: '<S4>/Constant'

    FLIGHT_hexacopter_B.OutportBufferFordes_xy[1] =
      FLIGHT_hexacopter_P.Constant_Value_k[1];

    // SystemInitialize for Enabled SubSystem: '<S4>/XY Velocity Controller'
    // Start for MATLABSystem: '<S193>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pi.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_pi.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_pi.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_pi.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_pi.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S193>/Read Parameter'

    // SystemInitialize for Gain: '<S193>/Gain1' incorporates:
    //   Outport: '<S193>/des_pitch'

    FLIGHT_hexacopter_B.Gain1 = FLIGHT_hexacopter_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S193>/des_roll' incorporates:
    //   Saturate: '<S193>/Saturation'

    FLIGHT_hexacopter_B.Saturation[1] = FLIGHT_hexacopter_P.des_roll_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/XY Velocity Controller'

    // SystemInitialize for Enabled SubSystem: '<S4>/Altitude Controller'
    // Start for MATLABSystem: '<S189>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_m.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_m.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_m.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S189>/Read Parameter1'
    // End of SystemInitialize for SubSystem: '<S4>/Altitude Controller'

    // SystemInitialize for Enabled SubSystem: '<S4>/Vz Controller'
    // InitializeConditions for DiscreteIntegrator: '<S276>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_g =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_l;
    FLIGHT_hexacopter_DW.Filter_PrevResetState = 2;

    // InitializeConditions for DiscreteIntegrator: '<S281>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_k =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_i;
    FLIGHT_hexacopter_DW.Integrator_PrevResetState = 2;
    FLIGHT_hexa_ReadParameter3_Init(&FLIGHT_hexacopter_DW.ReadParameter3_pn);
    FLIGHT_hexa_ReadParameter1_Init(&FLIGHT_hexacopter_DW.ReadParameter1_pnae);
    FLIGHT_hex_ReadParameter_e_Init(&FLIGHT_hexacopter_DW.ReadParameter_pna);
    FLIGHT_hexa_ReadParameter2_Init(&FLIGHT_hexacopter_DW.ReadParameter2_pn);

    // SystemInitialize for Sum: '<S191>/Sum6' incorporates:
    //   Outport: '<S191>/throttle'
    //   Saturate: '<S191>/Saturation1'

    FLIGHT_hexacopter_B.Saturation1 = FLIGHT_hexacopter_P.throttle_Y0_o;

    // SystemInitialize for Product: '<S233>/PProd Out' incorporates:
    //   Outport: '<S191>/log_alt'
    //   SignalConversion generated from: '<S191>/des_vz'

    FLIGHT_hexacopter_B.des_vz = FLIGHT_hexacopter_P.log_alt_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Vz Controller'

    // SystemInitialize for Sum: '<S4>/Add' incorporates:
    //   Outport: '<S4>/des_z'

    FLIGHT_hexacopter_B.Add = FLIGHT_hexacopter_P.des_z_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem'

    // SystemInitialize for IfAction SubSystem: '<Root>/Altitude_Mode'
    // SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem'
    // Start for FromWorkspace: '<S21>/fromWS_Signal 1'
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, -1.0, -1.0, 1.0, 1.0, 0.0, 0.0
      } ;

      FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK_i.TimePtr = static_cast<void *>
        (pTimeValues0);
      FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK_i.DataPtr = static_cast<void *>
        (pDataValues0);
      FLIGHT_hexacopter_DW.fromWS_Signal1_IWORK_n.PrevIndex = 0;
    }

    FLIGHT_hexac_ReadParameter_Init(&FLIGHT_hexacopter_DW.ReadParameter_p);

    // SystemInitialize for Outport: '<S18>/doublet' incorporates:
    //   Sum: '<S22>/Sum'
    //   UnitDelay: '<S22>/UD'
    //
    //  Block description for '<S22>/Sum':
    //
    //   Add in CPU
    //
    //  Block description for '<S22>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE_j = FLIGHT_hexacopter_P.doublet_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1>/Vz Controller'
    // InitializeConditions for DiscreteIntegrator: '<S54>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_i =
      FLIGHT_hexacopter_P.PIDController4_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S59>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_e =
      FLIGHT_hexacopter_P.PIDController4_InitialConditi_a;
    FLIGHT_hexa_ReadParameter3_Init(&FLIGHT_hexacopter_DW.ReadParameter3_p);
    FLIGHT_hexa_ReadParameter1_Init(&FLIGHT_hexacopter_DW.ReadParameter1_pn);
    FLIGHT_hex_ReadParameter_e_Init(&FLIGHT_hexacopter_DW.ReadParameter_pn);
    FLIGHT_hexa_ReadParameter2_Init(&FLIGHT_hexacopter_DW.ReadParameter2_p);

    // SystemInitialize for Sum: '<S19>/Sum6' incorporates:
    //   Outport: '<S19>/throttle'
    //   Saturate: '<S19>/Saturation1'

    FLIGHT_hexacopter_B.Saturation1_i = FLIGHT_hexacopter_P.throttle_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Vz Controller'
    // End of SystemInitialize for SubSystem: '<Root>/Altitude_Mode'

    // SystemInitialize for IfAction SubSystem: '<Root>/Stabilized_Mode'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // Start for FromWorkspace: '<S571>/fromWS_Signal 1'
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, -1.0, -1.0, 1.0, 1.0, 0.0, 0.0
      } ;

      FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK.TimePtr = static_cast<void *>
        (pTimeValues0);
      FLIGHT_hexacopter_DW.fromWS_Signal1_PWORK.DataPtr = static_cast<void *>
        (pDataValues0);
      FLIGHT_hexacopter_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
    }

    FLIGHT_hexac_ReadParameter_Init(&FLIGHT_hexacopter_DW.ReadParameter_pnaevv);

    // SystemInitialize for Outport: '<S569>/doublet' incorporates:
    //   Sum: '<S572>/Sum'
    //   UnitDelay: '<S572>/UD'
    //
    //  Block description for '<S572>/Sum':
    //
    //   Add in CPU
    //
    //  Block description for '<S572>/UD':
    //
    //   Store in Global RAM

    FLIGHT_hexacopter_DW.UD_DSTATE = FLIGHT_hexacopter_P.doublet_Y0_a;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Stabilized_Mode'

    // SystemInitialize for Merge: '<Root>/Merge1'
    FLIGHT_hexacopter_B.Merge1[0] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[1] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[2] = FLIGHT_hexacopter_P.Merge1_InitialOutput;
    FLIGHT_hexacopter_B.Merge1[3] = FLIGHT_hexacopter_P.Merge1_InitialOutput;

    // SystemInitialize for Enabled SubSystem: '<S408>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S409>/In1' incorporates:
    //   Outport: '<S409>/Out1'

    FLIGHT_hexacopter_B.In1_k = FLIGHT_hexacopter_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S408>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/CAS'
    // Start for MATLABSystem: '<S2>/Read Parameter9'
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_k.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_k.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_k.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter9'

    // Start for MATLABSystem: '<S2>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_jz.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_jz.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_jz.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_jz.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_jz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_jz.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter'

    // Start for MATLABSystem: '<S2>/Read Parameter10'
    FLIGHT_hexacopter_DW.obj_ds.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ds.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_ds.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_ds.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_ds.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_ds.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ds.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter10'

    // Start for MATLABSystem: '<S2>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_o.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_o.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_o.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_o.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/Read Parameter1'

    // SystemInitialize for Product: '<S169>/PProd Out' incorporates:
    //   Outport: '<S2>/des_p'
    //   Switch: '<S172>/Switch2'

    FLIGHT_hexacopter_B.Switch2 = FLIGHT_hexacopter_P.des_p_Y0;

    // SystemInitialize for Product: '<S118>/PProd Out' incorporates:
    //   Outport: '<S2>/des_q'
    //   Switch: '<S121>/Switch2'

    FLIGHT_hexacopter_B.Switch2_i = FLIGHT_hexacopter_P.des_q_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/CAS'

    // SystemInitialize for Enabled SubSystem: '<S404>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S407>/In1' incorporates:
    //   Outport: '<S407>/Out1'

    FLIGHT_hexacopter_B.In1_h = FLIGHT_hexacopter_P.Out1_Y0_pn;

    // End of SystemInitialize for SubSystem: '<S404>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/SAS'
    // InitializeConditions for DiscreteIntegrator: '<S496>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE =
      FLIGHT_hexacopter_P.PIDController2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S501>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE =
      FLIGHT_hexacopter_P.PIDController2_InitialConditi_c;

    // InitializeConditions for DiscreteIntegrator: '<S446>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_j =
      FLIGHT_hexacopter_P.PIDController1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S451>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_c =
      FLIGHT_hexacopter_P.PIDController1_InitialConditi_c;

    // InitializeConditions for DiscreteIntegrator: '<S546>/Filter'
    FLIGHT_hexacopter_DW.Filter_DSTATE_h =
      FLIGHT_hexacopter_P.PIDController6_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S551>/Integrator'
    FLIGHT_hexacopter_DW.Integrator_DSTATE_l =
      FLIGHT_hexacopter_P.PIDController6_InitialConditi_h;

    // Start for MATLABSystem: '<S8>/Read Parameter2'
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_d.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_d.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_d.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter2'

    // Start for MATLABSystem: '<S8>/Read Parameter'
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_i.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_i.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_i.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_i.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter'

    // Start for MATLABSystem: '<S8>/Read Parameter1'
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_e.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_e.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_e.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_e.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter1'

    // Start for MATLABSystem: '<S8>/Read Parameter5'
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_h.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_h.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_h.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_h.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter5'

    // Start for MATLABSystem: '<S8>/Read Parameter3'
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_b.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_b.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_b.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter3'

    // Start for MATLABSystem: '<S8>/Read Parameter4'
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

    // End of Start for MATLABSystem: '<S8>/Read Parameter4'

    // Start for MATLABSystem: '<S8>/Read Parameter8'
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_f
      [0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter8'

    // Start for MATLABSystem: '<S8>/Read Parameter6'
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_a.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_a.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter6'

    // Start for MATLABSystem: '<S8>/Read Parameter7'
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_j.SampleTime = FLIGHT_hexacopter_P.SampleTime;
    FLIGHT_hexacopter_DW.obj_j.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_j.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_j.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/Read Parameter7'

    // SystemInitialize for Sum: '<S510>/Sum' incorporates:
    //   Outport: '<S8>/tau_roll'

    FLIGHT_hexacopter_B.Sum_cc = FLIGHT_hexacopter_P.tau_roll_Y0;

    // SystemInitialize for Sum: '<S460>/Sum' incorporates:
    //   Outport: '<S8>/tau_pitch'

    FLIGHT_hexacopter_B.Sum_a = FLIGHT_hexacopter_P.tau_pitch_Y0;

    // SystemInitialize for Sum: '<S560>/Sum' incorporates:
    //   Outport: '<S8>/tau_yaw'

    FLIGHT_hexacopter_B.Sum_i = FLIGHT_hexacopter_P.tau_yaw_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/SAS'

    // SystemInitialize for Enabled SubSystem: '<Root>/Mixer'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Saturate: '<S5>/Output_Limits1' incorporates:
      //   Outport: '<S5>/PWM'

      FLIGHT_hexacopter_B.Output_Limits1[i] = FLIGHT_hexacopter_P.PWM_Y0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/Mixer'

    // SystemInitialize for Gain: '<S16>/Gain' incorporates:
    //   Merge: '<Root>/Merge'

    FLIGHT_hexacopter_B.Merge = FLIGHT_hexacopter_P.Merge_InitialOutput;

    // Start for MATLABSystem: '<S413>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_p2.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_p2.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_p2.eventStructObj);
    FLIGHT_hexacopter_DW.obj_p2.isSetupComplete = true;

    // Start for MATLABSystem: '<S403>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_kk.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_kk.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_kk.eventStructObj);
    FLIGHT_hexacopter_DW.obj_kk.isSetupComplete = true;

    // Start for MATLABSystem: '<S408>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ab.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_ab.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    FLIGHT_hexacopter_DW.obj_ab.isSetupComplete = true;

    // Start for MATLABSystem: '<S404>/SourceBlock'
    FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pe.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj = ORB_ID(vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_hexacopter_DW.obj_pe.orbMetadataObj,
                         &FLIGHT_hexacopter_DW.obj_pe.eventStructObj);
    FLIGHT_hexacopter_DW.obj_pe.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/Read Parameter13'
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_g.SampleTime =
      FLIGHT_hexacopter_P.ReadParameter13_SampleTime;
    FLIGHT_hexacopter_DW.obj_g.isInitialized = 1;
    if (FLIGHT_hexacopter_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_hexacopter_DW.obj_g.SampleTime;
    }

    FLIGHT_hexacopter_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr
      [0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter13'

    // Start for MATLABSystem: '<S3>/Read Parameter1'
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
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_j5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter1'

    // Start for MATLABSystem: '<S3>/Read Parameter2'
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
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_ao.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter2'

    // Start for MATLABSystem: '<S3>/Read Parameter3'
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
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter3'

    // Start for MATLABSystem: '<S3>/Read Parameter4'
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
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter4'

    // Start for MATLABSystem: '<S3>/Read Parameter5'
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
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_hexacopter_DW.obj_aq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/Read Parameter5'

    // Start for MATLABSystem: '<Root>/PX4 PWM Output'
    FLIGHT_hexacopter_DW.obj_dl.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_dl.isSetupComplete = false;
    FLIGHT_hexacopter_DW.obj_dl.isInitialized = 1;
    FLIGHT_hexacopter_PWM_setupImpl(&FLIGHT_hexacopter_DW.obj_dl, false, false);
    FLIGHT_hexacopter_DW.obj_dl.isSetupComplete = true;
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S581>/SinkBlock' incorporates:
    //   BusAssignment: '<S12>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_pt.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_pt.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_d, 1);
    FLIGHT_hexacopter_DW.obj_pt.isSetupComplete = true;
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_o);

    // Start for MATLABSystem: '<S579>/SinkBlock' incorporates:
    //   BusAssignment: '<S575>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_px.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_px.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_px.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_px.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_px.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment, 1);
    FLIGHT_hexacopter_DW.obj_px.isSetupComplete = true;
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_n);
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S577>/SinkBlock' incorporates:
    //   BusAssignment: '<S574>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_hf.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_hf.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_f, 1);
    FLIGHT_hexacopter_DW.obj_hf.isSetupComplete = true;

    // Start for MATLABSystem: '<S588>/SinkBlock' incorporates:
    //   BusAssignment: '<S15>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_my.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_my.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_my.orbMetadataObj = ORB_ID(vehicle_torque_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_my.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_my.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_n, 1);
    FLIGHT_hexacopter_DW.obj_my.isSetupComplete = true;
    FLIGHT_hexaco_PX4Timestamp_Init(&FLIGHT_hexacopter_DW.PX4Timestamp_pna);

    // Start for MATLABSystem: '<S586>/SinkBlock' incorporates:
    //   BusAssignment: '<S14>/Bus Assignment'

    FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_a4.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
    uORB_write_initialize(FLIGHT_hexacopter_DW.obj_a4.orbMetadataObj,
                          &FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj,
                          &FLIGHT_hexacopter_B.BusAssignment_e, 1);
    FLIGHT_hexacopter_DW.obj_a4.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/PX4 Timestamp'
    FLIGHT_hexacopter_DW.obj_ky.matlabCodegenIsDeleted = false;
    FLIGHT_hexacopter_DW.obj_ky.isInitialized = 1;
    FLIGHT_hexacopter_DW.obj_ky.isSetupComplete = true;

    // Start for MATLABSystem: '<S584>/SinkBlock' incorporates:
    //   BusAssignment: '<S13>/Bus Assignment'

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
  // Terminate for MATLABSystem: '<S413>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p2.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_p2.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_p2.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_p2.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S413>/SourceBlock'

  // Terminate for MATLABSystem: '<S403>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_kk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_kk.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_kk.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_kk.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S403>/SourceBlock'

  // Terminate for IfAction SubSystem: '<Root>/If Action Subsystem'
  // Terminate for Enabled SubSystem: '<S4>/XY Pos Controller'
  // Terminate for MATLABSystem: '<S192>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_eq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S192>/Read Parameter'
  // End of Terminate for SubSystem: '<S4>/XY Pos Controller'

  // Terminate for Enabled SubSystem: '<S4>/XY Velocity Controller'
  // Terminate for MATLABSystem: '<S193>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S193>/Read Parameter'
  // End of Terminate for SubSystem: '<S4>/XY Velocity Controller'

  // Terminate for Enabled SubSystem: '<S4>/Altitude Controller'
  // Terminate for MATLABSystem: '<S189>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S189>/Read Parameter1'
  // End of Terminate for SubSystem: '<S4>/Altitude Controller'

  // Terminate for Enabled SubSystem: '<S4>/Vz Controller'
  FLIGHT_hexa_ReadParameter3_Term(&FLIGHT_hexacopter_DW.ReadParameter3_pn);
  FLIGHT_hexa_ReadParameter1_Term(&FLIGHT_hexacopter_DW.ReadParameter1_pnae);
  FLIGHT_hex_ReadParameter_a_Term(&FLIGHT_hexacopter_DW.ReadParameter_pna);
  FLIGHT_hexa_ReadParameter2_Term(&FLIGHT_hexacopter_DW.ReadParameter2_pn);

  // End of Terminate for SubSystem: '<S4>/Vz Controller'
  // End of Terminate for SubSystem: '<Root>/If Action Subsystem'

  // Terminate for IfAction SubSystem: '<Root>/Altitude_Mode'
  // Terminate for Enabled SubSystem: '<S1>/Enabled Subsystem'
  FLIGHT_hexac_ReadParameter_Term(&FLIGHT_hexacopter_DW.ReadParameter_p);

  // End of Terminate for SubSystem: '<S1>/Enabled Subsystem'

  // Terminate for Enabled SubSystem: '<S1>/Vz Controller'
  FLIGHT_hexa_ReadParameter3_Term(&FLIGHT_hexacopter_DW.ReadParameter3_p);
  FLIGHT_hexa_ReadParameter1_Term(&FLIGHT_hexacopter_DW.ReadParameter1_pn);
  FLIGHT_hex_ReadParameter_a_Term(&FLIGHT_hexacopter_DW.ReadParameter_pn);
  FLIGHT_hexa_ReadParameter2_Term(&FLIGHT_hexacopter_DW.ReadParameter2_p);

  // End of Terminate for SubSystem: '<S1>/Vz Controller'
  // End of Terminate for SubSystem: '<Root>/Altitude_Mode'

  // Terminate for IfAction SubSystem: '<Root>/Stabilized_Mode'
  // Terminate for Enabled SubSystem: '<S9>/Enabled Subsystem'
  FLIGHT_hexac_ReadParameter_Term(&FLIGHT_hexacopter_DW.ReadParameter_pnaevv);

  // End of Terminate for SubSystem: '<S9>/Enabled Subsystem'
  // End of Terminate for SubSystem: '<Root>/Stabilized_Mode'

  // Terminate for MATLABSystem: '<S408>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ab.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_ab.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_ab.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_ab.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S408>/SourceBlock'

  // Terminate for Enabled SubSystem: '<Root>/CAS'
  // Terminate for MATLABSystem: '<S2>/Read Parameter9'
  if (!FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter9'

  // Terminate for MATLABSystem: '<S2>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_jz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter'

  // Terminate for MATLABSystem: '<S2>/Read Parameter10'
  if (!FLIGHT_hexacopter_DW.obj_ds.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ds.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter10'

  // Terminate for MATLABSystem: '<S2>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Read Parameter1'
  // End of Terminate for SubSystem: '<Root>/CAS'

  // Terminate for MATLABSystem: '<S404>/SourceBlock'
  if (!FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pe.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pe.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pe.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_hexacopter_DW.obj_pe.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S404>/SourceBlock'

  // Terminate for Enabled SubSystem: '<Root>/SAS'
  // Terminate for MATLABSystem: '<S8>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter2'

  // Terminate for MATLABSystem: '<S8>/Read Parameter'
  if (!FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter'

  // Terminate for MATLABSystem: '<S8>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter1'

  // Terminate for MATLABSystem: '<S8>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter5'

  // Terminate for MATLABSystem: '<S8>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter3'

  // Terminate for MATLABSystem: '<S8>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter4'

  // Terminate for MATLABSystem: '<S8>/Read Parameter8'
  if (!FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter8'

  // Terminate for MATLABSystem: '<S8>/Read Parameter6'
  if (!FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter6'

  // Terminate for MATLABSystem: '<S8>/Read Parameter7'
  if (!FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter7'
  // End of Terminate for SubSystem: '<Root>/SAS'

  // Terminate for MATLABSystem: '<S3>/Read Parameter13'
  if (!FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter13'

  // Terminate for MATLABSystem: '<S3>/Read Parameter1'
  if (!FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_j5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter1'

  // Terminate for MATLABSystem: '<S3>/Read Parameter2'
  if (!FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ao.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter2'

  // Terminate for MATLABSystem: '<S3>/Read Parameter3'
  if (!FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter3'

  // Terminate for MATLABSystem: '<S3>/Read Parameter4'
  if (!FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter4'

  // Terminate for MATLABSystem: '<S3>/Read Parameter5'
  if (!FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_aq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Read Parameter5'

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

  // Terminate for MATLABSystem: '<S581>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pt.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pt.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pt.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pt.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S581>/SinkBlock'
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_o);

  // Terminate for MATLABSystem: '<S579>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_px.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_px.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_px.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_px.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_px.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S579>/SinkBlock'
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_n);
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S577>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_hf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_hf.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_hf.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_hf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S577>/SinkBlock'

  // Terminate for MATLABSystem: '<S588>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_my.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_my.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_my.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_my.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_my.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S588>/SinkBlock'
  FLIGHT_hexaco_PX4Timestamp_Term(&FLIGHT_hexacopter_DW.PX4Timestamp_pna);

  // Terminate for MATLABSystem: '<S586>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_a4.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_a4.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_a4.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_a4.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S586>/SinkBlock'

  // Terminate for MATLABSystem: '<S13>/PX4 Timestamp'
  if (!FLIGHT_hexacopter_DW.obj_ky.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_ky.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S584>/SinkBlock'
  if (!FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted) {
    FLIGHT_hexacopter_DW.obj_pa.matlabCodegenIsDeleted = true;
    if ((FLIGHT_hexacopter_DW.obj_pa.isInitialized == 1) &&
        FLIGHT_hexacopter_DW.obj_pa.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_hexacopter_DW.obj_pa.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S584>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
