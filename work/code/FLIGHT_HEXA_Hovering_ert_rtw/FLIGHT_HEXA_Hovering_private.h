//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering_private.h
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Jan  8 13:53:58 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_HEXA_Hovering_private_h_
#define FLIGHT_HEXA_Hovering_private_h_
#include "rtwtypes.h"
#include "FLIGHT_HEXA_Hovering.h"
#include "FLIGHT_HEXA_Hovering_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

// Skipping ulong_long/long_long check: insufficient preprocessor integer range. 
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void FLIGHT_HEXA_Hovering_SourceBlock_Init
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_T *localDW);
extern void FLIGHT_HEXA_Hovering_SourceBlock
  (B_SourceBlock_FLIGHT_HEXA_Hovering_T *localB,
   DW_SourceBlock_FLIGHT_HEXA_Hovering_T *localDW);
extern void FLIGHT_HEXA_Hovering_SourceBlock_k_Init
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T *localDW);
extern void FLIGHT_HEXA_Hovering_SourceBlock_b
  (B_SourceBlock_FLIGHT_HEXA_Hovering_i_T *localB,
   DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T *localDW);
extern void FLIGHT_HEXA_Hovering_MATLABSystem_Init
  (DW_MATLABSystem_FLIGHT_HEXA_Hovering_T *localDW);
extern void FLIGHT_HEXA_Hovering_MATLABSystem(const real_T rtu_0[3], const
  real_T rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T *localB);
extern void FLIGHT_HEXA_Hovering_SourceBlock_Term
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_T *localDW);
extern void FLIGHT_HEXA_Hovering_SourceBlock_o_Term
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T *localDW);
extern void FLIGHT_HEXA_Hovering_MATLABSystem_Term
  (DW_MATLABSystem_FLIGHT_HEXA_Hovering_T *localDW);

#endif                                 // FLIGHT_HEXA_Hovering_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
