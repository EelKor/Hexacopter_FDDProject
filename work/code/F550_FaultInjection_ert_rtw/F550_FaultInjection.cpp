//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: F550_FaultInjection.cpp
//
// Code generated for Simulink model 'F550_FaultInjection'.
//
// Model version                  : 4.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 17:25:22 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "F550_FaultInjection.h"
#include "rtwtypes.h"
#include "F550_FaultInjection_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_sys_F550_FaultInjection_44.h"
#include <string.h>
#include "CLAW.h"
#include "rt_sys_CLAW_70.h"
#include "rt_defines.h"
#include <float.h>

// Block signals (default storage)
B_F550_FaultInjection_T F550_FaultInjection_B;

// Block states (default storage)
DW_F550_FaultInjection_T F550_FaultInjection_DW;

// Real-time model
RT_MODEL_F550_FaultInjection_T F550_FaultInjection_M_ =
  RT_MODEL_F550_FaultInjection_T();
RT_MODEL_F550_FaultInjection_T *const F550_FaultInjection_M =
  &F550_FaultInjection_M_;

// Forward declaration for local functions
static real_T F550_FaultInjection_sind(real_T x);

// Forward declaration for local functions
static real_T F550_FaultInjection_rt_remd_snf(real_T u0, real_T u1);
static real_T F550_FaultInjection_sind_d(real_T x);
static real_T F550_FaultInjection_rt_atan2d_snf_d(real_T u0, real_T u1);
static void F550_FaultInjection_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3]);
static real_T F550_FaultInjection_norm(const real_T x[3]);
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

static real_T F550_FaultInjection_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S586>/MATLAB System'
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

  // End of Start for MATLABSystem: '<S586>/MATLAB System'
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
void F550_FaultInjection_MATLABSystem_Init(DW_MATLABSystem_F550_FaultInjection_T
  *localDW)
{
  // Start for MATLABSystem: '<S586>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void F550_FaultInjection_MATLABSystem(const real_T rtu_0[3], const real_T rtu_1
  [3], boolean_T rtu_2, uint8_T rtu_3, B_MATLABSystem_F550_FaultInjection_T
  *localB)
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

  // MATLABSystem: '<S586>/MATLAB System'
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

    flat = F550_FaultInjection_sind(rtu_1[0]);
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

    // MATLABSystem: '<S586>/MATLAB System'
    localB->MATLABSystem[0] = static_cast<real32_T>(r + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(r + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(r + flat);
  } else {
    // MATLABSystem: '<S586>/MATLAB System'
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S586>/MATLAB System'
}

// Termination for atomic system:
void F550_FaultInjection_MATLABSystem_Term(DW_MATLABSystem_F550_FaultInjection_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S586>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S586>/MATLAB System'
}

static real_T F550_FaultInjection_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      F550_FaultInjection_B.q = ceil(u1);
    } else {
      F550_FaultInjection_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != F550_FaultInjection_B.q)) {
      F550_FaultInjection_B.q = fabs(u0 / u1);
      if (!(fabs(F550_FaultInjection_B.q - floor(F550_FaultInjection_B.q + 0.5))
            > DBL_EPSILON * F550_FaultInjection_B.q)) {
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

static real_T F550_FaultInjection_sind_d(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S589>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = F550_FaultInjection_rt_remd_snf(x, 360.0);
    F550_FaultInjection_B.absx_l = fabs(b_x);
    if (F550_FaultInjection_B.absx_l > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      F550_FaultInjection_B.absx_l = fabs(b_x);
    }

    if (F550_FaultInjection_B.absx_l <= 45.0) {
      b_x *= 0.017453292519943295;
      b_x = sin(b_x);
    } else if (F550_FaultInjection_B.absx_l <= 135.0) {
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

  // End of Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
  return b_x;
}

static real_T F550_FaultInjection_rt_atan2d_snf_d(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      F550_FaultInjection_B.i_d = 1;
    } else {
      F550_FaultInjection_B.i_d = -1;
    }

    if (u1 > 0.0) {
      F550_FaultInjection_B.i1_d = 1;
    } else {
      F550_FaultInjection_B.i1_d = -1;
    }

    y = atan2(static_cast<real_T>(F550_FaultInjection_B.i_d), static_cast<real_T>
              (F550_FaultInjection_B.i1_d));
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

static void F550_FaultInjection_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
  F550_FaultInjection_B.dLat = lla[0] - lla0[0];
  F550_FaultInjection_B.dLon = lla[1] - lla0[1];
  F550_FaultInjection_B.flat = fabs(F550_FaultInjection_B.dLat);
  if (F550_FaultInjection_B.flat > 180.0) {
    // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
    if (rtIsNaN(F550_FaultInjection_B.dLat + 180.0) || rtIsInf
        (F550_FaultInjection_B.dLat + 180.0)) {
      F550_FaultInjection_B.r = (rtNaN);
    } else if (F550_FaultInjection_B.dLat + 180.0 == 0.0) {
      F550_FaultInjection_B.r = 0.0;
    } else {
      F550_FaultInjection_B.r = fmod(F550_FaultInjection_B.dLat + 180.0, 360.0);
      if (F550_FaultInjection_B.r == 0.0) {
        F550_FaultInjection_B.r = 0.0;
      } else if (F550_FaultInjection_B.dLat + 180.0 < 0.0) {
        F550_FaultInjection_B.r += 360.0;
      }
    }

    F550_FaultInjection_B.dLat = F550_FaultInjection_B.dLat * 0.0 +
      (F550_FaultInjection_B.r - 180.0);
    F550_FaultInjection_B.flat = fabs(F550_FaultInjection_B.dLat);
  }

  if (F550_FaultInjection_B.flat > 90.0) {
    // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
    F550_FaultInjection_B.flat = fabs(F550_FaultInjection_B.dLat);
    F550_FaultInjection_B.latp2 = (F550_FaultInjection_B.flat > 90.0);

    // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
    F550_FaultInjection_B.dLon += 180.0;
    F550_FaultInjection_B.r = F550_FaultInjection_B.dLat * static_cast<real_T>
      (F550_FaultInjection_B.latp2);
    if (rtIsNaN(F550_FaultInjection_B.r)) {
      F550_FaultInjection_B.r = (rtNaN);
    } else if (F550_FaultInjection_B.r < 0.0) {
      F550_FaultInjection_B.r = -1.0;
    } else {
      F550_FaultInjection_B.r = (F550_FaultInjection_B.r > 0.0);
    }

    F550_FaultInjection_B.dLat = (90.0 - (F550_FaultInjection_B.flat *
      static_cast<real_T>(F550_FaultInjection_B.latp2) - 90.0)) *
      F550_FaultInjection_B.r * static_cast<real_T>(F550_FaultInjection_B.latp2)
      + F550_FaultInjection_B.dLat * static_cast<real_T>
      (!F550_FaultInjection_B.latp2);
  }

  // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
  if ((F550_FaultInjection_B.dLon > 180.0) || (F550_FaultInjection_B.dLon <
       -180.0)) {
    F550_FaultInjection_B.flat = F550_FaultInjection_rt_remd_snf
      (F550_FaultInjection_B.dLon, 360.0);
    F550_FaultInjection_B.r = F550_FaultInjection_B.flat / 180.0;
    if (F550_FaultInjection_B.r < 0.0) {
      F550_FaultInjection_B.r = ceil(F550_FaultInjection_B.r);
    } else {
      F550_FaultInjection_B.r = floor(F550_FaultInjection_B.r);
    }

    F550_FaultInjection_B.dLon = (F550_FaultInjection_B.flat - 360.0 *
      F550_FaultInjection_B.r) + F550_FaultInjection_B.dLon * 0.0;
  }

  F550_FaultInjection_B.flat = F550_FaultInjection_sind_d(lla0[0]);
  F550_FaultInjection_B.flat_tmp = 1.0 - 0.0066943799901413165 *
    F550_FaultInjection_B.flat * F550_FaultInjection_B.flat;
  F550_FaultInjection_B.flat = 6.378137E+6 / sqrt(F550_FaultInjection_B.flat_tmp);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    F550_FaultInjection_B.r = (rtNaN);
  } else {
    F550_FaultInjection_B.r = F550_FaultInjection_rt_remd_snf(lla0[0], 360.0);
    F550_FaultInjection_B.absx = fabs(F550_FaultInjection_B.r);
    if (F550_FaultInjection_B.absx > 180.0) {
      if (F550_FaultInjection_B.r > 0.0) {
        F550_FaultInjection_B.r -= 360.0;
      } else {
        F550_FaultInjection_B.r += 360.0;
      }

      F550_FaultInjection_B.absx = fabs(F550_FaultInjection_B.r);
    }

    if (F550_FaultInjection_B.absx <= 45.0) {
      F550_FaultInjection_B.r = cos(0.017453292519943295 *
        F550_FaultInjection_B.r);
    } else if (F550_FaultInjection_B.absx <= 135.0) {
      if (F550_FaultInjection_B.r > 0.0) {
        F550_FaultInjection_B.r = -sin((F550_FaultInjection_B.r - 90.0) *
          0.017453292519943295);
      } else {
        F550_FaultInjection_B.r = sin((F550_FaultInjection_B.r + 90.0) *
          0.017453292519943295);
      }
    } else {
      if (F550_FaultInjection_B.r > 0.0) {
        F550_FaultInjection_B.r = (F550_FaultInjection_B.r - 180.0) *
          0.017453292519943295;
      } else {
        F550_FaultInjection_B.r = (F550_FaultInjection_B.r + 180.0) *
          0.017453292519943295;
      }

      F550_FaultInjection_B.r = -cos(F550_FaultInjection_B.r);
    }
  }

  xyzNED[0] = F550_FaultInjection_B.dLat / (F550_FaultInjection_rt_atan2d_snf_d
    (1.0, 0.99330562000985867 / F550_FaultInjection_B.flat_tmp *
     F550_FaultInjection_B.flat) * 57.295779513082323);
  xyzNED[1] = F550_FaultInjection_B.dLon / (F550_FaultInjection_rt_atan2d_snf_d
    (1.0, F550_FaultInjection_B.flat * F550_FaultInjection_B.r) *
    57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  F550_FaultInjection_B.b[0] = rtIsNaN(xyzNED[0]);
  F550_FaultInjection_B.b[1] = rtIsNaN(xyzNED[1]);
  F550_FaultInjection_B.b[2] = rtIsNaN(xyzNED[2]);
  F550_FaultInjection_B.latp2 = false;
  F550_FaultInjection_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (F550_FaultInjection_B.b_k < 3)) {
    if (F550_FaultInjection_B.b[F550_FaultInjection_B.b_k]) {
      F550_FaultInjection_B.latp2 = true;
      exitg1 = true;
    } else {
      F550_FaultInjection_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
  F550_FaultInjection_B.dLat = 0.0 / static_cast<real_T>
    (!F550_FaultInjection_B.latp2);
  xyzNED[0] += F550_FaultInjection_B.dLat;
  xyzNED[1] += F550_FaultInjection_B.dLat;
  xyzNED[2] += F550_FaultInjection_B.dLat;
}

static real_T F550_FaultInjection_norm(const real_T x[3])
{
  real_T y;
  F550_FaultInjection_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S567>/UAV Waypoint Follower'
  F550_FaultInjection_B.absxk = fabs(x[0]);
  if (F550_FaultInjection_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    F550_FaultInjection_B.scale = F550_FaultInjection_B.absxk;
  } else {
    F550_FaultInjection_B.t = F550_FaultInjection_B.absxk /
      3.3121686421112381E-170;
    y = F550_FaultInjection_B.t * F550_FaultInjection_B.t;
  }

  // Start for MATLABSystem: '<S567>/UAV Waypoint Follower'
  F550_FaultInjection_B.absxk = fabs(x[1]);
  if (F550_FaultInjection_B.absxk > F550_FaultInjection_B.scale) {
    F550_FaultInjection_B.t = F550_FaultInjection_B.scale /
      F550_FaultInjection_B.absxk;
    y = y * F550_FaultInjection_B.t * F550_FaultInjection_B.t + 1.0;
    F550_FaultInjection_B.scale = F550_FaultInjection_B.absxk;
  } else {
    F550_FaultInjection_B.t = F550_FaultInjection_B.absxk /
      F550_FaultInjection_B.scale;
    y += F550_FaultInjection_B.t * F550_FaultInjection_B.t;
  }

  // Start for MATLABSystem: '<S567>/UAV Waypoint Follower'
  F550_FaultInjection_B.absxk = fabs(x[2]);
  if (F550_FaultInjection_B.absxk > F550_FaultInjection_B.scale) {
    F550_FaultInjection_B.t = F550_FaultInjection_B.scale /
      F550_FaultInjection_B.absxk;
    y = y * F550_FaultInjection_B.t * F550_FaultInjection_B.t + 1.0;
    F550_FaultInjection_B.scale = F550_FaultInjection_B.absxk;
  } else {
    F550_FaultInjection_B.t = F550_FaultInjection_B.absxk /
      F550_FaultInjection_B.scale;
    y += F550_FaultInjection_B.t * F550_FaultInjection_B.t;
  }

  return F550_FaultInjection_B.scale * sqrt(y);
}

// Model step function
void F550_FaultInjection_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  F550_FaultInjection_SourceBlock(&F550_FaultInjection_B.SourceBlock,
    &F550_FaultInjection_DW.SourceBlock);

  // Outputs for Enabled SubSystem: '<S19>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  if (F550_FaultInjection_B.SourceBlock.SourceBlock_o1) {
    // SignalConversion generated from: '<S20>/In1' incorporates:
    //   MATLABSystem: '<S19>/SourceBlock'

    F550_FaultInjection_B.In1_k =
      F550_FaultInjection_B.SourceBlock.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S19>/Enabled Subsystem'

  // RelationalOperator: '<S11>/Compare' incorporates:
  //   Constant: '<S11>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  F550_FaultInjection_B.Compare_k = (F550_FaultInjection_B.In1_k.values[6] >=
    F550_FaultInjection_P.CompareToConstant_const);

  // MATLABSystem: '<S603>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_mg.orbMetadataObj,
     &F550_FaultInjection_DW.obj_mg.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S603>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S607>/Enable'

  // Start for MATLABSystem: '<S603>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S607>/In1'
    F550_FaultInjection_B.In1_c = F550_FaultInjection_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S603>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion1'
  F550_FaultInjection_B.DataTypeConversion1[0] = F550_FaultInjection_B.In1_c.x;
  F550_FaultInjection_B.DataTypeConversion1[1] = F550_FaultInjection_B.In1_c.y;
  F550_FaultInjection_B.DataTypeConversion1[2] = F550_FaultInjection_B.In1_c.z;
  F550_FaultInjection_B.DataTypeConversion1[3] = F550_FaultInjection_B.In1_c.vx;
  F550_FaultInjection_B.DataTypeConversion1[4] = F550_FaultInjection_B.In1_c.vy;
  F550_FaultInjection_B.DataTypeConversion1[5] = F550_FaultInjection_B.In1_c.vz;
  F550_FaultInjection_B.DataTypeConversion1[6] =
    F550_FaultInjection_B.In1_c.heading;

  // MATLABSystem: '<S563>/Read Parameter'
  if (F550_FaultInjection_DW.obj_k.SampleTime !=
      F550_FaultInjection_P.ReadParameter_SampleTime_d) {
    F550_FaultInjection_DW.obj_k.SampleTime =
      F550_FaultInjection_P.ReadParameter_SampleTime_d;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_d);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_d = 0;
  }

  // MATLABSystem: '<S584>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_e.orbMetadataObj,
     &F550_FaultInjection_DW.obj_e.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S584>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S585>/Enable'

  // Start for MATLABSystem: '<S584>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S585>/In1'
    F550_FaultInjection_B.In1 = F550_FaultInjection_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S584>/Enabled Subsystem'

  // MATLABSystem: '<S582>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_kz.orbMetadataObj,
     &F550_FaultInjection_DW.obj_kz.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S582>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S597>/Enable'

  // Start for MATLABSystem: '<S582>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S597>/In1'
    F550_FaultInjection_B.In1_p = F550_FaultInjection_B.b_varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S582>/Enabled Subsystem'

  // MATLABSystem: '<S581>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_gf.orbMetadataObj,
     &F550_FaultInjection_DW.obj_gf.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_g1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S581>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S596>/Enable'

  // Start for MATLABSystem: '<S581>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S596>/In1'
    F550_FaultInjection_B.In1_f = F550_FaultInjection_B.b_varargout_2_g1;
  }

  // End of Outputs for SubSystem: '<S581>/Enabled Subsystem'

  // MATLABSystem: '<S563>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S563>/Read Parameter'
  //   SignalConversion generated from: '<S596>/In1'
  //
  F550_FaultInjection_B.MatrixConcatenate1_k[0] = 0.0;
  F550_FaultInjection_B.MatrixConcatenate1[0] = 0.0;
  F550_FaultInjection_B.b_varargout_3[0] = 0.0;
  F550_FaultInjection_B.MatrixConcatenate1_k[1] = 0.0;
  F550_FaultInjection_B.MatrixConcatenate1[1] = 0.0;
  F550_FaultInjection_B.b_varargout_3[1] = 0.0;
  F550_FaultInjection_B.MatrixConcatenate1_k[2] = 0.0;
  F550_FaultInjection_B.MatrixConcatenate1[2] = 0.0;
  F550_FaultInjection_B.b_varargout_3[2] = 0.0;
  F550_FaultInjection_B.lla0[0] = F550_FaultInjection_B.In1_f.lat;
  F550_FaultInjection_B.lla0[1] = F550_FaultInjection_B.In1_f.lon;
  F550_FaultInjection_B.lla0[2] = F550_FaultInjection_B.In1_f.alt;
  if (F550_FaultInjection_B.In1_p.previous.valid &&
      (!F550_FaultInjection_DW.obj_mr.previousValidReceived)) {
    F550_FaultInjection_DW.obj_mr.previousValidReceived = true;
  }

  if (F550_FaultInjection_B.In1_p.next.valid &&
      (!F550_FaultInjection_DW.obj_mr.nextValidReceived)) {
    F550_FaultInjection_DW.obj_mr.nextValidReceived = true;
  }

  if (F550_FaultInjection_B.In1_f.valid_hpos &&
      F550_FaultInjection_B.In1_p.current.valid &&
      (F550_FaultInjection_B.In1_p.current.type != 5)) {
    if (F550_FaultInjection_B.ParamStep_d != 0) {
      F550_FaultInjection_B.MatrixConcatenate1[0] =
        F550_FaultInjection_B.In1.waypoints[0].position[0];
      F550_FaultInjection_B.MatrixConcatenate1[1] =
        F550_FaultInjection_B.In1.waypoints[0].position[1];
      F550_FaultInjection_B.MatrixConcatenate1[2] =
        F550_FaultInjection_B.In1.waypoints[0].position[2];
    } else {
      F550_FaultInjection_B.rtb_Reshape1_m[0] =
        F550_FaultInjection_B.In1_p.current.lat;
      F550_FaultInjection_B.rtb_Reshape1_m[1] =
        F550_FaultInjection_B.In1_p.current.lon;
      F550_FaultInjection_B.rtb_Reshape1_m[2] =
        F550_FaultInjection_B.In1_p.current.alt;
      F550_FaultInjection_lla2ned(F550_FaultInjection_B.rtb_Reshape1_m,
        F550_FaultInjection_B.lla0, F550_FaultInjection_B.MatrixConcatenate1);
    }
  }

  if (F550_FaultInjection_B.In1_f.valid_hpos &&
      (F550_FaultInjection_B.In1_p.previous.valid ||
       F550_FaultInjection_DW.obj_mr.previousValidReceived)) {
    F550_FaultInjection_B.rtb_Reshape1_m[0] =
      F550_FaultInjection_B.In1_p.previous.lat;
    F550_FaultInjection_B.rtb_Reshape1_m[1] =
      F550_FaultInjection_B.In1_p.previous.lon;
    F550_FaultInjection_B.rtb_Reshape1_m[2] =
      F550_FaultInjection_B.In1_p.previous.alt;
    F550_FaultInjection_lla2ned(F550_FaultInjection_B.rtb_Reshape1_m,
      F550_FaultInjection_B.lla0, F550_FaultInjection_B.MatrixConcatenate1_k);
  }

  if (F550_FaultInjection_B.In1_f.valid_hpos &&
      (F550_FaultInjection_B.In1_p.next.valid ||
       F550_FaultInjection_DW.obj_mr.nextValidReceived)) {
    F550_FaultInjection_B.rtb_Reshape1_m[0] =
      F550_FaultInjection_B.In1_p.next.lat;
    F550_FaultInjection_B.rtb_Reshape1_m[1] =
      F550_FaultInjection_B.In1_p.next.lon;
    F550_FaultInjection_B.rtb_Reshape1_m[2] =
      F550_FaultInjection_B.In1_p.next.alt;
    F550_FaultInjection_lla2ned(F550_FaultInjection_B.rtb_Reshape1_m,
      F550_FaultInjection_B.lla0, F550_FaultInjection_B.b_varargout_3);
  }

  // If: '<S562>/If' incorporates:
  //   Delay: '<S568>/Delay'
  //   Delay: '<S571>/Delay'
  //   Delay: '<S575>/Delay'
  //   MATLABSystem: '<S563>/LLA2LocalCoordinates'
  //
  F550_FaultInjection_B.rtPrevAction = F550_FaultInjection_DW.If_ActiveSubsystem;
  if (F550_FaultInjection_B.In1_p.current.type == 3) {
    F550_FaultInjection_B.rtAction = 0;
  } else if (F550_FaultInjection_B.In1_p.current.type == 4) {
    F550_FaultInjection_B.rtAction = 1;
  } else if (F550_FaultInjection_B.In1_p.current.type == 0) {
    F550_FaultInjection_B.rtAction = 2;
  } else {
    F550_FaultInjection_B.rtAction = 3;
  }

  F550_FaultInjection_DW.If_ActiveSubsystem = F550_FaultInjection_B.rtAction;
  switch (F550_FaultInjection_B.rtAction) {
   case 0:
    if (F550_FaultInjection_B.rtAction != F550_FaultInjection_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S562>/Take-off' incorporates:
      //   ActionPort: '<S566>/Action Port'

      // InitializeConditions for If: '<S562>/If' incorporates:
      //   Delay: '<S574>/Delay'
      //   Delay: '<S575>/Delay'

      F550_FaultInjection_DW.Delay_DSTATE_c =
        F550_FaultInjection_P.Delay_InitialCondition;
      F550_FaultInjection_DW.Delay_DSTATE_d =
        F550_FaultInjection_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S562>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S562>/Take-off' incorporates:
    //   ActionPort: '<S566>/Action Port'

    // Sum: '<S574>/Sum' incorporates:
    //   Constant: '<S574>/Rate'
    //   Delay: '<S574>/Delay'

    F550_FaultInjection_B.Sum_f = F550_FaultInjection_P.Rate_Value +
      F550_FaultInjection_DW.Delay_DSTATE_c;

    // Gain: '<S574>/Gain1'
    F550_FaultInjection_B.Gain_i = F550_FaultInjection_P.Gain1_Gain_b *
      F550_FaultInjection_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S575>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S576>/Enable'

    if (F550_FaultInjection_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S576>/yaw_In'
      F550_FaultInjection_B.yaw_In_ik =
        F550_FaultInjection_B.DataTypeConversion1[6];
    }

    // End of Outputs for SubSystem: '<S575>/Enabled Subsystem2'

    // Reshape: '<S566>/Reshape' incorporates:
    //   Delay: '<S575>/Delay'
    //   Merge: '<S562>/Merge'

    F550_FaultInjection_B.Merge[0] = F550_FaultInjection_B.MatrixConcatenate1[0];
    F550_FaultInjection_B.Merge[1] = F550_FaultInjection_B.MatrixConcatenate1[1];

    // Gain: '<S574>/Gain' incorporates:
    //   RelationalOperator: '<S574>/Relational Operator'
    //   Switch: '<S574>/Switch'

    if (!(F550_FaultInjection_B.Gain_i <= F550_FaultInjection_B.Sum_f)) {
      F550_FaultInjection_B.Gain_i = F550_FaultInjection_B.Sum_f;
    }

    // Reshape: '<S566>/Reshape' incorporates:
    //   Gain: '<S574>/Gain'
    //   Merge: '<S562>/Merge'
    //   Switch: '<S574>/Switch'

    F550_FaultInjection_B.Merge[2] = F550_FaultInjection_P.Gain_Gain_e3 *
      F550_FaultInjection_B.Gain_i;
    F550_FaultInjection_B.Merge[3] = F550_FaultInjection_B.yaw_In_ik;

    // Update for Delay: '<S574>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_c = F550_FaultInjection_B.Sum_f;

    // Update for Delay: '<S575>/Delay' incorporates:
    //   Constant: '<S575>/Constant'

    F550_FaultInjection_DW.Delay_DSTATE_d =
      F550_FaultInjection_P.Constant_Value_fo;

    // End of Outputs for SubSystem: '<S562>/Take-off'
    break;

   case 1:
    if (F550_FaultInjection_B.rtAction != F550_FaultInjection_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S562>/Land' incorporates:
      //   ActionPort: '<S565>/Action Port'

      // InitializeConditions for If: '<S562>/If' incorporates:
      //   Delay: '<S565>/Delay'
      //   Delay: '<S570>/Delay'
      //   Delay: '<S571>/Delay'

      F550_FaultInjection_DW.Delay_DSTATE_l[0] =
        F550_FaultInjection_P.Delay_InitialCondition_n;
      F550_FaultInjection_DW.Delay_DSTATE_l[1] =
        F550_FaultInjection_P.Delay_InitialCondition_n;
      F550_FaultInjection_DW.Delay_DSTATE_n =
        F550_FaultInjection_P.Delay_InitialCondition_m;
      F550_FaultInjection_DW.Delay_DSTATE_b =
        F550_FaultInjection_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S562>/Land'
    }

    // Outputs for IfAction SubSystem: '<S562>/Land' incorporates:
    //   ActionPort: '<S565>/Action Port'

    // Delay: '<S570>/Delay'
    F550_FaultInjection_B.Sum_f = F550_FaultInjection_DW.Delay_DSTATE_n;

    // Switch: '<S570>/Switch' incorporates:
    //   Delay: '<S570>/Delay'
    //   Gain: '<S570>/Gain'

    if (!(F550_FaultInjection_DW.Delay_DSTATE_n >
          F550_FaultInjection_P.Switch_Threshold_j)) {
      F550_FaultInjection_B.Sum_f = F550_FaultInjection_P.Gain_Gain_l *
        F550_FaultInjection_B.MatrixConcatenate1_k[2];
    }

    // End of Switch: '<S570>/Switch'

    // Sum: '<S570>/Subtract' incorporates:
    //   Constant: '<S570>/Rate of descent'

    F550_FaultInjection_B.Gain_i = F550_FaultInjection_B.Sum_f -
      F550_FaultInjection_P.Rateofdescent_Value;

    // Gain: '<S570>/Gain2'
    F550_FaultInjection_B.Sum_f = F550_FaultInjection_P.Gain2_Gain_g *
      F550_FaultInjection_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S571>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S573>/Enable'

    if (F550_FaultInjection_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S573>/yaw_In'
      F550_FaultInjection_B.yaw_In_i =
        F550_FaultInjection_B.DataTypeConversion1[6];
    }

    // End of Outputs for SubSystem: '<S571>/Enabled Subsystem2'

    // Switch: '<S565>/Switch' incorporates:
    //   Delay: '<S571>/Delay'
    //   Logic: '<S565>/OR'
    //   RelationalOperator: '<S565>/IsNaN'

    if (rtIsNaN(F550_FaultInjection_B.MatrixConcatenate1[0]) || rtIsNaN
        (F550_FaultInjection_B.MatrixConcatenate1[1])) {
      // Reshape: '<S565>/Reshape' incorporates:
      //   Delay: '<S565>/Delay'
      //   Merge: '<S562>/Merge'

      F550_FaultInjection_B.Merge[0] = F550_FaultInjection_DW.Delay_DSTATE_l[0];
      F550_FaultInjection_B.Merge[1] = F550_FaultInjection_DW.Delay_DSTATE_l[1];
    } else {
      // Reshape: '<S565>/Reshape' incorporates:
      //   Delay: '<S565>/Delay'
      //   Merge: '<S562>/Merge'

      F550_FaultInjection_B.Merge[0] = F550_FaultInjection_B.MatrixConcatenate1
        [0];
      F550_FaultInjection_B.Merge[1] = F550_FaultInjection_B.MatrixConcatenate1
        [1];
    }

    // End of Switch: '<S565>/Switch'

    // Reshape: '<S565>/Reshape' incorporates:
    //   Gain: '<S570>/Gain1'
    //   Merge: '<S562>/Merge'
    //   RelationalOperator: '<S570>/GreaterThan'
    //   Switch: '<S570>/Switch1'

    if (!(F550_FaultInjection_B.Sum_f > F550_FaultInjection_B.Gain_i)) {
      F550_FaultInjection_B.Sum_f = F550_FaultInjection_B.Gain_i;
    }

    F550_FaultInjection_B.Merge[2] = F550_FaultInjection_P.Gain1_Gain_a *
      F550_FaultInjection_B.Sum_f;
    F550_FaultInjection_B.Merge[3] = F550_FaultInjection_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S570>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S572>/Enable'

    if (F550_FaultInjection_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S572>/In'
      F550_FaultInjection_B.In = F550_FaultInjection_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S570>/Enabled Subsystem'

    // Update for Delay: '<S565>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_l[0] =
      F550_FaultInjection_B.DataTypeConversion1[0];
    F550_FaultInjection_DW.Delay_DSTATE_l[1] =
      F550_FaultInjection_B.DataTypeConversion1[1];

    // Update for Delay: '<S570>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_n = F550_FaultInjection_B.In;

    // Update for Delay: '<S571>/Delay' incorporates:
    //   Constant: '<S571>/Constant'

    F550_FaultInjection_DW.Delay_DSTATE_b =
      F550_FaultInjection_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S562>/Land'
    break;

   case 2:
    if (F550_FaultInjection_B.rtAction != F550_FaultInjection_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S562>/Waypoint' incorporates:
      //   ActionPort: '<S567>/Action Port'

      // SystemReset for If: '<S562>/If' incorporates:
      //   MATLABSystem: '<S567>/UAV Waypoint Follower'
      //
      F550_FaultInjection_DW.obj.WaypointIndex = 1.0;
      for (F550_FaultInjection_B.i1_l = 0; F550_FaultInjection_B.i1_l < 9;
           F550_FaultInjection_B.i1_l++) {
        F550_FaultInjection_DW.obj.WaypointsInternal[F550_FaultInjection_B.i1_l]
          *= 0.0;
      }

      // End of SystemReset for If: '<S562>/If'
      // End of SystemReset for SubSystem: '<S562>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S562>/Waypoint' incorporates:
    //   ActionPort: '<S567>/Action Port'

    // Concatenate: '<S567>/Matrix Concatenate'
    F550_FaultInjection_B.MatrixConcatenate_p[0] =
      F550_FaultInjection_B.MatrixConcatenate1_k[0];
    F550_FaultInjection_B.MatrixConcatenate_p[1] =
      F550_FaultInjection_B.MatrixConcatenate1[0];
    F550_FaultInjection_B.MatrixConcatenate_p[2] =
      F550_FaultInjection_B.b_varargout_3[0];
    F550_FaultInjection_B.MatrixConcatenate_p[3] =
      F550_FaultInjection_B.MatrixConcatenate1_k[1];
    F550_FaultInjection_B.MatrixConcatenate_p[4] =
      F550_FaultInjection_B.MatrixConcatenate1[1];
    F550_FaultInjection_B.MatrixConcatenate_p[5] =
      F550_FaultInjection_B.b_varargout_3[1];
    F550_FaultInjection_B.MatrixConcatenate_p[6] =
      F550_FaultInjection_B.MatrixConcatenate1_k[2];
    F550_FaultInjection_B.MatrixConcatenate_p[7] =
      F550_FaultInjection_B.MatrixConcatenate1[2];
    F550_FaultInjection_B.MatrixConcatenate_p[8] =
      F550_FaultInjection_B.b_varargout_3[2];

    // MATLABSystem: '<S567>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S567>/Matrix Concatenate'
    //   Constant: '<S567>/Constant'

    F550_FaultInjection_B.Sum_f = F550_FaultInjection_P.Constant_Value_gw;
    F550_FaultInjection_DW.obj.LookaheadDistFlag = 0U;
    if (F550_FaultInjection_P.Constant_Value_gw < 0.3) {
      F550_FaultInjection_B.Sum_f = 0.3;
      F550_FaultInjection_DW.obj.LookaheadDistFlag = 1U;
    }

    F550_FaultInjection_DW.obj.InitialPose[0] = 0.0;
    F550_FaultInjection_DW.obj.InitialPose[1] = 0.0;
    F550_FaultInjection_DW.obj.InitialPose[2] = 0.0;
    F550_FaultInjection_DW.obj.InitialPose[3] = 0.0;
    F550_FaultInjection_DW.obj.NumWaypoints = 3.0;
    F550_FaultInjection_B.OR_g = false;
    F550_FaultInjection_B.Compare = true;
    F550_FaultInjection_B.iy = 0;
    exitg1 = false;
    while ((!exitg1) && (F550_FaultInjection_B.iy <= 8)) {
      F550_FaultInjection_B.i1_l = F550_FaultInjection_B.iy / 3 * 3 +
        F550_FaultInjection_B.iy % 3;
      if (!(F550_FaultInjection_DW.obj.WaypointsInternal[F550_FaultInjection_B.i1_l]
            ==
            F550_FaultInjection_B.MatrixConcatenate_p[F550_FaultInjection_B.i1_l]))
      {
        F550_FaultInjection_B.Compare = false;
        exitg1 = true;
      } else {
        F550_FaultInjection_B.iy++;
      }
    }

    if (F550_FaultInjection_B.Compare) {
      F550_FaultInjection_B.OR_g = true;
    }

    if (!F550_FaultInjection_B.OR_g) {
      memcpy(&F550_FaultInjection_DW.obj.WaypointsInternal[0],
             &F550_FaultInjection_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      F550_FaultInjection_DW.obj.WaypointIndex = 1.0;
    }

    F550_FaultInjection_B.i1_l = 0;
    F550_FaultInjection_B.iy = 0;
    for (F550_FaultInjection_B.j = 0; F550_FaultInjection_B.j < 3;
         F550_FaultInjection_B.j++) {
      F550_FaultInjection_B.distinctWptsIdx[F550_FaultInjection_B.j] = true;
      F550_FaultInjection_B.Gain_i =
        F550_FaultInjection_B.MatrixConcatenate_p[F550_FaultInjection_B.i1_l + 1];
      F550_FaultInjection_B.x[F550_FaultInjection_B.iy] =
        (F550_FaultInjection_B.Gain_i !=
         F550_FaultInjection_B.MatrixConcatenate_p[F550_FaultInjection_B.i1_l]);
      F550_FaultInjection_B.x[F550_FaultInjection_B.iy + 1] =
        (F550_FaultInjection_B.MatrixConcatenate_p[F550_FaultInjection_B.i1_l +
         2] != F550_FaultInjection_B.Gain_i);
      F550_FaultInjection_B.i1_l += 3;
      F550_FaultInjection_B.iy += 2;
    }

    F550_FaultInjection_B.IsNaN_l[0] = false;
    F550_FaultInjection_B.IsNaN_l[1] = false;
    F550_FaultInjection_B.i1_l = 0;
    F550_FaultInjection_B.iy = 4;
    for (F550_FaultInjection_B.j = 0; F550_FaultInjection_B.j < 2;
         F550_FaultInjection_B.j++) {
      F550_FaultInjection_B.i1_l++;
      F550_FaultInjection_B.iy++;
      F550_FaultInjection_B.ix = F550_FaultInjection_B.i1_l;
      exitg1 = false;
      while ((!exitg1) && (F550_FaultInjection_B.ix <= F550_FaultInjection_B.iy))
      {
        if (F550_FaultInjection_B.x[F550_FaultInjection_B.ix - 1]) {
          F550_FaultInjection_B.IsNaN_l[F550_FaultInjection_B.j] = true;
          exitg1 = true;
        } else {
          F550_FaultInjection_B.ix += 2;
        }
      }
    }

    F550_FaultInjection_B.distinctWptsIdx[0] = F550_FaultInjection_B.IsNaN_l[0];
    F550_FaultInjection_B.distinctWptsIdx[1] = F550_FaultInjection_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S562>/Waypoint'
    F550_FaultInjection_B.iy = 0;
    for (F550_FaultInjection_B.i1_l = 0; F550_FaultInjection_B.i1_l < 3;
         F550_FaultInjection_B.i1_l++) {
      // Outputs for IfAction SubSystem: '<S562>/Waypoint' incorporates:
      //   ActionPort: '<S567>/Action Port'

      if (F550_FaultInjection_B.distinctWptsIdx[F550_FaultInjection_B.i1_l]) {
        F550_FaultInjection_B.iy++;
      }

      // End of Outputs for SubSystem: '<S562>/Waypoint'
    }

    F550_FaultInjection_B.j = F550_FaultInjection_B.iy;
    F550_FaultInjection_B.iy = 0;
    for (F550_FaultInjection_B.i1_l = 0; F550_FaultInjection_B.i1_l < 3;
         F550_FaultInjection_B.i1_l++) {
      // Outputs for IfAction SubSystem: '<S562>/Waypoint' incorporates:
      //   ActionPort: '<S567>/Action Port'

      if (F550_FaultInjection_B.distinctWptsIdx[F550_FaultInjection_B.i1_l]) {
        // Start for MATLABSystem: '<S567>/UAV Waypoint Follower'
        F550_FaultInjection_B.tmp_data[F550_FaultInjection_B.iy] = static_cast<
          int8_T>(F550_FaultInjection_B.i1_l);
        F550_FaultInjection_B.iy++;
      }

      // End of Outputs for SubSystem: '<S562>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S562>/Waypoint' incorporates:
    //   ActionPort: '<S567>/Action Port'

    // MATLABSystem: '<S567>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S567>/Matrix Concatenate'
    //   Reshape: '<S567>/Reshape1'

    for (F550_FaultInjection_B.i1_l = 0; F550_FaultInjection_B.i1_l < 3;
         F550_FaultInjection_B.i1_l++) {
      for (F550_FaultInjection_B.iy = 0; F550_FaultInjection_B.iy <
           F550_FaultInjection_B.j; F550_FaultInjection_B.iy++) {
        F550_FaultInjection_B.b_waypointsIn_data[F550_FaultInjection_B.iy +
          F550_FaultInjection_B.j * F550_FaultInjection_B.i1_l] =
          F550_FaultInjection_B.MatrixConcatenate_p[3 *
          F550_FaultInjection_B.i1_l +
          F550_FaultInjection_B.tmp_data[F550_FaultInjection_B.iy]];
      }
    }

    F550_FaultInjection_DW.obj.LookaheadDistance = F550_FaultInjection_B.Sum_f;
    if (F550_FaultInjection_B.j == 0) {
      F550_FaultInjection_B.lla0[0] = F550_FaultInjection_B.DataTypeConversion1
        [0];
      F550_FaultInjection_B.lla0[1] = F550_FaultInjection_B.DataTypeConversion1
        [1];
      F550_FaultInjection_B.lla0[2] = F550_FaultInjection_B.DataTypeConversion1
        [2];
      F550_FaultInjection_B.Sum_f = F550_FaultInjection_B.DataTypeConversion1[6];
    } else {
      guard1 = false;
      if (F550_FaultInjection_B.j == 1) {
        if (F550_FaultInjection_DW.obj.StartFlag) {
          F550_FaultInjection_DW.obj.InitialPose[0] =
            F550_FaultInjection_B.DataTypeConversion1[0];
          F550_FaultInjection_DW.obj.InitialPose[1] =
            F550_FaultInjection_B.DataTypeConversion1[1];
          F550_FaultInjection_DW.obj.InitialPose[2] =
            F550_FaultInjection_B.DataTypeConversion1[2];
          F550_FaultInjection_DW.obj.InitialPose[3] =
            F550_FaultInjection_B.DataTypeConversion1[6];
        }

        F550_FaultInjection_B.b_varargout_3[0] =
          F550_FaultInjection_B.b_waypointsIn_data[0] -
          F550_FaultInjection_B.DataTypeConversion1[0];
        F550_FaultInjection_B.b_varargout_3[1] =
          F550_FaultInjection_B.b_waypointsIn_data[1] -
          F550_FaultInjection_B.DataTypeConversion1[1];
        F550_FaultInjection_B.b_varargout_3[2] =
          F550_FaultInjection_B.b_waypointsIn_data[2] -
          F550_FaultInjection_B.DataTypeConversion1[2];
        if (F550_FaultInjection_norm(F550_FaultInjection_B.b_varargout_3) <
            1.4901161193847656E-8) {
          F550_FaultInjection_B.lla0[0] =
            F550_FaultInjection_B.DataTypeConversion1[0];
          F550_FaultInjection_B.lla0[1] =
            F550_FaultInjection_B.DataTypeConversion1[1];
          F550_FaultInjection_B.lla0[2] =
            F550_FaultInjection_B.DataTypeConversion1[2];
          F550_FaultInjection_B.Sum_f =
            F550_FaultInjection_B.DataTypeConversion1[6];
          F550_FaultInjection_DW.obj.StartFlag = false;
        } else {
          F550_FaultInjection_DW.obj.StartFlag = false;
          F550_FaultInjection_DW.obj.NumWaypoints = 2.0;
          F550_FaultInjection_B.ix = F550_FaultInjection_B.j + 1;
          for (F550_FaultInjection_B.i1_l = 0; F550_FaultInjection_B.i1_l < 3;
               F550_FaultInjection_B.i1_l++) {
            F550_FaultInjection_B.waypoints_data_tmp = (F550_FaultInjection_B.j
              + 1) * F550_FaultInjection_B.i1_l;
            F550_FaultInjection_B.MatrixConcatenate_p[F550_FaultInjection_B.waypoints_data_tmp]
              =
              F550_FaultInjection_DW.obj.InitialPose[F550_FaultInjection_B.i1_l];
            for (F550_FaultInjection_B.iy = 0; F550_FaultInjection_B.iy <
                 F550_FaultInjection_B.j; F550_FaultInjection_B.iy++) {
              F550_FaultInjection_B.MatrixConcatenate_p
                [(F550_FaultInjection_B.iy +
                  F550_FaultInjection_B.waypoints_data_tmp) + 1] =
                F550_FaultInjection_B.b_waypointsIn_data[F550_FaultInjection_B.j
                * F550_FaultInjection_B.i1_l + F550_FaultInjection_B.iy];
            }
          }

          guard1 = true;
        }
      } else {
        F550_FaultInjection_B.ix = F550_FaultInjection_B.j;
        F550_FaultInjection_B.j *= 3;
        if (F550_FaultInjection_B.j - 1 >= 0) {
          memcpy(&F550_FaultInjection_B.MatrixConcatenate_p[0],
                 &F550_FaultInjection_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(F550_FaultInjection_B.j) * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        F550_FaultInjection_B.OR_g = false;
        if (F550_FaultInjection_DW.obj.WaypointIndex ==
            F550_FaultInjection_DW.obj.NumWaypoints) {
          F550_FaultInjection_B.OR_g = true;
        }

        if (F550_FaultInjection_B.OR_g) {
          F550_FaultInjection_DW.obj.LastWaypointFlag = true;
          F550_FaultInjection_DW.obj.WaypointIndex--;
        }

        F550_FaultInjection_B.rtb_Reshape1_m[0] =
          F550_FaultInjection_B.DataTypeConversion1[0] -
          F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
          (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) - 1];
        F550_FaultInjection_B.rtb_Reshape1_m[1] =
          F550_FaultInjection_B.DataTypeConversion1[1] -
          F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
          (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
          F550_FaultInjection_B.ix) - 1];
        F550_FaultInjection_B.rtb_Reshape1_m[2] =
          F550_FaultInjection_B.DataTypeConversion1[2] -
          F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
          (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
          (F550_FaultInjection_B.ix << 1)) - 1];
        guard2 = false;
        if (F550_FaultInjection_norm(F550_FaultInjection_B.rtb_Reshape1_m) <=
            2.0) {
          guard2 = true;
        } else {
          F550_FaultInjection_B.Sum_f =
            F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) - 1];
          F550_FaultInjection_B.MatrixConcatenate1_k[0] =
            F550_FaultInjection_B.Sum_f -
            F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex) - 1];
          F550_FaultInjection_B.MatrixConcatenate1[0] =
            F550_FaultInjection_B.DataTypeConversion1[0] -
            F550_FaultInjection_B.Sum_f;
          F550_FaultInjection_B.Sum_f =
            F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
            F550_FaultInjection_B.ix) - 1];
          F550_FaultInjection_B.MatrixConcatenate1_k[1] =
            F550_FaultInjection_B.Sum_f -
            F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex) +
            F550_FaultInjection_B.ix) - 1];
          F550_FaultInjection_B.MatrixConcatenate1[1] =
            F550_FaultInjection_B.DataTypeConversion1[1] -
            F550_FaultInjection_B.Sum_f;
          F550_FaultInjection_B.Gain_i =
            F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
            (F550_FaultInjection_B.ix << 1)) - 1];
          F550_FaultInjection_B.Gain3_k =
            F550_FaultInjection_B.MatrixConcatenate_p[((F550_FaultInjection_B.ix
            << 1) + static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex)) - 1];
          F550_FaultInjection_B.MatrixConcatenate1_k[2] =
            F550_FaultInjection_B.Gain_i - F550_FaultInjection_B.Gain3_k;
          F550_FaultInjection_B.MatrixConcatenate1[2] =
            F550_FaultInjection_B.DataTypeConversion1[2] -
            F550_FaultInjection_B.Gain_i;
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
            F550_FaultInjection_norm(F550_FaultInjection_B.MatrixConcatenate1_k);
          F550_FaultInjection_B.Sum_f = F550_FaultInjection_norm
            (F550_FaultInjection_B.MatrixConcatenate1);
          F550_FaultInjection_B.Sum_f =
            (F550_FaultInjection_B.MatrixConcatenate1_k[0] /
             F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *
             (F550_FaultInjection_B.MatrixConcatenate1[0] /
              F550_FaultInjection_B.Sum_f) +
             F550_FaultInjection_B.MatrixConcatenate1_k[1] /
             F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *
             (F550_FaultInjection_B.MatrixConcatenate1[1] /
              F550_FaultInjection_B.Sum_f)) +
            F550_FaultInjection_B.MatrixConcatenate1_k[2] /
            F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *
            (F550_FaultInjection_B.MatrixConcatenate1[2] /
             F550_FaultInjection_B.Sum_f);
          if (rtIsNaN(F550_FaultInjection_B.Sum_f) ||
              (F550_FaultInjection_B.Sum_f < 0.0)) {
            F550_FaultInjection_B.MatrixConcatenate1_k[0] =
              F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
              (F550_FaultInjection_DW.obj.WaypointIndex) - 1];
            F550_FaultInjection_B.lla0[0] =
              F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
              (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) - 1];
            F550_FaultInjection_B.MatrixConcatenate1_k[1] =
              F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
              (F550_FaultInjection_DW.obj.WaypointIndex) +
              F550_FaultInjection_B.ix) - 1];
            F550_FaultInjection_B.lla0[1] =
              F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
              (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
              F550_FaultInjection_B.ix) - 1];
            F550_FaultInjection_B.MatrixConcatenate1_k[2] =
              F550_FaultInjection_B.Gain3_k;
            F550_FaultInjection_B.lla0[2] = F550_FaultInjection_B.Gain_i;
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          F550_FaultInjection_DW.obj.WaypointIndex++;
          F550_FaultInjection_B.OR_g = false;
          if (F550_FaultInjection_DW.obj.WaypointIndex ==
              F550_FaultInjection_DW.obj.NumWaypoints) {
            F550_FaultInjection_B.OR_g = true;
          }

          if (F550_FaultInjection_B.OR_g) {
            F550_FaultInjection_DW.obj.LastWaypointFlag = true;
            F550_FaultInjection_DW.obj.WaypointIndex--;
          }

          F550_FaultInjection_B.MatrixConcatenate1_k[0] =
            F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex) - 1];
          F550_FaultInjection_B.lla0[0] =
            F550_FaultInjection_B.MatrixConcatenate_p[static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) - 1];
          F550_FaultInjection_B.MatrixConcatenate1_k[1] =
            F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex) +
            F550_FaultInjection_B.ix) - 1];
          F550_FaultInjection_B.lla0[1] =
            F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
            F550_FaultInjection_B.ix) - 1];
          F550_FaultInjection_B.MatrixConcatenate1_k[2] =
            F550_FaultInjection_B.MatrixConcatenate_p[((F550_FaultInjection_B.ix
            << 1) + static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex)) - 1];
          F550_FaultInjection_B.lla0[2] =
            F550_FaultInjection_B.MatrixConcatenate_p[(static_cast<int32_T>
            (F550_FaultInjection_DW.obj.WaypointIndex + 1.0) +
            (F550_FaultInjection_B.ix << 1)) - 1];
        }

        F550_FaultInjection_B.Gain_i =
          F550_FaultInjection_B.DataTypeConversion1[0] -
          F550_FaultInjection_B.MatrixConcatenate1_k[0];
        F550_FaultInjection_B.MatrixConcatenate1[0] =
          F550_FaultInjection_B.Gain_i;
        F550_FaultInjection_B.Gain3_k = F550_FaultInjection_B.lla0[0] -
          F550_FaultInjection_B.MatrixConcatenate1_k[0];
        F550_FaultInjection_B.b_varargout_3[0] = F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.Sum_f = F550_FaultInjection_B.Gain_i *
          F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.Saturation1 = F550_FaultInjection_B.Gain3_k *
          F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.Gain2_g =
          F550_FaultInjection_B.DataTypeConversion1[1] -
          F550_FaultInjection_B.MatrixConcatenate1_k[1];
        F550_FaultInjection_B.MatrixConcatenate1[1] =
          F550_FaultInjection_B.Gain2_g;
        F550_FaultInjection_B.Gain3_k = F550_FaultInjection_B.lla0[1] -
          F550_FaultInjection_B.MatrixConcatenate1_k[1];
        F550_FaultInjection_B.b_varargout_3[1] = F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.Sum_f += F550_FaultInjection_B.Gain2_g *
          F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.Saturation1 += F550_FaultInjection_B.Gain3_k *
          F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.DataTypeConversion1[2] -
          F550_FaultInjection_B.MatrixConcatenate1_k[2];
        F550_FaultInjection_B.MatrixConcatenate1[2] =
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp;
        F550_FaultInjection_B.Gain3_k = F550_FaultInjection_B.lla0[2] -
          F550_FaultInjection_B.MatrixConcatenate1_k[2];
        F550_FaultInjection_B.Saturation1 += F550_FaultInjection_B.Gain3_k *
          F550_FaultInjection_B.Gain3_k;
        F550_FaultInjection_B.Sum_f =
          (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *
           F550_FaultInjection_B.Gain3_k + F550_FaultInjection_B.Sum_f) /
          F550_FaultInjection_B.Saturation1;
        if (F550_FaultInjection_B.Sum_f < 0.0) {
          F550_FaultInjection_B.Sum_f = F550_FaultInjection_norm
            (F550_FaultInjection_B.MatrixConcatenate1);
        } else if (F550_FaultInjection_B.Sum_f > 1.0) {
          F550_FaultInjection_B.rtb_Reshape1_m[0] =
            F550_FaultInjection_B.DataTypeConversion1[0] -
            F550_FaultInjection_B.lla0[0];
          F550_FaultInjection_B.rtb_Reshape1_m[1] =
            F550_FaultInjection_B.DataTypeConversion1[1] -
            F550_FaultInjection_B.lla0[1];
          F550_FaultInjection_B.rtb_Reshape1_m[2] =
            F550_FaultInjection_B.DataTypeConversion1[2] -
            F550_FaultInjection_B.lla0[2];
          F550_FaultInjection_B.Sum_f = F550_FaultInjection_norm
            (F550_FaultInjection_B.rtb_Reshape1_m);
        } else {
          F550_FaultInjection_B.rtb_Reshape1_m[0] =
            F550_FaultInjection_B.DataTypeConversion1[0] -
            (F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.b_varargout_3[0]
             + F550_FaultInjection_B.MatrixConcatenate1_k[0]);
          F550_FaultInjection_B.rtb_Reshape1_m[1] =
            F550_FaultInjection_B.DataTypeConversion1[1] -
            (F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.b_varargout_3[1]
             + F550_FaultInjection_B.MatrixConcatenate1_k[1]);
          F550_FaultInjection_B.rtb_Reshape1_m[2] =
            F550_FaultInjection_B.DataTypeConversion1[2] -
            (F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.Gain3_k +
             F550_FaultInjection_B.MatrixConcatenate1_k[2]);
          F550_FaultInjection_B.Sum_f = F550_FaultInjection_norm
            (F550_FaultInjection_B.rtb_Reshape1_m);
        }

        if (F550_FaultInjection_DW.obj.LastWaypointFlag) {
          F550_FaultInjection_B.Sum_f = ((F550_FaultInjection_B.Gain_i *
            F550_FaultInjection_B.b_varargout_3[0] +
            F550_FaultInjection_B.Gain2_g * F550_FaultInjection_B.b_varargout_3
            [1]) + (F550_FaultInjection_B.DataTypeConversion1[2] -
                    F550_FaultInjection_B.MatrixConcatenate1_k[2]) *
            F550_FaultInjection_B.Gain3_k) / F550_FaultInjection_B.Saturation1;
          F550_FaultInjection_B.rtb_Reshape1_m[0] =
            F550_FaultInjection_B.DataTypeConversion1[0] -
            (F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.b_varargout_3[0]
             + F550_FaultInjection_B.MatrixConcatenate1_k[0]);
          F550_FaultInjection_B.rtb_Reshape1_m[1] =
            F550_FaultInjection_B.DataTypeConversion1[1] -
            (F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.b_varargout_3[1]
             + F550_FaultInjection_B.MatrixConcatenate1_k[1]);
          F550_FaultInjection_B.rtb_Reshape1_m[2] =
            F550_FaultInjection_B.DataTypeConversion1[2] -
            (F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.Gain3_k +
             F550_FaultInjection_B.MatrixConcatenate1_k[2]);
          F550_FaultInjection_B.Sum_f = F550_FaultInjection_norm
            (F550_FaultInjection_B.rtb_Reshape1_m);
        }

        F550_FaultInjection_B.Gain_i = fabs(F550_FaultInjection_B.Sum_f);
        if (rtIsInf(F550_FaultInjection_B.Gain_i) || rtIsNaN
            (F550_FaultInjection_B.Gain_i)) {
          F550_FaultInjection_B.Gain2_g = (rtNaN);
          F550_FaultInjection_B.Gain_i = (rtNaN);
        } else if (F550_FaultInjection_B.Gain_i < 4.4501477170144028E-308) {
          F550_FaultInjection_B.Gain2_g = 4.94065645841247E-324;
          F550_FaultInjection_B.Gain_i = 4.94065645841247E-324;
        } else {
          frexp(F550_FaultInjection_B.Gain_i, &F550_FaultInjection_B.ParamStep_g);
          F550_FaultInjection_B.Gain2_g = ldexp(1.0,
            F550_FaultInjection_B.ParamStep_g - 53);
          frexp(F550_FaultInjection_B.Gain_i, &F550_FaultInjection_B.b_exponent);
          F550_FaultInjection_B.Gain_i = ldexp(1.0,
            F550_FaultInjection_B.b_exponent - 53);
        }

        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = sqrt
          (F550_FaultInjection_B.Gain2_g);
        F550_FaultInjection_B.Gain_i *= 5.0;
        if ((F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >=
             F550_FaultInjection_B.Gain_i) || rtIsNaN
            (F550_FaultInjection_B.Gain_i)) {
          F550_FaultInjection_B.Gain_i =
            F550_FaultInjection_B.rtb_MatrixConcatenate1_pp;
        }

        if (F550_FaultInjection_DW.obj.LookaheadDistance <=
            F550_FaultInjection_B.Sum_f + F550_FaultInjection_B.Gain_i) {
          F550_FaultInjection_DW.obj.LookaheadDistance =
            F550_FaultInjection_DW.obj.LookaheadFactor *
            F550_FaultInjection_B.Sum_f;
        }

        F550_FaultInjection_B.MatrixConcatenate1[0] =
          F550_FaultInjection_B.MatrixConcatenate1_k[0] -
          F550_FaultInjection_B.DataTypeConversion1[0];
        F550_FaultInjection_B.MatrixConcatenate1[1] =
          F550_FaultInjection_B.MatrixConcatenate1_k[1] -
          F550_FaultInjection_B.DataTypeConversion1[1];
        F550_FaultInjection_B.MatrixConcatenate1[2] =
          F550_FaultInjection_B.MatrixConcatenate1_k[2] -
          F550_FaultInjection_B.DataTypeConversion1[2];
        F550_FaultInjection_B.Gain_i = ((F550_FaultInjection_B.b_varargout_3[0] *
          F550_FaultInjection_B.MatrixConcatenate1[0] +
          F550_FaultInjection_B.b_varargout_3[1] *
          F550_FaultInjection_B.MatrixConcatenate1[1]) +
          F550_FaultInjection_B.Gain3_k *
          F550_FaultInjection_B.MatrixConcatenate1[2]) * 2.0;
        F550_FaultInjection_B.Gain2_g = sqrt(F550_FaultInjection_B.Gain_i *
          F550_FaultInjection_B.Gain_i -
          (((F550_FaultInjection_B.MatrixConcatenate1[0] *
             F550_FaultInjection_B.MatrixConcatenate1[0] +
             F550_FaultInjection_B.MatrixConcatenate1[1] *
             F550_FaultInjection_B.MatrixConcatenate1[1]) +
            F550_FaultInjection_B.MatrixConcatenate1[2] *
            F550_FaultInjection_B.MatrixConcatenate1[2]) -
           F550_FaultInjection_DW.obj.LookaheadDistance *
           F550_FaultInjection_DW.obj.LookaheadDistance) * (4.0 *
          F550_FaultInjection_B.Saturation1));
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          (-F550_FaultInjection_B.Gain_i + F550_FaultInjection_B.Gain2_g) / 2.0 /
          F550_FaultInjection_B.Saturation1;
        F550_FaultInjection_B.Sum_f = (-F550_FaultInjection_B.Gain_i -
          F550_FaultInjection_B.Gain2_g) / 2.0 /
          F550_FaultInjection_B.Saturation1;
        if ((F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >=
             F550_FaultInjection_B.Sum_f) || rtIsNaN(F550_FaultInjection_B.Sum_f))
        {
          F550_FaultInjection_B.Sum_f =
            F550_FaultInjection_B.rtb_MatrixConcatenate1_pp;
        }

        F550_FaultInjection_B.lla0[0] = (1.0 - F550_FaultInjection_B.Sum_f) *
          F550_FaultInjection_B.MatrixConcatenate1_k[0] +
          F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.lla0[0];
        F550_FaultInjection_B.lla0[1] = (1.0 - F550_FaultInjection_B.Sum_f) *
          F550_FaultInjection_B.MatrixConcatenate1_k[1] +
          F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.lla0[1];
        F550_FaultInjection_B.lla0[2] = (1.0 - F550_FaultInjection_B.Sum_f) *
          F550_FaultInjection_B.MatrixConcatenate1_k[2] +
          F550_FaultInjection_B.Sum_f * F550_FaultInjection_B.lla0[2];
        F550_FaultInjection_B.Sum_f = F550_FaultInjection_rt_atan2d_snf_d
          (F550_FaultInjection_B.lla0[1] -
           F550_FaultInjection_B.DataTypeConversion1[1],
           F550_FaultInjection_B.lla0[0] -
           F550_FaultInjection_B.DataTypeConversion1[0]);
        F550_FaultInjection_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S577>/Switch1' incorporates:
    //   Constant: '<S578>/Constant'
    //   Logic: '<S577>/OR'
    //   Logic: '<S577>/OR1'
    //   MATLABSystem: '<S567>/UAV Waypoint Follower'
    //   Merge: '<S562>/Merge'
    //   RelationalOperator: '<S577>/IsNaN'
    //   RelationalOperator: '<S577>/IsNaN1'
    //   RelationalOperator: '<S578>/Compare'
    //   Reshape: '<S577>/Reshape3'
    //   Switch: '<S577>/Switch'
    //
    if (rtIsNaN(F550_FaultInjection_B.lla0[0]) || rtIsNaN
        (F550_FaultInjection_B.lla0[1]) || rtIsNaN(F550_FaultInjection_B.lla0[2])
        || (F550_FaultInjection_B.In1_p.current.type ==
            F550_FaultInjection_P.CompareToConstant_const_d)) {
      F550_FaultInjection_B.Merge[0] =
        F550_FaultInjection_B.DataTypeConversion1[0];
      F550_FaultInjection_B.Merge[1] =
        F550_FaultInjection_B.DataTypeConversion1[1];
      F550_FaultInjection_B.Merge[2] =
        F550_FaultInjection_B.DataTypeConversion1[2];
      F550_FaultInjection_B.Merge[3] =
        F550_FaultInjection_B.DataTypeConversion1[6];
    } else {
      if (rtIsNaN(F550_FaultInjection_B.Sum_f)) {
        // Switch: '<S577>/Switch' incorporates:
        //   Constant: '<S577>/Constant'
        //   Merge: '<S562>/Merge'
        //   Reshape: '<S577>/Reshape2'

        F550_FaultInjection_B.Merge[3] = F550_FaultInjection_P.Constant_Value_jd;
      } else {
        // Reshape: '<S577>/Reshape2' incorporates:
        //   Merge: '<S562>/Merge'
        //   Switch: '<S577>/Switch'

        F550_FaultInjection_B.Merge[3] = F550_FaultInjection_B.Sum_f;
      }

      // Math: '<S577>/Transpose1' incorporates:
      //   Merge: '<S562>/Merge'

      F550_FaultInjection_B.Merge[0] = F550_FaultInjection_B.lla0[0];
      F550_FaultInjection_B.Merge[1] = F550_FaultInjection_B.lla0[1];
      F550_FaultInjection_B.Merge[2] = F550_FaultInjection_B.lla0[2];
    }

    // End of Switch: '<S577>/Switch1'
    // End of Outputs for SubSystem: '<S562>/Waypoint'
    break;

   default:
    if (F550_FaultInjection_B.rtAction != F550_FaultInjection_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S562>/IDLE' incorporates:
      //   ActionPort: '<S564>/Action Port'

      // InitializeConditions for If: '<S562>/If' incorporates:
      //   Delay: '<S568>/Delay'

      F550_FaultInjection_DW.Delay_DSTATE =
        F550_FaultInjection_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S562>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S562>/IDLE' incorporates:
    //   ActionPort: '<S564>/Action Port'

    // Outputs for Enabled SubSystem: '<S568>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S569>/Enable'

    if (F550_FaultInjection_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S569>/yaw_In'
      F550_FaultInjection_B.yaw_In = F550_FaultInjection_B.DataTypeConversion1[6];
    }

    // End of Outputs for SubSystem: '<S568>/Enabled Subsystem2'

    // Reshape: '<S564>/Reshape1' incorporates:
    //   Delay: '<S568>/Delay'
    //   Merge: '<S562>/Merge'

    F550_FaultInjection_B.Merge[0] = F550_FaultInjection_B.DataTypeConversion1[0];
    F550_FaultInjection_B.Merge[1] = F550_FaultInjection_B.DataTypeConversion1[1];
    F550_FaultInjection_B.Merge[2] = F550_FaultInjection_B.DataTypeConversion1[2];
    F550_FaultInjection_B.Merge[3] = F550_FaultInjection_B.yaw_In;

    // Update for Delay: '<S568>/Delay' incorporates:
    //   Constant: '<S568>/Constant'

    F550_FaultInjection_DW.Delay_DSTATE =
      F550_FaultInjection_P.Constant_Value_ic;

    // End of Outputs for SubSystem: '<S562>/IDLE'
    break;
  }

  // End of If: '<S562>/If'

  // MATLABSystem: '<S602>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_gv.orbMetadataObj,
     &F550_FaultInjection_DW.obj_gv.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_g, false, 1.0);

  // Outputs for Enabled SubSystem: '<S602>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S606>/Enable'

  // Start for MATLABSystem: '<S602>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S606>/In1'
    F550_FaultInjection_B.In1_m = F550_FaultInjection_B.b_varargout_2_g;
  }

  // End of Outputs for SubSystem: '<S602>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion'
  F550_FaultInjection_B.DataTypeConversion[0] = F550_FaultInjection_B.In1_m.q[0];
  F550_FaultInjection_B.DataTypeConversion[1] = F550_FaultInjection_B.In1_m.q[1];
  F550_FaultInjection_B.DataTypeConversion[2] = F550_FaultInjection_B.In1_m.q[2];
  F550_FaultInjection_B.DataTypeConversion[3] = F550_FaultInjection_B.In1_m.q[3];

  // MATLABSystem: '<S600>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_po.orbMetadataObj,
     &F550_FaultInjection_DW.obj_po.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S600>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S604>/Enable'

  // Start for MATLABSystem: '<S600>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S604>/In1'
    F550_FaultInjection_B.In1_l = F550_FaultInjection_B.b_varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S600>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion2'
  F550_FaultInjection_B.DataTypeConversion2[0] =
    F550_FaultInjection_B.In1_l.rollspeed;
  F550_FaultInjection_B.DataTypeConversion2[1] =
    F550_FaultInjection_B.In1_l.pitchspeed;
  F550_FaultInjection_B.DataTypeConversion2[2] =
    F550_FaultInjection_B.In1_l.yawspeed;

  // MATLABSystem: '<S601>/SourceBlock'
  F550_FaultInjection_B.OR_g = uORB_read_step
    (F550_FaultInjection_DW.obj_d0.orbMetadataObj,
     &F550_FaultInjection_DW.obj_d0.eventStructObj,
     &F550_FaultInjection_B.b_varargout_2_n, false, 1.0);

  // Outputs for Enabled SubSystem: '<S601>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S605>/Enable'

  // Start for MATLABSystem: '<S601>/SourceBlock'
  if (F550_FaultInjection_B.OR_g) {
    // SignalConversion generated from: '<S605>/In1'
    F550_FaultInjection_B.In1_b = F550_FaultInjection_B.b_varargout_2_n;
  }

  // End of Outputs for SubSystem: '<S601>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/CLAW'
  F550_FaultInjection_CLAW();

  // End of Outputs for SubSystem: '<Root>/CLAW'

  // Gain: '<S5>/Gain'
  F550_FaultInjection_B.Sum_f = F550_FaultInjection_P.Gain_Gain_jo *
    F550_FaultInjection_B.Saturation;

  // Gain: '<S5>/Gain1'
  F550_FaultInjection_B.Gain_i = F550_FaultInjection_P.Gain1_Gain_j0 *
    F550_FaultInjection_B.Saturation_o;

  // Gain: '<S5>/Gain2'
  F550_FaultInjection_B.Gain2_g = F550_FaultInjection_P.Gain2_Gain_f *
    F550_FaultInjection_B.Saturation_k;

  // Gain: '<S5>/Gain3'
  F550_FaultInjection_B.Gain3_k = F550_FaultInjection_P.Gain3_Gain_c *
    F550_FaultInjection_B.Merge_n[0];

  // MATLABSystem: '<S7>/Read Parameter13'
  if (F550_FaultInjection_DW.obj_ka.SampleTime !=
      F550_FaultInjection_P.ReadParameter13_SampleTime) {
    F550_FaultInjection_DW.obj_ka.SampleTime =
      F550_FaultInjection_P.ReadParameter13_SampleTime;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_ka.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_g);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_g = 0;
  }

  // RelationalOperator: '<S18>/Compare' incorporates:
  //   Constant: '<S18>/Constant'

  F550_FaultInjection_B.Compare = (F550_FaultInjection_B.In1_k.values[7] >=
    F550_FaultInjection_P.CompareToConstant_const_k);

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

  if (F550_FaultInjection_B.Compare_k) {
    F550_FaultInjection_B.Saturation1 = F550_FaultInjection_P.Constant_Value_o;
  } else {
    if (F550_FaultInjection_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch' incorporates:
      //   Constant: '<S7>/Fault'
      //   DataTypeConversion: '<S7>/Data Type Conversion3'
      //   MATLABSystem: '<S7>/Read Parameter13'
      //   Switch: '<S7>/Switch'
      //
      if (F550_FaultInjection_P.ManualSwitch_CurrentSetting == 1) {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_P.Fault_Value;
      } else {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.ParamStep_g;
      }

      // End of ManualSwitch: '<S7>/Manual Switch'
    } else {
      // Switch: '<S7>/Switch' incorporates:
      //   Constant: '<S7>/Constant'

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Constant_Value_d3;
    }

    // Gain: '<S12>/Gain' incorporates:
    //   Switch: '<S7>/Switch'

    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *=
      F550_FaultInjection_P.Gain_Gain_c;

    // Saturate: '<S12>/Saturation1'
    if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >
        F550_FaultInjection_P.Saturation1_UpperSat_g) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_UpperSat_g;
    } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp <
               F550_FaultInjection_P.Saturation1_LowerSat_c) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_LowerSat_c;
    }

    F550_FaultInjection_B.Saturation1 = ((((-F550_FaultInjection_B.Sum_f -
      F550_FaultInjection_B.Gain2_g) * F550_FaultInjection_B.Gain3_k / 3.0 +
      F550_FaultInjection_B.Gain3_k) * 1000.0 + 1000.0) -
      F550_FaultInjection_P.IDLEPWM_Value_h) *
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
      F550_FaultInjection_P.Constant_Value_h;
  }

  // End of Switch: '<S6>/Switch'

  // MATLABSystem: '<S7>/Read Parameter1'
  if (F550_FaultInjection_DW.obj_a4.SampleTime !=
      F550_FaultInjection_P.ReadParameter1_SampleTime) {
    F550_FaultInjection_DW.obj_a4.SampleTime =
      F550_FaultInjection_P.ReadParameter1_SampleTime;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_a4.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_g);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_g = 0;
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

  if (F550_FaultInjection_B.Compare_k) {
    F550_FaultInjection_B.Saturation1_f = F550_FaultInjection_P.Constant1_Value;
  } else {
    if (F550_FaultInjection_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch1' incorporates:
      //   Constant: '<S7>/Fault1'
      //   DataTypeConversion: '<S7>/Data Type Conversion2'
      //   MATLABSystem: '<S7>/Read Parameter1'
      //   Switch: '<S7>/Switch1'
      //
      if (F550_FaultInjection_P.ManualSwitch1_CurrentSetting == 1) {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_P.Fault1_Value;
      } else {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.ParamStep_g;
      }

      // End of ManualSwitch: '<S7>/Manual Switch1'
    } else {
      // Switch: '<S7>/Switch1' incorporates:
      //   Constant: '<S7>/Constant1'

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Constant1_Value_j;
    }

    // Gain: '<S13>/Gain' incorporates:
    //   Switch: '<S7>/Switch1'

    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *=
      F550_FaultInjection_P.Gain_Gain;

    // Saturate: '<S13>/Saturation1'
    if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >
        F550_FaultInjection_P.Saturation1_UpperSat) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_UpperSat;
    } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp <
               F550_FaultInjection_P.Saturation1_LowerSat) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_LowerSat;
    }

    F550_FaultInjection_B.Saturation1_f = ((((F550_FaultInjection_B.Sum_f +
      F550_FaultInjection_B.Gain2_g) * F550_FaultInjection_B.Gain3_k / 3.0 +
      F550_FaultInjection_B.Gain3_k) * 1000.0 + 1000.0) -
      F550_FaultInjection_P.IDLEPWM_Value) *
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
      F550_FaultInjection_P.Constant_Value_e1;
  }

  // End of Switch: '<S6>/Switch1'

  // MATLABSystem: '<S7>/Read Parameter2'
  if (F550_FaultInjection_DW.obj_ng.SampleTime !=
      F550_FaultInjection_P.ReadParameter2_SampleTime) {
    F550_FaultInjection_DW.obj_ng.SampleTime =
      F550_FaultInjection_P.ReadParameter2_SampleTime;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_ng.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_g);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_g = 0;
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

  if (F550_FaultInjection_B.Compare_k) {
    F550_FaultInjection_B.Saturation1_g = F550_FaultInjection_P.Constant2_Value;
  } else {
    if (F550_FaultInjection_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch2' incorporates:
      //   Constant: '<S7>/Fault2'
      //   DataTypeConversion: '<S7>/Data Type Conversion'
      //   MATLABSystem: '<S7>/Read Parameter2'
      //   Switch: '<S7>/Switch2'
      //
      if (F550_FaultInjection_P.ManualSwitch2_CurrentSetting == 1) {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_P.Fault2_Value;
      } else {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.ParamStep_g;
      }

      // End of ManualSwitch: '<S7>/Manual Switch2'
    } else {
      // Switch: '<S7>/Switch2' incorporates:
      //   Constant: '<S7>/Constant2'

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Constant2_Value_o;
    }

    // Gain: '<S14>/Gain' incorporates:
    //   Switch: '<S7>/Switch2'

    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *=
      F550_FaultInjection_P.Gain_Gain_d;

    // Saturate: '<S14>/Saturation1'
    if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >
        F550_FaultInjection_P.Saturation1_UpperSat_e) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_UpperSat_e;
    } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp <
               F550_FaultInjection_P.Saturation1_LowerSat_m) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_LowerSat_m;
    }

    F550_FaultInjection_B.Saturation1_g = (((((F550_FaultInjection_B.Sum_f / 2.0
      + F550_FaultInjection_B.Gain_i) - F550_FaultInjection_B.Gain2_g) *
      F550_FaultInjection_B.Gain3_k / 3.0 + F550_FaultInjection_B.Gain3_k) *
      1000.0 + 1000.0) - F550_FaultInjection_P.IDLEPWM_Value_j) *
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
      F550_FaultInjection_P.Constant_Value_fl;
  }

  // End of Switch: '<S6>/Switch2'

  // MATLABSystem: '<S7>/Read Parameter3'
  if (F550_FaultInjection_DW.obj_n.SampleTime !=
      F550_FaultInjection_P.ReadParameter3_SampleTime) {
    F550_FaultInjection_DW.obj_n.SampleTime =
      F550_FaultInjection_P.ReadParameter3_SampleTime;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_n.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_g);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_g = 0;
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

  if (F550_FaultInjection_B.Compare_k) {
    F550_FaultInjection_B.Saturation1_d = F550_FaultInjection_P.Constant3_Value;
  } else {
    if (F550_FaultInjection_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch3' incorporates:
      //   Constant: '<S7>/Fault3'
      //   DataTypeConversion: '<S7>/Data Type Conversion4'
      //   MATLABSystem: '<S7>/Read Parameter3'
      //   Switch: '<S7>/Switch3'
      //
      if (F550_FaultInjection_P.ManualSwitch3_CurrentSetting == 1) {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_P.Fault3_Value;
      } else {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.ParamStep_g;
      }

      // End of ManualSwitch: '<S7>/Manual Switch3'
    } else {
      // Switch: '<S7>/Switch3' incorporates:
      //   Constant: '<S7>/Constant3'

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Constant3_Value_b;
    }

    // Gain: '<S15>/Gain' incorporates:
    //   Switch: '<S7>/Switch3'

    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *=
      F550_FaultInjection_P.Gain_Gain_a;

    // Saturate: '<S15>/Saturation1'
    if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >
        F550_FaultInjection_P.Saturation1_UpperSat_l) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_UpperSat_l;
    } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp <
               F550_FaultInjection_P.Saturation1_LowerSat_g) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_LowerSat_g;
    }

    F550_FaultInjection_B.Saturation1_d = (((((-F550_FaultInjection_B.Gain_i -
      F550_FaultInjection_B.Sum_f / 2.0) + F550_FaultInjection_B.Gain2_g) *
      F550_FaultInjection_B.Gain3_k / 3.0 + F550_FaultInjection_B.Gain3_k) *
      1000.0 + 1000.0) - F550_FaultInjection_P.IDLEPWM_Value_k) *
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
      F550_FaultInjection_P.Constant_Value_a0;
  }

  // End of Switch: '<S6>/Switch3'

  // MATLABSystem: '<S7>/Read Parameter4'
  if (F550_FaultInjection_DW.obj_c.SampleTime !=
      F550_FaultInjection_P.ReadParameter4_SampleTime) {
    F550_FaultInjection_DW.obj_c.SampleTime =
      F550_FaultInjection_P.ReadParameter4_SampleTime;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_c.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_g);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_g = 0;
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

  if (F550_FaultInjection_B.Compare_k) {
    F550_FaultInjection_B.Saturation1_l = F550_FaultInjection_P.Constant4_Value;
  } else {
    if (F550_FaultInjection_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch4' incorporates:
      //   Constant: '<S7>/Fault4'
      //   DataTypeConversion: '<S7>/Data Type Conversion1'
      //   MATLABSystem: '<S7>/Read Parameter4'
      //   Switch: '<S7>/Switch4'
      //
      if (F550_FaultInjection_P.ManualSwitch4_CurrentSetting == 1) {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_P.Fault4_Value;
      } else {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.ParamStep_g;
      }

      // End of ManualSwitch: '<S7>/Manual Switch4'
    } else {
      // Switch: '<S7>/Switch4' incorporates:
      //   Constant: '<S7>/Constant4'

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Constant4_Value_e;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Switch: '<S7>/Switch4'

    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *=
      F550_FaultInjection_P.Gain_Gain_o;

    // Saturate: '<S16>/Saturation1'
    if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >
        F550_FaultInjection_P.Saturation1_UpperSat_eb) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_UpperSat_eb;
    } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp <
               F550_FaultInjection_P.Saturation1_LowerSat_b) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_LowerSat_b;
    }

    F550_FaultInjection_B.Saturation1_l = (((((F550_FaultInjection_B.Gain_i -
      F550_FaultInjection_B.Sum_f / 2.0) + F550_FaultInjection_B.Gain2_g) *
      F550_FaultInjection_B.Gain3_k / 3.0 + F550_FaultInjection_B.Gain3_k) *
      1000.0 + 1000.0) - F550_FaultInjection_P.IDLEPWM_Value_c) *
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
      F550_FaultInjection_P.Constant_Value_j3;
  }

  // End of Switch: '<S6>/Switch4'

  // MATLABSystem: '<S7>/Read Parameter5'
  if (F550_FaultInjection_DW.obj_p1.SampleTime !=
      F550_FaultInjection_P.ReadParameter5_SampleTime) {
    F550_FaultInjection_DW.obj_p1.SampleTime =
      F550_FaultInjection_P.ReadParameter5_SampleTime;
  }

  F550_FaultInjection_B.OR_g = MW_Param_Step
    (F550_FaultInjection_DW.obj_p1.MW_PARAMHANDLE, MW_INT32,
     &F550_FaultInjection_B.ParamStep_g);
  if (F550_FaultInjection_B.OR_g) {
    F550_FaultInjection_B.ParamStep_g = 0;
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

  if (F550_FaultInjection_B.Compare_k) {
    F550_FaultInjection_B.Sum_f = F550_FaultInjection_P.Constant5_Value;
  } else {
    if (F550_FaultInjection_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch5' incorporates:
      //   Constant: '<S7>/Fault5'
      //   DataTypeConversion: '<S7>/Data Type Conversion5'
      //   MATLABSystem: '<S7>/Read Parameter5'
      //   Switch: '<S7>/Switch5'
      //
      if (F550_FaultInjection_P.ManualSwitch5_CurrentSetting == 1) {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_P.Fault5_Value;
      } else {
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.ParamStep_g;
      }

      // End of ManualSwitch: '<S7>/Manual Switch5'
    } else {
      // Switch: '<S7>/Switch5' incorporates:
      //   Constant: '<S7>/Constant5'

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Constant5_Value_f;
    }

    // Gain: '<S17>/Gain' incorporates:
    //   Switch: '<S7>/Switch5'

    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *=
      F550_FaultInjection_P.Gain_Gain_ap;

    // Saturate: '<S17>/Saturation1'
    if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp >
        F550_FaultInjection_P.Saturation1_UpperSat_b) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_UpperSat_b;
    } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp <
               F550_FaultInjection_P.Saturation1_LowerSat_o) {
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_P.Saturation1_LowerSat_o;
    }

    F550_FaultInjection_B.Sum_f = (((((F550_FaultInjection_B.Sum_f / 2.0 -
      F550_FaultInjection_B.Gain_i) - F550_FaultInjection_B.Gain2_g) *
      F550_FaultInjection_B.Gain3_k / 3.0 + F550_FaultInjection_B.Gain3_k) *
      1000.0 + 1000.0) - F550_FaultInjection_P.IDLEPWM_Value_e) *
      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
      F550_FaultInjection_P.Constant_Value_cx;
  }

  // End of Switch: '<S6>/Switch5'

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S21>/Constant'

  F550_FaultInjection_B.BusAssignment_l = F550_FaultInjection_P.Constant_Value_c;

  // DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
  //   Constant: '<S10>/Constant17'

  F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = floor
    (F550_FaultInjection_P.Constant17_Value);
  if (rtIsNaN(F550_FaultInjection_B.rtb_MatrixConcatenate1_pp) || rtIsInf
      (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp)) {
    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = 0.0;
  } else {
    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = fmod
      (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp, 4.294967296E+9);
  }

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S10>/Constant'
  //   DataTypeConversion: '<S10>/Data Type Conversion'
  //   DataTypeConversion: '<S10>/Data Type Conversion1'

  F550_FaultInjection_B.BusAssignment_l.noutputs =
    F550_FaultInjection_B.rtb_MatrixConcatenate1_pp < 0.0 ? static_cast<uint32_T>
    (-static_cast<int32_T>(static_cast<uint32_T>
      (-F550_FaultInjection_B.rtb_MatrixConcatenate1_pp))) :
    static_cast<uint32_T>(F550_FaultInjection_B.rtb_MatrixConcatenate1_pp);
  F550_FaultInjection_B.BusAssignment_l.output[0] = static_cast<real32_T>
    (F550_FaultInjection_B.Saturation1);
  F550_FaultInjection_B.BusAssignment_l.output[1] = static_cast<real32_T>
    (F550_FaultInjection_B.Saturation1_f);
  F550_FaultInjection_B.BusAssignment_l.output[2] = static_cast<real32_T>
    (F550_FaultInjection_B.Saturation1_g);
  F550_FaultInjection_B.BusAssignment_l.output[3] = static_cast<real32_T>
    (F550_FaultInjection_B.Saturation1_d);
  F550_FaultInjection_B.BusAssignment_l.output[4] = static_cast<real32_T>
    (F550_FaultInjection_B.Saturation1_l);
  F550_FaultInjection_B.BusAssignment_l.output[5] = static_cast<real32_T>
    (F550_FaultInjection_B.Sum_f);
  F550_FaultInjection_B.BusAssignment_l.output[6] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[7] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[8] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[9] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[10] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[11] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[12] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[13] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[14] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);
  F550_FaultInjection_B.BusAssignment_l.output[15] = static_cast<real32_T>
    (F550_FaultInjection_P.Constant_Value_gp);

  // MATLABSystem: '<S22>/SinkBlock' incorporates:
  //   BusAssignment: '<S10>/Bus Assignment'

  uORB_write_step(F550_FaultInjection_DW.obj_h.orbMetadataObj,
                  &F550_FaultInjection_DW.obj_h.orbAdvertiseObj,
                  &F550_FaultInjection_B.BusAssignment_l);
  F550_FaultInjection_PX4Timestamp(&F550_FaultInjection_B.PX4Timestamp_p);

  // BusAssignment: '<S560>/Bus Assignment' incorporates:
  //   Constant: '<S598>/Constant'
  //   DataTypeConversion: '<S560>/Data Type Conversion'
  //   DataTypeConversion: '<S560>/Data Type Conversion1'
  //   DataTypeConversion: '<S560>/Data Type Conversion2'
  //   DataTypeConversion: '<S560>/Data Type Conversion3'
  //   MATLABSystem: '<S560>/PX4 Timestamp'

  F550_FaultInjection_B.BusAssignment_m_c =
    F550_FaultInjection_P.Constant_Value_i;
  F550_FaultInjection_B.BusAssignment_m_c.timestamp =
    F550_FaultInjection_B.PX4Timestamp_p.PX4Timestamp;
  F550_FaultInjection_B.BusAssignment_m_c.x = static_cast<real32_T>
    (F550_FaultInjection_B.Merge[0]);
  F550_FaultInjection_B.BusAssignment_m_c.y = static_cast<real32_T>
    (F550_FaultInjection_B.Merge[1]);
  F550_FaultInjection_B.BusAssignment_m_c.z = static_cast<real32_T>
    (F550_FaultInjection_B.Merge[2]);
  F550_FaultInjection_B.BusAssignment_m_c.yaw = static_cast<real32_T>
    (F550_FaultInjection_B.Merge[3]);

  // MATLABSystem: '<S599>/SinkBlock' incorporates:
  //   BusAssignment: '<S560>/Bus Assignment'

  uORB_write_step(F550_FaultInjection_DW.obj_o2.orbMetadataObj,
                  &F550_FaultInjection_DW.obj_o2.orbAdvertiseObj,
                  &F550_FaultInjection_B.BusAssignment_m_c);

  // Outputs for Enabled SubSystem: '<S563>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S580>/Enable'

  // Start for MATLABSystem: '<S563>/Read Parameter'
  if (F550_FaultInjection_B.ParamStep_d > 0) {
    // BusAssignment: '<S580>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment'
    //   Constant: '<S590>/Constant'
    //   SignalConversion generated from: '<S586>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[0] =
      F550_FaultInjection_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S586>/Matrix Concatenate1'
    F550_FaultInjection_B.MatrixConcatenate1[0] =
      F550_FaultInjection_B.In1_p.current.lat;

    // SignalConversion generated from: '<S586>/Matrix Concatenate1'
    F550_FaultInjection_B.MatrixConcatenate1[1] =
      F550_FaultInjection_B.In1_p.current.lon;

    // DataTypeConversion: '<S586>/Data Type Conversion'
    F550_FaultInjection_B.MatrixConcatenate1[2] =
      F550_FaultInjection_B.In1_p.current.alt;

    // SignalConversion generated from: '<S580>/Matrix Concatenate1'
    F550_FaultInjection_B.MatrixConcatenate1_k[0] =
      F550_FaultInjection_B.In1_f.lat;

    // SignalConversion generated from: '<S580>/Matrix Concatenate1'
    F550_FaultInjection_B.MatrixConcatenate1_k[1] =
      F550_FaultInjection_B.In1_f.lon;

    // DataTypeConversion: '<S580>/Data Type Conversion'
    F550_FaultInjection_B.MatrixConcatenate1_k[2] =
      F550_FaultInjection_B.In1_f.alt;
    F550_FaultInjection_MATLABSystem(F550_FaultInjection_B.MatrixConcatenate1,
      F550_FaultInjection_B.MatrixConcatenate1_k,
      F550_FaultInjection_B.In1_p.current.valid,
      F550_FaultInjection_B.In1_p.current.type,
      &F550_FaultInjection_B.MATLABSystem);

    // SignalConversion generated from: '<S592>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'
    //   MATLABSystem: '<S586>/MATLAB System'
    //   SignalConversion generated from: '<S586>/MATLAB System'

    F550_FaultInjection_B.BusAssignment1.waypoints[0].position[0] =
      F550_FaultInjection_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S592>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'
    //   MATLABSystem: '<S586>/MATLAB System'
    //   SignalConversion generated from: '<S586>/MATLAB System'

    F550_FaultInjection_B.BusAssignment1.waypoints[0].position[1] =
      F550_FaultInjection_B.MATLABSystem.MATLABSystem[1];

    // If: '<S592>/If' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'
    //   Constant: '<S594>/Constant'
    //   Constant: '<S594>/Constant1'
    //   Constant: '<S595>/Constant'
    //   Constant: '<S595>/Constant1'

    if (F550_FaultInjection_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S592>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S595>/Action Port'

      // MATLABSystem: '<S595>/Read Parameter' incorporates:
      //   BusAssignment: '<S580>/Bus Assignment1'
      //   BusAssignment: '<S586>/Bus Assignment1'
      //   SignalConversion generated from: '<S595>/Read Parameter'

      if (F550_FaultInjection_DW.obj_g.SampleTime !=
          F550_FaultInjection_P.ReadParameter_SampleTime_c) {
        F550_FaultInjection_DW.obj_g.SampleTime =
          F550_FaultInjection_P.ReadParameter_SampleTime_c;
      }

      F550_FaultInjection_B.OR_g = MW_Param_Step
        (F550_FaultInjection_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[2]);
      if (F550_FaultInjection_B.OR_g) {
        F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S595>/Read Parameter'
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[0] =
        F550_FaultInjection_P.Constant1_Value_d[0];
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[1] =
        F550_FaultInjection_P.Constant1_Value_d[1];
      F550_FaultInjection_B.BusAssignment1.waypoints[0].position[2] =
        F550_FaultInjection_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S592>/If Action Subsystem2'
    } else if (F550_FaultInjection_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S592>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S594>/Action Port'

      // MATLABSystem: '<S594>/Read Parameter'
      if (F550_FaultInjection_DW.obj_b.SampleTime !=
          F550_FaultInjection_P.ReadParameter_SampleTime_g) {
        F550_FaultInjection_DW.obj_b.SampleTime =
          F550_FaultInjection_P.ReadParameter_SampleTime_g;
      }

      F550_FaultInjection_B.OR_g = MW_Param_Step
        (F550_FaultInjection_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &F550_FaultInjection_B.ParamStep_j);
      if (F550_FaultInjection_B.OR_g) {
        F550_FaultInjection_B.ParamStep_j = 0.0F;
      }

      // Gain: '<S594>/Gain' incorporates:
      //   BusAssignment: '<S580>/Bus Assignment1'
      //   BusAssignment: '<S586>/Bus Assignment1'
      //   MATLABSystem: '<S594>/Read Parameter'
      //
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[2] =
        F550_FaultInjection_P.Gain_Gain_h * F550_FaultInjection_B.ParamStep_j;
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[0] =
        F550_FaultInjection_P.Constant1_Value_k[0];
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[1] =
        F550_FaultInjection_P.Constant1_Value_k[1];
      F550_FaultInjection_B.BusAssignment1.waypoints[0].position[2] =
        F550_FaultInjection_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S592>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S592>/If Action Subsystem' incorporates:
      //   ActionPort: '<S593>/Action Port'

      // SignalConversion generated from: '<S593>/In1' incorporates:
      //   BusAssignment: '<S580>/Bus Assignment1'
      //   BusAssignment: '<S586>/Bus Assignment1'
      //   MATLABSystem: '<S586>/MATLAB System'
      //   SignalConversion generated from: '<S586>/MATLAB System'

      F550_FaultInjection_B.BusAssignment1.waypoints[0].position[2] =
        F550_FaultInjection_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S586>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S580>/Bus Assignment1'
      //   SignalConversion generated from: '<S592>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S593>/In2'
      //
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[0] =
        F550_FaultInjection_B.In1_p.current.vx;
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[1] =
        F550_FaultInjection_B.In1_p.current.vy;
      F550_FaultInjection_B.BusAssignment1.waypoints[0].velocity[2] =
        F550_FaultInjection_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S592>/If Action Subsystem'
    }

    // End of If: '<S592>/If'

    // BusAssignment: '<S586>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   Constant: '<S586>/Constant5'

    F550_FaultInjection_B.BusAssignment1.waypoints[0].timestamp =
      F550_FaultInjection_B.In1_p.current.timestamp;
    F550_FaultInjection_B.BusAssignment1.waypoints[0].type =
      F550_FaultInjection_B.In1_p.current.type;
    F550_FaultInjection_B.BusAssignment1.waypoints[0].yaw =
      F550_FaultInjection_B.In1_p.current.yaw;
    F550_FaultInjection_B.BusAssignment1.waypoints[0].yaw_speed =
      F550_FaultInjection_B.In1_p.current.yawspeed;
    F550_FaultInjection_B.BusAssignment1.waypoints[0].point_valid =
      F550_FaultInjection_P.Constant5_Value_j;

    // BusAssignment: '<S580>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment'
    //   Constant: '<S590>/Constant'
    //   SignalConversion generated from: '<S587>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[1] =
      F550_FaultInjection_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S587>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S586>/Matrix Concatenate1'

    F550_FaultInjection_B.MatrixConcatenate1[0] =
      F550_FaultInjection_B.In1_p.current.lat;

    // SignalConversion generated from: '<S587>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S586>/Matrix Concatenate1'

    F550_FaultInjection_B.MatrixConcatenate1[1] =
      F550_FaultInjection_B.In1_p.current.lon;

    // DataTypeConversion: '<S587>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S586>/Data Type Conversion'

    F550_FaultInjection_B.MatrixConcatenate1[2] =
      F550_FaultInjection_B.In1_p.current.alt;
    F550_FaultInjection_MATLABSystem(F550_FaultInjection_B.MatrixConcatenate1,
      F550_FaultInjection_B.MatrixConcatenate1_k,
      F550_FaultInjection_B.In1_p.current.valid,
      F550_FaultInjection_B.In1_p.current.type,
      &F550_FaultInjection_B.MATLABSystem_b);

    // SignalConversion generated from: '<S587>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S587>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[1].velocity[0] =
      F550_FaultInjection_B.In1_p.current.vx;

    // SignalConversion generated from: '<S587>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S587>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[1].velocity[1] =
      F550_FaultInjection_B.In1_p.current.vy;

    // SignalConversion generated from: '<S587>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S587>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[1].velocity[2] =
      F550_FaultInjection_B.In1_p.current.vz;

    // BusAssignment: '<S587>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'
    //   Constant: '<S587>/Constant5'
    //   MATLABSystem: '<S587>/MATLAB System'

    F550_FaultInjection_B.BusAssignment1.waypoints[1].timestamp =
      F550_FaultInjection_B.In1_p.current.timestamp;
    F550_FaultInjection_B.BusAssignment1.waypoints[1].position[0] =
      F550_FaultInjection_B.MATLABSystem_b.MATLABSystem[0];
    F550_FaultInjection_B.BusAssignment1.waypoints[1].position[1] =
      F550_FaultInjection_B.MATLABSystem_b.MATLABSystem[1];
    F550_FaultInjection_B.BusAssignment1.waypoints[1].position[2] =
      F550_FaultInjection_B.MATLABSystem_b.MATLABSystem[2];
    F550_FaultInjection_B.BusAssignment1.waypoints[1].yaw =
      F550_FaultInjection_B.In1_p.current.yaw;
    F550_FaultInjection_B.BusAssignment1.waypoints[1].yaw_speed =
      F550_FaultInjection_B.In1_p.current.yawspeed;
    F550_FaultInjection_B.BusAssignment1.waypoints[1].point_valid =
      F550_FaultInjection_P.Constant5_Value_k;
    F550_FaultInjection_B.BusAssignment1.waypoints[1].type =
      F550_FaultInjection_B.In1_p.current.type;

    // BusAssignment: '<S580>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment'
    //   Constant: '<S590>/Constant'
    //   SignalConversion generated from: '<S589>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[2] =
      F550_FaultInjection_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S589>/MATLAB System' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   DataTypeConversion: '<S580>/Data Type Conversion'
    //   DataTypeConversion: '<S589>/Data Type Conversion'
    //   SignalConversion generated from: '<S580>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S589>/Matrix Concatenate'
    //
    if (F550_FaultInjection_B.In1_p.next.valid) {
      F550_FaultInjection_B.Sum_f = F550_FaultInjection_B.In1_p.next.lat -
        F550_FaultInjection_B.In1_f.lat;
      F550_FaultInjection_B.Gain_i = F550_FaultInjection_B.In1_p.next.lon -
        F550_FaultInjection_B.In1_f.lon;
      F550_FaultInjection_B.Gain2_g = fabs(F550_FaultInjection_B.Sum_f);
      if (F550_FaultInjection_B.Gain2_g > 180.0) {
        if (rtIsNaN(F550_FaultInjection_B.Sum_f + 180.0) || rtIsInf
            (F550_FaultInjection_B.Sum_f + 180.0)) {
          F550_FaultInjection_B.Gain2_g = (rtNaN);
        } else if (F550_FaultInjection_B.Sum_f + 180.0 == 0.0) {
          F550_FaultInjection_B.Gain2_g = 0.0;
        } else {
          F550_FaultInjection_B.Gain2_g = fmod(F550_FaultInjection_B.Sum_f +
            180.0, 360.0);
          if (F550_FaultInjection_B.Gain2_g == 0.0) {
            F550_FaultInjection_B.Gain2_g = 0.0;
          } else if (F550_FaultInjection_B.Sum_f + 180.0 < 0.0) {
            F550_FaultInjection_B.Gain2_g += 360.0;
          }
        }

        F550_FaultInjection_B.Sum_f = F550_FaultInjection_B.Sum_f * 0.0 +
          (F550_FaultInjection_B.Gain2_g - 180.0);
        F550_FaultInjection_B.Gain2_g = fabs(F550_FaultInjection_B.Sum_f);
      }

      if (F550_FaultInjection_B.Gain2_g > 90.0) {
        F550_FaultInjection_B.Gain2_g = fabs(F550_FaultInjection_B.Sum_f);
        F550_FaultInjection_B.OR_g = (F550_FaultInjection_B.Gain2_g > 90.0);
        F550_FaultInjection_B.Gain_i += 180.0;
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.Sum_f * static_cast<real_T>
          (F550_FaultInjection_B.OR_g);
        if (rtIsNaN(F550_FaultInjection_B.rtb_MatrixConcatenate1_pp)) {
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = (rtNaN);
        } else if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp < 0.0) {
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = -1.0;
        } else {
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
            (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp > 0.0);
        }

        F550_FaultInjection_B.Sum_f = (90.0 - (F550_FaultInjection_B.Gain2_g *
          static_cast<real_T>(F550_FaultInjection_B.OR_g) - 90.0)) *
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp * static_cast<real_T>
          (F550_FaultInjection_B.OR_g) + F550_FaultInjection_B.Sum_f *
          static_cast<real_T>(!F550_FaultInjection_B.OR_g);
      }

      if ((F550_FaultInjection_B.Gain_i > 180.0) ||
          (F550_FaultInjection_B.Gain_i < -180.0)) {
        F550_FaultInjection_B.Gain2_g = F550_FaultInjection_rt_remd_snf
          (F550_FaultInjection_B.Gain_i, 360.0);
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
          F550_FaultInjection_B.Gain2_g / 180.0;
        if (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp < 0.0) {
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = ceil
            (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp);
        } else {
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = floor
            (F550_FaultInjection_B.rtb_MatrixConcatenate1_pp);
        }

        F550_FaultInjection_B.Gain_i = (F550_FaultInjection_B.Gain2_g - 360.0 *
          F550_FaultInjection_B.rtb_MatrixConcatenate1_pp) +
          F550_FaultInjection_B.Gain_i * 0.0;
      }

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp =
        F550_FaultInjection_sind_d(F550_FaultInjection_B.In1_f.lat);
      F550_FaultInjection_B.Gain2_g = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 * F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp);
      if (rtIsInf(F550_FaultInjection_B.In1_f.lat) || rtIsNaN
          (F550_FaultInjection_B.In1_f.lat)) {
        F550_FaultInjection_B.Gain3_k = (rtNaN);
      } else {
        F550_FaultInjection_B.Gain3_k = F550_FaultInjection_rt_remd_snf
          (F550_FaultInjection_B.In1_f.lat, 360.0);
        F550_FaultInjection_B.Saturation1 = fabs(F550_FaultInjection_B.Gain3_k);
        if (F550_FaultInjection_B.Saturation1 > 180.0) {
          if (F550_FaultInjection_B.Gain3_k > 0.0) {
            F550_FaultInjection_B.Gain3_k -= 360.0;
          } else {
            F550_FaultInjection_B.Gain3_k += 360.0;
          }

          F550_FaultInjection_B.Saturation1 = fabs(F550_FaultInjection_B.Gain3_k);
        }

        if (F550_FaultInjection_B.Saturation1 <= 45.0) {
          F550_FaultInjection_B.Gain3_k = cos(0.017453292519943295 *
            F550_FaultInjection_B.Gain3_k);
        } else if (F550_FaultInjection_B.Saturation1 <= 135.0) {
          if (F550_FaultInjection_B.Gain3_k > 0.0) {
            F550_FaultInjection_B.Gain3_k = -sin((F550_FaultInjection_B.Gain3_k
              - 90.0) * 0.017453292519943295);
          } else {
            F550_FaultInjection_B.Gain3_k = sin((F550_FaultInjection_B.Gain3_k +
              90.0) * 0.017453292519943295);
          }
        } else {
          if (F550_FaultInjection_B.Gain3_k > 0.0) {
            F550_FaultInjection_B.Gain3_k = (F550_FaultInjection_B.Gain3_k -
              180.0) * 0.017453292519943295;
          } else {
            F550_FaultInjection_B.Gain3_k = (F550_FaultInjection_B.Gain3_k +
              180.0) * 0.017453292519943295;
          }

          F550_FaultInjection_B.Gain3_k = -cos(F550_FaultInjection_B.Gain3_k);
        }
      }

      F550_FaultInjection_B.Sum_f /= F550_FaultInjection_rt_atan2d_snf_d(1.0,
        0.99330562000985867 / (1.0 - 0.0066943799901413165 *
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp *
        F550_FaultInjection_B.rtb_MatrixConcatenate1_pp) *
        F550_FaultInjection_B.Gain2_g) * 57.295779513082323;
      F550_FaultInjection_B.Gain_i /= F550_FaultInjection_rt_atan2d_snf_d(1.0,
        F550_FaultInjection_B.Gain2_g * F550_FaultInjection_B.Gain3_k) *
        57.295779513082323;
      F550_FaultInjection_B.Gain2_g = -static_cast<real_T>
        (F550_FaultInjection_B.In1_p.next.alt) + F550_FaultInjection_B.In1_f.alt;
      F550_FaultInjection_B.distinctWptsIdx[0] = rtIsNaN
        (F550_FaultInjection_B.Sum_f);
      F550_FaultInjection_B.distinctWptsIdx[1] = rtIsNaN
        (F550_FaultInjection_B.Gain_i);
      F550_FaultInjection_B.distinctWptsIdx[2] = rtIsNaN
        (F550_FaultInjection_B.Gain2_g);
      F550_FaultInjection_B.Compare_k = false;
      F550_FaultInjection_B.iy = 0;
      exitg1 = false;
      while ((!exitg1) && (F550_FaultInjection_B.iy < 3)) {
        if (F550_FaultInjection_B.distinctWptsIdx[F550_FaultInjection_B.iy]) {
          F550_FaultInjection_B.Compare_k = true;
          exitg1 = true;
        } else {
          F550_FaultInjection_B.iy++;
        }
      }

      F550_FaultInjection_B.rtb_MatrixConcatenate1_pp = 0.0 / static_cast<real_T>
        (!F550_FaultInjection_B.Compare_k);
      F550_FaultInjection_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
        F550_FaultInjection_B.Sum_f);
      F550_FaultInjection_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
        F550_FaultInjection_B.Gain_i);
      F550_FaultInjection_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(F550_FaultInjection_B.rtb_MatrixConcatenate1_pp +
        F550_FaultInjection_B.Gain2_g);
    } else {
      F550_FaultInjection_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      F550_FaultInjection_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      F550_FaultInjection_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S589>/MATLAB System'

    // SignalConversion generated from: '<S589>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S589>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[2].velocity[0] =
      F550_FaultInjection_B.In1_p.next.vx;

    // SignalConversion generated from: '<S589>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S589>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[2].velocity[1] =
      F550_FaultInjection_B.In1_p.next.vy;

    // SignalConversion generated from: '<S589>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   BusAssignment: '<S589>/Bus Assignment1'

    F550_FaultInjection_B.BusAssignment1.waypoints[2].velocity[2] =
      F550_FaultInjection_B.In1_p.next.vz;

    // BusAssignment: '<S589>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'
    //   Constant: '<S589>/Constant5'

    F550_FaultInjection_B.BusAssignment1.waypoints[2].timestamp =
      F550_FaultInjection_B.In1_p.next.timestamp;
    F550_FaultInjection_B.BusAssignment1.waypoints[2].yaw =
      F550_FaultInjection_B.In1_p.next.yaw;
    F550_FaultInjection_B.BusAssignment1.waypoints[2].yaw_speed =
      F550_FaultInjection_B.In1_p.next.yawspeed;
    F550_FaultInjection_B.BusAssignment1.waypoints[2].point_valid =
      F550_FaultInjection_P.Constant5_Value_h;
    F550_FaultInjection_B.BusAssignment1.waypoints[2].type =
      F550_FaultInjection_B.In1_p.next.type;

    // SignalConversion generated from: '<S588>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment'
    //   BusAssignment: '<S588>/Bus Assignment1'
    //   Constant: '<S590>/Constant'

    F550_FaultInjection_B.BusAssignment1_f =
      F550_FaultInjection_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S588>/Bus Assignment1' incorporates:
    //   Constant: '<S588>/Constant'
    //   Constant: '<S588>/Constant1'
    //   Constant: '<S588>/Constant2'
    //   Constant: '<S588>/Constant3'
    //   Constant: '<S588>/Constant4'
    //   Constant: '<S588>/Constant5'
    //   Constant: '<S588>/Constant6'
    //   Constant: '<S588>/Constant7'

    F550_FaultInjection_B.BusAssignment1_f.timestamp =
      F550_FaultInjection_P.Constant7_Value;
    F550_FaultInjection_B.BusAssignment1_f.yaw =
      F550_FaultInjection_P.Constant3_Value_a;
    F550_FaultInjection_B.BusAssignment1_f.yaw_speed =
      F550_FaultInjection_P.Constant4_Value_g;
    F550_FaultInjection_B.BusAssignment1_f.position[0] =
      F550_FaultInjection_P.Constant_Value_fh[0];
    F550_FaultInjection_B.BusAssignment1_f.velocity[0] =
      F550_FaultInjection_P.Constant1_Value_h[0];
    F550_FaultInjection_B.BusAssignment1_f.acceleration[0] =
      F550_FaultInjection_P.Constant2_Value_f[0];
    F550_FaultInjection_B.BusAssignment1_f.position[1] =
      F550_FaultInjection_P.Constant_Value_fh[1];
    F550_FaultInjection_B.BusAssignment1_f.velocity[1] =
      F550_FaultInjection_P.Constant1_Value_h[1];
    F550_FaultInjection_B.BusAssignment1_f.acceleration[1] =
      F550_FaultInjection_P.Constant2_Value_f[1];
    F550_FaultInjection_B.BusAssignment1_f.position[2] =
      F550_FaultInjection_P.Constant_Value_fh[2];
    F550_FaultInjection_B.BusAssignment1_f.velocity[2] =
      F550_FaultInjection_P.Constant1_Value_h[2];
    F550_FaultInjection_B.BusAssignment1_f.acceleration[2] =
      F550_FaultInjection_P.Constant2_Value_f[2];
    F550_FaultInjection_B.BusAssignment1_f.point_valid =
      F550_FaultInjection_P.Constant5_Value_l;
    F550_FaultInjection_B.BusAssignment1_f.type =
      F550_FaultInjection_P.Constant6_Value;

    // BusAssignment: '<S580>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment'
    //   BusAssignment: '<S588>/Bus Assignment1'
    //   Concatenate: '<S580>/Matrix Concatenate'
    //   Constant: '<S580>/Constant'
    //   Constant: '<S590>/Constant'

    F550_FaultInjection_B.BusAssignment1.timestamp =
      F550_FaultInjection_B.In1_p.timestamp;
    F550_FaultInjection_B.BusAssignment1.type =
      F550_FaultInjection_P.Constant_Value_fm;
    for (F550_FaultInjection_B.i1_l = 0; F550_FaultInjection_B.i1_l < 7;
         F550_FaultInjection_B.i1_l++) {
      F550_FaultInjection_B.BusAssignment1._padding0[F550_FaultInjection_B.i1_l]
        =
        F550_FaultInjection_P.Constant_Value._padding0[F550_FaultInjection_B.i1_l];
    }

    F550_FaultInjection_B.BusAssignment1.waypoints[3] =
      F550_FaultInjection_B.BusAssignment1_f;
    F550_FaultInjection_B.BusAssignment1.waypoints[4] =
      F550_FaultInjection_B.BusAssignment1_f;

    // MATLABSystem: '<S591>/SinkBlock' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'

    uORB_write_step(F550_FaultInjection_DW.obj_mc.orbMetadataObj,
                    &F550_FaultInjection_DW.obj_mc.orbAdvertiseObj,
                    &F550_FaultInjection_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S563>/Send waypoints to OBC'
  F550_FaultInjection_PX4Timestamp(&F550_FaultInjection_B.PX4Timestamp);
}

// Model initialize function
void F550_FaultInjection_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  F550_FaultInjection_P.Constant1_Value_d[0] = rtNaNF;
  F550_FaultInjection_P.Constant1_Value_d[1] = rtNaNF;
  F550_FaultInjection_P.Constant_Value_f2 = rtNaNF;
  F550_FaultInjection_P.Constant1_Value_k[0] = rtNaNF;
  F550_FaultInjection_P.Constant1_Value_k[1] = rtNaNF;
  F550_FaultInjection_P.Constant_Value_l4 = rtNaNF;
  F550_FaultInjection_P.Constant_Value_fh[0] = rtNaNF;
  F550_FaultInjection_P.Constant_Value_fh[1] = rtNaNF;
  F550_FaultInjection_P.Constant_Value_fh[2] = rtNaNF;
  F550_FaultInjection_P.Constant1_Value_h[0] = rtNaNF;
  F550_FaultInjection_P.Constant1_Value_h[1] = rtNaNF;
  F550_FaultInjection_P.Constant1_Value_h[2] = rtNaNF;
  F550_FaultInjection_P.Constant2_Value_f[0] = rtNaNF;
  F550_FaultInjection_P.Constant2_Value_f[1] = rtNaNF;
  F550_FaultInjection_P.Constant2_Value_f[2] = rtNaNF;
  F550_FaultInjection_P.Constant3_Value_a = rtNaNF;
  F550_FaultInjection_P.Constant4_Value_g = rtNaNF;

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

    // Start for If: '<S562>/If'
    F550_FaultInjection_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S19>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    F550_FaultInjection_B.In1_k = F550_FaultInjection_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S19>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S603>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S607>/In1' incorporates:
    //   Outport: '<S607>/Out1'

    F550_FaultInjection_B.In1_c = F550_FaultInjection_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S603>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S584>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S585>/In1' incorporates:
    //   Outport: '<S585>/Out1'

    F550_FaultInjection_B.In1 = F550_FaultInjection_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S584>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S582>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S597>/In1' incorporates:
    //   Outport: '<S597>/Out1'

    F550_FaultInjection_B.In1_p = F550_FaultInjection_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S582>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S581>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S596>/In1' incorporates:
    //   Outport: '<S596>/Out1'

    F550_FaultInjection_B.In1_f = F550_FaultInjection_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S581>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S562>/Take-off'
    // InitializeConditions for Delay: '<S574>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_c =
      F550_FaultInjection_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S575>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_d =
      F550_FaultInjection_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S575>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S576>/yaw_In' incorporates:
    //   Outport: '<S576>/yaw_Out'

    F550_FaultInjection_B.yaw_In_ik = F550_FaultInjection_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S575>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S562>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S562>/Land'
    // InitializeConditions for Delay: '<S565>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_l[0] =
      F550_FaultInjection_P.Delay_InitialCondition_n;
    F550_FaultInjection_DW.Delay_DSTATE_l[1] =
      F550_FaultInjection_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S570>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_n =
      F550_FaultInjection_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S571>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE_b =
      F550_FaultInjection_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S571>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S573>/yaw_In' incorporates:
    //   Outport: '<S573>/yaw_Out'

    F550_FaultInjection_B.yaw_In_i = F550_FaultInjection_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S571>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S570>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S572>/In' incorporates:
    //   Outport: '<S572>/Out'

    F550_FaultInjection_B.In = F550_FaultInjection_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S570>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S562>/Land'

    // SystemInitialize for IfAction SubSystem: '<S562>/Waypoint'
    // Start for MATLABSystem: '<S567>/UAV Waypoint Follower'
    F550_FaultInjection_DW.obj.LastWaypointFlag = false;
    F550_FaultInjection_DW.obj.StartFlag = true;
    F550_FaultInjection_DW.obj.LookaheadFactor = 1.01;
    F550_FaultInjection_DW.obj.isInitialized = 1;
    F550_FaultInjection_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S567>/UAV Waypoint Follower'
    F550_FaultInjection_DW.obj.WaypointIndex = 1.0;
    memset(&F550_FaultInjection_DW.obj.WaypointsInternal[0], 0, 9U * sizeof
           (real_T));

    // End of SystemInitialize for SubSystem: '<S562>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S562>/IDLE'
    // InitializeConditions for Delay: '<S568>/Delay'
    F550_FaultInjection_DW.Delay_DSTATE =
      F550_FaultInjection_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S568>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S569>/yaw_In' incorporates:
    //   Outport: '<S569>/yaw_Out'

    F550_FaultInjection_B.yaw_In = F550_FaultInjection_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S568>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S562>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S602>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S606>/In1' incorporates:
    //   Outport: '<S606>/Out1'

    F550_FaultInjection_B.In1_m = F550_FaultInjection_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S602>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S600>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S604>/In1' incorporates:
    //   Outport: '<S604>/Out1'

    F550_FaultInjection_B.In1_l = F550_FaultInjection_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S600>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S601>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S605>/Out1' incorporates:
    //   SignalConversion generated from: '<S605>/In1'

    F550_FaultInjection_B.In1_b = F550_FaultInjection_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S601>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/CLAW'
    F550_FaultInjection_CLAW_Init();

    // End of SystemInitialize for SubSystem: '<Root>/CLAW'

    // SystemInitialize for Enabled SubSystem: '<S563>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S592>/If Action Subsystem2'
    // Start for MATLABSystem: '<S595>/Read Parameter'
    F550_FaultInjection_DW.obj_g.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_g.SampleTime =
      F550_FaultInjection_P.ReadParameter_SampleTime_c;
    F550_FaultInjection_DW.obj_g.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_g.SampleTime;
    }

    F550_FaultInjection_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S595>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S592>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S592>/If Action Subsystem1'
    // Start for MATLABSystem: '<S594>/Read Parameter'
    F550_FaultInjection_DW.obj_b.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_b.SampleTime =
      F550_FaultInjection_P.ReadParameter_SampleTime_g;
    F550_FaultInjection_DW.obj_b.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_b.SampleTime;
    }

    F550_FaultInjection_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S594>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S592>/If Action Subsystem1'
    F550_FaultInjection_MATLABSystem_Init(&F550_FaultInjection_DW.MATLABSystem);
    F550_FaultInjection_MATLABSystem_Init(&F550_FaultInjection_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S589>/MATLAB System'
    F550_FaultInjection_DW.obj_mu.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S591>/SinkBlock' incorporates:
    //   BusAssignment: '<S580>/Bus Assignment1'

    F550_FaultInjection_DW.obj_mc.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_mc.isInitialized = 1;
    F550_FaultInjection_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(F550_FaultInjection_DW.obj_mc.orbMetadataObj,
                          &F550_FaultInjection_DW.obj_mc.orbAdvertiseObj,
                          &F550_FaultInjection_B.BusAssignment1_c, 1);
    F550_FaultInjection_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S563>/Send waypoints to OBC'
    F550_FaultInjection_SourceBlock_Init(&F550_FaultInjection_DW.SourceBlock);

    // Start for MATLABSystem: '<S603>/SourceBlock'
    F550_FaultInjection_DW.obj_mg.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_mg.isInitialized = 1;
    F550_FaultInjection_DW.obj_mg.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(F550_FaultInjection_DW.obj_mg.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_mg.eventStructObj);
    F550_FaultInjection_DW.obj_mg.isSetupComplete = true;

    // Start for MATLABSystem: '<S563>/Read Parameter'
    F550_FaultInjection_DW.obj_k.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_k.SampleTime =
      F550_FaultInjection_P.ReadParameter_SampleTime_d;
    F550_FaultInjection_DW.obj_k.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_k.SampleTime;
    }

    F550_FaultInjection_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S563>/Read Parameter'

    // Start for MATLABSystem: '<S584>/SourceBlock'
    F550_FaultInjection_DW.obj_e.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_e.isInitialized = 1;
    F550_FaultInjection_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize(F550_FaultInjection_DW.obj_e.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_e.eventStructObj);
    F550_FaultInjection_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S582>/SourceBlock'
    F550_FaultInjection_DW.obj_kz.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_kz.isInitialized = 1;
    F550_FaultInjection_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(F550_FaultInjection_DW.obj_kz.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_kz.eventStructObj);
    F550_FaultInjection_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S581>/SourceBlock'
    F550_FaultInjection_DW.obj_gf.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_gf.isInitialized = 1;
    F550_FaultInjection_DW.obj_gf.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(F550_FaultInjection_DW.obj_gf.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_gf.eventStructObj);
    F550_FaultInjection_DW.obj_gf.isSetupComplete = true;

    // Start for MATLABSystem: '<S563>/LLA2LocalCoordinates'
    F550_FaultInjection_DW.obj_mr.previousValidReceived = false;
    F550_FaultInjection_DW.obj_mr.nextValidReceived = false;
    F550_FaultInjection_DW.obj_mr.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_mr.isInitialized = 1;
    F550_FaultInjection_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S602>/SourceBlock'
    F550_FaultInjection_DW.obj_gv.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_gv.isInitialized = 1;
    F550_FaultInjection_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(F550_FaultInjection_DW.obj_gv.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_gv.eventStructObj);
    F550_FaultInjection_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S600>/SourceBlock'
    F550_FaultInjection_DW.obj_po.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_po.isInitialized = 1;
    F550_FaultInjection_DW.obj_po.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(F550_FaultInjection_DW.obj_po.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_po.eventStructObj);
    F550_FaultInjection_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S601>/SourceBlock'
    F550_FaultInjection_DW.obj_d0.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_d0.isInitialized = 1;
    F550_FaultInjection_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(F550_FaultInjection_DW.obj_d0.orbMetadataObj,
                         &F550_FaultInjection_DW.obj_d0.eventStructObj);
    F550_FaultInjection_DW.obj_d0.isSetupComplete = true;

    // Start for MATLABSystem: '<S7>/Read Parameter13'
    F550_FaultInjection_DW.obj_ka.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_ka.SampleTime =
      F550_FaultInjection_P.ReadParameter13_SampleTime;
    F550_FaultInjection_DW.obj_ka.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_ka.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_ka.SampleTime;
    }

    F550_FaultInjection_DW.obj_ka.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_ka.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter13'

    // Start for MATLABSystem: '<S7>/Read Parameter1'
    F550_FaultInjection_DW.obj_a4.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_a4.SampleTime =
      F550_FaultInjection_P.ReadParameter1_SampleTime;
    F550_FaultInjection_DW.obj_a4.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_a4.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_a4.SampleTime;
    }

    F550_FaultInjection_DW.obj_a4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_a4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter1'

    // Start for MATLABSystem: '<S7>/Read Parameter2'
    F550_FaultInjection_DW.obj_ng.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_ng.SampleTime =
      F550_FaultInjection_P.ReadParameter2_SampleTime;
    F550_FaultInjection_DW.obj_ng.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_ng.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_ng.SampleTime;
    }

    F550_FaultInjection_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_ng.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/Read Parameter3'
    F550_FaultInjection_DW.obj_n.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_n.SampleTime =
      F550_FaultInjection_P.ReadParameter3_SampleTime;
    F550_FaultInjection_DW.obj_n.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_n.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_n.SampleTime;
    }

    F550_FaultInjection_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter3'

    // Start for MATLABSystem: '<S7>/Read Parameter4'
    F550_FaultInjection_DW.obj_c.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_c.SampleTime =
      F550_FaultInjection_P.ReadParameter4_SampleTime;
    F550_FaultInjection_DW.obj_c.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_c.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_c.SampleTime;
    }

    F550_FaultInjection_DW.obj_c.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter4'

    // Start for MATLABSystem: '<S7>/Read Parameter5'
    F550_FaultInjection_DW.obj_p1.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_p1.SampleTime =
      F550_FaultInjection_P.ReadParameter5_SampleTime;
    F550_FaultInjection_DW.obj_p1.isInitialized = 1;
    if (F550_FaultInjection_DW.obj_p1.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = F550_FaultInjection_DW.obj_p1.SampleTime;
    }

    F550_FaultInjection_DW.obj_p1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    F550_FaultInjection_DW.obj_p1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter5'

    // Start for MATLABSystem: '<S22>/SinkBlock' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment'

    F550_FaultInjection_DW.obj_h.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_h.isInitialized = 1;
    F550_FaultInjection_DW.obj_h.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(F550_FaultInjection_DW.obj_h.orbMetadataObj,
                          &F550_FaultInjection_DW.obj_h.orbAdvertiseObj,
                          &F550_FaultInjection_B.BusAssignment_l_p, 1);
    F550_FaultInjection_DW.obj_h.isSetupComplete = true;
    F550_FaultInjection_PX4Timestamp_Init(&F550_FaultInjection_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S599>/SinkBlock' incorporates:
    //   BusAssignment: '<S560>/Bus Assignment'

    F550_FaultInjection_DW.obj_o2.matlabCodegenIsDeleted = false;
    F550_FaultInjection_DW.obj_o2.isInitialized = 1;
    F550_FaultInjection_DW.obj_o2.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(F550_FaultInjection_DW.obj_o2.orbMetadataObj,
                          &F550_FaultInjection_DW.obj_o2.orbAdvertiseObj,
                          &F550_FaultInjection_B.BusAssignment_m_f, 1);
    F550_FaultInjection_DW.obj_o2.isSetupComplete = true;
    F550_FaultInjection_PX4Timestamp_Init(&F550_FaultInjection_DW.PX4Timestamp);
  }
}

// Model terminate function
void F550_FaultInjection_terminate(void)
{
  F550_FaultInjection_SourceBlock_Term(&F550_FaultInjection_DW.SourceBlock);

  // Terminate for MATLABSystem: '<S603>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_mg.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_mg.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_mg.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_mg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S603>/SourceBlock'

  // Terminate for MATLABSystem: '<S563>/Read Parameter'
  if (!F550_FaultInjection_DW.obj_k.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S563>/Read Parameter'

  // Terminate for MATLABSystem: '<S584>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_e.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_e.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S584>/SourceBlock'

  // Terminate for MATLABSystem: '<S582>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_kz.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_kz.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S582>/SourceBlock'

  // Terminate for MATLABSystem: '<S581>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_gf.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_gf.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S581>/SourceBlock'

  // Terminate for MATLABSystem: '<S563>/LLA2LocalCoordinates'
  if (!F550_FaultInjection_DW.obj_mr.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S563>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S602>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_gv.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_gv.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S602>/SourceBlock'

  // Terminate for MATLABSystem: '<S600>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_po.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_po.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S600>/SourceBlock'

  // Terminate for MATLABSystem: '<S601>/SourceBlock'
  if (!F550_FaultInjection_DW.obj_d0.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_d0.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&F550_FaultInjection_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S601>/SourceBlock'

  // Terminate for Enabled SubSystem: '<Root>/CLAW'
  F550_FaultInjection_CLAW_Term();

  // End of Terminate for SubSystem: '<Root>/CLAW'

  // Terminate for MATLABSystem: '<S7>/Read Parameter13'
  if (!F550_FaultInjection_DW.obj_ka.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_ka.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter13'

  // Terminate for MATLABSystem: '<S7>/Read Parameter1'
  if (!F550_FaultInjection_DW.obj_a4.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_a4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter1'

  // Terminate for MATLABSystem: '<S7>/Read Parameter2'
  if (!F550_FaultInjection_DW.obj_ng.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/Read Parameter3'
  if (!F550_FaultInjection_DW.obj_n.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter3'

  // Terminate for MATLABSystem: '<S7>/Read Parameter4'
  if (!F550_FaultInjection_DW.obj_c.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter4'

  // Terminate for MATLABSystem: '<S7>/Read Parameter5'
  if (!F550_FaultInjection_DW.obj_p1.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_p1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter5'

  // Terminate for MATLABSystem: '<S22>/SinkBlock'
  if (!F550_FaultInjection_DW.obj_h.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_h.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_h.isSetupComplete) {
      uORB_write_terminate(&F550_FaultInjection_DW.obj_h.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SinkBlock'
  F550_FaultInjection_PX4Timestamp_Term(&F550_FaultInjection_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S599>/SinkBlock'
  if (!F550_FaultInjection_DW.obj_o2.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_o2.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_o2.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_o2.isSetupComplete) {
      uORB_write_terminate(&F550_FaultInjection_DW.obj_o2.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S599>/SinkBlock'

  // Terminate for Enabled SubSystem: '<S563>/Send waypoints to OBC'
  F550_FaultInjection_MATLABSystem_Term(&F550_FaultInjection_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S592>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S595>/Read Parameter'
  if (!F550_FaultInjection_DW.obj_g.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S595>/Read Parameter'
  // End of Terminate for SubSystem: '<S592>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S592>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S594>/Read Parameter'
  if (!F550_FaultInjection_DW.obj_b.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S594>/Read Parameter'
  // End of Terminate for SubSystem: '<S592>/If Action Subsystem1'
  F550_FaultInjection_MATLABSystem_Term(&F550_FaultInjection_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S589>/MATLAB System'
  if (!F550_FaultInjection_DW.obj_mu.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S589>/MATLAB System'

  // Terminate for MATLABSystem: '<S591>/SinkBlock'
  if (!F550_FaultInjection_DW.obj_mc.matlabCodegenIsDeleted) {
    F550_FaultInjection_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((F550_FaultInjection_DW.obj_mc.isInitialized == 1) &&
        F550_FaultInjection_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&F550_FaultInjection_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S591>/SinkBlock'
  // End of Terminate for SubSystem: '<S563>/Send waypoints to OBC'
  F550_FaultInjection_PX4Timestamp_Term(&F550_FaultInjection_DW.PX4Timestamp);
}

//
// File trailer for generated code.
//
// [EOF]
//
