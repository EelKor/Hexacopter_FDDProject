//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_hexacopter_private.h
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.250
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri May 23 13:47:19 2025
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

extern real32_T rt_roundf_snf(real32_T u);
extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void FLIGHT_he_PX4Timestamp_Init(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW);
extern void FLIGHT_hexacop_PX4Timestamp(B_PX4Timestamp_FLIGHT_hexacop_T *localB);
extern void FLIGHT__PX4Timestamp_b_Init(DW_PX4Timestamp_FLIGHT_hexa_b_T *localDW);
extern void FLIGHT_hexac_PX4Timestamp_o(B_PX4Timestamp_FLIGHT_hexac_l_T *localB);
extern void FLIGHT__PX4Timestamp_m_Init(DW_PX4Timestamp_FLIGHT_hexa_f_T *localDW);
extern void FLIGHT_hexac_PX4Timestamp_n(B_PX4Timestamp_FLIGHT_hexac_h_T *localB);
extern void FLIGHT_he_PX4Timestamp_Term(DW_PX4Timestamp_FLIGHT_hexaco_T *localDW);
extern void FLIGHT__PX4Timestamp_o_Term(DW_PX4Timestamp_FLIGHT_hexa_b_T *localDW);
extern void FLIGHT__PX4Timestamp_k_Term(DW_PX4Timestamp_FLIGHT_hexa_f_T *localDW);

#endif                                 // FLIGHT_hexacopter_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
