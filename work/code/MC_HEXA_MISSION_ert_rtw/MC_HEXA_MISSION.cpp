//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MC_HEXA_MISSION.cpp
//
// Code generated for Simulink model 'MC_HEXA_MISSION'.
//
// Model version                  : 4.139
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 10 19:48:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MC_HEXA_MISSION.h"
#include "rtwtypes.h"
#include "MC_HEXA_MISSION_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "mc_pos_controller.h"
#include "mc_att_controller.h"
#include "mc_rate_controller.h"
#include <uORB/topics/vehicle_rates_setpoint.h>
#include "rt_defines.h"
#include <float.h>

// Block signals (default storage)
B_MC_HEXA_MISSION_T MC_HEXA_MISSION_B;

// Block states (default storage)
DW_MC_HEXA_MISSION_T MC_HEXA_MISSION_DW;

// Real-time model
RT_MODEL_MC_HEXA_MISSION_T MC_HEXA_MISSION_M_ = RT_MODEL_MC_HEXA_MISSION_T();
RT_MODEL_MC_HEXA_MISSION_T *const MC_HEXA_MISSION_M = &MC_HEXA_MISSION_M_;

// Forward declaration for local functions
static real_T MC_HEXA_MISSION_sind(real_T x);

// Forward declaration for local functions
static real_T MC_HEXA_MISSION_rt_remd_snf(real_T u0, real_T u1);
static real_T MC_HEXA_MISSION_sind_a(real_T x);
static real_T MC_HEXA_MISSION_rt_atan2d_snf(real_T u0, real_T u1);
static void MC_HEXA_MISSION_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3]);
static real_T MC_HEXA_MISSION_norm(const real_T x[3]);

// System initialize for atomic system:
void MC_HEXA_MISSION_PX4Timestamp_Init(DW_PX4Timestamp_MC_HEXA_MISSION_T
  *localDW)
{
  // Start for MATLABSystem: '<S24>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void MC_HEXA_MISSION_PX4Timestamp(B_PX4Timestamp_MC_HEXA_MISSION_T *localB)
{
  // MATLABSystem: '<S24>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void MC_HEXA_MISSION_PX4Timestamp_Term(DW_PX4Timestamp_MC_HEXA_MISSION_T
  *localDW)
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

static real_T MC_HEXA_MISSION_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S583>/MATLAB System'
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

  // End of Start for MATLABSystem: '<S583>/MATLAB System'
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
void MC_HEXA_MISSION_MATLABSystem_Init(DW_MATLABSystem_MC_HEXA_MISSION_T
  *localDW)
{
  // Start for MATLABSystem: '<S583>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void MC_HEXA_MISSION_MATLABSystem(const real_T rtu_0[3], const real_T rtu_1[3],
  boolean_T rtu_2, uint8_T rtu_3, B_MATLABSystem_MC_HEXA_MISSION_T *localB)
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

  // MATLABSystem: '<S583>/MATLAB System'
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

    flat = MC_HEXA_MISSION_sind(rtu_1[0]);
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

    // MATLABSystem: '<S583>/MATLAB System'
    localB->MATLABSystem[0] = static_cast<real32_T>(r + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(r + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(r + flat);
  } else {
    // MATLABSystem: '<S583>/MATLAB System'
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S583>/MATLAB System'
}

// Termination for atomic system:
void MC_HEXA_MISSION_MATLABSystem_Term(DW_MATLABSystem_MC_HEXA_MISSION_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S583>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S583>/MATLAB System'
}

static real_T MC_HEXA_MISSION_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      MC_HEXA_MISSION_B.q = ceil(u1);
    } else {
      MC_HEXA_MISSION_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != MC_HEXA_MISSION_B.q)) {
      MC_HEXA_MISSION_B.q = fabs(u0 / u1);
      if (!(fabs(MC_HEXA_MISSION_B.q - floor(MC_HEXA_MISSION_B.q + 0.5)) >
            DBL_EPSILON * MC_HEXA_MISSION_B.q)) {
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

static real_T MC_HEXA_MISSION_sind_a(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S586>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = MC_HEXA_MISSION_rt_remd_snf(x, 360.0);
    MC_HEXA_MISSION_B.absx_p = fabs(b_x);
    if (MC_HEXA_MISSION_B.absx_p > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      MC_HEXA_MISSION_B.absx_p = fabs(b_x);
    }

    if (MC_HEXA_MISSION_B.absx_p <= 45.0) {
      b_x *= 0.017453292519943295;
      b_x = sin(b_x);
    } else if (MC_HEXA_MISSION_B.absx_p <= 135.0) {
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

  // End of Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
  return b_x;
}

static real_T MC_HEXA_MISSION_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      MC_HEXA_MISSION_B.i = 1;
    } else {
      MC_HEXA_MISSION_B.i = -1;
    }

    if (u1 > 0.0) {
      MC_HEXA_MISSION_B.i1_d = 1;
    } else {
      MC_HEXA_MISSION_B.i1_d = -1;
    }

    y = atan2(static_cast<real_T>(MC_HEXA_MISSION_B.i), static_cast<real_T>
              (MC_HEXA_MISSION_B.i1_d));
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

static void MC_HEXA_MISSION_lla2ned(const real_T lla[3], const real_T lla0[3],
  real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
  MC_HEXA_MISSION_B.dLat = lla[0] - lla0[0];
  MC_HEXA_MISSION_B.dLon = lla[1] - lla0[1];
  MC_HEXA_MISSION_B.flat = fabs(MC_HEXA_MISSION_B.dLat);
  if (MC_HEXA_MISSION_B.flat > 180.0) {
    // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
    if (rtIsNaN(MC_HEXA_MISSION_B.dLat + 180.0) || rtIsInf
        (MC_HEXA_MISSION_B.dLat + 180.0)) {
      MC_HEXA_MISSION_B.r = (rtNaN);
    } else if (MC_HEXA_MISSION_B.dLat + 180.0 == 0.0) {
      MC_HEXA_MISSION_B.r = 0.0;
    } else {
      MC_HEXA_MISSION_B.r = fmod(MC_HEXA_MISSION_B.dLat + 180.0, 360.0);
      if (MC_HEXA_MISSION_B.r == 0.0) {
        MC_HEXA_MISSION_B.r = 0.0;
      } else if (MC_HEXA_MISSION_B.dLat + 180.0 < 0.0) {
        MC_HEXA_MISSION_B.r += 360.0;
      }
    }

    MC_HEXA_MISSION_B.dLat = MC_HEXA_MISSION_B.dLat * 0.0 + (MC_HEXA_MISSION_B.r
      - 180.0);
    MC_HEXA_MISSION_B.flat = fabs(MC_HEXA_MISSION_B.dLat);
  }

  if (MC_HEXA_MISSION_B.flat > 90.0) {
    // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
    MC_HEXA_MISSION_B.flat = fabs(MC_HEXA_MISSION_B.dLat);
    MC_HEXA_MISSION_B.latp2 = (MC_HEXA_MISSION_B.flat > 90.0);

    // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
    MC_HEXA_MISSION_B.dLon += 180.0;
    MC_HEXA_MISSION_B.r = MC_HEXA_MISSION_B.dLat * static_cast<real_T>
      (MC_HEXA_MISSION_B.latp2);
    if (rtIsNaN(MC_HEXA_MISSION_B.r)) {
      MC_HEXA_MISSION_B.r = (rtNaN);
    } else if (MC_HEXA_MISSION_B.r < 0.0) {
      MC_HEXA_MISSION_B.r = -1.0;
    } else {
      MC_HEXA_MISSION_B.r = (MC_HEXA_MISSION_B.r > 0.0);
    }

    MC_HEXA_MISSION_B.dLat = (90.0 - (MC_HEXA_MISSION_B.flat *
      static_cast<real_T>(MC_HEXA_MISSION_B.latp2) - 90.0)) *
      MC_HEXA_MISSION_B.r * static_cast<real_T>(MC_HEXA_MISSION_B.latp2) +
      MC_HEXA_MISSION_B.dLat * static_cast<real_T>(!MC_HEXA_MISSION_B.latp2);
  }

  // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
  if ((MC_HEXA_MISSION_B.dLon > 180.0) || (MC_HEXA_MISSION_B.dLon < -180.0)) {
    MC_HEXA_MISSION_B.flat = MC_HEXA_MISSION_rt_remd_snf(MC_HEXA_MISSION_B.dLon,
      360.0);
    MC_HEXA_MISSION_B.r = MC_HEXA_MISSION_B.flat / 180.0;
    if (MC_HEXA_MISSION_B.r < 0.0) {
      MC_HEXA_MISSION_B.r = ceil(MC_HEXA_MISSION_B.r);
    } else {
      MC_HEXA_MISSION_B.r = floor(MC_HEXA_MISSION_B.r);
    }

    MC_HEXA_MISSION_B.dLon = (MC_HEXA_MISSION_B.flat - 360.0 *
      MC_HEXA_MISSION_B.r) + MC_HEXA_MISSION_B.dLon * 0.0;
  }

  MC_HEXA_MISSION_B.flat = MC_HEXA_MISSION_sind_a(lla0[0]);
  MC_HEXA_MISSION_B.flat_tmp = 1.0 - 0.0066943799901413165 *
    MC_HEXA_MISSION_B.flat * MC_HEXA_MISSION_B.flat;
  MC_HEXA_MISSION_B.flat = 6.378137E+6 / sqrt(MC_HEXA_MISSION_B.flat_tmp);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    MC_HEXA_MISSION_B.r = (rtNaN);
  } else {
    MC_HEXA_MISSION_B.r = MC_HEXA_MISSION_rt_remd_snf(lla0[0], 360.0);
    MC_HEXA_MISSION_B.absx = fabs(MC_HEXA_MISSION_B.r);
    if (MC_HEXA_MISSION_B.absx > 180.0) {
      if (MC_HEXA_MISSION_B.r > 0.0) {
        MC_HEXA_MISSION_B.r -= 360.0;
      } else {
        MC_HEXA_MISSION_B.r += 360.0;
      }

      MC_HEXA_MISSION_B.absx = fabs(MC_HEXA_MISSION_B.r);
    }

    if (MC_HEXA_MISSION_B.absx <= 45.0) {
      MC_HEXA_MISSION_B.r = cos(0.017453292519943295 * MC_HEXA_MISSION_B.r);
    } else if (MC_HEXA_MISSION_B.absx <= 135.0) {
      if (MC_HEXA_MISSION_B.r > 0.0) {
        MC_HEXA_MISSION_B.r = -sin((MC_HEXA_MISSION_B.r - 90.0) *
          0.017453292519943295);
      } else {
        MC_HEXA_MISSION_B.r = sin((MC_HEXA_MISSION_B.r + 90.0) *
          0.017453292519943295);
      }
    } else {
      if (MC_HEXA_MISSION_B.r > 0.0) {
        MC_HEXA_MISSION_B.r = (MC_HEXA_MISSION_B.r - 180.0) *
          0.017453292519943295;
      } else {
        MC_HEXA_MISSION_B.r = (MC_HEXA_MISSION_B.r + 180.0) *
          0.017453292519943295;
      }

      MC_HEXA_MISSION_B.r = -cos(MC_HEXA_MISSION_B.r);
    }
  }

  xyzNED[0] = MC_HEXA_MISSION_B.dLat / (MC_HEXA_MISSION_rt_atan2d_snf(1.0,
    0.99330562000985867 / MC_HEXA_MISSION_B.flat_tmp * MC_HEXA_MISSION_B.flat) *
    57.295779513082323);
  xyzNED[1] = MC_HEXA_MISSION_B.dLon / (MC_HEXA_MISSION_rt_atan2d_snf(1.0,
    MC_HEXA_MISSION_B.flat * MC_HEXA_MISSION_B.r) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  MC_HEXA_MISSION_B.b[0] = rtIsNaN(xyzNED[0]);
  MC_HEXA_MISSION_B.b[1] = rtIsNaN(xyzNED[1]);
  MC_HEXA_MISSION_B.b[2] = rtIsNaN(xyzNED[2]);
  MC_HEXA_MISSION_B.latp2 = false;
  MC_HEXA_MISSION_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (MC_HEXA_MISSION_B.b_k < 3)) {
    if (MC_HEXA_MISSION_B.b[MC_HEXA_MISSION_B.b_k]) {
      MC_HEXA_MISSION_B.latp2 = true;
      exitg1 = true;
    } else {
      MC_HEXA_MISSION_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
  MC_HEXA_MISSION_B.dLat = 0.0 / static_cast<real_T>(!MC_HEXA_MISSION_B.latp2);
  xyzNED[0] += MC_HEXA_MISSION_B.dLat;
  xyzNED[1] += MC_HEXA_MISSION_B.dLat;
  xyzNED[2] += MC_HEXA_MISSION_B.dLat;
}

static real_T MC_HEXA_MISSION_norm(const real_T x[3])
{
  real_T y;
  MC_HEXA_MISSION_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S564>/UAV Waypoint Follower'
  MC_HEXA_MISSION_B.absxk = fabs(x[0]);
  if (MC_HEXA_MISSION_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    MC_HEXA_MISSION_B.scale = MC_HEXA_MISSION_B.absxk;
  } else {
    MC_HEXA_MISSION_B.t = MC_HEXA_MISSION_B.absxk / 3.3121686421112381E-170;
    y = MC_HEXA_MISSION_B.t * MC_HEXA_MISSION_B.t;
  }

  // Start for MATLABSystem: '<S564>/UAV Waypoint Follower'
  MC_HEXA_MISSION_B.absxk = fabs(x[1]);
  if (MC_HEXA_MISSION_B.absxk > MC_HEXA_MISSION_B.scale) {
    MC_HEXA_MISSION_B.t = MC_HEXA_MISSION_B.scale / MC_HEXA_MISSION_B.absxk;
    y = y * MC_HEXA_MISSION_B.t * MC_HEXA_MISSION_B.t + 1.0;
    MC_HEXA_MISSION_B.scale = MC_HEXA_MISSION_B.absxk;
  } else {
    MC_HEXA_MISSION_B.t = MC_HEXA_MISSION_B.absxk / MC_HEXA_MISSION_B.scale;
    y += MC_HEXA_MISSION_B.t * MC_HEXA_MISSION_B.t;
  }

  // Start for MATLABSystem: '<S564>/UAV Waypoint Follower'
  MC_HEXA_MISSION_B.absxk = fabs(x[2]);
  if (MC_HEXA_MISSION_B.absxk > MC_HEXA_MISSION_B.scale) {
    MC_HEXA_MISSION_B.t = MC_HEXA_MISSION_B.scale / MC_HEXA_MISSION_B.absxk;
    y = y * MC_HEXA_MISSION_B.t * MC_HEXA_MISSION_B.t + 1.0;
    MC_HEXA_MISSION_B.scale = MC_HEXA_MISSION_B.absxk;
  } else {
    MC_HEXA_MISSION_B.t = MC_HEXA_MISSION_B.absxk / MC_HEXA_MISSION_B.scale;
    y += MC_HEXA_MISSION_B.t * MC_HEXA_MISSION_B.t;
  }

  return MC_HEXA_MISSION_B.scale * sqrt(y);
}

// Model step function
void MC_HEXA_MISSION_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;

  // MATLABSystem: '<S19>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_da.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_da.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_cv, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S19>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  // Start for MATLABSystem: '<S19>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S20>/In1'
    MC_HEXA_MISSION_B.In1_k = MC_HEXA_MISSION_B.b_varargout_2_cv;
  }

  // End of Outputs for SubSystem: '<S19>/Enabled Subsystem'

  // RelationalOperator: '<S11>/Compare' incorporates:
  //   Constant: '<S11>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  MC_HEXA_MISSION_B.Compare_k = (MC_HEXA_MISSION_B.In1_k.values[6] >=
    MC_HEXA_MISSION_P.CompareToConstant_const);

  // MATLABSystem: '<S598>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_d0.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_d0.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_n, false, 1.0);

  // Outputs for Enabled SubSystem: '<S598>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S602>/Enable'

  // Start for MATLABSystem: '<S598>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S602>/In1'
    MC_HEXA_MISSION_B.In1_b = MC_HEXA_MISSION_B.b_varargout_2_n;
  }

  // End of Outputs for SubSystem: '<S598>/Enabled Subsystem'

  // MATLABSystem: '<S560>/Read Parameter'
  if (MC_HEXA_MISSION_DW.obj_k.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter_SampleTime_d) {
    MC_HEXA_MISSION_DW.obj_k.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter_SampleTime_d;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step(MC_HEXA_MISSION_DW.obj_k.MW_PARAMHANDLE,
    MW_INT32, &MC_HEXA_MISSION_B.ParamStep_l);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_l = 0;
  }

  // MATLABSystem: '<S581>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_e.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_e.eventStructObj, &MC_HEXA_MISSION_B.b_varargout_2,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S581>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S582>/Enable'

  // Start for MATLABSystem: '<S581>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S582>/In1'
    MC_HEXA_MISSION_B.In1 = MC_HEXA_MISSION_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S581>/Enabled Subsystem'

  // MATLABSystem: '<S579>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_kz.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_kz.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S579>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S594>/Enable'

  // Start for MATLABSystem: '<S579>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S594>/In1'
    MC_HEXA_MISSION_B.In1_p = MC_HEXA_MISSION_B.b_varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S579>/Enabled Subsystem'

  // MATLABSystem: '<S578>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_gff.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_gff.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_g1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S578>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S593>/Enable'

  // Start for MATLABSystem: '<S578>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S593>/In1'
    MC_HEXA_MISSION_B.In1_f = MC_HEXA_MISSION_B.b_varargout_2_g1;
  }

  // End of Outputs for SubSystem: '<S578>/Enabled Subsystem'

  // MATLABSystem: '<S560>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S560>/Read Parameter'
  //   SignalConversion generated from: '<S593>/In1'
  //
  MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] = 0.0;
  MC_HEXA_MISSION_B.MatrixConcatenate1[0] = 0.0;
  MC_HEXA_MISSION_B.b_varargout_3[0] = 0.0;
  MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] = 0.0;
  MC_HEXA_MISSION_B.MatrixConcatenate1[1] = 0.0;
  MC_HEXA_MISSION_B.b_varargout_3[1] = 0.0;
  MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] = 0.0;
  MC_HEXA_MISSION_B.MatrixConcatenate1[2] = 0.0;
  MC_HEXA_MISSION_B.b_varargout_3[2] = 0.0;
  MC_HEXA_MISSION_B.lla0[0] = MC_HEXA_MISSION_B.In1_f.lat;
  MC_HEXA_MISSION_B.lla0[1] = MC_HEXA_MISSION_B.In1_f.lon;
  MC_HEXA_MISSION_B.lla0[2] = MC_HEXA_MISSION_B.In1_f.alt;
  if (MC_HEXA_MISSION_B.In1_p.previous.valid &&
      (!MC_HEXA_MISSION_DW.obj_mr.previousValidReceived)) {
    MC_HEXA_MISSION_DW.obj_mr.previousValidReceived = true;
  }

  if (MC_HEXA_MISSION_B.In1_p.next.valid &&
      (!MC_HEXA_MISSION_DW.obj_mr.nextValidReceived)) {
    MC_HEXA_MISSION_DW.obj_mr.nextValidReceived = true;
  }

  if (MC_HEXA_MISSION_B.In1_f.valid_hpos &&
      MC_HEXA_MISSION_B.In1_p.current.valid &&
      (MC_HEXA_MISSION_B.In1_p.current.type != 5)) {
    if (MC_HEXA_MISSION_B.ParamStep_l != 0) {
      MC_HEXA_MISSION_B.MatrixConcatenate1[0] = MC_HEXA_MISSION_B.In1.waypoints
        [0].position[0];
      MC_HEXA_MISSION_B.MatrixConcatenate1[1] = MC_HEXA_MISSION_B.In1.waypoints
        [0].position[1];
      MC_HEXA_MISSION_B.MatrixConcatenate1[2] = MC_HEXA_MISSION_B.In1.waypoints
        [0].position[2];
    } else {
      MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] =
        MC_HEXA_MISSION_B.In1_p.current.lat;
      MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] =
        MC_HEXA_MISSION_B.In1_p.current.lon;
      MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] =
        MC_HEXA_MISSION_B.In1_p.current.alt;
      MC_HEXA_MISSION_lla2ned(MC_HEXA_MISSION_B.rtb_CastToDouble_m,
        MC_HEXA_MISSION_B.lla0, MC_HEXA_MISSION_B.MatrixConcatenate1);
    }
  }

  if (MC_HEXA_MISSION_B.In1_f.valid_hpos &&
      (MC_HEXA_MISSION_B.In1_p.previous.valid ||
       MC_HEXA_MISSION_DW.obj_mr.previousValidReceived)) {
    MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] =
      MC_HEXA_MISSION_B.In1_p.previous.lat;
    MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] =
      MC_HEXA_MISSION_B.In1_p.previous.lon;
    MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] =
      MC_HEXA_MISSION_B.In1_p.previous.alt;
    MC_HEXA_MISSION_lla2ned(MC_HEXA_MISSION_B.rtb_CastToDouble_m,
      MC_HEXA_MISSION_B.lla0, MC_HEXA_MISSION_B.MatrixConcatenate1_k);
  }

  if (MC_HEXA_MISSION_B.In1_f.valid_hpos && (MC_HEXA_MISSION_B.In1_p.next.valid ||
       MC_HEXA_MISSION_DW.obj_mr.nextValidReceived)) {
    MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] = MC_HEXA_MISSION_B.In1_p.next.lat;
    MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] = MC_HEXA_MISSION_B.In1_p.next.lon;
    MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] = MC_HEXA_MISSION_B.In1_p.next.alt;
    MC_HEXA_MISSION_lla2ned(MC_HEXA_MISSION_B.rtb_CastToDouble_m,
      MC_HEXA_MISSION_B.lla0, MC_HEXA_MISSION_B.b_varargout_3);
  }

  // MATLABSystem: '<S600>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_mg.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_mg.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S600>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S604>/Enable'

  // Start for MATLABSystem: '<S600>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S604>/In1'
    MC_HEXA_MISSION_B.In1_c = MC_HEXA_MISSION_B.b_varargout_2_cx;
  }

  // End of Outputs for SubSystem: '<S600>/Enabled Subsystem'

  // If: '<S559>/If' incorporates:
  //   Delay: '<S565>/Delay'
  //   Delay: '<S568>/Delay'
  //   Delay: '<S572>/Delay'
  //   MATLABSystem: '<S560>/LLA2LocalCoordinates'
  //
  MC_HEXA_MISSION_B.rtPrevAction = MC_HEXA_MISSION_DW.If_ActiveSubsystem;
  if (MC_HEXA_MISSION_B.In1_p.current.type == 3) {
    MC_HEXA_MISSION_B.rtAction = 0;
  } else if (MC_HEXA_MISSION_B.In1_p.current.type == 4) {
    MC_HEXA_MISSION_B.rtAction = 1;
  } else if (MC_HEXA_MISSION_B.In1_p.current.type == 0) {
    MC_HEXA_MISSION_B.rtAction = 2;
  } else {
    MC_HEXA_MISSION_B.rtAction = 3;
  }

  MC_HEXA_MISSION_DW.If_ActiveSubsystem = MC_HEXA_MISSION_B.rtAction;
  switch (MC_HEXA_MISSION_B.rtAction) {
   case 0:
    if (MC_HEXA_MISSION_B.rtAction != MC_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S559>/Take-off' incorporates:
      //   ActionPort: '<S563>/Action Port'

      // InitializeConditions for If: '<S559>/If' incorporates:
      //   Delay: '<S571>/Delay'
      //   Delay: '<S572>/Delay'

      MC_HEXA_MISSION_DW.Delay_DSTATE_c =
        MC_HEXA_MISSION_P.Delay_InitialCondition;
      MC_HEXA_MISSION_DW.Delay_DSTATE_d =
        MC_HEXA_MISSION_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S559>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S559>/Take-off' incorporates:
    //   ActionPort: '<S563>/Action Port'

    // Sum: '<S571>/Sum' incorporates:
    //   Constant: '<S571>/Rate'
    //   Delay: '<S571>/Delay'

    MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Rate_Value +
      MC_HEXA_MISSION_DW.Delay_DSTATE_c;

    // Gain: '<S571>/Gain1'
    MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_P.Gain1_Gain_b *
      MC_HEXA_MISSION_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S572>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S573>/Enable'

    if (MC_HEXA_MISSION_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S573>/yaw_In' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Double'

      MC_HEXA_MISSION_B.yaw_In_ik = MC_HEXA_MISSION_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S572>/Enabled Subsystem2'

    // Reshape: '<S563>/Reshape' incorporates:
    //   Delay: '<S572>/Delay'
    //   Merge: '<S559>/Merge'

    MC_HEXA_MISSION_B.Merge[0] = MC_HEXA_MISSION_B.MatrixConcatenate1[0];
    MC_HEXA_MISSION_B.Merge[1] = MC_HEXA_MISSION_B.MatrixConcatenate1[1];

    // Gain: '<S571>/Gain' incorporates:
    //   RelationalOperator: '<S571>/Relational Operator'
    //   Switch: '<S571>/Switch'

    if (!(MC_HEXA_MISSION_B.Gain_i <= MC_HEXA_MISSION_B.Sum_f)) {
      MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.Sum_f;
    }

    // Reshape: '<S563>/Reshape' incorporates:
    //   Gain: '<S571>/Gain'
    //   Merge: '<S559>/Merge'
    //   Switch: '<S571>/Switch'

    MC_HEXA_MISSION_B.Merge[2] = MC_HEXA_MISSION_P.Gain_Gain_e *
      MC_HEXA_MISSION_B.Gain_i;
    MC_HEXA_MISSION_B.Merge[3] = MC_HEXA_MISSION_B.yaw_In_ik;

    // Update for Delay: '<S571>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_c = MC_HEXA_MISSION_B.Sum_f;

    // Update for Delay: '<S572>/Delay' incorporates:
    //   Constant: '<S572>/Constant'

    MC_HEXA_MISSION_DW.Delay_DSTATE_d = MC_HEXA_MISSION_P.Constant_Value_fo;

    // End of Outputs for SubSystem: '<S559>/Take-off'
    break;

   case 1:
    if (MC_HEXA_MISSION_B.rtAction != MC_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S559>/Land' incorporates:
      //   ActionPort: '<S562>/Action Port'

      // InitializeConditions for If: '<S559>/If' incorporates:
      //   Delay: '<S562>/Delay'
      //   Delay: '<S567>/Delay'
      //   Delay: '<S568>/Delay'

      MC_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
        MC_HEXA_MISSION_P.Delay_InitialCondition_n;
      MC_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
        MC_HEXA_MISSION_P.Delay_InitialCondition_n;
      MC_HEXA_MISSION_DW.Delay_DSTATE_n =
        MC_HEXA_MISSION_P.Delay_InitialCondition_m;
      MC_HEXA_MISSION_DW.Delay_DSTATE_b =
        MC_HEXA_MISSION_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S559>/Land'
    }

    // Outputs for IfAction SubSystem: '<S559>/Land' incorporates:
    //   ActionPort: '<S562>/Action Port'

    // Delay: '<S567>/Delay'
    MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_DW.Delay_DSTATE_n;

    // Switch: '<S567>/Switch' incorporates:
    //   Delay: '<S567>/Delay'
    //   Gain: '<S567>/Gain'

    if (!(MC_HEXA_MISSION_DW.Delay_DSTATE_n >
          MC_HEXA_MISSION_P.Switch_Threshold_j)) {
      MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Gain_Gain_ls *
        MC_HEXA_MISSION_B.MatrixConcatenate1_k[2];
    }

    // End of Switch: '<S567>/Switch'

    // Sum: '<S567>/Subtract' incorporates:
    //   Constant: '<S567>/Rate of descent'

    MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.Sum_f -
      MC_HEXA_MISSION_P.Rateofdescent_Value;

    // Gain: '<S567>/Gain2'
    MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Gain2_Gain *
      MC_HEXA_MISSION_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S568>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S570>/Enable'

    if (MC_HEXA_MISSION_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S570>/yaw_In' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Double'

      MC_HEXA_MISSION_B.yaw_In_i = MC_HEXA_MISSION_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S568>/Enabled Subsystem2'

    // Switch: '<S562>/Switch' incorporates:
    //   Delay: '<S568>/Delay'
    //   Logic: '<S562>/OR'
    //   RelationalOperator: '<S562>/IsNaN'

    if (rtIsNaN(MC_HEXA_MISSION_B.MatrixConcatenate1[0]) || rtIsNaN
        (MC_HEXA_MISSION_B.MatrixConcatenate1[1])) {
      // Reshape: '<S562>/Reshape' incorporates:
      //   Delay: '<S562>/Delay'
      //   Merge: '<S559>/Merge'

      MC_HEXA_MISSION_B.Merge[0] = MC_HEXA_MISSION_DW.Delay_DSTATE_l[0];
      MC_HEXA_MISSION_B.Merge[1] = MC_HEXA_MISSION_DW.Delay_DSTATE_l[1];
    } else {
      // Reshape: '<S562>/Reshape' incorporates:
      //   Delay: '<S562>/Delay'
      //   Merge: '<S559>/Merge'

      MC_HEXA_MISSION_B.Merge[0] = MC_HEXA_MISSION_B.MatrixConcatenate1[0];
      MC_HEXA_MISSION_B.Merge[1] = MC_HEXA_MISSION_B.MatrixConcatenate1[1];
    }

    // End of Switch: '<S562>/Switch'

    // Reshape: '<S562>/Reshape' incorporates:
    //   Gain: '<S567>/Gain1'
    //   Merge: '<S559>/Merge'
    //   RelationalOperator: '<S567>/GreaterThan'
    //   Switch: '<S567>/Switch1'

    if (!(MC_HEXA_MISSION_B.Sum_f > MC_HEXA_MISSION_B.Gain_i)) {
      MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.Gain_i;
    }

    MC_HEXA_MISSION_B.Merge[2] = MC_HEXA_MISSION_P.Gain1_Gain_a *
      MC_HEXA_MISSION_B.Sum_f;
    MC_HEXA_MISSION_B.Merge[3] = MC_HEXA_MISSION_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S567>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S569>/Enable'

    if (MC_HEXA_MISSION_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S569>/In'
      MC_HEXA_MISSION_B.In = MC_HEXA_MISSION_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S567>/Enabled Subsystem'

    // Update for Delay: '<S562>/Delay' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double'

    MC_HEXA_MISSION_DW.Delay_DSTATE_l[0] = MC_HEXA_MISSION_B.In1_c.x;
    MC_HEXA_MISSION_DW.Delay_DSTATE_l[1] = MC_HEXA_MISSION_B.In1_c.y;

    // Update for Delay: '<S567>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_n = MC_HEXA_MISSION_B.In;

    // Update for Delay: '<S568>/Delay' incorporates:
    //   Constant: '<S568>/Constant'

    MC_HEXA_MISSION_DW.Delay_DSTATE_b = MC_HEXA_MISSION_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S559>/Land'
    break;

   case 2:
    if (MC_HEXA_MISSION_B.rtAction != MC_HEXA_MISSION_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S559>/Waypoint' incorporates:
      //   ActionPort: '<S564>/Action Port'

      // SystemReset for If: '<S559>/If' incorporates:
      //   MATLABSystem: '<S564>/UAV Waypoint Follower'
      //
      MC_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
      for (MC_HEXA_MISSION_B.i1 = 0; MC_HEXA_MISSION_B.i1 < 9;
           MC_HEXA_MISSION_B.i1++) {
        MC_HEXA_MISSION_DW.obj.WaypointsInternal[MC_HEXA_MISSION_B.i1] *= 0.0;
      }

      // End of SystemReset for If: '<S559>/If'
      // End of SystemReset for SubSystem: '<S559>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S559>/Waypoint' incorporates:
    //   ActionPort: '<S564>/Action Port'

    // Concatenate: '<S564>/Matrix Concatenate'
    MC_HEXA_MISSION_B.MatrixConcatenate_p[0] =
      MC_HEXA_MISSION_B.MatrixConcatenate1_k[0];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[1] =
      MC_HEXA_MISSION_B.MatrixConcatenate1[0];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[2] = MC_HEXA_MISSION_B.b_varargout_3[0];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[3] =
      MC_HEXA_MISSION_B.MatrixConcatenate1_k[1];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[4] =
      MC_HEXA_MISSION_B.MatrixConcatenate1[1];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[5] = MC_HEXA_MISSION_B.b_varargout_3[1];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[6] =
      MC_HEXA_MISSION_B.MatrixConcatenate1_k[2];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[7] =
      MC_HEXA_MISSION_B.MatrixConcatenate1[2];
    MC_HEXA_MISSION_B.MatrixConcatenate_p[8] = MC_HEXA_MISSION_B.b_varargout_3[2];

    // MATLABSystem: '<S564>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S564>/Matrix Concatenate'
    //   Constant: '<S564>/Constant'

    MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Constant_Value_gw;
    MC_HEXA_MISSION_DW.obj.LookaheadDistFlag = 0U;
    if (MC_HEXA_MISSION_P.Constant_Value_gw < 0.3) {
      MC_HEXA_MISSION_B.Sum_f = 0.3;
      MC_HEXA_MISSION_DW.obj.LookaheadDistFlag = 1U;
    }

    MC_HEXA_MISSION_DW.obj.InitialPose[0] = 0.0;
    MC_HEXA_MISSION_DW.obj.InitialPose[1] = 0.0;
    MC_HEXA_MISSION_DW.obj.InitialPose[2] = 0.0;
    MC_HEXA_MISSION_DW.obj.InitialPose[3] = 0.0;
    MC_HEXA_MISSION_DW.obj.NumWaypoints = 3.0;
    MC_HEXA_MISSION_B.OR_g = false;
    MC_HEXA_MISSION_B.Compare = true;
    MC_HEXA_MISSION_B.iy = 0;
    exitg1 = false;
    while ((!exitg1) && (MC_HEXA_MISSION_B.iy <= 8)) {
      MC_HEXA_MISSION_B.i1 = MC_HEXA_MISSION_B.iy / 3 * 3 + MC_HEXA_MISSION_B.iy
        % 3;
      if (!(MC_HEXA_MISSION_DW.obj.WaypointsInternal[MC_HEXA_MISSION_B.i1] ==
            MC_HEXA_MISSION_B.MatrixConcatenate_p[MC_HEXA_MISSION_B.i1])) {
        MC_HEXA_MISSION_B.Compare = false;
        exitg1 = true;
      } else {
        MC_HEXA_MISSION_B.iy++;
      }
    }

    if (MC_HEXA_MISSION_B.Compare) {
      MC_HEXA_MISSION_B.OR_g = true;
    }

    if (!MC_HEXA_MISSION_B.OR_g) {
      memcpy(&MC_HEXA_MISSION_DW.obj.WaypointsInternal[0],
             &MC_HEXA_MISSION_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      MC_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
    }

    MC_HEXA_MISSION_B.i1 = 0;
    MC_HEXA_MISSION_B.iy = 0;
    for (MC_HEXA_MISSION_B.j = 0; MC_HEXA_MISSION_B.j < 3; MC_HEXA_MISSION_B.j++)
    {
      MC_HEXA_MISSION_B.distinctWptsIdx[MC_HEXA_MISSION_B.j] = true;
      MC_HEXA_MISSION_B.Gain_i =
        MC_HEXA_MISSION_B.MatrixConcatenate_p[MC_HEXA_MISSION_B.i1 + 1];
      MC_HEXA_MISSION_B.x[MC_HEXA_MISSION_B.iy] = (MC_HEXA_MISSION_B.Gain_i !=
        MC_HEXA_MISSION_B.MatrixConcatenate_p[MC_HEXA_MISSION_B.i1]);
      MC_HEXA_MISSION_B.x[MC_HEXA_MISSION_B.iy + 1] =
        (MC_HEXA_MISSION_B.MatrixConcatenate_p[MC_HEXA_MISSION_B.i1 + 2] !=
         MC_HEXA_MISSION_B.Gain_i);
      MC_HEXA_MISSION_B.i1 += 3;
      MC_HEXA_MISSION_B.iy += 2;
    }

    MC_HEXA_MISSION_B.IsNaN_l[0] = false;
    MC_HEXA_MISSION_B.IsNaN_l[1] = false;
    MC_HEXA_MISSION_B.i1 = 0;
    MC_HEXA_MISSION_B.iy = 4;
    for (MC_HEXA_MISSION_B.j = 0; MC_HEXA_MISSION_B.j < 2; MC_HEXA_MISSION_B.j++)
    {
      MC_HEXA_MISSION_B.i1++;
      MC_HEXA_MISSION_B.iy++;
      MC_HEXA_MISSION_B.ix = MC_HEXA_MISSION_B.i1;
      exitg1 = false;
      while ((!exitg1) && (MC_HEXA_MISSION_B.ix <= MC_HEXA_MISSION_B.iy)) {
        if (MC_HEXA_MISSION_B.x[MC_HEXA_MISSION_B.ix - 1]) {
          MC_HEXA_MISSION_B.IsNaN_l[MC_HEXA_MISSION_B.j] = true;
          exitg1 = true;
        } else {
          MC_HEXA_MISSION_B.ix += 2;
        }
      }
    }

    MC_HEXA_MISSION_B.distinctWptsIdx[0] = MC_HEXA_MISSION_B.IsNaN_l[0];
    MC_HEXA_MISSION_B.distinctWptsIdx[1] = MC_HEXA_MISSION_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S559>/Waypoint'
    MC_HEXA_MISSION_B.iy = 0;
    for (MC_HEXA_MISSION_B.i1 = 0; MC_HEXA_MISSION_B.i1 < 3;
         MC_HEXA_MISSION_B.i1++) {
      // Outputs for IfAction SubSystem: '<S559>/Waypoint' incorporates:
      //   ActionPort: '<S564>/Action Port'

      if (MC_HEXA_MISSION_B.distinctWptsIdx[MC_HEXA_MISSION_B.i1]) {
        MC_HEXA_MISSION_B.iy++;
      }

      // End of Outputs for SubSystem: '<S559>/Waypoint'
    }

    MC_HEXA_MISSION_B.j = MC_HEXA_MISSION_B.iy;
    MC_HEXA_MISSION_B.iy = 0;
    for (MC_HEXA_MISSION_B.i1 = 0; MC_HEXA_MISSION_B.i1 < 3;
         MC_HEXA_MISSION_B.i1++) {
      // Outputs for IfAction SubSystem: '<S559>/Waypoint' incorporates:
      //   ActionPort: '<S564>/Action Port'

      if (MC_HEXA_MISSION_B.distinctWptsIdx[MC_HEXA_MISSION_B.i1]) {
        // Start for MATLABSystem: '<S564>/UAV Waypoint Follower'
        MC_HEXA_MISSION_B.tmp_data[MC_HEXA_MISSION_B.iy] = static_cast<int8_T>
          (MC_HEXA_MISSION_B.i1);
        MC_HEXA_MISSION_B.iy++;
      }

      // End of Outputs for SubSystem: '<S559>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S559>/Waypoint' incorporates:
    //   ActionPort: '<S564>/Action Port'

    // MATLABSystem: '<S564>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S564>/Matrix Concatenate'
    //   DataTypeConversion: '<Root>/Cast To Double'

    for (MC_HEXA_MISSION_B.i1 = 0; MC_HEXA_MISSION_B.i1 < 3;
         MC_HEXA_MISSION_B.i1++) {
      for (MC_HEXA_MISSION_B.iy = 0; MC_HEXA_MISSION_B.iy < MC_HEXA_MISSION_B.j;
           MC_HEXA_MISSION_B.iy++) {
        MC_HEXA_MISSION_B.b_waypointsIn_data[MC_HEXA_MISSION_B.iy +
          MC_HEXA_MISSION_B.j * MC_HEXA_MISSION_B.i1] =
          MC_HEXA_MISSION_B.MatrixConcatenate_p[3 * MC_HEXA_MISSION_B.i1 +
          MC_HEXA_MISSION_B.tmp_data[MC_HEXA_MISSION_B.iy]];
      }
    }

    MC_HEXA_MISSION_DW.obj.LookaheadDistance = MC_HEXA_MISSION_B.Sum_f;
    if (MC_HEXA_MISSION_B.j == 0) {
      MC_HEXA_MISSION_B.lla0[0] = MC_HEXA_MISSION_B.In1_c.x;
      MC_HEXA_MISSION_B.lla0[1] = MC_HEXA_MISSION_B.In1_c.y;
      MC_HEXA_MISSION_B.lla0[2] = MC_HEXA_MISSION_B.In1_c.z;
      MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.In1_c.heading;
    } else {
      guard1 = false;
      if (MC_HEXA_MISSION_B.j == 1) {
        if (MC_HEXA_MISSION_DW.obj.StartFlag) {
          MC_HEXA_MISSION_DW.obj.InitialPose[0] = MC_HEXA_MISSION_B.In1_c.x;
          MC_HEXA_MISSION_DW.obj.InitialPose[1] = MC_HEXA_MISSION_B.In1_c.y;
          MC_HEXA_MISSION_DW.obj.InitialPose[2] = MC_HEXA_MISSION_B.In1_c.z;
          MC_HEXA_MISSION_DW.obj.InitialPose[3] =
            MC_HEXA_MISSION_B.In1_c.heading;
        }

        MC_HEXA_MISSION_B.b_varargout_3[0] =
          MC_HEXA_MISSION_B.b_waypointsIn_data[0] - MC_HEXA_MISSION_B.In1_c.x;
        MC_HEXA_MISSION_B.b_varargout_3[1] =
          MC_HEXA_MISSION_B.b_waypointsIn_data[1] - MC_HEXA_MISSION_B.In1_c.y;
        MC_HEXA_MISSION_B.b_varargout_3[2] =
          MC_HEXA_MISSION_B.b_waypointsIn_data[2] - MC_HEXA_MISSION_B.In1_c.z;
        if (MC_HEXA_MISSION_norm(MC_HEXA_MISSION_B.b_varargout_3) <
            1.4901161193847656E-8) {
          MC_HEXA_MISSION_B.lla0[0] = MC_HEXA_MISSION_B.In1_c.x;
          MC_HEXA_MISSION_B.lla0[1] = MC_HEXA_MISSION_B.In1_c.y;
          MC_HEXA_MISSION_B.lla0[2] = MC_HEXA_MISSION_B.In1_c.z;
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.In1_c.heading;
          MC_HEXA_MISSION_DW.obj.StartFlag = false;
        } else {
          MC_HEXA_MISSION_DW.obj.StartFlag = false;
          MC_HEXA_MISSION_DW.obj.NumWaypoints = 2.0;
          MC_HEXA_MISSION_B.ix = MC_HEXA_MISSION_B.j + 1;
          for (MC_HEXA_MISSION_B.i1 = 0; MC_HEXA_MISSION_B.i1 < 3;
               MC_HEXA_MISSION_B.i1++) {
            MC_HEXA_MISSION_B.waypoints_data_tmp = (MC_HEXA_MISSION_B.j + 1) *
              MC_HEXA_MISSION_B.i1;
            MC_HEXA_MISSION_B.MatrixConcatenate_p[MC_HEXA_MISSION_B.waypoints_data_tmp]
              = MC_HEXA_MISSION_DW.obj.InitialPose[MC_HEXA_MISSION_B.i1];
            for (MC_HEXA_MISSION_B.iy = 0; MC_HEXA_MISSION_B.iy <
                 MC_HEXA_MISSION_B.j; MC_HEXA_MISSION_B.iy++) {
              MC_HEXA_MISSION_B.MatrixConcatenate_p[(MC_HEXA_MISSION_B.iy +
                MC_HEXA_MISSION_B.waypoints_data_tmp) + 1] =
                MC_HEXA_MISSION_B.b_waypointsIn_data[MC_HEXA_MISSION_B.j *
                MC_HEXA_MISSION_B.i1 + MC_HEXA_MISSION_B.iy];
            }
          }

          guard1 = true;
        }
      } else {
        MC_HEXA_MISSION_B.ix = MC_HEXA_MISSION_B.j;
        MC_HEXA_MISSION_B.j *= 3;
        if (MC_HEXA_MISSION_B.j - 1 >= 0) {
          memcpy(&MC_HEXA_MISSION_B.MatrixConcatenate_p[0],
                 &MC_HEXA_MISSION_B.b_waypointsIn_data[0], static_cast<uint32_T>
                 (MC_HEXA_MISSION_B.j) * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        MC_HEXA_MISSION_B.OR_g = false;
        if (MC_HEXA_MISSION_DW.obj.WaypointIndex ==
            MC_HEXA_MISSION_DW.obj.NumWaypoints) {
          MC_HEXA_MISSION_B.OR_g = true;
        }

        if (MC_HEXA_MISSION_B.OR_g) {
          MC_HEXA_MISSION_DW.obj.LastWaypointFlag = true;
          MC_HEXA_MISSION_DW.obj.WaypointIndex--;
        }

        MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] = MC_HEXA_MISSION_B.In1_c.x -
          MC_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
          (MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
        MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] = MC_HEXA_MISSION_B.In1_c.y -
          MC_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
          (MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) + MC_HEXA_MISSION_B.ix) -
          1];
        MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] = MC_HEXA_MISSION_B.In1_c.z -
          MC_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
          (MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) + (MC_HEXA_MISSION_B.ix <<
          1)) - 1];
        guard2 = false;
        if (MC_HEXA_MISSION_norm(MC_HEXA_MISSION_B.rtb_CastToDouble_m) <= 2.0) {
          guard2 = true;
        } else {
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.MatrixConcatenate_p[
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] = MC_HEXA_MISSION_B.Sum_f -
            MC_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (MC_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1[0] = MC_HEXA_MISSION_B.In1_c.x -
            MC_HEXA_MISSION_B.Sum_f;
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.MatrixConcatenate_p[(
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            MC_HEXA_MISSION_B.ix) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] = MC_HEXA_MISSION_B.Sum_f -
            MC_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (MC_HEXA_MISSION_DW.obj.WaypointIndex) + MC_HEXA_MISSION_B.ix) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1[1] = MC_HEXA_MISSION_B.In1_c.y -
            MC_HEXA_MISSION_B.Sum_f;
          MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.MatrixConcatenate_p[(
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            (MC_HEXA_MISSION_B.ix << 1)) - 1];
          MC_HEXA_MISSION_B.Gain2_g = MC_HEXA_MISSION_B.MatrixConcatenate_p
            [((MC_HEXA_MISSION_B.ix << 1) + static_cast<int32_T>
              (MC_HEXA_MISSION_DW.obj.WaypointIndex)) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] = MC_HEXA_MISSION_B.Gain_i -
            MC_HEXA_MISSION_B.Gain2_g;
          MC_HEXA_MISSION_B.MatrixConcatenate1[2] = MC_HEXA_MISSION_B.In1_c.z -
            MC_HEXA_MISSION_B.Gain_i;
          MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_norm
            (MC_HEXA_MISSION_B.MatrixConcatenate1_k);
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_norm
            (MC_HEXA_MISSION_B.MatrixConcatenate1);
          MC_HEXA_MISSION_B.Sum_f = (MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] /
            MC_HEXA_MISSION_B.u0 * (MC_HEXA_MISSION_B.MatrixConcatenate1[0] /
            MC_HEXA_MISSION_B.Sum_f) + MC_HEXA_MISSION_B.MatrixConcatenate1_k[1]
            / MC_HEXA_MISSION_B.u0 * (MC_HEXA_MISSION_B.MatrixConcatenate1[1] /
            MC_HEXA_MISSION_B.Sum_f)) + MC_HEXA_MISSION_B.MatrixConcatenate1_k[2]
            / MC_HEXA_MISSION_B.u0 * (MC_HEXA_MISSION_B.MatrixConcatenate1[2] /
            MC_HEXA_MISSION_B.Sum_f);
          if (rtIsNaN(MC_HEXA_MISSION_B.Sum_f) || (MC_HEXA_MISSION_B.Sum_f < 0.0))
          {
            MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
              MC_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
              (MC_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
            MC_HEXA_MISSION_B.lla0[0] = MC_HEXA_MISSION_B.MatrixConcatenate_p[
              static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) -
              1];
            MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
              MC_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
              (MC_HEXA_MISSION_DW.obj.WaypointIndex) + MC_HEXA_MISSION_B.ix) - 1];
            MC_HEXA_MISSION_B.lla0[1] = MC_HEXA_MISSION_B.MatrixConcatenate_p[(
              static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
              MC_HEXA_MISSION_B.ix) - 1];
            MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
              MC_HEXA_MISSION_B.Gain2_g;
            MC_HEXA_MISSION_B.lla0[2] = MC_HEXA_MISSION_B.Gain_i;
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          MC_HEXA_MISSION_DW.obj.WaypointIndex++;
          MC_HEXA_MISSION_B.OR_g = false;
          if (MC_HEXA_MISSION_DW.obj.WaypointIndex ==
              MC_HEXA_MISSION_DW.obj.NumWaypoints) {
            MC_HEXA_MISSION_B.OR_g = true;
          }

          if (MC_HEXA_MISSION_B.OR_g) {
            MC_HEXA_MISSION_DW.obj.LastWaypointFlag = true;
            MC_HEXA_MISSION_DW.obj.WaypointIndex--;
          }

          MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] =
            MC_HEXA_MISSION_B.MatrixConcatenate_p[static_cast<int32_T>
            (MC_HEXA_MISSION_DW.obj.WaypointIndex) - 1];
          MC_HEXA_MISSION_B.lla0[0] = MC_HEXA_MISSION_B.MatrixConcatenate_p[
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] =
            MC_HEXA_MISSION_B.MatrixConcatenate_p[(static_cast<int32_T>
            (MC_HEXA_MISSION_DW.obj.WaypointIndex) + MC_HEXA_MISSION_B.ix) - 1];
          MC_HEXA_MISSION_B.lla0[1] = MC_HEXA_MISSION_B.MatrixConcatenate_p[(
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            MC_HEXA_MISSION_B.ix) - 1];
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] =
            MC_HEXA_MISSION_B.MatrixConcatenate_p[((MC_HEXA_MISSION_B.ix << 1) +
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex)) - 1];
          MC_HEXA_MISSION_B.lla0[2] = MC_HEXA_MISSION_B.MatrixConcatenate_p[(
            static_cast<int32_T>(MC_HEXA_MISSION_DW.obj.WaypointIndex + 1.0) +
            (MC_HEXA_MISSION_B.ix << 1)) - 1];
        }

        MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.In1_c.x -
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[0];
        MC_HEXA_MISSION_B.MatrixConcatenate1[0] = MC_HEXA_MISSION_B.Gain_i;
        MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_B.lla0[0] -
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[0];
        MC_HEXA_MISSION_B.b_varargout_3[0] = MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.Gain_i *
          MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 = MC_HEXA_MISSION_B.Switch2_a *
          MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = MC_HEXA_MISSION_B.In1_c.y -
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[1];
        MC_HEXA_MISSION_B.MatrixConcatenate1[1] =
          MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1;
        MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_B.lla0[1] -
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[1];
        MC_HEXA_MISSION_B.b_varargout_3[1] = MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.Sum_f += MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
          MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 += MC_HEXA_MISSION_B.Switch2_a *
          MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.Gain2_g = MC_HEXA_MISSION_B.In1_c.z -
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[2];
        MC_HEXA_MISSION_B.MatrixConcatenate1[2] = MC_HEXA_MISSION_B.Gain2_g;
        MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_B.lla0[2] -
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[2];
        MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 += MC_HEXA_MISSION_B.Switch2_a *
          MC_HEXA_MISSION_B.Switch2_a;
        MC_HEXA_MISSION_B.Sum_f = (MC_HEXA_MISSION_B.Gain2_g *
          MC_HEXA_MISSION_B.Switch2_a + MC_HEXA_MISSION_B.Sum_f) /
          MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0;
        if (MC_HEXA_MISSION_B.Sum_f < 0.0) {
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_norm
            (MC_HEXA_MISSION_B.MatrixConcatenate1);
        } else if (MC_HEXA_MISSION_B.Sum_f > 1.0) {
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] = MC_HEXA_MISSION_B.In1_c.x -
            MC_HEXA_MISSION_B.lla0[0];
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] = MC_HEXA_MISSION_B.In1_c.y -
            MC_HEXA_MISSION_B.lla0[1];
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] = MC_HEXA_MISSION_B.In1_c.z -
            MC_HEXA_MISSION_B.lla0[2];
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_norm
            (MC_HEXA_MISSION_B.rtb_CastToDouble_m);
        } else {
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] = MC_HEXA_MISSION_B.In1_c.x -
            (MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.b_varargout_3[0] +
             MC_HEXA_MISSION_B.MatrixConcatenate1_k[0]);
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] = MC_HEXA_MISSION_B.In1_c.y -
            (MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.b_varargout_3[1] +
             MC_HEXA_MISSION_B.MatrixConcatenate1_k[1]);
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] = MC_HEXA_MISSION_B.In1_c.z -
            (MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.Switch2_a +
             MC_HEXA_MISSION_B.MatrixConcatenate1_k[2]);
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_norm
            (MC_HEXA_MISSION_B.rtb_CastToDouble_m);
        }

        if (MC_HEXA_MISSION_DW.obj.LastWaypointFlag) {
          MC_HEXA_MISSION_B.Sum_f = ((MC_HEXA_MISSION_B.Gain_i *
            MC_HEXA_MISSION_B.b_varargout_3[0] +
            MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
            MC_HEXA_MISSION_B.b_varargout_3[1]) + (MC_HEXA_MISSION_B.In1_c.z -
            MC_HEXA_MISSION_B.MatrixConcatenate1_k[2]) *
            MC_HEXA_MISSION_B.Switch2_a) /
            MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0;
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[0] = MC_HEXA_MISSION_B.In1_c.x -
            (MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.b_varargout_3[0] +
             MC_HEXA_MISSION_B.MatrixConcatenate1_k[0]);
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[1] = MC_HEXA_MISSION_B.In1_c.y -
            (MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.b_varargout_3[1] +
             MC_HEXA_MISSION_B.MatrixConcatenate1_k[1]);
          MC_HEXA_MISSION_B.rtb_CastToDouble_m[2] = MC_HEXA_MISSION_B.In1_c.z -
            (MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.Switch2_a +
             MC_HEXA_MISSION_B.MatrixConcatenate1_k[2]);
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_norm
            (MC_HEXA_MISSION_B.rtb_CastToDouble_m);
        }

        MC_HEXA_MISSION_B.Gain_i = fabs(MC_HEXA_MISSION_B.Sum_f);
        if (rtIsInf(MC_HEXA_MISSION_B.Gain_i) || rtIsNaN
            (MC_HEXA_MISSION_B.Gain_i)) {
          MC_HEXA_MISSION_B.Gain2_g = (rtNaN);
          MC_HEXA_MISSION_B.Gain_i = (rtNaN);
        } else if (MC_HEXA_MISSION_B.Gain_i < 4.4501477170144028E-308) {
          MC_HEXA_MISSION_B.Gain2_g = 4.94065645841247E-324;
          MC_HEXA_MISSION_B.Gain_i = 4.94065645841247E-324;
        } else {
          frexp(MC_HEXA_MISSION_B.Gain_i, &MC_HEXA_MISSION_B.ParamStep_j);
          MC_HEXA_MISSION_B.Gain2_g = ldexp(1.0, MC_HEXA_MISSION_B.ParamStep_j -
            53);
          frexp(MC_HEXA_MISSION_B.Gain_i, &MC_HEXA_MISSION_B.b_exponent);
          MC_HEXA_MISSION_B.Gain_i = ldexp(1.0, MC_HEXA_MISSION_B.b_exponent -
            53);
        }

        MC_HEXA_MISSION_B.u0 = sqrt(MC_HEXA_MISSION_B.Gain2_g);
        MC_HEXA_MISSION_B.Gain_i *= 5.0;
        if ((MC_HEXA_MISSION_B.u0 >= MC_HEXA_MISSION_B.Gain_i) || rtIsNaN
            (MC_HEXA_MISSION_B.Gain_i)) {
          MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.u0;
        }

        if (MC_HEXA_MISSION_DW.obj.LookaheadDistance <= MC_HEXA_MISSION_B.Sum_f
            + MC_HEXA_MISSION_B.Gain_i) {
          MC_HEXA_MISSION_DW.obj.LookaheadDistance =
            MC_HEXA_MISSION_DW.obj.LookaheadFactor * MC_HEXA_MISSION_B.Sum_f;
        }

        MC_HEXA_MISSION_B.MatrixConcatenate1[0] =
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] - MC_HEXA_MISSION_B.In1_c.x;
        MC_HEXA_MISSION_B.MatrixConcatenate1[1] =
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] - MC_HEXA_MISSION_B.In1_c.y;
        MC_HEXA_MISSION_B.MatrixConcatenate1[2] =
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] - MC_HEXA_MISSION_B.In1_c.z;
        MC_HEXA_MISSION_B.Gain_i = ((MC_HEXA_MISSION_B.b_varargout_3[0] *
          MC_HEXA_MISSION_B.MatrixConcatenate1[0] +
          MC_HEXA_MISSION_B.b_varargout_3[1] *
          MC_HEXA_MISSION_B.MatrixConcatenate1[1]) + MC_HEXA_MISSION_B.Switch2_a
          * MC_HEXA_MISSION_B.MatrixConcatenate1[2]) * 2.0;
        MC_HEXA_MISSION_B.Gain2_g = sqrt(MC_HEXA_MISSION_B.Gain_i *
          MC_HEXA_MISSION_B.Gain_i - (((MC_HEXA_MISSION_B.MatrixConcatenate1[0] *
          MC_HEXA_MISSION_B.MatrixConcatenate1[0] +
          MC_HEXA_MISSION_B.MatrixConcatenate1[1] *
          MC_HEXA_MISSION_B.MatrixConcatenate1[1]) +
          MC_HEXA_MISSION_B.MatrixConcatenate1[2] *
          MC_HEXA_MISSION_B.MatrixConcatenate1[2]) -
          MC_HEXA_MISSION_DW.obj.LookaheadDistance *
          MC_HEXA_MISSION_DW.obj.LookaheadDistance) * (4.0 *
          MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0));
        MC_HEXA_MISSION_B.u0 = (-MC_HEXA_MISSION_B.Gain_i +
          MC_HEXA_MISSION_B.Gain2_g) / 2.0 /
          MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0;
        MC_HEXA_MISSION_B.Sum_f = (-MC_HEXA_MISSION_B.Gain_i -
          MC_HEXA_MISSION_B.Gain2_g) / 2.0 /
          MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0;
        if ((MC_HEXA_MISSION_B.u0 >= MC_HEXA_MISSION_B.Sum_f) || rtIsNaN
            (MC_HEXA_MISSION_B.Sum_f)) {
          MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.u0;
        }

        MC_HEXA_MISSION_B.lla0[0] = (1.0 - MC_HEXA_MISSION_B.Sum_f) *
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] + MC_HEXA_MISSION_B.Sum_f *
          MC_HEXA_MISSION_B.lla0[0];
        MC_HEXA_MISSION_B.lla0[1] = (1.0 - MC_HEXA_MISSION_B.Sum_f) *
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] + MC_HEXA_MISSION_B.Sum_f *
          MC_HEXA_MISSION_B.lla0[1];
        MC_HEXA_MISSION_B.lla0[2] = (1.0 - MC_HEXA_MISSION_B.Sum_f) *
          MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] + MC_HEXA_MISSION_B.Sum_f *
          MC_HEXA_MISSION_B.lla0[2];
        MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_rt_atan2d_snf
          (MC_HEXA_MISSION_B.lla0[1] - MC_HEXA_MISSION_B.In1_c.y,
           MC_HEXA_MISSION_B.lla0[0] - MC_HEXA_MISSION_B.In1_c.x);
        MC_HEXA_MISSION_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S574>/Switch1' incorporates:
    //   Constant: '<S575>/Constant'
    //   DataTypeConversion: '<Root>/Cast To Double'
    //   Logic: '<S574>/OR'
    //   Logic: '<S574>/OR1'
    //   MATLABSystem: '<S564>/UAV Waypoint Follower'
    //   Merge: '<S559>/Merge'
    //   RelationalOperator: '<S574>/IsNaN'
    //   RelationalOperator: '<S574>/IsNaN1'
    //   RelationalOperator: '<S575>/Compare'
    //   Switch: '<S574>/Switch'
    //
    if (rtIsNaN(MC_HEXA_MISSION_B.lla0[0]) || rtIsNaN(MC_HEXA_MISSION_B.lla0[1])
        || rtIsNaN(MC_HEXA_MISSION_B.lla0[2]) ||
        (MC_HEXA_MISSION_B.In1_p.current.type ==
         MC_HEXA_MISSION_P.CompareToConstant_const_d)) {
      MC_HEXA_MISSION_B.Merge[0] = MC_HEXA_MISSION_B.In1_c.x;
      MC_HEXA_MISSION_B.Merge[1] = MC_HEXA_MISSION_B.In1_c.y;
      MC_HEXA_MISSION_B.Merge[2] = MC_HEXA_MISSION_B.In1_c.z;
      MC_HEXA_MISSION_B.Merge[3] = MC_HEXA_MISSION_B.In1_c.heading;
    } else {
      if (rtIsNaN(MC_HEXA_MISSION_B.Sum_f)) {
        // Switch: '<S574>/Switch' incorporates:
        //   Constant: '<S574>/Constant'
        //   Merge: '<S559>/Merge'
        //   Reshape: '<S574>/Reshape2'

        MC_HEXA_MISSION_B.Merge[3] = MC_HEXA_MISSION_P.Constant_Value_jd;
      } else {
        // Reshape: '<S574>/Reshape2' incorporates:
        //   Merge: '<S559>/Merge'
        //   Switch: '<S574>/Switch'

        MC_HEXA_MISSION_B.Merge[3] = MC_HEXA_MISSION_B.Sum_f;
      }

      // Math: '<S574>/Transpose1' incorporates:
      //   Merge: '<S559>/Merge'

      MC_HEXA_MISSION_B.Merge[0] = MC_HEXA_MISSION_B.lla0[0];
      MC_HEXA_MISSION_B.Merge[1] = MC_HEXA_MISSION_B.lla0[1];
      MC_HEXA_MISSION_B.Merge[2] = MC_HEXA_MISSION_B.lla0[2];
    }

    // End of Switch: '<S574>/Switch1'
    // End of Outputs for SubSystem: '<S559>/Waypoint'
    break;

   default:
    if (MC_HEXA_MISSION_B.rtAction != MC_HEXA_MISSION_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S559>/IDLE' incorporates:
      //   ActionPort: '<S561>/Action Port'

      // InitializeConditions for If: '<S559>/If' incorporates:
      //   Delay: '<S565>/Delay'

      MC_HEXA_MISSION_DW.Delay_DSTATE =
        MC_HEXA_MISSION_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S559>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S559>/IDLE' incorporates:
    //   ActionPort: '<S561>/Action Port'

    // Outputs for Enabled SubSystem: '<S565>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S566>/Enable'

    if (MC_HEXA_MISSION_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S566>/yaw_In' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Double'

      MC_HEXA_MISSION_B.yaw_In = MC_HEXA_MISSION_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S565>/Enabled Subsystem2'

    // Reshape: '<S561>/Reshape1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double'
    //   Delay: '<S565>/Delay'
    //   Merge: '<S559>/Merge'

    MC_HEXA_MISSION_B.Merge[0] = MC_HEXA_MISSION_B.In1_c.x;
    MC_HEXA_MISSION_B.Merge[1] = MC_HEXA_MISSION_B.In1_c.y;
    MC_HEXA_MISSION_B.Merge[2] = MC_HEXA_MISSION_B.In1_c.z;
    MC_HEXA_MISSION_B.Merge[3] = MC_HEXA_MISSION_B.yaw_In;

    // Update for Delay: '<S565>/Delay' incorporates:
    //   Constant: '<S565>/Constant'

    MC_HEXA_MISSION_DW.Delay_DSTATE = MC_HEXA_MISSION_P.Constant_Value_ic;

    // End of Outputs for SubSystem: '<S559>/IDLE'
    break;
  }

  // End of If: '<S559>/If'

  // MATLABSystem: '<S599>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_gv.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_gv.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_g, false, 1.0);

  // Outputs for Enabled SubSystem: '<S599>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S603>/Enable'

  // Start for MATLABSystem: '<S599>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S603>/In1'
    MC_HEXA_MISSION_B.In1_m = MC_HEXA_MISSION_B.b_varargout_2_g;
  }

  // End of Outputs for SubSystem: '<S599>/Enabled Subsystem'

  // DataTypeConversion: '<S23>/Data Type Conversion' incorporates:
  //   Switch: '<S26>/Switch'

  MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 = MC_HEXA_MISSION_B.In1_m.q[0];
  MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = MC_HEXA_MISSION_B.In1_m.q[1];
  MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.In1_m.q[2];
  MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.In1_m.q[3];

  // Switch: '<S26>/Switch' incorporates:
  //   Constant: '<S26>/Constant'
  //   DataTypeConversion: '<S23>/Data Type Conversion'
  //   Product: '<S35>/Product'
  //   Product: '<S35>/Product1'
  //   Product: '<S35>/Product2'
  //   Product: '<S35>/Product3'
  //   Sum: '<S35>/Sum'

  if (!(((static_cast<real_T>(MC_HEXA_MISSION_B.In1_m.q[0]) *
          MC_HEXA_MISSION_B.In1_m.q[0] + static_cast<real_T>
          (MC_HEXA_MISSION_B.In1_m.q[1]) * MC_HEXA_MISSION_B.In1_m.q[1]) +
         static_cast<real_T>(MC_HEXA_MISSION_B.In1_m.q[2]) *
         MC_HEXA_MISSION_B.In1_m.q[2]) + static_cast<real_T>
        (MC_HEXA_MISSION_B.In1_m.q[3]) * MC_HEXA_MISSION_B.In1_m.q[3] >
        MC_HEXA_MISSION_P.Switch_Threshold_l)) {
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 =
      MC_HEXA_MISSION_P.Constant_Value_im[0];
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 =
      MC_HEXA_MISSION_P.Constant_Value_im[1];
    MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Constant_Value_im[2];
    MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_P.Constant_Value_im[3];
  }

  // End of Switch: '<S26>/Switch'

  // Sqrt: '<S42>/sqrt' incorporates:
  //   Product: '<S43>/Product'
  //   Product: '<S43>/Product1'
  //   Product: '<S43>/Product2'
  //   Product: '<S43>/Product3'
  //   Sum: '<S43>/Sum'

  MC_HEXA_MISSION_B.Switch2_a = sqrt(((MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 +
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1) + MC_HEXA_MISSION_B.Sum_f *
    MC_HEXA_MISSION_B.Sum_f) + MC_HEXA_MISSION_B.Gain_i *
    MC_HEXA_MISSION_B.Gain_i);

  // Product: '<S37>/Product'
  MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 /= MC_HEXA_MISSION_B.Switch2_a;

  // Product: '<S37>/Product1'
  MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 /= MC_HEXA_MISSION_B.Switch2_a;

  // Product: '<S37>/Product2'
  MC_HEXA_MISSION_B.Sum_f /= MC_HEXA_MISSION_B.Switch2_a;

  // Product: '<S37>/Product3'
  MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_B.Gain_i /
    MC_HEXA_MISSION_B.Switch2_a;

  // Fcn: '<S27>/fcn2' incorporates:
  //   Fcn: '<S27>/fcn5'

  MC_HEXA_MISSION_B.Gain2_g = MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0;
  MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1;
  MC_HEXA_MISSION_B.Gain3 = MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.Sum_f;
  MC_HEXA_MISSION_B.Saturation1 = MC_HEXA_MISSION_B.Switch2_a *
    MC_HEXA_MISSION_B.Switch2_a;

  // Trigonometry: '<S36>/Trigonometric Function1' incorporates:
  //   Fcn: '<S27>/fcn1'
  //   Fcn: '<S27>/fcn2'

  MC_HEXA_MISSION_B.VectorConcatenate[0] = MC_HEXA_MISSION_rt_atan2d_snf
    ((MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 * MC_HEXA_MISSION_B.Sum_f +
      MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 * MC_HEXA_MISSION_B.Switch2_a) *
     2.0, ((MC_HEXA_MISSION_B.Gain2_g + MC_HEXA_MISSION_B.u0) -
           MC_HEXA_MISSION_B.Gain3) - MC_HEXA_MISSION_B.Saturation1);

  // Fcn: '<S27>/fcn3'
  MC_HEXA_MISSION_B.Gain_i = (MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 *
    MC_HEXA_MISSION_B.Switch2_a - MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
    MC_HEXA_MISSION_B.Sum_f) * -2.0;

  // If: '<S38>/If' incorporates:
  //   Constant: '<S39>/Constant'
  //   Constant: '<S40>/Constant'
  //   Trigonometry: '<S36>/trigFcn'

  if (MC_HEXA_MISSION_B.Gain_i > 1.0) {
    MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_P.Constant_Value_be;
  } else if (MC_HEXA_MISSION_B.Gain_i < -1.0) {
    MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_P.Constant_Value_m;
  }

  if (MC_HEXA_MISSION_B.Gain_i > 1.0) {
    MC_HEXA_MISSION_B.Gain_i = 1.0;
  } else if (MC_HEXA_MISSION_B.Gain_i < -1.0) {
    MC_HEXA_MISSION_B.Gain_i = -1.0;
  }

  // End of If: '<S38>/If'

  // Trigonometry: '<S36>/trigFcn'
  MC_HEXA_MISSION_B.VectorConcatenate[1] = asin(MC_HEXA_MISSION_B.Gain_i);

  // Trigonometry: '<S36>/Trigonometric Function3' incorporates:
  //   Fcn: '<S27>/fcn4'
  //   Fcn: '<S27>/fcn5'

  MC_HEXA_MISSION_B.VectorConcatenate[2] = MC_HEXA_MISSION_rt_atan2d_snf
    ((MC_HEXA_MISSION_B.Sum_f * MC_HEXA_MISSION_B.Switch2_a +
      MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 *
      MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1) * 2.0,
     ((MC_HEXA_MISSION_B.Gain2_g - MC_HEXA_MISSION_B.u0) -
      MC_HEXA_MISSION_B.Gain3) + MC_HEXA_MISSION_B.Saturation1);

  // Gain: '<S23>/Gain'
  MC_HEXA_MISSION_B.desiredZ = MC_HEXA_MISSION_P.Gain_Gain_cc *
    MC_HEXA_MISSION_B.Merge[2];

  // Outputs for Enabled SubSystem: '<S23>/mc_pos_controller'
  MC_HEXA_MISSION_mc_pos_controller();

  // End of Outputs for SubSystem: '<S23>/mc_pos_controller'

  // Outputs for Enabled SubSystem: '<S23>/mc_att_controller'
  MC_HEXA_MISSION_mc_att_controller();

  // End of Outputs for SubSystem: '<S23>/mc_att_controller'

  // MATLABSystem: '<S597>/SourceBlock'
  MC_HEXA_MISSION_B.OR_g = uORB_read_step
    (MC_HEXA_MISSION_DW.obj_po.orbMetadataObj,
     &MC_HEXA_MISSION_DW.obj_po.eventStructObj,
     &MC_HEXA_MISSION_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S597>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S601>/Enable'

  // Start for MATLABSystem: '<S597>/SourceBlock'
  if (MC_HEXA_MISSION_B.OR_g) {
    // SignalConversion generated from: '<S601>/In1'
    MC_HEXA_MISSION_B.In1_l = MC_HEXA_MISSION_B.b_varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S597>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S23>/mc_rate_controller'
  MC_HEXA_MISSION_mc_rate_controller();

  // End of Outputs for SubSystem: '<S23>/mc_rate_controller'

  // Gain: '<S5>/Gain'
  MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Gain_Gain_j *
    MC_HEXA_MISSION_B.Saturation_b;

  // Gain: '<S5>/Gain1'
  MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_P.Gain1_Gain_j *
    MC_HEXA_MISSION_B.Saturation_c;

  // Gain: '<S5>/Gain2'
  MC_HEXA_MISSION_B.Gain2_g = MC_HEXA_MISSION_P.Gain2_Gain_f *
    MC_HEXA_MISSION_B.Saturation;

  // Gain: '<S5>/Gain3'
  MC_HEXA_MISSION_B.Gain3 = MC_HEXA_MISSION_P.Gain3_Gain *
    MC_HEXA_MISSION_B.Saturation_d;

  // MATLABSystem: '<S7>/Read Parameter13'
  if (MC_HEXA_MISSION_DW.obj_ka.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter13_SampleTime) {
    MC_HEXA_MISSION_DW.obj_ka.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter13_SampleTime;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step
    (MC_HEXA_MISSION_DW.obj_ka.MW_PARAMHANDLE, MW_INT32,
     &MC_HEXA_MISSION_B.ParamStep_j);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_j = 0;
  }

  // RelationalOperator: '<S18>/Compare' incorporates:
  //   Constant: '<S18>/Constant'

  MC_HEXA_MISSION_B.Compare = (MC_HEXA_MISSION_B.In1_k.values[7] >=
    MC_HEXA_MISSION_P.CompareToConstant_const_k);

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

  if (MC_HEXA_MISSION_B.Compare_k) {
    MC_HEXA_MISSION_B.Saturation1 = MC_HEXA_MISSION_P.Constant_Value_o;
  } else {
    if (MC_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch' incorporates:
      //   Constant: '<S7>/Fault'
      //   DataTypeConversion: '<S7>/Data Type Conversion3'
      //   MATLABSystem: '<S7>/Read Parameter13'
      //   Switch: '<S7>/Switch'
      //
      if (MC_HEXA_MISSION_P.ManualSwitch_CurrentSetting == 1) {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Fault_Value;
      } else {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.ParamStep_j;
      }

      // End of ManualSwitch: '<S7>/Manual Switch'
    } else {
      // Switch: '<S7>/Switch' incorporates:
      //   Constant: '<S7>/Constant'

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Constant_Value_d3;
    }

    // Gain: '<S12>/Gain' incorporates:
    //   Switch: '<S7>/Switch'

    MC_HEXA_MISSION_B.u0 *= MC_HEXA_MISSION_P.Gain_Gain_c;

    // Saturate: '<S12>/Saturation1'
    if (MC_HEXA_MISSION_B.u0 > MC_HEXA_MISSION_P.Saturation1_UpperSat_g) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_UpperSat_g;
    } else if (MC_HEXA_MISSION_B.u0 < MC_HEXA_MISSION_P.Saturation1_LowerSat_c)
    {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_LowerSat_c;
    }

    MC_HEXA_MISSION_B.Saturation1 = ((((-MC_HEXA_MISSION_B.Sum_f -
      MC_HEXA_MISSION_B.Gain2_g) * MC_HEXA_MISSION_B.Gain3 / 3.0 +
      MC_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
      MC_HEXA_MISSION_P.IDLEPWM_Value_h) * MC_HEXA_MISSION_B.u0 +
      MC_HEXA_MISSION_P.Constant_Value_h;
  }

  // End of Switch: '<S6>/Switch'

  // MATLABSystem: '<S7>/Read Parameter1'
  if (MC_HEXA_MISSION_DW.obj_a.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter1_SampleTime) {
    MC_HEXA_MISSION_DW.obj_a.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter1_SampleTime;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step(MC_HEXA_MISSION_DW.obj_a.MW_PARAMHANDLE,
    MW_INT32, &MC_HEXA_MISSION_B.ParamStep_j);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_j = 0;
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

  if (MC_HEXA_MISSION_B.Compare_k) {
    MC_HEXA_MISSION_B.Switch1_d = MC_HEXA_MISSION_P.Constant1_Value;
  } else {
    if (MC_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch1' incorporates:
      //   Constant: '<S7>/Fault1'
      //   DataTypeConversion: '<S7>/Data Type Conversion2'
      //   MATLABSystem: '<S7>/Read Parameter1'
      //   Switch: '<S7>/Switch1'
      //
      if (MC_HEXA_MISSION_P.ManualSwitch1_CurrentSetting == 1) {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Fault1_Value;
      } else {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.ParamStep_j;
      }

      // End of ManualSwitch: '<S7>/Manual Switch1'
    } else {
      // Switch: '<S7>/Switch1' incorporates:
      //   Constant: '<S7>/Constant1'

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Constant1_Value_j;
    }

    // Gain: '<S13>/Gain' incorporates:
    //   Switch: '<S7>/Switch1'

    MC_HEXA_MISSION_B.u0 *= MC_HEXA_MISSION_P.Gain_Gain;

    // Saturate: '<S13>/Saturation1'
    if (MC_HEXA_MISSION_B.u0 > MC_HEXA_MISSION_P.Saturation1_UpperSat) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_UpperSat;
    } else if (MC_HEXA_MISSION_B.u0 < MC_HEXA_MISSION_P.Saturation1_LowerSat) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_LowerSat;
    }

    MC_HEXA_MISSION_B.Switch1_d = ((((MC_HEXA_MISSION_B.Sum_f +
      MC_HEXA_MISSION_B.Gain2_g) * MC_HEXA_MISSION_B.Gain3 / 3.0 +
      MC_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0) -
      MC_HEXA_MISSION_P.IDLEPWM_Value) * MC_HEXA_MISSION_B.u0 +
      MC_HEXA_MISSION_P.Constant_Value_e1;
  }

  // End of Switch: '<S6>/Switch1'

  // MATLABSystem: '<S7>/Read Parameter2'
  if (MC_HEXA_MISSION_DW.obj_ng.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter2_SampleTime) {
    MC_HEXA_MISSION_DW.obj_ng.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter2_SampleTime;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step
    (MC_HEXA_MISSION_DW.obj_ng.MW_PARAMHANDLE, MW_INT32,
     &MC_HEXA_MISSION_B.ParamStep_j);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_j = 0;
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

  if (MC_HEXA_MISSION_B.Compare_k) {
    MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_P.Constant2_Value;
  } else {
    if (MC_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch2' incorporates:
      //   Constant: '<S7>/Fault2'
      //   DataTypeConversion: '<S7>/Data Type Conversion'
      //   MATLABSystem: '<S7>/Read Parameter2'
      //   Switch: '<S7>/Switch2'
      //
      if (MC_HEXA_MISSION_P.ManualSwitch2_CurrentSetting == 1) {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Fault2_Value;
      } else {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.ParamStep_j;
      }

      // End of ManualSwitch: '<S7>/Manual Switch2'
    } else {
      // Switch: '<S7>/Switch2' incorporates:
      //   Constant: '<S7>/Constant2'

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Constant2_Value_o;
    }

    // Gain: '<S14>/Gain' incorporates:
    //   Switch: '<S7>/Switch2'

    MC_HEXA_MISSION_B.u0 *= MC_HEXA_MISSION_P.Gain_Gain_d;

    // Saturate: '<S14>/Saturation1'
    if (MC_HEXA_MISSION_B.u0 > MC_HEXA_MISSION_P.Saturation1_UpperSat_e) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_UpperSat_e;
    } else if (MC_HEXA_MISSION_B.u0 < MC_HEXA_MISSION_P.Saturation1_LowerSat_m)
    {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_LowerSat_m;
    }

    MC_HEXA_MISSION_B.Switch2_a = (((((MC_HEXA_MISSION_B.Sum_f / 2.0 +
      MC_HEXA_MISSION_B.Gain_i) - MC_HEXA_MISSION_B.Gain2_g) *
      MC_HEXA_MISSION_B.Gain3 / 3.0 + MC_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0)
      - MC_HEXA_MISSION_P.IDLEPWM_Value_j) * MC_HEXA_MISSION_B.u0 +
      MC_HEXA_MISSION_P.Constant_Value_f;
  }

  // End of Switch: '<S6>/Switch2'

  // MATLABSystem: '<S7>/Read Parameter3'
  if (MC_HEXA_MISSION_DW.obj_n0.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter3_SampleTime) {
    MC_HEXA_MISSION_DW.obj_n0.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter3_SampleTime;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step
    (MC_HEXA_MISSION_DW.obj_n0.MW_PARAMHANDLE, MW_INT32,
     &MC_HEXA_MISSION_B.ParamStep_j);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_j = 0;
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

  if (MC_HEXA_MISSION_B.Compare_k) {
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 = MC_HEXA_MISSION_P.Constant3_Value;
  } else {
    if (MC_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch3' incorporates:
      //   Constant: '<S7>/Fault3'
      //   DataTypeConversion: '<S7>/Data Type Conversion4'
      //   MATLABSystem: '<S7>/Read Parameter3'
      //   Switch: '<S7>/Switch3'
      //
      if (MC_HEXA_MISSION_P.ManualSwitch3_CurrentSetting == 1) {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Fault3_Value;
      } else {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.ParamStep_j;
      }

      // End of ManualSwitch: '<S7>/Manual Switch3'
    } else {
      // Switch: '<S7>/Switch3' incorporates:
      //   Constant: '<S7>/Constant3'

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Constant3_Value_b;
    }

    // Gain: '<S15>/Gain' incorporates:
    //   Switch: '<S7>/Switch3'

    MC_HEXA_MISSION_B.u0 *= MC_HEXA_MISSION_P.Gain_Gain_a;

    // Saturate: '<S15>/Saturation1'
    if (MC_HEXA_MISSION_B.u0 > MC_HEXA_MISSION_P.Saturation1_UpperSat_l) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_UpperSat_l;
    } else if (MC_HEXA_MISSION_B.u0 < MC_HEXA_MISSION_P.Saturation1_LowerSat_g)
    {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_LowerSat_g;
    }

    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0 = (((((-MC_HEXA_MISSION_B.Gain_i -
      MC_HEXA_MISSION_B.Sum_f / 2.0) + MC_HEXA_MISSION_B.Gain2_g) *
      MC_HEXA_MISSION_B.Gain3 / 3.0 + MC_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0)
      - MC_HEXA_MISSION_P.IDLEPWM_Value_k) * MC_HEXA_MISSION_B.u0 +
      MC_HEXA_MISSION_P.Constant_Value_a;
  }

  // End of Switch: '<S6>/Switch3'

  // MATLABSystem: '<S7>/Read Parameter4'
  if (MC_HEXA_MISSION_DW.obj_cf.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter4_SampleTime) {
    MC_HEXA_MISSION_DW.obj_cf.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter4_SampleTime;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step
    (MC_HEXA_MISSION_DW.obj_cf.MW_PARAMHANDLE, MW_INT32,
     &MC_HEXA_MISSION_B.ParamStep_j);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_j = 0;
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

  if (MC_HEXA_MISSION_B.Compare_k) {
    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = MC_HEXA_MISSION_P.Constant4_Value;
  } else {
    if (MC_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch4' incorporates:
      //   Constant: '<S7>/Fault4'
      //   DataTypeConversion: '<S7>/Data Type Conversion1'
      //   MATLABSystem: '<S7>/Read Parameter4'
      //   Switch: '<S7>/Switch4'
      //
      if (MC_HEXA_MISSION_P.ManualSwitch4_CurrentSetting == 1) {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Fault4_Value;
      } else {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.ParamStep_j;
      }

      // End of ManualSwitch: '<S7>/Manual Switch4'
    } else {
      // Switch: '<S7>/Switch4' incorporates:
      //   Constant: '<S7>/Constant4'

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Constant4_Value_e;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Switch: '<S7>/Switch4'

    MC_HEXA_MISSION_B.u0 *= MC_HEXA_MISSION_P.Gain_Gain_o;

    // Saturate: '<S16>/Saturation1'
    if (MC_HEXA_MISSION_B.u0 > MC_HEXA_MISSION_P.Saturation1_UpperSat_eb) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_UpperSat_eb;
    } else if (MC_HEXA_MISSION_B.u0 < MC_HEXA_MISSION_P.Saturation1_LowerSat_b)
    {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_LowerSat_b;
    }

    MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1 = (((((MC_HEXA_MISSION_B.Gain_i -
      MC_HEXA_MISSION_B.Sum_f / 2.0) + MC_HEXA_MISSION_B.Gain2_g) *
      MC_HEXA_MISSION_B.Gain3 / 3.0 + MC_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0)
      - MC_HEXA_MISSION_P.IDLEPWM_Value_c) * MC_HEXA_MISSION_B.u0 +
      MC_HEXA_MISSION_P.Constant_Value_j3;
  }

  // End of Switch: '<S6>/Switch4'

  // MATLABSystem: '<S7>/Read Parameter5'
  if (MC_HEXA_MISSION_DW.obj_p1.SampleTime !=
      MC_HEXA_MISSION_P.ReadParameter5_SampleTime) {
    MC_HEXA_MISSION_DW.obj_p1.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter5_SampleTime;
  }

  MC_HEXA_MISSION_B.OR_g = MW_Param_Step
    (MC_HEXA_MISSION_DW.obj_p1.MW_PARAMHANDLE, MW_INT32,
     &MC_HEXA_MISSION_B.ParamStep_j);
  if (MC_HEXA_MISSION_B.OR_g) {
    MC_HEXA_MISSION_B.ParamStep_j = 0;
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

  if (MC_HEXA_MISSION_B.Compare_k) {
    MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_P.Constant5_Value;
  } else {
    if (MC_HEXA_MISSION_B.Compare) {
      // ManualSwitch: '<S7>/Manual Switch5' incorporates:
      //   Constant: '<S7>/Fault5'
      //   DataTypeConversion: '<S7>/Data Type Conversion5'
      //   MATLABSystem: '<S7>/Read Parameter5'
      //   Switch: '<S7>/Switch5'
      //
      if (MC_HEXA_MISSION_P.ManualSwitch5_CurrentSetting == 1) {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Fault5_Value;
      } else {
        MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_B.ParamStep_j;
      }

      // End of ManualSwitch: '<S7>/Manual Switch5'
    } else {
      // Switch: '<S7>/Switch5' incorporates:
      //   Constant: '<S7>/Constant5'

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Constant5_Value_f;
    }

    // Gain: '<S17>/Gain' incorporates:
    //   Switch: '<S7>/Switch5'

    MC_HEXA_MISSION_B.u0 *= MC_HEXA_MISSION_P.Gain_Gain_ap;

    // Saturate: '<S17>/Saturation1'
    if (MC_HEXA_MISSION_B.u0 > MC_HEXA_MISSION_P.Saturation1_UpperSat_b) {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_UpperSat_b;
    } else if (MC_HEXA_MISSION_B.u0 < MC_HEXA_MISSION_P.Saturation1_LowerSat_o)
    {
      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_P.Saturation1_LowerSat_o;
    }

    MC_HEXA_MISSION_B.Sum_f = (((((MC_HEXA_MISSION_B.Sum_f / 2.0 -
      MC_HEXA_MISSION_B.Gain_i) - MC_HEXA_MISSION_B.Gain2_g) *
      MC_HEXA_MISSION_B.Gain3 / 3.0 + MC_HEXA_MISSION_B.Gain3) * 1000.0 + 1000.0)
      - MC_HEXA_MISSION_P.IDLEPWM_Value_e) * MC_HEXA_MISSION_B.u0 +
      MC_HEXA_MISSION_P.Constant_Value_cx;
  }

  // End of Switch: '<S6>/Switch5'
  MC_HEXA_MISSION_PX4Timestamp(&MC_HEXA_MISSION_B.PX4Timestamp_p);

  // BusAssignment: '<S25>/Bus Assignment' incorporates:
  //   Constant: '<S25>/thrust_sp_bX'
  //   Constant: '<S25>/thrust_sp_bY'
  //   DataTypeConversion: '<S25>/Data Type Conversion'
  //   DataTypeConversion: '<S25>/Data Type Conversion1'
  //   DataTypeConversion: '<S25>/Data Type Conversion2'
  //   DataTypeConversion: '<S25>/Data Type Conversion3'
  //   MATLABSystem: '<S25>/PX4 Timestamp'

  MC_HEXA_MISSION_B.BusAssignment_h4.timestamp =
    MC_HEXA_MISSION_B.PX4Timestamp_p.PX4Timestamp;
  MC_HEXA_MISSION_B.BusAssignment_h4.roll = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Switch2_o);
  MC_HEXA_MISSION_B.BusAssignment_h4.pitch = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Switch2_l);
  MC_HEXA_MISSION_B.BusAssignment_h4.yaw = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Switch2_n);
  MC_HEXA_MISSION_B.BusAssignment_h4.thrust_body[0] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.thrust_sp_bX_Value_m);
  MC_HEXA_MISSION_B.BusAssignment_h4.thrust_body[1] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.thrust_sp_bY_Value_m);
  MC_HEXA_MISSION_B.BusAssignment_h4.thrust_body[2] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Saturation_d);

  // MATLABSystem: '<S34>/SinkBlock' incorporates:
  //   BusAssignment: '<S25>/Bus Assignment'

  uORB_write_step(MC_HEXA_MISSION_DW.obj_dz.orbMetadataObj,
                  &MC_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj,
                  &MC_HEXA_MISSION_B.BusAssignment_h4);
  MC_HEXA_MISSION_PX4Timestamp(&MC_HEXA_MISSION_B.PX4Timestamp);

  // BusAssignment: '<S24>/Bus Assignment' incorporates:
  //   Constant: '<S24>/thrust_sp_bX'
  //   Constant: '<S24>/thrust_sp_bY'
  //   Constant: '<S31>/Constant'
  //   DataTypeConversion: '<S24>/Data Type Conversion'
  //   DataTypeConversion: '<S24>/Data Type Conversion1'
  //   DataTypeConversion: '<S24>/Data Type Conversion2'
  //   DataTypeConversion: '<S24>/Data Type Conversion3'
  //   MATLABSystem: '<S24>/PX4 Timestamp'

  MC_HEXA_MISSION_B.BusAssignment_h = MC_HEXA_MISSION_P.Constant_Value_b;
  MC_HEXA_MISSION_B.BusAssignment_h.timestamp =
    MC_HEXA_MISSION_B.PX4Timestamp.PX4Timestamp;
  MC_HEXA_MISSION_B.BusAssignment_h.roll_body = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Switch2[1]);
  MC_HEXA_MISSION_B.BusAssignment_h.pitch_body = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Gain1);
  MC_HEXA_MISSION_B.BusAssignment_h.yaw_body = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Merge[3]);
  MC_HEXA_MISSION_B.BusAssignment_h.thrust_body[0] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.thrust_sp_bX_Value);
  MC_HEXA_MISSION_B.BusAssignment_h.thrust_body[1] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.thrust_sp_bY_Value);
  MC_HEXA_MISSION_B.BusAssignment_h.thrust_body[2] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Saturation_d);

  // MATLABSystem: '<S32>/SinkBlock' incorporates:
  //   BusAssignment: '<S24>/Bus Assignment'

  uORB_write_step(MC_HEXA_MISSION_DW.obj_mgm.orbMetadataObj,
                  &MC_HEXA_MISSION_DW.obj_mgm.orbAdvertiseObj,
                  &MC_HEXA_MISSION_B.BusAssignment_h);

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S21>/Constant'

  MC_HEXA_MISSION_B.BusAssignment_l = MC_HEXA_MISSION_P.Constant_Value_c;

  // DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
  //   Constant: '<S10>/Constant17'

  MC_HEXA_MISSION_B.u0 = floor(MC_HEXA_MISSION_P.Constant17_Value);
  if (rtIsNaN(MC_HEXA_MISSION_B.u0) || rtIsInf(MC_HEXA_MISSION_B.u0)) {
    MC_HEXA_MISSION_B.u0 = 0.0;
  } else {
    MC_HEXA_MISSION_B.u0 = fmod(MC_HEXA_MISSION_B.u0, 4.294967296E+9);
  }

  // BusAssignment: '<S10>/Bus Assignment' incorporates:
  //   Constant: '<S10>/Constant'
  //   DataTypeConversion: '<S10>/Data Type Conversion'
  //   DataTypeConversion: '<S10>/Data Type Conversion1'

  MC_HEXA_MISSION_B.BusAssignment_l.noutputs = MC_HEXA_MISSION_B.u0 < 0.0 ?
    static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>
    (-MC_HEXA_MISSION_B.u0))) : static_cast<uint32_T>(MC_HEXA_MISSION_B.u0);
  MC_HEXA_MISSION_B.BusAssignment_l.output[0] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Saturation1);
  MC_HEXA_MISSION_B.BusAssignment_l.output[1] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Switch1_d);
  MC_HEXA_MISSION_B.BusAssignment_l.output[2] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Switch2_a);
  MC_HEXA_MISSION_B.BusAssignment_l.output[3] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.rtb_CastToDouble_idx_0);
  MC_HEXA_MISSION_B.BusAssignment_l.output[4] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.rtb_CastToDouble_idx_1);
  MC_HEXA_MISSION_B.BusAssignment_l.output[5] = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Sum_f);
  MC_HEXA_MISSION_B.BusAssignment_l.output[6] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[7] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[8] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[9] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[10] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[11] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[12] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[13] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[14] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);
  MC_HEXA_MISSION_B.BusAssignment_l.output[15] = static_cast<real32_T>
    (MC_HEXA_MISSION_P.Constant_Value_gp);

  // MATLABSystem: '<S22>/SinkBlock' incorporates:
  //   BusAssignment: '<S10>/Bus Assignment'

  uORB_write_step(MC_HEXA_MISSION_DW.obj_hy.orbMetadataObj,
                  &MC_HEXA_MISSION_DW.obj_hy.orbAdvertiseObj,
                  &MC_HEXA_MISSION_B.BusAssignment_l);
  MC_HEXA_MISSION_PX4Timestamp(&MC_HEXA_MISSION_B.PX4Timestamp_pn);

  // BusAssignment: '<S557>/Bus Assignment' incorporates:
  //   Constant: '<S595>/Constant'
  //   DataTypeConversion: '<S557>/Data Type Conversion'
  //   DataTypeConversion: '<S557>/Data Type Conversion1'
  //   DataTypeConversion: '<S557>/Data Type Conversion2'
  //   DataTypeConversion: '<S557>/Data Type Conversion3'
  //   MATLABSystem: '<S557>/PX4 Timestamp'

  MC_HEXA_MISSION_B.BusAssignment_m = MC_HEXA_MISSION_P.Constant_Value_i;
  MC_HEXA_MISSION_B.BusAssignment_m.timestamp =
    MC_HEXA_MISSION_B.PX4Timestamp_pn.PX4Timestamp;
  MC_HEXA_MISSION_B.BusAssignment_m.x = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Merge[0]);
  MC_HEXA_MISSION_B.BusAssignment_m.y = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Merge[1]);
  MC_HEXA_MISSION_B.BusAssignment_m.z = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Merge[2]);
  MC_HEXA_MISSION_B.BusAssignment_m.yaw = static_cast<real32_T>
    (MC_HEXA_MISSION_B.Merge[3]);

  // MATLABSystem: '<S596>/SinkBlock' incorporates:
  //   BusAssignment: '<S557>/Bus Assignment'

  uORB_write_step(MC_HEXA_MISSION_DW.obj_o2.orbMetadataObj,
                  &MC_HEXA_MISSION_DW.obj_o2.orbAdvertiseObj,
                  &MC_HEXA_MISSION_B.BusAssignment_m);

  // Outputs for Enabled SubSystem: '<S560>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S577>/Enable'

  // Start for MATLABSystem: '<S560>/Read Parameter'
  if (MC_HEXA_MISSION_B.ParamStep_l > 0) {
    // BusAssignment: '<S577>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment'
    //   Constant: '<S587>/Constant'
    //   SignalConversion generated from: '<S583>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0] =
      MC_HEXA_MISSION_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S583>/Matrix Concatenate1'
    MC_HEXA_MISSION_B.MatrixConcatenate1[0] =
      MC_HEXA_MISSION_B.In1_p.current.lat;

    // SignalConversion generated from: '<S583>/Matrix Concatenate1'
    MC_HEXA_MISSION_B.MatrixConcatenate1[1] =
      MC_HEXA_MISSION_B.In1_p.current.lon;

    // DataTypeConversion: '<S583>/Data Type Conversion'
    MC_HEXA_MISSION_B.MatrixConcatenate1[2] =
      MC_HEXA_MISSION_B.In1_p.current.alt;

    // SignalConversion generated from: '<S577>/Matrix Concatenate1'
    MC_HEXA_MISSION_B.MatrixConcatenate1_k[0] = MC_HEXA_MISSION_B.In1_f.lat;

    // SignalConversion generated from: '<S577>/Matrix Concatenate1'
    MC_HEXA_MISSION_B.MatrixConcatenate1_k[1] = MC_HEXA_MISSION_B.In1_f.lon;

    // DataTypeConversion: '<S577>/Data Type Conversion'
    MC_HEXA_MISSION_B.MatrixConcatenate1_k[2] = MC_HEXA_MISSION_B.In1_f.alt;
    MC_HEXA_MISSION_MATLABSystem(MC_HEXA_MISSION_B.MatrixConcatenate1,
      MC_HEXA_MISSION_B.MatrixConcatenate1_k,
      MC_HEXA_MISSION_B.In1_p.current.valid,
      MC_HEXA_MISSION_B.In1_p.current.type, &MC_HEXA_MISSION_B.MATLABSystem);

    // SignalConversion generated from: '<S589>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S583>/Bus Assignment1'
    //   MATLABSystem: '<S583>/MATLAB System'
    //   SignalConversion generated from: '<S583>/MATLAB System'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[0] =
      MC_HEXA_MISSION_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S589>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S583>/Bus Assignment1'
    //   MATLABSystem: '<S583>/MATLAB System'
    //   SignalConversion generated from: '<S583>/MATLAB System'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[1] =
      MC_HEXA_MISSION_B.MATLABSystem.MATLABSystem[1];

    // If: '<S589>/If' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S583>/Bus Assignment1'
    //   Constant: '<S591>/Constant'
    //   Constant: '<S591>/Constant1'
    //   Constant: '<S592>/Constant'
    //   Constant: '<S592>/Constant1'

    if (MC_HEXA_MISSION_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S589>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S592>/Action Port'

      // MATLABSystem: '<S592>/Read Parameter' incorporates:
      //   BusAssignment: '<S577>/Bus Assignment1'
      //   BusAssignment: '<S583>/Bus Assignment1'
      //   SignalConversion generated from: '<S592>/Read Parameter'

      if (MC_HEXA_MISSION_DW.obj_g.SampleTime !=
          MC_HEXA_MISSION_P.ReadParameter_SampleTime_c) {
        MC_HEXA_MISSION_DW.obj_g.SampleTime =
          MC_HEXA_MISSION_P.ReadParameter_SampleTime_c;
      }

      MC_HEXA_MISSION_B.OR_g = MW_Param_Step
        (MC_HEXA_MISSION_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2]);
      if (MC_HEXA_MISSION_B.OR_g) {
        MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S592>/Read Parameter'
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        MC_HEXA_MISSION_P.Constant1_Value_d[0];
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        MC_HEXA_MISSION_P.Constant1_Value_d[1];
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        MC_HEXA_MISSION_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S589>/If Action Subsystem2'
    } else if (MC_HEXA_MISSION_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S589>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S591>/Action Port'

      // MATLABSystem: '<S591>/Read Parameter'
      if (MC_HEXA_MISSION_DW.obj_b.SampleTime !=
          MC_HEXA_MISSION_P.ReadParameter_SampleTime_g) {
        MC_HEXA_MISSION_DW.obj_b.SampleTime =
          MC_HEXA_MISSION_P.ReadParameter_SampleTime_g;
      }

      MC_HEXA_MISSION_B.OR_g = MW_Param_Step
        (MC_HEXA_MISSION_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &MC_HEXA_MISSION_B.ParamStep);
      if (MC_HEXA_MISSION_B.OR_g) {
        MC_HEXA_MISSION_B.ParamStep = 0.0F;
      }

      // Gain: '<S591>/Gain' incorporates:
      //   BusAssignment: '<S577>/Bus Assignment1'
      //   BusAssignment: '<S583>/Bus Assignment1'
      //   MATLABSystem: '<S591>/Read Parameter'
      //
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
        MC_HEXA_MISSION_P.Gain_Gain_h * MC_HEXA_MISSION_B.ParamStep;
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        MC_HEXA_MISSION_P.Constant1_Value_k4[0];
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        MC_HEXA_MISSION_P.Constant1_Value_k4[1];
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        MC_HEXA_MISSION_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S589>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S589>/If Action Subsystem' incorporates:
      //   ActionPort: '<S590>/Action Port'

      // SignalConversion generated from: '<S590>/In1' incorporates:
      //   BusAssignment: '<S577>/Bus Assignment1'
      //   BusAssignment: '<S583>/Bus Assignment1'
      //   MATLABSystem: '<S583>/MATLAB System'
      //   SignalConversion generated from: '<S583>/MATLAB System'

      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].position[2] =
        MC_HEXA_MISSION_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S583>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S577>/Bus Assignment1'
      //   SignalConversion generated from: '<S589>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S590>/In2'
      //
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[0] =
        MC_HEXA_MISSION_B.In1_p.current.vx;
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[1] =
        MC_HEXA_MISSION_B.In1_p.current.vy;
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].velocity[2] =
        MC_HEXA_MISSION_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S589>/If Action Subsystem'
    }

    // End of If: '<S589>/If'

    // BusAssignment: '<S583>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   Constant: '<S583>/Constant5'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].timestamp =
      MC_HEXA_MISSION_B.In1_p.current.timestamp;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].type =
      MC_HEXA_MISSION_B.In1_p.current.type;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].yaw =
      MC_HEXA_MISSION_B.In1_p.current.yaw;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].yaw_speed =
      MC_HEXA_MISSION_B.In1_p.current.yawspeed;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[0].point_valid =
      MC_HEXA_MISSION_P.Constant5_Value_j;

    // BusAssignment: '<S577>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment'
    //   Constant: '<S587>/Constant'
    //   SignalConversion generated from: '<S584>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1] =
      MC_HEXA_MISSION_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S584>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S583>/Matrix Concatenate1'

    MC_HEXA_MISSION_B.MatrixConcatenate1[0] =
      MC_HEXA_MISSION_B.In1_p.current.lat;

    // SignalConversion generated from: '<S584>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S583>/Matrix Concatenate1'

    MC_HEXA_MISSION_B.MatrixConcatenate1[1] =
      MC_HEXA_MISSION_B.In1_p.current.lon;

    // DataTypeConversion: '<S584>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S583>/Data Type Conversion'

    MC_HEXA_MISSION_B.MatrixConcatenate1[2] =
      MC_HEXA_MISSION_B.In1_p.current.alt;
    MC_HEXA_MISSION_MATLABSystem(MC_HEXA_MISSION_B.MatrixConcatenate1,
      MC_HEXA_MISSION_B.MatrixConcatenate1_k,
      MC_HEXA_MISSION_B.In1_p.current.valid,
      MC_HEXA_MISSION_B.In1_p.current.type, &MC_HEXA_MISSION_B.MATLABSystem_b);

    // SignalConversion generated from: '<S584>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S584>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[0] =
      MC_HEXA_MISSION_B.In1_p.current.vx;

    // SignalConversion generated from: '<S584>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S584>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[1] =
      MC_HEXA_MISSION_B.In1_p.current.vy;

    // SignalConversion generated from: '<S584>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S584>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].velocity[2] =
      MC_HEXA_MISSION_B.In1_p.current.vz;

    // BusAssignment: '<S584>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S583>/Bus Assignment1'
    //   Constant: '<S584>/Constant5'
    //   MATLABSystem: '<S584>/MATLAB System'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].timestamp =
      MC_HEXA_MISSION_B.In1_p.current.timestamp;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[0] =
      MC_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[0];
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[1] =
      MC_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[1];
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].position[2] =
      MC_HEXA_MISSION_B.MATLABSystem_b.MATLABSystem[2];
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].yaw =
      MC_HEXA_MISSION_B.In1_p.current.yaw;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].yaw_speed =
      MC_HEXA_MISSION_B.In1_p.current.yawspeed;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].point_valid =
      MC_HEXA_MISSION_P.Constant5_Value_k;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[1].type =
      MC_HEXA_MISSION_B.In1_p.current.type;

    // BusAssignment: '<S577>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment'
    //   Constant: '<S587>/Constant'
    //   SignalConversion generated from: '<S586>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2] =
      MC_HEXA_MISSION_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S586>/MATLAB System' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   DataTypeConversion: '<S577>/Data Type Conversion'
    //   DataTypeConversion: '<S586>/Data Type Conversion'
    //   SignalConversion generated from: '<S577>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S586>/Matrix Concatenate'
    //
    if (MC_HEXA_MISSION_B.In1_p.next.valid) {
      MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.In1_p.next.lat -
        MC_HEXA_MISSION_B.In1_f.lat;
      MC_HEXA_MISSION_B.Gain_i = MC_HEXA_MISSION_B.In1_p.next.lon -
        MC_HEXA_MISSION_B.In1_f.lon;
      MC_HEXA_MISSION_B.Gain2_g = fabs(MC_HEXA_MISSION_B.Sum_f);
      if (MC_HEXA_MISSION_B.Gain2_g > 180.0) {
        if (rtIsNaN(MC_HEXA_MISSION_B.Sum_f + 180.0) || rtIsInf
            (MC_HEXA_MISSION_B.Sum_f + 180.0)) {
          MC_HEXA_MISSION_B.Gain2_g = (rtNaN);
        } else if (MC_HEXA_MISSION_B.Sum_f + 180.0 == 0.0) {
          MC_HEXA_MISSION_B.Gain2_g = 0.0;
        } else {
          MC_HEXA_MISSION_B.Gain2_g = fmod(MC_HEXA_MISSION_B.Sum_f + 180.0,
            360.0);
          if (MC_HEXA_MISSION_B.Gain2_g == 0.0) {
            MC_HEXA_MISSION_B.Gain2_g = 0.0;
          } else if (MC_HEXA_MISSION_B.Sum_f + 180.0 < 0.0) {
            MC_HEXA_MISSION_B.Gain2_g += 360.0;
          }
        }

        MC_HEXA_MISSION_B.Sum_f = MC_HEXA_MISSION_B.Sum_f * 0.0 +
          (MC_HEXA_MISSION_B.Gain2_g - 180.0);
        MC_HEXA_MISSION_B.Gain2_g = fabs(MC_HEXA_MISSION_B.Sum_f);
      }

      if (MC_HEXA_MISSION_B.Gain2_g > 90.0) {
        MC_HEXA_MISSION_B.Gain2_g = fabs(MC_HEXA_MISSION_B.Sum_f);
        MC_HEXA_MISSION_B.OR_g = (MC_HEXA_MISSION_B.Gain2_g > 90.0);
        MC_HEXA_MISSION_B.Gain_i += 180.0;
        MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_B.Sum_f * static_cast<
          real_T>(MC_HEXA_MISSION_B.OR_g);
        if (rtIsNaN(MC_HEXA_MISSION_B.Switch2_a)) {
          MC_HEXA_MISSION_B.u0 = (rtNaN);
        } else if (MC_HEXA_MISSION_B.Switch2_a < 0.0) {
          MC_HEXA_MISSION_B.u0 = -1.0;
        } else {
          MC_HEXA_MISSION_B.u0 = (MC_HEXA_MISSION_B.Switch2_a > 0.0);
        }

        MC_HEXA_MISSION_B.Sum_f = (90.0 - (MC_HEXA_MISSION_B.Gain2_g *
          static_cast<real_T>(MC_HEXA_MISSION_B.OR_g) - 90.0)) *
          MC_HEXA_MISSION_B.u0 * static_cast<real_T>(MC_HEXA_MISSION_B.OR_g) +
          MC_HEXA_MISSION_B.Sum_f * static_cast<real_T>(!MC_HEXA_MISSION_B.OR_g);
      }

      if ((MC_HEXA_MISSION_B.Gain_i > 180.0) || (MC_HEXA_MISSION_B.Gain_i <
           -180.0)) {
        MC_HEXA_MISSION_B.Gain2_g = MC_HEXA_MISSION_rt_remd_snf
          (MC_HEXA_MISSION_B.Gain_i, 360.0);
        MC_HEXA_MISSION_B.Switch2_a = MC_HEXA_MISSION_B.Gain2_g / 180.0;
        if (MC_HEXA_MISSION_B.Switch2_a < 0.0) {
          MC_HEXA_MISSION_B.u0 = ceil(MC_HEXA_MISSION_B.Switch2_a);
        } else {
          MC_HEXA_MISSION_B.u0 = floor(MC_HEXA_MISSION_B.Switch2_a);
        }

        MC_HEXA_MISSION_B.Gain_i = (MC_HEXA_MISSION_B.Gain2_g - 360.0 *
          MC_HEXA_MISSION_B.u0) + MC_HEXA_MISSION_B.Gain_i * 0.0;
      }

      MC_HEXA_MISSION_B.u0 = MC_HEXA_MISSION_sind_a(MC_HEXA_MISSION_B.In1_f.lat);
      MC_HEXA_MISSION_B.Gain2_g = 6.378137E+6 / sqrt(1.0 - 0.0066943799901413165
        * MC_HEXA_MISSION_B.u0 * MC_HEXA_MISSION_B.u0);
      if (rtIsInf(MC_HEXA_MISSION_B.In1_f.lat) || rtIsNaN
          (MC_HEXA_MISSION_B.In1_f.lat)) {
        MC_HEXA_MISSION_B.Gain3 = (rtNaN);
      } else {
        MC_HEXA_MISSION_B.Gain3 = MC_HEXA_MISSION_rt_remd_snf
          (MC_HEXA_MISSION_B.In1_f.lat, 360.0);
        MC_HEXA_MISSION_B.Saturation1 = fabs(MC_HEXA_MISSION_B.Gain3);
        if (MC_HEXA_MISSION_B.Saturation1 > 180.0) {
          if (MC_HEXA_MISSION_B.Gain3 > 0.0) {
            MC_HEXA_MISSION_B.Gain3 -= 360.0;
          } else {
            MC_HEXA_MISSION_B.Gain3 += 360.0;
          }

          MC_HEXA_MISSION_B.Saturation1 = fabs(MC_HEXA_MISSION_B.Gain3);
        }

        if (MC_HEXA_MISSION_B.Saturation1 <= 45.0) {
          MC_HEXA_MISSION_B.Gain3 = cos(0.017453292519943295 *
            MC_HEXA_MISSION_B.Gain3);
        } else if (MC_HEXA_MISSION_B.Saturation1 <= 135.0) {
          if (MC_HEXA_MISSION_B.Gain3 > 0.0) {
            MC_HEXA_MISSION_B.Gain3 = -sin((MC_HEXA_MISSION_B.Gain3 - 90.0) *
              0.017453292519943295);
          } else {
            MC_HEXA_MISSION_B.Gain3 = sin((MC_HEXA_MISSION_B.Gain3 + 90.0) *
              0.017453292519943295);
          }
        } else {
          if (MC_HEXA_MISSION_B.Gain3 > 0.0) {
            MC_HEXA_MISSION_B.Gain3 = (MC_HEXA_MISSION_B.Gain3 - 180.0) *
              0.017453292519943295;
          } else {
            MC_HEXA_MISSION_B.Gain3 = (MC_HEXA_MISSION_B.Gain3 + 180.0) *
              0.017453292519943295;
          }

          MC_HEXA_MISSION_B.Gain3 = -cos(MC_HEXA_MISSION_B.Gain3);
        }
      }

      MC_HEXA_MISSION_B.Sum_f /= MC_HEXA_MISSION_rt_atan2d_snf(1.0,
        0.99330562000985867 / (1.0 - 0.0066943799901413165 *
        MC_HEXA_MISSION_B.u0 * MC_HEXA_MISSION_B.u0) * MC_HEXA_MISSION_B.Gain2_g)
        * 57.295779513082323;
      MC_HEXA_MISSION_B.Gain_i /= MC_HEXA_MISSION_rt_atan2d_snf(1.0,
        MC_HEXA_MISSION_B.Gain2_g * MC_HEXA_MISSION_B.Gain3) *
        57.295779513082323;
      MC_HEXA_MISSION_B.Switch2_a = -static_cast<real_T>
        (MC_HEXA_MISSION_B.In1_p.next.alt) + MC_HEXA_MISSION_B.In1_f.alt;
      MC_HEXA_MISSION_B.distinctWptsIdx[0] = rtIsNaN(MC_HEXA_MISSION_B.Sum_f);
      MC_HEXA_MISSION_B.distinctWptsIdx[1] = rtIsNaN(MC_HEXA_MISSION_B.Gain_i);
      MC_HEXA_MISSION_B.distinctWptsIdx[2] = rtIsNaN(MC_HEXA_MISSION_B.Switch2_a);
      MC_HEXA_MISSION_B.Compare_k = false;
      MC_HEXA_MISSION_B.iy = 0;
      exitg1 = false;
      while ((!exitg1) && (MC_HEXA_MISSION_B.iy < 3)) {
        if (MC_HEXA_MISSION_B.distinctWptsIdx[MC_HEXA_MISSION_B.iy]) {
          MC_HEXA_MISSION_B.Compare_k = true;
          exitg1 = true;
        } else {
          MC_HEXA_MISSION_B.iy++;
        }
      }

      MC_HEXA_MISSION_B.u0 = 0.0 / static_cast<real_T>
        (!MC_HEXA_MISSION_B.Compare_k);
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(MC_HEXA_MISSION_B.u0 + MC_HEXA_MISSION_B.Sum_f);
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(MC_HEXA_MISSION_B.u0 + MC_HEXA_MISSION_B.Gain_i);
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(MC_HEXA_MISSION_B.u0 + MC_HEXA_MISSION_B.Switch2_a);
    } else {
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S586>/MATLAB System'

    // SignalConversion generated from: '<S586>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[0] =
      MC_HEXA_MISSION_B.In1_p.next.vx;

    // SignalConversion generated from: '<S586>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[1] =
      MC_HEXA_MISSION_B.In1_p.next.vy;

    // SignalConversion generated from: '<S586>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   BusAssignment: '<S586>/Bus Assignment1'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].velocity[2] =
      MC_HEXA_MISSION_B.In1_p.next.vz;

    // BusAssignment: '<S586>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'
    //   Constant: '<S586>/Constant5'

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].timestamp =
      MC_HEXA_MISSION_B.In1_p.next.timestamp;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].yaw =
      MC_HEXA_MISSION_B.In1_p.next.yaw;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].yaw_speed =
      MC_HEXA_MISSION_B.In1_p.next.yawspeed;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].point_valid =
      MC_HEXA_MISSION_P.Constant5_Value_h;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[2].type =
      MC_HEXA_MISSION_B.In1_p.next.type;

    // SignalConversion generated from: '<S585>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment'
    //   BusAssignment: '<S585>/Bus Assignment1'
    //   Constant: '<S587>/Constant'

    MC_HEXA_MISSION_B.BusAssignment1_f =
      MC_HEXA_MISSION_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S585>/Bus Assignment1' incorporates:
    //   Constant: '<S585>/Constant'
    //   Constant: '<S585>/Constant1'
    //   Constant: '<S585>/Constant2'
    //   Constant: '<S585>/Constant3'
    //   Constant: '<S585>/Constant4'
    //   Constant: '<S585>/Constant5'
    //   Constant: '<S585>/Constant6'
    //   Constant: '<S585>/Constant7'

    MC_HEXA_MISSION_B.BusAssignment1_f.timestamp =
      MC_HEXA_MISSION_P.Constant7_Value;
    MC_HEXA_MISSION_B.BusAssignment1_f.yaw = MC_HEXA_MISSION_P.Constant3_Value_a;
    MC_HEXA_MISSION_B.BusAssignment1_f.yaw_speed =
      MC_HEXA_MISSION_P.Constant4_Value_g;
    MC_HEXA_MISSION_B.BusAssignment1_f.position[0] =
      MC_HEXA_MISSION_P.Constant_Value_fh[0];
    MC_HEXA_MISSION_B.BusAssignment1_f.velocity[0] =
      MC_HEXA_MISSION_P.Constant1_Value_h[0];
    MC_HEXA_MISSION_B.BusAssignment1_f.acceleration[0] =
      MC_HEXA_MISSION_P.Constant2_Value_f[0];
    MC_HEXA_MISSION_B.BusAssignment1_f.position[1] =
      MC_HEXA_MISSION_P.Constant_Value_fh[1];
    MC_HEXA_MISSION_B.BusAssignment1_f.velocity[1] =
      MC_HEXA_MISSION_P.Constant1_Value_h[1];
    MC_HEXA_MISSION_B.BusAssignment1_f.acceleration[1] =
      MC_HEXA_MISSION_P.Constant2_Value_f[1];
    MC_HEXA_MISSION_B.BusAssignment1_f.position[2] =
      MC_HEXA_MISSION_P.Constant_Value_fh[2];
    MC_HEXA_MISSION_B.BusAssignment1_f.velocity[2] =
      MC_HEXA_MISSION_P.Constant1_Value_h[2];
    MC_HEXA_MISSION_B.BusAssignment1_f.acceleration[2] =
      MC_HEXA_MISSION_P.Constant2_Value_f[2];
    MC_HEXA_MISSION_B.BusAssignment1_f.point_valid =
      MC_HEXA_MISSION_P.Constant5_Value_l;
    MC_HEXA_MISSION_B.BusAssignment1_f.type = MC_HEXA_MISSION_P.Constant6_Value;

    // BusAssignment: '<S577>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment'
    //   BusAssignment: '<S585>/Bus Assignment1'
    //   Concatenate: '<S577>/Matrix Concatenate'
    //   Constant: '<S577>/Constant'
    //   Constant: '<S587>/Constant'

    MC_HEXA_MISSION_B.BusAssignment1.timestamp =
      MC_HEXA_MISSION_B.In1_p.timestamp;
    MC_HEXA_MISSION_B.BusAssignment1.type = MC_HEXA_MISSION_P.Constant_Value_fm;
    for (MC_HEXA_MISSION_B.i1 = 0; MC_HEXA_MISSION_B.i1 < 7;
         MC_HEXA_MISSION_B.i1++) {
      MC_HEXA_MISSION_B.BusAssignment1._padding0[MC_HEXA_MISSION_B.i1] =
        MC_HEXA_MISSION_P.Constant_Value._padding0[MC_HEXA_MISSION_B.i1];
    }

    MC_HEXA_MISSION_B.BusAssignment1.waypoints[3] =
      MC_HEXA_MISSION_B.BusAssignment1_f;
    MC_HEXA_MISSION_B.BusAssignment1.waypoints[4] =
      MC_HEXA_MISSION_B.BusAssignment1_f;

    // MATLABSystem: '<S588>/SinkBlock' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'

    uORB_write_step(MC_HEXA_MISSION_DW.obj_mc.orbMetadataObj,
                    &MC_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj,
                    &MC_HEXA_MISSION_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S560>/Send waypoints to OBC'
  MC_HEXA_MISSION_PX4Timestamp(&MC_HEXA_MISSION_B.PX4Timestamp_o);
}

// Model initialize function
void MC_HEXA_MISSION_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  MC_HEXA_MISSION_P.Constant1_Value_d[0] = rtNaNF;
  MC_HEXA_MISSION_P.Constant1_Value_d[1] = rtNaNF;
  MC_HEXA_MISSION_P.Constant_Value_f2 = rtNaNF;
  MC_HEXA_MISSION_P.Constant1_Value_k4[0] = rtNaNF;
  MC_HEXA_MISSION_P.Constant1_Value_k4[1] = rtNaNF;
  MC_HEXA_MISSION_P.Constant_Value_l4 = rtNaNF;
  MC_HEXA_MISSION_P.Constant_Value_fh[0] = rtNaNF;
  MC_HEXA_MISSION_P.Constant_Value_fh[1] = rtNaNF;
  MC_HEXA_MISSION_P.Constant_Value_fh[2] = rtNaNF;
  MC_HEXA_MISSION_P.Constant1_Value_h[0] = rtNaNF;
  MC_HEXA_MISSION_P.Constant1_Value_h[1] = rtNaNF;
  MC_HEXA_MISSION_P.Constant1_Value_h[2] = rtNaNF;
  MC_HEXA_MISSION_P.Constant2_Value_f[0] = rtNaNF;
  MC_HEXA_MISSION_P.Constant2_Value_f[1] = rtNaNF;
  MC_HEXA_MISSION_P.Constant2_Value_f[2] = rtNaNF;
  MC_HEXA_MISSION_P.Constant3_Value_a = rtNaNF;
  MC_HEXA_MISSION_P.Constant4_Value_g = rtNaNF;

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
    px4_Bus_vehicle_rates_setpoint rtb_BusAssignment_p;
    real_T tmp;

    // Start for If: '<S559>/If'
    MC_HEXA_MISSION_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S19>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    MC_HEXA_MISSION_B.In1_k = MC_HEXA_MISSION_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S19>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S598>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S602>/Out1' incorporates:
    //   SignalConversion generated from: '<S602>/In1'

    MC_HEXA_MISSION_B.In1_b = MC_HEXA_MISSION_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S598>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S581>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S582>/In1' incorporates:
    //   Outport: '<S582>/Out1'

    MC_HEXA_MISSION_B.In1 = MC_HEXA_MISSION_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S581>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S579>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S594>/In1' incorporates:
    //   Outport: '<S594>/Out1'

    MC_HEXA_MISSION_B.In1_p = MC_HEXA_MISSION_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S579>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S578>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S593>/In1' incorporates:
    //   Outport: '<S593>/Out1'

    MC_HEXA_MISSION_B.In1_f = MC_HEXA_MISSION_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S578>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S600>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S604>/Out1' incorporates:
    //   SignalConversion generated from: '<S604>/In1'

    MC_HEXA_MISSION_B.In1_c = MC_HEXA_MISSION_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S600>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S559>/Take-off'
    // InitializeConditions for Delay: '<S571>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_c = MC_HEXA_MISSION_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S572>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_d =
      MC_HEXA_MISSION_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S572>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S573>/yaw_In' incorporates:
    //   Outport: '<S573>/yaw_Out'

    MC_HEXA_MISSION_B.yaw_In_ik = MC_HEXA_MISSION_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S572>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S559>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S559>/Land'
    // InitializeConditions for Delay: '<S562>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_l[0] =
      MC_HEXA_MISSION_P.Delay_InitialCondition_n;
    MC_HEXA_MISSION_DW.Delay_DSTATE_l[1] =
      MC_HEXA_MISSION_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S567>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_n =
      MC_HEXA_MISSION_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S568>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE_b =
      MC_HEXA_MISSION_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S568>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S570>/yaw_In' incorporates:
    //   Outport: '<S570>/yaw_Out'

    MC_HEXA_MISSION_B.yaw_In_i = MC_HEXA_MISSION_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S568>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S567>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S569>/In' incorporates:
    //   Outport: '<S569>/Out'

    MC_HEXA_MISSION_B.In = MC_HEXA_MISSION_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S567>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S559>/Land'

    // SystemInitialize for IfAction SubSystem: '<S559>/Waypoint'
    // Start for MATLABSystem: '<S564>/UAV Waypoint Follower'
    MC_HEXA_MISSION_DW.obj.LastWaypointFlag = false;
    MC_HEXA_MISSION_DW.obj.StartFlag = true;
    MC_HEXA_MISSION_DW.obj.LookaheadFactor = 1.01;
    MC_HEXA_MISSION_DW.obj.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S564>/UAV Waypoint Follower'
    MC_HEXA_MISSION_DW.obj.WaypointIndex = 1.0;
    memset(&MC_HEXA_MISSION_DW.obj.WaypointsInternal[0], 0, 9U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S559>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S559>/IDLE'
    // InitializeConditions for Delay: '<S565>/Delay'
    MC_HEXA_MISSION_DW.Delay_DSTATE =
      MC_HEXA_MISSION_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S565>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S566>/yaw_In' incorporates:
    //   Outport: '<S566>/yaw_Out'

    MC_HEXA_MISSION_B.yaw_In = MC_HEXA_MISSION_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S565>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S559>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S599>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S603>/In1' incorporates:
    //   Outport: '<S603>/Out1'

    MC_HEXA_MISSION_B.In1_m = MC_HEXA_MISSION_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S599>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/mc_pos_controller'
    MC_HEXA_MISSION_mc_pos_controller_Init();

    // End of SystemInitialize for SubSystem: '<S23>/mc_pos_controller'

    // SystemInitialize for Enabled SubSystem: '<S23>/mc_att_controller'
    MC_HEXA_MISSION_mc_att_controller_Init();

    // End of SystemInitialize for SubSystem: '<S23>/mc_att_controller'

    // SystemInitialize for Enabled SubSystem: '<S597>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S601>/Out1' incorporates:
    //   SignalConversion generated from: '<S601>/In1'

    MC_HEXA_MISSION_B.In1_l = MC_HEXA_MISSION_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S597>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/mc_rate_controller'
    MC_HEXA_MISSION_mc_rate_controller_Init();

    // End of SystemInitialize for SubSystem: '<S23>/mc_rate_controller'

    // SystemInitialize for Enabled SubSystem: '<S560>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S589>/If Action Subsystem2'
    // Start for MATLABSystem: '<S592>/Read Parameter'
    MC_HEXA_MISSION_DW.obj_g.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_g.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter_SampleTime_c;
    MC_HEXA_MISSION_DW.obj_g.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_g.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6
      [0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S592>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S589>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S589>/If Action Subsystem1'
    // Start for MATLABSystem: '<S591>/Read Parameter'
    MC_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_b.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter_SampleTime_g;
    MC_HEXA_MISSION_DW.obj_b.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_b.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7
      [0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S591>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S589>/If Action Subsystem1'
    MC_HEXA_MISSION_MATLABSystem_Init(&MC_HEXA_MISSION_DW.MATLABSystem);
    MC_HEXA_MISSION_MATLABSystem_Init(&MC_HEXA_MISSION_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S586>/MATLAB System'
    MC_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S588>/SinkBlock' incorporates:
    //   BusAssignment: '<S577>/Bus Assignment1'

    MC_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_mc.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(MC_HEXA_MISSION_DW.obj_mc.orbMetadataObj,
                          &MC_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj,
                          &MC_HEXA_MISSION_B.BusAssignment1_m, 1);
    MC_HEXA_MISSION_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S560>/Send waypoints to OBC'

    // Start for MATLABSystem: '<S19>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_da.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_da.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_da.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_da.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_da.eventStructObj);
    MC_HEXA_MISSION_DW.obj_da.isSetupComplete = true;

    // Start for MATLABSystem: '<S598>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_d0.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_d0.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_d0.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_d0.eventStructObj);
    MC_HEXA_MISSION_DW.obj_d0.isSetupComplete = true;

    // Start for MATLABSystem: '<S560>/Read Parameter'
    MC_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_k.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter_SampleTime_d;
    MC_HEXA_MISSION_DW.obj_k.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_k.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S560>/Read Parameter'

    // Start for MATLABSystem: '<S581>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_e.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_e.orbMetadataObj = ORB_ID(vehicle_trajectory_waypoint);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_e.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_e.eventStructObj);
    MC_HEXA_MISSION_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S579>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_kz.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_kz.orbMetadataObj = ORB_ID(position_setpoint_triplet);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_kz.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_kz.eventStructObj);
    MC_HEXA_MISSION_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S578>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_gff.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_gff.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_gff.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_gff.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_gff.eventStructObj);
    MC_HEXA_MISSION_DW.obj_gff.isSetupComplete = true;

    // Start for MATLABSystem: '<S560>/LLA2LocalCoordinates'
    MC_HEXA_MISSION_DW.obj_mr.previousValidReceived = false;
    MC_HEXA_MISSION_DW.obj_mr.nextValidReceived = false;
    MC_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_mr.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S600>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_mg.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_mg.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_mg.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_mg.eventStructObj);
    MC_HEXA_MISSION_DW.obj_mg.isSetupComplete = true;

    // Start for MATLABSystem: '<S599>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_gv.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_gv.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_gv.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_gv.eventStructObj);
    MC_HEXA_MISSION_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S597>/SourceBlock'
    MC_HEXA_MISSION_DW.obj_po.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_po.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_po.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(MC_HEXA_MISSION_DW.obj_po.orbMetadataObj,
                         &MC_HEXA_MISSION_DW.obj_po.eventStructObj);
    MC_HEXA_MISSION_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S7>/Read Parameter13'
    MC_HEXA_MISSION_DW.obj_ka.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_ka.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter13_SampleTime;
    MC_HEXA_MISSION_DW.obj_ka.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_ka.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_ka.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_ka.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_ka.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter13'

    // Start for MATLABSystem: '<S7>/Read Parameter1'
    MC_HEXA_MISSION_DW.obj_a.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_a.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter1_SampleTime;
    MC_HEXA_MISSION_DW.obj_a.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_a.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1
      [0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter1'

    // Start for MATLABSystem: '<S7>/Read Parameter2'
    MC_HEXA_MISSION_DW.obj_ng.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_ng.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter2_SampleTime;
    MC_HEXA_MISSION_DW.obj_ng.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_ng.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_ng.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_ng.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/Read Parameter3'
    MC_HEXA_MISSION_DW.obj_n0.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_n0.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter3_SampleTime;
    MC_HEXA_MISSION_DW.obj_n0.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_n0.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_n0.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_n0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_n0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter3'

    // Start for MATLABSystem: '<S7>/Read Parameter4'
    MC_HEXA_MISSION_DW.obj_cf.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_cf.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter4_SampleTime;
    MC_HEXA_MISSION_DW.obj_cf.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_cf.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_cf.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_cf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_cf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter4'

    // Start for MATLABSystem: '<S7>/Read Parameter5'
    MC_HEXA_MISSION_DW.obj_p1.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_p1.SampleTime =
      MC_HEXA_MISSION_P.ReadParameter5_SampleTime;
    MC_HEXA_MISSION_DW.obj_p1.isInitialized = 1;
    if (MC_HEXA_MISSION_DW.obj_p1.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = MC_HEXA_MISSION_DW.obj_p1.SampleTime;
    }

    MC_HEXA_MISSION_DW.obj_p1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    MC_HEXA_MISSION_DW.obj_p1.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter5'
    MC_HEXA_MISSION_PX4Timestamp_Init(&MC_HEXA_MISSION_DW.PX4Timestamp_p);

    // Start for MATLABSystem: '<S34>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'

    MC_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_dz.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_dz.orbMetadataObj = ORB_ID(vehicle_rates_setpoint);
    uORB_write_initialize(MC_HEXA_MISSION_DW.obj_dz.orbMetadataObj,
                          &MC_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj,
                          &rtb_BusAssignment_p, 1);
    MC_HEXA_MISSION_DW.obj_dz.isSetupComplete = true;
    MC_HEXA_MISSION_PX4Timestamp_Init(&MC_HEXA_MISSION_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S32>/SinkBlock' incorporates:
    //   BusAssignment: '<S24>/Bus Assignment'

    MC_HEXA_MISSION_DW.obj_mgm.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_mgm.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_mgm.orbMetadataObj = ORB_ID(vehicle_attitude_setpoint);
    uORB_write_initialize(MC_HEXA_MISSION_DW.obj_mgm.orbMetadataObj,
                          &MC_HEXA_MISSION_DW.obj_mgm.orbAdvertiseObj,
                          &MC_HEXA_MISSION_B.BusAssignment_h_f, 1);
    MC_HEXA_MISSION_DW.obj_mgm.isSetupComplete = true;

    // Start for MATLABSystem: '<S22>/SinkBlock' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment'

    MC_HEXA_MISSION_DW.obj_hy.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_hy.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_hy.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_write_initialize(MC_HEXA_MISSION_DW.obj_hy.orbMetadataObj,
                          &MC_HEXA_MISSION_DW.obj_hy.orbAdvertiseObj,
                          &MC_HEXA_MISSION_B.BusAssignment_l_b, 1);
    MC_HEXA_MISSION_DW.obj_hy.isSetupComplete = true;
    MC_HEXA_MISSION_PX4Timestamp_Init(&MC_HEXA_MISSION_DW.PX4Timestamp_pn);

    // Start for MATLABSystem: '<S596>/SinkBlock' incorporates:
    //   BusAssignment: '<S557>/Bus Assignment'

    MC_HEXA_MISSION_DW.obj_o2.matlabCodegenIsDeleted = false;
    MC_HEXA_MISSION_DW.obj_o2.isInitialized = 1;
    MC_HEXA_MISSION_DW.obj_o2.orbMetadataObj = ORB_ID
      (vehicle_local_position_setpoint);
    uORB_write_initialize(MC_HEXA_MISSION_DW.obj_o2.orbMetadataObj,
                          &MC_HEXA_MISSION_DW.obj_o2.orbAdvertiseObj,
                          &MC_HEXA_MISSION_B.BusAssignment_m_p, 1);
    MC_HEXA_MISSION_DW.obj_o2.isSetupComplete = true;
    MC_HEXA_MISSION_PX4Timestamp_Init(&MC_HEXA_MISSION_DW.PX4Timestamp_o);
  }
}

// Model terminate function
void MC_HEXA_MISSION_terminate(void)
{
  // Terminate for MATLABSystem: '<S19>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_da.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_da.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_da.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_da.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_da.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S19>/SourceBlock'

  // Terminate for MATLABSystem: '<S598>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_d0.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_d0.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_d0.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S598>/SourceBlock'

  // Terminate for MATLABSystem: '<S560>/Read Parameter'
  if (!MC_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S560>/Read Parameter'

  // Terminate for MATLABSystem: '<S581>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_e.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S581>/SourceBlock'

  // Terminate for MATLABSystem: '<S579>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_kz.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S579>/SourceBlock'

  // Terminate for MATLABSystem: '<S578>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_gff.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_gff.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_gff.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_gff.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_gff.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S578>/SourceBlock'

  // Terminate for MATLABSystem: '<S560>/LLA2LocalCoordinates'
  if (!MC_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S560>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S600>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_mg.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_mg.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_mg.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_mg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S600>/SourceBlock'

  // Terminate for MATLABSystem: '<S599>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_gv.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S599>/SourceBlock'

  // Terminate for Enabled SubSystem: '<S23>/mc_pos_controller'
  MC_HEXA_MISSION_mc_pos_controller_Term();

  // End of Terminate for SubSystem: '<S23>/mc_pos_controller'

  // Terminate for Enabled SubSystem: '<S23>/mc_att_controller'
  MC_HEXA_MISSION_mc_att_controller_Term();

  // End of Terminate for SubSystem: '<S23>/mc_att_controller'

  // Terminate for MATLABSystem: '<S597>/SourceBlock'
  if (!MC_HEXA_MISSION_DW.obj_po.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_po.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&MC_HEXA_MISSION_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S597>/SourceBlock'

  // Terminate for Enabled SubSystem: '<S23>/mc_rate_controller'
  MC_HEXA_MISSION_mc_rate_controller_Term();

  // End of Terminate for SubSystem: '<S23>/mc_rate_controller'

  // Terminate for MATLABSystem: '<S7>/Read Parameter13'
  if (!MC_HEXA_MISSION_DW.obj_ka.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_ka.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter13'

  // Terminate for MATLABSystem: '<S7>/Read Parameter1'
  if (!MC_HEXA_MISSION_DW.obj_a.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter1'

  // Terminate for MATLABSystem: '<S7>/Read Parameter2'
  if (!MC_HEXA_MISSION_DW.obj_ng.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/Read Parameter3'
  if (!MC_HEXA_MISSION_DW.obj_n0.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_n0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter3'

  // Terminate for MATLABSystem: '<S7>/Read Parameter4'
  if (!MC_HEXA_MISSION_DW.obj_cf.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_cf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter4'

  // Terminate for MATLABSystem: '<S7>/Read Parameter5'
  if (!MC_HEXA_MISSION_DW.obj_p1.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_p1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter5'
  MC_HEXA_MISSION_PX4Timestamp_Term(&MC_HEXA_MISSION_DW.PX4Timestamp_p);

  // Terminate for MATLABSystem: '<S34>/SinkBlock'
  if (!MC_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_dz.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_dz.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_dz.isSetupComplete) {
      uORB_write_terminate(&MC_HEXA_MISSION_DW.obj_dz.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S34>/SinkBlock'
  MC_HEXA_MISSION_PX4Timestamp_Term(&MC_HEXA_MISSION_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S32>/SinkBlock'
  if (!MC_HEXA_MISSION_DW.obj_mgm.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_mgm.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_mgm.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_mgm.isSetupComplete) {
      uORB_write_terminate(&MC_HEXA_MISSION_DW.obj_mgm.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S32>/SinkBlock'

  // Terminate for MATLABSystem: '<S22>/SinkBlock'
  if (!MC_HEXA_MISSION_DW.obj_hy.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_hy.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_hy.isSetupComplete) {
      uORB_write_terminate(&MC_HEXA_MISSION_DW.obj_hy.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SinkBlock'
  MC_HEXA_MISSION_PX4Timestamp_Term(&MC_HEXA_MISSION_DW.PX4Timestamp_pn);

  // Terminate for MATLABSystem: '<S596>/SinkBlock'
  if (!MC_HEXA_MISSION_DW.obj_o2.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_o2.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_o2.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_o2.isSetupComplete) {
      uORB_write_terminate(&MC_HEXA_MISSION_DW.obj_o2.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S596>/SinkBlock'

  // Terminate for Enabled SubSystem: '<S560>/Send waypoints to OBC'
  MC_HEXA_MISSION_MATLABSystem_Term(&MC_HEXA_MISSION_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S589>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S592>/Read Parameter'
  if (!MC_HEXA_MISSION_DW.obj_g.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S592>/Read Parameter'
  // End of Terminate for SubSystem: '<S589>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S589>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S591>/Read Parameter'
  if (!MC_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S591>/Read Parameter'
  // End of Terminate for SubSystem: '<S589>/If Action Subsystem1'
  MC_HEXA_MISSION_MATLABSystem_Term(&MC_HEXA_MISSION_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S586>/MATLAB System'
  if (!MC_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S586>/MATLAB System'

  // Terminate for MATLABSystem: '<S588>/SinkBlock'
  if (!MC_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted) {
    MC_HEXA_MISSION_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((MC_HEXA_MISSION_DW.obj_mc.isInitialized == 1) &&
        MC_HEXA_MISSION_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&MC_HEXA_MISSION_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S588>/SinkBlock'
  // End of Terminate for SubSystem: '<S560>/Send waypoints to OBC'
  MC_HEXA_MISSION_PX4Timestamp_Term(&MC_HEXA_MISSION_DW.PX4Timestamp_o);
}

//
// File trailer for generated code.
//
// [EOF]
//
