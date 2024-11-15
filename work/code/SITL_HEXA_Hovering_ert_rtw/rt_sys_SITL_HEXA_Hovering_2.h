//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_SITL_HEXA_Hovering_2.h
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
#ifndef rt_sys_SITL_HEXA_Hovering_2_h_
#define rt_sys_SITL_HEXA_Hovering_2_h_
#include <drivers/drv_hrt.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_uORB_Write.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Read.h"
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include "SITL_HEXA_Hovering_types.h"

// Block states (default storage) for system '<S17>/SinkBlock'
struct DW_SinkBlock_SITL_HEXA_Hovering_T {
  px4_internal_block_Publisher_SITL_HEXA_Hovering_T obj;// '<S17>/SinkBlock'
  boolean_T objisempty;                // '<S17>/SinkBlock'
};

extern void SITL_HEXA_Hovering_SinkBlock_Init(const
  px4_Bus_vehicle_local_position_setpoint *rtu_0,
  DW_SinkBlock_SITL_HEXA_Hovering_T *localDW);
extern void SITL_HEXA_Hovering_SinkBlock(const
  px4_Bus_vehicle_local_position_setpoint *rtu_0,
  DW_SinkBlock_SITL_HEXA_Hovering_T *localDW);
extern void SITL_HEXA_Hovering_SinkBlock_Term(DW_SinkBlock_SITL_HEXA_Hovering_T *
  localDW);

#endif                                 // rt_sys_SITL_HEXA_Hovering_2_h_

//
// File trailer for generated code.
//
// [EOF]
//
