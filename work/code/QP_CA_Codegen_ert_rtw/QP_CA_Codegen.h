//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: QP_CA_Codegen.h
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
#ifndef QP_CA_Codegen_h_
#define QP_CA_Codegen_h_
#include <cmath>
#include "rtwtypes.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Custom Type definition for MATLAB Function: '<Root>/MATLAB Function'
#ifndef struct_sBiFZCV7758PhXr6el0VfCD
#define struct_sBiFZCV7758PhXr6el0VfCD

struct sBiFZCV7758PhXr6el0VfCD
{
  real_T xstar[7];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[17];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[7];
};

#endif                                 // struct_sBiFZCV7758PhXr6el0VfCD

#ifndef struct_slzZ8M58FXlZqTD433BZJUH
#define struct_slzZ8M58FXlZqTD433BZJUH

struct slzZ8M58FXlZqTD433BZJUH
{
  real_T grad[7];
  real_T Hx[6];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                 // struct_slzZ8M58FXlZqTD433BZJUH

#ifndef struct_sY5VKsxRLdcmJCLAY5aC9o
#define struct_sY5VKsxRLdcmJCLAY5aC9o

struct sY5VKsxRLdcmJCLAY5aC9o
{
  real_T FMat[100];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[480];
  real_T workspace2_[480];
};

#endif                                 // struct_sY5VKsxRLdcmJCLAY5aC9o

#ifndef struct_sH0q0JNg27eDMe5yMaNXg9D
#define struct_sH0q0JNg27eDMe5yMaNXg9D

struct sH0q0JNg27eDMe5yMaNXg9D
{
  int32_T ldq;
  real_T QR[170];
  real_T Q[100];
  int32_T jpvt[17];
  int32_T mrows;
  int32_T ncols;
  real_T tau[10];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 // struct_sH0q0JNg27eDMe5yMaNXg9D

#ifndef struct_sTLNI0DWFUbeIRd2tl4OexC
#define struct_sTLNI0DWFUbeIRd2tl4OexC

struct sTLNI0DWFUbeIRd2tl4OexC
{
  real_T workspace_float[119];
  int32_T workspace_int[17];
  int32_T workspace_sort[17];
};

#endif                                 // struct_sTLNI0DWFUbeIRd2tl4OexC

#ifndef struct_sAjQtoJYLWYGAxqZWOtnxYE
#define struct_sAjQtoJYLWYGAxqZWOtnxYE

struct sAjQtoJYLWYGAxqZWOtnxYE
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aeq[28];
  real_T beq[4];
  real_T lb[7];
  real_T ub[7];
  int32_T indexLB[7];
  int32_T indexUB[7];
  int32_T indexFixed[7];
  int32_T mEqRemoved;
  int32_T indexEqRemoved[4];
  real_T ATwset[119];
  real_T bwset[17];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[17];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[17];
  int32_T Wid[17];
  int32_T Wlocalidx[17];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 // struct_sAjQtoJYLWYGAxqZWOtnxYE

#ifndef struct_sDROcIZ6ilexqwOTaATsaxG
#define struct_sDROcIZ6ilexqwOTaATsaxG

struct sDROcIZ6ilexqwOTaATsaxG
{
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T Display[4];
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

#endif                                 // struct_sDROcIZ6ilexqwOTaATsaxG

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
}                                      // extern "C"

// Class declaration for model QP_CA_Codegen
class QP_CA_Codegen final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    sY5VKsxRLdcmJCLAY5aC9o CholRegManager;
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: [1 1 1 1 1 1; 0.275 -0.275 0.1375 -0.1375 -0.1375 0.1375; 0 0 0.2382 -0.2382 0.2382 -0.2382; -0.1 0.1 -0.1 0.1 -0.1 0.1]
    //  Referenced by: '<Root>/Constant1'

    real_T Constant1_Value[24];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T heaven_acceleration_sp;     // '<Root>/heaven_acceleration_sp'
    real_T roll_angualr_acceleration_sp;// '<Root>/roll_angualr_acceleration_sp' 
    real_T pitch_angular_accleration_sp;// '<Root>/pitch_angular_accleration_sp' 
    real_T yaw_angular_accleration_sp; // '<Root>/yaw_angular_accleration_sp'
    real_T failure_status[6];          // '<Root>/failure_status'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T normalized_thrust_setpoint0;// '<Root>/normalized_thrust_setpoint0'
    real_T normalized_thrust_setpoint1;// '<Root>/normalized_thrust_setpoint1'
    real_T normalized_thrust_setpoint2;// '<Root>/normalized_thrust_setpoint2'
    real_T normalized_thrust_setpoint3;// '<Root>/normalized_thrust_setpoint3'
    real_T normalized_thrust_setpoint4;// '<Root>/normalized_thrust_setpoint4'
    real_T normalized_thrust_setpoint5;// '<Root>/normalized_thrust_setpoint5'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  QP_CA_Codegen(QP_CA_Codegen const&) = delete;

  // Assignment Operator
  QP_CA_Codegen& operator= (QP_CA_Codegen const&) & = delete;

  // Move Constructor
  QP_CA_Codegen(QP_CA_Codegen &&) = delete;

  // Move Assignment Operator
  QP_CA_Codegen& operator= (QP_CA_Codegen &&) = delete;

  // Real-Time Model get method
  QP_CA_Codegen::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // Root inport: '<Root>/heaven_acceleration_sp' set method
  void setheaven_acceleration_sp(real_T localArgInput);

  // Root inport: '<Root>/roll_angualr_acceleration_sp' set method
  void setroll_angualr_acceleration_sp(real_T localArgInput);

  // Root inport: '<Root>/pitch_angular_accleration_sp' set method
  void setpitch_angular_accleration_sp(real_T localArgInput);

  // Root inport: '<Root>/yaw_angular_accleration_sp' set method
  void setyaw_angular_accleration_sp(real_T localArgInput);

  // Root inport: '<Root>/failure_status' set method
  void setfailure_status(real_T localArgInput[6]);

  // Root outport: '<Root>/normalized_thrust_setpoint0' get method
  real_T getnormalized_thrust_setpoint0() const;

  // Root outport: '<Root>/normalized_thrust_setpoint1' get method
  real_T getnormalized_thrust_setpoint1() const;

  // Root outport: '<Root>/normalized_thrust_setpoint2' get method
  real_T getnormalized_thrust_setpoint2() const;

  // Root outport: '<Root>/normalized_thrust_setpoint3' get method
  real_T getnormalized_thrust_setpoint3() const;

  // Root outport: '<Root>/normalized_thrust_setpoint4' get method
  real_T getnormalized_thrust_setpoint4() const;

  // Root outport: '<Root>/normalized_thrust_setpoint5' get method
  real_T getnormalized_thrust_setpoint5() const;

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // Constructor
  QP_CA_Codegen();

  // Destructor
  ~QP_CA_Codegen();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<Root>'
  void loadProblem(sAjQtoJYLWYGAxqZWOtnxYE *obj, const real_T Aeq[24], const
                   real_T beq[4], int32_T mLB, int32_T mUB, const real_T ub[6],
                   int32_T mFixed);
  void modifyOverheadPhaseOne_(sAjQtoJYLWYGAxqZWOtnxYE *obj);
  void setProblemType(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T PROBLEM_TYPE);
  real_T xnrm2(int32_T n, const real_T x[170], int32_T ix0);
  real_T xzlarfg(int32_T n, real_T *alpha1, real_T x[170], int32_T ix0);
  void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C[170],
              int32_T ic0, real_T work[17]);
  void qrf(real_T A[170], int32_T ia0, int32_T m, int32_T n, int32_T nfxd,
           real_T tau[10]);
  void factorQRE(sH0q0JNg27eDMe5yMaNXg9D *obj, int32_T mrows, int32_T ncols);
  void computeQ_(sH0q0JNg27eDMe5yMaNXg9D *obj, int32_T nrows);
  int32_T ComputeNumDependentEq_(sH0q0JNg27eDMe5yMaNXg9D *qrmanager, const
    real_T beqf[17], int32_T mConstr, int32_T nVar);
  void countsort(int32_T x[17], int32_T xLen, int32_T workspace[17], int32_T
                 xMin, int32_T xMax);
  void removeConstr(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T idx_global);
  void removeEqConstr(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T idx_global);
  void RemoveDependentIneq_(sAjQtoJYLWYGAxqZWOtnxYE *workingset,
    sH0q0JNg27eDMe5yMaNXg9D *qrmanager, sTLNI0DWFUbeIRd2tl4OexC *memspace,
    real_T tolfactor);
  void factorQR(sH0q0JNg27eDMe5yMaNXg9D *obj, const real_T A[119], int32_T mrows,
                int32_T ncols, int32_T ldA);
  void xgemv(int32_T m, int32_T n, const real_T A[28], int32_T lda, const real_T
             x[119], real_T y[17]);
  void xgemv_b(int32_T m, int32_T n, const real_T A[28], int32_T lda, const
               real_T x[119], real_T y[17]);
  real_T maxConstraintViolation(sAjQtoJYLWYGAxqZWOtnxYE *obj, const real_T x[119]);
  boolean_T feasibleX0ForWorkingSet(real_T workspace[119], real_T xCurrent[7],
    sAjQtoJYLWYGAxqZWOtnxYE *workingset, sH0q0JNg27eDMe5yMaNXg9D *qrmanager);
  void xgemv_b4(int32_T m, int32_T n, const real_T A[28], int32_T lda, const
                real_T x[7], real_T y[17]);
  real_T maxConstraintViolation_e(sAjQtoJYLWYGAxqZWOtnxYE *obj, const real_T x[7]);
  void PresolveWorkingSet(sBiFZCV7758PhXr6el0VfCD *solution,
    sTLNI0DWFUbeIRd2tl4OexC *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
    sH0q0JNg27eDMe5yMaNXg9D *qrmanager);
  void linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T workspace
                   [119], const real_T x[7]);
  real_T computeFval(const slzZ8M58FXlZqTD433BZJUH *obj, real_T workspace[119],
                     const real_T x[7]);
  void xgemv_b4q(int32_T m, int32_T n, int32_T lda, const real_T x[7], real_T y
                 [6]);
  void computeGrad_StoreHx(slzZ8M58FXlZqTD433BZJUH *obj, const real_T x[7]);
  real_T computeFval_ReuseHx(const slzZ8M58FXlZqTD433BZJUH *obj, real_T
    workspace[119], const real_T x[7]);
  void xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
  void deleteColMoveEnd(sH0q0JNg27eDMe5yMaNXg9D *obj, int32_T idx);
  int32_T ixamax(int32_T n, const real_T x[100], int32_T incx);
  void fullColLDL2_(sY5VKsxRLdcmJCLAY5aC9o *obj, int32_T LD_offset, int32_T
                    NColsRemain, real_T REG_PRIMAL);
  void xgemv_b4qt(int32_T m, int32_T n, const real_T A[100], int32_T ia0,
                  int32_T lda, const real_T x[119], real_T y[7]);
  void compute_deltax(sBiFZCV7758PhXr6el0VfCD *solution, sTLNI0DWFUbeIRd2tl4OexC
                      *memspace, const sH0q0JNg27eDMe5yMaNXg9D *qrmanager,
                      sY5VKsxRLdcmJCLAY5aC9o *cholmanager, const
                      slzZ8M58FXlZqTD433BZJUH *objective);
  real_T xnrm2_l(int32_T n, const real_T x[7]);
  void ratiotest(const real_T solution_xstar[7], const real_T
                 solution_searchDir[7], const real_T workspace[119], int32_T
                 workingset_nVar, const real_T workingset_lb[7], const real_T
                 workingset_ub[7], const int32_T workingset_indexLB[7], const
                 int32_T workingset_indexUB[7], const int32_T workingset_sizes[5],
                 const int32_T workingset_isActiveIdx[6], const boolean_T
                 workingset_isActiveConstr[17], const int32_T
                 workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
                 real_T *toldelta, real_T toltau, real_T *alpha, boolean_T
                 *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void feasibleratiotest(const real_T solution_xstar[7], const real_T
    solution_searchDir[7], const real_T workspace[119], int32_T workingset_nVar,
    const real_T workingset_lb[7], const real_T workingset_ub[7], const int32_T
    workingset_indexLB[7], const int32_T workingset_indexUB[7], const int32_T
    workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const
    boolean_T workingset_isActiveConstr[17], const int32_T workingset_nWConstr[5],
    boolean_T isPhaseOne, real_T tolcon, real_T *alpha, boolean_T *newBlocking,
    int32_T *constrType, int32_T *constrIdx);
  void addBoundToActiveSetMatrix_(sAjQtoJYLWYGAxqZWOtnxYE *obj, int32_T TYPE,
    int32_T idx_local);
  void compute_lambda(real_T workspace[119], sBiFZCV7758PhXr6el0VfCD *solution,
                      const slzZ8M58FXlZqTD433BZJUH *objective, const
                      sH0q0JNg27eDMe5yMaNXg9D *qrmanager);
  void iterate(sBiFZCV7758PhXr6el0VfCD *solution, sTLNI0DWFUbeIRd2tl4OexC
               *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
               sH0q0JNg27eDMe5yMaNXg9D *qrmanager, sY5VKsxRLdcmJCLAY5aC9o
               *cholmanager, slzZ8M58FXlZqTD433BZJUH *objective, real_T
               options_PricingTolerance, real_T options_ObjectiveLimit, real_T
               options_ConstraintTolerance, real_T options_StepTolerance,
               int32_T runTimeOptions_MaxIterations, real_T
               runTimeOptions_ConstrRelTolFact, real_T
               runTimeOptions_ProbRelTolFactor, boolean_T
               runTimeOptions_RemainFeasible);
  void PresolveWorkingSet_e(sBiFZCV7758PhXr6el0VfCD *solution,
    sTLNI0DWFUbeIRd2tl4OexC *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
    sH0q0JNg27eDMe5yMaNXg9D *qrmanager, const sDROcIZ6ilexqwOTaATsaxG *options);
  void computeFirstOrderOpt(sBiFZCV7758PhXr6el0VfCD *solution, const
    slzZ8M58FXlZqTD433BZJUH *objective, int32_T workingset_nVar, int32_T
    workingset_ldA, const real_T workingset_ATwset[119], int32_T
    workingset_nActiveConstr, real_T workspace[119]);
  void driver(sBiFZCV7758PhXr6el0VfCD *solution, sTLNI0DWFUbeIRd2tl4OexC
              *memspace, sAjQtoJYLWYGAxqZWOtnxYE *workingset,
              sY5VKsxRLdcmJCLAY5aC9o *cholmanager, int32_T
              runTimeOptions_MaxIterations, real_T
              runTimeOptions_ConstrRelTolFact, real_T
              runTimeOptions_ProbRelTolFactor, sH0q0JNg27eDMe5yMaNXg9D
              *qrmanager, slzZ8M58FXlZqTD433BZJUH *objective);
  void linearForm__g(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
                     workspace[7], const real_T x[7]);

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const QP_CA_Codegen::ConstP rtConstP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'QP_CA_Codegen'
//  '<S1>'   : 'QP_CA_Codegen/MATLAB Function'

#endif                                 // QP_CA_Codegen_h_

//
// File trailer for generated code.
//
// [EOF]
//
