//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Navigation.h
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
#ifndef Navigation_h_
#define Navigation_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Write.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include "SITL_HEXA_Hovering_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

// Block signals for system '<S578>/MATLAB System'
struct B_MATLABSystem_SITL_HEXA_Hovering_T {
  real32_T MATLABSystem[3];            // '<S578>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S578>/MATLAB System'
struct DW_MATLABSystem_SITL_HEXA_Hovering_T {
  px4_internal_block_LLA2LocalCoordinatesNED_SITL_HEXA_Hovering_T obj;// '<S578>/MATLAB System' 
  boolean_T objisempty;                // '<S578>/MATLAB System'
};

extern void SITL_HEXA_Hovering_MATLABSystem_Init
  (DW_MATLABSystem_SITL_HEXA_Hovering_T *localDW);
extern void SITL_HEXA_Hovering_MATLABSystem(const real_T rtu_0[3], const real_T
  rtu_1[3], boolean_T rtu_2, uint8_T rtu_3, B_MATLABSystem_SITL_HEXA_Hovering_T *
  localB);
extern void SITL_HEXA_Hovering_Navigation_Init(void);
extern void SITL_HEXA_Hovering_Navigation(void);
extern void SITL_HEXA_Hovering_MATLABSystem_Term
  (DW_MATLABSystem_SITL_HEXA_Hovering_T *localDW);
extern void SITL_HEXA_Hovering_Navigation_Term(void);

#endif                                 // Navigation_h_

//
// File trailer for generated code.
//
// [EOF]
//
