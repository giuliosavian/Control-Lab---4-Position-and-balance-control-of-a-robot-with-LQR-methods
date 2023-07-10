/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: robust_drift_REALTIME_data.c
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

#include "robust_drift_REALTIME.h"
#include "robust_drift_REALTIME_private.h"

/* Block parameters (default storage) */
P_robust_drift_REALTIME_T robust_drift_REALTIME_P = {
  /* Variable: sens
   * Referenced by:
   *   '<S11>/pulse2deg'
   *   '<S11>/pulse2deg1'
   */
  {
    {
      64.0,
      5.625,
      0.098174770424681035,
      0.17777777777777778,
      10.185916357881302
    },

    {
      0.0,
      0.0,
      0.0135,

      {
        16.0,
        16.0,
        156.96,
        2048.0,
        208.76656472986747,
        0.00048828125,
        0.0047900390625,
        94.0,
        0.004,
        1.6e-5
      },

      {
        16.0,
        250.0,
        4.3633231299858242,
        131.0,
        7505.7471162137845,
        0.00762939453125,
        0.00013315805450396192,
        98.0,
        0.05,
        1.6e-5
      }
    }
  },

  /* Variable: wheel
   * Referenced by: '<S7>/Constant'
   */
  {
    0.026,
    0.034,
    0.0,
    0.1,
    0.0,
    0.05,
    1.7266666666666668e-5,
    2.8900000000000005e-5,
    1.7266666666666668e-5,
    0.0015
  },

  /* Variable: drv
   * Referenced by:
   *   '<S8>/Constant'
   *   '<S24>/V2duty1'
   *   '<S25>/V2duty'
   */
  {
    11.1,

    {
      8.0,
      256.0
    },
    255.0,
    0.043529411764705879,
    22.972972972972975
  },

  /* Variable: gbox
   * Referenced by:
   *   '<S11>/mot2load'
   *   '<S11>/mot2load1'
   */
  {
    30.0,
    0.025
  },

  /* Variable: Ki
   * Referenced by: '<S25>/integral gain (???)'
   */
  -0.013035510196433292,

  /* Variable: N_u
   * Referenced by: '<S25>/Input feedforward'
   */
  0.0,

  /* Variable: N_x
   * Referenced by: '<S25>/State feedforward	'
   */
  { 1.0, 0.0, -0.0, 0.0 },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S24>/deg2rad3'
   *   '<S25>/deg2rad'
   *   '<S25>/deg2rad1'
   *   '<S25>/deg2rad2'
   *   '<S26>/Gain'
   */
  0.017453292519943295,

  /* Variable: rad2deg
   * Referenced by:
   *   '<S7>/Constant'
   *   '<S26>/rad2deg'
   */
  57.295779513082323,

  /* Mask Parameter: UpCounterwithupperbound_C0
   * Referenced by: '<Root>/Up-Counter (with upper bound)'
   */
  0.0,

  /* Mask Parameter: UpCounterwithupperbound1_C0
   * Referenced by: '<Root>/Up-Counter (with upper bound)1'
   */
  0.0,

  /* Mask Parameter: UpCounterwithupperbound_CMAX
   * Referenced by: '<Root>/Up-Counter (with upper bound)'
   */
  10.0,

  /* Mask Parameter: UpCounterwithupperbound1_CMAX
   * Referenced by: '<Root>/Up-Counter (with upper bound)1'
   */
  10.0,

  /* Mask Parameter: Monostable_Tp
   * Referenced by: '<Root>/Monostable'
   */
  10.0,

  /* Mask Parameter: Monostable1_Tp
   * Referenced by: '<Root>/Monostable1'
   */
  10.0,

  /* Expression: [0]
   * Referenced by: '<S8>/Out[duty]'
   */
  0.0,

  /* Computed Parameter: uduty_Y0
   * Referenced by: '<S9>/u [duty]'
   */
  0.0,

  /* Computed Parameter: uduty1_Y0
   * Referenced by: '<S9>/u [duty]1'
   */
  0.0,

  /* Expression: K'
   * Referenced by: '<S25>/State feedback'
   */
  { -1.9326370245447111, -65.726637736306841, -1.7157694514193598,
    -7.3799936733678306 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S24>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S24>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S24>/Step'
   */
  0.0,

  /* Expression: 3.3
   * Referenced by: '<S24>/Proportional gain'
   */
  3.3,

  /* Expression: 0.7
   * Referenced by: '<S24>/Integral gain'
   */
  0.7,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S26>/Gain1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S26>/Gain2'
   */
  -1.0,

  /* Expression: [numLPFz]
   * Referenced by: '<S26>/LPF'
   */
  { 0.021517944265749128, 0.0 },

  /* Expression: [denLPFz]
   * Referenced by: '<S26>/LPF'
   */
  { 1.0, -0.97848205573425084 },

  /* Expression: 0
   * Referenced by: '<S26>/LPF'
   */
  0.0,

  /* Expression: [numHw]
   * Referenced by: '<S11>/Speed filter 1'
   */
  { 1.0, 0.0, 0.0, -1.0 },

  /* Expression: [denHw]
   * Referenced by: '<S11>/Speed filter 1'
   */
  { 0.03, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S11>/Speed filter 1'
   */
  0.0,

  /* Expression: [numHw]
   * Referenced by: '<S11>/Speed filter 3'
   */
  { 1.0, 0.0, 0.0, -1.0 },

  /* Expression: [denHw]
   * Referenced by: '<S11>/Speed filter 3'
   */
  { 0.03, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S11>/Speed filter 3'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S22>/Gain'
   */
  -1.0,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S16>/Gain'
   */
  MIN_int32_T,

  /* Computed Parameter: Gain1_Gain_h
   * Referenced by: '<S19>/Gain1'
   */
  -1.0F,

  /* Computed Parameter: wxraw2dps_Gain
   * Referenced by: '<S18>/wxraw2dps'
   */
  32018,

  /* Computed Parameter: ayraw2g_Gain
   * Referenced by: '<S18>/ayraw2g'
   */
  16384,

  /* Computed Parameter: azraw2g_Gain
   * Referenced by: '<S18>/azraw2g'
   */
  16384,

  /* Start of '<Root>/Up-Counter (with upper bound)1' */
  {
    /* Expression: 1
     * Referenced by: '<S13>/Constant2'
     */
    1.0
  }
  ,

  /* End of '<Root>/Up-Counter (with upper bound)1' */

  /* Start of '<Root>/Up-Counter (with upper bound)' */
  {
    /* Expression: 1
     * Referenced by: '<S12>/Constant2'
     */
    1.0
  }
  ,

  /* End of '<Root>/Up-Counter (with upper bound)' */

  /* Start of '<Root>/Monostable1' */
  {
    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S4>/Discrete-Time Integrator'
     */
    0.01,

    /* Expression: 0
     * Referenced by: '<S4>/Discrete-Time Integrator'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S4>/Discrete-Time Integrator'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S4>/Constant1'
     */
    1.0,

    /* Computed Parameter: Out_Y0
     * Referenced by: '<S4>/Out'
     */
    0
  }
  ,

  /* End of '<Root>/Monostable1' */

  /* Start of '<Root>/Monostable' */
  {
    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S3>/Discrete-Time Integrator'
     */
    0.01,

    /* Expression: 0
     * Referenced by: '<S3>/Discrete-Time Integrator'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S3>/Discrete-Time Integrator'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S3>/Constant1'
     */
    1.0,

    /* Computed Parameter: Out_Y0
     * Referenced by: '<S3>/Out'
     */
    0
  }
  /* End of '<Root>/Monostable' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
