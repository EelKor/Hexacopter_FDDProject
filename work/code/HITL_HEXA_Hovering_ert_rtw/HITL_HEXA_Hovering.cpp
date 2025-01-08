//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HITL_HEXA_Hovering.cpp
//
// Code generated for Simulink model 'HITL_HEXA_Hovering'.
//
// Model version                  : 5.30
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Jan  8 14:27:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "HITL_HEXA_Hovering.h"
#include "rtwtypes.h"
#include "HITL_HEXA_Hovering_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"
#include <float.h>

// Named constants for Chart: '<S4>/Chart'
const uint8_T HITL_HEXA_Hovering_IN_MISSION = 1U;
const uint8_T HITL_HEXA_Hovering_IN_STABLIZED = 2U;
const real_T HITL_HEXA_Hovering_period = 0.004;

// Block signals (default storage)
B_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_B;

// Block states (default storage)
DW_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_DW;

// Real-time model
RT_MODEL_HITL_HEXA_Hovering_T HITL_HEXA_Hovering_M_ =
  RT_MODEL_HITL_HEXA_Hovering_T();
RT_MODEL_HITL_HEXA_Hovering_T *const HITL_HEXA_Hovering_M =
  &HITL_HEXA_Hovering_M_;

// Forward declaration for local functions
static real_T HITL_HEXA_Hovering_sind(real_T x);

// Forward declaration for local functions
static real_T HITL_HEXA_Hovering_rt_atan2d_snf(real_T u0, real_T u1);
static real_T HITL_HEXA_Hovering_rt_remd_snf(real_T u0, real_T u1);
static real_T HITL_HEXA_Hovering_sind_g(real_T x);
static void HITL_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3]);
static real_T HITL_HEXA_Hovering_norm(const real_T x[3]);

// System initialize for atomic system:
void HITL_HEXA_Hovering_SourceBlock_Init(DW_SourceBlock_HITL_HEXA_Hovering_T
  *localDW)
{
  // Start for MATLABSystem: '<S19>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(input_rc);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void HITL_HEXA_Hovering_SourceBlock(B_SourceBlock_HITL_HEXA_Hovering_T *localB,
  DW_SourceBlock_HITL_HEXA_Hovering_T *localDW)
{
  // MATLABSystem: '<S19>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 5000.0);
}

// Termination for atomic system:
void HITL_HEXA_Hovering_SourceBlock_Term(DW_SourceBlock_HITL_HEXA_Hovering_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S19>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S19>/SourceBlock'
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

static real_T HITL_HEXA_Hovering_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S60>/MATLAB System'
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
      b_x = sin(0.017453292519943295 * b_x);
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = cos((b_x - 90.0) * 0.017453292519943295);
      } else {
        b_x = -cos((b_x + 90.0) * 0.017453292519943295);
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

  // End of Start for MATLABSystem: '<S60>/MATLAB System'
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
void HITL_HEXA_Hovering_MATLABSystem_Init(DW_MATLABSystem_HITL_HEXA_Hovering_T
  *localDW)
{
  // Start for MATLABSystem: '<S60>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void HITL_HEXA_Hovering_MATLABSystem(const real_T rtu_0[3], const real_T rtu_1[3],
  boolean_T rtu_2, uint8_T rtu_3, B_MATLABSystem_HITL_HEXA_Hovering_T *localB)
{
  real_T Rn_tmp;
  real_T absx;
  real_T dLon;
  real_T flat;
  real_T u;
  int32_T b_k;
  boolean_T b[3];
  boolean_T exitg1;
  boolean_T latp2;

  // MATLABSystem: '<S60>/MATLAB System'
  if (rtu_2 && (rtu_3 != 5)) {
    localB->dLat = rtu_0[0] - rtu_1[0];
    dLon = rtu_0[1] - rtu_1[1];
    flat = fabs(localB->dLat);
    if (flat > 180.0) {
      if (rtIsNaN(localB->dLat + 180.0) || rtIsInf(localB->dLat + 180.0)) {
        flat = (rtNaN);
      } else if (localB->dLat + 180.0 == 0.0) {
        flat = 0.0;
      } else {
        flat = fmod(localB->dLat + 180.0, 360.0);
        if (flat == 0.0) {
          flat = 0.0;
        } else if (localB->dLat + 180.0 < 0.0) {
          flat += 360.0;
        }
      }

      localB->dLat = localB->dLat * 0.0 + (flat - 180.0);
      flat = fabs(localB->dLat);
    }

    if (flat > 90.0) {
      flat = fabs(localB->dLat);
      latp2 = (flat > 90.0);
      dLon += 180.0;
      u = localB->dLat * static_cast<real_T>(latp2);
      if (rtIsNaN(u)) {
        u = (rtNaN);
      } else if (u < 0.0) {
        u = -1.0;
      } else {
        u = (u > 0.0);
      }

      localB->dLat = (90.0 - (flat * static_cast<real_T>(latp2) - 90.0)) * u *
        static_cast<real_T>(latp2) + localB->dLat * static_cast<real_T>(!latp2);
    }

    if ((dLon > 180.0) || (dLon < -180.0)) {
      flat = rt_remd_snf(dLon, 360.0);
      u = flat / 180.0;
      if (u < 0.0) {
        u = ceil(u);
      } else {
        u = floor(u);
      }

      dLon = (flat - 360.0 * u) + dLon * 0.0;
    }

    flat = HITL_HEXA_Hovering_sind(rtu_1[0]);
    Rn_tmp = 1.0 - 0.0066943799901413165 * flat * flat;
    flat = 6.378137E+6 / sqrt(Rn_tmp);
    if (rtIsInf(rtu_1[0]) || rtIsNaN(rtu_1[0])) {
      u = (rtNaN);
    } else {
      u = rt_remd_snf(rtu_1[0], 360.0);
      absx = fabs(u);
      if (absx > 180.0) {
        if (u > 0.0) {
          u -= 360.0;
        } else {
          u += 360.0;
        }

        absx = fabs(u);
      }

      if (absx <= 45.0) {
        u = cos(0.017453292519943295 * u);
      } else if (absx <= 135.0) {
        if (u > 0.0) {
          u = -sin((u - 90.0) * 0.017453292519943295);
        } else {
          u = sin((u + 90.0) * 0.017453292519943295);
        }
      } else {
        if (u > 0.0) {
          u = (u - 180.0) * 0.017453292519943295;
        } else {
          u = (u + 180.0) * 0.017453292519943295;
        }

        u = -cos(u);
      }
    }

    localB->dLat /= rt_atan2d_snf(1.0, 0.99330562000985867 / Rn_tmp * flat) *
      57.295779513082323;
    dLon /= rt_atan2d_snf(1.0, flat * u) * 57.295779513082323;
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

    u = 0.0 / static_cast<real_T>(!latp2);
    localB->MATLABSystem[0] = static_cast<real32_T>(u + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(u + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(u + flat);
  } else {
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S60>/MATLAB System'
}

// Termination for atomic system:
void HITL_HEXA_Hovering_MATLABSystem_Term(DW_MATLABSystem_HITL_HEXA_Hovering_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S60>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/MATLAB System'
}

static real_T HITL_HEXA_Hovering_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      HITL_HEXA_Hovering_B.i = 1;
    } else {
      HITL_HEXA_Hovering_B.i = -1;
    }

    if (u1 > 0.0) {
      HITL_HEXA_Hovering_B.i1_c = 1;
    } else {
      HITL_HEXA_Hovering_B.i1_c = -1;
    }

    y = atan2(static_cast<real_T>(HITL_HEXA_Hovering_B.i), static_cast<real_T>
              (HITL_HEXA_Hovering_B.i1_c));
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

static real_T HITL_HEXA_Hovering_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      HITL_HEXA_Hovering_B.q = ceil(u1);
    } else {
      HITL_HEXA_Hovering_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != HITL_HEXA_Hovering_B.q)) {
      HITL_HEXA_Hovering_B.q = fabs(u0 / u1);
      if (!(fabs(HITL_HEXA_Hovering_B.q - floor(HITL_HEXA_Hovering_B.q + 0.5)) >
            DBL_EPSILON * HITL_HEXA_Hovering_B.q)) {
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

static real_T HITL_HEXA_Hovering_sind_g(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S63>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = HITL_HEXA_Hovering_rt_remd_snf(x, 360.0);
    HITL_HEXA_Hovering_B.absx_m = fabs(b_x);
    if (HITL_HEXA_Hovering_B.absx_m > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      HITL_HEXA_Hovering_B.absx_m = fabs(b_x);
    }

    if (HITL_HEXA_Hovering_B.absx_m <= 45.0) {
      b_x = sin(0.017453292519943295 * b_x);
    } else if (HITL_HEXA_Hovering_B.absx_m <= 135.0) {
      if (b_x > 0.0) {
        b_x = cos((b_x - 90.0) * 0.017453292519943295);
      } else {
        b_x = -cos((b_x + 90.0) * 0.017453292519943295);
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

  // End of Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
  return b_x;
}

static void HITL_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
  HITL_HEXA_Hovering_B.dLat = lla[0] - lla0[0];
  HITL_HEXA_Hovering_B.dLon = lla[1] - lla0[1];
  HITL_HEXA_Hovering_B.flat = fabs(HITL_HEXA_Hovering_B.dLat);
  if (HITL_HEXA_Hovering_B.flat > 180.0) {
    // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
    if (rtIsNaN(HITL_HEXA_Hovering_B.dLat + 180.0) || rtIsInf
        (HITL_HEXA_Hovering_B.dLat + 180.0)) {
      HITL_HEXA_Hovering_B.flat = (rtNaN);
    } else if (HITL_HEXA_Hovering_B.dLat + 180.0 == 0.0) {
      HITL_HEXA_Hovering_B.flat = 0.0;
    } else {
      HITL_HEXA_Hovering_B.flat = fmod(HITL_HEXA_Hovering_B.dLat + 180.0, 360.0);
      if (HITL_HEXA_Hovering_B.flat == 0.0) {
        HITL_HEXA_Hovering_B.flat = 0.0;
      } else if (HITL_HEXA_Hovering_B.dLat + 180.0 < 0.0) {
        HITL_HEXA_Hovering_B.flat += 360.0;
      }
    }

    HITL_HEXA_Hovering_B.dLat = HITL_HEXA_Hovering_B.dLat * 0.0 +
      (HITL_HEXA_Hovering_B.flat - 180.0);
    HITL_HEXA_Hovering_B.flat = fabs(HITL_HEXA_Hovering_B.dLat);
  }

  if (HITL_HEXA_Hovering_B.flat > 90.0) {
    // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
    HITL_HEXA_Hovering_B.flat = fabs(HITL_HEXA_Hovering_B.dLat);
    HITL_HEXA_Hovering_B.latp2 = (HITL_HEXA_Hovering_B.flat > 90.0);

    // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
    HITL_HEXA_Hovering_B.dLon += 180.0;
    HITL_HEXA_Hovering_B.Rn = HITL_HEXA_Hovering_B.dLat * static_cast<real_T>
      (HITL_HEXA_Hovering_B.latp2);
    if (rtIsNaN(HITL_HEXA_Hovering_B.Rn)) {
      HITL_HEXA_Hovering_B.Rn = (rtNaN);
    } else if (HITL_HEXA_Hovering_B.Rn < 0.0) {
      HITL_HEXA_Hovering_B.Rn = -1.0;
    } else {
      HITL_HEXA_Hovering_B.Rn = (HITL_HEXA_Hovering_B.Rn > 0.0);
    }

    HITL_HEXA_Hovering_B.dLat = (90.0 - (HITL_HEXA_Hovering_B.flat *
      static_cast<real_T>(HITL_HEXA_Hovering_B.latp2) - 90.0)) *
      HITL_HEXA_Hovering_B.Rn * static_cast<real_T>(HITL_HEXA_Hovering_B.latp2)
      + HITL_HEXA_Hovering_B.dLat * static_cast<real_T>
      (!HITL_HEXA_Hovering_B.latp2);
  }

  // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
  if ((HITL_HEXA_Hovering_B.dLon > 180.0) || (HITL_HEXA_Hovering_B.dLon < -180.0))
  {
    HITL_HEXA_Hovering_B.flat = HITL_HEXA_Hovering_rt_remd_snf
      (HITL_HEXA_Hovering_B.dLon, 360.0);
    HITL_HEXA_Hovering_B.Rn = HITL_HEXA_Hovering_B.flat / 180.0;
    if (HITL_HEXA_Hovering_B.Rn < 0.0) {
      HITL_HEXA_Hovering_B.Rn = ceil(HITL_HEXA_Hovering_B.Rn);
    } else {
      HITL_HEXA_Hovering_B.Rn = floor(HITL_HEXA_Hovering_B.Rn);
    }

    HITL_HEXA_Hovering_B.dLon = (HITL_HEXA_Hovering_B.flat - 360.0 *
      HITL_HEXA_Hovering_B.Rn) + HITL_HEXA_Hovering_B.dLon * 0.0;
  }

  HITL_HEXA_Hovering_B.flat = HITL_HEXA_Hovering_sind_g(lla0[0]);
  HITL_HEXA_Hovering_B.flat = 1.0 - 0.0066943799901413165 *
    HITL_HEXA_Hovering_B.flat * HITL_HEXA_Hovering_B.flat;
  HITL_HEXA_Hovering_B.Rn = 6.378137E+6 / sqrt(HITL_HEXA_Hovering_B.flat);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    HITL_HEXA_Hovering_B.b_x = (rtNaN);
  } else {
    HITL_HEXA_Hovering_B.b_x = HITL_HEXA_Hovering_rt_remd_snf(lla0[0], 360.0);
    HITL_HEXA_Hovering_B.absx = fabs(HITL_HEXA_Hovering_B.b_x);
    if (HITL_HEXA_Hovering_B.absx > 180.0) {
      if (HITL_HEXA_Hovering_B.b_x > 0.0) {
        HITL_HEXA_Hovering_B.b_x -= 360.0;
      } else {
        HITL_HEXA_Hovering_B.b_x += 360.0;
      }

      HITL_HEXA_Hovering_B.absx = fabs(HITL_HEXA_Hovering_B.b_x);
    }

    if (HITL_HEXA_Hovering_B.absx <= 45.0) {
      HITL_HEXA_Hovering_B.b_x = cos(0.017453292519943295 *
        HITL_HEXA_Hovering_B.b_x);
    } else if (HITL_HEXA_Hovering_B.absx <= 135.0) {
      if (HITL_HEXA_Hovering_B.b_x > 0.0) {
        HITL_HEXA_Hovering_B.b_x = -sin((HITL_HEXA_Hovering_B.b_x - 90.0) *
          0.017453292519943295);
      } else {
        HITL_HEXA_Hovering_B.b_x = sin((HITL_HEXA_Hovering_B.b_x + 90.0) *
          0.017453292519943295);
      }
    } else {
      if (HITL_HEXA_Hovering_B.b_x > 0.0) {
        HITL_HEXA_Hovering_B.b_x = (HITL_HEXA_Hovering_B.b_x - 180.0) *
          0.017453292519943295;
      } else {
        HITL_HEXA_Hovering_B.b_x = (HITL_HEXA_Hovering_B.b_x + 180.0) *
          0.017453292519943295;
      }

      HITL_HEXA_Hovering_B.b_x = -cos(HITL_HEXA_Hovering_B.b_x);
    }
  }

  xyzNED[0] = HITL_HEXA_Hovering_B.dLat / (HITL_HEXA_Hovering_rt_atan2d_snf(1.0,
    0.99330562000985867 / HITL_HEXA_Hovering_B.flat * HITL_HEXA_Hovering_B.Rn) *
    57.295779513082323);
  xyzNED[1] = HITL_HEXA_Hovering_B.dLon / (HITL_HEXA_Hovering_rt_atan2d_snf(1.0,
    HITL_HEXA_Hovering_B.Rn * HITL_HEXA_Hovering_B.b_x) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  HITL_HEXA_Hovering_B.b[0] = rtIsNaN(xyzNED[0]);
  HITL_HEXA_Hovering_B.b[1] = rtIsNaN(xyzNED[1]);
  HITL_HEXA_Hovering_B.b[2] = rtIsNaN(xyzNED[2]);
  HITL_HEXA_Hovering_B.latp2 = false;
  HITL_HEXA_Hovering_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (HITL_HEXA_Hovering_B.b_k < 3)) {
    if (HITL_HEXA_Hovering_B.b[HITL_HEXA_Hovering_B.b_k]) {
      HITL_HEXA_Hovering_B.latp2 = true;
      exitg1 = true;
    } else {
      HITL_HEXA_Hovering_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
  HITL_HEXA_Hovering_B.dLat = 0.0 / static_cast<real_T>
    (!HITL_HEXA_Hovering_B.latp2);
  xyzNED[0] += HITL_HEXA_Hovering_B.dLat;
  xyzNED[1] += HITL_HEXA_Hovering_B.dLat;
  xyzNED[2] += HITL_HEXA_Hovering_B.dLat;
}

static real_T HITL_HEXA_Hovering_norm(const real_T x[3])
{
  real_T y;
  HITL_HEXA_Hovering_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S41>/UAV Waypoint Follower'
  HITL_HEXA_Hovering_B.absxk = fabs(x[0]);
  if (HITL_HEXA_Hovering_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    HITL_HEXA_Hovering_B.scale = HITL_HEXA_Hovering_B.absxk;
  } else {
    HITL_HEXA_Hovering_B.t = HITL_HEXA_Hovering_B.absxk /
      3.3121686421112381E-170;
    y = HITL_HEXA_Hovering_B.t * HITL_HEXA_Hovering_B.t;
  }

  // Start for MATLABSystem: '<S41>/UAV Waypoint Follower'
  HITL_HEXA_Hovering_B.absxk = fabs(x[1]);
  if (HITL_HEXA_Hovering_B.absxk > HITL_HEXA_Hovering_B.scale) {
    HITL_HEXA_Hovering_B.t = HITL_HEXA_Hovering_B.scale /
      HITL_HEXA_Hovering_B.absxk;
    y = y * HITL_HEXA_Hovering_B.t * HITL_HEXA_Hovering_B.t + 1.0;
    HITL_HEXA_Hovering_B.scale = HITL_HEXA_Hovering_B.absxk;
  } else {
    HITL_HEXA_Hovering_B.t = HITL_HEXA_Hovering_B.absxk /
      HITL_HEXA_Hovering_B.scale;
    y += HITL_HEXA_Hovering_B.t * HITL_HEXA_Hovering_B.t;
  }

  // Start for MATLABSystem: '<S41>/UAV Waypoint Follower'
  HITL_HEXA_Hovering_B.absxk = fabs(x[2]);
  if (HITL_HEXA_Hovering_B.absxk > HITL_HEXA_Hovering_B.scale) {
    HITL_HEXA_Hovering_B.t = HITL_HEXA_Hovering_B.scale /
      HITL_HEXA_Hovering_B.absxk;
    y = y * HITL_HEXA_Hovering_B.t * HITL_HEXA_Hovering_B.t + 1.0;
    HITL_HEXA_Hovering_B.scale = HITL_HEXA_Hovering_B.absxk;
  } else {
    HITL_HEXA_Hovering_B.t = HITL_HEXA_Hovering_B.absxk /
      HITL_HEXA_Hovering_B.scale;
    y += HITL_HEXA_Hovering_B.t * HITL_HEXA_Hovering_B.t;
  }

  return HITL_HEXA_Hovering_B.scale * sqrt(y);
}

// Model step function
void HITL_HEXA_Hovering_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  HITL_HEXA_Hovering_SourceBlock(&HITL_HEXA_Hovering_B.SourceBlock,
    &HITL_HEXA_Hovering_DW.SourceBlock);

  // Outputs for Enabled SubSystem: '<S19>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  if (HITL_HEXA_Hovering_B.SourceBlock.SourceBlock_o1) {
    // SignalConversion generated from: '<S20>/In1' incorporates:
    //   MATLABSystem: '<S19>/SourceBlock'

    HITL_HEXA_Hovering_B.In1_b = HITL_HEXA_Hovering_B.SourceBlock.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S19>/Enabled Subsystem'

  // RelationalOperator: '<S11>/Compare' incorporates:
  //   Constant: '<S11>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  HITL_HEXA_Hovering_B.Compare_h = (HITL_HEXA_Hovering_B.In1_b.values[6] >=
    HITL_HEXA_Hovering_P.CompareToConstant_const);

  // MATLABSystem: '<S26>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_gv.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_gv.eventStructObj, &HITL_HEXA_Hovering_B.r3,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S32>/Enable'

  // Start for MATLABSystem: '<S26>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S32>/In1'
    HITL_HEXA_Hovering_B.In1_m = HITL_HEXA_Hovering_B.r3;
  }

  // End of Outputs for SubSystem: '<S26>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   Math: '<S340>/Transpose'

  HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = HITL_HEXA_Hovering_B.In1_m.q[0];
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = HITL_HEXA_Hovering_B.In1_m.q[1];
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = HITL_HEXA_Hovering_B.In1_m.q[2];
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 = HITL_HEXA_Hovering_B.In1_m.q[3];

  // Switch: '<S76>/Switch' incorporates:
  //   Constant: '<S76>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   Math: '<S340>/Transpose'
  //   Product: '<S602>/Product'
  //   Product: '<S602>/Product1'
  //   Product: '<S602>/Product2'
  //   Product: '<S602>/Product3'
  //   Sum: '<S602>/Sum'

  if (!(((static_cast<real_T>(HITL_HEXA_Hovering_B.In1_m.q[0]) *
          HITL_HEXA_Hovering_B.In1_m.q[0] + static_cast<real_T>
          (HITL_HEXA_Hovering_B.In1_m.q[1]) * HITL_HEXA_Hovering_B.In1_m.q[1]) +
         static_cast<real_T>(HITL_HEXA_Hovering_B.In1_m.q[2]) *
         HITL_HEXA_Hovering_B.In1_m.q[2]) + static_cast<real_T>
        (HITL_HEXA_Hovering_B.In1_m.q[3]) * HITL_HEXA_Hovering_B.In1_m.q[3] >
        HITL_HEXA_Hovering_P.Switch_Threshold_o)) {
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 =
      HITL_HEXA_Hovering_P.Constant_Value_pp[0];
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      HITL_HEXA_Hovering_P.Constant_Value_pp[1];
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 =
      HITL_HEXA_Hovering_P.Constant_Value_pp[2];
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 =
      HITL_HEXA_Hovering_P.Constant_Value_pp[3];
  }

  // End of Switch: '<S76>/Switch'

  // Sqrt: '<S609>/sqrt' incorporates:
  //   Product: '<S610>/Product'
  //   Product: '<S610>/Product1'
  //   Product: '<S610>/Product2'
  //   Product: '<S610>/Product3'
  //   Sum: '<S610>/Sum'

  HITL_HEXA_Hovering_B.Switch2 = sqrt(((HITL_HEXA_Hovering_B.rtb_Transpose_idx_0
    * HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 +
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 *
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) +
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 *
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_2) +
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 *
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_3);

  // Product: '<S604>/Product'
  HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 /
    HITL_HEXA_Hovering_B.Switch2;

  // Product: '<S604>/Product1'
  HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 /
    HITL_HEXA_Hovering_B.Switch2;

  // Product: '<S604>/Product2'
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 / HITL_HEXA_Hovering_B.Switch2;

  // Product: '<S604>/Product3'
  HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 /
    HITL_HEXA_Hovering_B.Switch2;

  // Fcn: '<S77>/fcn2' incorporates:
  //   Fcn: '<S77>/fcn5'

  HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = HITL_HEXA_Hovering_B.Switch3 *
    HITL_HEXA_Hovering_B.Switch3;
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = HITL_HEXA_Hovering_B.Switch4 *
    HITL_HEXA_Hovering_B.Switch4;
  HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 *
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1;
  HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_B.Switch2 *
    HITL_HEXA_Hovering_B.Switch2;

  // Trigonometry: '<S603>/Trigonometric Function1' incorporates:
  //   Fcn: '<S77>/fcn1'
  //   Fcn: '<S77>/fcn2'

  HITL_HEXA_Hovering_B.VectorConcatenate[0] = HITL_HEXA_Hovering_rt_atan2d_snf
    ((HITL_HEXA_Hovering_B.Switch4 * HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 +
      HITL_HEXA_Hovering_B.Switch3 * HITL_HEXA_Hovering_B.Switch2) * 2.0,
     ((HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 +
       HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) -
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0) - HITL_HEXA_Hovering_B.Subtract_f);

  // Fcn: '<S77>/fcn3'
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 = (HITL_HEXA_Hovering_B.Switch4 *
    HITL_HEXA_Hovering_B.Switch2 - HITL_HEXA_Hovering_B.Switch3 *
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) * -2.0;

  // Trigonometry: '<S603>/Trigonometric Function3' incorporates:
  //   Fcn: '<S77>/fcn4'
  //   Fcn: '<S77>/fcn5'

  HITL_HEXA_Hovering_B.VectorConcatenate[2] = HITL_HEXA_Hovering_rt_atan2d_snf
    ((HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 * HITL_HEXA_Hovering_B.Switch2 +
      HITL_HEXA_Hovering_B.Switch3 * HITL_HEXA_Hovering_B.Switch4) * 2.0,
     ((HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 -
       HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) -
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0) + HITL_HEXA_Hovering_B.Subtract_f);

  // MATLABSystem: '<S23>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_po.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_po.eventStructObj, &HITL_HEXA_Hovering_B.r5,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S28>/Enable'

  // Start for MATLABSystem: '<S23>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S28>/In1'
    HITL_HEXA_Hovering_B.In1_l = HITL_HEXA_Hovering_B.r5;
  }

  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'

  // MATLABSystem: '<S24>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_d0.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_d0.eventStructObj, &HITL_HEXA_Hovering_B.r6,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S29>/Enable'

  // Start for MATLABSystem: '<S24>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S29>/In1'
    HITL_HEXA_Hovering_B.In1_bs = HITL_HEXA_Hovering_B.r6;
  }

  // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'
  HITL_HEXA_Hovering_SourceBlock(&HITL_HEXA_Hovering_B.SourceBlock_b,
    &HITL_HEXA_Hovering_DW.SourceBlock_b);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S31>/Enable'

  if (HITL_HEXA_Hovering_B.SourceBlock_b.SourceBlock_o1) {
    // SignalConversion generated from: '<S31>/In1' incorporates:
    //   MATLABSystem: '<S30>/SourceBlock'

    HITL_HEXA_Hovering_B.In1_j =
      HITL_HEXA_Hovering_B.SourceBlock_b.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'

  // Gain: '<S74>/Gain2' incorporates:
  //   Constant: '<S74>/Constant2'
  //   Sum: '<S74>/Sum2'

  HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (HITL_HEXA_Hovering_B.In1_j.values[1]) -
    HITL_HEXA_Hovering_P.Constant2_Value_g) * HITL_HEXA_Hovering_P.Gain2_Gain_d;

  // Saturate: '<S74>/Saturation2'
  if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
      HITL_HEXA_Hovering_P.Saturation2_UpperSat) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_P.Saturation2_UpperSat;
  } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
             HITL_HEXA_Hovering_P.Saturation2_LowerSat) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_P.Saturation2_LowerSat;
  }

  // Gain: '<S4>/Gain1' incorporates:
  //   Saturate: '<S74>/Saturation2'

  HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = HITL_HEXA_Hovering_P.Gain1_Gain_h *
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0;

  // Gain: '<S74>/Gain1' incorporates:
  //   Constant: '<S74>/Constant1'
  //   Sum: '<S74>/Sum1'

  HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (HITL_HEXA_Hovering_B.In1_j.values[0]) -
    HITL_HEXA_Hovering_P.Constant1_Value_h) * HITL_HEXA_Hovering_P.Gain1_Gain_e;

  // Saturate: '<S74>/Saturation1'
  if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
      HITL_HEXA_Hovering_P.Saturation1_UpperSat_p) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_P.Saturation1_UpperSat_p;
  } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
             HITL_HEXA_Hovering_P.Saturation1_LowerSat_j) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_P.Saturation1_LowerSat_j;
  }

  // Gain: '<S4>/Gain2' incorporates:
  //   Saturate: '<S74>/Saturation1'

  HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = HITL_HEXA_Hovering_P.Gain2_Gain_m *
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0;

  // Gain: '<S74>/Gain' incorporates:
  //   Constant: '<S74>/Constant'
  //   Sum: '<S74>/Sum'

  HITL_HEXA_Hovering_B.Switch2 = (static_cast<real_T>
    (HITL_HEXA_Hovering_B.In1_j.values[2]) -
    HITL_HEXA_Hovering_P.Constant_Value_ol) * HITL_HEXA_Hovering_P.Gain_Gain_et;

  // Saturate: '<S74>/Saturation'
  if (HITL_HEXA_Hovering_B.Switch2 > HITL_HEXA_Hovering_P.Saturation_UpperSat_j)
  {
    HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_P.Saturation_UpperSat_j;
  } else if (HITL_HEXA_Hovering_B.Switch2 <
             HITL_HEXA_Hovering_P.Saturation_LowerSat_l4) {
    HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_P.Saturation_LowerSat_l4;
  }

  // End of Saturate: '<S74>/Saturation'

  // Gain: '<S74>/Gain3' incorporates:
  //   Constant: '<S74>/Constant3'
  //   Sum: '<S74>/Sum3'

  HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (HITL_HEXA_Hovering_B.In1_j.values[3]) -
    HITL_HEXA_Hovering_P.Constant3_Value_n) * HITL_HEXA_Hovering_P.Gain3_Gain;

  // Saturate: '<S74>/Saturation3'
  if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
      HITL_HEXA_Hovering_P.Saturation3_UpperSat) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_P.Saturation3_UpperSat;
  } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
             HITL_HEXA_Hovering_P.Saturation3_LowerSat) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_P.Saturation3_LowerSat;
  }

  // Gain: '<S4>/Gain4' incorporates:
  //   Saturate: '<S74>/Saturation3'

  HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = HITL_HEXA_Hovering_P.Gain4_Gain *
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0;

  // MATLABSystem: '<S27>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_mg.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_mg.eventStructObj, &HITL_HEXA_Hovering_B.r2,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S27>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  // Start for MATLABSystem: '<S27>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S33>/In1'
    HITL_HEXA_Hovering_B.In1_c = HITL_HEXA_Hovering_B.r2;
  }

  // End of Outputs for SubSystem: '<S27>/Enabled Subsystem'

  // MATLABSystem: '<S37>/Read Parameter'
  if (HITL_HEXA_Hovering_DW.obj_k.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_k.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_c);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // MATLABSystem: '<S58>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_e.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_e.eventStructObj, &HITL_HEXA_Hovering_B.r, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S58>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S59>/Enable'

  // Start for MATLABSystem: '<S58>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S59>/In1'
    HITL_HEXA_Hovering_B.In1 = HITL_HEXA_Hovering_B.r;
  }

  // End of Outputs for SubSystem: '<S58>/Enabled Subsystem'

  // MATLABSystem: '<S56>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_kz.eventStructObj, &HITL_HEXA_Hovering_B.r1,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S56>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S71>/Enable'

  // Start for MATLABSystem: '<S56>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S71>/In1'
    HITL_HEXA_Hovering_B.In1_p = HITL_HEXA_Hovering_B.r1;
  }

  // End of Outputs for SubSystem: '<S56>/Enabled Subsystem'

  // MATLABSystem: '<S55>/SourceBlock'
  HITL_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (HITL_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
     &HITL_HEXA_Hovering_DW.obj_gf.eventStructObj, &HITL_HEXA_Hovering_B.r4,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S70>/Enable'

  // Start for MATLABSystem: '<S55>/SourceBlock'
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S70>/In1'
    HITL_HEXA_Hovering_B.In1_f = HITL_HEXA_Hovering_B.r4;
  }

  // End of Outputs for SubSystem: '<S55>/Enabled Subsystem'

  // MATLABSystem: '<S37>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S37>/Read Parameter'
  //   SignalConversion generated from: '<S70>/In1'
  //
  HITL_HEXA_Hovering_B.b_startWaypoint[0] = 0.0;
  HITL_HEXA_Hovering_B.DataTypeConversion2[0] = 0.0;
  HITL_HEXA_Hovering_B.virtualWaypoint[0] = 0.0;
  HITL_HEXA_Hovering_B.b_startWaypoint[1] = 0.0;
  HITL_HEXA_Hovering_B.DataTypeConversion2[1] = 0.0;
  HITL_HEXA_Hovering_B.virtualWaypoint[1] = 0.0;
  HITL_HEXA_Hovering_B.b_startWaypoint[2] = 0.0;
  HITL_HEXA_Hovering_B.DataTypeConversion2[2] = 0.0;
  HITL_HEXA_Hovering_B.virtualWaypoint[2] = 0.0;
  HITL_HEXA_Hovering_B.lla0[0] = HITL_HEXA_Hovering_B.In1_f.lat;
  HITL_HEXA_Hovering_B.lla0[1] = HITL_HEXA_Hovering_B.In1_f.lon;
  HITL_HEXA_Hovering_B.lla0[2] = HITL_HEXA_Hovering_B.In1_f.alt;
  if (HITL_HEXA_Hovering_B.In1_p.previous.valid &&
      (!HITL_HEXA_Hovering_DW.obj_mr.previousValidReceived)) {
    HITL_HEXA_Hovering_DW.obj_mr.previousValidReceived = true;
  }

  if (HITL_HEXA_Hovering_B.In1_p.next.valid &&
      (!HITL_HEXA_Hovering_DW.obj_mr.nextValidReceived)) {
    HITL_HEXA_Hovering_DW.obj_mr.nextValidReceived = true;
  }

  if (HITL_HEXA_Hovering_B.In1_f.valid_hpos &&
      HITL_HEXA_Hovering_B.In1_p.current.valid &&
      (HITL_HEXA_Hovering_B.In1_p.current.type != 5)) {
    if (HITL_HEXA_Hovering_B.ParamStep_c != 0) {
      HITL_HEXA_Hovering_B.DataTypeConversion2[0] =
        HITL_HEXA_Hovering_B.In1.waypoints[0].position[0];
      HITL_HEXA_Hovering_B.DataTypeConversion2[1] =
        HITL_HEXA_Hovering_B.In1.waypoints[0].position[1];
      HITL_HEXA_Hovering_B.DataTypeConversion2[2] =
        HITL_HEXA_Hovering_B.In1.waypoints[0].position[2];
    } else {
      HITL_HEXA_Hovering_B.dv[0] = HITL_HEXA_Hovering_B.In1_p.current.lat;
      HITL_HEXA_Hovering_B.dv[1] = HITL_HEXA_Hovering_B.In1_p.current.lon;
      HITL_HEXA_Hovering_B.dv[2] = HITL_HEXA_Hovering_B.In1_p.current.alt;
      HITL_HEXA_Hovering_lla2ned(HITL_HEXA_Hovering_B.dv,
        HITL_HEXA_Hovering_B.lla0, HITL_HEXA_Hovering_B.DataTypeConversion2);
    }
  }

  if (HITL_HEXA_Hovering_B.In1_f.valid_hpos &&
      (HITL_HEXA_Hovering_B.In1_p.previous.valid ||
       HITL_HEXA_Hovering_DW.obj_mr.previousValidReceived)) {
    HITL_HEXA_Hovering_B.dv[0] = HITL_HEXA_Hovering_B.In1_p.previous.lat;
    HITL_HEXA_Hovering_B.dv[1] = HITL_HEXA_Hovering_B.In1_p.previous.lon;
    HITL_HEXA_Hovering_B.dv[2] = HITL_HEXA_Hovering_B.In1_p.previous.alt;
    HITL_HEXA_Hovering_lla2ned(HITL_HEXA_Hovering_B.dv,
      HITL_HEXA_Hovering_B.lla0, HITL_HEXA_Hovering_B.b_startWaypoint);
  }

  if (HITL_HEXA_Hovering_B.In1_f.valid_hpos &&
      (HITL_HEXA_Hovering_B.In1_p.next.valid ||
       HITL_HEXA_Hovering_DW.obj_mr.nextValidReceived)) {
    HITL_HEXA_Hovering_B.dv[0] = HITL_HEXA_Hovering_B.In1_p.next.lat;
    HITL_HEXA_Hovering_B.dv[1] = HITL_HEXA_Hovering_B.In1_p.next.lon;
    HITL_HEXA_Hovering_B.dv[2] = HITL_HEXA_Hovering_B.In1_p.next.alt;
    HITL_HEXA_Hovering_lla2ned(HITL_HEXA_Hovering_B.dv,
      HITL_HEXA_Hovering_B.lla0, HITL_HEXA_Hovering_B.virtualWaypoint);
  }

  // If: '<S36>/If' incorporates:
  //   Delay: '<S42>/Delay'
  //   Delay: '<S45>/Delay'
  //   Delay: '<S49>/Delay'
  //   MATLABSystem: '<S37>/LLA2LocalCoordinates'
  //
  HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_DW.If_ActiveSubsystem;
  if (HITL_HEXA_Hovering_B.In1_p.current.type == 3) {
    HITL_HEXA_Hovering_DW.If_ActiveSubsystem = 0;
  } else if (HITL_HEXA_Hovering_B.In1_p.current.type == 4) {
    HITL_HEXA_Hovering_DW.If_ActiveSubsystem = 1;
  } else if (HITL_HEXA_Hovering_B.In1_p.current.type == 0) {
    HITL_HEXA_Hovering_DW.If_ActiveSubsystem = 2;
  } else {
    HITL_HEXA_Hovering_DW.If_ActiveSubsystem = 3;
  }

  switch (HITL_HEXA_Hovering_DW.If_ActiveSubsystem) {
   case 0:
    if (HITL_HEXA_Hovering_DW.If_ActiveSubsystem !=
        HITL_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S36>/Take-off' incorporates:
      //   ActionPort: '<S40>/Action Port'

      // InitializeConditions for If: '<S36>/If' incorporates:
      //   Delay: '<S48>/Delay'
      //   Delay: '<S49>/Delay'

      HITL_HEXA_Hovering_DW.Delay_DSTATE_c =
        HITL_HEXA_Hovering_P.Delay_InitialCondition;
      HITL_HEXA_Hovering_DW.Delay_DSTATE_d =
        HITL_HEXA_Hovering_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S36>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S36>/Take-off' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // Sum: '<S48>/Sum' incorporates:
    //   Constant: '<S48>/Rate'
    //   Delay: '<S48>/Delay'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_c += HITL_HEXA_Hovering_P.Rate_Value;

    // Gain: '<S48>/Gain1'
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.Gain1_Gain *
      HITL_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S49>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S50>/Enable'

    if (HITL_HEXA_Hovering_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S50>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      HITL_HEXA_Hovering_B.yaw_In_ik = HITL_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S49>/Enabled Subsystem2'

    // Reshape: '<S40>/Reshape' incorporates:
    //   Delay: '<S49>/Delay'
    //   Merge: '<S36>/Merge'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
      HITL_HEXA_Hovering_B.DataTypeConversion2[0];
    HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.DataTypeConversion2[1];

    // Gain: '<S48>/Gain' incorporates:
    //   Delay: '<S48>/Delay'
    //   RelationalOperator: '<S48>/Relational Operator'
    //   Switch: '<S48>/Switch'

    if (!(HITL_HEXA_Hovering_B.Switch3 <= HITL_HEXA_Hovering_DW.Delay_DSTATE_c))
    {
      HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_DW.Delay_DSTATE_c;
    }

    // Reshape: '<S40>/Reshape' incorporates:
    //   Gain: '<S48>/Gain'
    //   Merge: '<S36>/Merge'
    //   Switch: '<S48>/Switch'

    HITL_HEXA_Hovering_B.Switch3 *= HITL_HEXA_Hovering_P.Gain_Gain_e;
    HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_B.yaw_In_ik;

    // Update for Delay: '<S49>/Delay' incorporates:
    //   Constant: '<S49>/Constant'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_d = HITL_HEXA_Hovering_P.Constant_Value_f;

    // End of Outputs for SubSystem: '<S36>/Take-off'
    break;

   case 1:
    if (HITL_HEXA_Hovering_DW.If_ActiveSubsystem !=
        HITL_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S36>/Land' incorporates:
      //   ActionPort: '<S39>/Action Port'

      // InitializeConditions for If: '<S36>/If' incorporates:
      //   Delay: '<S39>/Delay'
      //   Delay: '<S44>/Delay'
      //   Delay: '<S45>/Delay'
      //   Gain: '<S44>/Gain1'

      HITL_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        HITL_HEXA_Hovering_P.Delay_InitialCondition_n;
      HITL_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        HITL_HEXA_Hovering_P.Delay_InitialCondition_n;
      HITL_HEXA_Hovering_DW.Delay_DSTATE_n =
        HITL_HEXA_Hovering_P.Delay_InitialCondition_m;
      HITL_HEXA_Hovering_DW.Delay_DSTATE_b =
        HITL_HEXA_Hovering_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S36>/Land'
    }

    // Outputs for IfAction SubSystem: '<S36>/Land' incorporates:
    //   ActionPort: '<S39>/Action Port'

    // Switch: '<S39>/Switch' incorporates:
    //   Delay: '<S39>/Delay'
    //   Logic: '<S39>/OR'
    //   RelationalOperator: '<S39>/IsNaN'

    if ((!rtIsNaN(HITL_HEXA_Hovering_B.DataTypeConversion2[0])) && (!rtIsNaN
         (HITL_HEXA_Hovering_B.DataTypeConversion2[1]))) {
      HITL_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        HITL_HEXA_Hovering_B.DataTypeConversion2[0];
      HITL_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        HITL_HEXA_Hovering_B.DataTypeConversion2[1];
    }

    // End of Switch: '<S39>/Switch'

    // Switch: '<S44>/Switch' incorporates:
    //   Delay: '<S44>/Delay'

    if (!(HITL_HEXA_Hovering_DW.Delay_DSTATE_n >
          HITL_HEXA_Hovering_P.Switch_Threshold)) {
      // Gain: '<S44>/Gain1' incorporates:
      //   Gain: '<S44>/Gain'

      HITL_HEXA_Hovering_DW.Delay_DSTATE_n = HITL_HEXA_Hovering_P.Gain_Gain_l *
        HITL_HEXA_Hovering_B.b_startWaypoint[2];
    }

    // End of Switch: '<S44>/Switch'

    // Sum: '<S44>/Subtract' incorporates:
    //   Constant: '<S44>/Rate of descent'

    HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_DW.Delay_DSTATE_n -
      HITL_HEXA_Hovering_P.Rateofdescent_Value;

    // Gain: '<S44>/Gain1' incorporates:
    //   Gain: '<S44>/Gain2'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_n = HITL_HEXA_Hovering_P.Gain2_Gain *
      HITL_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S45>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S47>/Enable'

    if (HITL_HEXA_Hovering_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S47>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      HITL_HEXA_Hovering_B.yaw_In_i = HITL_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S45>/Enabled Subsystem2'

    // Reshape: '<S39>/Reshape' incorporates:
    //   Delay: '<S39>/Delay'
    //   Delay: '<S45>/Delay'
    //   Merge: '<S36>/Merge'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_DW.Delay_DSTATE_l
      [0];
    HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_DW.Delay_DSTATE_l[1];

    // Switch: '<S44>/Switch1' incorporates:
    //   RelationalOperator: '<S44>/GreaterThan'

    if (!(HITL_HEXA_Hovering_DW.Delay_DSTATE_n > HITL_HEXA_Hovering_B.Subtract_f))
    {
      // Gain: '<S44>/Gain1'
      HITL_HEXA_Hovering_DW.Delay_DSTATE_n = HITL_HEXA_Hovering_B.Subtract_f;
    }

    // Reshape: '<S39>/Reshape' incorporates:
    //   Gain: '<S44>/Gain1'
    //   Merge: '<S36>/Merge'
    //   Switch: '<S44>/Switch1'

    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.Gain1_Gain_a *
      HITL_HEXA_Hovering_DW.Delay_DSTATE_n;
    HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S44>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S46>/Enable'

    if (HITL_HEXA_Hovering_B.Subtract_f > 0.0) {
      // SignalConversion generated from: '<S46>/In'
      HITL_HEXA_Hovering_B.In = HITL_HEXA_Hovering_B.Subtract_f;
    }

    // End of Outputs for SubSystem: '<S44>/Enabled Subsystem'

    // Update for Delay: '<S39>/Delay' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_l[0] = HITL_HEXA_Hovering_B.In1_c.x;
    HITL_HEXA_Hovering_DW.Delay_DSTATE_l[1] = HITL_HEXA_Hovering_B.In1_c.y;

    // Update for Gain: '<S44>/Gain1' incorporates:
    //   Delay: '<S44>/Delay'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_n = HITL_HEXA_Hovering_B.In;

    // Update for Delay: '<S45>/Delay' incorporates:
    //   Constant: '<S45>/Constant'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_b =
      HITL_HEXA_Hovering_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S36>/Land'
    break;

   case 2:
    if (HITL_HEXA_Hovering_DW.If_ActiveSubsystem !=
        HITL_HEXA_Hovering_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S36>/Waypoint' incorporates:
      //   ActionPort: '<S41>/Action Port'

      // SystemReset for If: '<S36>/If' incorporates:
      //   MATLABSystem: '<S41>/UAV Waypoint Follower'
      //
      HITL_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
      for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 9;
           HITL_HEXA_Hovering_B.j++) {
        HITL_HEXA_Hovering_DW.obj.WaypointsInternal[HITL_HEXA_Hovering_B.j] *=
          0.0;
      }

      // End of SystemReset for If: '<S36>/If'
      // End of SystemReset for SubSystem: '<S36>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S36>/Waypoint' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Concatenate: '<S41>/Matrix Concatenate'
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[0] =
      HITL_HEXA_Hovering_B.b_startWaypoint[0];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[1] =
      HITL_HEXA_Hovering_B.DataTypeConversion2[0];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[2] =
      HITL_HEXA_Hovering_B.virtualWaypoint[0];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[3] =
      HITL_HEXA_Hovering_B.b_startWaypoint[1];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[4] =
      HITL_HEXA_Hovering_B.DataTypeConversion2[1];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[5] =
      HITL_HEXA_Hovering_B.virtualWaypoint[1];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[6] =
      HITL_HEXA_Hovering_B.b_startWaypoint[2];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[7] =
      HITL_HEXA_Hovering_B.DataTypeConversion2[2];
    HITL_HEXA_Hovering_B.MatrixConcatenate_p[8] =
      HITL_HEXA_Hovering_B.virtualWaypoint[2];

    // MATLABSystem: '<S41>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S41>/Matrix Concatenate'
    //   Constant: '<S41>/Constant'

    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.Constant_Value_gw;
    HITL_HEXA_Hovering_DW.obj.LookaheadDistFlag = 0U;
    if (HITL_HEXA_Hovering_P.Constant_Value_gw < 0.3) {
      HITL_HEXA_Hovering_B.Switch3 = 0.3;
      HITL_HEXA_Hovering_DW.obj.LookaheadDistFlag = 1U;
    }

    HITL_HEXA_Hovering_DW.obj.InitialPose[0] = 0.0;
    HITL_HEXA_Hovering_DW.obj.InitialPose[1] = 0.0;
    HITL_HEXA_Hovering_DW.obj.InitialPose[2] = 0.0;
    HITL_HEXA_Hovering_DW.obj.InitialPose[3] = 0.0;
    HITL_HEXA_Hovering_DW.obj.NumWaypoints = 3.0;
    HITL_HEXA_Hovering_B.b_varargout_1 = false;
    HITL_HEXA_Hovering_B.Compare = true;
    HITL_HEXA_Hovering_B.i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (HITL_HEXA_Hovering_B.i1 <= 8)) {
      HITL_HEXA_Hovering_B.j = HITL_HEXA_Hovering_B.i1 / 3 * 3 +
        HITL_HEXA_Hovering_B.i1 % 3;
      if (!(HITL_HEXA_Hovering_DW.obj.WaypointsInternal[HITL_HEXA_Hovering_B.j] ==
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[HITL_HEXA_Hovering_B.j])) {
        HITL_HEXA_Hovering_B.Compare = false;
        exitg1 = true;
      } else {
        HITL_HEXA_Hovering_B.i1++;
      }
    }

    if (HITL_HEXA_Hovering_B.Compare) {
      HITL_HEXA_Hovering_B.b_varargout_1 = true;
    }

    if (!HITL_HEXA_Hovering_B.b_varargout_1) {
      memcpy(&HITL_HEXA_Hovering_DW.obj.WaypointsInternal[0],
             &HITL_HEXA_Hovering_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      HITL_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    }

    for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 3;
         HITL_HEXA_Hovering_B.j++) {
      HITL_HEXA_Hovering_B.distinctWptsIdx[HITL_HEXA_Hovering_B.j] = true;
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_B.MatrixConcatenate_p[3 * HITL_HEXA_Hovering_B.j + 1];
      HITL_HEXA_Hovering_B.i1 = HITL_HEXA_Hovering_B.j << 1;
      HITL_HEXA_Hovering_B.x[HITL_HEXA_Hovering_B.i1] =
        (HITL_HEXA_Hovering_B.MatrixConcatenate_p[3 * HITL_HEXA_Hovering_B.j] !=
         HITL_HEXA_Hovering_B.rtb_Merge_idx_0);
      HITL_HEXA_Hovering_B.x[HITL_HEXA_Hovering_B.i1 + 1] =
        (HITL_HEXA_Hovering_B.MatrixConcatenate_p[3 * HITL_HEXA_Hovering_B.j + 2]
         != HITL_HEXA_Hovering_B.rtb_Merge_idx_0);
    }

    HITL_HEXA_Hovering_B.IsNaN_l[0] = false;
    HITL_HEXA_Hovering_B.IsNaN_l[1] = false;
    HITL_HEXA_Hovering_B.i1 = 0;
    HITL_HEXA_Hovering_B.i2 = 4;
    for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 2;
         HITL_HEXA_Hovering_B.j++) {
      HITL_HEXA_Hovering_B.i1++;
      HITL_HEXA_Hovering_B.i2++;
      HITL_HEXA_Hovering_B.ix = HITL_HEXA_Hovering_B.i1;
      exitg1 = false;
      while ((!exitg1) && (HITL_HEXA_Hovering_B.ix <= HITL_HEXA_Hovering_B.i2))
      {
        if (HITL_HEXA_Hovering_B.x[HITL_HEXA_Hovering_B.ix - 1]) {
          HITL_HEXA_Hovering_B.IsNaN_l[HITL_HEXA_Hovering_B.j] = true;
          exitg1 = true;
        } else {
          HITL_HEXA_Hovering_B.ix += 2;
        }
      }
    }

    HITL_HEXA_Hovering_B.distinctWptsIdx[0] = HITL_HEXA_Hovering_B.IsNaN_l[0];
    HITL_HEXA_Hovering_B.distinctWptsIdx[1] = HITL_HEXA_Hovering_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S36>/Waypoint'
    HITL_HEXA_Hovering_B.i1 = 0;
    for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 3;
         HITL_HEXA_Hovering_B.j++) {
      // Outputs for IfAction SubSystem: '<S36>/Waypoint' incorporates:
      //   ActionPort: '<S41>/Action Port'

      if (HITL_HEXA_Hovering_B.distinctWptsIdx[HITL_HEXA_Hovering_B.j]) {
        HITL_HEXA_Hovering_B.i1++;
      }

      // End of Outputs for SubSystem: '<S36>/Waypoint'
    }

    HITL_HEXA_Hovering_B.ix = HITL_HEXA_Hovering_B.i1;
    HITL_HEXA_Hovering_B.i1 = 0;
    for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 3;
         HITL_HEXA_Hovering_B.j++) {
      // Outputs for IfAction SubSystem: '<S36>/Waypoint' incorporates:
      //   ActionPort: '<S41>/Action Port'

      if (HITL_HEXA_Hovering_B.distinctWptsIdx[HITL_HEXA_Hovering_B.j]) {
        // Start for MATLABSystem: '<S41>/UAV Waypoint Follower'
        HITL_HEXA_Hovering_B.tmp_data[HITL_HEXA_Hovering_B.i1] =
          static_cast<int8_T>(HITL_HEXA_Hovering_B.j);
        HITL_HEXA_Hovering_B.i1++;
      }

      // End of Outputs for SubSystem: '<S36>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S36>/Waypoint' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // MATLABSystem: '<S41>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S41>/Matrix Concatenate'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Reshape: '<S41>/Reshape1'

    for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 3;
         HITL_HEXA_Hovering_B.j++) {
      for (HITL_HEXA_Hovering_B.i2 = 0; HITL_HEXA_Hovering_B.i2 <
           HITL_HEXA_Hovering_B.ix; HITL_HEXA_Hovering_B.i2++) {
        HITL_HEXA_Hovering_B.b_waypointsIn_data[HITL_HEXA_Hovering_B.i2 +
          HITL_HEXA_Hovering_B.ix * HITL_HEXA_Hovering_B.j] =
          HITL_HEXA_Hovering_B.MatrixConcatenate_p[3 * HITL_HEXA_Hovering_B.j +
          HITL_HEXA_Hovering_B.tmp_data[HITL_HEXA_Hovering_B.i2]];
      }
    }

    HITL_HEXA_Hovering_DW.obj.LookaheadDistance = HITL_HEXA_Hovering_B.Switch3;
    if (HITL_HEXA_Hovering_B.ix == 0) {
      HITL_HEXA_Hovering_B.DataTypeConversion2[0] = HITL_HEXA_Hovering_B.In1_c.x;
      HITL_HEXA_Hovering_B.DataTypeConversion2[1] = HITL_HEXA_Hovering_B.In1_c.y;
      HITL_HEXA_Hovering_B.DataTypeConversion2[2] = HITL_HEXA_Hovering_B.In1_c.z;
      HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_B.In1_c.heading;
    } else {
      guard1 = false;
      if (HITL_HEXA_Hovering_B.ix == 1) {
        if (HITL_HEXA_Hovering_DW.obj.StartFlag) {
          HITL_HEXA_Hovering_DW.obj.InitialPose[0] =
            HITL_HEXA_Hovering_B.In1_c.x;
          HITL_HEXA_Hovering_DW.obj.InitialPose[1] =
            HITL_HEXA_Hovering_B.In1_c.y;
          HITL_HEXA_Hovering_DW.obj.InitialPose[2] =
            HITL_HEXA_Hovering_B.In1_c.z;
          HITL_HEXA_Hovering_DW.obj.InitialPose[3] =
            HITL_HEXA_Hovering_B.In1_c.heading;
        }

        HITL_HEXA_Hovering_B.b_startWaypoint[0] =
          HITL_HEXA_Hovering_B.b_waypointsIn_data[0] -
          HITL_HEXA_Hovering_B.In1_c.x;
        HITL_HEXA_Hovering_B.b_startWaypoint[1] =
          HITL_HEXA_Hovering_B.b_waypointsIn_data[1] -
          HITL_HEXA_Hovering_B.In1_c.y;
        HITL_HEXA_Hovering_B.b_startWaypoint[2] =
          HITL_HEXA_Hovering_B.b_waypointsIn_data[2] -
          HITL_HEXA_Hovering_B.In1_c.z;
        if (HITL_HEXA_Hovering_norm(HITL_HEXA_Hovering_B.b_startWaypoint) <
            1.4901161193847656E-8) {
          HITL_HEXA_Hovering_B.DataTypeConversion2[0] =
            HITL_HEXA_Hovering_B.In1_c.x;
          HITL_HEXA_Hovering_B.DataTypeConversion2[1] =
            HITL_HEXA_Hovering_B.In1_c.y;
          HITL_HEXA_Hovering_B.DataTypeConversion2[2] =
            HITL_HEXA_Hovering_B.In1_c.z;
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3 =
            HITL_HEXA_Hovering_B.In1_c.heading;
          HITL_HEXA_Hovering_DW.obj.StartFlag = false;
        } else {
          HITL_HEXA_Hovering_DW.obj.StartFlag = false;
          HITL_HEXA_Hovering_DW.obj.NumWaypoints = 2.0;
          HITL_HEXA_Hovering_B.i1 = HITL_HEXA_Hovering_B.ix + 1;
          for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 3;
               HITL_HEXA_Hovering_B.j++) {
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(HITL_HEXA_Hovering_B.ix +
              1) * HITL_HEXA_Hovering_B.j] =
              HITL_HEXA_Hovering_DW.obj.InitialPose[HITL_HEXA_Hovering_B.j];
            for (HITL_HEXA_Hovering_B.i2 = 0; HITL_HEXA_Hovering_B.i2 <
                 HITL_HEXA_Hovering_B.ix; HITL_HEXA_Hovering_B.i2++) {
              HITL_HEXA_Hovering_B.MatrixConcatenate_p[(HITL_HEXA_Hovering_B.i2
                + (HITL_HEXA_Hovering_B.ix + 1) * HITL_HEXA_Hovering_B.j) + 1] =
                HITL_HEXA_Hovering_B.b_waypointsIn_data[HITL_HEXA_Hovering_B.ix *
                HITL_HEXA_Hovering_B.j + HITL_HEXA_Hovering_B.i2];
            }
          }

          guard1 = true;
        }
      } else {
        HITL_HEXA_Hovering_B.i1 = HITL_HEXA_Hovering_B.ix;
        HITL_HEXA_Hovering_B.i2 = HITL_HEXA_Hovering_B.ix * 3;
        if (HITL_HEXA_Hovering_B.i2 - 1 >= 0) {
          memcpy(&HITL_HEXA_Hovering_B.MatrixConcatenate_p[0],
                 &HITL_HEXA_Hovering_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(HITL_HEXA_Hovering_B.i2) * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        HITL_HEXA_Hovering_B.b_varargout_1 = false;
        if (HITL_HEXA_Hovering_DW.obj.WaypointIndex ==
            HITL_HEXA_Hovering_DW.obj.NumWaypoints) {
          HITL_HEXA_Hovering_B.b_varargout_1 = true;
        }

        if (HITL_HEXA_Hovering_B.b_varargout_1) {
          HITL_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
          HITL_HEXA_Hovering_DW.obj.WaypointIndex--;
        }

        HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.MatrixConcatenate_p[
          static_cast<int32_T>(HITL_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
        HITL_HEXA_Hovering_B.b_startWaypoint[0] = HITL_HEXA_Hovering_B.Switch3;
        HITL_HEXA_Hovering_B.Subtract_f =
          HITL_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
        HITL_HEXA_Hovering_B.DataTypeConversion2[0] =
          HITL_HEXA_Hovering_B.Subtract_f;
        HITL_HEXA_Hovering_B.virtualWaypoint[0] = HITL_HEXA_Hovering_B.In1_c.x -
          HITL_HEXA_Hovering_B.Subtract_f;
        HITL_HEXA_Hovering_B.b_startWaypoint[1] =
          HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (HITL_HEXA_Hovering_DW.obj.WaypointIndex) + HITL_HEXA_Hovering_B.i1) -
          1];
        HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
          HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          HITL_HEXA_Hovering_B.i1) - 1];
        HITL_HEXA_Hovering_B.DataTypeConversion2[1] =
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        HITL_HEXA_Hovering_B.virtualWaypoint[1] = HITL_HEXA_Hovering_B.In1_c.y -
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        HITL_HEXA_Hovering_B.b_startWaypoint[2] =
          HITL_HEXA_Hovering_B.MatrixConcatenate_p[((HITL_HEXA_Hovering_B.i1 <<
          1) + static_cast<int32_T>(HITL_HEXA_Hovering_DW.obj.WaypointIndex)) -
          1];
        HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
          HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          (HITL_HEXA_Hovering_B.i1 << 1)) - 1];
        HITL_HEXA_Hovering_B.DataTypeConversion2[2] =
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        HITL_HEXA_Hovering_B.virtualWaypoint[2] = HITL_HEXA_Hovering_B.In1_c.z -
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_norm
          (HITL_HEXA_Hovering_B.virtualWaypoint);
        guard2 = false;
        if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <= 2.0) {
          guard2 = true;
        } else {
          HITL_HEXA_Hovering_B.lla0[0] = HITL_HEXA_Hovering_B.Subtract_f -
            HITL_HEXA_Hovering_B.Switch3;
          HITL_HEXA_Hovering_B.lla0[1] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            HITL_HEXA_Hovering_B.i1) - 1] -
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex) + HITL_HEXA_Hovering_B.i1)
            - 1];
          HITL_HEXA_Hovering_B.Switch3 =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (HITL_HEXA_Hovering_B.i1 << 1)) - 1];
          HITL_HEXA_Hovering_B.lla0[2] = HITL_HEXA_Hovering_B.Switch3 -
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[((HITL_HEXA_Hovering_B.i1 <<
            1) + static_cast<int32_T>(HITL_HEXA_Hovering_DW.obj.WaypointIndex))
            - 1];
          HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_norm
            (HITL_HEXA_Hovering_B.lla0);
          HITL_HEXA_Hovering_B.Switch3 = ((HITL_HEXA_Hovering_B.In1_c.x -
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1]) /
            HITL_HEXA_Hovering_B.rtb_Merge_idx_0 * (HITL_HEXA_Hovering_B.lla0[0]
            / HITL_HEXA_Hovering_B.Subtract_f) + HITL_HEXA_Hovering_B.lla0[1] /
            HITL_HEXA_Hovering_B.Subtract_f *
            (HITL_HEXA_Hovering_B.virtualWaypoint[1] /
             HITL_HEXA_Hovering_B.rtb_Merge_idx_0)) +
            (HITL_HEXA_Hovering_B.In1_c.z - HITL_HEXA_Hovering_B.Switch3) /
            HITL_HEXA_Hovering_B.rtb_Merge_idx_0 * (HITL_HEXA_Hovering_B.lla0[2]
            / HITL_HEXA_Hovering_B.Subtract_f);
          if (rtIsNaN(HITL_HEXA_Hovering_B.Switch3) ||
              (HITL_HEXA_Hovering_B.Switch3 < 0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          HITL_HEXA_Hovering_DW.obj.WaypointIndex++;
          HITL_HEXA_Hovering_B.b_varargout_1 = false;
          if (HITL_HEXA_Hovering_DW.obj.WaypointIndex ==
              HITL_HEXA_Hovering_DW.obj.NumWaypoints) {
            HITL_HEXA_Hovering_B.b_varargout_1 = true;
          }

          if (HITL_HEXA_Hovering_B.b_varargout_1) {
            HITL_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
            HITL_HEXA_Hovering_DW.obj.WaypointIndex--;
          }

          HITL_HEXA_Hovering_B.b_startWaypoint[0] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
          HITL_HEXA_Hovering_B.DataTypeConversion2[0] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
          HITL_HEXA_Hovering_B.b_startWaypoint[1] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex) + HITL_HEXA_Hovering_B.i1)
            - 1];
          HITL_HEXA_Hovering_B.DataTypeConversion2[1] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            HITL_HEXA_Hovering_B.i1) - 1];
          HITL_HEXA_Hovering_B.b_startWaypoint[2] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[((HITL_HEXA_Hovering_B.i1 <<
            1) + static_cast<int32_T>(HITL_HEXA_Hovering_DW.obj.WaypointIndex))
            - 1];
          HITL_HEXA_Hovering_B.DataTypeConversion2[2] =
            HITL_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (HITL_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (HITL_HEXA_Hovering_B.i1 << 1)) - 1];
        }

        HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.In1_c.x -
          HITL_HEXA_Hovering_B.b_startWaypoint[0];
        HITL_HEXA_Hovering_B.virtualWaypoint[0] =
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.DataTypeConversion2
          [0] - HITL_HEXA_Hovering_B.b_startWaypoint[0];
        HITL_HEXA_Hovering_B.virtualWaypoint_tmp = HITL_HEXA_Hovering_B.In1_c.y
          - HITL_HEXA_Hovering_B.b_startWaypoint[1];
        HITL_HEXA_Hovering_B.virtualWaypoint[1] =
          HITL_HEXA_Hovering_B.virtualWaypoint_tmp;
        HITL_HEXA_Hovering_B.Switch_m =
          HITL_HEXA_Hovering_B.DataTypeConversion2[1] -
          HITL_HEXA_Hovering_B.b_startWaypoint[1];
        HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_B.In1_c.z -
          HITL_HEXA_Hovering_B.b_startWaypoint[2];
        HITL_HEXA_Hovering_B.virtualWaypoint[2] =
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3;
        HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.DataTypeConversion2
          [2] - HITL_HEXA_Hovering_B.b_startWaypoint[2];
        HITL_HEXA_Hovering_B.Subtract_f = (HITL_HEXA_Hovering_B.Switch_m *
          HITL_HEXA_Hovering_B.Switch_m + HITL_HEXA_Hovering_B.Switch3 *
          HITL_HEXA_Hovering_B.Switch3) + HITL_HEXA_Hovering_B.Switch4 *
          HITL_HEXA_Hovering_B.Switch4;
        HITL_HEXA_Hovering_B.rtb_Merge_idx_3 =
          ((HITL_HEXA_Hovering_B.virtualWaypoint_tmp *
            HITL_HEXA_Hovering_B.Switch_m + HITL_HEXA_Hovering_B.rtb_Merge_idx_0
            * HITL_HEXA_Hovering_B.Switch3) +
           HITL_HEXA_Hovering_B.rtb_Merge_idx_3 * HITL_HEXA_Hovering_B.Switch4) /
          HITL_HEXA_Hovering_B.Subtract_f;
        if (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 < 0.0) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_norm
            (HITL_HEXA_Hovering_B.virtualWaypoint);
        } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 > 1.0) {
          HITL_HEXA_Hovering_B.virtualWaypoint[0] = HITL_HEXA_Hovering_B.In1_c.x
            - HITL_HEXA_Hovering_B.DataTypeConversion2[0];
          HITL_HEXA_Hovering_B.virtualWaypoint[1] = HITL_HEXA_Hovering_B.In1_c.y
            - HITL_HEXA_Hovering_B.DataTypeConversion2[1];
          HITL_HEXA_Hovering_B.virtualWaypoint[2] = HITL_HEXA_Hovering_B.In1_c.z
            - HITL_HEXA_Hovering_B.DataTypeConversion2[2];
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_norm
            (HITL_HEXA_Hovering_B.virtualWaypoint);
        } else {
          HITL_HEXA_Hovering_B.virtualWaypoint[0] = HITL_HEXA_Hovering_B.In1_c.x
            - (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 *
               HITL_HEXA_Hovering_B.Switch3 +
               HITL_HEXA_Hovering_B.b_startWaypoint[0]);
          HITL_HEXA_Hovering_B.virtualWaypoint[1] = HITL_HEXA_Hovering_B.In1_c.y
            - (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 *
               HITL_HEXA_Hovering_B.Switch_m +
               HITL_HEXA_Hovering_B.b_startWaypoint[1]);
          HITL_HEXA_Hovering_B.virtualWaypoint[2] = HITL_HEXA_Hovering_B.In1_c.z
            - (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 *
               HITL_HEXA_Hovering_B.Switch4 +
               HITL_HEXA_Hovering_B.b_startWaypoint[2]);
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_norm
            (HITL_HEXA_Hovering_B.virtualWaypoint);
        }

        if (HITL_HEXA_Hovering_DW.obj.LastWaypointFlag) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3 =
            ((HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *
              HITL_HEXA_Hovering_B.Switch3 +
              HITL_HEXA_Hovering_B.virtualWaypoint_tmp *
              HITL_HEXA_Hovering_B.Switch_m) + (HITL_HEXA_Hovering_B.In1_c.z -
              HITL_HEXA_Hovering_B.b_startWaypoint[2]) *
             HITL_HEXA_Hovering_B.Switch4) / HITL_HEXA_Hovering_B.Subtract_f;
          HITL_HEXA_Hovering_B.virtualWaypoint[0] = HITL_HEXA_Hovering_B.In1_c.x
            - (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 *
               HITL_HEXA_Hovering_B.Switch3 +
               HITL_HEXA_Hovering_B.b_startWaypoint[0]);
          HITL_HEXA_Hovering_B.virtualWaypoint[1] = HITL_HEXA_Hovering_B.In1_c.y
            - (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 *
               HITL_HEXA_Hovering_B.Switch_m +
               HITL_HEXA_Hovering_B.b_startWaypoint[1]);
          HITL_HEXA_Hovering_B.virtualWaypoint[2] = HITL_HEXA_Hovering_B.In1_c.z
            - (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 *
               HITL_HEXA_Hovering_B.Switch4 +
               HITL_HEXA_Hovering_B.b_startWaypoint[2]);
          HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_norm
            (HITL_HEXA_Hovering_B.virtualWaypoint);
        }

        HITL_HEXA_Hovering_B.virtualWaypoint_tmp = fabs
          (HITL_HEXA_Hovering_B.rtb_Merge_idx_3);
        if (rtIsInf(HITL_HEXA_Hovering_B.virtualWaypoint_tmp) || rtIsNaN
            (HITL_HEXA_Hovering_B.virtualWaypoint_tmp)) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
          HITL_HEXA_Hovering_B.virtualWaypoint_tmp = (rtNaN);
        } else if (HITL_HEXA_Hovering_B.virtualWaypoint_tmp <
                   4.4501477170144028E-308) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = 4.94065645841247E-324;
          HITL_HEXA_Hovering_B.virtualWaypoint_tmp = 4.94065645841247E-324;
        } else {
          frexp(HITL_HEXA_Hovering_B.virtualWaypoint_tmp,
                &HITL_HEXA_Hovering_B.ParamStep_k);
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = ldexp(1.0,
            HITL_HEXA_Hovering_B.ParamStep_k - 53);
          frexp(HITL_HEXA_Hovering_B.virtualWaypoint_tmp,
                &HITL_HEXA_Hovering_B.b_exponent);
          HITL_HEXA_Hovering_B.virtualWaypoint_tmp = ldexp(1.0,
            HITL_HEXA_Hovering_B.b_exponent - 53);
        }

        HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = sqrt
          (HITL_HEXA_Hovering_B.rtb_Merge_idx_0);
        HITL_HEXA_Hovering_B.virtualWaypoint_tmp *= 5.0;
        if ((HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >=
             HITL_HEXA_Hovering_B.virtualWaypoint_tmp) || rtIsNaN
            (HITL_HEXA_Hovering_B.virtualWaypoint_tmp)) {
          HITL_HEXA_Hovering_B.virtualWaypoint_tmp =
            HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        }

        if (HITL_HEXA_Hovering_DW.obj.LookaheadDistance <=
            HITL_HEXA_Hovering_B.rtb_Merge_idx_3 +
            HITL_HEXA_Hovering_B.virtualWaypoint_tmp) {
          HITL_HEXA_Hovering_DW.obj.LookaheadDistance =
            HITL_HEXA_Hovering_DW.obj.LookaheadFactor *
            HITL_HEXA_Hovering_B.rtb_Merge_idx_3;
        }

        HITL_HEXA_Hovering_B.lla0[0] = HITL_HEXA_Hovering_B.b_startWaypoint[0] -
          HITL_HEXA_Hovering_B.In1_c.x;
        HITL_HEXA_Hovering_B.lla0[1] = HITL_HEXA_Hovering_B.b_startWaypoint[1] -
          HITL_HEXA_Hovering_B.In1_c.y;
        HITL_HEXA_Hovering_B.lla0[2] = HITL_HEXA_Hovering_B.b_startWaypoint[2] -
          HITL_HEXA_Hovering_B.In1_c.z;
        HITL_HEXA_Hovering_B.Switch3 = ((HITL_HEXA_Hovering_B.Switch3 *
          HITL_HEXA_Hovering_B.lla0[0] + HITL_HEXA_Hovering_B.Switch_m *
          HITL_HEXA_Hovering_B.lla0[1]) + HITL_HEXA_Hovering_B.Switch4 *
          HITL_HEXA_Hovering_B.lla0[2]) * 2.0;
        HITL_HEXA_Hovering_B.Switch_m = sqrt(HITL_HEXA_Hovering_B.Switch3 *
          HITL_HEXA_Hovering_B.Switch3 - (((HITL_HEXA_Hovering_B.lla0[0] *
          HITL_HEXA_Hovering_B.lla0[0] + HITL_HEXA_Hovering_B.lla0[1] *
          HITL_HEXA_Hovering_B.lla0[1]) + HITL_HEXA_Hovering_B.lla0[2] *
          HITL_HEXA_Hovering_B.lla0[2]) -
          HITL_HEXA_Hovering_DW.obj.LookaheadDistance *
          HITL_HEXA_Hovering_DW.obj.LookaheadDistance) * (4.0 *
          HITL_HEXA_Hovering_B.Subtract_f));
        HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (-HITL_HEXA_Hovering_B.Switch3 +
          HITL_HEXA_Hovering_B.Switch_m) / 2.0 / HITL_HEXA_Hovering_B.Subtract_f;
        HITL_HEXA_Hovering_B.Switch3 = (-HITL_HEXA_Hovering_B.Switch3 -
          HITL_HEXA_Hovering_B.Switch_m) / 2.0 / HITL_HEXA_Hovering_B.Subtract_f;
        if ((HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >=
             HITL_HEXA_Hovering_B.Switch3) || rtIsNaN
            (HITL_HEXA_Hovering_B.Switch3)) {
          HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
        }

        HITL_HEXA_Hovering_B.DataTypeConversion2[0] = (1.0 -
          HITL_HEXA_Hovering_B.Switch3) * HITL_HEXA_Hovering_B.b_startWaypoint[0]
          + HITL_HEXA_Hovering_B.Switch3 *
          HITL_HEXA_Hovering_B.DataTypeConversion2[0];
        HITL_HEXA_Hovering_B.DataTypeConversion2[1] = (1.0 -
          HITL_HEXA_Hovering_B.Switch3) * HITL_HEXA_Hovering_B.b_startWaypoint[1]
          + HITL_HEXA_Hovering_B.Switch3 *
          HITL_HEXA_Hovering_B.DataTypeConversion2[1];
        HITL_HEXA_Hovering_B.DataTypeConversion2[2] = (1.0 -
          HITL_HEXA_Hovering_B.Switch3) * HITL_HEXA_Hovering_B.b_startWaypoint[2]
          + HITL_HEXA_Hovering_B.Switch3 *
          HITL_HEXA_Hovering_B.DataTypeConversion2[2];
        HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_rt_atan2d_snf
          (HITL_HEXA_Hovering_B.DataTypeConversion2[1] -
           HITL_HEXA_Hovering_B.In1_c.y,
           HITL_HEXA_Hovering_B.DataTypeConversion2[0] -
           HITL_HEXA_Hovering_B.In1_c.x);
        HITL_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S51>/Switch1' incorporates:
    //   Constant: '<S52>/Constant'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Logic: '<S51>/OR'
    //   Logic: '<S51>/OR1'
    //   MATLABSystem: '<S41>/UAV Waypoint Follower'
    //   Merge: '<S36>/Merge'
    //   RelationalOperator: '<S51>/IsNaN'
    //   RelationalOperator: '<S51>/IsNaN1'
    //   RelationalOperator: '<S52>/Compare'
    //   Switch: '<S51>/Switch'
    //
    if (rtIsNaN(HITL_HEXA_Hovering_B.DataTypeConversion2[0]) || rtIsNaN
        (HITL_HEXA_Hovering_B.DataTypeConversion2[1]) || rtIsNaN
        (HITL_HEXA_Hovering_B.DataTypeConversion2[2]) ||
        (HITL_HEXA_Hovering_B.In1_p.current.type ==
         HITL_HEXA_Hovering_P.CompareToConstant_const_d)) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.In1_c.x;
      HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.In1_c.y;
      HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.In1_c.z;
      HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_B.In1_c.heading;
    } else {
      if (rtIsNaN(HITL_HEXA_Hovering_B.rtb_Merge_idx_3)) {
        // Switch: '<S51>/Switch' incorporates:
        //   Constant: '<S51>/Constant'
        //   Merge: '<S36>/Merge'
        //   Reshape: '<S51>/Reshape2'

        HITL_HEXA_Hovering_B.rtb_Merge_idx_3 =
          HITL_HEXA_Hovering_P.Constant_Value_jd;
      }

      // Math: '<S51>/Transpose1' incorporates:
      //   Merge: '<S36>/Merge'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_B.DataTypeConversion2[0];
      HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.DataTypeConversion2[1];
      HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.DataTypeConversion2[2];
    }

    // End of Switch: '<S51>/Switch1'
    // End of Outputs for SubSystem: '<S36>/Waypoint'
    break;

   default:
    if (HITL_HEXA_Hovering_DW.If_ActiveSubsystem !=
        HITL_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S36>/IDLE' incorporates:
      //   ActionPort: '<S38>/Action Port'

      // InitializeConditions for If: '<S36>/If' incorporates:
      //   Delay: '<S42>/Delay'

      HITL_HEXA_Hovering_DW.Delay_DSTATE =
        HITL_HEXA_Hovering_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S36>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S36>/IDLE' incorporates:
    //   ActionPort: '<S38>/Action Port'

    // Outputs for Enabled SubSystem: '<S42>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S43>/Enable'

    if (HITL_HEXA_Hovering_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S43>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      HITL_HEXA_Hovering_B.yaw_In = HITL_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S42>/Enabled Subsystem2'

    // Reshape: '<S38>/Reshape1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Delay: '<S42>/Delay'
    //   Merge: '<S36>/Merge'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.In1_c.x;
    HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.In1_c.y;
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.In1_c.z;
    HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = HITL_HEXA_Hovering_B.yaw_In;

    // Update for Delay: '<S42>/Delay' incorporates:
    //   Constant: '<S42>/Constant'

    HITL_HEXA_Hovering_DW.Delay_DSTATE = HITL_HEXA_Hovering_P.Constant_Value_ic;

    // End of Outputs for SubSystem: '<S36>/IDLE'
    break;
  }

  // End of If: '<S36>/If'

  // Outputs for Enabled SubSystem: '<S4>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S75>/Enable'

  if (HITL_HEXA_Hovering_B.In1_bs.armed) {
    // Trigonometry: '<S340>/SinCos'
    HITL_HEXA_Hovering_B.Switch_m = sin(HITL_HEXA_Hovering_B.VectorConcatenate[0]);
    HITL_HEXA_Hovering_B.Subtract_f = cos
      (HITL_HEXA_Hovering_B.VectorConcatenate[0]);

    // Sum: '<S75>/Sum5'
    HITL_HEXA_Hovering_B.rtb_Merge_idx_3 -=
      HITL_HEXA_Hovering_B.VectorConcatenate[0];

    // Saturate: '<S438>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S436>/Proportional Gain'
    //   Sum: '<S75>/Sum1'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (HITL_HEXA_Hovering_B.rtb_Merge_idx_0
      - HITL_HEXA_Hovering_B.In1_c.x) * HITL_HEXA_Hovering_P.PIDController1_P_f;
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h;
    }

    // Sum: '<S75>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S438>/Saturation'

    HITL_HEXA_Hovering_B.virtualWaypoint_tmp =
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 - HITL_HEXA_Hovering_B.In1_c.vx;

    // Saturate: '<S438>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S436>/Proportional Gain'
    //   Sum: '<S75>/Sum1'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (HITL_HEXA_Hovering_B.Switch4 -
      HITL_HEXA_Hovering_B.In1_c.y) * HITL_HEXA_Hovering_P.PIDController1_P_f;
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_e;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_h;
    }

    // Sum: '<S75>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S438>/Saturation'

    HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.rtb_Merge_idx_0 -
      HITL_HEXA_Hovering_B.In1_c.vy;

    // Saturate: '<S388>/Saturation' incorporates:
    //   Gain: '<S340>/Gain'
    //   Gain: '<S386>/Proportional Gain'
    //   Product: '<S75>/MatrixMultiply'
    //   Reshape: '<S340>/Reshape'
    //   Reshape: '<S340>/Reshape1'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (HITL_HEXA_Hovering_B.Subtract_f *
      HITL_HEXA_Hovering_B.virtualWaypoint_tmp + HITL_HEXA_Hovering_B.Switch_m *
      HITL_HEXA_Hovering_B.Switch4) * HITL_HEXA_Hovering_P.PIDController_P_b;
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e) {
      // Saturate: '<S388>/Saturation'
      HITL_HEXA_Hovering_B.Saturation[0] =
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o) {
      // Saturate: '<S388>/Saturation'
      HITL_HEXA_Hovering_B.Saturation[0] =
        HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o;
    } else {
      // Saturate: '<S388>/Saturation'
      HITL_HEXA_Hovering_B.Saturation[0] = HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (HITL_HEXA_Hovering_P.Gain_Gain_a *
      HITL_HEXA_Hovering_B.Switch_m * HITL_HEXA_Hovering_B.virtualWaypoint_tmp +
      HITL_HEXA_Hovering_B.Subtract_f * HITL_HEXA_Hovering_B.Switch4) *
      HITL_HEXA_Hovering_P.PIDController_P_b;
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e) {
      // Saturate: '<S388>/Saturation'
      HITL_HEXA_Hovering_B.Saturation[1] =
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit_e;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o) {
      // Saturate: '<S388>/Saturation'
      HITL_HEXA_Hovering_B.Saturation[1] =
        HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit_o;
    } else {
      // Saturate: '<S388>/Saturation'
      HITL_HEXA_Hovering_B.Saturation[1] = HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    // End of Saturate: '<S388>/Saturation'

    // Gain: '<S75>/Gain1'
    HITL_HEXA_Hovering_B.Gain1 = HITL_HEXA_Hovering_P.Gain1_Gain_ad *
      HITL_HEXA_Hovering_B.Saturation[0];

    // Switch: '<S341>/Switch' incorporates:
    //   Abs: '<S341>/Abs'

    if (fabs(HITL_HEXA_Hovering_B.rtb_Merge_idx_3) >
        HITL_HEXA_Hovering_P.Switch_Threshold_p) {
      // Switch: '<S341>/Switch1' incorporates:
      //   Constant: '<S341>/Constant'
      //   Sum: '<S341>/Add'
      //   Sum: '<S341>/Subtract'

      if (HITL_HEXA_Hovering_B.rtb_Merge_idx_3 >
          HITL_HEXA_Hovering_P.Switch1_Threshold) {
        HITL_HEXA_Hovering_B.rtb_Merge_idx_3 -=
          HITL_HEXA_Hovering_P.Constant_Value_p;
      } else {
        HITL_HEXA_Hovering_B.rtb_Merge_idx_3 +=
          HITL_HEXA_Hovering_P.Constant_Value_p;
      }

      // End of Switch: '<S341>/Switch1'
    }

    // Gain: '<S486>/Proportional Gain' incorporates:
    //   Switch: '<S341>/Switch'

    HITL_HEXA_Hovering_B.Saturation_e = HITL_HEXA_Hovering_P.PIDController5_P *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Saturate: '<S488>/Saturation'
    if (HITL_HEXA_Hovering_B.Saturation_e >
        HITL_HEXA_Hovering_P.PIDController5_UpperSaturationLimit) {
      // Gain: '<S486>/Proportional Gain' incorporates:
      //   Saturate: '<S488>/Saturation'

      HITL_HEXA_Hovering_B.Saturation_e =
        HITL_HEXA_Hovering_P.PIDController5_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.Saturation_e <
               HITL_HEXA_Hovering_P.PIDController5_LowerSaturationLimit) {
      // Gain: '<S486>/Proportional Gain' incorporates:
      //   Saturate: '<S488>/Saturation'

      HITL_HEXA_Hovering_B.Saturation_e =
        HITL_HEXA_Hovering_P.PIDController5_LowerSaturationLimit;
    }

    // End of Saturate: '<S488>/Saturation'

    // Gain: '<S339>/Gain1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_P.Gain1_Gain_j *
      HITL_HEXA_Hovering_B.In1_c.z;

    // Switch: '<S347>/Switch' incorporates:
    //   Constant: '<S339>/Constant'
    //   RelationalOperator: '<S347>/UpperRelop'
    //   Switch: '<S347>/Switch2'

    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
        HITL_HEXA_Hovering_P.Constant_Value_a) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant_Value_a;
    }

    // Sum: '<S75>/Sum2' incorporates:
    //   Gain: '<S4>/Gain'
    //   Switch: '<S347>/Switch'
    //   Switch: '<S347>/Switch2'

    HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_P.Gain_Gain_k1 *
      HITL_HEXA_Hovering_B.Switch3 - HITL_HEXA_Hovering_B.rtb_Merge_idx_0;

    // Gain: '<S538>/Proportional Gain'
    HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_P.PID_Altitude_P *
      HITL_HEXA_Hovering_B.Switch_m;

    // Gain: '<S536>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S528>/Filter'
    //   Gain: '<S526>/Derivative Gain'
    //   Sum: '<S528>/SumD'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_3 = (HITL_HEXA_Hovering_P.PID_Altitude_D *
      HITL_HEXA_Hovering_B.Switch_m - HITL_HEXA_Hovering_DW.Filter_DSTATE) *
      HITL_HEXA_Hovering_P.PID_Altitude_N;

    // Sum: '<S543>/Sum Fdbk'
    HITL_HEXA_Hovering_B.Switch3 = (HITL_HEXA_Hovering_B.Subtract_f +
      HITL_HEXA_Hovering_DW.Integrator_DSTATE) +
      HITL_HEXA_Hovering_B.rtb_Merge_idx_3;

    // DeadZone: '<S525>/DeadZone'
    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch3 -=
        HITL_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.Switch3 >=
               HITL_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch3 = 0.0;
    } else {
      HITL_HEXA_Hovering_B.Switch3 -=
        HITL_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // End of DeadZone: '<S525>/DeadZone'

    // Gain: '<S530>/Integral Gain'
    HITL_HEXA_Hovering_B.Switch_m *= HITL_HEXA_Hovering_P.PID_Altitude_I;

    // Switch: '<S523>/Switch1' incorporates:
    //   Constant: '<S523>/Clamping_zero'
    //   Constant: '<S523>/Constant'
    //   Constant: '<S523>/Constant2'
    //   RelationalOperator: '<S523>/fix for DT propagation issue'

    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_o) {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant_Value_n1;
    } else {
      HITL_HEXA_Hovering_B.rtPrevAction =
        HITL_HEXA_Hovering_P.Constant2_Value_gq;
    }

    // Switch: '<S523>/Switch2' incorporates:
    //   Constant: '<S523>/Clamping_zero'
    //   Constant: '<S523>/Constant3'
    //   Constant: '<S523>/Constant4'
    //   RelationalOperator: '<S523>/fix for DT propagation issue1'

    if (HITL_HEXA_Hovering_B.Switch_m >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_o) {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant3_Value_i;
    } else {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant4_Value_h;
    }

    // Switch: '<S523>/Switch' incorporates:
    //   Constant: '<S523>/Clamping_zero'
    //   Constant: '<S523>/Constant1'
    //   Logic: '<S523>/AND3'
    //   RelationalOperator: '<S523>/Equal1'
    //   RelationalOperator: '<S523>/Relational Operator'
    //   Switch: '<S523>/Switch1'
    //   Switch: '<S523>/Switch2'

    if ((HITL_HEXA_Hovering_P.Clamping_zero_Value_o !=
         HITL_HEXA_Hovering_B.Switch3) && (HITL_HEXA_Hovering_B.rtPrevAction ==
         HITL_HEXA_Hovering_B.i2_b)) {
      HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_P.Constant1_Value_cc;
    }

    // DiscreteIntegrator: '<S533>/Integrator' incorporates:
    //   Switch: '<S523>/Switch'

    HITL_HEXA_Hovering_DW.Integrator_DSTATE +=
      HITL_HEXA_Hovering_P.Integrator_gainval_p4 * HITL_HEXA_Hovering_B.Switch_m;

    // Sum: '<S542>/Sum'
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (HITL_HEXA_Hovering_B.Subtract_f +
      HITL_HEXA_Hovering_DW.Integrator_DSTATE) +
      HITL_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Saturate: '<S540>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // Sum: '<S75>/Sum3' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S540>/Saturation'
    //   UnaryMinus: '<S75>/Unary Minus'

    HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_B.rtb_Merge_idx_0 - (-
      static_cast<real_T>(HITL_HEXA_Hovering_B.In1_c.vz));

    // Gain: '<S590>/Proportional Gain'
    HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_P.PID_vz_P *
      HITL_HEXA_Hovering_B.Subtract_f;

    // Gain: '<S588>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S580>/Filter'
    //   Gain: '<S578>/Derivative Gain'
    //   Sum: '<S580>/SumD'

    HITL_HEXA_Hovering_B.Switch3 = (HITL_HEXA_Hovering_P.PID_vz_D *
      HITL_HEXA_Hovering_B.Subtract_f - HITL_HEXA_Hovering_DW.Filter_DSTATE_n) *
      HITL_HEXA_Hovering_P.PID_vz_N;

    // Sum: '<S595>/Sum Fdbk'
    HITL_HEXA_Hovering_B.Switch4 = (HITL_HEXA_Hovering_B.Switch_m +
      HITL_HEXA_Hovering_DW.Integrator_DSTATE_c) + HITL_HEXA_Hovering_B.Switch3;

    // DeadZone: '<S577>/DeadZone'
    if (HITL_HEXA_Hovering_B.Switch4 >
        HITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch4 -=
        HITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.Switch4 >=
               HITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch4 = 0.0;
    } else {
      HITL_HEXA_Hovering_B.Switch4 -=
        HITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S577>/DeadZone'

    // Gain: '<S582>/Integral Gain'
    HITL_HEXA_Hovering_B.Subtract_f *= HITL_HEXA_Hovering_P.PID_vz_I;

    // Switch: '<S575>/Switch1' incorporates:
    //   Constant: '<S575>/Clamping_zero'
    //   Constant: '<S575>/Constant'
    //   Constant: '<S575>/Constant2'
    //   RelationalOperator: '<S575>/fix for DT propagation issue'

    if (HITL_HEXA_Hovering_B.Switch4 >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_bl) {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant_Value_gf;
    } else {
      HITL_HEXA_Hovering_B.rtPrevAction =
        HITL_HEXA_Hovering_P.Constant2_Value_ga;
    }

    // Switch: '<S575>/Switch2' incorporates:
    //   Constant: '<S575>/Clamping_zero'
    //   Constant: '<S575>/Constant3'
    //   Constant: '<S575>/Constant4'
    //   RelationalOperator: '<S575>/fix for DT propagation issue1'

    if (HITL_HEXA_Hovering_B.Subtract_f >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_bl) {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant3_Value_b;
    } else {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant4_Value_fv;
    }

    // Switch: '<S575>/Switch' incorporates:
    //   Constant: '<S575>/Clamping_zero'
    //   Constant: '<S575>/Constant1'
    //   Logic: '<S575>/AND3'
    //   RelationalOperator: '<S575>/Equal1'
    //   RelationalOperator: '<S575>/Relational Operator'
    //   Switch: '<S575>/Switch1'
    //   Switch: '<S575>/Switch2'

    if ((HITL_HEXA_Hovering_P.Clamping_zero_Value_bl !=
         HITL_HEXA_Hovering_B.Switch4) && (HITL_HEXA_Hovering_B.rtPrevAction ==
         HITL_HEXA_Hovering_B.i2_b)) {
      HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_P.Constant1_Value_f;
    }

    // DiscreteIntegrator: '<S585>/Integrator' incorporates:
    //   Switch: '<S575>/Switch'

    HITL_HEXA_Hovering_DW.Integrator_DSTATE_c +=
      HITL_HEXA_Hovering_P.Integrator_gainval_ik *
      HITL_HEXA_Hovering_B.Subtract_f;

    // Sum: '<S594>/Sum'
    HITL_HEXA_Hovering_B.Saturation_f = (HITL_HEXA_Hovering_B.Switch_m +
      HITL_HEXA_Hovering_DW.Integrator_DSTATE_c) + HITL_HEXA_Hovering_B.Switch3;

    // Saturate: '<S592>/Saturation'
    if (HITL_HEXA_Hovering_B.Saturation_f >
        HITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      // Sum: '<S594>/Sum' incorporates:
      //   Saturate: '<S592>/Saturation'

      HITL_HEXA_Hovering_B.Saturation_f =
        HITL_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.Saturation_f <
               HITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      // Sum: '<S594>/Sum' incorporates:
      //   Saturate: '<S592>/Saturation'

      HITL_HEXA_Hovering_B.Saturation_f =
        HITL_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of Saturate: '<S592>/Saturation'

    // Update for DiscreteIntegrator: '<S528>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE += HITL_HEXA_Hovering_P.Filter_gainval_i
      * HITL_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Update for DiscreteIntegrator: '<S580>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_n +=
      HITL_HEXA_Hovering_P.Filter_gainval_d * HITL_HEXA_Hovering_B.Switch3;
  }

  // End of Outputs for SubSystem: '<S4>/Position & Altitude controller'

  // Chart: '<S4>/Chart'
  if (HITL_HEXA_Hovering_DW.is_active_c3_HITL_HEXA_Hovering == 0U) {
    HITL_HEXA_Hovering_DW.is_active_c3_HITL_HEXA_Hovering = 1U;
    HITL_HEXA_Hovering_DW.is_c3_HITL_HEXA_Hovering =
      HITL_HEXA_Hovering_IN_STABLIZED;
  } else if (HITL_HEXA_Hovering_DW.is_c3_HITL_HEXA_Hovering ==
             HITL_HEXA_Hovering_IN_MISSION) {
    if (HITL_HEXA_Hovering_B.In1_j.values[5] <= 1400) {
      HITL_HEXA_Hovering_DW.is_c3_HITL_HEXA_Hovering =
        HITL_HEXA_Hovering_IN_STABLIZED;
    } else {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 =
        HITL_HEXA_Hovering_B.Saturation_e;
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = HITL_HEXA_Hovering_B.Gain1;
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 =
        HITL_HEXA_Hovering_B.Saturation[1];
      HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_B.Saturation_f;
    }

    // case IN_STABLIZED:
  } else if (HITL_HEXA_Hovering_B.In1_j.values[5] > 1400) {
    HITL_HEXA_Hovering_DW.is_c3_HITL_HEXA_Hovering =
      HITL_HEXA_Hovering_IN_MISSION;
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = HITL_HEXA_Hovering_B.Saturation_e;
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = HITL_HEXA_Hovering_B.Gain1;
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = HITL_HEXA_Hovering_B.Saturation[1];
    HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_B.Saturation_f;
  }

  // End of Chart: '<S4>/Chart'

  // Outputs for Enabled SubSystem: '<S4>/Attitude controller' incorporates:
  //   EnablePort: '<S72>/Enable'

  if (HITL_HEXA_Hovering_B.In1_bs.armed) {
    // Sum: '<S72>/Sum4' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'

    HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 -
      HITL_HEXA_Hovering_B.In1_l.xyz[2];

    // Gain: '<S115>/Integral Gain'
    HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_P.PIDController_I *
      HITL_HEXA_Hovering_B.Switch_m;

    // Gain: '<S121>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S113>/Filter'
    //   Gain: '<S111>/Derivative Gain'
    //   Sum: '<S113>/SumD'

    HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 =
      (HITL_HEXA_Hovering_P.PIDController_D * HITL_HEXA_Hovering_B.Switch_m -
       HITL_HEXA_Hovering_DW.Filter_DSTATE_e) *
      HITL_HEXA_Hovering_P.PIDController_N;

    // Sum: '<S127>/Sum' incorporates:
    //   DiscreteIntegrator: '<S118>/Integrator'
    //   Gain: '<S123>/Proportional Gain'

    HITL_HEXA_Hovering_B.Switch3 = (HITL_HEXA_Hovering_P.PIDController_P *
      HITL_HEXA_Hovering_B.Switch_m + HITL_HEXA_Hovering_DW.Integrator_DSTATE_k)
      + HITL_HEXA_Hovering_B.rtb_Transpose_idx_0;

    // DeadZone: '<S110>/DeadZone'
    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.Switch3 -
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.Switch3 >=
               HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch4 = 0.0;
    } else {
      HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_B.Switch3 -
        HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    }

    // End of DeadZone: '<S110>/DeadZone'

    // Switch: '<S108>/Switch1' incorporates:
    //   Constant: '<S108>/Clamping_zero'
    //   Constant: '<S108>/Constant'
    //   Constant: '<S108>/Constant2'
    //   RelationalOperator: '<S108>/fix for DT propagation issue'

    if (HITL_HEXA_Hovering_B.Switch4 > HITL_HEXA_Hovering_P.Clamping_zero_Value)
    {
      HITL_HEXA_Hovering_B.rtPrevAction =
        HITL_HEXA_Hovering_P.Constant_Value_gep;
    } else {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant2_Value_i;
    }

    // Switch: '<S108>/Switch2' incorporates:
    //   Constant: '<S108>/Clamping_zero'
    //   Constant: '<S108>/Constant3'
    //   Constant: '<S108>/Constant4'
    //   RelationalOperator: '<S108>/fix for DT propagation issue1'

    if (HITL_HEXA_Hovering_B.Subtract_f >
        HITL_HEXA_Hovering_P.Clamping_zero_Value) {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant3_Value_h;
    } else {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant4_Value_f;
    }

    // Switch: '<S108>/Switch' incorporates:
    //   Constant: '<S108>/Clamping_zero'
    //   Constant: '<S108>/Constant1'
    //   Logic: '<S108>/AND3'
    //   RelationalOperator: '<S108>/Equal1'
    //   RelationalOperator: '<S108>/Relational Operator'
    //   Switch: '<S108>/Switch1'
    //   Switch: '<S108>/Switch2'

    if ((HITL_HEXA_Hovering_P.Clamping_zero_Value !=
         HITL_HEXA_Hovering_B.Switch4) && (HITL_HEXA_Hovering_B.rtPrevAction ==
         HITL_HEXA_Hovering_B.i2_b)) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant1_Value_k;
    } else {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.Subtract_f;
    }

    // End of Switch: '<S108>/Switch'

    // Saturate: '<S125>/Saturation'
    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S125>/Saturation'
      HITL_HEXA_Hovering_B.Saturation_l =
        HITL_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.Switch3 <
               HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      // Saturate: '<S125>/Saturation'
      HITL_HEXA_Hovering_B.Saturation_l =
        HITL_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    } else {
      // Saturate: '<S125>/Saturation'
      HITL_HEXA_Hovering_B.Saturation_l = HITL_HEXA_Hovering_B.Switch3;
    }

    // End of Saturate: '<S125>/Saturation'

    // RateLimiter: '<S72>/Rate Limiter2'
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 -
      HITL_HEXA_Hovering_DW.PrevY;
    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.RateLimiter2_RisingLim * HITL_HEXA_Hovering_period)
    {
      HITL_HEXA_Hovering_B.Subtract_f =
        HITL_HEXA_Hovering_P.RateLimiter2_RisingLim * HITL_HEXA_Hovering_period
        + HITL_HEXA_Hovering_DW.PrevY;
    } else if (HITL_HEXA_Hovering_B.Switch3 <
               HITL_HEXA_Hovering_P.RateLimiter2_FallingLim *
               HITL_HEXA_Hovering_period) {
      HITL_HEXA_Hovering_B.Subtract_f =
        HITL_HEXA_Hovering_P.RateLimiter2_FallingLim * HITL_HEXA_Hovering_period
        + HITL_HEXA_Hovering_DW.PrevY;
    } else {
      HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_B.rtb_Transpose_idx_1;
    }

    HITL_HEXA_Hovering_DW.PrevY = HITL_HEXA_Hovering_B.Subtract_f;

    // End of RateLimiter: '<S72>/Rate Limiter2'

    // If: '<S605>/If' incorporates:
    //   Constant: '<S606>/Constant'
    //   Constant: '<S607>/Constant'

    if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 > 1.0) {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 =
        HITL_HEXA_Hovering_P.Constant_Value_cs;
    } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 < -1.0) {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 =
        HITL_HEXA_Hovering_P.Constant_Value_m;
    }

    // Saturate: '<S72>/Saturation1'
    if (HITL_HEXA_Hovering_B.Subtract_f >
        HITL_HEXA_Hovering_P.Saturation1_UpperSat) {
      HITL_HEXA_Hovering_B.Subtract_f =
        HITL_HEXA_Hovering_P.Saturation1_UpperSat;
    } else if (HITL_HEXA_Hovering_B.Subtract_f <
               HITL_HEXA_Hovering_P.Saturation1_LowerSat) {
      HITL_HEXA_Hovering_B.Subtract_f =
        HITL_HEXA_Hovering_P.Saturation1_LowerSat;
    }

    // If: '<S605>/If' incorporates:
    //   Trigonometry: '<S603>/trigFcn'

    if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 > 1.0) {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 = 1.0;
    } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 < -1.0) {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 = -1.0;
    }

    // Sum: '<S72>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S277>/Proportional Gain'
    //   Saturate: '<S72>/Saturation1'
    //   Sum: '<S72>/Sum2'
    //   Trigonometry: '<S603>/trigFcn'

    HITL_HEXA_Hovering_B.Subtract_f = (HITL_HEXA_Hovering_B.Subtract_f - asin
      (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3)) *
      HITL_HEXA_Hovering_P.PIDController3_P - HITL_HEXA_Hovering_B.In1_l.xyz[1];

    // Gain: '<S167>/Integral Gain'
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.PIDController1_I *
      HITL_HEXA_Hovering_B.Subtract_f;

    // Gain: '<S173>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S165>/Filter'
    //   Gain: '<S163>/Derivative Gain'
    //   Sum: '<S165>/SumD'

    HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 =
      (HITL_HEXA_Hovering_P.PIDController1_D * HITL_HEXA_Hovering_B.Subtract_f -
       HITL_HEXA_Hovering_DW.Filter_DSTATE_ek) *
      HITL_HEXA_Hovering_P.PIDController1_N;

    // Sum: '<S179>/Sum' incorporates:
    //   DiscreteIntegrator: '<S170>/Integrator'
    //   Gain: '<S175>/Proportional Gain'

    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      (HITL_HEXA_Hovering_P.PIDController1_P * HITL_HEXA_Hovering_B.Subtract_f +
       HITL_HEXA_Hovering_DW.Integrator_DSTATE_kd) +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3;

    // DeadZone: '<S162>/DeadZone'
    if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 >
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 -
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 >=
               HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      HITL_HEXA_Hovering_B.Switch_m = 0.0;
    } else {
      HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 -
        HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S162>/DeadZone'

    // Switch: '<S160>/Switch1' incorporates:
    //   Constant: '<S160>/Clamping_zero'
    //   Constant: '<S160>/Constant'
    //   Constant: '<S160>/Constant2'
    //   RelationalOperator: '<S160>/fix for DT propagation issue'

    if (HITL_HEXA_Hovering_B.Switch_m >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_b) {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant_Value_a1;
    } else {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant2_Value_l;
    }

    // Switch: '<S160>/Switch2' incorporates:
    //   Constant: '<S160>/Clamping_zero'
    //   Constant: '<S160>/Constant3'
    //   Constant: '<S160>/Constant4'
    //   RelationalOperator: '<S160>/fix for DT propagation issue1'

    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_b) {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant3_Value_j;
    } else {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant4_Value_a;
    }

    // Switch: '<S160>/Switch' incorporates:
    //   Constant: '<S160>/Clamping_zero'
    //   Constant: '<S160>/Constant1'
    //   Logic: '<S160>/AND3'
    //   RelationalOperator: '<S160>/Equal1'
    //   RelationalOperator: '<S160>/Relational Operator'
    //   Switch: '<S160>/Switch1'
    //   Switch: '<S160>/Switch2'

    if ((HITL_HEXA_Hovering_P.Clamping_zero_Value_b !=
         HITL_HEXA_Hovering_B.Switch_m) && (HITL_HEXA_Hovering_B.rtPrevAction ==
         HITL_HEXA_Hovering_B.i2_b)) {
      HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_P.Constant1_Value_o;
    } else {
      HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_B.Switch3;
    }

    // End of Switch: '<S160>/Switch'

    // Saturate: '<S177>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 >
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S177>/Saturation'
      HITL_HEXA_Hovering_B.Saturation_o =
        HITL_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 <
               HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      // Saturate: '<S177>/Saturation'
      HITL_HEXA_Hovering_B.Saturation_o =
        HITL_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S177>/Saturation'
      HITL_HEXA_Hovering_B.Saturation_o =
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1;
    }

    // End of Saturate: '<S177>/Saturation'

    // RateLimiter: '<S72>/Rate Limiter1'
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 -
      HITL_HEXA_Hovering_DW.PrevY_f;
    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.RateLimiter1_RisingLim * HITL_HEXA_Hovering_period)
    {
      HITL_HEXA_Hovering_B.Switch_m =
        HITL_HEXA_Hovering_P.RateLimiter1_RisingLim * HITL_HEXA_Hovering_period
        + HITL_HEXA_Hovering_DW.PrevY_f;
    } else if (HITL_HEXA_Hovering_B.Switch3 <
               HITL_HEXA_Hovering_P.RateLimiter1_FallingLim *
               HITL_HEXA_Hovering_period) {
      HITL_HEXA_Hovering_B.Switch_m =
        HITL_HEXA_Hovering_P.RateLimiter1_FallingLim * HITL_HEXA_Hovering_period
        + HITL_HEXA_Hovering_DW.PrevY_f;
    } else {
      HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_B.rtb_Transpose_idx_2;
    }

    HITL_HEXA_Hovering_DW.PrevY_f = HITL_HEXA_Hovering_B.Switch_m;

    // End of RateLimiter: '<S72>/Rate Limiter1'

    // Saturate: '<S72>/Saturation'
    if (HITL_HEXA_Hovering_B.Switch_m >
        HITL_HEXA_Hovering_P.Saturation_UpperSat_m) {
      HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_P.Saturation_UpperSat_m;
    } else if (HITL_HEXA_Hovering_B.Switch_m <
               HITL_HEXA_Hovering_P.Saturation_LowerSat_l) {
      HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_P.Saturation_LowerSat_l;
    }

    // Sum: '<S72>/Sum1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S327>/Proportional Gain'
    //   Saturate: '<S72>/Saturation'
    //   Sum: '<S72>/Sum3'

    HITL_HEXA_Hovering_B.Switch_m = (HITL_HEXA_Hovering_B.Switch_m -
      HITL_HEXA_Hovering_B.VectorConcatenate[2]) *
      HITL_HEXA_Hovering_P.PIDController4_P - HITL_HEXA_Hovering_B.In1_l.xyz[0];

    // Gain: '<S219>/Integral Gain'
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.PIDController2_I *
      HITL_HEXA_Hovering_B.Switch_m;

    // Gain: '<S225>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S217>/Filter'
    //   Gain: '<S215>/Derivative Gain'
    //   Sum: '<S217>/SumD'

    HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 =
      (HITL_HEXA_Hovering_P.PIDController2_D * HITL_HEXA_Hovering_B.Switch_m -
       HITL_HEXA_Hovering_DW.Filter_DSTATE_j) *
      HITL_HEXA_Hovering_P.PIDController2_N;

    // Sum: '<S231>/Sum' incorporates:
    //   DiscreteIntegrator: '<S222>/Integrator'
    //   Gain: '<S227>/Proportional Gain'

    HITL_HEXA_Hovering_B.Saturation_m = (HITL_HEXA_Hovering_P.PIDController2_P *
      HITL_HEXA_Hovering_B.Switch_m + HITL_HEXA_Hovering_DW.Integrator_DSTATE_i)
      + HITL_HEXA_Hovering_B.rtb_Transpose_idx_2;

    // DeadZone: '<S214>/DeadZone' incorporates:
    //   Saturate: '<S229>/Saturation'

    if (HITL_HEXA_Hovering_B.Saturation_m >
        HITL_HEXA_Hovering_P.PIDController2_UpperSaturationLimit) {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
        HITL_HEXA_Hovering_B.Saturation_m -
        HITL_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;

      // Sum: '<S231>/Sum' incorporates:
      //   Saturate: '<S229>/Saturation'

      HITL_HEXA_Hovering_B.Saturation_m =
        HITL_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;
    } else {
      if (HITL_HEXA_Hovering_B.Saturation_m >=
          HITL_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = 0.0;
      } else {
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          HITL_HEXA_Hovering_B.Saturation_m -
          HITL_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }

      if (HITL_HEXA_Hovering_B.Saturation_m <
          HITL_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        // Sum: '<S231>/Sum' incorporates:
        //   Saturate: '<S229>/Saturation'

        HITL_HEXA_Hovering_B.Saturation_m =
          HITL_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of DeadZone: '<S214>/DeadZone'

    // Update for DiscreteIntegrator: '<S118>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE_k +=
      HITL_HEXA_Hovering_P.Integrator_gainval *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;

    // Update for DiscreteIntegrator: '<S113>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_e += HITL_HEXA_Hovering_P.Filter_gainval
      * HITL_HEXA_Hovering_B.rtb_Transpose_idx_0;

    // Update for DiscreteIntegrator: '<S170>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE_kd +=
      HITL_HEXA_Hovering_P.Integrator_gainval_i *
      HITL_HEXA_Hovering_B.Subtract_f;

    // Update for DiscreteIntegrator: '<S165>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_ek +=
      HITL_HEXA_Hovering_P.Filter_gainval_p *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3;

    // Switch: '<S212>/Switch1' incorporates:
    //   Constant: '<S212>/Clamping_zero'
    //   Constant: '<S212>/Constant'
    //   Constant: '<S212>/Constant2'
    //   RelationalOperator: '<S212>/fix for DT propagation issue'

    if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_f) {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant_Value_jj;
    } else {
      HITL_HEXA_Hovering_B.rtPrevAction = HITL_HEXA_Hovering_P.Constant2_Value_o;
    }

    // Switch: '<S212>/Switch2' incorporates:
    //   Constant: '<S212>/Clamping_zero'
    //   Constant: '<S212>/Constant3'
    //   Constant: '<S212>/Constant4'
    //   RelationalOperator: '<S212>/fix for DT propagation issue1'

    if (HITL_HEXA_Hovering_B.Switch3 >
        HITL_HEXA_Hovering_P.Clamping_zero_Value_f) {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant3_Value_l;
    } else {
      HITL_HEXA_Hovering_B.i2_b = HITL_HEXA_Hovering_P.Constant4_Value_n;
    }

    // Switch: '<S212>/Switch' incorporates:
    //   Constant: '<S212>/Clamping_zero'
    //   Constant: '<S212>/Constant1'
    //   Logic: '<S212>/AND3'
    //   RelationalOperator: '<S212>/Equal1'
    //   RelationalOperator: '<S212>/Relational Operator'
    //   Switch: '<S212>/Switch1'
    //   Switch: '<S212>/Switch2'

    if ((HITL_HEXA_Hovering_P.Clamping_zero_Value_f !=
         HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) &&
        (HITL_HEXA_Hovering_B.rtPrevAction == HITL_HEXA_Hovering_B.i2_b)) {
      HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.Constant1_Value_p;
    }

    // Update for DiscreteIntegrator: '<S222>/Integrator' incorporates:
    //   Switch: '<S212>/Switch'

    HITL_HEXA_Hovering_DW.Integrator_DSTATE_i +=
      HITL_HEXA_Hovering_P.Integrator_gainval_p * HITL_HEXA_Hovering_B.Switch3;

    // Update for DiscreteIntegrator: '<S217>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_j +=
      HITL_HEXA_Hovering_P.Filter_gainval_k *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_2;
  }

  // End of Outputs for SubSystem: '<S4>/Attitude controller'

  // Gain: '<S5>/Gain'
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 = HITL_HEXA_Hovering_P.Gain_Gain_e2 *
    HITL_HEXA_Hovering_B.Saturation_m;

  // Gain: '<S5>/Gain1'
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = HITL_HEXA_Hovering_P.Gain1_Gain_a2 *
    HITL_HEXA_Hovering_B.Saturation_o;

  // Gain: '<S5>/Gain2'
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = HITL_HEXA_Hovering_P.Gain2_Gain_e *
    HITL_HEXA_Hovering_B.Saturation_l;

  // Gain: '<S5>/Gain3'
  HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = HITL_HEXA_Hovering_P.Gain3_Gain_b *
    HITL_HEXA_Hovering_B.Switch2;

  // MATLABSystem: '<S7>/Read Parameter13'
  if (HITL_HEXA_Hovering_DW.obj_d.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter13_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_d.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter13_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_k);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // RelationalOperator: '<S12>/Compare' incorporates:
  //   Constant: '<S12>/Constant'

  HITL_HEXA_Hovering_B.Compare = (HITL_HEXA_Hovering_B.In1_b.values[7] >=
    HITL_HEXA_Hovering_P.CompareToConstant_const_c);

  // Switch: '<S6>/Switch' incorporates:
  //   Constant: '<S6>/Constant'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S13>/Product'
  //   Saturate: '<S13>/Saturation'
  //   Switch: '<S7>/Switch'

  if (HITL_HEXA_Hovering_B.Compare_h) {
    HITL_HEXA_Hovering_B.Switch_m = HITL_HEXA_Hovering_P.Constant_Value_oh;
  } else {
    if (HITL_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion3'
      //   MATLABSystem: '<S7>/Read Parameter13'
      //
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch' incorporates:
      //   Constant: '<S7>/Constant'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant_Value_i;
    }

    // Gain: '<S13>/Gain' incorporates:
    //   Switch: '<S7>/Switch'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *= HITL_HEXA_Hovering_P.Gain_Gain_d;

    // Saturate: '<S13>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.Saturation_UpperSat_f) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_UpperSat_f;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.Saturation_LowerSat_p) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_LowerSat_p;
    }

    HITL_HEXA_Hovering_B.Switch_m = ((-HITL_HEXA_Hovering_B.rtb_Transpose_idx_3
      - HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch'

  // MATLABSystem: '<S7>/Read Parameter1'
  if (HITL_HEXA_Hovering_DW.obj_p.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter1_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_p.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter1_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_p.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_k);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch1' incorporates:
  //   Constant: '<S6>/Constant1'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S14>/Product'
  //   Saturate: '<S14>/Saturation'
  //   Switch: '<S7>/Switch1'

  if (HITL_HEXA_Hovering_B.Compare_h) {
    HITL_HEXA_Hovering_B.Subtract_f = HITL_HEXA_Hovering_P.Constant1_Value;
  } else {
    if (HITL_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch1' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion2'
      //   MATLABSystem: '<S7>/Read Parameter1'
      //
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch1' incorporates:
      //   Constant: '<S7>/Constant1'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant1_Value_c;
    }

    // Gain: '<S14>/Gain' incorporates:
    //   Switch: '<S7>/Switch1'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *= HITL_HEXA_Hovering_P.Gain_Gain;

    // Saturate: '<S14>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.Saturation_UpperSat) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_UpperSat;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.Saturation_LowerSat) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_LowerSat;
    }

    HITL_HEXA_Hovering_B.Subtract_f = ((HITL_HEXA_Hovering_B.rtb_Transpose_idx_3
      + HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch1'

  // MATLABSystem: '<S7>/Read Parameter2'
  if (HITL_HEXA_Hovering_DW.obj_m0.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter2_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_m0.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter2_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_m0.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_k);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch2' incorporates:
  //   Constant: '<S6>/Constant2'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S15>/Product'
  //   Saturate: '<S15>/Saturation'
  //   Switch: '<S7>/Switch2'

  if (HITL_HEXA_Hovering_B.Compare_h) {
    HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_P.Constant2_Value;
  } else {
    if (HITL_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch2' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion'
      //   MATLABSystem: '<S7>/Read Parameter2'
      //
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch2' incorporates:
      //   Constant: '<S7>/Constant2'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant2_Value_e;
    }

    // Gain: '<S15>/Gain' incorporates:
    //   Switch: '<S7>/Switch2'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *= HITL_HEXA_Hovering_P.Gain_Gain_i;

    // Saturate: '<S15>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.Saturation_UpperSat_l) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_UpperSat_l;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.Saturation_LowerSat_i) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_LowerSat_i;
    }

    HITL_HEXA_Hovering_B.Switch2 = (((HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 /
      2.0 + HITL_HEXA_Hovering_B.rtb_Transpose_idx_2) -
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch2'

  // MATLABSystem: '<S7>/Read Parameter3'
  if (HITL_HEXA_Hovering_DW.obj_be.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter3_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_be.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter3_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_be.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_k);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch3' incorporates:
  //   Constant: '<S6>/Constant3'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S16>/Product'
  //   Saturate: '<S16>/Saturation'
  //   Switch: '<S7>/Switch3'

  if (HITL_HEXA_Hovering_B.Compare_h) {
    HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_P.Constant3_Value;
  } else {
    if (HITL_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch3' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion4'
      //   MATLABSystem: '<S7>/Read Parameter3'
      //
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch3' incorporates:
      //   Constant: '<S7>/Constant3'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant3_Value_f;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Switch: '<S7>/Switch3'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *= HITL_HEXA_Hovering_P.Gain_Gain_j;

    // Saturate: '<S16>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.Saturation_UpperSat_d) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_UpperSat_d;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.Saturation_LowerSat_o) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_LowerSat_o;
    }

    HITL_HEXA_Hovering_B.Switch3 = (((-HITL_HEXA_Hovering_B.rtb_Transpose_idx_2
      - HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0) +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch3'

  // MATLABSystem: '<S7>/Read Parameter4'
  if (HITL_HEXA_Hovering_DW.obj_gw.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter4_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_gw.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter4_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_gw.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_k);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch4' incorporates:
  //   Constant: '<S6>/Constant4'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S17>/Product'
  //   Saturate: '<S17>/Saturation'
  //   Switch: '<S7>/Switch4'

  if (HITL_HEXA_Hovering_B.Compare_h) {
    HITL_HEXA_Hovering_B.Switch4 = HITL_HEXA_Hovering_P.Constant4_Value;
  } else {
    if (HITL_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch4' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion1'
      //   MATLABSystem: '<S7>/Read Parameter4'
      //
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch4' incorporates:
      //   Constant: '<S7>/Constant4'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant4_Value_m;
    }

    // Gain: '<S17>/Gain' incorporates:
    //   Switch: '<S7>/Switch4'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *= HITL_HEXA_Hovering_P.Gain_Gain_jb;

    // Saturate: '<S17>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.Saturation_UpperSat_c) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_UpperSat_c;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.Saturation_LowerSat_f) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_LowerSat_f;
    }

    HITL_HEXA_Hovering_B.Switch4 = (((HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 -
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0) +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) *
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch4'

  // MATLABSystem: '<S7>/Read Parameter5'
  if (HITL_HEXA_Hovering_DW.obj_m.SampleTime !=
      HITL_HEXA_Hovering_P.ReadParameter5_SampleTime) {
    HITL_HEXA_Hovering_DW.obj_m.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter5_SampleTime;
  }

  HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (HITL_HEXA_Hovering_DW.obj_m.MW_PARAMHANDLE, MW_INT32,
     &HITL_HEXA_Hovering_B.ParamStep_k);
  if (HITL_HEXA_Hovering_B.b_varargout_1) {
    HITL_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch5' incorporates:
  //   Constant: '<S6>/Constant5'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S18>/Product'
  //   Saturate: '<S18>/Saturation'
  //   Switch: '<S7>/Switch5'

  if (HITL_HEXA_Hovering_B.Compare_h) {
    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      HITL_HEXA_Hovering_P.Constant5_Value;
  } else {
    if (HITL_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch5' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion5'
      //   MATLABSystem: '<S7>/Read Parameter5'
      //
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = HITL_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch5' incorporates:
      //   Constant: '<S7>/Constant5'

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Constant5_Value_j;
    }

    // Gain: '<S18>/Gain' incorporates:
    //   Switch: '<S7>/Switch5'

    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 *= HITL_HEXA_Hovering_P.Gain_Gain_k;

    // Saturate: '<S18>/Saturation'
    if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 >
        HITL_HEXA_Hovering_P.Saturation_UpperSat_cb) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_UpperSat_cb;
    } else if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 <
               HITL_HEXA_Hovering_P.Saturation_LowerSat_k) {
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
        HITL_HEXA_Hovering_P.Saturation_LowerSat_k;
    }

    HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      (((HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0 -
         HITL_HEXA_Hovering_B.rtb_Transpose_idx_2) -
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       HITL_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      HITL_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch5'

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S21>/Constant'

  HITL_HEXA_Hovering_B.BusAssignment = HITL_HEXA_Hovering_P.Constant_Value_c;

  // DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
  //   Constant: '<S10>/Constant17'

  HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = floor
    (HITL_HEXA_Hovering_P.Constant17_Value);
  if (rtIsNaN(HITL_HEXA_Hovering_B.rtb_Merge_idx_0) || rtIsInf
      (HITL_HEXA_Hovering_B.rtb_Merge_idx_0)) {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0;
  } else {
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = fmod
      (HITL_HEXA_Hovering_B.rtb_Merge_idx_0, 4.294967296E+9);
  }

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S10>/Constant'
  //   DataTypeConversion: '<S10>/Data Type Conversion'
  //   DataTypeConversion: '<S10>/Data Type Conversion1'

  HITL_HEXA_Hovering_B.BusAssignment.noutputs =
    HITL_HEXA_Hovering_B.rtb_Merge_idx_0 < 0.0 ? static_cast<uint32_T>(-
    static_cast<int32_T>(static_cast<uint32_T>
    (-HITL_HEXA_Hovering_B.rtb_Merge_idx_0))) : static_cast<uint32_T>
    (HITL_HEXA_Hovering_B.rtb_Merge_idx_0);
  HITL_HEXA_Hovering_B.BusAssignment.output[0] = static_cast<real32_T>
    (HITL_HEXA_Hovering_B.Switch_m);
  HITL_HEXA_Hovering_B.BusAssignment.output[1] = static_cast<real32_T>
    (HITL_HEXA_Hovering_B.Subtract_f);
  HITL_HEXA_Hovering_B.BusAssignment.output[2] = static_cast<real32_T>
    (HITL_HEXA_Hovering_B.Switch2);
  HITL_HEXA_Hovering_B.BusAssignment.output[3] = static_cast<real32_T>
    (HITL_HEXA_Hovering_B.Switch3);
  HITL_HEXA_Hovering_B.BusAssignment.output[4] = static_cast<real32_T>
    (HITL_HEXA_Hovering_B.Switch4);
  HITL_HEXA_Hovering_B.BusAssignment.output[5] = static_cast<real32_T>
    (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
  HITL_HEXA_Hovering_B.BusAssignment.output[6] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[7] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[8] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[9] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[10] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[11] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[12] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[13] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[14] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);
  HITL_HEXA_Hovering_B.BusAssignment.output[15] = static_cast<real32_T>
    (HITL_HEXA_Hovering_P.Constant_Value_me);

  // MATLABSystem: '<S22>/SinkBlock' incorporates:
  //   BusAssignment: '<S10>/Bus Assignment'

  uORB_write_step(HITL_HEXA_Hovering_DW.obj_nt.orbMetadataObj,
                  &HITL_HEXA_Hovering_DW.obj_nt.orbAdvertiseObj,
                  &HITL_HEXA_Hovering_B.BusAssignment);

  // Outputs for Enabled SubSystem: '<S37>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S54>/Enable'

  // Start for MATLABSystem: '<S37>/Read Parameter'
  if (HITL_HEXA_Hovering_B.ParamStep_c > 0) {
    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment'
    //   Constant: '<S64>/Constant'
    //   SignalConversion generated from: '<S60>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0] =
      HITL_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S60>/Matrix Concatenate1'
    HITL_HEXA_Hovering_B.DataTypeConversion2[0] =
      HITL_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S60>/Matrix Concatenate1'
    HITL_HEXA_Hovering_B.DataTypeConversion2[1] =
      HITL_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S60>/Data Type Conversion'
    HITL_HEXA_Hovering_B.DataTypeConversion2[2] =
      HITL_HEXA_Hovering_B.In1_p.current.alt;

    // SignalConversion generated from: '<S54>/Matrix Concatenate1'
    HITL_HEXA_Hovering_B.VectorConcatenate[0] = HITL_HEXA_Hovering_B.In1_f.lat;

    // SignalConversion generated from: '<S54>/Matrix Concatenate1'
    HITL_HEXA_Hovering_B.VectorConcatenate[1] = HITL_HEXA_Hovering_B.In1_f.lon;

    // DataTypeConversion: '<S54>/Data Type Conversion'
    HITL_HEXA_Hovering_B.VectorConcatenate[2] = HITL_HEXA_Hovering_B.In1_f.alt;
    HITL_HEXA_Hovering_MATLABSystem(HITL_HEXA_Hovering_B.DataTypeConversion2,
      HITL_HEXA_Hovering_B.VectorConcatenate,
      HITL_HEXA_Hovering_B.In1_p.current.valid,
      HITL_HEXA_Hovering_B.In1_p.current.type,
      &HITL_HEXA_Hovering_B.MATLABSystem);

    // SignalConversion generated from: '<S66>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S60>/Bus Assignment1'
    //   MATLABSystem: '<S60>/MATLAB System'
    //   SignalConversion generated from: '<S60>/MATLAB System'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[0] =
      HITL_HEXA_Hovering_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S66>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S60>/Bus Assignment1'
    //   MATLABSystem: '<S60>/MATLAB System'
    //   SignalConversion generated from: '<S60>/MATLAB System'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[1] =
      HITL_HEXA_Hovering_B.MATLABSystem.MATLABSystem[1];

    // If: '<S66>/If' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S60>/Bus Assignment1'
    //   Constant: '<S68>/Constant'
    //   Constant: '<S68>/Constant1'
    //   Constant: '<S69>/Constant'
    //   Constant: '<S69>/Constant1'

    if (HITL_HEXA_Hovering_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S66>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S69>/Action Port'

      // MATLABSystem: '<S69>/Read Parameter' incorporates:
      //   BusAssignment: '<S54>/Bus Assignment1'
      //   BusAssignment: '<S60>/Bus Assignment1'
      //   SignalConversion generated from: '<S69>/Read Parameter'

      if (HITL_HEXA_Hovering_DW.obj_g.SampleTime !=
          HITL_HEXA_Hovering_P.ReadParameter_SampleTime_c) {
        HITL_HEXA_Hovering_DW.obj_g.SampleTime =
          HITL_HEXA_Hovering_P.ReadParameter_SampleTime_c;
      }

      HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
        (HITL_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2]);
      if (HITL_HEXA_Hovering_B.b_varargout_1) {
        HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S69>/Read Parameter'
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        HITL_HEXA_Hovering_P.Constant1_Value_d[0];
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        HITL_HEXA_Hovering_P.Constant1_Value_d[1];
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        HITL_HEXA_Hovering_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S66>/If Action Subsystem2'
    } else if (HITL_HEXA_Hovering_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S66>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S68>/Action Port'

      // MATLABSystem: '<S68>/Read Parameter'
      if (HITL_HEXA_Hovering_DW.obj_b.SampleTime !=
          HITL_HEXA_Hovering_P.ReadParameter_SampleTime_g) {
        HITL_HEXA_Hovering_DW.obj_b.SampleTime =
          HITL_HEXA_Hovering_P.ReadParameter_SampleTime_g;
      }

      HITL_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
        (HITL_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &HITL_HEXA_Hovering_B.ParamStep);
      if (HITL_HEXA_Hovering_B.b_varargout_1) {
        HITL_HEXA_Hovering_B.ParamStep = 0.0F;
      }

      // Gain: '<S68>/Gain' incorporates:
      //   BusAssignment: '<S54>/Bus Assignment1'
      //   BusAssignment: '<S60>/Bus Assignment1'
      //   MATLABSystem: '<S68>/Read Parameter'
      //
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        HITL_HEXA_Hovering_P.Gain_Gain_h * HITL_HEXA_Hovering_B.ParamStep;
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        HITL_HEXA_Hovering_P.Constant1_Value_k4[0];
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        HITL_HEXA_Hovering_P.Constant1_Value_k4[1];
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        HITL_HEXA_Hovering_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S66>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S66>/If Action Subsystem' incorporates:
      //   ActionPort: '<S67>/Action Port'

      // SignalConversion generated from: '<S67>/In1' incorporates:
      //   BusAssignment: '<S54>/Bus Assignment1'
      //   BusAssignment: '<S60>/Bus Assignment1'
      //   MATLABSystem: '<S60>/MATLAB System'
      //   SignalConversion generated from: '<S60>/MATLAB System'

      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        HITL_HEXA_Hovering_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S60>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S54>/Bus Assignment1'
      //   SignalConversion generated from: '<S66>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S67>/In2'
      //
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        HITL_HEXA_Hovering_B.In1_p.current.vx;
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        HITL_HEXA_Hovering_B.In1_p.current.vy;
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        HITL_HEXA_Hovering_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S66>/If Action Subsystem'
    }

    // End of If: '<S66>/If'

    // BusAssignment: '<S60>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   Constant: '<S60>/Constant5'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].timestamp =
      HITL_HEXA_Hovering_B.In1_p.current.timestamp;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].type =
      HITL_HEXA_Hovering_B.In1_p.current.type;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].yaw =
      HITL_HEXA_Hovering_B.In1_p.current.yaw;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].yaw_speed =
      HITL_HEXA_Hovering_B.In1_p.current.yawspeed;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[0].point_valid =
      HITL_HEXA_Hovering_P.Constant5_Value_jn;

    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment'
    //   Constant: '<S64>/Constant'
    //   SignalConversion generated from: '<S61>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1] =
      HITL_HEXA_Hovering_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S61>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S60>/Matrix Concatenate1'

    HITL_HEXA_Hovering_B.DataTypeConversion2[0] =
      HITL_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S61>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S60>/Matrix Concatenate1'

    HITL_HEXA_Hovering_B.DataTypeConversion2[1] =
      HITL_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S61>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S60>/Data Type Conversion'

    HITL_HEXA_Hovering_B.DataTypeConversion2[2] =
      HITL_HEXA_Hovering_B.In1_p.current.alt;
    HITL_HEXA_Hovering_MATLABSystem(HITL_HEXA_Hovering_B.DataTypeConversion2,
      HITL_HEXA_Hovering_B.VectorConcatenate,
      HITL_HEXA_Hovering_B.In1_p.current.valid,
      HITL_HEXA_Hovering_B.In1_p.current.type,
      &HITL_HEXA_Hovering_B.MATLABSystem_b);

    // SignalConversion generated from: '<S61>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S61>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[0] =
      HITL_HEXA_Hovering_B.In1_p.current.vx;

    // SignalConversion generated from: '<S61>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S61>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[1] =
      HITL_HEXA_Hovering_B.In1_p.current.vy;

    // SignalConversion generated from: '<S61>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S61>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[2] =
      HITL_HEXA_Hovering_B.In1_p.current.vz;

    // BusAssignment: '<S61>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S60>/Bus Assignment1'
    //   Constant: '<S61>/Constant5'
    //   MATLABSystem: '<S61>/MATLAB System'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].timestamp =
      HITL_HEXA_Hovering_B.In1_p.current.timestamp;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].position[0] =
      HITL_HEXA_Hovering_B.MATLABSystem_b.MATLABSystem[0];
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].position[1] =
      HITL_HEXA_Hovering_B.MATLABSystem_b.MATLABSystem[1];
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].position[2] =
      HITL_HEXA_Hovering_B.MATLABSystem_b.MATLABSystem[2];
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].yaw =
      HITL_HEXA_Hovering_B.In1_p.current.yaw;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].yaw_speed =
      HITL_HEXA_Hovering_B.In1_p.current.yawspeed;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].point_valid =
      HITL_HEXA_Hovering_P.Constant5_Value_k;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[1].type =
      HITL_HEXA_Hovering_B.In1_p.current.type;

    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment'
    //   Constant: '<S64>/Constant'
    //   SignalConversion generated from: '<S63>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2] =
      HITL_HEXA_Hovering_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S63>/MATLAB System' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   DataTypeConversion: '<S54>/Data Type Conversion'
    //   DataTypeConversion: '<S63>/Data Type Conversion'
    //   SignalConversion generated from: '<S54>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S63>/Matrix Concatenate'
    //
    if (HITL_HEXA_Hovering_B.In1_p.next.valid) {
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 =
        HITL_HEXA_Hovering_B.In1_p.next.lat - HITL_HEXA_Hovering_B.In1_f.lat;
      HITL_HEXA_Hovering_B.Switch2 = HITL_HEXA_Hovering_B.In1_p.next.lon -
        HITL_HEXA_Hovering_B.In1_f.lon;
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = fabs
        (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3);
      if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 > 180.0) {
        if (rtIsNaN(HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0) || rtIsInf
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0)) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
        } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0 == 0.0) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0;
        } else {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = fmod
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0, 360.0);
          if (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 == 0.0) {
            HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0;
          } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0 < 0.0) {
            HITL_HEXA_Hovering_B.rtb_Merge_idx_0 += 360.0;
          }
        }

        HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 =
          HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 * 0.0 +
          (HITL_HEXA_Hovering_B.rtb_Merge_idx_0 - 180.0);
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = fabs
          (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3);
      }

      if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 > 90.0) {
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = fabs
          (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3);
        HITL_HEXA_Hovering_B.Compare_h =
          (HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 > 90.0);
        HITL_HEXA_Hovering_B.Switch2 += 180.0;
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 * static_cast<real_T>
          (HITL_HEXA_Hovering_B.Compare_h);
        if (rtIsNaN(HITL_HEXA_Hovering_B.rtb_Transpose_idx_1)) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
        } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 < 0.0) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = -1.0;
        } else {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 =
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0);
        }

        HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 = (90.0 -
          (HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 * static_cast<real_T>
           (HITL_HEXA_Hovering_B.Compare_h) - 90.0)) *
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 * static_cast<real_T>
          (HITL_HEXA_Hovering_B.Compare_h) +
          HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 * static_cast<real_T>
          (!HITL_HEXA_Hovering_B.Compare_h);
      }

      if ((HITL_HEXA_Hovering_B.Switch2 > 180.0) ||
          (HITL_HEXA_Hovering_B.Switch2 < -180.0)) {
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 =
          HITL_HEXA_Hovering_rt_remd_snf(HITL_HEXA_Hovering_B.Switch2, 360.0);
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 / 180.0;
        if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 < 0.0) {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = ceil
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
        } else {
          HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = floor
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
        }

        HITL_HEXA_Hovering_B.Switch2 = (HITL_HEXA_Hovering_B.rtb_Transpose_idx_2
          - 360.0 * HITL_HEXA_Hovering_B.rtb_Merge_idx_0) +
          HITL_HEXA_Hovering_B.Switch2 * 0.0;
      }

      HITL_HEXA_Hovering_B.Switch3 = HITL_HEXA_Hovering_sind_g
        (HITL_HEXA_Hovering_B.In1_f.lat);
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 * HITL_HEXA_Hovering_B.Switch3 *
        HITL_HEXA_Hovering_B.Switch3);
      if (rtIsInf(HITL_HEXA_Hovering_B.In1_f.lat) || rtIsNaN
          (HITL_HEXA_Hovering_B.In1_f.lat)) {
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = (rtNaN);
      } else {
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          HITL_HEXA_Hovering_rt_remd_snf(HITL_HEXA_Hovering_B.In1_f.lat, 360.0);
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = fabs
          (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
        if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 > 180.0) {
          if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0) {
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 -= 360.0;
          } else {
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 += 360.0;
          }

          HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 = fabs
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
        }

        if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 <= 45.0) {
          HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = cos(0.017453292519943295 *
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
        } else if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_0 <= 135.0) {
          if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0) {
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = -sin
              ((HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 - 90.0) *
               0.017453292519943295);
          } else {
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = sin
              ((HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 + 90.0) *
               0.017453292519943295);
          }
        } else {
          if (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0) {
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
              (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 - 180.0) *
              0.017453292519943295;
          } else {
            HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 =
              (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 + 180.0) *
              0.017453292519943295;
          }

          HITL_HEXA_Hovering_B.rtb_Transpose_idx_1 = -cos
            (HITL_HEXA_Hovering_B.rtb_Transpose_idx_1);
        }
      }

      HITL_HEXA_Hovering_B.rtb_Transpose_idx_3 /=
        HITL_HEXA_Hovering_rt_atan2d_snf(1.0, 0.99330562000985867 / (1.0 -
        0.0066943799901413165 * HITL_HEXA_Hovering_B.Switch3 *
        HITL_HEXA_Hovering_B.Switch3) * HITL_HEXA_Hovering_B.rtb_Transpose_idx_2)
        * 57.295779513082323;
      HITL_HEXA_Hovering_B.Switch2 /= HITL_HEXA_Hovering_rt_atan2d_snf(1.0,
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 *
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_1) * 57.295779513082323;
      HITL_HEXA_Hovering_B.rtb_Transpose_idx_2 = -static_cast<real_T>
        (HITL_HEXA_Hovering_B.In1_p.next.alt) + HITL_HEXA_Hovering_B.In1_f.alt;
      HITL_HEXA_Hovering_B.distinctWptsIdx[0] = rtIsNaN
        (HITL_HEXA_Hovering_B.rtb_Transpose_idx_3);
      HITL_HEXA_Hovering_B.distinctWptsIdx[1] = rtIsNaN
        (HITL_HEXA_Hovering_B.Switch2);
      HITL_HEXA_Hovering_B.distinctWptsIdx[2] = rtIsNaN
        (HITL_HEXA_Hovering_B.rtb_Transpose_idx_2);
      HITL_HEXA_Hovering_B.Compare_h = false;
      HITL_HEXA_Hovering_B.i1 = 0;
      exitg1 = false;
      while ((!exitg1) && (HITL_HEXA_Hovering_B.i1 < 3)) {
        if (HITL_HEXA_Hovering_B.distinctWptsIdx[HITL_HEXA_Hovering_B.i1]) {
          HITL_HEXA_Hovering_B.Compare_h = true;
          exitg1 = true;
        } else {
          HITL_HEXA_Hovering_B.i1++;
        }
      }

      HITL_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0 / static_cast<real_T>
        (!HITL_HEXA_Hovering_B.Compare_h);
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(HITL_HEXA_Hovering_B.rtb_Merge_idx_0 +
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_3);
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(HITL_HEXA_Hovering_B.rtb_Merge_idx_0 +
        HITL_HEXA_Hovering_B.Switch2);
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(HITL_HEXA_Hovering_B.rtb_Merge_idx_0 +
        HITL_HEXA_Hovering_B.rtb_Transpose_idx_2);
    } else {
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S63>/MATLAB System'

    // SignalConversion generated from: '<S63>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S63>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[0] =
      HITL_HEXA_Hovering_B.In1_p.next.vx;

    // SignalConversion generated from: '<S63>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S63>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[1] =
      HITL_HEXA_Hovering_B.In1_p.next.vy;

    // SignalConversion generated from: '<S63>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   BusAssignment: '<S63>/Bus Assignment1'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[2] =
      HITL_HEXA_Hovering_B.In1_p.next.vz;

    // BusAssignment: '<S63>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'
    //   Constant: '<S63>/Constant5'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].timestamp =
      HITL_HEXA_Hovering_B.In1_p.next.timestamp;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].yaw =
      HITL_HEXA_Hovering_B.In1_p.next.yaw;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].yaw_speed =
      HITL_HEXA_Hovering_B.In1_p.next.yawspeed;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].point_valid =
      HITL_HEXA_Hovering_P.Constant5_Value_h;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[2].type =
      HITL_HEXA_Hovering_B.In1_p.next.type;

    // SignalConversion generated from: '<S62>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment'
    //   BusAssignment: '<S62>/Bus Assignment1'
    //   Constant: '<S64>/Constant'

    HITL_HEXA_Hovering_B.BusAssignment1_f =
      HITL_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S62>/Bus Assignment1' incorporates:
    //   Constant: '<S62>/Constant'
    //   Constant: '<S62>/Constant1'
    //   Constant: '<S62>/Constant2'
    //   Constant: '<S62>/Constant3'
    //   Constant: '<S62>/Constant4'
    //   Constant: '<S62>/Constant5'
    //   Constant: '<S62>/Constant6'
    //   Constant: '<S62>/Constant7'

    HITL_HEXA_Hovering_B.BusAssignment1_f.timestamp =
      HITL_HEXA_Hovering_P.Constant7_Value;
    HITL_HEXA_Hovering_B.BusAssignment1_f.yaw =
      HITL_HEXA_Hovering_P.Constant3_Value_a;
    HITL_HEXA_Hovering_B.BusAssignment1_f.yaw_speed =
      HITL_HEXA_Hovering_P.Constant4_Value_g;
    HITL_HEXA_Hovering_B.BusAssignment1_f.position[0] =
      HITL_HEXA_Hovering_P.Constant_Value_fh[0];
    HITL_HEXA_Hovering_B.BusAssignment1_f.velocity[0] =
      HITL_HEXA_Hovering_P.Constant1_Value_hv[0];
    HITL_HEXA_Hovering_B.BusAssignment1_f.acceleration[0] =
      HITL_HEXA_Hovering_P.Constant2_Value_f[0];
    HITL_HEXA_Hovering_B.BusAssignment1_f.position[1] =
      HITL_HEXA_Hovering_P.Constant_Value_fh[1];
    HITL_HEXA_Hovering_B.BusAssignment1_f.velocity[1] =
      HITL_HEXA_Hovering_P.Constant1_Value_hv[1];
    HITL_HEXA_Hovering_B.BusAssignment1_f.acceleration[1] =
      HITL_HEXA_Hovering_P.Constant2_Value_f[1];
    HITL_HEXA_Hovering_B.BusAssignment1_f.position[2] =
      HITL_HEXA_Hovering_P.Constant_Value_fh[2];
    HITL_HEXA_Hovering_B.BusAssignment1_f.velocity[2] =
      HITL_HEXA_Hovering_P.Constant1_Value_hv[2];
    HITL_HEXA_Hovering_B.BusAssignment1_f.acceleration[2] =
      HITL_HEXA_Hovering_P.Constant2_Value_f[2];
    HITL_HEXA_Hovering_B.BusAssignment1_f.point_valid =
      HITL_HEXA_Hovering_P.Constant5_Value_l;
    HITL_HEXA_Hovering_B.BusAssignment1_f.type =
      HITL_HEXA_Hovering_P.Constant6_Value;

    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment'
    //   Constant: '<S54>/Constant'
    //   Constant: '<S64>/Constant'

    HITL_HEXA_Hovering_B.BusAssignment1.timestamp =
      HITL_HEXA_Hovering_B.In1_p.timestamp;
    HITL_HEXA_Hovering_B.BusAssignment1.type =
      HITL_HEXA_Hovering_P.Constant_Value_fm;
    for (HITL_HEXA_Hovering_B.j = 0; HITL_HEXA_Hovering_B.j < 7;
         HITL_HEXA_Hovering_B.j++) {
      HITL_HEXA_Hovering_B.BusAssignment1._padding0[HITL_HEXA_Hovering_B.j] =
        HITL_HEXA_Hovering_P.Constant_Value._padding0[HITL_HEXA_Hovering_B.j];
    }

    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S62>/Bus Assignment1'
    //   Concatenate: '<S54>/Matrix Concatenate'

    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[3] =
      HITL_HEXA_Hovering_B.BusAssignment1_f;
    HITL_HEXA_Hovering_B.BusAssignment1.waypoints[4] =
      HITL_HEXA_Hovering_B.BusAssignment1_f;

    // MATLABSystem: '<S65>/SinkBlock' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'

    uORB_write_step(HITL_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                    &HITL_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                    &HITL_HEXA_Hovering_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S37>/Send waypoints to OBC'

  // MATLABSystem: '<S53>/PX4 Timestamp'
  hrt_absolute_time();
}

// Model initialize function
void HITL_HEXA_Hovering_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  HITL_HEXA_Hovering_P.Constant1_Value_d[0] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant1_Value_d[1] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant_Value_f2 = rtNaNF;
  HITL_HEXA_Hovering_P.Constant1_Value_k4[0] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant1_Value_k4[1] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant_Value_l4 = rtNaNF;
  HITL_HEXA_Hovering_P.Constant_Value_fh[0] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant_Value_fh[1] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant_Value_fh[2] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant1_Value_hv[0] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant1_Value_hv[1] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant1_Value_hv[2] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant2_Value_f[0] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant2_Value_f[1] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant2_Value_f[2] = rtNaNF;
  HITL_HEXA_Hovering_P.Constant3_Value_a = rtNaNF;
  HITL_HEXA_Hovering_P.Constant4_Value_g = rtNaNF;

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

    // Start for If: '<S36>/If'
    HITL_HEXA_Hovering_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S19>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    HITL_HEXA_Hovering_B.In1_b = HITL_HEXA_Hovering_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S19>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S32>/In1' incorporates:
    //   Outport: '<S32>/Out1'

    HITL_HEXA_Hovering_B.In1_m = HITL_HEXA_Hovering_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S28>/In1' incorporates:
    //   Outport: '<S28>/Out1'

    HITL_HEXA_Hovering_B.In1_l = HITL_HEXA_Hovering_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S29>/In1' incorporates:
    //   Outport: '<S29>/Out1'

    HITL_HEXA_Hovering_B.In1_bs = HITL_HEXA_Hovering_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S31>/In1' incorporates:
    //   Outport: '<S31>/Out1'

    HITL_HEXA_Hovering_B.In1_j = HITL_HEXA_Hovering_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S27>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S33>/In1' incorporates:
    //   Outport: '<S33>/Out1'

    HITL_HEXA_Hovering_B.In1_c = HITL_HEXA_Hovering_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S27>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S58>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S59>/In1' incorporates:
    //   Outport: '<S59>/Out1'

    HITL_HEXA_Hovering_B.In1 = HITL_HEXA_Hovering_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S58>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S56>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S71>/In1' incorporates:
    //   Outport: '<S71>/Out1'

    HITL_HEXA_Hovering_B.In1_p = HITL_HEXA_Hovering_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S56>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    HITL_HEXA_Hovering_B.In1_f = HITL_HEXA_Hovering_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S36>/Take-off'
    // InitializeConditions for Delay: '<S48>/Delay'
    HITL_HEXA_Hovering_DW.Delay_DSTATE_c =
      HITL_HEXA_Hovering_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S49>/Delay'
    HITL_HEXA_Hovering_DW.Delay_DSTATE_d =
      HITL_HEXA_Hovering_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S49>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S50>/yaw_In' incorporates:
    //   Outport: '<S50>/yaw_Out'

    HITL_HEXA_Hovering_B.yaw_In_ik = HITL_HEXA_Hovering_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S49>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S36>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S36>/Land'
    // InitializeConditions for Delay: '<S39>/Delay'
    HITL_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
      HITL_HEXA_Hovering_P.Delay_InitialCondition_n;
    HITL_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
      HITL_HEXA_Hovering_P.Delay_InitialCondition_n;

    // InitializeConditions for Gain: '<S44>/Gain1' incorporates:
    //   Delay: '<S44>/Delay'

    HITL_HEXA_Hovering_DW.Delay_DSTATE_n =
      HITL_HEXA_Hovering_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S45>/Delay'
    HITL_HEXA_Hovering_DW.Delay_DSTATE_b =
      HITL_HEXA_Hovering_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S45>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S47>/yaw_In' incorporates:
    //   Outport: '<S47>/yaw_Out'

    HITL_HEXA_Hovering_B.yaw_In_i = HITL_HEXA_Hovering_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S45>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S44>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S46>/In' incorporates:
    //   Outport: '<S46>/Out'

    HITL_HEXA_Hovering_B.In = HITL_HEXA_Hovering_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S44>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S36>/Land'

    // SystemInitialize for IfAction SubSystem: '<S36>/Waypoint'
    // Start for MATLABSystem: '<S41>/UAV Waypoint Follower'
    HITL_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
    HITL_HEXA_Hovering_DW.obj.StartFlag = true;
    HITL_HEXA_Hovering_DW.obj.LookaheadFactor = 1.01;
    HITL_HEXA_Hovering_DW.obj.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S41>/UAV Waypoint Follower'
    HITL_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    memset(&HITL_HEXA_Hovering_DW.obj.WaypointsInternal[0], 0, 9U * sizeof
           (real_T));

    // End of SystemInitialize for SubSystem: '<S36>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S36>/IDLE'
    // InitializeConditions for Delay: '<S42>/Delay'
    HITL_HEXA_Hovering_DW.Delay_DSTATE =
      HITL_HEXA_Hovering_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S42>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S43>/yaw_In' incorporates:
    //   Outport: '<S43>/yaw_Out'

    HITL_HEXA_Hovering_B.yaw_In = HITL_HEXA_Hovering_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S42>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S36>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S4>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S528>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE =
      HITL_HEXA_Hovering_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S533>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE =
      HITL_HEXA_Hovering_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S580>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_n =
      HITL_HEXA_Hovering_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S585>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE_c =
      HITL_HEXA_Hovering_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Gain: '<S75>/Gain1' incorporates:
    //   Outport: '<S75>/des_pitch'

    HITL_HEXA_Hovering_B.Gain1 = HITL_HEXA_Hovering_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S75>/des_roll' incorporates:
    //   Saturate: '<S388>/Saturation'

    HITL_HEXA_Hovering_B.Saturation[1] = HITL_HEXA_Hovering_P.des_roll_Y0;

    // SystemInitialize for Gain: '<S486>/Proportional Gain' incorporates:
    //   Outport: '<S75>/des_yawrate'
    //   Saturate: '<S488>/Saturation'

    HITL_HEXA_Hovering_B.Saturation_e = HITL_HEXA_Hovering_P.des_yawrate_Y0;

    // SystemInitialize for Sum: '<S594>/Sum' incorporates:
    //   Outport: '<S75>/tau_Thrust'
    //   Saturate: '<S592>/Saturation'

    HITL_HEXA_Hovering_B.Saturation_f = HITL_HEXA_Hovering_P.tau_Thrust_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S4>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S118>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE_k =
      HITL_HEXA_Hovering_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S113>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_e =
      HITL_HEXA_Hovering_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S72>/Rate Limiter2'
    HITL_HEXA_Hovering_DW.PrevY = HITL_HEXA_Hovering_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S170>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE_kd =
      HITL_HEXA_Hovering_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S165>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_ek =
      HITL_HEXA_Hovering_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S72>/Rate Limiter1'
    HITL_HEXA_Hovering_DW.PrevY_f = HITL_HEXA_Hovering_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S222>/Integrator'
    HITL_HEXA_Hovering_DW.Integrator_DSTATE_i =
      HITL_HEXA_Hovering_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S217>/Filter'
    HITL_HEXA_Hovering_DW.Filter_DSTATE_j =
      HITL_HEXA_Hovering_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S125>/Saturation' incorporates:
    //   Outport: '<S72>/tau_Yaw'

    HITL_HEXA_Hovering_B.Saturation_l = HITL_HEXA_Hovering_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S177>/Saturation' incorporates:
    //   Outport: '<S72>/tau_Pitch'

    HITL_HEXA_Hovering_B.Saturation_o = HITL_HEXA_Hovering_P.tau_Pitch_Y0;

    // SystemInitialize for Sum: '<S231>/Sum' incorporates:
    //   Outport: '<S72>/tau_Roll'
    //   Saturate: '<S229>/Saturation'

    HITL_HEXA_Hovering_B.Saturation_m = HITL_HEXA_Hovering_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S37>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S66>/If Action Subsystem2'
    // Start for MATLABSystem: '<S69>/Read Parameter'
    HITL_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_g.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter_SampleTime_c;
    HITL_HEXA_Hovering_DW.obj_g.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_g.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S69>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S66>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S66>/If Action Subsystem1'
    // Start for MATLABSystem: '<S68>/Read Parameter'
    HITL_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_b.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter_SampleTime_g;
    HITL_HEXA_Hovering_DW.obj_b.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_b.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S68>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S66>/If Action Subsystem1'
    HITL_HEXA_Hovering_MATLABSystem_Init(&HITL_HEXA_Hovering_DW.MATLABSystem);
    HITL_HEXA_Hovering_MATLABSystem_Init(&HITL_HEXA_Hovering_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S63>/MATLAB System'
    HITL_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S65>/SinkBlock' incorporates:
    //   BusAssignment: '<S54>/Bus Assignment1'

    HITL_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_mc.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(HITL_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                          &HITL_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                          &HITL_HEXA_Hovering_B.BusAssignment1, 1);
    HITL_HEXA_Hovering_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S37>/Send waypoints to OBC'
    HITL_HEXA_Hovering_SourceBlock_Init(&HITL_HEXA_Hovering_DW.SourceBlock);

    // Start for MATLABSystem: '<S26>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_gv.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_gv.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_gv.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S23>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_po.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_po.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_po.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_po.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S24>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_d0.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_d0.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_d0.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_d0.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_d0.isSetupComplete = true;
    HITL_HEXA_Hovering_SourceBlock_Init(&HITL_HEXA_Hovering_DW.SourceBlock_b);

    // Start for MATLABSystem: '<S27>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_mg.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_mg.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_mg.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_mg.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_mg.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_mg.isSetupComplete = true;

    // Start for MATLABSystem: '<S37>/Read Parameter'
    HITL_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_k.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter_SampleTime;
    HITL_HEXA_Hovering_DW.obj_k.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_k.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S37>/Read Parameter'

    // Start for MATLABSystem: '<S58>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_e.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_e.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_e.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S56>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_kz.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_kz.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S55>/SourceBlock'
    HITL_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_gf.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_gf.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(HITL_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
                         &HITL_HEXA_Hovering_DW.obj_gf.eventStructObj);
    HITL_HEXA_Hovering_DW.obj_gf.isSetupComplete = true;

    // Start for MATLABSystem: '<S37>/LLA2LocalCoordinates'
    HITL_HEXA_Hovering_DW.obj_mr.previousValidReceived = false;
    HITL_HEXA_Hovering_DW.obj_mr.nextValidReceived = false;
    HITL_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_mr.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S7>/Read Parameter13'
    HITL_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_d.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter13_SampleTime;
    HITL_HEXA_Hovering_DW.obj_d.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_d.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter13'

    // Start for MATLABSystem: '<S7>/Read Parameter1'
    HITL_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_p.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter1_SampleTime;
    HITL_HEXA_Hovering_DW.obj_p.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_p.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_p.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter1'

    // Start for MATLABSystem: '<S7>/Read Parameter2'
    HITL_HEXA_Hovering_DW.obj_m0.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_m0.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter2_SampleTime;
    HITL_HEXA_Hovering_DW.obj_m0.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_m0.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_m0.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_m0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_m0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/Read Parameter3'
    HITL_HEXA_Hovering_DW.obj_be.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_be.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter3_SampleTime;
    HITL_HEXA_Hovering_DW.obj_be.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_be.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_be.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_be.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_be.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter3'

    // Start for MATLABSystem: '<S7>/Read Parameter4'
    HITL_HEXA_Hovering_DW.obj_gw.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_gw.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter4_SampleTime;
    HITL_HEXA_Hovering_DW.obj_gw.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_gw.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_gw.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_gw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_gw.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter4'

    // Start for MATLABSystem: '<S7>/Read Parameter5'
    HITL_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_m.SampleTime =
      HITL_HEXA_Hovering_P.ReadParameter5_SampleTime;
    HITL_HEXA_Hovering_DW.obj_m.isInitialized = 1;
    if (HITL_HEXA_Hovering_DW.obj_m.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = HITL_HEXA_Hovering_DW.obj_m.SampleTime;
    }

    HITL_HEXA_Hovering_DW.obj_m.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    HITL_HEXA_Hovering_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter5'

    // Start for MATLABSystem: '<S22>/SinkBlock' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment'

    HITL_HEXA_Hovering_DW.obj_nt.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_nt.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_nt.orbMetadataObj = ORB_ID(actuator_outputs_sim);
    uORB_write_initialize(HITL_HEXA_Hovering_DW.obj_nt.orbMetadataObj,
                          &HITL_HEXA_Hovering_DW.obj_nt.orbAdvertiseObj,
                          &HITL_HEXA_Hovering_B.BusAssignment, 1);
    HITL_HEXA_Hovering_DW.obj_nt.isSetupComplete = true;

    // Start for MATLABSystem: '<S53>/PX4 Timestamp'
    HITL_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = false;
    HITL_HEXA_Hovering_DW.obj_n.isInitialized = 1;
    HITL_HEXA_Hovering_DW.obj_n.isSetupComplete = true;
  }
}

// Model terminate function
void HITL_HEXA_Hovering_terminate(void)
{
  HITL_HEXA_Hovering_SourceBlock_Term(&HITL_HEXA_Hovering_DW.SourceBlock);

  // Terminate for MATLABSystem: '<S26>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_gv.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S26>/SourceBlock'

  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_po.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'

  // Terminate for MATLABSystem: '<S24>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_d0.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_d0.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S24>/SourceBlock'
  HITL_HEXA_Hovering_SourceBlock_Term(&HITL_HEXA_Hovering_DW.SourceBlock_b);

  // Terminate for MATLABSystem: '<S27>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_mg.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_mg.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_mg.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_mg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S27>/SourceBlock'

  // Terminate for MATLABSystem: '<S37>/Read Parameter'
  if (!HITL_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S37>/Read Parameter'

  // Terminate for MATLABSystem: '<S58>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_e.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S58>/SourceBlock'

  // Terminate for MATLABSystem: '<S56>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_kz.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S56>/SourceBlock'

  // Terminate for MATLABSystem: '<S55>/SourceBlock'
  if (!HITL_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_gf.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate(&HITL_HEXA_Hovering_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S55>/SourceBlock'

  // Terminate for MATLABSystem: '<S37>/LLA2LocalCoordinates'
  if (!HITL_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S37>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S7>/Read Parameter13'
  if (!HITL_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter13'

  // Terminate for MATLABSystem: '<S7>/Read Parameter1'
  if (!HITL_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter1'

  // Terminate for MATLABSystem: '<S7>/Read Parameter2'
  if (!HITL_HEXA_Hovering_DW.obj_m0.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_m0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/Read Parameter3'
  if (!HITL_HEXA_Hovering_DW.obj_be.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_be.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter3'

  // Terminate for MATLABSystem: '<S7>/Read Parameter4'
  if (!HITL_HEXA_Hovering_DW.obj_gw.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_gw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter4'

  // Terminate for MATLABSystem: '<S7>/Read Parameter5'
  if (!HITL_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter5'

  // Terminate for MATLABSystem: '<S22>/SinkBlock'
  if (!HITL_HEXA_Hovering_DW.obj_nt.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_nt.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_nt.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_nt.isSetupComplete) {
      uORB_write_terminate(&HITL_HEXA_Hovering_DW.obj_nt.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SinkBlock'

  // Terminate for Enabled SubSystem: '<S37>/Send waypoints to OBC'
  HITL_HEXA_Hovering_MATLABSystem_Term(&HITL_HEXA_Hovering_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S66>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S69>/Read Parameter'
  if (!HITL_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/Read Parameter'
  // End of Terminate for SubSystem: '<S66>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S66>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S68>/Read Parameter'
  if (!HITL_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S68>/Read Parameter'
  // End of Terminate for SubSystem: '<S66>/If Action Subsystem1'
  HITL_HEXA_Hovering_MATLABSystem_Term(&HITL_HEXA_Hovering_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S63>/MATLAB System'
  if (!HITL_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S63>/MATLAB System'

  // Terminate for MATLABSystem: '<S65>/SinkBlock'
  if (!HITL_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((HITL_HEXA_Hovering_DW.obj_mc.isInitialized == 1) &&
        HITL_HEXA_Hovering_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&HITL_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S65>/SinkBlock'
  // End of Terminate for SubSystem: '<S37>/Send waypoints to OBC'

  // Terminate for MATLABSystem: '<S53>/PX4 Timestamp'
  if (!HITL_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted) {
    HITL_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S53>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
