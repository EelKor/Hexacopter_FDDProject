//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: QP_CA_Codegen.cpp
//
// Code generated for Simulink model 'QP_CA_Codegen'.
//
// Model version                  : 1.5
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri Dec 27 13:44:10 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "QP_CA_Codegen.h"
#include "rtwtypes.h"
#include <cstring>
#include <cmath>
#include "cmath"
#include "limits"

// Constant parameters (default storage)
const QP_CA_Codegen::ConstP rtConstP{
  // Expression: [1 1 1 1 1 1; 0.275 -0.275 0.1375 -0.1375 -0.1375 0.1375; 0 0 0.2382 -0.2382 0.2382 -0.2382; -0.1 0.1 -0.1 0.1 -0.1 0.1]
  //  Referenced by: '<Root>/Constant1'

  { 1.0, 0.275, 0.0, -0.1, 1.0, -0.275, 0.0, 0.1, 1.0, 0.1375, 0.2382, -0.1, 1.0,
    -0.1375, -0.2382, 0.1, 1.0, -0.1375, 0.2382, -0.1, 1.0, 0.1375, -0.2382, 0.1
  }
};

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern "C"
{
  real_T rtNaN { -std::numeric_limits<real_T>::quiet_NaN() };

  real_T rtInf { std::numeric_limits<real_T>::infinity() };

  real_T rtMinusInf { -std::numeric_limits<real_T>::infinity() };

  real32_T rtNaNF { -std::numeric_limits<real32_T>::quiet_NaN() };

  real32_T rtInfF { std::numeric_limits<real32_T>::infinity() };

  real32_T rtMinusInfF { -std::numeric_limits<real32_T>::infinity() };
}

extern "C"
{
  // Return rtInf needed by the generated code.
  static real_T rtGetInf(void)
  {
    return rtInf;
  }

  // Get rtInfF needed by the generated code.
  static real32_T rtGetInfF(void)
  {
    return rtInfF;
  }

  // Return rtMinusInf needed by the generated code.
  static real_T rtGetMinusInf(void)
  {
    return rtMinusInf;
  }

  // Return rtMinusInfF needed by the generated code.
  static real32_T rtGetMinusInfF(void)
  {
    return rtMinusInfF;
  }
}

extern "C"
{
  // Return rtNaN needed by the generated code.
  static real_T rtGetNaN(void)
  {
    return rtNaN;
  }

  // Return rtNaNF needed by the generated code.
  static real32_T rtGetNaNF(void)
  {
    return rtNaNF;
  }
}

extern "C"
{
  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return std::isinf(value);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return std::isinf(value);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    return std::isnan(value);
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    return std::isnan(value);
  }
}

static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::loadProblem(sAjQtoJYLWYGAxqZWOtnxYE *obj, const real_T Aeq
  [24], const real_T beq[4], int32_T mLB, int32_T mUB, const real_T ub[6],
  int32_T mFixed)
{
  int32_T idx_row;
  int32_T k;
  k = ((mLB + mUB) + mFixed) + 4;
  obj->mConstr = k;
  obj->mConstrOrig = k;
  obj->mConstrMax = 17;
  obj->sizes[0] = mFixed;
  obj->sizes[1] = 4;
  obj->sizes[2] = 0;
  obj->sizes[3] = mLB;
  obj->sizes[4] = mUB;
  for (k = 0; k < 5; k++) {
    obj->sizesNormal[k] = obj->sizes[k];
  }

  obj->sizesPhaseOne[0] = mFixed;
  obj->sizesPhaseOne[1] = 4;
  obj->sizesPhaseOne[2] = 0;
  obj->sizesPhaseOne[3] = mLB + 1;
  obj->sizesPhaseOne[4] = mUB;
  obj->sizesRegularized[0] = mFixed;
  obj->sizesRegularized[1] = 4;
  obj->sizesRegularized[2] = 0;
  obj->sizesRegularized[3] = mLB + 8;
  obj->sizesRegularized[4] = mUB;
  obj->sizesRegPhaseOne[0] = mFixed;
  obj->sizesRegPhaseOne[1] = 4;
  obj->sizesRegPhaseOne[2] = 0;
  obj->sizesRegPhaseOne[3] = mLB + 9;
  obj->sizesRegPhaseOne[4] = mUB;
  obj->isActiveIdxNormal[0] = 1;
  obj->isActiveIdxNormal[1] = mFixed;
  obj->isActiveIdxNormal[2] = 4;
  obj->isActiveIdxNormal[3] = 0;
  obj->isActiveIdxNormal[4] = mLB;
  obj->isActiveIdxNormal[5] = mUB;
  for (k = 0; k < 6; k++) {
    obj->isActiveIdxRegPhaseOne[k] = obj->isActiveIdxNormal[k];
  }

  for (k = 0; k < 5; k++) {
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 6; k++) {
    obj->isActiveIdx[k] = obj->isActiveIdxRegPhaseOne[k];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 4;
  obj->isActiveIdxRegPhaseOne[3] = 0;
  obj->isActiveIdxRegPhaseOne[4] = mLB + 1;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj->isActiveIdxNormal[k + 1] += obj->isActiveIdxNormal[k];
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 6; k++) {
    obj->isActiveIdxPhaseOne[k] = obj->isActiveIdxRegPhaseOne[k];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 4;
  obj->isActiveIdxRegPhaseOne[3] = 0;
  obj->isActiveIdxRegPhaseOne[4] = mLB + 8;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 6; k++) {
    obj->isActiveIdxRegularized[k] = obj->isActiveIdxRegPhaseOne[k];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 4;
  obj->isActiveIdxRegPhaseOne[3] = 0;
  obj->isActiveIdxRegPhaseOne[4] = mLB + 9;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 4; k++) {
    int32_T b;
    b = obj->nVar;
    for (idx_row = 0; idx_row < b; idx_row++) {
      obj->Aeq[idx_row + obj->ldA * k] = Aeq[(idx_row << 2) + k];
    }
  }

  obj->beq[0] = beq[0];
  obj->beq[1] = beq[1];
  obj->beq[2] = beq[2];
  obj->beq[3] = beq[3];
  idx_row = obj->nVar;
  for (k = 0; k < idx_row; k++) {
    obj->lb[k] = -0.0;
    obj->ub[k] = ub[k];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::modifyOverheadPhaseOne_(sAjQtoJYLWYGAxqZWOtnxYE *obj)
{
  int32_T idxEq;
  int32_T idxStartIneq;
  idxStartIneq = obj->sizes[0];
  for (int32_T idx{0}; idx < idxStartIneq; idx++) {
    obj->ATwset[(obj->nVar + obj->ldA * idx) - 1] = 0.0;
  }

  idxStartIneq = obj->sizes[1];
  for (int32_T idx{0}; idx < idxStartIneq; idx++) {
    idxEq = (obj->ldA * idx + obj->nVar) - 1;
    obj->Aeq[idxEq] = 0.0;
    obj->ATwset[idxEq + obj->ldA * (obj->isActiveIdx[1] - 1)] = 0.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[obj->nVar - 1] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  idxEq = obj->nActiveConstr;
  for (int32_T idx{idxStartIneq}; idx <= idxEq; idx++) {
    obj->ATwset[(obj->nVar + obj->ldA * (idx - 1)) - 1] = -1.0;
  }

  idxStartIneq = obj->isActiveIdx[4] - 1;
  if (obj->nWConstr[4] > 0) {
    idxEq = obj->sizesNormal[4] - 1;
    for (int32_T idx{idxEq}; idx >= 0; idx--) {
      int32_T tmp;
      tmp = idxStartIneq + idx;
      obj->isActiveConstr[tmp] = obj->isActiveConstr[tmp - 1];
    }
  } else {
    obj->isActiveConstr[(obj->isActiveIdx[4] + obj->sizesNormal[4]) - 1] = false;
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::setProblemType(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T
  PROBLEM_TYPE)
{
  int32_T b_idx_col;
  int32_T idxUpperExisting;
  int32_T mEq;
  int32_T mIneq;
  int32_T offsetEq1_tmp;
  int32_T offsetEq2;
  int32_T offsetIneq;
  int32_T offsetIneq_tmp;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = obj->nVarOrig;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      idxUpperExisting = obj->isActiveIdx[4] - 2;
      mEq = obj->sizesNormal[4];
      for (offsetIneq = 0; offsetIneq < mEq; offsetIneq++) {
        mIneq = (offsetIneq + idxUpperExisting) + 1;
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + offsetIneq) - 1] =
          obj->isActiveConstr[mIneq];
        obj->isActiveConstr[mIneq] = false;
      }
    }

    for (mIneq = 0; mIneq < 5; mIneq++) {
      obj->sizes[mIneq] = obj->sizesNormal[mIneq];
    }

    for (mIneq = 0; mIneq < 6; mIneq++) {
      obj->isActiveIdx[mIneq] = obj->isActiveIdxNormal[mIneq];
    }
    break;

   case 1:
    obj->nVar = obj->nVarOrig + 1;
    obj->mConstr = obj->mConstrOrig + 1;
    for (mIneq = 0; mIneq < 5; mIneq++) {
      obj->sizes[mIneq] = obj->sizesPhaseOne[mIneq];
    }

    modifyOverheadPhaseOne_(obj);
    for (mIneq = 0; mIneq < 6; mIneq++) {
      obj->isActiveIdx[mIneq] = obj->isActiveIdxPhaseOne[mIneq];
    }
    break;

   case 2:
    obj->nVar = obj->nVarMax - 1;
    obj->mConstr = obj->mConstrMax - 1;
    for (mIneq = 0; mIneq < 5; mIneq++) {
      obj->sizes[mIneq] = obj->sizesRegularized[mIneq];
    }

    if (obj->probType != 4) {
      mEq = obj->sizes[1];
      offsetIneq_tmp = obj->nVarOrig + 1;
      offsetEq1_tmp = obj->nVarOrig + obj->sizes[2];
      offsetEq2 = offsetEq1_tmp + obj->sizes[1];
      mIneq = obj->sizes[0];
      for (b_idx_col = 0; b_idx_col < mIneq; b_idx_col++) {
        idxUpperExisting = obj->ldA * b_idx_col;
        if (offsetIneq_tmp <= obj->nVar) {
          std::memset(&obj->ATwset[(offsetIneq_tmp + idxUpperExisting) + -1], 0,
                      static_cast<uint32_T>((((obj->nVar + idxUpperExisting) -
            offsetIneq_tmp) - idxUpperExisting) + 1) * sizeof(real_T));
        }
      }

      for (mIneq = 0; mIneq < mEq; mIneq++) {
        offsetIneq = mIneq * obj->ldA - 1;
        idxUpperExisting = (obj->isActiveIdx[1] - 1) * obj->ldA + offsetIneq;
        if (offsetIneq_tmp <= offsetEq1_tmp) {
          std::memset(&obj->Aeq[offsetIneq_tmp + offsetIneq], 0,
                      static_cast<uint32_T>((((offsetEq1_tmp + offsetIneq) -
            offsetIneq_tmp) - offsetIneq) + 1) * sizeof(real_T));
        }

        if (offsetIneq_tmp <= offsetEq1_tmp) {
          std::memset(&obj->ATwset[offsetIneq_tmp + idxUpperExisting], 0,
                      static_cast<uint32_T>((((offsetEq1_tmp + idxUpperExisting)
            - offsetIneq_tmp) - idxUpperExisting) + 1) * sizeof(real_T));
        }

        b_idx_col = mIneq + offsetEq1_tmp;
        if (offsetEq1_tmp + 1 <= b_idx_col) {
          std::memset(&obj->Aeq[(offsetEq1_tmp + offsetIneq) + 1], 0,
                      static_cast<uint32_T>(((b_idx_col + offsetIneq) -
            offsetEq1_tmp) - offsetIneq) * sizeof(real_T));
        }

        if (offsetEq1_tmp + 1 <= b_idx_col) {
          std::memset(&obj->ATwset[(offsetEq1_tmp + idxUpperExisting) + 1], 0,
                      static_cast<uint32_T>(((b_idx_col + idxUpperExisting) -
            offsetEq1_tmp) - idxUpperExisting) * sizeof(real_T));
        }

        obj->Aeq[(b_idx_col + offsetIneq) + 1] = -1.0;
        obj->ATwset[(b_idx_col + idxUpperExisting) + 1] = -1.0;
        if (b_idx_col + 2 <= offsetEq2) {
          std::memset(&obj->Aeq[(b_idx_col + 2) + offsetIneq], 0, static_cast<
                      uint32_T>((((offsetEq2 + offsetIneq) - (b_idx_col + 2)) -
            offsetIneq) + 1) * sizeof(real_T));
        }

        if (b_idx_col + 2 <= offsetEq2) {
          std::memset(&obj->ATwset[(b_idx_col + 2) + idxUpperExisting], 0,
                      static_cast<uint32_T>((((offsetEq2 + idxUpperExisting) -
            (b_idx_col + 2)) - idxUpperExisting) + 1) * sizeof(real_T));
        }

        b_idx_col = mIneq + offsetEq2;
        if (offsetEq2 + 1 <= b_idx_col) {
          std::memset(&obj->Aeq[(offsetEq2 + offsetIneq) + 1], 0,
                      static_cast<uint32_T>(((b_idx_col + offsetIneq) -
            offsetEq2) - offsetIneq) * sizeof(real_T));
        }

        if (offsetEq2 + 1 <= b_idx_col) {
          std::memset(&obj->ATwset[(offsetEq2 + idxUpperExisting) + 1], 0,
                      static_cast<uint32_T>(((b_idx_col + idxUpperExisting) -
            offsetEq2) - idxUpperExisting) * sizeof(real_T));
        }

        obj->Aeq[(b_idx_col + offsetIneq) + 1] = 1.0;
        obj->ATwset[(b_idx_col + idxUpperExisting) + 1] = 1.0;
        if (b_idx_col + 2 <= obj->nVar) {
          std::memset(&obj->Aeq[(b_idx_col + 2) + offsetIneq], 0, static_cast<
                      uint32_T>((((obj->nVar + offsetIneq) - (b_idx_col + 2)) -
            offsetIneq) + 1) * sizeof(real_T));
        }

        if (b_idx_col + 2 <= obj->nVar) {
          std::memset(&obj->ATwset[(b_idx_col + 2) + idxUpperExisting], 0,
                      static_cast<uint32_T>((((obj->nVar + idxUpperExisting) -
            (b_idx_col + 2)) - idxUpperExisting) + 1) * sizeof(real_T));
        }
      }

      mEq = obj->nVarOrig;
      mIneq = obj->sizesNormal[3] + 1;
      offsetEq2 = obj->sizesRegularized[3];
      for (idxUpperExisting = mIneq; idxUpperExisting <= offsetEq2;
           idxUpperExisting++) {
        mEq++;
        obj->indexLB[idxUpperExisting - 1] = mEq;
      }

      if (obj->nWConstr[4] > 0) {
        mEq = obj->sizesRegularized[4];
        for (idxUpperExisting = 0; idxUpperExisting < mEq; idxUpperExisting++) {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + idxUpperExisting]
            = obj->isActiveConstr[(obj->isActiveIdx[4] + idxUpperExisting) - 1];
        }
      }

      mEq = obj->isActiveIdx[4];
      mIneq = obj->isActiveIdxRegularized[4] - 1;
      if (mEq <= mIneq) {
        std::memset(&obj->isActiveConstr[mEq + -1], 0, static_cast<uint32_T>
                    ((mIneq - mEq) + 1) * sizeof(boolean_T));
      }

      mIneq = (obj->sizes[1] << 1) + offsetEq1_tmp;
      if (obj->nVarOrig + 1 <= mIneq) {
        std::memset(&obj->lb[(obj->nVarOrig + 1) + -1], 0, static_cast<uint32_T>
                    ((mIneq - (obj->nVarOrig + 1)) + 1) * sizeof(real_T));
      }

      mIneq = obj->isActiveIdx[2];
      offsetEq2 = obj->nActiveConstr;
      for (mEq = mIneq; mEq <= offsetEq2; mEq++) {
        idxUpperExisting = (mEq - 1) * obj->ldA - 1;
        if (obj->Wid[mEq - 1] == 3) {
          offsetEq1_tmp = obj->Wlocalidx[mEq - 1] + offsetIneq_tmp;
          if (offsetIneq_tmp <= offsetEq1_tmp - 2) {
            std::memset(&obj->ATwset[offsetIneq_tmp + idxUpperExisting], 0,
                        static_cast<uint32_T>(((((offsetEq1_tmp - 2) +
              idxUpperExisting) - offsetIneq_tmp) - idxUpperExisting) + 1) *
                        sizeof(real_T));
          }

          obj->ATwset[(offsetEq1_tmp + idxUpperExisting) - 1] = -1.0;
          if (offsetEq1_tmp <= obj->nVar) {
            std::memset(&obj->ATwset[offsetEq1_tmp + idxUpperExisting], 0,
                        static_cast<uint32_T>((((obj->nVar + idxUpperExisting) -
              offsetEq1_tmp) - idxUpperExisting) + 1) * sizeof(real_T));
          }
        } else if (offsetIneq_tmp <= obj->nVar) {
          std::memset(&obj->ATwset[offsetIneq_tmp + idxUpperExisting], 0,
                      static_cast<uint32_T>((((obj->nVar + idxUpperExisting) -
            offsetIneq_tmp) - idxUpperExisting) + 1) * sizeof(real_T));
        }
      }
    }

    for (mIneq = 0; mIneq < 6; mIneq++) {
      obj->isActiveIdx[mIneq] = obj->isActiveIdxRegularized[mIneq];
    }
    break;

   default:
    obj->nVar = obj->nVarMax;
    obj->mConstr = obj->mConstrMax;
    for (mIneq = 0; mIneq < 5; mIneq++) {
      obj->sizes[mIneq] = obj->sizesRegPhaseOne[mIneq];
    }

    modifyOverheadPhaseOne_(obj);
    for (mIneq = 0; mIneq < 6; mIneq++) {
      obj->isActiveIdx[mIneq] = obj->isActiveIdxRegPhaseOne[mIneq];
    }
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::xnrm2(int32_T n, const real_T x[170], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (std::isnan(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::xzlarfg(int32_T n, real_T *alpha1, real_T x[170], int32_T
  ix0)
{
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c_tmp;
  int32_T d;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    xnorm = xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (std::abs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        c_tmp = (ix0 + n) - 2;
        do {
          knt++;
          for (d = ix0; d <= c_tmp; d++) {
            x[d - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((std::abs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(*alpha1, xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        for (d = ix0; d <= c_tmp; d++) {
          x[d - 1] *= a;
        }

        for (d = 0; d < knt; d++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        d = (ix0 + n) - 2;
        for (knt = ix0; knt <= d; knt++) {
          x[knt - 1] *= a;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[170], int32_T ic0, real_T work[17])
{
  int32_T coltop;
  int32_T iyend;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n - 1;
    exitg2 = false;
    while ((!exitg2) && (lastc + 1 > 0)) {
      int32_T exitg1;
      coltop = lastc * 10 + ic0;
      iyend = coltop;
      do {
        exitg1 = 0;
        if (iyend <= (coltop + lastv) - 1) {
          if (C[iyend - 1] != 0.0) {
            exitg1 = 1;
          } else {
            iyend++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T jy;
    if (lastc + 1 != 0) {
      if (lastc >= 0) {
        std::memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof
                    (real_T));
      }

      jy = 10 * lastc + ic0;
      for (coltop = ic0; coltop <= jy; coltop += 10) {
        c = 0.0;
        d = (coltop + lastv) - 1;
        for (iyend = coltop; iyend <= d; iyend++) {
          c += C[((iv0 + iyend) - coltop) - 1] * C[iyend - 1];
        }

        iyend = div_nde_s32_floor(coltop - ic0, 10);
        work[iyend] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jy = ic0;
      for (coltop = 0; coltop <= lastc; coltop++) {
        c = work[coltop];
        if (c != 0.0) {
          c *= -tau;
          d = lastv + jy;
          for (iyend = jy; iyend < d; iyend++) {
            C[iyend - 1] += C[((iv0 + iyend) - jy) - 1] * c;
          }
        }

        jy += 10;
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::qrf(real_T A[170], int32_T ia0, int32_T m, int32_T n,
  int32_T nfxd, real_T tau[10])
{
  real_T work[17];
  real_T b_atmp;
  real_T tau_0;
  int32_T i;
  int32_T ii;
  int32_T mmi;
  std::memset(&work[0], 0, 17U * sizeof(real_T));
  for (i = 0; i < nfxd; i++) {
    ii = ((i * 10 + ia0) + i) - 1;
    mmi = m - i;
    if (i + 1 < m) {
      b_atmp = A[ii];
      tau_0 = xzlarfg(mmi, &b_atmp, A, ii + 2);
      tau[i] = tau_0;
      A[ii] = b_atmp;
    } else {
      tau_0 = 0.0;
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      xzlarf(mmi, (n - i) - 1, ii + 1, tau_0, A, ii + 11, work);
      A[ii] = b_atmp;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::factorQRE(sH0q0JNg27eDMe5yMaNXg9D *obj, int32_T mrows,
  int32_T ncols)
{
  real_T vn1[17];
  real_T vn2[17];
  real_T work[17];
  real_T s;
  real_T temp;
  real_T vn1_0;
  int32_T b_ix;
  int32_T i;
  int32_T itemp;
  int32_T ix;
  int32_T ix_tmp;
  int32_T iy;
  int32_T j;
  int32_T mmi;
  int32_T nfxd;
  int32_T pvt;
  int32_T temp_tmp;
  int32_T tmp;
  if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      j = mrows;
    } else {
      j = ncols;
    }

    obj->minRowCol = j;
    std::memset(&obj->tau[0], 0, 10U * sizeof(real_T));
    if (j < 1) {
      for (j = 0; j < ncols; j++) {
        obj->jpvt[j] = j + 1;
      }
    } else {
      nfxd = -1;
      for (i = 0; i < ncols; i++) {
        if (obj->jpvt[i] != 0) {
          nfxd++;
          if (i + 1 != nfxd + 1) {
            ix = i * 10;
            iy = nfxd * 10;
            for (mmi = 0; mmi < mrows; mmi++) {
              temp_tmp = ix + mmi;
              temp = obj->QR[temp_tmp];
              tmp = iy + mmi;
              obj->QR[temp_tmp] = obj->QR[tmp];
              obj->QR[tmp] = temp;
            }

            obj->jpvt[i] = obj->jpvt[nfxd];
            obj->jpvt[nfxd] = i + 1;
          } else {
            obj->jpvt[i] = i + 1;
          }
        } else {
          obj->jpvt[i] = i + 1;
        }
      }

      if (nfxd + 1 <= j) {
        nfxd++;
      } else {
        nfxd = j;
      }

      std::memset(&obj->tau[0], 0, 10U * sizeof(real_T));
      qrf(obj->QR, 1, mrows, ncols, nfxd, obj->tau);
      if (nfxd < j) {
        std::memset(&work[0], 0, 17U * sizeof(real_T));
        std::memset(&vn1[0], 0, 17U * sizeof(real_T));
        std::memset(&vn2[0], 0, 17U * sizeof(real_T));
        for (i = nfxd + 1; i <= ncols; i++) {
          vn1_0 = xnrm2(mrows - nfxd, obj->QR, ((i - 1) * 10 + nfxd) + 1);
          vn1[i - 1] = vn1_0;
          vn2[i - 1] = vn1_0;
        }

        for (i = nfxd + 1; i <= j; i++) {
          ix_tmp = (i - 1) * 10;
          ix = (ix_tmp + i) - 1;
          iy = (ncols - i) + 1;
          mmi = mrows - i;
          if (iy < 1) {
            itemp = -2;
          } else {
            itemp = -1;
            if (iy > 1) {
              temp = std::abs(vn1[i - 1]);
              for (pvt = 2; pvt <= iy; pvt++) {
                s = std::abs(vn1[(i + pvt) - 2]);
                if (s > temp) {
                  itemp = pvt - 2;
                  temp = s;
                }
              }
            }
          }

          pvt = i + itemp;
          if (pvt + 1 != i) {
            b_ix = pvt * 10;
            for (itemp = 0; itemp < mrows; itemp++) {
              temp_tmp = b_ix + itemp;
              temp = obj->QR[temp_tmp];
              tmp = ix_tmp + itemp;
              obj->QR[temp_tmp] = obj->QR[tmp];
              obj->QR[tmp] = temp;
            }

            itemp = obj->jpvt[pvt];
            obj->jpvt[pvt] = obj->jpvt[i - 1];
            obj->jpvt[i - 1] = itemp;
            vn1[pvt] = vn1[i - 1];
            vn2[pvt] = vn2[i - 1];
          }

          if (i < mrows) {
            temp = obj->QR[ix];
            obj->tau[i - 1] = xzlarfg(mmi + 1, &temp, obj->QR, ix + 2);
            obj->QR[ix] = temp;
          } else {
            obj->tau[i - 1] = 0.0;
          }

          if (i < ncols) {
            temp = obj->QR[ix];
            obj->QR[ix] = 1.0;
            xzlarf(mmi + 1, iy - 1, ix + 1, obj->tau[i - 1], obj->QR, ix + 11,
                   work);
            obj->QR[ix] = temp;
          }

          for (ix = i + 1; ix <= ncols; ix++) {
            iy = (ix - 1) * 10 + i;
            vn1_0 = vn1[ix - 1];
            if (vn1_0 != 0.0) {
              temp = std::abs(obj->QR[iy - 1]) / vn1_0;
              temp = 1.0 - temp * temp;
              if (temp < 0.0) {
                temp = 0.0;
              }

              s = vn1_0 / vn2[ix - 1];
              s = s * s * temp;
              if (s <= 1.4901161193847656E-8) {
                if (i < mrows) {
                  vn1_0 = xnrm2(mmi, obj->QR, iy + 1);
                  vn1[ix - 1] = vn1_0;
                  vn2[ix - 1] = vn1_0;
                } else {
                  vn1[ix - 1] = 0.0;
                  vn2[ix - 1] = 0.0;
                }
              } else {
                vn1[ix - 1] = vn1_0 * std::sqrt(temp);
              }
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::computeQ_(sH0q0JNg27eDMe5yMaNXg9D *obj, int32_T nrows)
{
  real_T work[10];
  int32_T b_k;
  int32_T coltop;
  int32_T iQR0;
  int32_T iaii;
  int32_T idx;
  coltop = obj->minRowCol;
  for (idx = 0; idx < coltop; idx++) {
    iQR0 = obj->ldq * idx + idx;
    iaii = obj->mrows - idx;
    if (iaii - 2 >= 0) {
      std::memcpy(&obj->Q[iQR0 + 1], &obj->QR[iQR0 + 1], static_cast<uint32_T>
                  (((iaii + iQR0) - iQR0) - 1) * sizeof(real_T));
    }
  }

  idx = obj->mrows;
  b_k = obj->ldq;
  if (nrows >= 1) {
    int32_T ia;
    int32_T itau;
    for (itau = coltop; itau < nrows; itau++) {
      ia = itau * b_k;
      if (idx - 1 >= 0) {
        std::memset(&obj->Q[ia], 0, static_cast<uint32_T>((idx + ia) - ia) *
                    sizeof(real_T));
      }

      obj->Q[ia + itau] = 1.0;
    }

    itau = obj->minRowCol - 1;
    std::memset(&work[0], 0, 10U * sizeof(real_T));
    for (iQR0 = obj->minRowCol; iQR0 >= 1; iQR0--) {
      int32_T jA;
      iaii = ((iQR0 - 1) * b_k + iQR0) - 1;
      if (iQR0 < nrows) {
        int32_T iyend;
        int32_T lastc;
        obj->Q[iaii] = 1.0;
        lastc = idx - iQR0;
        jA = (iaii + b_k) + 1;
        if (obj->tau[itau] != 0.0) {
          boolean_T exitg2;
          ia = lastc;
          lastc += iaii;
          while ((ia + 1 > 0) && (obj->Q[lastc] == 0.0)) {
            ia--;
            lastc--;
          }

          lastc = (nrows - iQR0) - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc + 1 > 0)) {
            int32_T exitg1;
            coltop = lastc * b_k + jA;
            iyend = coltop;
            do {
              exitg1 = 0;
              if (iyend <= coltop + ia) {
                if (obj->Q[iyend - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  iyend++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          ia = -1;
          lastc = -1;
        }

        if (ia + 1 > 0) {
          real_T b_c;
          int32_T jy;
          if (lastc + 1 != 0) {
            int32_T b_ix;
            if (lastc >= 0) {
              std::memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof
                          (real_T));
            }

            jy = 0;
            b_ix = b_k * lastc + jA;
            for (coltop = jA; b_k < 0 ? coltop >= b_ix : coltop <= b_ix; coltop +=
                 b_k) {
              int32_T f;
              b_c = 0.0;
              f = coltop + ia;
              for (iyend = coltop; iyend <= f; iyend++) {
                b_c += obj->Q[(iaii + iyend) - coltop] * obj->Q[iyend - 1];
              }

              work[jy] += b_c;
              jy++;
            }
          }

          if (!(-obj->tau[itau] == 0.0)) {
            for (coltop = 0; coltop <= lastc; coltop++) {
              b_c = work[coltop];
              if (b_c != 0.0) {
                b_c *= -obj->tau[itau];
                jy = ia + jA;
                for (iyend = jA; iyend <= jy; iyend++) {
                  obj->Q[iyend - 1] += obj->Q[(iaii + iyend) - jA] * b_c;
                }
              }

              jA += b_k;
            }
          }
        }
      }

      if (iQR0 < idx) {
        jA = ((iaii + idx) - iQR0) + 1;
        for (ia = iaii + 2; ia <= jA; ia++) {
          obj->Q[ia - 1] *= -obj->tau[itau];
        }
      }

      obj->Q[iaii] = 1.0 - obj->tau[itau];
      for (ia = 0; ia <= iQR0 - 2; ia++) {
        obj->Q[(iaii - ia) - 1] = 0.0;
      }

      itau--;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
int32_T QP_CA_Codegen::ComputeNumDependentEq_(sH0q0JNg27eDMe5yMaNXg9D *qrmanager,
  const real_T beqf[17], int32_T mConstr, int32_T nVar)
{
  real_T qtb;
  real_T tol;
  int32_T b_idx;
  int32_T ix;
  int32_T numDependent;
  int32_T totalRank;
  boolean_T exitg1;
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }

  if (nVar - 1 >= 0) {
    std::memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>(nVar) * sizeof
                (int32_T));
  }

  factorQRE(qrmanager, mConstr, nVar);
  tol = 100.0 * static_cast<real_T>(nVar) * 2.2204460492503131E-16;
  if (nVar <= mConstr) {
    totalRank = nVar;
  } else {
    totalRank = mConstr;
  }

  totalRank += (totalRank - 1) * qrmanager->ldq;
  while ((totalRank > 0) && (std::abs(qrmanager->QR[totalRank - 1]) < tol)) {
    totalRank = (totalRank - qrmanager->ldq) - 1;
    numDependent++;
  }

  if (numDependent > 0) {
    computeQ_(qrmanager, qrmanager->mrows);
    b_idx = 0;
    exitg1 = false;
    while ((!exitg1) && (b_idx <= numDependent - 1)) {
      qtb = 0.0;
      if (mConstr >= 1) {
        ix = ((mConstr - b_idx) - 1) * qrmanager->ldq;
        for (totalRank = 0; totalRank < mConstr; totalRank++) {
          qtb += qrmanager->Q[ix + totalRank] * beqf[totalRank];
        }
      }

      if (std::abs(qtb) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        b_idx++;
      }
    }
  }

  return numDependent;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
  int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T idxEnd;
    int32_T idxEnd_tmp;
    int32_T idxStart;
    int32_T maxOffset_tmp;
    idxEnd_tmp = xMax - xMin;
    if (idxEnd_tmp >= 0) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>(idxEnd_tmp + 1) *
                  sizeof(int32_T));
    }

    maxOffset_tmp = idxEnd_tmp - 1;
    for (idxStart = 0; idxStart < xLen; idxStart++) {
      idxEnd = x[idxStart] - xMin;
      workspace[idxEnd]++;
    }

    for (idxStart = 2; idxStart <= maxOffset_tmp + 2; idxStart++) {
      workspace[idxStart - 1] += workspace[idxStart - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (int32_T maxOffset{0}; maxOffset <= maxOffset_tmp; maxOffset++) {
      for (idxEnd_tmp = idxStart; idxEnd_tmp <= idxEnd; idxEnd_tmp++) {
        x[idxEnd_tmp - 1] = maxOffset + xMin;
      }

      idxStart = workspace[maxOffset] + 1;
      idxEnd = workspace[maxOffset + 1];
    }

    for (int32_T maxOffset{idxStart}; maxOffset <= idxEnd; maxOffset++) {
      x[maxOffset - 1] = xMax;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::removeConstr(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T
  idx_global)
{
  int32_T TYPE_tmp;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  if (idx_global < obj->nActiveConstr) {
    int32_T b;
    obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
    b = obj->nVar;
    for (int32_T idx{0}; idx < b; idx++) {
      obj->ATwset[idx + obj->ldA * (idx_global - 1)] = obj->ATwset
        [(obj->nActiveConstr - 1) * obj->ldA + idx];
    }

    obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  }

  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::removeEqConstr(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T
  idx_global)
{
  int32_T TYPE_tmp;
  int32_T b_tmp;
  int32_T idx;
  int32_T totalEq;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global)) {
      obj->mEqRemoved++;
      obj->indexEqRemoved[obj->mEqRemoved - 1] = obj->Wlocalidx[idx_global - 1];
      removeConstr(obj, idx_global);
    } else {
      obj->mEqRemoved++;
      TYPE_tmp = obj->Wid[idx_global - 1] - 1;
      idx = obj->Wlocalidx[idx_global - 1];
      obj->indexEqRemoved[obj->mEqRemoved - 1] = idx;
      obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + idx) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[totalEq];
      b_tmp = obj->nVar;
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + obj->ldA * (idx_global - 1)] = obj->ATwset[obj->ldA *
          totalEq + idx];
      }

      obj->bwset[idx_global - 1] = obj->bwset[totalEq];
      obj->Wid[totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[totalEq] = obj->Wlocalidx[obj->nActiveConstr - 1];
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + obj->ldA * totalEq] = obj->ATwset[(obj->nActiveConstr
          - 1) * obj->ldA + idx];
      }

      obj->bwset[totalEq] = obj->bwset[obj->nActiveConstr - 1];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE_tmp]--;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::RemoveDependentIneq_(sAjQtoJYLWYGAxqZWOtnxYE *workingset,
  sH0q0JNg27eDMe5yMaNXg9D *qrmanager, sTLNI0DWFUbeIRd2tl4OexC *memspace, real_T
  tolfactor)
{
  real_T tol;
  int32_T ix0;
  int32_T iy0;
  int32_T nActiveConstr;
  int32_T nActiveConstr_tmp;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;
  nActiveConstr_tmp = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = tolfactor * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    for (nDepIneq = 0; nDepIneq < nFixedConstr; nDepIneq++) {
      qrmanager->jpvt[nDepIneq] = 1;
    }

    if (nFixedConstr + 1 <= workingset->nActiveConstr) {
      std::memset(&qrmanager->jpvt[nFixedConstr], 0, static_cast<uint32_T>
                  (workingset->nActiveConstr - nFixedConstr) * sizeof(int32_T));
    }

    for (nDepIneq = 0; nDepIneq < nActiveConstr_tmp; nDepIneq++) {
      iy0 = qrmanager->ldq * nDepIneq;
      ix0 = workingset->ldA * nDepIneq;
      for (nActiveConstr = 0; nActiveConstr < nVar; nActiveConstr++) {
        qrmanager->QR[iy0 + nActiveConstr] = workingset->ATwset[nActiveConstr +
          ix0];
      }
    }

    factorQRE(qrmanager, workingset->nVar, workingset->nActiveConstr);
    nDepIneq = 0;
    for (nActiveConstr = workingset->nActiveConstr - 1; nActiveConstr + 1 > nVar;
         nActiveConstr--) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[nActiveConstr];
    }

    if (nActiveConstr + 1 <= workingset->nVar) {
      nVar = qrmanager->ldq * nActiveConstr + nActiveConstr;
      while ((nActiveConstr + 1 > nFixedConstr) && (std::abs(qrmanager->QR[nVar])
              < tol)) {
        nDepIneq++;
        memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[nActiveConstr];
        nActiveConstr--;
        nVar = (nVar - qrmanager->ldq) - 1;
      }
    }

    countsort(memspace->workspace_int, nDepIneq, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      removeConstr(workingset, memspace->workspace_int[nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::factorQR(sH0q0JNg27eDMe5yMaNXg9D *obj, const real_T A[119],
  int32_T mrows, int32_T ncols, int32_T ldA)
{
  int32_T i;
  int32_T idx;
  int32_T ix0;
  int32_T iy0;
  boolean_T guard1;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    for (idx = 0; idx < ncols; idx++) {
      ix0 = ldA * idx;
      iy0 = obj->ldq * idx;
      for (i = 0; i < mrows; i++) {
        obj->QR[iy0 + i] = A[i + ix0];
      }
    }

    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    for (idx = 0; idx < ncols; idx++) {
      obj->jpvt[idx] = idx + 1;
    }

    if (mrows <= ncols) {
      idx = mrows;
    } else {
      idx = ncols;
    }

    obj->minRowCol = idx;
    std::memset(&obj->tau[0], 0, 10U * sizeof(real_T));
    if (idx >= 1) {
      std::memset(&obj->tau[0], 0, 10U * sizeof(real_T));
      qrf(obj->QR, 1, mrows, ncols, idx, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xgemv(int32_T m, int32_T n, const real_T A[28], int32_T lda,
  const real_T x[119], real_T y[17])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy{0}; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy{1}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = (b_iy + m) - 1;
      for (int32_T iyend{b_iy}; iyend <= d; iyend++) {
        c += A[iyend - 1] * x[iyend - b_iy];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xgemv_b(int32_T m, int32_T n, const real_T A[28], int32_T
  lda, const real_T x[119], real_T y[17])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy{0}; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy{1}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = (b_iy + m) - 1;
      for (int32_T iyend{b_iy}; iyend <= d; iyend++) {
        c += x[(iyend - b_iy) + 17] * A[iyend - 1];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::maxConstraintViolation(sAjQtoJYLWYGAxqZWOtnxYE *obj, const
  real_T x[119])
{
  real_T obj_maxConstrWorkspace;
  real_T v;
  int32_T k;
  int32_T mEq;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int32_T offsetEq1;
  int32_T offsetEq2;
  mLB = obj->sizes[3] - 1;
  mUB = obj->sizes[4] - 1;
  mFixed = obj->sizes[0] - 1;
  if (obj->probType == 2) {
    v = 0.0;
    mEq = obj->sizes[1] - 1;
    if (mEq >= 0) {
      std::memcpy(&obj->maxConstrWorkspace[0], &obj->beq[0],
                  static_cast<uint32_T>(mEq + 1) * sizeof(real_T));
    }

    xgemv_b(obj->nVarOrig, obj->sizes[1], obj->Aeq, obj->ldA, x,
            obj->maxConstrWorkspace);
    offsetEq1 = (obj->nVarOrig + obj->sizes[2]) + 16;
    offsetEq2 = (offsetEq1 + obj->sizes[1]) + 1;
    for (k = 0; k <= mEq; k++) {
      obj_maxConstrWorkspace = (obj->maxConstrWorkspace[k] - x[(offsetEq1 + k) +
        1]) + x[offsetEq2 + k];
      obj->maxConstrWorkspace[k] = obj_maxConstrWorkspace;
      v = std::fmax(v, std::abs(obj_maxConstrWorkspace));
    }
  } else {
    v = 0.0;
    mEq = obj->sizes[1] - 1;
    if (mEq >= 0) {
      std::memcpy(&obj->maxConstrWorkspace[0], &obj->beq[0],
                  static_cast<uint32_T>(mEq + 1) * sizeof(real_T));
    }

    xgemv_b(obj->nVar, obj->sizes[1], obj->Aeq, obj->ldA, x,
            obj->maxConstrWorkspace);
    for (k = 0; k <= mEq; k++) {
      v = std::fmax(v, std::abs(obj->maxConstrWorkspace[k]));
    }
  }

  if (obj->sizes[3] > 0) {
    for (mEq = 0; mEq <= mLB; mEq++) {
      v = std::fmax(v, -x[obj->indexLB[mEq] + 16] - obj->lb[obj->indexLB[mEq] -
                    1]);
    }
  }

  if (obj->sizes[4] > 0) {
    for (mLB = 0; mLB <= mUB; mLB++) {
      v = std::fmax(v, x[obj->indexUB[mLB] + 16] - obj->ub[obj->indexUB[mLB] - 1]);
    }
  }

  if (obj->sizes[0] > 0) {
    for (mUB = 0; mUB <= mFixed; mUB++) {
      v = std::fmax(v, std::abs(x[obj->indexFixed[mUB] + 16] - obj->ub
        [obj->indexFixed[mUB] - 1]));
    }
  }

  return v;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
boolean_T QP_CA_Codegen::feasibleX0ForWorkingSet(real_T workspace[119], real_T
  xCurrent[7], sAjQtoJYLWYGAxqZWOtnxYE *workingset, sH0q0JNg27eDMe5yMaNXg9D
  *qrmanager)
{
  real_T B_0[119];
  real_T c;
  real_T workingset_maxConstrWorkspace;
  int32_T d;
  int32_T exitg1;
  int32_T h;
  int32_T ix;
  int32_T iy;
  int32_T jBcol;
  int32_T ldq;
  int32_T mLB;
  int32_T mWConstr;
  int32_T nVar_tmp_tmp;
  int32_T offsetQR;
  boolean_T nonDegenerateWset;
  mWConstr = workingset->nActiveConstr - 1;
  nVar_tmp_tmp = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (ldq = 0; ldq <= mWConstr; ldq++) {
      workspace[ldq] = workingset->bwset[ldq];
      workspace[ldq + 17] = workingset->bwset[ldq];
    }

    offsetQR = workingset->ldA;
    if ((workingset->nVar != 0) && (workingset->nActiveConstr != 0)) {
      iy = 0;
      jBcol = (workingset->nActiveConstr - 1) * workingset->ldA + 1;
      for (ldq = 1; offsetQR < 0 ? ldq >= jBcol : ldq <= jBcol; ldq += offsetQR)
      {
        c = 0.0;
        d = (ldq + nVar_tmp_tmp) - 1;
        for (mLB = ldq; mLB <= d; mLB++) {
          c += workingset->ATwset[mLB - 1] * xCurrent[mLB - ldq];
        }

        workspace[iy] -= c;
        iy++;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      for (ldq = 0; ldq < nVar_tmp_tmp; ldq++) {
        offsetQR = qrmanager->ldq * ldq;
        for (mLB = 0; mLB <= mWConstr; mLB++) {
          qrmanager->QR[mLB + offsetQR] = workingset->ATwset[workingset->ldA *
            mLB + ldq];
        }
      }

      if (workingset->nActiveConstr * workingset->nVar == 0) {
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = false;
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        for (ldq = 0; ldq < nVar_tmp_tmp; ldq++) {
          qrmanager->jpvt[ldq] = ldq + 1;
        }

        if (workingset->nActiveConstr <= workingset->nVar) {
          ldq = workingset->nActiveConstr;
        } else {
          ldq = workingset->nVar;
        }

        qrmanager->minRowCol = ldq;
        std::memset(&qrmanager->tau[0], 0, 10U * sizeof(real_T));
        if (ldq >= 1) {
          std::memset(&qrmanager->tau[0], 0, 10U * sizeof(real_T));
          qrf(qrmanager->QR, 1, workingset->nActiveConstr, workingset->nVar, ldq,
              qrmanager->tau);
        }
      }

      computeQ_(qrmanager, qrmanager->mrows);
      ldq = qrmanager->ldq;
      std::memcpy(&B_0[0], &workspace[0], 119U * sizeof(real_T));
      if (workingset->nVar != 0) {
        jBcol = -1;
        for (mLB = 0; mLB <= 17; mLB += 17) {
          iy = mLB + nVar_tmp_tmp;
          for (offsetQR = mLB + 1; offsetQR <= iy; offsetQR++) {
            workspace[offsetQR - 1] = 0.0;
          }
        }

        for (mLB = 0; mLB <= 17; mLB += 17) {
          ix = -1;
          d = mLB + nVar_tmp_tmp;
          for (offsetQR = mLB + 1; offsetQR <= d; offsetQR++) {
            c = 0.0;
            for (iy = 0; iy <= mWConstr; iy++) {
              c += qrmanager->Q[(iy + ix) + 1] * B_0[(iy + jBcol) + 1];
            }

            workspace[offsetQR - 1] += c;
            ix += ldq;
          }

          jBcol += 17;
        }
      }

      for (mWConstr = 0; mWConstr < 2; mWConstr++) {
        iy = 17 * mWConstr - 1;
        for (mLB = nVar_tmp_tmp; mLB >= 1; mLB--) {
          jBcol = (mLB - 1) * ldq;
          ix = mLB + iy;
          c = workspace[ix];
          if (c != 0.0) {
            workspace[ix] = c / qrmanager->QR[(mLB + jBcol) - 1];
            for (offsetQR = 0; offsetQR <= mLB - 2; offsetQR++) {
              d = (offsetQR + iy) + 1;
              workspace[d] -= qrmanager->QR[offsetQR + jBcol] * workspace[ix];
            }
          }
        }
      }
    } else {
      factorQR(qrmanager, workingset->ATwset, workingset->nVar,
               workingset->nActiveConstr, workingset->ldA);
      computeQ_(qrmanager, qrmanager->minRowCol);
      ldq = qrmanager->ldq;
      for (mLB = 0; mLB < 2; mLB++) {
        jBcol = 17 * mLB;
        for (offsetQR = 0; offsetQR <= mWConstr; offsetQR++) {
          ix = ldq * offsetQR;
          d = offsetQR + jBcol;
          c = workspace[d];
          for (iy = 0; iy < offsetQR; iy++) {
            c -= qrmanager->QR[iy + ix] * workspace[iy + jBcol];
          }

          workspace[d] = c / qrmanager->QR[offsetQR + ix];
        }
      }

      std::memcpy(&B_0[0], &workspace[0], 119U * sizeof(real_T));
      if (workingset->nVar != 0) {
        jBcol = 1;
        for (mLB = 0; mLB <= 17; mLB += 17) {
          iy = mLB + nVar_tmp_tmp;
          for (offsetQR = mLB + 1; offsetQR <= iy; offsetQR++) {
            workspace[offsetQR - 1] = 0.0;
          }
        }

        for (mLB = 0; mLB <= 17; mLB += 17) {
          ix = -1;
          d = jBcol + mWConstr;
          for (offsetQR = jBcol; offsetQR <= d; offsetQR++) {
            h = mLB + nVar_tmp_tmp;
            for (iy = mLB + 1; iy <= h; iy++) {
              workspace[iy - 1] += qrmanager->Q[(ix + iy) - mLB] * B_0[offsetQR
                - 1];
            }

            ix += ldq;
          }

          jBcol += 17;
        }
      }
    }

    mWConstr = 0;
    do {
      exitg1 = 0;
      if (mWConstr <= nVar_tmp_tmp - 1) {
        if (std::isinf(workspace[mWConstr]) || std::isnan(workspace[mWConstr]))
        {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace[mWConstr + 17];
          if (std::isinf(c) || std::isnan(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            mWConstr++;
          }
        }
      } else {
        if (nVar_tmp_tmp >= 1) {
          for (mWConstr = 0; mWConstr < nVar_tmp_tmp; mWConstr++) {
            workspace[mWConstr] += xCurrent[mWConstr];
          }
        }

        mLB = workingset->sizes[3];
        ldq = workingset->sizes[4];
        mWConstr = workingset->sizes[0];
        if (workingset->probType == 2) {
          c = 0.0;
          iy = workingset->sizes[1] - 1;
          if (iy >= 0) {
            std::memcpy(&workingset->maxConstrWorkspace[0], &workingset->beq[0],
                        static_cast<uint32_T>(iy + 1) * sizeof(real_T));
          }

          xgemv(workingset->nVarOrig, workingset->sizes[1], workingset->Aeq,
                workingset->ldA, workspace, workingset->maxConstrWorkspace);
          jBcol = workingset->nVarOrig + workingset->sizes[2];
          ix = jBcol + workingset->sizes[1];
          for (offsetQR = 0; offsetQR <= iy; offsetQR++) {
            workingset_maxConstrWorkspace = (workingset->
              maxConstrWorkspace[offsetQR] - workspace[jBcol + offsetQR]) +
              workspace[ix + offsetQR];
            workingset->maxConstrWorkspace[offsetQR] =
              workingset_maxConstrWorkspace;
            c = std::fmax(c, std::abs(workingset_maxConstrWorkspace));
          }
        } else {
          c = 0.0;
          iy = workingset->sizes[1] - 1;
          if (iy >= 0) {
            std::memcpy(&workingset->maxConstrWorkspace[0], &workingset->beq[0],
                        static_cast<uint32_T>(iy + 1) * sizeof(real_T));
          }

          xgemv(workingset->nVar, workingset->sizes[1], workingset->Aeq,
                workingset->ldA, workspace, workingset->maxConstrWorkspace);
          for (offsetQR = 0; offsetQR <= iy; offsetQR++) {
            c = std::fmax(c, std::abs(workingset->maxConstrWorkspace[offsetQR]));
          }
        }

        if (workingset->sizes[3] > 0) {
          for (offsetQR = 0; offsetQR < mLB; offsetQR++) {
            c = std::fmax(c, -workspace[workingset->indexLB[offsetQR] - 1] -
                          workingset->lb[workingset->indexLB[offsetQR] - 1]);
          }
        }

        if (workingset->sizes[4] > 0) {
          for (mLB = 0; mLB < ldq; mLB++) {
            c = std::fmax(c, workspace[workingset->indexUB[mLB] - 1] -
                          workingset->ub[workingset->indexUB[mLB] - 1]);
          }
        }

        if (workingset->sizes[0] > 0) {
          for (ldq = 0; ldq < mWConstr; ldq++) {
            c = std::fmax(c, std::abs(workspace[workingset->indexFixed[ldq] - 1]
              - workingset->ub[workingset->indexFixed[ldq] - 1]));
          }
        }

        workingset_maxConstrWorkspace = maxConstraintViolation(workingset,
          workspace);
        if ((c <= 2.2204460492503131E-16) || (c < workingset_maxConstrWorkspace))
        {
          if (nVar_tmp_tmp - 1 >= 0) {
            std::memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                        (nVar_tmp_tmp) * sizeof(real_T));
          }
        } else if (nVar_tmp_tmp - 1 >= 0) {
          std::memcpy(&xCurrent[0], &workspace[17], static_cast<uint32_T>
                      (nVar_tmp_tmp) * sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xgemv_b4(int32_T m, int32_T n, const real_T A[28], int32_T
  lda, const real_T x[7], real_T y[17])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy{0}; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy{1}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = (b_iy + m) - 1;
      for (int32_T iyend{b_iy}; iyend <= d; iyend++) {
        c += A[iyend - 1] * x[iyend - b_iy];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::maxConstraintViolation_e(sAjQtoJYLWYGAxqZWOtnxYE *obj,
  const real_T x[7])
{
  real_T obj_maxConstrWorkspace;
  real_T v;
  int32_T k;
  int32_T mEq;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int32_T offsetEq1;
  int32_T offsetEq2;
  mLB = obj->sizes[3] - 1;
  mUB = obj->sizes[4] - 1;
  mFixed = obj->sizes[0] - 1;
  if (obj->probType == 2) {
    v = 0.0;
    mEq = obj->sizes[1] - 1;
    if (mEq >= 0) {
      std::memcpy(&obj->maxConstrWorkspace[0], &obj->beq[0],
                  static_cast<uint32_T>(mEq + 1) * sizeof(real_T));
    }

    xgemv_b4(obj->nVarOrig, obj->sizes[1], obj->Aeq, obj->ldA, x,
             obj->maxConstrWorkspace);
    offsetEq1 = obj->nVarOrig + obj->sizes[2];
    offsetEq2 = offsetEq1 + obj->sizes[1];
    for (k = 0; k <= mEq; k++) {
      obj_maxConstrWorkspace = (obj->maxConstrWorkspace[k] - x[offsetEq1 + k]) +
        x[offsetEq2 + k];
      obj->maxConstrWorkspace[k] = obj_maxConstrWorkspace;
      v = std::fmax(v, std::abs(obj_maxConstrWorkspace));
    }
  } else {
    v = 0.0;
    mEq = obj->sizes[1] - 1;
    if (mEq >= 0) {
      std::memcpy(&obj->maxConstrWorkspace[0], &obj->beq[0],
                  static_cast<uint32_T>(mEq + 1) * sizeof(real_T));
    }

    xgemv_b4(obj->nVar, obj->sizes[1], obj->Aeq, obj->ldA, x,
             obj->maxConstrWorkspace);
    for (k = 0; k <= mEq; k++) {
      v = std::fmax(v, std::abs(obj->maxConstrWorkspace[k]));
    }
  }

  if (obj->sizes[3] > 0) {
    for (mEq = 0; mEq <= mLB; mEq++) {
      v = std::fmax(v, -x[obj->indexLB[mEq] - 1] - obj->lb[obj->indexLB[mEq] - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    for (mLB = 0; mLB <= mUB; mLB++) {
      v = std::fmax(v, x[obj->indexUB[mLB] - 1] - obj->ub[obj->indexUB[mLB] - 1]);
    }
  }

  if (obj->sizes[0] > 0) {
    for (mUB = 0; mUB <= mFixed; mUB++) {
      v = std::fmax(v, std::abs(x[obj->indexFixed[mUB] - 1] - obj->ub
        [obj->indexFixed[mUB] - 1]));
    }
  }

  return v;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::PresolveWorkingSet(sBiFZCV7758PhXr6el0VfCD *solution,
  sTLNI0DWFUbeIRd2tl4OexC *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
  sH0q0JNg27eDMe5yMaNXg9D *qrmanager)
{
  real_T constrViolation;
  int32_T b_k;
  int32_T i;
  int32_T idxStartIneq;
  int32_T ix0;
  int32_T iy0;
  int32_T mTotalWorkingEq;
  int32_T mTotalWorkingEq_tmp_tmp;
  int32_T nVar;
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  qrmanager->ldq = 10;
  std::memset(&qrmanager->QR[0], 0, 170U * sizeof(real_T));
  std::memset(&qrmanager->Q[0], 0, 100U * sizeof(real_T));
  std::memset(&qrmanager->jpvt[0], 0, 17U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  std::memset(&qrmanager->tau[0], 0, 10U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  nVar = workingset->nVar - 1;
  i = workingset->nWConstr[0];
  mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  idxStartIneq = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    for (idxStartIneq = 0; idxStartIneq < mTotalWorkingEq_tmp_tmp; idxStartIneq
         ++) {
      for (mTotalWorkingEq = 0; mTotalWorkingEq <= nVar; mTotalWorkingEq++) {
        qrmanager->QR[idxStartIneq + 10 * mTotalWorkingEq] = workingset->
          ATwset[workingset->ldA * idxStartIneq + mTotalWorkingEq];
      }
    }

    idxStartIneq = ComputeNumDependentEq_(qrmanager, workingset->bwset,
      mTotalWorkingEq_tmp_tmp, workingset->nVar);
    if (idxStartIneq > 0) {
      for (mTotalWorkingEq = 0; mTotalWorkingEq < mTotalWorkingEq_tmp_tmp;
           mTotalWorkingEq++) {
        iy0 = qrmanager->ldq * mTotalWorkingEq;
        ix0 = workingset->ldA * mTotalWorkingEq;
        for (b_k = 0; b_k <= nVar; b_k++) {
          qrmanager->QR[iy0 + b_k] = workingset->ATwset[b_k + ix0];
        }
      }

      for (mTotalWorkingEq = 0; mTotalWorkingEq < i; mTotalWorkingEq++) {
        qrmanager->jpvt[mTotalWorkingEq] = 1;
      }

      mTotalWorkingEq = workingset->nWConstr[0] + 1;
      if (mTotalWorkingEq <= mTotalWorkingEq_tmp_tmp) {
        std::memset(&qrmanager->jpvt[mTotalWorkingEq + -1], 0, static_cast<
                    uint32_T>((mTotalWorkingEq_tmp_tmp - mTotalWorkingEq) + 1) *
                    sizeof(int32_T));
      }

      factorQRE(qrmanager, workingset->nVar, mTotalWorkingEq_tmp_tmp);
      for (i = 0; i < idxStartIneq; i++) {
        memspace->workspace_int[i] = qrmanager->jpvt[(mTotalWorkingEq_tmp_tmp -
          idxStartIneq) + i];
      }

      countsort(memspace->workspace_int, idxStartIneq, memspace->workspace_sort,
                1, mTotalWorkingEq_tmp_tmp);
      for (mTotalWorkingEq = idxStartIneq; mTotalWorkingEq >= 1; mTotalWorkingEq
           --) {
        removeEqConstr(workingset, memspace->workspace_int[mTotalWorkingEq - 1]);
      }
    }
  }

  if ((idxStartIneq != -1) && (workingset->nActiveConstr <= qrmanager->ldq)) {
    RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = feasibleX0ForWorkingSet(memspace->workspace_float,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = feasibleX0ForWorkingSet(memspace->workspace_float,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        constrViolation = maxConstraintViolation_e(workingset, solution->xstar);
        if (constrViolation > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    idxStartIneq = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
    i = workingset->nActiveConstr;
    for (mTotalWorkingEq = idxStartIneq; mTotalWorkingEq <= i; mTotalWorkingEq++)
    {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[mTotalWorkingEq - 1] - 1] + workingset->Wlocalidx[mTotalWorkingEq -
        1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[119], const real_T x[7])
{
  int32_T beta1;
  static const int8_T f[36]{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  beta1 = 0;
  if (obj_hasLinear) {
    if (obj_nvar - 1 >= 0) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>(obj_nvar) * sizeof
                  (real_T));
    }

    beta1 = 1;
  }

  if (obj_nvar != 0) {
    int32_T d;
    int32_T ix;
    if ((beta1 != 1) && (obj_nvar - 1 >= 0)) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>(obj_nvar) * sizeof
                  (real_T));
    }

    ix = 0;
    d = (obj_nvar - 1) * obj_nvar + 1;
    for (int32_T iyend{1}; obj_nvar < 0 ? iyend >= d : iyend <= d; iyend +=
         obj_nvar) {
      real_T c;
      int32_T e;
      c = 0.5 * x[ix];
      e = (iyend + obj_nvar) - 1;
      for (beta1 = iyend; beta1 <= e; beta1++) {
        int32_T tmp;
        tmp = beta1 - iyend;
        workspace[tmp] += static_cast<real_T>(f[beta1 - 1]) * c;
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::computeFval(const slzZ8M58FXlZqTD433BZJUH *obj, real_T
  workspace[119], const real_T x[7])
{
  real_T val;
  int32_T c_tmp_tmp;
  int32_T ixlast;
  int32_T k;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    linearForm_(obj->hasLinear, obj->nvar, workspace, x);
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (k = 0; k < ixlast; k++) {
        val += x[k] * workspace[k];
      }
    }
    break;

   case 4:
    linearForm_(obj->hasLinear, obj->nvar, workspace, x);
    ixlast = obj->nvar + 1;
    c_tmp_tmp = obj->maxVar - 1;
    for (k = ixlast; k <= c_tmp_tmp; k++) {
      workspace[k - 1] = 0.5 * obj->beta * x[k - 1] + obj->rho;
    }

    if (obj->maxVar - 1 >= 1) {
      ixlast = obj->maxVar;
      for (k = 0; k <= ixlast - 2; k++) {
        val += x[k] * workspace[k];
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xgemv_b4q(int32_T m, int32_T n, int32_T lda, const real_T x
  [7], real_T y[6])
{
  static const int8_T d[36]{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T ix;
    if (m - 1 >= 0) {
      std::memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy{1}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      int32_T c;
      c = (b_iy + m) - 1;
      for (int32_T iyend{b_iy}; iyend <= c; iyend++) {
        int32_T tmp;
        tmp = iyend - b_iy;
        y[tmp] += static_cast<real_T>(d[iyend - 1]) * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::computeGrad_StoreHx(slzZ8M58FXlZqTD433BZJUH *obj, const
  real_T x[7])
{
  int32_T b;
  int32_T iy;
  int32_T maxRegVar;
  switch (obj->objtype) {
   case 5:
    if (obj->nvar - 2 >= 0) {
      std::memset(&obj->grad[0], 0, static_cast<uint32_T>(obj->nvar - 1) *
                  sizeof(real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    xgemv_b4q(obj->nvar, obj->nvar, obj->nvar, x, obj->Hx);
    if (obj->nvar - 1 >= 0) {
      std::memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>(obj->nvar) *
                  sizeof(real_T));
    }
    break;

   case 4:
    maxRegVar = obj->maxVar - 1;
    xgemv_b4q(obj->nvar, obj->nvar, obj->nvar, x, obj->Hx);
    iy = obj->nvar + 1;
    for (b = iy; b <= maxRegVar; b++) {
      obj->Hx[b - 1] = x[b - 1] * obj->beta;
    }

    if ((obj->maxVar - 1) - 1 >= 0) {
      std::memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>(obj->maxVar
        - 1) * sizeof(real_T));
    }

    b = (obj->maxVar - obj->nvar) - 1;
    if (b >= 1) {
      for (maxRegVar = 0; maxRegVar < b; maxRegVar++) {
        iy = obj->nvar + maxRegVar;
        obj->grad[iy] += obj->rho;
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::computeFval_ReuseHx(const slzZ8M58FXlZqTD433BZJUH *obj,
  real_T workspace[119], const real_T x[7])
{
  real_T val;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T ixlast;
        ixlast = obj->nvar;
        for (int32_T maxRegVar{0}; maxRegVar < ixlast; maxRegVar++) {
          workspace[maxRegVar] = 0.5 * obj->Hx[maxRegVar];
        }

        if (obj->nvar >= 1) {
          ixlast = obj->nvar;
          for (int32_T maxRegVar{0}; maxRegVar < ixlast; maxRegVar++) {
            val += x[maxRegVar] * workspace[maxRegVar];
          }
        }
      } else {
        if (obj->nvar >= 1) {
          int32_T ixlast;
          ixlast = obj->nvar;
          for (int32_T maxRegVar{0}; maxRegVar < ixlast; maxRegVar++) {
            val += x[maxRegVar] * obj->Hx[maxRegVar];
          }
        }

        val *= 0.5;
      }
    }
    break;

   case 4:
    {
      int32_T maxRegVar;
      maxRegVar = obj->maxVar - 1;
      if (obj->hasLinear) {
        int32_T b_ixlast;
        int32_T ixlast;
        if (obj->nvar - 1 >= 0) {
          std::memset(&workspace[0], 0, static_cast<uint32_T>(obj->nvar) *
                      sizeof(real_T));
        }

        b_ixlast = obj->maxVar - obj->nvar;
        for (ixlast = 0; ixlast <= b_ixlast - 2; ixlast++) {
          workspace[obj->nvar + ixlast] = obj->rho;
        }

        for (ixlast = 0; ixlast < maxRegVar; ixlast++) {
          workspace[ixlast] += 0.5 * obj->Hx[ixlast];
        }

        if (obj->maxVar - 1 >= 1) {
          ixlast = obj->maxVar;
          for (maxRegVar = 0; maxRegVar <= ixlast - 2; maxRegVar++) {
            val += x[maxRegVar] * workspace[maxRegVar];
          }
        }
      } else {
        int32_T b_ixlast;
        if (obj->maxVar - 1 >= 1) {
          b_ixlast = obj->maxVar;
          for (int32_T ixlast{0}; ixlast <= b_ixlast - 2; ixlast++) {
            val += x[ixlast] * obj->Hx[ixlast];
          }
        }

        val *= 0.5;
        b_ixlast = obj->nvar + 1;
        for (int32_T ixlast{b_ixlast}; ixlast <= maxRegVar; ixlast++) {
          val += x[ixlast - 1] * obj->rho;
        }
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = std::abs(*a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::deleteColMoveEnd(sH0q0JNg27eDMe5yMaNXg9D *obj, int32_T idx)
{
  real_T b_s;
  real_T b_temp;
  real_T c_c;
  int32_T QRk0;
  int32_T b_ix;
  int32_T b_temp_tmp;
  int32_T b_temp_tmp_0;
  int32_T d_ix;
  int32_T i;
  int32_T idxRotGCol;
  int32_T ix;
  int32_T k;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    idxRotGCol = obj->minRowCol;
    for (i = 0; i < idxRotGCol; i++) {
      obj->QR[i + obj->ldq * (idx - 1)] = obj->QR[(obj->ncols - 1) * obj->ldq +
        i];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        i = obj->mrows - 1;
      } else {
        i = obj->ncols;
      }

      k = i;
      idxRotGCol = (idx - 1) * obj->ldq;
      while (k >= idx) {
        b_temp_tmp_0 = k + idxRotGCol;
        b_temp = obj->QR[b_temp_tmp_0];
        xrotg(&obj->QR[b_temp_tmp_0 - 1], &b_temp, &c_c, &b_s);
        obj->QR[b_temp_tmp_0] = b_temp;
        obj->QR[k + obj->ldq * (k - 1)] = 0.0;
        QRk0 = obj->ldq * idx + k;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = QRk0 - 1;
          for (d_ix = 0; d_ix < b_ix; d_ix++) {
            b_temp = c_c * obj->QR[ix] + b_s * obj->QR[QRk0];
            obj->QR[QRk0] = c_c * obj->QR[QRk0] - b_s * obj->QR[ix];
            obj->QR[ix] = b_temp;
            QRk0 += obj->ldq;
            ix += obj->ldq;
          }
        }

        QRk0 = (k - 1) * obj->ldq;
        d_ix = obj->mrows;
        if (obj->mrows >= 1) {
          b_ix = QRk0;
          ix = obj->ldq + QRk0;
          for (QRk0 = 0; QRk0 < d_ix; QRk0++) {
            b_temp_tmp_0 = ix + QRk0;
            b_temp_tmp = b_ix + QRk0;
            b_temp = obj->Q[b_temp_tmp] * c_c + obj->Q[b_temp_tmp_0] * b_s;
            obj->Q[b_temp_tmp_0] = obj->Q[b_temp_tmp_0] * c_c - obj->
              Q[b_temp_tmp] * b_s;
            obj->Q[b_temp_tmp] = b_temp;
          }
        }

        k--;
      }

      for (k = idx + 1; k <= i; k++) {
        ix = (k - 1) * obj->ldq;
        b_temp_tmp_0 = k + ix;
        b_temp = obj->QR[b_temp_tmp_0];
        xrotg(&obj->QR[b_temp_tmp_0 - 1], &b_temp, &c_c, &b_s);
        obj->QR[b_temp_tmp_0] = b_temp;
        QRk0 = (obj->ldq + 1) * k;
        d_ix = obj->ncols - k;
        if (d_ix >= 1) {
          b_ix = QRk0 - 1;
          for (idxRotGCol = 0; idxRotGCol < d_ix; idxRotGCol++) {
            b_temp = c_c * obj->QR[b_ix] + b_s * obj->QR[QRk0];
            obj->QR[QRk0] = c_c * obj->QR[QRk0] - b_s * obj->QR[b_ix];
            obj->QR[b_ix] = b_temp;
            QRk0 += obj->ldq;
            b_ix += obj->ldq;
          }
        }

        idxRotGCol = obj->mrows;
        if (obj->mrows >= 1) {
          d_ix = ix;
          b_ix = obj->ldq + ix;
          for (QRk0 = 0; QRk0 < idxRotGCol; QRk0++) {
            b_temp_tmp_0 = b_ix + QRk0;
            b_temp = obj->Q[b_temp_tmp_0] * b_s + c_c * obj->Q[d_ix];
            obj->Q[b_temp_tmp_0] = obj->Q[b_temp_tmp_0] * c_c - b_s * obj->
              Q[d_ix];
            obj->Q[d_ix] = b_temp;
            d_ix++;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
int32_T QP_CA_Codegen::ixamax(int32_T n, const real_T x[100], int32_T incx)
{
  int32_T idxmax;
  if ((n < 1) || (incx < 1)) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      smax = std::abs(x[0]);
      for (int32_T k{2}; k <= n; k++) {
        real_T s;
        s = std::abs(x[(k - 1) * incx]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::fullColLDL2_(sY5VKsxRLdcmJCLAY5aC9o *obj, int32_T LD_offset,
  int32_T NColsRemain, real_T REG_PRIMAL)
{
  int32_T LDimSizeP1;
  int32_T lastDiag;
  LDimSizeP1 = obj->ldm;
  for (lastDiag = 0; lastDiag < NColsRemain; lastDiag++) {
    real_T alpha1;
    int32_T LD_diagOffset;
    int32_T b_k;
    int32_T subMatrixDim;
    LD_diagOffset = ((LDimSizeP1 + 1) * lastDiag + LD_offset) - 1;
    if (std::abs(obj->FMat[LD_diagOffset]) <= obj->regTol_) {
      obj->FMat[LD_diagOffset] += REG_PRIMAL;
    }

    alpha1 = -1.0 / obj->FMat[LD_diagOffset];
    subMatrixDim = (NColsRemain - lastDiag) - 2;
    for (b_k = 0; b_k <= subMatrixDim; b_k++) {
      obj->workspace_[b_k] = obj->FMat[(LD_diagOffset + b_k) + 1];
    }

    if (!(alpha1 == 0.0)) {
      int32_T jA;
      jA = (LD_diagOffset + LDimSizeP1) + 2;
      for (b_k = 0; b_k <= subMatrixDim; b_k++) {
        real_T temp;
        temp = obj->workspace_[b_k];
        if (temp != 0.0) {
          int32_T b;
          temp *= alpha1;
          b = subMatrixDim + jA;
          for (int32_T ijA{jA}; ijA <= b; ijA++) {
            obj->FMat[ijA - 1] += obj->workspace_[ijA - jA] * temp;
          }
        }

        jA += obj->ldm;
      }
    }

    alpha1 = 1.0 / obj->FMat[LD_diagOffset];
    b_k = LD_diagOffset + subMatrixDim;
    for (subMatrixDim = LD_diagOffset + 2; subMatrixDim <= b_k + 2; subMatrixDim
         ++) {
      obj->FMat[subMatrixDim - 1] *= alpha1;
    }
  }

  lastDiag = ((obj->ldm + 1) * (NColsRemain - 1) + LD_offset) - 1;
  if (std::abs(obj->FMat[lastDiag]) <= obj->regTol_) {
    obj->FMat[lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::xgemv_b4qt(int32_T m, int32_T n, const real_T A[100],
  int32_T ia0, int32_T lda, const real_T x[119], real_T y[7])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T ix;
    if (m - 1 >= 0) {
      std::memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * lda + ia0;
    for (int32_T b_iy{ia0}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      int32_T c;
      c = (b_iy + m) - 1;
      for (int32_T iyend{b_iy}; iyend <= c; iyend++) {
        int32_T tmp;
        tmp = iyend - b_iy;
        y[tmp] += A[iyend - 1] * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::compute_deltax(sBiFZCV7758PhXr6el0VfCD *solution,
  sTLNI0DWFUbeIRd2tl4OexC *memspace, const sH0q0JNg27eDMe5yMaNXg9D *qrmanager,
  sY5VKsxRLdcmJCLAY5aC9o *cholmanager, const slzZ8M58FXlZqTD433BZJUH *objective)
{
  real_T b_temp;
  int32_T ar;
  int32_T b_jA;
  int32_T br;
  int32_T c_ix;
  int32_T h;
  int32_T i;
  int32_T ix;
  int32_T lastColC;
  int32_T ldQ;
  int32_T mNull_tmp;
  int32_T nVar;
  int32_T nVars;
  int32_T nullStart;
  int32_T nullStartIdx;
  int32_T nullStartIdx_tmp;
  static const int8_T o[36]{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  int32_T exitg1;
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    if (qrmanager->mrows - 1 >= 0) {
      std::memset(&solution->searchDir[0], 0, static_cast<uint32_T>
                  ((qrmanager->mrows - 1) + 1) * sizeof(real_T));
    }
  } else {
    for (nullStartIdx = 0; nullStartIdx <= nVar; nullStartIdx++) {
      solution->searchDir[nullStartIdx] = -objective->grad[nullStartIdx];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        b_temp = 1.4901161193847656E-8 * cholmanager->scaleFactor * static_cast<
          real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (c_ix = 0; c_ix <= nVar; c_ix++) {
          nVars = (nVar + 1) * c_ix;
          ix = cholmanager->ldm * c_ix;
          for (nullStartIdx = 0; nullStartIdx <= nVar; nullStartIdx++) {
            cholmanager->FMat[ix + nullStartIdx] = o[nullStartIdx + nVars];
          }
        }

        c_ix = ixamax(qrmanager->mrows, cholmanager->FMat, cholmanager->ldm + 1)
          - 1;
        cholmanager->regTol_ = std::fmax(std::abs(cholmanager->FMat
          [cholmanager->ldm * c_ix + c_ix]) * 2.2204460492503131E-16, std::abs
          (b_temp));
        fullColLDL2_(cholmanager, 1, qrmanager->mrows, b_temp);
        if (cholmanager->ConvexCheck) {
          c_ix = 0;
          do {
            exitg1 = 0;
            if (c_ix <= nVar) {
              if (cholmanager->FMat[cholmanager->ldm * c_ix + c_ix] <= 0.0) {
                cholmanager->info = -c_ix - 1;
                exitg1 = 1;
              } else {
                c_ix++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          nVar = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (c_ix = 0; c_ix <= nVar; c_ix++) {
              ix = c_ix * cholmanager->ldm + c_ix;
              b_jA = nVar - c_ix;
              for (nullStartIdx = 0; nullStartIdx < b_jA; nullStartIdx++) {
                nullStart = (nullStartIdx + c_ix) + 1;
                solution->searchDir[nullStart] -= cholmanager->FMat
                  [(nullStartIdx + ix) + 1] * solution->searchDir[c_ix];
              }
            }
          }

          nullStartIdx = cholmanager->ndims;
          for (c_ix = 0; c_ix < nullStartIdx; c_ix++) {
            solution->searchDir[c_ix] /= cholmanager->FMat[cholmanager->ldm *
              c_ix + c_ix];
          }

          nVar = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (c_ix = nVar; c_ix >= 1; c_ix--) {
              nVars = (c_ix - 1) * cholmanager->ldm;
              b_temp = solution->searchDir[c_ix - 1];
              for (nullStartIdx = nVar; nullStartIdx >= c_ix + 1; nullStartIdx--)
              {
                b_temp -= cholmanager->FMat[(nVars + nullStartIdx) - 1] *
                  solution->searchDir[nullStartIdx - 1];
              }

              solution->searchDir[c_ix - 1] = b_temp;
            }
          }
        }
      }
    } else {
      nullStartIdx_tmp = qrmanager->ldq * qrmanager->ncols;
      nullStartIdx = nullStartIdx_tmp + 1;
      if (objective->objtype == 5) {
        for (nVars = 0; nVars < mNull_tmp; nVars++) {
          memspace->workspace_float[nVars] = -qrmanager->Q[(qrmanager->ncols +
            nVars) * qrmanager->ldq + nVar];
        }

        xgemv_b4qt(qrmanager->mrows, mNull_tmp, qrmanager->Q, nullStartIdx_tmp +
                   1, qrmanager->ldq, memspace->workspace_float,
                   solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          nVars = qrmanager->mrows;
          b_jA = cholmanager->ldm;
          ldQ = qrmanager->ldq;
          if ((qrmanager->mrows != 0) && (mNull_tmp != 0)) {
            br = nullStartIdx_tmp;
            lastColC = (mNull_tmp - 1) * 17;
            for (ix = 0; ix <= lastColC; ix += 17) {
              nullStart = ix + nVars;
              for (c_ix = ix + 1; c_ix <= nullStart; c_ix++) {
                memspace->workspace_float[c_ix - 1] = 0.0;
              }
            }

            for (ix = 0; ix <= lastColC; ix += 17) {
              ar = -1;
              h = br + nVars;
              for (c_ix = br + 1; c_ix <= h; c_ix++) {
                i = ix + nVars;
                for (nullStart = ix + 1; nullStart <= i; nullStart++) {
                  memspace->workspace_float[nullStart - 1] += static_cast<real_T>
                    (o[(ar + nullStart) - ix]) * qrmanager->Q[c_ix - 1];
                }

                ar += nVars;
              }

              br += ldQ;
            }
          }

          if (mNull_tmp != 0) {
            br = -1;
            lastColC = (mNull_tmp - 1) * cholmanager->ldm;
            for (ix = 0; b_jA < 0 ? ix >= lastColC : ix <= lastColC; ix += b_jA)
            {
              nullStart = ix + mNull_tmp;
              for (c_ix = ix + 1; c_ix <= nullStart; c_ix++) {
                cholmanager->FMat[c_ix - 1] = 0.0;
              }
            }

            for (ix = 0; b_jA < 0 ? ix >= lastColC : ix <= lastColC; ix += b_jA)
            {
              ar = nullStartIdx_tmp;
              h = ix + mNull_tmp;
              for (c_ix = ix + 1; c_ix <= h; c_ix++) {
                b_temp = 0.0;
                for (nullStart = 0; nullStart < nVars; nullStart++) {
                  b_temp += memspace->workspace_float[(nullStart + br) + 1] *
                    qrmanager->Q[nullStart + ar];
                }

                cholmanager->FMat[c_ix - 1] += b_temp;
                ar += ldQ;
              }

              br += 17;
            }
          }
        }

        b_temp = 1.4901161193847656E-8 * cholmanager->scaleFactor *
          static_cast<real_T>(mNull_tmp);
        cholmanager->ndims = mNull_tmp;
        nVars = ixamax(mNull_tmp, cholmanager->FMat, cholmanager->ldm + 1) - 1;
        cholmanager->regTol_ = std::fmax(std::abs(cholmanager->FMat
          [cholmanager->ldm * nVars + nVars]) * 2.2204460492503131E-16, std::abs
          (b_temp));
        fullColLDL2_(cholmanager, 1, mNull_tmp, b_temp);
        if (cholmanager->ConvexCheck) {
          nVars = 0;
          do {
            exitg1 = 0;
            if (nVars <= mNull_tmp - 1) {
              if (cholmanager->FMat[cholmanager->ldm * nVars + nVars] <= 0.0) {
                cholmanager->info = -nVars - 1;
                exitg1 = 1;
              } else {
                nVars++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          b_jA = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            std::memset(&memspace->workspace_float[0], 0, static_cast<uint32_T>
                        (mNull_tmp) * sizeof(real_T));
            ldQ = 0;
            nullStart = ((mNull_tmp - 1) * qrmanager->ldq + nullStartIdx_tmp) +
              1;
            for (nVars = nullStartIdx; b_jA < 0 ? nVars >= nullStart : nVars <=
                 nullStart; nVars += b_jA) {
              b_temp = 0.0;
              c_ix = nVars + nVar;
              for (ix = nVars; ix <= c_ix; ix++) {
                b_temp += qrmanager->Q[ix - 1] * objective->grad[ix - nVars];
              }

              memspace->workspace_float[ldQ] -= b_temp;
              ldQ++;
            }
          }

          ix = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (nVar = 0; nVar <= ix; nVar++) {
              ldQ = nVar * cholmanager->ldm + nVar;
              nullStart = ix - nVar;
              for (nVars = 0; nVars < nullStart; nVars++) {
                c_ix = (nVars + nVar) + 1;
                memspace->workspace_float[c_ix] -= cholmanager->FMat[(nVars +
                  ldQ) + 1] * memspace->workspace_float[nVar];
              }
            }
          }

          nVars = cholmanager->ndims;
          for (nVar = 0; nVar < nVars; nVar++) {
            memspace->workspace_float[nVar] /= cholmanager->FMat
              [cholmanager->ldm * nVar + nVar];
          }

          ix = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (nVar = ix; nVar >= 1; nVar--) {
              b_jA = (nVar - 1) * cholmanager->ldm;
              b_temp = memspace->workspace_float[nVar - 1];
              for (nVars = ix; nVars >= nVar + 1; nVars--) {
                b_temp -= cholmanager->FMat[(b_jA + nVars) - 1] *
                  memspace->workspace_float[nVars - 1];
              }

              memspace->workspace_float[nVar - 1] = b_temp;
            }
          }

          xgemv_b4qt(qrmanager->mrows, mNull_tmp, qrmanager->Q, nullStartIdx_tmp
                     + 1, qrmanager->ldq, memspace->workspace_float,
                     solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T QP_CA_Codegen::xnrm2_l(int32_T n, const real_T x[7])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[0]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      for (int32_T k{0}; k < n; k++) {
        real_T absxk;
        absxk = std::abs(x[k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::ratiotest(const real_T solution_xstar[7], const real_T
  solution_searchDir[7], const real_T workspace[119], int32_T workingset_nVar,
  const real_T workingset_lb[7], const real_T workingset_ub[7], const int32_T
  workingset_indexLB[7], const int32_T workingset_indexUB[7], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[17], const int32_T workingset_nWConstr[5], boolean_T
  isPhaseOne, real_T tolcon, real_T *toldelta, real_T toltau, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T alphaTemp;
  real_T alphaTemp_tmp;
  real_T denomTol;
  real_T p_max;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T pk_corrected;
  int32_T idx;
  int32_T totalIneq;
  int32_T totalUB;
  int32_T workingset_indexLB_0;
  p_max = 0.0;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol = 2.2204460492503131E-13 * xnrm2_l(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    for (idx = 0; idx < totalIneq; idx++) {
      phaseOneCorrectionX = workspace[idx + 17];
      if ((phaseOneCorrectionX > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + idx) - 1])) {
        phaseOneCorrectionP = workspace[idx];
        alphaTemp_tmp = tolcon - phaseOneCorrectionP;
        alphaTemp = std::fmin(std::abs(phaseOneCorrectionP - *toldelta),
                              alphaTemp_tmp + *toldelta) / phaseOneCorrectionX;
        if ((alphaTemp <= *alpha) && (std::abs(phaseOneCorrectionX) > p_max)) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }

        alphaTemp = std::fmin(std::abs(phaseOneCorrectionP), alphaTemp_tmp) /
          phaseOneCorrectionX;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = idx + 1;
          *newBlocking = true;
          p_max = std::abs(phaseOneCorrectionX);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * static_cast<
      real_T>(isPhaseOne);
    totalIneq = workingset_sizes[3];
    for (idx = 0; idx <= totalIneq - 2; idx++) {
      workingset_indexLB_0 = workingset_indexLB[idx];
      pk_corrected = -solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + idx) - 1])) {
        alphaTemp_tmp = -solution_xstar[workingset_indexLB_0 - 1] -
          workingset_lb[workingset_indexLB_0 - 1];
        alphaTemp = (alphaTemp_tmp - *toldelta) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), tolcon - alphaTemp) /
          pk_corrected;
        if ((alphaTemp <= *alpha) && (std::abs(pk_corrected) > p_max)) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }

        alphaTemp = alphaTemp_tmp - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), tolcon - alphaTemp) /
          pk_corrected;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
          p_max = std::abs(pk_corrected);
        }
      }
    }

    idx = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    phaseOneCorrectionX = solution_searchDir[idx];
    if ((-phaseOneCorrectionX > denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      alphaTemp_tmp = -solution_xstar[idx] - workingset_lb[idx];
      alphaTemp = alphaTemp_tmp - *toldelta;
      alphaTemp = std::fmin(std::abs(alphaTemp), tolcon - alphaTemp) /
        -phaseOneCorrectionX;
      if ((alphaTemp <= *alpha) && (std::abs(phaseOneCorrectionX) > p_max)) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      alphaTemp = std::fmin(std::abs(alphaTemp_tmp), tolcon - alphaTemp_tmp) /
        -phaseOneCorrectionX;
      if (alphaTemp < *alpha) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        p_max = std::abs(phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    for (idx = 0; idx < totalUB; idx++) {
      totalIneq = workingset_indexUB[idx];
      pk_corrected = solution_searchDir[totalIneq - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + idx) - 1])) {
        alphaTemp_tmp = solution_xstar[totalIneq - 1] - workingset_ub[totalIneq
          - 1];
        alphaTemp = (alphaTemp_tmp - *toldelta) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), tolcon - alphaTemp) /
          pk_corrected;
        if ((alphaTemp <= *alpha) && (std::abs(pk_corrected) > p_max)) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }

        alphaTemp = alphaTemp_tmp - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), tolcon - alphaTemp) /
          pk_corrected;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = idx + 1;
          *newBlocking = true;
          p_max = std::abs(pk_corrected);
        }
      }
    }
  }

  *toldelta += toltau;
  if (p_max > 0.0) {
    *alpha = std::fmax(*alpha, toltau / p_max);
  }

  if (isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.7976931348623157E+308))) &&
                    (*newBlocking));
    *alpha = std::fmin(*alpha, 1.7976931348623157E+308);
  } else {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    *alpha = std::fmin(*alpha, 1.0);
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::feasibleratiotest(const real_T solution_xstar[7], const
  real_T solution_searchDir[7], const real_T workspace[119], int32_T
  workingset_nVar, const real_T workingset_lb[7], const real_T workingset_ub[7],
  const int32_T workingset_indexLB[7], const int32_T workingset_indexUB[7],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T alphaTemp;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T ratio;
  int32_T idx;
  int32_T totalIneq;
  int32_T totalUB;
  int32_T workingset_indexLB_0;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol = 2.2204460492503131E-13 * xnrm2_l(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    for (idx = 0; idx < totalIneq; idx++) {
      ratio = workspace[idx + 17];
      if ((ratio > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + idx) - 1])) {
        alphaTemp = workspace[idx];
        alphaTemp = std::fmin(std::abs(alphaTemp), tolcon - alphaTemp) / ratio;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * static_cast<
      real_T>(isPhaseOne);
    totalIneq = workingset_sizes[3];
    for (idx = 0; idx <= totalIneq - 2; idx++) {
      workingset_indexLB_0 = workingset_indexLB[idx];
      alphaTemp = -solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((alphaTemp > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + idx) - 1])) {
        ratio = (-solution_xstar[workingset_indexLB_0 - 1] -
                 workingset_lb[workingset_indexLB_0 - 1]) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / alphaTemp;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }
      }
    }

    idx = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    alphaTemp = -solution_searchDir[idx];
    if ((alphaTemp > denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[idx] - workingset_lb[idx];
      alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / alphaTemp;
      if (alphaTemp < *alpha) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * static_cast<
      real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    for (idx = 0; idx < totalUB; idx++) {
      totalIneq = workingset_indexUB[idx];
      alphaTemp = solution_searchDir[totalIneq - 1] - phaseOneCorrectionP;
      if ((alphaTemp > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + idx) - 1])) {
        ratio = (solution_xstar[totalIneq - 1] - workingset_ub[totalIneq - 1]) -
          phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / alphaTemp;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    *alpha = std::fmin(*alpha, 1.0);
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::addBoundToActiveSetMatrix_(sAjQtoJYLWYGAxqZWOtnxYE *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * obj->ldA - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  if (idx_bnd_local - 2 >= 0) {
    std::memset(&obj->ATwset[colOffset + 1], 0, static_cast<uint32_T>
                (((idx_bnd_local + colOffset) - colOffset) - 1) * sizeof(real_T));
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  if (idx_bnd_local + 1 <= obj->nVar) {
    std::memset(&obj->ATwset[(idx_bnd_local + colOffset) + 1], 0,
                static_cast<uint32_T>(((obj->nVar + colOffset) - idx_bnd_local)
      - colOffset) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::compute_lambda(real_T workspace[119],
  sBiFZCV7758PhXr6el0VfCD *solution, const slzZ8M58FXlZqTD433BZJUH *objective,
  const sH0q0JNg27eDMe5yMaNXg9D *qrmanager)
{
  int32_T nActiveConstr_tmp_tmp;
  nActiveConstr_tmp_tmp = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    real_T c;
    int32_T b_idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      c = 100.0 * static_cast<real_T>(qrmanager->mrows) * 2.2204460492503131E-16;
      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2;
        b_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * qrmanager->ldq + qrmanager->mrows;
          while ((b_idx > qrmanager->mrows) && (std::abs(qrmanager->QR[idxQR - 1])
                  >= c)) {
            b_idx--;
            idxQR -= qrmanager->ldq;
          }

          nonDegenerate = (b_idx == qrmanager->mrows);
          if (!nonDegenerate) {
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          idxQR = (b_idx - 1) * qrmanager->ldq + b_idx;
          while ((b_idx >= 1) && (std::abs(qrmanager->QR[idxQR - 1]) >= c)) {
            b_idx--;
            idxQR = (idxQR - qrmanager->ldq) - 1;
          }

          nonDegenerate = (b_idx == 0);
        }
      }

      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      int32_T ix;
      int32_T jjA;
      b_idx = qrmanager->ldq;
      if ((qrmanager->mrows != 0) && (qrmanager->ncols != 0)) {
        if (qrmanager->ncols - 1 >= 0) {
          std::memset(&workspace[0], 0, static_cast<uint32_T>(qrmanager->ncols) *
                      sizeof(real_T));
        }

        jjA = 0;
        ix = (qrmanager->ncols - 1) * qrmanager->ldq + 1;
        for (idxQR = 1; b_idx < 0 ? idxQR >= ix : idxQR <= ix; idxQR += b_idx) {
          int32_T d;
          c = 0.0;
          d = (idxQR + qrmanager->mrows) - 1;
          for (int32_T iyend{idxQR}; iyend <= d; iyend++) {
            c += qrmanager->Q[iyend - 1] * objective->grad[iyend - idxQR];
          }

          workspace[jjA] += c;
          jjA++;
        }
      }

      if (qrmanager->ncols != 0) {
        for (idxQR = nActiveConstr_tmp_tmp; idxQR >= 1; idxQR--) {
          jjA = ((idxQR - 1) * b_idx + idxQR) - 2;
          workspace[idxQR - 1] /= qrmanager->QR[jjA + 1];
          for (int32_T iyend{0}; iyend <= idxQR - 2; iyend++) {
            ix = (idxQR - iyend) - 2;
            workspace[ix] -= workspace[idxQR - 1] * qrmanager->QR[jjA - iyend];
          }
        }
      }

      for (b_idx = 0; b_idx < nActiveConstr_tmp_tmp; b_idx++) {
        solution->lambda[b_idx] = -workspace[b_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::iterate(sBiFZCV7758PhXr6el0VfCD *solution,
  sTLNI0DWFUbeIRd2tl4OexC *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
  sH0q0JNg27eDMe5yMaNXg9D *qrmanager, sY5VKsxRLdcmJCLAY5aC9o *cholmanager,
  slzZ8M58FXlZqTD433BZJUH *objective, real_T options_PricingTolerance, real_T
  options_ObjectiveLimit, real_T options_ConstraintTolerance, real_T
  options_StepTolerance, int32_T runTimeOptions_MaxIterations, real_T
  runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  boolean_T runTimeOptions_RemainFeasible)
{
  real_T normDelta;
  real_T s;
  real_T temp;
  real_T tolDelta;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T b_iy;
  int32_T exitg1;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T iAw0;
  int32_T idxRotGCol;
  int32_T ix;
  int32_T iyend;
  int32_T j;
  int32_T nVar;
  boolean_T guard1;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  computeGrad_StoreHx(objective, solution->xstar);
  solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_float,
    solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  iyend = workingset->mConstrMax;
  if (workingset->mConstrMax - 1 >= 0) {
    std::memset(&solution->lambda[0], 0, static_cast<uint32_T>
                (workingset->mConstrMax) * sizeof(real_T));
  }

  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          iAw0 = (workingset->nActiveConstr - 1) * workingset->ldA;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          b_iy = qrmanager->ldq * qrmanager->ncols;
          ix = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            iyend = b_iy + qrmanager->mrows;
            if (b_iy + 1 <= iyend) {
              std::memset(&qrmanager->QR[b_iy], 0, static_cast<uint32_T>(iyend -
                b_iy) * sizeof(real_T));
            }

            i = (qrmanager->mrows - 1) * qrmanager->ldq + 1;
            for (idxRotGCol = 1; ix < 0 ? idxRotGCol >= i : idxRotGCol <= i;
                 idxRotGCol += ix) {
              normDelta = 0.0;
              j = (idxRotGCol + qrmanager->mrows) - 1;
              for (iyend = idxRotGCol; iyend <= j; iyend++) {
                normDelta += workingset->ATwset[(iAw0 + iyend) - idxRotGCol] *
                  qrmanager->Q[iyend - 1];
              }

              qrmanager->QR[b_iy] += normDelta;
              b_iy++;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          for (iyend = qrmanager->mrows - 2; iyend + 2 > qrmanager->ncols; iyend
               --) {
            i = (qrmanager->ncols - 1) * qrmanager->ldq + iyend;
            temp = qrmanager->QR[i + 1];
            xrotg(&qrmanager->QR[i], &temp, &normDelta, &s);
            qrmanager->QR[i + 1] = temp;
            idxRotGCol = qrmanager->ldq * iyend;
            iAw0 = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              ix = idxRotGCol;
              b_iy = qrmanager->ldq + idxRotGCol;
              for (idxRotGCol = 0; idxRotGCol < iAw0; idxRotGCol++) {
                i = b_iy + idxRotGCol;
                j = ix + idxRotGCol;
                temp = qrmanager->Q[j] * normDelta + qrmanager->Q[i] * s;
                qrmanager->Q[i] = qrmanager->Q[i] * normDelta - qrmanager->Q[j] *
                  s;
                qrmanager->Q[j] = temp;
              }
            }
          }
          break;

         case -1:
          deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;

         default:
          factorQR(qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr, workingset->ldA);
          computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        compute_deltax(solution, memspace, qrmanager, cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = xnrm2_l(nVar, solution->searchDir);
          guard1 = true;
        }
      } else {
        if (nVar - 1 >= 0) {
          std::memset(&solution->searchDir[0], 0, static_cast<uint32_T>(nVar) *
                      sizeof(real_T));
        }

        normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!subProblemChanged) || (normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= nVar)) {
          compute_lambda(memspace->workspace_float, solution, objective,
                         qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
            iyend = 0;
            normDelta = options_PricingTolerance *
              runTimeOptions_ProbRelTolFactor * static_cast<real_T>(TYPE != 5);
            iAw0 = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
            ix = workingset->nActiveConstr;
            for (idxRotGCol = iAw0; idxRotGCol <= ix; idxRotGCol++) {
              temp = solution->lambda[idxRotGCol - 1];
              if (temp < normDelta) {
                normDelta = temp;
                iyend = idxRotGCol;
              }
            }

            if (iyend == 0) {
              solution->state = 1;
            } else {
              activeSetChangeID = -1;
              globalActiveConstrIdx = iyend;
              subProblemChanged = true;
              removeConstr(workingset, iyend);
              if (iyend < workingset->nActiveConstr + 1) {
                solution->lambda[iyend - 1] = solution->lambda
                  [workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            iyend = workingset->nActiveConstr;
            activeSetChangeID = 0;
            globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[iyend - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            feasibleratiotest(solution->xstar, solution->searchDir,
                              memspace->workspace_float, workingset->nVar,
                              workingset->lb, workingset->ub,
                              workingset->indexLB, workingset->indexUB,
                              workingset->sizes, workingset->isActiveIdx,
                              workingset->isActiveConstr, workingset->nWConstr,
                              updateFval, options_ConstraintTolerance,
                              &normDelta, &newBlocking, &iyend, &idxRotGCol);
          } else {
            ratiotest(solution->xstar, solution->searchDir,
                      memspace->workspace_float, workingset->nVar,
                      workingset->lb, workingset->ub, workingset->indexLB,
                      workingset->indexUB, workingset->sizes,
                      workingset->isActiveIdx, workingset->isActiveConstr,
                      workingset->nWConstr, false, options_ConstraintTolerance,
                      &tolDelta, 6.608625846508183E-7, &normDelta, &newBlocking,
                      &iyend, &idxRotGCol);
          }

          if (newBlocking) {
            switch (iyend) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                idxRotGCol) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] = idxRotGCol;
              break;

             case 4:
              addBoundToActiveSetMatrix_(workingset, 4, idxRotGCol);
              break;

             default:
              addBoundToActiveSetMatrix_(workingset, 5, idxRotGCol);
              break;
            }

            activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (xnrm2_l(objective->nvar, solution->searchDir) > 100.0 *
                  static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
              {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if ((nVar >= 1) && (!(normDelta == 0.0))) {
            for (idxRotGCol = 0; idxRotGCol < nVar; idxRotGCol++) {
              solution->xstar[idxRotGCol] += normDelta * solution->
                searchDir[idxRotGCol];
            }
          }

          computeGrad_StoreHx(objective, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        iyend = objective->nvar - 1;
        if ((solution->iterations >= runTimeOptions_MaxIterations) &&
            ((solution->state != 1) || (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = maxConstraintViolation_e(workingset,
            solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            normDelta = solution->maxConstr - solution->xstar[objective->nvar -
              1];
          }

          if (normDelta > options_ConstraintTolerance *
              runTimeOptions_ConstrRelTolFact) {
            if (objective->nvar - 1 >= 0) {
              std::memcpy(&solution->searchDir[0], &solution->xstar[0],
                          static_cast<uint32_T>((objective->nvar - 1) + 1) *
                          sizeof(real_T));
            }

            newBlocking = feasibleX0ForWorkingSet(memspace->workspace_float,
              solution->searchDir, workingset, qrmanager);
            if ((!newBlocking) && (solution->state != 0)) {
              solution->state = -2;
            }

            activeSetChangeID = 0;
            normDelta = maxConstraintViolation_e(workingset, solution->searchDir);
            if (normDelta < solution->maxConstr) {
              if (objective->nvar - 1 >= 0) {
                std::memcpy(&solution->xstar[0], &solution->searchDir[0],
                            static_cast<uint32_T>((objective->nvar - 1) + 1) *
                            sizeof(real_T));
              }

              solution->maxConstr = normDelta;
            }
          }
        }

        if (updateFval) {
          if (options_ObjectiveLimit > (rtMinusInf)) {
            solution->fstar = computeFval_ReuseHx(objective,
              memspace->workspace_float, solution->xstar);
            if ((solution->fstar < options_ObjectiveLimit) && ((solution->state
                  != 0) || (objective->objtype != 5))) {
              solution->state = 2;
            }
          } else {
            updateFval = false;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(objective,
          memspace->workspace_float, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::PresolveWorkingSet_e(sBiFZCV7758PhXr6el0VfCD *solution,
  sTLNI0DWFUbeIRd2tl4OexC *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
  sH0q0JNg27eDMe5yMaNXg9D *qrmanager, const sDROcIZ6ilexqwOTaATsaxG *options)
{
  real_T constrViolation;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T ix0;
  int32_T iy0;
  int32_T mTotalWorkingEq;
  int32_T mTotalWorkingEq_tmp_tmp;
  int32_T mWorkingFixed;
  int32_T nVar;
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  nVar = workingset->nVar - 1;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  idxStartIneq = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    for (idxStartIneq = 0; idxStartIneq < mTotalWorkingEq_tmp_tmp; idxStartIneq
         ++) {
      for (idxEndIneq = 0; idxEndIneq <= nVar; idxEndIneq++) {
        qrmanager->QR[idxStartIneq + qrmanager->ldq * idxEndIneq] =
          workingset->ATwset[workingset->ldA * idxStartIneq + idxEndIneq];
      }
    }

    idxStartIneq = ComputeNumDependentEq_(qrmanager, workingset->bwset,
      mTotalWorkingEq_tmp_tmp, workingset->nVar);
    if (idxStartIneq > 0) {
      for (idxEndIneq = 0; idxEndIneq < mTotalWorkingEq_tmp_tmp; idxEndIneq++) {
        iy0 = qrmanager->ldq * idxEndIneq;
        ix0 = workingset->ldA * idxEndIneq;
        for (mTotalWorkingEq = 0; mTotalWorkingEq <= nVar; mTotalWorkingEq++) {
          qrmanager->QR[iy0 + mTotalWorkingEq] = workingset->
            ATwset[mTotalWorkingEq + ix0];
        }
      }

      for (idxEndIneq = 0; idxEndIneq < mWorkingFixed; idxEndIneq++) {
        qrmanager->jpvt[idxEndIneq] = 1;
      }

      mTotalWorkingEq = workingset->nWConstr[0] + 1;
      if (mTotalWorkingEq <= mTotalWorkingEq_tmp_tmp) {
        std::memset(&qrmanager->jpvt[mTotalWorkingEq + -1], 0,
                    static_cast<uint32_T>((mTotalWorkingEq_tmp_tmp -
          mTotalWorkingEq) + 1) * sizeof(int32_T));
      }

      factorQRE(qrmanager, workingset->nVar, mTotalWorkingEq_tmp_tmp);
      for (idxEndIneq = 0; idxEndIneq < idxStartIneq; idxEndIneq++) {
        memspace->workspace_int[idxEndIneq] = qrmanager->jpvt
          [(mTotalWorkingEq_tmp_tmp - idxStartIneq) + idxEndIneq];
      }

      countsort(memspace->workspace_int, idxStartIneq, memspace->workspace_sort,
                1, mTotalWorkingEq_tmp_tmp);
      for (mTotalWorkingEq = idxStartIneq; mTotalWorkingEq >= 1; mTotalWorkingEq
           --) {
        removeEqConstr(workingset, memspace->workspace_int[mTotalWorkingEq - 1]);
      }
    }
  }

  if ((idxStartIneq != -1) && (workingset->nActiveConstr <= qrmanager->ldq)) {
    RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = feasibleX0ForWorkingSet(memspace->workspace_float,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = feasibleX0ForWorkingSet(memspace->workspace_float,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        constrViolation = maxConstraintViolation_e(workingset, solution->xstar);
        if (constrViolation > options->ConstraintTolerance) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    idxStartIneq = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
    idxEndIneq = workingset->nActiveConstr;
    for (mTotalWorkingEq = idxStartIneq; mTotalWorkingEq <= idxEndIneq;
         mTotalWorkingEq++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[mTotalWorkingEq - 1] - 1] + workingset->Wlocalidx[mTotalWorkingEq -
        1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::computeFirstOrderOpt(sBiFZCV7758PhXr6el0VfCD *solution,
  const slzZ8M58FXlZqTD433BZJUH *objective, int32_T workingset_nVar, int32_T
  workingset_ldA, const real_T workingset_ATwset[119], int32_T
  workingset_nActiveConstr, real_T workspace[119])
{
  real_T infNorm;
  int32_T k;
  boolean_T exitg1;
  infNorm = 0.0;
  if (workingset_nVar - 1 >= 0) {
    std::memcpy(&workspace[0], &objective->grad[0], static_cast<uint32_T>
                (workingset_nVar) * sizeof(real_T));
  }

  if ((workingset_nVar != 0) && (workingset_nActiveConstr != 0)) {
    int32_T b;
    int32_T ix;
    ix = 0;
    b = (workingset_nActiveConstr - 1) * workingset_ldA + 1;
    for (k = 1; workingset_ldA < 0 ? k >= b : k <= b; k += workingset_ldA) {
      int32_T d;
      d = (k + workingset_nVar) - 1;
      for (int32_T nVar{k}; nVar <= d; nVar++) {
        int32_T tmp;
        tmp = nVar - k;
        workspace[tmp] += workingset_ATwset[nVar - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= workingset_nVar - 1)) {
    real_T abs_workspace_i;
    abs_workspace_i = std::abs(workspace[k]);
    if (std::isnan(abs_workspace_i)) {
      infNorm = (rtNaN);
      exitg1 = true;
    } else {
      infNorm = std::fmax(infNorm, abs_workspace_i);
      k++;
    }
  }

  solution->firstorderopt = infNorm;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::driver(sBiFZCV7758PhXr6el0VfCD *solution,
  sTLNI0DWFUbeIRd2tl4OexC *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
  sY5VKsxRLdcmJCLAY5aC9o *cholmanager, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  sH0q0JNg27eDMe5yMaNXg9D *qrmanager, slzZ8M58FXlZqTD433BZJUH *objective)
{
  sAjQtoJYLWYGAxqZWOtnxYE b_workingset;
  sDROcIZ6ilexqwOTaATsaxG options;
  real_T oldObjLim;
  int32_T b_idxStartIneq;
  int32_T b_idxStartIneq_tmp;
  int32_T i;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T mConstr;
  boolean_T b_bool;
  static const char_T g_FiniteDifferenceType[7]{ 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T g_Algorithm[10]{ 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T g_SolverName[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  static const char_T h[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  int32_T b_idxEndIneq_tmp_tmp;
  int32_T exitg2;
  boolean_T exitg1;
  boolean_T guard1;
  for (i = 0; i < 7; i++) {
    objective->grad[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    objective->Hx[i] = 0.0;
  }

  objective->hasLinear = true;
  objective->nvar = 6;
  objective->maxVar = 7;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  i = workingset->nVar - 1;
  idxStartIneq = workingset->sizes[0];
  for (mConstr = 0; mConstr < idxStartIneq; mConstr++) {
    solution->xstar[workingset->indexFixed[mConstr] - 1] = workingset->
      ub[workingset->indexFixed[mConstr] - 1];
  }

  idxStartIneq = workingset->sizes[3];
  for (mConstr = 0; mConstr < idxStartIneq; mConstr++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + mConstr) - 1])
    {
      solution->xstar[workingset->indexLB[mConstr] - 1] = -workingset->
        lb[workingset->indexLB[mConstr] - 1];
    }
  }

  idxStartIneq = workingset->sizes[4];
  for (mConstr = 0; mConstr < idxStartIneq; mConstr++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] + mConstr) - 1])
    {
      solution->xstar[workingset->indexUB[mConstr] - 1] = workingset->
        ub[workingset->indexUB[mConstr] - 1];
    }
  }

  PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  options.NonFiniteSupport = true;
  options.IterDisplaySQP = false;
  options.InitDamping = 0.01;
  for (b_idxStartIneq_tmp = 0; b_idxStartIneq_tmp < 7; b_idxStartIneq_tmp++) {
    options.FiniteDifferenceType[b_idxStartIneq_tmp] =
      g_FiniteDifferenceType[b_idxStartIneq_tmp];
  }

  options.SpecifyObjectiveGradient = false;
  options.ScaleProblem = false;
  options.SpecifyConstraintGradient = false;
  options.FiniteDifferenceStepSize = -1.0;
  options.MaxFunctionEvaluations = -1.0;
  options.IterDisplayQP = false;
  options.PricingTolerance = 0.0;
  for (b_idxStartIneq_tmp = 0; b_idxStartIneq_tmp < 10; b_idxStartIneq_tmp++) {
    options.Algorithm[b_idxStartIneq_tmp] = g_Algorithm[b_idxStartIneq_tmp];
  }

  options.ObjectiveLimit = -1.0E+20;
  options.ConstraintTolerance = 1.0E-8;
  options.OptimalityTolerance = 1.0E-8;
  options.StepTolerance = 1.0E-8;
  options.MaxIterations = -1.0;
  options.FunctionTolerance = (rtInf);
  for (b_idxStartIneq_tmp = 0; b_idxStartIneq_tmp < 8; b_idxStartIneq_tmp++) {
    options.SolverName[b_idxStartIneq_tmp] = g_SolverName[b_idxStartIneq_tmp];
  }

  options.CheckGradients = false;
  options.Diagnostics[0] = 'o';
  options.Diagnostics[1] = 'f';
  options.Diagnostics[2] = 'f';
  options.DiffMaxChange = (rtInf);
  options.DiffMinChange = 0.0;
  options.Display[0] = 'n';
  options.Display[1] = 'o';
  options.Display[2] = 'n';
  options.Display[3] = 'e';
  options.FunValCheck[0] = 'o';
  options.FunValCheck[1] = 'f';
  options.FunValCheck[2] = 'f';
  options.UseParallel = false;
  options.LinearSolver[0] = 'a';
  options.LinearSolver[1] = 'u';
  options.LinearSolver[2] = 't';
  options.LinearSolver[3] = 'o';
  options.SubproblemAlgorithm[0] = 'c';
  options.SubproblemAlgorithm[1] = 'g';
  if (solution->state >= 0) {
    solution->iterations = 0;
    solution->maxConstr = maxConstraintViolation_e(workingset, solution->xstar);
    guard1 = false;
    if (solution->maxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
      solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
      b_workingset = *workingset;
      if (workingset->probType == 3) {
        b_idxStartIneq_tmp = 1;
      } else {
        b_idxStartIneq_tmp = 4;
      }

      setProblemType(&b_workingset, b_idxStartIneq_tmp);
      idxStartIneq = (b_workingset.nWConstr[0] + b_workingset.nWConstr[1]) + 1;
      idxEndIneq = b_workingset.nActiveConstr;
      for (mConstr = idxStartIneq; mConstr <= idxEndIneq; mConstr++) {
        b_workingset.isActiveConstr
          [(b_workingset.isActiveIdx[b_workingset.Wid[mConstr - 1] - 1] +
            b_workingset.Wlocalidx[mConstr - 1]) - 2] = false;
      }

      b_workingset.nWConstr[2] = 0;
      b_workingset.nWConstr[3] = 0;
      b_workingset.nWConstr[4] = 0;
      b_workingset.nActiveConstr = b_workingset.nWConstr[0] +
        b_workingset.nWConstr[1];
      objective->prev_objtype = 3;
      objective->prev_nvar = 6;
      objective->prev_hasLinear = true;
      objective->objtype = 5;
      objective->nvar = workingset->nVar + 1;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      options.ObjectiveLimit = 1.0E-8 * runTimeOptions_ConstrRelTolFact;
      solution->fstar = computeFval(objective, memspace->workspace_float,
        solution->xstar);
      solution->state = 5;
      iterate(solution, memspace, &b_workingset, qrmanager, cholmanager,
              objective, 0.0, options.ObjectiveLimit, 1.0E-8,
              1.4901161193847657E-10, runTimeOptions_MaxIterations,
              runTimeOptions_ConstrRelTolFact, runTimeOptions_ProbRelTolFactor,
              true);
      if (b_workingset.isActiveConstr[(b_workingset.isActiveIdx[3] +
           b_workingset.sizes[3]) - 2]) {
        mConstr = b_workingset.sizes[0] + b_workingset.sizes[1];
        exitg1 = false;
        while ((!exitg1) && (mConstr + 1 <= b_workingset.nActiveConstr)) {
          if ((b_workingset.Wid[mConstr] == 4) &&
              (b_workingset.Wlocalidx[mConstr] == b_workingset.sizes[3])) {
            removeConstr(&b_workingset, mConstr + 1);
            exitg1 = true;
          } else {
            mConstr++;
          }
        }
      }

      mConstr = b_workingset.nActiveConstr;
      idxStartIneq = b_workingset.sizes[0] + b_workingset.sizes[1];
      while ((mConstr > idxStartIneq) && (mConstr > workingset->nVar)) {
        removeConstr(&b_workingset, mConstr);
        mConstr--;
      }

      solution->maxConstr = solution->xstar[workingset->nVar];
      setProblemType(&b_workingset, workingset->probType);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      options.ObjectiveLimit = -1.0E+20;
      options.StepTolerance = 1.0E-8;
      *workingset = b_workingset;
      if (solution->state == 0) {
      } else {
        solution->maxConstr = maxConstraintViolation_e(&b_workingset,
          solution->xstar);
        *workingset = b_workingset;
        if (solution->maxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
          if (b_workingset.mConstrMax - 1 >= 0) {
            std::memset(&solution->lambda[0], 0, static_cast<uint32_T>
                        (b_workingset.mConstrMax) * sizeof(real_T));
          }

          solution->fstar = computeFval(objective, memspace->workspace_float,
            solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            if (i >= 0) {
              std::memcpy(&solution->searchDir[0], &solution->xstar[0],
                          static_cast<uint32_T>(i + 1) * sizeof(real_T));
            }

            PresolveWorkingSet_e(solution, memspace, &b_workingset, qrmanager,
                                 &options);
            *workingset = b_workingset;
            oldObjLim = maxConstraintViolation_e(workingset, solution->xstar);
            if (oldObjLim >= solution->maxConstr) {
              solution->maxConstr = oldObjLim;
              if (i >= 0) {
                std::memcpy(&solution->xstar[0], &solution->searchDir[0],
                            static_cast<uint32_T>(i + 1) * sizeof(real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      iterate(solution, memspace, workingset, qrmanager, cholmanager, objective,
              0.0, -1.0E+20, 1.0E-8, 1.0E-8, runTimeOptions_MaxIterations,
              runTimeOptions_ConstrRelTolFact, runTimeOptions_ProbRelTolFactor,
              true);
      b_bool = false;
      i = 0;
      do {
        exitg2 = 0;
        if (i < 8) {
          if (h[static_cast<int32_T>(options.SolverName[i])] != h
              [static_cast<int32_T>(g_SolverName[i])]) {
            exitg2 = 1;
          } else {
            i++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (b_bool && (solution->state != -6)) {
        solution->maxConstr = maxConstraintViolation_e(workingset,
          solution->xstar);
        computeFirstOrderOpt(solution, objective, workingset->nVar,
                             workingset->ldA, workingset->ATwset,
                             workingset->nActiveConstr,
                             memspace->workspace_float);
        while ((solution->iterations < runTimeOptions_MaxIterations) &&
               ((solution->state == -7) || ((solution->state == 1) &&
                 ((solution->maxConstr > 1.0E-8 *
                   runTimeOptions_ConstrRelTolFact) || (solution->firstorderopt >
                   1.0E-8 * runTimeOptions_ProbRelTolFactor))))) {
          feasibleX0ForWorkingSet(memspace->workspace_float, solution->xstar,
            workingset, qrmanager);
          PresolveWorkingSet_e(solution, memspace, workingset, qrmanager,
                               &options);
          mConstr = workingset->probType;
          idxStartIneq = workingset->nVar;
          idxEndIneq = workingset->nVar;
          solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
          if (workingset->probType == 3) {
            b_idxStartIneq_tmp = 1;
          } else {
            b_idxStartIneq_tmp = 4;
          }

          setProblemType(workingset, b_idxStartIneq_tmp);
          b_idxStartIneq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
          b_idxStartIneq = b_idxStartIneq_tmp + 1;
          b_idxEndIneq_tmp_tmp = workingset->nActiveConstr;
          for (i = b_idxStartIneq; i <= b_idxEndIneq_tmp_tmp; i++) {
            workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
              Wid[i - 1] - 1] + workingset->Wlocalidx[i - 1]) - 2] = false;
          }

          workingset->nWConstr[2] = 0;
          workingset->nWConstr[3] = 0;
          workingset->nWConstr[4] = 0;
          workingset->nActiveConstr = b_idxStartIneq_tmp;
          objective->prev_objtype = objective->objtype;
          objective->prev_nvar = objective->nvar;
          objective->prev_hasLinear = objective->hasLinear;
          objective->objtype = 5;
          objective->nvar = idxEndIneq + 1;
          objective->gammaScalar = 1.0;
          objective->hasLinear = true;
          options.ObjectiveLimit = 1.0E-8 * runTimeOptions_ConstrRelTolFact;
          solution->fstar = computeFval(objective, memspace->workspace_float,
            solution->xstar);
          solution->state = 5;
          iterate(solution, memspace, workingset, qrmanager, cholmanager,
                  objective, 0.0, options.ObjectiveLimit, 1.0E-8,
                  1.4901161193847657E-10, runTimeOptions_MaxIterations,
                  runTimeOptions_ConstrRelTolFact,
                  runTimeOptions_ProbRelTolFactor, false);
          if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
               workingset->sizes[3]) - 2]) {
            i = workingset->sizes[0] + workingset->sizes[1];
            exitg1 = false;
            while ((!exitg1) && (i + 1 <= workingset->nActiveConstr)) {
              if ((workingset->Wid[i] == 4) && (workingset->Wlocalidx[i] ==
                   workingset->sizes[3])) {
                removeConstr(workingset, i + 1);
                exitg1 = true;
              } else {
                i++;
              }
            }
          }

          i = workingset->nActiveConstr;
          b_idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
          while ((i > b_idxStartIneq) && (i > idxStartIneq)) {
            removeConstr(workingset, i);
            i--;
          }

          solution->maxConstr = solution->xstar[idxEndIneq];
          setProblemType(workingset, mConstr);
          objective->objtype = objective->prev_objtype;
          objective->nvar = objective->prev_nvar;
          objective->hasLinear = objective->prev_hasLinear;
          options.ObjectiveLimit = -1.0E+20;
          iterate(solution, memspace, workingset, qrmanager, cholmanager,
                  objective, 0.0, -1.0E+20, 1.0E-8, 1.0E-8,
                  runTimeOptions_MaxIterations, runTimeOptions_ConstrRelTolFact,
                  runTimeOptions_ProbRelTolFactor, false);
          solution->maxConstr = maxConstraintViolation_e(workingset,
            solution->xstar);
          computeFirstOrderOpt(solution, objective, workingset->nVar,
                               workingset->ldA, workingset->ATwset,
                               workingset->nActiveConstr,
                               memspace->workspace_float);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void QP_CA_Codegen::linearForm__g(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[7], const real_T x[7])
{
  int32_T beta1;
  static const int8_T e[36]{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  beta1 = 0;
  if (obj_hasLinear) {
    if (obj_nvar - 1 >= 0) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>(obj_nvar) * sizeof
                  (real_T));
    }

    beta1 = 1;
  }

  if (obj_nvar != 0) {
    int32_T c;
    int32_T ix;
    if ((beta1 != 1) && (obj_nvar - 1 >= 0)) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>(obj_nvar) * sizeof
                  (real_T));
    }

    ix = 0;
    c = (obj_nvar - 1) * obj_nvar + 1;
    for (int32_T iyend{1}; obj_nvar < 0 ? iyend >= c : iyend <= c; iyend +=
         obj_nvar) {
      int32_T d;
      d = (iyend + obj_nvar) - 1;
      for (beta1 = iyend; beta1 <= d; beta1++) {
        int32_T tmp;
        tmp = beta1 - iyend;
        workspace[tmp] += static_cast<real_T>(e[beta1 - 1]) * x[ix];
      }

      ix++;
    }
  }
}

// Model step function
void QP_CA_Codegen::step()
{
  sAjQtoJYLWYGAxqZWOtnxYE WorkingSet;
  sBiFZCV7758PhXr6el0VfCD solution;
  sH0q0JNg27eDMe5yMaNXg9D QRManager;
  sTLNI0DWFUbeIRd2tl4OexC memspace;
  slzZ8M58FXlZqTD433BZJUH QPObjective;
  real_T rtb_thrust_setpoints[6];
  real_T tmp[4];
  real_T a__2;
  real_T b_colSum;
  real_T colSum;
  int32_T c_i;
  int32_T colOffsetATw;
  int32_T g;
  int32_T i;
  int32_T iATw0;
  int32_T iAeq0;
  int32_T idxFillStart;
  int32_T idx_global;
  int32_T mFixed;
  int32_T mUB;
  int32_T nWeq;
  static const int8_T H[36]{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  boolean_T exitg1;

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain1'
  //   Gain: '<Root>/Gain2'
  //   Gain: '<Root>/Gain3'
  //   Inport: '<Root>/failure_status'
  //   Inport: '<Root>/heaven_acceleration_sp'
  //   Inport: '<Root>/pitch_angular_accleration_sp'
  //   Inport: '<Root>/roll_angualr_acceleration_sp'
  //   Inport: '<Root>/yaw_angular_accleration_sp'

  for (i = 0; i < 6; i++) {
    rtb_thrust_setpoints[i] = 5.0 * rtU.failure_status[i];
  }

  a__2 = (rtInf);
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 6)) {
    if (rtb_thrust_setpoints[i] < 0.0) {
      a__2 = -2.0;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (a__2 == -2.0) {
    for (i = 0; i < 6; i++) {
      rtb_thrust_setpoints[i] = 0.0;
    }
  } else {
    solution.fstar = 0.0;
    solution.firstorderopt = 0.0;
    std::memset(&solution.lambda[0], 0, 17U * sizeof(real_T));
    solution.state = 0;
    solution.maxConstr = 0.0;
    solution.iterations = 0;
    for (i = 0; i < 7; i++) {
      solution.searchDir[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      solution.xstar[i] = 0.0;
    }

    rtDW.CholRegManager.ldm = 10;
    rtDW.CholRegManager.ndims = 0;
    rtDW.CholRegManager.info = 0;
    rtDW.CholRegManager.ConvexCheck = true;
    rtDW.CholRegManager.regTol_ = 0.0;
    rtDW.CholRegManager.scaleFactor = 100.0;
    WorkingSet.mConstr = 0;
    WorkingSet.mConstrOrig = 0;
    WorkingSet.mConstrMax = 17;
    WorkingSet.nVar = 6;
    WorkingSet.nVarOrig = 6;
    WorkingSet.nVarMax = 7;
    WorkingSet.ldA = 7;
    std::memset(&WorkingSet.Aeq[0], 0, 28U * sizeof(real_T));
    WorkingSet.beq[0] = 0.0;
    WorkingSet.beq[1] = 0.0;
    WorkingSet.beq[2] = 0.0;
    WorkingSet.beq[3] = 0.0;
    for (i = 0; i < 7; i++) {
      WorkingSet.lb[i] = 0.0;
      WorkingSet.ub[i] = 0.0;
    }

    WorkingSet.mEqRemoved = 0;
    WorkingSet.indexEqRemoved[0] = 0;
    WorkingSet.indexEqRemoved[1] = 0;
    WorkingSet.indexEqRemoved[2] = 0;
    WorkingSet.indexEqRemoved[3] = 0;
    std::memset(&WorkingSet.ATwset[0], 0, 119U * sizeof(real_T));
    WorkingSet.nActiveConstr = 0;
    std::memset(&WorkingSet.bwset[0], 0, 17U * sizeof(real_T));
    std::memset(&WorkingSet.maxConstrWorkspace[0], 0, 17U * sizeof(real_T));
    for (i = 0; i < 5; i++) {
      WorkingSet.sizes[i] = 0;
      WorkingSet.sizesNormal[i] = 0;
      WorkingSet.sizesPhaseOne[i] = 0;
      WorkingSet.sizesRegularized[i] = 0;
      WorkingSet.sizesRegPhaseOne[i] = 0;
    }

    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdx[i] = 0;
      WorkingSet.isActiveIdxNormal[i] = 0;
      WorkingSet.isActiveIdxPhaseOne[i] = 0;
      WorkingSet.isActiveIdxRegularized[i] = 0;
      WorkingSet.isActiveIdxRegPhaseOne[i] = 0;
    }

    std::memset(&WorkingSet.Wid[0], 0, 17U * sizeof(int32_T));
    std::memset(&WorkingSet.Wlocalidx[0], 0, 17U * sizeof(int32_T));
    for (i = 0; i < 17; i++) {
      WorkingSet.isActiveConstr[i] = false;
    }

    for (i = 0; i < 5; i++) {
      WorkingSet.nWConstr[i] = 0;
    }

    WorkingSet.probType = 3;
    WorkingSet.SLACK0 = 1.0E-5;
    for (i = 0; i < 7; i++) {
      WorkingSet.indexLB[i] = 0;
      WorkingSet.indexUB[i] = 0;
      WorkingSet.indexFixed[i] = 0;
    }

    i = 0;
    mUB = 0;
    mFixed = 0;
    for (idxFillStart = 0; idxFillStart < 6; idxFillStart++) {
      a__2 = rtb_thrust_setpoints[idxFillStart];
      if (std::abs(0.0 - a__2) < 1.0E-8) {
        mFixed++;
        WorkingSet.indexFixed[mFixed - 1] = idxFillStart + 1;
      } else {
        i++;
        WorkingSet.indexLB[i - 1] = idxFillStart + 1;
        if ((!std::isinf(a__2)) && (!std::isnan(a__2))) {
          mUB++;
          WorkingSet.indexUB[mUB - 1] = idxFillStart + 1;
        }
      }
    }

    tmp[0] = 2.06 * rtU.heaven_acceleration_sp;
    tmp[1] = 0.031017 * rtU.roll_angualr_acceleration_sp;
    tmp[2] = 0.032193 * rtU.pitch_angular_accleration_sp;
    tmp[3] = 0.053802 * rtU.yaw_angular_accleration_sp;
    loadProblem(&WorkingSet, rtConstP.Constant1_Value, tmp, i, mUB,
                rtb_thrust_setpoints, mFixed);
    setProblemType(&WorkingSet, 3);
    idxFillStart = WorkingSet.isActiveIdx[2];
    if (idxFillStart <= WorkingSet.mConstrMax) {
      std::memset(&WorkingSet.isActiveConstr[idxFillStart + -1], 0, static_cast<
                  uint32_T>((WorkingSet.mConstrMax - idxFillStart) + 1) * sizeof
                  (boolean_T));
    }

    WorkingSet.nWConstr[0] = WorkingSet.sizes[0];
    WorkingSet.nWConstr[1] = WorkingSet.sizes[1];
    WorkingSet.nWConstr[2] = 0;
    WorkingSet.nWConstr[3] = 0;
    WorkingSet.nWConstr[4] = 0;
    WorkingSet.nActiveConstr = WorkingSet.nWConstr[0] + WorkingSet.nWConstr[1];
    idxFillStart = WorkingSet.sizes[0];
    for (nWeq = 0; nWeq < idxFillStart; nWeq++) {
      WorkingSet.Wid[nWeq] = 1;
      WorkingSet.Wlocalidx[nWeq] = nWeq + 1;
      WorkingSet.isActiveConstr[nWeq] = true;
      colOffsetATw = WorkingSet.ldA * nWeq;
      idx_global = WorkingSet.indexFixed[nWeq];
      if (idx_global - 2 >= 0) {
        std::memset(&WorkingSet.ATwset[colOffsetATw], 0, static_cast<uint32_T>
                    (((idx_global + colOffsetATw) - colOffsetATw) - 1) * sizeof
                    (real_T));
      }

      WorkingSet.ATwset[(WorkingSet.indexFixed[nWeq] + colOffsetATw) - 1] = 1.0;
      idx_global = WorkingSet.indexFixed[nWeq] + 1;
      if (idx_global <= WorkingSet.nVar) {
        std::memset(&WorkingSet.ATwset[(idx_global + colOffsetATw) + -1], 0,
                    static_cast<uint32_T>((((WorkingSet.nVar + colOffsetATw) -
          idx_global) - colOffsetATw) + 1) * sizeof(real_T));
      }

      WorkingSet.bwset[nWeq] = WorkingSet.ub[WorkingSet.indexFixed[nWeq] - 1];
    }

    nWeq = WorkingSet.sizes[1];
    for (colOffsetATw = 0; colOffsetATw < nWeq; colOffsetATw++) {
      idx_global = idxFillStart + colOffsetATw;
      WorkingSet.Wid[idx_global] = 2;
      WorkingSet.Wlocalidx[idx_global] = colOffsetATw + 1;
      WorkingSet.isActiveConstr[idx_global] = true;
      iAeq0 = WorkingSet.ldA * colOffsetATw;
      iATw0 = WorkingSet.ldA * idx_global;
      g = WorkingSet.nVar - 1;
      for (c_i = 0; c_i <= g; c_i++) {
        WorkingSet.ATwset[iATw0 + c_i] = WorkingSet.Aeq[iAeq0 + c_i];
      }

      WorkingSet.bwset[idx_global] = WorkingSet.beq[colOffsetATw];
    }

    WorkingSet.SLACK0 = 0.0;
    a__2 = 1.0;
    idxFillStart = WorkingSet.nVarOrig;
    nWeq = WorkingSet.sizes[1];
    for (colOffsetATw = 0; colOffsetATw < nWeq; colOffsetATw++) {
      colSum = 0.0;
      idx_global = WorkingSet.ldA * colOffsetATw;
      for (iAeq0 = 0; iAeq0 < idxFillStart; iAeq0++) {
        colSum += std::abs(WorkingSet.Aeq[iAeq0 + idx_global]);
      }

      a__2 = std::fmax(a__2, colSum);
    }

    colSum = 0.0;
    for (idxFillStart = 0; idxFillStart < 6; idxFillStart++) {
      b_colSum = 0.0;
      for (nWeq = 0; nWeq < 6; nWeq++) {
        b_colSum += static_cast<real_T>(H[6 * idxFillStart + nWeq]);
      }

      colSum = std::fmax(colSum, b_colSum);
    }

    driver(&solution, &memspace, &WorkingSet, &rtDW.CholRegManager, 10 *
           (((mFixed + i) + mUB) + 10), a__2, std::fmax(a__2, colSum),
           &QRManager, &QPObjective);
    for (i = 0; i < 6; i++) {
      rtb_thrust_setpoints[i] = solution.xstar[i];
    }

    if (solution.state <= 0) {
      computeFval(&QPObjective, memspace.workspace_float, solution.xstar);
    }

    switch (solution.state) {
     case 2:
      solution.state = -3;
      break;

     case -3:
      solution.state = -2;
      break;

     case 4:
      solution.state = -2;
      break;
    }

    if ((solution.state != -2) && (solution.state <= 0)) {
      solution.maxConstr = maxConstraintViolation_e(&WorkingSet, solution.xstar);
      if (solution.maxConstr <= 1.0E-8 * a__2) {
        switch (QPObjective.objtype) {
         case 5:
          if (QPObjective.nvar - 2 >= 0) {
            std::memset(&QPObjective.grad[0], 0, static_cast<uint32_T>
                        (QPObjective.nvar - 1) * sizeof(real_T));
          }

          QPObjective.grad[QPObjective.nvar - 1] = QPObjective.gammaScalar;
          break;

         case 3:
          linearForm__g(QPObjective.hasLinear, QPObjective.nvar,
                        QPObjective.grad, solution.xstar);
          break;

         case 4:
          linearForm__g(QPObjective.hasLinear, QPObjective.nvar,
                        QPObjective.grad, solution.xstar);
          i = QPObjective.nvar + 1;
          mUB = QPObjective.maxVar - 1;
          for (mFixed = i; mFixed <= mUB; mFixed++) {
            QPObjective.grad[mFixed - 1] = solution.xstar[mFixed - 1] *
              QPObjective.beta + QPObjective.rho;
          }
          break;
        }

        computeFirstOrderOpt(&solution, &QPObjective, WorkingSet.nVar,
                             WorkingSet.ldA, WorkingSet.ATwset,
                             WorkingSet.nActiveConstr, memspace.workspace_float);
      }
    }
  }

  for (i = 0; i < 6; i++) {
    rtb_thrust_setpoints[i] /= 5.0;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // Outport: '<Root>/normalized_thrust_setpoint0'
  rtY.normalized_thrust_setpoint0 = rtb_thrust_setpoints[0];

  // Outport: '<Root>/normalized_thrust_setpoint1'
  rtY.normalized_thrust_setpoint1 = rtb_thrust_setpoints[1];

  // Outport: '<Root>/normalized_thrust_setpoint2'
  rtY.normalized_thrust_setpoint2 = rtb_thrust_setpoints[2];

  // Outport: '<Root>/normalized_thrust_setpoint3'
  rtY.normalized_thrust_setpoint3 = rtb_thrust_setpoints[3];

  // Outport: '<Root>/normalized_thrust_setpoint4'
  rtY.normalized_thrust_setpoint4 = rtb_thrust_setpoints[4];

  // Outport: '<Root>/normalized_thrust_setpoint5'
  rtY.normalized_thrust_setpoint5 = rtb_thrust_setpoints[5];
}

// Model initialize function
void QP_CA_Codegen::initialize()
{
  // (no initialization code required)
}

// Root inport: '<Root>/heaven_acceleration_sp' set method
void QP_CA_Codegen::setheaven_acceleration_sp(real_T localArgInput)
{
  rtU.heaven_acceleration_sp = localArgInput;
}

// Root inport: '<Root>/roll_angualr_acceleration_sp' set method
void QP_CA_Codegen::setroll_angualr_acceleration_sp(real_T localArgInput)
{
  rtU.roll_angualr_acceleration_sp = localArgInput;
}

// Root inport: '<Root>/pitch_angular_accleration_sp' set method
void QP_CA_Codegen::setpitch_angular_accleration_sp(real_T localArgInput)
{
  rtU.pitch_angular_accleration_sp = localArgInput;
}

// Root inport: '<Root>/yaw_angular_accleration_sp' set method
void QP_CA_Codegen::setyaw_angular_accleration_sp(real_T localArgInput)
{
  rtU.yaw_angular_accleration_sp = localArgInput;
}

// Root inport: '<Root>/failure_status' set method
void QP_CA_Codegen::setfailure_status(real_T localArgInput[6])
{
  for (int32_T i{0}; i <= 5; i++) {
    rtU.failure_status[i] = localArgInput[i];
  }
}

// Root outport: '<Root>/normalized_thrust_setpoint0' get method
real_T QP_CA_Codegen::getnormalized_thrust_setpoint0() const
{
  return rtY.normalized_thrust_setpoint0;
}

// Root outport: '<Root>/normalized_thrust_setpoint1' get method
real_T QP_CA_Codegen::getnormalized_thrust_setpoint1() const
{
  return rtY.normalized_thrust_setpoint1;
}

// Root outport: '<Root>/normalized_thrust_setpoint2' get method
real_T QP_CA_Codegen::getnormalized_thrust_setpoint2() const
{
  return rtY.normalized_thrust_setpoint2;
}

// Root outport: '<Root>/normalized_thrust_setpoint3' get method
real_T QP_CA_Codegen::getnormalized_thrust_setpoint3() const
{
  return rtY.normalized_thrust_setpoint3;
}

// Root outport: '<Root>/normalized_thrust_setpoint4' get method
real_T QP_CA_Codegen::getnormalized_thrust_setpoint4() const
{
  return rtY.normalized_thrust_setpoint4;
}

// Root outport: '<Root>/normalized_thrust_setpoint5' get method
real_T QP_CA_Codegen::getnormalized_thrust_setpoint5() const
{
  return rtY.normalized_thrust_setpoint5;
}

// Constructor
QP_CA_Codegen::QP_CA_Codegen() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
QP_CA_Codegen::~QP_CA_Codegen() = default;

// Real-Time Model get method
QP_CA_Codegen::RT_MODEL * QP_CA_Codegen::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
