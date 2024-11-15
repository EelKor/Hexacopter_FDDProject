//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Copy_of_HITL_HEXA_MISSION.cpp
//
// Code generated for Simulink model 'Copy_of_HITL_HEXA_MISSION'.
//
// Model version                  : 5.1
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Oct 14 16:51:03 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Copy_of_HITL_HEXA_MISSION.h"
#include "rtwtypes.h"
#include "Copy_of_HITL_HEXA_MISSION_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "mc_pos_controller.h"
#include "mc_att_controller.h"
#include "mc_rate_controller.h"
#include "rt_defines.h"
#include <float.h>

// Block signals (default storage)
B_Copy_of_HITL_HEXA_MISSION_T Copy_of_HITL_HEXA_MISSION_B;

// Block states (default storage)
DW_Copy_of_HITL_HEXA_MISSION_T Copy_of_HITL_HEXA_MISSION_DW;

// Real-time model
RT_MODEL_Copy_of_HITL_HEXA_MISSION_T Copy_of_HITL_HEXA_MISSION_M_ =
  RT_MODEL_Copy_of_HITL_HEXA_MISSION_T();
RT_MODEL_Copy_of_HITL_HEXA_MISSION_T *const Copy_of_HITL_HEXA_MISSION_M =
  &Copy_of_HITL_HEXA_MISSION_M_;

// Forward declaration for local functions
static real_T Copy_of_HITL_HEXA_MISSION_sind(real_T x);

// Forward declaration for local functions
static real_T Copy_of_HITL_HEXA_MISSION_rt_remd_snf(real_T u0, real_T u1);
static real_T Copy_of_HITL_HEXA_MISSION_sind_f(real_T x);
static real_T Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf(real_T u0, real_T u1);
static void Copy_of_HITL_HEXA_MISSION_lla2ned(const real_T lla[3], const real_T
  lla0[3], real_T xyzNED[3]);
static real_T Copy_of_HITL_HEXA_MISSION_norm(const real_T x[3]);

// System initialize for atomic system:
void Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Init
  (DW_PX4Timestamp_Copy_of_HITL_HEXA_MISSION_T *localDW)
{
  // Start for MATLABSystem: '<S24>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Copy_of_HITL_HEXA_MISSION_PX4Timestamp
  (B_PX4Timestamp_Copy_of_HITL_HEXA_MISSION_T *localB)
{
  // MATLABSystem: '<S24>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Term
  (DW_PX4Timestamp_Copy_of_HITL_HEXA_MISSION_T *localDW)
{
  // Terminate for MATLABSystem: '<S24>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/PX4 Timestamp'
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

static real_T Copy_of_HITL_HEXA_MISSION_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S603>/MATLAB System'
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

  // End of Start for MATLABSystem: '<S603>/MATLAB System'
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
void Copy_of_HITL_HEXA_MISSION_MATLABSystem_Init
  (DW_MATLABSystem_Copy_of_HITL_HEXA_MISSION_T *localDW)
{
  // Start for MATLABSystem: '<S603>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Copy_of_HITL_HEXA_MISSION_MATLABSystem(const real_T rtu_0[3], const real_T
  rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_Copy_of_HITL_HEXA_MISSION_T *localB)
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

  // MATLABSystem: '<S603>/MATLAB System'
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

    flat = Copy_of_HITL_HEXA_MISSION_sind(rtu_1[0]);
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

    // MATLABSystem: '<S603>/MATLAB System'
    localB->MATLABSystem[0] = static_cast<real32_T>(r + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(r + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(r + flat);
  } else {
    // MATLABSystem: '<S603>/MATLAB System'
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S603>/MATLAB System'
}

// Termination for atomic system:
void Copy_of_HITL_HEXA_MISSION_MATLABSystem_Term
  (DW_MATLABSystem_Copy_of_HITL_HEXA_MISSION_T *localDW)
{
  // Terminate for MATLABSystem: '<S603>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S603>/MATLAB System'
}

static real_T Copy_of_HITL_HEXA_MISSION_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      Copy_of_HITL_HEXA_MISSION_B.q = ceil(u1);
    } else {
      Copy_of_HITL_HEXA_MISSION_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != Copy_of_HITL_HEXA_MISSION_B.q)) {
      Copy_of_HITL_HEXA_MISSION_B.q = fabs(u0 / u1);
      if (!(fabs(Copy_of_HITL_HEXA_MISSION_B.q - floor
                 (Copy_of_HITL_HEXA_MISSION_B.q + 0.5)) > DBL_EPSILON *
            Copy_of_HITL_HEXA_MISSION_B.q)) {
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

static real_T Copy_of_HITL_HEXA_MISSION_sind_f(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S606>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = Copy_of_HITL_HEXA_MISSION_rt_remd_snf(x, 360.0);
    Copy_of_HITL_HEXA_MISSION_B.absx_c = fabs(b_x);
    if (Copy_of_HITL_HEXA_MISSION_B.absx_c > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      Copy_of_HITL_HEXA_MISSION_B.absx_c = fabs(b_x);
    }

    if (Copy_of_HITL_HEXA_MISSION_B.absx_c <= 45.0) {
      b_x *= 0.017453292519943295;
      b_x = sin(b_x);
    } else if (Copy_of_HITL_HEXA_MISSION_B.absx_c <= 135.0) {
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

  // End of Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
  return b_x;
}

static real_T Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      Copy_of_HITL_HEXA_MISSION_B.i = 1;
    } else {
      Copy_of_HITL_HEXA_MISSION_B.i = -1;
    }

    if (u1 > 0.0) {
      Copy_of_HITL_HEXA_MISSION_B.i1_b = 1;
    } else {
      Copy_of_HITL_HEXA_MISSION_B.i1_b = -1;
    }

    y = atan2(static_cast<real_T>(Copy_of_HITL_HEXA_MISSION_B.i),
              static_cast<real_T>(Copy_of_HITL_HEXA_MISSION_B.i1_b));
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

static void Copy_of_HITL_HEXA_MISSION_lla2ned(const real_T lla[3], const real_T
  lla0[3], real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
  Copy_of_HITL_HEXA_MISSION_B.dLat = lla[0] - lla0[0];
  Copy_of_HITL_HEXA_MISSION_B.dLon = lla[1] - lla0[1];
  Copy_of_HITL_HEXA_MISSION_B.flat = fabs(Copy_of_HITL_HEXA_MISSION_B.dLat);
  if (Copy_of_HITL_HEXA_MISSION_B.flat > 180.0) {
    // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
    if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.dLat + 180.0) || rtIsInf
        (Copy_of_HITL_HEXA_MISSION_B.dLat + 180.0)) {
      Copy_of_HITL_HEXA_MISSION_B.r_m = (rtNaN);
    } else if (Copy_of_HITL_HEXA_MISSION_B.dLat + 180.0 == 0.0) {
      Copy_of_HITL_HEXA_MISSION_B.r_m = 0.0;
    } else {
      Copy_of_HITL_HEXA_MISSION_B.r_m = fmod(Copy_of_HITL_HEXA_MISSION_B.dLat +
        180.0, 360.0);
      if (Copy_of_HITL_HEXA_MISSION_B.r_m == 0.0) {
        Copy_of_HITL_HEXA_MISSION_B.r_m = 0.0;
      } else if (Copy_of_HITL_HEXA_MISSION_B.dLat + 180.0 < 0.0) {
        Copy_of_HITL_HEXA_MISSION_B.r_m += 360.0;
      }
    }

    Copy_of_HITL_HEXA_MISSION_B.dLat = Copy_of_HITL_HEXA_MISSION_B.dLat * 0.0 +
      (Copy_of_HITL_HEXA_MISSION_B.r_m - 180.0);
    Copy_of_HITL_HEXA_MISSION_B.flat = fabs(Copy_of_HITL_HEXA_MISSION_B.dLat);
  }

  if (Copy_of_HITL_HEXA_MISSION_B.flat > 90.0) {
    // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
    Copy_of_HITL_HEXA_MISSION_B.flat = fabs(Copy_of_HITL_HEXA_MISSION_B.dLat);
    Copy_of_HITL_HEXA_MISSION_B.latp2 = (Copy_of_HITL_HEXA_MISSION_B.flat > 90.0);

    // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
    Copy_of_HITL_HEXA_MISSION_B.dLon += 180.0;
    Copy_of_HITL_HEXA_MISSION_B.r_m = Copy_of_HITL_HEXA_MISSION_B.dLat *
      static_cast<real_T>(Copy_of_HITL_HEXA_MISSION_B.latp2);
    if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.r_m)) {
      Copy_of_HITL_HEXA_MISSION_B.r_m = (rtNaN);
    } else if (Copy_of_HITL_HEXA_MISSION_B.r_m < 0.0) {
      Copy_of_HITL_HEXA_MISSION_B.r_m = -1.0;
    } else {
      Copy_of_HITL_HEXA_MISSION_B.r_m = (Copy_of_HITL_HEXA_MISSION_B.r_m > 0.0);
    }

    Copy_of_HITL_HEXA_MISSION_B.dLat = (90.0 - (Copy_of_HITL_HEXA_MISSION_B.flat
      * static_cast<real_T>(Copy_of_HITL_HEXA_MISSION_B.latp2) - 90.0)) *
      Copy_of_HITL_HEXA_MISSION_B.r_m * static_cast<real_T>
      (Copy_of_HITL_HEXA_MISSION_B.latp2) + Copy_of_HITL_HEXA_MISSION_B.dLat *
      static_cast<real_T>(!Copy_of_HITL_HEXA_MISSION_B.latp2);
  }

  // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
  if ((Copy_of_HITL_HEXA_MISSION_B.dLon > 180.0) ||
      (Copy_of_HITL_HEXA_MISSION_B.dLon < -180.0)) {
    Copy_of_HITL_HEXA_MISSION_B.flat = Copy_of_HITL_HEXA_MISSION_rt_remd_snf
      (Copy_of_HITL_HEXA_MISSION_B.dLon, 360.0);
    Copy_of_HITL_HEXA_MISSION_B.r_m = Copy_of_HITL_HEXA_MISSION_B.flat / 180.0;
    if (Copy_of_HITL_HEXA_MISSION_B.r_m < 0.0) {
      Copy_of_HITL_HEXA_MISSION_B.r_m = ceil(Copy_of_HITL_HEXA_MISSION_B.r_m);
    } else {
      Copy_of_HITL_HEXA_MISSION_B.r_m = floor(Copy_of_HITL_HEXA_MISSION_B.r_m);
    }

    Copy_of_HITL_HEXA_MISSION_B.dLon = (Copy_of_HITL_HEXA_MISSION_B.flat - 360.0
      * Copy_of_HITL_HEXA_MISSION_B.r_m) + Copy_of_HITL_HEXA_MISSION_B.dLon *
      0.0;
  }

  Copy_of_HITL_HEXA_MISSION_B.flat = Copy_of_HITL_HEXA_MISSION_sind_f(lla0[0]);
  Copy_of_HITL_HEXA_MISSION_B.flat_tmp = 1.0 - 0.0066943799901413165 *
    Copy_of_HITL_HEXA_MISSION_B.flat * Copy_of_HITL_HEXA_MISSION_B.flat;
  Copy_of_HITL_HEXA_MISSION_B.flat = 6.378137E+6 / sqrt
    (Copy_of_HITL_HEXA_MISSION_B.flat_tmp);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    Copy_of_HITL_HEXA_MISSION_B.r_m = (rtNaN);
  } else {
    Copy_of_HITL_HEXA_MISSION_B.r_m = Copy_of_HITL_HEXA_MISSION_rt_remd_snf
      (lla0[0], 360.0);
    Copy_of_HITL_HEXA_MISSION_B.absx = fabs(Copy_of_HITL_HEXA_MISSION_B.r_m);
    if (Copy_of_HITL_HEXA_MISSION_B.absx > 180.0) {
      if (Copy_of_HITL_HEXA_MISSION_B.r_m > 0.0) {
        Copy_of_HITL_HEXA_MISSION_B.r_m -= 360.0;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.r_m += 360.0;
      }

      Copy_of_HITL_HEXA_MISSION_B.absx = fabs(Copy_of_HITL_HEXA_MISSION_B.r_m);
    }

    if (Copy_of_HITL_HEXA_MISSION_B.absx <= 45.0) {
      Copy_of_HITL_HEXA_MISSION_B.r_m = cos(0.017453292519943295 *
        Copy_of_HITL_HEXA_MISSION_B.r_m);
    } else if (Copy_of_HITL_HEXA_MISSION_B.absx <= 135.0) {
      if (Copy_of_HITL_HEXA_MISSION_B.r_m > 0.0) {
        Copy_of_HITL_HEXA_MISSION_B.r_m = -sin((Copy_of_HITL_HEXA_MISSION_B.r_m
          - 90.0) * 0.017453292519943295);
      } else {
        Copy_of_HITL_HEXA_MISSION_B.r_m = sin((Copy_of_HITL_HEXA_MISSION_B.r_m +
          90.0) * 0.017453292519943295);
      }
    } else {
      if (Copy_of_HITL_HEXA_MISSION_B.r_m > 0.0) {
        Copy_of_HITL_HEXA_MISSION_B.r_m = (Copy_of_HITL_HEXA_MISSION_B.r_m -
          180.0) * 0.017453292519943295;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.r_m = (Copy_of_HITL_HEXA_MISSION_B.r_m +
          180.0) * 0.017453292519943295;
      }

      Copy_of_HITL_HEXA_MISSION_B.r_m = -cos(Copy_of_HITL_HEXA_MISSION_B.r_m);
    }
  }

  xyzNED[0] = Copy_of_HITL_HEXA_MISSION_B.dLat /
    (Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf(1.0, 0.99330562000985867 /
      Copy_of_HITL_HEXA_MISSION_B.flat_tmp * Copy_of_HITL_HEXA_MISSION_B.flat) *
     57.295779513082323);
  xyzNED[1] = Copy_of_HITL_HEXA_MISSION_B.dLon /
    (Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf(1.0,
      Copy_of_HITL_HEXA_MISSION_B.flat * Copy_of_HITL_HEXA_MISSION_B.r_m) *
     57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  Copy_of_HITL_HEXA_MISSION_B.b[0] = rtIsNaN(xyzNED[0]);
  Copy_of_HITL_HEXA_MISSION_B.b[1] = rtIsNaN(xyzNED[1]);
  Copy_of_HITL_HEXA_MISSION_B.b[2] = rtIsNaN(xyzNED[2]);
  Copy_of_HITL_HEXA_MISSION_B.latp2 = false;
  Copy_of_HITL_HEXA_MISSION_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (Copy_of_HITL_HEXA_MISSION_B.b_k < 3)) {
    if (Copy_of_HITL_HEXA_MISSION_B.b[Copy_of_HITL_HEXA_MISSION_B.b_k]) {
      Copy_of_HITL_HEXA_MISSION_B.latp2 = true;
      exitg1 = true;
    } else {
      Copy_of_HITL_HEXA_MISSION_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
  Copy_of_HITL_HEXA_MISSION_B.dLat = 0.0 / static_cast<real_T>
    (!Copy_of_HITL_HEXA_MISSION_B.latp2);
  xyzNED[0] += Copy_of_HITL_HEXA_MISSION_B.dLat;
  xyzNED[1] += Copy_of_HITL_HEXA_MISSION_B.dLat;
  xyzNED[2] += Copy_of_HITL_HEXA_MISSION_B.dLat;
}

static real_T Copy_of_HITL_HEXA_MISSION_norm(const real_T x[3])
{
  real_T y;
  Copy_of_HITL_HEXA_MISSION_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S584>/UAV Waypoint Follower'
  Copy_of_HITL_HEXA_MISSION_B.absxk = fabs(x[0]);
  if (Copy_of_HITL_HEXA_MISSION_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    Copy_of_HITL_HEXA_MISSION_B.scale = Copy_of_HITL_HEXA_MISSION_B.absxk;
  } else {
    Copy_of_HITL_HEXA_MISSION_B.t = Copy_of_HITL_HEXA_MISSION_B.absxk /
      3.3121686421112381E-170;
    y = Copy_of_HITL_HEXA_MISSION_B.t * Copy_of_HITL_HEXA_MISSION_B.t;
  }

  // Start for MATLABSystem: '<S584>/UAV Waypoint Follower'
  Copy_of_HITL_HEXA_MISSION_B.absxk = fabs(x[1]);
  if (Copy_of_HITL_HEXA_MISSION_B.absxk > Copy_of_HITL_HEXA_MISSION_B.scale) {
    Copy_of_HITL_HEXA_MISSION_B.t = Copy_of_HITL_HEXA_MISSION_B.scale /
      Copy_of_HITL_HEXA_MISSION_B.absxk;
    y = y * Copy_of_HITL_HEXA_MISSION_B.t * Copy_of_HITL_HEXA_MISSION_B.t + 1.0;
    Copy_of_HITL_HEXA_MISSION_B.scale = Copy_of_HITL_HEXA_MISSION_B.absxk;
  } else {
    Copy_of_HITL_HEXA_MISSION_B.t = Copy_of_HITL_HEXA_MISSION_B.absxk /
      Copy_of_HITL_HEXA_MISSION_B.scale;
    y += Copy_of_HITL_HEXA_MISSION_B.t * Copy_of_HITL_HEXA_MISSION_B.t;
  }

  // Start for MATLABSystem: '<S584>/UAV Waypoint Follower'
  Copy_of_HITL_HEXA_MISSION_B.absxk = fabs(x[2]);
  if (Copy_of_HITL_HEXA_MISSION_B.absxk > Copy_of_HITL_HEXA_MISSION_B.scale) {
    Copy_of_HITL_HEXA_MISSION_B.t = Copy_of_HITL_HEXA_MISSION_B.scale /
      Copy_of_HITL_HEXA_MISSION_B.absxk;
    y = y * Copy_of_HITL_HEXA_MISSION_B.t * Copy_of_HITL_HEXA_MISSION_B.t + 1.0;
    Copy_of_HITL_HEXA_MISSION_B.scale = Copy_of_HITL_HEXA_MISSION_B.absxk;
  } else {
    Copy_of_HITL_HEXA_MISSION_B.t = Copy_of_HITL_HEXA_MISSION_B.absxk /
      Copy_of_HITL_HEXA_MISSION_B.scale;
    y += Copy_of_HITL_HEXA_MISSION_B.t * Copy_of_HITL_HEXA_MISSION_B.t;
  }

  return Copy_of_HITL_HEXA_MISSION_B.scale * sqrt(y);
}

// Model step function
void Copy_of_HITL_HEXA_MISSION_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;

  // MATLABSystem: '<S19>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_da.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_da.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r3, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S19>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  // Start for MATLABSystem: '<S19>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S20>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_k = Copy_of_HITL_HEXA_MISSION_B.r3;
  }

  // End of Outputs for SubSystem: '<S19>/Enabled Subsystem'

  // RelationalOperator: '<S11>/Compare' incorporates:
  //   Constant: '<S11>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  Copy_of_HITL_HEXA_MISSION_B.Compare_k =
    (Copy_of_HITL_HEXA_MISSION_B.In1_k.values[6] >=
     Copy_of_HITL_HEXA_MISSION_P.CompareToConstant_const);

  // MATLABSystem: '<S618>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_d0.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_d0.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r7, false, 1.0);

  // Outputs for Enabled SubSystem: '<S618>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S622>/Enable'

  // Start for MATLABSystem: '<S618>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S622>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_b = Copy_of_HITL_HEXA_MISSION_B.r7;
  }

  // End of Outputs for SubSystem: '<S618>/Enabled Subsystem'

  // MATLABSystem: '<S580>/Read Parameter'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_k.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_d) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_k.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_d;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_k);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_k = 0;
  }

  // MATLABSystem: '<S601>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_e.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_e.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S601>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S602>/Enable'

  // Start for MATLABSystem: '<S601>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S602>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1 = Copy_of_HITL_HEXA_MISSION_B.r;
  }

  // End of Outputs for SubSystem: '<S601>/Enabled Subsystem'

  // MATLABSystem: '<S599>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_kz.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_kz.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S599>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S614>/Enable'

  // Start for MATLABSystem: '<S599>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S614>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_p = Copy_of_HITL_HEXA_MISSION_B.r1;
  }

  // End of Outputs for SubSystem: '<S599>/Enabled Subsystem'

  // MATLABSystem: '<S598>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_gff.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_gff.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r5, false, 1.0);

  // Outputs for Enabled SubSystem: '<S598>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S613>/Enable'

  // Start for MATLABSystem: '<S598>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S613>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_f = Copy_of_HITL_HEXA_MISSION_B.r5;
  }

  // End of Outputs for SubSystem: '<S598>/Enabled Subsystem'

  // MATLABSystem: '<S580>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S580>/Read Parameter'
  //   SignalConversion generated from: '<S613>/In1'
  //
  Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2] = 0.0;
  Copy_of_HITL_HEXA_MISSION_B.lla0[0] = Copy_of_HITL_HEXA_MISSION_B.In1_f.lat;
  Copy_of_HITL_HEXA_MISSION_B.lla0[1] = Copy_of_HITL_HEXA_MISSION_B.In1_f.lon;
  Copy_of_HITL_HEXA_MISSION_B.lla0[2] = Copy_of_HITL_HEXA_MISSION_B.In1_f.alt;
  if (Copy_of_HITL_HEXA_MISSION_B.In1_p.previous.valid &&
      (!Copy_of_HITL_HEXA_MISSION_DW.obj_mr.previousValidReceived)) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.previousValidReceived = true;
  }

  if (Copy_of_HITL_HEXA_MISSION_B.In1_p.next.valid &&
      (!Copy_of_HITL_HEXA_MISSION_DW.obj_mr.nextValidReceived)) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.nextValidReceived = true;
  }

  if (Copy_of_HITL_HEXA_MISSION_B.In1_f.valid_hpos &&
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.valid &&
      (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type != 5)) {
    if (Copy_of_HITL_HEXA_MISSION_B.ParamStep_k != 0) {
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
        Copy_of_HITL_HEXA_MISSION_B.In1.waypoints[0].position[0];
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
        Copy_of_HITL_HEXA_MISSION_B.In1.waypoints[0].position[1];
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
        Copy_of_HITL_HEXA_MISSION_B.In1.waypoints[0].position[2];
    } else {
      Copy_of_HITL_HEXA_MISSION_B.dv[0] =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.current.lat;
      Copy_of_HITL_HEXA_MISSION_B.dv[1] =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.current.lon;
      Copy_of_HITL_HEXA_MISSION_B.dv[2] =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.current.alt;
      Copy_of_HITL_HEXA_MISSION_lla2ned(Copy_of_HITL_HEXA_MISSION_B.dv,
        Copy_of_HITL_HEXA_MISSION_B.lla0,
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1);
    }
  }

  if (Copy_of_HITL_HEXA_MISSION_B.In1_f.valid_hpos &&
      (Copy_of_HITL_HEXA_MISSION_B.In1_p.previous.valid ||
       Copy_of_HITL_HEXA_MISSION_DW.obj_mr.previousValidReceived)) {
    Copy_of_HITL_HEXA_MISSION_B.dv[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.previous.lat;
    Copy_of_HITL_HEXA_MISSION_B.dv[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.previous.lon;
    Copy_of_HITL_HEXA_MISSION_B.dv[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.previous.alt;
    Copy_of_HITL_HEXA_MISSION_lla2ned(Copy_of_HITL_HEXA_MISSION_B.dv,
      Copy_of_HITL_HEXA_MISSION_B.lla0,
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k);
  }

  if (Copy_of_HITL_HEXA_MISSION_B.In1_f.valid_hpos &&
      (Copy_of_HITL_HEXA_MISSION_B.In1_p.next.valid ||
       Copy_of_HITL_HEXA_MISSION_DW.obj_mr.nextValidReceived)) {
    Copy_of_HITL_HEXA_MISSION_B.dv[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.lat;
    Copy_of_HITL_HEXA_MISSION_B.dv[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.lon;
    Copy_of_HITL_HEXA_MISSION_B.dv[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.alt;
    Copy_of_HITL_HEXA_MISSION_lla2ned(Copy_of_HITL_HEXA_MISSION_B.dv,
      Copy_of_HITL_HEXA_MISSION_B.lla0,
      Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint);
  }

  // MATLABSystem: '<S620>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_mg.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_mg.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S620>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S624>/Enable'

  // Start for MATLABSystem: '<S620>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S624>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_c = Copy_of_HITL_HEXA_MISSION_B.r2;
  }

  // End of Outputs for SubSystem: '<S620>/Enabled Subsystem'

  // If: '<S579>/If' incorporates:
  //   Delay: '<S585>/Delay'
  //   Delay: '<S588>/Delay'
  //   Delay: '<S592>/Delay'
  //   MATLABSystem: '<S580>/LLA2LocalCoordinates'
  //
  Copy_of_HITL_HEXA_MISSION_B.rtPrevAction =
    Copy_of_HITL_HEXA_MISSION_DW.If_ActiveSubsystem;
  if (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type == 3) {
    Copy_of_HITL_HEXA_MISSION_B.rtAction = 0;
  } else if (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type == 4) {
    Copy_of_HITL_HEXA_MISSION_B.rtAction = 1;
  } else if (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type == 0) {
    Copy_of_HITL_HEXA_MISSION_B.rtAction = 2;
  } else {
    Copy_of_HITL_HEXA_MISSION_B.rtAction = 3;
  }

  Copy_of_HITL_HEXA_MISSION_DW.If_ActiveSubsystem =
    Copy_of_HITL_HEXA_MISSION_B.rtAction;
  switch (Copy_of_HITL_HEXA_MISSION_B.rtAction) {
   case 0:
    if (Copy_of_HITL_HEXA_MISSION_B.rtAction !=
        Copy_of_HITL_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S579>/Take-off' incorporates:
      //   ActionPort: '<S583>/Action Port'

      // InitializeConditions for If: '<S579>/If' incorporates:
      //   Delay: '<S591>/Delay'
      //   Delay: '<S592>/Delay'

      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_c =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition;
      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_d =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S579>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S579>/Take-off' incorporates:
    //   ActionPort: '<S583>/Action Port'

    // Sum: '<S591>/Sum' incorporates:
    //   Constant: '<S591>/Rate'
    //   Delay: '<S591>/Delay'

    Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_P.Rate_Value +
      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_c;

    // Gain: '<S591>/Gain1'
    Copy_of_HITL_HEXA_MISSION_B.Gain_i =
      Copy_of_HITL_HEXA_MISSION_P.Gain1_Gain_b *
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S592>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S593>/Enable'

    if (Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S593>/yaw_In' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Double'

      Copy_of_HITL_HEXA_MISSION_B.yaw_In_ik =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S592>/Enabled Subsystem2'

    // Reshape: '<S583>/Reshape' incorporates:
    //   Delay: '<S592>/Delay'
    //   Merge: '<S579>/Merge'

    Copy_of_HITL_HEXA_MISSION_B.Merge[0] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0];
    Copy_of_HITL_HEXA_MISSION_B.Merge[1] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1];

    // Gain: '<S591>/Gain' incorporates:
    //   RelationalOperator: '<S591>/Relational Operator'
    //   Switch: '<S591>/Switch'

    if (!(Copy_of_HITL_HEXA_MISSION_B.Gain_i <=
          Copy_of_HITL_HEXA_MISSION_B.Sum_f)) {
      Copy_of_HITL_HEXA_MISSION_B.Gain_i = Copy_of_HITL_HEXA_MISSION_B.Sum_f;
    }

    // Reshape: '<S583>/Reshape' incorporates:
    //   Gain: '<S591>/Gain'
    //   Merge: '<S579>/Merge'
    //   Switch: '<S591>/Switch'

    Copy_of_HITL_HEXA_MISSION_B.Merge[2] =
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_e *
      Copy_of_HITL_HEXA_MISSION_B.Gain_i;
    Copy_of_HITL_HEXA_MISSION_B.Merge[3] = Copy_of_HITL_HEXA_MISSION_B.yaw_In_ik;

    // Update for Delay: '<S591>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_c =
      Copy_of_HITL_HEXA_MISSION_B.Sum_f;

    // Update for Delay: '<S592>/Delay' incorporates:
    //   Constant: '<S592>/Constant'

    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_d =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fo;

    // End of Outputs for SubSystem: '<S579>/Take-off'
    break;

   case 1:
    if (Copy_of_HITL_HEXA_MISSION_B.rtAction !=
        Copy_of_HITL_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S579>/Land' incorporates:
      //   ActionPort: '<S582>/Action Port'

      // InitializeConditions for If: '<S579>/If' incorporates:
      //   Delay: '<S582>/Delay'
      //   Delay: '<S587>/Delay'
      //   Delay: '<S588>/Delay'

      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_n;
      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_n;
      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_n =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_m;
      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_b =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S579>/Land'
    }

    // Outputs for IfAction SubSystem: '<S579>/Land' incorporates:
    //   ActionPort: '<S582>/Action Port'

    // Delay: '<S587>/Delay'
    Copy_of_HITL_HEXA_MISSION_B.Sum_f =
      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_n;

    // Switch: '<S587>/Switch' incorporates:
    //   Delay: '<S587>/Delay'
    //   Gain: '<S587>/Gain'

    if (!(Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_n >
          Copy_of_HITL_HEXA_MISSION_P.Switch_Threshold_j)) {
      Copy_of_HITL_HEXA_MISSION_B.Sum_f =
        Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_ls *
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
    }

    // End of Switch: '<S587>/Switch'

    // Sum: '<S587>/Subtract' incorporates:
    //   Constant: '<S587>/Rate of descent'

    Copy_of_HITL_HEXA_MISSION_B.Gain_i = Copy_of_HITL_HEXA_MISSION_B.Sum_f -
      Copy_of_HITL_HEXA_MISSION_P.Rateofdescent_Value;

    // Gain: '<S587>/Gain2'
    Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_P.Gain2_Gain *
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S588>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S590>/Enable'

    if (Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S590>/yaw_In' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Double'

      Copy_of_HITL_HEXA_MISSION_B.yaw_In_i =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S588>/Enabled Subsystem2'

    // Switch: '<S582>/Switch' incorporates:
    //   Delay: '<S588>/Delay'
    //   Logic: '<S582>/OR'
    //   RelationalOperator: '<S582>/IsNaN'

    if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0]) || rtIsNaN
        (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1])) {
      // Reshape: '<S582>/Reshape' incorporates:
      //   Delay: '<S582>/Delay'
      //   Merge: '<S579>/Merge'

      Copy_of_HITL_HEXA_MISSION_B.Merge[0] =
        Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[0];
      Copy_of_HITL_HEXA_MISSION_B.Merge[1] =
        Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[1];
    } else {
      // Reshape: '<S582>/Reshape' incorporates:
      //   Delay: '<S582>/Delay'
      //   Merge: '<S579>/Merge'

      Copy_of_HITL_HEXA_MISSION_B.Merge[0] =
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0];
      Copy_of_HITL_HEXA_MISSION_B.Merge[1] =
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1];
    }

    // End of Switch: '<S582>/Switch'

    // Reshape: '<S582>/Reshape' incorporates:
    //   Gain: '<S587>/Gain1'
    //   Merge: '<S579>/Merge'
    //   RelationalOperator: '<S587>/GreaterThan'
    //   Switch: '<S587>/Switch1'

    if (!(Copy_of_HITL_HEXA_MISSION_B.Sum_f > Copy_of_HITL_HEXA_MISSION_B.Gain_i))
    {
      Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_B.Gain_i;
    }

    Copy_of_HITL_HEXA_MISSION_B.Merge[2] =
      Copy_of_HITL_HEXA_MISSION_P.Gain1_Gain_a *
      Copy_of_HITL_HEXA_MISSION_B.Sum_f;
    Copy_of_HITL_HEXA_MISSION_B.Merge[3] = Copy_of_HITL_HEXA_MISSION_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S587>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S589>/Enable'

    if (Copy_of_HITL_HEXA_MISSION_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S589>/In'
      Copy_of_HITL_HEXA_MISSION_B.In = Copy_of_HITL_HEXA_MISSION_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S587>/Enabled Subsystem'

    // Update for Delay: '<S582>/Delay' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double'

    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_c.y;

    // Update for Delay: '<S587>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_n = Copy_of_HITL_HEXA_MISSION_B.In;

    // Update for Delay: '<S588>/Delay' incorporates:
    //   Constant: '<S588>/Constant'

    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_b =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S579>/Land'
    break;

   case 2:
    if (Copy_of_HITL_HEXA_MISSION_B.rtAction !=
        Copy_of_HITL_HEXA_MISSION_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S579>/Waypoint' incorporates:
      //   ActionPort: '<S584>/Action Port'

      // SystemReset for If: '<S579>/If' incorporates:
      //   MATLABSystem: '<S584>/UAV Waypoint Follower'
      //
      Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
      for (Copy_of_HITL_HEXA_MISSION_B.i1 = 0; Copy_of_HITL_HEXA_MISSION_B.i1 <
           9; Copy_of_HITL_HEXA_MISSION_B.i1++) {
        Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointsInternal[Copy_of_HITL_HEXA_MISSION_B.i1]
          *= 0.0;
      }

      // End of SystemReset for If: '<S579>/If'
      // End of SystemReset for SubSystem: '<S579>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S579>/Waypoint' incorporates:
    //   ActionPort: '<S584>/Action Port'

    // Concatenate: '<S584>/Matrix Concatenate'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[0] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[1] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[2] =
      Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[3] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[4] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[5] =
      Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[6] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[7] =
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2];
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[8] =
      Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2];

    // MATLABSystem: '<S584>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S584>/Matrix Concatenate'
    //   Constant: '<S584>/Constant'

    Copy_of_HITL_HEXA_MISSION_B.Sum_f =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gw;
    Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistFlag = 0U;
    if (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gw < 0.3) {
      Copy_of_HITL_HEXA_MISSION_B.Sum_f = 0.3;
      Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistFlag = 1U;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[0] = 0.0;
    Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[1] = 0.0;
    Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[2] = 0.0;
    Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[3] = 0.0;
    Copy_of_HITL_HEXA_MISSION_DW.obj.NumWaypoints = 3.0;
    Copy_of_HITL_HEXA_MISSION_B.OR_g = false;
    Copy_of_HITL_HEXA_MISSION_B.Compare = true;
    Copy_of_HITL_HEXA_MISSION_B.iy = 0;
    exitg1 = false;
    while ((!exitg1) && (Copy_of_HITL_HEXA_MISSION_B.iy <= 8)) {
      Copy_of_HITL_HEXA_MISSION_B.i1 = Copy_of_HITL_HEXA_MISSION_B.iy / 3 * 3 +
        Copy_of_HITL_HEXA_MISSION_B.iy % 3;
      if (!(Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointsInternal[Copy_of_HITL_HEXA_MISSION_B.i1]
            ==
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[Copy_of_HITL_HEXA_MISSION_B.i1]))
      {
        Copy_of_HITL_HEXA_MISSION_B.Compare = false;
        exitg1 = true;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.iy++;
      }
    }

    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      Copy_of_HITL_HEXA_MISSION_B.OR_g = true;
    }

    if (!Copy_of_HITL_HEXA_MISSION_B.OR_g) {
      memcpy(&Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointsInternal[0],
             &Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[0], 9U * sizeof
             (real_T));
      Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
    }

    Copy_of_HITL_HEXA_MISSION_B.i1 = 0;
    Copy_of_HITL_HEXA_MISSION_B.iy = 0;
    for (Copy_of_HITL_HEXA_MISSION_B.j = 0; Copy_of_HITL_HEXA_MISSION_B.j < 3;
         Copy_of_HITL_HEXA_MISSION_B.j++) {
      Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[Copy_of_HITL_HEXA_MISSION_B.j]
        = true;
      Copy_of_HITL_HEXA_MISSION_B.Gain_i =
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[Copy_of_HITL_HEXA_MISSION_B.i1
        + 1];
      Copy_of_HITL_HEXA_MISSION_B.x[Copy_of_HITL_HEXA_MISSION_B.iy] =
        (Copy_of_HITL_HEXA_MISSION_B.Gain_i !=
         Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[Copy_of_HITL_HEXA_MISSION_B.i1]);
      Copy_of_HITL_HEXA_MISSION_B.x[Copy_of_HITL_HEXA_MISSION_B.iy + 1] =
        (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[Copy_of_HITL_HEXA_MISSION_B.i1
         + 2] != Copy_of_HITL_HEXA_MISSION_B.Gain_i);
      Copy_of_HITL_HEXA_MISSION_B.i1 += 3;
      Copy_of_HITL_HEXA_MISSION_B.iy += 2;
    }

    Copy_of_HITL_HEXA_MISSION_B.IsNaN_l[0] = false;
    Copy_of_HITL_HEXA_MISSION_B.IsNaN_l[1] = false;
    Copy_of_HITL_HEXA_MISSION_B.i1 = 0;
    Copy_of_HITL_HEXA_MISSION_B.iy = 4;
    for (Copy_of_HITL_HEXA_MISSION_B.j = 0; Copy_of_HITL_HEXA_MISSION_B.j < 2;
         Copy_of_HITL_HEXA_MISSION_B.j++) {
      Copy_of_HITL_HEXA_MISSION_B.i1++;
      Copy_of_HITL_HEXA_MISSION_B.iy++;
      Copy_of_HITL_HEXA_MISSION_B.ix = Copy_of_HITL_HEXA_MISSION_B.i1;
      exitg1 = false;
      while ((!exitg1) && (Copy_of_HITL_HEXA_MISSION_B.ix <=
                           Copy_of_HITL_HEXA_MISSION_B.iy)) {
        if (Copy_of_HITL_HEXA_MISSION_B.x[Copy_of_HITL_HEXA_MISSION_B.ix - 1]) {
          Copy_of_HITL_HEXA_MISSION_B.IsNaN_l[Copy_of_HITL_HEXA_MISSION_B.j] =
            true;
          exitg1 = true;
        } else {
          Copy_of_HITL_HEXA_MISSION_B.ix += 2;
        }
      }
    }

    Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[0] =
      Copy_of_HITL_HEXA_MISSION_B.IsNaN_l[0];
    Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[1] =
      Copy_of_HITL_HEXA_MISSION_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S579>/Waypoint'
    Copy_of_HITL_HEXA_MISSION_B.iy = 0;
    for (Copy_of_HITL_HEXA_MISSION_B.i1 = 0; Copy_of_HITL_HEXA_MISSION_B.i1 < 3;
         Copy_of_HITL_HEXA_MISSION_B.i1++) {
      // Outputs for IfAction SubSystem: '<S579>/Waypoint' incorporates:
      //   ActionPort: '<S584>/Action Port'

      if (Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[Copy_of_HITL_HEXA_MISSION_B.i1])
      {
        Copy_of_HITL_HEXA_MISSION_B.iy++;
      }

      // End of Outputs for SubSystem: '<S579>/Waypoint'
    }

    Copy_of_HITL_HEXA_MISSION_B.j = Copy_of_HITL_HEXA_MISSION_B.iy;
    Copy_of_HITL_HEXA_MISSION_B.iy = 0;
    for (Copy_of_HITL_HEXA_MISSION_B.i1 = 0; Copy_of_HITL_HEXA_MISSION_B.i1 < 3;
         Copy_of_HITL_HEXA_MISSION_B.i1++) {
      // Outputs for IfAction SubSystem: '<S579>/Waypoint' incorporates:
      //   ActionPort: '<S584>/Action Port'

      if (Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[Copy_of_HITL_HEXA_MISSION_B.i1])
      {
        // Start for MATLABSystem: '<S584>/UAV Waypoint Follower'
        Copy_of_HITL_HEXA_MISSION_B.tmp_data[Copy_of_HITL_HEXA_MISSION_B.iy] =
          static_cast<int8_T>(Copy_of_HITL_HEXA_MISSION_B.i1);
        Copy_of_HITL_HEXA_MISSION_B.iy++;
      }

      // End of Outputs for SubSystem: '<S579>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S579>/Waypoint' incorporates:
    //   ActionPort: '<S584>/Action Port'

    // MATLABSystem: '<S584>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S584>/Matrix Concatenate'
    //   DataTypeConversion: '<Root>/Cast To Double'

    for (Copy_of_HITL_HEXA_MISSION_B.i1 = 0; Copy_of_HITL_HEXA_MISSION_B.i1 < 3;
         Copy_of_HITL_HEXA_MISSION_B.i1++) {
      for (Copy_of_HITL_HEXA_MISSION_B.iy = 0; Copy_of_HITL_HEXA_MISSION_B.iy <
           Copy_of_HITL_HEXA_MISSION_B.j; Copy_of_HITL_HEXA_MISSION_B.iy++) {
        Copy_of_HITL_HEXA_MISSION_B.b_waypointsIn_data[Copy_of_HITL_HEXA_MISSION_B.iy
          + Copy_of_HITL_HEXA_MISSION_B.j * Copy_of_HITL_HEXA_MISSION_B.i1] =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[3 *
          Copy_of_HITL_HEXA_MISSION_B.i1 +
          Copy_of_HITL_HEXA_MISSION_B.tmp_data[Copy_of_HITL_HEXA_MISSION_B.iy]];
      }
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistance =
      Copy_of_HITL_HEXA_MISSION_B.Sum_f;
    if (Copy_of_HITL_HEXA_MISSION_B.j == 0) {
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
      Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
      Copy_of_HITL_HEXA_MISSION_B.Sum_f =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
    } else {
      guard1 = false;
      if (Copy_of_HITL_HEXA_MISSION_B.j == 1) {
        if (Copy_of_HITL_HEXA_MISSION_DW.obj.StartFlag) {
          Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[0] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
          Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[1] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
          Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[2] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
          Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[3] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
        }

        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
          Copy_of_HITL_HEXA_MISSION_B.b_waypointsIn_data[0] -
          Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
          Copy_of_HITL_HEXA_MISSION_B.b_waypointsIn_data[1] -
          Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
          Copy_of_HITL_HEXA_MISSION_B.b_waypointsIn_data[2] -
          Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
        if (Copy_of_HITL_HEXA_MISSION_norm
            (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k) <
            1.4901161193847656E-8) {
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
          Copy_of_HITL_HEXA_MISSION_B.Sum_f =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
          Copy_of_HITL_HEXA_MISSION_DW.obj.StartFlag = false;
        } else {
          Copy_of_HITL_HEXA_MISSION_DW.obj.StartFlag = false;
          Copy_of_HITL_HEXA_MISSION_DW.obj.NumWaypoints = 2.0;
          Copy_of_HITL_HEXA_MISSION_B.ix = Copy_of_HITL_HEXA_MISSION_B.j + 1;
          for (Copy_of_HITL_HEXA_MISSION_B.i1 = 0;
               Copy_of_HITL_HEXA_MISSION_B.i1 < 3;
               Copy_of_HITL_HEXA_MISSION_B.i1++) {
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p
              [(Copy_of_HITL_HEXA_MISSION_B.j + 1) *
              Copy_of_HITL_HEXA_MISSION_B.i1] =
              Copy_of_HITL_HEXA_MISSION_DW.obj.InitialPose[Copy_of_HITL_HEXA_MISSION_B.i1];
            for (Copy_of_HITL_HEXA_MISSION_B.iy = 0;
                 Copy_of_HITL_HEXA_MISSION_B.iy < Copy_of_HITL_HEXA_MISSION_B.j;
                 Copy_of_HITL_HEXA_MISSION_B.iy++) {
              Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p
                [(Copy_of_HITL_HEXA_MISSION_B.iy +
                  (Copy_of_HITL_HEXA_MISSION_B.j + 1) *
                  Copy_of_HITL_HEXA_MISSION_B.i1) + 1] =
                Copy_of_HITL_HEXA_MISSION_B.b_waypointsIn_data[Copy_of_HITL_HEXA_MISSION_B.j
                * Copy_of_HITL_HEXA_MISSION_B.i1 +
                Copy_of_HITL_HEXA_MISSION_B.iy];
            }
          }

          guard1 = true;
        }
      } else {
        Copy_of_HITL_HEXA_MISSION_B.ix = Copy_of_HITL_HEXA_MISSION_B.j;
        Copy_of_HITL_HEXA_MISSION_B.iy = Copy_of_HITL_HEXA_MISSION_B.j * 3;
        if (Copy_of_HITL_HEXA_MISSION_B.iy - 1 >= 0) {
          memcpy(&Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[0],
                 &Copy_of_HITL_HEXA_MISSION_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(Copy_of_HITL_HEXA_MISSION_B.iy) * sizeof
                 (real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        Copy_of_HITL_HEXA_MISSION_B.OR_g = false;
        if (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex ==
            Copy_of_HITL_HEXA_MISSION_DW.obj.NumWaypoints) {
          Copy_of_HITL_HEXA_MISSION_B.OR_g = true;
        }

        if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
          Copy_of_HITL_HEXA_MISSION_DW.obj.LastWaypointFlag = true;
          Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex--;
        }

        Copy_of_HITL_HEXA_MISSION_B.Sum_f =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
          (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
          Copy_of_HITL_HEXA_MISSION_B.Sum_f;
        Copy_of_HITL_HEXA_MISSION_B.Gain_i =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
          (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
          Copy_of_HITL_HEXA_MISSION_B.Gain_i;
        Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0] =
          Copy_of_HITL_HEXA_MISSION_B.In1_c.x -
          Copy_of_HITL_HEXA_MISSION_B.Gain_i;
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
          (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex) +
          Copy_of_HITL_HEXA_MISSION_B.ix) - 1];
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
          (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
          Copy_of_HITL_HEXA_MISSION_B.ix) - 1];
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
          Copy_of_HITL_HEXA_MISSION_B.Switch2_a;
        Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] =
          Copy_of_HITL_HEXA_MISSION_B.In1_c.y -
          Copy_of_HITL_HEXA_MISSION_B.Switch2_a;
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p
          [((Copy_of_HITL_HEXA_MISSION_B.ix << 1) + static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex)) - 1];
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
          (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
          (Copy_of_HITL_HEXA_MISSION_B.ix << 1)) - 1];
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
          Copy_of_HITL_HEXA_MISSION_B.Switch2_a;
        Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2] =
          Copy_of_HITL_HEXA_MISSION_B.In1_c.z -
          Copy_of_HITL_HEXA_MISSION_B.Switch2_a;
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_norm
          (Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint);
        guard2 = false;
        if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <= 2.0) {
          guard2 = true;
        } else {
          Copy_of_HITL_HEXA_MISSION_B.lla0[0] =
            Copy_of_HITL_HEXA_MISSION_B.Gain_i -
            Copy_of_HITL_HEXA_MISSION_B.Sum_f;
          Copy_of_HITL_HEXA_MISSION_B.lla0[1] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            Copy_of_HITL_HEXA_MISSION_B.ix) - 1] -
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex) +
            Copy_of_HITL_HEXA_MISSION_B.ix) - 1];
          Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            (Copy_of_HITL_HEXA_MISSION_B.ix << 1)) - 1];
          Copy_of_HITL_HEXA_MISSION_B.lla0[2] =
            Copy_of_HITL_HEXA_MISSION_B.Switch2_a -
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p
            [((Copy_of_HITL_HEXA_MISSION_B.ix << 1) + static_cast<int32_T>
              (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex)) - 1];
          Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_norm
            (Copy_of_HITL_HEXA_MISSION_B.lla0);
          Copy_of_HITL_HEXA_MISSION_B.Sum_f =
            ((Copy_of_HITL_HEXA_MISSION_B.In1_c.x -
              Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p
              [static_cast<int32_T>
              (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1]) /
             Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
             (Copy_of_HITL_HEXA_MISSION_B.lla0[0] /
              Copy_of_HITL_HEXA_MISSION_B.Sum_f) +
             Copy_of_HITL_HEXA_MISSION_B.lla0[1] /
             Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             (Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] /
              Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1)) +
            (Copy_of_HITL_HEXA_MISSION_B.In1_c.z -
             Copy_of_HITL_HEXA_MISSION_B.Switch2_a) /
            Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
            (Copy_of_HITL_HEXA_MISSION_B.lla0[2] /
             Copy_of_HITL_HEXA_MISSION_B.Sum_f);
          if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.Sum_f) ||
              (Copy_of_HITL_HEXA_MISSION_B.Sum_f < 0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex++;
          Copy_of_HITL_HEXA_MISSION_B.OR_g = false;
          if (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex ==
              Copy_of_HITL_HEXA_MISSION_DW.obj.NumWaypoints) {
            Copy_of_HITL_HEXA_MISSION_B.OR_g = true;
          }

          if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
            Copy_of_HITL_HEXA_MISSION_DW.obj.LastWaypointFlag = true;
            Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex--;
          }

          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex) +
            Copy_of_HITL_HEXA_MISSION_B.ix) - 1];
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            Copy_of_HITL_HEXA_MISSION_B.ix) - 1];
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p
            [((Copy_of_HITL_HEXA_MISSION_B.ix << 1) + static_cast<int32_T>
              (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex)) - 1];
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            (Copy_of_HITL_HEXA_MISSION_B.ix << 1)) - 1];
        }

        Copy_of_HITL_HEXA_MISSION_B.Gain_i = Copy_of_HITL_HEXA_MISSION_B.In1_c.x
          - Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0];
        Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0] =
          Copy_of_HITL_HEXA_MISSION_B.Gain_i;
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] -
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0];
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.In1_c.y -
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1];
        Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] =
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1;
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] -
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1];
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g =
          Copy_of_HITL_HEXA_MISSION_B.In1_c.z -
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
        Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2] =
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g;
        Copy_of_HITL_HEXA_MISSION_B.Switch4 =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] -
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2];
        Copy_of_HITL_HEXA_MISSION_B.Gain3 =
          (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
           Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 +
           Copy_of_HITL_HEXA_MISSION_B.Switch2_a *
           Copy_of_HITL_HEXA_MISSION_B.Switch2_a) +
          Copy_of_HITL_HEXA_MISSION_B.Switch4 *
          Copy_of_HITL_HEXA_MISSION_B.Switch4;
        Copy_of_HITL_HEXA_MISSION_B.Gain_i =
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 +
          Copy_of_HITL_HEXA_MISSION_B.Gain_i *
          Copy_of_HITL_HEXA_MISSION_B.Switch2_a;
        Copy_of_HITL_HEXA_MISSION_B.Sum_f = (Copy_of_HITL_HEXA_MISSION_B.Gain2_g
          * Copy_of_HITL_HEXA_MISSION_B.Switch4 +
          Copy_of_HITL_HEXA_MISSION_B.Gain_i) /
          Copy_of_HITL_HEXA_MISSION_B.Gain3;
        if (Copy_of_HITL_HEXA_MISSION_B.Sum_f < 0.0) {
          Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_norm
            (Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint);
        } else if (Copy_of_HITL_HEXA_MISSION_B.Sum_f > 1.0) {
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.x -
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0];
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.y -
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1];
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.z -
            Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2];
          Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_norm
            (Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint);
        } else {
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.x -
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             Copy_of_HITL_HEXA_MISSION_B.Switch2_a +
             Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0]);
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.y -
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 +
             Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1]);
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.z -
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             Copy_of_HITL_HEXA_MISSION_B.Switch4 +
             Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2]);
          Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_norm
            (Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint);
        }

        if (Copy_of_HITL_HEXA_MISSION_DW.obj.LastWaypointFlag) {
          Copy_of_HITL_HEXA_MISSION_B.Sum_f =
            (Copy_of_HITL_HEXA_MISSION_B.Gain2_g *
             Copy_of_HITL_HEXA_MISSION_B.Switch4 +
             Copy_of_HITL_HEXA_MISSION_B.Gain_i) /
            Copy_of_HITL_HEXA_MISSION_B.Gain3;
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[0] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.x -
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             Copy_of_HITL_HEXA_MISSION_B.Switch2_a +
             Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0]);
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[1] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.y -
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 +
             Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1]);
          Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint[2] =
            Copy_of_HITL_HEXA_MISSION_B.In1_c.z -
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f *
             Copy_of_HITL_HEXA_MISSION_B.Switch4 +
             Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2]);
          Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_norm
            (Copy_of_HITL_HEXA_MISSION_B.virtualWaypoint);
        }

        Copy_of_HITL_HEXA_MISSION_B.Gain_i = fabs
          (Copy_of_HITL_HEXA_MISSION_B.Sum_f);
        if (rtIsInf(Copy_of_HITL_HEXA_MISSION_B.Gain_i) || rtIsNaN
            (Copy_of_HITL_HEXA_MISSION_B.Gain_i)) {
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g = (rtNaN);
          Copy_of_HITL_HEXA_MISSION_B.Gain_i = (rtNaN);
        } else if (Copy_of_HITL_HEXA_MISSION_B.Gain_i < 4.4501477170144028E-308)
        {
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g = 4.94065645841247E-324;
          Copy_of_HITL_HEXA_MISSION_B.Gain_i = 4.94065645841247E-324;
        } else {
          frexp(Copy_of_HITL_HEXA_MISSION_B.Gain_i,
                &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g = ldexp(1.0,
            Copy_of_HITL_HEXA_MISSION_B.ParamStep_c - 53);
          frexp(Copy_of_HITL_HEXA_MISSION_B.Gain_i,
                &Copy_of_HITL_HEXA_MISSION_B.b_exponent);
          Copy_of_HITL_HEXA_MISSION_B.Gain_i = ldexp(1.0,
            Copy_of_HITL_HEXA_MISSION_B.b_exponent - 53);
        }

        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = sqrt
          (Copy_of_HITL_HEXA_MISSION_B.Gain2_g);
        Copy_of_HITL_HEXA_MISSION_B.Gain_i *= 5.0;
        if ((Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >=
             Copy_of_HITL_HEXA_MISSION_B.Gain_i) || rtIsNaN
            (Copy_of_HITL_HEXA_MISSION_B.Gain_i)) {
          Copy_of_HITL_HEXA_MISSION_B.Gain_i =
            Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1;
        }

        if (Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistance <=
            Copy_of_HITL_HEXA_MISSION_B.Sum_f +
            Copy_of_HITL_HEXA_MISSION_B.Gain_i) {
          Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistance =
            Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadFactor *
            Copy_of_HITL_HEXA_MISSION_B.Sum_f;
        }

        Copy_of_HITL_HEXA_MISSION_B.lla0[0] =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] -
          Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
        Copy_of_HITL_HEXA_MISSION_B.lla0[1] =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] -
          Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
        Copy_of_HITL_HEXA_MISSION_B.lla0[2] =
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] -
          Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
        Copy_of_HITL_HEXA_MISSION_B.Gain_i =
          ((Copy_of_HITL_HEXA_MISSION_B.Switch2_a *
            Copy_of_HITL_HEXA_MISSION_B.lla0[0] +
            Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
            Copy_of_HITL_HEXA_MISSION_B.lla0[1]) +
           Copy_of_HITL_HEXA_MISSION_B.Switch4 *
           Copy_of_HITL_HEXA_MISSION_B.lla0[2]) * 2.0;
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g = sqrt
          (Copy_of_HITL_HEXA_MISSION_B.Gain_i *
           Copy_of_HITL_HEXA_MISSION_B.Gain_i -
           (((Copy_of_HITL_HEXA_MISSION_B.lla0[0] *
              Copy_of_HITL_HEXA_MISSION_B.lla0[0] +
              Copy_of_HITL_HEXA_MISSION_B.lla0[1] *
              Copy_of_HITL_HEXA_MISSION_B.lla0[1]) +
             Copy_of_HITL_HEXA_MISSION_B.lla0[2] *
             Copy_of_HITL_HEXA_MISSION_B.lla0[2]) -
            Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistance *
            Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadDistance) * (4.0 *
            Copy_of_HITL_HEXA_MISSION_B.Gain3));
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          (-Copy_of_HITL_HEXA_MISSION_B.Gain_i +
           Copy_of_HITL_HEXA_MISSION_B.Gain2_g) / 2.0 /
          Copy_of_HITL_HEXA_MISSION_B.Gain3;
        Copy_of_HITL_HEXA_MISSION_B.Sum_f = (-Copy_of_HITL_HEXA_MISSION_B.Gain_i
          - Copy_of_HITL_HEXA_MISSION_B.Gain2_g) / 2.0 /
          Copy_of_HITL_HEXA_MISSION_B.Gain3;
        if ((Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >=
             Copy_of_HITL_HEXA_MISSION_B.Sum_f) || rtIsNaN
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f)) {
          Copy_of_HITL_HEXA_MISSION_B.Sum_f =
            Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1;
        }

        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] = (1.0 -
          Copy_of_HITL_HEXA_MISSION_B.Sum_f) *
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] +
          Copy_of_HITL_HEXA_MISSION_B.Sum_f *
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0];
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] = (1.0 -
          Copy_of_HITL_HEXA_MISSION_B.Sum_f) *
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] +
          Copy_of_HITL_HEXA_MISSION_B.Sum_f *
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1];
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] = (1.0 -
          Copy_of_HITL_HEXA_MISSION_B.Sum_f) *
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] +
          Copy_of_HITL_HEXA_MISSION_B.Sum_f *
          Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2];
        Copy_of_HITL_HEXA_MISSION_B.Sum_f =
          Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf
          (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] -
           Copy_of_HITL_HEXA_MISSION_B.In1_c.y,
           Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] -
           Copy_of_HITL_HEXA_MISSION_B.In1_c.x);
        Copy_of_HITL_HEXA_MISSION_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S594>/Switch1' incorporates:
    //   Constant: '<S595>/Constant'
    //   DataTypeConversion: '<Root>/Cast To Double'
    //   Logic: '<S594>/OR'
    //   Logic: '<S594>/OR1'
    //   MATLABSystem: '<S584>/UAV Waypoint Follower'
    //   Merge: '<S579>/Merge'
    //   RelationalOperator: '<S594>/IsNaN'
    //   RelationalOperator: '<S594>/IsNaN1'
    //   RelationalOperator: '<S595>/Compare'
    //   Switch: '<S594>/Switch'
    //
    if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0]) || rtIsNaN
        (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1]) || rtIsNaN
        (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2]) ||
        (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type ==
         Copy_of_HITL_HEXA_MISSION_P.CompareToConstant_const_d)) {
      Copy_of_HITL_HEXA_MISSION_B.Merge[0] = Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
      Copy_of_HITL_HEXA_MISSION_B.Merge[1] = Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
      Copy_of_HITL_HEXA_MISSION_B.Merge[2] = Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
      Copy_of_HITL_HEXA_MISSION_B.Merge[3] =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
    } else {
      if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.Sum_f)) {
        // Switch: '<S594>/Switch' incorporates:
        //   Constant: '<S594>/Constant'
        //   Merge: '<S579>/Merge'
        //   Reshape: '<S594>/Reshape2'

        Copy_of_HITL_HEXA_MISSION_B.Merge[3] =
          Copy_of_HITL_HEXA_MISSION_P.Constant_Value_jd;
      } else {
        // Reshape: '<S594>/Reshape2' incorporates:
        //   MATLABSystem: '<S584>/UAV Waypoint Follower'
        //   Merge: '<S579>/Merge'
        //   Switch: '<S594>/Switch'

        Copy_of_HITL_HEXA_MISSION_B.Merge[3] = Copy_of_HITL_HEXA_MISSION_B.Sum_f;
      }

      // Math: '<S594>/Transpose1' incorporates:
      //   Merge: '<S579>/Merge'

      Copy_of_HITL_HEXA_MISSION_B.Merge[0] =
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0];
      Copy_of_HITL_HEXA_MISSION_B.Merge[1] =
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1];
      Copy_of_HITL_HEXA_MISSION_B.Merge[2] =
        Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2];
    }

    // End of Switch: '<S594>/Switch1'
    // End of Outputs for SubSystem: '<S579>/Waypoint'
    break;

   default:
    if (Copy_of_HITL_HEXA_MISSION_B.rtAction !=
        Copy_of_HITL_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S579>/IDLE' incorporates:
      //   ActionPort: '<S581>/Action Port'

      // InitializeConditions for If: '<S579>/If' incorporates:
      //   Delay: '<S585>/Delay'

      Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE =
        Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S579>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S579>/IDLE' incorporates:
    //   ActionPort: '<S581>/Action Port'

    // Outputs for Enabled SubSystem: '<S585>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S586>/Enable'

    if (Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S586>/yaw_In' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Double'

      Copy_of_HITL_HEXA_MISSION_B.yaw_In =
        Copy_of_HITL_HEXA_MISSION_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S585>/Enabled Subsystem2'

    // Reshape: '<S581>/Reshape1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double'
    //   Delay: '<S585>/Delay'
    //   Merge: '<S579>/Merge'

    Copy_of_HITL_HEXA_MISSION_B.Merge[0] = Copy_of_HITL_HEXA_MISSION_B.In1_c.x;
    Copy_of_HITL_HEXA_MISSION_B.Merge[1] = Copy_of_HITL_HEXA_MISSION_B.In1_c.y;
    Copy_of_HITL_HEXA_MISSION_B.Merge[2] = Copy_of_HITL_HEXA_MISSION_B.In1_c.z;
    Copy_of_HITL_HEXA_MISSION_B.Merge[3] = Copy_of_HITL_HEXA_MISSION_B.yaw_In;

    // Update for Delay: '<S585>/Delay' incorporates:
    //   Constant: '<S585>/Constant'

    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_ic;

    // End of Outputs for SubSystem: '<S579>/IDLE'
    break;
  }

  // End of If: '<S579>/If'

  // MATLABSystem: '<S619>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_gv.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_gv.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r4, false, 1.0);

  // Outputs for Enabled SubSystem: '<S619>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S623>/Enable'

  // Start for MATLABSystem: '<S619>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S623>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_m = Copy_of_HITL_HEXA_MISSION_B.r4;
  }

  // End of Outputs for SubSystem: '<S619>/Enabled Subsystem'

  // DataTypeConversion: '<S23>/Data Type Conversion' incorporates:
  //   Switch: '<S26>/Switch'

  Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 =
    Copy_of_HITL_HEXA_MISSION_B.In1_m.q[0];
  Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
    Copy_of_HITL_HEXA_MISSION_B.In1_m.q[1];
  Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_B.In1_m.q[2];
  Copy_of_HITL_HEXA_MISSION_B.Gain_i = Copy_of_HITL_HEXA_MISSION_B.In1_m.q[3];

  // Switch: '<S26>/Switch' incorporates:
  //   Constant: '<S26>/Constant'
  //   DataTypeConversion: '<S23>/Data Type Conversion'
  //   Product: '<S35>/Product'
  //   Product: '<S35>/Product1'
  //   Product: '<S35>/Product2'
  //   Product: '<S35>/Product3'
  //   Sum: '<S35>/Sum'

  if (!(((static_cast<real_T>(Copy_of_HITL_HEXA_MISSION_B.In1_m.q[0]) *
          Copy_of_HITL_HEXA_MISSION_B.In1_m.q[0] + static_cast<real_T>
          (Copy_of_HITL_HEXA_MISSION_B.In1_m.q[1]) *
          Copy_of_HITL_HEXA_MISSION_B.In1_m.q[1]) + static_cast<real_T>
         (Copy_of_HITL_HEXA_MISSION_B.In1_m.q[2]) *
         Copy_of_HITL_HEXA_MISSION_B.In1_m.q[2]) + static_cast<real_T>
        (Copy_of_HITL_HEXA_MISSION_B.In1_m.q[3]) *
        Copy_of_HITL_HEXA_MISSION_B.In1_m.q[3] >
        Copy_of_HITL_HEXA_MISSION_P.Switch_Threshold_l)) {
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_im[0];
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_im[1];
    Copy_of_HITL_HEXA_MISSION_B.Sum_f =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_im[2];
    Copy_of_HITL_HEXA_MISSION_B.Gain_i =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_im[3];
  }

  // End of Switch: '<S26>/Switch'

  // Sqrt: '<S42>/sqrt' incorporates:
  //   Product: '<S43>/Product'
  //   Product: '<S43>/Product1'
  //   Product: '<S43>/Product2'
  //   Product: '<S43>/Product3'
  //   Sum: '<S43>/Sum'

  Copy_of_HITL_HEXA_MISSION_B.Switch2_a = sqrt
    (((Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
       Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 +
       Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
       Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1) +
      Copy_of_HITL_HEXA_MISSION_B.Sum_f * Copy_of_HITL_HEXA_MISSION_B.Sum_f) +
     Copy_of_HITL_HEXA_MISSION_B.Gain_i * Copy_of_HITL_HEXA_MISSION_B.Gain_i);

  // Product: '<S37>/Product'
  Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 /=
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a;

  // Product: '<S37>/Product1'
  Copy_of_HITL_HEXA_MISSION_B.Switch4 =
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 /
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a;

  // Product: '<S37>/Product2'
  Copy_of_HITL_HEXA_MISSION_B.Sum_f /= Copy_of_HITL_HEXA_MISSION_B.Switch2_a;

  // Product: '<S37>/Product3'
  Copy_of_HITL_HEXA_MISSION_B.Switch2_a = Copy_of_HITL_HEXA_MISSION_B.Gain_i /
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a;

  // Fcn: '<S27>/fcn2' incorporates:
  //   Fcn: '<S27>/fcn5'

  Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0;
  Copy_of_HITL_HEXA_MISSION_B.Gain2_g = Copy_of_HITL_HEXA_MISSION_B.Switch4 *
    Copy_of_HITL_HEXA_MISSION_B.Switch4;
  Copy_of_HITL_HEXA_MISSION_B.Gain3 = Copy_of_HITL_HEXA_MISSION_B.Sum_f *
    Copy_of_HITL_HEXA_MISSION_B.Sum_f;
  Copy_of_HITL_HEXA_MISSION_B.Saturation1 =
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a *
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a;

  // Trigonometry: '<S36>/Trigonometric Function1' incorporates:
  //   Fcn: '<S27>/fcn1'
  //   Fcn: '<S27>/fcn2'

  Copy_of_HITL_HEXA_MISSION_B.VectorConcatenate[0] =
    Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf((Copy_of_HITL_HEXA_MISSION_B.Switch4
    * Copy_of_HITL_HEXA_MISSION_B.Sum_f +
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a) * 2.0,
    ((Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_B.Gain2_g) - Copy_of_HITL_HEXA_MISSION_B.Gain3)
    - Copy_of_HITL_HEXA_MISSION_B.Saturation1);

  // Fcn: '<S27>/fcn3'
  Copy_of_HITL_HEXA_MISSION_B.Gain_i = (Copy_of_HITL_HEXA_MISSION_B.Switch4 *
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a -
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    Copy_of_HITL_HEXA_MISSION_B.Sum_f) * -2.0;

  // If: '<S38>/If' incorporates:
  //   Constant: '<S39>/Constant'
  //   Constant: '<S40>/Constant'
  //   Trigonometry: '<S36>/trigFcn'

  if (Copy_of_HITL_HEXA_MISSION_B.Gain_i > 1.0) {
    Copy_of_HITL_HEXA_MISSION_B.Gain_i =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_be;
  } else if (Copy_of_HITL_HEXA_MISSION_B.Gain_i < -1.0) {
    Copy_of_HITL_HEXA_MISSION_B.Gain_i =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_m;
  }

  if (Copy_of_HITL_HEXA_MISSION_B.Gain_i > 1.0) {
    Copy_of_HITL_HEXA_MISSION_B.Gain_i = 1.0;
  } else if (Copy_of_HITL_HEXA_MISSION_B.Gain_i < -1.0) {
    Copy_of_HITL_HEXA_MISSION_B.Gain_i = -1.0;
  }

  // End of If: '<S38>/If'

  // Trigonometry: '<S36>/trigFcn'
  Copy_of_HITL_HEXA_MISSION_B.VectorConcatenate[1] = asin
    (Copy_of_HITL_HEXA_MISSION_B.Gain_i);

  // Trigonometry: '<S36>/Trigonometric Function3' incorporates:
  //   Fcn: '<S27>/fcn4'
  //   Fcn: '<S27>/fcn5'

  Copy_of_HITL_HEXA_MISSION_B.VectorConcatenate[2] =
    Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf((Copy_of_HITL_HEXA_MISSION_B.Sum_f *
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a +
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    Copy_of_HITL_HEXA_MISSION_B.Switch4) * 2.0,
    ((Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 -
      Copy_of_HITL_HEXA_MISSION_B.Gain2_g) - Copy_of_HITL_HEXA_MISSION_B.Gain3)
    + Copy_of_HITL_HEXA_MISSION_B.Saturation1);

  // Gain: '<S23>/Gain'
  Copy_of_HITL_HEXA_MISSION_B.desiredZ =
    Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_cc *
    Copy_of_HITL_HEXA_MISSION_B.Merge[2];

  // Outputs for Enabled SubSystem: '<S23>/mc_pos_controller'
  Copy_of_HITL_HEXA_MISSION_mc_pos_controller();

  // End of Outputs for SubSystem: '<S23>/mc_pos_controller'

  // Outputs for Enabled SubSystem: '<S23>/mc_att_controller'
  Copy_of_HITL_HEXA_MISSION_mc_att_controller();

  // End of Outputs for SubSystem: '<S23>/mc_att_controller'

  // MATLABSystem: '<S617>/SourceBlock'
  Copy_of_HITL_HEXA_MISSION_B.OR_g = uORB_read_step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_po.orbMetadataObj,
     &Copy_of_HITL_HEXA_MISSION_DW.obj_po.eventStructObj,
     &Copy_of_HITL_HEXA_MISSION_B.r6, false, 1.0);

  // Outputs for Enabled SubSystem: '<S617>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S621>/Enable'

  // Start for MATLABSystem: '<S617>/SourceBlock'
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S621>/In1'
    Copy_of_HITL_HEXA_MISSION_B.In1_l = Copy_of_HITL_HEXA_MISSION_B.r6;
  }

  // End of Outputs for SubSystem: '<S617>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S23>/mc_rate_controller'
  Copy_of_HITL_HEXA_MISSION_mc_rate_controller();

  // End of Outputs for SubSystem: '<S23>/mc_rate_controller'

  // Gain: '<S5>/Gain'
  Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_j *
    Copy_of_HITL_HEXA_MISSION_B.Saturation_b;

  // Gain: '<S5>/Gain1'
  Copy_of_HITL_HEXA_MISSION_B.Gain_i = Copy_of_HITL_HEXA_MISSION_P.Gain1_Gain_j *
    Copy_of_HITL_HEXA_MISSION_B.Saturation_c;

  // Gain: '<S5>/Gain2'
  Copy_of_HITL_HEXA_MISSION_B.Gain2_g = Copy_of_HITL_HEXA_MISSION_P.Gain2_Gain_f
    * Copy_of_HITL_HEXA_MISSION_B.Saturation;

  // Gain: '<S5>/Gain3'
  Copy_of_HITL_HEXA_MISSION_B.Gain3 = Copy_of_HITL_HEXA_MISSION_P.Gain3_Gain *
    Copy_of_HITL_HEXA_MISSION_B.Saturation_d;

  // MATLABSystem: '<S7>/Read Parameter13'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_ka.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter13_SampleTime) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter13_SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_ka.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_c = 0;
  }

  // RelationalOperator: '<S18>/Compare' incorporates:
  //   Constant: '<S18>/Constant'

  Copy_of_HITL_HEXA_MISSION_B.Compare =
    (Copy_of_HITL_HEXA_MISSION_B.In1_k.values[7] >=
     Copy_of_HITL_HEXA_MISSION_P.CompareToConstant_const_k);

  // Switch: '<S6>/Switch' incorporates:
  //   Constant: '<S12>/Constant'
  //   Constant: '<S12>/IDLE PWM'
  //   Constant: '<S6>/Constant'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S12>/Product'
  //   Saturate: '<S12>/Saturation1'
  //   Sum: '<S12>/Add'
  //   Sum: '<S12>/Sum'
  //   Switch: '<S7>/Switch'

  if (Copy_of_HITL_HEXA_MISSION_B.Compare_k) {
    Copy_of_HITL_HEXA_MISSION_B.Saturation1 =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_o;
  } else {
    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch' incorporates:
      //   Constant: '<S7>/Fault'
      //   DataTypeConversion: '<S7>/Data Type Conversion3'
      //   MATLABSystem: '<S7>/Read Parameter13'
      //   Switch: '<S7>/Switch'
      //
      if (Copy_of_HITL_HEXA_MISSION_P.ManualSwitch_CurrentSetting == 1) {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_P.Fault_Value;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.ParamStep_c;
      }

      // End of ManualSwitch: '<S7>/Manual Switch'
    } else {
      // Switch: '<S7>/Switch' incorporates:
      //   Constant: '<S7>/Constant'

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Constant_Value_d3;
    }

    // Gain: '<S12>/Gain' incorporates:
    //   Switch: '<S7>/Switch'

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *=
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_c;

    // Saturate: '<S12>/Saturation1'
    if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_g) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_g;
    } else if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <
               Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_c) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_c;
    }

    Copy_of_HITL_HEXA_MISSION_B.Saturation1 =
      ((((-Copy_of_HITL_HEXA_MISSION_B.Sum_f -
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g) *
         Copy_of_HITL_HEXA_MISSION_B.Gain3 / 3.0 +
         Copy_of_HITL_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
       Copy_of_HITL_HEXA_MISSION_P.IDLEPWM_Value_h) *
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_h;
  }

  // End of Switch: '<S6>/Switch'

  // MATLABSystem: '<S7>/Read Parameter1'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_a.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter1_SampleTime) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_a.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter1_SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_a.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_c = 0;
  }

  // Switch: '<S6>/Switch1' incorporates:
  //   Constant: '<S13>/Constant'
  //   Constant: '<S13>/IDLE PWM'
  //   Constant: '<S6>/Constant1'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S13>/Product'
  //   Saturate: '<S13>/Saturation1'
  //   Sum: '<S13>/Add'
  //   Sum: '<S13>/Sum'
  //   Switch: '<S7>/Switch1'

  if (Copy_of_HITL_HEXA_MISSION_B.Compare_k) {
    Copy_of_HITL_HEXA_MISSION_B.Switch1_d =
      Copy_of_HITL_HEXA_MISSION_P.Constant1_Value;
  } else {
    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch1' incorporates:
      //   Constant: '<S7>/Fault1'
      //   DataTypeConversion: '<S7>/Data Type Conversion2'
      //   MATLABSystem: '<S7>/Read Parameter1'
      //   Switch: '<S7>/Switch1'
      //
      if (Copy_of_HITL_HEXA_MISSION_P.ManualSwitch1_CurrentSetting == 1) {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_P.Fault1_Value;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.ParamStep_c;
      }

      // End of ManualSwitch: '<S7>/Manual Switch1'
    } else {
      // Switch: '<S7>/Switch1' incorporates:
      //   Constant: '<S7>/Constant1'

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_j;
    }

    // Gain: '<S13>/Gain' incorporates:
    //   Switch: '<S7>/Switch1'

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *=
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain;

    // Saturate: '<S13>/Saturation1'
    if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat;
    } else if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <
               Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat;
    }

    Copy_of_HITL_HEXA_MISSION_B.Switch1_d =
      ((((Copy_of_HITL_HEXA_MISSION_B.Sum_f +
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g) *
         Copy_of_HITL_HEXA_MISSION_B.Gain3 / 3.0 +
         Copy_of_HITL_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
       Copy_of_HITL_HEXA_MISSION_P.IDLEPWM_Value) *
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_e1;
  }

  // End of Switch: '<S6>/Switch1'

  // MATLABSystem: '<S7>/Read Parameter2'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_ng.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter2_SampleTime) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter2_SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_ng.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_c = 0;
  }

  // Switch: '<S6>/Switch2' incorporates:
  //   Constant: '<S14>/Constant'
  //   Constant: '<S14>/IDLE PWM'
  //   Constant: '<S6>/Constant2'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S14>/Product'
  //   Saturate: '<S14>/Saturation1'
  //   Sum: '<S14>/Add'
  //   Sum: '<S14>/Sum'
  //   Switch: '<S7>/Switch2'

  if (Copy_of_HITL_HEXA_MISSION_B.Compare_k) {
    Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
      Copy_of_HITL_HEXA_MISSION_P.Constant2_Value;
  } else {
    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch2' incorporates:
      //   Constant: '<S7>/Fault2'
      //   DataTypeConversion: '<S7>/Data Type Conversion'
      //   MATLABSystem: '<S7>/Read Parameter2'
      //   Switch: '<S7>/Switch2'
      //
      if (Copy_of_HITL_HEXA_MISSION_P.ManualSwitch2_CurrentSetting == 1) {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_P.Fault2_Value;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.ParamStep_c;
      }

      // End of ManualSwitch: '<S7>/Manual Switch2'
    } else {
      // Switch: '<S7>/Switch2' incorporates:
      //   Constant: '<S7>/Constant2'

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_o;
    }

    // Gain: '<S14>/Gain' incorporates:
    //   Switch: '<S7>/Switch2'

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *=
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_d;

    // Saturate: '<S14>/Saturation1'
    if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_e) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_e;
    } else if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <
               Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_m) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_m;
    }

    Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
      (((((Copy_of_HITL_HEXA_MISSION_B.Sum_f / 2.0 +
           Copy_of_HITL_HEXA_MISSION_B.Gain_i) -
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g) *
         Copy_of_HITL_HEXA_MISSION_B.Gain3 / 3.0 +
         Copy_of_HITL_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
       Copy_of_HITL_HEXA_MISSION_P.IDLEPWM_Value_j) *
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_f;
  }

  // End of Switch: '<S6>/Switch2'

  // MATLABSystem: '<S7>/Read Parameter3'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_n0.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter3_SampleTime) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter3_SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_n0.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_c = 0;
  }

  // Switch: '<S6>/Switch3' incorporates:
  //   Constant: '<S15>/Constant'
  //   Constant: '<S15>/IDLE PWM'
  //   Constant: '<S6>/Constant3'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S15>/Product'
  //   Saturate: '<S15>/Saturation1'
  //   Sum: '<S15>/Add'
  //   Sum: '<S15>/Sum'
  //   Switch: '<S7>/Switch3'

  if (Copy_of_HITL_HEXA_MISSION_B.Compare_k) {
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 =
      Copy_of_HITL_HEXA_MISSION_P.Constant3_Value;
  } else {
    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch3' incorporates:
      //   Constant: '<S7>/Fault3'
      //   DataTypeConversion: '<S7>/Data Type Conversion4'
      //   MATLABSystem: '<S7>/Read Parameter3'
      //   Switch: '<S7>/Switch3'
      //
      if (Copy_of_HITL_HEXA_MISSION_P.ManualSwitch3_CurrentSetting == 1) {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_P.Fault3_Value;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.ParamStep_c;
      }

      // End of ManualSwitch: '<S7>/Manual Switch3'
    } else {
      // Switch: '<S7>/Switch3' incorporates:
      //   Constant: '<S7>/Constant3'

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Constant3_Value_b;
    }

    // Gain: '<S15>/Gain' incorporates:
    //   Switch: '<S7>/Switch3'

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *=
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_a;

    // Saturate: '<S15>/Saturation1'
    if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_l) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_l;
    } else if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <
               Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_g) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_g;
    }

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0 =
      (((((-Copy_of_HITL_HEXA_MISSION_B.Gain_i -
           Copy_of_HITL_HEXA_MISSION_B.Sum_f / 2.0) +
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g) *
         Copy_of_HITL_HEXA_MISSION_B.Gain3 / 3.0 +
         Copy_of_HITL_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
       Copy_of_HITL_HEXA_MISSION_P.IDLEPWM_Value_k) *
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_a;
  }

  // End of Switch: '<S6>/Switch3'

  // MATLABSystem: '<S7>/Read Parameter4'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_cf.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter4_SampleTime) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter4_SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_cf.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_c = 0;
  }

  // Switch: '<S6>/Switch4' incorporates:
  //   Constant: '<S16>/Constant'
  //   Constant: '<S16>/IDLE PWM'
  //   Constant: '<S6>/Constant4'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S16>/Product'
  //   Saturate: '<S16>/Saturation1'
  //   Sum: '<S16>/Add'
  //   Sum: '<S16>/Sum'
  //   Switch: '<S7>/Switch4'

  if (Copy_of_HITL_HEXA_MISSION_B.Compare_k) {
    Copy_of_HITL_HEXA_MISSION_B.Switch4 =
      Copy_of_HITL_HEXA_MISSION_P.Constant4_Value;
  } else {
    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch4' incorporates:
      //   Constant: '<S7>/Fault4'
      //   DataTypeConversion: '<S7>/Data Type Conversion1'
      //   MATLABSystem: '<S7>/Read Parameter4'
      //   Switch: '<S7>/Switch4'
      //
      if (Copy_of_HITL_HEXA_MISSION_P.ManualSwitch4_CurrentSetting == 1) {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_P.Fault4_Value;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.ParamStep_c;
      }

      // End of ManualSwitch: '<S7>/Manual Switch4'
    } else {
      // Switch: '<S7>/Switch4' incorporates:
      //   Constant: '<S7>/Constant4'

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Constant4_Value_e;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Switch: '<S7>/Switch4'

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *=
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_o;

    // Saturate: '<S16>/Saturation1'
    if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_eb) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_eb;
    } else if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <
               Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_b) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_b;
    }

    Copy_of_HITL_HEXA_MISSION_B.Switch4 =
      (((((Copy_of_HITL_HEXA_MISSION_B.Gain_i -
           Copy_of_HITL_HEXA_MISSION_B.Sum_f / 2.0) +
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g) *
         Copy_of_HITL_HEXA_MISSION_B.Gain3 / 3.0 +
         Copy_of_HITL_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
       Copy_of_HITL_HEXA_MISSION_P.IDLEPWM_Value_c) *
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_j3;
  }

  // End of Switch: '<S6>/Switch4'

  // MATLABSystem: '<S7>/Read Parameter5'
  if (Copy_of_HITL_HEXA_MISSION_DW.obj_p1.SampleTime !=
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter5_SampleTime) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter5_SampleTime;
  }

  Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
    (Copy_of_HITL_HEXA_MISSION_DW.obj_p1.MW_PARAMHANDLE, MW_INT32,
     &Copy_of_HITL_HEXA_MISSION_B.ParamStep_c);
  if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
    Copy_of_HITL_HEXA_MISSION_B.ParamStep_c = 0;
  }

  // Switch: '<S6>/Switch5' incorporates:
  //   Constant: '<S17>/Constant'
  //   Constant: '<S17>/IDLE PWM'
  //   Constant: '<S6>/Constant5'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S17>/Product'
  //   Saturate: '<S17>/Saturation1'
  //   Sum: '<S17>/Add'
  //   Sum: '<S17>/Sum'
  //   Switch: '<S7>/Switch5'

  if (Copy_of_HITL_HEXA_MISSION_B.Compare_k) {
    Copy_of_HITL_HEXA_MISSION_B.Sum_f =
      Copy_of_HITL_HEXA_MISSION_P.Constant5_Value;
  } else {
    if (Copy_of_HITL_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch5' incorporates:
      //   Constant: '<S7>/Fault5'
      //   DataTypeConversion: '<S7>/Data Type Conversion5'
      //   MATLABSystem: '<S7>/Read Parameter5'
      //   Switch: '<S7>/Switch5'
      //
      if (Copy_of_HITL_HEXA_MISSION_P.ManualSwitch5_CurrentSetting == 1) {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_P.Fault5_Value;
      } else {
        Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
          Copy_of_HITL_HEXA_MISSION_B.ParamStep_c;
      }

      // End of ManualSwitch: '<S7>/Manual Switch5'
    } else {
      // Switch: '<S7>/Switch5' incorporates:
      //   Constant: '<S7>/Constant5'

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Constant5_Value_f;
    }

    // Gain: '<S17>/Gain' incorporates:
    //   Switch: '<S7>/Switch5'

    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *=
      Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_ap;

    // Saturate: '<S17>/Saturation1'
    if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 >
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_b) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_UpperSat_b;
    } else if (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 <
               Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_o) {
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
        Copy_of_HITL_HEXA_MISSION_P.Saturation1_LowerSat_o;
    }

    Copy_of_HITL_HEXA_MISSION_B.Sum_f = (((((Copy_of_HITL_HEXA_MISSION_B.Sum_f /
      2.0 - Copy_of_HITL_HEXA_MISSION_B.Gain_i) -
      Copy_of_HITL_HEXA_MISSION_B.Gain2_g) * Copy_of_HITL_HEXA_MISSION_B.Gain3 /
      3.0 + Copy_of_HITL_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
      Copy_of_HITL_HEXA_MISSION_P.IDLEPWM_Value_e) *
      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 +
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_cx;
  }

  // End of Switch: '<S6>/Switch5'
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp
    (&Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp_p);

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Constant: '<S33>/Constant'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4 =
    Copy_of_HITL_HEXA_MISSION_P.Constant_Value_j;

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Constant: '<S25>/thrust_sp_bX'
  //   Constant: '<S25>/thrust_sp_bY'
  //   DataTypeConversion: '<S25>/Data Type Conversion'
  //   DataTypeConversion: '<S25>/Data Type Conversion1'
  //   DataTypeConversion: '<S25>/Data Type Conversion2'
  //   DataTypeConversion: '<S25>/Data Type Conversion3'
  //   MATLABSystem: '<S25>/PX4 Timestamp'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.timestamp =
    Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp_p.PX4Timestamp;
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.roll = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch2_o);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.pitch = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch2_l);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.yaw = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch2_n);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.thrust_body[0] =
    static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_P.thrust_sp_bX_Value_m);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.thrust_body[1] =
    static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_P.thrust_sp_bY_Value_m);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4.thrust_body[2] =
    static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_B.Saturation_d);

  // MATLABSystem: '<S34>/SinkBlock' incorporates:
  //   BusAssignment: '<S25>/Bus Assignment'

  uORB_write_step(Copy_of_HITL_HEXA_MISSION_DW.obj_dz.orbMetadataObj,
                  &Copy_of_HITL_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj,
                  &Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4);
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp
    (&Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp);

  // BusAssignment: '<S24>/Bus Assignment' incorporates:
  //   Constant: '<S31>/Constant'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h =
    Copy_of_HITL_HEXA_MISSION_P.Constant_Value_b;

  // BusAssignment: '<S24>/Bus Assignment' incorporates:
  //   Constant: '<S24>/thrust_sp_bX'
  //   Constant: '<S24>/thrust_sp_bY'
  //   DataTypeConversion: '<S24>/Data Type Conversion'
  //   DataTypeConversion: '<S24>/Data Type Conversion1'
  //   DataTypeConversion: '<S24>/Data Type Conversion2'
  //   DataTypeConversion: '<S24>/Data Type Conversion3'
  //   MATLABSystem: '<S24>/PX4 Timestamp'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.timestamp =
    Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp.PX4Timestamp;
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.roll_body = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch2[1]);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.pitch_body = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Gain1);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.yaw_body = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Merge[3]);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.thrust_body[0] =
    static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_P.thrust_sp_bX_Value);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.thrust_body[1] = static_cast<
    real32_T>(Copy_of_HITL_HEXA_MISSION_P.thrust_sp_bY_Value);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h.thrust_body[2] =
    static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_B.Saturation_d);

  // MATLABSystem: '<S32>/SinkBlock' incorporates:
  //   BusAssignment: '<S24>/Bus Assignment'

  uORB_write_step(Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.orbMetadataObj,
                  &Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.orbAdvertiseObj,
                  &Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h);

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S21>/Constant'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment =
    Copy_of_HITL_HEXA_MISSION_P.Constant_Value_c;

  // DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
  //   Constant: '<S10>/Constant17'

  Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = floor
    (Copy_of_HITL_HEXA_MISSION_P.Constant17_Value);
  if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1) || rtIsInf
      (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1)) {
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = 0.0;
  } else {
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = fmod
      (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1, 4.294967296E+9);
  }

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S10>/Constant'
  //   DataTypeConversion: '<S10>/Data Type Conversion'
  //   DataTypeConversion: '<S10>/Data Type Conversion1'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.noutputs =
    Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 < 0.0 ?
    static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>
    (-Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1))) :
    static_cast<uint32_T>(Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[0] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Saturation1);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[1] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch1_d);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[2] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch2_a);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[3] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_0);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[4] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Switch4);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[5] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Sum_f);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[6] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[7] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[8] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[9] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[10] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[11] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[12] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[13] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[14] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment.output[15] = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_P.Constant_Value_gp);

  // MATLABSystem: '<S22>/SinkBlock' incorporates:
  //   BusAssignment: '<S10>/Bus Assignment'

  uORB_write_step(Copy_of_HITL_HEXA_MISSION_DW.obj_hy.orbMetadataObj,
                  &Copy_of_HITL_HEXA_MISSION_DW.obj_hy.orbAdvertiseObj,
                  &Copy_of_HITL_HEXA_MISSION_B.BusAssignment);
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp
    (&Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp_pn);

  // BusAssignment: '<S577>/Bus Assignment' incorporates:
  //   Constant: '<S615>/Constant'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m =
    Copy_of_HITL_HEXA_MISSION_P.Constant_Value_i;

  // BusAssignment: '<S577>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S577>/Data Type Conversion'
  //   DataTypeConversion: '<S577>/Data Type Conversion1'
  //   DataTypeConversion: '<S577>/Data Type Conversion2'
  //   DataTypeConversion: '<S577>/Data Type Conversion3'
  //   MATLABSystem: '<S577>/PX4 Timestamp'

  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m.timestamp =
    Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp_pn.PX4Timestamp;
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m.x = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Merge[0]);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m.y = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Merge[1]);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m.z = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Merge[2]);
  Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m.yaw = static_cast<real32_T>
    (Copy_of_HITL_HEXA_MISSION_B.Merge[3]);

  // MATLABSystem: '<S616>/SinkBlock' incorporates:
  //   BusAssignment: '<S577>/Bus Assignment'

  uORB_write_step(Copy_of_HITL_HEXA_MISSION_DW.obj_o2.orbMetadataObj,
                  &Copy_of_HITL_HEXA_MISSION_DW.obj_o2.orbAdvertiseObj,
                  &Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m);

  // Outputs for Enabled SubSystem: '<S580>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S597>/Enable'

  // Start for MATLABSystem: '<S580>/Read Parameter'
  if (Copy_of_HITL_HEXA_MISSION_B.ParamStep_k > 0) {
    // BusAssignment: '<S597>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment'
    //   Constant: '<S607>/Constant'
    //   SignalConversion generated from: '<S603>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0] =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S603>/Matrix Concatenate1'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.lat;

    // SignalConversion generated from: '<S603>/Matrix Concatenate1'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.lon;

    // DataTypeConversion: '<S603>/Data Type Conversion'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.alt;

    // SignalConversion generated from: '<S597>/Matrix Concatenate1'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_f.lat;

    // SignalConversion generated from: '<S597>/Matrix Concatenate1'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_f.lon;

    // DataTypeConversion: '<S597>/Data Type Conversion'
    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_f.alt;
    Copy_of_HITL_HEXA_MISSION_MATLABSystem
      (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1,
       Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k,
       Copy_of_HITL_HEXA_MISSION_B.In1_p.current.valid,
       Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type,
       &Copy_of_HITL_HEXA_MISSION_B.MATLABSystem);

    // SignalConversion generated from: '<S609>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S603>/Bus Assignment1'
    //   MATLABSystem: '<S603>/MATLAB System'
    //   SignalConversion generated from: '<S603>/MATLAB System'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[0] =
      Copy_of_HITL_HEXA_MISSION_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S609>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S603>/Bus Assignment1'
    //   MATLABSystem: '<S603>/MATLAB System'
    //   SignalConversion generated from: '<S603>/MATLAB System'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[1] =
      Copy_of_HITL_HEXA_MISSION_B.MATLABSystem.MATLABSystem[1];

    // If: '<S609>/If' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S603>/Bus Assignment1'
    //   Constant: '<S611>/Constant'
    //   Constant: '<S611>/Constant1'
    //   Constant: '<S612>/Constant'
    //   Constant: '<S612>/Constant1'

    if (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S609>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S612>/Action Port'

      // MATLABSystem: '<S612>/Read Parameter' incorporates:
      //   BusAssignment: '<S597>/Bus Assignment1'
      //   BusAssignment: '<S603>/Bus Assignment1'
      //   SignalConversion generated from: '<S612>/Read Parameter'

      if (Copy_of_HITL_HEXA_MISSION_DW.obj_g.SampleTime !=
          Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_c) {
        Copy_of_HITL_HEXA_MISSION_DW.obj_g.SampleTime =
          Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_c;
      }

      Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
        (Copy_of_HITL_HEXA_MISSION_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2]);
      if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
        Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
          0.0F;
      }

      // End of MATLABSystem: '<S612>/Read Parameter'
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_d[0];
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_d[1];
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        Copy_of_HITL_HEXA_MISSION_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S609>/If Action Subsystem2'
    } else if (Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S609>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S611>/Action Port'

      // MATLABSystem: '<S611>/Read Parameter'
      if (Copy_of_HITL_HEXA_MISSION_DW.obj_b.SampleTime !=
          Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_g) {
        Copy_of_HITL_HEXA_MISSION_DW.obj_b.SampleTime =
          Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_g;
      }

      Copy_of_HITL_HEXA_MISSION_B.OR_g = MW_Param_Step
        (Copy_of_HITL_HEXA_MISSION_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &Copy_of_HITL_HEXA_MISSION_B.ParamStep);
      if (Copy_of_HITL_HEXA_MISSION_B.OR_g) {
        Copy_of_HITL_HEXA_MISSION_B.ParamStep = 0.0F;
      }

      // Gain: '<S611>/Gain' incorporates:
      //   BusAssignment: '<S597>/Bus Assignment1'
      //   BusAssignment: '<S603>/Bus Assignment1'
      //   MATLABSystem: '<S611>/Read Parameter'
      //
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
        Copy_of_HITL_HEXA_MISSION_P.Gain_Gain_h *
        Copy_of_HITL_HEXA_MISSION_B.ParamStep;
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_k4[0];
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_k4[1];
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        Copy_of_HITL_HEXA_MISSION_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S609>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S609>/If Action Subsystem' incorporates:
      //   ActionPort: '<S610>/Action Port'

      // SignalConversion generated from: '<S610>/In1' incorporates:
      //   BusAssignment: '<S597>/Bus Assignment1'
      //   BusAssignment: '<S603>/Bus Assignment1'
      //   MATLABSystem: '<S603>/MATLAB System'
      //   SignalConversion generated from: '<S603>/MATLAB System'

      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        Copy_of_HITL_HEXA_MISSION_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S603>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S597>/Bus Assignment1'
      //   SignalConversion generated from: '<S609>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S610>/In2'
      //
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.current.vx;
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.current.vy;
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S609>/If Action Subsystem'
    }

    // End of If: '<S609>/If'

    // BusAssignment: '<S603>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   Constant: '<S603>/Constant5'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].timestamp =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.timestamp;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].type =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].yaw =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.yaw;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].yaw_speed =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.yawspeed;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[0].point_valid =
      Copy_of_HITL_HEXA_MISSION_P.Constant5_Value_j;

    // BusAssignment: '<S597>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment'
    //   Constant: '<S607>/Constant'
    //   SignalConversion generated from: '<S604>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1] =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S604>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S603>/Matrix Concatenate1'

    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.lat;

    // SignalConversion generated from: '<S604>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S603>/Matrix Concatenate1'

    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.lon;

    // DataTypeConversion: '<S604>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S603>/Data Type Conversion'

    Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.alt;
    Copy_of_HITL_HEXA_MISSION_MATLABSystem
      (Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1,
       Copy_of_HITL_HEXA_MISSION_B.MatrixConcatenate1_k,
       Copy_of_HITL_HEXA_MISSION_B.In1_p.current.valid,
       Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type,
       &Copy_of_HITL_HEXA_MISSION_B.MATLABSystem_b);

    // SignalConversion generated from: '<S604>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S604>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.vx;

    // SignalConversion generated from: '<S604>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S604>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.vy;

    // SignalConversion generated from: '<S604>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S604>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.vz;

    // BusAssignment: '<S604>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S603>/Bus Assignment1'
    //   Constant: '<S604>/Constant5'
    //   MATLABSystem: '<S604>/MATLAB System'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].timestamp =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.timestamp;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[0] =
      Copy_of_HITL_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[0];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[1] =
      Copy_of_HITL_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[1];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[2] =
      Copy_of_HITL_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[2];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].yaw =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.yaw;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].yaw_speed =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.yawspeed;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].point_valid =
      Copy_of_HITL_HEXA_MISSION_P.Constant5_Value_k;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[1].type =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.current.type;

    // BusAssignment: '<S597>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment'
    //   Constant: '<S607>/Constant'
    //   SignalConversion generated from: '<S606>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2] =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S606>/MATLAB System' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   DataTypeConversion: '<S597>/Data Type Conversion'
    //   DataTypeConversion: '<S606>/Data Type Conversion'
    //   SignalConversion generated from: '<S597>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S606>/Matrix Concatenate'
    //
    if (Copy_of_HITL_HEXA_MISSION_B.In1_p.next.valid) {
      Copy_of_HITL_HEXA_MISSION_B.Sum_f =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.next.lat -
        Copy_of_HITL_HEXA_MISSION_B.In1_f.lat;
      Copy_of_HITL_HEXA_MISSION_B.Gain_i =
        Copy_of_HITL_HEXA_MISSION_B.In1_p.next.lon -
        Copy_of_HITL_HEXA_MISSION_B.In1_f.lon;
      Copy_of_HITL_HEXA_MISSION_B.Gain2_g = fabs
        (Copy_of_HITL_HEXA_MISSION_B.Sum_f);
      if (Copy_of_HITL_HEXA_MISSION_B.Gain2_g > 180.0) {
        if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.Sum_f + 180.0) || rtIsInf
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f + 180.0)) {
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g = (rtNaN);
        } else if (Copy_of_HITL_HEXA_MISSION_B.Sum_f + 180.0 == 0.0) {
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g = 0.0;
        } else {
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g = fmod
            (Copy_of_HITL_HEXA_MISSION_B.Sum_f + 180.0, 360.0);
          if (Copy_of_HITL_HEXA_MISSION_B.Gain2_g == 0.0) {
            Copy_of_HITL_HEXA_MISSION_B.Gain2_g = 0.0;
          } else if (Copy_of_HITL_HEXA_MISSION_B.Sum_f + 180.0 < 0.0) {
            Copy_of_HITL_HEXA_MISSION_B.Gain2_g += 360.0;
          }
        }

        Copy_of_HITL_HEXA_MISSION_B.Sum_f = Copy_of_HITL_HEXA_MISSION_B.Sum_f *
          0.0 + (Copy_of_HITL_HEXA_MISSION_B.Gain2_g - 180.0);
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g = fabs
          (Copy_of_HITL_HEXA_MISSION_B.Sum_f);
      }

      if (Copy_of_HITL_HEXA_MISSION_B.Gain2_g > 90.0) {
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g = fabs
          (Copy_of_HITL_HEXA_MISSION_B.Sum_f);
        Copy_of_HITL_HEXA_MISSION_B.OR_g = (Copy_of_HITL_HEXA_MISSION_B.Gain2_g >
          90.0);
        Copy_of_HITL_HEXA_MISSION_B.Gain_i += 180.0;
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
          Copy_of_HITL_HEXA_MISSION_B.Sum_f * static_cast<real_T>
          (Copy_of_HITL_HEXA_MISSION_B.OR_g);
        if (rtIsNaN(Copy_of_HITL_HEXA_MISSION_B.Switch2_a)) {
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = (rtNaN);
        } else if (Copy_of_HITL_HEXA_MISSION_B.Switch2_a < 0.0) {
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = -1.0;
        } else {
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
            (Copy_of_HITL_HEXA_MISSION_B.Switch2_a > 0.0);
        }

        Copy_of_HITL_HEXA_MISSION_B.Sum_f = (90.0 -
          (Copy_of_HITL_HEXA_MISSION_B.Gain2_g * static_cast<real_T>
           (Copy_of_HITL_HEXA_MISSION_B.OR_g) - 90.0)) *
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
          static_cast<real_T>(Copy_of_HITL_HEXA_MISSION_B.OR_g) +
          Copy_of_HITL_HEXA_MISSION_B.Sum_f * static_cast<real_T>
          (!Copy_of_HITL_HEXA_MISSION_B.OR_g);
      }

      if ((Copy_of_HITL_HEXA_MISSION_B.Gain_i > 180.0) ||
          (Copy_of_HITL_HEXA_MISSION_B.Gain_i < -180.0)) {
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g =
          Copy_of_HITL_HEXA_MISSION_rt_remd_snf
          (Copy_of_HITL_HEXA_MISSION_B.Gain_i, 360.0);
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a =
          Copy_of_HITL_HEXA_MISSION_B.Gain2_g / 180.0;
        if (Copy_of_HITL_HEXA_MISSION_B.Switch2_a < 0.0) {
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = ceil
            (Copy_of_HITL_HEXA_MISSION_B.Switch2_a);
        } else {
          Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = floor
            (Copy_of_HITL_HEXA_MISSION_B.Switch2_a);
        }

        Copy_of_HITL_HEXA_MISSION_B.Gain_i =
          (Copy_of_HITL_HEXA_MISSION_B.Gain2_g - 360.0 *
           Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1) +
          Copy_of_HITL_HEXA_MISSION_B.Gain_i * 0.0;
      }

      Copy_of_HITL_HEXA_MISSION_B.Switch2_a = Copy_of_HITL_HEXA_MISSION_sind_f
        (Copy_of_HITL_HEXA_MISSION_B.In1_f.lat);
      Copy_of_HITL_HEXA_MISSION_B.Gain2_g = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 * Copy_of_HITL_HEXA_MISSION_B.Switch2_a *
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a);
      if (rtIsInf(Copy_of_HITL_HEXA_MISSION_B.In1_f.lat) || rtIsNaN
          (Copy_of_HITL_HEXA_MISSION_B.In1_f.lat)) {
        Copy_of_HITL_HEXA_MISSION_B.Gain3 = (rtNaN);
      } else {
        Copy_of_HITL_HEXA_MISSION_B.Gain3 =
          Copy_of_HITL_HEXA_MISSION_rt_remd_snf
          (Copy_of_HITL_HEXA_MISSION_B.In1_f.lat, 360.0);
        Copy_of_HITL_HEXA_MISSION_B.Saturation1 = fabs
          (Copy_of_HITL_HEXA_MISSION_B.Gain3);
        if (Copy_of_HITL_HEXA_MISSION_B.Saturation1 > 180.0) {
          if (Copy_of_HITL_HEXA_MISSION_B.Gain3 > 0.0) {
            Copy_of_HITL_HEXA_MISSION_B.Gain3 -= 360.0;
          } else {
            Copy_of_HITL_HEXA_MISSION_B.Gain3 += 360.0;
          }

          Copy_of_HITL_HEXA_MISSION_B.Saturation1 = fabs
            (Copy_of_HITL_HEXA_MISSION_B.Gain3);
        }

        if (Copy_of_HITL_HEXA_MISSION_B.Saturation1 <= 45.0) {
          Copy_of_HITL_HEXA_MISSION_B.Gain3 = cos(0.017453292519943295 *
            Copy_of_HITL_HEXA_MISSION_B.Gain3);
        } else if (Copy_of_HITL_HEXA_MISSION_B.Saturation1 <= 135.0) {
          if (Copy_of_HITL_HEXA_MISSION_B.Gain3 > 0.0) {
            Copy_of_HITL_HEXA_MISSION_B.Gain3 = -sin
              ((Copy_of_HITL_HEXA_MISSION_B.Gain3 - 90.0) * 0.017453292519943295);
          } else {
            Copy_of_HITL_HEXA_MISSION_B.Gain3 = sin
              ((Copy_of_HITL_HEXA_MISSION_B.Gain3 + 90.0) * 0.017453292519943295);
          }
        } else {
          if (Copy_of_HITL_HEXA_MISSION_B.Gain3 > 0.0) {
            Copy_of_HITL_HEXA_MISSION_B.Gain3 =
              (Copy_of_HITL_HEXA_MISSION_B.Gain3 - 180.0) * 0.017453292519943295;
          } else {
            Copy_of_HITL_HEXA_MISSION_B.Gain3 =
              (Copy_of_HITL_HEXA_MISSION_B.Gain3 + 180.0) * 0.017453292519943295;
          }

          Copy_of_HITL_HEXA_MISSION_B.Gain3 = -cos
            (Copy_of_HITL_HEXA_MISSION_B.Gain3);
        }
      }

      Copy_of_HITL_HEXA_MISSION_B.Sum_f /=
        Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf(1.0, 0.99330562000985867 / (1.0
        - 0.0066943799901413165 * Copy_of_HITL_HEXA_MISSION_B.Switch2_a *
        Copy_of_HITL_HEXA_MISSION_B.Switch2_a) *
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g) * 57.295779513082323;
      Copy_of_HITL_HEXA_MISSION_B.Gain_i /=
        Copy_of_HITL_HEXA_MISSION_rt_atan2d_snf(1.0,
        Copy_of_HITL_HEXA_MISSION_B.Gain2_g * Copy_of_HITL_HEXA_MISSION_B.Gain3)
        * 57.295779513082323;
      Copy_of_HITL_HEXA_MISSION_B.Switch2_a = -static_cast<real_T>
        (Copy_of_HITL_HEXA_MISSION_B.In1_p.next.alt) +
        Copy_of_HITL_HEXA_MISSION_B.In1_f.alt;
      Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[0] = rtIsNaN
        (Copy_of_HITL_HEXA_MISSION_B.Sum_f);
      Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[1] = rtIsNaN
        (Copy_of_HITL_HEXA_MISSION_B.Gain_i);
      Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[2] = rtIsNaN
        (Copy_of_HITL_HEXA_MISSION_B.Switch2_a);
      Copy_of_HITL_HEXA_MISSION_B.Compare_k = false;
      Copy_of_HITL_HEXA_MISSION_B.iy = 0;
      exitg1 = false;
      while ((!exitg1) && (Copy_of_HITL_HEXA_MISSION_B.iy < 3)) {
        if (Copy_of_HITL_HEXA_MISSION_B.distinctWptsIdx[Copy_of_HITL_HEXA_MISSION_B.iy])
        {
          Copy_of_HITL_HEXA_MISSION_B.Compare_k = true;
          exitg1 = true;
        } else {
          Copy_of_HITL_HEXA_MISSION_B.iy++;
        }
      }

      Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = 0.0 /
        static_cast<real_T>(!Copy_of_HITL_HEXA_MISSION_B.Compare_k);
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1
        + Copy_of_HITL_HEXA_MISSION_B.Sum_f);
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1
        + Copy_of_HITL_HEXA_MISSION_B.Gain_i);
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(Copy_of_HITL_HEXA_MISSION_B.rtb_CastToDouble_idx_1
        + Copy_of_HITL_HEXA_MISSION_B.Switch2_a);
    } else {
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S606>/MATLAB System'

    // SignalConversion generated from: '<S606>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S606>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[0] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.vx;

    // SignalConversion generated from: '<S606>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S606>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[1] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.vy;

    // SignalConversion generated from: '<S606>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   BusAssignment: '<S606>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[2] =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.vz;

    // BusAssignment: '<S606>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'
    //   Constant: '<S606>/Constant5'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].timestamp =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.timestamp;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].yaw =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.yaw;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].yaw_speed =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.yawspeed;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].point_valid =
      Copy_of_HITL_HEXA_MISSION_P.Constant5_Value_h;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[2].type =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.next.type;

    // SignalConversion generated from: '<S605>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment'
    //   BusAssignment: '<S605>/Bus Assignment1'
    //   Constant: '<S607>/Constant'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S605>/Bus Assignment1' incorporates:
    //   Constant: '<S605>/Constant'
    //   Constant: '<S605>/Constant1'
    //   Constant: '<S605>/Constant2'
    //   Constant: '<S605>/Constant3'
    //   Constant: '<S605>/Constant4'
    //   Constant: '<S605>/Constant5'
    //   Constant: '<S605>/Constant6'
    //   Constant: '<S605>/Constant7'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.timestamp =
      Copy_of_HITL_HEXA_MISSION_P.Constant7_Value;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.yaw =
      Copy_of_HITL_HEXA_MISSION_P.Constant3_Value_a;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.yaw_speed =
      Copy_of_HITL_HEXA_MISSION_P.Constant4_Value_g;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.position[0] =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fh[0];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.velocity[0] =
      Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_h[0];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.acceleration[0] =
      Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_f[0];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.position[1] =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fh[1];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.velocity[1] =
      Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_h[1];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.acceleration[1] =
      Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_f[1];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.position[2] =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fh[2];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.velocity[2] =
      Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_h[2];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.acceleration[2] =
      Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_f[2];
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.point_valid =
      Copy_of_HITL_HEXA_MISSION_P.Constant5_Value_l;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f.type =
      Copy_of_HITL_HEXA_MISSION_P.Constant6_Value;

    // BusAssignment: '<S597>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment'
    //   Constant: '<S597>/Constant'
    //   Constant: '<S607>/Constant'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.timestamp =
      Copy_of_HITL_HEXA_MISSION_B.In1_p.timestamp;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.type =
      Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fm;
    for (Copy_of_HITL_HEXA_MISSION_B.i1 = 0; Copy_of_HITL_HEXA_MISSION_B.i1 < 7;
         Copy_of_HITL_HEXA_MISSION_B.i1++) {
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1._padding0[Copy_of_HITL_HEXA_MISSION_B.i1]
        =
        Copy_of_HITL_HEXA_MISSION_P.Constant_Value._padding0[Copy_of_HITL_HEXA_MISSION_B.i1];
    }

    // BusAssignment: '<S597>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S605>/Bus Assignment1'
    //   Concatenate: '<S597>/Matrix Concatenate'

    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[3] =
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f;
    Copy_of_HITL_HEXA_MISSION_B.BusAssignment1.waypoints[4] =
      Copy_of_HITL_HEXA_MISSION_B.BusAssignment1_f;

    // MATLABSystem: '<S608>/SinkBlock' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'

    uORB_write_step(Copy_of_HITL_HEXA_MISSION_DW.obj_mc.orbMetadataObj,
                    &Copy_of_HITL_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj,
                    &Copy_of_HITL_HEXA_MISSION_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S580>/Send waypoints to OBC'
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp
    (&Copy_of_HITL_HEXA_MISSION_B.PX4Timestamp_o);
}

// Model initialize function
void Copy_of_HITL_HEXA_MISSION_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_d[0] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_d[1] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant_Value_f2 = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_k4[0] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_k4[1] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant_Value_l4 = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fh[0] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fh[1] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant_Value_fh[2] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_h[0] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_h[1] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant1_Value_h[2] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_f[0] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_f[1] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant2_Value_f[2] = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant3_Value_a = rtNaNF;
  Copy_of_HITL_HEXA_MISSION_P.Constant4_Value_g = rtNaNF;

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

    // Start for If: '<S579>/If'
    Copy_of_HITL_HEXA_MISSION_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S19>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    Copy_of_HITL_HEXA_MISSION_B.In1_k = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S19>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S618>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S622>/Out1' incorporates:
    //   SignalConversion generated from: '<S622>/In1'

    Copy_of_HITL_HEXA_MISSION_B.In1_b = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S618>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S601>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S602>/In1' incorporates:
    //   Outport: '<S602>/Out1'

    Copy_of_HITL_HEXA_MISSION_B.In1 = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S601>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S599>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S614>/In1' incorporates:
    //   Outport: '<S614>/Out1'

    Copy_of_HITL_HEXA_MISSION_B.In1_p = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S599>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S598>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S613>/In1' incorporates:
    //   Outport: '<S613>/Out1'

    Copy_of_HITL_HEXA_MISSION_B.In1_f = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S598>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S620>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S624>/Out1' incorporates:
    //   SignalConversion generated from: '<S624>/In1'

    Copy_of_HITL_HEXA_MISSION_B.In1_c = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S620>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S579>/Take-off'
    // InitializeConditions for Delay: '<S591>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_c =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S592>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_d =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S592>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S593>/yaw_In' incorporates:
    //   Outport: '<S593>/yaw_Out'

    Copy_of_HITL_HEXA_MISSION_B.yaw_In_ik =
      Copy_of_HITL_HEXA_MISSION_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S592>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S579>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S579>/Land'
    // InitializeConditions for Delay: '<S582>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_n;
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S587>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_n =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S588>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE_b =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S588>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S590>/yaw_In' incorporates:
    //   Outport: '<S590>/yaw_Out'

    Copy_of_HITL_HEXA_MISSION_B.yaw_In_i =
      Copy_of_HITL_HEXA_MISSION_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S588>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S587>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S589>/In' incorporates:
    //   Outport: '<S589>/Out'

    Copy_of_HITL_HEXA_MISSION_B.In = Copy_of_HITL_HEXA_MISSION_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S587>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S579>/Land'

    // SystemInitialize for IfAction SubSystem: '<S579>/Waypoint'
    // Start for MATLABSystem: '<S584>/UAV Waypoint Follower'
    Copy_of_HITL_HEXA_MISSION_DW.obj.LastWaypointFlag = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj.StartFlag = true;
    Copy_of_HITL_HEXA_MISSION_DW.obj.LookaheadFactor = 1.01;
    Copy_of_HITL_HEXA_MISSION_DW.obj.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S584>/UAV Waypoint Follower'
    Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
    memset(&Copy_of_HITL_HEXA_MISSION_DW.obj.WaypointsInternal[0], 0, 9U *
           sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S579>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S579>/IDLE'
    // InitializeConditions for Delay: '<S585>/Delay'
    Copy_of_HITL_HEXA_MISSION_DW.Delay_DSTATE =
      Copy_of_HITL_HEXA_MISSION_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S585>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S586>/yaw_In' incorporates:
    //   Outport: '<S586>/yaw_Out'

    Copy_of_HITL_HEXA_MISSION_B.yaw_In =
      Copy_of_HITL_HEXA_MISSION_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S585>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S579>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S619>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S623>/In1' incorporates:
    //   Outport: '<S623>/Out1'

    Copy_of_HITL_HEXA_MISSION_B.In1_m = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S619>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/mc_pos_controller'
    Copy_of_HITL_HEXA_MISSION_mc_pos_controller_Init();

    // End of SystemInitialize for SubSystem: '<S23>/mc_pos_controller'

    // SystemInitialize for Enabled SubSystem: '<S23>/mc_att_controller'
    Copy_of_HITL_HEXA_MISSION_mc_att_controller_Init();

    // End of SystemInitialize for SubSystem: '<S23>/mc_att_controller'

    // SystemInitialize for Enabled SubSystem: '<S617>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S621>/Out1' incorporates:
    //   SignalConversion generated from: '<S621>/In1'

    Copy_of_HITL_HEXA_MISSION_B.In1_l = Copy_of_HITL_HEXA_MISSION_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S617>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/mc_rate_controller'
    Copy_of_HITL_HEXA_MISSION_mc_rate_controller_Init();

    // End of SystemInitialize for SubSystem: '<S23>/mc_rate_controller'

    // SystemInitialize for Enabled SubSystem: '<S580>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S609>/If Action Subsystem2'
    // Start for MATLABSystem: '<S612>/Read Parameter'
    Copy_of_HITL_HEXA_MISSION_DW.obj_g.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_g.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_c;
    Copy_of_HITL_HEXA_MISSION_DW.obj_g.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_g.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S612>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S609>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S609>/If Action Subsystem1'
    // Start for MATLABSystem: '<S611>/Read Parameter'
    Copy_of_HITL_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_b.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_g;
    Copy_of_HITL_HEXA_MISSION_DW.obj_b.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_b.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S611>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S609>/If Action Subsystem1'
    Copy_of_HITL_HEXA_MISSION_MATLABSystem_Init
      (&Copy_of_HITL_HEXA_MISSION_DW.MATLABSystem);
    Copy_of_HITL_HEXA_MISSION_MATLABSystem_Init
      (&Copy_of_HITL_HEXA_MISSION_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S606>/MATLAB System'
    Copy_of_HITL_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S608>/SinkBlock' incorporates:
    //   BusAssignment: '<S597>/Bus Assignment1'

    Copy_of_HITL_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mc.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_mc.orbMetadataObj,
                          &Copy_of_HITL_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj,
                          &Copy_of_HITL_HEXA_MISSION_B.BusAssignment1, 1);
    Copy_of_HITL_HEXA_MISSION_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S580>/Send waypoints to OBC'

    // Start for MATLABSystem: '<S19>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_da.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_da.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_da.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_da.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_da.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_da.isSetupComplete = true;

    // Start for MATLABSystem: '<S618>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_d0.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_d0.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_d0.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_d0.isSetupComplete = true;

    // Start for MATLABSystem: '<S580>/Read Parameter'
    Copy_of_HITL_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_k.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter_SampleTime_d;
    Copy_of_HITL_HEXA_MISSION_DW.obj_k.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_k.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S580>/Read Parameter'

    // Start for MATLABSystem: '<S601>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_e.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_e.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_e.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S599>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_kz.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_kz.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_kz.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S598>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_gff.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_gff.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_gff.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_gff.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_gff.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_gff.isSetupComplete = true;

    // Start for MATLABSystem: '<S580>/LLA2LocalCoordinates'
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.previousValidReceived = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.nextValidReceived = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S620>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mg.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mg.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_mg.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_mg.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_mg.isSetupComplete = true;

    // Start for MATLABSystem: '<S619>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_gv.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_gv.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_gv.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S617>/SourceBlock'
    Copy_of_HITL_HEXA_MISSION_DW.obj_po.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_po.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_po.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_po.orbMetadataObj,
                         &Copy_of_HITL_HEXA_MISSION_DW.obj_po.eventStructObj);
    Copy_of_HITL_HEXA_MISSION_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S7>/Read Parameter13'
    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter13_SampleTime;
    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_ka.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_ka.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter13'

    // Start for MATLABSystem: '<S7>/Read Parameter1'
    Copy_of_HITL_HEXA_MISSION_DW.obj_a.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_a.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter1_SampleTime;
    Copy_of_HITL_HEXA_MISSION_DW.obj_a.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_a.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter1'

    // Start for MATLABSystem: '<S7>/Read Parameter2'
    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter2_SampleTime;
    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_ng.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_ng.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/Read Parameter3'
    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter3_SampleTime;
    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_n0.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_n0.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter3'

    // Start for MATLABSystem: '<S7>/Read Parameter4'
    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter4_SampleTime;
    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_cf.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_cf.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter4'

    // Start for MATLABSystem: '<S7>/Read Parameter5'
    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.SampleTime =
      Copy_of_HITL_HEXA_MISSION_P.ReadParameter5_SampleTime;
    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.isInitialized = 1;
    if (Copy_of_HITL_HEXA_MISSION_DW.obj_p1.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Copy_of_HITL_HEXA_MISSION_DW.obj_p1.SampleTime;
    }

    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter5'
    Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Init
      (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S34>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'

    Copy_of_HITL_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_dz.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_dz.orbMetadataObj = ORB_ID
      (vehicle_rates_setpoint);
    uORB_write_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_dz.orbMetadataObj,
                          &Copy_of_HITL_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj,
                          &Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h4, 1);
    Copy_of_HITL_HEXA_MISSION_DW.obj_dz.isSetupComplete = true;
    Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Init
      (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S32>/SinkBlock' incorporates:
    //   BusAssignment: '<S24>/Bus Assignment'

    Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.orbMetadataObj = ORB_ID
      (vehicle_attitude_setpoint);
    uORB_write_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.orbMetadataObj,
                          &Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.orbAdvertiseObj,
                          &Copy_of_HITL_HEXA_MISSION_B.BusAssignment_h, 1);
    Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.isSetupComplete = true;

    // Start for MATLABSystem: '<S22>/SinkBlock' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment'

    Copy_of_HITL_HEXA_MISSION_DW.obj_hy.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_hy.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_hy.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_hy.orbMetadataObj,
                          &Copy_of_HITL_HEXA_MISSION_DW.obj_hy.orbAdvertiseObj,
                          &Copy_of_HITL_HEXA_MISSION_B.BusAssignment, 1);
    Copy_of_HITL_HEXA_MISSION_DW.obj_hy.isSetupComplete = true;
    Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Init
      (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: '<S616>/SinkBlock' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment'

    Copy_of_HITL_HEXA_MISSION_DW.obj_o2.matlabCodegenIsDeleted = false;
    Copy_of_HITL_HEXA_MISSION_DW.obj_o2.isInitialized = 1;
    Copy_of_HITL_HEXA_MISSION_DW.obj_o2.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(Copy_of_HITL_HEXA_MISSION_DW.obj_o2.orbMetadataObj,
                          &Copy_of_HITL_HEXA_MISSION_DW.obj_o2.orbAdvertiseObj,
                          &Copy_of_HITL_HEXA_MISSION_B.BusAssignment_m, 1);
    Copy_of_HITL_HEXA_MISSION_DW.obj_o2.isSetupComplete = true;
    Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Init
      (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp_o);
  }
}

// Model terminate function
void Copy_of_HITL_HEXA_MISSION_terminate(void)
{
  // Terminate for MATLABSystem: '<S19>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_da.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_da.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_da.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_da.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_da.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S19>/SourceBlock'

  // Terminate for MATLABSystem: '<S618>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_d0.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S618>/SourceBlock'

  // Terminate for MATLABSystem: '<S580>/Read Parameter'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S580>/Read Parameter'

  // Terminate for MATLABSystem: '<S601>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_e.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S601>/SourceBlock'

  // Terminate for MATLABSystem: '<S599>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_kz.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S599>/SourceBlock'

  // Terminate for MATLABSystem: '<S598>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_gff.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_gff.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_gff.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_gff.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_gff.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S598>/SourceBlock'

  // Terminate for MATLABSystem: '<S580>/LLA2LocalCoordinates'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S580>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S620>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_mg.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_mg.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_mg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S620>/SourceBlock'

  // Terminate for MATLABSystem: '<S619>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_gv.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S619>/SourceBlock'

  // Terminate for Enabled SubSystem: '<S23>/mc_pos_controller'
  Copy_of_HITL_HEXA_MISSION_mc_pos_controller_Term();

  // End of Terminate for SubSystem: '<S23>/mc_pos_controller'

  // Terminate for Enabled SubSystem: '<S23>/mc_att_controller'
  Copy_of_HITL_HEXA_MISSION_mc_att_controller_Term();

  // End of Terminate for SubSystem: '<S23>/mc_att_controller'

  // Terminate for MATLABSystem: '<S617>/SourceBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_po.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_po.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S617>/SourceBlock'

  // Terminate for Enabled SubSystem: '<S23>/mc_rate_controller'
  Copy_of_HITL_HEXA_MISSION_mc_rate_controller_Term();

  // End of Terminate for SubSystem: '<S23>/mc_rate_controller'

  // Terminate for MATLABSystem: '<S7>/Read Parameter13'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_ka.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_ka.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter13'

  // Terminate for MATLABSystem: '<S7>/Read Parameter1'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_a.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter1'

  // Terminate for MATLABSystem: '<S7>/Read Parameter2'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_ng.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/Read Parameter3'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_n0.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_n0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter3'

  // Terminate for MATLABSystem: '<S7>/Read Parameter4'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_cf.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_cf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter4'

  // Terminate for MATLABSystem: '<S7>/Read Parameter5'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_p1.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_p1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter5'
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Term
    (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S34>/SinkBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_dz.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_dz.isSetupComplete) {
      uORB_write_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S34>/SinkBlock'
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Term
    (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S32>/SinkBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.isSetupComplete) {
      uORB_write_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_mgm.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S32>/SinkBlock'

  // Terminate for MATLABSystem: '<S22>/SinkBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_hy.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_hy.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_hy.isSetupComplete) {
      uORB_write_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_hy.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SinkBlock'
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Term
    (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S616>/SinkBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_o2.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_o2.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_o2.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_o2.isSetupComplete) {
      uORB_write_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_o2.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S616>/SinkBlock'

  // Terminate for Enabled SubSystem: '<S580>/Send waypoints to OBC'
  Copy_of_HITL_HEXA_MISSION_MATLABSystem_Term
    (&Copy_of_HITL_HEXA_MISSION_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S609>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S612>/Read Parameter'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_g.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S612>/Read Parameter'
  // End of Terminate for SubSystem: '<S609>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S609>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S611>/Read Parameter'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S611>/Read Parameter'
  // End of Terminate for SubSystem: '<S609>/If Action Subsystem1'
  Copy_of_HITL_HEXA_MISSION_MATLABSystem_Term
    (&Copy_of_HITL_HEXA_MISSION_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S606>/MATLAB System'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S606>/MATLAB System'

  // Terminate for MATLABSystem: '<S608>/SinkBlock'
  if (!Copy_of_HITL_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted) {
    Copy_of_HITL_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((Copy_of_HITL_HEXA_MISSION_DW.obj_mc.isInitialized == 1) &&
        Copy_of_HITL_HEXA_MISSION_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&Copy_of_HITL_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S608>/SinkBlock'
  // End of Terminate for SubSystem: '<S580>/Send waypoints to OBC'
  Copy_of_HITL_HEXA_MISSION_PX4Timestamp_Term
    (&Copy_of_HITL_HEXA_MISSION_DW.PX4Timestamp_o);
}

//
// File trailer for generated code.
//
// [EOF]
//
