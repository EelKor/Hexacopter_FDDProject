//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering.cpp
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.25
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Oct 16 16:25:30 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FLIGHT_HEXA_Hovering.h"
#include "rtwtypes.h"
#include "FLIGHT_HEXA_Hovering_types.h"
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
const real_T FLIGHT_HEXA_Hovering_period = 0.004;

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
static real_T FLIGHT_HEXA_Hovering_rt_remd_snf(real_T u0, real_T u1);
static real_T FLIGHT_HEXA_Hovering_sind_d(real_T x);
static real_T FLIGHT_HEXA_Hovering_rt_atan2d_snf(real_T u0, real_T u1);
static void FLIGHT_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0
  [3], real_T xyzNED[3]);
static real_T FLIGHT_HEXA_Hovering_norm(const real_T x[3]);
static void FLIGHT_HEXA_Hovering_PWM_setupImpl
  (px4_internal_block_PWM_FLIGHT_HEXA_Hovering_T *obj, boolean_T armPWM,
   boolean_T forceFailsafe);
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

  // Start for MATLABSystem: '<S51>/MATLAB System'
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

  // End of Start for MATLABSystem: '<S51>/MATLAB System'
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
  // Start for MATLABSystem: '<S51>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_HEXA_Hovering_MATLABSystem(const real_T rtu_0[3], const real_T
  rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_FLIGHT_HEXA_Hovering_T *localB)
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

  // MATLABSystem: '<S51>/MATLAB System'
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

    flat = FLIGHT_HEXA_Hovering_sind(rtu_1[0]);
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

  // End of MATLABSystem: '<S51>/MATLAB System'
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_MATLABSystem_Term
  (DW_MATLABSystem_FLIGHT_HEXA_Hovering_T *localDW)
{
  // Terminate for MATLABSystem: '<S51>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/MATLAB System'
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

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S54>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = FLIGHT_HEXA_Hovering_rt_remd_snf(x, 360.0);
    FLIGHT_HEXA_Hovering_B.absx_b = fabs(b_x);
    if (FLIGHT_HEXA_Hovering_B.absx_b > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      FLIGHT_HEXA_Hovering_B.absx_b = fabs(b_x);
    }

    if (FLIGHT_HEXA_Hovering_B.absx_b <= 45.0) {
      b_x = sin(0.017453292519943295 * b_x);
    } else if (FLIGHT_HEXA_Hovering_B.absx_b <= 135.0) {
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

  // End of Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  return b_x;
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
      FLIGHT_HEXA_Hovering_B.i1_m = 1;
    } else {
      FLIGHT_HEXA_Hovering_B.i1_m = -1;
    }

    y = atan2(static_cast<real_T>(FLIGHT_HEXA_Hovering_B.i), static_cast<real_T>
              (FLIGHT_HEXA_Hovering_B.i1_m));
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

static void FLIGHT_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0
  [3], real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  FLIGHT_HEXA_Hovering_B.dLat = lla[0] - lla0[0];
  FLIGHT_HEXA_Hovering_B.dLon = lla[1] - lla0[1];
  FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
  if (FLIGHT_HEXA_Hovering_B.flat > 180.0) {
    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.dLat + 180.0) || rtIsInf
        (FLIGHT_HEXA_Hovering_B.dLat + 180.0)) {
      FLIGHT_HEXA_Hovering_B.flat = (rtNaN);
    } else if (FLIGHT_HEXA_Hovering_B.dLat + 180.0 == 0.0) {
      FLIGHT_HEXA_Hovering_B.flat = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.flat = fmod(FLIGHT_HEXA_Hovering_B.dLat + 180.0,
        360.0);
      if (FLIGHT_HEXA_Hovering_B.flat == 0.0) {
        FLIGHT_HEXA_Hovering_B.flat = 0.0;
      } else if (FLIGHT_HEXA_Hovering_B.dLat + 180.0 < 0.0) {
        FLIGHT_HEXA_Hovering_B.flat += 360.0;
      }
    }

    FLIGHT_HEXA_Hovering_B.dLat = FLIGHT_HEXA_Hovering_B.dLat * 0.0 +
      (FLIGHT_HEXA_Hovering_B.flat - 180.0);
    FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
  }

  if (FLIGHT_HEXA_Hovering_B.flat > 90.0) {
    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
    FLIGHT_HEXA_Hovering_B.latp2_p = (FLIGHT_HEXA_Hovering_B.flat > 90.0);

    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_B.dLon += 180.0;
    FLIGHT_HEXA_Hovering_B.Rn = FLIGHT_HEXA_Hovering_B.dLat * static_cast<real_T>
      (FLIGHT_HEXA_Hovering_B.latp2_p);
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Rn)) {
      FLIGHT_HEXA_Hovering_B.Rn = (rtNaN);
    } else if (FLIGHT_HEXA_Hovering_B.Rn < 0.0) {
      FLIGHT_HEXA_Hovering_B.Rn = -1.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Rn = (FLIGHT_HEXA_Hovering_B.Rn > 0.0);
    }

    FLIGHT_HEXA_Hovering_B.dLat = (90.0 - (FLIGHT_HEXA_Hovering_B.flat *
      static_cast<real_T>(FLIGHT_HEXA_Hovering_B.latp2_p) - 90.0)) *
      FLIGHT_HEXA_Hovering_B.Rn * static_cast<real_T>
      (FLIGHT_HEXA_Hovering_B.latp2_p) + FLIGHT_HEXA_Hovering_B.dLat *
      static_cast<real_T>(!FLIGHT_HEXA_Hovering_B.latp2_p);
  }

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  if ((FLIGHT_HEXA_Hovering_B.dLon > 180.0) || (FLIGHT_HEXA_Hovering_B.dLon <
       -180.0)) {
    FLIGHT_HEXA_Hovering_B.flat = FLIGHT_HEXA_Hovering_rt_remd_snf
      (FLIGHT_HEXA_Hovering_B.dLon, 360.0);
    FLIGHT_HEXA_Hovering_B.Rn = FLIGHT_HEXA_Hovering_B.flat / 180.0;
    if (FLIGHT_HEXA_Hovering_B.Rn < 0.0) {
      FLIGHT_HEXA_Hovering_B.Rn = ceil(FLIGHT_HEXA_Hovering_B.Rn);
    } else {
      FLIGHT_HEXA_Hovering_B.Rn = floor(FLIGHT_HEXA_Hovering_B.Rn);
    }

    FLIGHT_HEXA_Hovering_B.dLon = (FLIGHT_HEXA_Hovering_B.flat - 360.0 *
      FLIGHT_HEXA_Hovering_B.Rn) + FLIGHT_HEXA_Hovering_B.dLon * 0.0;
  }

  FLIGHT_HEXA_Hovering_B.flat = FLIGHT_HEXA_Hovering_sind_d(lla0[0]);
  FLIGHT_HEXA_Hovering_B.flat = 1.0 - 0.0066943799901413165 *
    FLIGHT_HEXA_Hovering_B.flat * FLIGHT_HEXA_Hovering_B.flat;
  FLIGHT_HEXA_Hovering_B.Rn = 6.378137E+6 / sqrt(FLIGHT_HEXA_Hovering_B.flat);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    FLIGHT_HEXA_Hovering_B.b_x = (rtNaN);
  } else {
    FLIGHT_HEXA_Hovering_B.b_x = FLIGHT_HEXA_Hovering_rt_remd_snf(lla0[0], 360.0);
    FLIGHT_HEXA_Hovering_B.absx = fabs(FLIGHT_HEXA_Hovering_B.b_x);
    if (FLIGHT_HEXA_Hovering_B.absx > 180.0) {
      if (FLIGHT_HEXA_Hovering_B.b_x > 0.0) {
        FLIGHT_HEXA_Hovering_B.b_x -= 360.0;
      } else {
        FLIGHT_HEXA_Hovering_B.b_x += 360.0;
      }

      FLIGHT_HEXA_Hovering_B.absx = fabs(FLIGHT_HEXA_Hovering_B.b_x);
    }

    if (FLIGHT_HEXA_Hovering_B.absx <= 45.0) {
      FLIGHT_HEXA_Hovering_B.b_x = cos(0.017453292519943295 *
        FLIGHT_HEXA_Hovering_B.b_x);
    } else if (FLIGHT_HEXA_Hovering_B.absx <= 135.0) {
      if (FLIGHT_HEXA_Hovering_B.b_x > 0.0) {
        FLIGHT_HEXA_Hovering_B.b_x = -sin((FLIGHT_HEXA_Hovering_B.b_x - 90.0) *
          0.017453292519943295);
      } else {
        FLIGHT_HEXA_Hovering_B.b_x = sin((FLIGHT_HEXA_Hovering_B.b_x + 90.0) *
          0.017453292519943295);
      }
    } else {
      if (FLIGHT_HEXA_Hovering_B.b_x > 0.0) {
        FLIGHT_HEXA_Hovering_B.b_x = (FLIGHT_HEXA_Hovering_B.b_x - 180.0) *
          0.017453292519943295;
      } else {
        FLIGHT_HEXA_Hovering_B.b_x = (FLIGHT_HEXA_Hovering_B.b_x + 180.0) *
          0.017453292519943295;
      }

      FLIGHT_HEXA_Hovering_B.b_x = -cos(FLIGHT_HEXA_Hovering_B.b_x);
    }
  }

  xyzNED[0] = FLIGHT_HEXA_Hovering_B.dLat / (FLIGHT_HEXA_Hovering_rt_atan2d_snf
    (1.0, 0.99330562000985867 / FLIGHT_HEXA_Hovering_B.flat *
     FLIGHT_HEXA_Hovering_B.Rn) * 57.295779513082323);
  xyzNED[1] = FLIGHT_HEXA_Hovering_B.dLon / (FLIGHT_HEXA_Hovering_rt_atan2d_snf
    (1.0, FLIGHT_HEXA_Hovering_B.Rn * FLIGHT_HEXA_Hovering_B.b_x) *
    57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  FLIGHT_HEXA_Hovering_B.b[0] = rtIsNaN(xyzNED[0]);
  FLIGHT_HEXA_Hovering_B.b[1] = rtIsNaN(xyzNED[1]);
  FLIGHT_HEXA_Hovering_B.b[2] = rtIsNaN(xyzNED[2]);
  FLIGHT_HEXA_Hovering_B.latp2_p = false;
  FLIGHT_HEXA_Hovering_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.b_k < 3)) {
    if (FLIGHT_HEXA_Hovering_B.b[FLIGHT_HEXA_Hovering_B.b_k]) {
      FLIGHT_HEXA_Hovering_B.latp2_p = true;
      exitg1 = true;
    } else {
      FLIGHT_HEXA_Hovering_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  FLIGHT_HEXA_Hovering_B.dLat = 0.0 / static_cast<real_T>
    (!FLIGHT_HEXA_Hovering_B.latp2_p);
  xyzNED[0] += FLIGHT_HEXA_Hovering_B.dLat;
  xyzNED[1] += FLIGHT_HEXA_Hovering_B.dLat;
  xyzNED[2] += FLIGHT_HEXA_Hovering_B.dLat;
}

static real_T FLIGHT_HEXA_Hovering_norm(const real_T x[3])
{
  real_T y;
  FLIGHT_HEXA_Hovering_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
  FLIGHT_HEXA_Hovering_B.absxk = fabs(x[0]);
  if (FLIGHT_HEXA_Hovering_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    FLIGHT_HEXA_Hovering_B.scale = FLIGHT_HEXA_Hovering_B.absxk;
  } else {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.absxk /
      3.3121686421112381E-170;
    y = FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t;
  }

  // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
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

  // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
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

static void FLIGHT_HEXA_Hovering_PWM_setupImpl
  (px4_internal_block_PWM_FLIGHT_HEXA_Hovering_T *obj, boolean_T armPWM,
   boolean_T forceFailsafe)
{
  obj->isMain = true;
  pwm_open(&obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->servoCount = 8;
  if (armPWM) {
    pwm_arm(&obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    pwm_disarm(&obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->channelMask = 63;
  if (obj->isMain) {
    if (forceFailsafe) {
      pwm_disarm(&obj->armAdvertiseObj);
    } else {
      pwm_arm(&obj->armAdvertiseObj);
    }
  }
}

// Model step function
void FLIGHT_HEXA_Hovering_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;

  // MATLABSystem: '<S18>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_m.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_m.eventStructObj, &FLIGHT_HEXA_Hovering_B.r2,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S24>/Enable'

  // Start for MATLABSystem: '<S18>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S24>/In1'
    FLIGHT_HEXA_Hovering_B.In1_c = FLIGHT_HEXA_Hovering_B.r2;
  }

  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'

  // MATLABSystem: '<S28>/Read Parameter'
  if (FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_p);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.ParamStep_p = 0;
  }

  // MATLABSystem: '<S49>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj, &FLIGHT_HEXA_Hovering_B.r,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S49>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S50>/Enable'

  // Start for MATLABSystem: '<S49>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S50>/In1'
    FLIGHT_HEXA_Hovering_B.In1 = FLIGHT_HEXA_Hovering_B.r;
  }

  // End of Outputs for SubSystem: '<S49>/Enabled Subsystem'

  // MATLABSystem: '<S47>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj, &FLIGHT_HEXA_Hovering_B.r1,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S47>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S62>/Enable'

  // Start for MATLABSystem: '<S47>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S62>/In1'
    FLIGHT_HEXA_Hovering_B.In1_p = FLIGHT_HEXA_Hovering_B.r1;
  }

  // End of Outputs for SubSystem: '<S47>/Enabled Subsystem'

  // MATLABSystem: '<S46>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj, &FLIGHT_HEXA_Hovering_B.r5,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S46>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S61>/Enable'

  // Start for MATLABSystem: '<S46>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S61>/In1'
    FLIGHT_HEXA_Hovering_B.In1_f = FLIGHT_HEXA_Hovering_B.r5;
  }

  // End of Outputs for SubSystem: '<S46>/Enabled Subsystem'

  // MATLABSystem: '<S28>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S28>/Read Parameter'
  //   SignalConversion generated from: '<S61>/In1'
  //
  FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] = 0.0;
  FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] = 0.0;
  FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] = 0.0;
  FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] = 0.0;
  FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] = 0.0;
  FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] = 0.0;
  FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] = 0.0;
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
    if (FLIGHT_HEXA_Hovering_B.ParamStep_p != 0) {
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
      FLIGHT_HEXA_Hovering_B.lla0, FLIGHT_HEXA_Hovering_B.VectorConcatenate);
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

  // If: '<S27>/If' incorporates:
  //   Delay: '<S33>/Delay'
  //   Delay: '<S36>/Delay'
  //   Delay: '<S40>/Delay'
  //   MATLABSystem: '<S28>/LLA2LocalCoordinates'
  //
  FLIGHT_HEXA_Hovering_B.rtPrevAction =
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem;
  if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 3) {
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = 0;
  } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 4) {
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = 1;
  } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 0) {
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = 2;
  } else {
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = 3;
  }

  switch (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem) {
   case 0:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S27>/Take-off' incorporates:
      //   ActionPort: '<S31>/Action Port'

      // InitializeConditions for If: '<S27>/If' incorporates:
      //   Delay: '<S39>/Delay'
      //   Delay: '<S40>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S27>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S27>/Take-off' incorporates:
    //   ActionPort: '<S31>/Action Port'

    // Sum: '<S39>/Sum' incorporates:
    //   Constant: '<S39>/Rate'
    //   Delay: '<S39>/Delay'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c += FLIGHT_HEXA_Hovering_P.Rate_Value;

    // Gain: '<S39>/Gain1'
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Gain1_Gain *
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S41>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S41>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In_ik = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S40>/Enabled Subsystem2'

    // Reshape: '<S31>/Reshape' incorporates:
    //   Delay: '<S40>/Delay'
    //   Merge: '<S27>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];

    // Gain: '<S39>/Gain' incorporates:
    //   Delay: '<S39>/Delay'
    //   RelationalOperator: '<S39>/Relational Operator'
    //   Switch: '<S39>/Switch'

    if (!(FLIGHT_HEXA_Hovering_B.Gain_i <=
          FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c)) {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c;
    }

    // Reshape: '<S31>/Reshape' incorporates:
    //   Gain: '<S39>/Gain'
    //   Merge: '<S27>/Merge'
    //   Switch: '<S39>/Switch'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_P.Gain_Gain *
      FLIGHT_HEXA_Hovering_B.Gain_i;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In_ik;

    // Update for Delay: '<S40>/Delay' incorporates:
    //   Constant: '<S40>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
      FLIGHT_HEXA_Hovering_P.Constant_Value_f;

    // End of Outputs for SubSystem: '<S27>/Take-off'
    break;

   case 1:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S27>/Land' incorporates:
      //   ActionPort: '<S30>/Action Port'

      // InitializeConditions for If: '<S27>/If' incorporates:
      //   Delay: '<S30>/Delay'
      //   Delay: '<S35>/Delay'
      //   Delay: '<S36>/Delay'
      //   Gain: '<S35>/Gain1'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_m;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S27>/Land'
    }

    // Outputs for IfAction SubSystem: '<S27>/Land' incorporates:
    //   ActionPort: '<S30>/Action Port'

    // Switch: '<S30>/Switch' incorporates:
    //   Delay: '<S30>/Delay'
    //   Logic: '<S30>/OR'
    //   RelationalOperator: '<S30>/IsNaN'

    if ((!rtIsNaN(FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0])) && (!rtIsNaN
         (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1]))) {
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
    }

    // End of Switch: '<S30>/Switch'

    // Switch: '<S35>/Switch' incorporates:
    //   Delay: '<S35>/Delay'

    if (!(FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n >
          FLIGHT_HEXA_Hovering_P.Switch_Threshold)) {
      // Gain: '<S35>/Gain1' incorporates:
      //   Gain: '<S35>/Gain'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
        FLIGHT_HEXA_Hovering_P.Gain_Gain_l *
        FLIGHT_HEXA_Hovering_B.VectorConcatenate[2];
    }

    // End of Switch: '<S35>/Switch'

    // Sum: '<S35>/Subtract' incorporates:
    //   Constant: '<S35>/Rate of descent'

    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n -
      FLIGHT_HEXA_Hovering_P.Rateofdescent_Value;

    // Gain: '<S35>/Gain1' incorporates:
    //   Gain: '<S35>/Gain2'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_P.Gain2_Gain *
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S38>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S38>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In_i = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S36>/Enabled Subsystem2'

    // Reshape: '<S30>/Reshape' incorporates:
    //   Delay: '<S30>/Delay'
    //   Delay: '<S36>/Delay'
    //   Merge: '<S27>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0];
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1];

    // Switch: '<S35>/Switch1' incorporates:
    //   RelationalOperator: '<S35>/GreaterThan'

    if (!(FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n > FLIGHT_HEXA_Hovering_B.Gain_i))
    {
      // Gain: '<S35>/Gain1'
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_B.Gain_i;
    }

    // Reshape: '<S30>/Reshape' incorporates:
    //   Gain: '<S35>/Gain1'
    //   Merge: '<S27>/Merge'
    //   Switch: '<S35>/Switch1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_a
      * FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S37>/Enable'

    if (FLIGHT_HEXA_Hovering_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S37>/In'
      FLIGHT_HEXA_Hovering_B.In = FLIGHT_HEXA_Hovering_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

    // Update for Delay: '<S30>/Delay' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] = FLIGHT_HEXA_Hovering_B.In1_c.x;
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] = FLIGHT_HEXA_Hovering_B.In1_c.y;

    // Update for Gain: '<S35>/Gain1' incorporates:
    //   Delay: '<S35>/Delay'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_B.In;

    // Update for Delay: '<S36>/Delay' incorporates:
    //   Constant: '<S36>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
      FLIGHT_HEXA_Hovering_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S27>/Land'
    break;

   case 2:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S27>/Waypoint' incorporates:
      //   ActionPort: '<S32>/Action Port'

      // SystemReset for If: '<S27>/If' incorporates:
      //   MATLABSystem: '<S32>/UAV Waypoint Follower'
      //
      FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
      for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
           FLIGHT_HEXA_Hovering_B.ParamStep_g < 9;
           FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
        FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[FLIGHT_HEXA_Hovering_B.ParamStep_g]
          *= 0.0;
      }

      // End of SystemReset for If: '<S27>/If'
      // End of SystemReset for SubSystem: '<S27>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
    //   ActionPort: '<S32>/Action Port'

    // Concatenate: '<S32>/Matrix Concatenate'
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0] =
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[0];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[1] =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[2] =
      FLIGHT_HEXA_Hovering_B.virtualWaypoint[0];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3] =
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[1];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[4] =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[5] =
      FLIGHT_HEXA_Hovering_B.virtualWaypoint[1];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[6] =
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[2];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[7] =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
    FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[8] =
      FLIGHT_HEXA_Hovering_B.virtualWaypoint[2];

    // MATLABSystem: '<S32>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S32>/Matrix Concatenate'
    //   Constant: '<S32>/Constant'

    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Constant_Value_gw;
    FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistFlag = 0U;
    if (FLIGHT_HEXA_Hovering_P.Constant_Value_gw < 0.3) {
      FLIGHT_HEXA_Hovering_B.Gain_i = 0.3;
      FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistFlag = 1U;
    }

    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[0] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[1] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[2] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.InitialPose[3] = 0.0;
    FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 3.0;
    FLIGHT_HEXA_Hovering_B.latp2 = false;
    FLIGHT_HEXA_Hovering_B.Compare_f = true;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.i1 <= 8)) {
      FLIGHT_HEXA_Hovering_B.ParamStep_g = FLIGHT_HEXA_Hovering_B.i1 / 3 * 3 +
        FLIGHT_HEXA_Hovering_B.i1 % 3;
      if (!(FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[FLIGHT_HEXA_Hovering_B.ParamStep_g]
            ==
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[FLIGHT_HEXA_Hovering_B.ParamStep_g]))
      {
        FLIGHT_HEXA_Hovering_B.Compare_f = false;
        exitg1 = true;
      } else {
        FLIGHT_HEXA_Hovering_B.i1++;
      }
    }

    if (FLIGHT_HEXA_Hovering_B.Compare_f) {
      FLIGHT_HEXA_Hovering_B.latp2 = true;
    }

    if (!FLIGHT_HEXA_Hovering_B.latp2) {
      memcpy(&FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[0],
             &FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    }

    for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
         FLIGHT_HEXA_Hovering_B.ParamStep_g < 3;
         FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.ParamStep_g]
        = true;
      FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
        [3 * FLIGHT_HEXA_Hovering_B.ParamStep_g + 1];
      FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.ParamStep_g << 1;
      FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.i1] =
        (FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 *
         FLIGHT_HEXA_Hovering_B.ParamStep_g] != FLIGHT_HEXA_Hovering_B.Gain2);
      FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.i1 + 1] =
        (FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 *
         FLIGHT_HEXA_Hovering_B.ParamStep_g + 2] != FLIGHT_HEXA_Hovering_B.Gain2);
    }

    FLIGHT_HEXA_Hovering_B.IsNaN_l[0] = false;
    FLIGHT_HEXA_Hovering_B.IsNaN_l[1] = false;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    FLIGHT_HEXA_Hovering_B.i2 = 4;
    for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
         FLIGHT_HEXA_Hovering_B.ParamStep_g < 2;
         FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
      FLIGHT_HEXA_Hovering_B.i1++;
      FLIGHT_HEXA_Hovering_B.i2++;
      FLIGHT_HEXA_Hovering_B.ParamStep_g1 = FLIGHT_HEXA_Hovering_B.i1;
      exitg1 = false;
      while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.ParamStep_g1 <=
                           FLIGHT_HEXA_Hovering_B.i2)) {
        if (FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.ParamStep_g1 - 1]) {
          FLIGHT_HEXA_Hovering_B.IsNaN_l[FLIGHT_HEXA_Hovering_B.ParamStep_g] =
            true;
          exitg1 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.ParamStep_g1 += 2;
        }
      }
    }

    FLIGHT_HEXA_Hovering_B.distinctWptsIdx[0] = FLIGHT_HEXA_Hovering_B.IsNaN_l[0];
    FLIGHT_HEXA_Hovering_B.distinctWptsIdx[1] = FLIGHT_HEXA_Hovering_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S27>/Waypoint'
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
         FLIGHT_HEXA_Hovering_B.ParamStep_g < 3;
         FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
      // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
      //   ActionPort: '<S32>/Action Port'

      if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.ParamStep_g])
      {
        FLIGHT_HEXA_Hovering_B.i1++;
      }

      // End of Outputs for SubSystem: '<S27>/Waypoint'
    }

    FLIGHT_HEXA_Hovering_B.ParamStep_g1 = FLIGHT_HEXA_Hovering_B.i1;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
         FLIGHT_HEXA_Hovering_B.ParamStep_g < 3;
         FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
      // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
      //   ActionPort: '<S32>/Action Port'

      if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.ParamStep_g])
      {
        // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
        FLIGHT_HEXA_Hovering_B.tmp_data[FLIGHT_HEXA_Hovering_B.i1] =
          static_cast<int8_T>(FLIGHT_HEXA_Hovering_B.ParamStep_g);
        FLIGHT_HEXA_Hovering_B.i1++;
      }

      // End of Outputs for SubSystem: '<S27>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
    //   ActionPort: '<S32>/Action Port'

    // MATLABSystem: '<S32>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S32>/Matrix Concatenate'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Reshape: '<S32>/Reshape1'

    for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
         FLIGHT_HEXA_Hovering_B.ParamStep_g < 3;
         FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
      for (FLIGHT_HEXA_Hovering_B.i2 = 0; FLIGHT_HEXA_Hovering_B.i2 <
           FLIGHT_HEXA_Hovering_B.ParamStep_g1; FLIGHT_HEXA_Hovering_B.i2++) {
        FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[FLIGHT_HEXA_Hovering_B.i2 +
          FLIGHT_HEXA_Hovering_B.ParamStep_g1 *
          FLIGHT_HEXA_Hovering_B.ParamStep_g] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 *
          FLIGHT_HEXA_Hovering_B.ParamStep_g +
          FLIGHT_HEXA_Hovering_B.tmp_data[FLIGHT_HEXA_Hovering_B.i2]];
      }
    }

    FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance =
      FLIGHT_HEXA_Hovering_B.Gain_i;
    if (FLIGHT_HEXA_Hovering_B.ParamStep_g1 == 0) {
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
        FLIGHT_HEXA_Hovering_B.In1_c.x;
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
        FLIGHT_HEXA_Hovering_B.In1_c.y;
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
        FLIGHT_HEXA_Hovering_B.In1_c.z;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
        FLIGHT_HEXA_Hovering_B.In1_c.heading;
    } else {
      guard1 = false;
      if (FLIGHT_HEXA_Hovering_B.ParamStep_g1 == 1) {
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

        FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
          FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[0] -
          FLIGHT_HEXA_Hovering_B.In1_c.x;
        FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] =
          FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[1] -
          FLIGHT_HEXA_Hovering_B.In1_c.y;
        FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
          FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[2] -
          FLIGHT_HEXA_Hovering_B.In1_c.z;
        if (FLIGHT_HEXA_Hovering_norm(FLIGHT_HEXA_Hovering_B.VectorConcatenate) <
            1.4901161193847656E-8) {
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x;
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y;
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z;
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
            FLIGHT_HEXA_Hovering_B.In1_c.heading;
          FLIGHT_HEXA_Hovering_DW.obj.StartFlag = false;
        } else {
          FLIGHT_HEXA_Hovering_DW.obj.StartFlag = false;
          FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 2.0;
          FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.ParamStep_g1 + 1;
          for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
               FLIGHT_HEXA_Hovering_B.ParamStep_g < 3;
               FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
              [(FLIGHT_HEXA_Hovering_B.ParamStep_g1 + 1) *
              FLIGHT_HEXA_Hovering_B.ParamStep_g] =
              FLIGHT_HEXA_Hovering_DW.obj.InitialPose[FLIGHT_HEXA_Hovering_B.ParamStep_g];
            for (FLIGHT_HEXA_Hovering_B.i2 = 0; FLIGHT_HEXA_Hovering_B.i2 <
                 FLIGHT_HEXA_Hovering_B.ParamStep_g1; FLIGHT_HEXA_Hovering_B.i2
                 ++) {
              FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
                [(FLIGHT_HEXA_Hovering_B.i2 +
                  (FLIGHT_HEXA_Hovering_B.ParamStep_g1 + 1) *
                  FLIGHT_HEXA_Hovering_B.ParamStep_g) + 1] =
                FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[FLIGHT_HEXA_Hovering_B.ParamStep_g1
                * FLIGHT_HEXA_Hovering_B.ParamStep_g + FLIGHT_HEXA_Hovering_B.i2];
            }
          }

          guard1 = true;
        }
      } else {
        FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.ParamStep_g1;
        FLIGHT_HEXA_Hovering_B.i2 = FLIGHT_HEXA_Hovering_B.ParamStep_g1 * 3;
        if (FLIGHT_HEXA_Hovering_B.i2 - 1 >= 0) {
          memcpy(&FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0],
                 &FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(FLIGHT_HEXA_Hovering_B.i2) * sizeof
                 (real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        FLIGHT_HEXA_Hovering_B.latp2 = false;
        if (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex ==
            FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints) {
          FLIGHT_HEXA_Hovering_B.latp2 = true;
        }

        if (FLIGHT_HEXA_Hovering_B.latp2) {
          FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
          FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex--;
        }

        FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_cx =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
        FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
          FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_cx;
        FLIGHT_HEXA_Hovering_B.Gain_i =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
          FLIGHT_HEXA_Hovering_B.Gain_i;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.In1_c.x - FLIGHT_HEXA_Hovering_B.Gain_i;
        FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
          FLIGHT_HEXA_Hovering_B.i1) - 1];
        FLIGHT_HEXA_Hovering_B.Gain2 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          FLIGHT_HEXA_Hovering_B.i1) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
          FLIGHT_HEXA_Hovering_B.Gain2;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.In1_c.y - FLIGHT_HEXA_Hovering_B.Gain2;
        FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[((FLIGHT_HEXA_Hovering_B.i1
          << 1) + static_cast<int32_T>(FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex))
          - 1];
        FLIGHT_HEXA_Hovering_B.Gain2 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          (FLIGHT_HEXA_Hovering_B.i1 << 1)) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
          FLIGHT_HEXA_Hovering_B.Gain2;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.In1_c.z - FLIGHT_HEXA_Hovering_B.Gain2;
        FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_norm
          (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        guard2 = false;
        if (FLIGHT_HEXA_Hovering_B.Gain2 <= 2.0) {
          guard2 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.lla0[0] = FLIGHT_HEXA_Hovering_B.Gain_i -
            FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_cx;
          FLIGHT_HEXA_Hovering_B.lla0[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            FLIGHT_HEXA_Hovering_B.i1) - 1] -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
            FLIGHT_HEXA_Hovering_B.i1) - 1];
          FLIGHT_HEXA_Hovering_B.Gain_i =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (FLIGHT_HEXA_Hovering_B.i1 << 1)) - 1];
          FLIGHT_HEXA_Hovering_B.lla0[2] = FLIGHT_HEXA_Hovering_B.Gain_i -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
            [((FLIGHT_HEXA_Hovering_B.i1 << 1) + static_cast<int32_T>
              (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex)) - 1];
          FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.lla0);
          FLIGHT_HEXA_Hovering_B.Gain_i = ((FLIGHT_HEXA_Hovering_B.In1_c.x -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1]) /
            FLIGHT_HEXA_Hovering_B.Gain2 * (FLIGHT_HEXA_Hovering_B.lla0[0] /
            FLIGHT_HEXA_Hovering_B.Gain1_m) + FLIGHT_HEXA_Hovering_B.lla0[1] /
            FLIGHT_HEXA_Hovering_B.Gain1_m *
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] /
             FLIGHT_HEXA_Hovering_B.Gain2)) + (FLIGHT_HEXA_Hovering_B.In1_c.z -
            FLIGHT_HEXA_Hovering_B.Gain_i) / FLIGHT_HEXA_Hovering_B.Gain2 *
            (FLIGHT_HEXA_Hovering_B.lla0[2] / FLIGHT_HEXA_Hovering_B.Gain1_m);
          if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain_i) ||
              (FLIGHT_HEXA_Hovering_B.Gain_i < 0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex++;
          FLIGHT_HEXA_Hovering_B.latp2 = false;
          if (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex ==
              FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints) {
            FLIGHT_HEXA_Hovering_B.latp2 = true;
          }

          if (FLIGHT_HEXA_Hovering_B.latp2) {
            FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
            FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex--;
          }

          FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
            FLIGHT_HEXA_Hovering_B.i1) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            FLIGHT_HEXA_Hovering_B.i1) - 1];
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
            [((FLIGHT_HEXA_Hovering_B.i1 << 1) + static_cast<int32_T>
              (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex)) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (FLIGHT_HEXA_Hovering_B.i1 << 1)) - 1];
        }

        FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.In1_c.x -
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[0];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] = FLIGHT_HEXA_Hovering_B.Sum_o;
        FLIGHT_HEXA_Hovering_B.Gain_i =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] -
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[0];
        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
          FLIGHT_HEXA_Hovering_B.In1_c.y -
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[1];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3;
        FLIGHT_HEXA_Hovering_B.Gain1_m =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] -
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[1];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_B.In1_c.z
          - FLIGHT_HEXA_Hovering_B.VectorConcatenate[2];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;
        FLIGHT_HEXA_Hovering_B.Gain4 =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] -
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[2];
        FLIGHT_HEXA_Hovering_B.Gain2 = (FLIGHT_HEXA_Hovering_B.Gain1_m *
          FLIGHT_HEXA_Hovering_B.Gain1_m + FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.Gain_i) + FLIGHT_HEXA_Hovering_B.Gain4 *
          FLIGHT_HEXA_Hovering_B.Gain4;
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
          FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 *
          FLIGHT_HEXA_Hovering_B.Gain1_m;
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = ((FLIGHT_HEXA_Hovering_B.Sum_o *
          FLIGHT_HEXA_Hovering_B.Gain_i + FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0)
          + FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
          FLIGHT_HEXA_Hovering_B.Gain4) / FLIGHT_HEXA_Hovering_B.Gain2;
        if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 < 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 > 1.0) {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        } else {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
             FLIGHT_HEXA_Hovering_B.Gain_i +
             FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
             FLIGHT_HEXA_Hovering_B.Gain1_m +
             FLIGHT_HEXA_Hovering_B.VectorConcatenate[1]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
             FLIGHT_HEXA_Hovering_B.Gain4 +
             FLIGHT_HEXA_Hovering_B.VectorConcatenate[2]);
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        }

        if (FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
            ((FLIGHT_HEXA_Hovering_B.Sum_o * FLIGHT_HEXA_Hovering_B.Gain_i +
              FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0) +
             (FLIGHT_HEXA_Hovering_B.In1_c.z -
              FLIGHT_HEXA_Hovering_B.VectorConcatenate[2]) *
             FLIGHT_HEXA_Hovering_B.Gain4) / FLIGHT_HEXA_Hovering_B.Gain2;
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
             FLIGHT_HEXA_Hovering_B.Gain_i +
             FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
             FLIGHT_HEXA_Hovering_B.Gain1_m +
             FLIGHT_HEXA_Hovering_B.VectorConcatenate[1]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
             FLIGHT_HEXA_Hovering_B.Gain4 +
             FLIGHT_HEXA_Hovering_B.VectorConcatenate[2]);
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        }

        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
          fabs(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2);
        if (rtIsInf
            (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3)
            || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3))
        {
          FLIGHT_HEXA_Hovering_B.Sum_o = (rtNaN);
          FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
            (rtNaN);
        } else if
            (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
             < 4.4501477170144028E-308) {
          FLIGHT_HEXA_Hovering_B.Sum_o = 4.94065645841247E-324;
          FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
            4.94065645841247E-324;
        } else {
          frexp
            (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3,
             &FLIGHT_HEXA_Hovering_B.ParamStep_c);
          FLIGHT_HEXA_Hovering_B.Sum_o = ldexp(1.0,
            FLIGHT_HEXA_Hovering_B.ParamStep_c - 53);
          frexp
            (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3,
             &FLIGHT_HEXA_Hovering_B.ParamStep_f);
          FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
            ldexp(1.0, FLIGHT_HEXA_Hovering_B.ParamStep_f - 53);
        }

        FLIGHT_HEXA_Hovering_B.Sum_o = sqrt(FLIGHT_HEXA_Hovering_B.Sum_o);
        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 *=
          5.0;
        if ((FLIGHT_HEXA_Hovering_B.Sum_o >=
             FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3)
            || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3))
        {
          FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
            FLIGHT_HEXA_Hovering_B.Sum_o;
        }

        if (FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance <=
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 +
            FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3)
        {
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance =
            FLIGHT_HEXA_Hovering_DW.obj.LookaheadFactor *
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;
        }

        FLIGHT_HEXA_Hovering_B.lla0[0] =
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] -
          FLIGHT_HEXA_Hovering_B.In1_c.x;
        FLIGHT_HEXA_Hovering_B.lla0[1] =
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] -
          FLIGHT_HEXA_Hovering_B.In1_c.y;
        FLIGHT_HEXA_Hovering_B.lla0[2] =
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] -
          FLIGHT_HEXA_Hovering_B.In1_c.z;
        FLIGHT_HEXA_Hovering_B.Gain_i = ((FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.lla0[0] + FLIGHT_HEXA_Hovering_B.Gain1_m *
          FLIGHT_HEXA_Hovering_B.lla0[1]) + FLIGHT_HEXA_Hovering_B.Gain4 *
          FLIGHT_HEXA_Hovering_B.lla0[2]) * 2.0;
        FLIGHT_HEXA_Hovering_B.Gain1_m = sqrt(FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.Gain_i - (((FLIGHT_HEXA_Hovering_B.lla0[0] *
          FLIGHT_HEXA_Hovering_B.lla0[0] + FLIGHT_HEXA_Hovering_B.lla0[1] *
          FLIGHT_HEXA_Hovering_B.lla0[1]) + FLIGHT_HEXA_Hovering_B.lla0[2] *
          FLIGHT_HEXA_Hovering_B.lla0[2]) -
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance *
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance) * (4.0 *
          FLIGHT_HEXA_Hovering_B.Gain2));
        FLIGHT_HEXA_Hovering_B.Sum_o = (-FLIGHT_HEXA_Hovering_B.Gain_i +
          FLIGHT_HEXA_Hovering_B.Gain1_m) / 2.0 / FLIGHT_HEXA_Hovering_B.Gain2;
        FLIGHT_HEXA_Hovering_B.Gain_i = (-FLIGHT_HEXA_Hovering_B.Gain_i -
          FLIGHT_HEXA_Hovering_B.Gain1_m) / 2.0 / FLIGHT_HEXA_Hovering_B.Gain2;
        if ((FLIGHT_HEXA_Hovering_B.Sum_o >= FLIGHT_HEXA_Hovering_B.Gain_i) ||
            rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain_i)) {
          FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.Sum_o;
        }

        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] = (1.0 -
          FLIGHT_HEXA_Hovering_B.Gain_i) *
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] +
          FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] = (1.0 -
          FLIGHT_HEXA_Hovering_B.Gain_i) *
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] +
          FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] = (1.0 -
          FLIGHT_HEXA_Hovering_B.Gain_i) *
          FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] +
          FLIGHT_HEXA_Hovering_B.Gain_i *
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
          FLIGHT_HEXA_Hovering_rt_atan2d_snf
          (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] -
           FLIGHT_HEXA_Hovering_B.In1_c.y,
           FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] -
           FLIGHT_HEXA_Hovering_B.In1_c.x);
        FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S42>/Switch1' incorporates:
    //   Constant: '<S43>/Constant'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Logic: '<S42>/OR'
    //   Logic: '<S42>/OR1'
    //   MATLABSystem: '<S32>/UAV Waypoint Follower'
    //   Merge: '<S27>/Merge'
    //   RelationalOperator: '<S42>/IsNaN'
    //   RelationalOperator: '<S42>/IsNaN1'
    //   RelationalOperator: '<S43>/Compare'
    //   Switch: '<S42>/Switch'
    //
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2]) ||
        (FLIGHT_HEXA_Hovering_B.In1_p.current.type ==
         FLIGHT_HEXA_Hovering_P.CompareToConstant_const_d)) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 = FLIGHT_HEXA_Hovering_B.In1_c.y;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_B.In1_c.z;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
        FLIGHT_HEXA_Hovering_B.In1_c.heading;
    } else {
      if (rtIsNaN(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3)) {
        // Switch: '<S42>/Switch' incorporates:
        //   Constant: '<S42>/Constant'
        //   Merge: '<S27>/Merge'
        //   Reshape: '<S42>/Reshape2'

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
          FLIGHT_HEXA_Hovering_P.Constant_Value_jd;
      }

      // Math: '<S42>/Transpose1' incorporates:
      //   Merge: '<S27>/Merge'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
    }

    // End of Switch: '<S42>/Switch1'
    // End of Outputs for SubSystem: '<S27>/Waypoint'
    break;

   default:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S27>/IDLE' incorporates:
      //   ActionPort: '<S29>/Action Port'

      // InitializeConditions for If: '<S27>/If' incorporates:
      //   Delay: '<S33>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S27>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S27>/IDLE' incorporates:
    //   ActionPort: '<S29>/Action Port'

    // Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S34>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S34>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S33>/Enabled Subsystem2'

    // Reshape: '<S29>/Reshape1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Delay: '<S33>/Delay'
    //   Merge: '<S27>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 = FLIGHT_HEXA_Hovering_B.In1_c.y;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_B.In1_c.z;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In;

    // Update for Delay: '<S33>/Delay' incorporates:
    //   Constant: '<S33>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
      FLIGHT_HEXA_Hovering_P.Constant_Value_i;

    // End of Outputs for SubSystem: '<S27>/IDLE'
    break;
  }

  // End of If: '<S27>/If'

  // MATLABSystem: '<S21>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_ah.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_ah.eventStructObj, &FLIGHT_HEXA_Hovering_B.r3,
     false, 5000.0);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S22>/Enable'

  // Start for MATLABSystem: '<S21>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S22>/In1'
    FLIGHT_HEXA_Hovering_B.In1_j = FLIGHT_HEXA_Hovering_B.r3;
  }

  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'

  // Gain: '<S65>/Gain2' incorporates:
  //   Constant: '<S65>/Constant2'
  //   Sum: '<S65>/Sum2'

  FLIGHT_HEXA_Hovering_B.Sum_o = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[1]) -
    FLIGHT_HEXA_Hovering_P.Constant2_Value_b) *
    FLIGHT_HEXA_Hovering_P.Gain2_Gain_j;

  // Saturate: '<S65>/Saturation2'
  if (FLIGHT_HEXA_Hovering_B.Sum_o > FLIGHT_HEXA_Hovering_P.Saturation2_UpperSat)
  {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation2_UpperSat;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation2_LowerSat) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation2_LowerSat;
  }

  // Gain: '<S4>/Gain1' incorporates:
  //   Saturate: '<S65>/Saturation2'

  FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_P.Gain1_Gain_hq *
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // Gain: '<S65>/Gain1' incorporates:
  //   Constant: '<S65>/Constant1'
  //   Sum: '<S65>/Sum1'

  FLIGHT_HEXA_Hovering_B.Sum_o = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[0]) -
    FLIGHT_HEXA_Hovering_P.Constant1_Value_d) *
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_mu;

  // Saturate: '<S65>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_p) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_p;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_e) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_e;
  }

  // Gain: '<S4>/Gain2' incorporates:
  //   Saturate: '<S65>/Saturation1'

  FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_P.Gain2_Gain_b *
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // Gain: '<S65>/Gain' incorporates:
  //   Constant: '<S65>/Constant'
  //   Sum: '<S65>/Sum'

  FLIGHT_HEXA_Hovering_B.Gain_i = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[2]) -
    FLIGHT_HEXA_Hovering_P.Constant_Value_bk) *
    FLIGHT_HEXA_Hovering_P.Gain_Gain_k;

  // Saturate: '<S65>/Saturation'
  if (FLIGHT_HEXA_Hovering_B.Gain_i >
      FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_c) {
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_c;
  } else if (FLIGHT_HEXA_Hovering_B.Gain_i <
             FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_g) {
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_g;
  }

  // End of Saturate: '<S65>/Saturation'

  // Gain: '<S65>/Gain3' incorporates:
  //   Constant: '<S65>/Constant3'
  //   Sum: '<S65>/Sum3'

  FLIGHT_HEXA_Hovering_B.Sum_o = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[3]) -
    FLIGHT_HEXA_Hovering_P.Constant3_Value_a) *
    FLIGHT_HEXA_Hovering_P.Gain3_Gain;

  // Saturate: '<S65>/Saturation3'
  if (FLIGHT_HEXA_Hovering_B.Sum_o > FLIGHT_HEXA_Hovering_P.Saturation3_UpperSat)
  {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation3_UpperSat;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation3_LowerSat) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation3_LowerSat;
  }

  // Gain: '<S4>/Gain4' incorporates:
  //   Saturate: '<S65>/Saturation3'

  FLIGHT_HEXA_Hovering_B.Gain4 = FLIGHT_HEXA_Hovering_P.Gain4_Gain *
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // MATLABSystem: '<S17>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_gv.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_gv.eventStructObj, &FLIGHT_HEXA_Hovering_B.r4,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  // Start for MATLABSystem: '<S17>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S23>/In1'
    FLIGHT_HEXA_Hovering_B.In1_m = FLIGHT_HEXA_Hovering_B.r4;
  }

  // End of Outputs for SubSystem: '<S17>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   SignalConversion generated from: '<S5>/Product1'

  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
    FLIGHT_HEXA_Hovering_B.In1_m.q[0];
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
    FLIGHT_HEXA_Hovering_B.In1_m.q[1];
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
    FLIGHT_HEXA_Hovering_B.In1_m.q[2];
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
    FLIGHT_HEXA_Hovering_B.In1_m.q[3];

  // Switch: '<S67>/Switch' incorporates:
  //   Constant: '<S67>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   Product: '<S593>/Product'
  //   Product: '<S593>/Product1'
  //   Product: '<S593>/Product2'
  //   Product: '<S593>/Product3'
  //   SignalConversion generated from: '<S5>/Product1'
  //   Sum: '<S593>/Sum'

  if (!(((static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_m.q[0]) *
          FLIGHT_HEXA_Hovering_B.In1_m.q[0] + static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.In1_m.q[1]) * FLIGHT_HEXA_Hovering_B.In1_m.q[1])
         + static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_m.q[2]) *
         FLIGHT_HEXA_Hovering_B.In1_m.q[2]) + static_cast<real_T>
        (FLIGHT_HEXA_Hovering_B.In1_m.q[3]) * FLIGHT_HEXA_Hovering_B.In1_m.q[3] >
        FLIGHT_HEXA_Hovering_P.Switch_Threshold_d)) {
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[0];
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[1];
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[2];
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[3];
  }

  // End of Switch: '<S67>/Switch'

  // Sqrt: '<S600>/sqrt' incorporates:
  //   Product: '<S601>/Product'
  //   Product: '<S601>/Product1'
  //   Product: '<S601>/Product2'
  //   Product: '<S601>/Product3'
  //   Sum: '<S601>/Sum'

  FLIGHT_HEXA_Hovering_B.Sum_o = sqrt
    (((FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 *
       FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 +
       FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *
       FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1) +
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2) +
     FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 *
     FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3);

  // Product: '<S595>/Product'
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 /=
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // Product: '<S595>/Product1'
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 /=
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // Product: '<S595>/Product2'
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 /=
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // Product: '<S595>/Product3'
  FLIGHT_HEXA_Hovering_B.Sum_o =
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 /
    FLIGHT_HEXA_Hovering_B.Sum_o;

  // Fcn: '<S68>/fcn2' incorporates:
  //   Fcn: '<S68>/fcn5'

  FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_cx =
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 *
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0;
  FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp =
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
  FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_c =
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 *
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;
  FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_k =
    FLIGHT_HEXA_Hovering_B.Sum_o * FLIGHT_HEXA_Hovering_B.Sum_o;

  // Trigonometry: '<S594>/Trigonometric Function1' incorporates:
  //   Fcn: '<S68>/fcn1'
  //   Fcn: '<S68>/fcn2'

  FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
    FLIGHT_HEXA_Hovering_rt_atan2d_snf
    ((FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 +
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 *
      FLIGHT_HEXA_Hovering_B.Sum_o) * 2.0,
     ((FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_cx +
       FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp) -
      FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_c) -
     FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_k);

  // Fcn: '<S68>/fcn3'
  FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
    (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *
     FLIGHT_HEXA_Hovering_B.Sum_o -
     FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 *
     FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2) *
    -2.0;

  // Trigonometry: '<S594>/Trigonometric Function3' incorporates:
  //   Fcn: '<S68>/fcn4'
  //   Fcn: '<S68>/fcn5'

  FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
    FLIGHT_HEXA_Hovering_rt_atan2d_snf
    ((FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 *
      FLIGHT_HEXA_Hovering_B.Sum_o +
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1) *
     2.0, ((FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_cx -
            FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp) -
           FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_c) +
     FLIGHT_HEXA_Hovering_B.rtb_VectorConcatenate_tmp_k);

  // MATLABSystem: '<S15>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_d0.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_d0.eventStructObj, &FLIGHT_HEXA_Hovering_B.r7,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  // Start for MATLABSystem: '<S15>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S20>/In1'
    FLIGHT_HEXA_Hovering_B.In1_b = FLIGHT_HEXA_Hovering_B.r7;
  }

  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S4>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S66>/Enable'

  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    // Trigonometry: '<S331>/SinCos'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 = sin
      (FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 = cos
      (FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);

    // Sum: '<S66>/Sum5'
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 -=
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[0];

    // Saturate: '<S429>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S427>/Proportional Gain'
    //   Sum: '<S66>/Sum1'

    FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 -
      FLIGHT_HEXA_Hovering_B.In1_c.x) *
      FLIGHT_HEXA_Hovering_P.PIDController1_P_h;
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e;
    }

    // Sum: '<S66>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S429>/Saturation'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.Sum_o -
      FLIGHT_HEXA_Hovering_B.In1_c.vx;

    // Saturate: '<S429>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S427>/Proportional Gain'
    //   Sum: '<S66>/Sum1'

    FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 -
      FLIGHT_HEXA_Hovering_B.In1_c.y) *
      FLIGHT_HEXA_Hovering_P.PIDController1_P_h;
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e;
    }

    // Sum: '<S66>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S429>/Saturation'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1 = FLIGHT_HEXA_Hovering_B.Sum_o -
      FLIGHT_HEXA_Hovering_B.In1_c.vy;

    // Saturate: '<S379>/Saturation' incorporates:
    //   Gain: '<S331>/Gain'
    //   Gain: '<S377>/Proportional Gain'
    //   Product: '<S66>/MatrixMultiply'
    //   Reshape: '<S331>/Reshape'
    //   Reshape: '<S331>/Reshape1'

    FLIGHT_HEXA_Hovering_B.Sum_o =
      (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *
       FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
       FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 *
       FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1) *
      FLIGHT_HEXA_Hovering_P.PIDController_P_d;
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b) {
      // Saturate: '<S379>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j) {
      // Saturate: '<S379>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j;
    } else {
      // Saturate: '<S379>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] = FLIGHT_HEXA_Hovering_B.Sum_o;
    }

    FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_P.Gain_Gain_o *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_1) *
      FLIGHT_HEXA_Hovering_P.PIDController_P_d;
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b) {
      // Saturate: '<S379>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j) {
      // Saturate: '<S379>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j;
    } else {
      // Saturate: '<S379>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] = FLIGHT_HEXA_Hovering_B.Sum_o;
    }

    // End of Saturate: '<S379>/Saturation'

    // Gain: '<S66>/Gain1'
    FLIGHT_HEXA_Hovering_B.Gain1 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_m *
      FLIGHT_HEXA_Hovering_B.Saturation[0];

    // Switch: '<S332>/Switch' incorporates:
    //   Abs: '<S332>/Abs'

    if (fabs(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3) >
        FLIGHT_HEXA_Hovering_P.Switch_Threshold_e) {
      // Switch: '<S332>/Switch1' incorporates:
      //   Constant: '<S332>/Constant'
      //   Sum: '<S332>/Add'
      //   Sum: '<S332>/Subtract'

      if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 >
          FLIGHT_HEXA_Hovering_P.Switch1_Threshold) {
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 -=
          FLIGHT_HEXA_Hovering_P.Constant_Value_g4;
      } else {
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 +=
          FLIGHT_HEXA_Hovering_P.Constant_Value_g4;
      }

      // End of Switch: '<S332>/Switch1'
    }

    // Gain: '<S477>/Proportional Gain' incorporates:
    //   Switch: '<S332>/Switch'

    FLIGHT_HEXA_Hovering_B.Saturation_a =
      FLIGHT_HEXA_Hovering_P.PIDController5_P *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Saturate: '<S479>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Saturation_a >
        FLIGHT_HEXA_Hovering_P.PIDController5_UpperSaturationLimit) {
      // Gain: '<S477>/Proportional Gain' incorporates:
      //   Saturate: '<S479>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_a =
        FLIGHT_HEXA_Hovering_P.PIDController5_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Saturation_a <
               FLIGHT_HEXA_Hovering_P.PIDController5_LowerSaturationLimit) {
      // Gain: '<S477>/Proportional Gain' incorporates:
      //   Saturate: '<S479>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_a =
        FLIGHT_HEXA_Hovering_P.PIDController5_LowerSaturationLimit;
    }

    // End of Saturate: '<S479>/Saturation'

    // Gain: '<S330>/Gain1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Gain1_Gain_h *
      FLIGHT_HEXA_Hovering_B.In1_c.z;

    // Switch: '<S338>/Switch' incorporates:
    //   Constant: '<S330>/Constant'
    //   RelationalOperator: '<S338>/UpperRelop'
    //   Switch: '<S338>/Switch2'

    if (FLIGHT_HEXA_Hovering_B.Sum_o < FLIGHT_HEXA_Hovering_P.Constant_Value_ib)
    {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Constant_Value_ib;
    }

    // Sum: '<S66>/Sum2' incorporates:
    //   Gain: '<S4>/Gain'
    //   Switch: '<S338>/Switch'
    //   Switch: '<S338>/Switch2'

    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
      FLIGHT_HEXA_Hovering_P.Gain_Gain_b *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 - FLIGHT_HEXA_Hovering_B.Sum_o;

    // Gain: '<S529>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_P *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;

    // Gain: '<S527>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S519>/Filter'
    //   Gain: '<S517>/Derivative Gain'
    //   Sum: '<S519>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
      (FLIGHT_HEXA_Hovering_P.PID_Altitude_D *
       FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 -
       FLIGHT_HEXA_Hovering_DW.Filter_DSTATE) *
      FLIGHT_HEXA_Hovering_P.PID_Altitude_N;

    // Sum: '<S534>/Sum Fdbk'
    FLIGHT_HEXA_Hovering_B.Sum_o =
      (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE) +
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // DeadZone: '<S516>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Sum_o -=
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o >=
               FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Sum_o = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Sum_o -=
        FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // End of DeadZone: '<S516>/DeadZone'

    // Gain: '<S521>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 *=
      FLIGHT_HEXA_Hovering_P.PID_Altitude_I;

    // Switch: '<S514>/Switch1' incorporates:
    //   Constant: '<S514>/Clamping_zero'
    //   Constant: '<S514>/Constant'
    //   Constant: '<S514>/Constant2'
    //   RelationalOperator: '<S514>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_nq;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_o;
    }

    // Switch: '<S514>/Switch2' incorporates:
    //   Constant: '<S514>/Clamping_zero'
    //   Constant: '<S514>/Constant3'
    //   Constant: '<S514>/Constant4'
    //   RelationalOperator: '<S514>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f) {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant3_Value_o;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant4_Value_d;
    }

    // Switch: '<S514>/Switch' incorporates:
    //   Constant: '<S514>/Clamping_zero'
    //   Constant: '<S514>/Constant1'
    //   Logic: '<S514>/AND3'
    //   RelationalOperator: '<S514>/Equal1'
    //   RelationalOperator: '<S514>/Relational Operator'
    //   Switch: '<S514>/Switch1'
    //   Switch: '<S514>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f !=
         FLIGHT_HEXA_Hovering_B.Sum_o) && (FLIGHT_HEXA_Hovering_B.rtPrevAction ==
         FLIGHT_HEXA_Hovering_B.i2_n)) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_l;
    }

    // DiscreteIntegrator: '<S524>/Integrator' incorporates:
    //   Switch: '<S514>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_p *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;

    // Sum: '<S533>/Sum'
    FLIGHT_HEXA_Hovering_B.Sum_o =
      (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE) +
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // Saturate: '<S531>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // Sum: '<S66>/Sum3' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S531>/Saturation'
    //   UnaryMinus: '<S66>/Unary Minus'

    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      FLIGHT_HEXA_Hovering_B.Sum_o - (-static_cast<real_T>
      (FLIGHT_HEXA_Hovering_B.In1_c.vz));

    // Gain: '<S581>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
      FLIGHT_HEXA_Hovering_P.PID_vz_P *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Gain: '<S579>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S571>/Filter'
    //   Gain: '<S569>/Derivative Gain'
    //   Sum: '<S571>/SumD'

    FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_P.PID_vz_D *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 -
      FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_o) * FLIGHT_HEXA_Hovering_P.PID_vz_N;

    // Sum: '<S586>/Sum Fdbk'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
      (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o) +
      FLIGHT_HEXA_Hovering_B.Sum_o;

    // DeadZone: '<S568>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 >
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 -=
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if
        (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 >=
         FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
        0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 -=
        FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S568>/DeadZone'

    // Gain: '<S573>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 *=
      FLIGHT_HEXA_Hovering_P.PID_vz_I;

    // Switch: '<S566>/Switch1' incorporates:
    //   Constant: '<S566>/Clamping_zero'
    //   Constant: '<S566>/Constant'
    //   Constant: '<S566>/Constant2'
    //   RelationalOperator: '<S566>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_a) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_d3;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_pb;
    }

    // Switch: '<S566>/Switch2' incorporates:
    //   Constant: '<S566>/Clamping_zero'
    //   Constant: '<S566>/Constant3'
    //   Constant: '<S566>/Constant4'
    //   RelationalOperator: '<S566>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_a) {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant3_Value_m;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant4_Value_c;
    }

    // Switch: '<S566>/Switch' incorporates:
    //   Constant: '<S566>/Clamping_zero'
    //   Constant: '<S566>/Constant1'
    //   Logic: '<S566>/AND3'
    //   RelationalOperator: '<S566>/Equal1'
    //   RelationalOperator: '<S566>/Relational Operator'
    //   Switch: '<S566>/Switch1'
    //   Switch: '<S566>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_a !=
         FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.i2_n)) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_f;
    }

    // DiscreteIntegrator: '<S576>/Integrator' incorporates:
    //   Switch: '<S566>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_k *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Sum: '<S585>/Sum'
    FLIGHT_HEXA_Hovering_B.Saturation_o =
      (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o) +
      FLIGHT_HEXA_Hovering_B.Sum_o;

    // Saturate: '<S583>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Saturation_o >
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      // Sum: '<S585>/Sum' incorporates:
      //   Saturate: '<S583>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Saturation_o <
               FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      // Sum: '<S585>/Sum' incorporates:
      //   Saturate: '<S583>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of Saturate: '<S583>/Saturation'

    // Update for DiscreteIntegrator: '<S519>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_i *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // Update for DiscreteIntegrator: '<S571>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_o +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_m * FLIGHT_HEXA_Hovering_B.Sum_o;
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
      FLIGHT_HEXA_Hovering_B.Gain4 = FLIGHT_HEXA_Hovering_B.Saturation_a;
      FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_B.Gain1;
      FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Saturation[1];
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.Saturation_o;
    }

    // case IN_STABLIZED:
  } else if (FLIGHT_HEXA_Hovering_B.In1_j.values[5] > 1400) {
    FLIGHT_HEXA_Hovering_DW.is_c3_FLIGHT_HEXA_Hovering =
      FLIGHT_HEXA_Hovering_IN_MISSION;
    FLIGHT_HEXA_Hovering_B.Gain4 = FLIGHT_HEXA_Hovering_B.Saturation_a;
    FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_B.Gain1;
    FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Saturation[1];
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.Saturation_o;
  }

  // End of Chart: '<S4>/Chart'

  // MATLABSystem: '<S14>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.latp2 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_po.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_po.eventStructObj, &FLIGHT_HEXA_Hovering_B.r6,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  // Start for MATLABSystem: '<S14>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    // SignalConversion generated from: '<S19>/In1'
    FLIGHT_HEXA_Hovering_B.In1_l = FLIGHT_HEXA_Hovering_B.r6;
  }

  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S4>/Attitude controller' incorporates:
  //   EnablePort: '<S63>/Enable'

  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    // Sum: '<S63>/Sum4' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'

    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
      FLIGHT_HEXA_Hovering_B.Gain4 - FLIGHT_HEXA_Hovering_B.In1_l.xyz[2];

    // Gain: '<S106>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      FLIGHT_HEXA_Hovering_P.PIDController_I *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;

    // Gain: '<S112>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S104>/Filter'
    //   Gain: '<S102>/Derivative Gain'
    //   Sum: '<S104>/SumD'

    FLIGHT_HEXA_Hovering_B.Gain4 = (FLIGHT_HEXA_Hovering_P.PIDController_D *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 -
      FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ov) *
      FLIGHT_HEXA_Hovering_P.PIDController_N;

    // Sum: '<S118>/Sum' incorporates:
    //   DiscreteIntegrator: '<S109>/Integrator'
    //   Gain: '<S114>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_P.PIDController_P *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i) +
      FLIGHT_HEXA_Hovering_B.Gain4;

    // DeadZone: '<S101>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
        FLIGHT_HEXA_Hovering_B.Sum_o -
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o >=
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
        0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 =
        FLIGHT_HEXA_Hovering_B.Sum_o -
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    }

    // End of DeadZone: '<S101>/DeadZone'

    // Switch: '<S99>/Switch1' incorporates:
    //   Constant: '<S99>/Clamping_zero'
    //   Constant: '<S99>/Constant'
    //   Constant: '<S99>/Constant2'
    //   RelationalOperator: '<S99>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_k;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_j;
    }

    // Switch: '<S99>/Switch2' incorporates:
    //   Constant: '<S99>/Clamping_zero'
    //   Constant: '<S99>/Constant3'
    //   Constant: '<S99>/Constant4'
    //   RelationalOperator: '<S99>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value) {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant3_Value_l;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant4_Value_o;
    }

    // Switch: '<S99>/Switch' incorporates:
    //   Constant: '<S99>/Clamping_zero'
    //   Constant: '<S99>/Constant1'
    //   Logic: '<S99>/AND3'
    //   RelationalOperator: '<S99>/Equal1'
    //   RelationalOperator: '<S99>/Relational Operator'
    //   Switch: '<S99>/Switch1'
    //   Switch: '<S99>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value !=
         FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.i2_n)) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_m;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
    }

    // End of Switch: '<S99>/Switch'

    // Saturate: '<S116>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S116>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_n =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      // Saturate: '<S116>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_n =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    } else {
      // Saturate: '<S116>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_n = FLIGHT_HEXA_Hovering_B.Sum_o;
    }

    // End of Saturate: '<S116>/Saturation'

    // RateLimiter: '<S63>/Rate Limiter2'
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.Gain1_m -
      FLIGHT_HEXA_Hovering_DW.PrevY;
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.RateLimiter2_RisingLim *
        FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_P.RateLimiter2_RisingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.RateLimiter2_FallingLim *
               FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_P.RateLimiter2_FallingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_B.Gain1_m;
    }

    FLIGHT_HEXA_Hovering_DW.PrevY =
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // End of RateLimiter: '<S63>/Rate Limiter2'

    // If: '<S596>/If' incorporates:
    //   Constant: '<S597>/Constant'
    //   Constant: '<S598>/Constant'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 >
        1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_ji;
    } else if
        (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 <
         -1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_hi;
    }

    // Saturate: '<S63>/Saturation1'
    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >
        FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat;
    } else if
        (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 <
         FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat;
    }

    // If: '<S596>/If' incorporates:
    //   Trigonometry: '<S594>/trigFcn'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 >
        1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
        1.0;
    } else if
        (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 <
         -1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
        -1.0;
    }

    // Sum: '<S63>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S268>/Proportional Gain'
    //   Saturate: '<S63>/Saturation1'
    //   Sum: '<S63>/Sum2'
    //   Trigonometry: '<S594>/trigFcn'

    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 -
       asin
       (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3)) *
      FLIGHT_HEXA_Hovering_P.PIDController3_P -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[1];

    // Gain: '<S158>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.PIDController1_I *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Gain: '<S164>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S156>/Filter'
    //   Gain: '<S154>/Derivative Gain'
    //   Sum: '<S156>/SumD'

    FLIGHT_HEXA_Hovering_B.Gain1_m = (FLIGHT_HEXA_Hovering_P.PIDController1_D *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 -
      FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_c) *
      FLIGHT_HEXA_Hovering_P.PIDController1_N;

    // Sum: '<S170>/Sum' incorporates:
    //   DiscreteIntegrator: '<S161>/Integrator'
    //   Gain: '<S166>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      (FLIGHT_HEXA_Hovering_P.PIDController1_P *
       FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_h) +
      FLIGHT_HEXA_Hovering_B.Gain1_m;

    // DeadZone: '<S153>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 -
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if
        (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >=
         FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
        0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 =
        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 -
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S153>/DeadZone'

    // Switch: '<S151>/Switch1' incorporates:
    //   Constant: '<S151>/Clamping_zero'
    //   Constant: '<S151>/Constant'
    //   Constant: '<S151>/Constant2'
    //   RelationalOperator: '<S151>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_e) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_bd;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_fs;
    }

    // Switch: '<S151>/Switch2' incorporates:
    //   Constant: '<S151>/Clamping_zero'
    //   Constant: '<S151>/Constant3'
    //   Constant: '<S151>/Constant4'
    //   RelationalOperator: '<S151>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_e) {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant3_Value_n;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant4_Value_n;
    }

    // Switch: '<S151>/Switch' incorporates:
    //   Constant: '<S151>/Clamping_zero'
    //   Constant: '<S151>/Constant1'
    //   Logic: '<S151>/AND3'
    //   RelationalOperator: '<S151>/Equal1'
    //   RelationalOperator: '<S151>/Relational Operator'
    //   Switch: '<S151>/Switch1'
    //   Switch: '<S151>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_e !=
         FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.i2_n)) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_c;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3 =
        FLIGHT_HEXA_Hovering_B.Sum_o;
    }

    // End of Switch: '<S151>/Switch'

    // Saturate: '<S168>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S168>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_b =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if
        (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 <
         FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      // Saturate: '<S168>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_b =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S168>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_b =
        FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
    }

    // End of Saturate: '<S168>/Saturation'

    // RateLimiter: '<S63>/Rate Limiter1'
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.Gain2 -
      FLIGHT_HEXA_Hovering_DW.PrevY_m;
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.RateLimiter1_RisingLim *
        FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.RateLimiter1_RisingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY_m;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.RateLimiter1_FallingLim *
               FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Sum_o =
        FLIGHT_HEXA_Hovering_P.RateLimiter1_FallingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY_m;
    } else {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.Gain2;
    }

    FLIGHT_HEXA_Hovering_DW.PrevY_m = FLIGHT_HEXA_Hovering_B.Sum_o;

    // End of RateLimiter: '<S63>/Rate Limiter1'

    // Saturate: '<S63>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat) {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation_UpperSat;
    } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat) {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation_LowerSat;
    }

    // Sum: '<S63>/Sum1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S318>/Proportional Gain'
    //   Saturate: '<S63>/Saturation'
    //   Sum: '<S63>/Sum3'

    FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_B.Sum_o -
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[2]) *
      FLIGHT_HEXA_Hovering_P.PIDController4_P -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[0];

    // Gain: '<S210>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
      FLIGHT_HEXA_Hovering_P.PIDController2_I * FLIGHT_HEXA_Hovering_B.Sum_o;

    // Gain: '<S216>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S208>/Filter'
    //   Gain: '<S206>/Derivative Gain'
    //   Sum: '<S208>/SumD'

    FLIGHT_HEXA_Hovering_B.Gain2 = (FLIGHT_HEXA_Hovering_P.PIDController2_D *
      FLIGHT_HEXA_Hovering_B.Sum_o - FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_f) *
      FLIGHT_HEXA_Hovering_P.PIDController2_N;

    // Sum: '<S222>/Sum' incorporates:
    //   DiscreteIntegrator: '<S213>/Integrator'
    //   Gain: '<S218>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.Saturation_a1 =
      (FLIGHT_HEXA_Hovering_P.PIDController2_P * FLIGHT_HEXA_Hovering_B.Sum_o +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_ih) +
      FLIGHT_HEXA_Hovering_B.Gain2;

    // DeadZone: '<S205>/DeadZone' incorporates:
    //   Saturate: '<S220>/Saturation'

    if (FLIGHT_HEXA_Hovering_B.Saturation_a1 >
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.Saturation_a1 -
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;

      // Sum: '<S222>/Sum' incorporates:
      //   Saturate: '<S220>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_a1 =
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;
    } else {
      if (FLIGHT_HEXA_Hovering_B.Saturation_a1 >=
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        FLIGHT_HEXA_Hovering_B.Sum_o = 0.0;
      } else {
        FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.Saturation_a1 -
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }

      if (FLIGHT_HEXA_Hovering_B.Saturation_a1 <
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        // Sum: '<S222>/Sum' incorporates:
        //   Saturate: '<S220>/Saturation'

        FLIGHT_HEXA_Hovering_B.Saturation_a1 =
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of DeadZone: '<S205>/DeadZone'

    // Update for DiscreteIntegrator: '<S109>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

    // Update for DiscreteIntegrator: '<S104>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ov +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval * FLIGHT_HEXA_Hovering_B.Gain4;

    // Update for DiscreteIntegrator: '<S161>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_h +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_i *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3;

    // Update for DiscreteIntegrator: '<S156>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_c +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_e * FLIGHT_HEXA_Hovering_B.Gain1_m;

    // Switch: '<S203>/Switch1' incorporates:
    //   Constant: '<S203>/Clamping_zero'
    //   Constant: '<S203>/Constant'
    //   Constant: '<S203>/Constant2'
    //   RelationalOperator: '<S203>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Sum_o >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_j) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_a;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_p;
    }

    // Switch: '<S203>/Switch2' incorporates:
    //   Constant: '<S203>/Clamping_zero'
    //   Constant: '<S203>/Constant3'
    //   Constant: '<S203>/Constant4'
    //   RelationalOperator: '<S203>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_j) {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant3_Value_b;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_n = FLIGHT_HEXA_Hovering_P.Constant4_Value_l;
    }

    // Switch: '<S203>/Switch' incorporates:
    //   Constant: '<S203>/Clamping_zero'
    //   Constant: '<S203>/Constant1'
    //   Logic: '<S203>/AND3'
    //   RelationalOperator: '<S203>/Equal1'
    //   RelationalOperator: '<S203>/Relational Operator'
    //   Switch: '<S203>/Switch1'
    //   Switch: '<S203>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_j !=
         FLIGHT_HEXA_Hovering_B.Sum_o) && (FLIGHT_HEXA_Hovering_B.rtPrevAction ==
         FLIGHT_HEXA_Hovering_B.i2_n)) {
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k;
    }

    // Update for DiscreteIntegrator: '<S213>/Integrator' incorporates:
    //   Switch: '<S203>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_ih +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_f *
      FLIGHT_HEXA_Hovering_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Update for DiscreteIntegrator: '<S208>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_f +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_l * FLIGHT_HEXA_Hovering_B.Gain2;
  }

  // End of Outputs for SubSystem: '<S4>/Attitude controller'
  for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
       FLIGHT_HEXA_Hovering_B.ParamStep_g < 6;
       FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
    // Saturate: '<S5>/Saturation' incorporates:
    //   Bias: '<S5>/Bias'
    //   Constant: '<S5>/Mixer matrix'
    //   Gain: '<S5>/Gain1'
    //   Product: '<S5>/Product1'
    //   SignalConversion generated from: '<S5>/Product1'

    FLIGHT_HEXA_Hovering_B.Gain2 = floor
      (((((FLIGHT_HEXA_Hovering_P.Mixermatrix_Value[FLIGHT_HEXA_Hovering_B.ParamStep_g
           + 6] * FLIGHT_HEXA_Hovering_B.Saturation_a1 +
           FLIGHT_HEXA_Hovering_P.Mixermatrix_Value[FLIGHT_HEXA_Hovering_B.ParamStep_g]
           * FLIGHT_HEXA_Hovering_B.Gain_i) +
          FLIGHT_HEXA_Hovering_P.Mixermatrix_Value[FLIGHT_HEXA_Hovering_B.ParamStep_g
          + 12] * FLIGHT_HEXA_Hovering_B.Saturation_b) +
         FLIGHT_HEXA_Hovering_P.Mixermatrix_Value[FLIGHT_HEXA_Hovering_B.ParamStep_g
         + 18] * FLIGHT_HEXA_Hovering_B.Saturation_n) +
        FLIGHT_HEXA_Hovering_P.Bias_Bias) * FLIGHT_HEXA_Hovering_P.Gain1_Gain_p);
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain2) || rtIsInf
        (FLIGHT_HEXA_Hovering_B.Gain2)) {
      FLIGHT_HEXA_Hovering_B.Gain2 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain2 = fmod(FLIGHT_HEXA_Hovering_B.Gain2, 65536.0);
    }

    FLIGHT_HEXA_Hovering_B.u0 = static_cast<uint16_T>
      (FLIGHT_HEXA_Hovering_B.Gain2 < 0.0 ? static_cast<int32_T>
       (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-FLIGHT_HEXA_Hovering_B.Gain2)))) : static_cast<int32_T>(static_cast<
        uint16_T>(FLIGHT_HEXA_Hovering_B.Gain2)));
    if (FLIGHT_HEXA_Hovering_B.u0 > FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_g)
    {
      // DataTypeConversion: '<S6>/Cast To Double'
      FLIGHT_HEXA_Hovering_B.CastToDouble[FLIGHT_HEXA_Hovering_B.ParamStep_g] =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_g;
    } else if (FLIGHT_HEXA_Hovering_B.u0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_j) {
      // DataTypeConversion: '<S6>/Cast To Double'
      FLIGHT_HEXA_Hovering_B.CastToDouble[FLIGHT_HEXA_Hovering_B.ParamStep_g] =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_j;
    } else {
      // DataTypeConversion: '<S6>/Cast To Double'
      FLIGHT_HEXA_Hovering_B.CastToDouble[FLIGHT_HEXA_Hovering_B.ParamStep_g] =
        FLIGHT_HEXA_Hovering_B.u0;
    }

    // End of Saturate: '<S5>/Saturation'
  }

  // MATLABSystem: '<S6>/Read Parameter13'
  if (FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_a.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // RelationalOperator: '<S13>/Compare' incorporates:
  //   Constant: '<S13>/Constant'

  FLIGHT_HEXA_Hovering_B.Compare_f = (FLIGHT_HEXA_Hovering_B.In1_j.values[7] >=
    FLIGHT_HEXA_Hovering_P.CompareToConstant_const);

  // MATLABSystem: '<S6>/Read Parameter1'
  if (FLIGHT_HEXA_Hovering_DW.obj_l.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_l.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_l.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_f);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.ParamStep_f = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter2'
  if (FLIGHT_HEXA_Hovering_DW.obj_jh.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_jh.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_jh.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_g);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter3'
  if (FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_p.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.i1);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.i1 = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter4'
  if (FLIGHT_HEXA_Hovering_DW.obj_j.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_j.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_j.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.i2);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.i2 = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter5'
  if (FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_g1);
  if (FLIGHT_HEXA_Hovering_B.latp2) {
    FLIGHT_HEXA_Hovering_B.ParamStep_g1 = 0;
  }

  // Switch: '<S6>/Switch' incorporates:
  //   Constant: '<S6>/Constant'

  if (FLIGHT_HEXA_Hovering_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch' incorporates:
    //   Constant: '<S6>/Fault'
    //   DataTypeConversion: '<S6>/Data Type Conversion3'
    //   MATLABSystem: '<S6>/Read Parameter13'
    //
    if (FLIGHT_HEXA_Hovering_P.ManualSwitch_CurrentSetting == 1) {
      FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_P.Fault_Value;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.ParamStep_c;
    }

    // End of ManualSwitch: '<S6>/Manual Switch'
  } else {
    FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_P.Constant_Value_h;
  }

  // Gain: '<S7>/Gain' incorporates:
  //   Switch: '<S6>/Switch'

  FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Gain_Gain_i *
    FLIGHT_HEXA_Hovering_B.Gain2;

  // Saturate: '<S7>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_j) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_j;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_b) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_b;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S7>/Constant'
  //   Constant: '<S7>/IDLE PWM'
  //   Product: '<S7>/Product'
  //   Saturate: '<S7>/Saturation1'
  //   Sum: '<S7>/Add'
  //   Sum: '<S7>/Sum'

  FLIGHT_HEXA_Hovering_B.Gain2 = floor((static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.CastToDouble[0]) -
    FLIGHT_HEXA_Hovering_P.IDLEPWM_Value) * FLIGHT_HEXA_Hovering_B.Sum_o +
    FLIGHT_HEXA_Hovering_P.Constant_Value_ik);
  if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain2) || rtIsInf
      (FLIGHT_HEXA_Hovering_B.Gain2)) {
    FLIGHT_HEXA_Hovering_B.Gain2 = 0.0;
  } else {
    FLIGHT_HEXA_Hovering_B.Gain2 = fmod(FLIGHT_HEXA_Hovering_B.Gain2, 65536.0);
  }

  // Switch: '<S6>/Switch1' incorporates:
  //   Constant: '<S6>/Constant1'

  if (FLIGHT_HEXA_Hovering_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch1' incorporates:
    //   Constant: '<S6>/Fault1'
    //   DataTypeConversion: '<S6>/Data Type Conversion2'
    //   MATLABSystem: '<S6>/Read Parameter1'
    //
    if (FLIGHT_HEXA_Hovering_P.ManualSwitch1_CurrentSetting == 1) {
      FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_P.Fault1_Value;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_B.ParamStep_f;
    }

    // End of ManualSwitch: '<S6>/Manual Switch1'
  } else {
    FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_P.Constant1_Value;
  }

  // Gain: '<S8>/Gain' incorporates:
  //   Switch: '<S6>/Switch1'

  FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Gain_Gain_n *
    FLIGHT_HEXA_Hovering_B.Gain1_m;

  // Saturate: '<S8>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_g) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_g;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_k) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_k;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S8>/Constant'
  //   Constant: '<S8>/IDLE PWM'
  //   Product: '<S8>/Product'
  //   Saturate: '<S8>/Saturation1'
  //   Sum: '<S8>/Add'
  //   Sum: '<S8>/Sum'

  FLIGHT_HEXA_Hovering_B.Gain1_m = floor((static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.CastToDouble[1]) -
    FLIGHT_HEXA_Hovering_P.IDLEPWM_Value_c) * FLIGHT_HEXA_Hovering_B.Sum_o +
    FLIGHT_HEXA_Hovering_P.Constant_Value_c);
  if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain1_m) || rtIsInf
      (FLIGHT_HEXA_Hovering_B.Gain1_m)) {
    FLIGHT_HEXA_Hovering_B.Gain1_m = 0.0;
  } else {
    FLIGHT_HEXA_Hovering_B.Gain1_m = fmod(FLIGHT_HEXA_Hovering_B.Gain1_m,
      65536.0);
  }

  // Switch: '<S6>/Switch2' incorporates:
  //   Constant: '<S6>/Constant2'

  if (FLIGHT_HEXA_Hovering_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch2' incorporates:
    //   Constant: '<S6>/Fault2'
    //   DataTypeConversion: '<S6>/Data Type Conversion'
    //   MATLABSystem: '<S6>/Read Parameter2'
    //
    if (FLIGHT_HEXA_Hovering_P.ManualSwitch2_CurrentSetting == 1) {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Fault2_Value;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.ParamStep_g;
    }

    // End of ManualSwitch: '<S6>/Manual Switch2'
  } else {
    FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_P.Constant2_Value;
  }

  // Gain: '<S9>/Gain' incorporates:
  //   Switch: '<S6>/Switch2'

  FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Gain_Gain_g *
    FLIGHT_HEXA_Hovering_B.Gain_i;

  // Saturate: '<S9>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_h) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_h;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_i) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_i;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S9>/Constant'
  //   Constant: '<S9>/IDLE PWM'
  //   Product: '<S9>/Product'
  //   Saturate: '<S9>/Saturation1'
  //   Sum: '<S9>/Add'
  //   Sum: '<S9>/Sum'

  FLIGHT_HEXA_Hovering_B.Gain_i = floor((static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.CastToDouble[2]) -
    FLIGHT_HEXA_Hovering_P.IDLEPWM_Value_o) * FLIGHT_HEXA_Hovering_B.Sum_o +
    FLIGHT_HEXA_Hovering_P.Constant_Value_g1);
  if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain_i) || rtIsInf
      (FLIGHT_HEXA_Hovering_B.Gain_i)) {
    FLIGHT_HEXA_Hovering_B.Gain_i = 0.0;
  } else {
    FLIGHT_HEXA_Hovering_B.Gain_i = fmod(FLIGHT_HEXA_Hovering_B.Gain_i, 65536.0);
  }

  // Switch: '<S6>/Switch3' incorporates:
  //   Constant: '<S6>/Constant3'

  if (FLIGHT_HEXA_Hovering_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch3' incorporates:
    //   Constant: '<S6>/Fault3'
    //   DataTypeConversion: '<S6>/Data Type Conversion4'
    //   MATLABSystem: '<S6>/Read Parameter3'
    //
    if (FLIGHT_HEXA_Hovering_P.ManualSwitch3_CurrentSetting == 1) {
      FLIGHT_HEXA_Hovering_B.Gain4 = FLIGHT_HEXA_Hovering_P.Fault3_Value;
    } else {
      FLIGHT_HEXA_Hovering_B.Gain4 = FLIGHT_HEXA_Hovering_B.i1;
    }

    // End of ManualSwitch: '<S6>/Manual Switch3'
  } else {
    FLIGHT_HEXA_Hovering_B.Gain4 = FLIGHT_HEXA_Hovering_P.Constant3_Value;
  }

  // Gain: '<S10>/Gain' incorporates:
  //   Switch: '<S6>/Switch3'

  FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Gain_Gain_ni *
    FLIGHT_HEXA_Hovering_B.Gain4;

  // Saturate: '<S10>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_h1) {
    FLIGHT_HEXA_Hovering_B.Sum_o =
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_h1;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_bv) {
    FLIGHT_HEXA_Hovering_B.Sum_o =
      FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_bv;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S10>/Constant'
  //   Constant: '<S10>/IDLE PWM'
  //   Product: '<S10>/Product'
  //   Saturate: '<S10>/Saturation1'
  //   Sum: '<S10>/Add'
  //   Sum: '<S10>/Sum'

  FLIGHT_HEXA_Hovering_B.Gain4 = floor((static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.CastToDouble[3]) -
    FLIGHT_HEXA_Hovering_P.IDLEPWM_Value_h) * FLIGHT_HEXA_Hovering_B.Sum_o +
    FLIGHT_HEXA_Hovering_P.Constant_Value_gp);
  if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain4) || rtIsInf
      (FLIGHT_HEXA_Hovering_B.Gain4)) {
    FLIGHT_HEXA_Hovering_B.Gain4 = 0.0;
  } else {
    FLIGHT_HEXA_Hovering_B.Gain4 = fmod(FLIGHT_HEXA_Hovering_B.Gain4, 65536.0);
  }

  // Switch: '<S6>/Switch4' incorporates:
  //   Constant: '<S6>/Constant4'

  if (FLIGHT_HEXA_Hovering_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch4' incorporates:
    //   Constant: '<S6>/Fault4'
    //   DataTypeConversion: '<S6>/Data Type Conversion1'
    //   MATLABSystem: '<S6>/Read Parameter4'
    //
    if (FLIGHT_HEXA_Hovering_P.ManualSwitch4_CurrentSetting == 1) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
        FLIGHT_HEXA_Hovering_P.Fault4_Value;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_B.i2;
    }

    // End of ManualSwitch: '<S6>/Manual Switch4'
  } else {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 =
      FLIGHT_HEXA_Hovering_P.Constant4_Value;
  }

  // Gain: '<S11>/Gain' incorporates:
  //   Switch: '<S6>/Switch4'

  FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Gain_Gain_i4 *
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2;

  // Saturate: '<S11>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_a) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_a;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_p) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_p;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S11>/Constant'
  //   Constant: '<S11>/IDLE PWM'
  //   Product: '<S11>/Product'
  //   Saturate: '<S11>/Saturation1'
  //   Sum: '<S11>/Add'
  //   Sum: '<S11>/Sum'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = floor((static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.CastToDouble[4]) -
    FLIGHT_HEXA_Hovering_P.IDLEPWM_Value_n) * FLIGHT_HEXA_Hovering_B.Sum_o +
    FLIGHT_HEXA_Hovering_P.Constant_Value_fa);
  if (rtIsNaN(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2) || rtIsInf
      (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2)) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = 0.0;
  } else {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = fmod
      (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2, 65536.0);
  }

  // Switch: '<S6>/Switch5' incorporates:
  //   Constant: '<S6>/Constant5'

  if (FLIGHT_HEXA_Hovering_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch5' incorporates:
    //   Constant: '<S6>/Fault5'
    //   DataTypeConversion: '<S6>/Data Type Conversion5'
    //   MATLABSystem: '<S6>/Read Parameter5'
    //
    if (FLIGHT_HEXA_Hovering_P.ManualSwitch5_CurrentSetting == 1) {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Fault5_Value;
    } else {
      FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_B.ParamStep_g1;
    }

    // End of ManualSwitch: '<S6>/Manual Switch5'
  } else {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Constant5_Value;
  }

  // Gain: '<S12>/Gain' incorporates:
  //   Switch: '<S6>/Switch5'

  FLIGHT_HEXA_Hovering_B.Sum_o *= FLIGHT_HEXA_Hovering_P.Gain_Gain_ly;

  // Saturate: '<S12>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.Sum_o >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_k) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_k;
  } else if (FLIGHT_HEXA_Hovering_B.Sum_o <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_h) {
    FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_h;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S12>/Constant'
  //   Constant: '<S12>/IDLE PWM'
  //   Product: '<S12>/Product'
  //   Saturate: '<S12>/Saturation1'
  //   Sum: '<S12>/Add'
  //   Sum: '<S12>/Sum'

  FLIGHT_HEXA_Hovering_B.Sum_o = floor((static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.CastToDouble[5]) -
    FLIGHT_HEXA_Hovering_P.IDLEPWM_Value_l) * FLIGHT_HEXA_Hovering_B.Sum_o +
    FLIGHT_HEXA_Hovering_P.Constant_Value_cc);
  if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Sum_o) || rtIsInf
      (FLIGHT_HEXA_Hovering_B.Sum_o)) {
    FLIGHT_HEXA_Hovering_B.Sum_o = 0.0;
  } else {
    FLIGHT_HEXA_Hovering_B.Sum_o = fmod(FLIGHT_HEXA_Hovering_B.Sum_o, 65536.0);
  }

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/Constant1'
  //   DataTypeConversion: '<S6>/Cast To Double1'

  for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
       FLIGHT_HEXA_Hovering_B.ParamStep_g < 8;
       FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
    FLIGHT_HEXA_Hovering_B.pwmValue[FLIGHT_HEXA_Hovering_B.ParamStep_g] = 0U;
  }

  FLIGHT_HEXA_Hovering_B.pwmValue[0] = static_cast<uint16_T>
    (FLIGHT_HEXA_Hovering_B.Gain2 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_HEXA_Hovering_B.Gain2)))) : static_cast<int32_T>(static_cast<
      uint16_T>(FLIGHT_HEXA_Hovering_B.Gain2)));
  FLIGHT_HEXA_Hovering_B.pwmValue[1] = static_cast<uint16_T>
    (FLIGHT_HEXA_Hovering_B.Gain1_m < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_HEXA_Hovering_B.Gain1_m)))) : static_cast<int32_T>(static_cast<
      uint16_T>(FLIGHT_HEXA_Hovering_B.Gain1_m)));
  FLIGHT_HEXA_Hovering_B.pwmValue[2] = static_cast<uint16_T>
    (FLIGHT_HEXA_Hovering_B.Gain_i < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_HEXA_Hovering_B.Gain_i)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_HEXA_Hovering_B.Gain_i)));
  FLIGHT_HEXA_Hovering_B.pwmValue[3] = static_cast<uint16_T>
    (FLIGHT_HEXA_Hovering_B.Gain4 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_HEXA_Hovering_B.Gain4)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_HEXA_Hovering_B.Gain4)));
  FLIGHT_HEXA_Hovering_B.pwmValue[4] = static_cast<uint16_T>
    (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2)))) : static_cast<int32_T>(
      static_cast<uint16_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2)));
  FLIGHT_HEXA_Hovering_B.pwmValue[5] = static_cast<uint16_T>
    (FLIGHT_HEXA_Hovering_B.Sum_o < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-FLIGHT_HEXA_Hovering_B.Sum_o)))) : static_cast<int32_T>
     (static_cast<uint16_T>(FLIGHT_HEXA_Hovering_B.Sum_o)));
  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    if (!FLIGHT_HEXA_Hovering_DW.obj_pk.isArmed) {
      FLIGHT_HEXA_Hovering_DW.obj_pk.isArmed = true;
      pwm_arm(&FLIGHT_HEXA_Hovering_DW.obj_pk.armAdvertiseObj);
    }

    pwm_setServo(FLIGHT_HEXA_Hovering_DW.obj_pk.servoCount,
                 FLIGHT_HEXA_Hovering_DW.obj_pk.channelMask,
                 &FLIGHT_HEXA_Hovering_B.pwmValue[0],
                 FLIGHT_HEXA_Hovering_DW.obj_pk.isMain,
                 &FLIGHT_HEXA_Hovering_DW.obj_pk.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&FLIGHT_HEXA_Hovering_DW.obj_pk.armAdvertiseObj);
    FLIGHT_HEXA_Hovering_DW.obj_pk.isArmed = false;
    pwm_resetServo(FLIGHT_HEXA_Hovering_DW.obj_pk.servoCount,
                   FLIGHT_HEXA_Hovering_DW.obj_pk.isMain,
                   &FLIGHT_HEXA_Hovering_DW.obj_pk.actuatorAdvertiseObj);
  }

  if (FLIGHT_HEXA_Hovering_DW.obj_pk.isMain) {
    if (FLIGHT_HEXA_Hovering_P.Constant1_Value_ct) {
      pwm_disarm(&FLIGHT_HEXA_Hovering_DW.obj_pk.armAdvertiseObj);
    } else {
      pwm_arm(&FLIGHT_HEXA_Hovering_DW.obj_pk.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'

  // Outputs for Enabled SubSystem: '<S28>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S45>/Enable'

  // Start for MATLABSystem: '<S28>/Read Parameter'
  if (FLIGHT_HEXA_Hovering_B.ParamStep_p > 0) {
    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S55>/Constant'
    //   SignalConversion generated from: '<S51>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S51>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S51>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S51>/Data Type Conversion'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.alt;

    // SignalConversion generated from: '<S45>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
      FLIGHT_HEXA_Hovering_B.In1_f.lat;

    // SignalConversion generated from: '<S45>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] =
      FLIGHT_HEXA_Hovering_B.In1_f.lon;

    // DataTypeConversion: '<S45>/Data Type Conversion'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
      FLIGHT_HEXA_Hovering_B.In1_f.alt;
    FLIGHT_HEXA_Hovering_MATLABSystem(FLIGHT_HEXA_Hovering_B.DataTypeConversion2,
      FLIGHT_HEXA_Hovering_B.VectorConcatenate,
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid,
      FLIGHT_HEXA_Hovering_B.In1_p.current.type,
      &FLIGHT_HEXA_Hovering_B.MATLABSystem);

    // SignalConversion generated from: '<S57>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   MATLABSystem: '<S51>/MATLAB System'
    //   SignalConversion generated from: '<S51>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[0] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S57>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   MATLABSystem: '<S51>/MATLAB System'
    //   SignalConversion generated from: '<S51>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[1] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[1];

    // If: '<S57>/If' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   Constant: '<S59>/Constant'
    //   Constant: '<S59>/Constant1'
    //   Constant: '<S60>/Constant'
    //   Constant: '<S60>/Constant1'

    if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S57>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S60>/Action Port'

      // MATLABSystem: '<S60>/Read Parameter' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   BusAssignment: '<S51>/Bus Assignment1'
      //   SignalConversion generated from: '<S60>/Read Parameter'

      if (FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime !=
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c) {
        FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime =
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c;
      }

      FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
        (FLIGHT_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2]);
      if (FLIGHT_HEXA_Hovering_B.latp2) {
        FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S60>/Read Parameter'
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_dr[0];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_dr[1];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S57>/If Action Subsystem2'
    } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S57>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S59>/Action Port'

      // MATLABSystem: '<S59>/Read Parameter'
      if (FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime !=
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g) {
        FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime =
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g;
      }

      FLIGHT_HEXA_Hovering_B.latp2 = MW_Param_Step
        (FLIGHT_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &FLIGHT_HEXA_Hovering_B.ParamStep);
      if (FLIGHT_HEXA_Hovering_B.latp2) {
        FLIGHT_HEXA_Hovering_B.ParamStep = 0.0F;
      }

      // Gain: '<S59>/Gain' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   BusAssignment: '<S51>/Bus Assignment1'
      //   MATLABSystem: '<S59>/Read Parameter'
      //
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        FLIGHT_HEXA_Hovering_P.Gain_Gain_h * FLIGHT_HEXA_Hovering_B.ParamStep;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[0];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[1];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S57>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S57>/If Action Subsystem' incorporates:
      //   ActionPort: '<S58>/Action Port'

      // SignalConversion generated from: '<S58>/In1' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   BusAssignment: '<S51>/Bus Assignment1'
      //   MATLABSystem: '<S51>/MATLAB System'
      //   SignalConversion generated from: '<S51>/MATLAB System'

      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S51>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   SignalConversion generated from: '<S57>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S58>/In2'
      //
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vx;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vy;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S57>/If Action Subsystem'
    }

    // End of If: '<S57>/If'

    // BusAssignment: '<S51>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   Constant: '<S51>/Constant5'

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

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S55>/Constant'
    //   SignalConversion generated from: '<S52>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S52>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S51>/Matrix Concatenate1'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S52>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S51>/Matrix Concatenate1'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S51>/Data Type Conversion'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.alt;
    FLIGHT_HEXA_Hovering_MATLABSystem(FLIGHT_HEXA_Hovering_B.DataTypeConversion2,
      FLIGHT_HEXA_Hovering_B.VectorConcatenate,
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid,
      FLIGHT_HEXA_Hovering_B.In1_p.current.type,
      &FLIGHT_HEXA_Hovering_B.MATLABSystem_b);

    // SignalConversion generated from: '<S52>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S52>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vx;

    // SignalConversion generated from: '<S52>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S52>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vy;

    // SignalConversion generated from: '<S52>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S52>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vz;

    // BusAssignment: '<S52>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   Constant: '<S52>/Constant5'
    //   MATLABSystem: '<S52>/MATLAB System'

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

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S55>/Constant'
    //   SignalConversion generated from: '<S54>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S54>/MATLAB System' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   DataTypeConversion: '<S45>/Data Type Conversion'
    //   DataTypeConversion: '<S54>/Data Type Conversion'
    //   SignalConversion generated from: '<S45>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S54>/Matrix Concatenate'
    //
    if (FLIGHT_HEXA_Hovering_B.In1_p.next.valid) {
      FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_B.In1_p.next.lat -
        FLIGHT_HEXA_Hovering_B.In1_f.lat;
      FLIGHT_HEXA_Hovering_B.Gain_i = FLIGHT_HEXA_Hovering_B.In1_p.next.lon -
        FLIGHT_HEXA_Hovering_B.In1_f.lon;
      FLIGHT_HEXA_Hovering_B.Sum_o = fabs(FLIGHT_HEXA_Hovering_B.Gain1_m);
      if (FLIGHT_HEXA_Hovering_B.Sum_o > 180.0) {
        if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain1_m + 180.0) || rtIsInf
            (FLIGHT_HEXA_Hovering_B.Gain1_m + 180.0)) {
          FLIGHT_HEXA_Hovering_B.Sum_o = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.Gain1_m + 180.0 == 0.0) {
          FLIGHT_HEXA_Hovering_B.Sum_o = 0.0;
        } else {
          FLIGHT_HEXA_Hovering_B.Sum_o = fmod(FLIGHT_HEXA_Hovering_B.Gain1_m +
            180.0, 360.0);
          if (FLIGHT_HEXA_Hovering_B.Sum_o == 0.0) {
            FLIGHT_HEXA_Hovering_B.Sum_o = 0.0;
          } else if (FLIGHT_HEXA_Hovering_B.Gain1_m + 180.0 < 0.0) {
            FLIGHT_HEXA_Hovering_B.Sum_o += 360.0;
          }
        }

        FLIGHT_HEXA_Hovering_B.Gain1_m = FLIGHT_HEXA_Hovering_B.Gain1_m * 0.0 +
          (FLIGHT_HEXA_Hovering_B.Sum_o - 180.0);
        FLIGHT_HEXA_Hovering_B.Sum_o = fabs(FLIGHT_HEXA_Hovering_B.Gain1_m);
      }

      if (FLIGHT_HEXA_Hovering_B.Sum_o > 90.0) {
        FLIGHT_HEXA_Hovering_B.Sum_o = fabs(FLIGHT_HEXA_Hovering_B.Gain1_m);
        FLIGHT_HEXA_Hovering_B.latp2 = (FLIGHT_HEXA_Hovering_B.Sum_o > 90.0);
        FLIGHT_HEXA_Hovering_B.Gain_i += 180.0;
        FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Gain1_m *
          static_cast<real_T>(FLIGHT_HEXA_Hovering_B.latp2);
        if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Gain2)) {
          FLIGHT_HEXA_Hovering_B.Gain2 = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.Gain2 < 0.0) {
          FLIGHT_HEXA_Hovering_B.Gain2 = -1.0;
        } else {
          FLIGHT_HEXA_Hovering_B.Gain2 = (FLIGHT_HEXA_Hovering_B.Gain2 > 0.0);
        }

        FLIGHT_HEXA_Hovering_B.Gain1_m = (90.0 - (FLIGHT_HEXA_Hovering_B.Sum_o *
          static_cast<real_T>(FLIGHT_HEXA_Hovering_B.latp2) - 90.0)) *
          FLIGHT_HEXA_Hovering_B.Gain2 * static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.latp2) + FLIGHT_HEXA_Hovering_B.Gain1_m *
          static_cast<real_T>(!FLIGHT_HEXA_Hovering_B.latp2);
      }

      if ((FLIGHT_HEXA_Hovering_B.Gain_i > 180.0) ||
          (FLIGHT_HEXA_Hovering_B.Gain_i < -180.0)) {
        FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_rt_remd_snf
          (FLIGHT_HEXA_Hovering_B.Gain_i, 360.0);
        FLIGHT_HEXA_Hovering_B.Gain2 = FLIGHT_HEXA_Hovering_B.Sum_o / 180.0;
        if (FLIGHT_HEXA_Hovering_B.Gain2 < 0.0) {
          FLIGHT_HEXA_Hovering_B.Gain2 = ceil(FLIGHT_HEXA_Hovering_B.Gain2);
        } else {
          FLIGHT_HEXA_Hovering_B.Gain2 = floor(FLIGHT_HEXA_Hovering_B.Gain2);
        }

        FLIGHT_HEXA_Hovering_B.Gain_i = (FLIGHT_HEXA_Hovering_B.Sum_o - 360.0 *
          FLIGHT_HEXA_Hovering_B.Gain2) + FLIGHT_HEXA_Hovering_B.Gain_i * 0.0;
      }

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 = FLIGHT_HEXA_Hovering_sind_d
        (FLIGHT_HEXA_Hovering_B.In1_f.lat);
      FLIGHT_HEXA_Hovering_B.Gain2 = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2);
      if (rtIsInf(FLIGHT_HEXA_Hovering_B.In1_f.lat) || rtIsNaN
          (FLIGHT_HEXA_Hovering_B.In1_f.lat)) {
        FLIGHT_HEXA_Hovering_B.Sum_o = (rtNaN);
      } else {
        FLIGHT_HEXA_Hovering_B.Sum_o = FLIGHT_HEXA_Hovering_rt_remd_snf
          (FLIGHT_HEXA_Hovering_B.In1_f.lat, 360.0);
        FLIGHT_HEXA_Hovering_B.Gain4 = fabs(FLIGHT_HEXA_Hovering_B.Sum_o);
        if (FLIGHT_HEXA_Hovering_B.Gain4 > 180.0) {
          if (FLIGHT_HEXA_Hovering_B.Sum_o > 0.0) {
            FLIGHT_HEXA_Hovering_B.Sum_o -= 360.0;
          } else {
            FLIGHT_HEXA_Hovering_B.Sum_o += 360.0;
          }

          FLIGHT_HEXA_Hovering_B.Gain4 = fabs(FLIGHT_HEXA_Hovering_B.Sum_o);
        }

        if (FLIGHT_HEXA_Hovering_B.Gain4 <= 45.0) {
          FLIGHT_HEXA_Hovering_B.Sum_o = cos(0.017453292519943295 *
            FLIGHT_HEXA_Hovering_B.Sum_o);
        } else if (FLIGHT_HEXA_Hovering_B.Gain4 <= 135.0) {
          if (FLIGHT_HEXA_Hovering_B.Sum_o > 0.0) {
            FLIGHT_HEXA_Hovering_B.Sum_o = -sin((FLIGHT_HEXA_Hovering_B.Sum_o -
              90.0) * 0.017453292519943295);
          } else {
            FLIGHT_HEXA_Hovering_B.Sum_o = sin((FLIGHT_HEXA_Hovering_B.Sum_o +
              90.0) * 0.017453292519943295);
          }
        } else {
          if (FLIGHT_HEXA_Hovering_B.Sum_o > 0.0) {
            FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_B.Sum_o - 180.0)
              * 0.017453292519943295;
          } else {
            FLIGHT_HEXA_Hovering_B.Sum_o = (FLIGHT_HEXA_Hovering_B.Sum_o + 180.0)
              * 0.017453292519943295;
          }

          FLIGHT_HEXA_Hovering_B.Sum_o = -cos(FLIGHT_HEXA_Hovering_B.Sum_o);
        }
      }

      FLIGHT_HEXA_Hovering_B.Gain1_m /= FLIGHT_HEXA_Hovering_rt_atan2d_snf(1.0,
        0.99330562000985867 / (1.0 - 0.0066943799901413165 *
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2 *
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_2) * FLIGHT_HEXA_Hovering_B.Gain2) *
        57.295779513082323;
      FLIGHT_HEXA_Hovering_B.Gain_i /= FLIGHT_HEXA_Hovering_rt_atan2d_snf(1.0,
        FLIGHT_HEXA_Hovering_B.Gain2 * FLIGHT_HEXA_Hovering_B.Sum_o) *
        57.295779513082323;
      FLIGHT_HEXA_Hovering_B.Sum_o = -static_cast<real_T>
        (FLIGHT_HEXA_Hovering_B.In1_p.next.alt) +
        FLIGHT_HEXA_Hovering_B.In1_f.alt;
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[0] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.Gain1_m);
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[1] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.Gain_i);
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[2] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.Sum_o);
      FLIGHT_HEXA_Hovering_B.latp2 = false;
      FLIGHT_HEXA_Hovering_B.i1 = 0;
      exitg1 = false;
      while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.i1 < 3)) {
        if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.i1]) {
          FLIGHT_HEXA_Hovering_B.latp2 = true;
          exitg1 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.i1++;
        }
      }

      FLIGHT_HEXA_Hovering_B.Gain2 = 0.0 / static_cast<real_T>
        (!FLIGHT_HEXA_Hovering_B.latp2);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.Gain2 +
        FLIGHT_HEXA_Hovering_B.Gain1_m);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.Gain2 +
        FLIGHT_HEXA_Hovering_B.Gain_i);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.Gain2 +
        FLIGHT_HEXA_Hovering_B.Sum_o);
    } else {
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S54>/MATLAB System'

    // SignalConversion generated from: '<S54>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S54>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vx;

    // SignalConversion generated from: '<S54>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S54>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vy;

    // SignalConversion generated from: '<S54>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S54>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vz;

    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   Constant: '<S54>/Constant5'

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

    // SignalConversion generated from: '<S53>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   BusAssignment: '<S53>/Bus Assignment1'
    //   Constant: '<S55>/Constant'

    FLIGHT_HEXA_Hovering_B.BusAssignment1_f =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S53>/Bus Assignment1' incorporates:
    //   Constant: '<S53>/Constant'
    //   Constant: '<S53>/Constant1'
    //   Constant: '<S53>/Constant2'
    //   Constant: '<S53>/Constant3'
    //   Constant: '<S53>/Constant4'
    //   Constant: '<S53>/Constant5'
    //   Constant: '<S53>/Constant6'
    //   Constant: '<S53>/Constant7'

    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.timestamp =
      FLIGHT_HEXA_Hovering_P.Constant7_Value;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.yaw =
      FLIGHT_HEXA_Hovering_P.Constant3_Value_al;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.yaw_speed =
      FLIGHT_HEXA_Hovering_P.Constant4_Value_g;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.position[0] =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fh[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.velocity[0] =
      FLIGHT_HEXA_Hovering_P.Constant1_Value_h[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.acceleration[0] =
      FLIGHT_HEXA_Hovering_P.Constant2_Value_f[0];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.position[1] =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fh[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.velocity[1] =
      FLIGHT_HEXA_Hovering_P.Constant1_Value_h[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.acceleration[1] =
      FLIGHT_HEXA_Hovering_P.Constant2_Value_f[1];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.position[2] =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fh[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.velocity[2] =
      FLIGHT_HEXA_Hovering_P.Constant1_Value_h[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.acceleration[2] =
      FLIGHT_HEXA_Hovering_P.Constant2_Value_f[2];
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.point_valid =
      FLIGHT_HEXA_Hovering_P.Constant5_Value_l;
    FLIGHT_HEXA_Hovering_B.BusAssignment1_f.type =
      FLIGHT_HEXA_Hovering_P.Constant6_Value;

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S45>/Constant'
    //   Constant: '<S55>/Constant'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.timestamp =
      FLIGHT_HEXA_Hovering_B.In1_p.timestamp;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.type =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fm;
    for (FLIGHT_HEXA_Hovering_B.ParamStep_g = 0;
         FLIGHT_HEXA_Hovering_B.ParamStep_g < 7;
         FLIGHT_HEXA_Hovering_B.ParamStep_g++) {
      FLIGHT_HEXA_Hovering_B.BusAssignment1._padding0[FLIGHT_HEXA_Hovering_B.ParamStep_g]
        =
        FLIGHT_HEXA_Hovering_P.Constant_Value._padding0[FLIGHT_HEXA_Hovering_B.ParamStep_g];
    }

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S53>/Bus Assignment1'
    //   Concatenate: '<S45>/Matrix Concatenate'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[3] =
      FLIGHT_HEXA_Hovering_B.BusAssignment1_f;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[4] =
      FLIGHT_HEXA_Hovering_B.BusAssignment1_f;

    // MATLABSystem: '<S56>/SinkBlock' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'

    uORB_write_step(FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                    &FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                    &FLIGHT_HEXA_Hovering_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S28>/Send waypoints to OBC'

  // MATLABSystem: '<S44>/PX4 Timestamp'
  hrt_absolute_time();
}

// Model initialize function
void FLIGHT_HEXA_Hovering_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  FLIGHT_HEXA_Hovering_P.Constant1_Value_dr[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_dr[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_f2 = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_l4 = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_fh[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_fh[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant_Value_fh[2] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_h[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_h[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant1_Value_h[2] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant2_Value_f[0] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant2_Value_f[1] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant2_Value_f[2] = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant3_Value_al = rtNaNF;
  FLIGHT_HEXA_Hovering_P.Constant4_Value_g = rtNaNF;

  {
    static const char_T ParameterNameStr[15] = "MPC_LAND_SPEED";
    static const char_T ParameterNameStr_0[14] = "MPC_TKO_SPEED";
    static const char_T ParameterNameStr_1[14] = "COM_OBS_AVOID";
    static const char_T ParameterNameStr_2[14] = "FDD_M1_STATUS";
    static const char_T ParameterNameStr_3[14] = "FDD_M2_STATUS";
    static const char_T ParameterNameStr_4[14] = "FDD_M3_STATUS";
    static const char_T ParameterNameStr_5[14] = "FDD_M4_STATUS";
    static const char_T ParameterNameStr_6[14] = "FDD_M5_STATUS";
    static const char_T ParameterNameStr_7[14] = "FDD_M6_STATUS";
    real_T tmp;

    // Start for If: '<S27>/If'
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S24>/In1' incorporates:
    //   Outport: '<S24>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_c = FLIGHT_HEXA_Hovering_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S49>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S50>/In1' incorporates:
    //   Outport: '<S50>/Out1'

    FLIGHT_HEXA_Hovering_B.In1 = FLIGHT_HEXA_Hovering_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S49>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S47>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S62>/In1' incorporates:
    //   Outport: '<S62>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_p = FLIGHT_HEXA_Hovering_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S47>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S46>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S61>/In1' incorporates:
    //   Outport: '<S61>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_f = FLIGHT_HEXA_Hovering_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S46>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S27>/Take-off'
    // InitializeConditions for Delay: '<S39>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S40>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S41>/yaw_In' incorporates:
    //   Outport: '<S41>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In_ik = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S27>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S27>/Land'
    // InitializeConditions for Delay: '<S30>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;

    // InitializeConditions for Gain: '<S35>/Gain1' incorporates:
    //   Delay: '<S35>/Delay'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S36>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S38>/yaw_In' incorporates:
    //   Outport: '<S38>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In_i = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S37>/In' incorporates:
    //   Outport: '<S37>/Out'

    FLIGHT_HEXA_Hovering_B.In = FLIGHT_HEXA_Hovering_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S27>/Land'

    // SystemInitialize for IfAction SubSystem: '<S27>/Waypoint'
    // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
    FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
    FLIGHT_HEXA_Hovering_DW.obj.StartFlag = true;
    FLIGHT_HEXA_Hovering_DW.obj.LookaheadFactor = 1.01;
    FLIGHT_HEXA_Hovering_DW.obj.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S32>/UAV Waypoint Follower'
    FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    memset(&FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[0], 0, 9U * sizeof
           (real_T));

    // End of SystemInitialize for SubSystem: '<S27>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S27>/IDLE'
    // InitializeConditions for Delay: '<S33>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S33>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S34>/yaw_In' incorporates:
    //   Outport: '<S34>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S33>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S27>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
    //   Outport: '<S22>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_j = FLIGHT_HEXA_Hovering_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S17>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S23>/In1' incorporates:
    //   Outport: '<S23>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_m = FLIGHT_HEXA_Hovering_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S17>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_b = FLIGHT_HEXA_Hovering_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S519>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S524>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S571>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_o =
      FLIGHT_HEXA_Hovering_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S576>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o =
      FLIGHT_HEXA_Hovering_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Gain: '<S66>/Gain1' incorporates:
    //   Outport: '<S66>/des_pitch'

    FLIGHT_HEXA_Hovering_B.Gain1 = FLIGHT_HEXA_Hovering_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S66>/des_roll' incorporates:
    //   Saturate: '<S379>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation[1] = FLIGHT_HEXA_Hovering_P.des_roll_Y0;

    // SystemInitialize for Gain: '<S477>/Proportional Gain' incorporates:
    //   Outport: '<S66>/des_yawrate'
    //   Saturate: '<S479>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation_a = FLIGHT_HEXA_Hovering_P.des_yawrate_Y0;

    // SystemInitialize for Sum: '<S585>/Sum' incorporates:
    //   Outport: '<S66>/tau_Thrust'
    //   Saturate: '<S583>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation_o = FLIGHT_HEXA_Hovering_P.tau_Thrust_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_l = FLIGHT_HEXA_Hovering_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S109>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i =
      FLIGHT_HEXA_Hovering_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S104>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ov =
      FLIGHT_HEXA_Hovering_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S63>/Rate Limiter2'
    FLIGHT_HEXA_Hovering_DW.PrevY = FLIGHT_HEXA_Hovering_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S161>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_h =
      FLIGHT_HEXA_Hovering_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S156>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_c =
      FLIGHT_HEXA_Hovering_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S63>/Rate Limiter1'
    FLIGHT_HEXA_Hovering_DW.PrevY_m = FLIGHT_HEXA_Hovering_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S213>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_ih =
      FLIGHT_HEXA_Hovering_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S208>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_f =
      FLIGHT_HEXA_Hovering_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S116>/Saturation' incorporates:
    //   Outport: '<S63>/tau_Yaw'

    FLIGHT_HEXA_Hovering_B.Saturation_n = FLIGHT_HEXA_Hovering_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S168>/Saturation' incorporates:
    //   Outport: '<S63>/tau_Pitch'

    FLIGHT_HEXA_Hovering_B.Saturation_b = FLIGHT_HEXA_Hovering_P.tau_Pitch_Y0;

    // SystemInitialize for Sum: '<S222>/Sum' incorporates:
    //   Outport: '<S63>/tau_Roll'
    //   Saturate: '<S220>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation_a1 = FLIGHT_HEXA_Hovering_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S28>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S57>/If Action Subsystem2'
    // Start for MATLABSystem: '<S60>/Read Parameter'
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
      (&ParameterNameStr[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S57>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S57>/If Action Subsystem1'
    // Start for MATLABSystem: '<S59>/Read Parameter'
    FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g;
    FLIGHT_HEXA_Hovering_DW.obj_b.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S59>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S57>/If Action Subsystem1'
    FLIGHT_HEXA_Hovering_MATLABSystem_Init(&FLIGHT_HEXA_Hovering_DW.MATLABSystem);
    FLIGHT_HEXA_Hovering_MATLABSystem_Init
      (&FLIGHT_HEXA_Hovering_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S54>/MATLAB System'
    FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S56>/SinkBlock' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mc.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                          &FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                          &FLIGHT_HEXA_Hovering_B.BusAssignment1, 1);
    FLIGHT_HEXA_Hovering_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S28>/Send waypoints to OBC'

    // Start for MATLABSystem: '<S18>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_m.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_m.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_m.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_m.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S28>/Read Parameter'
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
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S28>/Read Parameter'

    // Start for MATLABSystem: '<S49>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_e.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_kz.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S46>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gf.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_gf.isSetupComplete = true;

    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_DW.obj_mr.previousValidReceived = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.nextValidReceived = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S21>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_ah.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_ah.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_ah.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_ah.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_ah.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_ah.isSetupComplete = true;

    // Start for MATLABSystem: '<S17>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gv.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_gv.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_gv.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S15>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_d0.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_d0.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_d0.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_d0.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_d0.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_po.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_po.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_po.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_po.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/Read Parameter13'
    FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_a.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter13'

    // Start for MATLABSystem: '<S6>/Read Parameter1'
    FLIGHT_HEXA_Hovering_DW.obj_l.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_l.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_l.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_l.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_l.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter1'

    // Start for MATLABSystem: '<S6>/Read Parameter2'
    FLIGHT_HEXA_Hovering_DW.obj_jh.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_jh.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_jh.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_jh.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_jh.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_jh.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_jh.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter2'

    // Start for MATLABSystem: '<S6>/Read Parameter3'
    FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_p.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter3'

    // Start for MATLABSystem: '<S6>/Read Parameter4'
    FLIGHT_HEXA_Hovering_DW.obj_j.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_j.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_j.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_j.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_j.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter4'

    // Start for MATLABSystem: '<S6>/Read Parameter5'
    FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_d.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter5'

    // Start for MATLABSystem: '<S5>/PX4 PWM Output'
    FLIGHT_HEXA_Hovering_DW.obj_pk.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_pk.isSetupComplete = false;
    FLIGHT_HEXA_Hovering_DW.obj_pk.isInitialized = 1;
    FLIGHT_HEXA_Hovering_PWM_setupImpl(&FLIGHT_HEXA_Hovering_DW.obj_pk, false,
      false);
    FLIGHT_HEXA_Hovering_DW.obj_pk.isSetupComplete = true;

    // Start for MATLABSystem: '<S44>/PX4 Timestamp'
    FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_n.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_n.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_HEXA_Hovering_terminate(void)
{
  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_m.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S28>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter'

  // Terminate for MATLABSystem: '<S49>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_e.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S49>/SourceBlock'

  // Terminate for MATLABSystem: '<S47>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_kz.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S47>/SourceBlock'

  // Terminate for MATLABSystem: '<S46>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_gf.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S46>/SourceBlock'

  // Terminate for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_ah.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_ah.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_ah.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_ah.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_ah.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'

  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_gv.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'

  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_d0.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_d0.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_po.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/Read Parameter13'
  if (!FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter13'

  // Terminate for MATLABSystem: '<S6>/Read Parameter1'
  if (!FLIGHT_HEXA_Hovering_DW.obj_l.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter1'

  // Terminate for MATLABSystem: '<S6>/Read Parameter2'
  if (!FLIGHT_HEXA_Hovering_DW.obj_jh.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_jh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter2'

  // Terminate for MATLABSystem: '<S6>/Read Parameter3'
  if (!FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter3'

  // Terminate for MATLABSystem: '<S6>/Read Parameter4'
  if (!FLIGHT_HEXA_Hovering_DW.obj_j.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter4'

  // Terminate for MATLABSystem: '<S6>/Read Parameter5'
  if (!FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter5'

  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!FLIGHT_HEXA_Hovering_DW.obj_pk.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_pk.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_pk.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_pk.isSetupComplete) {
      pwm_disarm(&FLIGHT_HEXA_Hovering_DW.obj_pk.armAdvertiseObj);
      pwm_resetServo(FLIGHT_HEXA_Hovering_DW.obj_pk.servoCount,
                     FLIGHT_HEXA_Hovering_DW.obj_pk.isMain,
                     &FLIGHT_HEXA_Hovering_DW.obj_pk.actuatorAdvertiseObj);
      pwm_close(FLIGHT_HEXA_Hovering_DW.obj_pk.servoCount,
                &FLIGHT_HEXA_Hovering_DW.obj_pk.actuatorAdvertiseObj,
                &FLIGHT_HEXA_Hovering_DW.obj_pk.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'

  // Terminate for Enabled SubSystem: '<S28>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_MATLABSystem_Term(&FLIGHT_HEXA_Hovering_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S57>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S60>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Read Parameter'
  // End of Terminate for SubSystem: '<S57>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S57>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S59>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S59>/Read Parameter'
  // End of Terminate for SubSystem: '<S57>/If Action Subsystem1'
  FLIGHT_HEXA_Hovering_MATLABSystem_Term(&FLIGHT_HEXA_Hovering_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S54>/MATLAB System'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/MATLAB System'

  // Terminate for MATLABSystem: '<S56>/SinkBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_mc.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S56>/SinkBlock'
  // End of Terminate for SubSystem: '<S28>/Send waypoints to OBC'

  // Terminate for MATLABSystem: '<S44>/PX4 Timestamp'
  if (!FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S44>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
