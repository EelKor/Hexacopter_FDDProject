//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering.cpp
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Jan  9 13:36:09 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_HEXA_Hovering.h"
#include "rtwtypes.h"
#include "FLIGHT_HEXA_Hovering_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"
#include <float.h>

// Named constants for Chart: '<S4>/Chart'
const uint8_T FLIGHT_HEXA_Hovering_IN_MISSION = 1U;
const uint8_T FLIGHT_HEXA_Hovering_IN_STABLIZED = 2U;
const real_T FLIGHT_HEXA_Hovering_period = 0.01;

// Block signals (default storage)
B_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_B;

// Block states (default storage)
DW_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_DW;

// Real-time model
RT_MODEL_FLIGHT_HEXA_Hovering_T FLIGHT_HEXA_Hovering_M_ =
  RT_MODEL_FLIGHT_HEXA_Hovering_T();
RT_MODEL_FLIGHT_HEXA_Hovering_T *const FLIGHT_HEXA_Hovering_M =
  &FLIGHT_HEXA_Hovering_M_;

// Forward declaration for local functions
static real_T FLIGHT_HEXA_Hovering_sind(real_T x);

// Forward declaration for local functions
static real_T FLIGHT_HEXA_Hovering_rt_atan2d_snf(real_T u0, real_T u1);
static real_T FLIGHT_HEXA_Hovering_rt_remd_snf(real_T u0, real_T u1);
static real_T FLIGHT_HEXA_Hovering_sind_d(real_T x);
static void FLIGHT_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0
  [3], real_T xyzNED[3]);
static real_T FLIGHT_HEXA_Hovering_norm(const real_T x[3]);

// System initialize for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_Init(DW_SourceBlock_FLIGHT_HEXA_Hovering_T
  *localDW)
{
  // Start for MATLABSystem: '<S6>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(actuator_armed);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock(B_SourceBlock_FLIGHT_HEXA_Hovering_T
  *localB, DW_SourceBlock_FLIGHT_HEXA_Hovering_T *localDW)
{
  // MATLABSystem: '<S6>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_Term(DW_SourceBlock_FLIGHT_HEXA_Hovering_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

// System initialize for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_k_Init
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T *localDW)
{
  // Start for MATLABSystem: '<S12>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(input_rc);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_b(B_SourceBlock_FLIGHT_HEXA_Hovering_i_T
  *localB, DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T *localDW)
{
  // MATLABSystem: '<S12>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 5000.0);
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_o_Term
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_m_T *localDW)
{
  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    real_T q;
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

static real_T FLIGHT_HEXA_Hovering_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S42>/MATLAB System'
  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = rt_remd_snf(x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      b_x = sin(b_x);
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        b_x = cos(b_x);
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        b_x = -cos(b_x);
      }
    } else {
      if (b_x > 0.0) {
        b_x = (b_x - 180.0) * 0.017453292519943295;
      } else {
        b_x = (b_x + 180.0) * 0.017453292519943295;
      }

      b_x = -sin(b_x);
    }
  }

  // End of Start for MATLABSystem: '<S42>/MATLAB System'
  return b_x;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
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

// System initialize for atomic system:
void FLIGHT_HEXA_Hovering_MATLABSystem_Init
  (DW_MATLABSystem_FLIGHT_HEXA_Hovering_T *localDW)
{
  // Start for MATLABSystem: '<S42>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_HEXA_Hovering_MATLABSystem(const real_T rtu_0[3], const real_T
  rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T *localB)
{
  real_T absx;
  real_T dLon;
  real_T flat;
  real_T flat_tmp;
  real_T r;
  int32_T b_k;
  boolean_T b[3];
  boolean_T exitg1;
  boolean_T latp2;

  // MATLABSystem: '<S42>/MATLAB System'
  if (rtu_2 && (rtu_3 != 5)) {
    localB->dLat = rtu_0[0] - rtu_1[0];
    dLon = rtu_0[1] - rtu_1[1];
    flat = fabs(localB->dLat);
    if (flat > 180.0) {
      if (rtIsNaN(localB->dLat + 180.0) || rtIsInf(localB->dLat + 180.0)) {
        r = (rtNaN);
      } else if (localB->dLat + 180.0 == 0.0) {
        r = 0.0;
      } else {
        r = fmod(localB->dLat + 180.0, 360.0);
        if (r == 0.0) {
          r = 0.0;
        } else if (localB->dLat + 180.0 < 0.0) {
          r += 360.0;
        }
      }

      localB->dLat = localB->dLat * 0.0 + (r - 180.0);
      flat = fabs(localB->dLat);
    }

    if (flat > 90.0) {
      flat = fabs(localB->dLat);
      latp2 = (flat > 90.0);
      dLon += 180.0;
      r = localB->dLat * static_cast<real_T>(latp2);
      if (rtIsNaN(r)) {
        r = (rtNaN);
      } else if (r < 0.0) {
        r = -1.0;
      } else {
        r = (r > 0.0);
      }

      localB->dLat = (90.0 - (flat * static_cast<real_T>(latp2) - 90.0)) * r *
        static_cast<real_T>(latp2) + localB->dLat * static_cast<real_T>(!latp2);
    }

    if ((dLon > 180.0) || (dLon < -180.0)) {
      flat = rt_remd_snf(dLon, 360.0);
      r = flat / 180.0;
      if (r < 0.0) {
        r = ceil(r);
      } else {
        r = floor(r);
      }

      dLon = (flat - 360.0 * r) + dLon * 0.0;
    }

    flat = FLIGHT_HEXA_Hovering_sind(rtu_1[0]);
    flat_tmp = 1.0 - 0.0066943799901413165 * flat * flat;
    flat = 6.378137E+6 / sqrt(flat_tmp);
    if (rtIsInf(rtu_1[0]) || rtIsNaN(rtu_1[0])) {
      r = (rtNaN);
    } else {
      r = rt_remd_snf(rtu_1[0], 360.0);
      absx = fabs(r);
      if (absx > 180.0) {
        if (r > 0.0) {
          r -= 360.0;
        } else {
          r += 360.0;
        }

        absx = fabs(r);
      }

      if (absx <= 45.0) {
        r = cos(0.017453292519943295 * r);
      } else if (absx <= 135.0) {
        if (r > 0.0) {
          r = -sin((r - 90.0) * 0.017453292519943295);
        } else {
          r = sin((r + 90.0) * 0.017453292519943295);
        }
      } else {
        if (r > 0.0) {
          r = (r - 180.0) * 0.017453292519943295;
        } else {
          r = (r + 180.0) * 0.017453292519943295;
        }

        r = -cos(r);
      }
    }

    localB->dLat /= rt_atan2d_snf(1.0, 0.99330562000985867 / flat_tmp * flat) *
      57.295779513082323;
    dLon /= rt_atan2d_snf(1.0, flat * r) * 57.295779513082323;
    flat = -rtu_0[2] + rtu_1[2];
    b[0] = rtIsNaN(localB->dLat);
    b[1] = rtIsNaN(dLon);
    b[2] = rtIsNaN(flat);
    latp2 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
      if (b[b_k]) {
        latp2 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    r = 0.0 / static_cast<real_T>(!latp2);

    // MATLABSystem: '<S42>/MATLAB System'
    localB->MATLABSystem[0] = static_cast<real32_T>(r + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(r + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(r + flat);
  } else {
    // MATLABSystem: '<S42>/MATLAB System'
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S42>/MATLAB System'
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_MATLABSystem_Term
  (DW_MATLABSystem_FLIGHT_HEXA_Hovering_T *localDW)
{
  // Terminate for MATLABSystem: '<S42>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S42>/MATLAB System'
}

static real_T FLIGHT_HEXA_Hovering_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      FLIGHT_HEXA_Hovering_B.i = 1;
    } else {
      FLIGHT_HEXA_Hovering_B.i = -1;
    }

    if (u1 > 0.0) {
      FLIGHT_HEXA_Hovering_B.i1_b = 1;
    } else {
      FLIGHT_HEXA_Hovering_B.i1_b = -1;
    }

    y = atan2(static_cast<real_T>(FLIGHT_HEXA_Hovering_B.i), static_cast<real_T>
              (FLIGHT_HEXA_Hovering_B.i1_b));
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

static real_T FLIGHT_HEXA_Hovering_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      FLIGHT_HEXA_Hovering_B.q = ceil(u1);
    } else {
      FLIGHT_HEXA_Hovering_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != FLIGHT_HEXA_Hovering_B.q)) {
      FLIGHT_HEXA_Hovering_B.q = fabs(u0 / u1);
      if (!(fabs(FLIGHT_HEXA_Hovering_B.q - floor(FLIGHT_HEXA_Hovering_B.q + 0.5))
            > DBL_EPSILON * FLIGHT_HEXA_Hovering_B.q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

static real_T FLIGHT_HEXA_Hovering_sind_d(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S45>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = FLIGHT_HEXA_Hovering_rt_remd_snf(x, 360.0);
    FLIGHT_HEXA_Hovering_B.absx_c = fabs(b_x);
    if (FLIGHT_HEXA_Hovering_B.absx_c > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      FLIGHT_HEXA_Hovering_B.absx_c = fabs(b_x);
    }

    if (FLIGHT_HEXA_Hovering_B.absx_c <= 45.0) {
      b_x *= 0.017453292519943295;
      b_x = sin(b_x);
    } else if (FLIGHT_HEXA_Hovering_B.absx_c <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        b_x = cos(b_x);
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        b_x = -cos(b_x);
      }
    } else {
      if (b_x > 0.0) {
        b_x = (b_x - 180.0) * 0.017453292519943295;
      } else {
        b_x = (b_x + 180.0) * 0.017453292519943295;
      }

      b_x = -sin(b_x);
    }
  }

  // End of Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
  return b_x;
}

static void FLIGHT_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0
  [3], real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
  FLIGHT_HEXA_Hovering_B.dLat = lla[0] - lla0[0];
  FLIGHT_HEXA_Hovering_B.dLon = lla[1] - lla0[1];
  FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
  if (FLIGHT_HEXA_Hovering_B.flat > 180.0) {
    // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.dLat + 180.0) || rtIsInf
        (FLIGHT_HEXA_Hovering_B.dLat + 180.0)) {
      FLIGHT_HEXA_Hovering_B.r_m = (rtNaN);
    } else if (FLIGHT_HEXA_Hovering_B.dLat + 180.0 == 0.0) {
      FLIGHT_HEXA_Hovering_B.r_m = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.r_m = fmod(FLIGHT_HEXA_Hovering_B.dLat + 180.0,
        360.0);
      if (FLIGHT_HEXA_Hovering_B.r_m == 0.0) {
        FLIGHT_HEXA_Hovering_B.r_m = 0.0;
      } else if (FLIGHT_HEXA_Hovering_B.dLat + 180.0 < 0.0) {
        FLIGHT_HEXA_Hovering_B.r_m += 360.0;
      }
    }

    FLIGHT_HEXA_Hovering_B.dLat = FLIGHT_HEXA_Hovering_B.dLat * 0.0 +
      (FLIGHT_HEXA_Hovering_B.r_m - 180.0);
    FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
  }

  if (FLIGHT_HEXA_Hovering_B.flat > 90.0) {
    // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
    FLIGHT_HEXA_Hovering_B.latp2 = (FLIGHT_HEXA_Hovering_B.flat > 90.0);

    // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_B.dLon += 180.0;
    FLIGHT_HEXA_Hovering_B.r_m = FLIGHT_HEXA_Hovering_B.dLat *
      static_cast<real_T>(FLIGHT_HEXA_Hovering_B.latp2);
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.r_m)) {
      FLIGHT_HEXA_Hovering_B.r_m = (rtNaN);
    } else if (FLIGHT_HEXA_Hovering_B.r_m < 0.0) {
      FLIGHT_HEXA_Hovering_B.r_m = -1.0;
    } else {
      FLIGHT_HEXA_Hovering_B.r_m = (FLIGHT_HEXA_Hovering_B.r_m > 0.0);
    }

    FLIGHT_HEXA_Hovering_B.dLat = (90.0 - (FLIGHT_HEXA_Hovering_B.flat *
      static_cast<real_T>(FLIGHT_HEXA_Hovering_B.latp2) - 90.0)) *
      FLIGHT_HEXA_Hovering_B.r_m * static_cast<real_T>
      (FLIGHT_HEXA_Hovering_B.latp2) + FLIGHT_HEXA_Hovering_B.dLat *
      static_cast<real_T>(!FLIGHT_HEXA_Hovering_B.latp2);
  }

  // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
  if ((FLIGHT_HEXA_Hovering_B.dLon > 180.0) || (FLIGHT_HEXA_Hovering_B.dLon <
       -180.0)) {
    FLIGHT_HEXA_Hovering_B.flat = FLIGHT_HEXA_Hovering_rt_remd_snf
      (FLIGHT_HEXA_Hovering_B.dLon, 360.0);
    FLIGHT_HEXA_Hovering_B.r_m = FLIGHT_HEXA_Hovering_B.flat / 180.0;
    if (FLIGHT_HEXA_Hovering_B.r_m < 0.0) {
      FLIGHT_HEXA_Hovering_B.r_m = ceil(FLIGHT_HEXA_Hovering_B.r_m);
    } else {
      FLIGHT_HEXA_Hovering_B.r_m = floor(FLIGHT_HEXA_Hovering_B.r_m);
    }

    FLIGHT_HEXA_Hovering_B.dLon = (FLIGHT_HEXA_Hovering_B.flat - 360.0 *
      FLIGHT_HEXA_Hovering_B.r_m) + FLIGHT_HEXA_Hovering_B.dLon * 0.0;
  }

  FLIGHT_HEXA_Hovering_B.flat = FLIGHT_HEXA_Hovering_sind_d(lla0[0]);
  FLIGHT_HEXA_Hovering_B.flat_tmp = 1.0 - 0.0066943799901413165 *
    FLIGHT_HEXA_Hovering_B.flat * FLIGHT_HEXA_Hovering_B.flat;
  FLIGHT_HEXA_Hovering_B.flat = 6.378137E+6 / sqrt
    (FLIGHT_HEXA_Hovering_B.flat_tmp);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    FLIGHT_HEXA_Hovering_B.r_m = (rtNaN);
  } else {
    FLIGHT_HEXA_Hovering_B.r_m = FLIGHT_HEXA_Hovering_rt_remd_snf(lla0[0], 360.0);
    FLIGHT_HEXA_Hovering_B.absx = fabs(FLIGHT_HEXA_Hovering_B.r_m);
    if (FLIGHT_HEXA_Hovering_B.absx > 180.0) {
      if (FLIGHT_HEXA_Hovering_B.r_m > 0.0) {
        FLIGHT_HEXA_Hovering_B.r_m -= 360.0;
      } else {
        FLIGHT_HEXA_Hovering_B.r_m += 360.0;
      }

      FLIGHT_HEXA_Hovering_B.absx = fabs(FLIGHT_HEXA_Hovering_B.r_m);
    }

    if (FLIGHT_HEXA_Hovering_B.absx <= 45.0) {
      FLIGHT_HEXA_Hovering_B.r_m = cos(0.017453292519943295 *
        FLIGHT_HEXA_Hovering_B.r_m);
    } else if (FLIGHT_HEXA_Hovering_B.absx <= 135.0) {
      if (FLIGHT_HEXA_Hovering_B.r_m > 0.0) {
        FLIGHT_HEXA_Hovering_B.r_m = -sin((FLIGHT_HEXA_Hovering_B.r_m - 90.0) *
          0.017453292519943295);
      } else {
        FLIGHT_HEXA_Hovering_B.r_m = sin((FLIGHT_HEXA_Hovering_B.r_m + 90.0) *
          0.017453292519943295);
      }
    } else {
      if (FLIGHT_HEXA_Hovering_B.r_m > 0.0) {
        FLIGHT_HEXA_Hovering_B.r_m = (FLIGHT_HEXA_Hovering_B.r_m - 180.0) *
          0.017453292519943295;
      } else {
        FLIGHT_HEXA_Hovering_B.r_m = (FLIGHT_HEXA_Hovering_B.r_m + 180.0) *
          0.017453292519943295;
      }

      FLIGHT_HEXA_Hovering_B.r_m = -cos(FLIGHT_HEXA_Hovering_B.r_m);
    }
  }

  xyzNED[0] = FLIGHT_HEXA_Hovering_B.dLat / (FLIGHT_HEXA_Hovering_rt_atan2d_snf
    (1.0, 0.99330562000985867 / FLIGHT_HEXA_Hovering_B.flat_tmp *
     FLIGHT_HEXA_Hovering_B.flat) * 57.295779513082323);
  xyzNED[1] = FLIGHT_HEXA_Hovering_B.dLon / (FLIGHT_HEXA_Hovering_rt_atan2d_snf
    (1.0, FLIGHT_HEXA_Hovering_B.flat * FLIGHT_HEXA_Hovering_B.r_m) *
    57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  FLIGHT_HEXA_Hovering_B.b[0] = rtIsNaN(xyzNED[0]);
  FLIGHT_HEXA_Hovering_B.b[1] = rtIsNaN(xyzNED[1]);
  FLIGHT_HEXA_Hovering_B.b[2] = rtIsNaN(xyzNED[2]);
  FLIGHT_HEXA_Hovering_B.latp2 = false;
  FLIGHT_HEXA_Hovering_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.b_k < 3)) {
    if (FLIGHT_HEXA_Hovering_B.b[FLIGHT_HEXA_Hovering_B.b_k]) {
      FLIGHT_HEXA_Hovering_B.latp2 = true;
      exitg1 = true;
    } else {
      FLIGHT_HEXA_Hovering_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
  FLIGHT_HEXA_Hovering_B.dLat = 0.0 / static_cast<real_T>
    (!FLIGHT_HEXA_Hovering_B.latp2);
  xyzNED[0] += FLIGHT_HEXA_Hovering_B.dLat;
  xyzNED[1] += FLIGHT_HEXA_Hovering_B.dLat;
  xyzNED[2] += FLIGHT_HEXA_Hovering_B.dLat;
}

static real_T FLIGHT_HEXA_Hovering_norm(const real_T x[3])
{
  real_T y;
  FLIGHT_HEXA_Hovering_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S23>/UAV Waypoint Follower'
  FLIGHT_HEXA_Hovering_B.absxk = fabs(x[0]);
  if (FLIGHT_HEXA_Hovering_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    FLIGHT_HEXA_Hovering_B.scale = FLIGHT_HEXA_Hovering_B.absxk;
  } else {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.absxk /
      3.3121686421112381E-170;
    y = FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t;
  }

  // Start for MATLABSystem: '<S23>/UAV Waypoint Follower'
  FLIGHT_HEXA_Hovering_B.absxk = fabs(x[1]);
  if (FLIGHT_HEXA_Hovering_B.absxk > FLIGHT_HEXA_Hovering_B.scale) {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.scale /
      FLIGHT_HEXA_Hovering_B.absxk;
    y = y * FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t + 1.0;
    FLIGHT_HEXA_Hovering_B.scale = FLIGHT_HEXA_Hovering_B.absxk;
  } else {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.absxk /
      FLIGHT_HEXA_Hovering_B.scale;
    y += FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t;
  }

  // Start for MATLABSystem: '<S23>/UAV Waypoint Follower'
  FLIGHT_HEXA_Hovering_B.absxk = fabs(x[2]);
  if (FLIGHT_HEXA_Hovering_B.absxk > FLIGHT_HEXA_Hovering_B.scale) {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.scale /
      FLIGHT_HEXA_Hovering_B.absxk;
    y = y * FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t + 1.0;
    FLIGHT_HEXA_Hovering_B.scale = FLIGHT_HEXA_Hovering_B.absxk;
  } else {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.absxk /
      FLIGHT_HEXA_Hovering_B.scale;
    y += FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t;
  }

  return FLIGHT_HEXA_Hovering_B.scale * sqrt(y);
}

// Model step function
void FLIGHT_HEXA_Hovering_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  FLIGHT_HEXA_Hovering_SourceBlock_b(&FLIGHT_HEXA_Hovering_B.SourceBlock_g,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_g);

  // Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S70>/Enable'

  if (FLIGHT_HEXA_Hovering_B.SourceBlock_g.SourceBlock_o1) {
    // SignalConversion generated from: '<S70>/In1' incorporates:
    //   MATLABSystem: '<S69>/SourceBlock'

    FLIGHT_HEXA_Hovering_B.In1_h =
      FLIGHT_HEXA_Hovering_B.SourceBlock_g.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S69>/Enabled Subsystem'

  // RelationalOperator: '<S60>/Compare' incorporates:
  //   Constant: '<S60>/Constant'
  //   DataTypeConversion: '<S54>/Data Type Conversion'

  FLIGHT_HEXA_Hovering_B.Compare_k = (FLIGHT_HEXA_Hovering_B.In1_h.values[6] >=
    FLIGHT_HEXA_Hovering_P.CompareToConstant_const);

  // MATLABSystem: '<S8>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.OR_g = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_gv.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_gv.eventStructObj, &FLIGHT_HEXA_Hovering_B.r3,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    // SignalConversion generated from: '<S14>/In1'
    FLIGHT_HEXA_Hovering_B.In1_m = FLIGHT_HEXA_Hovering_B.r3;
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'

  // DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
  //   Switch: '<S77>/Switch'

  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = FLIGHT_HEXA_Hovering_B.In1_m.q[0];
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = FLIGHT_HEXA_Hovering_B.In1_m.q[1];
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 = FLIGHT_HEXA_Hovering_B.In1_m.q[2];
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = FLIGHT_HEXA_Hovering_B.In1_m.q[3];

  // Switch: '<S77>/Switch' incorporates:
  //   Constant: '<S77>/Constant'
  //   DataTypeConversion: '<S1>/Data Type Conversion'
  //   Product: '<S603>/Product'
  //   Product: '<S603>/Product1'
  //   Product: '<S603>/Product2'
  //   Product: '<S603>/Product3'
  //   Sum: '<S603>/Sum'

  if (!(((static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_m.q[0]) *
          FLIGHT_HEXA_Hovering_B.In1_m.q[0] + static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.In1_m.q[1]) * FLIGHT_HEXA_Hovering_B.In1_m.q[1])
         + static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_m.q[2]) *
         FLIGHT_HEXA_Hovering_B.In1_m.q[2]) + static_cast<real_T>
        (FLIGHT_HEXA_Hovering_B.In1_m.q[3]) * FLIGHT_HEXA_Hovering_B.In1_m.q[3] >
        FLIGHT_HEXA_Hovering_P.Switch_Threshold_o)) {
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_pp[0];
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_pp[1];
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_pp[2];
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_pp[3];
  }

  // End of Switch: '<S77>/Switch'

  // Sqrt: '<S610>/sqrt' incorporates:
  //   Product: '<S611>/Product'
  //   Product: '<S611>/Product1'
  //   Product: '<S611>/Product2'
  //   Product: '<S611>/Product3'
  //   Sum: '<S611>/Sum'

  FLIGHT_HEXA_Hovering_B.Switch2 = sqrt
    (((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 *
       FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 +
       FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
       FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2) +
     FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 *
     FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3);

  // Product: '<S605>/Product'
  FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 /
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Product: '<S605>/Product1'
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 /= FLIGHT_HEXA_Hovering_B.Switch2;

  // Product: '<S605>/Product2'
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 / FLIGHT_HEXA_Hovering_B.Switch2;

  // Product: '<S605>/Product3'
  FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 /
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Fcn: '<S78>/fcn2' incorporates:
  //   Fcn: '<S78>/fcn5'

  FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Switch3 *
    FLIGHT_HEXA_Hovering_B.Switch3;
  FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1;
  FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 *
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0;
  FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_B.Switch2 *
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Trigonometry: '<S604>/Trigonometric Function1' incorporates:
  //   Fcn: '<S78>/fcn1'
  //   Fcn: '<S78>/fcn2'

  FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
    FLIGHT_HEXA_Hovering_rt_atan2d_snf
    ((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 +
      FLIGHT_HEXA_Hovering_B.Switch3 * FLIGHT_HEXA_Hovering_B.Switch2) * 2.0,
     ((FLIGHT_HEXA_Hovering_B.Gain2 + FLIGHT_HEXA_Hovering_B.Sum) -
      FLIGHT_HEXA_Hovering_B.Gain_i) - FLIGHT_HEXA_Hovering_B.Sum5);

  // Fcn: '<S78>/fcn3'
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
    (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 * FLIGHT_HEXA_Hovering_B.Switch2
     - FLIGHT_HEXA_Hovering_B.Switch3 *
     FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * -2.0;

  // Trigonometry: '<S604>/Trigonometric Function3' incorporates:
  //   Fcn: '<S78>/fcn4'
  //   Fcn: '<S78>/fcn5'

  FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
    FLIGHT_HEXA_Hovering_rt_atan2d_snf
    ((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 *
      FLIGHT_HEXA_Hovering_B.Switch2 + FLIGHT_HEXA_Hovering_B.Switch3 *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) * 2.0,
     ((FLIGHT_HEXA_Hovering_B.Gain2 - FLIGHT_HEXA_Hovering_B.Sum) -
      FLIGHT_HEXA_Hovering_B.Gain_i) + FLIGHT_HEXA_Hovering_B.Sum5);

  // MATLABSystem: '<S5>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.OR_g = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_p.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_p.eventStructObj, &FLIGHT_HEXA_Hovering_B.r5,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // Start for MATLABSystem: '<S5>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    // SignalConversion generated from: '<S10>/In1'
    FLIGHT_HEXA_Hovering_B.In1_l = FLIGHT_HEXA_Hovering_B.r5;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  FLIGHT_HEXA_Hovering_SourceBlock(&FLIGHT_HEXA_Hovering_B.SourceBlock_l,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_l);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (FLIGHT_HEXA_Hovering_B.SourceBlock_l.SourceBlock_o1) {
    // SignalConversion generated from: '<S11>/In1' incorporates:
    //   MATLABSystem: '<S6>/SourceBlock'

    FLIGHT_HEXA_Hovering_B.In1_b =
      FLIGHT_HEXA_Hovering_B.SourceBlock_l.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  FLIGHT_HEXA_Hovering_SourceBlock_b(&FLIGHT_HEXA_Hovering_B.SourceBlock_b,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_b);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (FLIGHT_HEXA_Hovering_B.SourceBlock_b.SourceBlock_o1) {
    // SignalConversion generated from: '<S13>/In1' incorporates:
    //   MATLABSystem: '<S12>/SourceBlock'

    FLIGHT_HEXA_Hovering_B.In1_j =
      FLIGHT_HEXA_Hovering_B.SourceBlock_b.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'

  // Gain: '<S75>/Gain2' incorporates:
  //   Constant: '<S75>/Constant2'
  //   Sum: '<S75>/Sum2'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[1]) -
    FLIGHT_HEXA_Hovering_P.Constant2_Value_g) *
    FLIGHT_HEXA_Hovering_P.Gain2_Gain_d;

  // Saturate: '<S75>/Saturation2'
  if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
      FLIGHT_HEXA_Hovering_P.Saturation2_UpperSat) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation2_UpperSat;
  } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
             FLIGHT_HEXA_Hovering_P.Saturation2_LowerSat) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation2_LowerSat;
  }

  // Gain: '<S4>/Gain1' incorporates:
  //   Saturate: '<S75>/Saturation2'

  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_h * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

  // Gain: '<S75>/Gain1' incorporates:
  //   Constant: '<S75>/Constant1'
  //   Sum: '<S75>/Sum1'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[0]) -
    FLIGHT_HEXA_Hovering_P.Constant1_Value_h) *
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_e;

  // Saturate: '<S75>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_p) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_p;
  } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_j) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_j;
  }

  // Gain: '<S4>/Gain2' incorporates:
  //   Saturate: '<S75>/Saturation1'

  FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_P.Gain2_Gain_m *
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

  // Gain: '<S75>/Gain' incorporates:
  //   Constant: '<S75>/Constant'
  //   Sum: '<S75>/Sum'

  FLIGHT_HEXA_Hovering_B.Sum = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[2]) -
    FLIGHT_HEXA_Hovering_P.Constant_Value_ol) *
    FLIGHT_HEXA_Hovering_P.Gain_Gain_e;

  // Saturate: '<S75>/Saturation'
  if (FLIGHT_HEXA_Hovering_B.Sum > FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_ji)
  {
    FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_ji;
  } else if (FLIGHT_HEXA_Hovering_B.Sum <
             FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_l4) {
    FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_l4;
  }

  // End of Saturate: '<S75>/Saturation'

  // Gain: '<S75>/Gain3' incorporates:
  //   Constant: '<S75>/Constant3'
  //   Sum: '<S75>/Sum3'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[3]) -
    FLIGHT_HEXA_Hovering_P.Constant3_Value_n) *
    FLIGHT_HEXA_Hovering_P.Gain3_Gain;

  // Saturate: '<S75>/Saturation3'
  if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
      FLIGHT_HEXA_Hovering_P.Saturation3_UpperSat) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation3_UpperSat;
  } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
             FLIGHT_HEXA_Hovering_P.Saturation3_LowerSat) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation3_LowerSat;
  }

  // Gain: '<S4>/Gain4' incorporates:
  //   Saturate: '<S75>/Saturation3'

  FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_P.Gain4_Gain *
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

  // MATLABSystem: '<S9>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.OR_g = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_mg.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_mg.eventStructObj, &FLIGHT_HEXA_Hovering_B.r2,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  // Start for MATLABSystem: '<S9>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    // SignalConversion generated from: '<S15>/In1'
    FLIGHT_HEXA_Hovering_B.In1_c = FLIGHT_HEXA_Hovering_B.r2;
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'

  // MATLABSystem: '<S19>/Read Parameter'
  if (FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // MATLABSystem: '<S40>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.OR_g = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj, &FLIGHT_HEXA_Hovering_B.r,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S41>/Enable'

  // Start for MATLABSystem: '<S40>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    // SignalConversion generated from: '<S41>/In1'
    FLIGHT_HEXA_Hovering_B.In1 = FLIGHT_HEXA_Hovering_B.r;
  }

  // End of Outputs for SubSystem: '<S40>/Enabled Subsystem'

  // MATLABSystem: '<S38>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.OR_g = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj, &FLIGHT_HEXA_Hovering_B.r1,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S38>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S53>/Enable'

  // Start for MATLABSystem: '<S38>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    // SignalConversion generated from: '<S53>/In1'
    FLIGHT_HEXA_Hovering_B.In1_p = FLIGHT_HEXA_Hovering_B.r1;
  }

  // End of Outputs for SubSystem: '<S38>/Enabled Subsystem'

  // MATLABSystem: '<S37>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.OR_g = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj, &FLIGHT_HEXA_Hovering_B.r4,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S37>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S52>/Enable'

  // Start for MATLABSystem: '<S37>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    // SignalConversion generated from: '<S52>/In1'
    FLIGHT_HEXA_Hovering_B.In1_f = FLIGHT_HEXA_Hovering_B.r4;
  }

  // End of Outputs for SubSystem: '<S37>/Enabled Subsystem'

  // MATLABSystem: '<S19>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S19>/Read Parameter'
  //   SignalConversion generated from: '<S52>/In1'
  //
  FLIGHT_HEXA_Hovering_B.b_startWaypoint[0] = 0.0;
  FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] = 0.0;
  FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] = 0.0;
  FLIGHT_HEXA_Hovering_B.b_startWaypoint[1] = 0.0;
  FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] = 0.0;
  FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] = 0.0;
  FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] = 0.0;
  FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] = 0.0;
  FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] = 0.0;
  FLIGHT_HEXA_Hovering_B.lla0[0] = FLIGHT_HEXA_Hovering_B.In1_f.lat;
  FLIGHT_HEXA_Hovering_B.lla0[1] = FLIGHT_HEXA_Hovering_B.In1_f.lon;
  FLIGHT_HEXA_Hovering_B.lla0[2] = FLIGHT_HEXA_Hovering_B.In1_f.alt;
  if (FLIGHT_HEXA_Hovering_B.In1_p.previous.valid &&
      (!FLIGHT_HEXA_Hovering_DW.obj_mr.previousValidReceived)) {
    FLIGHT_HEXA_Hovering_DW.obj_mr.previousValidReceived = true;
  }

  if (FLIGHT_HEXA_Hovering_B.In1_p.next.valid &&
      (!FLIGHT_HEXA_Hovering_DW.obj_mr.nextValidReceived)) {
    FLIGHT_HEXA_Hovering_DW.obj_mr.nextValidReceived = true;
  }

  if (FLIGHT_HEXA_Hovering_B.In1_f.valid_hpos &&
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid &&
      (FLIGHT_HEXA_Hovering_B.In1_p.current.type != 5)) {
    if (FLIGHT_HEXA_Hovering_B.ParamStep_k != 0) {
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
        FLIGHT_HEXA_Hovering_B.In1.waypoints[0].position[0];
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
        FLIGHT_HEXA_Hovering_B.In1.waypoints[0].position[1];
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
        FLIGHT_HEXA_Hovering_B.In1.waypoints[0].position[2];
    } else {
      FLIGHT_HEXA_Hovering_B.dv[0] = FLIGHT_HEXA_Hovering_B.In1_p.current.lat;
      FLIGHT_HEXA_Hovering_B.dv[1] = FLIGHT_HEXA_Hovering_B.In1_p.current.lon;
      FLIGHT_HEXA_Hovering_B.dv[2] = FLIGHT_HEXA_Hovering_B.In1_p.current.alt;
      FLIGHT_HEXA_Hovering_lla2ned(FLIGHT_HEXA_Hovering_B.dv,
        FLIGHT_HEXA_Hovering_B.lla0, FLIGHT_HEXA_Hovering_B.DataTypeConversion2);
    }
  }

  if (FLIGHT_HEXA_Hovering_B.In1_f.valid_hpos &&
      (FLIGHT_HEXA_Hovering_B.In1_p.previous.valid ||
       FLIGHT_HEXA_Hovering_DW.obj_mr.previousValidReceived)) {
    FLIGHT_HEXA_Hovering_B.dv[0] = FLIGHT_HEXA_Hovering_B.In1_p.previous.lat;
    FLIGHT_HEXA_Hovering_B.dv[1] = FLIGHT_HEXA_Hovering_B.In1_p.previous.lon;
    FLIGHT_HEXA_Hovering_B.dv[2] = FLIGHT_HEXA_Hovering_B.In1_p.previous.alt;
    FLIGHT_HEXA_Hovering_lla2ned(FLIGHT_HEXA_Hovering_B.dv,
      FLIGHT_HEXA_Hovering_B.lla0, FLIGHT_HEXA_Hovering_B.b_startWaypoint);
  }

  if (FLIGHT_HEXA_Hovering_B.In1_f.valid_hpos &&
      (FLIGHT_HEXA_Hovering_B.In1_p.next.valid ||
       FLIGHT_HEXA_Hovering_DW.obj_mr.nextValidReceived)) {
    FLIGHT_HEXA_Hovering_B.dv[0] = FLIGHT_HEXA_Hovering_B.In1_p.next.lat;
    FLIGHT_HEXA_Hovering_B.dv[1] = FLIGHT_HEXA_Hovering_B.In1_p.next.lon;
    FLIGHT_HEXA_Hovering_B.dv[2] = FLIGHT_HEXA_Hovering_B.In1_p.next.alt;
    FLIGHT_HEXA_Hovering_lla2ned(FLIGHT_HEXA_Hovering_B.dv,
      FLIGHT_HEXA_Hovering_B.lla0, FLIGHT_HEXA_Hovering_B.virtualWaypoint);
  }

  // If: '<S18>/If' incorporates:
  //   Delay: '<S24>/Delay'
  //   Delay: '<S27>/Delay'
  //   Delay: '<S31>/Delay'
  //   MATLABSystem: '<S19>/LLA2LocalCoordinates'
  //
  FLIGHT_HEXA_Hovering_B.rtPrevAction =
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem;
  if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 3) {
    FLIGHT_HEXA_Hovering_B.rtAction = 0;
  } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 4) {
    FLIGHT_HEXA_Hovering_B.rtAction = 1;
  } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 0) {
    FLIGHT_HEXA_Hovering_B.rtAction = 2;
  } else {
    FLIGHT_HEXA_Hovering_B.rtAction = 3;
  }

  FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = FLIGHT_HEXA_Hovering_B.rtAction;
  switch (FLIGHT_HEXA_Hovering_B.rtAction) {
   case 0:
    if (FLIGHT_HEXA_Hovering_B.rtAction != FLIGHT_HEXA_Hovering_B.rtPrevAction)
    {
      // InitializeConditions for IfAction SubSystem: '<S18>/Take-off' incorporates:
      //   ActionPort: '<S22>/Action Port'

      // InitializeConditions for If: '<S18>/If' incorporates:
      //   Delay: '<S30>/Delay'
      //   Delay: '<S31>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S18>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S18>/Take-off' incorporates:
    //   ActionPort: '<S22>/Action Port'

    // Sum: '<S30>/Sum' incorporates:
    //   Constant: '<S30>/Rate'
    //   Delay: '<S30>/Delay'

    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Rate_Value +
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c;

    // Gain: '<S30>/Gain1'
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Gain1_Gain *
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S32>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S32>/yaw_In' incorporates:
      //   DataTypeConversion: '<S1>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In_ik = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S31>/Enabled Subsystem2'

    // Reshape: '<S22>/Reshape' incorporates:
    //   Delay: '<S31>/Delay'
    //   Merge: '<S18>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];

    // Gain: '<S30>/Gain' incorporates:
    //   RelationalOperator: '<S30>/Relational Operator'
    //   Switch: '<S30>/Switch'

    if (!(FLIGHT_HEXA_Hovering_B.Gain_i <= FLIGHT_HEXA_Hovering_B.Switch3)) {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.Switch3;
    }

    // Reshape: '<S22>/Reshape' incorporates:
    //   Gain: '<S30>/Gain'
    //   Merge: '<S18>/Merge'
    //   Switch: '<S30>/Switch'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_P.Gain_Gain *
      FLIGHT_HEXA_Hovering_B.Gain_i;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In_ik;

    // Update for Delay: '<S30>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c = FLIGHT_HEXA_Hovering_B.Switch3;

    // Update for Delay: '<S31>/Delay' incorporates:
    //   Constant: '<S31>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fo;

    // End of Outputs for SubSystem: '<S18>/Take-off'
    break;

   case 1:
    if (FLIGHT_HEXA_Hovering_B.rtAction != FLIGHT_HEXA_Hovering_B.rtPrevAction)
    {
      // InitializeConditions for IfAction SubSystem: '<S18>/Land' incorporates:
      //   ActionPort: '<S21>/Action Port'

      // InitializeConditions for If: '<S18>/If' incorporates:
      //   Delay: '<S21>/Delay'
      //   Delay: '<S26>/Delay'
      //   Delay: '<S27>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_m;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S18>/Land'
    }

    // Outputs for IfAction SubSystem: '<S18>/Land' incorporates:
    //   ActionPort: '<S21>/Action Port'

    // Delay: '<S26>/Delay'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n;

    // Switch: '<S26>/Switch' incorporates:
    //   Delay: '<S26>/Delay'
    //   Gain: '<S26>/Gain'

    if (!(FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n >
          FLIGHT_HEXA_Hovering_P.Switch_Threshold)) {
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Gain_Gain_l *
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
    }

    // End of Switch: '<S26>/Switch'

    // Sum: '<S26>/Subtract' incorporates:
    //   Constant: '<S26>/Rate of descent'

    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.Switch3 -
      FLIGHT_HEXA_Hovering_P.Rateofdescent_Value;

    // Gain: '<S26>/Gain2'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Gain2_Gain *
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S27>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S29>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S29>/yaw_In' incorporates:
      //   DataTypeConversion: '<S1>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In_i = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S27>/Enabled Subsystem2'

    // Switch: '<S21>/Switch' incorporates:
    //   Delay: '<S27>/Delay'
    //   Logic: '<S21>/OR'
    //   RelationalOperator: '<S21>/IsNaN'

    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1])) {
      // Reshape: '<S21>/Reshape' incorporates:
      //   Delay: '<S21>/Delay'
      //   Merge: '<S18>/Merge'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0];
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
        FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1];
    } else {
      // Reshape: '<S21>/Reshape' incorporates:
      //   Delay: '<S21>/Delay'
      //   Merge: '<S18>/Merge'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
    }

    // End of Switch: '<S21>/Switch'

    // Reshape: '<S21>/Reshape' incorporates:
    //   Gain: '<S26>/Gain1'
    //   Merge: '<S18>/Merge'
    //   RelationalOperator: '<S26>/GreaterThan'
    //   Switch: '<S26>/Switch1'

    if (!(FLIGHT_HEXA_Hovering_B.Switch3 > FLIGHT_HEXA_Hovering_B.Gain_i)) {
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.Gain_i;
    }

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_a
      * FLIGHT_HEXA_Hovering_B.Switch3;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S28>/Enable'

    if (FLIGHT_HEXA_Hovering_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S28>/In'
      FLIGHT_HEXA_Hovering_B.In = FLIGHT_HEXA_Hovering_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S26>/Enabled Subsystem'

    // Update for Delay: '<S21>/Delay' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] = FLIGHT_HEXA_Hovering_B.In1_c.x;
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] = FLIGHT_HEXA_Hovering_B.In1_c.y;

    // Update for Delay: '<S26>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_B.In;

    // Update for Delay: '<S27>/Delay' incorporates:
    //   Constant: '<S27>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
      FLIGHT_HEXA_Hovering_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S18>/Land'
    break;

   case 2:
    if (FLIGHT_HEXA_Hovering_B.rtAction != FLIGHT_HEXA_Hovering_B.rtPrevAction)
    {
      // SystemReset for IfAction SubSystem: '<S18>/Waypoint' incorporates:
      //   ActionPort: '<S23>/Action Port'

      // SystemReset for If: '<S18>/If' incorporates:
      //   MATLABSystem: '<S23>/UAV Waypoint Follower'
      //
      FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
      for (FLIGHT_HEXA_Hovering_B.i1 = 0; FLIGHT_HEXA_Hovering_B.i1 < 9;
           FLIGHT_HEXA_Hovering_B.i1++) {
        FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[FLIGHT_HEXA_Hovering_B.i1]
          *= 0.0;
      }

      // End of SystemReset for If: '<S18>/If'
      // End of SystemReset for SubSystem: '<S18>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S18>/Waypoint' incorporates:
    //   ActionPort: '<S23>/Action Port'

    // Concatenate: '<S23>/Matrix Concatenate'
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0] =
      FLIGHT_HEXA_Hovering_B.b_startWaypoint[0];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[1] =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[2] =
      FLIGHT_HEXA_Hovering_B.virtualWaypoint[0];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3] =
      FLIGHT_HEXA_Hovering_B.b_startWaypoint[1];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[4] =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[5] =
      FLIGHT_HEXA_Hovering_B.virtualWaypoint[1];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[6] =
      FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[7] =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[8] =
      FLIGHT_HEXA_Hovering_B.virtualWaypoint[2];

    // MATLABSystem: '<S23>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S23>/Matrix Concatenate'
    //   Constant: '<S23>/Constant'

    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Constant_Value_gw;
    FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistFlag = 0U;
    if (FLIGHT_HEXA_Hovering_P.Constant_Value_gw < 0.3) {
      FLIGHT_HEXA_Hovering_B.Switch3 = 0.3;
      FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistFlag = 1U;
    }

    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[0] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[1] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[2] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[3] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 3.0;
    FLIGHT_HEXA_Hovering_B.OR_g = false;
    FLIGHT_HEXA_Hovering_B.Compare = true;
    FLIGHT_HEXA_Hovering_B.iy = 0;
    exitg1 = false;
    while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.iy <= 8)) {
      FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.iy / 3 * 3 +
        FLIGHT_HEXA_Hovering_B.iy % 3;
      if (!(FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[FLIGHT_HEXA_Hovering_B.i1]
            ==
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[FLIGHT_HEXA_Hovering_B.i1]))
      {
        FLIGHT_HEXA_Hovering_B.Compare = false;
        exitg1 = true;
      } else {
        FLIGHT_HEXA_Hovering_B.iy++;
      }
    }

    if (FLIGHT_HEXA_Hovering_B.Compare) {
      FLIGHT_HEXA_Hovering_B.OR_g = true;
    }

    if (!FLIGHT_HEXA_Hovering_B.OR_g) {
      memcpy(&FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[0],
             &FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    }

    FLIGHT_HEXA_Hovering_B.i1 = 0;
    FLIGHT_HEXA_Hovering_B.iy = 0;
    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 3;
         FLIGHT_HEXA_Hovering_B.j++) {
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.j] = true;
      FLIGHT_HEXA_Hovering_B.Gain_i =
        FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[FLIGHT_HEXA_Hovering_B.i1 + 1];
      FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.iy] =
        (FLIGHT_HEXA_Hovering_B.Gain_i !=
         FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[FLIGHT_HEXA_Hovering_B.i1]);
      FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.iy + 1] =
        (FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[FLIGHT_HEXA_Hovering_B.i1 +
         2] != FLIGHT_HEXA_Hovering_B.Gain_i);
      FLIGHT_HEXA_Hovering_B.i1 += 3;
      FLIGHT_HEXA_Hovering_B.iy += 2;
    }

    FLIGHT_HEXA_Hovering_B.IsNaN_l[0] = false;
    FLIGHT_HEXA_Hovering_B.IsNaN_l[1] = false;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    FLIGHT_HEXA_Hovering_B.iy = 4;
    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 2;
         FLIGHT_HEXA_Hovering_B.j++) {
      FLIGHT_HEXA_Hovering_B.i1++;
      FLIGHT_HEXA_Hovering_B.iy++;
      FLIGHT_HEXA_Hovering_B.ix = FLIGHT_HEXA_Hovering_B.i1;
      exitg1 = false;
      while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.ix <=
                           FLIGHT_HEXA_Hovering_B.iy)) {
        if (FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.ix - 1]) {
          FLIGHT_HEXA_Hovering_B.IsNaN_l[FLIGHT_HEXA_Hovering_B.j] = true;
          exitg1 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.ix += 2;
        }
      }
    }

    FLIGHT_HEXA_Hovering_B.distinctWptsIdx[0] = FLIGHT_HEXA_Hovering_B.IsNaN_l[0];
    FLIGHT_HEXA_Hovering_B.distinctWptsIdx[1] = FLIGHT_HEXA_Hovering_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S18>/Waypoint'
    FLIGHT_HEXA_Hovering_B.iy = 0;
    for (FLIGHT_HEXA_Hovering_B.i1 = 0; FLIGHT_HEXA_Hovering_B.i1 < 3;
         FLIGHT_HEXA_Hovering_B.i1++) {
      // Outputs for IfAction SubSystem: '<S18>/Waypoint' incorporates:
      //   ActionPort: '<S23>/Action Port'

      if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.i1]) {
        FLIGHT_HEXA_Hovering_B.iy++;
      }

      // End of Outputs for SubSystem: '<S18>/Waypoint'
    }

    FLIGHT_HEXA_Hovering_B.j = FLIGHT_HEXA_Hovering_B.iy;
    FLIGHT_HEXA_Hovering_B.iy = 0;
    for (FLIGHT_HEXA_Hovering_B.i1 = 0; FLIGHT_HEXA_Hovering_B.i1 < 3;
         FLIGHT_HEXA_Hovering_B.i1++) {
      // Outputs for IfAction SubSystem: '<S18>/Waypoint' incorporates:
      //   ActionPort: '<S23>/Action Port'

      if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.i1]) {
        // Start for MATLABSystem: '<S23>/UAV Waypoint Follower'
        FLIGHT_HEXA_Hovering_B.tmp_data[FLIGHT_HEXA_Hovering_B.iy] =
          static_cast<int8_T>(FLIGHT_HEXA_Hovering_B.i1);
        FLIGHT_HEXA_Hovering_B.iy++;
      }

      // End of Outputs for SubSystem: '<S18>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S18>/Waypoint' incorporates:
    //   ActionPort: '<S23>/Action Port'

    // MATLABSystem: '<S23>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S23>/Matrix Concatenate'
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Reshape: '<S23>/Reshape1'

    for (FLIGHT_HEXA_Hovering_B.i1 = 0; FLIGHT_HEXA_Hovering_B.i1 < 3;
         FLIGHT_HEXA_Hovering_B.i1++) {
      for (FLIGHT_HEXA_Hovering_B.iy = 0; FLIGHT_HEXA_Hovering_B.iy <
           FLIGHT_HEXA_Hovering_B.j; FLIGHT_HEXA_Hovering_B.iy++) {
        FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[FLIGHT_HEXA_Hovering_B.iy +
          FLIGHT_HEXA_Hovering_B.j * FLIGHT_HEXA_Hovering_B.i1] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 *
          FLIGHT_HEXA_Hovering_B.i1 +
          FLIGHT_HEXA_Hovering_B.tmp_data[FLIGHT_HEXA_Hovering_B.iy]];
      }
    }

    FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance =
      FLIGHT_HEXA_Hovering_B.Switch3;
    if (FLIGHT_HEXA_Hovering_B.j == 0) {
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
        FLIGHT_HEXA_Hovering_B.In1_c.x;
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
        FLIGHT_HEXA_Hovering_B.In1_c.y;
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
        FLIGHT_HEXA_Hovering_B.In1_c.z;
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    } else {
      guard1 = false;
      if (FLIGHT_HEXA_Hovering_B.j == 1) {
        if (FLIGHT_HEXA_Hovering_DW.obj.StartFlag) {
          FLIGHT_HEXA_Hovering_DW.obj.InitialPose[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x;
          FLIGHT_HEXA_Hovering_DW.obj.InitialPose[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y;
          FLIGHT_HEXA_Hovering_DW.obj.InitialPose[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z;
          FLIGHT_HEXA_Hovering_DW.obj.InitialPose[3] =
            FLIGHT_HEXA_Hovering_B.In1_c.heading;
        }

        FLIGHT_HEXA_Hovering_B.b_startWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[0] -
          FLIGHT_HEXA_Hovering_B.In1_c.x;
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[1] -
          FLIGHT_HEXA_Hovering_B.In1_c.y;
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[2] -
          FLIGHT_HEXA_Hovering_B.In1_c.z;
        if (FLIGHT_HEXA_Hovering_norm(FLIGHT_HEXA_Hovering_B.b_startWaypoint) <
            1.4901161193847656E-8) {
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x;
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y;
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z;
          FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.In1_c.heading;
          FLIGHT_HEXA_Hovering_DW.obj.StartFlag = false;
        } else {
          FLIGHT_HEXA_Hovering_DW.obj.StartFlag = false;
          FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 2.0;
          FLIGHT_HEXA_Hovering_B.ix = FLIGHT_HEXA_Hovering_B.j + 1;
          for (FLIGHT_HEXA_Hovering_B.i1 = 0; FLIGHT_HEXA_Hovering_B.i1 < 3;
               FLIGHT_HEXA_Hovering_B.i1++) {
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(FLIGHT_HEXA_Hovering_B.j
              + 1) * FLIGHT_HEXA_Hovering_B.i1] =
              FLIGHT_HEXA_Hovering_DW.obj.InitialPose[FLIGHT_HEXA_Hovering_B.i1];
            for (FLIGHT_HEXA_Hovering_B.iy = 0; FLIGHT_HEXA_Hovering_B.iy <
                 FLIGHT_HEXA_Hovering_B.j; FLIGHT_HEXA_Hovering_B.iy++) {
              FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
                [(FLIGHT_HEXA_Hovering_B.iy + (FLIGHT_HEXA_Hovering_B.j + 1) *
                  FLIGHT_HEXA_Hovering_B.i1) + 1] =
                FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[FLIGHT_HEXA_Hovering_B.j
                * FLIGHT_HEXA_Hovering_B.i1 + FLIGHT_HEXA_Hovering_B.iy];
            }
          }

          guard1 = true;
        }
      } else {
        FLIGHT_HEXA_Hovering_B.ix = FLIGHT_HEXA_Hovering_B.j;
        FLIGHT_HEXA_Hovering_B.iy = FLIGHT_HEXA_Hovering_B.j * 3;
        if (FLIGHT_HEXA_Hovering_B.iy - 1 >= 0) {
          memcpy(&FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0],
                 &FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(FLIGHT_HEXA_Hovering_B.iy) * sizeof
                 (real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        FLIGHT_HEXA_Hovering_B.OR_g = false;
        if (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex ==
            FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints) {
          FLIGHT_HEXA_Hovering_B.OR_g = true;
        }

        if (FLIGHT_HEXA_Hovering_B.OR_g) {
          FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
          FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex--;
        }

        FLIGHT_HEXA_Hovering_B.Switch3 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.Switch3;
        FLIGHT_HEXA_Hovering_B.Gain_i =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
          FLIGHT_HEXA_Hovering_B.Gain_i;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.In1_c.x - FLIGHT_HEXA_Hovering_B.Gain_i;
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
          FLIGHT_HEXA_Hovering_B.ix) - 1];
        FLIGHT_HEXA_Hovering_B.Sum5 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          FLIGHT_HEXA_Hovering_B.ix) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
          FLIGHT_HEXA_Hovering_B.Sum5;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.In1_c.y - FLIGHT_HEXA_Hovering_B.Sum5;
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[((FLIGHT_HEXA_Hovering_B.ix
          << 1) + static_cast<int32_T>(FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex))
          - 1];
        FLIGHT_HEXA_Hovering_B.Sum5 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          (FLIGHT_HEXA_Hovering_B.ix << 1)) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
          FLIGHT_HEXA_Hovering_B.Sum5;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.In1_c.z - FLIGHT_HEXA_Hovering_B.Sum5;
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_norm
          (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        guard2 = false;
        if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <= 2.0) {
          guard2 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.lla0[0] = FLIGHT_HEXA_Hovering_B.Gain_i -
            FLIGHT_HEXA_Hovering_B.Switch3;
          FLIGHT_HEXA_Hovering_B.lla0[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            FLIGHT_HEXA_Hovering_B.ix) - 1] -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
            FLIGHT_HEXA_Hovering_B.ix) - 1];
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (FLIGHT_HEXA_Hovering_B.ix << 1)) - 1];
          FLIGHT_HEXA_Hovering_B.lla0[2] =
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
            [((FLIGHT_HEXA_Hovering_B.ix << 1) + static_cast<int32_T>
              (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex)) - 1];
          FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.lla0);
          FLIGHT_HEXA_Hovering_B.Switch3 = ((FLIGHT_HEXA_Hovering_B.In1_c.x -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1]) /
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            (FLIGHT_HEXA_Hovering_B.lla0[0] / FLIGHT_HEXA_Hovering_B.Switch3) +
            FLIGHT_HEXA_Hovering_B.lla0[1] / FLIGHT_HEXA_Hovering_B.Switch3 *
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] /
             FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0)) +
            (FLIGHT_HEXA_Hovering_B.In1_c.z -
             FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2) /
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            (FLIGHT_HEXA_Hovering_B.lla0[2] / FLIGHT_HEXA_Hovering_B.Switch3);
          if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Switch3) ||
              (FLIGHT_HEXA_Hovering_B.Switch3 < 0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex++;
          FLIGHT_HEXA_Hovering_B.OR_g = false;
          if (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex ==
              FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints) {
            FLIGHT_HEXA_Hovering_B.OR_g = true;
          }

          if (FLIGHT_HEXA_Hovering_B.OR_g) {
            FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
            FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex--;
          }

          FLIGHT_HEXA_Hovering_B.b_startWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
            FLIGHT_HEXA_Hovering_B.ix) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            FLIGHT_HEXA_Hovering_B.ix) - 1];
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
            [((FLIGHT_HEXA_Hovering_B.ix << 1) + static_cast<int32_T>
              (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex)) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (FLIGHT_HEXA_Hovering_B.ix << 1)) - 1];
        }

        FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_B.In1_c.x -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[0];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] = FLIGHT_HEXA_Hovering_B.Sum5;
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[0];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.y
          - FLIGHT_HEXA_Hovering_B.b_startWaypoint[1];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[1];
        FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.In1_c.z -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.Switch3;
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
          (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
           FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 +
           FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 *
           FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2) +
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;
        FLIGHT_HEXA_Hovering_B.Switch3 =
          ((FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 +
            FLIGHT_HEXA_Hovering_B.Sum5 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2) +
           FLIGHT_HEXA_Hovering_B.Switch3 *
           FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2) /
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1;
        if (FLIGHT_HEXA_Hovering_B.Switch3 < 0.0) {
          FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        } else if (FLIGHT_HEXA_Hovering_B.Switch3 > 1.0) {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
          FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        } else {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x - (FLIGHT_HEXA_Hovering_B.Switch3 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 +
            FLIGHT_HEXA_Hovering_B.b_startWaypoint[0]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y - (FLIGHT_HEXA_Hovering_B.Switch3 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 +
            FLIGHT_HEXA_Hovering_B.b_startWaypoint[1]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z - (FLIGHT_HEXA_Hovering_B.Switch3 *
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 +
            FLIGHT_HEXA_Hovering_B.b_startWaypoint[2]);
          FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        }

        if (FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag) {
          FLIGHT_HEXA_Hovering_B.Switch3 = ((FLIGHT_HEXA_Hovering_B.Sum5 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 +
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) +
            (FLIGHT_HEXA_Hovering_B.In1_c.z -
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[2]) *
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2) /
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1;
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x - (FLIGHT_HEXA_Hovering_B.Switch3 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 +
            FLIGHT_HEXA_Hovering_B.b_startWaypoint[0]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y - (FLIGHT_HEXA_Hovering_B.Switch3 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 +
            FLIGHT_HEXA_Hovering_B.b_startWaypoint[1]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z - (FLIGHT_HEXA_Hovering_B.Switch3 *
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 +
            FLIGHT_HEXA_Hovering_B.b_startWaypoint[2]);
          FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        }

        FLIGHT_HEXA_Hovering_B.Sum5 = fabs(FLIGHT_HEXA_Hovering_B.Gain_i);
        if (rtIsInf(FLIGHT_HEXA_Hovering_B.Sum5) || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.Sum5)) {
          FLIGHT_HEXA_Hovering_B.Switch3 = (rtNaN);
          FLIGHT_HEXA_Hovering_B.Sum5 = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.Sum5 < 4.4501477170144028E-308) {
          FLIGHT_HEXA_Hovering_B.Switch3 = 4.94065645841247E-324;
          FLIGHT_HEXA_Hovering_B.Sum5 = 4.94065645841247E-324;
        } else {
          frexp(FLIGHT_HEXA_Hovering_B.Sum5, &FLIGHT_HEXA_Hovering_B.ParamStep_c);
          FLIGHT_HEXA_Hovering_B.Switch3 = ldexp(1.0,
            FLIGHT_HEXA_Hovering_B.ParamStep_c - 53);
          frexp(FLIGHT_HEXA_Hovering_B.Sum5, &FLIGHT_HEXA_Hovering_B.b_exponent);
          FLIGHT_HEXA_Hovering_B.Sum5 = ldexp(1.0,
            FLIGHT_HEXA_Hovering_B.b_exponent - 53);
        }

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = sqrt
          (FLIGHT_HEXA_Hovering_B.Switch3);
        FLIGHT_HEXA_Hovering_B.Switch3 = 5.0 * FLIGHT_HEXA_Hovering_B.Sum5;
        if ((FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >=
             FLIGHT_HEXA_Hovering_B.Switch3) || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.Switch3)) {
          FLIGHT_HEXA_Hovering_B.Switch3 =
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        }

        if (FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance <=
            FLIGHT_HEXA_Hovering_B.Gain_i + FLIGHT_HEXA_Hovering_B.Switch3) {
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance =
            FLIGHT_HEXA_Hovering_DW.obj.LookaheadFactor *
            FLIGHT_HEXA_Hovering_B.Gain_i;
        }

        FLIGHT_HEXA_Hovering_B.lla0[0] = FLIGHT_HEXA_Hovering_B.b_startWaypoint
          [0] - FLIGHT_HEXA_Hovering_B.In1_c.x;
        FLIGHT_HEXA_Hovering_B.lla0[1] = FLIGHT_HEXA_Hovering_B.b_startWaypoint
          [1] - FLIGHT_HEXA_Hovering_B.In1_c.y;
        FLIGHT_HEXA_Hovering_B.lla0[2] = FLIGHT_HEXA_Hovering_B.b_startWaypoint
          [2] - FLIGHT_HEXA_Hovering_B.In1_c.z;
        FLIGHT_HEXA_Hovering_B.Gain_i =
          ((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 *
            FLIGHT_HEXA_Hovering_B.lla0[0] +
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
            FLIGHT_HEXA_Hovering_B.lla0[1]) +
           FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 * FLIGHT_HEXA_Hovering_B.lla0
           [2]) * 2.0;
        FLIGHT_HEXA_Hovering_B.Sum5 = sqrt(FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.Gain_i - (((FLIGHT_HEXA_Hovering_B.lla0[0] *
          FLIGHT_HEXA_Hovering_B.lla0[0] + FLIGHT_HEXA_Hovering_B.lla0[1] *
          FLIGHT_HEXA_Hovering_B.lla0[1]) + FLIGHT_HEXA_Hovering_B.lla0[2] *
          FLIGHT_HEXA_Hovering_B.lla0[2]) -
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance *
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance) * (4.0 *
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1));
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (-FLIGHT_HEXA_Hovering_B.Gain_i
          + FLIGHT_HEXA_Hovering_B.Sum5) / 2.0 /
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1;
        FLIGHT_HEXA_Hovering_B.Switch3 = (-FLIGHT_HEXA_Hovering_B.Gain_i -
          FLIGHT_HEXA_Hovering_B.Sum5) / 2.0 /
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1;
        if ((FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >=
             FLIGHT_HEXA_Hovering_B.Switch3) || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.Switch3)) {
          FLIGHT_HEXA_Hovering_B.Switch3 =
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        }

        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] = (1.0 -
          FLIGHT_HEXA_Hovering_B.Switch3) *
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[0] +
          FLIGHT_HEXA_Hovering_B.Switch3 *
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] = (1.0 -
          FLIGHT_HEXA_Hovering_B.Switch3) *
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[1] +
          FLIGHT_HEXA_Hovering_B.Switch3 *
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] = (1.0 -
          FLIGHT_HEXA_Hovering_B.Switch3) *
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] +
          FLIGHT_HEXA_Hovering_B.Switch3 *
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
        FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_rt_atan2d_snf
          (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] -
           FLIGHT_HEXA_Hovering_B.In1_c.y,
           FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] -
           FLIGHT_HEXA_Hovering_B.In1_c.x);
        FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S33>/Switch1' incorporates:
    //   Constant: '<S34>/Constant'
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Logic: '<S33>/OR'
    //   Logic: '<S33>/OR1'
    //   MATLABSystem: '<S23>/UAV Waypoint Follower'
    //   Merge: '<S18>/Merge'
    //   RelationalOperator: '<S33>/IsNaN'
    //   RelationalOperator: '<S33>/IsNaN1'
    //   RelationalOperator: '<S34>/Compare'
    //   Switch: '<S33>/Switch'
    //
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2]) ||
        (FLIGHT_HEXA_Hovering_B.In1_p.current.type ==
         FLIGHT_HEXA_Hovering_P.CompareToConstant_const_dt)) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 = FLIGHT_HEXA_Hovering_B.In1_c.y;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_B.In1_c.z;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
        FLIGHT_HEXA_Hovering_B.In1_c.heading;
    } else {
      if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Switch3)) {
        // Switch: '<S33>/Switch' incorporates:
        //   Constant: '<S33>/Constant'
        //   Merge: '<S18>/Merge'
        //   Reshape: '<S33>/Reshape2'

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
          FLIGHT_HEXA_Hovering_P.Constant_Value_jd;
      } else {
        // Reshape: '<S33>/Reshape2' incorporates:
        //   MATLABSystem: '<S23>/UAV Waypoint Follower'
        //   Merge: '<S18>/Merge'

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.Switch3;
      }

      // Math: '<S33>/Transpose1' incorporates:
      //   Merge: '<S18>/Merge'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
    }

    // End of Switch: '<S33>/Switch1'
    // End of Outputs for SubSystem: '<S18>/Waypoint'
    break;

   default:
    if (FLIGHT_HEXA_Hovering_B.rtAction != FLIGHT_HEXA_Hovering_B.rtPrevAction)
    {
      // InitializeConditions for IfAction SubSystem: '<S18>/IDLE' incorporates:
      //   ActionPort: '<S20>/Action Port'

      // InitializeConditions for If: '<S18>/If' incorporates:
      //   Delay: '<S24>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S18>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S18>/IDLE' incorporates:
    //   ActionPort: '<S20>/Action Port'

    // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S25>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S25>/yaw_In' incorporates:
      //   DataTypeConversion: '<S1>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S24>/Enabled Subsystem2'

    // Reshape: '<S20>/Reshape1' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Delay: '<S24>/Delay'
    //   Merge: '<S18>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 = FLIGHT_HEXA_Hovering_B.In1_c.y;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_B.In1_c.z;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In;

    // Update for Delay: '<S24>/Delay' incorporates:
    //   Constant: '<S24>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
      FLIGHT_HEXA_Hovering_P.Constant_Value_i;

    // End of Outputs for SubSystem: '<S18>/IDLE'
    break;
  }

  // End of If: '<S18>/If'

  // Outputs for Enabled SubSystem: '<S4>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S76>/Enable'

  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    // Trigonometry: '<S341>/SinCos'
    FLIGHT_HEXA_Hovering_B.Sum5 = sin(FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);
    FLIGHT_HEXA_Hovering_B.Gain_i = cos
      (FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);

    // Math: '<S341>/Transpose' incorporates:
    //   Gain: '<S341>/Gain'
    //   Reshape: '<S341>/Reshape1'

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
      FLIGHT_HEXA_Hovering_P.Gain_Gain_a * FLIGHT_HEXA_Hovering_B.Sum5;
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 = FLIGHT_HEXA_Hovering_B.Sum5;

    // Sum: '<S76>/Sum5'
    FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 -
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[0];

    // Switch: '<S342>/Switch' incorporates:
    //   Abs: '<S342>/Abs'

    if (fabs(FLIGHT_HEXA_Hovering_B.Sum5) >
        FLIGHT_HEXA_Hovering_P.Switch_Threshold_p) {
      // Switch: '<S342>/Switch1' incorporates:
      //   Constant: '<S342>/Constant'
      //   Sum: '<S342>/Add'
      //   Sum: '<S342>/Subtract'

      if (FLIGHT_HEXA_Hovering_B.Sum5 > FLIGHT_HEXA_Hovering_P.Switch1_Threshold)
      {
        FLIGHT_HEXA_Hovering_B.Sum5 -= FLIGHT_HEXA_Hovering_P.Constant_Value_p;
      } else {
        FLIGHT_HEXA_Hovering_B.Sum5 += FLIGHT_HEXA_Hovering_P.Constant_Value_p;
      }

      // End of Switch: '<S342>/Switch1'
    }

    // End of Switch: '<S342>/Switch'

    // Saturate: '<S439>/Saturation' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Gain: '<S437>/Proportional Gain'
    //   Sum: '<S76>/Sum1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 - FLIGHT_HEXA_Hovering_B.In1_c.x) *
      FLIGHT_HEXA_Hovering_P.PIDController1_P_f;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h;
    }

    // Sum: '<S76>/Sum' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Saturate: '<S439>/Saturation'

    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 -
      FLIGHT_HEXA_Hovering_B.In1_c.vx;

    // Saturate: '<S439>/Saturation' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Gain: '<S437>/Proportional Gain'
    //   Sum: '<S76>/Sum1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 - FLIGHT_HEXA_Hovering_B.In1_c.y) *
      FLIGHT_HEXA_Hovering_P.PIDController1_P_f;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h;
    }

    // Sum: '<S76>/Sum' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Saturate: '<S439>/Saturation'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 - FLIGHT_HEXA_Hovering_B.In1_c.vy;

    // Saturate: '<S389>/Saturation' incorporates:
    //   Gain: '<S387>/Proportional Gain'
    //   Math: '<S341>/Transpose'
    //   Product: '<S76>/MatrixMultiply'
    //   Reshape: '<S341>/Reshape'
    //   Reshape: '<S341>/Reshape1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (FLIGHT_HEXA_Hovering_B.Gain_i *
      FLIGHT_HEXA_Hovering_B.Switch3 +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1) *
      FLIGHT_HEXA_Hovering_P.PIDController_P_b;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e) {
      // Saturate: '<S389>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o) {
      // Saturate: '<S389>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o;
    } else {
      // Saturate: '<S389>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
       FLIGHT_HEXA_Hovering_B.Switch3 + FLIGHT_HEXA_Hovering_B.Gain_i *
       FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1) *
      FLIGHT_HEXA_Hovering_P.PIDController_P_b;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e) {
      // Saturate: '<S389>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o) {
      // Saturate: '<S389>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o;
    } else {
      // Saturate: '<S389>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    // End of Saturate: '<S389>/Saturation'

    // Gain: '<S76>/Gain1'
    FLIGHT_HEXA_Hovering_B.Gain1 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_ad *
      FLIGHT_HEXA_Hovering_B.Saturation[0];

    // Gain: '<S487>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.PIDController5_P * FLIGHT_HEXA_Hovering_B.Sum5;

    // Saturate: '<S489>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController5_UpperSaturationLimit) {
      // Saturate: '<S489>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_e =
        FLIGHT_HEXA_Hovering_P.PIDController5_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController5_LowerSaturationLimit) {
      // Saturate: '<S489>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_e =
        FLIGHT_HEXA_Hovering_P.PIDController5_LowerSaturationLimit;
    } else {
      // Saturate: '<S489>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_e =
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    // End of Saturate: '<S489>/Saturation'

    // Gain: '<S340>/Gain1' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'

    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_j *
      FLIGHT_HEXA_Hovering_B.In1_c.z;

    // Switch: '<S348>/Switch' incorporates:
    //   Constant: '<S340>/Constant'
    //   RelationalOperator: '<S348>/UpperRelop'
    //   Switch: '<S348>/Switch2'

    if (FLIGHT_HEXA_Hovering_B.Switch3 <
        FLIGHT_HEXA_Hovering_P.Constant_Value_ag) {
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Constant_Value_ag;
    }

    // Sum: '<S76>/Sum2' incorporates:
    //   Gain: '<S4>/Gain'
    //   Switch: '<S348>/Switch'
    //   Switch: '<S348>/Switch2'

    FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_P.Gain_Gain_k1 *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 - FLIGHT_HEXA_Hovering_B.Switch3;

    // Gain: '<S539>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.PID_Altitude_P *
      FLIGHT_HEXA_Hovering_B.Sum5;

    // Gain: '<S537>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S529>/Filter'
    //   Gain: '<S527>/Derivative Gain'
    //   Sum: '<S529>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2 =
      (FLIGHT_HEXA_Hovering_P.PID_Altitude_D * FLIGHT_HEXA_Hovering_B.Sum5 -
       FLIGHT_HEXA_Hovering_DW.Filter_DSTATE) *
      FLIGHT_HEXA_Hovering_P.PID_Altitude_N;

    // Sum: '<S544>/Sum Fdbk'
    FLIGHT_HEXA_Hovering_B.Switch3 = (FLIGHT_HEXA_Hovering_B.Gain_i +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE) +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2;

    // DeadZone: '<S526>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch3 -=
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 >=
               FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch3 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Switch3 -=
        FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // End of DeadZone: '<S526>/DeadZone'

    // Gain: '<S531>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Sum5 *= FLIGHT_HEXA_Hovering_P.PID_Altitude_I;

    // Switch: '<S524>/Switch1' incorporates:
    //   Constant: '<S524>/Clamping_zero'
    //   Constant: '<S524>/Constant'
    //   Constant: '<S524>/Constant2'
    //   RelationalOperator: '<S524>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_o) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_n1;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_gq;
    }

    // Switch: '<S524>/Switch2' incorporates:
    //   Constant: '<S524>/Clamping_zero'
    //   Constant: '<S524>/Constant3'
    //   Constant: '<S524>/Constant4'
    //   RelationalOperator: '<S524>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Sum5 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_o) {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant3_Value_i;
    } else {
      FLIGHT_HEXA_Hovering_B.rtAction =
        FLIGHT_HEXA_Hovering_P.Constant4_Value_hf;
    }

    // Switch: '<S524>/Switch' incorporates:
    //   Constant: '<S524>/Clamping_zero'
    //   Constant: '<S524>/Constant1'
    //   Logic: '<S524>/AND3'
    //   RelationalOperator: '<S524>/Equal1'
    //   RelationalOperator: '<S524>/Relational Operator'
    //   Switch: '<S524>/Switch1'
    //   Switch: '<S524>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_o !=
         FLIGHT_HEXA_Hovering_B.Switch3) && (FLIGHT_HEXA_Hovering_B.rtPrevAction
         == FLIGHT_HEXA_Hovering_B.rtAction)) {
      FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_P.Constant1_Value_c;
    }

    // DiscreteIntegrator: '<S534>/Integrator' incorporates:
    //   Switch: '<S524>/Switch'

    FLIGHT_HEXA_Hovering_B.Switch3 =
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_p4 * FLIGHT_HEXA_Hovering_B.Sum5
      + FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE;

    // Sum: '<S543>/Sum'
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (FLIGHT_HEXA_Hovering_B.Gain_i +
      FLIGHT_HEXA_Hovering_B.Switch3) +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2;

    // Saturate: '<S541>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // Sum: '<S76>/Sum3' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Saturate: '<S541>/Saturation'
    //   UnaryMinus: '<S76>/Unary Minus'

    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 - (-
      static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_c.vz));

    // Gain: '<S591>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_P.PID_vz_P *
      FLIGHT_HEXA_Hovering_B.Gain_i;

    // Gain: '<S589>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S581>/Filter'
    //   Gain: '<S579>/Derivative Gain'
    //   Sum: '<S581>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = (FLIGHT_HEXA_Hovering_P.PID_vz_D *
      FLIGHT_HEXA_Hovering_B.Gain_i - FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_n) *
      FLIGHT_HEXA_Hovering_P.PID_vz_N;

    // Sum: '<S596>/Sum Fdbk'
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = (FLIGHT_HEXA_Hovering_B.Sum5 +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_c) +
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // DeadZone: '<S578>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 -=
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >=
               FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 -=
        FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S578>/DeadZone'

    // Gain: '<S583>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Gain_i *= FLIGHT_HEXA_Hovering_P.PID_vz_I;

    // Switch: '<S576>/Switch1' incorporates:
    //   Constant: '<S576>/Clamping_zero'
    //   Constant: '<S576>/Constant'
    //   Constant: '<S576>/Constant2'
    //   RelationalOperator: '<S576>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_bl) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_gf;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_ga;
    }

    // Switch: '<S576>/Switch2' incorporates:
    //   Constant: '<S576>/Clamping_zero'
    //   Constant: '<S576>/Constant3'
    //   Constant: '<S576>/Constant4'
    //   RelationalOperator: '<S576>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Gain_i >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_bl) {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant3_Value_b;
    } else {
      FLIGHT_HEXA_Hovering_B.rtAction =
        FLIGHT_HEXA_Hovering_P.Constant4_Value_fv;
    }

    // Switch: '<S576>/Switch' incorporates:
    //   Constant: '<S576>/Clamping_zero'
    //   Constant: '<S576>/Constant1'
    //   Logic: '<S576>/AND3'
    //   RelationalOperator: '<S576>/Equal1'
    //   RelationalOperator: '<S576>/Relational Operator'
    //   Switch: '<S576>/Switch1'
    //   Switch: '<S576>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_bl !=
         FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.rtAction))
    {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Constant1_Value_f;
    }

    // DiscreteIntegrator: '<S586>/Integrator' incorporates:
    //   Switch: '<S576>/Switch'

    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Integrator_gainval_ik
      * FLIGHT_HEXA_Hovering_B.Gain_i +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_c;

    // Sum: '<S595>/Sum'
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (FLIGHT_HEXA_Hovering_B.Sum5 +
      FLIGHT_HEXA_Hovering_B.Gain_i) + FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // Saturate: '<S593>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      // Saturate: '<S593>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_f =
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      // Saturate: '<S593>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_f =
        FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    } else {
      // Saturate: '<S593>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_f =
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    // End of Saturate: '<S593>/Saturation'

    // Update for DiscreteIntegrator: '<S529>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_i *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_2;

    // Update for DiscreteIntegrator: '<S534>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE = FLIGHT_HEXA_Hovering_B.Switch3;

    // Update for DiscreteIntegrator: '<S581>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_n +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_d *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // Update for DiscreteIntegrator: '<S586>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_c = FLIGHT_HEXA_Hovering_B.Gain_i;
  }

  // End of Outputs for SubSystem: '<S4>/Position & Altitude controller'

  // Chart: '<S4>/Chart'
  if (FLIGHT_HEXA_Hovering_DW.is_active_c3_FLIGHT_HEXA_Hovering == 0U) {
    FLIGHT_HEXA_Hovering_DW.is_active_c3_FLIGHT_HEXA_Hovering = 1U;
    FLIGHT_HEXA_Hovering_DW.is_c3_FLIGHT_HEXA_Hovering =
      FLIGHT_HEXA_Hovering_IN_STABLIZED;
  } else if (FLIGHT_HEXA_Hovering_DW.is_c3_FLIGHT_HEXA_Hovering ==
             FLIGHT_HEXA_Hovering_IN_MISSION) {
    if (FLIGHT_HEXA_Hovering_B.In1_j.values[5] <= 1400) {
      FLIGHT_HEXA_Hovering_DW.is_c3_FLIGHT_HEXA_Hovering =
        FLIGHT_HEXA_Hovering_IN_STABLIZED;
    } else {
      FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.Saturation_e;
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = FLIGHT_HEXA_Hovering_B.Gain1;
      FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Saturation[1];
      FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_B.Saturation_f;
    }

    // case IN_STABLIZED:
  } else if (FLIGHT_HEXA_Hovering_B.In1_j.values[5] > 1400) {
    FLIGHT_HEXA_Hovering_DW.is_c3_FLIGHT_HEXA_Hovering =
      FLIGHT_HEXA_Hovering_IN_MISSION;
    FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.Saturation_e;
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = FLIGHT_HEXA_Hovering_B.Gain1;
    FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Saturation[1];
    FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_B.Saturation_f;
  }

  // End of Chart: '<S4>/Chart'

  // Outputs for Enabled SubSystem: '<S4>/Attitude controller' incorporates:
  //   EnablePort: '<S73>/Enable'

  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    // Sum: '<S73>/Sum4' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion2'

    FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_B.Switch2 -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[2];

    // Gain: '<S116>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.PIDController_I *
      FLIGHT_HEXA_Hovering_B.Sum5;

    // Gain: '<S122>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S114>/Filter'
    //   Gain: '<S112>/Derivative Gain'
    //   Sum: '<S114>/SumD'

    FLIGHT_HEXA_Hovering_B.Switch2 = (FLIGHT_HEXA_Hovering_P.PIDController_D *
      FLIGHT_HEXA_Hovering_B.Sum5 - FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_e) *
      FLIGHT_HEXA_Hovering_P.PIDController_N;

    // Sum: '<S128>/Sum' incorporates:
    //   DiscreteIntegrator: '<S119>/Integrator'
    //   Gain: '<S124>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.Switch3 = (FLIGHT_HEXA_Hovering_P.PIDController_P *
      FLIGHT_HEXA_Hovering_B.Sum5 + FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_k)
      + FLIGHT_HEXA_Hovering_B.Switch2;

    // DeadZone: '<S111>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_B.Switch3 -
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 >=
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_B.Switch3 -
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    }

    // End of DeadZone: '<S111>/DeadZone'

    // Switch: '<S109>/Switch1' incorporates:
    //   Constant: '<S109>/Clamping_zero'
    //   Constant: '<S109>/Constant'
    //   Constant: '<S109>/Constant2'
    //   RelationalOperator: '<S109>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_ge;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_i;
    }

    // Switch: '<S109>/Switch2' incorporates:
    //   Constant: '<S109>/Clamping_zero'
    //   Constant: '<S109>/Constant3'
    //   Constant: '<S109>/Constant4'
    //   RelationalOperator: '<S109>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Gain_i >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value) {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant3_Value_h;
    } else {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant4_Value_f;
    }

    // Switch: '<S109>/Switch' incorporates:
    //   Constant: '<S109>/Clamping_zero'
    //   Constant: '<S109>/Constant1'
    //   Logic: '<S109>/AND3'
    //   RelationalOperator: '<S109>/Equal1'
    //   RelationalOperator: '<S109>/Relational Operator'
    //   Switch: '<S109>/Switch1'
    //   Switch: '<S109>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value !=
         FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.rtAction))
    {
      FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_P.Constant1_Value_k;
    } else {
      FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_B.Gain_i;
    }

    // End of Switch: '<S109>/Switch'

    // Saturate: '<S126>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S126>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_l =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      // Saturate: '<S126>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_l =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    } else {
      // Saturate: '<S126>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_l = FLIGHT_HEXA_Hovering_B.Switch3;
    }

    // End of Saturate: '<S126>/Saturation'

    // RateLimiter: '<S73>/Rate Limiter2'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0
      - FLIGHT_HEXA_Hovering_DW.PrevY;
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.RateLimiter2_RisingLim *
        FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Gain_i =
        FLIGHT_HEXA_Hovering_P.RateLimiter2_RisingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 <
               FLIGHT_HEXA_Hovering_P.RateLimiter2_FallingLim *
               FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Gain_i =
        FLIGHT_HEXA_Hovering_P.RateLimiter2_FallingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0;
    }

    FLIGHT_HEXA_Hovering_DW.PrevY = FLIGHT_HEXA_Hovering_B.Gain_i;

    // End of RateLimiter: '<S73>/Rate Limiter2'

    // If: '<S606>/If' incorporates:
    //   Constant: '<S607>/Constant'
    //   Constant: '<S608>/Constant'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 > 1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_c;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 < -1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_md;
    }

    // Saturate: '<S73>/Saturation1'
    if (FLIGHT_HEXA_Hovering_B.Gain_i >
        FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat) {
      FLIGHT_HEXA_Hovering_B.Gain_i =
        FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat;
    } else if (FLIGHT_HEXA_Hovering_B.Gain_i <
               FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat) {
      FLIGHT_HEXA_Hovering_B.Gain_i =
        FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat;
    }

    // If: '<S606>/If' incorporates:
    //   Trigonometry: '<S604>/trigFcn'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 > 1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = 1.0;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 < -1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = -1.0;
    }

    // Sum: '<S73>/Sum' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion2'
    //   Gain: '<S278>/Proportional Gain'
    //   Saturate: '<S73>/Saturation1'
    //   Sum: '<S73>/Sum2'
    //   Trigonometry: '<S604>/trigFcn'

    FLIGHT_HEXA_Hovering_B.Gain_i = (FLIGHT_HEXA_Hovering_B.Gain_i - asin
      (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3)) *
      FLIGHT_HEXA_Hovering_P.PIDController3_P -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[1];

    // Gain: '<S168>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.PIDController1_I *
      FLIGHT_HEXA_Hovering_B.Gain_i;

    // Gain: '<S174>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S166>/Filter'
    //   Gain: '<S164>/Derivative Gain'
    //   Sum: '<S166>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
      (FLIGHT_HEXA_Hovering_P.PIDController1_D * FLIGHT_HEXA_Hovering_B.Gain_i -
       FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ek) *
      FLIGHT_HEXA_Hovering_P.PIDController1_N;

    // Sum: '<S180>/Sum' incorporates:
    //   DiscreteIntegrator: '<S171>/Integrator'
    //   Gain: '<S176>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
      (FLIGHT_HEXA_Hovering_P.PIDController1_P * FLIGHT_HEXA_Hovering_B.Gain_i +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_kd) +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3;

    // DeadZone: '<S163>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 -
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 >=
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 -
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S163>/DeadZone'

    // Switch: '<S161>/Switch1' incorporates:
    //   Constant: '<S161>/Clamping_zero'
    //   Constant: '<S161>/Constant'
    //   Constant: '<S161>/Constant2'
    //   RelationalOperator: '<S161>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_b) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_a1;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_l;
    }

    // Switch: '<S161>/Switch2' incorporates:
    //   Constant: '<S161>/Clamping_zero'
    //   Constant: '<S161>/Constant3'
    //   Constant: '<S161>/Constant4'
    //   RelationalOperator: '<S161>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_b) {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant3_Value_j;
    } else {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant4_Value_a;
    }

    // Switch: '<S161>/Switch' incorporates:
    //   Constant: '<S161>/Clamping_zero'
    //   Constant: '<S161>/Constant1'
    //   Logic: '<S161>/AND3'
    //   RelationalOperator: '<S161>/Equal1'
    //   RelationalOperator: '<S161>/Relational Operator'
    //   Switch: '<S161>/Switch1'
    //   Switch: '<S161>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_b !=
         FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.rtAction))
    {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Constant1_Value_o;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.Switch3;
    }

    // End of Switch: '<S161>/Switch'

    // Saturate: '<S178>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S178>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      // Saturate: '<S178>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S178>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0;
    }

    // End of Saturate: '<S178>/Saturation'

    // RateLimiter: '<S73>/Rate Limiter1'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.Gain2 -
      FLIGHT_HEXA_Hovering_DW.PrevY_f;
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.RateLimiter1_RisingLim *
        FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_P.RateLimiter1_RisingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY_f;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 <
               FLIGHT_HEXA_Hovering_P.RateLimiter1_FallingLim *
               FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_P.RateLimiter1_FallingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY_f;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = FLIGHT_HEXA_Hovering_B.Gain2;
    }

    FLIGHT_HEXA_Hovering_DW.PrevY_f = FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1;

    // End of RateLimiter: '<S73>/Rate Limiter1'

    // Saturate: '<S73>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_m) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_m;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_l) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_l;
    }

    // Sum: '<S73>/Sum1' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion2'
    //   Gain: '<S328>/Proportional Gain'
    //   Saturate: '<S73>/Saturation'
    //   Sum: '<S73>/Sum3'

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
      (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 -
       FLIGHT_HEXA_Hovering_B.VectorConcatenate[2]) *
      FLIGHT_HEXA_Hovering_P.PIDController4_P -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[0];

    // Gain: '<S220>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.PIDController2_I *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1;

    // Gain: '<S226>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S218>/Filter'
    //   Gain: '<S216>/Derivative Gain'
    //   Sum: '<S218>/SumD'

    FLIGHT_HEXA_Hovering_B.Gain2 = (FLIGHT_HEXA_Hovering_P.PIDController2_D *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 -
      FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_j) *
      FLIGHT_HEXA_Hovering_P.PIDController2_N;

    // Sum: '<S232>/Sum' incorporates:
    //   DiscreteIntegrator: '<S223>/Integrator'
    //   Gain: '<S228>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
      (FLIGHT_HEXA_Hovering_P.PIDController2_P *
       FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i) +
      FLIGHT_HEXA_Hovering_B.Gain2;

    // DeadZone: '<S215>/DeadZone' incorporates:
    //   Saturate: '<S230>/Saturation'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 -
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;

      // Saturate: '<S230>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_m =
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;
    } else {
      if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 >=
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = 0.0;
      } else {
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 -
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }

      if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 <
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        // Saturate: '<S230>/Saturation'
        FLIGHT_HEXA_Hovering_B.Saturation_m =
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      } else {
        // Saturate: '<S230>/Saturation'
        FLIGHT_HEXA_Hovering_B.Saturation_m =
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0;
      }
    }

    // End of DeadZone: '<S215>/DeadZone'

    // Update for DiscreteIntegrator: '<S119>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_k +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval * FLIGHT_HEXA_Hovering_B.Sum5;

    // Update for DiscreteIntegrator: '<S114>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_e +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval * FLIGHT_HEXA_Hovering_B.Switch2;

    // Update for DiscreteIntegrator: '<S171>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_kd +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_i *
      FLIGHT_HEXA_Hovering_B.Gain_i;

    // Update for DiscreteIntegrator: '<S166>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ek +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_p *
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3;

    // Switch: '<S213>/Switch1' incorporates:
    //   Constant: '<S213>/Clamping_zero'
    //   Constant: '<S213>/Constant'
    //   Constant: '<S213>/Constant2'
    //   RelationalOperator: '<S213>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_jj;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_o;
    }

    // Switch: '<S213>/Switch2' incorporates:
    //   Constant: '<S213>/Clamping_zero'
    //   Constant: '<S213>/Constant3'
    //   Constant: '<S213>/Constant4'
    //   RelationalOperator: '<S213>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f) {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant3_Value_l;
    } else {
      FLIGHT_HEXA_Hovering_B.rtAction = FLIGHT_HEXA_Hovering_P.Constant4_Value_n;
    }

    // Switch: '<S213>/Switch' incorporates:
    //   Constant: '<S213>/Clamping_zero'
    //   Constant: '<S213>/Constant1'
    //   Logic: '<S213>/AND3'
    //   RelationalOperator: '<S213>/Equal1'
    //   RelationalOperator: '<S213>/Relational Operator'
    //   Switch: '<S213>/Switch1'
    //   Switch: '<S213>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f !=
         FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.rtAction))
    {
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Constant1_Value_p;
    }

    // Update for DiscreteIntegrator: '<S223>/Integrator' incorporates:
    //   Switch: '<S213>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_p *
      FLIGHT_HEXA_Hovering_B.Switch3;

    // Update for DiscreteIntegrator: '<S218>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_j +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_k * FLIGHT_HEXA_Hovering_B.Gain2;
  }

  // End of Outputs for SubSystem: '<S4>/Attitude controller'

  // Gain: '<S3>/Gain'
  FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_P.Gain_Gain_kw *
    FLIGHT_HEXA_Hovering_B.Saturation_m;

  // Gain: '<S3>/Gain1'
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_b * FLIGHT_HEXA_Hovering_B.Saturation_o;

  // Gain: '<S3>/Gain2'
  FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
    FLIGHT_HEXA_Hovering_P.Gain2_Gain_du * FLIGHT_HEXA_Hovering_B.Saturation_l;

  // Gain: '<S3>/Gain3'
  FLIGHT_HEXA_Hovering_B.Sum *= FLIGHT_HEXA_Hovering_P.Gain3_Gain_o;

  // MATLABSystem: '<S55>/Read Parameter13'
  if (FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // RelationalOperator: '<S61>/Compare' incorporates:
  //   Constant: '<S61>/Constant'

  FLIGHT_HEXA_Hovering_B.Compare = (FLIGHT_HEXA_Hovering_B.In1_h.values[7] >=
    FLIGHT_HEXA_Hovering_P.CompareToConstant_const_d);

  // Switch: '<S54>/Switch' incorporates:
  //   Constant: '<S54>/Constant'
  //   MATLAB Function: '<S3>/MATLAB Function'
  //   Product: '<S62>/Product'
  //   Saturate: '<S62>/Saturation'
  //   Switch: '<S55>/Switch'

  if (FLIGHT_HEXA_Hovering_B.Compare_k) {
    FLIGHT_HEXA_Hovering_B.Sum5 = FLIGHT_HEXA_Hovering_P.Constant_Value_bd;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S55>/Switch' incorporates:
      //   DataTypeConversion: '<S55>/Data Type Conversion3'
      //   MATLABSystem: '<S55>/Read Parameter13'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_c;
    } else {
      // Switch: '<S55>/Switch' incorporates:
      //   Constant: '<S55>/Constant'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_a;
    }

    // Gain: '<S62>/Gain' incorporates:
    //   Switch: '<S55>/Switch'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *=
      FLIGHT_HEXA_Hovering_P.Gain_Gain_mg;

    // Saturate: '<S62>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_j) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_j;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_av) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_av;
    }

    FLIGHT_HEXA_Hovering_B.Sum5 = ((-FLIGHT_HEXA_Hovering_B.Gain2 -
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * FLIGHT_HEXA_Hovering_B.Sum /
      3.0 + FLIGHT_HEXA_Hovering_B.Sum) * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S54>/Switch'

  // MATLABSystem: '<S55>/Read Parameter1'
  if (FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_a.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // Switch: '<S54>/Switch1' incorporates:
  //   Constant: '<S54>/Constant1'
  //   MATLAB Function: '<S3>/MATLAB Function'
  //   Product: '<S63>/Product'
  //   Saturate: '<S63>/Saturation'
  //   Switch: '<S55>/Switch1'

  if (FLIGHT_HEXA_Hovering_B.Compare_k) {
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Constant1_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S55>/Switch1' incorporates:
      //   DataTypeConversion: '<S55>/Data Type Conversion2'
      //   MATLABSystem: '<S55>/Read Parameter1'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_c;
    } else {
      // Switch: '<S55>/Switch1' incorporates:
      //   Constant: '<S55>/Constant1'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_g;
    }

    // Gain: '<S63>/Gain' incorporates:
    //   Switch: '<S55>/Switch1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_m;

    // Saturate: '<S63>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat;
    }

    FLIGHT_HEXA_Hovering_B.Gain_i = ((FLIGHT_HEXA_Hovering_B.Gain2 +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * FLIGHT_HEXA_Hovering_B.Sum /
      3.0 + FLIGHT_HEXA_Hovering_B.Sum) * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S54>/Switch1'

  // MATLABSystem: '<S55>/Read Parameter2'
  if (FLIGHT_HEXA_Hovering_DW.obj_m.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_m.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_m.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // Switch: '<S54>/Switch2' incorporates:
  //   Constant: '<S54>/Constant2'
  //   MATLAB Function: '<S3>/MATLAB Function'
  //   Product: '<S64>/Product'
  //   Saturate: '<S64>/Saturation'
  //   Switch: '<S55>/Switch2'

  if (FLIGHT_HEXA_Hovering_B.Compare_k) {
    FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_P.Constant2_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S55>/Switch2' incorporates:
      //   DataTypeConversion: '<S55>/Data Type Conversion'
      //   MATLABSystem: '<S55>/Read Parameter2'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_c;
    } else {
      // Switch: '<S55>/Switch2' incorporates:
      //   Constant: '<S55>/Constant2'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_p;
    }

    // Gain: '<S64>/Gain' incorporates:
    //   Switch: '<S55>/Switch2'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_k;

    // Saturate: '<S64>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_c) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_c;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_p) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_p;
    }

    FLIGHT_HEXA_Hovering_B.Switch2 = (((FLIGHT_HEXA_Hovering_B.Gain2 / 2.0 +
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3) -
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * FLIGHT_HEXA_Hovering_B.Sum /
      3.0 + FLIGHT_HEXA_Hovering_B.Sum) * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S54>/Switch2'

  // MATLABSystem: '<S55>/Read Parameter3'
  if (FLIGHT_HEXA_Hovering_DW.obj_i.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_i.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_i.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // Switch: '<S54>/Switch3' incorporates:
  //   Constant: '<S54>/Constant3'
  //   MATLAB Function: '<S3>/MATLAB Function'
  //   Product: '<S65>/Product'
  //   Saturate: '<S65>/Saturation'
  //   Switch: '<S55>/Switch3'

  if (FLIGHT_HEXA_Hovering_B.Compare_k) {
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Constant3_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S55>/Switch3' incorporates:
      //   DataTypeConversion: '<S55>/Data Type Conversion4'
      //   MATLABSystem: '<S55>/Read Parameter3'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_c;
    } else {
      // Switch: '<S55>/Switch3' incorporates:
      //   Constant: '<S55>/Constant3'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant3_Value_o;
    }

    // Gain: '<S65>/Gain' incorporates:
    //   Switch: '<S55>/Switch3'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *=
      FLIGHT_HEXA_Hovering_P.Gain_Gain_lf;

    // Saturate: '<S65>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_f) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_f;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_c) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_c;
    }

    FLIGHT_HEXA_Hovering_B.Switch3 =
      (((-FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 -
         FLIGHT_HEXA_Hovering_B.Gain2 / 2.0) +
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * FLIGHT_HEXA_Hovering_B.Sum
       / 3.0 + FLIGHT_HEXA_Hovering_B.Sum) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S54>/Switch3'

  // MATLABSystem: '<S55>/Read Parameter4'
  if (FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // Switch: '<S54>/Switch4' incorporates:
  //   Constant: '<S54>/Constant4'
  //   MATLAB Function: '<S3>/MATLAB Function'
  //   Product: '<S66>/Product'
  //   Saturate: '<S66>/Saturation'
  //   Switch: '<S55>/Switch4'

  if (FLIGHT_HEXA_Hovering_B.Compare_k) {
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
      FLIGHT_HEXA_Hovering_P.Constant4_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S55>/Switch4' incorporates:
      //   DataTypeConversion: '<S55>/Data Type Conversion1'
      //   MATLABSystem: '<S55>/Read Parameter4'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_c;
    } else {
      // Switch: '<S55>/Switch4' incorporates:
      //   Constant: '<S55>/Constant4'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant4_Value_h;
    }

    // Gain: '<S66>/Gain' incorporates:
    //   Switch: '<S55>/Switch4'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *=
      FLIGHT_HEXA_Hovering_P.Gain_Gain_mp;

    // Saturate: '<S66>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_o) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_o;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_a) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_a;
    }

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 =
      (((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 -
         FLIGHT_HEXA_Hovering_B.Gain2 / 2.0) +
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * FLIGHT_HEXA_Hovering_B.Sum
       / 3.0 + FLIGHT_HEXA_Hovering_B.Sum) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S54>/Switch4'

  // MATLABSystem: '<S55>/Read Parameter5'
  if (FLIGHT_HEXA_Hovering_DW.obj_c.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_c.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_c.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.OR_g) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // Switch: '<S54>/Switch5' incorporates:
  //   Constant: '<S54>/Constant5'
  //   MATLAB Function: '<S3>/MATLAB Function'
  //   Product: '<S67>/Product'
  //   Saturate: '<S67>/Saturation'
  //   Switch: '<S55>/Switch5'

  if (FLIGHT_HEXA_Hovering_B.Compare_k) {
    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
      FLIGHT_HEXA_Hovering_P.Constant5_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S55>/Switch5' incorporates:
      //   DataTypeConversion: '<S55>/Data Type Conversion5'
      //   MATLABSystem: '<S55>/Read Parameter5'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_c;
    } else {
      // Switch: '<S55>/Switch5' incorporates:
      //   Constant: '<S55>/Constant5'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant5_Value_e;
    }

    // Gain: '<S67>/Gain' incorporates:
    //   Switch: '<S55>/Switch5'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_g;

    // Saturate: '<S67>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_fq) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_fq;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_e) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_e;
    }

    FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = (((FLIGHT_HEXA_Hovering_B.Gain2
      / 2.0 - FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3) -
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * FLIGHT_HEXA_Hovering_B.Sum /
      3.0 + FLIGHT_HEXA_Hovering_B.Sum) * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S54>/Switch5'

  // BusAssignment: '<S59>/Bus Assignment' incorporates:
  //   Constant: '<S71>/Constant'

  FLIGHT_HEXA_Hovering_B.BusAssignment = FLIGHT_HEXA_Hovering_P.Constant_Value_f;

  // BusAssignment: '<S59>/Bus Assignment' incorporates:
  //   Constant: '<S59>/Constant'
  //   DataTypeConversion: '<S59>/Data Type Conversion'

  FLIGHT_HEXA_Hovering_B.BusAssignment.control[0] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Sum5);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[1] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Gain_i);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[2] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Switch2);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[3] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Switch3);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[4] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[5] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[6] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_olz);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[7] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_olz);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[8] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_olz);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[9] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_olz);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[10] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_olz);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[11] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_olz);

  // MATLABSystem: '<S72>/SinkBlock' incorporates:
  //   BusAssignment: '<S59>/Bus Assignment'

  uORB_write_step(FLIGHT_HEXA_Hovering_DW.obj_m4.orbMetadataObj,
                  &FLIGHT_HEXA_Hovering_DW.obj_m4.orbAdvertiseObj,
                  &FLIGHT_HEXA_Hovering_B.BusAssignment);

  // Outputs for Enabled SubSystem: '<S19>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S36>/Enable'

  // Start for MATLABSystem: '<S19>/Read Parameter'
  if (FLIGHT_HEXA_Hovering_B.ParamStep_k > 0) {
    // BusAssignment: '<S36>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment'
    //   Constant: '<S46>/Constant'
    //   SignalConversion generated from: '<S42>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S42>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S42>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S42>/Data Type Conversion'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.alt;

    // SignalConversion generated from: '<S36>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
      FLIGHT_HEXA_Hovering_B.In1_f.lat;

    // SignalConversion generated from: '<S36>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] =
      FLIGHT_HEXA_Hovering_B.In1_f.lon;

    // DataTypeConversion: '<S36>/Data Type Conversion'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
      FLIGHT_HEXA_Hovering_B.In1_f.alt;
    FLIGHT_HEXA_Hovering_MATLABSystem(FLIGHT_HEXA_Hovering_B.DataTypeConversion2,
      FLIGHT_HEXA_Hovering_B.VectorConcatenate,
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid,
      FLIGHT_HEXA_Hovering_B.In1_p.current.type,
      &FLIGHT_HEXA_Hovering_B.MATLABSystem);

    // SignalConversion generated from: '<S48>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S42>/Bus Assignment1'
    //   MATLABSystem: '<S42>/MATLAB System'
    //   SignalConversion generated from: '<S42>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[0] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S48>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S42>/Bus Assignment1'
    //   MATLABSystem: '<S42>/MATLAB System'
    //   SignalConversion generated from: '<S42>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[1] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[1];

    // If: '<S48>/If' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S42>/Bus Assignment1'
    //   Constant: '<S50>/Constant'
    //   Constant: '<S50>/Constant1'
    //   Constant: '<S51>/Constant'
    //   Constant: '<S51>/Constant1'

    if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S48>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S51>/Action Port'

      // MATLABSystem: '<S51>/Read Parameter' incorporates:
      //   BusAssignment: '<S36>/Bus Assignment1'
      //   BusAssignment: '<S42>/Bus Assignment1'
      //   SignalConversion generated from: '<S51>/Read Parameter'

      if (FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime !=
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c) {
        FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime =
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c;
      }

      FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
        (FLIGHT_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2]);
      if (FLIGHT_HEXA_Hovering_B.OR_g) {
        FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S51>/Read Parameter'
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_d[0];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_d[1];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S48>/If Action Subsystem2'
    } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S48>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S50>/Action Port'

      // MATLABSystem: '<S50>/Read Parameter'
      if (FLIGHT_HEXA_Hovering_DW.obj_b4.SampleTime !=
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g) {
        FLIGHT_HEXA_Hovering_DW.obj_b4.SampleTime =
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g;
      }

      FLIGHT_HEXA_Hovering_B.OR_g = MW_Param_Step
        (FLIGHT_HEXA_Hovering_DW.obj_b4.MW_PARAMHANDLE, MW_SINGLE,
         &FLIGHT_HEXA_Hovering_B.ParamStep);
      if (FLIGHT_HEXA_Hovering_B.OR_g) {
        FLIGHT_HEXA_Hovering_B.ParamStep = 0.0F;
      }

      // Gain: '<S50>/Gain' incorporates:
      //   BusAssignment: '<S36>/Bus Assignment1'
      //   BusAssignment: '<S42>/Bus Assignment1'
      //   MATLABSystem: '<S50>/Read Parameter'
      //
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        FLIGHT_HEXA_Hovering_P.Gain_Gain_h * FLIGHT_HEXA_Hovering_B.ParamStep;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[0];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[1];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S48>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S48>/If Action Subsystem' incorporates:
      //   ActionPort: '<S49>/Action Port'

      // SignalConversion generated from: '<S49>/In1' incorporates:
      //   BusAssignment: '<S36>/Bus Assignment1'
      //   BusAssignment: '<S42>/Bus Assignment1'
      //   MATLABSystem: '<S42>/MATLAB System'
      //   SignalConversion generated from: '<S42>/MATLAB System'

      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S42>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S36>/Bus Assignment1'
      //   SignalConversion generated from: '<S48>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S49>/In2'
      //
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vx;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vy;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S48>/If Action Subsystem'
    }

    // End of If: '<S48>/If'

    // BusAssignment: '<S42>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   Constant: '<S42>/Constant5'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].timestamp =
      FLIGHT_HEXA_Hovering_B.In1_p.current.timestamp;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].type =
      FLIGHT_HEXA_Hovering_B.In1_p.current.type;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].yaw =
      FLIGHT_HEXA_Hovering_B.In1_p.current.yaw;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].yaw_speed =
      FLIGHT_HEXA_Hovering_B.In1_p.current.yawspeed;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].point_valid =
      FLIGHT_HEXA_Hovering_P.Constant5_Value_j;

    // BusAssignment: '<S36>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment'
    //   Constant: '<S46>/Constant'
    //   SignalConversion generated from: '<S43>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S43>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S42>/Matrix Concatenate1'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S43>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S42>/Matrix Concatenate1'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S43>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S42>/Data Type Conversion'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.alt;
    FLIGHT_HEXA_Hovering_MATLABSystem(FLIGHT_HEXA_Hovering_B.DataTypeConversion2,
      FLIGHT_HEXA_Hovering_B.VectorConcatenate,
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid,
      FLIGHT_HEXA_Hovering_B.In1_p.current.type,
      &FLIGHT_HEXA_Hovering_B.MATLABSystem_b);

    // SignalConversion generated from: '<S43>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S43>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vx;

    // SignalConversion generated from: '<S43>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S43>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vy;

    // SignalConversion generated from: '<S43>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S43>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vz;

    // BusAssignment: '<S43>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S42>/Bus Assignment1'
    //   Constant: '<S43>/Constant5'
    //   MATLABSystem: '<S43>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].timestamp =
      FLIGHT_HEXA_Hovering_B.In1_p.current.timestamp;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].position[0] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem_b.MATLABSystem[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].position[1] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem_b.MATLABSystem[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].position[2] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem_b.MATLABSystem[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].yaw =
      FLIGHT_HEXA_Hovering_B.In1_p.current.yaw;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].yaw_speed =
      FLIGHT_HEXA_Hovering_B.In1_p.current.yawspeed;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].point_valid =
      FLIGHT_HEXA_Hovering_P.Constant5_Value_k;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].type =
      FLIGHT_HEXA_Hovering_B.In1_p.current.type;

    // BusAssignment: '<S36>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment'
    //   Constant: '<S46>/Constant'
    //   SignalConversion generated from: '<S45>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S45>/MATLAB System' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   DataTypeConversion: '<S36>/Data Type Conversion'
    //   DataTypeConversion: '<S45>/Data Type Conversion'
    //   SignalConversion generated from: '<S36>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S45>/Matrix Concatenate'
    //
    if (FLIGHT_HEXA_Hovering_B.In1_p.next.valid) {
      FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_B.In1_p.next.lat -
        FLIGHT_HEXA_Hovering_B.In1_f.lat;
      FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.In1_p.next.lon -
        FLIGHT_HEXA_Hovering_B.In1_f.lon;
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = fabs
        (FLIGHT_HEXA_Hovering_B.Sum);
      if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 > 180.0) {
        if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Sum + 180.0) || rtIsInf
            (FLIGHT_HEXA_Hovering_B.Sum + 180.0)) {
          FLIGHT_HEXA_Hovering_B.Switch3 = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.Sum + 180.0 == 0.0) {
          FLIGHT_HEXA_Hovering_B.Switch3 = 0.0;
        } else {
          FLIGHT_HEXA_Hovering_B.Switch3 = fmod(FLIGHT_HEXA_Hovering_B.Sum +
            180.0, 360.0);
          if (FLIGHT_HEXA_Hovering_B.Switch3 == 0.0) {
            FLIGHT_HEXA_Hovering_B.Switch3 = 0.0;
          } else if (FLIGHT_HEXA_Hovering_B.Sum + 180.0 < 0.0) {
            FLIGHT_HEXA_Hovering_B.Switch3 += 360.0;
          }
        }

        FLIGHT_HEXA_Hovering_B.Sum = FLIGHT_HEXA_Hovering_B.Sum * 0.0 +
          (FLIGHT_HEXA_Hovering_B.Switch3 - 180.0);
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = fabs
          (FLIGHT_HEXA_Hovering_B.Sum);
      }

      if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 > 90.0) {
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = fabs
          (FLIGHT_HEXA_Hovering_B.Sum);
        FLIGHT_HEXA_Hovering_B.OR_g =
          (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 > 90.0);
        FLIGHT_HEXA_Hovering_B.Gain2 += 180.0;
        FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.Sum *
          static_cast<real_T>(FLIGHT_HEXA_Hovering_B.OR_g);
        if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Switch2)) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.Switch2 < 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = -1.0;
        } else {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
            (FLIGHT_HEXA_Hovering_B.Switch2 > 0.0);
        }

        FLIGHT_HEXA_Hovering_B.Sum = (90.0 -
          (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 * static_cast<real_T>
           (FLIGHT_HEXA_Hovering_B.OR_g) - 90.0)) *
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 * static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.OR_g) + FLIGHT_HEXA_Hovering_B.Sum *
          static_cast<real_T>(!FLIGHT_HEXA_Hovering_B.OR_g);
      }

      if ((FLIGHT_HEXA_Hovering_B.Gain2 > 180.0) ||
          (FLIGHT_HEXA_Hovering_B.Gain2 < -180.0)) {
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 =
          FLIGHT_HEXA_Hovering_rt_remd_snf(FLIGHT_HEXA_Hovering_B.Gain2, 360.0);
        FLIGHT_HEXA_Hovering_B.Switch2 =
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 / 180.0;
        if (FLIGHT_HEXA_Hovering_B.Switch2 < 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = ceil
            (FLIGHT_HEXA_Hovering_B.Switch2);
        } else {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = floor
            (FLIGHT_HEXA_Hovering_B.Switch2);
        }

        FLIGHT_HEXA_Hovering_B.Gain2 =
          (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 - 360.0 *
           FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0) +
          FLIGHT_HEXA_Hovering_B.Gain2 * 0.0;
      }

      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 = FLIGHT_HEXA_Hovering_sind_d
        (FLIGHT_HEXA_Hovering_B.In1_f.lat);
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 * FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1);
      if (rtIsInf(FLIGHT_HEXA_Hovering_B.In1_f.lat) || rtIsNaN
          (FLIGHT_HEXA_Hovering_B.In1_f.lat)) {
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = (rtNaN);
      } else {
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
          FLIGHT_HEXA_Hovering_rt_remd_snf(FLIGHT_HEXA_Hovering_B.In1_f.lat,
          360.0);
        FLIGHT_HEXA_Hovering_B.Switch2 = fabs
          (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
        if (FLIGHT_HEXA_Hovering_B.Switch2 > 180.0) {
          if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 > 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 -= 360.0;
          } else {
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 += 360.0;
          }

          FLIGHT_HEXA_Hovering_B.Switch2 = fabs
            (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
        }

        if (FLIGHT_HEXA_Hovering_B.Switch2 <= 45.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = cos(0.017453292519943295 *
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
        } else if (FLIGHT_HEXA_Hovering_B.Switch2 <= 135.0) {
          if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 > 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = -sin
              ((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 - 90.0) *
               0.017453292519943295);
          } else {
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = sin
              ((FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 + 90.0) *
               0.017453292519943295);
          }
        } else {
          if (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 > 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
              (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 - 180.0) *
              0.017453292519943295;
          } else {
            FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 =
              (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 + 180.0) *
              0.017453292519943295;
          }

          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = -cos
            (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
        }
      }

      FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.Sum /
        (FLIGHT_HEXA_Hovering_rt_atan2d_snf(1.0, 0.99330562000985867 / (1.0 -
           0.0066943799901413165 * FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1 *
           FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_1) *
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3) * 57.295779513082323);
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0 = FLIGHT_HEXA_Hovering_B.Gain2 /
        (FLIGHT_HEXA_Hovering_rt_atan2d_snf(1.0,
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 *
          FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0) * 57.295779513082323);
      FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3 = -static_cast<real_T>
        (FLIGHT_HEXA_Hovering_B.In1_p.next.alt) +
        FLIGHT_HEXA_Hovering_B.In1_f.alt;
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[0] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.Switch2);
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[1] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[2] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3);
      FLIGHT_HEXA_Hovering_B.Compare_k = false;
      FLIGHT_HEXA_Hovering_B.iy = 0;
      exitg1 = false;
      while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.iy < 3)) {
        if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.iy]) {
          FLIGHT_HEXA_Hovering_B.Compare_k = true;
          exitg1 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.iy++;
        }
      }

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0 / static_cast<real_T>
        (!FLIGHT_HEXA_Hovering_B.Compare_k);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
        FLIGHT_HEXA_Hovering_B.Switch2);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_0);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
        FLIGHT_HEXA_Hovering_B.rtb_Switch_aw_idx_3);
    } else {
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S45>/MATLAB System'

    // SignalConversion generated from: '<S45>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S45>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vx;

    // SignalConversion generated from: '<S45>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S45>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vy;

    // SignalConversion generated from: '<S45>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   BusAssignment: '<S45>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vz;

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'
    //   Constant: '<S45>/Constant5'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].timestamp =
      FLIGHT_HEXA_Hovering_B.In1_p.next.timestamp;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].yaw =
      FLIGHT_HEXA_Hovering_B.In1_p.next.yaw;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].yaw_speed =
      FLIGHT_HEXA_Hovering_B.In1_p.next.yawspeed;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].point_valid =
      FLIGHT_HEXA_Hovering_P.Constant5_Value_h;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].type =
      FLIGHT_HEXA_Hovering_B.In1_p.next.type;

    // SignalConversion generated from: '<S44>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment'
    //   BusAssignment: '<S44>/Bus Assignment1'
    //   Constant: '<S46>/Constant'

    FLIGHT_HEXA_Hovering_B.BusAssignment1_f =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S44>/Bus Assignment1' incorporates:
    //   Constant: '<S44>/Constant'
    //   Constant: '<S44>/Constant1'
    //   Constant: '<S44>/Constant2'
    //   Constant: '<S44>/Constant3'
    //   Constant: '<S44>/Constant4'
    //   Constant: '<S44>/Constant5'
    //   Constant: '<S44>/Constant6'
    //   Constant: '<S44>/Constant7'

    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.timestamp =
      FLIGHT_HEXA_Hovering_P.Constant7_Value;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.yaw =
      FLIGHT_HEXA_Hovering_P.Constant3_Value_a;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.yaw_speed =
      FLIGHT_HEXA_Hovering_P.Constant4_Value_g;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.position[0] =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fh[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.velocity[0] =
      FLIGHT_HEXA_Hovering_P.Constant1_Value_hv[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.acceleration[0] =
      FLIGHT_HEXA_Hovering_P.Constant2_Value_f[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.position[1] =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fh[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.velocity[1] =
      FLIGHT_HEXA_Hovering_P.Constant1_Value_hv[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.acceleration[1] =
      FLIGHT_HEXA_Hovering_P.Constant2_Value_f[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.position[2] =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fh[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.velocity[2] =
      FLIGHT_HEXA_Hovering_P.Constant1_Value_hv[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.acceleration[2] =
      FLIGHT_HEXA_Hovering_P.Constant2_Value_f[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.point_valid =
      FLIGHT_HEXA_Hovering_P.Constant5_Value_l;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.type =
      FLIGHT_HEXA_Hovering_P.Constant6_Value;

    // BusAssignment: '<S36>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment'
    //   Constant: '<S36>/Constant'
    //   Constant: '<S46>/Constant'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.timestamp =
      FLIGHT_HEXA_Hovering_B.In1_p.timestamp;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.type =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fm;
    for (FLIGHT_HEXA_Hovering_B.i1 = 0; FLIGHT_HEXA_Hovering_B.i1 < 7;
         FLIGHT_HEXA_Hovering_B.i1++) {
      FLIGHT_HEXA_Hovering_B.BusAssignment1._padding0[FLIGHT_HEXA_Hovering_B.i1]
        =
        FLIGHT_HEXA_Hovering_P.Constant_Value._padding0[FLIGHT_HEXA_Hovering_B.i1];
    }

    // BusAssignment: '<S36>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S44>/Bus Assignment1'
    //   Concatenate: '<S36>/Matrix Concatenate'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[3] =
      FLIGHT_HEXA_Hovering_B.BusAssignment1_f;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[4] =
      FLIGHT_HEXA_Hovering_B.BusAssignment1_f;

    // MATLABSystem: '<S47>/SinkBlock' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'

    uORB_write_step(FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                    &FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                    &FLIGHT_HEXA_Hovering_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S19>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_SourceBlock(&FLIGHT_HEXA_Hovering_B.SourceBlock_h,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_h);

  // MATLABSystem: '<S35>/PX4 Timestamp'
  hrt_absolute_time();
}

// Model initialize function
void FLIGHT_HEXA_Hovering_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  FLIGHT_HEXA_Hovering_P.Constant1_Value_d[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_d[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_f2 = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_l4 = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_fh[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_fh[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_fh[2] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_hv[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_hv[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_hv[2] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant2_Value_f[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant2_Value_f[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant2_Value_f[2] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant3_Value_a = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant4_Value_g = rtNaNF;

  {
    static const char_T ParameterNameStr[14] = "COM_OBS_AVOID";
    static const char_T ParameterNameStr_0[14] = "FDD_M1_STATUS";
    static const char_T ParameterNameStr_1[14] = "FDD_M2_STATUS";
    static const char_T ParameterNameStr_2[14] = "FDD_M3_STATUS";
    static const char_T ParameterNameStr_3[14] = "FDD_M4_STATUS";
    static const char_T ParameterNameStr_4[14] = "FDD_M5_STATUS";
    static const char_T ParameterNameStr_5[14] = "FDD_M6_STATUS";
    static const char_T ParameterNameStr_6[15] = "MPC_LAND_SPEED";
    static const char_T ParameterNameStr_7[14] = "MPC_TKO_SPEED";
    real_T tmp;

    // Start for If: '<S18>/If'
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S69>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_h = FLIGHT_HEXA_Hovering_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S69>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S14>/In1' incorporates:
    //   Outport: '<S14>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_m = FLIGHT_HEXA_Hovering_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_l = FLIGHT_HEXA_Hovering_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_b = FLIGHT_HEXA_Hovering_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_j = FLIGHT_HEXA_Hovering_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S15>/In1' incorporates:
    //   Outport: '<S15>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_c = FLIGHT_HEXA_Hovering_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S41>/In1' incorporates:
    //   Outport: '<S41>/Out1'

    FLIGHT_HEXA_Hovering_B.In1 = FLIGHT_HEXA_Hovering_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S38>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S53>/In1' incorporates:
    //   Outport: '<S53>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_p = FLIGHT_HEXA_Hovering_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S38>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S37>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S52>/In1' incorporates:
    //   Outport: '<S52>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_f = FLIGHT_HEXA_Hovering_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S37>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S18>/Take-off'
    // InitializeConditions for Delay: '<S30>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S31>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S32>/yaw_In' incorporates:
    //   Outport: '<S32>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In_ik = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S31>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S18>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S18>/Land'
    // InitializeConditions for Delay: '<S21>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S26>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S27>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S27>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S29>/yaw_In' incorporates:
    //   Outport: '<S29>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In_i = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S27>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S28>/In' incorporates:
    //   Outport: '<S28>/Out'

    FLIGHT_HEXA_Hovering_B.In = FLIGHT_HEXA_Hovering_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S18>/Land'

    // SystemInitialize for IfAction SubSystem: '<S18>/Waypoint'
    // Start for MATLABSystem: '<S23>/UAV Waypoint Follower'
    FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
    FLIGHT_HEXA_Hovering_DW.obj.StartFlag = true;
    FLIGHT_HEXA_Hovering_DW.obj.LookaheadFactor = 1.01;
    FLIGHT_HEXA_Hovering_DW.obj.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S23>/UAV Waypoint Follower'
    FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    memset(&FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[0], 0, 9U * sizeof
           (real_T));

    // End of SystemInitialize for SubSystem: '<S18>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S18>/IDLE'
    // InitializeConditions for Delay: '<S24>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S25>/yaw_In' incorporates:
    //   Outport: '<S25>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S18>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S4>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S529>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S534>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S581>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_n =
      FLIGHT_HEXA_Hovering_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S586>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_c =
      FLIGHT_HEXA_Hovering_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Gain: '<S76>/Gain1' incorporates:
    //   Outport: '<S76>/des_pitch'

    FLIGHT_HEXA_Hovering_B.Gain1 = FLIGHT_HEXA_Hovering_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S76>/des_roll' incorporates:
    //   Saturate: '<S389>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation[1] = FLIGHT_HEXA_Hovering_P.des_roll_Y0;

    // SystemInitialize for Saturate: '<S489>/Saturation' incorporates:
    //   Outport: '<S76>/des_yawrate'

    FLIGHT_HEXA_Hovering_B.Saturation_e = FLIGHT_HEXA_Hovering_P.des_yawrate_Y0;

    // SystemInitialize for Saturate: '<S593>/Saturation' incorporates:
    //   Outport: '<S76>/tau_Thrust'

    FLIGHT_HEXA_Hovering_B.Saturation_f = FLIGHT_HEXA_Hovering_P.tau_Thrust_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S4>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S119>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_k =
      FLIGHT_HEXA_Hovering_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S114>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_e =
      FLIGHT_HEXA_Hovering_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S73>/Rate Limiter2'
    FLIGHT_HEXA_Hovering_DW.PrevY = FLIGHT_HEXA_Hovering_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S171>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_kd =
      FLIGHT_HEXA_Hovering_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S166>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ek =
      FLIGHT_HEXA_Hovering_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S73>/Rate Limiter1'
    FLIGHT_HEXA_Hovering_DW.PrevY_f = FLIGHT_HEXA_Hovering_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S223>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i =
      FLIGHT_HEXA_Hovering_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S218>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_j =
      FLIGHT_HEXA_Hovering_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S126>/Saturation' incorporates:
    //   Outport: '<S73>/tau_Yaw'

    FLIGHT_HEXA_Hovering_B.Saturation_l = FLIGHT_HEXA_Hovering_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S178>/Saturation' incorporates:
    //   Outport: '<S73>/tau_Pitch'

    FLIGHT_HEXA_Hovering_B.Saturation_o = FLIGHT_HEXA_Hovering_P.tau_Pitch_Y0;

    // SystemInitialize for Saturate: '<S230>/Saturation' incorporates:
    //   Outport: '<S73>/tau_Roll'

    FLIGHT_HEXA_Hovering_B.Saturation_m = FLIGHT_HEXA_Hovering_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S19>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S48>/If Action Subsystem2'
    // Start for MATLABSystem: '<S51>/Read Parameter'
    FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c;
    FLIGHT_HEXA_Hovering_DW.obj_g.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S51>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S48>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S48>/If Action Subsystem1'
    // Start for MATLABSystem: '<S50>/Read Parameter'
    FLIGHT_HEXA_Hovering_DW.obj_b4.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_b4.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g;
    FLIGHT_HEXA_Hovering_DW.obj_b4.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_b4.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_b4.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_b4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_b4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S50>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S48>/If Action Subsystem1'
    FLIGHT_HEXA_Hovering_MATLABSystem_Init(&FLIGHT_HEXA_Hovering_DW.MATLABSystem);
    FLIGHT_HEXA_Hovering_MATLABSystem_Init
      (&FLIGHT_HEXA_Hovering_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S45>/MATLAB System'
    FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/SinkBlock' incorporates:
    //   BusAssignment: '<S36>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mc.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                          &FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                          &FLIGHT_HEXA_Hovering_B.BusAssignment1, 1);
    FLIGHT_HEXA_Hovering_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S19>/Send waypoints to OBC'
    FLIGHT_HEXA_Hovering_SourceBlock_k_Init
      (&FLIGHT_HEXA_Hovering_DW.SourceBlock_g);

    // Start for MATLABSystem: '<S8>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gv.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_gv.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_gv.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_p.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_p.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_p.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_p.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_p.isSetupComplete = true;
    FLIGHT_HEXA_Hovering_SourceBlock_Init(&FLIGHT_HEXA_Hovering_DW.SourceBlock_l);
    FLIGHT_HEXA_Hovering_SourceBlock_k_Init
      (&FLIGHT_HEXA_Hovering_DW.SourceBlock_b);

    // Start for MATLABSystem: '<S9>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_mg.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mg.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mg.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_mg.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_mg.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_mg.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/Read Parameter'
    FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_k.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S19>/Read Parameter'

    // Start for MATLABSystem: '<S40>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_e.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S38>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_kz.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S37>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gf.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_gf.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_DW.obj_mr.previousValidReceived = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.nextValidReceived = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S55>/Read Parameter13'
    FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_b.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Read Parameter13'

    // Start for MATLABSystem: '<S55>/Read Parameter1'
    FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_a.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Read Parameter1'

    // Start for MATLABSystem: '<S55>/Read Parameter2'
    FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_m.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_m.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_m.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Read Parameter2'

    // Start for MATLABSystem: '<S55>/Read Parameter3'
    FLIGHT_HEXA_Hovering_DW.obj_i.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_i.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_i.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_i.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_i.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Read Parameter3'

    // Start for MATLABSystem: '<S55>/Read Parameter4'
    FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_d.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Read Parameter4'

    // Start for MATLABSystem: '<S55>/Read Parameter5'
    FLIGHT_HEXA_Hovering_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_c.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_c.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_c.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S55>/Read Parameter5'

    // Start for MATLABSystem: '<S72>/SinkBlock' incorporates:
    //   BusAssignment: '<S59>/Bus Assignment'

    FLIGHT_HEXA_Hovering_DW.obj_m4.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_m4.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_m4.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_HEXA_Hovering_DW.obj_m4.orbMetadataObj,
                          &FLIGHT_HEXA_Hovering_DW.obj_m4.orbAdvertiseObj,
                          &FLIGHT_HEXA_Hovering_B.BusAssignment, 1);
    FLIGHT_HEXA_Hovering_DW.obj_m4.isSetupComplete = true;
    FLIGHT_HEXA_Hovering_SourceBlock_Init(&FLIGHT_HEXA_Hovering_DW.SourceBlock_h);

    // Start for MATLABSystem: '<S35>/PX4 Timestamp'
    FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_n.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_n.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_HEXA_Hovering_terminate(void)
{
  FLIGHT_HEXA_Hovering_SourceBlock_o_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_g);

  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_gv.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_p.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_p.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_p.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  FLIGHT_HEXA_Hovering_SourceBlock_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_l);
  FLIGHT_HEXA_Hovering_SourceBlock_o_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_b);

  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mg.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_mg.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_mg.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_mg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'

  // Terminate for MATLABSystem: '<S19>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Read Parameter'

  // Terminate for MATLABSystem: '<S40>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_e.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S40>/SourceBlock'

  // Terminate for MATLABSystem: '<S38>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_kz.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S38>/SourceBlock'

  // Terminate for MATLABSystem: '<S37>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_gf.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S37>/SourceBlock'

  // Terminate for MATLABSystem: '<S19>/LLA2LocalCoordinates'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S55>/Read Parameter13'
  if (!FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Read Parameter13'

  // Terminate for MATLABSystem: '<S55>/Read Parameter1'
  if (!FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Read Parameter1'

  // Terminate for MATLABSystem: '<S55>/Read Parameter2'
  if (!FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Read Parameter2'

  // Terminate for MATLABSystem: '<S55>/Read Parameter3'
  if (!FLIGHT_HEXA_Hovering_DW.obj_i.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Read Parameter3'

  // Terminate for MATLABSystem: '<S55>/Read Parameter4'
  if (!FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Read Parameter4'

  // Terminate for MATLABSystem: '<S55>/Read Parameter5'
  if (!FLIGHT_HEXA_Hovering_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/Read Parameter5'

  // Terminate for MATLABSystem: '<S72>/SinkBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_m4.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_m4.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_m4.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_m4.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_HEXA_Hovering_DW.obj_m4.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S72>/SinkBlock'

  // Terminate for Enabled SubSystem: '<S19>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_MATLABSystem_Term(&FLIGHT_HEXA_Hovering_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S48>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S51>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/Read Parameter'
  // End of Terminate for SubSystem: '<S48>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S48>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S50>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_b4.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_b4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S50>/Read Parameter'
  // End of Terminate for SubSystem: '<S48>/If Action Subsystem1'
  FLIGHT_HEXA_Hovering_MATLABSystem_Term(&FLIGHT_HEXA_Hovering_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S45>/MATLAB System'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S45>/MATLAB System'

  // Terminate for MATLABSystem: '<S47>/SinkBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_mc.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S47>/SinkBlock'
  // End of Terminate for SubSystem: '<S19>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_SourceBlock_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_h);

  // Terminate for MATLABSystem: '<S35>/PX4 Timestamp'
  if (!FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S35>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
