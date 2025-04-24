//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'FLIGHT_hexacopter'.
//
// Model version                  : 1.142
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Apr 23 15:33:57 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>
#include <stdlib.h>
#include "FLIGHT_hexacopter.h"
#include "FLIGHT_hexacopter_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "MW_PX4_TaskControl.h"
#include "nuttxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
px4_sem_t stopSem;
px4_sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(FLIGHT_hexacopter_M) == (NULL));
  while (runModel) {
    px4_sem_wait(&baserateTaskSem);
    FLIGHT_hexacopter_step();

    // Get model outputs here
    stopRequested = !((rtmGetErrorStatus(FLIGHT_hexacopter_M) == (NULL)));
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(FLIGHT_hexacopter_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  MW_PX4_Terminate();

  // Terminate model
  FLIGHT_hexacopter_terminate();
  px4_sem_post(&stopSem);
  return NULL;
}

int px4_simulink_app_task_main (int argc, char *argv[])
{
  px4_simulink_app_control_MAVLink();
  rtmSetErrorStatus(FLIGHT_hexacopter_M, 0);

  // Initialize model
  FLIGHT_hexacopter_initialize();

  // Call RTOS Initialization function
  nuttxRTOSInit(0.0025, 0);

  // Wait for stop semaphore
  px4_sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(px4_sem_destroy(&timerTaskSem[i]), 0, "px4_sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
