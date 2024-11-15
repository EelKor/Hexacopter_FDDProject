//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hexacopter_ControllerWithNavigation_ver2023b_private.h
//
// Code generated for Simulink model 'Hexacopter_ControllerWithNavigation_ver2023b'.
//
// Model version                  : 4.4
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jul 27 17:27:58 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Hexacopter_ControllerWithNavigation_ver2023b_private_h_
#define RTW_HEADER_Hexacopter_ControllerWithNavigation_ver2023b_private_h_
#include "rtwtypes.h"
#include "Hexacopter_ControllerWithNavigation_ver2023b.h"
#include "Hexacopter_ControllerWithNavigation_ver2023b_types.h"
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
extern void Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Init
  (DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T *localDW);
extern void Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem(const
  real_T rtu_0[3], const real_T rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T *localB);
extern void Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Term
  (DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T *localDW);

#endif    // RTW_HEADER_Hexacopter_ControllerWithNavigation_ver2023b_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
