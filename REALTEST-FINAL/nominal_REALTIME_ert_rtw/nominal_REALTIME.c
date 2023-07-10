/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: nominal_REALTIME.c
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

#include "nominal_REALTIME.h"
#include "nominal_REALTIME_private.h"

/* Block signals (default storage) */
B_nominal_REALTIME_T nominal_REALTIME_B;

/* Block states (default storage) */
DW_nominal_REALTIME_T nominal_REALTIME_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_nominal_REALTIME_T nominal_REALTIME_PrevZCX;

/* Real-time model */
static RT_MODEL_nominal_REALTIME_T nominal_REALTIME_M_;
RT_MODEL_nominal_REALTIME_T *const nominal_REALTIME_M = &nominal_REALTIME_M_;
real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0L ? ~(uint32_T)in0 + 1UL : (uint32_T)in0;
  absIn1 = in1 < 0L ? ~(uint32_T)in1 + 1UL : (uint32_T)in1;
  in0Hi = absIn0 >> 16UL;
  in0Lo = absIn0 & 65535UL;
  in1Hi = absIn1 >> 16UL;
  absIn0 = absIn1 & 65535UL;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0UL;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16UL) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1UL;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16UL;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0L) && ((in1 != 0L) && ((in0 > 0L) != (in1 > 0L)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0UL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32UL - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

/*
 * System initialize for enable system:
 *    '<Root>/Monostable'
 *    '<Root>/Monostable1'
 */
void nominal_REALTIM_Monostable_Init(boolean_T *rty_Out,
  DW_Monostable_nominal_REALTIM_T *localDW, P_Monostable_nominal_REALTIME_T
  *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;

  /* SystemInitialize for Outport: '<S3>/Out' */
  *rty_Out = localP->Out_Y0;
}

/*
 * System reset for enable system:
 *    '<Root>/Monostable'
 *    '<Root>/Monostable1'
 */
void nominal_REALTI_Monostable_Reset(DW_Monostable_nominal_REALTIM_T *localDW,
  P_Monostable_nominal_REALTIME_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
}

/*
 * Disable for enable system:
 *    '<Root>/Monostable'
 *    '<Root>/Monostable1'
 */
void nominal_REAL_Monostable_Disable(DW_Monostable_nominal_REALTIM_T *localDW)
{
  localDW->Monostable_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<Root>/Monostable'
 *    '<Root>/Monostable1'
 */
void nominal_REALTIME_Monostable(real_T rtu_Enable, boolean_T *rty_Out,
  DW_Monostable_nominal_REALTIM_T *localDW, P_Monostable_nominal_REALTIME_T
  *localP, real_T rtp_Tp)
{
  /* Outputs for Enabled SubSystem: '<Root>/Monostable' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtu_Enable > 0.0) {
    if (!localDW->Monostable_MODE) {
      nominal_REALTI_Monostable_Reset(localDW, localP);
      localDW->Monostable_MODE = true;
    }

    /* RelationalOperator: '<S19>/Compare' incorporates:
     *  Constant: '<S19>/Constant'
     *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
     */
    *rty_Out = (localDW->DiscreteTimeIntegrator_DSTATE < rtp_Tp);

    /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * localP->Constant1_Value;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= rtp_Tp) {
      localDW->DiscreteTimeIntegrator_DSTATE = rtp_Tp;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <=
          localP->DiscreteTimeIntegrator_LowerSat) {
        localDW->DiscreteTimeIntegrator_DSTATE =
          localP->DiscreteTimeIntegrator_LowerSat;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  } else {
    if (localDW->Monostable_MODE) {
      nominal_REAL_Monostable_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Monostable' */
}

/*
 * System initialize for trigger system:
 *    '<Root>/Up-Counter (with upper bound)'
 *    '<Root>/Up-Counter (with upper bound)1'
 */
void no_UpCounterwithupperbound_Init(real_T *rty_Out,
  DW_UpCounterwithupperbound_no_T *localDW, real_T rtp_C0)
{
  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_C0;

  /* SystemInitialize for Outport: '<S12>/Out' */
  *rty_Out = rtp_C0;
}

/*
 * Output and update for trigger system:
 *    '<Root>/Up-Counter (with upper bound)'
 *    '<Root>/Up-Counter (with upper bound)1'
 */
void nominal_UpCounterwithupperbound(uint8_T rtu_Trigger, real_T *rty_Out,
  DW_UpCounterwithupperbound_no_T *localDW, P_UpCounterwithupperbound_nom_T
  *localP, ZCE_UpCounterwithupperbound_n_T *localZCE, real_T rtp_C0, real_T
  rtp_CMAX)
{
  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  if ((rtu_Trigger > 0) && (localZCE->UpCounterwithupperbound_Trig_ZC != 1)) {
    /* Sum: '<S12>/Sum1' incorporates:
     *  Constant: '<S12>/Constant2'
     *  UnitDelay: '<S12>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE += localP->Constant2_Value;

    /* Saturate: '<S12>/Saturation' incorporates:
     *  UnitDelay: '<S12>/Unit Delay'
     */
    if (localDW->UnitDelay_DSTATE > rtp_CMAX) {
      *rty_Out = rtp_CMAX;
    } else if (localDW->UnitDelay_DSTATE < rtp_C0) {
      *rty_Out = rtp_C0;
    } else {
      *rty_Out = localDW->UnitDelay_DSTATE;
    }

    /* End of Saturate: '<S12>/Saturation' */
  }

  localZCE->UpCounterwithupperbound_Trig_ZC = (ZCSigState)(rtu_Trigger > 0);

  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)' */
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
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

/* Model step function */
void nominal_REALTIME_step(void)
{
  int64m_T tmp;
  real_T denAccum;
  real_T rtb_DataTypeConversion7;
  real_T rtb_Sum_c;
  real_T rtb_rad2deg;
  int32_T rtb_Add;
  real32_T rtb_DataTypeConversion1;
  real32_T rtb_Gain1_b;
  uint32_T tmp_0;
  uint32_T tmp_1;

  /* S-Function (sfun_BalRobTbx_Pushbuttons): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function */
  sfun_BalRobTbx_Pushbuttons_WrappedOutput(&nominal_REALTIME_B.SFunction_o1_h,
    &nominal_REALTIME_B.SFunction_o2_o);

  /* S-Function (sfun_BalRobTbx_Encoders): '<S14>/S-Function' */

  /* S-Function Block: <S14>/S-Function */
  sfun_BalRobTbx_Encoders_WrappedOutput(&nominal_REALTIME_B.SFunction_o1,
    &nominal_REALTIME_B.SFunction_o2);

  /* S-Function (sfun_BalRobTbx_MPU6050): '<S16>/S-Function' */

  /* S-Function Block: <S16>/S-Function */
  sfun_BalRobTbx_MPU6050_WrappedOutput(&nominal_REALTIME_B.SFunction_o1_g[0],
    &nominal_REALTIME_B.SFunction_o2_i[0]);

  /* Gain: '<S15>/Gain' */
  rtb_Add = mul_s32_loSR(nominal_REALTIME_P.Gain_Gain_p,
    nominal_REALTIME_B.SFunction_o2, 31UL);

  /* SignalConversion generated from: '<S10>/S-Function' */
  nominal_REALTIME_B.TmpSignalConversionAtSFunctio_i[0] =
    nominal_REALTIME_B.SFunction_o1;
  nominal_REALTIME_B.TmpSignalConversionAtSFunctio_i[1] = rtb_Add;

  /* SignalConversion generated from: '<S10>/S-Function' */
  nominal_REALTIME_B.TmpSignalConversionAtSFunctio_c[0] =
    nominal_REALTIME_B.SFunction_o1_h;
  nominal_REALTIME_B.TmpSignalConversionAtSFunctio_c[1] =
    nominal_REALTIME_B.SFunction_o2_o;

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  Gain: '<S17>/ayraw2g'
   */
  rtb_DataTypeConversion1 = (real32_T)((int32_T)nominal_REALTIME_P.ayraw2g_Gain *
    nominal_REALTIME_B.SFunction_o1_g[1]) * 2.98023224E-8F;

  /* Gain: '<S18>/Gain1' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion3'
   *  Gain: '<S17>/azraw2g'
   */
  rtb_Gain1_b = (real32_T)((int32_T)nominal_REALTIME_P.azraw2g_Gain *
    nominal_REALTIME_B.SFunction_o1_g[2]) * 2.98023224E-8F *
    nominal_REALTIME_P.Gain1_Gain_g;

  /* SignalConversion generated from: '<S10>/S-Function' */
  nominal_REALTIME_B.TmpSignalConversionAtSFunctionI[0] =
    rtb_DataTypeConversion1;
  nominal_REALTIME_B.TmpSignalConversionAtSFunctionI[1] = rtb_Gain1_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion2' incorporates:
   *  Gain: '<S17>/wxraw2dps'
   */
  nominal_REALTIME_B.DataTypeConversion2 = (real32_T)((int32_T)
    nominal_REALTIME_P.wxraw2dps_Gain * nominal_REALTIME_B.SFunction_o2_i[0]) *
    2.38418579E-7F;

  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  nominal_UpCounterwithupperbound(nominal_REALTIME_B.SFunction_o2_o,
    &nominal_REALTIME_B.Saturation,
    &nominal_REALTIME_DW.UpCounterwithupperbound1,
    &nominal_REALTIME_P.UpCounterwithupperbound1,
    &nominal_REALTIME_PrevZCX.UpCounterwithupperbound1,
    nominal_REALTIME_P.UpCounterwithupperbound1_C0,
    nominal_REALTIME_P.UpCounterwithupperbound1_CMAX);

  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)1' */

  /* Outputs for Enabled SubSystem: '<Root>/Monostable1' */
  /* Outputs for Enabled SubSystem: '<Root>/Monostable1' */
  nominal_REALTIME_Monostable(nominal_REALTIME_B.Saturation,
    &nominal_REALTIME_B.Compare, &nominal_REALTIME_DW.Monostable1,
    &nominal_REALTIME_P.Monostable1, nominal_REALTIME_P.Monostable1_Tp);

  /* End of Outputs for SubSystem: '<Root>/Monostable1' */
  /* End of Outputs for SubSystem: '<Root>/Monostable1' */

  /* Outputs for Enabled SubSystem: '<Root>/Reference generator1' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Logic: '<Root>/Logical Operator2' incorporates:
   *  Constant: '<S8>/Constant'
   *  Logic: '<Root>/Logical Operator3'
   */
  if ((nominal_REALTIME_B.Saturation != 0.0) && (!nominal_REALTIME_B.Compare)) {
    nominal_REALTIME_B.Constant = 5.0 / nominal_REALTIME_P.drv.duty2V;
  }

  /* End of Logic: '<Root>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<Root>/Reference generator1' */

  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  nominal_UpCounterwithupperbound(nominal_REALTIME_B.SFunction_o1_h,
    &nominal_REALTIME_B.Saturation_p,
    &nominal_REALTIME_DW.UpCounterwithupperbound,
    &nominal_REALTIME_P.UpCounterwithupperbound,
    &nominal_REALTIME_PrevZCX.UpCounterwithupperbound,
    nominal_REALTIME_P.UpCounterwithupperbound_C0,
    nominal_REALTIME_P.UpCounterwithupperbound_CMAX);

  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)' */

  /* Outputs for Enabled SubSystem: '<Root>/Monostable' */
  /* Outputs for Enabled SubSystem: '<Root>/Monostable' */
  nominal_REALTIME_Monostable(nominal_REALTIME_B.Saturation_p,
    &nominal_REALTIME_B.Compare_l, &nominal_REALTIME_DW.Monostable,
    &nominal_REALTIME_P.Monostable, nominal_REALTIME_P.Monostable_Tp);

  /* End of Outputs for SubSystem: '<Root>/Monostable' */
  /* End of Outputs for SubSystem: '<Root>/Monostable' */

  /* Outputs for Enabled SubSystem: '<Root>/Reference generator' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<S7>/Constant'
   *  Logic: '<Root>/Logical Operator1'
   */
  if ((nominal_REALTIME_B.Saturation_p != 0.0) && (!nominal_REALTIME_B.Compare_l))
  {
    nominal_REALTIME_B.Constant_m = 0.1 / nominal_REALTIME_P.wheel.r *
      nominal_REALTIME_P.rad2deg;
  }

  /* End of Logic: '<Root>/Logical Operator' */
  /* End of Outputs for SubSystem: '<Root>/Reference generator' */

  /* DiscreteTransferFcn: '<S23>/LPF' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   *  Gain: '<S23>/Gain1'
   *  Gain: '<S23>/Gain2'
   *  Sum: '<S23>/Sum'
   *  Trigonometry: '<S23>/Trigonometric Function'
   */
  nominal_REALTIME_B.denAccum = ((rt_atan2d_snf(nominal_REALTIME_P.Gain1_Gain *
    rtb_DataTypeConversion1, nominal_REALTIME_P.Gain2_Gain * rtb_Gain1_b) -
    nominal_REALTIME_DW.DiscreteTimeIntegrator_DSTATE) -
    nominal_REALTIME_P.LPF_DenCoef[1L] * nominal_REALTIME_DW.LPF_states) /
    nominal_REALTIME_P.LPF_DenCoef[0];

  /* Gain: '<S23>/rad2deg' incorporates:
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S23>/LPF'
   *  Sum: '<S23>/Sum1'
   */
  rtb_rad2deg = ((nominal_REALTIME_P.LPF_NumCoef[0] *
                  nominal_REALTIME_B.denAccum + nominal_REALTIME_P.LPF_NumCoef
                  [1L] * nominal_REALTIME_DW.LPF_states) +
                 nominal_REALTIME_DW.DiscreteTimeIntegrator_DSTATE) *
    nominal_REALTIME_P.rad2deg;

  /* Sum: '<Root>/Add' */
  rtb_Add += nominal_REALTIME_B.SFunction_o1;

  /* Gain: '<Root>/Gain' */
  tmp_0 = (uint32_T)nominal_REALTIME_P.Gain_Gain_pt;
  tmp_1 = (uint32_T)rtb_Add;
  sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

  /* Sum: '<S11>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Gain: '<S11>/mot2load'
   *  Gain: '<S11>/pulse2deg'
   */
  rtb_Sum_c = sMultiWord2Double(&tmp.chunks[0U], 2, 0) * 4.6566128730773926E-10 *
    nominal_REALTIME_P.sens.enc.pulse2deg * (1.0 / nominal_REALTIME_P.gbox.N) +
    rtb_rad2deg;

  /* DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_B.denAccum_m = (((rtb_Sum_c -
    nominal_REALTIME_P.Speedfilter1_DenCoef[1L] *
    nominal_REALTIME_DW.Speedfilter1_states[0L]) -
    nominal_REALTIME_P.Speedfilter1_DenCoef[2L] *
    nominal_REALTIME_DW.Speedfilter1_states[1L]) -
    nominal_REALTIME_P.Speedfilter1_DenCoef[3L] *
    nominal_REALTIME_DW.Speedfilter1_states[2L]) /
    nominal_REALTIME_P.Speedfilter1_DenCoef[0];

  /* DiscreteTransferFcn: '<S11>/Speed filter 2' */
  denAccum = (((rtb_rad2deg - nominal_REALTIME_P.Speedfilter2_DenCoef[1L] *
                nominal_REALTIME_DW.Speedfilter2_states[0L]) -
               nominal_REALTIME_P.Speedfilter2_DenCoef[2L] *
               nominal_REALTIME_DW.Speedfilter2_states[1L]) -
              nominal_REALTIME_P.Speedfilter2_DenCoef[3L] *
              nominal_REALTIME_DW.Speedfilter2_states[2L]) /
    nominal_REALTIME_P.Speedfilter2_DenCoef[0];

  /* Outputs for Enabled SubSystem: '<Root>/SS controller nominal' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* Logic: '<Root>/Logical Operator4' */
  if ((nominal_REALTIME_B.Saturation_p != 0.0) || (nominal_REALTIME_B.Saturation
       != 0.0)) {
    /* Gain: '<S9>/deg2rad' */
    rtb_DataTypeConversion7 = nominal_REALTIME_P.deg2rad *
      nominal_REALTIME_B.Constant_m;

    /* Gain: '<S9>/V2duty' incorporates:
     *  DiscreteTransferFcn: '<S11>/Speed filter 1'
     *  DiscreteTransferFcn: '<S11>/Speed filter 2'
     *  Gain: '<S9>/Input feedforward'
     *  Gain: '<S9>/State feedback'
     *  Gain: '<S9>/State feedforward	'
     *  Gain: '<S9>/deg2rad1'
     *  Sum: '<S9>/Sum'
     *  Sum: '<S9>/Sum2'
     */
    nominal_REALTIME_B.V2duty = ((((rtb_DataTypeConversion7 *
      nominal_REALTIME_P.N_x[2] - (((nominal_REALTIME_P.Speedfilter1_NumCoef[0] *
      nominal_REALTIME_B.denAccum_m + nominal_REALTIME_P.Speedfilter1_NumCoef[1L]
      * nominal_REALTIME_DW.Speedfilter1_states[0L]) +
      nominal_REALTIME_P.Speedfilter1_NumCoef[2L] *
      nominal_REALTIME_DW.Speedfilter1_states[1L]) +
      nominal_REALTIME_P.Speedfilter1_NumCoef[3L] *
      nominal_REALTIME_DW.Speedfilter1_states[2L]) * nominal_REALTIME_P.deg2rad)
      * nominal_REALTIME_P.Statefeedback_Gain[2] + ((rtb_DataTypeConversion7 *
      nominal_REALTIME_P.N_x[0] - nominal_REALTIME_P.deg2rad * rtb_Sum_c) *
      nominal_REALTIME_P.Statefeedback_Gain[0] + (rtb_DataTypeConversion7 *
      nominal_REALTIME_P.N_x[1] - nominal_REALTIME_P.deg2rad * rtb_rad2deg) *
      nominal_REALTIME_P.Statefeedback_Gain[1])) + (rtb_DataTypeConversion7 *
      nominal_REALTIME_P.N_x[3] - (((nominal_REALTIME_P.Speedfilter2_NumCoef[0] *
      denAccum + nominal_REALTIME_P.Speedfilter2_NumCoef[1L] *
      nominal_REALTIME_DW.Speedfilter2_states[0L]) +
      nominal_REALTIME_P.Speedfilter2_NumCoef[2L] *
      nominal_REALTIME_DW.Speedfilter2_states[1L]) +
      nominal_REALTIME_P.Speedfilter2_NumCoef[3L] *
      nominal_REALTIME_DW.Speedfilter2_states[2L]) * nominal_REALTIME_P.deg2rad)
      * nominal_REALTIME_P.Statefeedback_Gain[3]) + nominal_REALTIME_P.N_u *
      rtb_DataTypeConversion7) * nominal_REALTIME_P.drv.V2duty;
  }

  /* End of Logic: '<Root>/Logical Operator4' */
  /* End of Outputs for SubSystem: '<Root>/SS controller nominal' */

  /* Sum: '<Root>/Sum' */
  rtb_DataTypeConversion7 = nominal_REALTIME_B.V2duty -
    nominal_REALTIME_B.Constant;

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  rtb_rad2deg = floor(rtb_DataTypeConversion7);
  if (rtIsNaN(rtb_rad2deg) || rtIsInf(rtb_rad2deg)) {
    rtb_rad2deg = 0.0;
  } else {
    rtb_rad2deg = fmod(rtb_rad2deg, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  nominal_REALTIME_B.DataTypeConversion = rtb_rad2deg < 0.0 ? -(int16_T)
    (uint16_T)-rtb_rad2deg : (int16_T)(uint16_T)rtb_rad2deg;

  /* Gain: '<S21>/Gain' */
  rtb_DataTypeConversion7 *= nominal_REALTIME_P.Gain_Gain;

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  rtb_rad2deg = floor(rtb_DataTypeConversion7);
  if (rtIsNaN(rtb_rad2deg) || rtIsInf(rtb_rad2deg)) {
    rtb_rad2deg = 0.0;
  } else {
    rtb_rad2deg = fmod(rtb_rad2deg, 65536.0);
  }

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  nominal_REALTIME_B.DataTypeConversion1 = rtb_rad2deg < 0.0 ? -(int16_T)
    (uint16_T)-rtb_rad2deg : (int16_T)(uint16_T)rtb_rad2deg;

  /* S-Function (sfun_BalRobTbx_Motors): '<S22>/S-Function' */

  /* S-Function Block: <S22>/S-Function */
  sfun_BalRobTbx_Motors_WrappedOutput(&nominal_REALTIME_B.DataTypeConversion,
    &nominal_REALTIME_B.DataTypeConversion1);

  /* S-Function (sfun_BalRobTbx_SerialPacketSend): '<S10>/S-Function' */
  /* S-Function Block: <S10>/S-Function */

  /*  Pack input signals to payload buffer  */
  {
    uint8_T *pAux = (uint8_T *)nominal_REALTIME_DW.SFunction_DWORK1[0];

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &nominal_REALTIME_B.TmpSignalConversionAtSFunctio_c[0], 2);
    pAux += 2;

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &nominal_REALTIME_B.TmpSignalConversionAtSFunctio_i[0], 8);
    pAux += 8;

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &nominal_REALTIME_B.TmpSignalConversionAtSFunctionI[0], 8);
    pAux += 8;

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &nominal_REALTIME_B.DataTypeConversion2, 4);
  }

  /*  Perform COBS encoding  */
  cobsEncode(nominal_REALTIME_DW.SFunction_DWORK1[0], 22U,
             nominal_REALTIME_DW.SFunction_DWORK1[1]);

  /*  Add null terminator  */
  ((uint8_T *)nominal_REALTIME_DW.SFunction_DWORK1[1])[23U] = 0x00;

  /*  Send packet  */
  sfun_BalRobTbx_SerialPacketSend_WrappedOutput(2, (uint8_T*)
    nominal_REALTIME_DW.SFunction_DWORK1[1], 24U, 1, 65U, 66U, (boolean_T *)
    &nominal_REALTIME_DW.SFunction_DWORK2);

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  Gain: '<S23>/Gain'
   */
  nominal_REALTIME_DW.DiscreteTimeIntegrator_DSTATE +=
    nominal_REALTIME_P.deg2rad * nominal_REALTIME_B.DataTypeConversion2 *
    nominal_REALTIME_P.DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteTransferFcn: '<S23>/LPF' */
  nominal_REALTIME_DW.LPF_states = nominal_REALTIME_B.denAccum;

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_DW.Speedfilter1_states[2L] =
    nominal_REALTIME_DW.Speedfilter1_states[1L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 2' */
  nominal_REALTIME_DW.Speedfilter2_states[2L] =
    nominal_REALTIME_DW.Speedfilter2_states[1L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_DW.Speedfilter1_states[1L] =
    nominal_REALTIME_DW.Speedfilter1_states[0L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 2' */
  nominal_REALTIME_DW.Speedfilter2_states[1L] =
    nominal_REALTIME_DW.Speedfilter2_states[0L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_DW.Speedfilter1_states[0L] = nominal_REALTIME_B.denAccum_m;

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 2' */
  nominal_REALTIME_DW.Speedfilter2_states[0L] = denAccum;
}

/* Model initialize function */
void nominal_REALTIME_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (sfun_BalRobTbx_Pushbuttons): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function */
  sfun_BalRobTbx_Pushbuttons_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_Encoders): '<S14>/S-Function' */

  /* S-Function Block: <S14>/S-Function */
  sfun_BalRobTbx_Encoders_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_MPU6050): '<S16>/S-Function' */

  /* S-Function Block: <S16>/S-Function */
  sfun_BalRobTbx_MPU6050_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_Motors): '<S22>/S-Function' */

  /* S-Function Block: <S22>/S-Function */
  sfun_BalRobTbx_Motors_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_SerialPacketSend): '<S10>/S-Function' */

  /* S-Function Block: <S10>/S-Function */

  /*  Allocate payload buffer  */
  nominal_REALTIME_DW.SFunction_DWORK1[0] = calloc(22U, sizeof(uint8_T));

  /*  Allocate packet buffer  */
  nominal_REALTIME_DW.SFunction_DWORK1[1] = calloc(24U, sizeof(uint8_T));

  /*  Set Tx Enable flag to false  */
  nominal_REALTIME_DW.SFunction_DWORK2 = false;

  /*  Invoke Start wrapped function  */
  sfun_BalRobTbx_SerialPacketSend_WrappedStart(2, 38400);
  nominal_REALTIME_PrevZCX.UpCounterwithupperbound1.UpCounterwithupperbound_Trig_ZC
    = POS_ZCSIG;
  nominal_REALTIME_PrevZCX.UpCounterwithupperbound.UpCounterwithupperbound_Trig_ZC
    = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  nominal_REALTIME_DW.DiscreteTimeIntegrator_DSTATE =
    nominal_REALTIME_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S23>/LPF' */
  nominal_REALTIME_DW.LPF_states = nominal_REALTIME_P.LPF_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_DW.Speedfilter1_states[0] =
    nominal_REALTIME_P.Speedfilter1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 2' */
  nominal_REALTIME_DW.Speedfilter2_states[0] =
    nominal_REALTIME_P.Speedfilter2_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_DW.Speedfilter1_states[1] =
    nominal_REALTIME_P.Speedfilter1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 2' */
  nominal_REALTIME_DW.Speedfilter2_states[1] =
    nominal_REALTIME_P.Speedfilter2_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  nominal_REALTIME_DW.Speedfilter1_states[2] =
    nominal_REALTIME_P.Speedfilter1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 2' */
  nominal_REALTIME_DW.Speedfilter2_states[2] =
    nominal_REALTIME_P.Speedfilter2_InitialStates;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  no_UpCounterwithupperbound_Init(&nominal_REALTIME_B.Saturation,
    &nominal_REALTIME_DW.UpCounterwithupperbound1,
    nominal_REALTIME_P.UpCounterwithupperbound1_C0);

  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Monostable1' */
  nominal_REALTIM_Monostable_Init(&nominal_REALTIME_B.Compare,
    &nominal_REALTIME_DW.Monostable1, &nominal_REALTIME_P.Monostable1);

  /* End of SystemInitialize for SubSystem: '<Root>/Monostable1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Reference generator1' */
  /* SystemInitialize for Outport: '<S8>/Out[duty]' incorporates:
   *  Constant: '<S8>/Constant'
   */
  nominal_REALTIME_B.Constant = nominal_REALTIME_P.Outduty_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Reference generator1' */

  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  no_UpCounterwithupperbound_Init(&nominal_REALTIME_B.Saturation_p,
    &nominal_REALTIME_DW.UpCounterwithupperbound,
    nominal_REALTIME_P.UpCounterwithupperbound_C0);

  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Monostable' */
  nominal_REALTIM_Monostable_Init(&nominal_REALTIME_B.Compare_l,
    &nominal_REALTIME_DW.Monostable, &nominal_REALTIME_P.Monostable);

  /* End of SystemInitialize for SubSystem: '<Root>/Monostable' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Reference generator' */
  /* SystemInitialize for Outport: '<S7>/gam_ref[deg]' incorporates:
   *  Constant: '<S7>/Constant'
   */
  nominal_REALTIME_B.Constant_m = nominal_REALTIME_P.gam_refdeg_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Reference generator' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/SS controller nominal' */
  /* SystemInitialize for Gain: '<S9>/V2duty' incorporates:
   *  Outport: '<S9>/u [duty]'
   */
  nominal_REALTIME_B.V2duty = nominal_REALTIME_P.uduty_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/SS controller nominal' */
}

/* Model terminate function */
void nominal_REALTIME_terminate(void)
{
  /* Terminate for S-Function (sfun_BalRobTbx_Pushbuttons): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function */
  sfun_BalRobTbx_Pushbuttons_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_Encoders): '<S14>/S-Function' */

  /* S-Function Block: <S14>/S-Function */
  sfun_BalRobTbx_Encoders_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_MPU6050): '<S16>/S-Function' */

  /* S-Function Block: <S16>/S-Function */
  sfun_BalRobTbx_MPU6050_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_Motors): '<S22>/S-Function' */

  /* S-Function Block: <S22>/S-Function */
  sfun_BalRobTbx_Motors_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_SerialPacketSend): '<S10>/S-Function' */

  /* S-Function Block: <S10>/S-Function */

  /*  Release heap space  */
  free(nominal_REALTIME_DW.SFunction_DWORK1[0]);
  free(nominal_REALTIME_DW.SFunction_DWORK1[1]);

  /*  Set Tx Enable flag to false  */
  nominal_REALTIME_DW.SFunction_DWORK2 = false;

  /*  Invoke Terminate wrapped function  */
  sfun_BalRobTbx_SerialPacketSend_WrappedTerminate(2);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
