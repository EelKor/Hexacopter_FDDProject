//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_Hexacopter_V2_private.h
//
// Code generated for Simulink model 'FLIGHT_Hexacopter_V2'.
//
// Model version                  : 1.165
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Jun  5 13:05:15 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef FLIGHT_Hexacopter_V2_private_h_
#define FLIGHT_Hexacopter_V2_private_h_
#include "rtwtypes.h"
#include "FLIGHT_Hexacopter_V2.h"
#include "FLIGHT_Hexacopter_V2_types.h"

extern real32_T rt_roundf_snf(real32_T u);
extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void FLIGHT_He_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_Hexaco_T *localDW);
extern void FLIGHT_Hexacop_PX4Timestamp(B_PX4Timestamp_FLIGHT_Hexacop_T *localB);
extern void FLIGHT__PX4Timestamp_c_Init(DW_PX4Timestamp_FLIGHT_Hexa_j_T *localDW);
extern void FLIGHT_Hexac_PX4Timestamp_j(B_PX4Timestamp_FLIGHT_Hexac_l_T *localB);
extern void FLIGHT__PX4Timestamp_k_Init(DW_PX4Timestamp_FLIGHT_Hexa_f_T *localDW);
extern void FLIGHT_Hexac_PX4Timestamp_p(B_PX4Timestamp_FLIGHT_Hexac_c_T *localB);
extern void FLIGHT_Hex_SourceBlock_Init(DW_SourceBlock_FLIGHT_Hexacop_T *localDW);
extern void FLIGHT_Hexacopt_SourceBlock(B_SourceBlock_FLIGHT_Hexacopt_T *localB,
  DW_SourceBlock_FLIGHT_Hexacop_T *localDW);
extern void FLIGHT_He_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_Hexaco_T *localDW);
extern void FLIGHT__PX4Timestamp_d_Term(DW_PX4Timestamp_FLIGHT_Hexa_j_T *localDW);
extern void FLIGHT__PX4Timestamp_m_Term(DW_PX4Timestamp_FLIGHT_Hexa_f_T *localDW);
extern void FLIGHT_Hex_SourceBlock_Term(DW_SourceBlock_FLIGHT_Hexacop_T *localDW);

#endif                                 // FLIGHT_Hexacopter_V2_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
