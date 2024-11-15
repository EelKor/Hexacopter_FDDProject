//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Navigation.cpp
//
// Code generated for Simulink model 'SITL_HEXA_MISSION'.
//
// Model version                  : 5.6
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Sun Oct 20 19:46:11 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Navigation.h"
#include "rtwtypes.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "SITL_HEXA_MISSION_private.h"
#include <string.h>
#include "rt_sys_SITL_HEXA_MISSION_0.h"
#include "rt_sys_SITL_HEXA_MISSION_2.h"
#include "SITL_HEXA_MISSION.h"
#include <float.h>
#include "rt_defines.h"

// Forward declaration for local functions
static real_T SITL_HEXA_MISSION_sind(real_T x);

// Forward declaration for local functions
static real_T SITL_HEXA_MISSION_rt_remd_snf(real_T u0, real_T u1);
static real_T SITL_HEXA_MISSION_sind_d(real_T x);
static real_T SITL_HEXA_MISSION_rt_atan2d_snf(real_T u0, real_T u1);
static void SITL_HEXA_MISSION_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3]);
static real_T SITL_HEXA_MISSION_norm(const real_T x[3]);
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

static real_T SITL_HEXA_MISSION_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S578>/MATLAB System'
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

  // End of Start for MATLABSystem: '<S578>/MATLAB System'
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
void SITL_HEXA_MISSION_MATLABSystem_Init(DW_MATLABSystem_SITL_HEXA_MISSION_T
  *localDW)
{
  // Start for MATLABSystem: '<S578>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void SITL_HEXA_MISSION_MATLABSystem(const real_T rtu_0[3], const real_T rtu_1[3],
  boolean_T rtu_2, uint8_T rtu_3, B_MATLABSystem_SITL_HEXA_MISSION_T *localB)
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

  // MATLABSystem: '<S578>/MATLAB System'
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

    flat = SITL_HEXA_MISSION_sind(rtu_1[0]);
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

    // MATLABSystem: '<S578>/MATLAB System'
    localB->MATLABSystem[0] = static_cast<real32_T>(r + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(r + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(r + flat);
  } else {
    // MATLABSystem: '<S578>/MATLAB System'
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S578>/MATLAB System'
}

// Termination for atomic system:
void SITL_HEXA_MISSION_MATLABSystem_Term(DW_MATLABSystem_SITL_HEXA_MISSION_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S578>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S578>/MATLAB System'
}

static real_T SITL_HEXA_MISSION_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      SITL_HEXA_MISSION_B.q = ceil(u1);
    } else {
      SITL_HEXA_MISSION_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != SITL_HEXA_MISSION_B.q)) {
      SITL_HEXA_MISSION_B.q = fabs(u0 / u1);
      if (!(fabs(SITL_HEXA_MISSION_B.q - floor(SITL_HEXA_MISSION_B.q + 0.5)) >
            DBL_EPSILON * SITL_HEXA_MISSION_B.q)) {
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

static real_T SITL_HEXA_MISSION_sind_d(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S581>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = SITL_HEXA_MISSION_rt_remd_snf(x, 360.0);
    SITL_HEXA_MISSION_B.absx_cx = fabs(b_x);
    if (SITL_HEXA_MISSION_B.absx_cx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      SITL_HEXA_MISSION_B.absx_cx = fabs(b_x);
    }

    if (SITL_HEXA_MISSION_B.absx_cx <= 45.0) {
      b_x *= 0.017453292519943295;
      b_x = sin(b_x);
    } else if (SITL_HEXA_MISSION_B.absx_cx <= 135.0) {
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

  // End of Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
  return b_x;
}

static real_T SITL_HEXA_MISSION_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      SITL_HEXA_MISSION_B.i = 1;
    } else {
      SITL_HEXA_MISSION_B.i = -1;
    }

    if (u1 > 0.0) {
      SITL_HEXA_MISSION_B.i1_c = 1;
    } else {
      SITL_HEXA_MISSION_B.i1_c = -1;
    }

    y = atan2(static_cast<real_T>(SITL_HEXA_MISSION_B.i), static_cast<real_T>
              (SITL_HEXA_MISSION_B.i1_c));
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

static void SITL_HEXA_MISSION_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
  SITL_HEXA_MISSION_B.dLat = lla[0] - lla0[0];
  SITL_HEXA_MISSION_B.dLon = lla[1] - lla0[1];
  SITL_HEXA_MISSION_B.flat_m = fabs(SITL_HEXA_MISSION_B.dLat);
  if (SITL_HEXA_MISSION_B.flat_m > 180.0) {
    // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
    if (rtIsNaN(SITL_HEXA_MISSION_B.dLat + 180.0) || rtIsInf
        (SITL_HEXA_MISSION_B.dLat + 180.0)) {
      SITL_HEXA_MISSION_B.r_k = (rtNaN);
    } else if (SITL_HEXA_MISSION_B.dLat + 180.0 == 0.0) {
      SITL_HEXA_MISSION_B.r_k = 0.0;
    } else {
      SITL_HEXA_MISSION_B.r_k = fmod(SITL_HEXA_MISSION_B.dLat + 180.0, 360.0);
      if (SITL_HEXA_MISSION_B.r_k == 0.0) {
        SITL_HEXA_MISSION_B.r_k = 0.0;
      } else if (SITL_HEXA_MISSION_B.dLat + 180.0 < 0.0) {
        SITL_HEXA_MISSION_B.r_k += 360.0;
      }
    }

    SITL_HEXA_MISSION_B.dLat = SITL_HEXA_MISSION_B.dLat * 0.0 +
      (SITL_HEXA_MISSION_B.r_k - 180.0);
    SITL_HEXA_MISSION_B.flat_m = fabs(SITL_HEXA_MISSION_B.dLat);
  }

  if (SITL_HEXA_MISSION_B.flat_m > 90.0) {
    // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
    SITL_HEXA_MISSION_B.flat_m = fabs(SITL_HEXA_MISSION_B.dLat);
    SITL_HEXA_MISSION_B.latp2_f = (SITL_HEXA_MISSION_B.flat_m > 90.0);

    // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
    SITL_HEXA_MISSION_B.dLon += 180.0;
    SITL_HEXA_MISSION_B.r_k = SITL_HEXA_MISSION_B.dLat * static_cast<real_T>
      (SITL_HEXA_MISSION_B.latp2_f);
    if (rtIsNaN(SITL_HEXA_MISSION_B.r_k)) {
      SITL_HEXA_MISSION_B.r_k = (rtNaN);
    } else if (SITL_HEXA_MISSION_B.r_k < 0.0) {
      SITL_HEXA_MISSION_B.r_k = -1.0;
    } else {
      SITL_HEXA_MISSION_B.r_k = (SITL_HEXA_MISSION_B.r_k > 0.0);
    }

    SITL_HEXA_MISSION_B.dLat = (90.0 - (SITL_HEXA_MISSION_B.flat_m *
      static_cast<real_T>(SITL_HEXA_MISSION_B.latp2_f) - 90.0)) *
      SITL_HEXA_MISSION_B.r_k * static_cast<real_T>(SITL_HEXA_MISSION_B.latp2_f)
      + SITL_HEXA_MISSION_B.dLat * static_cast<real_T>
      (!SITL_HEXA_MISSION_B.latp2_f);
  }

  // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
  if ((SITL_HEXA_MISSION_B.dLon > 180.0) || (SITL_HEXA_MISSION_B.dLon < -180.0))
  {
    SITL_HEXA_MISSION_B.flat_m = SITL_HEXA_MISSION_rt_remd_snf
      (SITL_HEXA_MISSION_B.dLon, 360.0);
    SITL_HEXA_MISSION_B.r_k = SITL_HEXA_MISSION_B.flat_m / 180.0;
    if (SITL_HEXA_MISSION_B.r_k < 0.0) {
      SITL_HEXA_MISSION_B.r_k = ceil(SITL_HEXA_MISSION_B.r_k);
    } else {
      SITL_HEXA_MISSION_B.r_k = floor(SITL_HEXA_MISSION_B.r_k);
    }

    SITL_HEXA_MISSION_B.dLon = (SITL_HEXA_MISSION_B.flat_m - 360.0 *
      SITL_HEXA_MISSION_B.r_k) + SITL_HEXA_MISSION_B.dLon * 0.0;
  }

  SITL_HEXA_MISSION_B.flat_m = SITL_HEXA_MISSION_sind_d(lla0[0]);
  SITL_HEXA_MISSION_B.flat_tmp = 1.0 - 0.0066943799901413165 *
    SITL_HEXA_MISSION_B.flat_m * SITL_HEXA_MISSION_B.flat_m;
  SITL_HEXA_MISSION_B.flat_m = 6.378137E+6 / sqrt(SITL_HEXA_MISSION_B.flat_tmp);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    SITL_HEXA_MISSION_B.r_k = (rtNaN);
  } else {
    SITL_HEXA_MISSION_B.r_k = SITL_HEXA_MISSION_rt_remd_snf(lla0[0], 360.0);
    SITL_HEXA_MISSION_B.absx_c = fabs(SITL_HEXA_MISSION_B.r_k);
    if (SITL_HEXA_MISSION_B.absx_c > 180.0) {
      if (SITL_HEXA_MISSION_B.r_k > 0.0) {
        SITL_HEXA_MISSION_B.r_k -= 360.0;
      } else {
        SITL_HEXA_MISSION_B.r_k += 360.0;
      }

      SITL_HEXA_MISSION_B.absx_c = fabs(SITL_HEXA_MISSION_B.r_k);
    }

    if (SITL_HEXA_MISSION_B.absx_c <= 45.0) {
      SITL_HEXA_MISSION_B.r_k = cos(0.017453292519943295 *
        SITL_HEXA_MISSION_B.r_k);
    } else if (SITL_HEXA_MISSION_B.absx_c <= 135.0) {
      if (SITL_HEXA_MISSION_B.r_k > 0.0) {
        SITL_HEXA_MISSION_B.r_k = -sin((SITL_HEXA_MISSION_B.r_k - 90.0) *
          0.017453292519943295);
      } else {
        SITL_HEXA_MISSION_B.r_k = sin((SITL_HEXA_MISSION_B.r_k + 90.0) *
          0.017453292519943295);
      }
    } else {
      if (SITL_HEXA_MISSION_B.r_k > 0.0) {
        SITL_HEXA_MISSION_B.r_k = (SITL_HEXA_MISSION_B.r_k - 180.0) *
          0.017453292519943295;
      } else {
        SITL_HEXA_MISSION_B.r_k = (SITL_HEXA_MISSION_B.r_k + 180.0) *
          0.017453292519943295;
      }

      SITL_HEXA_MISSION_B.r_k = -cos(SITL_HEXA_MISSION_B.r_k);
    }
  }

  xyzNED[0] = SITL_HEXA_MISSION_B.dLat / (SITL_HEXA_MISSION_rt_atan2d_snf(1.0,
    0.99330562000985867 / SITL_HEXA_MISSION_B.flat_tmp *
    SITL_HEXA_MISSION_B.flat_m) * 57.295779513082323);
  xyzNED[1] = SITL_HEXA_MISSION_B.dLon / (SITL_HEXA_MISSION_rt_atan2d_snf(1.0,
    SITL_HEXA_MISSION_B.flat_m * SITL_HEXA_MISSION_B.r_k) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  SITL_HEXA_MISSION_B.b[0] = rtIsNaN(xyzNED[0]);
  SITL_HEXA_MISSION_B.b[1] = rtIsNaN(xyzNED[1]);
  SITL_HEXA_MISSION_B.b[2] = rtIsNaN(xyzNED[2]);
  SITL_HEXA_MISSION_B.latp2_f = false;
  SITL_HEXA_MISSION_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (SITL_HEXA_MISSION_B.b_k < 3)) {
    if (SITL_HEXA_MISSION_B.b[SITL_HEXA_MISSION_B.b_k]) {
      SITL_HEXA_MISSION_B.latp2_f = true;
      exitg1 = true;
    } else {
      SITL_HEXA_MISSION_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
  SITL_HEXA_MISSION_B.dLat = 0.0 / static_cast<real_T>
    (!SITL_HEXA_MISSION_B.latp2_f);
  xyzNED[0] += SITL_HEXA_MISSION_B.dLat;
  xyzNED[1] += SITL_HEXA_MISSION_B.dLat;
  xyzNED[2] += SITL_HEXA_MISSION_B.dLat;
}

static real_T SITL_HEXA_MISSION_norm(const real_T x[3])
{
  real_T y;
  SITL_HEXA_MISSION_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S559>/UAV Waypoint Follower'
  SITL_HEXA_MISSION_B.absxk = fabs(x[0]);
  if (SITL_HEXA_MISSION_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    SITL_HEXA_MISSION_B.scale = SITL_HEXA_MISSION_B.absxk;
  } else {
    SITL_HEXA_MISSION_B.t = SITL_HEXA_MISSION_B.absxk / 3.3121686421112381E-170;
    y = SITL_HEXA_MISSION_B.t * SITL_HEXA_MISSION_B.t;
  }

  // Start for MATLABSystem: '<S559>/UAV Waypoint Follower'
  SITL_HEXA_MISSION_B.absxk = fabs(x[1]);
  if (SITL_HEXA_MISSION_B.absxk > SITL_HEXA_MISSION_B.scale) {
    SITL_HEXA_MISSION_B.t = SITL_HEXA_MISSION_B.scale /
      SITL_HEXA_MISSION_B.absxk;
    y = y * SITL_HEXA_MISSION_B.t * SITL_HEXA_MISSION_B.t + 1.0;
    SITL_HEXA_MISSION_B.scale = SITL_HEXA_MISSION_B.absxk;
  } else {
    SITL_HEXA_MISSION_B.t = SITL_HEXA_MISSION_B.absxk /
      SITL_HEXA_MISSION_B.scale;
    y += SITL_HEXA_MISSION_B.t * SITL_HEXA_MISSION_B.t;
  }

  // Start for MATLABSystem: '<S559>/UAV Waypoint Follower'
  SITL_HEXA_MISSION_B.absxk = fabs(x[2]);
  if (SITL_HEXA_MISSION_B.absxk > SITL_HEXA_MISSION_B.scale) {
    SITL_HEXA_MISSION_B.t = SITL_HEXA_MISSION_B.scale /
      SITL_HEXA_MISSION_B.absxk;
    y = y * SITL_HEXA_MISSION_B.t * SITL_HEXA_MISSION_B.t + 1.0;
    SITL_HEXA_MISSION_B.scale = SITL_HEXA_MISSION_B.absxk;
  } else {
    SITL_HEXA_MISSION_B.t = SITL_HEXA_MISSION_B.absxk /
      SITL_HEXA_MISSION_B.scale;
    y += SITL_HEXA_MISSION_B.t * SITL_HEXA_MISSION_B.t;
  }

  return SITL_HEXA_MISSION_B.scale * sqrt(y);
}

// System initialize for atomic system: '<Root>/Navigation'
void SITL_HEXA_MISSION_Navigation_Init(void)
{
  static const char_T ParameterNameStr[15] = "MPC_LAND_SPEED";
  static const char_T ParameterNameStr_0[14] = "MPC_TKO_SPEED";
  static const char_T ParameterNameStr_1[14] = "COM_OBS_AVOID";
  real_T tmp;

  // Start for If: '<S554>/If'
  SITL_HEXA_MISSION_DW.If_ActiveSubsystem = -1;

  // SystemInitialize for Enabled SubSystem: '<S576>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S577>/In1' incorporates:
  //   Outport: '<S577>/Out1'

  SITL_HEXA_MISSION_B.In1 = SITL_HEXA_MISSION_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S576>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S574>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S589>/In1' incorporates:
  //   Outport: '<S589>/Out1'

  SITL_HEXA_MISSION_B.In1_p = SITL_HEXA_MISSION_P.Out1_Y0_h;

  // End of SystemInitialize for SubSystem: '<S574>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S573>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S588>/In1' incorporates:
  //   Outport: '<S588>/Out1'

  SITL_HEXA_MISSION_B.In1_f = SITL_HEXA_MISSION_P.Out1_Y0_o;

  // End of SystemInitialize for SubSystem: '<S573>/Enabled Subsystem'

  // SystemInitialize for IfAction SubSystem: '<S554>/Take-off'
  // InitializeConditions for Delay: '<S566>/Delay'
  SITL_HEXA_MISSION_DW.Delay_DSTATE_c =
    SITL_HEXA_MISSION_P.Delay_InitialCondition;

  // InitializeConditions for Delay: '<S567>/Delay'
  SITL_HEXA_MISSION_DW.Delay_DSTATE_d =
    SITL_HEXA_MISSION_P.Delay_InitialCondition_g;

  // SystemInitialize for Enabled SubSystem: '<S567>/Enabled Subsystem2'
  // SystemInitialize for SignalConversion generated from: '<S568>/yaw_In' incorporates:
  //   Outport: '<S568>/yaw_Out'

  SITL_HEXA_MISSION_B.yaw_In_ik = SITL_HEXA_MISSION_P.yaw_Out_Y0;

  // End of SystemInitialize for SubSystem: '<S567>/Enabled Subsystem2'
  // End of SystemInitialize for SubSystem: '<S554>/Take-off'

  // SystemInitialize for IfAction SubSystem: '<S554>/Land'
  // InitializeConditions for Delay: '<S557>/Delay'
  SITL_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
    SITL_HEXA_MISSION_P.Delay_InitialCondition_n;
  SITL_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
    SITL_HEXA_MISSION_P.Delay_InitialCondition_n;

  // InitializeConditions for Delay: '<S562>/Delay'
  SITL_HEXA_MISSION_DW.Delay_DSTATE_n =
    SITL_HEXA_MISSION_P.Delay_InitialCondition_m;

  // InitializeConditions for Delay: '<S563>/Delay'
  SITL_HEXA_MISSION_DW.Delay_DSTATE_b =
    SITL_HEXA_MISSION_P.Delay_InitialCondition_j;

  // SystemInitialize for Enabled SubSystem: '<S563>/Enabled Subsystem2'
  // SystemInitialize for SignalConversion generated from: '<S565>/yaw_In' incorporates:
  //   Outport: '<S565>/yaw_Out'

  SITL_HEXA_MISSION_B.yaw_In_i = SITL_HEXA_MISSION_P.yaw_Out_Y0_f;

  // End of SystemInitialize for SubSystem: '<S563>/Enabled Subsystem2'

  // SystemInitialize for Enabled SubSystem: '<S562>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S564>/In' incorporates:
  //   Outport: '<S564>/Out'

  SITL_HEXA_MISSION_B.In = SITL_HEXA_MISSION_P.Out_Y0;

  // End of SystemInitialize for SubSystem: '<S562>/Enabled Subsystem'
  // End of SystemInitialize for SubSystem: '<S554>/Land'

  // SystemInitialize for IfAction SubSystem: '<S554>/Waypoint'
  // Start for MATLABSystem: '<S559>/UAV Waypoint Follower'
  SITL_HEXA_MISSION_DW.obj.LastWaypointFlag = false;
  SITL_HEXA_MISSION_DW.obj.StartFlag = true;
  SITL_HEXA_MISSION_DW.obj.LookaheadFactor = 1.01;
  SITL_HEXA_MISSION_DW.obj.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj.NumWaypoints = 0.0;

  // InitializeConditions for MATLABSystem: '<S559>/UAV Waypoint Follower'
  SITL_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
  memset(&SITL_HEXA_MISSION_DW.obj.WaypointsInternal[0], 0, 9U * sizeof(real_T));

  // End of SystemInitialize for SubSystem: '<S554>/Waypoint'

  // SystemInitialize for IfAction SubSystem: '<S554>/IDLE'
  // InitializeConditions for Delay: '<S560>/Delay'
  SITL_HEXA_MISSION_DW.Delay_DSTATE =
    SITL_HEXA_MISSION_P.Delay_InitialCondition_g0;

  // SystemInitialize for Enabled SubSystem: '<S560>/Enabled Subsystem2'
  // SystemInitialize for SignalConversion generated from: '<S561>/yaw_In' incorporates:
  //   Outport: '<S561>/yaw_Out'

  SITL_HEXA_MISSION_B.yaw_In = SITL_HEXA_MISSION_P.yaw_Out_Y0_p;

  // End of SystemInitialize for SubSystem: '<S560>/Enabled Subsystem2'
  // End of SystemInitialize for SubSystem: '<S554>/IDLE'

  // SystemInitialize for Enabled SubSystem: '<S555>/Send waypoints to OBC'
  // SystemInitialize for IfAction SubSystem: '<S584>/If Action Subsystem2'
  // Start for MATLABSystem: '<S587>/Read Parameter'
  SITL_HEXA_MISSION_DW.obj_ga.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_ga.SampleTime =
    SITL_HEXA_MISSION_P.ReadParameter_SampleTime_c;
  SITL_HEXA_MISSION_DW.obj_ga.isInitialized = 1;
  if (SITL_HEXA_MISSION_DW.obj_ga.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_MISSION_DW.obj_ga.SampleTime;
  }

  SITL_HEXA_MISSION_DW.obj_ga.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
    true, tmp * 1000.0);
  SITL_HEXA_MISSION_DW.obj_ga.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S587>/Read Parameter'
  // End of SystemInitialize for SubSystem: '<S584>/If Action Subsystem2'

  // SystemInitialize for IfAction SubSystem: '<S584>/If Action Subsystem1'
  // Start for MATLABSystem: '<S586>/Read Parameter'
  SITL_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_b.SampleTime =
    SITL_HEXA_MISSION_P.ReadParameter_SampleTime_g;
  SITL_HEXA_MISSION_DW.obj_b.isInitialized = 1;
  if (SITL_HEXA_MISSION_DW.obj_b.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_MISSION_DW.obj_b.SampleTime;
  }

  SITL_HEXA_MISSION_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0
    [0], true, tmp * 1000.0);
  SITL_HEXA_MISSION_DW.obj_b.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S586>/Read Parameter'
  // End of SystemInitialize for SubSystem: '<S584>/If Action Subsystem1'
  SITL_HEXA_MISSION_MATLABSystem_Init(&SITL_HEXA_MISSION_DW.MATLABSystem);
  SITL_HEXA_MISSION_MATLABSystem_Init(&SITL_HEXA_MISSION_DW.MATLABSystem_b);

  // Start for MATLABSystem: '<S581>/MATLAB System'
  SITL_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_mu.isSetupComplete = true;

  // Start for MATLABSystem: '<S583>/SinkBlock' incorporates:
  //   BusAssignment: '<S572>/Bus Assignment1'

  SITL_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_mc.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_mc.orbMetadataObj = ORB_ID
    (vehicle_trajectory_waypoint_desired);
  uORB_write_initialize(SITL_HEXA_MISSION_DW.obj_mc.orbMetadataObj,
                        &SITL_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj,
                        &SITL_HEXA_MISSION_B.BusAssignment1, 1);
  SITL_HEXA_MISSION_DW.obj_mc.isSetupComplete = true;

  // End of SystemInitialize for SubSystem: '<S555>/Send waypoints to OBC'

  // Start for MATLABSystem: '<S555>/Read Parameter'
  SITL_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_k.SampleTime =
    SITL_HEXA_MISSION_P.ReadParameter_SampleTime;
  SITL_HEXA_MISSION_DW.obj_k.isInitialized = 1;
  if (SITL_HEXA_MISSION_DW.obj_k.SampleTime == -1.0) {
    tmp = 0.2;
  } else {
    tmp = SITL_HEXA_MISSION_DW.obj_k.SampleTime;
  }

  SITL_HEXA_MISSION_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1
    [0], true, tmp * 1000.0);
  SITL_HEXA_MISSION_DW.obj_k.isSetupComplete = true;

  // End of Start for MATLABSystem: '<S555>/Read Parameter'

  // Start for MATLABSystem: '<S576>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_e.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_e.orbMetadataObj = ORB_ID(vehicle_trajectory_waypoint);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_e.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_e.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_e.isSetupComplete = true;

  // Start for MATLABSystem: '<S574>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_kz.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_kz.orbMetadataObj = ORB_ID(position_setpoint_triplet);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_kz.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_kz.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_kz.isSetupComplete = true;

  // Start for MATLABSystem: '<S573>/SourceBlock'
  SITL_HEXA_MISSION_DW.obj_gf.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_gf.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_gf.orbMetadataObj = ORB_ID(home_position);
  uORB_read_initialize(SITL_HEXA_MISSION_DW.obj_gf.orbMetadataObj,
                       &SITL_HEXA_MISSION_DW.obj_gf.eventStructObj);
  SITL_HEXA_MISSION_DW.obj_gf.isSetupComplete = true;

  // Start for MATLABSystem: '<S555>/LLA2LocalCoordinates'
  SITL_HEXA_MISSION_DW.obj_mr.previousValidReceived = false;
  SITL_HEXA_MISSION_DW.obj_mr.nextValidReceived = false;
  SITL_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted = false;
  SITL_HEXA_MISSION_DW.obj_mr.isInitialized = 1;
  SITL_HEXA_MISSION_DW.obj_mr.isSetupComplete = true;
  SITL_HEXA_MISSION_PX4Timestamp_Init(&SITL_HEXA_MISSION_DW.PX4Timestamp_pna);
  SITL_HEXA_MISSION_SinkBlock_Init(&SITL_HEXA_MISSION_B.BusAssignment_m,
    &SITL_HEXA_MISSION_DW.SinkBlock_a);
  SITL_HEXA_MISSION_PX4Timestamp_Init(&SITL_HEXA_MISSION_DW.PX4Timestamp_o);
}

// Output and update for atomic system: '<Root>/Navigation'
void SITL_HEXA_MISSION_Navigation(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;

  // MATLABSystem: '<S555>/Read Parameter'
  if (SITL_HEXA_MISSION_DW.obj_k.SampleTime !=
      SITL_HEXA_MISSION_P.ReadParameter_SampleTime) {
    SITL_HEXA_MISSION_DW.obj_k.SampleTime =
      SITL_HEXA_MISSION_P.ReadParameter_SampleTime;
  }

  SITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (SITL_HEXA_MISSION_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &SITL_HEXA_MISSION_B.ParamStep_b);
  if (SITL_HEXA_MISSION_B.OR_g) {
    SITL_HEXA_MISSION_B.ParamStep_b = 0;
  }

  // MATLABSystem: '<S576>/SourceBlock'
  SITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_e.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_e.eventStructObj, &SITL_HEXA_MISSION_B.r, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S576>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S577>/Enable'

  // Start for MATLABSystem: '<S576>/SourceBlock'
  if (SITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S577>/In1'
    SITL_HEXA_MISSION_B.In1 = SITL_HEXA_MISSION_B.r;
  }

  // End of Outputs for SubSystem: '<S576>/Enabled Subsystem'

  // MATLABSystem: '<S574>/SourceBlock'
  SITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_kz.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_kz.eventStructObj, &SITL_HEXA_MISSION_B.r1, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S574>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S589>/Enable'

  // Start for MATLABSystem: '<S574>/SourceBlock'
  if (SITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S589>/In1'
    SITL_HEXA_MISSION_B.In1_p = SITL_HEXA_MISSION_B.r1;
  }

  // End of Outputs for SubSystem: '<S574>/Enabled Subsystem'

  // MATLABSystem: '<S573>/SourceBlock'
  SITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (SITL_HEXA_MISSION_DW.obj_gf.orbMetadataObj,
     &SITL_HEXA_MISSION_DW.obj_gf.eventStructObj, &SITL_HEXA_MISSION_B.r2, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S573>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S588>/Enable'

  // Start for MATLABSystem: '<S573>/SourceBlock'
  if (SITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S588>/In1'
    SITL_HEXA_MISSION_B.In1_f = SITL_HEXA_MISSION_B.r2;
  }

  // End of Outputs for SubSystem: '<S573>/Enabled Subsystem'

  // MATLABSystem: '<S555>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S555>/Read Parameter'
  //   SignalConversion generated from: '<S588>/In1'
  //
  SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] = 0.0;
  SITL_HEXA_MISSION_B.MatrixConcatenate1[0] = 0.0;
  SITL_HEXA_MISSION_B.virtualWaypoint[0] = 0.0;
  SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] = 0.0;
  SITL_HEXA_MISSION_B.MatrixConcatenate1[1] = 0.0;
  SITL_HEXA_MISSION_B.virtualWaypoint[1] = 0.0;
  SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] = 0.0;
  SITL_HEXA_MISSION_B.MatrixConcatenate1[2] = 0.0;
  SITL_HEXA_MISSION_B.virtualWaypoint[2] = 0.0;
  SITL_HEXA_MISSION_B.lla0[0] = SITL_HEXA_MISSION_B.In1_f.lat;
  SITL_HEXA_MISSION_B.lla0[1] = SITL_HEXA_MISSION_B.In1_f.lon;
  SITL_HEXA_MISSION_B.lla0[2] = SITL_HEXA_MISSION_B.In1_f.alt;
  if (SITL_HEXA_MISSION_B.In1_p.previous.valid &&
      (!SITL_HEXA_MISSION_DW.obj_mr.previousValidReceived)) {
    SITL_HEXA_MISSION_DW.obj_mr.previousValidReceived = true;
  }

  if (SITL_HEXA_MISSION_B.In1_p.next.valid &&
      (!SITL_HEXA_MISSION_DW.obj_mr.nextValidReceived)) {
    SITL_HEXA_MISSION_DW.obj_mr.nextValidReceived = true;
  }

  if (SITL_HEXA_MISSION_B.In1_f.valid_hpos &&
      SITL_HEXA_MISSION_B.In1_p.current.valid &&
      (SITL_HEXA_MISSION_B.In1_p.current.type != 5)) {
    if (SITL_HEXA_MISSION_B.ParamStep_b != 0) {
      SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
        SITL_HEXA_MISSION_B.In1.waypoints[0].position[0];
      SITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
        SITL_HEXA_MISSION_B.In1.waypoints[0].position[1];
      SITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
        SITL_HEXA_MISSION_B.In1.waypoints[0].position[2];
    } else {
      SITL_HEXA_MISSION_B.dv[0] = SITL_HEXA_MISSION_B.In1_p.current.lat;
      SITL_HEXA_MISSION_B.dv[1] = SITL_HEXA_MISSION_B.In1_p.current.lon;
      SITL_HEXA_MISSION_B.dv[2] = SITL_HEXA_MISSION_B.In1_p.current.alt;
      SITL_HEXA_MISSION_lla2ned(SITL_HEXA_MISSION_B.dv, SITL_HEXA_MISSION_B.lla0,
        SITL_HEXA_MISSION_B.MatrixConcatenate1);
    }
  }

  if (SITL_HEXA_MISSION_B.In1_f.valid_hpos &&
      (SITL_HEXA_MISSION_B.In1_p.previous.valid ||
       SITL_HEXA_MISSION_DW.obj_mr.previousValidReceived)) {
    SITL_HEXA_MISSION_B.dv[0] = SITL_HEXA_MISSION_B.In1_p.previous.lat;
    SITL_HEXA_MISSION_B.dv[1] = SITL_HEXA_MISSION_B.In1_p.previous.lon;
    SITL_HEXA_MISSION_B.dv[2] = SITL_HEXA_MISSION_B.In1_p.previous.alt;
    SITL_HEXA_MISSION_lla2ned(SITL_HEXA_MISSION_B.dv, SITL_HEXA_MISSION_B.lla0,
      SITL_HEXA_MISSION_B.MatrixConcatenate1_k);
  }

  if (SITL_HEXA_MISSION_B.In1_f.valid_hpos &&
      (SITL_HEXA_MISSION_B.In1_p.next.valid ||
       SITL_HEXA_MISSION_DW.obj_mr.nextValidReceived)) {
    SITL_HEXA_MISSION_B.dv[0] = SITL_HEXA_MISSION_B.In1_p.next.lat;
    SITL_HEXA_MISSION_B.dv[1] = SITL_HEXA_MISSION_B.In1_p.next.lon;
    SITL_HEXA_MISSION_B.dv[2] = SITL_HEXA_MISSION_B.In1_p.next.alt;
    SITL_HEXA_MISSION_lla2ned(SITL_HEXA_MISSION_B.dv, SITL_HEXA_MISSION_B.lla0,
      SITL_HEXA_MISSION_B.virtualWaypoint);
  }

  // If: '<S554>/If' incorporates:
  //   Delay: '<S560>/Delay'
  //   Delay: '<S563>/Delay'
  //   Delay: '<S567>/Delay'
  //   MATLABSystem: '<S555>/LLA2LocalCoordinates'
  //
  SITL_HEXA_MISSION_B.rtPrevAction = SITL_HEXA_MISSION_DW.If_ActiveSubsystem;
  if (SITL_HEXA_MISSION_B.In1_p.current.type == 3) {
    SITL_HEXA_MISSION_B.rtAction = 0;
  } else if (SITL_HEXA_MISSION_B.In1_p.current.type == 4) {
    SITL_HEXA_MISSION_B.rtAction = 1;
  } else if (SITL_HEXA_MISSION_B.In1_p.current.type == 0) {
    SITL_HEXA_MISSION_B.rtAction = 2;
  } else {
    SITL_HEXA_MISSION_B.rtAction = 3;
  }

  SITL_HEXA_MISSION_DW.If_ActiveSubsystem = SITL_HEXA_MISSION_B.rtAction;
  switch (SITL_HEXA_MISSION_B.rtAction) {
   case 0:
    if (SITL_HEXA_MISSION_B.rtAction != SITL_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S554>/Take-off' incorporates:
      //   ActionPort: '<S558>/Action Port'

      // InitializeConditions for If: '<S554>/If' incorporates:
      //   Delay: '<S566>/Delay'
      //   Delay: '<S567>/Delay'

      SITL_HEXA_MISSION_DW.Delay_DSTATE_c =
        SITL_HEXA_MISSION_P.Delay_InitialCondition;
      SITL_HEXA_MISSION_DW.Delay_DSTATE_d =
        SITL_HEXA_MISSION_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S554>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S554>/Take-off' incorporates:
    //   ActionPort: '<S558>/Action Port'

    // Sum: '<S566>/Sum' incorporates:
    //   Constant: '<S566>/Rate'
    //   Delay: '<S566>/Delay'

    SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_P.Rate_Value +
      SITL_HEXA_MISSION_DW.Delay_DSTATE_c;

    // Gain: '<S566>/Gain1'
    SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_P.Gain1_Gain_b *
      SITL_HEXA_MISSION_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S567>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S568>/Enable'

    if (SITL_HEXA_MISSION_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S568>/yaw_In'
      SITL_HEXA_MISSION_B.yaw_In_ik = SITL_HEXA_MISSION_B.DataTypeConversion1[6];
    }

    // End of Outputs for SubSystem: '<S567>/Enabled Subsystem2'

    // Reshape: '<S558>/Reshape' incorporates:
    //   Delay: '<S567>/Delay'
    //   Merge: '<S554>/Merge'

    SITL_HEXA_MISSION_B.Merge[0] = SITL_HEXA_MISSION_B.MatrixConcatenate1[0];
    SITL_HEXA_MISSION_B.Merge[1] = SITL_HEXA_MISSION_B.MatrixConcatenate1[1];

    // Gain: '<S566>/Gain' incorporates:
    //   RelationalOperator: '<S566>/Relational Operator'
    //   Switch: '<S566>/Switch'

    if (!(SITL_HEXA_MISSION_B.Gain_i <= SITL_HEXA_MISSION_B.Sum_f)) {
      SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.Sum_f;
    }

    // Reshape: '<S558>/Reshape' incorporates:
    //   Gain: '<S566>/Gain'
    //   Merge: '<S554>/Merge'
    //   Switch: '<S566>/Switch'

    SITL_HEXA_MISSION_B.Merge[2] = SITL_HEXA_MISSION_P.Gain_Gain_e *
      SITL_HEXA_MISSION_B.Gain_i;
    SITL_HEXA_MISSION_B.Merge[3] = SITL_HEXA_MISSION_B.yaw_In_ik;

    // Update for Delay: '<S566>/Delay'
    SITL_HEXA_MISSION_DW.Delay_DSTATE_c = SITL_HEXA_MISSION_B.Sum_f;

    // Update for Delay: '<S567>/Delay' incorporates:
    //   Constant: '<S567>/Constant'

    SITL_HEXA_MISSION_DW.Delay_DSTATE_d = SITL_HEXA_MISSION_P.Constant_Value_f;

    // End of Outputs for SubSystem: '<S554>/Take-off'
    break;

   case 1:
    if (SITL_HEXA_MISSION_B.rtAction != SITL_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S554>/Land' incorporates:
      //   ActionPort: '<S557>/Action Port'

      // InitializeConditions for If: '<S554>/If' incorporates:
      //   Delay: '<S557>/Delay'
      //   Delay: '<S562>/Delay'
      //   Delay: '<S563>/Delay'

      SITL_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
        SITL_HEXA_MISSION_P.Delay_InitialCondition_n;
      SITL_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
        SITL_HEXA_MISSION_P.Delay_InitialCondition_n;
      SITL_HEXA_MISSION_DW.Delay_DSTATE_n =
        SITL_HEXA_MISSION_P.Delay_InitialCondition_m;
      SITL_HEXA_MISSION_DW.Delay_DSTATE_b =
        SITL_HEXA_MISSION_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S554>/Land'
    }

    // Outputs for IfAction SubSystem: '<S554>/Land' incorporates:
    //   ActionPort: '<S557>/Action Port'

    // Delay: '<S562>/Delay'
    SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_DW.Delay_DSTATE_n;

    // Switch: '<S562>/Switch' incorporates:
    //   Delay: '<S562>/Delay'
    //   Gain: '<S562>/Gain'

    if (!(SITL_HEXA_MISSION_DW.Delay_DSTATE_n >
          SITL_HEXA_MISSION_P.Switch_Threshold_j)) {
      SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_P.Gain_Gain_l *
        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
    }

    // End of Switch: '<S562>/Switch'

    // Sum: '<S562>/Subtract' incorporates:
    //   Constant: '<S562>/Rate of descent'

    SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.Sum_f -
      SITL_HEXA_MISSION_P.Rateofdescent_Value;

    // Gain: '<S562>/Gain2'
    SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_P.Gain2_Gain *
      SITL_HEXA_MISSION_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S563>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S565>/Enable'

    if (SITL_HEXA_MISSION_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S565>/yaw_In'
      SITL_HEXA_MISSION_B.yaw_In_i = SITL_HEXA_MISSION_B.DataTypeConversion1[6];
    }

    // End of Outputs for SubSystem: '<S563>/Enabled Subsystem2'

    // Switch: '<S557>/Switch' incorporates:
    //   Delay: '<S563>/Delay'
    //   Logic: '<S557>/OR'
    //   RelationalOperator: '<S557>/IsNaN'

    if (rtIsNaN(SITL_HEXA_MISSION_B.MatrixConcatenate1[0]) || rtIsNaN
        (SITL_HEXA_MISSION_B.MatrixConcatenate1[1])) {
      // Reshape: '<S557>/Reshape' incorporates:
      //   Delay: '<S557>/Delay'
      //   Merge: '<S554>/Merge'

      SITL_HEXA_MISSION_B.Merge[0] = SITL_HEXA_MISSION_DW.Delay_DSTATE_l[0];
      SITL_HEXA_MISSION_B.Merge[1] = SITL_HEXA_MISSION_DW.Delay_DSTATE_l[1];
    } else {
      // Reshape: '<S557>/Reshape' incorporates:
      //   Delay: '<S557>/Delay'
      //   Merge: '<S554>/Merge'

      SITL_HEXA_MISSION_B.Merge[0] = SITL_HEXA_MISSION_B.MatrixConcatenate1[0];
      SITL_HEXA_MISSION_B.Merge[1] = SITL_HEXA_MISSION_B.MatrixConcatenate1[1];
    }

    // End of Switch: '<S557>/Switch'

    // Reshape: '<S557>/Reshape' incorporates:
    //   Gain: '<S562>/Gain1'
    //   Merge: '<S554>/Merge'
    //   RelationalOperator: '<S562>/GreaterThan'
    //   Switch: '<S562>/Switch1'

    if (!(SITL_HEXA_MISSION_B.Sum_f > SITL_HEXA_MISSION_B.Gain_i)) {
      SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.Gain_i;
    }

    SITL_HEXA_MISSION_B.Merge[2] = SITL_HEXA_MISSION_P.Gain1_Gain_a *
      SITL_HEXA_MISSION_B.Sum_f;
    SITL_HEXA_MISSION_B.Merge[3] = SITL_HEXA_MISSION_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S562>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S564>/Enable'

    if (SITL_HEXA_MISSION_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S564>/In'
      SITL_HEXA_MISSION_B.In = SITL_HEXA_MISSION_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S562>/Enabled Subsystem'

    // Update for Delay: '<S557>/Delay'
    SITL_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
      SITL_HEXA_MISSION_B.DataTypeConversion1[0];
    SITL_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
      SITL_HEXA_MISSION_B.DataTypeConversion1[1];

    // Update for Delay: '<S562>/Delay'
    SITL_HEXA_MISSION_DW.Delay_DSTATE_n = SITL_HEXA_MISSION_B.In;

    // Update for Delay: '<S563>/Delay' incorporates:
    //   Constant: '<S563>/Constant'

    SITL_HEXA_MISSION_DW.Delay_DSTATE_b = SITL_HEXA_MISSION_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S554>/Land'
    break;

   case 2:
    if (SITL_HEXA_MISSION_B.rtAction != SITL_HEXA_MISSION_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S554>/Waypoint' incorporates:
      //   ActionPort: '<S559>/Action Port'

      // SystemReset for If: '<S554>/If' incorporates:
      //   MATLABSystem: '<S559>/UAV Waypoint Follower'
      //
      SITL_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
      for (SITL_HEXA_MISSION_B.i1 = 0; SITL_HEXA_MISSION_B.i1 < 9;
           SITL_HEXA_MISSION_B.i1++) {
        SITL_HEXA_MISSION_DW.obj.WaypointsInternal[SITL_HEXA_MISSION_B.i1] *=
          0.0;
      }

      // End of SystemReset for If: '<S554>/If'
      // End of SystemReset for SubSystem: '<S554>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S554>/Waypoint' incorporates:
    //   ActionPort: '<S559>/Action Port'

    // Concatenate: '<S559>/Matrix Concatenate'
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[0] =
      SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[1] =
      SITL_HEXA_MISSION_B.MatrixConcatenate1[0];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[2] =
      SITL_HEXA_MISSION_B.virtualWaypoint[0];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[3] =
      SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[4] =
      SITL_HEXA_MISSION_B.MatrixConcatenate1[1];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[5] =
      SITL_HEXA_MISSION_B.virtualWaypoint[1];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[6] =
      SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[7] =
      SITL_HEXA_MISSION_B.MatrixConcatenate1[2];
    SITL_HEXA_MISSION_B.MatrixConcatenate_p[8] =
      SITL_HEXA_MISSION_B.virtualWaypoint[2];

    // MATLABSystem: '<S559>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S559>/Matrix Concatenate'
    //   Constant: '<S559>/Constant'

    SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_P.Constant_Value_gw;
    SITL_HEXA_MISSION_DW.obj.LookaheadDistFlag = 0U;
    if (SITL_HEXA_MISSION_P.Constant_Value_gw < 0.3) {
      SITL_HEXA_MISSION_B.Sum_f = 0.3;
      SITL_HEXA_MISSION_DW.obj.LookaheadDistFlag = 1U;
    }

    SITL_HEXA_MISSION_DW.obj.InitialPose[0] = 0.0;
    SITL_HEXA_MISSION_DW.obj.InitialPose[1] = 0.0;
    SITL_HEXA_MISSION_DW.obj.InitialPose[2] = 0.0;
    SITL_HEXA_MISSION_DW.obj.InitialPose[3] = 0.0;
    SITL_HEXA_MISSION_DW.obj.NumWaypoints = 3.0;
    SITL_HEXA_MISSION_B.OR_g = false;
    SITL_HEXA_MISSION_B.latp2 = true;
    SITL_HEXA_MISSION_B.iy = 0;
    exitg1 = false;
    while ((!exitg1) && (SITL_HEXA_MISSION_B.iy <= 8)) {
      SITL_HEXA_MISSION_B.i1 = SITL_HEXA_MISSION_B.iy / 3 * 3 +
        SITL_HEXA_MISSION_B.iy % 3;
      if (!(SITL_HEXA_MISSION_DW.obj.WaypointsInternal[SITL_HEXA_MISSION_B.i1] ==
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[SITL_HEXA_MISSION_B.i1])) {
        SITL_HEXA_MISSION_B.latp2 = false;
        exitg1 = true;
      } else {
        SITL_HEXA_MISSION_B.iy++;
      }
    }

    if (SITL_HEXA_MISSION_B.latp2) {
      SITL_HEXA_MISSION_B.OR_g = true;
    }

    if (!SITL_HEXA_MISSION_B.OR_g) {
      memcpy(&SITL_HEXA_MISSION_DW.obj.WaypointsInternal[0],
             &SITL_HEXA_MISSION_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      SITL_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
    }

    SITL_HEXA_MISSION_B.i1 = 0;
    SITL_HEXA_MISSION_B.iy = 0;
    for (SITL_HEXA_MISSION_B.j = 0; SITL_HEXA_MISSION_B.j < 3;
         SITL_HEXA_MISSION_B.j++) {
      SITL_HEXA_MISSION_B.distinctWptsIdx[SITL_HEXA_MISSION_B.j] = true;
      SITL_HEXA_MISSION_B.b_xyzNED_idx_1 =
        SITL_HEXA_MISSION_B.MatrixConcatenate_p[SITL_HEXA_MISSION_B.i1 + 1];
      SITL_HEXA_MISSION_B.x[SITL_HEXA_MISSION_B.iy] =
        (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 !=
         SITL_HEXA_MISSION_B.MatrixConcatenate_p[SITL_HEXA_MISSION_B.i1]);
      SITL_HEXA_MISSION_B.x[SITL_HEXA_MISSION_B.iy + 1] =
        (SITL_HEXA_MISSION_B.MatrixConcatenate_p[SITL_HEXA_MISSION_B.i1 + 2] !=
         SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
      SITL_HEXA_MISSION_B.i1 += 3;
      SITL_HEXA_MISSION_B.iy += 2;
    }

    SITL_HEXA_MISSION_B.IsNaN_l[0] = false;
    SITL_HEXA_MISSION_B.IsNaN_l[1] = false;
    SITL_HEXA_MISSION_B.i1 = 0;
    SITL_HEXA_MISSION_B.iy = 4;
    for (SITL_HEXA_MISSION_B.j = 0; SITL_HEXA_MISSION_B.j < 2;
         SITL_HEXA_MISSION_B.j++) {
      SITL_HEXA_MISSION_B.i1++;
      SITL_HEXA_MISSION_B.iy++;
      SITL_HEXA_MISSION_B.ix = SITL_HEXA_MISSION_B.i1;
      exitg1 = false;
      while ((!exitg1) && (SITL_HEXA_MISSION_B.ix <= SITL_HEXA_MISSION_B.iy)) {
        if (SITL_HEXA_MISSION_B.x[SITL_HEXA_MISSION_B.ix - 1]) {
          SITL_HEXA_MISSION_B.IsNaN_l[SITL_HEXA_MISSION_B.j] = true;
          exitg1 = true;
        } else {
          SITL_HEXA_MISSION_B.ix += 2;
        }
      }
    }

    SITL_HEXA_MISSION_B.distinctWptsIdx[0] = SITL_HEXA_MISSION_B.IsNaN_l[0];
    SITL_HEXA_MISSION_B.distinctWptsIdx[1] = SITL_HEXA_MISSION_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S554>/Waypoint'
    SITL_HEXA_MISSION_B.iy = 0;
    for (SITL_HEXA_MISSION_B.i1 = 0; SITL_HEXA_MISSION_B.i1 < 3;
         SITL_HEXA_MISSION_B.i1++) {
      // Outputs for IfAction SubSystem: '<S554>/Waypoint' incorporates:
      //   ActionPort: '<S559>/Action Port'

      if (SITL_HEXA_MISSION_B.distinctWptsIdx[SITL_HEXA_MISSION_B.i1]) {
        SITL_HEXA_MISSION_B.iy++;
      }

      // End of Outputs for SubSystem: '<S554>/Waypoint'
    }

    SITL_HEXA_MISSION_B.j = SITL_HEXA_MISSION_B.iy;
    SITL_HEXA_MISSION_B.iy = 0;
    for (SITL_HEXA_MISSION_B.i1 = 0; SITL_HEXA_MISSION_B.i1 < 3;
         SITL_HEXA_MISSION_B.i1++) {
      // Outputs for IfAction SubSystem: '<S554>/Waypoint' incorporates:
      //   ActionPort: '<S559>/Action Port'

      if (SITL_HEXA_MISSION_B.distinctWptsIdx[SITL_HEXA_MISSION_B.i1]) {
        // Start for MATLABSystem: '<S559>/UAV Waypoint Follower'
        SITL_HEXA_MISSION_B.tmp_data[SITL_HEXA_MISSION_B.iy] =
          static_cast<int8_T>(SITL_HEXA_MISSION_B.i1);
        SITL_HEXA_MISSION_B.iy++;
      }

      // End of Outputs for SubSystem: '<S554>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S554>/Waypoint' incorporates:
    //   ActionPort: '<S559>/Action Port'

    // MATLABSystem: '<S559>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S559>/Matrix Concatenate'
    //   Reshape: '<S559>/Reshape1'

    for (SITL_HEXA_MISSION_B.i1 = 0; SITL_HEXA_MISSION_B.i1 < 3;
         SITL_HEXA_MISSION_B.i1++) {
      for (SITL_HEXA_MISSION_B.iy = 0; SITL_HEXA_MISSION_B.iy <
           SITL_HEXA_MISSION_B.j; SITL_HEXA_MISSION_B.iy++) {
        SITL_HEXA_MISSION_B.b_waypointsIn_data[SITL_HEXA_MISSION_B.iy +
          SITL_HEXA_MISSION_B.j * SITL_HEXA_MISSION_B.i1] =
          SITL_HEXA_MISSION_B.MatrixConcatenate_p[3 * SITL_HEXA_MISSION_B.i1 +
          SITL_HEXA_MISSION_B.tmp_data[SITL_HEXA_MISSION_B.iy]];
      }
    }

    SITL_HEXA_MISSION_DW.obj.LookaheadDistance = SITL_HEXA_MISSION_B.Sum_f;
    if (SITL_HEXA_MISSION_B.j == 0) {
      SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
        SITL_HEXA_MISSION_B.DataTypeConversion1[0];
      SITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
        SITL_HEXA_MISSION_B.DataTypeConversion1[1];
      SITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
        SITL_HEXA_MISSION_B.DataTypeConversion1[2];
      SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.DataTypeConversion1[6];
    } else {
      guard1 = false;
      if (SITL_HEXA_MISSION_B.j == 1) {
        if (SITL_HEXA_MISSION_DW.obj.StartFlag) {
          SITL_HEXA_MISSION_DW.obj.InitialPose[0] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[0];
          SITL_HEXA_MISSION_DW.obj.InitialPose[1] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[1];
          SITL_HEXA_MISSION_DW.obj.InitialPose[2] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[2];
          SITL_HEXA_MISSION_DW.obj.InitialPose[3] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[6];
        }

        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
          SITL_HEXA_MISSION_B.b_waypointsIn_data[0] -
          SITL_HEXA_MISSION_B.DataTypeConversion1[0];
        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
          SITL_HEXA_MISSION_B.b_waypointsIn_data[1] -
          SITL_HEXA_MISSION_B.DataTypeConversion1[1];
        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
          SITL_HEXA_MISSION_B.b_waypointsIn_data[2] -
          SITL_HEXA_MISSION_B.DataTypeConversion1[2];
        if (SITL_HEXA_MISSION_norm(SITL_HEXA_MISSION_B.MatrixConcatenate1_k) <
            1.4901161193847656E-8) {
          SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[0];
          SITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[1];
          SITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[2];
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.DataTypeConversion1[6];
          SITL_HEXA_MISSION_DW.obj.StartFlag = false;
        } else {
          SITL_HEXA_MISSION_DW.obj.StartFlag = false;
          SITL_HEXA_MISSION_DW.obj.NumWaypoints = 2.0;
          SITL_HEXA_MISSION_B.ix = SITL_HEXA_MISSION_B.j + 1;
          for (SITL_HEXA_MISSION_B.i1 = 0; SITL_HEXA_MISSION_B.i1 < 3;
               SITL_HEXA_MISSION_B.i1++) {
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[(SITL_HEXA_MISSION_B.j + 1) *
              SITL_HEXA_MISSION_B.i1] =
              SITL_HEXA_MISSION_DW.obj.InitialPose[SITL_HEXA_MISSION_B.i1];
            for (SITL_HEXA_MISSION_B.iy = 0; SITL_HEXA_MISSION_B.iy <
                 SITL_HEXA_MISSION_B.j; SITL_HEXA_MISSION_B.iy++) {
              SITL_HEXA_MISSION_B.MatrixConcatenate_p[(SITL_HEXA_MISSION_B.iy +
                (SITL_HEXA_MISSION_B.j + 1) * SITL_HEXA_MISSION_B.i1) + 1] =
                SITL_HEXA_MISSION_B.b_waypointsIn_data[SITL_HEXA_MISSION_B.j *
                SITL_HEXA_MISSION_B.i1 + SITL_HEXA_MISSION_B.iy];
            }
          }

          guard1 = true;
        }
      } else {
        SITL_HEXA_MISSION_B.ix = SITL_HEXA_MISSION_B.j;
        SITL_HEXA_MISSION_B.iy = SITL_HEXA_MISSION_B.j * 3;
        if (SITL_HEXA_MISSION_B.iy - 1 >= 0) {
          memcpy(&SITL_HEXA_MISSION_B.MatrixConcatenate_p[0],
                 &SITL_HEXA_MISSION_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(SITL_HEXA_MISSION_B.iy) * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        SITL_HEXA_MISSION_B.OR_g = false;
        if (SITL_HEXA_MISSION_DW.obj.WaypointIndex ==
            SITL_HEXA_MISSION_DW.obj.NumWaypoints) {
          SITL_HEXA_MISSION_B.OR_g = true;
        }

        if (SITL_HEXA_MISSION_B.OR_g) {
          SITL_HEXA_MISSION_DW.obj.LastWaypointFlag = true;
          SITL_HEXA_MISSION_DW.obj.WaypointIndex--;
        }

        SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.MatrixConcatenate_p[
          static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] = SITL_HEXA_MISSION_B.Sum_f;
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1 =
          SITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
          (SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
        SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1;
        SITL_HEXA_MISSION_B.virtualWaypoint[0] =
          SITL_HEXA_MISSION_B.DataTypeConversion1[0] -
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1;
        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
          SITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
          (SITL_HEXA_MISSION_DW.obj.WaypointIndex) + SITL_HEXA_MISSION_B.ix) - 1];
        SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.MatrixConcatenate_p[(
          static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
          SITL_HEXA_MISSION_B.ix) - 1];
        SITL_HEXA_MISSION_B.MatrixConcatenate1[1] = SITL_HEXA_MISSION_B.Gain_i;
        SITL_HEXA_MISSION_B.virtualWaypoint[1] =
          SITL_HEXA_MISSION_B.DataTypeConversion1[1] -
          SITL_HEXA_MISSION_B.Gain_i;
        SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
          SITL_HEXA_MISSION_B.MatrixConcatenate_p[((SITL_HEXA_MISSION_B.ix << 1)
          + static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex)) - 1];
        SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.MatrixConcatenate_p[(
          static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
          (SITL_HEXA_MISSION_B.ix << 1)) - 1];
        SITL_HEXA_MISSION_B.MatrixConcatenate1[2] = SITL_HEXA_MISSION_B.Gain_i;
        SITL_HEXA_MISSION_B.virtualWaypoint[2] =
          SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
          SITL_HEXA_MISSION_B.Gain_i;
        SITL_HEXA_MISSION_B.absx = SITL_HEXA_MISSION_norm
          (SITL_HEXA_MISSION_B.virtualWaypoint);
        guard2 = false;
        if (SITL_HEXA_MISSION_B.absx <= 2.0) {
          guard2 = true;
        } else {
          SITL_HEXA_MISSION_B.lla0[0] = SITL_HEXA_MISSION_B.b_xyzNED_idx_1 -
            SITL_HEXA_MISSION_B.Sum_f;
          SITL_HEXA_MISSION_B.lla0[1] = SITL_HEXA_MISSION_B.MatrixConcatenate_p
            [(static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0)
              + SITL_HEXA_MISSION_B.ix) - 1] -
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex) + SITL_HEXA_MISSION_B.ix) -
            1];
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1 =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            (SITL_HEXA_MISSION_B.ix << 1)) - 1];
          SITL_HEXA_MISSION_B.lla0[2] = SITL_HEXA_MISSION_B.b_xyzNED_idx_1 -
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[((SITL_HEXA_MISSION_B.ix <<
            1) + static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex)) -
            1];
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_norm
            (SITL_HEXA_MISSION_B.lla0);
          SITL_HEXA_MISSION_B.Sum_f = ((SITL_HEXA_MISSION_B.DataTypeConversion1
            [0] - SITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1]) /
            SITL_HEXA_MISSION_B.absx * (SITL_HEXA_MISSION_B.lla0[0] /
            SITL_HEXA_MISSION_B.Sum_f) + SITL_HEXA_MISSION_B.lla0[1] /
            SITL_HEXA_MISSION_B.Sum_f * (SITL_HEXA_MISSION_B.virtualWaypoint[1] /
            SITL_HEXA_MISSION_B.absx)) +
            (SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
             SITL_HEXA_MISSION_B.b_xyzNED_idx_1) / SITL_HEXA_MISSION_B.absx *
            (SITL_HEXA_MISSION_B.lla0[2] / SITL_HEXA_MISSION_B.Sum_f);
          if (rtIsNaN(SITL_HEXA_MISSION_B.Sum_f) || (SITL_HEXA_MISSION_B.Sum_f <
               0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          SITL_HEXA_MISSION_DW.obj.WaypointIndex++;
          SITL_HEXA_MISSION_B.OR_g = false;
          if (SITL_HEXA_MISSION_DW.obj.WaypointIndex ==
              SITL_HEXA_MISSION_DW.obj.NumWaypoints) {
            SITL_HEXA_MISSION_B.OR_g = true;
          }

          if (SITL_HEXA_MISSION_B.OR_g) {
            SITL_HEXA_MISSION_DW.obj.LastWaypointFlag = true;
            SITL_HEXA_MISSION_DW.obj.WaypointIndex--;
          }

          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
          SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex) + SITL_HEXA_MISSION_B.ix) -
            1];
          SITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            SITL_HEXA_MISSION_B.ix) - 1];
          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[((SITL_HEXA_MISSION_B.ix <<
            1) + static_cast<int32_T>(SITL_HEXA_MISSION_DW.obj.WaypointIndex)) -
            1];
          SITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
            SITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (SITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            (SITL_HEXA_MISSION_B.ix << 1)) - 1];
        }

        SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.DataTypeConversion1[0]
          - SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0];
        SITL_HEXA_MISSION_B.virtualWaypoint[0] = SITL_HEXA_MISSION_B.Gain_i;
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1 =
          SITL_HEXA_MISSION_B.MatrixConcatenate1[0] -
          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0];
        SITL_HEXA_MISSION_B.flat = SITL_HEXA_MISSION_B.DataTypeConversion1[1] -
          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1];
        SITL_HEXA_MISSION_B.virtualWaypoint[1] = SITL_HEXA_MISSION_B.flat;
        SITL_HEXA_MISSION_B.absx = SITL_HEXA_MISSION_B.MatrixConcatenate1[1] -
          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1];
        SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
          SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
        SITL_HEXA_MISSION_B.virtualWaypoint[2] = SITL_HEXA_MISSION_B.Sum_f;
        SITL_HEXA_MISSION_B.lla0_tmp = SITL_HEXA_MISSION_B.MatrixConcatenate1[2]
          - SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
        SITL_HEXA_MISSION_B.rtb_Sum_f_tmp = (SITL_HEXA_MISSION_B.absx *
          SITL_HEXA_MISSION_B.absx + SITL_HEXA_MISSION_B.b_xyzNED_idx_1 *
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1) + SITL_HEXA_MISSION_B.lla0_tmp *
          SITL_HEXA_MISSION_B.lla0_tmp;
        SITL_HEXA_MISSION_B.Sum_f = ((SITL_HEXA_MISSION_B.flat *
          SITL_HEXA_MISSION_B.absx + SITL_HEXA_MISSION_B.Gain_i *
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1) + SITL_HEXA_MISSION_B.Sum_f *
          SITL_HEXA_MISSION_B.lla0_tmp) / SITL_HEXA_MISSION_B.rtb_Sum_f_tmp;
        if (SITL_HEXA_MISSION_B.Sum_f < 0.0) {
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_norm
            (SITL_HEXA_MISSION_B.virtualWaypoint);
        } else if (SITL_HEXA_MISSION_B.Sum_f > 1.0) {
          SITL_HEXA_MISSION_B.virtualWaypoint[0] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[0] -
            SITL_HEXA_MISSION_B.MatrixConcatenate1[0];
          SITL_HEXA_MISSION_B.virtualWaypoint[1] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[1] -
            SITL_HEXA_MISSION_B.MatrixConcatenate1[1];
          SITL_HEXA_MISSION_B.virtualWaypoint[2] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
            SITL_HEXA_MISSION_B.MatrixConcatenate1[2];
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_norm
            (SITL_HEXA_MISSION_B.virtualWaypoint);
        } else {
          SITL_HEXA_MISSION_B.virtualWaypoint[0] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[0] -
            (SITL_HEXA_MISSION_B.Sum_f * SITL_HEXA_MISSION_B.b_xyzNED_idx_1 +
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0]);
          SITL_HEXA_MISSION_B.virtualWaypoint[1] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[1] -
            (SITL_HEXA_MISSION_B.Sum_f * SITL_HEXA_MISSION_B.absx +
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1]);
          SITL_HEXA_MISSION_B.virtualWaypoint[2] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
            (SITL_HEXA_MISSION_B.Sum_f * SITL_HEXA_MISSION_B.lla0_tmp +
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2]);
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_norm
            (SITL_HEXA_MISSION_B.virtualWaypoint);
        }

        if (SITL_HEXA_MISSION_DW.obj.LastWaypointFlag) {
          SITL_HEXA_MISSION_B.Sum_f = ((SITL_HEXA_MISSION_B.Gain_i *
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 + SITL_HEXA_MISSION_B.flat *
            SITL_HEXA_MISSION_B.absx) +
            (SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2]) *
            SITL_HEXA_MISSION_B.lla0_tmp) / SITL_HEXA_MISSION_B.rtb_Sum_f_tmp;
          SITL_HEXA_MISSION_B.virtualWaypoint[0] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[0] -
            (SITL_HEXA_MISSION_B.Sum_f * SITL_HEXA_MISSION_B.b_xyzNED_idx_1 +
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0]);
          SITL_HEXA_MISSION_B.virtualWaypoint[1] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[1] -
            (SITL_HEXA_MISSION_B.Sum_f * SITL_HEXA_MISSION_B.absx +
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1]);
          SITL_HEXA_MISSION_B.virtualWaypoint[2] =
            SITL_HEXA_MISSION_B.DataTypeConversion1[2] -
            (SITL_HEXA_MISSION_B.Sum_f * SITL_HEXA_MISSION_B.lla0_tmp +
             SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2]);
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_norm
            (SITL_HEXA_MISSION_B.virtualWaypoint);
        }

        SITL_HEXA_MISSION_B.Gain_i = fabs(SITL_HEXA_MISSION_B.Sum_f);
        if (rtIsInf(SITL_HEXA_MISSION_B.Gain_i) || rtIsNaN
            (SITL_HEXA_MISSION_B.Gain_i)) {
          SITL_HEXA_MISSION_B.flat = (rtNaN);
          SITL_HEXA_MISSION_B.Gain_i = (rtNaN);
        } else if (SITL_HEXA_MISSION_B.Gain_i < 4.4501477170144028E-308) {
          SITL_HEXA_MISSION_B.flat = 4.94065645841247E-324;
          SITL_HEXA_MISSION_B.Gain_i = 4.94065645841247E-324;
        } else {
          frexp(SITL_HEXA_MISSION_B.Gain_i, &SITL_HEXA_MISSION_B.b_exponent);
          SITL_HEXA_MISSION_B.flat = ldexp(1.0, SITL_HEXA_MISSION_B.b_exponent -
            53);
          frexp(SITL_HEXA_MISSION_B.Gain_i, &SITL_HEXA_MISSION_B.b_exponent_p);
          SITL_HEXA_MISSION_B.Gain_i = ldexp(1.0,
            SITL_HEXA_MISSION_B.b_exponent_p - 53);
        }

        SITL_HEXA_MISSION_B.u0 = sqrt(SITL_HEXA_MISSION_B.flat);
        SITL_HEXA_MISSION_B.Gain_i *= 5.0;
        if ((SITL_HEXA_MISSION_B.u0 >= SITL_HEXA_MISSION_B.Gain_i) || rtIsNaN
            (SITL_HEXA_MISSION_B.Gain_i)) {
          SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.u0;
        }

        if (SITL_HEXA_MISSION_DW.obj.LookaheadDistance <=
            SITL_HEXA_MISSION_B.Sum_f + SITL_HEXA_MISSION_B.Gain_i) {
          SITL_HEXA_MISSION_DW.obj.LookaheadDistance =
            SITL_HEXA_MISSION_DW.obj.LookaheadFactor * SITL_HEXA_MISSION_B.Sum_f;
        }

        SITL_HEXA_MISSION_B.lla0[0] = SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0]
          - SITL_HEXA_MISSION_B.DataTypeConversion1[0];
        SITL_HEXA_MISSION_B.lla0[1] = SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1]
          - SITL_HEXA_MISSION_B.DataTypeConversion1[1];
        SITL_HEXA_MISSION_B.lla0[2] = SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2]
          - SITL_HEXA_MISSION_B.DataTypeConversion1[2];
        SITL_HEXA_MISSION_B.Gain_i = ((SITL_HEXA_MISSION_B.b_xyzNED_idx_1 *
          SITL_HEXA_MISSION_B.lla0[0] + SITL_HEXA_MISSION_B.absx *
          SITL_HEXA_MISSION_B.lla0[1]) + SITL_HEXA_MISSION_B.lla0_tmp *
          SITL_HEXA_MISSION_B.lla0[2]) * 2.0;
        SITL_HEXA_MISSION_B.flat = sqrt(SITL_HEXA_MISSION_B.Gain_i *
          SITL_HEXA_MISSION_B.Gain_i - (((SITL_HEXA_MISSION_B.lla0[0] *
          SITL_HEXA_MISSION_B.lla0[0] + SITL_HEXA_MISSION_B.lla0[1] *
          SITL_HEXA_MISSION_B.lla0[1]) + SITL_HEXA_MISSION_B.lla0[2] *
          SITL_HEXA_MISSION_B.lla0[2]) -
          SITL_HEXA_MISSION_DW.obj.LookaheadDistance *
          SITL_HEXA_MISSION_DW.obj.LookaheadDistance) * (4.0 *
          SITL_HEXA_MISSION_B.rtb_Sum_f_tmp));
        SITL_HEXA_MISSION_B.u0 = (-SITL_HEXA_MISSION_B.Gain_i +
          SITL_HEXA_MISSION_B.flat) / 2.0 / SITL_HEXA_MISSION_B.rtb_Sum_f_tmp;
        SITL_HEXA_MISSION_B.Sum_f = (-SITL_HEXA_MISSION_B.Gain_i -
          SITL_HEXA_MISSION_B.flat) / 2.0 / SITL_HEXA_MISSION_B.rtb_Sum_f_tmp;
        if ((SITL_HEXA_MISSION_B.u0 >= SITL_HEXA_MISSION_B.Sum_f) || rtIsNaN
            (SITL_HEXA_MISSION_B.Sum_f)) {
          SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.u0;
        }

        SITL_HEXA_MISSION_B.MatrixConcatenate1[0] = (1.0 -
          SITL_HEXA_MISSION_B.Sum_f) * SITL_HEXA_MISSION_B.MatrixConcatenate1_k
          [0] + SITL_HEXA_MISSION_B.Sum_f *
          SITL_HEXA_MISSION_B.MatrixConcatenate1[0];
        SITL_HEXA_MISSION_B.MatrixConcatenate1[1] = (1.0 -
          SITL_HEXA_MISSION_B.Sum_f) * SITL_HEXA_MISSION_B.MatrixConcatenate1_k
          [1] + SITL_HEXA_MISSION_B.Sum_f *
          SITL_HEXA_MISSION_B.MatrixConcatenate1[1];
        SITL_HEXA_MISSION_B.MatrixConcatenate1[2] = (1.0 -
          SITL_HEXA_MISSION_B.Sum_f) * SITL_HEXA_MISSION_B.MatrixConcatenate1_k
          [2] + SITL_HEXA_MISSION_B.Sum_f *
          SITL_HEXA_MISSION_B.MatrixConcatenate1[2];
        SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_rt_atan2d_snf
          (SITL_HEXA_MISSION_B.MatrixConcatenate1[1] -
           SITL_HEXA_MISSION_B.DataTypeConversion1[1],
           SITL_HEXA_MISSION_B.MatrixConcatenate1[0] -
           SITL_HEXA_MISSION_B.DataTypeConversion1[0]);
        SITL_HEXA_MISSION_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S569>/Switch1' incorporates:
    //   Constant: '<S570>/Constant'
    //   Logic: '<S569>/OR'
    //   Logic: '<S569>/OR1'
    //   MATLABSystem: '<S559>/UAV Waypoint Follower'
    //   Merge: '<S554>/Merge'
    //   RelationalOperator: '<S569>/IsNaN'
    //   RelationalOperator: '<S569>/IsNaN1'
    //   RelationalOperator: '<S570>/Compare'
    //   Reshape: '<S569>/Reshape3'
    //   Switch: '<S569>/Switch'
    //
    if (rtIsNaN(SITL_HEXA_MISSION_B.MatrixConcatenate1[0]) || rtIsNaN
        (SITL_HEXA_MISSION_B.MatrixConcatenate1[1]) || rtIsNaN
        (SITL_HEXA_MISSION_B.MatrixConcatenate1[2]) ||
        (SITL_HEXA_MISSION_B.In1_p.current.type ==
         SITL_HEXA_MISSION_P.CompareToConstant_const)) {
      SITL_HEXA_MISSION_B.Merge[0] = SITL_HEXA_MISSION_B.DataTypeConversion1[0];
      SITL_HEXA_MISSION_B.Merge[1] = SITL_HEXA_MISSION_B.DataTypeConversion1[1];
      SITL_HEXA_MISSION_B.Merge[2] = SITL_HEXA_MISSION_B.DataTypeConversion1[2];
      SITL_HEXA_MISSION_B.Merge[3] = SITL_HEXA_MISSION_B.DataTypeConversion1[6];
    } else {
      if (rtIsNaN(SITL_HEXA_MISSION_B.Sum_f)) {
        // Switch: '<S569>/Switch' incorporates:
        //   Constant: '<S569>/Constant'
        //   Merge: '<S554>/Merge'
        //   Reshape: '<S569>/Reshape2'

        SITL_HEXA_MISSION_B.Merge[3] = SITL_HEXA_MISSION_P.Constant_Value_jd;
      } else {
        // Reshape: '<S569>/Reshape2' incorporates:
        //   MATLABSystem: '<S559>/UAV Waypoint Follower'
        //   Merge: '<S554>/Merge'
        //   Switch: '<S569>/Switch'

        SITL_HEXA_MISSION_B.Merge[3] = SITL_HEXA_MISSION_B.Sum_f;
      }

      // Math: '<S569>/Transpose1' incorporates:
      //   Merge: '<S554>/Merge'

      SITL_HEXA_MISSION_B.Merge[0] = SITL_HEXA_MISSION_B.MatrixConcatenate1[0];
      SITL_HEXA_MISSION_B.Merge[1] = SITL_HEXA_MISSION_B.MatrixConcatenate1[1];
      SITL_HEXA_MISSION_B.Merge[2] = SITL_HEXA_MISSION_B.MatrixConcatenate1[2];
    }

    // End of Switch: '<S569>/Switch1'
    // End of Outputs for SubSystem: '<S554>/Waypoint'
    break;

   default:
    if (SITL_HEXA_MISSION_B.rtAction != SITL_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S554>/IDLE' incorporates:
      //   ActionPort: '<S556>/Action Port'

      // InitializeConditions for If: '<S554>/If' incorporates:
      //   Delay: '<S560>/Delay'

      SITL_HEXA_MISSION_DW.Delay_DSTATE =
        SITL_HEXA_MISSION_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S554>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S554>/IDLE' incorporates:
    //   ActionPort: '<S556>/Action Port'

    // Outputs for Enabled SubSystem: '<S560>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S561>/Enable'

    if (SITL_HEXA_MISSION_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S561>/yaw_In'
      SITL_HEXA_MISSION_B.yaw_In = SITL_HEXA_MISSION_B.DataTypeConversion1[6];
    }

    // End of Outputs for SubSystem: '<S560>/Enabled Subsystem2'

    // Reshape: '<S556>/Reshape1' incorporates:
    //   Delay: '<S560>/Delay'
    //   Merge: '<S554>/Merge'

    SITL_HEXA_MISSION_B.Merge[0] = SITL_HEXA_MISSION_B.DataTypeConversion1[0];
    SITL_HEXA_MISSION_B.Merge[1] = SITL_HEXA_MISSION_B.DataTypeConversion1[1];
    SITL_HEXA_MISSION_B.Merge[2] = SITL_HEXA_MISSION_B.DataTypeConversion1[2];
    SITL_HEXA_MISSION_B.Merge[3] = SITL_HEXA_MISSION_B.yaw_In;

    // Update for Delay: '<S560>/Delay' incorporates:
    //   Constant: '<S560>/Constant'

    SITL_HEXA_MISSION_DW.Delay_DSTATE = SITL_HEXA_MISSION_P.Constant_Value_ic;

    // End of Outputs for SubSystem: '<S554>/IDLE'
    break;
  }

  // End of If: '<S554>/If'

  // Outputs for Enabled SubSystem: '<S555>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S572>/Enable'

  // Start for MATLABSystem: '<S555>/Read Parameter'
  if (SITL_HEXA_MISSION_B.ParamStep_b > 0) {
    // BusAssignment: '<S572>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment'
    //   Constant: '<S582>/Constant'
    //   SignalConversion generated from: '<S578>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0] =
      SITL_HEXA_MISSION_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S578>/Matrix Concatenate1'
    SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
      SITL_HEXA_MISSION_B.In1_p.current.lat;

    // SignalConversion generated from: '<S578>/Matrix Concatenate1'
    SITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
      SITL_HEXA_MISSION_B.In1_p.current.lon;

    // DataTypeConversion: '<S578>/Data Type Conversion'
    SITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
      SITL_HEXA_MISSION_B.In1_p.current.alt;

    // SignalConversion generated from: '<S572>/Matrix Concatenate1'
    SITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] = SITL_HEXA_MISSION_B.In1_f.lat;

    // SignalConversion generated from: '<S572>/Matrix Concatenate1'
    SITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] = SITL_HEXA_MISSION_B.In1_f.lon;

    // DataTypeConversion: '<S572>/Data Type Conversion'
    SITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] = SITL_HEXA_MISSION_B.In1_f.alt;
    SITL_HEXA_MISSION_MATLABSystem(SITL_HEXA_MISSION_B.MatrixConcatenate1,
      SITL_HEXA_MISSION_B.MatrixConcatenate1_k,
      SITL_HEXA_MISSION_B.In1_p.current.valid,
      SITL_HEXA_MISSION_B.In1_p.current.type, &SITL_HEXA_MISSION_B.MATLABSystem);

    // SignalConversion generated from: '<S584>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S578>/Bus Assignment1'
    //   MATLABSystem: '<S578>/MATLAB System'
    //   SignalConversion generated from: '<S578>/MATLAB System'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[0] =
      SITL_HEXA_MISSION_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S584>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S578>/Bus Assignment1'
    //   MATLABSystem: '<S578>/MATLAB System'
    //   SignalConversion generated from: '<S578>/MATLAB System'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[1] =
      SITL_HEXA_MISSION_B.MATLABSystem.MATLABSystem[1];

    // If: '<S584>/If' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S578>/Bus Assignment1'
    //   Constant: '<S586>/Constant'
    //   Constant: '<S586>/Constant1'
    //   Constant: '<S587>/Constant'
    //   Constant: '<S587>/Constant1'

    if (SITL_HEXA_MISSION_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S584>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S587>/Action Port'

      // MATLABSystem: '<S587>/Read Parameter' incorporates:
      //   BusAssignment: '<S572>/Bus Assignment1'
      //   BusAssignment: '<S578>/Bus Assignment1'
      //   SignalConversion generated from: '<S587>/Read Parameter'

      if (SITL_HEXA_MISSION_DW.obj_ga.SampleTime !=
          SITL_HEXA_MISSION_P.ReadParameter_SampleTime_c) {
        SITL_HEXA_MISSION_DW.obj_ga.SampleTime =
          SITL_HEXA_MISSION_P.ReadParameter_SampleTime_c;
      }

      SITL_HEXA_MISSION_B.OR_g = MW_Param_Step
        (SITL_HEXA_MISSION_DW.obj_ga.MW_PARAMHANDLE, MW_SINGLE,
         &SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2]);
      if (SITL_HEXA_MISSION_B.OR_g) {
        SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S587>/Read Parameter'
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        SITL_HEXA_MISSION_P.Constant1_Value_d[0];
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        SITL_HEXA_MISSION_P.Constant1_Value_d[1];
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        SITL_HEXA_MISSION_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S584>/If Action Subsystem2'
    } else if (SITL_HEXA_MISSION_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S584>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S586>/Action Port'

      // MATLABSystem: '<S586>/Read Parameter'
      if (SITL_HEXA_MISSION_DW.obj_b.SampleTime !=
          SITL_HEXA_MISSION_P.ReadParameter_SampleTime_g) {
        SITL_HEXA_MISSION_DW.obj_b.SampleTime =
          SITL_HEXA_MISSION_P.ReadParameter_SampleTime_g;
      }

      SITL_HEXA_MISSION_B.OR_g = MW_Param_Step
        (SITL_HEXA_MISSION_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &SITL_HEXA_MISSION_B.ParamStep);
      if (SITL_HEXA_MISSION_B.OR_g) {
        SITL_HEXA_MISSION_B.ParamStep = 0.0F;
      }

      // Gain: '<S586>/Gain' incorporates:
      //   BusAssignment: '<S572>/Bus Assignment1'
      //   BusAssignment: '<S578>/Bus Assignment1'
      //   MATLABSystem: '<S586>/Read Parameter'
      //
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
        SITL_HEXA_MISSION_P.Gain_Gain_hp * SITL_HEXA_MISSION_B.ParamStep;
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        SITL_HEXA_MISSION_P.Constant1_Value_k4[0];
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        SITL_HEXA_MISSION_P.Constant1_Value_k4[1];
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        SITL_HEXA_MISSION_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S584>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S584>/If Action Subsystem' incorporates:
      //   ActionPort: '<S585>/Action Port'

      // SignalConversion generated from: '<S585>/In1' incorporates:
      //   BusAssignment: '<S572>/Bus Assignment1'
      //   BusAssignment: '<S578>/Bus Assignment1'
      //   MATLABSystem: '<S578>/MATLAB System'
      //   SignalConversion generated from: '<S578>/MATLAB System'

      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        SITL_HEXA_MISSION_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S578>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S572>/Bus Assignment1'
      //   SignalConversion generated from: '<S584>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S585>/In2'
      //
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        SITL_HEXA_MISSION_B.In1_p.current.vx;
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        SITL_HEXA_MISSION_B.In1_p.current.vy;
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
        SITL_HEXA_MISSION_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S584>/If Action Subsystem'
    }

    // End of If: '<S584>/If'

    // BusAssignment: '<S578>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   Constant: '<S578>/Constant5'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].timestamp =
      SITL_HEXA_MISSION_B.In1_p.current.timestamp;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].type =
      SITL_HEXA_MISSION_B.In1_p.current.type;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].yaw =
      SITL_HEXA_MISSION_B.In1_p.current.yaw;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].yaw_speed =
      SITL_HEXA_MISSION_B.In1_p.current.yawspeed;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].point_valid =
      SITL_HEXA_MISSION_P.Constant5_Value;

    // BusAssignment: '<S572>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment'
    //   Constant: '<S582>/Constant'
    //   SignalConversion generated from: '<S579>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1] =
      SITL_HEXA_MISSION_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S579>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S578>/Matrix Concatenate1'

    SITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
      SITL_HEXA_MISSION_B.In1_p.current.lat;

    // SignalConversion generated from: '<S579>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S578>/Matrix Concatenate1'

    SITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
      SITL_HEXA_MISSION_B.In1_p.current.lon;

    // DataTypeConversion: '<S579>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S578>/Data Type Conversion'

    SITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
      SITL_HEXA_MISSION_B.In1_p.current.alt;
    SITL_HEXA_MISSION_MATLABSystem(SITL_HEXA_MISSION_B.MatrixConcatenate1,
      SITL_HEXA_MISSION_B.MatrixConcatenate1_k,
      SITL_HEXA_MISSION_B.In1_p.current.valid,
      SITL_HEXA_MISSION_B.In1_p.current.type,
      &SITL_HEXA_MISSION_B.MATLABSystem_b);

    // SignalConversion generated from: '<S579>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S579>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[0] =
      SITL_HEXA_MISSION_B.In1_p.current.vx;

    // SignalConversion generated from: '<S579>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S579>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[1] =
      SITL_HEXA_MISSION_B.In1_p.current.vy;

    // SignalConversion generated from: '<S579>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S579>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[2] =
      SITL_HEXA_MISSION_B.In1_p.current.vz;

    // BusAssignment: '<S579>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S578>/Bus Assignment1'
    //   Constant: '<S579>/Constant5'
    //   MATLABSystem: '<S579>/MATLAB System'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].timestamp =
      SITL_HEXA_MISSION_B.In1_p.current.timestamp;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[0] =
      SITL_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[0];
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[1] =
      SITL_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[1];
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[2] =
      SITL_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[2];
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].yaw =
      SITL_HEXA_MISSION_B.In1_p.current.yaw;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].yaw_speed =
      SITL_HEXA_MISSION_B.In1_p.current.yawspeed;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].point_valid =
      SITL_HEXA_MISSION_P.Constant5_Value_k;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].type =
      SITL_HEXA_MISSION_B.In1_p.current.type;

    // BusAssignment: '<S572>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment'
    //   Constant: '<S582>/Constant'
    //   SignalConversion generated from: '<S581>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2] =
      SITL_HEXA_MISSION_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S581>/MATLAB System' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   DataTypeConversion: '<S572>/Data Type Conversion'
    //   DataTypeConversion: '<S581>/Data Type Conversion'
    //   SignalConversion generated from: '<S572>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S581>/Matrix Concatenate'
    //
    if (SITL_HEXA_MISSION_B.In1_p.next.valid) {
      SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.In1_p.next.lat -
        SITL_HEXA_MISSION_B.In1_f.lat;
      SITL_HEXA_MISSION_B.Gain_i = SITL_HEXA_MISSION_B.In1_p.next.lon -
        SITL_HEXA_MISSION_B.In1_f.lon;
      SITL_HEXA_MISSION_B.flat = fabs(SITL_HEXA_MISSION_B.Sum_f);
      if (SITL_HEXA_MISSION_B.flat > 180.0) {
        if (rtIsNaN(SITL_HEXA_MISSION_B.Sum_f + 180.0) || rtIsInf
            (SITL_HEXA_MISSION_B.Sum_f + 180.0)) {
          SITL_HEXA_MISSION_B.flat = (rtNaN);
        } else if (SITL_HEXA_MISSION_B.Sum_f + 180.0 == 0.0) {
          SITL_HEXA_MISSION_B.flat = 0.0;
        } else {
          SITL_HEXA_MISSION_B.flat = fmod(SITL_HEXA_MISSION_B.Sum_f + 180.0,
            360.0);
          if (SITL_HEXA_MISSION_B.flat == 0.0) {
            SITL_HEXA_MISSION_B.flat = 0.0;
          } else if (SITL_HEXA_MISSION_B.Sum_f + 180.0 < 0.0) {
            SITL_HEXA_MISSION_B.flat += 360.0;
          }
        }

        SITL_HEXA_MISSION_B.Sum_f = SITL_HEXA_MISSION_B.Sum_f * 0.0 +
          (SITL_HEXA_MISSION_B.flat - 180.0);
        SITL_HEXA_MISSION_B.flat = fabs(SITL_HEXA_MISSION_B.Sum_f);
      }

      if (SITL_HEXA_MISSION_B.flat > 90.0) {
        SITL_HEXA_MISSION_B.flat = fabs(SITL_HEXA_MISSION_B.Sum_f);
        SITL_HEXA_MISSION_B.latp2 = (SITL_HEXA_MISSION_B.flat > 90.0);
        SITL_HEXA_MISSION_B.Gain_i += 180.0;
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = SITL_HEXA_MISSION_B.Sum_f *
          static_cast<real_T>(SITL_HEXA_MISSION_B.latp2);
        if (rtIsNaN(SITL_HEXA_MISSION_B.b_xyzNED_idx_1)) {
          SITL_HEXA_MISSION_B.absx = (rtNaN);
        } else if (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 < 0.0) {
          SITL_HEXA_MISSION_B.absx = -1.0;
        } else {
          SITL_HEXA_MISSION_B.absx = (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 > 0.0);
        }

        SITL_HEXA_MISSION_B.Sum_f = (90.0 - (SITL_HEXA_MISSION_B.flat *
          static_cast<real_T>(SITL_HEXA_MISSION_B.latp2) - 90.0)) *
          SITL_HEXA_MISSION_B.absx * static_cast<real_T>
          (SITL_HEXA_MISSION_B.latp2) + SITL_HEXA_MISSION_B.Sum_f *
          static_cast<real_T>(!SITL_HEXA_MISSION_B.latp2);
      }

      if ((SITL_HEXA_MISSION_B.Gain_i > 180.0) || (SITL_HEXA_MISSION_B.Gain_i <
           -180.0)) {
        SITL_HEXA_MISSION_B.flat = SITL_HEXA_MISSION_rt_remd_snf
          (SITL_HEXA_MISSION_B.Gain_i, 360.0);
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = SITL_HEXA_MISSION_B.flat / 180.0;
        if (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 < 0.0) {
          SITL_HEXA_MISSION_B.absx = ceil(SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
        } else {
          SITL_HEXA_MISSION_B.absx = floor(SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
        }

        SITL_HEXA_MISSION_B.Gain_i = (SITL_HEXA_MISSION_B.flat - 360.0 *
          SITL_HEXA_MISSION_B.absx) + SITL_HEXA_MISSION_B.Gain_i * 0.0;
      }

      SITL_HEXA_MISSION_B.lla0_tmp = SITL_HEXA_MISSION_sind_d
        (SITL_HEXA_MISSION_B.In1_f.lat);
      SITL_HEXA_MISSION_B.flat = 6.378137E+6 / sqrt(1.0 - 0.0066943799901413165 *
        SITL_HEXA_MISSION_B.lla0_tmp * SITL_HEXA_MISSION_B.lla0_tmp);
      if (rtIsInf(SITL_HEXA_MISSION_B.In1_f.lat) || rtIsNaN
          (SITL_HEXA_MISSION_B.In1_f.lat)) {
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = (rtNaN);
      } else {
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = SITL_HEXA_MISSION_rt_remd_snf
          (SITL_HEXA_MISSION_B.In1_f.lat, 360.0);
        SITL_HEXA_MISSION_B.absx = fabs(SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
        if (SITL_HEXA_MISSION_B.absx > 180.0) {
          if (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 > 0.0) {
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 -= 360.0;
          } else {
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 += 360.0;
          }

          SITL_HEXA_MISSION_B.absx = fabs(SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
        }

        if (SITL_HEXA_MISSION_B.absx <= 45.0) {
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = cos(0.017453292519943295 *
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
        } else if (SITL_HEXA_MISSION_B.absx <= 135.0) {
          if (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 > 0.0) {
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = -sin
              ((SITL_HEXA_MISSION_B.b_xyzNED_idx_1 - 90.0) *
               0.017453292519943295);
          } else {
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = sin
              ((SITL_HEXA_MISSION_B.b_xyzNED_idx_1 + 90.0) *
               0.017453292519943295);
          }
        } else {
          if (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 > 0.0) {
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 =
              (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 - 180.0) *
              0.017453292519943295;
          } else {
            SITL_HEXA_MISSION_B.b_xyzNED_idx_1 =
              (SITL_HEXA_MISSION_B.b_xyzNED_idx_1 + 180.0) *
              0.017453292519943295;
          }

          SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = -cos
            (SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
        }
      }

      SITL_HEXA_MISSION_B.Sum_f /= SITL_HEXA_MISSION_rt_atan2d_snf(1.0,
        0.99330562000985867 / (1.0 - 0.0066943799901413165 *
        SITL_HEXA_MISSION_B.lla0_tmp * SITL_HEXA_MISSION_B.lla0_tmp) *
        SITL_HEXA_MISSION_B.flat) * 57.295779513082323;
      SITL_HEXA_MISSION_B.b_xyzNED_idx_1 = SITL_HEXA_MISSION_B.Gain_i /
        (SITL_HEXA_MISSION_rt_atan2d_snf(1.0, SITL_HEXA_MISSION_B.flat *
          SITL_HEXA_MISSION_B.b_xyzNED_idx_1) * 57.295779513082323);
      SITL_HEXA_MISSION_B.Gain_i = -static_cast<real_T>
        (SITL_HEXA_MISSION_B.In1_p.next.alt) + SITL_HEXA_MISSION_B.In1_f.alt;
      SITL_HEXA_MISSION_B.distinctWptsIdx[0] = rtIsNaN(SITL_HEXA_MISSION_B.Sum_f);
      SITL_HEXA_MISSION_B.distinctWptsIdx[1] = rtIsNaN
        (SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
      SITL_HEXA_MISSION_B.distinctWptsIdx[2] = rtIsNaN
        (SITL_HEXA_MISSION_B.Gain_i);
      SITL_HEXA_MISSION_B.OR_g = false;
      SITL_HEXA_MISSION_B.iy = 0;
      exitg1 = false;
      while ((!exitg1) && (SITL_HEXA_MISSION_B.iy < 3)) {
        if (SITL_HEXA_MISSION_B.distinctWptsIdx[SITL_HEXA_MISSION_B.iy]) {
          SITL_HEXA_MISSION_B.OR_g = true;
          exitg1 = true;
        } else {
          SITL_HEXA_MISSION_B.iy++;
        }
      }

      SITL_HEXA_MISSION_B.absx = 0.0 / static_cast<real_T>
        (!SITL_HEXA_MISSION_B.OR_g);
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[0] = static_cast<
        real32_T>(SITL_HEXA_MISSION_B.absx + SITL_HEXA_MISSION_B.Sum_f);
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(SITL_HEXA_MISSION_B.absx +
        SITL_HEXA_MISSION_B.b_xyzNED_idx_1);
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(SITL_HEXA_MISSION_B.absx +
        SITL_HEXA_MISSION_B.Gain_i);
    } else {
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S581>/MATLAB System'

    // SignalConversion generated from: '<S581>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S581>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[0] =
      SITL_HEXA_MISSION_B.In1_p.next.vx;

    // SignalConversion generated from: '<S581>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S581>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[1] =
      SITL_HEXA_MISSION_B.In1_p.next.vy;

    // SignalConversion generated from: '<S581>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   BusAssignment: '<S581>/Bus Assignment1'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[2] =
      SITL_HEXA_MISSION_B.In1_p.next.vz;

    // BusAssignment: '<S581>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'
    //   Constant: '<S581>/Constant5'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].timestamp =
      SITL_HEXA_MISSION_B.In1_p.next.timestamp;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].yaw =
      SITL_HEXA_MISSION_B.In1_p.next.yaw;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].yaw_speed =
      SITL_HEXA_MISSION_B.In1_p.next.yawspeed;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].point_valid =
      SITL_HEXA_MISSION_P.Constant5_Value_h;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].type =
      SITL_HEXA_MISSION_B.In1_p.next.type;

    // SignalConversion generated from: '<S580>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment'
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   Constant: '<S582>/Constant'

    SITL_HEXA_MISSION_B.BusAssignment1_f =
      SITL_HEXA_MISSION_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S580>/Bus Assignment1' incorporates:
    //   Constant: '<S580>/Constant'
    //   Constant: '<S580>/Constant1'
    //   Constant: '<S580>/Constant2'
    //   Constant: '<S580>/Constant3'
    //   Constant: '<S580>/Constant4'
    //   Constant: '<S580>/Constant5'
    //   Constant: '<S580>/Constant6'
    //   Constant: '<S580>/Constant7'

    SITL_HEXA_MISSION_B.BusAssignment1_f.timestamp =
      SITL_HEXA_MISSION_P.Constant7_Value;
    SITL_HEXA_MISSION_B.BusAssignment1_f.yaw =
      SITL_HEXA_MISSION_P.Constant3_Value;
    SITL_HEXA_MISSION_B.BusAssignment1_f.yaw_speed =
      SITL_HEXA_MISSION_P.Constant4_Value;
    SITL_HEXA_MISSION_B.BusAssignment1_f.position[0] =
      SITL_HEXA_MISSION_P.Constant_Value_fh[0];
    SITL_HEXA_MISSION_B.BusAssignment1_f.velocity[0] =
      SITL_HEXA_MISSION_P.Constant1_Value_h[0];
    SITL_HEXA_MISSION_B.BusAssignment1_f.acceleration[0] =
      SITL_HEXA_MISSION_P.Constant2_Value[0];
    SITL_HEXA_MISSION_B.BusAssignment1_f.position[1] =
      SITL_HEXA_MISSION_P.Constant_Value_fh[1];
    SITL_HEXA_MISSION_B.BusAssignment1_f.velocity[1] =
      SITL_HEXA_MISSION_P.Constant1_Value_h[1];
    SITL_HEXA_MISSION_B.BusAssignment1_f.acceleration[1] =
      SITL_HEXA_MISSION_P.Constant2_Value[1];
    SITL_HEXA_MISSION_B.BusAssignment1_f.position[2] =
      SITL_HEXA_MISSION_P.Constant_Value_fh[2];
    SITL_HEXA_MISSION_B.BusAssignment1_f.velocity[2] =
      SITL_HEXA_MISSION_P.Constant1_Value_h[2];
    SITL_HEXA_MISSION_B.BusAssignment1_f.acceleration[2] =
      SITL_HEXA_MISSION_P.Constant2_Value[2];
    SITL_HEXA_MISSION_B.BusAssignment1_f.point_valid =
      SITL_HEXA_MISSION_P.Constant5_Value_l;
    SITL_HEXA_MISSION_B.BusAssignment1_f.type =
      SITL_HEXA_MISSION_P.Constant6_Value;

    // BusAssignment: '<S572>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment'
    //   Constant: '<S572>/Constant'
    //   Constant: '<S582>/Constant'

    SITL_HEXA_MISSION_B.BusAssignment1.timestamp =
      SITL_HEXA_MISSION_B.In1_p.timestamp;
    SITL_HEXA_MISSION_B.BusAssignment1.type =
      SITL_HEXA_MISSION_P.Constant_Value_fm;
    for (SITL_HEXA_MISSION_B.i1 = 0; SITL_HEXA_MISSION_B.i1 < 7;
         SITL_HEXA_MISSION_B.i1++) {
      SITL_HEXA_MISSION_B.BusAssignment1._padding0[SITL_HEXA_MISSION_B.i1] =
        SITL_HEXA_MISSION_P.Constant_Value._padding0[SITL_HEXA_MISSION_B.i1];
    }

    // BusAssignment: '<S572>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   Concatenate: '<S572>/Matrix Concatenate'

    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[3] =
      SITL_HEXA_MISSION_B.BusAssignment1_f;
    SITL_HEXA_MISSION_B.BusAssignment1.waypoints[4] =
      SITL_HEXA_MISSION_B.BusAssignment1_f;

    // MATLABSystem: '<S583>/SinkBlock' incorporates:
    //   BusAssignment: '<S572>/Bus Assignment1'

    uORB_write_step(SITL_HEXA_MISSION_DW.obj_mc.orbMetadataObj,
                    &SITL_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj,
                    &SITL_HEXA_MISSION_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S555>/Send waypoints to OBC'
  SITL_HEXA_MISSION_PX4Timestamp(&SITL_HEXA_MISSION_B.PX4Timestamp_pna);

  // BusAssignment: '<S552>/Bus Assignment' incorporates:
  //   Constant: '<S590>/Constant'

  SITL_HEXA_MISSION_B.BusAssignment_m = SITL_HEXA_MISSION_P.Constant_Value_i;

  // BusAssignment: '<S552>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S552>/Data Type Conversion'
  //   DataTypeConversion: '<S552>/Data Type Conversion1'
  //   DataTypeConversion: '<S552>/Data Type Conversion2'
  //   DataTypeConversion: '<S552>/Data Type Conversion3'
  //   MATLABSystem: '<S552>/PX4 Timestamp'

  SITL_HEXA_MISSION_B.BusAssignment_m.timestamp =
    SITL_HEXA_MISSION_B.PX4Timestamp_pna.PX4Timestamp;
  SITL_HEXA_MISSION_B.BusAssignment_m.x = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[0]);
  SITL_HEXA_MISSION_B.BusAssignment_m.y = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[1]);
  SITL_HEXA_MISSION_B.BusAssignment_m.z = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[2]);
  SITL_HEXA_MISSION_B.BusAssignment_m.yaw = static_cast<real32_T>
    (SITL_HEXA_MISSION_B.Merge[3]);
  SITL_HEXA_MISSION_SinkBlock(&SITL_HEXA_MISSION_B.BusAssignment_m,
    &SITL_HEXA_MISSION_DW.SinkBlock_a);
  SITL_HEXA_MISSION_PX4Timestamp(&SITL_HEXA_MISSION_B.PX4Timestamp_o);
}

// Termination for atomic system: '<Root>/Navigation'
void SITL_HEXA_MISSION_Navigation_Term(void)
{
  // Terminate for MATLABSystem: '<S555>/Read Parameter'
  if (!SITL_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S555>/Read Parameter'

  // Terminate for MATLABSystem: '<S576>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_e.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S576>/SourceBlock'

  // Terminate for MATLABSystem: '<S574>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_kz.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S574>/SourceBlock'

  // Terminate for MATLABSystem: '<S573>/SourceBlock'
  if (!SITL_HEXA_MISSION_DW.obj_gf.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_gf.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate(&SITL_HEXA_MISSION_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S573>/SourceBlock'

  // Terminate for MATLABSystem: '<S555>/LLA2LocalCoordinates'
  if (!SITL_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S555>/LLA2LocalCoordinates'

  // Terminate for Enabled SubSystem: '<S555>/Send waypoints to OBC'
  SITL_HEXA_MISSION_MATLABSystem_Term(&SITL_HEXA_MISSION_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S584>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S587>/Read Parameter'
  if (!SITL_HEXA_MISSION_DW.obj_ga.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_ga.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S587>/Read Parameter'
  // End of Terminate for SubSystem: '<S584>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S584>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S586>/Read Parameter'
  if (!SITL_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S586>/Read Parameter'
  // End of Terminate for SubSystem: '<S584>/If Action Subsystem1'
  SITL_HEXA_MISSION_MATLABSystem_Term(&SITL_HEXA_MISSION_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S581>/MATLAB System'
  if (!SITL_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S581>/MATLAB System'

  // Terminate for MATLABSystem: '<S583>/SinkBlock'
  if (!SITL_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted) {
    SITL_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((SITL_HEXA_MISSION_DW.obj_mc.isInitialized == 1) &&
        SITL_HEXA_MISSION_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&SITL_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S583>/SinkBlock'
  // End of Terminate for SubSystem: '<S555>/Send waypoints to OBC'
  SITL_HEXA_MISSION_PX4Timestamp_Term(&SITL_HEXA_MISSION_DW.PX4Timestamp_pna);
  SITL_HEXA_MISSION_SinkBlock_Term(&SITL_HEXA_MISSION_DW.SinkBlock_a);
  SITL_HEXA_MISSION_PX4Timestamp_Term(&SITL_HEXA_MISSION_DW.PX4Timestamp_o);
}

//
// File trailer for generated code.
//
// [EOF]
//
