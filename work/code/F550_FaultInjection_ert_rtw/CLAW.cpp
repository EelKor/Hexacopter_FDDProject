//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CLAW.cpp
//
// Code generated for Simulink model 'F550_FaultInjection'.
//
// Model version                  : 4.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 17:25:22 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "CLAW.h"
#include "mc_pos_controller.h"
#include "rt_sys_F550_FaultInjection_44.h"
#include "rt_sys_CLAW_70.h"
#include "F550_FaultInjection.h"
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"
#include "F550_FaultInjection_private.h"

const real_T F550_FaultInjection_period = 0.004;

// Forward declaration for local functions
static real_T F550_FaultInjection_rt_atan2d_snf(real_T u0, real_T u1);
static real_T F550_FaultInjection_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      F550_FaultInjection_B.i = 1;
    } else {
      F550_FaultInjection_B.i = -1;
    }

    if (u1 > 0.0) {
      F550_FaultInjection_B.i1 = 1;
    } else {
      F550_FaultInjection_B.i1 = -1;
    }

    y = atan2(static_cast<real_T>(F550_FaultInjection_B.i), static_cast<real_T>
              (F550_FaultInjection_B.i1));
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

// System initialize for enable system: '<Root>/CLAW'
void F550_FaultInjection_CLAW_Init(void)
{
  static const char_T ParameterNameStr[17] = "SL_PITCHRATE_MAX";
  static const char_T ParameterNameStr_0[11] = "SL_PITCH_P";
  static const char_T ParameterNameStr_1[16] = "SL_ROLLRATE_MAX";
  static const char_T ParameterNameStr_2[10] = "SL_ROLL_P";
  static const char_T ParameterNameStr_3[14] = "SL_ROLLRATE_P";
  static const char_T ParameterNameStr_4[14] = "SL_ROLLRATE_D";
  static const char_T ParameterNameStr_5[14] = "SL_ROLLRATE_I";
  static const char_T ParameterNameStr_6[15] = "SL_PITCHRATE_P";
  static const char_T ParameterNameStr_7[15] = "SL_PITCHRATE_D";
  static const char_T ParameterNameStr_8[15] = "SL_PITCHRATE_I";
  static const char_T ParameterNameStr_9[13] = "SL_YAWRATE_P";
  static const char_T ParameterNameStr_a[13] = "SL_YAWRATE_D";
  static const char_T ParameterNameStr_b[13] = "SL_YAWRATE_I";
  px4_Bus_vehicle_rates_setpoint rtb_BusAssignment_jn;
  real_T tmp;

  // InitializeConditions for RateLimiter: '<S29>/Rate Limiter2'
  F550_FaultInjection_DW.PrevY = F550_FaultInjection_P.RateLimiter2_IC;

  // InitializeConditions for RateLimiter: '<S29>/Rate Limiter1'
  F550_FaultInjection_DW.PrevY_h = F550_FaultInjection_P.RateLimiter1_IC;

  // InitializeConditions for DiscreteIntegrator: '<S542>/Integrator'
  F550_FaultInjection_DW.Integrator_DSTATE =
    F550_FaultInjection_P.PIDController2_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S537>/Filter'
  F550_FaultInjection_DW.Filter_DSTATE =
    F550_FaultInjection_P.PIDController2_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S492>/Integrator'
  F550_FaultInjection_DW.Integrator_DSTATE_h =
    F550_FaultInjection_P.PIDController1_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S487>/Filter'
  F550_FaultInjection_DW.Filter_DSTATE_e =
    F550_FaultInjection_P.PIDController1_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S442>/Integrator'
  F550_FaultInjection_DW.Integrator_DSTATE_d =
    F550_FaultInjection_P.PIDController_InitialConditionForIntegrator;

  // InitializeConditions for DiscreteIntegrator: '<S437>/Filter'
  F550_FaultInjection_DW.Filter_DSTATE_a =
    F550_FaultInjection_P.PIDController_InitialConditionForFilter;

  // SystemInitialize for Enabled SubSystem: '<S45>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S46>/In1' incorporates:
  //   Outport: '<S46>/Out1'

  F550_FaultInjection_B.In1_e = F550_FaultInjection_P.Out1_Y0_ii;

  // End of SystemInitialize for SubSystem: '<S45>/Enabled Subsystem'

  // SystemInitialize for IfAction SubSystem: '<S2>/mc_pos_controller'
  F550_FaultInjection_mc_pos_controller_Init();

  // End of SystemInitialize for SubSystem: '<S2>/mc_pos_controller'

  // SystemInitialize for Merge: '<S2>/Merge'
  F550_FaultInjection_B.Merge_n[0] = F550_FaultInjection_P.Merge_InitialOutput;
  F550_FaultInjection_B.Merge_n[1] = F550_FaultInjection_P.Merge_InitialOutput;
  F550_FaultInjection_B.Merge_n[2] = F550_FaultInjection_P.Merge_InitialOutput;
  F550_FaultInjection_B.Merge_n[3] = F550_FaultInjection_P.Merge_InitialOutput;
  F550_FaultInjection_SourceBlock_Init(&F550_FaultInjection_DW.SourceBlock_b);
  F550_FaultInjection_PX4Timestamp_Init(&F550_FaultInjection_DW.PX4Timestamp_pna);

  // Start for MATLABSystem: '<S29>/Read Parameter9'
  F550_FaultInjection_DW.obj_j.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_j.SampleTime =
    F550_FaultInjection_P.ReadParameter9_SampleTime;
  F550_FaultInjection_DW.obj_j.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_j.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_j.SampleTime;
  }

  F550_FaultInjection_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr
    [0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_j.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter9'

  // Start for MATLABSystem: '<S29>/Read Parameter5'
  F550_FaultInjection_DW.obj_m4.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_m4.SampleTime =
    F550_FaultInjection_P.ReadParameter5_SampleTime_m;
  F550_FaultInjection_DW.obj_m4.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_m4.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_m4.SampleTime;
  }

  F550_FaultInjection_DW.obj_m4.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_0[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_m4.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter5'

  // Start for MATLABSystem: '<S29>/Read Parameter10'
  F550_FaultInjection_DW.obj_bt.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_bt.SampleTime =
    F550_FaultInjection_P.ReadParameter10_SampleTime;
  F550_FaultInjection_DW.obj_bt.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_bt.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_bt.SampleTime;
  }

  F550_FaultInjection_DW.obj_bt.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_1[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_bt.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter10'

  // Start for MATLABSystem: '<S29>/Read Parameter6'
  F550_FaultInjection_DW.obj_o.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_o.SampleTime =
    F550_FaultInjection_P.ReadParameter6_SampleTime;
  F550_FaultInjection_DW.obj_o.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_o.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_o.SampleTime;
  }

  F550_FaultInjection_DW.obj_o.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_2[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_o.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S29>/Read Parameter6'

  // Start for MATLABSystem: '<S35>/SinkBlock' incorporates:
  //   BusAssignment: '<S25>/Bus Assignment'

  F550_FaultInjection_DW.obj_ln.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_ln.isInitialized = 1;
  F550_FaultInjection_DW.obj_ln.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
  uORB_write_initialize(F550_FaultInjection_DW.obj_ln.orbMetadataObj,
                        &F550_FaultInjection_DW.obj_ln.orbAdvertiseObj,
                        &rtb_BusAssignment_jn, 1);
  F550_FaultInjection_DW.obj_ln.isSetupComplete = true;

  // Start for MATLABSystem: '<S31>/Read Parameter22'
  F550_FaultInjection_DW.obj_l.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_l.SampleTime =
    F550_FaultInjection_P.ReadParameter22_SampleTime;
  F550_FaultInjection_DW.obj_l.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_l.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_l.SampleTime;
  }

  F550_FaultInjection_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_3[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_l.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter22'

  // Start for MATLABSystem: '<S31>/Read Parameter24'
  F550_FaultInjection_DW.obj_k1.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_k1.SampleTime =
    F550_FaultInjection_P.ReadParameter24_SampleTime;
  F550_FaultInjection_DW.obj_k1.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_k1.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_k1.SampleTime;
  }

  F550_FaultInjection_DW.obj_k1.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_4[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_k1.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter24'

  // Start for MATLABSystem: '<S31>/Read Parameter23'
  F550_FaultInjection_DW.obj_p.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_p.SampleTime =
    F550_FaultInjection_P.ReadParameter23_SampleTime;
  F550_FaultInjection_DW.obj_p.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_p.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_p.SampleTime;
  }

  F550_FaultInjection_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_5[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_p.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter23'

  // Start for MATLABSystem: '<S31>/Read Parameter16'
  F550_FaultInjection_DW.obj_p4.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_p4.SampleTime =
    F550_FaultInjection_P.ReadParameter16_SampleTime;
  F550_FaultInjection_DW.obj_p4.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_p4.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_p4.SampleTime;
  }

  F550_FaultInjection_DW.obj_p4.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_6[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_p4.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter16'

  // Start for MATLABSystem: '<S31>/Read Parameter18'
  F550_FaultInjection_DW.obj_pa.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_pa.SampleTime =
    F550_FaultInjection_P.ReadParameter18_SampleTime;
  F550_FaultInjection_DW.obj_pa.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_pa.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_pa.SampleTime;
  }

  F550_FaultInjection_DW.obj_pa.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_7[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_pa.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter18'

  // Start for MATLABSystem: '<S31>/Read Parameter17'
  F550_FaultInjection_DW.obj_dn.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_dn.SampleTime =
    F550_FaultInjection_P.ReadParameter17_SampleTime;
  F550_FaultInjection_DW.obj_dn.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_dn.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_dn.SampleTime;
  }

  F550_FaultInjection_DW.obj_dn.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_8[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_dn.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter17'
  F550_FaultInjection_PX4Timestamp_Init(&F550_FaultInjection_DW.PX4Timestamp_pn);

  // Start for MATLABSystem: '<S33>/SinkBlock' incorporates:
  //   BusAssignment: '<S24>/Bus Assignment'

  F550_FaultInjection_DW.obj_i.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_i.isInitialized = 1;
  F550_FaultInjection_DW.obj_i.orbMetadataObj = ORB_ID(vehicle_attitude_setpoint);
  uORB_write_initialize(F550_FaultInjection_DW.obj_i.orbMetadataObj,
                        &F550_FaultInjection_DW.obj_i.orbAdvertiseObj,
                        &F550_FaultInjection_B.BusAssignment_m, 1);
  F550_FaultInjection_DW.obj_i.isSetupComplete = true;

  // Start for MATLABSystem: '<S31>/Read Parameter19'
  F550_FaultInjection_DW.obj_pe.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_pe.SampleTime =
    F550_FaultInjection_P.ReadParameter19_SampleTime;
  F550_FaultInjection_DW.obj_pe.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_pe.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_pe.SampleTime;
  }

  F550_FaultInjection_DW.obj_pe.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_9[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_pe.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter19'

  // Start for MATLABSystem: '<S31>/Read Parameter21'
  F550_FaultInjection_DW.obj_m.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_m.SampleTime =
    F550_FaultInjection_P.ReadParameter21_SampleTime;
  F550_FaultInjection_DW.obj_m.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_m.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_m.SampleTime;
  }

  F550_FaultInjection_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_a[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_m.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter21'

  // Start for MATLABSystem: '<S31>/Read Parameter20'
  F550_FaultInjection_DW.obj_d.matlabCodegenIsDeleted = false;
  F550_FaultInjection_DW.obj_d.SampleTime =
    F550_FaultInjection_P.ReadParameter20_SampleTime;
  F550_FaultInjection_DW.obj_d.isInitialized = 1;
  if (F550_FaultInjection_DW.obj_d.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = F550_FaultInjection_DW.obj_d.SampleTime;
  }

  F550_FaultInjection_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
    (&ParameterNameStr_b[0], true, tmp * 1000.0);
  F550_FaultInjection_DW.obj_d.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S31>/Read Parameter20'

  // SystemInitialize for Saturate: '<S449>/Saturation' incorporates:
  //   Outport: '<S2>/tau_Yaw'

  F550_FaultInjection_B.Saturation_k = F550_FaultInjection_P.tau_Yaw_Y0;

  // SystemInitialize for Saturate: '<S499>/Saturation' incorporates:
  //   Outport: '<S2>/tau_Pitch'

  F550_FaultInjection_B.Saturation_o = F550_FaultInjection_P.tau_Pitch_Y0;

  // SystemInitialize for Saturate: '<S549>/Saturation' incorporates:
  //   Outport: '<S2>/tau_Roll'

  F550_FaultInjection_B.Saturation = F550_FaultInjection_P.tau_Roll_Y0;
}

// Output and update for enable system: '<Root>/CLAW'
void F550_FaultInjection_CLAW(void)
{
  // Outputs for Enabled SubSystem: '<Root>/CLAW' incorporates:
  //   EnablePort: '<S2>/Enable'

  if (F550_FaultInjection_B.In1_b.armed) {
    // Switch: '<S26>/Switch' incorporates:
    //   Constant: '<S26>/Constant'
    //   DataTypeConversion: '<S4>/Data Type Conversion'
    //   Product: '<S36>/Product'
    //   Product: '<S36>/Product1'
    //   Product: '<S36>/Product2'
    //   Product: '<S36>/Product3'
    //   Sum: '<S36>/Sum'

    if (((F550_FaultInjection_B.DataTypeConversion[0] *
          F550_FaultInjection_B.DataTypeConversion[0] +
          F550_FaultInjection_B.DataTypeConversion[1] *
          F550_FaultInjection_B.DataTypeConversion[1]) +
         F550_FaultInjection_B.DataTypeConversion[2] *
         F550_FaultInjection_B.DataTypeConversion[2]) +
        F550_FaultInjection_B.DataTypeConversion[3] *
        F550_FaultInjection_B.DataTypeConversion[3] >
        F550_FaultInjection_P.Switch_Threshold_n) {
      F550_FaultInjection_B.rtb_Switch_es_idx_0 =
        F550_FaultInjection_B.DataTypeConversion[0];
      F550_FaultInjection_B.rtb_Switch_es_idx_1 =
        F550_FaultInjection_B.DataTypeConversion[1];
      F550_FaultInjection_B.rtb_Switch_es_idx_2 =
        F550_FaultInjection_B.DataTypeConversion[2];
      F550_FaultInjection_B.rtb_Switch_es_idx_3 =
        F550_FaultInjection_B.DataTypeConversion[3];
    } else {
      F550_FaultInjection_B.rtb_Switch_es_idx_0 =
        F550_FaultInjection_P.Constant_Value_aa[0];
      F550_FaultInjection_B.rtb_Switch_es_idx_1 =
        F550_FaultInjection_P.Constant_Value_aa[1];
      F550_FaultInjection_B.rtb_Switch_es_idx_2 =
        F550_FaultInjection_P.Constant_Value_aa[2];
      F550_FaultInjection_B.rtb_Switch_es_idx_3 =
        F550_FaultInjection_P.Constant_Value_aa[3];
    }

    // End of Switch: '<S26>/Switch'
    F550_FaultInjection_SourceBlock(&F550_FaultInjection_B.SourceBlock_b,
      &F550_FaultInjection_DW.SourceBlock_b);

    // Outputs for Enabled SubSystem: '<S45>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S46>/Enable'

    if (F550_FaultInjection_B.SourceBlock_b.SourceBlock_o1) {
      // SignalConversion generated from: '<S46>/In1' incorporates:
      //   MATLABSystem: '<S45>/SourceBlock'

      F550_FaultInjection_B.In1_e =
        F550_FaultInjection_B.SourceBlock_b.SourceBlock_o2;
    }

    // End of Outputs for SubSystem: '<S45>/Enabled Subsystem'

    // Sqrt: '<S43>/sqrt' incorporates:
    //   Product: '<S44>/Product'
    //   Product: '<S44>/Product1'
    //   Product: '<S44>/Product2'
    //   Product: '<S44>/Product3'
    //   Sum: '<S44>/Sum'

    F550_FaultInjection_B.Integrator_g = sqrt
      (((F550_FaultInjection_B.rtb_Switch_es_idx_0 *
         F550_FaultInjection_B.rtb_Switch_es_idx_0 +
         F550_FaultInjection_B.rtb_Switch_es_idx_1 *
         F550_FaultInjection_B.rtb_Switch_es_idx_1) +
        F550_FaultInjection_B.rtb_Switch_es_idx_2 *
        F550_FaultInjection_B.rtb_Switch_es_idx_2) +
       F550_FaultInjection_B.rtb_Switch_es_idx_3 *
       F550_FaultInjection_B.rtb_Switch_es_idx_3);

    // Product: '<S38>/Product'
    F550_FaultInjection_B.rtb_Switch_es_idx_0 /=
      F550_FaultInjection_B.Integrator_g;

    // Product: '<S38>/Product1'
    F550_FaultInjection_B.rtb_Switch_es_idx_1 /=
      F550_FaultInjection_B.Integrator_g;

    // Product: '<S38>/Product2'
    F550_FaultInjection_B.rtb_Switch_es_idx_2 /=
      F550_FaultInjection_B.Integrator_g;

    // Product: '<S38>/Product3'
    F550_FaultInjection_B.Integrator_g =
      F550_FaultInjection_B.rtb_Switch_es_idx_3 /
      F550_FaultInjection_B.Integrator_g;

    // Fcn: '<S27>/fcn2' incorporates:
    //   Fcn: '<S27>/fcn5'

    F550_FaultInjection_B.Switch_m = F550_FaultInjection_B.rtb_Switch_es_idx_0 *
      F550_FaultInjection_B.rtb_Switch_es_idx_0;
    F550_FaultInjection_B.NProdOut_a = F550_FaultInjection_B.rtb_Switch_es_idx_1
      * F550_FaultInjection_B.rtb_Switch_es_idx_1;
    F550_FaultInjection_B.VectorConcatenate_tmp =
      F550_FaultInjection_B.rtb_Switch_es_idx_2 *
      F550_FaultInjection_B.rtb_Switch_es_idx_2;
    F550_FaultInjection_B.VectorConcatenate_tmp_c =
      F550_FaultInjection_B.Integrator_g * F550_FaultInjection_B.Integrator_g;

    // Trigonometry: '<S37>/Trigonometric Function1' incorporates:
    //   Fcn: '<S27>/fcn1'
    //   Fcn: '<S27>/fcn2'

    F550_FaultInjection_B.VectorConcatenate[0] =
      F550_FaultInjection_rt_atan2d_snf
      ((F550_FaultInjection_B.rtb_Switch_es_idx_1 *
        F550_FaultInjection_B.rtb_Switch_es_idx_2 +
        F550_FaultInjection_B.rtb_Switch_es_idx_0 *
        F550_FaultInjection_B.Integrator_g) * 2.0,
       ((F550_FaultInjection_B.Switch_m + F550_FaultInjection_B.NProdOut_a) -
        F550_FaultInjection_B.VectorConcatenate_tmp) -
       F550_FaultInjection_B.VectorConcatenate_tmp_c);

    // Fcn: '<S27>/fcn3'
    F550_FaultInjection_B.rtb_Switch_es_idx_3 =
      (F550_FaultInjection_B.rtb_Switch_es_idx_1 *
       F550_FaultInjection_B.Integrator_g -
       F550_FaultInjection_B.rtb_Switch_es_idx_0 *
       F550_FaultInjection_B.rtb_Switch_es_idx_2) * -2.0;

    // If: '<S39>/If' incorporates:
    //   Constant: '<S40>/Constant'
    //   Constant: '<S41>/Constant'
    //   Trigonometry: '<S37>/trigFcn'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_3 > 1.0) {
      F550_FaultInjection_B.rtb_Switch_es_idx_3 =
        F550_FaultInjection_P.Constant_Value_ch;
    } else if (F550_FaultInjection_B.rtb_Switch_es_idx_3 < -1.0) {
      F550_FaultInjection_B.rtb_Switch_es_idx_3 =
        F550_FaultInjection_P.Constant_Value_ex;
    }

    if (F550_FaultInjection_B.rtb_Switch_es_idx_3 > 1.0) {
      F550_FaultInjection_B.rtb_Switch_es_idx_3 = 1.0;
    } else if (F550_FaultInjection_B.rtb_Switch_es_idx_3 < -1.0) {
      F550_FaultInjection_B.rtb_Switch_es_idx_3 = -1.0;
    }

    // End of If: '<S39>/If'

    // Trigonometry: '<S37>/trigFcn'
    F550_FaultInjection_B.VectorConcatenate[1] = asin
      (F550_FaultInjection_B.rtb_Switch_es_idx_3);

    // Trigonometry: '<S37>/Trigonometric Function3' incorporates:
    //   Fcn: '<S27>/fcn4'
    //   Fcn: '<S27>/fcn5'

    F550_FaultInjection_B.VectorConcatenate[2] =
      F550_FaultInjection_rt_atan2d_snf
      ((F550_FaultInjection_B.rtb_Switch_es_idx_2 *
        F550_FaultInjection_B.Integrator_g +
        F550_FaultInjection_B.rtb_Switch_es_idx_0 *
        F550_FaultInjection_B.rtb_Switch_es_idx_1) * 2.0,
       ((F550_FaultInjection_B.Switch_m - F550_FaultInjection_B.NProdOut_a) -
        F550_FaultInjection_B.VectorConcatenate_tmp) +
       F550_FaultInjection_B.VectorConcatenate_tmp_c);

    // If: '<S2>/Mode SW' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    if (F550_FaultInjection_B.In1_e.values[5] < 1800) {
      // Outputs for IfAction SubSystem: '<S2>/PWM2CMD' incorporates:
      //   ActionPort: '<S23>/Action Port'

      // Gain: '<S23>/Gain' incorporates:
      //   Constant: '<S23>/Constant'
      //   DataTypeConversion: '<S23>/Cast To Double3'
      //   Sum: '<S23>/Sum'

      F550_FaultInjection_B.Integrator_g = (static_cast<real_T>
        (F550_FaultInjection_B.In1_e.values[2]) -
        F550_FaultInjection_P.Constant_Value_gu) *
        F550_FaultInjection_P.Gain_Gain_e;

      // Saturate: '<S23>/Saturation'
      if (F550_FaultInjection_B.Integrator_g >
          F550_FaultInjection_P.Saturation_UpperSat) {
        F550_FaultInjection_B.Merge_n[0] =
          F550_FaultInjection_P.Saturation_UpperSat;
      } else if (F550_FaultInjection_B.Integrator_g <
                 F550_FaultInjection_P.Saturation_LowerSat) {
        F550_FaultInjection_B.Merge_n[0] =
          F550_FaultInjection_P.Saturation_LowerSat;
      } else {
        F550_FaultInjection_B.Merge_n[0] = F550_FaultInjection_B.Integrator_g;
      }

      // End of Saturate: '<S23>/Saturation'

      // Gain: '<S23>/Gain1' incorporates:
      //   Constant: '<S23>/Constant1'
      //   DataTypeConversion: '<S23>/Cast To Double2'
      //   Sum: '<S23>/Sum1'

      F550_FaultInjection_B.Integrator_g = (static_cast<real_T>
        (F550_FaultInjection_B.In1_e.values[0]) -
        F550_FaultInjection_P.Constant1_Value_n) *
        F550_FaultInjection_P.Gain1_Gain;

      // Saturate: '<S23>/Saturation1'
      if (F550_FaultInjection_B.Integrator_g >
          F550_FaultInjection_P.Saturation1_UpperSat_k) {
        F550_FaultInjection_B.Merge_n[1] =
          F550_FaultInjection_P.Saturation1_UpperSat_k;
      } else if (F550_FaultInjection_B.Integrator_g <
                 F550_FaultInjection_P.Saturation1_LowerSat_i) {
        F550_FaultInjection_B.Merge_n[1] =
          F550_FaultInjection_P.Saturation1_LowerSat_i;
      } else {
        F550_FaultInjection_B.Merge_n[1] = F550_FaultInjection_B.Integrator_g;
      }

      // End of Saturate: '<S23>/Saturation1'

      // Gain: '<S23>/Gain2' incorporates:
      //   Constant: '<S23>/Constant2'
      //   DataTypeConversion: '<S23>/Cast To Double1'
      //   Sum: '<S23>/Sum2'

      F550_FaultInjection_B.Integrator_g = (static_cast<real_T>
        (F550_FaultInjection_B.In1_e.values[1]) -
        F550_FaultInjection_P.Constant2_Value_k) *
        F550_FaultInjection_P.Gain2_Gain;

      // Saturate: '<S23>/Saturation2'
      if (F550_FaultInjection_B.Integrator_g >
          F550_FaultInjection_P.Saturation2_UpperSat) {
        F550_FaultInjection_B.Merge_n[2] =
          F550_FaultInjection_P.Saturation2_UpperSat;
      } else if (F550_FaultInjection_B.Integrator_g <
                 F550_FaultInjection_P.Saturation2_LowerSat) {
        F550_FaultInjection_B.Merge_n[2] =
          F550_FaultInjection_P.Saturation2_LowerSat;
      } else {
        F550_FaultInjection_B.Merge_n[2] = F550_FaultInjection_B.Integrator_g;
      }

      // End of Saturate: '<S23>/Saturation2'

      // Gain: '<S23>/Gain3' incorporates:
      //   Constant: '<S23>/Constant3'
      //   DataTypeConversion: '<S23>/Cast To Double'
      //   Sum: '<S23>/Sum3'

      F550_FaultInjection_B.Integrator_g = (static_cast<real_T>
        (F550_FaultInjection_B.In1_e.values[3]) -
        F550_FaultInjection_P.Constant3_Value_j) *
        F550_FaultInjection_P.Gain3_Gain;

      // Saturate: '<S23>/Saturation3'
      if (F550_FaultInjection_B.Integrator_g >
          F550_FaultInjection_P.Saturation3_UpperSat) {
        F550_FaultInjection_B.Merge_n[3] =
          F550_FaultInjection_P.Saturation3_UpperSat;
      } else if (F550_FaultInjection_B.Integrator_g <
                 F550_FaultInjection_P.Saturation3_LowerSat) {
        F550_FaultInjection_B.Merge_n[3] =
          F550_FaultInjection_P.Saturation3_LowerSat;
      } else {
        F550_FaultInjection_B.Merge_n[3] = F550_FaultInjection_B.Integrator_g;
      }

      // End of Saturate: '<S23>/Saturation3'
      // End of Outputs for SubSystem: '<S2>/PWM2CMD'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/mc_pos_controller' incorporates:
      //   ActionPort: '<S30>/Action Port'

      F550_FaultInjection_mc_pos_controller();

      // End of Outputs for SubSystem: '<S2>/mc_pos_controller'
    }

    // End of If: '<S2>/Mode SW'
    F550_FaultInjection_PX4Timestamp(&F550_FaultInjection_B.PX4Timestamp_pna);

    // MATLABSystem: '<S29>/Read Parameter9'
    if (F550_FaultInjection_DW.obj_j.SampleTime !=
        F550_FaultInjection_P.ReadParameter9_SampleTime) {
      F550_FaultInjection_DW.obj_j.SampleTime =
        F550_FaultInjection_P.ReadParameter9_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_j.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Gain: '<S47>/Gain1' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter9'
    //
    F550_FaultInjection_B.Gain1_o = F550_FaultInjection_P.Gain1_Gain_l *
      F550_FaultInjection_B.ParamStep;

    // RateLimiter: '<S29>/Rate Limiter2'
    F550_FaultInjection_B.rtb_Switch_es_idx_0 = F550_FaultInjection_B.Merge_n[2]
      - F550_FaultInjection_DW.PrevY;
    if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
        F550_FaultInjection_P.RateLimiter2_RisingLim *
        F550_FaultInjection_period) {
      F550_FaultInjection_B.Integrator_g =
        F550_FaultInjection_P.RateLimiter2_RisingLim *
        F550_FaultInjection_period + F550_FaultInjection_DW.PrevY;
    } else if (F550_FaultInjection_B.rtb_Switch_es_idx_0 <
               F550_FaultInjection_P.RateLimiter2_FallingLim *
               F550_FaultInjection_period) {
      F550_FaultInjection_B.Integrator_g =
        F550_FaultInjection_P.RateLimiter2_FallingLim *
        F550_FaultInjection_period + F550_FaultInjection_DW.PrevY;
    } else {
      F550_FaultInjection_B.Integrator_g = F550_FaultInjection_B.Merge_n[2];
    }

    F550_FaultInjection_DW.PrevY = F550_FaultInjection_B.Integrator_g;

    // End of RateLimiter: '<S29>/Rate Limiter2'

    // Sum: '<S29>/Sum2'
    F550_FaultInjection_B.Integrator_g -=
      F550_FaultInjection_B.VectorConcatenate[1];

    // MATLABSystem: '<S29>/Read Parameter5'
    if (F550_FaultInjection_DW.obj_m4.SampleTime !=
        F550_FaultInjection_P.ReadParameter5_SampleTime_m) {
      F550_FaultInjection_DW.obj_m4.SampleTime =
        F550_FaultInjection_P.ReadParameter5_SampleTime_m;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_m4.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Product: '<S87>/PProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter5'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_0 =
      F550_FaultInjection_B.Integrator_g * F550_FaultInjection_B.ParamStep;

    // Switch: '<S90>/Switch2' incorporates:
    //   RelationalOperator: '<S90>/LowerRelop1'
    //   RelationalOperator: '<S90>/UpperRelop'
    //   Switch: '<S90>/Switch'
    //   UnaryMinus: '<S29>/Unary Minus1'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
        F550_FaultInjection_B.Gain1_o) {
      F550_FaultInjection_B.Integrator_g = F550_FaultInjection_B.Gain1_o;
    } else if (F550_FaultInjection_B.rtb_Switch_es_idx_0 <
               -F550_FaultInjection_B.Gain1_o) {
      // Switch: '<S90>/Switch' incorporates:
      //   UnaryMinus: '<S29>/Unary Minus1'

      F550_FaultInjection_B.Integrator_g = -F550_FaultInjection_B.Gain1_o;
    } else {
      F550_FaultInjection_B.Integrator_g =
        F550_FaultInjection_B.rtb_Switch_es_idx_0;
    }

    // End of Switch: '<S90>/Switch2'

    // MATLABSystem: '<S29>/Read Parameter10'
    if (F550_FaultInjection_DW.obj_bt.SampleTime !=
        F550_FaultInjection_P.ReadParameter10_SampleTime) {
      F550_FaultInjection_DW.obj_bt.SampleTime =
        F550_FaultInjection_P.ReadParameter10_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_bt.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Gain: '<S48>/Gain1' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter10'
    //
    F550_FaultInjection_B.Gain1_o = F550_FaultInjection_P.Gain1_Gain_c *
      F550_FaultInjection_B.ParamStep;

    // RateLimiter: '<S29>/Rate Limiter1'
    F550_FaultInjection_B.rtb_Switch_es_idx_0 = F550_FaultInjection_B.Merge_n[1]
      - F550_FaultInjection_DW.PrevY_h;
    if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
        F550_FaultInjection_P.RateLimiter1_RisingLim *
        F550_FaultInjection_period) {
      F550_FaultInjection_B.rtb_Switch_es_idx_1 =
        F550_FaultInjection_P.RateLimiter1_RisingLim *
        F550_FaultInjection_period + F550_FaultInjection_DW.PrevY_h;
    } else if (F550_FaultInjection_B.rtb_Switch_es_idx_0 <
               F550_FaultInjection_P.RateLimiter1_FallingLim *
               F550_FaultInjection_period) {
      F550_FaultInjection_B.rtb_Switch_es_idx_1 =
        F550_FaultInjection_P.RateLimiter1_FallingLim *
        F550_FaultInjection_period + F550_FaultInjection_DW.PrevY_h;
    } else {
      F550_FaultInjection_B.rtb_Switch_es_idx_1 = F550_FaultInjection_B.Merge_n
        [1];
    }

    F550_FaultInjection_DW.PrevY_h = F550_FaultInjection_B.rtb_Switch_es_idx_1;

    // End of RateLimiter: '<S29>/Rate Limiter1'

    // Sum: '<S29>/Sum3'
    F550_FaultInjection_B.rtb_Switch_es_idx_1 -=
      F550_FaultInjection_B.VectorConcatenate[2];

    // MATLABSystem: '<S29>/Read Parameter6'
    if (F550_FaultInjection_DW.obj_o.SampleTime !=
        F550_FaultInjection_P.ReadParameter6_SampleTime) {
      F550_FaultInjection_DW.obj_o.SampleTime =
        F550_FaultInjection_P.ReadParameter6_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_o.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Product: '<S136>/PProd Out' incorporates:
    //   MATLABSystem: '<S29>/Read Parameter6'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_0 =
      F550_FaultInjection_B.rtb_Switch_es_idx_1 *
      F550_FaultInjection_B.ParamStep;

    // Switch: '<S139>/Switch2' incorporates:
    //   RelationalOperator: '<S139>/LowerRelop1'
    //   RelationalOperator: '<S139>/UpperRelop'
    //   Switch: '<S139>/Switch'
    //   UnaryMinus: '<S29>/Unary Minus2'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
        F550_FaultInjection_B.Gain1_o) {
      F550_FaultInjection_B.rtb_Switch_es_idx_1 = F550_FaultInjection_B.Gain1_o;
    } else if (F550_FaultInjection_B.rtb_Switch_es_idx_0 <
               -F550_FaultInjection_B.Gain1_o) {
      // Switch: '<S139>/Switch' incorporates:
      //   UnaryMinus: '<S29>/Unary Minus2'

      F550_FaultInjection_B.rtb_Switch_es_idx_1 = -F550_FaultInjection_B.Gain1_o;
    } else {
      F550_FaultInjection_B.rtb_Switch_es_idx_1 =
        F550_FaultInjection_B.rtb_Switch_es_idx_0;
    }

    // End of Switch: '<S139>/Switch2'

    // BusAssignment: '<S25>/Bus Assignment' incorporates:
    //   Constant: '<S25>/thrust_sp_bX'
    //   Constant: '<S25>/thrust_sp_bY'
    //   DataTypeConversion: '<S25>/Data Type Conversion'
    //   DataTypeConversion: '<S25>/Data Type Conversion1'
    //   DataTypeConversion: '<S25>/Data Type Conversion2'
    //   DataTypeConversion: '<S25>/Data Type Conversion3'
    //   MATLABSystem: '<S25>/PX4 Timestamp'

    F550_FaultInjection_B.BusAssignment_j.timestamp =
      F550_FaultInjection_B.PX4Timestamp_pna.PX4Timestamp;
    F550_FaultInjection_B.BusAssignment_j.roll = static_cast<real32_T>
      (F550_FaultInjection_B.Merge_n[3]);
    F550_FaultInjection_B.BusAssignment_j.pitch = static_cast<real32_T>
      (F550_FaultInjection_B.Integrator_g);
    F550_FaultInjection_B.BusAssignment_j.yaw = static_cast<real32_T>
      (F550_FaultInjection_B.rtb_Switch_es_idx_1);
    F550_FaultInjection_B.BusAssignment_j.thrust_body[0] = static_cast<real32_T>
      (F550_FaultInjection_P.thrust_sp_bX_Value_m);
    F550_FaultInjection_B.BusAssignment_j.thrust_body[1] = static_cast<real32_T>
      (F550_FaultInjection_P.thrust_sp_bY_Value_f);
    F550_FaultInjection_B.BusAssignment_j.thrust_body[2] = static_cast<real32_T>
      (F550_FaultInjection_B.Merge_n[0]);

    // MATLABSystem: '<S35>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'

    uORB_write_step(F550_FaultInjection_DW.obj_ln.orbMetadataObj,
                    &F550_FaultInjection_DW.obj_ln.orbAdvertiseObj,
                    &F550_FaultInjection_B.BusAssignment_j);

    // Sum: '<S31>/Sum1'
    F550_FaultInjection_B.rtb_Switch_es_idx_1 -=
      F550_FaultInjection_B.DataTypeConversion2[0];

    // MATLABSystem: '<S31>/Read Parameter22'
    if (F550_FaultInjection_DW.obj_l.SampleTime !=
        F550_FaultInjection_P.ReadParameter22_SampleTime) {
      F550_FaultInjection_DW.obj_l.SampleTime =
        F550_FaultInjection_P.ReadParameter22_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_l.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // MATLABSystem: '<S31>/Read Parameter24'
    if (F550_FaultInjection_DW.obj_k1.SampleTime !=
        F550_FaultInjection_P.ReadParameter24_SampleTime) {
      F550_FaultInjection_DW.obj_k1.SampleTime =
        F550_FaultInjection_P.ReadParameter24_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_k1.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.Gain1_o);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.Gain1_o = 0.0F;
    }

    // Product: '<S545>/NProd Out' incorporates:
    //   Constant: '<S31>/Constant2'
    //   DiscreteIntegrator: '<S537>/Filter'
    //   MATLABSystem: '<S31>/Read Parameter24'
    //   Product: '<S536>/DProd Out'
    //   Sum: '<S537>/SumD'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_2 =
      (F550_FaultInjection_B.rtb_Switch_es_idx_1 * F550_FaultInjection_B.Gain1_o
       - F550_FaultInjection_DW.Filter_DSTATE) *
      F550_FaultInjection_P.Constant2_Value_o4;

    // Sum: '<S551>/Sum' incorporates:
    //   DiscreteIntegrator: '<S542>/Integrator'
    //   MATLABSystem: '<S31>/Read Parameter22'
    //   Product: '<S547>/PProd Out'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_0 =
      (F550_FaultInjection_B.rtb_Switch_es_idx_1 *
       F550_FaultInjection_B.ParamStep +
       F550_FaultInjection_DW.Integrator_DSTATE) +
      F550_FaultInjection_B.rtb_Switch_es_idx_2;

    // Saturate: '<S549>/Saturation' incorporates:
    //   DeadZone: '<S535>/DeadZone'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
        F550_FaultInjection_P.PIDController2_UpperSaturationLimit) {
      // Saturate: '<S549>/Saturation'
      F550_FaultInjection_B.Saturation =
        F550_FaultInjection_P.PIDController2_UpperSaturationLimit;
      F550_FaultInjection_B.rtb_Switch_es_idx_0 -=
        F550_FaultInjection_P.PIDController2_UpperSaturationLimit;
    } else {
      if (F550_FaultInjection_B.rtb_Switch_es_idx_0 <
          F550_FaultInjection_P.PIDController2_LowerSaturationLimit) {
        // Saturate: '<S549>/Saturation'
        F550_FaultInjection_B.Saturation =
          F550_FaultInjection_P.PIDController2_LowerSaturationLimit;
      } else {
        // Saturate: '<S549>/Saturation'
        F550_FaultInjection_B.Saturation =
          F550_FaultInjection_B.rtb_Switch_es_idx_0;
      }

      if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >=
          F550_FaultInjection_P.PIDController2_LowerSaturationLimit) {
        F550_FaultInjection_B.rtb_Switch_es_idx_0 = 0.0;
      } else {
        F550_FaultInjection_B.rtb_Switch_es_idx_0 -=
          F550_FaultInjection_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S549>/Saturation'

    // RelationalOperator: '<S533>/Relational Operator' incorporates:
    //   Constant: '<S533>/Clamping_zero'

    F550_FaultInjection_B.RelationalOperator_i =
      (F550_FaultInjection_P.Clamping_zero_Value_g !=
       F550_FaultInjection_B.rtb_Switch_es_idx_0);

    // RelationalOperator: '<S533>/fix for DT propagation issue' incorporates:
    //   Constant: '<S533>/Clamping_zero'

    F550_FaultInjection_B.fixforDTpropagationissue_h =
      (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
       F550_FaultInjection_P.Clamping_zero_Value_g);

    // MATLABSystem: '<S31>/Read Parameter23'
    if (F550_FaultInjection_DW.obj_p.SampleTime !=
        F550_FaultInjection_P.ReadParameter23_SampleTime) {
      F550_FaultInjection_DW.obj_p.SampleTime =
        F550_FaultInjection_P.ReadParameter23_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_p.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Product: '<S539>/IProd Out' incorporates:
    //   MATLABSystem: '<S31>/Read Parameter23'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_0 =
      F550_FaultInjection_B.rtb_Switch_es_idx_1 *
      F550_FaultInjection_B.ParamStep;

    // Sum: '<S31>/Sum'
    F550_FaultInjection_B.Integrator_g -=
      F550_FaultInjection_B.DataTypeConversion2[1];

    // MATLABSystem: '<S31>/Read Parameter16'
    if (F550_FaultInjection_DW.obj_p4.SampleTime !=
        F550_FaultInjection_P.ReadParameter16_SampleTime) {
      F550_FaultInjection_DW.obj_p4.SampleTime =
        F550_FaultInjection_P.ReadParameter16_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_p4.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // MATLABSystem: '<S31>/Read Parameter18'
    if (F550_FaultInjection_DW.obj_pa.SampleTime !=
        F550_FaultInjection_P.ReadParameter18_SampleTime) {
      F550_FaultInjection_DW.obj_pa.SampleTime =
        F550_FaultInjection_P.ReadParameter18_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_pa.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.Gain1_o);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.Gain1_o = 0.0F;
    }

    // Product: '<S495>/NProd Out' incorporates:
    //   Constant: '<S31>/Constant1'
    //   DiscreteIntegrator: '<S487>/Filter'
    //   MATLABSystem: '<S31>/Read Parameter18'
    //   Product: '<S486>/DProd Out'
    //   Sum: '<S487>/SumD'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_3 =
      (F550_FaultInjection_B.Integrator_g * F550_FaultInjection_B.Gain1_o -
       F550_FaultInjection_DW.Filter_DSTATE_e) *
      F550_FaultInjection_P.Constant1_Value_e;

    // Sum: '<S501>/Sum' incorporates:
    //   DiscreteIntegrator: '<S492>/Integrator'
    //   MATLABSystem: '<S31>/Read Parameter16'
    //   Product: '<S497>/PProd Out'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_1 =
      (F550_FaultInjection_B.Integrator_g * F550_FaultInjection_B.ParamStep +
       F550_FaultInjection_DW.Integrator_DSTATE_h) +
      F550_FaultInjection_B.rtb_Switch_es_idx_3;

    // Saturate: '<S499>/Saturation' incorporates:
    //   DeadZone: '<S485>/DeadZone'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_1 >
        F550_FaultInjection_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S499>/Saturation'
      F550_FaultInjection_B.Saturation_o =
        F550_FaultInjection_P.PIDController1_UpperSaturationLimit;
      F550_FaultInjection_B.rtb_Switch_es_idx_1 -=
        F550_FaultInjection_P.PIDController1_UpperSaturationLimit;
    } else {
      if (F550_FaultInjection_B.rtb_Switch_es_idx_1 <
          F550_FaultInjection_P.PIDController1_LowerSaturationLimit) {
        // Saturate: '<S499>/Saturation'
        F550_FaultInjection_B.Saturation_o =
          F550_FaultInjection_P.PIDController1_LowerSaturationLimit;
      } else {
        // Saturate: '<S499>/Saturation'
        F550_FaultInjection_B.Saturation_o =
          F550_FaultInjection_B.rtb_Switch_es_idx_1;
      }

      if (F550_FaultInjection_B.rtb_Switch_es_idx_1 >=
          F550_FaultInjection_P.PIDController1_LowerSaturationLimit) {
        F550_FaultInjection_B.rtb_Switch_es_idx_1 = 0.0;
      } else {
        F550_FaultInjection_B.rtb_Switch_es_idx_1 -=
          F550_FaultInjection_P.PIDController1_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S499>/Saturation'

    // RelationalOperator: '<S483>/Relational Operator' incorporates:
    //   Constant: '<S483>/Clamping_zero'

    F550_FaultInjection_B.RelationalOperator_h =
      (F550_FaultInjection_P.Clamping_zero_Value_gi !=
       F550_FaultInjection_B.rtb_Switch_es_idx_1);

    // RelationalOperator: '<S483>/fix for DT propagation issue' incorporates:
    //   Constant: '<S483>/Clamping_zero'

    F550_FaultInjection_B.fixforDTpropagationissue_c =
      (F550_FaultInjection_B.rtb_Switch_es_idx_1 >
       F550_FaultInjection_P.Clamping_zero_Value_gi);

    // MATLABSystem: '<S31>/Read Parameter17'
    if (F550_FaultInjection_DW.obj_dn.SampleTime !=
        F550_FaultInjection_P.ReadParameter17_SampleTime) {
      F550_FaultInjection_DW.obj_dn.SampleTime =
        F550_FaultInjection_P.ReadParameter17_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_dn.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Product: '<S489>/IProd Out' incorporates:
    //   MATLABSystem: '<S31>/Read Parameter17'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_1 =
      F550_FaultInjection_B.Integrator_g * F550_FaultInjection_B.ParamStep;

    // Switch: '<S483>/Switch1' incorporates:
    //   Constant: '<S483>/Constant'
    //   Constant: '<S483>/Constant2'

    if (F550_FaultInjection_B.fixforDTpropagationissue_c) {
      F550_FaultInjection_B.i2 = F550_FaultInjection_P.Constant_Value_ol;
    } else {
      F550_FaultInjection_B.i2 = F550_FaultInjection_P.Constant2_Value_d;
    }

    // Switch: '<S483>/Switch2' incorporates:
    //   Constant: '<S483>/Clamping_zero'
    //   Constant: '<S483>/Constant3'
    //   Constant: '<S483>/Constant4'
    //   RelationalOperator: '<S483>/fix for DT propagation issue1'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_1 >
        F550_FaultInjection_P.Clamping_zero_Value_gi) {
      F550_FaultInjection_B.i3 = F550_FaultInjection_P.Constant3_Value_m;
    } else {
      F550_FaultInjection_B.i3 = F550_FaultInjection_P.Constant4_Value_m;
    }

    // Switch: '<S483>/Switch' incorporates:
    //   Constant: '<S483>/Constant1'
    //   Logic: '<S483>/AND3'
    //   RelationalOperator: '<S483>/Equal1'
    //   Switch: '<S483>/Switch1'
    //   Switch: '<S483>/Switch2'

    if (F550_FaultInjection_B.RelationalOperator_h && (F550_FaultInjection_B.i2 ==
         F550_FaultInjection_B.i3)) {
      F550_FaultInjection_B.Switch_m = F550_FaultInjection_P.Constant1_Value_nh;
    } else {
      F550_FaultInjection_B.Switch_m = F550_FaultInjection_B.rtb_Switch_es_idx_1;
    }

    // End of Switch: '<S483>/Switch'
    F550_FaultInjection_PX4Timestamp(&F550_FaultInjection_B.PX4Timestamp_pn);

    // BusAssignment: '<S24>/Bus Assignment' incorporates:
    //   Constant: '<S24>/thrust_sp_bX'
    //   Constant: '<S24>/thrust_sp_bY'
    //   Constant: '<S32>/Constant'
    //   DataTypeConversion: '<S24>/Data Type Conversion'
    //   DataTypeConversion: '<S24>/Data Type Conversion1'
    //   DataTypeConversion: '<S24>/Data Type Conversion3'
    //   MATLABSystem: '<S24>/PX4 Timestamp'

    F550_FaultInjection_B.BusAssignment = F550_FaultInjection_P.Constant_Value_a;
    F550_FaultInjection_B.BusAssignment.timestamp =
      F550_FaultInjection_B.PX4Timestamp_pn.PX4Timestamp;
    F550_FaultInjection_B.BusAssignment.roll_body = static_cast<real32_T>
      (F550_FaultInjection_B.Merge_n[1]);
    F550_FaultInjection_B.BusAssignment.pitch_body = static_cast<real32_T>
      (F550_FaultInjection_B.Merge_n[2]);
    F550_FaultInjection_B.BusAssignment.yaw_body = 0.0F;
    F550_FaultInjection_B.BusAssignment.thrust_body[0] = static_cast<real32_T>
      (F550_FaultInjection_P.thrust_sp_bX_Value);
    F550_FaultInjection_B.BusAssignment.thrust_body[1] = static_cast<real32_T>
      (F550_FaultInjection_P.thrust_sp_bY_Value);
    F550_FaultInjection_B.BusAssignment.thrust_body[2] = static_cast<real32_T>
      (F550_FaultInjection_B.Merge_n[0]);

    // MATLABSystem: '<S33>/SinkBlock' incorporates:
    //   BusAssignment: '<S24>/Bus Assignment'

    uORB_write_step(F550_FaultInjection_DW.obj_i.orbMetadataObj,
                    &F550_FaultInjection_DW.obj_i.orbAdvertiseObj,
                    &F550_FaultInjection_B.BusAssignment);

    // Sum: '<S31>/Sum4'
    F550_FaultInjection_B.Integrator_g = F550_FaultInjection_B.Merge_n[3] -
      F550_FaultInjection_B.DataTypeConversion2[2];

    // MATLABSystem: '<S31>/Read Parameter19'
    if (F550_FaultInjection_DW.obj_pe.SampleTime !=
        F550_FaultInjection_P.ReadParameter19_SampleTime) {
      F550_FaultInjection_DW.obj_pe.SampleTime =
        F550_FaultInjection_P.ReadParameter19_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_pe.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // MATLABSystem: '<S31>/Read Parameter21'
    if (F550_FaultInjection_DW.obj_m.SampleTime !=
        F550_FaultInjection_P.ReadParameter21_SampleTime) {
      F550_FaultInjection_DW.obj_m.SampleTime =
        F550_FaultInjection_P.ReadParameter21_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_m.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.Gain1_o);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.Gain1_o = 0.0F;
    }

    // Product: '<S445>/NProd Out' incorporates:
    //   Constant: '<S31>/Constant'
    //   DiscreteIntegrator: '<S437>/Filter'
    //   MATLABSystem: '<S31>/Read Parameter21'
    //   Product: '<S436>/DProd Out'
    //   Sum: '<S437>/SumD'
    //
    F550_FaultInjection_B.NProdOut_a = (F550_FaultInjection_B.Integrator_g *
      F550_FaultInjection_B.Gain1_o - F550_FaultInjection_DW.Filter_DSTATE_a) *
      F550_FaultInjection_P.Constant_Value_lz;

    // Sum: '<S451>/Sum' incorporates:
    //   DiscreteIntegrator: '<S442>/Integrator'
    //   MATLABSystem: '<S31>/Read Parameter19'
    //   Product: '<S447>/PProd Out'
    //
    F550_FaultInjection_B.rtb_Switch_es_idx_1 =
      (F550_FaultInjection_B.Integrator_g * F550_FaultInjection_B.ParamStep +
       F550_FaultInjection_DW.Integrator_DSTATE_d) +
      F550_FaultInjection_B.NProdOut_a;

    // Saturate: '<S449>/Saturation' incorporates:
    //   DeadZone: '<S435>/DeadZone'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_1 >
        F550_FaultInjection_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S449>/Saturation'
      F550_FaultInjection_B.Saturation_k =
        F550_FaultInjection_P.PIDController_UpperSaturationLimit;
      F550_FaultInjection_B.rtb_Switch_es_idx_1 -=
        F550_FaultInjection_P.PIDController_UpperSaturationLimit;
    } else {
      if (F550_FaultInjection_B.rtb_Switch_es_idx_1 <
          F550_FaultInjection_P.PIDController_LowerSaturationLimit) {
        // Saturate: '<S449>/Saturation'
        F550_FaultInjection_B.Saturation_k =
          F550_FaultInjection_P.PIDController_LowerSaturationLimit;
      } else {
        // Saturate: '<S449>/Saturation'
        F550_FaultInjection_B.Saturation_k =
          F550_FaultInjection_B.rtb_Switch_es_idx_1;
      }

      if (F550_FaultInjection_B.rtb_Switch_es_idx_1 >=
          F550_FaultInjection_P.PIDController_LowerSaturationLimit) {
        F550_FaultInjection_B.rtb_Switch_es_idx_1 = 0.0;
      } else {
        F550_FaultInjection_B.rtb_Switch_es_idx_1 -=
          F550_FaultInjection_P.PIDController_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S449>/Saturation'

    // MATLABSystem: '<S31>/Read Parameter20'
    if (F550_FaultInjection_DW.obj_d.SampleTime !=
        F550_FaultInjection_P.ReadParameter20_SampleTime) {
      F550_FaultInjection_DW.obj_d.SampleTime =
        F550_FaultInjection_P.ReadParameter20_SampleTime;
    }

    F550_FaultInjection_B.b_varargout_2 = MW_Param_Step
      (F550_FaultInjection_DW.obj_d.MW_PARAMHANDLE, MW_SINGLE,
       &F550_FaultInjection_B.ParamStep);
    if (F550_FaultInjection_B.b_varargout_2) {
      F550_FaultInjection_B.ParamStep = 0.0F;
    }

    // Product: '<S439>/IProd Out' incorporates:
    //   MATLABSystem: '<S31>/Read Parameter20'
    //
    F550_FaultInjection_B.Integrator_g *= F550_FaultInjection_B.ParamStep;

    // Switch: '<S533>/Switch1' incorporates:
    //   Constant: '<S533>/Constant'
    //   Constant: '<S533>/Constant2'

    if (F550_FaultInjection_B.fixforDTpropagationissue_h) {
      F550_FaultInjection_B.i2 = F550_FaultInjection_P.Constant_Value_ix;
    } else {
      F550_FaultInjection_B.i2 = F550_FaultInjection_P.Constant2_Value_f2;
    }

    // Switch: '<S533>/Switch2' incorporates:
    //   Constant: '<S533>/Clamping_zero'
    //   Constant: '<S533>/Constant3'
    //   Constant: '<S533>/Constant4'
    //   RelationalOperator: '<S533>/fix for DT propagation issue1'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_0 >
        F550_FaultInjection_P.Clamping_zero_Value_g) {
      F550_FaultInjection_B.i3 = F550_FaultInjection_P.Constant3_Value_ki;
    } else {
      F550_FaultInjection_B.i3 = F550_FaultInjection_P.Constant4_Value_l;
    }

    // Switch: '<S533>/Switch' incorporates:
    //   Constant: '<S533>/Constant1'
    //   Logic: '<S533>/AND3'
    //   RelationalOperator: '<S533>/Equal1'
    //   Switch: '<S533>/Switch1'
    //   Switch: '<S533>/Switch2'

    if (F550_FaultInjection_B.RelationalOperator_i && (F550_FaultInjection_B.i2 ==
         F550_FaultInjection_B.i3)) {
      F550_FaultInjection_B.rtb_Switch_es_idx_0 =
        F550_FaultInjection_P.Constant1_Value_i;
    }

    // Update for DiscreteIntegrator: '<S542>/Integrator' incorporates:
    //   Switch: '<S533>/Switch'

    F550_FaultInjection_DW.Integrator_DSTATE +=
      F550_FaultInjection_P.Integrator_gainval_n *
      F550_FaultInjection_B.rtb_Switch_es_idx_0;

    // Update for DiscreteIntegrator: '<S537>/Filter'
    F550_FaultInjection_DW.Filter_DSTATE +=
      F550_FaultInjection_P.Filter_gainval_d *
      F550_FaultInjection_B.rtb_Switch_es_idx_2;

    // Update for DiscreteIntegrator: '<S492>/Integrator'
    F550_FaultInjection_DW.Integrator_DSTATE_h +=
      F550_FaultInjection_P.Integrator_gainval_c *
      F550_FaultInjection_B.Switch_m;

    // Update for DiscreteIntegrator: '<S487>/Filter'
    F550_FaultInjection_DW.Filter_DSTATE_e +=
      F550_FaultInjection_P.Filter_gainval_c *
      F550_FaultInjection_B.rtb_Switch_es_idx_3;

    // Switch: '<S433>/Switch1' incorporates:
    //   Constant: '<S433>/Clamping_zero'
    //   Constant: '<S433>/Constant'
    //   Constant: '<S433>/Constant2'
    //   RelationalOperator: '<S433>/fix for DT propagation issue'

    if (F550_FaultInjection_B.rtb_Switch_es_idx_1 >
        F550_FaultInjection_P.Clamping_zero_Value_m) {
      F550_FaultInjection_B.i2 = F550_FaultInjection_P.Constant_Value_dm;
    } else {
      F550_FaultInjection_B.i2 = F550_FaultInjection_P.Constant2_Value_l;
    }

    // Switch: '<S433>/Switch2' incorporates:
    //   Constant: '<S433>/Clamping_zero'
    //   Constant: '<S433>/Constant3'
    //   Constant: '<S433>/Constant4'
    //   RelationalOperator: '<S433>/fix for DT propagation issue1'

    if (F550_FaultInjection_B.Integrator_g >
        F550_FaultInjection_P.Clamping_zero_Value_m) {
      F550_FaultInjection_B.i3 = F550_FaultInjection_P.Constant3_Value_by;
    } else {
      F550_FaultInjection_B.i3 = F550_FaultInjection_P.Constant4_Value_i;
    }

    // Switch: '<S433>/Switch' incorporates:
    //   Constant: '<S433>/Clamping_zero'
    //   Constant: '<S433>/Constant1'
    //   Logic: '<S433>/AND3'
    //   RelationalOperator: '<S433>/Equal1'
    //   RelationalOperator: '<S433>/Relational Operator'
    //   Switch: '<S433>/Switch1'
    //   Switch: '<S433>/Switch2'

    if ((F550_FaultInjection_P.Clamping_zero_Value_m !=
         F550_FaultInjection_B.rtb_Switch_es_idx_1) && (F550_FaultInjection_B.i2
         == F550_FaultInjection_B.i3)) {
      F550_FaultInjection_B.Integrator_g =
        F550_FaultInjection_P.Constant1_Value_fh;
    }

    // Update for DiscreteIntegrator: '<S442>/Integrator' incorporates:
    //   Switch: '<S433>/Switch'

    F550_FaultInjection_DW.Integrator_DSTATE_d +=
      F550_FaultInjection_P.Integrator_gainval_p *
      F550_FaultInjection_B.Integrator_g;

    // Update for DiscreteIntegrator: '<S437>/Filter'
    F550_FaultInjection_DW.Filter_DSTATE_a +=
      F550_FaultInjection_P.Filter_gainval_dc * F550_FaultInjection_B.NProdOut_a;
  }

  // End of Outputs for SubSystem: '<Root>/CLAW'
}

// Termination for enable system: '<Root>/CLAW'
void F550_FaultInjection_CLAW_Term(void)
{
  F550_FaultInjection_SourceBlock_Term(&F550_FaultInjection_DW.SourceBlock_b);

  // Terminate for IfAction SubSystem: '<S2>/mc_pos_controller'
  F550_FaultInjection_mc_pos_controller_Term();

  // End of Terminate for SubSystem: '<S2>/mc_pos_controller'
  F550_FaultInjection_PX4Timestamp_Term(&F550_FaultInjection_DW.PX4Timestamp_pna);

  // Terminate for MATLABSystem: '<S29>/Read Parameter9'
  if (!F550_FaultInjection_DW.obj_j.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter9'

  // Terminate for MATLABSystem: '<S29>/Read Parameter5'
  if (!F550_FaultInjection_DW.obj_m4.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_m4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter5'

  // Terminate for MATLABSystem: '<S29>/Read Parameter10'
  if (!F550_FaultInjection_DW.obj_bt.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_bt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter10'

  // Terminate for MATLABSystem: '<S29>/Read Parameter6'
  if (!F550_FaultInjection_DW.obj_o.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter6'

  // Terminate for MATLABSystem: '<S35>/SinkBlock'
  if (!F550_FaultInjection_DW.obj_ln.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_ln.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_ln.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_ln.isSetupComplete) {
      uORB_write_terminate(&F550_FaultInjection_DW.obj_ln.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S35>/SinkBlock'

  // Terminate for MATLABSystem: '<S31>/Read Parameter22'
  if (!F550_FaultInjection_DW.obj_l.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter22'

  // Terminate for MATLABSystem: '<S31>/Read Parameter24'
  if (!F550_FaultInjection_DW.obj_k1.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_k1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter24'

  // Terminate for MATLABSystem: '<S31>/Read Parameter23'
  if (!F550_FaultInjection_DW.obj_p.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter23'

  // Terminate for MATLABSystem: '<S31>/Read Parameter16'
  if (!F550_FaultInjection_DW.obj_p4.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_p4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter16'

  // Terminate for MATLABSystem: '<S31>/Read Parameter18'
  if (!F550_FaultInjection_DW.obj_pa.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_pa.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter18'

  // Terminate for MATLABSystem: '<S31>/Read Parameter17'
  if (!F550_FaultInjection_DW.obj_dn.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_dn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter17'
  F550_FaultInjection_PX4Timestamp_Term(&F550_FaultInjection_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S33>/SinkBlock'
  if (!F550_FaultInjection_DW.obj_i.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_i.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_i.isSetupComplete) {
      uORB_write_terminate(&F550_FaultInjection_DW.obj_i.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S33>/SinkBlock'

  // Terminate for MATLABSystem: '<S31>/Read Parameter19'
  if (!F550_FaultInjection_DW.obj_pe.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_pe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter19'

  // Terminate for MATLABSystem: '<S31>/Read Parameter21'
  if (!F550_FaultInjection_DW.obj_m.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter21'

  // Terminate for MATLABSystem: '<S31>/Read Parameter20'
  if (!F550_FaultInjection_DW.obj_d.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/Read Parameter20'
}

//
// File trailer for generated code.
//
// [EOF]
//
