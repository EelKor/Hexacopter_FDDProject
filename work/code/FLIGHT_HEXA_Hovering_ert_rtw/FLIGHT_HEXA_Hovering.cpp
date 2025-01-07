//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FLIGHT_HEXA_Hovering.cpp
//
// Code generated for Simulink model 'FLIGHT_HEXA_Hovering'.
//
// Model version                  : 5.27
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Tue Jan  7 14:03:20 2025
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
  // Start for MATLABSystem: '<S9>/SourceBlock'
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
  // MATLABSystem: '<S9>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_Term(DW_SourceBlock_FLIGHT_HEXA_Hovering_T
  *localDW)
{
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
}

// System initialize for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_n_Init
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_e_T *localDW)
{
  // Start for MATLABSystem: '<S21>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(input_rc);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_d(B_SourceBlock_FLIGHT_HEXA_Hovering_d_T
  *localB, DW_SourceBlock_FLIGHT_HEXA_Hovering_e_T *localDW)
{
  // MATLABSystem: '<S21>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 5000.0);
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_SourceBlock_a_Term
  (DW_SourceBlock_FLIGHT_HEXA_Hovering_e_T *localDW)
{
  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'
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

  // Start for MATLABSystem: '<S62>/MATLAB System'
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

  // End of Start for MATLABSystem: '<S62>/MATLAB System'
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
  // Start for MATLABSystem: '<S62>/MATLAB System'
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

  // MATLABSystem: '<S62>/MATLAB System'
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

  // End of MATLABSystem: '<S62>/MATLAB System'
}

// Termination for atomic system:
void FLIGHT_HEXA_Hovering_MATLABSystem_Term
  (DW_MATLABSystem_FLIGHT_HEXA_Hovering_T *localDW)
{
  // Terminate for MATLABSystem: '<S62>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S62>/MATLAB System'
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
      FLIGHT_HEXA_Hovering_B.i1_c = 1;
    } else {
      FLIGHT_HEXA_Hovering_B.i1_c = -1;
    }

    y = atan2(static_cast<real_T>(FLIGHT_HEXA_Hovering_B.i), static_cast<real_T>
              (FLIGHT_HEXA_Hovering_B.i1_c));
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

  // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S65>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = FLIGHT_HEXA_Hovering_rt_remd_snf(x, 360.0);
    FLIGHT_HEXA_Hovering_B.absx_m = fabs(b_x);
    if (FLIGHT_HEXA_Hovering_B.absx_m > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      FLIGHT_HEXA_Hovering_B.absx_m = fabs(b_x);
    }

    if (FLIGHT_HEXA_Hovering_B.absx_m <= 45.0) {
      b_x = sin(0.017453292519943295 * b_x);
    } else if (FLIGHT_HEXA_Hovering_B.absx_m <= 135.0) {
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

  // End of Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
  return b_x;
}

static void FLIGHT_HEXA_Hovering_lla2ned(const real_T lla[3], const real_T lla0
  [3], real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
  FLIGHT_HEXA_Hovering_B.dLat = lla[0] - lla0[0];
  FLIGHT_HEXA_Hovering_B.dLon = lla[1] - lla0[1];
  FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
  if (FLIGHT_HEXA_Hovering_B.flat > 180.0) {
    // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
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
    // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_B.flat = fabs(FLIGHT_HEXA_Hovering_B.dLat);
    FLIGHT_HEXA_Hovering_B.latp2 = (FLIGHT_HEXA_Hovering_B.flat > 90.0);

    // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_B.dLon += 180.0;
    FLIGHT_HEXA_Hovering_B.Rn = FLIGHT_HEXA_Hovering_B.dLat * static_cast<real_T>
      (FLIGHT_HEXA_Hovering_B.latp2);
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Rn)) {
      FLIGHT_HEXA_Hovering_B.Rn = (rtNaN);
    } else if (FLIGHT_HEXA_Hovering_B.Rn < 0.0) {
      FLIGHT_HEXA_Hovering_B.Rn = -1.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Rn = (FLIGHT_HEXA_Hovering_B.Rn > 0.0);
    }

    FLIGHT_HEXA_Hovering_B.dLat = (90.0 - (FLIGHT_HEXA_Hovering_B.flat *
      static_cast<real_T>(FLIGHT_HEXA_Hovering_B.latp2) - 90.0)) *
      FLIGHT_HEXA_Hovering_B.Rn * static_cast<real_T>
      (FLIGHT_HEXA_Hovering_B.latp2) + FLIGHT_HEXA_Hovering_B.dLat *
      static_cast<real_T>(!FLIGHT_HEXA_Hovering_B.latp2);
  }

  // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
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

  // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
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

  // Start for MATLABSystem: '<S43>/UAV Waypoint Follower'
  FLIGHT_HEXA_Hovering_B.absxk = fabs(x[0]);
  if (FLIGHT_HEXA_Hovering_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    FLIGHT_HEXA_Hovering_B.scale = FLIGHT_HEXA_Hovering_B.absxk;
  } else {
    FLIGHT_HEXA_Hovering_B.t = FLIGHT_HEXA_Hovering_B.absxk /
      3.3121686421112381E-170;
    y = FLIGHT_HEXA_Hovering_B.t * FLIGHT_HEXA_Hovering_B.t;
  }

  // Start for MATLABSystem: '<S43>/UAV Waypoint Follower'
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

  // Start for MATLABSystem: '<S43>/UAV Waypoint Follower'
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
  FLIGHT_HEXA_Hovering_SourceBlock_d(&FLIGHT_HEXA_Hovering_B.SourceBlock_d,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_d);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S22>/Enable'

  if (FLIGHT_HEXA_Hovering_B.SourceBlock_d.SourceBlock_o1) {
    // SignalConversion generated from: '<S22>/In1' incorporates:
    //   MATLABSystem: '<S21>/SourceBlock'

    FLIGHT_HEXA_Hovering_B.In1_a =
      FLIGHT_HEXA_Hovering_B.SourceBlock_d.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'

  // RelationalOperator: '<S12>/Compare' incorporates:
  //   Constant: '<S12>/Constant'
  //   DataTypeConversion: '<S6>/Data Type Conversion'

  FLIGHT_HEXA_Hovering_B.Compare_b = (FLIGHT_HEXA_Hovering_B.In1_a.values[6] >=
    FLIGHT_HEXA_Hovering_P.CompareToConstant_const);

  // MATLABSystem: '<S28>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_gvl.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_gvl.eventStructObj, &FLIGHT_HEXA_Hovering_B.r3,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S28>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S34>/Enable'

  // Start for MATLABSystem: '<S28>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S34>/In1'
    FLIGHT_HEXA_Hovering_B.In1_m = FLIGHT_HEXA_Hovering_B.r3;
  }

  // End of Outputs for SubSystem: '<S28>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   Math: '<S342>/Transpose'

  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 = FLIGHT_HEXA_Hovering_B.In1_m.q[0];
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = FLIGHT_HEXA_Hovering_B.In1_m.q[1];
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = FLIGHT_HEXA_Hovering_B.In1_m.q[2];
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 = FLIGHT_HEXA_Hovering_B.In1_m.q[3];

  // Switch: '<S78>/Switch' incorporates:
  //   Constant: '<S78>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   Math: '<S342>/Transpose'
  //   Product: '<S604>/Product'
  //   Product: '<S604>/Product1'
  //   Product: '<S604>/Product2'
  //   Product: '<S604>/Product3'
  //   Sum: '<S604>/Sum'

  if (!(((static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_m.q[0]) *
          FLIGHT_HEXA_Hovering_B.In1_m.q[0] + static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.In1_m.q[1]) * FLIGHT_HEXA_Hovering_B.In1_m.q[1])
         + static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_m.q[2]) *
         FLIGHT_HEXA_Hovering_B.In1_m.q[2]) + static_cast<real_T>
        (FLIGHT_HEXA_Hovering_B.In1_m.q[3]) * FLIGHT_HEXA_Hovering_B.In1_m.q[3] >
        FLIGHT_HEXA_Hovering_P.Switch_Threshold_d)) {
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[0];
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[1];
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[2];
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
      FLIGHT_HEXA_Hovering_P.Constant_Value_m[3];
  }

  // End of Switch: '<S78>/Switch'

  // Sqrt: '<S611>/sqrt' incorporates:
  //   Product: '<S612>/Product'
  //   Product: '<S612>/Product1'
  //   Product: '<S612>/Product2'
  //   Product: '<S612>/Product3'
  //   Sum: '<S612>/Sum'

  FLIGHT_HEXA_Hovering_B.Switch2 = sqrt
    (((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) +
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 *
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2) +
     FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 *
     FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3);

  // Product: '<S606>/Product'
  FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 /
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Product: '<S606>/Product1'
  FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 /
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Product: '<S606>/Product2'
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 / FLIGHT_HEXA_Hovering_B.Switch2;

  // Product: '<S606>/Product3'
  FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 /
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Fcn: '<S79>/fcn2' incorporates:
  //   Fcn: '<S79>/fcn5'

  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = FLIGHT_HEXA_Hovering_B.Switch3 *
    FLIGHT_HEXA_Hovering_B.Switch3;
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 = FLIGHT_HEXA_Hovering_B.Switch4 *
    FLIGHT_HEXA_Hovering_B.Switch4;
  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 *
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1;
  FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_B.Switch2 *
    FLIGHT_HEXA_Hovering_B.Switch2;

  // Trigonometry: '<S605>/Trigonometric Function1' incorporates:
  //   Fcn: '<S79>/fcn1'
  //   Fcn: '<S79>/fcn2'

  FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
    FLIGHT_HEXA_Hovering_rt_atan2d_snf((FLIGHT_HEXA_Hovering_B.Switch4 *
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 + FLIGHT_HEXA_Hovering_B.Switch3 *
    FLIGHT_HEXA_Hovering_B.Switch2) * 2.0,
    ((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 +
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) -
     FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0) - FLIGHT_HEXA_Hovering_B.Subtract_f);

  // Fcn: '<S79>/fcn3'
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 = (FLIGHT_HEXA_Hovering_B.Switch4 *
    FLIGHT_HEXA_Hovering_B.Switch2 - FLIGHT_HEXA_Hovering_B.Switch3 *
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) * -2.0;

  // Trigonometry: '<S605>/Trigonometric Function3' incorporates:
  //   Fcn: '<S79>/fcn4'
  //   Fcn: '<S79>/fcn5'

  FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
    FLIGHT_HEXA_Hovering_rt_atan2d_snf
    ((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 *
      FLIGHT_HEXA_Hovering_B.Switch2 + FLIGHT_HEXA_Hovering_B.Switch3 *
      FLIGHT_HEXA_Hovering_B.Switch4) * 2.0,
     ((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 -
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) -
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0) +
     FLIGHT_HEXA_Hovering_B.Subtract_f);

  // MATLABSystem: '<S25>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_po.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_po.eventStructObj, &FLIGHT_HEXA_Hovering_B.r5,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S30>/Enable'

  // Start for MATLABSystem: '<S25>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S30>/In1'
    FLIGHT_HEXA_Hovering_B.In1_l = FLIGHT_HEXA_Hovering_B.r5;
  }

  // End of Outputs for SubSystem: '<S25>/Enabled Subsystem'
  FLIGHT_HEXA_Hovering_SourceBlock(&FLIGHT_HEXA_Hovering_B.SourceBlock_l,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_l);

  // Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S31>/Enable'

  if (FLIGHT_HEXA_Hovering_B.SourceBlock_l.SourceBlock_o1) {
    // SignalConversion generated from: '<S31>/In1' incorporates:
    //   MATLABSystem: '<S26>/SourceBlock'

    FLIGHT_HEXA_Hovering_B.In1_b =
      FLIGHT_HEXA_Hovering_B.SourceBlock_l.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S26>/Enabled Subsystem'
  FLIGHT_HEXA_Hovering_SourceBlock_d(&FLIGHT_HEXA_Hovering_B.SourceBlock_b,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock_b);

  // Outputs for Enabled SubSystem: '<S32>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  if (FLIGHT_HEXA_Hovering_B.SourceBlock_b.SourceBlock_o1) {
    // SignalConversion generated from: '<S33>/In1' incorporates:
    //   MATLABSystem: '<S32>/SourceBlock'

    FLIGHT_HEXA_Hovering_B.In1_j =
      FLIGHT_HEXA_Hovering_B.SourceBlock_b.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S32>/Enabled Subsystem'

  // Gain: '<S76>/Gain2' incorporates:
  //   Constant: '<S76>/Constant2'
  //   Sum: '<S76>/Sum2'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[1]) -
    FLIGHT_HEXA_Hovering_P.Constant2_Value_b) *
    FLIGHT_HEXA_Hovering_P.Gain2_Gain_j;

  // Saturate: '<S76>/Saturation2'
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
  //   Saturate: '<S76>/Saturation2'

  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_hq *
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

  // Gain: '<S76>/Gain1' incorporates:
  //   Constant: '<S76>/Constant1'
  //   Sum: '<S76>/Sum1'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[0]) -
    FLIGHT_HEXA_Hovering_P.Constant1_Value_d) *
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_mu;

  // Saturate: '<S76>/Saturation1'
  if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_p) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat_p;
  } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
             FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_e) {
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat_e;
  }

  // Gain: '<S4>/Gain2' incorporates:
  //   Saturate: '<S76>/Saturation1'

  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
    FLIGHT_HEXA_Hovering_P.Gain2_Gain_b * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

  // Gain: '<S76>/Gain' incorporates:
  //   Constant: '<S76>/Constant'
  //   Sum: '<S76>/Sum'

  FLIGHT_HEXA_Hovering_B.Switch2 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[2]) -
    FLIGHT_HEXA_Hovering_P.Constant_Value_bk) *
    FLIGHT_HEXA_Hovering_P.Gain_Gain_k;

  // Saturate: '<S76>/Saturation'
  if (FLIGHT_HEXA_Hovering_B.Switch2 >
      FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_c) {
    FLIGHT_HEXA_Hovering_B.Switch2 =
      FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_c;
  } else if (FLIGHT_HEXA_Hovering_B.Switch2 <
             FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_g) {
    FLIGHT_HEXA_Hovering_B.Switch2 =
      FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_g;
  }

  // End of Saturate: '<S76>/Saturation'

  // Gain: '<S76>/Gain3' incorporates:
  //   Constant: '<S76>/Constant3'
  //   Sum: '<S76>/Sum3'

  FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (static_cast<real_T>
    (FLIGHT_HEXA_Hovering_B.In1_j.values[3]) -
    FLIGHT_HEXA_Hovering_P.Constant3_Value_a) *
    FLIGHT_HEXA_Hovering_P.Gain3_Gain;

  // Saturate: '<S76>/Saturation3'
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
  //   Saturate: '<S76>/Saturation3'

  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 = FLIGHT_HEXA_Hovering_P.Gain4_Gain
    * FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

  // MATLABSystem: '<S29>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_m.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_m.eventStructObj, &FLIGHT_HEXA_Hovering_B.r2,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S29>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S35>/Enable'

  // Start for MATLABSystem: '<S29>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S35>/In1'
    FLIGHT_HEXA_Hovering_B.In1_c = FLIGHT_HEXA_Hovering_B.r2;
  }

  // End of Outputs for SubSystem: '<S29>/Enabled Subsystem'

  // MATLABSystem: '<S39>/Read Parameter'
  if (FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_k.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_c);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_c = 0;
  }

  // MATLABSystem: '<S60>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj, &FLIGHT_HEXA_Hovering_B.r,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S60>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S61>/Enable'

  // Start for MATLABSystem: '<S60>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S61>/In1'
    FLIGHT_HEXA_Hovering_B.In1 = FLIGHT_HEXA_Hovering_B.r;
  }

  // End of Outputs for SubSystem: '<S60>/Enabled Subsystem'

  // MATLABSystem: '<S58>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj, &FLIGHT_HEXA_Hovering_B.r1,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S58>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S73>/Enable'

  // Start for MATLABSystem: '<S58>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S73>/In1'
    FLIGHT_HEXA_Hovering_B.In1_p = FLIGHT_HEXA_Hovering_B.r1;
  }

  // End of Outputs for SubSystem: '<S58>/Enabled Subsystem'

  // MATLABSystem: '<S57>/SourceBlock'
  FLIGHT_HEXA_Hovering_B.b_varargout_1 = uORB_read_step
    (FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
     &FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj, &FLIGHT_HEXA_Hovering_B.r4,
     false, 1.0);

  // Outputs for Enabled SubSystem: '<S57>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S72>/Enable'

  // Start for MATLABSystem: '<S57>/SourceBlock'
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    // SignalConversion generated from: '<S72>/In1'
    FLIGHT_HEXA_Hovering_B.In1_f = FLIGHT_HEXA_Hovering_B.r4;
  }

  // End of Outputs for SubSystem: '<S57>/Enabled Subsystem'

  // MATLABSystem: '<S39>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S39>/Read Parameter'
  //   SignalConversion generated from: '<S72>/In1'
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
    if (FLIGHT_HEXA_Hovering_B.ParamStep_c != 0) {
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

  // If: '<S38>/If' incorporates:
  //   Delay: '<S44>/Delay'
  //   Delay: '<S47>/Delay'
  //   Delay: '<S51>/Delay'
  //   MATLABSystem: '<S39>/LLA2LocalCoordinates'
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
      // InitializeConditions for IfAction SubSystem: '<S38>/Take-off' incorporates:
      //   ActionPort: '<S42>/Action Port'

      // InitializeConditions for If: '<S38>/If' incorporates:
      //   Delay: '<S50>/Delay'
      //   Delay: '<S51>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S38>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S38>/Take-off' incorporates:
    //   ActionPort: '<S42>/Action Port'

    // Sum: '<S50>/Sum' incorporates:
    //   Constant: '<S50>/Rate'
    //   Delay: '<S50>/Delay'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c += FLIGHT_HEXA_Hovering_P.Rate_Value;

    // Gain: '<S50>/Gain1'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Gain1_Gain *
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S51>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S52>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S52>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In_ik = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S51>/Enabled Subsystem2'

    // Reshape: '<S42>/Reshape' incorporates:
    //   Delay: '<S51>/Delay'
    //   Merge: '<S38>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
    FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.DataTypeConversion2
      [1];

    // Gain: '<S50>/Gain' incorporates:
    //   Delay: '<S50>/Delay'
    //   RelationalOperator: '<S50>/Relational Operator'
    //   Switch: '<S50>/Switch'

    if (!(FLIGHT_HEXA_Hovering_B.Switch3 <=
          FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c)) {
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c;
    }

    // Reshape: '<S42>/Reshape' incorporates:
    //   Gain: '<S50>/Gain'
    //   Merge: '<S38>/Merge'
    //   Switch: '<S50>/Switch'

    FLIGHT_HEXA_Hovering_B.Switch3 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_e3;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In_ik;

    // Update for Delay: '<S51>/Delay' incorporates:
    //   Constant: '<S51>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fo;

    // End of Outputs for SubSystem: '<S38>/Take-off'
    break;

   case 1:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S38>/Land' incorporates:
      //   ActionPort: '<S41>/Action Port'

      // InitializeConditions for If: '<S38>/If' incorporates:
      //   Delay: '<S41>/Delay'
      //   Delay: '<S46>/Delay'
      //   Delay: '<S47>/Delay'
      //   Gain: '<S46>/Gain1'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_m;
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S38>/Land'
    }

    // Outputs for IfAction SubSystem: '<S38>/Land' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Switch: '<S41>/Switch' incorporates:
    //   Delay: '<S41>/Delay'
    //   Logic: '<S41>/OR'
    //   RelationalOperator: '<S41>/IsNaN'

    if ((!rtIsNaN(FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0])) && (!rtIsNaN
         (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1]))) {
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
    }

    // End of Switch: '<S41>/Switch'

    // Switch: '<S46>/Switch' incorporates:
    //   Delay: '<S46>/Delay'

    if (!(FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n >
          FLIGHT_HEXA_Hovering_P.Switch_Threshold)) {
      // Gain: '<S46>/Gain1' incorporates:
      //   Gain: '<S46>/Gain'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
        FLIGHT_HEXA_Hovering_P.Gain_Gain_l *
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
    }

    // End of Switch: '<S46>/Switch'

    // Sum: '<S46>/Subtract' incorporates:
    //   Constant: '<S46>/Rate of descent'

    FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n -
      FLIGHT_HEXA_Hovering_P.Rateofdescent_Value;

    // Gain: '<S46>/Gain1' incorporates:
    //   Gain: '<S46>/Gain2'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_P.Gain2_Gain *
      FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];

    // Outputs for Enabled SubSystem: '<S47>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S49>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S49>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In_i = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S47>/Enabled Subsystem2'

    // Reshape: '<S41>/Reshape' incorporates:
    //   Delay: '<S41>/Delay'
    //   Delay: '<S47>/Delay'
    //   Merge: '<S38>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0];
    FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1];

    // Switch: '<S46>/Switch1' incorporates:
    //   RelationalOperator: '<S46>/GreaterThan'

    if (!(FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n >
          FLIGHT_HEXA_Hovering_B.Subtract_f)) {
      // Gain: '<S46>/Gain1'
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_B.Subtract_f;
    }

    // Reshape: '<S41>/Reshape' incorporates:
    //   Gain: '<S46>/Gain1'
    //   Merge: '<S38>/Merge'
    //   Switch: '<S46>/Switch1'

    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_a *
      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S46>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S48>/Enable'

    if (FLIGHT_HEXA_Hovering_B.Subtract_f > 0.0) {
      // SignalConversion generated from: '<S48>/In'
      FLIGHT_HEXA_Hovering_B.In = FLIGHT_HEXA_Hovering_B.Subtract_f;
    }

    // End of Outputs for SubSystem: '<S46>/Enabled Subsystem'

    // Update for Delay: '<S41>/Delay' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] = FLIGHT_HEXA_Hovering_B.In1_c.x;
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] = FLIGHT_HEXA_Hovering_B.In1_c.y;

    // Update for Gain: '<S46>/Gain1' incorporates:
    //   Delay: '<S46>/Delay'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n = FLIGHT_HEXA_Hovering_B.In;

    // Update for Delay: '<S47>/Delay' incorporates:
    //   Constant: '<S47>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
      FLIGHT_HEXA_Hovering_P.Constant_Value_nn;

    // End of Outputs for SubSystem: '<S38>/Land'
    break;

   case 2:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S38>/Waypoint' incorporates:
      //   ActionPort: '<S43>/Action Port'

      // SystemReset for If: '<S38>/If' incorporates:
      //   MATLABSystem: '<S43>/UAV Waypoint Follower'
      //
      FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
      for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 9;
           FLIGHT_HEXA_Hovering_B.j++) {
        FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[FLIGHT_HEXA_Hovering_B.j] *=
          0.0;
      }

      // End of SystemReset for If: '<S38>/If'
      // End of SystemReset for SubSystem: '<S38>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S38>/Waypoint' incorporates:
    //   ActionPort: '<S43>/Action Port'

    // Concatenate: '<S43>/Matrix Concatenate'
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

    // MATLABSystem: '<S43>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S43>/Matrix Concatenate'
    //   Constant: '<S43>/Constant'

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
    FLIGHT_HEXA_Hovering_B.b_varargout_1 = false;
    FLIGHT_HEXA_Hovering_B.Compare = true;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.i1 <= 8)) {
      FLIGHT_HEXA_Hovering_B.j = FLIGHT_HEXA_Hovering_B.i1 / 3 * 3 +
        FLIGHT_HEXA_Hovering_B.i1 % 3;
      if (!(FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[FLIGHT_HEXA_Hovering_B.j]
            ==
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[FLIGHT_HEXA_Hovering_B.j]))
      {
        FLIGHT_HEXA_Hovering_B.Compare = false;
        exitg1 = true;
      } else {
        FLIGHT_HEXA_Hovering_B.i1++;
      }
    }

    if (FLIGHT_HEXA_Hovering_B.Compare) {
      FLIGHT_HEXA_Hovering_B.b_varargout_1 = true;
    }

    if (!FLIGHT_HEXA_Hovering_B.b_varargout_1) {
      memcpy(&FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[0],
             &FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0], 9U * sizeof(real_T));
      FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    }

    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 3;
         FLIGHT_HEXA_Hovering_B.j++) {
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.j] = true;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 * FLIGHT_HEXA_Hovering_B.j
        + 1];
      FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.j << 1;
      FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.i1] =
        (FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 * FLIGHT_HEXA_Hovering_B.j]
         != FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0);
      FLIGHT_HEXA_Hovering_B.x[FLIGHT_HEXA_Hovering_B.i1 + 1] =
        (FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 * FLIGHT_HEXA_Hovering_B.j
         + 2] != FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0);
    }

    FLIGHT_HEXA_Hovering_B.IsNaN_l[0] = false;
    FLIGHT_HEXA_Hovering_B.IsNaN_l[1] = false;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    FLIGHT_HEXA_Hovering_B.i2 = 4;
    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 2;
         FLIGHT_HEXA_Hovering_B.j++) {
      FLIGHT_HEXA_Hovering_B.i1++;
      FLIGHT_HEXA_Hovering_B.i2++;
      FLIGHT_HEXA_Hovering_B.ix = FLIGHT_HEXA_Hovering_B.i1;
      exitg1 = false;
      while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.ix <=
                           FLIGHT_HEXA_Hovering_B.i2)) {
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

    // End of Outputs for SubSystem: '<S38>/Waypoint'
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 3;
         FLIGHT_HEXA_Hovering_B.j++) {
      // Outputs for IfAction SubSystem: '<S38>/Waypoint' incorporates:
      //   ActionPort: '<S43>/Action Port'

      if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.j]) {
        FLIGHT_HEXA_Hovering_B.i1++;
      }

      // End of Outputs for SubSystem: '<S38>/Waypoint'
    }

    FLIGHT_HEXA_Hovering_B.ix = FLIGHT_HEXA_Hovering_B.i1;
    FLIGHT_HEXA_Hovering_B.i1 = 0;
    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 3;
         FLIGHT_HEXA_Hovering_B.j++) {
      // Outputs for IfAction SubSystem: '<S38>/Waypoint' incorporates:
      //   ActionPort: '<S43>/Action Port'

      if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.j]) {
        // Start for MATLABSystem: '<S43>/UAV Waypoint Follower'
        FLIGHT_HEXA_Hovering_B.tmp_data[FLIGHT_HEXA_Hovering_B.i1] =
          static_cast<int8_T>(FLIGHT_HEXA_Hovering_B.j);
        FLIGHT_HEXA_Hovering_B.i1++;
      }

      // End of Outputs for SubSystem: '<S38>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S38>/Waypoint' incorporates:
    //   ActionPort: '<S43>/Action Port'

    // MATLABSystem: '<S43>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S43>/Matrix Concatenate'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Reshape: '<S43>/Reshape1'

    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 3;
         FLIGHT_HEXA_Hovering_B.j++) {
      for (FLIGHT_HEXA_Hovering_B.i2 = 0; FLIGHT_HEXA_Hovering_B.i2 <
           FLIGHT_HEXA_Hovering_B.ix; FLIGHT_HEXA_Hovering_B.i2++) {
        FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[FLIGHT_HEXA_Hovering_B.i2 +
          FLIGHT_HEXA_Hovering_B.ix * FLIGHT_HEXA_Hovering_B.j] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[3 *
          FLIGHT_HEXA_Hovering_B.j +
          FLIGHT_HEXA_Hovering_B.tmp_data[FLIGHT_HEXA_Hovering_B.i2]];
      }
    }

    FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance =
      FLIGHT_HEXA_Hovering_B.Switch3;
    if (FLIGHT_HEXA_Hovering_B.ix == 0) {
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
      if (FLIGHT_HEXA_Hovering_B.ix == 1) {
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
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
            FLIGHT_HEXA_Hovering_B.In1_c.heading;
          FLIGHT_HEXA_Hovering_DW.obj.StartFlag = false;
        } else {
          FLIGHT_HEXA_Hovering_DW.obj.StartFlag = false;
          FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 2.0;
          FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.ix + 1;
          for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 3;
               FLIGHT_HEXA_Hovering_B.j++) {
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
              [(FLIGHT_HEXA_Hovering_B.ix + 1) * FLIGHT_HEXA_Hovering_B.j] =
              FLIGHT_HEXA_Hovering_DW.obj.InitialPose[FLIGHT_HEXA_Hovering_B.j];
            for (FLIGHT_HEXA_Hovering_B.i2 = 0; FLIGHT_HEXA_Hovering_B.i2 <
                 FLIGHT_HEXA_Hovering_B.ix; FLIGHT_HEXA_Hovering_B.i2++) {
              FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
                [(FLIGHT_HEXA_Hovering_B.i2 + (FLIGHT_HEXA_Hovering_B.ix + 1) *
                  FLIGHT_HEXA_Hovering_B.j) + 1] =
                FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[FLIGHT_HEXA_Hovering_B.ix
                * FLIGHT_HEXA_Hovering_B.j + FLIGHT_HEXA_Hovering_B.i2];
            }
          }

          guard1 = true;
        }
      } else {
        FLIGHT_HEXA_Hovering_B.i1 = FLIGHT_HEXA_Hovering_B.ix;
        FLIGHT_HEXA_Hovering_B.i2 = FLIGHT_HEXA_Hovering_B.ix * 3;
        if (FLIGHT_HEXA_Hovering_B.i2 - 1 >= 0) {
          memcpy(&FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[0],
                 &FLIGHT_HEXA_Hovering_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(FLIGHT_HEXA_Hovering_B.i2) * sizeof
                 (real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        FLIGHT_HEXA_Hovering_B.b_varargout_1 = false;
        if (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex ==
            FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints) {
          FLIGHT_HEXA_Hovering_B.b_varargout_1 = true;
        }

        if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
          FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = true;
          FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex--;
        }

        FLIGHT_HEXA_Hovering_B.Switch3 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) - 1];
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.Switch3;
        FLIGHT_HEXA_Hovering_B.Subtract_f =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
          FLIGHT_HEXA_Hovering_B.Subtract_f;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.In1_c.x - FLIGHT_HEXA_Hovering_B.Subtract_f;
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
          FLIGHT_HEXA_Hovering_B.i1) - 1];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          FLIGHT_HEXA_Hovering_B.i1) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.In1_c.y -
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[((FLIGHT_HEXA_Hovering_B.i1
          << 1) + static_cast<int32_T>(FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex))
          - 1];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
          FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
          (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
          (FLIGHT_HEXA_Hovering_B.i1 << 1)) - 1];
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.In1_c.z -
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_norm
          (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        guard2 = false;
        if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <= 2.0) {
          guard2 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.lla0[0] = FLIGHT_HEXA_Hovering_B.Subtract_f -
            FLIGHT_HEXA_Hovering_B.Switch3;
          FLIGHT_HEXA_Hovering_B.lla0[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            FLIGHT_HEXA_Hovering_B.i1) - 1] -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex) +
            FLIGHT_HEXA_Hovering_B.i1) - 1];
          FLIGHT_HEXA_Hovering_B.Switch3 =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (FLIGHT_HEXA_Hovering_B.i1 << 1)) - 1];
          FLIGHT_HEXA_Hovering_B.lla0[2] = FLIGHT_HEXA_Hovering_B.Switch3 -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
            [((FLIGHT_HEXA_Hovering_B.i1 << 1) + static_cast<int32_T>
              (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex)) - 1];
          FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.lla0);
          FLIGHT_HEXA_Hovering_B.Switch3 = ((FLIGHT_HEXA_Hovering_B.In1_c.x -
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) - 1]) /
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            (FLIGHT_HEXA_Hovering_B.lla0[0] / FLIGHT_HEXA_Hovering_B.Subtract_f)
            + FLIGHT_HEXA_Hovering_B.lla0[1] / FLIGHT_HEXA_Hovering_B.Subtract_f
            * (FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] /
               FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0)) +
            (FLIGHT_HEXA_Hovering_B.In1_c.z - FLIGHT_HEXA_Hovering_B.Switch3) /
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            (FLIGHT_HEXA_Hovering_B.lla0[2] / FLIGHT_HEXA_Hovering_B.Subtract_f);
          if (rtIsNaN(FLIGHT_HEXA_Hovering_B.Switch3) ||
              (FLIGHT_HEXA_Hovering_B.Switch3 < 0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex++;
          FLIGHT_HEXA_Hovering_B.b_varargout_1 = false;
          if (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex ==
              FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints) {
            FLIGHT_HEXA_Hovering_B.b_varargout_1 = true;
          }

          if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
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
            FLIGHT_HEXA_Hovering_B.i1) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            FLIGHT_HEXA_Hovering_B.i1) - 1];
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p
            [((FLIGHT_HEXA_Hovering_B.i1 << 1) + static_cast<int32_T>
              (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex)) - 1];
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
            FLIGHT_HEXA_Hovering_B.MatrixConcatenate_p[(static_cast<int32_T>
            (FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex + 1.0) +
            (FLIGHT_HEXA_Hovering_B.i1 << 1)) - 1];
        }

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x
          - FLIGHT_HEXA_Hovering_B.b_startWaypoint[0];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        FLIGHT_HEXA_Hovering_B.Switch3 =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[0];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp =
          FLIGHT_HEXA_Hovering_B.In1_c.y -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[1];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
          FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp;
        FLIGHT_HEXA_Hovering_B.Switch_fw =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[1];
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.In1_c.z
          - FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
        FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;
        FLIGHT_HEXA_Hovering_B.Switch4 =
          FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] -
          FLIGHT_HEXA_Hovering_B.b_startWaypoint[2];
        FLIGHT_HEXA_Hovering_B.Subtract_f = (FLIGHT_HEXA_Hovering_B.Switch_fw *
          FLIGHT_HEXA_Hovering_B.Switch_fw + FLIGHT_HEXA_Hovering_B.Switch3 *
          FLIGHT_HEXA_Hovering_B.Switch3) + FLIGHT_HEXA_Hovering_B.Switch4 *
          FLIGHT_HEXA_Hovering_B.Switch4;
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
          ((FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp *
            FLIGHT_HEXA_Hovering_B.Switch_fw +
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
            FLIGHT_HEXA_Hovering_B.Switch3) +
           FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
           FLIGHT_HEXA_Hovering_B.Switch4) / FLIGHT_HEXA_Hovering_B.Subtract_f;
        if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 < 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 > 1.0) {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        } else {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
             FLIGHT_HEXA_Hovering_B.Switch3 +
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[0]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
             FLIGHT_HEXA_Hovering_B.Switch_fw +
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[1]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
             FLIGHT_HEXA_Hovering_B.Switch4 +
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[2]);
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        }

        if (FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
            ((FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *
              FLIGHT_HEXA_Hovering_B.Switch3 +
              FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp *
              FLIGHT_HEXA_Hovering_B.Switch_fw) +
             (FLIGHT_HEXA_Hovering_B.In1_c.z -
              FLIGHT_HEXA_Hovering_B.b_startWaypoint[2]) *
             FLIGHT_HEXA_Hovering_B.Switch4) / FLIGHT_HEXA_Hovering_B.Subtract_f;
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[0] =
            FLIGHT_HEXA_Hovering_B.In1_c.x -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
             FLIGHT_HEXA_Hovering_B.Switch3 +
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[0]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[1] =
            FLIGHT_HEXA_Hovering_B.In1_c.y -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
             FLIGHT_HEXA_Hovering_B.Switch_fw +
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[1]);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint[2] =
            FLIGHT_HEXA_Hovering_B.In1_c.z -
            (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 *
             FLIGHT_HEXA_Hovering_B.Switch4 +
             FLIGHT_HEXA_Hovering_B.b_startWaypoint[2]);
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_norm
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint);
        }

        FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp = fabs
          (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3);
        if (rtIsInf(FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp) || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp)) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp <
                   4.4501477170144028E-308) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = 4.94065645841247E-324;
          FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp = 4.94065645841247E-324;
        } else {
          frexp(FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp,
                &FLIGHT_HEXA_Hovering_B.ParamStep_k);
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = ldexp(1.0,
            FLIGHT_HEXA_Hovering_B.ParamStep_k - 53);
          frexp(FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp,
                &FLIGHT_HEXA_Hovering_B.b_exponent);
          FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp = ldexp(1.0,
            FLIGHT_HEXA_Hovering_B.b_exponent - 53);
        }

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = sqrt
          (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0);
        FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp *= 5.0;
        if ((FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >=
             FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp) || rtIsNaN
            (FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp)) {
          FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp =
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
        }

        if (FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance <=
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 +
            FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp) {
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance =
            FLIGHT_HEXA_Hovering_DW.obj.LookaheadFactor *
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;
        }

        FLIGHT_HEXA_Hovering_B.lla0[0] = FLIGHT_HEXA_Hovering_B.b_startWaypoint
          [0] - FLIGHT_HEXA_Hovering_B.In1_c.x;
        FLIGHT_HEXA_Hovering_B.lla0[1] = FLIGHT_HEXA_Hovering_B.b_startWaypoint
          [1] - FLIGHT_HEXA_Hovering_B.In1_c.y;
        FLIGHT_HEXA_Hovering_B.lla0[2] = FLIGHT_HEXA_Hovering_B.b_startWaypoint
          [2] - FLIGHT_HEXA_Hovering_B.In1_c.z;
        FLIGHT_HEXA_Hovering_B.Switch3 = ((FLIGHT_HEXA_Hovering_B.Switch3 *
          FLIGHT_HEXA_Hovering_B.lla0[0] + FLIGHT_HEXA_Hovering_B.Switch_fw *
          FLIGHT_HEXA_Hovering_B.lla0[1]) + FLIGHT_HEXA_Hovering_B.Switch4 *
          FLIGHT_HEXA_Hovering_B.lla0[2]) * 2.0;
        FLIGHT_HEXA_Hovering_B.Switch_fw = sqrt(FLIGHT_HEXA_Hovering_B.Switch3 *
          FLIGHT_HEXA_Hovering_B.Switch3 - (((FLIGHT_HEXA_Hovering_B.lla0[0] *
          FLIGHT_HEXA_Hovering_B.lla0[0] + FLIGHT_HEXA_Hovering_B.lla0[1] *
          FLIGHT_HEXA_Hovering_B.lla0[1]) + FLIGHT_HEXA_Hovering_B.lla0[2] *
          FLIGHT_HEXA_Hovering_B.lla0[2]) -
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance *
          FLIGHT_HEXA_Hovering_DW.obj.LookaheadDistance) * (4.0 *
          FLIGHT_HEXA_Hovering_B.Subtract_f));
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
          (-FLIGHT_HEXA_Hovering_B.Switch3 + FLIGHT_HEXA_Hovering_B.Switch_fw) /
          2.0 / FLIGHT_HEXA_Hovering_B.Subtract_f;
        FLIGHT_HEXA_Hovering_B.Switch3 = (-FLIGHT_HEXA_Hovering_B.Switch3 -
          FLIGHT_HEXA_Hovering_B.Switch_fw) / 2.0 /
          FLIGHT_HEXA_Hovering_B.Subtract_f;
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
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
          FLIGHT_HEXA_Hovering_rt_atan2d_snf
          (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] -
           FLIGHT_HEXA_Hovering_B.In1_c.y,
           FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] -
           FLIGHT_HEXA_Hovering_B.In1_c.x);
        FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S53>/Switch1' incorporates:
    //   Constant: '<S54>/Constant'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Logic: '<S53>/OR'
    //   Logic: '<S53>/OR1'
    //   MATLABSystem: '<S43>/UAV Waypoint Follower'
    //   Merge: '<S38>/Merge'
    //   RelationalOperator: '<S53>/IsNaN'
    //   RelationalOperator: '<S53>/IsNaN1'
    //   RelationalOperator: '<S54>/Compare'
    //   Switch: '<S53>/Switch'
    //
    if (rtIsNaN(FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1]) || rtIsNaN
        (FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2]) ||
        (FLIGHT_HEXA_Hovering_B.In1_p.current.type ==
         FLIGHT_HEXA_Hovering_P.CompareToConstant_const_d)) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x;
      FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.In1_c.y;
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.In1_c.z;
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
        FLIGHT_HEXA_Hovering_B.In1_c.heading;
    } else {
      if (rtIsNaN(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3)) {
        // Switch: '<S53>/Switch' incorporates:
        //   Constant: '<S53>/Constant'
        //   Merge: '<S38>/Merge'
        //   Reshape: '<S53>/Reshape2'

        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
          FLIGHT_HEXA_Hovering_P.Constant_Value_jd;
      }

      // Math: '<S53>/Transpose1' incorporates:
      //   Merge: '<S38>/Merge'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0];
      FLIGHT_HEXA_Hovering_B.Switch4 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1];
      FLIGHT_HEXA_Hovering_B.Switch3 =
        FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2];
    }

    // End of Switch: '<S53>/Switch1'
    // End of Outputs for SubSystem: '<S38>/Waypoint'
    break;

   default:
    if (FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem !=
        FLIGHT_HEXA_Hovering_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S38>/IDLE' incorporates:
      //   ActionPort: '<S40>/Action Port'

      // InitializeConditions for If: '<S38>/If' incorporates:
      //   Delay: '<S44>/Delay'

      FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
        FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S38>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S38>/IDLE' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // Outputs for Enabled SubSystem: '<S44>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S45>/Enable'

    if (FLIGHT_HEXA_Hovering_DW.Delay_DSTATE > 0.0) {
      // SignalConversion generated from: '<S45>/yaw_In' incorporates:
      //   DataTypeConversion: '<S2>/Data Type Conversion1'

      FLIGHT_HEXA_Hovering_B.yaw_In = FLIGHT_HEXA_Hovering_B.In1_c.heading;
    }

    // End of Outputs for SubSystem: '<S44>/Enabled Subsystem2'

    // Reshape: '<S40>/Reshape1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Delay: '<S44>/Delay'
    //   Merge: '<S38>/Merge'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.In1_c.x;
    FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.In1_c.y;
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.In1_c.z;
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 = FLIGHT_HEXA_Hovering_B.yaw_In;

    // Update for Delay: '<S44>/Delay' incorporates:
    //   Constant: '<S44>/Constant'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
      FLIGHT_HEXA_Hovering_P.Constant_Value_i;

    // End of Outputs for SubSystem: '<S38>/IDLE'
    break;
  }

  // End of If: '<S38>/If'

  // Outputs for Enabled SubSystem: '<S4>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S77>/Enable'

  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    // Trigonometry: '<S342>/SinCos'
    FLIGHT_HEXA_Hovering_B.Switch_fw = sin
      (FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);
    FLIGHT_HEXA_Hovering_B.Subtract_f = cos
      (FLIGHT_HEXA_Hovering_B.VectorConcatenate[0]);

    // Sum: '<S77>/Sum5'
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 -=
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[0];

    // Saturate: '<S440>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S438>/Proportional Gain'
    //   Sum: '<S77>/Sum1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 - FLIGHT_HEXA_Hovering_B.In1_c.x) *
      FLIGHT_HEXA_Hovering_P.PIDController1_P_h;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e;
    }

    // Sum: '<S77>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S440>/Saturation'

    FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp =
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 - FLIGHT_HEXA_Hovering_B.In1_c.vx;

    // Saturate: '<S440>/Saturation' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Gain: '<S438>/Proportional Gain'
    //   Sum: '<S77>/Sum1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (FLIGHT_HEXA_Hovering_B.Switch4 -
      FLIGHT_HEXA_Hovering_B.In1_c.y) *
      FLIGHT_HEXA_Hovering_P.PIDController1_P_h;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit_l;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit_e;
    }

    // Sum: '<S77>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S440>/Saturation'

    FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 -
      FLIGHT_HEXA_Hovering_B.In1_c.vy;

    // Saturate: '<S390>/Saturation' incorporates:
    //   Gain: '<S342>/Gain'
    //   Gain: '<S388>/Proportional Gain'
    //   Product: '<S77>/MatrixMultiply'
    //   Reshape: '<S342>/Reshape'
    //   Reshape: '<S342>/Reshape1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (FLIGHT_HEXA_Hovering_B.Subtract_f *
      FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp +
      FLIGHT_HEXA_Hovering_B.Switch_fw * FLIGHT_HEXA_Hovering_B.Switch4) *
      FLIGHT_HEXA_Hovering_P.PIDController_P_d;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b) {
      // Saturate: '<S390>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j) {
      // Saturate: '<S390>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j;
    } else {
      // Saturate: '<S390>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[0] =
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
      (FLIGHT_HEXA_Hovering_P.Gain_Gain_or * FLIGHT_HEXA_Hovering_B.Switch_fw *
       FLIGHT_HEXA_Hovering_B.virtualWaypoint_tmp +
       FLIGHT_HEXA_Hovering_B.Subtract_f * FLIGHT_HEXA_Hovering_B.Switch4) *
      FLIGHT_HEXA_Hovering_P.PIDController_P_d;
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b) {
      // Saturate: '<S390>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit_b;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j) {
      // Saturate: '<S390>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit_j;
    } else {
      // Saturate: '<S390>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation[1] =
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
    }

    // End of Saturate: '<S390>/Saturation'

    // Gain: '<S77>/Gain1'
    FLIGHT_HEXA_Hovering_B.Gain1 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_m *
      FLIGHT_HEXA_Hovering_B.Saturation[0];

    // Switch: '<S343>/Switch' incorporates:
    //   Abs: '<S343>/Abs'

    if (fabs(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3) >
        FLIGHT_HEXA_Hovering_P.Switch_Threshold_e) {
      // Switch: '<S343>/Switch1' incorporates:
      //   Constant: '<S343>/Constant'
      //   Sum: '<S343>/Add'
      //   Sum: '<S343>/Subtract'

      if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 >
          FLIGHT_HEXA_Hovering_P.Switch1_Threshold) {
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 -=
          FLIGHT_HEXA_Hovering_P.Constant_Value_g4;
      } else {
        FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 +=
          FLIGHT_HEXA_Hovering_P.Constant_Value_g4;
      }

      // End of Switch: '<S343>/Switch1'
    }

    // Gain: '<S488>/Proportional Gain' incorporates:
    //   Switch: '<S343>/Switch'

    FLIGHT_HEXA_Hovering_B.Saturation_a =
      FLIGHT_HEXA_Hovering_P.PIDController5_P *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Saturate: '<S490>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Saturation_a >
        FLIGHT_HEXA_Hovering_P.PIDController5_UpperSaturationLimit) {
      // Gain: '<S488>/Proportional Gain' incorporates:
      //   Saturate: '<S490>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_a =
        FLIGHT_HEXA_Hovering_P.PIDController5_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Saturation_a <
               FLIGHT_HEXA_Hovering_P.PIDController5_LowerSaturationLimit) {
      // Gain: '<S488>/Proportional Gain' incorporates:
      //   Saturate: '<S490>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_a =
        FLIGHT_HEXA_Hovering_P.PIDController5_LowerSaturationLimit;
    }

    // End of Saturate: '<S490>/Saturation'

    // Gain: '<S341>/Gain1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_P.Gain1_Gain_h
      * FLIGHT_HEXA_Hovering_B.In1_c.z;

    // Switch: '<S349>/Switch' incorporates:
    //   Constant: '<S341>/Constant'
    //   RelationalOperator: '<S349>/UpperRelop'
    //   Switch: '<S349>/Switch2'

    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
        FLIGHT_HEXA_Hovering_P.Constant_Value_ib) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_ib;
    }

    // Sum: '<S77>/Sum2' incorporates:
    //   Gain: '<S4>/Gain'
    //   Switch: '<S349>/Switch'
    //   Switch: '<S349>/Switch2'

    FLIGHT_HEXA_Hovering_B.Switch_fw = FLIGHT_HEXA_Hovering_P.Gain_Gain_bp *
      FLIGHT_HEXA_Hovering_B.Switch3 - FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

    // Gain: '<S540>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_P.PID_Altitude_P *
      FLIGHT_HEXA_Hovering_B.Switch_fw;

    // Gain: '<S538>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S530>/Filter'
    //   Gain: '<S528>/Derivative Gain'
    //   Sum: '<S530>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3 =
      (FLIGHT_HEXA_Hovering_P.PID_Altitude_D * FLIGHT_HEXA_Hovering_B.Switch_fw
       - FLIGHT_HEXA_Hovering_DW.Filter_DSTATE) *
      FLIGHT_HEXA_Hovering_P.PID_Altitude_N;

    // Sum: '<S545>/Sum Fdbk'
    FLIGHT_HEXA_Hovering_B.Switch3 = (FLIGHT_HEXA_Hovering_B.Subtract_f +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE) +
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;

    // DeadZone: '<S527>/DeadZone'
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

    // End of DeadZone: '<S527>/DeadZone'

    // Gain: '<S532>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Switch_fw *= FLIGHT_HEXA_Hovering_P.PID_Altitude_I;

    // Switch: '<S525>/Switch1' incorporates:
    //   Constant: '<S525>/Clamping_zero'
    //   Constant: '<S525>/Constant'
    //   Constant: '<S525>/Constant2'
    //   RelationalOperator: '<S525>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_nq;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_o;
    }

    // Switch: '<S525>/Switch2' incorporates:
    //   Constant: '<S525>/Clamping_zero'
    //   Constant: '<S525>/Constant3'
    //   Constant: '<S525>/Constant4'
    //   RelationalOperator: '<S525>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Switch_fw >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f) {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant3_Value_o;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant4_Value_d;
    }

    // Switch: '<S525>/Switch' incorporates:
    //   Constant: '<S525>/Clamping_zero'
    //   Constant: '<S525>/Constant1'
    //   Logic: '<S525>/AND3'
    //   RelationalOperator: '<S525>/Equal1'
    //   RelationalOperator: '<S525>/Relational Operator'
    //   Switch: '<S525>/Switch1'
    //   Switch: '<S525>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_f !=
         FLIGHT_HEXA_Hovering_B.Switch3) && (FLIGHT_HEXA_Hovering_B.rtPrevAction
         == FLIGHT_HEXA_Hovering_B.i2_b)) {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_l;
    }

    // DiscreteIntegrator: '<S535>/Integrator' incorporates:
    //   Switch: '<S525>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_p *
      FLIGHT_HEXA_Hovering_B.Switch_fw;

    // Sum: '<S544>/Sum'
    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (FLIGHT_HEXA_Hovering_B.Subtract_f
      + FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE) +
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Saturate: '<S542>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PID_Altitude_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.PID_Altitude_LowerSaturationLimit;
    }

    // Sum: '<S77>/Sum3' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   Saturate: '<S542>/Saturation'
    //   UnaryMinus: '<S77>/Unary Minus'

    FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 -
      (-static_cast<real_T>(FLIGHT_HEXA_Hovering_B.In1_c.vz));

    // Gain: '<S592>/Proportional Gain'
    FLIGHT_HEXA_Hovering_B.Switch_fw = FLIGHT_HEXA_Hovering_P.PID_vz_P *
      FLIGHT_HEXA_Hovering_B.Subtract_f;

    // Gain: '<S590>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S582>/Filter'
    //   Gain: '<S580>/Derivative Gain'
    //   Sum: '<S582>/SumD'

    FLIGHT_HEXA_Hovering_B.Switch3 = (FLIGHT_HEXA_Hovering_P.PID_vz_D *
      FLIGHT_HEXA_Hovering_B.Subtract_f -
      FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_o) * FLIGHT_HEXA_Hovering_P.PID_vz_N;

    // Sum: '<S597>/Sum Fdbk'
    FLIGHT_HEXA_Hovering_B.Switch4 = (FLIGHT_HEXA_Hovering_B.Switch_fw +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o) +
      FLIGHT_HEXA_Hovering_B.Switch3;

    // DeadZone: '<S579>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.Switch4 >
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch4 -=
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Switch4 >=
               FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch4 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Switch4 -=
        FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S579>/DeadZone'

    // Gain: '<S584>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Subtract_f *= FLIGHT_HEXA_Hovering_P.PID_vz_I;

    // Switch: '<S577>/Switch1' incorporates:
    //   Constant: '<S577>/Clamping_zero'
    //   Constant: '<S577>/Constant'
    //   Constant: '<S577>/Constant2'
    //   RelationalOperator: '<S577>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Switch4 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_a) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_d3;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_pb;
    }

    // Switch: '<S577>/Switch2' incorporates:
    //   Constant: '<S577>/Clamping_zero'
    //   Constant: '<S577>/Constant3'
    //   Constant: '<S577>/Constant4'
    //   RelationalOperator: '<S577>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Subtract_f >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_a) {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant3_Value_m;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant4_Value_c;
    }

    // Switch: '<S577>/Switch' incorporates:
    //   Constant: '<S577>/Clamping_zero'
    //   Constant: '<S577>/Constant1'
    //   Logic: '<S577>/AND3'
    //   RelationalOperator: '<S577>/Equal1'
    //   RelationalOperator: '<S577>/Relational Operator'
    //   Switch: '<S577>/Switch1'
    //   Switch: '<S577>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_a !=
         FLIGHT_HEXA_Hovering_B.Switch4) && (FLIGHT_HEXA_Hovering_B.rtPrevAction
         == FLIGHT_HEXA_Hovering_B.i2_b)) {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_fq;
    }

    // DiscreteIntegrator: '<S587>/Integrator' incorporates:
    //   Switch: '<S577>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_k *
      FLIGHT_HEXA_Hovering_B.Subtract_f;

    // Sum: '<S596>/Sum'
    FLIGHT_HEXA_Hovering_B.Saturation_o = (FLIGHT_HEXA_Hovering_B.Switch_fw +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o) +
      FLIGHT_HEXA_Hovering_B.Switch3;

    // Saturate: '<S594>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Saturation_o >
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit) {
      // Sum: '<S596>/Sum' incorporates:
      //   Saturate: '<S594>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_P.PID_vz_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Saturation_o <
               FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit) {
      // Sum: '<S596>/Sum' incorporates:
      //   Saturate: '<S594>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_o =
        FLIGHT_HEXA_Hovering_P.PID_vz_LowerSaturationLimit;
    }

    // End of Saturate: '<S594>/Saturation'

    // Update for DiscreteIntegrator: '<S530>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_i *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_3;

    // Update for DiscreteIntegrator: '<S582>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_o +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_m * FLIGHT_HEXA_Hovering_B.Switch3;
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
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 =
        FLIGHT_HEXA_Hovering_B.Saturation_a;
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = FLIGHT_HEXA_Hovering_B.Gain1;
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
        FLIGHT_HEXA_Hovering_B.Saturation[1];
      FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.Saturation_o;
    }

    // case IN_STABLIZED:
  } else if (FLIGHT_HEXA_Hovering_B.In1_j.values[5] > 1400) {
    FLIGHT_HEXA_Hovering_DW.is_c3_FLIGHT_HEXA_Hovering =
      FLIGHT_HEXA_Hovering_IN_MISSION;
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 =
      FLIGHT_HEXA_Hovering_B.Saturation_a;
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = FLIGHT_HEXA_Hovering_B.Gain1;
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
      FLIGHT_HEXA_Hovering_B.Saturation[1];
    FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.Saturation_o;
  }

  // End of Chart: '<S4>/Chart'

  // Outputs for Enabled SubSystem: '<S4>/Attitude controller' incorporates:
  //   EnablePort: '<S74>/Enable'

  if (FLIGHT_HEXA_Hovering_B.In1_b.armed) {
    // Sum: '<S74>/Sum4' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'

    FLIGHT_HEXA_Hovering_B.Switch_fw =
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[2];

    // Gain: '<S117>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_P.PIDController_I *
      FLIGHT_HEXA_Hovering_B.Switch_fw;

    // Gain: '<S123>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S115>/Filter'
    //   Gain: '<S113>/Derivative Gain'
    //   Sum: '<S115>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 =
      (FLIGHT_HEXA_Hovering_P.PIDController_D * FLIGHT_HEXA_Hovering_B.Switch_fw
       - FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ov) *
      FLIGHT_HEXA_Hovering_P.PIDController_N;

    // Sum: '<S129>/Sum' incorporates:
    //   DiscreteIntegrator: '<S120>/Integrator'
    //   Gain: '<S125>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.Switch3 = (FLIGHT_HEXA_Hovering_P.PIDController_P *
      FLIGHT_HEXA_Hovering_B.Switch_fw +
      FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i) +
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0;

    // DeadZone: '<S112>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.Switch3 -
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 >=
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch4 = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_B.Switch3 -
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    }

    // End of DeadZone: '<S112>/DeadZone'

    // Switch: '<S110>/Switch1' incorporates:
    //   Constant: '<S110>/Clamping_zero'
    //   Constant: '<S110>/Constant'
    //   Constant: '<S110>/Constant2'
    //   RelationalOperator: '<S110>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Switch4 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_k;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_j;
    }

    // Switch: '<S110>/Switch2' incorporates:
    //   Constant: '<S110>/Clamping_zero'
    //   Constant: '<S110>/Constant3'
    //   Constant: '<S110>/Constant4'
    //   RelationalOperator: '<S110>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Subtract_f >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value) {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant3_Value_l;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant4_Value_o;
    }

    // Switch: '<S110>/Switch' incorporates:
    //   Constant: '<S110>/Clamping_zero'
    //   Constant: '<S110>/Constant1'
    //   Logic: '<S110>/AND3'
    //   RelationalOperator: '<S110>/Equal1'
    //   RelationalOperator: '<S110>/Relational Operator'
    //   Switch: '<S110>/Switch1'
    //   Switch: '<S110>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value !=
         FLIGHT_HEXA_Hovering_B.Switch4) && (FLIGHT_HEXA_Hovering_B.rtPrevAction
         == FLIGHT_HEXA_Hovering_B.i2_b)) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_m;
    } else {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = FLIGHT_HEXA_Hovering_B.Subtract_f;
    }

    // End of Switch: '<S110>/Switch'

    // Saturate: '<S127>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit) {
      // Saturate: '<S127>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_n =
        FLIGHT_HEXA_Hovering_P.PIDController_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 <
               FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit) {
      // Saturate: '<S127>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_n =
        FLIGHT_HEXA_Hovering_P.PIDController_LowerSaturationLimit;
    } else {
      // Saturate: '<S127>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_n = FLIGHT_HEXA_Hovering_B.Switch3;
    }

    // End of Saturate: '<S127>/Saturation'

    // RateLimiter: '<S74>/Rate Limiter2'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1
      - FLIGHT_HEXA_Hovering_DW.PrevY;
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.RateLimiter2_RisingLim *
        FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_P.RateLimiter2_RisingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 <
               FLIGHT_HEXA_Hovering_P.RateLimiter2_FallingLim *
               FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_P.RateLimiter2_FallingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY;
    } else {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1;
    }

    FLIGHT_HEXA_Hovering_DW.PrevY = FLIGHT_HEXA_Hovering_B.Subtract_f;

    // End of RateLimiter: '<S74>/Rate Limiter2'

    // If: '<S607>/If' incorporates:
    //   Constant: '<S608>/Constant'
    //   Constant: '<S609>/Constant'

    if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 > 1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_ji;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 < -1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_h;
    }

    // Saturate: '<S74>/Saturation1'
    if (FLIGHT_HEXA_Hovering_B.Subtract_f >
        FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat) {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_P.Saturation1_UpperSat;
    } else if (FLIGHT_HEXA_Hovering_B.Subtract_f <
               FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat) {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_P.Saturation1_LowerSat;
    }

    // If: '<S607>/If' incorporates:
    //   Trigonometry: '<S605>/trigFcn'

    if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 > 1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 = 1.0;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 < -1.0) {
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 = -1.0;
    }

    // Sum: '<S74>/Sum' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S279>/Proportional Gain'
    //   Saturate: '<S74>/Saturation1'
    //   Sum: '<S74>/Sum2'
    //   Trigonometry: '<S605>/trigFcn'

    FLIGHT_HEXA_Hovering_B.Subtract_f = (FLIGHT_HEXA_Hovering_B.Subtract_f -
      asin(FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3)) *
      FLIGHT_HEXA_Hovering_P.PIDController3_P -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[1];

    // Gain: '<S169>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.PIDController1_I *
      FLIGHT_HEXA_Hovering_B.Subtract_f;

    // Gain: '<S175>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S167>/Filter'
    //   Gain: '<S165>/Derivative Gain'
    //   Sum: '<S167>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
      (FLIGHT_HEXA_Hovering_P.PIDController1_D *
       FLIGHT_HEXA_Hovering_B.Subtract_f -
       FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_c) *
      FLIGHT_HEXA_Hovering_P.PIDController1_N;

    // Sum: '<S181>/Sum' incorporates:
    //   DiscreteIntegrator: '<S172>/Integrator'
    //   Gain: '<S177>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      (FLIGHT_HEXA_Hovering_P.PIDController1_P *
       FLIGHT_HEXA_Hovering_B.Subtract_f +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_h) +
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3;

    // DeadZone: '<S164>/DeadZone'
    if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 -
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 >=
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.Switch_fw = 0.0;
    } else {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 -
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S164>/DeadZone'

    // Switch: '<S162>/Switch1' incorporates:
    //   Constant: '<S162>/Clamping_zero'
    //   Constant: '<S162>/Constant'
    //   Constant: '<S162>/Constant2'
    //   RelationalOperator: '<S162>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.Switch_fw >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_e) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_bd;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_fs;
    }

    // Switch: '<S162>/Switch2' incorporates:
    //   Constant: '<S162>/Clamping_zero'
    //   Constant: '<S162>/Constant3'
    //   Constant: '<S162>/Constant4'
    //   RelationalOperator: '<S162>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_e) {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant3_Value_n;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant4_Value_n;
    }

    // Switch: '<S162>/Switch' incorporates:
    //   Constant: '<S162>/Clamping_zero'
    //   Constant: '<S162>/Constant1'
    //   Logic: '<S162>/AND3'
    //   RelationalOperator: '<S162>/Equal1'
    //   RelationalOperator: '<S162>/Relational Operator'
    //   Switch: '<S162>/Switch1'
    //   Switch: '<S162>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_e !=
         FLIGHT_HEXA_Hovering_B.Switch_fw) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.i2_b)) {
      FLIGHT_HEXA_Hovering_B.Subtract_f =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_c;
    } else {
      FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_B.Switch3;
    }

    // End of Switch: '<S162>/Switch'

    // Saturate: '<S179>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 >
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit) {
      // Saturate: '<S179>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_b =
        FLIGHT_HEXA_Hovering_P.PIDController1_UpperSaturationLimit;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 <
               FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit) {
      // Saturate: '<S179>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_b =
        FLIGHT_HEXA_Hovering_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S179>/Saturation'
      FLIGHT_HEXA_Hovering_B.Saturation_b =
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1;
    }

    // End of Saturate: '<S179>/Saturation'

    // RateLimiter: '<S74>/Rate Limiter1'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2
      - FLIGHT_HEXA_Hovering_DW.PrevY_m;
    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.RateLimiter1_RisingLim *
        FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_P.RateLimiter1_RisingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY_m;
    } else if (FLIGHT_HEXA_Hovering_B.Switch3 <
               FLIGHT_HEXA_Hovering_P.RateLimiter1_FallingLim *
               FLIGHT_HEXA_Hovering_period) {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_P.RateLimiter1_FallingLim *
        FLIGHT_HEXA_Hovering_period + FLIGHT_HEXA_Hovering_DW.PrevY_m;
    } else {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2;
    }

    FLIGHT_HEXA_Hovering_DW.PrevY_m = FLIGHT_HEXA_Hovering_B.Switch_fw;

    // End of RateLimiter: '<S74>/Rate Limiter1'

    // Saturate: '<S74>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.Switch_fw >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_a) {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_a;
    } else if (FLIGHT_HEXA_Hovering_B.Switch_fw <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_a) {
      FLIGHT_HEXA_Hovering_B.Switch_fw =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_a;
    }

    // Sum: '<S74>/Sum1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   Gain: '<S329>/Proportional Gain'
    //   Saturate: '<S74>/Saturation'
    //   Sum: '<S74>/Sum3'

    FLIGHT_HEXA_Hovering_B.Switch_fw = (FLIGHT_HEXA_Hovering_B.Switch_fw -
      FLIGHT_HEXA_Hovering_B.VectorConcatenate[2]) *
      FLIGHT_HEXA_Hovering_P.PIDController4_P -
      FLIGHT_HEXA_Hovering_B.In1_l.xyz[0];

    // Gain: '<S221>/Integral Gain'
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.PIDController2_I *
      FLIGHT_HEXA_Hovering_B.Switch_fw;

    // Gain: '<S227>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S219>/Filter'
    //   Gain: '<S217>/Derivative Gain'
    //   Sum: '<S219>/SumD'

    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
      (FLIGHT_HEXA_Hovering_P.PIDController2_D *
       FLIGHT_HEXA_Hovering_B.Switch_fw -
       FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_f) *
      FLIGHT_HEXA_Hovering_P.PIDController2_N;

    // Sum: '<S233>/Sum' incorporates:
    //   DiscreteIntegrator: '<S224>/Integrator'
    //   Gain: '<S229>/Proportional Gain'

    FLIGHT_HEXA_Hovering_B.Saturation_a1 =
      (FLIGHT_HEXA_Hovering_P.PIDController2_P *
       FLIGHT_HEXA_Hovering_B.Switch_fw +
       FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_ih) +
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2;

    // DeadZone: '<S216>/DeadZone' incorporates:
    //   Saturate: '<S231>/Saturation'

    if (FLIGHT_HEXA_Hovering_B.Saturation_a1 >
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit) {
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
        FLIGHT_HEXA_Hovering_B.Saturation_a1 -
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;

      // Sum: '<S233>/Sum' incorporates:
      //   Saturate: '<S231>/Saturation'

      FLIGHT_HEXA_Hovering_B.Saturation_a1 =
        FLIGHT_HEXA_Hovering_P.PIDController2_UpperSaturationLimit;
    } else {
      if (FLIGHT_HEXA_Hovering_B.Saturation_a1 >=
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = 0.0;
      } else {
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          FLIGHT_HEXA_Hovering_B.Saturation_a1 -
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }

      if (FLIGHT_HEXA_Hovering_B.Saturation_a1 <
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit) {
        // Sum: '<S233>/Sum' incorporates:
        //   Saturate: '<S231>/Saturation'

        FLIGHT_HEXA_Hovering_B.Saturation_a1 =
          FLIGHT_HEXA_Hovering_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of DeadZone: '<S216>/DeadZone'

    // Update for DiscreteIntegrator: '<S120>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;

    // Update for DiscreteIntegrator: '<S115>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ov +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval *
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0;

    // Update for DiscreteIntegrator: '<S172>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_h +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_i *
      FLIGHT_HEXA_Hovering_B.Subtract_f;

    // Update for DiscreteIntegrator: '<S167>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_c +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_e *
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3;

    // Switch: '<S214>/Switch1' incorporates:
    //   Constant: '<S214>/Clamping_zero'
    //   Constant: '<S214>/Constant'
    //   Constant: '<S214>/Constant2'
    //   RelationalOperator: '<S214>/fix for DT propagation issue'

    if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_j) {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant_Value_a;
    } else {
      FLIGHT_HEXA_Hovering_B.rtPrevAction =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_p;
    }

    // Switch: '<S214>/Switch2' incorporates:
    //   Constant: '<S214>/Clamping_zero'
    //   Constant: '<S214>/Constant3'
    //   Constant: '<S214>/Constant4'
    //   RelationalOperator: '<S214>/fix for DT propagation issue1'

    if (FLIGHT_HEXA_Hovering_B.Switch3 >
        FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_j) {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant3_Value_b;
    } else {
      FLIGHT_HEXA_Hovering_B.i2_b = FLIGHT_HEXA_Hovering_P.Constant4_Value_l;
    }

    // Switch: '<S214>/Switch' incorporates:
    //   Constant: '<S214>/Clamping_zero'
    //   Constant: '<S214>/Constant1'
    //   Logic: '<S214>/AND3'
    //   RelationalOperator: '<S214>/Equal1'
    //   RelationalOperator: '<S214>/Relational Operator'
    //   Switch: '<S214>/Switch1'
    //   Switch: '<S214>/Switch2'

    if ((FLIGHT_HEXA_Hovering_P.Clamping_zero_Value_j !=
         FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) &&
        (FLIGHT_HEXA_Hovering_B.rtPrevAction == FLIGHT_HEXA_Hovering_B.i2_b)) {
      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Constant1_Value_k;
    }

    // Update for DiscreteIntegrator: '<S224>/Integrator' incorporates:
    //   Switch: '<S214>/Switch'

    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_ih +=
      FLIGHT_HEXA_Hovering_P.Integrator_gainval_f *
      FLIGHT_HEXA_Hovering_B.Switch3;

    // Update for DiscreteIntegrator: '<S219>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_f +=
      FLIGHT_HEXA_Hovering_P.Filter_gainval_l *
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2;
  }

  // End of Outputs for SubSystem: '<S4>/Attitude controller'

  // Gain: '<S5>/Gain'
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
    FLIGHT_HEXA_Hovering_P.Gain_Gain_d * FLIGHT_HEXA_Hovering_B.Saturation_a1;

  // Gain: '<S5>/Gain1'
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
    FLIGHT_HEXA_Hovering_P.Gain1_Gain_hr * FLIGHT_HEXA_Hovering_B.Saturation_b;

  // Gain: '<S5>/Gain2'
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
    FLIGHT_HEXA_Hovering_P.Gain2_Gain_i * FLIGHT_HEXA_Hovering_B.Saturation_n;

  // Gain: '<S5>/Gain3'
  FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 =
    FLIGHT_HEXA_Hovering_P.Gain3_Gain_e * FLIGHT_HEXA_Hovering_B.Switch2;

  // MATLABSystem: '<S7>/Read Parameter13'
  if (FLIGHT_HEXA_Hovering_DW.obj_bs.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_bs.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_bs.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // RelationalOperator: '<S13>/Compare' incorporates:
  //   Constant: '<S13>/Constant'

  FLIGHT_HEXA_Hovering_B.Compare = (FLIGHT_HEXA_Hovering_B.In1_a.values[7] >=
    FLIGHT_HEXA_Hovering_P.CompareToConstant_const_m);

  // Switch: '<S6>/Switch' incorporates:
  //   Constant: '<S6>/Constant'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S14>/Product'
  //   Saturate: '<S14>/Saturation'
  //   Switch: '<S7>/Switch'

  if (FLIGHT_HEXA_Hovering_B.Compare_b) {
    FLIGHT_HEXA_Hovering_B.Switch_fw = FLIGHT_HEXA_Hovering_P.Constant_Value_bv;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion3'
      //   MATLABSystem: '<S7>/Read Parameter13'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch' incorporates:
      //   Constant: '<S7>/Constant'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant_Value_jp;
    }

    // Gain: '<S14>/Gain' incorporates:
    //   Switch: '<S7>/Switch'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_o;

    // Saturate: '<S14>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_or) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_or;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_cq) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_cq;
    }

    FLIGHT_HEXA_Hovering_B.Switch_fw =
      ((-FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 -
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch'

  // MATLABSystem: '<S7>/Read Parameter1'
  if (FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch1' incorporates:
  //   Constant: '<S6>/Constant1'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S15>/Product'
  //   Saturate: '<S15>/Saturation'
  //   Switch: '<S7>/Switch1'

  if (FLIGHT_HEXA_Hovering_B.Compare_b) {
    FLIGHT_HEXA_Hovering_B.Subtract_f = FLIGHT_HEXA_Hovering_P.Constant1_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch1' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion2'
      //   MATLABSystem: '<S7>/Read Parameter1'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch1' incorporates:
      //   Constant: '<S7>/Constant1'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_f;
    }

    // Gain: '<S15>/Gain' incorporates:
    //   Switch: '<S7>/Switch1'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain;

    // Saturate: '<S15>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat;
    }

    FLIGHT_HEXA_Hovering_B.Subtract_f =
      ((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 +
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch1'

  // MATLABSystem: '<S7>/Read Parameter2'
  if (FLIGHT_HEXA_Hovering_DW.obj_gv.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_gv.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_gv.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch2' incorporates:
  //   Constant: '<S6>/Constant2'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S16>/Product'
  //   Saturate: '<S16>/Saturation'
  //   Switch: '<S7>/Switch2'

  if (FLIGHT_HEXA_Hovering_B.Compare_b) {
    FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_P.Constant2_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch2' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion'
      //   MATLABSystem: '<S7>/Read Parameter2'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch2' incorporates:
      //   Constant: '<S7>/Constant2'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant2_Value_l;
    }

    // Gain: '<S16>/Gain' incorporates:
    //   Switch: '<S7>/Switch2'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_e;

    // Saturate: '<S16>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_f) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_f;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_c) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_c;
    }

    FLIGHT_HEXA_Hovering_B.Switch2 =
      (((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0 +
         FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2) -
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch2'

  // MATLABSystem: '<S7>/Read Parameter3'
  if (FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_p.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter3_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_p.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch3' incorporates:
  //   Constant: '<S6>/Constant3'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S17>/Product'
  //   Saturate: '<S17>/Saturation'
  //   Switch: '<S7>/Switch3'

  if (FLIGHT_HEXA_Hovering_B.Compare_b) {
    FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_P.Constant3_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch3' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion4'
      //   MATLABSystem: '<S7>/Read Parameter3'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch3' incorporates:
      //   Constant: '<S7>/Constant3'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant3_Value_p;
    }

    // Gain: '<S17>/Gain' incorporates:
    //   Switch: '<S7>/Switch3'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_b;

    // Saturate: '<S17>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_o) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_o;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_cl) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_cl;
    }

    FLIGHT_HEXA_Hovering_B.Switch3 =
      (((-FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 -
         FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0) +
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch3'

  // MATLABSystem: '<S7>/Read Parameter4'
  if (FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_a.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch4' incorporates:
  //   Constant: '<S6>/Constant4'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S18>/Product'
  //   Saturate: '<S18>/Saturation'
  //   Switch: '<S7>/Switch4'

  if (FLIGHT_HEXA_Hovering_B.Compare_b) {
    FLIGHT_HEXA_Hovering_B.Switch4 = FLIGHT_HEXA_Hovering_P.Constant4_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch4' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion1'
      //   MATLABSystem: '<S7>/Read Parameter4'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch4' incorporates:
      //   Constant: '<S7>/Constant4'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant4_Value_j;
    }

    // Gain: '<S18>/Gain' incorporates:
    //   Switch: '<S7>/Switch4'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *=
      FLIGHT_HEXA_Hovering_P.Gain_Gain_el;

    // Saturate: '<S18>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_l) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_l;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_l) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_l;
    }

    FLIGHT_HEXA_Hovering_B.Switch4 =
      (((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 -
         FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0) +
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch4'

  // MATLABSystem: '<S7>/Read Parameter5'
  if (FLIGHT_HEXA_Hovering_DW.obj_f.SampleTime !=
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime) {
    FLIGHT_HEXA_Hovering_DW.obj_f.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime;
  }

  FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
    (FLIGHT_HEXA_Hovering_DW.obj_f.MW_PARAMHANDLE, MW_INT32,
     &FLIGHT_HEXA_Hovering_B.ParamStep_k);
  if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
    FLIGHT_HEXA_Hovering_B.ParamStep_k = 0;
  }

  // Switch: '<S6>/Switch5' incorporates:
  //   Constant: '<S6>/Constant5'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   Product: '<S19>/Product'
  //   Saturate: '<S19>/Saturation'
  //   Switch: '<S7>/Switch5'

  if (FLIGHT_HEXA_Hovering_B.Compare_b) {
    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      FLIGHT_HEXA_Hovering_P.Constant5_Value;
  } else {
    if (FLIGHT_HEXA_Hovering_B.Compare) {
      // Switch: '<S7>/Switch5' incorporates:
      //   DataTypeConversion: '<S7>/Data Type Conversion5'
      //   MATLABSystem: '<S7>/Read Parameter5'
      //
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_B.ParamStep_k;
    } else {
      // Switch: '<S7>/Switch5' incorporates:
      //   Constant: '<S7>/Constant5'

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Constant5_Value_m;
    }

    // Gain: '<S19>/Gain' incorporates:
    //   Switch: '<S7>/Switch5'

    FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 *= FLIGHT_HEXA_Hovering_P.Gain_Gain_a;

    // Saturate: '<S19>/Saturation'
    if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 >
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_k) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_UpperSat_k;
    } else if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 <
               FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_k) {
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
        FLIGHT_HEXA_Hovering_P.Saturation_LowerSat_k;
    }

    FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
      (((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 / 2.0 -
         FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2) -
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) *
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 / 3.0 +
       FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0) *
      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0;
  }

  // End of Switch: '<S6>/Switch5'

  // BusAssignment: '<S11>/Bus Assignment' incorporates:
  //   Constant: '<S23>/Constant'

  FLIGHT_HEXA_Hovering_B.BusAssignment = FLIGHT_HEXA_Hovering_P.Constant_Value_o;

  // BusAssignment: '<S11>/Bus Assignment' incorporates:
  //   Constant: '<S11>/Constant'
  //   DataTypeConversion: '<S11>/Data Type Conversion'

  FLIGHT_HEXA_Hovering_B.BusAssignment.control[0] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Switch_fw);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[1] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Subtract_f);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[2] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Switch2);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[3] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Switch3);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[4] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.Switch4);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[5] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[6] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_p);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[7] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_p);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[8] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_p);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[9] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_p);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[10] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_p);
  FLIGHT_HEXA_Hovering_B.BusAssignment.control[11] = static_cast<real32_T>
    (FLIGHT_HEXA_Hovering_P.Constant_Value_p);

  // MATLABSystem: '<S24>/SinkBlock' incorporates:
  //   BusAssignment: '<S11>/Bus Assignment'

  uORB_write_step(FLIGHT_HEXA_Hovering_DW.obj_c.orbMetadataObj,
                  &FLIGHT_HEXA_Hovering_DW.obj_c.orbAdvertiseObj,
                  &FLIGHT_HEXA_Hovering_B.BusAssignment);

  // Outputs for Enabled SubSystem: '<S39>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S56>/Enable'

  // Start for MATLABSystem: '<S39>/Read Parameter'
  if (FLIGHT_HEXA_Hovering_B.ParamStep_c > 0) {
    // BusAssignment: '<S56>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment'
    //   Constant: '<S66>/Constant'
    //   SignalConversion generated from: '<S62>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S62>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S62>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S62>/Data Type Conversion'
    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.alt;

    // SignalConversion generated from: '<S56>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[0] =
      FLIGHT_HEXA_Hovering_B.In1_f.lat;

    // SignalConversion generated from: '<S56>/Matrix Concatenate1'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[1] =
      FLIGHT_HEXA_Hovering_B.In1_f.lon;

    // DataTypeConversion: '<S56>/Data Type Conversion'
    FLIGHT_HEXA_Hovering_B.VectorConcatenate[2] =
      FLIGHT_HEXA_Hovering_B.In1_f.alt;
    FLIGHT_HEXA_Hovering_MATLABSystem(FLIGHT_HEXA_Hovering_B.DataTypeConversion2,
      FLIGHT_HEXA_Hovering_B.VectorConcatenate,
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid,
      FLIGHT_HEXA_Hovering_B.In1_p.current.type,
      &FLIGHT_HEXA_Hovering_B.MATLABSystem);

    // SignalConversion generated from: '<S68>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S62>/Bus Assignment1'
    //   MATLABSystem: '<S62>/MATLAB System'
    //   SignalConversion generated from: '<S62>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[0] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S68>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S62>/Bus Assignment1'
    //   MATLABSystem: '<S62>/MATLAB System'
    //   SignalConversion generated from: '<S62>/MATLAB System'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[1] =
      FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[1];

    // If: '<S68>/If' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S62>/Bus Assignment1'
    //   Constant: '<S70>/Constant'
    //   Constant: '<S70>/Constant1'
    //   Constant: '<S71>/Constant'
    //   Constant: '<S71>/Constant1'

    if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S68>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S71>/Action Port'

      // MATLABSystem: '<S71>/Read Parameter' incorporates:
      //   BusAssignment: '<S56>/Bus Assignment1'
      //   BusAssignment: '<S62>/Bus Assignment1'
      //   SignalConversion generated from: '<S71>/Read Parameter'

      if (FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime !=
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c) {
        FLIGHT_HEXA_Hovering_DW.obj_g.SampleTime =
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_c;
      }

      FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
        (FLIGHT_HEXA_Hovering_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2]);
      if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
        FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S71>/Read Parameter'
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_dr[0];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_dr[1];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S68>/If Action Subsystem2'
    } else if (FLIGHT_HEXA_Hovering_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S68>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S70>/Action Port'

      // MATLABSystem: '<S70>/Read Parameter'
      if (FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime !=
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g) {
        FLIGHT_HEXA_Hovering_DW.obj_b.SampleTime =
          FLIGHT_HEXA_Hovering_P.ReadParameter_SampleTime_g;
      }

      FLIGHT_HEXA_Hovering_B.b_varargout_1 = MW_Param_Step
        (FLIGHT_HEXA_Hovering_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &FLIGHT_HEXA_Hovering_B.ParamStep);
      if (FLIGHT_HEXA_Hovering_B.b_varargout_1) {
        FLIGHT_HEXA_Hovering_B.ParamStep = 0.0F;
      }

      // Gain: '<S70>/Gain' incorporates:
      //   BusAssignment: '<S56>/Bus Assignment1'
      //   BusAssignment: '<S62>/Bus Assignment1'
      //   MATLABSystem: '<S70>/Read Parameter'
      //
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        FLIGHT_HEXA_Hovering_P.Gain_Gain_h * FLIGHT_HEXA_Hovering_B.ParamStep;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[0];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_P.Constant1_Value_k4[1];
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S68>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S68>/If Action Subsystem' incorporates:
      //   ActionPort: '<S69>/Action Port'

      // SignalConversion generated from: '<S69>/In1' incorporates:
      //   BusAssignment: '<S56>/Bus Assignment1'
      //   BusAssignment: '<S62>/Bus Assignment1'
      //   MATLABSystem: '<S62>/MATLAB System'
      //   SignalConversion generated from: '<S62>/MATLAB System'

      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].position[2] =
        FLIGHT_HEXA_Hovering_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S62>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S56>/Bus Assignment1'
      //   SignalConversion generated from: '<S68>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S69>/In2'
      //
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[0] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vx;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[1] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vy;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[0].velocity[2] =
        FLIGHT_HEXA_Hovering_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S68>/If Action Subsystem'
    }

    // End of If: '<S68>/If'

    // BusAssignment: '<S62>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   Constant: '<S62>/Constant5'

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

    // BusAssignment: '<S56>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment'
    //   Constant: '<S66>/Constant'
    //   SignalConversion generated from: '<S63>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S63>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S62>/Matrix Concatenate1'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lat;

    // SignalConversion generated from: '<S63>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S62>/Matrix Concatenate1'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.lon;

    // DataTypeConversion: '<S63>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S62>/Data Type Conversion'

    FLIGHT_HEXA_Hovering_B.DataTypeConversion2[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.alt;
    FLIGHT_HEXA_Hovering_MATLABSystem(FLIGHT_HEXA_Hovering_B.DataTypeConversion2,
      FLIGHT_HEXA_Hovering_B.VectorConcatenate,
      FLIGHT_HEXA_Hovering_B.In1_p.current.valid,
      FLIGHT_HEXA_Hovering_B.In1_p.current.type,
      &FLIGHT_HEXA_Hovering_B.MATLABSystem_b);

    // SignalConversion generated from: '<S63>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S63>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vx;

    // SignalConversion generated from: '<S63>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S63>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vy;

    // SignalConversion generated from: '<S63>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S63>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[1].velocity[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.current.vz;

    // BusAssignment: '<S63>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S62>/Bus Assignment1'
    //   Constant: '<S63>/Constant5'
    //   MATLABSystem: '<S63>/MATLAB System'

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

    // BusAssignment: '<S56>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment'
    //   Constant: '<S66>/Constant'
    //   SignalConversion generated from: '<S65>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2] =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S65>/MATLAB System' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   DataTypeConversion: '<S56>/Data Type Conversion'
    //   DataTypeConversion: '<S65>/Data Type Conversion'
    //   SignalConversion generated from: '<S56>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S65>/Matrix Concatenate'
    //
    if (FLIGHT_HEXA_Hovering_B.In1_p.next.valid) {
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
        FLIGHT_HEXA_Hovering_B.In1_p.next.lat - FLIGHT_HEXA_Hovering_B.In1_f.lat;
      FLIGHT_HEXA_Hovering_B.Switch2 = FLIGHT_HEXA_Hovering_B.In1_p.next.lon -
        FLIGHT_HEXA_Hovering_B.In1_f.lon;
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = fabs
        (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3);
      if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 > 180.0) {
        if (rtIsNaN(FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0) ||
            rtIsInf(FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0)) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0 == 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0;
        } else {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = fmod
            (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0, 360.0);
          if (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 == 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0;
          } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 + 180.0 < 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 += 360.0;
          }
        }

        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 =
          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 * 0.0 +
          (FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 - 180.0);
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = fabs
          (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3);
      }

      if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 > 90.0) {
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = fabs
          (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3);
        FLIGHT_HEXA_Hovering_B.Compare_b =
          (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 > 90.0);
        FLIGHT_HEXA_Hovering_B.Switch2 += 180.0;
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 * static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.Compare_b);
        if (rtIsNaN(FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1)) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = (rtNaN);
        } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 < 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = -1.0;
        } else {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 =
            (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0);
        }

        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 = (90.0 -
          (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 * static_cast<real_T>
           (FLIGHT_HEXA_Hovering_B.Compare_b) - 90.0)) *
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 * static_cast<real_T>
          (FLIGHT_HEXA_Hovering_B.Compare_b) +
          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 * static_cast<real_T>
          (!FLIGHT_HEXA_Hovering_B.Compare_b);
      }

      if ((FLIGHT_HEXA_Hovering_B.Switch2 > 180.0) ||
          (FLIGHT_HEXA_Hovering_B.Switch2 < -180.0)) {
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 =
          FLIGHT_HEXA_Hovering_rt_remd_snf(FLIGHT_HEXA_Hovering_B.Switch2, 360.0);
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 / 180.0;
        if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 < 0.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = ceil
            (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
        } else {
          FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = floor
            (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
        }

        FLIGHT_HEXA_Hovering_B.Switch2 =
          (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 - 360.0 *
           FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0) +
          FLIGHT_HEXA_Hovering_B.Switch2 * 0.0;
      }

      FLIGHT_HEXA_Hovering_B.Switch3 = FLIGHT_HEXA_Hovering_sind_d
        (FLIGHT_HEXA_Hovering_B.In1_f.lat);
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 * FLIGHT_HEXA_Hovering_B.Switch3 *
        FLIGHT_HEXA_Hovering_B.Switch3);
      if (rtIsInf(FLIGHT_HEXA_Hovering_B.In1_f.lat) || rtIsNaN
          (FLIGHT_HEXA_Hovering_B.In1_f.lat)) {
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = (rtNaN);
      } else {
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
          FLIGHT_HEXA_Hovering_rt_remd_snf(FLIGHT_HEXA_Hovering_B.In1_f.lat,
          360.0);
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 = fabs
          (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
        if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 > 180.0) {
          if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 -= 360.0;
          } else {
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 += 360.0;
          }

          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 = fabs
            (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
        }

        if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 <= 45.0) {
          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = cos(0.017453292519943295 *
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
        } else if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_0 <= 135.0) {
          if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = -sin
              ((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 - 90.0) *
               0.017453292519943295);
          } else {
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = sin
              ((FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 + 90.0) *
               0.017453292519943295);
          }
        } else {
          if (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 > 0.0) {
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
              (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 - 180.0) *
              0.017453292519943295;
          } else {
            FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 =
              (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 + 180.0) *
              0.017453292519943295;
          }

          FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1 = -cos
            (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1);
        }
      }

      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3 /=
        FLIGHT_HEXA_Hovering_rt_atan2d_snf(1.0, 0.99330562000985867 / (1.0 -
        0.0066943799901413165 * FLIGHT_HEXA_Hovering_B.Switch3 *
        FLIGHT_HEXA_Hovering_B.Switch3) *
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2) * 57.295779513082323;
      FLIGHT_HEXA_Hovering_B.Switch2 /= FLIGHT_HEXA_Hovering_rt_atan2d_snf(1.0,
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 *
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_1) * 57.295779513082323;
      FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2 = -static_cast<real_T>
        (FLIGHT_HEXA_Hovering_B.In1_p.next.alt) +
        FLIGHT_HEXA_Hovering_B.In1_f.alt;
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[0] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3);
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[1] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.Switch2);
      FLIGHT_HEXA_Hovering_B.distinctWptsIdx[2] = rtIsNaN
        (FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2);
      FLIGHT_HEXA_Hovering_B.Compare_b = false;
      FLIGHT_HEXA_Hovering_B.i1 = 0;
      exitg1 = false;
      while ((!exitg1) && (FLIGHT_HEXA_Hovering_B.i1 < 3)) {
        if (FLIGHT_HEXA_Hovering_B.distinctWptsIdx[FLIGHT_HEXA_Hovering_B.i1]) {
          FLIGHT_HEXA_Hovering_B.Compare_b = true;
          exitg1 = true;
        } else {
          FLIGHT_HEXA_Hovering_B.i1++;
        }
      }

      FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 = 0.0 / static_cast<real_T>
        (!FLIGHT_HEXA_Hovering_B.Compare_b);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_3);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
        FLIGHT_HEXA_Hovering_B.Switch2);
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] =
        static_cast<real32_T>(FLIGHT_HEXA_Hovering_B.rtb_Merge_idx_0 +
        FLIGHT_HEXA_Hovering_B.rtb_Transpose_idx_2);
    } else {
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[0] = 0.0F;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[1] = 0.0F;
      FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S65>/MATLAB System'

    // SignalConversion generated from: '<S65>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S65>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[0] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vx;

    // SignalConversion generated from: '<S65>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S65>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[1] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vy;

    // SignalConversion generated from: '<S65>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   BusAssignment: '<S65>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[2].velocity[2] =
      FLIGHT_HEXA_Hovering_B.In1_p.next.vz;

    // BusAssignment: '<S65>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'
    //   Constant: '<S65>/Constant5'

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

    // SignalConversion generated from: '<S64>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment'
    //   BusAssignment: '<S64>/Bus Assignment1'
    //   Constant: '<S66>/Constant'

    FLIGHT_HEXA_Hovering_B.BusAssignment1_f =
      FLIGHT_HEXA_Hovering_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S64>/Bus Assignment1' incorporates:
    //   Constant: '<S64>/Constant'
    //   Constant: '<S64>/Constant1'
    //   Constant: '<S64>/Constant2'
    //   Constant: '<S64>/Constant3'
    //   Constant: '<S64>/Constant4'
    //   Constant: '<S64>/Constant5'
    //   Constant: '<S64>/Constant6'
    //   Constant: '<S64>/Constant7'

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

    // BusAssignment: '<S56>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment'
    //   Constant: '<S56>/Constant'
    //   Constant: '<S66>/Constant'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.timestamp =
      FLIGHT_HEXA_Hovering_B.In1_p.timestamp;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.type =
      FLIGHT_HEXA_Hovering_P.Constant_Value_fm;
    for (FLIGHT_HEXA_Hovering_B.j = 0; FLIGHT_HEXA_Hovering_B.j < 7;
         FLIGHT_HEXA_Hovering_B.j++) {
      FLIGHT_HEXA_Hovering_B.BusAssignment1._padding0[FLIGHT_HEXA_Hovering_B.j] =
        FLIGHT_HEXA_Hovering_P.Constant_Value._padding0[FLIGHT_HEXA_Hovering_B.j];
    }

    // BusAssignment: '<S56>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S64>/Bus Assignment1'
    //   Concatenate: '<S56>/Matrix Concatenate'

    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[3] =
      FLIGHT_HEXA_Hovering_B.BusAssignment1_f;
    FLIGHT_HEXA_Hovering_B.BusAssignment1.waypoints[4] =
      FLIGHT_HEXA_Hovering_B.BusAssignment1_f;

    // MATLABSystem: '<S67>/SinkBlock' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'

    uORB_write_step(FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                    &FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                    &FLIGHT_HEXA_Hovering_B.BusAssignment1);
  }

  // End of Outputs for SubSystem: '<S39>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_SourceBlock(&FLIGHT_HEXA_Hovering_B.SourceBlock,
    &FLIGHT_HEXA_Hovering_DW.SourceBlock);

  // MATLABSystem: '<S55>/PX4 Timestamp'
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

    // Start for If: '<S38>/If'
    FLIGHT_HEXA_Hovering_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
    //   Outport: '<S22>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_a = FLIGHT_HEXA_Hovering_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S28>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S34>/In1' incorporates:
    //   Outport: '<S34>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_m = FLIGHT_HEXA_Hovering_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S28>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S30>/In1' incorporates:
    //   Outport: '<S30>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_l = FLIGHT_HEXA_Hovering_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S31>/In1' incorporates:
    //   Outport: '<S31>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_b = FLIGHT_HEXA_Hovering_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S33>/In1' incorporates:
    //   Outport: '<S33>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_j = FLIGHT_HEXA_Hovering_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S29>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S35>/In1' incorporates:
    //   Outport: '<S35>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_c = FLIGHT_HEXA_Hovering_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S29>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S60>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S61>/In1' incorporates:
    //   Outport: '<S61>/Out1'

    FLIGHT_HEXA_Hovering_B.In1 = FLIGHT_HEXA_Hovering_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S60>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S58>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S73>/In1' incorporates:
    //   Outport: '<S73>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_p = FLIGHT_HEXA_Hovering_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S58>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S57>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S72>/In1' incorporates:
    //   Outport: '<S72>/Out1'

    FLIGHT_HEXA_Hovering_B.In1_f = FLIGHT_HEXA_Hovering_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S57>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S38>/Take-off'
    // InitializeConditions for Delay: '<S50>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_c =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S51>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_d =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S51>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S52>/yaw_In' incorporates:
    //   Outport: '<S52>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In_ik = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S51>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S38>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S38>/Land'
    // InitializeConditions for Delay: '<S41>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[0] =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_l[1] =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_n;

    // InitializeConditions for Gain: '<S46>/Gain1' incorporates:
    //   Delay: '<S46>/Delay'

    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_n =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S47>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE_b =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S47>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S49>/yaw_In' incorporates:
    //   Outport: '<S49>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In_i = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S47>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S46>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S48>/In' incorporates:
    //   Outport: '<S48>/Out'

    FLIGHT_HEXA_Hovering_B.In = FLIGHT_HEXA_Hovering_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S46>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S38>/Land'

    // SystemInitialize for IfAction SubSystem: '<S38>/Waypoint'
    // Start for MATLABSystem: '<S43>/UAV Waypoint Follower'
    FLIGHT_HEXA_Hovering_DW.obj.LastWaypointFlag = false;
    FLIGHT_HEXA_Hovering_DW.obj.StartFlag = true;
    FLIGHT_HEXA_Hovering_DW.obj.LookaheadFactor = 1.01;
    FLIGHT_HEXA_Hovering_DW.obj.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S43>/UAV Waypoint Follower'
    FLIGHT_HEXA_Hovering_DW.obj.WaypointIndex = 1.0;
    memset(&FLIGHT_HEXA_Hovering_DW.obj.WaypointsInternal[0], 0, 9U * sizeof
           (real_T));

    // End of SystemInitialize for SubSystem: '<S38>/Waypoint'

    // SystemInitialize for IfAction SubSystem: '<S38>/IDLE'
    // InitializeConditions for Delay: '<S44>/Delay'
    FLIGHT_HEXA_Hovering_DW.Delay_DSTATE =
      FLIGHT_HEXA_Hovering_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S44>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S45>/yaw_In' incorporates:
    //   Outport: '<S45>/yaw_Out'

    FLIGHT_HEXA_Hovering_B.yaw_In = FLIGHT_HEXA_Hovering_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S44>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S38>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S4>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S530>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S535>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE =
      FLIGHT_HEXA_Hovering_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S582>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_o =
      FLIGHT_HEXA_Hovering_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S587>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_o =
      FLIGHT_HEXA_Hovering_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Gain: '<S77>/Gain1' incorporates:
    //   Outport: '<S77>/des_pitch'

    FLIGHT_HEXA_Hovering_B.Gain1 = FLIGHT_HEXA_Hovering_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S77>/des_roll' incorporates:
    //   Saturate: '<S390>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation[1] = FLIGHT_HEXA_Hovering_P.des_roll_Y0;

    // SystemInitialize for Gain: '<S488>/Proportional Gain' incorporates:
    //   Outport: '<S77>/des_yawrate'
    //   Saturate: '<S490>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation_a = FLIGHT_HEXA_Hovering_P.des_yawrate_Y0;

    // SystemInitialize for Sum: '<S596>/Sum' incorporates:
    //   Outport: '<S77>/tau_Thrust'
    //   Saturate: '<S594>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation_o = FLIGHT_HEXA_Hovering_P.tau_Thrust_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S4>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S120>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_i =
      FLIGHT_HEXA_Hovering_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S115>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_ov =
      FLIGHT_HEXA_Hovering_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S74>/Rate Limiter2'
    FLIGHT_HEXA_Hovering_DW.PrevY = FLIGHT_HEXA_Hovering_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S172>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_h =
      FLIGHT_HEXA_Hovering_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S167>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_c =
      FLIGHT_HEXA_Hovering_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S74>/Rate Limiter1'
    FLIGHT_HEXA_Hovering_DW.PrevY_m = FLIGHT_HEXA_Hovering_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S224>/Integrator'
    FLIGHT_HEXA_Hovering_DW.Integrator_DSTATE_ih =
      FLIGHT_HEXA_Hovering_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S219>/Filter'
    FLIGHT_HEXA_Hovering_DW.Filter_DSTATE_f =
      FLIGHT_HEXA_Hovering_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S127>/Saturation' incorporates:
    //   Outport: '<S74>/tau_Yaw'

    FLIGHT_HEXA_Hovering_B.Saturation_n = FLIGHT_HEXA_Hovering_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S179>/Saturation' incorporates:
    //   Outport: '<S74>/tau_Pitch'

    FLIGHT_HEXA_Hovering_B.Saturation_b = FLIGHT_HEXA_Hovering_P.tau_Pitch_Y0;

    // SystemInitialize for Sum: '<S233>/Sum' incorporates:
    //   Outport: '<S74>/tau_Roll'
    //   Saturate: '<S231>/Saturation'

    FLIGHT_HEXA_Hovering_B.Saturation_a1 = FLIGHT_HEXA_Hovering_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S39>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S68>/If Action Subsystem2'
    // Start for MATLABSystem: '<S71>/Read Parameter'
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

    // End of Start for MATLABSystem: '<S71>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S68>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S68>/If Action Subsystem1'
    // Start for MATLABSystem: '<S70>/Read Parameter'
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
      (&ParameterNameStr_7[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S70>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S68>/If Action Subsystem1'
    FLIGHT_HEXA_Hovering_MATLABSystem_Init(&FLIGHT_HEXA_Hovering_DW.MATLABSystem);
    FLIGHT_HEXA_Hovering_MATLABSystem_Init
      (&FLIGHT_HEXA_Hovering_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S65>/MATLAB System'
    FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S67>/SinkBlock' incorporates:
    //   BusAssignment: '<S56>/Bus Assignment1'

    FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mc.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize(FLIGHT_HEXA_Hovering_DW.obj_mc.orbMetadataObj,
                          &FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj,
                          &FLIGHT_HEXA_Hovering_B.BusAssignment1, 1);
    FLIGHT_HEXA_Hovering_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S39>/Send waypoints to OBC'
    FLIGHT_HEXA_Hovering_SourceBlock_n_Init
      (&FLIGHT_HEXA_Hovering_DW.SourceBlock_d);

    // Start for MATLABSystem: '<S28>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_gvl.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gvl.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_gvl.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_gvl.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_gvl.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_gvl.isSetupComplete = true;

    // Start for MATLABSystem: '<S25>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_po.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_po.orbMetadataObj = ORB_ID
      (vehicle_angular_velocity);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_po.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_po.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_po.isSetupComplete = true;
    FLIGHT_HEXA_Hovering_SourceBlock_Init(&FLIGHT_HEXA_Hovering_DW.SourceBlock_l);
    FLIGHT_HEXA_Hovering_SourceBlock_n_Init
      (&FLIGHT_HEXA_Hovering_DW.SourceBlock_b);

    // Start for MATLABSystem: '<S29>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_m.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_m.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_m.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_m.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S39>/Read Parameter'
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

    // End of Start for MATLABSystem: '<S39>/Read Parameter'

    // Start for MATLABSystem: '<S60>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_e.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_e.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S58>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_kz.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_kz.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S57>/SourceBlock'
    FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gf.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(FLIGHT_HEXA_Hovering_DW.obj_gf.orbMetadataObj,
                         &FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj);
    FLIGHT_HEXA_Hovering_DW.obj_gf.isSetupComplete = true;

    // Start for MATLABSystem: '<S39>/LLA2LocalCoordinates'
    FLIGHT_HEXA_Hovering_DW.obj_mr.previousValidReceived = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.nextValidReceived = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_mr.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S7>/Read Parameter13'
    FLIGHT_HEXA_Hovering_DW.obj_bs.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_bs.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter13_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_bs.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_bs.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_bs.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_bs.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_bs.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter13'

    // Start for MATLABSystem: '<S7>/Read Parameter1'
    FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter1_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_d.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_d.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter1'

    // Start for MATLABSystem: '<S7>/Read Parameter2'
    FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_gv.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter2_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_gv.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_gv.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_gv.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_gv.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_gv.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/Read Parameter3'
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
      (&ParameterNameStr_3[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter3'

    // Start for MATLABSystem: '<S7>/Read Parameter4'
    FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter4_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_a.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_a.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter4'

    // Start for MATLABSystem: '<S7>/Read Parameter5'
    FLIGHT_HEXA_Hovering_DW.obj_f.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_f.SampleTime =
      FLIGHT_HEXA_Hovering_P.ReadParameter5_SampleTime;
    FLIGHT_HEXA_Hovering_DW.obj_f.isInitialized = 1;
    if (FLIGHT_HEXA_Hovering_DW.obj_f.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = FLIGHT_HEXA_Hovering_DW.obj_f.SampleTime;
    }

    FLIGHT_HEXA_Hovering_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, tmp * 1000.0);
    FLIGHT_HEXA_Hovering_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/Read Parameter5'

    // Start for MATLABSystem: '<S24>/SinkBlock' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment'

    FLIGHT_HEXA_Hovering_DW.obj_c.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_c.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_c.orbMetadataObj = ORB_ID(actuator_motors);
    uORB_write_initialize(FLIGHT_HEXA_Hovering_DW.obj_c.orbMetadataObj,
                          &FLIGHT_HEXA_Hovering_DW.obj_c.orbAdvertiseObj,
                          &FLIGHT_HEXA_Hovering_B.BusAssignment, 1);
    FLIGHT_HEXA_Hovering_DW.obj_c.isSetupComplete = true;
    FLIGHT_HEXA_Hovering_SourceBlock_Init(&FLIGHT_HEXA_Hovering_DW.SourceBlock);

    // Start for MATLABSystem: '<S55>/PX4 Timestamp'
    FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = false;
    FLIGHT_HEXA_Hovering_DW.obj_n.isInitialized = 1;
    FLIGHT_HEXA_Hovering_DW.obj_n.isSetupComplete = true;
  }
}

// Model terminate function
void FLIGHT_HEXA_Hovering_terminate(void)
{
  FLIGHT_HEXA_Hovering_SourceBlock_a_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_d);

  // Terminate for MATLABSystem: '<S28>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gvl.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gvl.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_gvl.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_gvl.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_gvl.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S28>/SourceBlock'

  // Terminate for MATLABSystem: '<S25>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_po.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_po.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S25>/SourceBlock'
  FLIGHT_HEXA_Hovering_SourceBlock_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_l);
  FLIGHT_HEXA_Hovering_SourceBlock_a_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock_b);

  // Terminate for MATLABSystem: '<S29>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_m.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S29>/SourceBlock'

  // Terminate for MATLABSystem: '<S39>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S39>/Read Parameter'

  // Terminate for MATLABSystem: '<S60>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_e.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S60>/SourceBlock'

  // Terminate for MATLABSystem: '<S58>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_kz.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S58>/SourceBlock'

  // Terminate for MATLABSystem: '<S57>/SourceBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_gf.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate(&FLIGHT_HEXA_Hovering_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S57>/SourceBlock'

  // Terminate for MATLABSystem: '<S39>/LLA2LocalCoordinates'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S39>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S7>/Read Parameter13'
  if (!FLIGHT_HEXA_Hovering_DW.obj_bs.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_bs.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter13'

  // Terminate for MATLABSystem: '<S7>/Read Parameter1'
  if (!FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter1'

  // Terminate for MATLABSystem: '<S7>/Read Parameter2'
  if (!FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_gv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/Read Parameter3'
  if (!FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter3'

  // Terminate for MATLABSystem: '<S7>/Read Parameter4'
  if (!FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter4'

  // Terminate for MATLABSystem: '<S7>/Read Parameter5'
  if (!FLIGHT_HEXA_Hovering_DW.obj_f.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/Read Parameter5'

  // Terminate for MATLABSystem: '<S24>/SinkBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_c.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_c.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_c.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_HEXA_Hovering_DW.obj_c.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S24>/SinkBlock'

  // Terminate for Enabled SubSystem: '<S39>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_MATLABSystem_Term(&FLIGHT_HEXA_Hovering_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S68>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S71>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S71>/Read Parameter'
  // End of Terminate for SubSystem: '<S68>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S68>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S70>/Read Parameter'
  if (!FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/Read Parameter'
  // End of Terminate for SubSystem: '<S68>/If Action Subsystem1'
  FLIGHT_HEXA_Hovering_MATLABSystem_Term(&FLIGHT_HEXA_Hovering_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S65>/MATLAB System'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S65>/MATLAB System'

  // Terminate for MATLABSystem: '<S67>/SinkBlock'
  if (!FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((FLIGHT_HEXA_Hovering_DW.obj_mc.isInitialized == 1) &&
        FLIGHT_HEXA_Hovering_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate(&FLIGHT_HEXA_Hovering_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S67>/SinkBlock'
  // End of Terminate for SubSystem: '<S39>/Send waypoints to OBC'
  FLIGHT_HEXA_Hovering_SourceBlock_Term(&FLIGHT_HEXA_Hovering_DW.SourceBlock);

  // Terminate for MATLABSystem: '<S55>/PX4 Timestamp'
  if (!FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted) {
    FLIGHT_HEXA_Hovering_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
