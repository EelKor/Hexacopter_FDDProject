//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter_private.h
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
#ifndef FLIGHT_hexacopter_private_h_
#define FLIGHT_hexacopter_private_h_
#include "rtwtypes.h"
#include "FLIGHT_hexacopter.h"
#include "FLIGHT_hexacopter_types.h"

// Used by FromWorkspace Block: '<S21>/fromWS_Signal 1'
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

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
extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real32_T rt_roundf_snf(real32_T u);
extern void FLIGHT_hexac_ReadParameter_Init(DW_ReadParameter_FLIGHT_hexac_T
  *localDW);
extern void FLIGHT_hexacopter_ReadParameter(DW_ReadParameter_FLIGHT_hexac_T
  *localDW);
extern void FLIGHT_hex_ReadParameter_e_Init(DW_ReadParameter_FLIGHT_hex_f_T
  *localDW);
extern void FLIGHT_hexacopt_ReadParameter_p(B_ReadParameter_FLIGHT_hexa_c_T
  *localB, DW_ReadParameter_FLIGHT_hex_f_T *localDW);
extern void FLIGHT_hexa_ReadParameter1_Init(DW_ReadParameter1_FLIGHT_hexa_T
  *localDW);
extern void FLIGHT_hexacopte_ReadParameter1(B_ReadParameter1_FLIGHT_hexac_T
  *localB, DW_ReadParameter1_FLIGHT_hexa_T *localDW);
extern void FLIGHT_hexa_ReadParameter2_Init(DW_ReadParameter2_FLIGHT_hexa_T
  *localDW);
extern void FLIGHT_hexacopte_ReadParameter2(B_ReadParameter2_FLIGHT_hexac_T
  *localB, DW_ReadParameter2_FLIGHT_hexa_T *localDW);
extern void FLIGHT_hexa_ReadParameter3_Init(DW_ReadParameter3_FLIGHT_hexa_T
  *localDW);
extern void FLIGHT_hexacopte_ReadParameter3(B_ReadParameter3_FLIGHT_hexac_T
  *localB, DW_ReadParameter3_FLIGHT_hexa_T *localDW);
extern void FLIGHT_hexaco_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_hexaco_T
  *localDW);
extern void FLIGHT_hexacopter_PX4Timestamp(B_PX4Timestamp_FLIGHT_hexacop_T
  *localB);
extern void FLIGHT_hexac_ReadParameter_Term(DW_ReadParameter_FLIGHT_hexac_T
  *localDW);
extern void FLIGHT_hex_ReadParameter_a_Term(DW_ReadParameter_FLIGHT_hex_f_T
  *localDW);
extern void FLIGHT_hexa_ReadParameter1_Term(DW_ReadParameter1_FLIGHT_hexa_T
  *localDW);
extern void FLIGHT_hexa_ReadParameter2_Term(DW_ReadParameter2_FLIGHT_hexa_T
  *localDW);
extern void FLIGHT_hexa_ReadParameter3_Term(DW_ReadParameter3_FLIGHT_hexa_T
  *localDW);
extern void FLIGHT_hexaco_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_hexaco_T
  *localDW);

#endif                                 // FLIGHT_hexacopter_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
