//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hexacopter_ControllerWithNavigation_ver2023b.cpp
//
// Code generated for Simulink model 'Hexacopter_ControllerWithNavigation_ver2023b'.
//
// Model version                  : 4.4
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jul 27 17:27:58 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Hexacopter_ControllerWithNavigation_ver2023b.h"
#include "rtwtypes.h"
#include "Hexacopter_ControllerWithNavigation_ver2023b_types.h"
#include "Hexacopter_ControllerWithNavigation_ver2023b_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"
#include <float.h>

// Named constants for Chart: '<S4>/Chart'
const uint8_T Hexacopter_ControllerWithNavigation_ver2023b_IN_MISSION = 1U;
const uint8_T Hexacopter_ControllerWithNavigation_ver2023b_IN_STABLIZED = 2U;
const real_T Hexacopter_ControllerWithNavigation_ver2023b_period = 0.01;

// Block signals (default storage)
B_Hexacopter_ControllerWithNavigation_ver2023b_T
  Hexacopter_ControllerWithNavigation_ver2023b_B;

// Block states (default storage)
DW_Hexacopter_ControllerWithNavigation_ver2023b_T
  Hexacopter_ControllerWithNavigation_ver2023b_DW;

// Real-time model
RT_MODEL_Hexacopter_ControllerWithNavigation_ver2023b_T
  Hexacopter_ControllerWithNavigation_ver2023b_M_ =
  RT_MODEL_Hexacopter_ControllerWithNavigation_ver2023b_T();
RT_MODEL_Hexacopter_ControllerWithNavigation_ver2023b_T *const
  Hexacopter_ControllerWithNavigation_ver2023b_M =
  &Hexacopter_ControllerWithNavigation_ver2023b_M_;

// Forward declaration for local functions
static real_T Hexacopter_ControllerWithNavigation_ver2023b_sind(real_T x);

// Forward declaration for local functions
static real_T Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf(real_T u0,
  real_T u1);
static real_T Hexacopter_ControllerWithNavigation_ver2023b_sind_c(real_T x);
static real_T Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf(real_T
  u0, real_T u1);
static void Hexacopter_ControllerWithNavigation_ver2023b_lla2ned(const real_T
  lla[3], const real_T lla0[3], real_T xyzNED[3]);
static real_T Hexacopter_ControllerWithNavigation_ver2023b_norm(const real_T x[3]);
static void Hexacopter_ControllerWithNavigation_ver2023b_SystemCore_setup
  (px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_ve_T *obj,
   boolean_T varargin_1, boolean_T varargin_2);
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

static real_T Hexacopter_ControllerWithNavigation_ver2023b_sind(real_T x)
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
void Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Init
  (DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T *localDW)
{
  // Start for MATLABSystem: '<S51>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem(const real_T
  rtu_0[3], const real_T rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T *localB)
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

    flat = Hexacopter_ControllerWithNavigation_ver2023b_sind(rtu_1[0]);
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
void Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Term
  (DW_MATLABSystem_Hexacopter_ControllerWithNavigation_ver2023b_T *localDW)
{
  // Terminate for MATLABSystem: '<S51>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S51>/MATLAB System'
}

static real_T Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf(real_T u0,
  real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.q = ceil(u1);
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != Hexacopter_ControllerWithNavigation_ver2023b_B.q))
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.q = fabs(u0 / u1);
      if (!(fabs(Hexacopter_ControllerWithNavigation_ver2023b_B.q - floor
                 (Hexacopter_ControllerWithNavigation_ver2023b_B.q + 0.5)) >
            DBL_EPSILON * Hexacopter_ControllerWithNavigation_ver2023b_B.q)) {
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

static real_T Hexacopter_ControllerWithNavigation_ver2023b_sind_c(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S54>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf(x, 360.0);
    Hexacopter_ControllerWithNavigation_ver2023b_B.absx_n = fabs(b_x);
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.absx_n > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.absx_n = fabs(b_x);
    }

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.absx_n <= 45.0) {
      b_x = sin(0.017453292519943295 * b_x);
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.absx_n <= 135.0) {
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

static real_T Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf(real_T
  u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i = 1;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i = -1;
    }

    if (u1 > 0.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i1_l = 1;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i1_l = -1;
    }

    y = atan2(static_cast<real_T>
              (Hexacopter_ControllerWithNavigation_ver2023b_B.i),
              static_cast<real_T>
              (Hexacopter_ControllerWithNavigation_ver2023b_B.i1_l));
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

static void Hexacopter_ControllerWithNavigation_ver2023b_lla2ned(const real_T
  lla[3], const real_T lla0[3], real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  Hexacopter_ControllerWithNavigation_ver2023b_B.dLat = lla[0] - lla0[0];
  Hexacopter_ControllerWithNavigation_ver2023b_B.dLon = lla[1] - lla0[1];
  Hexacopter_ControllerWithNavigation_ver2023b_B.flat = fabs
    (Hexacopter_ControllerWithNavigation_ver2023b_B.dLat);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.flat > 180.0) {
    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.dLat + 180.0) ||
        rtIsInf(Hexacopter_ControllerWithNavigation_ver2023b_B.dLat + 180.0)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.flat = (rtNaN);
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.dLat + 180.0 ==
               0.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.flat = 0.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.flat = fmod
        (Hexacopter_ControllerWithNavigation_ver2023b_B.dLat + 180.0, 360.0);
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.flat == 0.0) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.flat = 0.0;
      } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.dLat + 180.0 <
                 0.0) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.flat += 360.0;
      }
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.dLat =
      Hexacopter_ControllerWithNavigation_ver2023b_B.dLat * 0.0 +
      (Hexacopter_ControllerWithNavigation_ver2023b_B.flat - 180.0);
    Hexacopter_ControllerWithNavigation_ver2023b_B.flat = fabs
      (Hexacopter_ControllerWithNavigation_ver2023b_B.dLat);
  }

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.flat > 90.0) {
    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    Hexacopter_ControllerWithNavigation_ver2023b_B.flat = fabs
      (Hexacopter_ControllerWithNavigation_ver2023b_B.dLat);
    Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.flat > 90.0);

    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    Hexacopter_ControllerWithNavigation_ver2023b_B.dLon += 180.0;
    Hexacopter_ControllerWithNavigation_ver2023b_B.Rn =
      Hexacopter_ControllerWithNavigation_ver2023b_B.dLat * static_cast<real_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l);
    if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Rn)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn = (rtNaN);
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Rn < 0.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn = -1.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn =
        (Hexacopter_ControllerWithNavigation_ver2023b_B.Rn > 0.0);
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.dLat = (90.0 -
      (Hexacopter_ControllerWithNavigation_ver2023b_B.flat * static_cast<real_T>
       (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l) - 90.0)) *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn * static_cast<real_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.dLat * static_cast<real_T>(
      !Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l);
  }

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  if ((Hexacopter_ControllerWithNavigation_ver2023b_B.dLon > 180.0) ||
      (Hexacopter_ControllerWithNavigation_ver2023b_B.dLon < -180.0)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.flat =
      Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf
      (Hexacopter_ControllerWithNavigation_ver2023b_B.dLon, 360.0);
    Hexacopter_ControllerWithNavigation_ver2023b_B.Rn =
      Hexacopter_ControllerWithNavigation_ver2023b_B.flat / 180.0;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Rn < 0.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn = ceil
        (Hexacopter_ControllerWithNavigation_ver2023b_B.Rn);
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn = floor
        (Hexacopter_ControllerWithNavigation_ver2023b_B.Rn);
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.dLon =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.flat - 360.0 *
       Hexacopter_ControllerWithNavigation_ver2023b_B.Rn) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.dLon * 0.0;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.flat =
    Hexacopter_ControllerWithNavigation_ver2023b_sind_c(lla0[0]);
  Hexacopter_ControllerWithNavigation_ver2023b_B.flat = 1.0 -
    0.0066943799901413165 * Hexacopter_ControllerWithNavigation_ver2023b_B.flat *
    Hexacopter_ControllerWithNavigation_ver2023b_B.flat;
  Hexacopter_ControllerWithNavigation_ver2023b_B.Rn = 6.378137E+6 / sqrt
    (Hexacopter_ControllerWithNavigation_ver2023b_B.flat);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.b_x = (rtNaN);
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.b_x =
      Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf(lla0[0], 360.0);
    Hexacopter_ControllerWithNavigation_ver2023b_B.absx = fabs
      (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x);
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.absx > 180.0) {
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x > 0.0) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_x -= 360.0;
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_x += 360.0;
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.absx = fabs
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x);
    }

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.absx <= 45.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_x = cos
        (0.017453292519943295 *
         Hexacopter_ControllerWithNavigation_ver2023b_B.b_x);
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.absx <= 135.0) {
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x > 0.0) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_x = -sin
          ((Hexacopter_ControllerWithNavigation_ver2023b_B.b_x - 90.0) *
           0.017453292519943295);
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_x = sin
          ((Hexacopter_ControllerWithNavigation_ver2023b_B.b_x + 90.0) *
           0.017453292519943295);
      }
    } else {
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x > 0.0) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_x =
          (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x - 180.0) *
          0.017453292519943295;
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_x =
          (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x + 180.0) *
          0.017453292519943295;
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.b_x = -cos
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b_x);
    }
  }

  xyzNED[0] = Hexacopter_ControllerWithNavigation_ver2023b_B.dLat /
    (Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf(1.0,
      0.99330562000985867 / Hexacopter_ControllerWithNavigation_ver2023b_B.flat *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn) * 57.295779513082323);
  xyzNED[1] = Hexacopter_ControllerWithNavigation_ver2023b_B.dLon /
    (Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf(1.0,
      Hexacopter_ControllerWithNavigation_ver2023b_B.Rn *
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_x) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_d[0] = rtIsNaN(xyzNED[0]);
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_d[1] = rtIsNaN(xyzNED[1]);
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_d[2] = rtIsNaN(xyzNED[2]);
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l = false;
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (Hexacopter_ControllerWithNavigation_ver2023b_B.b_k < 3))
  {
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.b_d[Hexacopter_ControllerWithNavigation_ver2023b_B.b_k])
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l = true;
      exitg1 = true;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  Hexacopter_ControllerWithNavigation_ver2023b_B.dLat = 0.0 / static_cast<real_T>
    (!Hexacopter_ControllerWithNavigation_ver2023b_B.latp2_l);
  xyzNED[0] += Hexacopter_ControllerWithNavigation_ver2023b_B.dLat;
  xyzNED[1] += Hexacopter_ControllerWithNavigation_ver2023b_B.dLat;
  xyzNED[2] += Hexacopter_ControllerWithNavigation_ver2023b_B.dLat;
}

static real_T Hexacopter_ControllerWithNavigation_ver2023b_norm(const real_T x[3])
{
  real_T y;
  Hexacopter_ControllerWithNavigation_ver2023b_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
  Hexacopter_ControllerWithNavigation_ver2023b_B.absxk = fabs(x[0]);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.absxk >
      3.3121686421112381E-170) {
    y = 1.0;
    Hexacopter_ControllerWithNavigation_ver2023b_B.scale =
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.t =
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk /
      3.3121686421112381E-170;
    y = Hexacopter_ControllerWithNavigation_ver2023b_B.t *
      Hexacopter_ControllerWithNavigation_ver2023b_B.t;
  }

  // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
  Hexacopter_ControllerWithNavigation_ver2023b_B.absxk = fabs(x[1]);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.absxk >
      Hexacopter_ControllerWithNavigation_ver2023b_B.scale) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.t =
      Hexacopter_ControllerWithNavigation_ver2023b_B.scale /
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk;
    y = y * Hexacopter_ControllerWithNavigation_ver2023b_B.t *
      Hexacopter_ControllerWithNavigation_ver2023b_B.t + 1.0;
    Hexacopter_ControllerWithNavigation_ver2023b_B.scale =
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.t =
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk /
      Hexacopter_ControllerWithNavigation_ver2023b_B.scale;
    y += Hexacopter_ControllerWithNavigation_ver2023b_B.t *
      Hexacopter_ControllerWithNavigation_ver2023b_B.t;
  }

  // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
  Hexacopter_ControllerWithNavigation_ver2023b_B.absxk = fabs(x[2]);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.absxk >
      Hexacopter_ControllerWithNavigation_ver2023b_B.scale) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.t =
      Hexacopter_ControllerWithNavigation_ver2023b_B.scale /
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk;
    y = y * Hexacopter_ControllerWithNavigation_ver2023b_B.t *
      Hexacopter_ControllerWithNavigation_ver2023b_B.t + 1.0;
    Hexacopter_ControllerWithNavigation_ver2023b_B.scale =
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.t =
      Hexacopter_ControllerWithNavigation_ver2023b_B.absxk /
      Hexacopter_ControllerWithNavigation_ver2023b_B.scale;
    y += Hexacopter_ControllerWithNavigation_ver2023b_B.t *
      Hexacopter_ControllerWithNavigation_ver2023b_B.t;
  }

  return Hexacopter_ControllerWithNavigation_ver2023b_B.scale * sqrt(y);
}

static void Hexacopter_ControllerWithNavigation_ver2023b_SystemCore_setup
  (px4_internal_block_PWM_Hexacopter_ControllerWithNavigation_ve_T *obj,
   boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;

  // Start for MATLABSystem: '<S5>/PX4 PWM Output'
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj,
                    &obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->channelMask = 63;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain, &obj->actuatorAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, static_cast<int32_T>
      (varargin_2));
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, 0);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  }

  // End of Start for MATLABSystem: '<S5>/PX4 PWM Output'
  obj->isSetupComplete = true;
}

// Model step function
void Hexacopter_ControllerWithNavigation_ver2023b_step(void)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;

  // MATLABSystem: '<S18>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_cx, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S24>/Enable'

  // Start for MATLABSystem: '<S18>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S24>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_cx;
  }

  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'

  // MATLABSystem: '<S28>/Read Parameter'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime) {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_p);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_p = 0;
  }

  // MATLABSystem: '<S49>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S49>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S50>/Enable'

  // Start for MATLABSystem: '<S49>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S50>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S49>/Enabled Subsystem'

  // MATLABSystem: '<S47>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S47>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S62>/Enable'

  // Start for MATLABSystem: '<S47>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S62>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S47>/Enabled Subsystem'

  // MATLABSystem: '<S46>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_cv, false,
     1.0);

  // Outputs for Enabled SubSystem: '<S46>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S61>/Enable'

  // Start for MATLABSystem: '<S46>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S61>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_cv;
  }

  // End of Outputs for SubSystem: '<S46>/Enabled Subsystem'

  // MATLABSystem: '<S28>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S28>/Read Parameter'
  //   SignalConversion generated from: '<S61>/In1'
  //
  Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[2] = 0.0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] =
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat;
  Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] =
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lon;
  Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] =
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.alt;
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.previous.valid &&
      (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.previousValidReceived))
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.previousValidReceived
      = true;
  }

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.valid &&
      (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.nextValidReceived))
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.nextValidReceived =
      true;
  }

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.valid_hpos &&
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.valid &&
      (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type != 5))
  {
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_p != 0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1.waypoints[0]
        .position[0];
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1.waypoints[0]
        .position[1];
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1.waypoints[0]
        .position[2];
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
        [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.lat;
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
        [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.lon;
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
        [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.alt;
      Hexacopter_ControllerWithNavigation_ver2023b_lla2ned
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc,
         Hexacopter_ControllerWithNavigation_ver2023b_B.lla0,
         Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2);
    }
  }

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.valid_hpos &&
      (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.previous.valid ||
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.previousValidReceived))
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
      [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.previous.lat;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
      [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.previous.lon;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
      [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.previous.alt;
    Hexacopter_ControllerWithNavigation_ver2023b_lla2ned
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc,
       Hexacopter_ControllerWithNavigation_ver2023b_B.lla0,
       Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate);
  }

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.valid_hpos &&
      (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.valid ||
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.nextValidReceived))
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
      [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.lat;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
      [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.lon;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
      [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.alt;
    Hexacopter_ControllerWithNavigation_ver2023b_lla2ned
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc,
       Hexacopter_ControllerWithNavigation_ver2023b_B.lla0,
       Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3);
  }

  // If: '<S27>/If' incorporates:
  //   Delay: '<S33>/Delay'
  //   Delay: '<S36>/Delay'
  //   Delay: '<S40>/Delay'
  //   MATLABSystem: '<S28>/LLA2LocalCoordinates'
  //
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
    Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem;
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type == 3) {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem = 0;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type ==
             4) {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem = 1;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type ==
             0) {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem = 2;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem = 3;
  }

  switch (Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem) {
   case 0:
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem !=
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S27>/Take-off' incorporates:
      //   ActionPort: '<S31>/Action Port'

      // InitializeConditions for If: '<S27>/If' incorporates:
      //   Delay: '<S39>/Delay'
      //   Delay: '<S40>/Delay'

      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_c =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition;
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S27>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S27>/Take-off' incorporates:
    //   ActionPort: '<S31>/Action Port'

    // Sum: '<S39>/Sum' incorporates:
    //   Constant: '<S39>/Rate'
    //   Delay: '<S39>/Delay'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_c +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Rate_Value;

    // Gain: '<S39>/Gain1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain *
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S41>/Enable'

    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S41>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In_ik =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S40>/Enabled Subsystem2'

    // Reshape: '<S31>/Reshape' incorporates:
    //   Delay: '<S40>/Delay'
    //   Merge: '<S27>/Merge'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1];

    // Gain: '<S39>/Gain' incorporates:
    //   Delay: '<S39>/Delay'
    //   RelationalOperator: '<S39>/Relational Operator'
    //   Switch: '<S39>/Switch'

    if (!(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i <=
          Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_c)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
        Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_c;
    }

    // Reshape: '<S31>/Reshape' incorporates:
    //   Gain: '<S39>/Gain'
    //   Merge: '<S27>/Merge'
    //   Switch: '<S39>/Switch'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In_ik;

    // Update for Delay: '<S40>/Delay' incorporates:
    //   Constant: '<S40>/Constant'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_d =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_f;

    // End of Outputs for SubSystem: '<S27>/Take-off'
    break;

   case 1:
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem !=
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S27>/Land' incorporates:
      //   ActionPort: '<S30>/Action Port'

      // InitializeConditions for If: '<S27>/If' incorporates:
      //   Delay: '<S30>/Delay'
      //   Delay: '<S35>/Delay'
      //   Delay: '<S36>/Delay'
      //   Gain: '<S35>/Gain1'

      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_n;
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_n;
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_m;
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_b =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S27>/Land'
    }

    // Outputs for IfAction SubSystem: '<S27>/Land' incorporates:
    //   ActionPort: '<S30>/Action Port'

    // Switch: '<S30>/Switch' incorporates:
    //   Delay: '<S30>/Delay'
    //   Logic: '<S30>/OR'
    //   RelationalOperator: '<S30>/IsNaN'

    if ((!rtIsNaN
         (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0]))
        && (!rtIsNaN
            (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2
             [1]))) {
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0];
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1];
    }

    // End of Switch: '<S30>/Switch'

    // Switch: '<S35>/Switch' incorporates:
    //   Delay: '<S35>/Delay'

    if (!(Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n >
          Hexacopter_ControllerWithNavigation_ver2023b_P.Switch_Threshold)) {
      // Gain: '<S35>/Gain1' incorporates:
      //   Gain: '<S35>/Gain'

      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_l *
        Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2];
    }

    // End of Switch: '<S35>/Switch'

    // Sum: '<S35>/Subtract' incorporates:
    //   Constant: '<S35>/Rate of descent'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n -
      Hexacopter_ControllerWithNavigation_ver2023b_P.Rateofdescent_Value;

    // Gain: '<S35>/Gain1' incorporates:
    //   Gain: '<S35>/Gain2'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Gain2_Gain *
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S38>/Enable'

    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S38>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In_i =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S36>/Enabled Subsystem2'

    // Reshape: '<S30>/Reshape' incorporates:
    //   Delay: '<S30>/Delay'
    //   Delay: '<S36>/Delay'
    //   Merge: '<S27>/Merge'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 =
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[1];

    // Switch: '<S35>/Switch1' incorporates:
    //   RelationalOperator: '<S35>/GreaterThan'

    if (!(Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n >
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i)) {
      // Gain: '<S35>/Gain1'
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
    }

    // Reshape: '<S30>/Reshape' incorporates:
    //   Gain: '<S35>/Gain1'
    //   Merge: '<S27>/Merge'
    //   Switch: '<S35>/Switch1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain_a *
      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S37>/Enable'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S37>/In'
      Hexacopter_ControllerWithNavigation_ver2023b_B.In =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
    }

    // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

    // Update for Delay: '<S30>/Delay' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;

    // Update for Gain: '<S35>/Gain1' incorporates:
    //   Delay: '<S35>/Delay'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In;

    // Update for Delay: '<S36>/Delay' incorporates:
    //   Constant: '<S36>/Constant'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_b =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S27>/Land'
    break;

   case 2:
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem !=
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S27>/Waypoint' incorporates:
      //   ActionPort: '<S32>/Action Port'

      // SystemReset for If: '<S27>/If' incorporates:
      //   MATLABSystem: '<S32>/UAV Waypoint Follower'
      //
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex = 1.0;
      for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
           Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 9;
           Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointsInternal[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
          *= 0.0;
      }

      // End of SystemReset for If: '<S27>/If'
      // End of SystemReset for SubSystem: '<S27>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
    //   ActionPort: '<S32>/Action Port'

    // Concatenate: '<S32>/Matrix Concatenate'
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[3] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[4] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[5] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[6] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[7] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[8] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[2];

    // MATLABSystem: '<S32>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S32>/Matrix Concatenate'
    //   Constant: '<S32>/Constant'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_gw;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistFlag = 0U;
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_gw < 0.3)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i = 0.3;
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistFlag = 1U;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[0] = 0.0;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[1] = 0.0;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[2] = 0.0;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[3] = 0.0;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.NumWaypoints = 3.0;
    Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = false;
    Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f = true;
    Hexacopter_ControllerWithNavigation_ver2023b_B.i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (Hexacopter_ControllerWithNavigation_ver2023b_B.i1 <= 8))
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d =
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1 / 3 * 3 +
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1 % 3;
      if (!(Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointsInternal
            [Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d] ==
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]))
      {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f = false;
        exitg1 = true;
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1++;
      }
    }

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = true;
    }

    if (!Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
      memcpy
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointsInternal
         [0],
         &Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[0],
         9U * sizeof(real_T));
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex = 1.0;
    }

    for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 3;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
        = true;
      Hexacopter_ControllerWithNavigation_ver2023b_B.b =
        Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[3 *
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d + 1];
      Hexacopter_ControllerWithNavigation_ver2023b_B.i1 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d << 1;
      Hexacopter_ControllerWithNavigation_ver2023b_B.x[Hexacopter_ControllerWithNavigation_ver2023b_B.i1]
        = (Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[3 *
           Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d] !=
           Hexacopter_ControllerWithNavigation_ver2023b_B.b);
      Hexacopter_ControllerWithNavigation_ver2023b_B.x[Hexacopter_ControllerWithNavigation_ver2023b_B.i1
        + 1] =
        (Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[3 *
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d + 2] !=
         Hexacopter_ControllerWithNavigation_ver2023b_B.b);
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.IsNaN_l[0] = false;
    Hexacopter_ControllerWithNavigation_ver2023b_B.IsNaN_l[1] = false;
    Hexacopter_ControllerWithNavigation_ver2023b_B.i1 = 0;
    Hexacopter_ControllerWithNavigation_ver2023b_B.i2 = 4;
    for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 2;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i1++;
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2++;
      Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g =
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1;
      exitg1 = false;
      while ((!exitg1) &&
             (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g <=
              Hexacopter_ControllerWithNavigation_ver2023b_B.i2)) {
        if (Hexacopter_ControllerWithNavigation_ver2023b_B.x[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g
            - 1]) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.IsNaN_l[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
            = true;
          exitg1 = true;
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g += 2;
        }
      }
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.IsNaN_l[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S27>/Waypoint'
    Hexacopter_ControllerWithNavigation_ver2023b_B.i1 = 0;
    for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 3;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
      // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
      //   ActionPort: '<S32>/Action Port'

      if (Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d])
      {
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1++;
      }

      // End of Outputs for SubSystem: '<S27>/Waypoint'
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g =
      Hexacopter_ControllerWithNavigation_ver2023b_B.i1;
    Hexacopter_ControllerWithNavigation_ver2023b_B.i1 = 0;
    for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 3;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
      // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
      //   ActionPort: '<S32>/Action Port'

      if (Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d])
      {
        // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
        Hexacopter_ControllerWithNavigation_ver2023b_B.tmp_data[Hexacopter_ControllerWithNavigation_ver2023b_B.i1]
          = static_cast<int8_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d);
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1++;
      }

      // End of Outputs for SubSystem: '<S27>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S27>/Waypoint' incorporates:
    //   ActionPort: '<S32>/Action Port'

    // MATLABSystem: '<S32>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S32>/Matrix Concatenate'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Reshape: '<S32>/Reshape1'

    for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 3;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
      for (Hexacopter_ControllerWithNavigation_ver2023b_B.i2 = 0;
           Hexacopter_ControllerWithNavigation_ver2023b_B.i2 <
           Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g;
           Hexacopter_ControllerWithNavigation_ver2023b_B.i2++) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_waypointsIn_data[Hexacopter_ControllerWithNavigation_ver2023b_B.i2
          + Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g *
          Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[3 *
          Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d +
          Hexacopter_ControllerWithNavigation_ver2023b_B.tmp_data[Hexacopter_ControllerWithNavigation_ver2023b_B.i2]];
      }
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistance =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g == 0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
      Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
      Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
    } else {
      guard1 = false;
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g == 1) {
        if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.StartFlag) {
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[0] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[1] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[2] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[3] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.b_waypointsIn_data[0] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.b_waypointsIn_data[1] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[2] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.b_waypointsIn_data[2] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
        if (Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3) <
            1.4901161193847656E-8) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.StartFlag = false;
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.StartFlag = false;
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.NumWaypoints = 2.0;
          Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0 =
            Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g + 1;
          for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
               Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 3;
               Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.i1 =
              (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g + 1) *
              Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d;
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[Hexacopter_ControllerWithNavigation_ver2023b_B.i1]
              =
              Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.InitialPose[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d];
            for (Hexacopter_ControllerWithNavigation_ver2023b_B.i2 = 0;
                 Hexacopter_ControllerWithNavigation_ver2023b_B.i2 <
                 Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g;
                 Hexacopter_ControllerWithNavigation_ver2023b_B.i2++) {
              Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
                (Hexacopter_ControllerWithNavigation_ver2023b_B.i2 +
                 Hexacopter_ControllerWithNavigation_ver2023b_B.i1) + 1] =
                Hexacopter_ControllerWithNavigation_ver2023b_B.b_waypointsIn_data
                [Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g *
                Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d +
                Hexacopter_ControllerWithNavigation_ver2023b_B.i2];
            }
          }

          guard1 = true;
        }
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0 =
          Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g;
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1 =
          Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g * 3;
        if (Hexacopter_ControllerWithNavigation_ver2023b_B.i1 - 1 >= 0) {
          memcpy
            (&Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
             0],
             &Hexacopter_ControllerWithNavigation_ver2023b_B.b_waypointsIn_data
             [0], static_cast<uint32_T>
             (Hexacopter_ControllerWithNavigation_ver2023b_B.i1) * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = false;
        if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex ==
            Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.NumWaypoints) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = true;
        }

        if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LastWaypointFlag =
            true;
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex--;
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
          [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x -
          Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
          static_cast<int32_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
           1.0) - 1];
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
          [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y -
          Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
          static_cast<int32_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
           1.0) +
          Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0) -
          1];
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
          [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z -
          Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
          static_cast<int32_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
           1.0) +
          (Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0 <<
           1)) - 1];
        guard2 = false;
        if (Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc)
            <= 2.0) {
          guard2 = true;
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
            =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
             1.0) - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
            - Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex)
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x -
            Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1;
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
            =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
             1.0) +
            Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0)
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
            - Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
            (static_cast<int32_T>
             (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex)
             + Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0)
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y -
            Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1;
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
            =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
             1.0) +
            (Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0
             << 1)) - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_m
            =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p
            [((Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0
               << 1) + static_cast<int32_T>
              (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex))
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
            - Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_m;
          Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z -
            Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1;
          Hexacopter_ControllerWithNavigation_ver2023b_B.b =
            Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate);
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
            Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2);
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
            (Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0]
             / Hexacopter_ControllerWithNavigation_ver2023b_B.b *
             (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[
              0] / Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1]
             / Hexacopter_ControllerWithNavigation_ver2023b_B.b *
             (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[
              1] / Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i)) +
            Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] /
            Hexacopter_ControllerWithNavigation_ver2023b_B.b *
            (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2
             [2] / Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i);
          if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) ||
              (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i < 0.0)) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] =
              Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
              static_cast<int32_T>
              (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex)
              - 1];
            Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] =
              Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
              static_cast<int32_T>
              (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex
               + 1.0) - 1];
            Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] =
              Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
              (static_cast<int32_T>
               (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex)
               + Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0)
              - 1];
            Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] =
              Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
              (static_cast<int32_T>
               (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex
                + 1.0) +
               Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0)
              - 1];
            Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] =
              Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_m;
            Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] =
              Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1;
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex++;
          Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = false;
          if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex ==
              Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.NumWaypoints)
          {
            Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = true;
          }

          if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
            Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LastWaypointFlag
              = true;
            Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex--;
          }

          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex)
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
             1.0) - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex)
            + Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0)
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
             1.0) +
            Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0)
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p
            [((Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0
               << 1) + static_cast<int32_T>
              (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex))
            - 1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] =
            Hexacopter_ControllerWithNavigation_ver2023b_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex +
             1.0) +
            (Hexacopter_ControllerWithNavigation_ver2023b_B.waypoints_size_idx_0
             << 1)) - 1];
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x -
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0];
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b =
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0];
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 *
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
          Hexacopter_ControllerWithNavigation_ver2023b_B.b *
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y -
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1];
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b =
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1];
        Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.lambda +=
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 *
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i +=
          Hexacopter_ControllerWithNavigation_ver2023b_B.b *
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z -
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2];
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b =
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2];
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i +=
          Hexacopter_ControllerWithNavigation_ver2023b_B.b *
          Hexacopter_ControllerWithNavigation_ver2023b_B.b;
        Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
          (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 *
           Hexacopter_ControllerWithNavigation_ver2023b_B.b +
           Hexacopter_ControllerWithNavigation_ver2023b_B.lambda) /
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
        if (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda < 0.0) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
            Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2);
        } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda > 1.0)
        {
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x -
            Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0];
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y -
            Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1];
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z -
            Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2];
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
            Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc);
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x -
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0]);
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y -
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1] +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1]);
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z -
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2]);
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
            Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc);
        }

        if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LastWaypointFlag)
        {
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
            ((Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 *
              Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] +
              Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 *
              Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1]) +
             Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b) /
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x -
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0]);
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y -
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1] +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1]);
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc
            [2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z -
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
             Hexacopter_ControllerWithNavigation_ver2023b_B.b +
             Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2]);
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
            Hexacopter_ControllerWithNavigation_ver2023b_norm
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduc);
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = fabs
          (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda);
        if (rtIsInf
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2) ||
            rtIsNaN
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2)) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = (rtNaN);
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
            (rtNaN);
        } else if
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 <
             4.4501477170144028E-308) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
            4.94065645841247E-324;
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
            4.94065645841247E-324;
        } else {
          frexp(Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2,
                &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_l);
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = ldexp(1.0,
            Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_l - 53);
          frexp(Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2,
                &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_j);
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = ldexp
            (1.0, Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_j -
             53);
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = sqrt
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = 5.0 *
          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;
        if ((Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >=
             Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4) || rtIsNaN
            (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4)) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
            Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
        }

        if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistance
            <= Hexacopter_ControllerWithNavigation_ver2023b_B.lambda +
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4) {
          Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistance =
            Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadFactor *
            Hexacopter_ControllerWithNavigation_ver2023b_B.lambda;
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
        Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] =
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] -
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b =
          ((Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[0] *
            Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0]
            + Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_3[1] *
            Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1])
           + Hexacopter_ControllerWithNavigation_ver2023b_B.b *
           Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2])
          * 2.0;
        Hexacopter_ControllerWithNavigation_ver2023b_B.lambda = sqrt
          (Hexacopter_ControllerWithNavigation_ver2023b_B.b *
           Hexacopter_ControllerWithNavigation_ver2023b_B.b -
           (((Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[
              0] *
              Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[
              0] +
              Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[
              1] *
              Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[
              1]) +
             Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2
             [2] *
             Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2
             [2]) -
            Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistance
            * Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadDistance)
           * (4.0 * Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i));
        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
          (-Hexacopter_ControllerWithNavigation_ver2023b_B.b +
           Hexacopter_ControllerWithNavigation_ver2023b_B.lambda) / 2.0 /
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
          (-Hexacopter_ControllerWithNavigation_ver2023b_B.b -
           Hexacopter_ControllerWithNavigation_ver2023b_B.lambda) / 2.0 /
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;
        if ((Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >=
             Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) || rtIsNaN
            (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i)) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
            Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] = (1.0 -
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) *
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] +
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i *
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0];
        Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] = (1.0 -
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) *
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] +
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i *
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1];
        Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2] = (1.0 -
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) *
          Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] +
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i *
          Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2];
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
          Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf
          (Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1] -
           Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y,
           Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0] -
           Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x);
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LastWaypointFlag =
          false;
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
    if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0]) ||
        rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1]) ||
        rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2]) ||
        (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type ==
         Hexacopter_ControllerWithNavigation_ver2023b_P.CompareToConstant_const_d))
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
    } else {
      if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3))
      {
        // Switch: '<S42>/Switch' incorporates:
        //   Constant: '<S42>/Constant'
        //   Merge: '<S27>/Merge'
        //   Reshape: '<S42>/Reshape2'

        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
          Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_jd;
      }

      // Math: '<S42>/Transpose1' incorporates:
      //   Merge: '<S27>/Merge'

      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[0];
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[1];
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.lla0[2];
    }

    // End of Switch: '<S42>/Switch1'
    // End of Outputs for SubSystem: '<S27>/Waypoint'
    break;

   default:
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem !=
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S27>/IDLE' incorporates:
      //   ActionPort: '<S29>/Action Port'

      // InitializeConditions for If: '<S27>/If' incorporates:
      //   Delay: '<S33>/Delay'

      Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S27>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S27>/IDLE' incorporates:
    //   ActionPort: '<S29>/Action Port'

    // Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S34>/Enable'

    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S34>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S33>/Enabled Subsystem2'

    // Reshape: '<S29>/Reshape1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Delay: '<S33>/Delay'
    //   Merge: '<S27>/Merge'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In;

    // Update for Delay: '<S33>/Delay' incorporates:
    //   Constant: '<S33>/Constant'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_i;

    // End of Outputs for SubSystem: '<S27>/IDLE'
    break;
  }

  // End of If: '<S27>/If'

  // MATLABSystem: '<S21>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_b, false,
     5000.0);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S22>/Enable'

  // Start for MATLABSystem: '<S21>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S22>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'

  // Gain: '<S65>/Gain2' incorporates:
  //   Constant: '<S65>/Constant2'
  //   Sum: '<S65>/Sum2'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = (static_cast<real_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[1]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_b) *
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain2_Gain_j;

  // Saturate: '<S65>/Saturation2'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation2_UpperSat) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation2_UpperSat;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation2_LowerSat)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation2_LowerSat;
  }

  // Gain: '<S4>/Gain1' incorporates:
  //   Saturate: '<S65>/Saturation2'

  Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain_hq *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Gain: '<S65>/Gain1' incorporates:
  //   Constant: '<S65>/Constant1'
  //   Sum: '<S65>/Sum1'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = (static_cast<real_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[0]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_d) *
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain_mu;

  // Saturate: '<S65>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_p) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_p;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_e)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_e;
  }

  // Gain: '<S4>/Gain2' incorporates:
  //   Saturate: '<S65>/Saturation1'

  Hexacopter_ControllerWithNavigation_ver2023b_B.b =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain2_Gain_b *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Gain: '<S65>/Gain' incorporates:
  //   Constant: '<S65>/Constant'
  //   Sum: '<S65>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i = (static_cast<real_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[2]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_bk) *
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_k;

  // Saturate: '<S65>/Saturation'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_UpperSat_c) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_UpperSat_c;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_LowerSat_g)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_LowerSat_g;
  }

  // End of Saturate: '<S65>/Saturation'

  // Gain: '<S65>/Gain3' incorporates:
  //   Constant: '<S65>/Constant3'
  //   Sum: '<S65>/Sum3'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = (static_cast<real_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[3]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_a) *
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain3_Gain;

  // Saturate: '<S65>/Saturation3'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation3_UpperSat) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation3_UpperSat;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation3_LowerSat)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation3_LowerSat;
  }

  // Gain: '<S4>/Gain4' incorporates:
  //   Saturate: '<S65>/Saturation3'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain4_Gain *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // MATLABSystem: '<S17>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_p, false, 1.0);

  // Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  // Start for MATLABSystem: '<S17>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S23>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_p;
  }

  // End of Outputs for SubSystem: '<S17>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   SignalConversion generated from: '<S5>/Product1'

  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
    = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[0];
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
    = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[1];
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
    = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[2];
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
    = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[3];

  // Switch: '<S67>/Switch' incorporates:
  //   Constant: '<S67>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   Product: '<S573>/Product'
  //   Product: '<S573>/Product1'
  //   Product: '<S573>/Product2'
  //   Product: '<S573>/Product3'
  //   SignalConversion generated from: '<S5>/Product1'
  //   Sum: '<S573>/Sum'

  if (!(((static_cast<real_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[0]) *
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[0] +
          static_cast<real_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[1]) *
          Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[1]) +
         static_cast<real_T>
         (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[2]) *
         Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[2]) +
        static_cast<real_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[3]) *
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m.q[3] >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Switch_Threshold_d)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
      = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_m[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_m[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_m[2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
      = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_m[3];
  }

  // End of Switch: '<S67>/Switch'

  // Sqrt: '<S580>/sqrt' incorporates:
  //   Product: '<S581>/Product'
  //   Product: '<S581>/Product1'
  //   Product: '<S581>/Product2'
  //   Product: '<S581>/Product3'
  //   Sum: '<S581>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = sqrt
    (((Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
       * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
       + Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1)
      + Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2)
     + Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
     * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3);

  // Product: '<S575>/Product'
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
    /= Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Product: '<S575>/Product1'
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
    /= Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Product: '<S575>/Product2'
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
    /= Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Product: '<S575>/Product3'
  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
    / Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Fcn: '<S68>/fcn2' incorporates:
  //   Fcn: '<S68>/fcn5'

  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1 =
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
    * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0;
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_m =
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
    * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp =
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
    * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g =
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

  // Trigonometry: '<S574>/Trigonometric Function1' incorporates:
  //   Fcn: '<S68>/fcn1'
  //   Fcn: '<S68>/fcn2'

  Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] =
    Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf
    ((Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      + Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
      * Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o) * 2.0,
     ((Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
       + Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_m)
      - Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp)
     - Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g);

  // Fcn: '<S68>/fcn3'
  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
    =
    (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
     * Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
     Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
     * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2)
    * -2.0;

  // Trigonometry: '<S574>/Trigonometric Function3' incorporates:
  //   Fcn: '<S68>/fcn4'
  //   Fcn: '<S68>/fcn5'

  Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] =
    Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf
    ((Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      * Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
      * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1)
     * 2.0,
     ((Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g1
       - Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_m)
      - Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp)
     + Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_VectorConcatenate_tmp_g);

  // MATLABSystem: '<S15>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_f, false, 1.0);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  // Start for MATLABSystem: '<S15>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S20>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_b =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_f;
  }

  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S4>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S66>/Enable'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_b.armed) {
    // Trigonometry: '<S321>/SinCos'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      = sin(Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0]);
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = cos(Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0]);

    // Sum: '<S66>/Sum5'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 -=
      Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0];

    // Saturate: '<S415>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S413>/Proportional Gain'
    //   Sum: '<S66>/Sum1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 -
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.x) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_P_h;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit_l)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit_l;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit_e)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit_e;
    }

    // Sum: '<S66>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S415>/Saturation'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.vx;

    // Saturate: '<S415>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S413>/Proportional Gain'
    //   Sum: '<S66>/Sum1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 -
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.y) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_P_h;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit_l)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit_l;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit_e)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit_e;
    }

    // Sum: '<S66>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S415>/Saturation'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.vy;

    // Saturate: '<S367>/Saturation' incorporates:
    //   Gain: '<S321>/Gain'
    //   Gain: '<S365>/Proportional Gain'
    //   Product: '<S66>/MatrixMultiply'
    //   Reshape: '<S321>/Reshape'
    //   Reshape: '<S321>/Reshape1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 +
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_P_d;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit_b)
    {
      // Saturate: '<S367>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit_b;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit_j)
    {
      // Saturate: '<S367>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit_j;
    } else {
      // Saturate: '<S367>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_o *
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 +
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       * Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_1) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_P_d;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit_b)
    {
      // Saturate: '<S367>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit_b;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit_j)
    {
      // Saturate: '<S367>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit_j;
    } else {
      // Saturate: '<S367>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
    }

    // End of Saturate: '<S367>/Saturation'

    // Gain: '<S66>/Gain1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain1 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain_m *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[0];

    // Switch: '<S322>/Switch' incorporates:
    //   Abs: '<S322>/Abs'

    if (fabs(Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3) >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Switch_Threshold_e) {
      // Switch: '<S322>/Switch1' incorporates:
      //   Constant: '<S322>/Constant'
      //   Sum: '<S322>/Add'
      //   Sum: '<S322>/Subtract'

      if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 >
          Hexacopter_ControllerWithNavigation_ver2023b_P.Switch1_Threshold) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 -=
          Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_g4;
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3 +=
          Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_g4;
      }

      // End of Switch: '<S322>/Switch1'
    }

    // Gain: '<S461>/Proportional Gain' incorporates:
    //   Switch: '<S322>/Switch'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController5_P *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_3;

    // Saturate: '<S463>/Saturation'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController5_UpperSaturationLimit)
    {
      // Gain: '<S461>/Proportional Gain' incorporates:
      //   Saturate: '<S463>/Saturation'

      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController5_UpperSaturationLimit;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController5_LowerSaturationLimit)
    {
      // Gain: '<S461>/Proportional Gain' incorporates:
      //   Saturate: '<S463>/Saturation'

      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController5_LowerSaturationLimit;
    }

    // End of Saturate: '<S463>/Saturation'

    // Gain: '<S320>/Gain1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain_h *
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.z;

    // Switch: '<S328>/Switch' incorporates:
    //   Constant: '<S320>/Constant'
    //   RelationalOperator: '<S328>/UpperRelop'
    //   Switch: '<S328>/Switch2'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_ib) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_ib;
    }

    // Sum: '<S66>/Sum2' incorporates:
    //   Gain: '<S4>/Gain'
    //   Switch: '<S328>/Switch'
    //   Switch: '<S328>/Switch2'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      = Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_b *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 -
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

    // Gain: '<S511>/Proportional Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_P *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;

    // Gain: '<S509>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S501>/Filter'
    //   Gain: '<S500>/Derivative Gain'
    //   Sum: '<S501>/SumD'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_D *
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       - Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_N;

    // Sum: '<S516>/Sum Fdbk'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       + Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;

    // DeadZone: '<S499>/DeadZone'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_UpperSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -=
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_UpperSaturationLimit;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >=
               Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_LowerSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = 0.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -=
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_LowerSaturationLimit;
    }

    // End of DeadZone: '<S499>/DeadZone'

    // Gain: '<S503>/Integral Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      *= Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_I;

    // Switch: '<S497>/Switch1' incorporates:
    //   Constant: '<S497>/Clamping_zero'
    //   Constant: '<S497>/Constant'
    //   Constant: '<S497>/Constant2'
    //   RelationalOperator: '<S497>/fix for DT propagation issue'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_f) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_nq;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_o;
    }

    // Switch: '<S497>/Switch2' incorporates:
    //   Constant: '<S497>/Clamping_zero'
    //   Constant: '<S497>/Constant3'
    //   Constant: '<S497>/Constant4'
    //   RelationalOperator: '<S497>/fix for DT propagation issue1'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_f)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_o;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_d;
    }

    // Switch: '<S497>/Switch' incorporates:
    //   Constant: '<S497>/Clamping_zero'
    //   Constant: '<S497>/Constant1'
    //   Logic: '<S497>/AND3'
    //   RelationalOperator: '<S497>/Equal1'
    //   RelationalOperator: '<S497>/Relational Operator'
    //   Switch: '<S497>/Switch1'
    //   Switch: '<S497>/Switch2'

    if ((Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_f !=
         Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o) &&
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction ==
         Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_l;
    }

    // DiscreteIntegrator: '<S506>/Integrator' incorporates:
    //   Switch: '<S497>/Switch'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Integrator_gainval_p *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;

    // Sum: '<S515>/Sum'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       + Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;

    // Saturate: '<S513>/Saturation'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_UpperSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_UpperSaturationLimit;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_LowerSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_LowerSaturationLimit;
    }

    // Sum: '<S66>/Sum3' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S513>/Saturation'
    //   UnaryMinus: '<S66>/Unary Minus'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
      (-static_cast<real_T>
       (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c.vz));

    // Gain: '<S561>/Proportional Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      = Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_P *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Gain: '<S559>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S551>/Filter'
    //   Gain: '<S550>/Derivative Gain'
    //   Sum: '<S551>/SumD'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_D *
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       - Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_o) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_N;

    // Sum: '<S566>/Sum Fdbk'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
      =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       + Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_o) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

    // DeadZone: '<S549>/DeadZone'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_UpperSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        -=
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_UpperSaturationLimit;
    } else if
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
         >=
         Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_LowerSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        = 0.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        -=
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S549>/DeadZone'

    // Gain: '<S553>/Integral Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      *= Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_I;

    // Switch: '<S547>/Switch1' incorporates:
    //   Constant: '<S547>/Clamping_zero'
    //   Constant: '<S547>/Constant'
    //   Constant: '<S547>/Constant2'
    //   RelationalOperator: '<S547>/fix for DT propagation issue'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_a)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_d3;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_pb;
    }

    // Switch: '<S547>/Switch2' incorporates:
    //   Constant: '<S547>/Clamping_zero'
    //   Constant: '<S547>/Constant3'
    //   Constant: '<S547>/Constant4'
    //   RelationalOperator: '<S547>/fix for DT propagation issue1'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_a)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_m;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_c;
    }

    // Switch: '<S547>/Switch' incorporates:
    //   Constant: '<S547>/Clamping_zero'
    //   Constant: '<S547>/Constant1'
    //   Logic: '<S547>/AND3'
    //   RelationalOperator: '<S547>/Equal1'
    //   RelationalOperator: '<S547>/Relational Operator'
    //   Switch: '<S547>/Switch1'
    //   Switch: '<S547>/Switch2'

    if ((Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_a !=
         Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0)
        && (Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction ==
            Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_f;
    }

    // DiscreteIntegrator: '<S556>/Integrator' incorporates:
    //   Switch: '<S547>/Switch'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_o +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Integrator_gainval_k *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Sum: '<S565>/Sum'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       + Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_o) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

    // Saturate: '<S563>/Saturation'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_UpperSaturationLimit)
    {
      // Sum: '<S565>/Sum' incorporates:
      //   Saturate: '<S563>/Saturation'

      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_UpperSaturationLimit;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_LowerSaturationLimit)
    {
      // Sum: '<S565>/Sum' incorporates:
      //   Saturate: '<S563>/Saturation'

      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_LowerSaturationLimit;
    }

    // End of Saturate: '<S563>/Saturation'

    // Update for DiscreteIntegrator: '<S501>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Filter_gainval_i *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;

    // Update for DiscreteIntegrator: '<S551>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_o +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Filter_gainval_m *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
  }

  // End of Outputs for SubSystem: '<S4>/Position & Altitude controller'

  // Chart: '<S4>/Chart'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.is_active_c3_Hexacopter_ControllerWithNavigation_ver2023b
      == 0U) {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.is_active_c3_Hexacopter_ControllerWithNavigation_ver2023b
      = 1U;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.is_c3_Hexacopter_ControllerWithNavigation_ver2023b
      = Hexacopter_ControllerWithNavigation_ver2023b_IN_STABLIZED;
  } else if
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.is_c3_Hexacopter_ControllerWithNavigation_ver2023b
       == Hexacopter_ControllerWithNavigation_ver2023b_IN_MISSION) {
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[5] <= 1400)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_DW.is_c3_Hexacopter_ControllerWithNavigation_ver2023b
        = Hexacopter_ControllerWithNavigation_ver2023b_IN_STABLIZED;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a;
      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain1;
      Hexacopter_ControllerWithNavigation_ver2023b_B.b =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[1];
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o;
    }

    // case IN_STABLIZED:
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[5] >
             1400) {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.is_c3_Hexacopter_ControllerWithNavigation_ver2023b
      = Hexacopter_ControllerWithNavigation_ver2023b_IN_MISSION;
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a;
    Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain1;
    Hexacopter_ControllerWithNavigation_ver2023b_B.b =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o;
  }

  // End of Chart: '<S4>/Chart'

  // MATLABSystem: '<S14>/SourceBlock'
  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = uORB_read_step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.orbMetadataObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.eventStructObj,
     &Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  // Start for MATLABSystem: '<S14>/SourceBlock'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    // SignalConversion generated from: '<S19>/In1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_l =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b_varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S4>/Attitude controller' incorporates:
  //   EnablePort: '<S63>/Enable'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_b.armed) {
    // Sum: '<S63>/Sum4' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
      = Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 -
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_l.yawspeed;

    // Gain: '<S104>/Integral Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_I *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2;

    // Gain: '<S110>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S102>/Filter'
    //   Gain: '<S101>/Derivative Gain'
    //   Sum: '<S102>/SumD'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_D *
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       - Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_ov) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_N;

    // Sum: '<S116>/Sum' incorporates:
    //   DiscreteIntegrator: '<S107>/Integrator'
    //   Gain: '<S112>/Proportional Gain'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_P *
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
       + Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_i) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4;

    // DeadZone: '<S100>/DeadZone'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        = Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >=
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        = 0.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        = Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit;
    }

    // End of DeadZone: '<S100>/DeadZone'

    // Switch: '<S98>/Switch1' incorporates:
    //   Constant: '<S98>/Clamping_zero'
    //   Constant: '<S98>/Constant'
    //   Constant: '<S98>/Constant2'
    //   RelationalOperator: '<S98>/fix for DT propagation issue'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_k;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_j;
    }

    // Switch: '<S98>/Switch2' incorporates:
    //   Constant: '<S98>/Clamping_zero'
    //   Constant: '<S98>/Constant3'
    //   Constant: '<S98>/Constant4'
    //   RelationalOperator: '<S98>/fix for DT propagation issue1'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_l;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_o;
    }

    // Switch: '<S98>/Switch' incorporates:
    //   Constant: '<S98>/Clamping_zero'
    //   Constant: '<S98>/Constant1'
    //   Logic: '<S98>/AND3'
    //   RelationalOperator: '<S98>/Equal1'
    //   RelationalOperator: '<S98>/Relational Operator'
    //   Switch: '<S98>/Switch1'
    //   Switch: '<S98>/Switch2'

    if ((Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value !=
         Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_0)
        && (Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction ==
            Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_m;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
    }

    // End of Switch: '<S98>/Switch'

    // Saturate: '<S114>/Saturation'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit)
    {
      // Saturate: '<S114>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_n =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_UpperSaturationLimit;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit)
    {
      // Saturate: '<S114>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_n =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_LowerSaturationLimit;
    } else {
      // Saturate: '<S114>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_n =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
    }

    // End of Saturate: '<S114>/Saturation'

    // RateLimiter: '<S63>/Rate Limiter2'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda -
      Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter2_RisingLim *
        Hexacopter_ControllerWithNavigation_ver2023b_period) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter2_RisingLim *
        Hexacopter_ControllerWithNavigation_ver2023b_period +
        Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter2_FallingLim
               * Hexacopter_ControllerWithNavigation_ver2023b_period) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter2_FallingLim
        * Hexacopter_ControllerWithNavigation_ver2023b_period +
        Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_B.lambda;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY =
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // End of RateLimiter: '<S63>/Rate Limiter2'

    // If: '<S576>/If' incorporates:
    //   Constant: '<S577>/Constant'
    //   Constant: '<S578>/Constant'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        > 1.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_ji;
    } else if
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
         < -1.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_hi;
    }

    // Saturate: '<S63>/Saturation1'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat;
    } else if
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
         < Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat;
    }

    // If: '<S576>/If' incorporates:
    //   Trigonometry: '<S574>/trigFcn'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        > 1.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        = 1.0;
    } else if
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
         < -1.0) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        = -1.0;
    }

    // Sum: '<S63>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S260>/Proportional Gain'
    //   Saturate: '<S63>/Saturation1'
    //   Sum: '<S63>/Sum2'
    //   Trigonometry: '<S574>/trigFcn'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       - asin
       (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3))
      * Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController3_P -
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_l.pitchspeed;

    // Gain: '<S154>/Integral Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_I *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Gain: '<S160>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S152>/Filter'
    //   Gain: '<S151>/Derivative Gain'
    //   Sum: '<S152>/SumD'

    Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_D *
       Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
       - Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_c) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_N;

    // Sum: '<S166>/Sum' incorporates:
    //   DiscreteIntegrator: '<S157>/Integrator'
    //   Gain: '<S162>/Proportional Gain'

    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = (Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_P *
         Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
         + Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_h)
      + Hexacopter_ControllerWithNavigation_ver2023b_B.lambda;

    // DeadZone: '<S150>/DeadZone'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
        =
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        - Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit;
    } else if
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
         >=
         Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
        = 0.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
        =
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        - Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S150>/DeadZone'

    // Switch: '<S148>/Switch1' incorporates:
    //   Constant: '<S148>/Clamping_zero'
    //   Constant: '<S148>/Constant'
    //   Constant: '<S148>/Constant2'
    //   RelationalOperator: '<S148>/fix for DT propagation issue'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_e)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_bd;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_fs;
    }

    // Switch: '<S148>/Switch2' incorporates:
    //   Constant: '<S148>/Clamping_zero'
    //   Constant: '<S148>/Constant3'
    //   Constant: '<S148>/Constant4'
    //   RelationalOperator: '<S148>/fix for DT propagation issue1'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_e) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_n;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_n;
    }

    // Switch: '<S148>/Switch' incorporates:
    //   Constant: '<S148>/Clamping_zero'
    //   Constant: '<S148>/Constant1'
    //   Logic: '<S148>/AND3'
    //   RelationalOperator: '<S148>/Equal1'
    //   RelationalOperator: '<S148>/Relational Operator'
    //   Switch: '<S148>/Switch1'
    //   Switch: '<S148>/Switch2'

    if ((Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_e !=
         Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_2)
        && (Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction ==
            Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_c;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3
        = Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;
    }

    // End of Switch: '<S148>/Switch'

    // Saturate: '<S164>/Saturation'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit)
    {
      // Saturate: '<S164>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_b =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_UpperSaturationLimit;
    } else if
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
         <
         Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit)
    {
      // Saturate: '<S164>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_b =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S164>/Saturation'
      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_b =
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;
    }

    // End of Saturate: '<S164>/Saturation'

    // RateLimiter: '<S63>/Rate Limiter1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_B.b -
      Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY_l;
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter1_RisingLim *
        Hexacopter_ControllerWithNavigation_ver2023b_period) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter1_RisingLim *
        Hexacopter_ControllerWithNavigation_ver2023b_period +
        Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY_l;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter1_FallingLim
               * Hexacopter_ControllerWithNavigation_ver2023b_period) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter1_FallingLim *
        Hexacopter_ControllerWithNavigation_ver2023b_period +
        Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY_l;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_B.b;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY_l =
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

    // End of RateLimiter: '<S63>/Rate Limiter1'

    // Saturate: '<S63>/Saturation'
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_UpperSat) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_UpperSat;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
               Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_LowerSat)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_LowerSat;
    }

    // Sum: '<S63>/Sum1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S308>/Proportional Gain'
    //   Saturate: '<S63>/Saturation'
    //   Sum: '<S63>/Sum3'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
       Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2]) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController4_P -
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_l.rollspeed;

    // Gain: '<S204>/Integral Gain'
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
      = Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_I *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o;

    // Gain: '<S210>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S202>/Filter'
    //   Gain: '<S201>/Derivative Gain'
    //   Sum: '<S202>/SumD'

    Hexacopter_ControllerWithNavigation_ver2023b_B.b =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_D *
       Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o -
       Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_f) *
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_N;

    // Sum: '<S216>/Sum' incorporates:
    //   DiscreteIntegrator: '<S207>/Integrator'
    //   Gain: '<S212>/Proportional Gain'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 =
      (Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_P *
       Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
       Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_ih) +
      Hexacopter_ControllerWithNavigation_ver2023b_B.b;

    // DeadZone: '<S200>/DeadZone' incorporates:
    //   Saturate: '<S214>/Saturation'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 >
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_UpperSaturationLimit)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 -
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_UpperSaturationLimit;

      // Sum: '<S216>/Sum' incorporates:
      //   Saturate: '<S214>/Saturation'

      Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 =
        Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_UpperSaturationLimit;
    } else {
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 >=
          Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_LowerSaturationLimit)
      {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = 0.0;
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
          Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 -
          Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_LowerSaturationLimit;
      }

      if (Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 <
          Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_LowerSaturationLimit)
      {
        // Sum: '<S216>/Sum' incorporates:
        //   Saturate: '<S214>/Saturation'

        Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 =
          Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of DeadZone: '<S200>/DeadZone'

    // Update for DiscreteIntegrator: '<S107>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_i +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Integrator_gainval *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;

    // Update for DiscreteIntegrator: '<S102>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_ov +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Filter_gainval *
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4;

    // Update for DiscreteIntegrator: '<S157>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_h +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Integrator_gainval_i *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_3;

    // Update for DiscreteIntegrator: '<S152>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_c +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Filter_gainval_e *
      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda;

    // Switch: '<S198>/Switch1' incorporates:
    //   Constant: '<S198>/Clamping_zero'
    //   Constant: '<S198>/Constant'
    //   Constant: '<S198>/Constant2'
    //   RelationalOperator: '<S198>/fix for DT propagation issue'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_j) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_a;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_p;
    }

    // Switch: '<S198>/Switch2' incorporates:
    //   Constant: '<S198>/Clamping_zero'
    //   Constant: '<S198>/Constant3'
    //   Constant: '<S198>/Constant4'
    //   RelationalOperator: '<S198>/fix for DT propagation issue1'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        > Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_j)
    {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_b;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_l;
    }

    // Switch: '<S198>/Switch' incorporates:
    //   Constant: '<S198>/Clamping_zero'
    //   Constant: '<S198>/Constant1'
    //   Logic: '<S198>/AND3'
    //   RelationalOperator: '<S198>/Equal1'
    //   RelationalOperator: '<S198>/Relational Operator'
    //   Switch: '<S198>/Switch1'
    //   Switch: '<S198>/Switch2'

    if ((Hexacopter_ControllerWithNavigation_ver2023b_P.Clamping_zero_Value_j !=
         Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o) &&
        (Hexacopter_ControllerWithNavigation_ver2023b_B.rtPrevAction ==
         Hexacopter_ControllerWithNavigation_ver2023b_B.i2_d)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_k;
    }

    // Update for DiscreteIntegrator: '<S207>/Integrator' incorporates:
    //   Switch: '<S198>/Switch'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_ih +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Integrator_gainval_f *
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_TmpSignalConversionAtProduct1Inport2_idx_1;

    // Update for DiscreteIntegrator: '<S202>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_f +=
      Hexacopter_ControllerWithNavigation_ver2023b_P.Filter_gainval_l *
      Hexacopter_ControllerWithNavigation_ver2023b_B.b;
  }

  // End of Outputs for SubSystem: '<S4>/Attitude controller'
  for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
       Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 6;
       Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
    // Saturate: '<S5>/Saturation' incorporates:
    //   Bias: '<S5>/Bias'
    //   Constant: '<S5>/Mixer matrix'
    //   Gain: '<S5>/Gain1'
    //   Product: '<S5>/Product1'
    //   SignalConversion generated from: '<S5>/Product1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.b = floor
      (((((Hexacopter_ControllerWithNavigation_ver2023b_P.Mixermatrix_Value[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d
           + 6] * Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 +
           Hexacopter_ControllerWithNavigation_ver2023b_P.Mixermatrix_Value[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
           * Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) +
          Hexacopter_ControllerWithNavigation_ver2023b_P.Mixermatrix_Value[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d
          + 12] * Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_b) +
         Hexacopter_ControllerWithNavigation_ver2023b_P.Mixermatrix_Value[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d
         + 18] * Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_n) +
        Hexacopter_ControllerWithNavigation_ver2023b_P.Bias_Bias) *
       Hexacopter_ControllerWithNavigation_ver2023b_P.Gain1_Gain_p);
    if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.b) || rtIsInf
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b)) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.b = 0.0;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.b = fmod
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b, 65536.0);
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.status = static_cast<uint16_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_B.b < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Hexacopter_ControllerWithNavigation_ver2023b_B.b)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b)));
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.status >
        Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_UpperSat_g) {
      // DataTypeConversion: '<S6>/Cast To Double'
      Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_UpperSat_g;
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.status <
               Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_LowerSat_j)
    {
      // DataTypeConversion: '<S6>/Cast To Double'
      Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
        = Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation_LowerSat_j;
    } else {
      // DataTypeConversion: '<S6>/Cast To Double'
      Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
        = Hexacopter_ControllerWithNavigation_ver2023b_B.status;
    }

    // End of Saturate: '<S5>/Saturation'
  }

  // MATLABSystem: '<S6>/Read Parameter13'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter13_SampleTime)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter13_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_l);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_l = 0;
  }

  // RelationalOperator: '<S13>/Compare' incorporates:
  //   Constant: '<S13>/Constant'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f =
    (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j.values[7] >=
     Hexacopter_ControllerWithNavigation_ver2023b_P.CompareToConstant_const);

  // MATLABSystem: '<S6>/Read Parameter1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter1_SampleTime)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter1_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_j);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_j = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter2'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter2_SampleTime)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter2_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter3'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter3_SampleTime)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter3_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.i1);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.i1 = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter4'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter4_SampleTime)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter4_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.i2);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.i2 = 0;
  }

  // MATLABSystem: '<S6>/Read Parameter5'
  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.SampleTime !=
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter5_SampleTime)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter5_SampleTime;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
    (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.MW_PARAMHANDLE,
     MW_INT32, &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g);
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g = 0;
  }

  // Switch: '<S6>/Switch' incorporates:
  //   Constant: '<S6>/Constant'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch' incorporates:
    //   Constant: '<S6>/Fault'
    //   DataTypeConversion: '<S6>/Data Type Conversion3'
    //   MATLABSystem: '<S6>/Read Parameter13'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.ManualSwitch_CurrentSetting
        == 1) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.b =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Fault_Value;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.b =
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_l;
    }

    // End of ManualSwitch: '<S6>/Manual Switch'
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.b =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_h;
  }

  // Gain: '<S7>/Gain' incorporates:
  //   Switch: '<S6>/Switch'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_i *
    Hexacopter_ControllerWithNavigation_ver2023b_B.b;

  // Saturate: '<S7>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_j) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_j;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_b)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_b;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S7>/Constant'
  //   Constant: '<S7>/IDLE PWM'
  //   Product: '<S7>/Product'
  //   Saturate: '<S7>/Saturation1'
  //   Sum: '<S7>/Add'
  //   Sum: '<S7>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.b = floor((static_cast<real_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[0]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.IDLEPWM_Value) *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_ik);
  if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.b) || rtIsInf
      (Hexacopter_ControllerWithNavigation_ver2023b_B.b)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.b = 0.0;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.b = fmod
      (Hexacopter_ControllerWithNavigation_ver2023b_B.b, 65536.0);
  }

  // Switch: '<S6>/Switch1' incorporates:
  //   Constant: '<S6>/Constant1'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch1' incorporates:
    //   Constant: '<S6>/Fault1'
    //   DataTypeConversion: '<S6>/Data Type Conversion2'
    //   MATLABSystem: '<S6>/Read Parameter1'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.ManualSwitch1_CurrentSetting
        == 1) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Fault1_Value;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_j;
    }

    // End of ManualSwitch: '<S6>/Manual Switch1'
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value;
  }

  // Gain: '<S8>/Gain' incorporates:
  //   Switch: '<S6>/Switch1'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_n *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i;

  // Saturate: '<S8>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_g) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_g;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_k)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_k;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S8>/Constant'
  //   Constant: '<S8>/IDLE PWM'
  //   Product: '<S8>/Product'
  //   Saturate: '<S8>/Saturation1'
  //   Sum: '<S8>/Add'
  //   Sum: '<S8>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i = floor((static_cast<
    real_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[1]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.IDLEPWM_Value_c) *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_c);
  if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i) || rtIsInf
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i = 0.0;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i = fmod
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i, 65536.0);
  }

  // Switch: '<S6>/Switch2' incorporates:
  //   Constant: '<S6>/Constant2'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch2' incorporates:
    //   Constant: '<S6>/Fault2'
    //   DataTypeConversion: '<S6>/Data Type Conversion'
    //   MATLABSystem: '<S6>/Read Parameter2'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.ManualSwitch2_CurrentSetting
        == 1) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Fault2_Value;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d;
    }

    // End of ManualSwitch: '<S6>/Manual Switch2'
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value;
  }

  // Gain: '<S9>/Gain' incorporates:
  //   Switch: '<S6>/Switch2'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_g *
    Hexacopter_ControllerWithNavigation_ver2023b_B.lambda;

  // Saturate: '<S9>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_h) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_h;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_i)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_i;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S9>/Constant'
  //   Constant: '<S9>/IDLE PWM'
  //   Product: '<S9>/Product'
  //   Saturate: '<S9>/Saturation1'
  //   Sum: '<S9>/Add'
  //   Sum: '<S9>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.lambda = floor((static_cast<
    real_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[2]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.IDLEPWM_Value_o) *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_g1);
  if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.lambda) || rtIsInf
      (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.lambda = 0.0;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.lambda = fmod
      (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda, 65536.0);
  }

  // Switch: '<S6>/Switch3' incorporates:
  //   Constant: '<S6>/Constant3'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch3' incorporates:
    //   Constant: '<S6>/Fault3'
    //   DataTypeConversion: '<S6>/Data Type Conversion4'
    //   MATLABSystem: '<S6>/Read Parameter3'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.ManualSwitch3_CurrentSetting
        == 1) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Fault3_Value;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.i1;
    }

    // End of ManualSwitch: '<S6>/Manual Switch3'
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value;
  }

  // Gain: '<S10>/Gain' incorporates:
  //   Switch: '<S6>/Switch3'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_ni *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4;

  // Saturate: '<S10>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_h1) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_h1;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_bv)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_bv;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S10>/Constant'
  //   Constant: '<S10>/IDLE PWM'
  //   Product: '<S10>/Product'
  //   Saturate: '<S10>/Saturation1'
  //   Sum: '<S10>/Add'
  //   Sum: '<S10>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = floor
    ((static_cast<real_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[3]) -
      Hexacopter_ControllerWithNavigation_ver2023b_P.IDLEPWM_Value_h) *
     Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
     Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_gp);
  if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4) || rtIsInf
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = 0.0;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = fmod
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4, 65536.0);
  }

  // Switch: '<S6>/Switch4' incorporates:
  //   Constant: '<S6>/Constant4'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch4' incorporates:
    //   Constant: '<S6>/Fault4'
    //   DataTypeConversion: '<S6>/Data Type Conversion1'
    //   MATLABSystem: '<S6>/Read Parameter4'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.ManualSwitch4_CurrentSetting
        == 1) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Fault4_Value;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
        Hexacopter_ControllerWithNavigation_ver2023b_B.i2;
    }

    // End of ManualSwitch: '<S6>/Manual Switch4'
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value;
  }

  // Gain: '<S11>/Gain' incorporates:
  //   Switch: '<S6>/Switch4'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_i4 *
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2;

  // Saturate: '<S11>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_a) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_a;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_p)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_p;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S11>/Constant'
  //   Constant: '<S11>/IDLE PWM'
  //   Product: '<S11>/Product'
  //   Saturate: '<S11>/Saturation1'
  //   Sum: '<S11>/Add'
  //   Sum: '<S11>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = floor((
    static_cast<real_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[4]) -
    Hexacopter_ControllerWithNavigation_ver2023b_P.IDLEPWM_Value_n) *
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
    Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fa);
  if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2) ||
      rtIsInf(Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = 0.0;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = fmod
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2, 65536.0);
  }

  // Switch: '<S6>/Switch5' incorporates:
  //   Constant: '<S6>/Constant5'

  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Compare_f) {
    // ManualSwitch: '<S6>/Manual Switch5' incorporates:
    //   Constant: '<S6>/Fault5'
    //   DataTypeConversion: '<S6>/Data Type Conversion5'
    //   MATLABSystem: '<S6>/Read Parameter5'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_P.ManualSwitch5_CurrentSetting
        == 1) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Fault5_Value;
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_g;
    }

    // End of ManualSwitch: '<S6>/Manual Switch5'
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant5_Value;
  }

  // Gain: '<S12>/Gain' incorporates:
  //   Switch: '<S6>/Switch5'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o *=
    Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_ly;

  // Saturate: '<S12>/Saturation1'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o >
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_k) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_UpperSat_k;
  } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
             Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_h)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Saturation1_LowerSat_h;
  }

  // DataTypeConversion: '<S6>/Cast To Double1' incorporates:
  //   Constant: '<S12>/Constant'
  //   Constant: '<S12>/IDLE PWM'
  //   Product: '<S12>/Product'
  //   Saturate: '<S12>/Saturation1'
  //   Sum: '<S12>/Add'
  //   Sum: '<S12>/Sum'

  Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = floor
    ((static_cast<real_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_B.CastToDouble[5]) -
      Hexacopter_ControllerWithNavigation_ver2023b_P.IDLEPWM_Value_l) *
     Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o +
     Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_cc);
  if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o) || rtIsInf
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o)) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = 0.0;
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o = fmod
      (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o, 65536.0);
  }

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/Constant1'
  //   DataTypeConversion: '<S6>/Cast To Double1'

  for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
       Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 8;
       Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
      = 0U;
  }

  Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[0] =
    static_cast<uint16_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.b < 0.0
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Hexacopter_ControllerWithNavigation_ver2023b_B.b)))) :
    static_cast<int32_T>(static_cast<uint16_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.b)));
  Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[1] =
    static_cast<uint16_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i))))
    : static_cast<int32_T>(static_cast<uint16_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i)));
  Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[2] =
    static_cast<uint16_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.lambda <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Hexacopter_ControllerWithNavigation_ver2023b_B.lambda))))
    : static_cast<int32_T>(static_cast<uint16_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda)));
  Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[3] =
    static_cast<uint16_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4))))
    : static_cast<int32_T>(static_cast<uint16_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4)));
  Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[4] =
    static_cast<uint16_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 < 0.0 ?
     static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>
        (-Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2)))) :
     static_cast<int32_T>(static_cast<uint16_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2)));
  Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[5] =
    static_cast<uint16_T>(Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o))))
    : static_cast<int32_T>(static_cast<uint16_T>
    (Hexacopter_ControllerWithNavigation_ver2023b_B.Sum_o)));
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_b.armed) {
    if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isArmed) {
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isArmed = true;
      Hexacopter_ControllerWithNavigation_ver2023b_B.status = pwm_arm
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
         &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.armAdvertiseObj);
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
        static_cast<uint16_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
         Hexacopter_ControllerWithNavigation_ver2023b_B.status);
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.status = pwm_setServo
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.servoCount,
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.channelMask,
       &Hexacopter_ControllerWithNavigation_ver2023b_B.pwmValue[0],
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isMain,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.actuatorAdvertiseObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
      static_cast<uint16_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
       Hexacopter_ControllerWithNavigation_ver2023b_B.status);
  } else {
    Hexacopter_ControllerWithNavigation_ver2023b_B.status = pwm_disarm
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.armAdvertiseObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
      static_cast<uint16_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
       Hexacopter_ControllerWithNavigation_ver2023b_B.status);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isArmed = false;
    Hexacopter_ControllerWithNavigation_ver2023b_B.status = pwm_resetServo
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.servoCount,
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.channelMask,
       Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isMain,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.actuatorAdvertiseObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
      static_cast<uint16_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
       Hexacopter_ControllerWithNavigation_ver2023b_B.status);
  }

  if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isMain) {
    Hexacopter_ControllerWithNavigation_ver2023b_B.status = pwm_forceFailsafe
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
       static_cast<int32_T>
       (Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_ct));
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
      static_cast<uint16_T>
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
       Hexacopter_ControllerWithNavigation_ver2023b_B.status);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'

  // Outputs for Enabled SubSystem: '<S28>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S45>/Enable'

  // Start for MATLABSystem: '<S28>/Read Parameter'
  if (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_p > 0) {
    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S55>/Constant'
    //   SignalConversion generated from: '<S51>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S51>/Matrix Concatenate1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.lat;

    // SignalConversion generated from: '<S51>/Matrix Concatenate1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.lon;

    // DataTypeConversion: '<S51>/Data Type Conversion'
    Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.alt;

    // SignalConversion generated from: '<S45>/Matrix Concatenate1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat;

    // SignalConversion generated from: '<S45>/Matrix Concatenate1'
    Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lon;

    // DataTypeConversion: '<S45>/Data Type Conversion'
    Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.alt;
    Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem
      (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2,
       Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate,
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.valid,
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type,
       &Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem);

    // SignalConversion generated from: '<S57>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   MATLABSystem: '<S51>/MATLAB System'
    //   SignalConversion generated from: '<S51>/MATLAB System'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      position[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S57>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   MATLABSystem: '<S51>/MATLAB System'
    //   SignalConversion generated from: '<S51>/MATLAB System'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      position[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem.MATLABSystem[1];

    // If: '<S57>/If' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   Constant: '<S59>/Constant'
    //   Constant: '<S59>/Constant1'
    //   Constant: '<S60>/Constant'
    //   Constant: '<S60>/Constant1'

    if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type == 4)
    {
      // Outputs for IfAction SubSystem: '<S57>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S60>/Action Port'

      // MATLABSystem: '<S60>/Read Parameter' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   BusAssignment: '<S51>/Bus Assignment1'
      //   SignalConversion generated from: '<S60>/Read Parameter'

      if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.SampleTime !=
          Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime_c)
      {
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.SampleTime =
          Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime_c;
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
        (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.MW_PARAMHANDLE,
         MW_SINGLE,
         &Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints
         [0].velocity[2]);
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints
          [0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S60>/Read Parameter'
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_dr[0];
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_dr[1];
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .position[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S57>/If Action Subsystem2'
    } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type
               == 3) {
      // Outputs for IfAction SubSystem: '<S57>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S59>/Action Port'

      // MATLABSystem: '<S59>/Read Parameter'
      if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.SampleTime !=
          Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime_g)
      {
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.SampleTime =
          Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime_g;
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = MW_Param_Step
        (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.MW_PARAMHANDLE,
         MW_SINGLE, &Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep);
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep = 0.0F;
      }

      // Gain: '<S59>/Gain' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   BusAssignment: '<S51>/Bus Assignment1'
      //   MATLABSystem: '<S59>/Read Parameter'
      //
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Gain_Gain_h *
        Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep;
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_k4[0];
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_k4[1];
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .position[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S57>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S57>/If Action Subsystem' incorporates:
      //   ActionPort: '<S58>/Action Port'

      // SignalConversion generated from: '<S58>/In1' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   BusAssignment: '<S51>/Bus Assignment1'
      //   MATLABSystem: '<S51>/MATLAB System'
      //   SignalConversion generated from: '<S51>/MATLAB System'

      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .position[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem.MATLABSystem[
        2];

      // BusAssignment: '<S51>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S45>/Bus Assignment1'
      //   SignalConversion generated from: '<S57>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S58>/In2'
      //
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[0] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.vx;
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[1] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.vy;
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0]
        .velocity[2] =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S57>/If Action Subsystem'
    }

    // End of If: '<S57>/If'

    // BusAssignment: '<S51>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   Constant: '<S51>/Constant5'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      timestamp =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.timestamp;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      type = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      yaw = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.yaw;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      yaw_speed =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.yawspeed;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[0].
      point_valid =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant5_Value_j;

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S55>/Constant'
    //   SignalConversion generated from: '<S52>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S52>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S51>/Matrix Concatenate1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.lat;

    // SignalConversion generated from: '<S52>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S51>/Matrix Concatenate1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.lon;

    // DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S51>/Data Type Conversion'

    Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.alt;
    Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem
      (Hexacopter_ControllerWithNavigation_ver2023b_B.DataTypeConversion2,
       Hexacopter_ControllerWithNavigation_ver2023b_B.VectorConcatenate,
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.valid,
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type,
       &Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem_b);

    // SignalConversion generated from: '<S52>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S52>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      velocity[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.vx;

    // SignalConversion generated from: '<S52>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S52>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      velocity[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.vy;

    // SignalConversion generated from: '<S52>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S52>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      velocity[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.vz;

    // BusAssignment: '<S52>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S51>/Bus Assignment1'
    //   Constant: '<S52>/Constant5'
    //   MATLABSystem: '<S52>/MATLAB System'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      timestamp =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.timestamp;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      position[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem_b.MATLABSystem[
      0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      position[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem_b.MATLABSystem[
      1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      position[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.MATLABSystem_b.MATLABSystem[
      2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      yaw = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.yaw;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      yaw_speed =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.yawspeed;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      point_valid =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant5_Value_k;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[1].
      type = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.current.type;

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   Constant: '<S55>/Constant'
    //   SignalConversion generated from: '<S54>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S54>/MATLAB System' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   DataTypeConversion: '<S45>/Data Type Conversion'
    //   DataTypeConversion: '<S54>/Data Type Conversion'
    //   SignalConversion generated from: '<S45>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S54>/Matrix Concatenate'
    //
    if (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.valid) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.lat -
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat;
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.lon -
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lon;
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = fabs
        (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda);
      if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 > 180.0) {
        if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.lambda +
                    180.0) || rtIsInf
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda + 180.0)) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = (rtNaN);
        } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda + 180.0
                   == 0.0) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = 0.0;
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = fmod
            (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda + 180.0,
             360.0);
          if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 == 0.0) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = 0.0;
          } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda +
                     180.0 < 0.0) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 += 360.0;
          }
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.lambda =
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda * 0.0 +
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 - 180.0);
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = fabs
          (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda);
      }

      if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 > 90.0) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = fabs
          (Hexacopter_ControllerWithNavigation_ver2023b_B.lambda);
        Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 =
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 > 90.0);
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i += 180.0;
        Hexacopter_ControllerWithNavigation_ver2023b_B.b =
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
          static_cast<real_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2);
        if (rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.b)) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.b = (rtNaN);
        } else if (Hexacopter_ControllerWithNavigation_ver2023b_B.b < 0.0) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.b = -1.0;
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.b =
            (Hexacopter_ControllerWithNavigation_ver2023b_B.b > 0.0);
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.lambda = (90.0 -
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 *
           static_cast<real_T>
           (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) - 90.0)) *
          Hexacopter_ControllerWithNavigation_ver2023b_B.b * static_cast<real_T>
          (Hexacopter_ControllerWithNavigation_ver2023b_B.latp2) +
          Hexacopter_ControllerWithNavigation_ver2023b_B.lambda *
          static_cast<real_T>
          (!Hexacopter_ControllerWithNavigation_ver2023b_B.latp2);
      }

      if ((Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i > 180.0) ||
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i < -180.0)) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
          Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i, 360.0);
        Hexacopter_ControllerWithNavigation_ver2023b_B.b =
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 / 180.0;
        if (Hexacopter_ControllerWithNavigation_ver2023b_B.b < 0.0) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.b = ceil
            (Hexacopter_ControllerWithNavigation_ver2023b_B.b);
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.b = floor
            (Hexacopter_ControllerWithNavigation_ver2023b_B.b);
        }

        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i =
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 - 360.0 *
           Hexacopter_ControllerWithNavigation_ver2023b_B.b) +
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i * 0.0;
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 =
        Hexacopter_ControllerWithNavigation_ver2023b_sind_c
        (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat);
      Hexacopter_ControllerWithNavigation_ver2023b_B.b = 6.378137E+6 / sqrt(1.0
        - 0.0066943799901413165 *
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 *
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0);
      if (rtIsInf(Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat) ||
          rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat)) {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = (rtNaN);
      } else {
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
          Hexacopter_ControllerWithNavigation_ver2023b_rt_remd_snf
          (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.lat, 360.0);
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = fabs
          (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
        if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 >
            180.0) {
          if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 > 0.0) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 -= 360.0;
          } else {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 += 360.0;
          }

          Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 = fabs
            (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
        }

        if (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 <=
            45.0) {
          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = cos
            (0.017453292519943295 *
             Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
        } else if
            (Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_2 <=
             135.0) {
          if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 > 0.0) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = -sin
              ((Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 - 90.0) *
               0.017453292519943295);
          } else {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = sin
              ((Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 + 90.0) *
               0.017453292519943295);
          }
        } else {
          if (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 > 0.0) {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
              (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 - 180.0) *
              0.017453292519943295;
          } else {
            Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 =
              (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 + 180.0) *
              0.017453292519943295;
          }

          Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = -cos
            (Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
        }
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.lambda /=
        Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf(1.0,
        0.99330562000985867 / (1.0 - 0.0066943799901413165 *
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0 *
        Hexacopter_ControllerWithNavigation_ver2023b_B.rtb_Merge_idx_0) *
        Hexacopter_ControllerWithNavigation_ver2023b_B.b) * 57.295779513082323;
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i /=
        Hexacopter_ControllerWithNavigation_ver2023b_rt_atan2d_snf(1.0,
        Hexacopter_ControllerWithNavigation_ver2023b_B.b *
        Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4) *
        57.295779513082323;
      Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4 = -static_cast<real_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.alt) +
        Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f.alt;
      Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[0] =
        rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.lambda);
      Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[1] =
        rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i);
      Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[2] =
        rtIsNaN(Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
      Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = false;
      Hexacopter_ControllerWithNavigation_ver2023b_B.i1 = 0;
      exitg1 = false;
      while ((!exitg1) && (Hexacopter_ControllerWithNavigation_ver2023b_B.i1 < 3))
      {
        if (Hexacopter_ControllerWithNavigation_ver2023b_B.distinctWptsIdx[Hexacopter_ControllerWithNavigation_ver2023b_B.i1])
        {
          Hexacopter_ControllerWithNavigation_ver2023b_B.latp2 = true;
          exitg1 = true;
        } else {
          Hexacopter_ControllerWithNavigation_ver2023b_B.i1++;
        }
      }

      Hexacopter_ControllerWithNavigation_ver2023b_B.b = 0.0 / static_cast<
        real_T>(!Hexacopter_ControllerWithNavigation_ver2023b_B.latp2);
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2]
        .position[0] = static_cast<real32_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b +
         Hexacopter_ControllerWithNavigation_ver2023b_B.lambda);
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2]
        .position[1] = static_cast<real32_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b +
         Hexacopter_ControllerWithNavigation_ver2023b_B.Gain_i);
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2]
        .position[2] = static_cast<real32_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_B.b +
         Hexacopter_ControllerWithNavigation_ver2023b_B.Gain4);
    } else {
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2]
        .position[0] = 0.0F;
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2]
        .position[1] = 0.0F;
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2]
        .position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S54>/MATLAB System'

    // SignalConversion generated from: '<S54>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S54>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      velocity[0] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.vx;

    // SignalConversion generated from: '<S54>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S54>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      velocity[1] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.vy;

    // SignalConversion generated from: '<S54>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   BusAssignment: '<S54>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      velocity[2] = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.vz;

    // BusAssignment: '<S54>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'
    //   Constant: '<S54>/Constant5'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      timestamp =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.timestamp;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      yaw = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.yaw;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      yaw_speed =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.yawspeed;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      point_valid =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant5_Value_h;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[2].
      type = Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.next.type;

    // SignalConversion generated from: '<S53>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   BusAssignment: '<S53>/Bus Assignment1'
    //   Constant: '<S55>/Constant'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S53>/Bus Assignment1' incorporates:
    //   Constant: '<S53>/Constant'
    //   Constant: '<S53>/Constant1'
    //   Constant: '<S53>/Constant2'
    //   Constant: '<S53>/Constant3'
    //   Constant: '<S53>/Constant4'
    //   Constant: '<S53>/Constant5'
    //   Constant: '<S53>/Constant6'
    //   Constant: '<S53>/Constant7'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.timestamp =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant7_Value;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.yaw =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_al;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.yaw_speed =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_g;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.position[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fh[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.velocity[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_h[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.acceleration[
      0] = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_f[0];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.position[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fh[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.velocity[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_h[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.acceleration[
      1] = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_f[1];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.position[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fh[2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.velocity[2] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_h[2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.acceleration[
      2] = Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_f[2];
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.point_valid =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant5_Value_l;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f.type =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant6_Value;

    // BusAssignment: '<S45>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment'
    //   BusAssignment: '<S53>/Bus Assignment1'
    //   Concatenate: '<S45>/Matrix Concatenate'
    //   Constant: '<S45>/Constant'
    //   Constant: '<S55>/Constant'

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.timestamp =
      Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p.timestamp;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.type =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fm;
    for (Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d = 0;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d < 7;
         Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d++) {
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1._padding0[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d]
        =
        Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value._padding0[Hexacopter_ControllerWithNavigation_ver2023b_B.ParamStep_d];
    }

    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[3] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f;
    Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1.waypoints[4] =
      Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_f;

    // MATLABSystem: '<S56>/SinkBlock' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'

    uORB_write_step
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.orbAdvertiseObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S28>/Send waypoints to OBC'

  // MATLABSystem: '<S44>/PX4 Timestamp'
  hrt_absolute_time();
}

// Model initialize function
void Hexacopter_ControllerWithNavigation_ver2023b_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_dr[0] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_dr[1] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_f2 = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_k4[0] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_k4[1] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_l4 = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fh[0] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fh[1] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant_Value_fh[2] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_h[0] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_h[1] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_h[2] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_f[0] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_f[1] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant2_Value_f[2] = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant3_Value_al = rtNaNF;
  Hexacopter_ControllerWithNavigation_ver2023b_P.Constant4_Value_g = rtNaNF;

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
    Hexacopter_ControllerWithNavigation_ver2023b_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S24>/In1' incorporates:
    //   Outport: '<S24>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_c =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S49>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S50>/In1' incorporates:
    //   Outport: '<S50>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S49>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S47>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S62>/In1' incorporates:
    //   Outport: '<S62>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_p =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S47>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S46>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S61>/In1' incorporates:
    //   Outport: '<S61>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_f =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S46>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S27>/Take-off'
    // InitializeConditions for Delay: '<S39>/Delay'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_c =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S40>/Delay'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_d =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S41>/yaw_In' incorporates:
    //   Outport: '<S41>/yaw_Out'

    Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In_ik =
      Hexacopter_ControllerWithNavigation_ver2023b_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S27>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S27>/Land'
    // InitializeConditions for Delay: '<S30>/Delay'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[0] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_n;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_l[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_n;

    // InitializeConditions for Gain: '<S35>/Gain1' incorporates:
    //   Delay: '<S35>/Delay'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_n =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S36>/Delay'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE_b =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S38>/yaw_In' incorporates:
    //   Outport: '<S38>/yaw_Out'

    Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S37>/In' incorporates:
    //   Outport: '<S37>/Out'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S27>/Land'

    // SystemInitialize for IfAction SubSystem: '<S27>/Waypoint'
    // Start for MATLABSystem: '<S32>/UAV Waypoint Follower'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LastWaypointFlag = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.StartFlag = true;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.LookaheadFactor = 1.01;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S32>/UAV Waypoint Follower'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointIndex = 1.0;
    memset
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj.WaypointsInternal[0],
       0, 9U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S27>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S27>/IDLE'
    // InitializeConditions for Delay: '<S33>/Delay'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Delay_DSTATE =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S33>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S34>/yaw_In' incorporates:
    //   Outport: '<S34>/yaw_Out'

    Hexacopter_ControllerWithNavigation_ver2023b_B.yaw_In =
      Hexacopter_ControllerWithNavigation_ver2023b_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S33>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S27>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
    //   Outport: '<S22>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_j =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S17>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S23>/In1' incorporates:
    //   Outport: '<S23>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_m =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S17>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_b =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S501>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S506>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S551>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S556>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Gain: '<S66>/Gain1' incorporates:
    //   Outport: '<S66>/des_pitch'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Gain1 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S66>/des_roll' incorporates:
    //   Saturate: '<S367>/Saturation'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation[1] =
      Hexacopter_ControllerWithNavigation_ver2023b_P.des_roll_Y0;

    // SystemInitialize for Gain: '<S461>/Proportional Gain' incorporates:
    //   Outport: '<S66>/des_yawrate'
    //   Saturate: '<S463>/Saturation'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a =
      Hexacopter_ControllerWithNavigation_ver2023b_P.des_yawrate_Y0;

    // SystemInitialize for Sum: '<S565>/Sum' incorporates:
    //   Outport: '<S66>/tau_Thrust'
    //   Saturate: '<S563>/Saturation'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_o =
      Hexacopter_ControllerWithNavigation_ver2023b_P.tau_Thrust_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    Hexacopter_ControllerWithNavigation_ver2023b_B.In1_l =
      Hexacopter_ControllerWithNavigation_ver2023b_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S107>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_i =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S102>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_ov =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S63>/Rate Limiter2'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY =
      Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S157>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_h =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S152>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_c =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S63>/Rate Limiter1'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.PrevY_l =
      Hexacopter_ControllerWithNavigation_ver2023b_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S207>/Integrator'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Integrator_DSTATE_ih =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S202>/Filter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.Filter_DSTATE_f =
      Hexacopter_ControllerWithNavigation_ver2023b_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S114>/Saturation' incorporates:
    //   Outport: '<S63>/tau_Yaw'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_n =
      Hexacopter_ControllerWithNavigation_ver2023b_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S164>/Saturation' incorporates:
    //   Outport: '<S63>/tau_Pitch'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_b =
      Hexacopter_ControllerWithNavigation_ver2023b_P.tau_Pitch_Y0;

    // SystemInitialize for Sum: '<S216>/Sum' incorporates:
    //   Outport: '<S63>/tau_Roll'
    //   Saturate: '<S214>/Saturation'

    Hexacopter_ControllerWithNavigation_ver2023b_B.Saturation_a1 =
      Hexacopter_ControllerWithNavigation_ver2023b_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S28>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S57>/If Action Subsystem2'
    // Start for MATLABSystem: '<S60>/Read Parameter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime_c;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S57>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S57>/If Action Subsystem1'
    // Start for MATLABSystem: '<S59>/Read Parameter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime_g;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_0[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S59>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S57>/If Action Subsystem1'
    Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Init
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.MATLABSystem);
    Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Init
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S54>/MATLAB System'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mu.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mu.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S56>/SinkBlock' incorporates:
    //   BusAssignment: '<S45>/Bus Assignment1'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.orbMetadataObj =
      ORB_ID(vehicle_trajectory_waypoint_desired);
    uORB_write_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.orbAdvertiseObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_B.BusAssignment1_m, 1);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.isSetupComplete =
      true;

    // End of SystemInitialize for SubSystem: '<S28>/Send waypoints to OBC'

    // Start for MATLABSystem: '<S18>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.orbMetadataObj =
      ORB_ID(vehicle_local_position);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S28>/Read Parameter'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_1[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S28>/Read Parameter'

    // Start for MATLABSystem: '<S49>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.orbMetadataObj =
      ORB_ID(vehicle_trajectory_waypoint);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.orbMetadataObj =
      ORB_ID(position_setpoint_triplet);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S46>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.orbMetadataObj =
      ORB_ID(home_position);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S28>/LLA2LocalCoordinates'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.previousValidReceived
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.nextValidReceived =
      false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S21>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.orbMetadataObj =
      ORB_ID(input_rc);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S17>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.orbMetadataObj =
      ORB_ID(vehicle_attitude);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S15>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.orbMetadataObj =
      ORB_ID(actuator_armed);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S14>/SourceBlock'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.orbMetadataObj =
      ORB_ID(vehicle_odometry);
    uORB_read_initialize
      (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.orbMetadataObj,
       &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.eventStructObj);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.isSetupComplete =
      true;

    // Start for MATLABSystem: '<S6>/Read Parameter13'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter13_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_2[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter13'

    // Start for MATLABSystem: '<S6>/Read Parameter1'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter1_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_3[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter1'

    // Start for MATLABSystem: '<S6>/Read Parameter2'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter2_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.SampleTime ==
        -1.0) {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_4[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.isSetupComplete =
      true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter2'

    // Start for MATLABSystem: '<S6>/Read Parameter3'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter3_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_5[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter3'

    // Start for MATLABSystem: '<S6>/Read Parameter4'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter4_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_6[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter4'

    // Start for MATLABSystem: '<S6>/Read Parameter5'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.SampleTime =
      Hexacopter_ControllerWithNavigation_ver2023b_P.ReadParameter5_SampleTime;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.isInitialized = 1;
    if (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.SampleTime == -1.0)
    {
      tmp = 0.2;
    } else {
      tmp = Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.SampleTime;
    }

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.MW_PARAMHANDLE =
      MW_Init_Param(&ParameterNameStr_7[0], true, tmp * 1000.0);
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/Read Parameter5'

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/Constant1'

    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus = 0U;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isInitialized = 0;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_SystemCore_setup
      (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk,
       Hexacopter_ControllerWithNavigation_ver2023b_B.In1_b.armed,
       Hexacopter_ControllerWithNavigation_ver2023b_P.Constant1_Value_ct);

    // Start for MATLABSystem: '<S44>/PX4 Timestamp'
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_n.matlabCodegenIsDeleted
      = false;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_n.isInitialized = 1;
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_n.isSetupComplete = true;
  }
}

// Model terminate function
void Hexacopter_ControllerWithNavigation_ver2023b_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.isSetupComplete) {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S28>/Read Parameter'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_k.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter'

  // Terminate for MATLABSystem: '<S49>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.isSetupComplete) {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S49>/SourceBlock'

  // Terminate for MATLABSystem: '<S47>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.isSetupComplete)
    {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S47>/SourceBlock'

  // Terminate for MATLABSystem: '<S46>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.isSetupComplete)
    {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S46>/SourceBlock'

  // Terminate for MATLABSystem: '<S28>/LLA2LocalCoordinates'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mr.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.isSetupComplete)
    {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_ah.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'

  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.isSetupComplete)
    {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'

  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.isSetupComplete)
    {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d0.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.isSetupComplete)
    {
      uORB_read_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/Read Parameter13'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_a.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter13'

  // Terminate for MATLABSystem: '<S6>/Read Parameter1'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_l.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter1'

  // Terminate for MATLABSystem: '<S6>/Read Parameter2'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_jh.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter2'

  // Terminate for MATLABSystem: '<S6>/Read Parameter3'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_p.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter3'

  // Terminate for MATLABSystem: '<S6>/Read Parameter4'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_j.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter4'

  // Terminate for MATLABSystem: '<S6>/Read Parameter5'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_d.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter5'

  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isSetupComplete)
    {
      status = pwm_disarm
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
         &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.armAdvertiseObj);
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
        static_cast<uint16_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
         status);
      status = pwm_resetServo
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
         Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.servoCount,
         Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.channelMask,
         Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.isMain,
         &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.actuatorAdvertiseObj);
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
        static_cast<uint16_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
         status);
      status = pwm_close
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.pwmDevHandler,
         &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.actuatorAdvertiseObj,
         &Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.armAdvertiseObj);
      Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus =
        static_cast<uint16_T>
        (Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_pk.errorStatus |
         status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'

  // Terminate for Enabled SubSystem: '<S28>/Send waypoints to OBC'
  Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Term
    (&Hexacopter_ControllerWithNavigation_ver2023b_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S57>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S60>/Read Parameter'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_g.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/Read Parameter'
  // End of Terminate for SubSystem: '<S57>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S57>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S59>/Read Parameter'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_b.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S59>/Read Parameter'
  // End of Terminate for SubSystem: '<S57>/If Action Subsystem1'
  Hexacopter_ControllerWithNavigation_ver2023b_MATLABSystem_Term
    (&Hexacopter_ControllerWithNavigation_ver2023b_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S54>/MATLAB System'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mu.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mu.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S54>/MATLAB System'

  // Terminate for MATLABSystem: '<S56>/SinkBlock'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.matlabCodegenIsDeleted
      = true;
    if ((Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.isInitialized ==
         1) &&
        Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.isSetupComplete)
    {
      uORB_write_terminate
        (&Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S56>/SinkBlock'
  // End of Terminate for SubSystem: '<S28>/Send waypoints to OBC'

  // Terminate for MATLABSystem: '<S44>/PX4 Timestamp'
  if (!Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_n.matlabCodegenIsDeleted)
  {
    Hexacopter_ControllerWithNavigation_ver2023b_DW.obj_n.matlabCodegenIsDeleted
      = true;
  }

  // End of Terminate for MATLABSystem: '<S44>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
