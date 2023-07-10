/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: robust_drift_REALTIME.h
 *
 * Code generated for Simulink model 'robust_drift_REALTIME'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon May 31 11:44:21 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_robust_drift_REALTIME_h_
#define RTW_HEADER_robust_drift_REALTIME_h_
#include <math.h>
#include <stddef.h>
#ifndef robust_drift_REALTIME_COMMON_INCLUDES_
#define robust_drift_REALTIME_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* robust_drift_REALTIME_COMMON_INCLUDES_ */

#include "robust_drift_REALTIME_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>/Monostable' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  boolean_T Monostable_MODE;           /* '<Root>/Monostable' */
} DW_Monostable_robust_drift_RE_T;

/* Block states (default storage) for system '<Root>/Up-Counter (with upper bound)' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S12>/Unit Delay' */
} DW_UpCounterwithupperbound_ro_T;

/* Zero-crossing (trigger) state for system '<Root>/Up-Counter (with upper bound)' */
typedef struct {
  ZCSigState UpCounterwithupperbound_Trig_ZC;
                                    /* '<Root>/Up-Counter (with upper bound)' */
} ZCE_UpCounterwithupperbound_r_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain;                         /* '<S26>/Gain' */
  real_T Saturation;                   /* '<S13>/Saturation' */
  real_T Saturation_o;                 /* '<S12>/Saturation' */
  real_T V2duty;                       /* '<S25>/V2duty' */
  real_T Sum1;                         /* '<S25>/Sum1' */
  real_T V2duty1;                      /* '<S24>/V2duty1' */
  real_T Integralgain;                 /* '<S24>/Integral gain' */
  real_T Constant;                     /* '<S8>/Constant' */
  real_T Constant_j;                   /* '<S7>/Constant' */
  real32_T TmpSignalConversionAtSFunctionI[2];
  real32_T DataTypeConversion2;        /* '<S18>/Data Type Conversion2' */
  int32_T SFunction_o1;                /* '<S15>/S-Function' */
  int32_T SFunction_o2;                /* '<S15>/S-Function' */
  int32_T TmpSignalConversionAtSFunctio_b[2];
  int16_T SFunction_o1_i[3];           /* '<S17>/S-Function' */
  int16_T SFunction_o2_a[3];           /* '<S17>/S-Function' */
  int16_T DataTypeConversion;          /* '<S23>/Data Type Conversion' */
  int16_T DataTypeConversion1;         /* '<S23>/Data Type Conversion1' */
  uint8_T SFunction_o1_f;              /* '<S6>/S-Function' */
  uint8_T SFunction_o2_i;              /* '<S6>/S-Function' */
  uint8_T TmpSignalConversionAtSFunctio_p[2];
  boolean_T Compare;                   /* '<S21>/Compare' */
  boolean_T Compare_n;                 /* '<S20>/Compare' */
} B_robust_drift_REALTIME_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S26>/Discrete-Time Integrator' */
  real_T LPF_states;                   /* '<S26>/LPF' */
  real_T Speedfilter1_states[3];       /* '<S11>/Speed filter 1' */
  real_T Speedfilter3_states[3];       /* '<S11>/Speed filter 3' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S25>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S24>/Discrete-Time Integrator' */
  real_T LPF_tmp;                      /* '<S26>/LPF' */
  real_T Speedfilter1_tmp;             /* '<S11>/Speed filter 1' */
  real_T Speedfilter3_tmp;             /* '<S11>/Speed filter 3' */
  void* SFunction_DWORK1[2];           /* '<S10>/S-Function' */
  boolean_T SFunction_DWORK2;          /* '<S10>/S-Function' */
  boolean_T SScontrollerrobust2_MODE;  /* '<Root>/SS controller robust2' */
  DW_UpCounterwithupperbound_ro_T UpCounterwithupperbound1;
                                   /* '<Root>/Up-Counter (with upper bound)1' */
  DW_UpCounterwithupperbound_ro_T UpCounterwithupperbound;
                                    /* '<Root>/Up-Counter (with upper bound)' */
  DW_Monostable_robust_drift_RE_T Monostable1;/* '<Root>/Monostable1' */
  DW_Monostable_robust_drift_RE_T Monostable;/* '<Root>/Monostable' */
} DW_robust_drift_REALTIME_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_UpCounterwithupperbound_r_T UpCounterwithupperbound1;
                                   /* '<Root>/Up-Counter (with upper bound)1' */
  ZCE_UpCounterwithupperbound_r_T UpCounterwithupperbound;
                                    /* '<Root>/Up-Counter (with upper bound)' */
} PrevZCX_robust_drift_REALTIME_T;

/* Parameters for system: '<Root>/Monostable' */
struct P_Monostable_robust_drift_REA_T_ {
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S3>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete-Time Integrator'
                                          */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  boolean_T Out_Y0;                    /* Computed Parameter: Out_Y0
                                        * Referenced by: '<S3>/Out'
                                        */
};

/* Parameters for system: '<Root>/Up-Counter (with upper bound)' */
struct P_UpCounterwithupperbound_rob_T_ {
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant2'
                                        */
};

/* Parameters (default storage) */
struct P_robust_drift_REALTIME_T_ {
  struct_ZyOsf22oZpzf3TbBVA5VPH sens;  /* Variable: sens
                                        * Referenced by:
                                        *   '<S11>/pulse2deg'
                                        *   '<S11>/pulse2deg1'
                                        */
  struct_p66wMqgqG0tqrYXpsxIiT wheel;  /* Variable: wheel
                                        * Referenced by: '<S7>/Constant'
                                        */
  struct_Wq2SEuethZwdYr1NQjhMYF drv;   /* Variable: drv
                                        * Referenced by:
                                        *   '<S8>/Constant'
                                        *   '<S24>/V2duty1'
                                        *   '<S25>/V2duty'
                                        */
  struct_X2VAEXKuhkaiuxF0Z4qglD gbox;  /* Variable: gbox
                                        * Referenced by:
                                        *   '<S11>/mot2load'
                                        *   '<S11>/mot2load1'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S25>/integral gain (???)'
                                        */
  real_T N_u;                          /* Variable: N_u
                                        * Referenced by: '<S25>/Input feedforward'
                                        */
  real_T N_x[4];                       /* Variable: N_x
                                        * Referenced by: '<S25>/State feedforward	'
                                        */
  real_T deg2rad;                      /* Variable: deg2rad
                                        * Referenced by:
                                        *   '<S24>/deg2rad3'
                                        *   '<S25>/deg2rad'
                                        *   '<S25>/deg2rad1'
                                        *   '<S25>/deg2rad2'
                                        *   '<S26>/Gain'
                                        */
  real_T rad2deg;                      /* Variable: rad2deg
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S26>/rad2deg'
                                        */
  real_T UpCounterwithupperbound_C0;
                                   /* Mask Parameter: UpCounterwithupperbound_C0
                                    * Referenced by: '<Root>/Up-Counter (with upper bound)'
                                    */
  real_T UpCounterwithupperbound1_C0;
                                  /* Mask Parameter: UpCounterwithupperbound1_C0
                                   * Referenced by: '<Root>/Up-Counter (with upper bound)1'
                                   */
  real_T UpCounterwithupperbound_CMAX;
                                 /* Mask Parameter: UpCounterwithupperbound_CMAX
                                  * Referenced by: '<Root>/Up-Counter (with upper bound)'
                                  */
  real_T UpCounterwithupperbound1_CMAX;
                                /* Mask Parameter: UpCounterwithupperbound1_CMAX
                                 * Referenced by: '<Root>/Up-Counter (with upper bound)1'
                                 */
  real_T Monostable_Tp;                /* Mask Parameter: Monostable_Tp
                                        * Referenced by: '<Root>/Monostable'
                                        */
  real_T Monostable1_Tp;               /* Mask Parameter: Monostable1_Tp
                                        * Referenced by: '<Root>/Monostable1'
                                        */
  real_T Outduty_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S8>/Out[duty]'
                                        */
  real_T uduty_Y0;                     /* Computed Parameter: uduty_Y0
                                        * Referenced by: '<S9>/u [duty]'
                                        */
  real_T uduty1_Y0;                    /* Computed Parameter: uduty1_Y0
                                        * Referenced by: '<S9>/u [duty]1'
                                        */
  real_T Statefeedback_Gain[4];        /* Expression: K'
                                        * Referenced by: '<S25>/State feedback'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S25>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                           * Referenced by: '<S24>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<S24>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S24>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S24>/Step'
                                        */
  real_T Proportionalgain_Gain;        /* Expression: 3.3
                                        * Referenced by: '<S24>/Proportional gain'
                                        */
  real_T Integralgain_Gain;            /* Expression: 0.7
                                        * Referenced by: '<S24>/Integral gain'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<S26>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real_T LPF_NumCoef[2];               /* Expression: [numLPFz]
                                        * Referenced by: '<S26>/LPF'
                                        */
  real_T LPF_DenCoef[2];               /* Expression: [denLPFz]
                                        * Referenced by: '<S26>/LPF'
                                        */
  real_T LPF_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S26>/LPF'
                                        */
  real_T Speedfilter1_NumCoef[4];      /* Expression: [numHw]
                                        * Referenced by: '<S11>/Speed filter 1'
                                        */
  real_T Speedfilter1_DenCoef[4];      /* Expression: [denHw]
                                        * Referenced by: '<S11>/Speed filter 1'
                                        */
  real_T Speedfilter1_InitialStates;   /* Expression: 0
                                        * Referenced by: '<S11>/Speed filter 1'
                                        */
  real_T Speedfilter3_NumCoef[4];      /* Expression: [numHw]
                                        * Referenced by: '<S11>/Speed filter 3'
                                        */
  real_T Speedfilter3_DenCoef[4];      /* Expression: [denHw]
                                        * Referenced by: '<S11>/Speed filter 3'
                                        */
  real_T Speedfilter3_InitialStates;   /* Expression: 0
                                        * Referenced by: '<S11>/Speed filter 3'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S22>/Gain'
                                        */
  int32_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S16>/Gain'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S19>/Gain1'
                                        */
  int16_T wxraw2dps_Gain;              /* Computed Parameter: wxraw2dps_Gain
                                        * Referenced by: '<S18>/wxraw2dps'
                                        */
  int16_T ayraw2g_Gain;                /* Computed Parameter: ayraw2g_Gain
                                        * Referenced by: '<S18>/ayraw2g'
                                        */
  int16_T azraw2g_Gain;                /* Computed Parameter: azraw2g_Gain
                                        * Referenced by: '<S18>/azraw2g'
                                        */
  P_UpCounterwithupperbound_rob_T UpCounterwithupperbound1;
                                   /* '<Root>/Up-Counter (with upper bound)1' */
  P_UpCounterwithupperbound_rob_T UpCounterwithupperbound;
                                    /* '<Root>/Up-Counter (with upper bound)' */
  P_Monostable_robust_drift_REA_T Monostable1;/* '<Root>/Monostable1' */
  P_Monostable_robust_drift_REA_T Monostable;/* '<Root>/Monostable' */
};

/* Real-time Model Data Structure */
struct tag_RTM_robust_drift_REALTIME_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_robust_drift_REALTIME_T robust_drift_REALTIME_P;

/* Block signals (default storage) */
extern B_robust_drift_REALTIME_T robust_drift_REALTIME_B;

/* Block states (default storage) */
extern DW_robust_drift_REALTIME_T robust_drift_REALTIME_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_robust_drift_REALTIME_T robust_drift_REALTIME_PrevZCX;

/* Model entry point functions */
extern void robust_drift_REALTIME_initialize(void);
extern void robust_drift_REALTIME_step(void);
extern void robust_drift_REALTIME_terminate(void);

/* Real-time Model object */
extern RT_MODEL_robust_drift_REALTIM_T *const robust_drift_REALTIME_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S18>/Data Type Conversion' : Unused code path elimination
 * Block '<S18>/Data Type Conversion4' : Unused code path elimination
 * Block '<S18>/Data Type Conversion5' : Unused code path elimination
 * Block '<S18>/axraw2g' : Unused code path elimination
 * Block '<S18>/wyraw2dps' : Unused code path elimination
 * Block '<S18>/wzraw2dps' : Unused code path elimination
 * Block '<S19>/Gain' : Unused code path elimination
 * Block '<S19>/Gain2' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<S11>/Speed filter 2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'robust_drift_REALTIME'
 * '<S1>'   : 'robust_drift_REALTIME/Encoders'
 * '<S2>'   : 'robust_drift_REALTIME/MPU6050 Inertial Measurement Unit'
 * '<S3>'   : 'robust_drift_REALTIME/Monostable'
 * '<S4>'   : 'robust_drift_REALTIME/Monostable1'
 * '<S5>'   : 'robust_drift_REALTIME/Motors'
 * '<S6>'   : 'robust_drift_REALTIME/Pushbuttons'
 * '<S7>'   : 'robust_drift_REALTIME/Reference generator'
 * '<S8>'   : 'robust_drift_REALTIME/Reference generator1'
 * '<S9>'   : 'robust_drift_REALTIME/SS controller robust2'
 * '<S10>'  : 'robust_drift_REALTIME/Serial Packet Send'
 * '<S11>'  : 'robust_drift_REALTIME/State Observer'
 * '<S12>'  : 'robust_drift_REALTIME/Up-Counter (with upper bound)'
 * '<S13>'  : 'robust_drift_REALTIME/Up-Counter (with upper bound)1'
 * '<S14>'  : 'robust_drift_REALTIME/control input conversion'
 * '<S15>'  : 'robust_drift_REALTIME/Encoders/Encoders'
 * '<S16>'  : 'robust_drift_REALTIME/Encoders/To Wheel Frames'
 * '<S17>'  : 'robust_drift_REALTIME/MPU6050 Inertial Measurement Unit/MPU'
 * '<S18>'  : 'robust_drift_REALTIME/MPU6050 Inertial Measurement Unit/Raw to physical units'
 * '<S19>'  : 'robust_drift_REALTIME/MPU6050 Inertial Measurement Unit/To Body Frame'
 * '<S20>'  : 'robust_drift_REALTIME/Monostable/Compare To Constant'
 * '<S21>'  : 'robust_drift_REALTIME/Monostable1/Compare To Constant'
 * '<S22>'  : 'robust_drift_REALTIME/Motors/From Wheel Frames'
 * '<S23>'  : 'robust_drift_REALTIME/Motors/Motors'
 * '<S24>'  : 'robust_drift_REALTIME/SS controller robust2/Yaw controller'
 * '<S25>'  : 'robust_drift_REALTIME/SS controller robust2/robust controller'
 * '<S26>'  : 'robust_drift_REALTIME/State Observer/Complementary filter'
 * '<S27>'  : 'robust_drift_REALTIME/State Observer/to_gam_psi_angles'
 * '<S28>'  : 'robust_drift_REALTIME/State Observer/to_gam_psi_angles/MATLAB Function'
 * '<S29>'  : 'robust_drift_REALTIME/State Observer/to_gam_psi_angles/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_robust_drift_REALTIME_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
