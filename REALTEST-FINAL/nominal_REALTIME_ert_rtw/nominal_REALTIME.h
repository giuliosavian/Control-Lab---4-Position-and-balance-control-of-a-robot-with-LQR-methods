/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: nominal_REALTIME.h
 *
 * Code generated for Simulink model 'nominal_REALTIME'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon May 31 12:05:49 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_nominal_REALTIME_h_
#define RTW_HEADER_nominal_REALTIME_h_
#include <math.h>
#include <stddef.h>
#ifndef nominal_REALTIME_COMMON_INCLUDES_
#define nominal_REALTIME_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* nominal_REALTIME_COMMON_INCLUDES_ */

#include "nominal_REALTIME_types.h"

/* Shared type includes */
#include "multiword_types.h"
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

/* Block states (default storage) for system '<Root>/Monostable' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  boolean_T Monostable_MODE;           /* '<Root>/Monostable' */
} DW_Monostable_nominal_REALTIM_T;

/* Block states (default storage) for system '<Root>/Up-Counter (with upper bound)' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S12>/Unit Delay' */
} DW_UpCounterwithupperbound_no_T;

/* Zero-crossing (trigger) state for system '<Root>/Up-Counter (with upper bound)' */
typedef struct {
  ZCSigState UpCounterwithupperbound_Trig_ZC;
                                    /* '<Root>/Up-Counter (with upper bound)' */
} ZCE_UpCounterwithupperbound_n_T;

/* Block signals (default storage) */
typedef struct {
  real_T Saturation;                   /* '<S13>/Saturation' */
  real_T Saturation_p;                 /* '<S12>/Saturation' */
  real_T V2duty;                       /* '<S9>/V2duty' */
  real_T Constant;                     /* '<S8>/Constant' */
  real_T Constant_m;                   /* '<S7>/Constant' */
  real_T denAccum;
  real_T denAccum_m;
  real32_T TmpSignalConversionAtSFunctionI[2];
  real32_T DataTypeConversion2;        /* '<S17>/Data Type Conversion2' */
  int32_T SFunction_o1;                /* '<S14>/S-Function' */
  int32_T SFunction_o2;                /* '<S14>/S-Function' */
  int32_T TmpSignalConversionAtSFunctio_i[2];
  int16_T SFunction_o1_g[3];           /* '<S16>/S-Function' */
  int16_T SFunction_o2_i[3];           /* '<S16>/S-Function' */
  int16_T DataTypeConversion;          /* '<S22>/Data Type Conversion' */
  int16_T DataTypeConversion1;         /* '<S22>/Data Type Conversion1' */
  uint8_T SFunction_o1_h;              /* '<S6>/S-Function' */
  uint8_T SFunction_o2_o;              /* '<S6>/S-Function' */
  uint8_T TmpSignalConversionAtSFunctio_c[2];
  boolean_T Compare;                   /* '<S20>/Compare' */
  boolean_T Compare_l;                 /* '<S19>/Compare' */
} B_nominal_REALTIME_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S23>/Discrete-Time Integrator' */
  real_T LPF_states;                   /* '<S23>/LPF' */
  real_T Speedfilter1_states[3];       /* '<S11>/Speed filter 1' */
  real_T Speedfilter2_states[3];       /* '<S11>/Speed filter 2' */
  void* SFunction_DWORK1[2];           /* '<S10>/S-Function' */
  boolean_T SFunction_DWORK2;          /* '<S10>/S-Function' */
  DW_UpCounterwithupperbound_no_T UpCounterwithupperbound1;
                                   /* '<Root>/Up-Counter (with upper bound)1' */
  DW_UpCounterwithupperbound_no_T UpCounterwithupperbound;
                                    /* '<Root>/Up-Counter (with upper bound)' */
  DW_Monostable_nominal_REALTIM_T Monostable1;/* '<Root>/Monostable1' */
  DW_Monostable_nominal_REALTIM_T Monostable;/* '<Root>/Monostable' */
} DW_nominal_REALTIME_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_UpCounterwithupperbound_n_T UpCounterwithupperbound1;
                                   /* '<Root>/Up-Counter (with upper bound)1' */
  ZCE_UpCounterwithupperbound_n_T UpCounterwithupperbound;
                                    /* '<Root>/Up-Counter (with upper bound)' */
} PrevZCX_nominal_REALTIME_T;

/* Parameters for system: '<Root>/Monostable' */
struct P_Monostable_nominal_REALTIME_T_ {
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
struct P_UpCounterwithupperbound_nom_T_ {
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant2'
                                        */
};

/* Parameters (default storage) */
struct P_nominal_REALTIME_T_ {
  struct_ZyOsf22oZpzf3TbBVA5VPH sens;  /* Variable: sens
                                        * Referenced by: '<S11>/pulse2deg'
                                        */
  struct_p66wMqgqG0tqrYXpsxIiT wheel;  /* Variable: wheel
                                        * Referenced by: '<S7>/Constant'
                                        */
  struct_Wq2SEuethZwdYr1NQjhMYF drv;   /* Variable: drv
                                        * Referenced by:
                                        *   '<S8>/Constant'
                                        *   '<S9>/V2duty'
                                        */
  struct_X2VAEXKuhkaiuxF0Z4qglD gbox;  /* Variable: gbox
                                        * Referenced by: '<S11>/mot2load'
                                        */
  real_T N_u;                          /* Variable: N_u
                                        * Referenced by: '<S9>/Input feedforward'
                                        */
  real_T N_x[4];                       /* Variable: N_x
                                        * Referenced by: '<S9>/State feedforward	'
                                        */
  real_T deg2rad;                      /* Variable: deg2rad
                                        * Referenced by:
                                        *   '<S9>/deg2rad'
                                        *   '<S9>/deg2rad1'
                                        *   '<S23>/Gain'
                                        */
  real_T rad2deg;                      /* Variable: rad2deg
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S23>/rad2deg'
                                        */
  real_T UpCounterwithupperbound1_C0;
                                  /* Mask Parameter: UpCounterwithupperbound1_C0
                                   * Referenced by: '<Root>/Up-Counter (with upper bound)1'
                                   */
  real_T UpCounterwithupperbound_C0;
                                   /* Mask Parameter: UpCounterwithupperbound_C0
                                    * Referenced by: '<Root>/Up-Counter (with upper bound)'
                                    */
  real_T UpCounterwithupperbound1_CMAX;
                                /* Mask Parameter: UpCounterwithupperbound1_CMAX
                                 * Referenced by: '<Root>/Up-Counter (with upper bound)1'
                                 */
  real_T UpCounterwithupperbound_CMAX;
                                 /* Mask Parameter: UpCounterwithupperbound_CMAX
                                  * Referenced by: '<Root>/Up-Counter (with upper bound)'
                                  */
  real_T Monostable1_Tp;               /* Mask Parameter: Monostable1_Tp
                                        * Referenced by: '<Root>/Monostable1'
                                        */
  real_T Monostable_Tp;                /* Mask Parameter: Monostable_Tp
                                        * Referenced by: '<Root>/Monostable'
                                        */
  real_T gam_refdeg_Y0;                /* Expression: [0]
                                        * Referenced by: '<S7>/gam_ref[deg]'
                                        */
  real_T Outduty_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S8>/Out[duty]'
                                        */
  real_T uduty_Y0;                     /* Expression: [0]
                                        * Referenced by: '<S9>/u [duty]'
                                        */
  real_T Statefeedback_Gain[4];        /* Expression: K'
                                        * Referenced by: '<S9>/State feedback'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S23>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S23>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S23>/Gain2'
                                        */
  real_T LPF_NumCoef[2];               /* Expression: [numLPFz]
                                        * Referenced by: '<S23>/LPF'
                                        */
  real_T LPF_DenCoef[2];               /* Expression: [denLPFz]
                                        * Referenced by: '<S23>/LPF'
                                        */
  real_T LPF_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S23>/LPF'
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
  real_T Speedfilter2_NumCoef[4];      /* Expression: [numHw]
                                        * Referenced by: '<S11>/Speed filter 2'
                                        */
  real_T Speedfilter2_DenCoef[4];      /* Expression: [denHw]
                                        * Referenced by: '<S11>/Speed filter 2'
                                        */
  real_T Speedfilter2_InitialStates;   /* Expression: 0
                                        * Referenced by: '<S11>/Speed filter 2'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S21>/Gain'
                                        */
  int32_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S15>/Gain'
                                        */
  int32_T Gain_Gain_pt;                /* Computed Parameter: Gain_Gain_pt
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain1_Gain_g;               /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S18>/Gain1'
                                        */
  int16_T wxraw2dps_Gain;              /* Computed Parameter: wxraw2dps_Gain
                                        * Referenced by: '<S17>/wxraw2dps'
                                        */
  int16_T ayraw2g_Gain;                /* Computed Parameter: ayraw2g_Gain
                                        * Referenced by: '<S17>/ayraw2g'
                                        */
  int16_T azraw2g_Gain;                /* Computed Parameter: azraw2g_Gain
                                        * Referenced by: '<S17>/azraw2g'
                                        */
  P_UpCounterwithupperbound_nom_T UpCounterwithupperbound1;
                                   /* '<Root>/Up-Counter (with upper bound)1' */
  P_UpCounterwithupperbound_nom_T UpCounterwithupperbound;
                                    /* '<Root>/Up-Counter (with upper bound)' */
  P_Monostable_nominal_REALTIME_T Monostable1;/* '<Root>/Monostable1' */
  P_Monostable_nominal_REALTIME_T Monostable;/* '<Root>/Monostable' */
};

/* Real-time Model Data Structure */
struct tag_RTM_nominal_REALTIME_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_nominal_REALTIME_T nominal_REALTIME_P;

/* Block signals (default storage) */
extern B_nominal_REALTIME_T nominal_REALTIME_B;

/* Block states (default storage) */
extern DW_nominal_REALTIME_T nominal_REALTIME_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_nominal_REALTIME_T nominal_REALTIME_PrevZCX;

/* Model entry point functions */
extern void nominal_REALTIME_initialize(void);
extern void nominal_REALTIME_step(void);
extern void nominal_REALTIME_terminate(void);

/* Real-time Model object */
extern RT_MODEL_nominal_REALTIME_T *const nominal_REALTIME_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S17>/Data Type Conversion' : Unused code path elimination
 * Block '<S17>/Data Type Conversion4' : Unused code path elimination
 * Block '<S17>/Data Type Conversion5' : Unused code path elimination
 * Block '<S17>/axraw2g' : Unused code path elimination
 * Block '<S17>/wyraw2dps' : Unused code path elimination
 * Block '<S17>/wzraw2dps' : Unused code path elimination
 * Block '<S18>/Gain' : Unused code path elimination
 * Block '<S18>/Gain2' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'nominal_REALTIME'
 * '<S1>'   : 'nominal_REALTIME/Encoders'
 * '<S2>'   : 'nominal_REALTIME/MPU6050 Inertial Measurement Unit'
 * '<S3>'   : 'nominal_REALTIME/Monostable'
 * '<S4>'   : 'nominal_REALTIME/Monostable1'
 * '<S5>'   : 'nominal_REALTIME/Motors'
 * '<S6>'   : 'nominal_REALTIME/Pushbuttons'
 * '<S7>'   : 'nominal_REALTIME/Reference generator'
 * '<S8>'   : 'nominal_REALTIME/Reference generator1'
 * '<S9>'   : 'nominal_REALTIME/SS controller nominal'
 * '<S10>'  : 'nominal_REALTIME/Serial Packet Send'
 * '<S11>'  : 'nominal_REALTIME/State Observer'
 * '<S12>'  : 'nominal_REALTIME/Up-Counter (with upper bound)'
 * '<S13>'  : 'nominal_REALTIME/Up-Counter (with upper bound)1'
 * '<S14>'  : 'nominal_REALTIME/Encoders/Encoders'
 * '<S15>'  : 'nominal_REALTIME/Encoders/To Wheel Frames'
 * '<S16>'  : 'nominal_REALTIME/MPU6050 Inertial Measurement Unit/MPU'
 * '<S17>'  : 'nominal_REALTIME/MPU6050 Inertial Measurement Unit/Raw to physical units'
 * '<S18>'  : 'nominal_REALTIME/MPU6050 Inertial Measurement Unit/To Body Frame'
 * '<S19>'  : 'nominal_REALTIME/Monostable/Compare To Constant'
 * '<S20>'  : 'nominal_REALTIME/Monostable1/Compare To Constant'
 * '<S21>'  : 'nominal_REALTIME/Motors/From Wheel Frames'
 * '<S22>'  : 'nominal_REALTIME/Motors/Motors'
 * '<S23>'  : 'nominal_REALTIME/State Observer/Complementary filter'
 */
#endif                                 /* RTW_HEADER_nominal_REALTIME_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
