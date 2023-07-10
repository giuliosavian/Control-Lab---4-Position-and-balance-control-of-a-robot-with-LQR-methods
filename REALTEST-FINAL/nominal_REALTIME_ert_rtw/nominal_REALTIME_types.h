/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: nominal_REALTIME_types.h
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

#ifndef RTW_HEADER_nominal_REALTIME_types_h_
#define RTW_HEADER_nominal_REALTIME_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_p66wMqgqG0tqrYXpsxIiT_
#define DEFINED_TYPEDEF_FOR_struct_p66wMqgqG0tqrYXpsxIiT_

typedef struct {
  real_T h;
  real_T r;
  real_T xb;
  real_T yb;
  real_T zb;
  real_T m;
  real_T Ixx;
  real_T Iyy;
  real_T Izz;
  real_T B;
} struct_p66wMqgqG0tqrYXpsxIiT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_d8cmdukBJ5Nd7RbUzCHyC_
#define DEFINED_TYPEDEF_FOR_struct_d8cmdukBJ5Nd7RbUzCHyC_

typedef struct {
  real_T bits;
  real_T levels;
} struct_d8cmdukBJ5Nd7RbUzCHyC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Wq2SEuethZwdYr1NQjhMYF_
#define DEFINED_TYPEDEF_FOR_struct_Wq2SEuethZwdYr1NQjhMYF_

typedef struct {
  real_T Vbus;
  struct_d8cmdukBJ5Nd7RbUzCHyC pwm;
  real_T dutymax;
  real_T duty2V;
  real_T V2duty;
} struct_Wq2SEuethZwdYr1NQjhMYF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_X2VAEXKuhkaiuxF0Z4qglD_
#define DEFINED_TYPEDEF_FOR_struct_X2VAEXKuhkaiuxF0Z4qglD_

typedef struct {
  real_T N;
  real_T B;
} struct_X2VAEXKuhkaiuxF0Z4qglD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_
#define DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_

typedef struct {
  real_T ppr;
  real_T pulse2deg;
  real_T pulse2rad;
  real_T deg2pulse;
  real_T rad2pulse;
} struct_nZqFUEOh71pPhzsMP64FWD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ftcYWn2dqP1JlOLB454i0D_
#define DEFINED_TYPEDEF_FOR_struct_ftcYWn2dqP1JlOLB454i0D_

typedef struct {
  real_T bits;
  real_T fs_g;
  real_T fs;
  real_T g2LSB;
  real_T ms22LSB;
  real_T LSB2g;
  real_T LSB2ms2;
  real_T bw;
  real_T noisestd;
  real_T noisevar;
} struct_ftcYWn2dqP1JlOLB454i0D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OGsdivEIlFPpoTvZhXJp2C_
#define DEFINED_TYPEDEF_FOR_struct_OGsdivEIlFPpoTvZhXJp2C_

typedef struct {
  real_T bits;
  real_T fs_degs;
  real_T fs;
  real_T degs2LSB;
  real_T rads2LSB;
  real_T LSB2degs;
  real_T LSB2rads;
  real_T bw;
  real_T noisestd;
  real_T noisevar;
} struct_OGsdivEIlFPpoTvZhXJp2C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vZUFa5TfBPunEBje2rifzD_
#define DEFINED_TYPEDEF_FOR_struct_vZUFa5TfBPunEBje2rifzD_

typedef struct {
  real_T xb;
  real_T yb;
  real_T zb;
  struct_ftcYWn2dqP1JlOLB454i0D acc;
  struct_OGsdivEIlFPpoTvZhXJp2C gyro;
} struct_vZUFa5TfBPunEBje2rifzD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZyOsf22oZpzf3TbBVA5VPH_
#define DEFINED_TYPEDEF_FOR_struct_ZyOsf22oZpzf3TbBVA5VPH_

typedef struct {
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_vZUFa5TfBPunEBje2rifzD mpu;
} struct_ZyOsf22oZpzf3TbBVA5VPH;

#endif

/* Parameters for system: '<Root>/Monostable' */
typedef struct P_Monostable_nominal_REALTIME_T_ P_Monostable_nominal_REALTIME_T;

/* Parameters for system: '<Root>/Up-Counter (with upper bound)' */
typedef struct P_UpCounterwithupperbound_nom_T_ P_UpCounterwithupperbound_nom_T;

/* Parameters (default storage) */
typedef struct P_nominal_REALTIME_T_ P_nominal_REALTIME_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_nominal_REALTIME_T RT_MODEL_nominal_REALTIME_T;

#endif                                /* RTW_HEADER_nominal_REALTIME_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
