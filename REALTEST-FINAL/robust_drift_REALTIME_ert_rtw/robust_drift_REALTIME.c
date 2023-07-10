/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: robust_drift_REALTIME.c
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

/* Block signals (default storage) */
B_robust_drift_REALTIME_T robust_drift_REALTIME_B;

/* Block states (default storage) */
DW_robust_drift_REALTIME_T robust_drift_REALTIME_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_robust_drift_REALTIME_T robust_drift_REALTIME_PrevZCX;

/* Real-time model */
static RT_MODEL_robust_drift_REALTIM_T robust_drift_REALTIME_M_;
RT_MODEL_robust_drift_REALTIM_T *const robust_drift_REALTIME_M =
  &robust_drift_REALTIME_M_;
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
void robust_drift_RE_Monostable_Init(boolean_T *rty_Out,
  DW_Monostable_robust_drift_RE_T *localDW, P_Monostable_robust_drift_REA_T
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
void robust_drift_R_Monostable_Reset(DW_Monostable_robust_drift_RE_T *localDW,
  P_Monostable_robust_drift_REA_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
}

/*
 * Disable for enable system:
 *    '<Root>/Monostable'
 *    '<Root>/Monostable1'
 */
void robust_drift_Monostable_Disable(DW_Monostable_robust_drift_RE_T *localDW)
{
  localDW->Monostable_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<Root>/Monostable'
 *    '<Root>/Monostable1'
 */
void robust_drift_REALTIM_Monostable(real_T rtu_Enable, boolean_T *rty_Out,
  DW_Monostable_robust_drift_RE_T *localDW, P_Monostable_robust_drift_REA_T
  *localP, real_T rtp_Tp)
{
  /* Outputs for Enabled SubSystem: '<Root>/Monostable' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtu_Enable > 0.0) {
    if (!localDW->Monostable_MODE) {
      robust_drift_R_Monostable_Reset(localDW, localP);
      localDW->Monostable_MODE = true;
    }

    /* RelationalOperator: '<S20>/Compare' incorporates:
     *  Constant: '<S20>/Constant'
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
      robust_drift_Monostable_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Monostable' */
}

/*
 * System initialize for trigger system:
 *    '<Root>/Up-Counter (with upper bound)'
 *    '<Root>/Up-Counter (with upper bound)1'
 */
void ro_UpCounterwithupperbound_Init(real_T *rty_Out,
  DW_UpCounterwithupperbound_ro_T *localDW, real_T rtp_C0)
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
void robust__UpCounterwithupperbound(uint8_T rtu_Trigger, real_T *rty_Out,
  DW_UpCounterwithupperbound_ro_T *localDW, P_UpCounterwithupperbound_rob_T
  *localP, ZCE_UpCounterwithupperbound_r_T *localZCE, real_T rtp_C0, real_T
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
void robust_drift_REALTIME_step(void)
{
  real_T deg2rad;
  real_T gamma;
  real_T rad2deg;
  real_T rtb_Sum;
  real_T rtb_Sum1_o;
  int32_T rtb_Gain;
  real32_T rtb_DataTypeConversion1;
  real32_T rtb_Gain1_m;

  /* S-Function (sfun_BalRobTbx_Pushbuttons): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function */
  sfun_BalRobTbx_Pushbuttons_WrappedOutput
    (&robust_drift_REALTIME_B.SFunction_o1_f,
     &robust_drift_REALTIME_B.SFunction_o2_i);

  /* S-Function (sfun_BalRobTbx_Encoders): '<S15>/S-Function' */

  /* S-Function Block: <S15>/S-Function */
  sfun_BalRobTbx_Encoders_WrappedOutput(&robust_drift_REALTIME_B.SFunction_o1,
    &robust_drift_REALTIME_B.SFunction_o2);

  /* S-Function (sfun_BalRobTbx_MPU6050): '<S17>/S-Function' */

  /* S-Function Block: <S17>/S-Function */
  sfun_BalRobTbx_MPU6050_WrappedOutput(&robust_drift_REALTIME_B.SFunction_o1_i[0],
    &robust_drift_REALTIME_B.SFunction_o2_a[0]);

  /* Gain: '<S16>/Gain' */
  rtb_Gain = mul_s32_loSR(robust_drift_REALTIME_P.Gain_Gain_e,
    robust_drift_REALTIME_B.SFunction_o2, 31UL);

  /* SignalConversion generated from: '<S10>/S-Function' */
  robust_drift_REALTIME_B.TmpSignalConversionAtSFunctio_b[0] =
    robust_drift_REALTIME_B.SFunction_o1;
  robust_drift_REALTIME_B.TmpSignalConversionAtSFunctio_b[1] = rtb_Gain;

  /* SignalConversion generated from: '<S10>/S-Function' */
  robust_drift_REALTIME_B.TmpSignalConversionAtSFunctio_p[0] =
    robust_drift_REALTIME_B.SFunction_o1_f;
  robust_drift_REALTIME_B.TmpSignalConversionAtSFunctio_p[1] =
    robust_drift_REALTIME_B.SFunction_o2_i;

  /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
   *  Gain: '<S18>/ayraw2g'
   */
  rtb_DataTypeConversion1 = (real32_T)((int32_T)
    robust_drift_REALTIME_P.ayraw2g_Gain *
    robust_drift_REALTIME_B.SFunction_o1_i[1]) * 2.98023224E-8F;

  /* Gain: '<S19>/Gain1' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion3'
   *  Gain: '<S18>/azraw2g'
   */
  rtb_Gain1_m = (real32_T)((int32_T)robust_drift_REALTIME_P.azraw2g_Gain *
    robust_drift_REALTIME_B.SFunction_o1_i[2]) * 2.98023224E-8F *
    robust_drift_REALTIME_P.Gain1_Gain_h;

  /* SignalConversion generated from: '<S10>/S-Function' */
  robust_drift_REALTIME_B.TmpSignalConversionAtSFunctionI[0] =
    rtb_DataTypeConversion1;
  robust_drift_REALTIME_B.TmpSignalConversionAtSFunctionI[1] = rtb_Gain1_m;

  /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
   *  Gain: '<S18>/wxraw2dps'
   */
  robust_drift_REALTIME_B.DataTypeConversion2 = (real32_T)((int32_T)
    robust_drift_REALTIME_P.wxraw2dps_Gain *
    robust_drift_REALTIME_B.SFunction_o2_a[0]) * 2.38418579E-7F;

  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  robust__UpCounterwithupperbound(robust_drift_REALTIME_B.SFunction_o1_f,
    &robust_drift_REALTIME_B.Saturation_o,
    &robust_drift_REALTIME_DW.UpCounterwithupperbound,
    &robust_drift_REALTIME_P.UpCounterwithupperbound,
    &robust_drift_REALTIME_PrevZCX.UpCounterwithupperbound,
    robust_drift_REALTIME_P.UpCounterwithupperbound_C0,
    robust_drift_REALTIME_P.UpCounterwithupperbound_CMAX);

  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)' */

  /* Outputs for Enabled SubSystem: '<Root>/Monostable' */
  /* Outputs for Enabled SubSystem: '<Root>/Monostable' */
  robust_drift_REALTIM_Monostable(robust_drift_REALTIME_B.Saturation_o,
    &robust_drift_REALTIME_B.Compare_n, &robust_drift_REALTIME_DW.Monostable,
    &robust_drift_REALTIME_P.Monostable, robust_drift_REALTIME_P.Monostable_Tp);

  /* End of Outputs for SubSystem: '<Root>/Monostable' */
  /* End of Outputs for SubSystem: '<Root>/Monostable' */

  /* Outputs for Enabled SubSystem: '<Root>/Reference generator' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* Logic: '<Root>/Logical Operator5' incorporates:
   *  Constant: '<S7>/Constant'
   *  Logic: '<Root>/Logical Operator6'
   */
  if ((robust_drift_REALTIME_B.Saturation_o != 0.0) &&
      (!robust_drift_REALTIME_B.Compare_n)) {
    robust_drift_REALTIME_B.Constant_j = 0.1 / robust_drift_REALTIME_P.wheel.r *
      robust_drift_REALTIME_P.rad2deg;
  }

  /* End of Logic: '<Root>/Logical Operator5' */
  /* End of Outputs for SubSystem: '<Root>/Reference generator' */

  /* DiscreteTransferFcn: '<S26>/LPF' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
   *  Gain: '<S26>/Gain1'
   *  Gain: '<S26>/Gain2'
   *  Sum: '<S26>/Sum'
   *  Trigonometry: '<S26>/Trigonometric Function'
   */
  robust_drift_REALTIME_DW.LPF_tmp = ((rt_atan2d_snf
    (robust_drift_REALTIME_P.Gain1_Gain * rtb_DataTypeConversion1,
     robust_drift_REALTIME_P.Gain2_Gain * rtb_Gain1_m) -
    robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE) -
    robust_drift_REALTIME_P.LPF_DenCoef[1L] *
    robust_drift_REALTIME_DW.LPF_states) / robust_drift_REALTIME_P.LPF_DenCoef[0];

  /* Gain: '<S26>/rad2deg' incorporates:
   *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S26>/LPF'
   *  Sum: '<S26>/Sum1'
   */
  rad2deg = ((robust_drift_REALTIME_P.LPF_NumCoef[0] *
              robust_drift_REALTIME_DW.LPF_tmp +
              robust_drift_REALTIME_P.LPF_NumCoef[1L] *
              robust_drift_REALTIME_DW.LPF_states) +
             robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE) *
    robust_drift_REALTIME_P.rad2deg;

  /* Gain: '<S11>/mot2load' incorporates:
   *  Gain: '<S11>/mot2load1'
   */
  rtb_Sum1_o = 1.0 / robust_drift_REALTIME_P.gbox.N;

  /* Sum: '<S11>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  Gain: '<S11>/mot2load'
   *  Gain: '<S11>/pulse2deg'
   */
  rtb_Sum = rtb_Sum1_o * (robust_drift_REALTIME_P.sens.enc.pulse2deg * (real_T)
    robust_drift_REALTIME_B.SFunction_o1) + rad2deg;

  /* Sum: '<S11>/Sum1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   *  Gain: '<S11>/mot2load1'
   *  Gain: '<S11>/pulse2deg1'
   */
  rtb_Sum1_o = rtb_Sum1_o * (robust_drift_REALTIME_P.sens.enc.pulse2deg *
    (real_T)rtb_Gain) + rad2deg;

  /* MATLAB Function: '<S27>/MATLAB Function' */
  gamma = (rtb_Sum + rtb_Sum1_o) / 2.0;

  /* DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_tmp = (((gamma -
    robust_drift_REALTIME_P.Speedfilter1_DenCoef[1L] *
    robust_drift_REALTIME_DW.Speedfilter1_states[0L]) -
    robust_drift_REALTIME_P.Speedfilter1_DenCoef[2L] *
    robust_drift_REALTIME_DW.Speedfilter1_states[1L]) -
    robust_drift_REALTIME_P.Speedfilter1_DenCoef[3L] *
    robust_drift_REALTIME_DW.Speedfilter1_states[2L]) /
    robust_drift_REALTIME_P.Speedfilter1_DenCoef[0];

  /* DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_tmp = (((rad2deg -
    robust_drift_REALTIME_P.Speedfilter3_DenCoef[1L] *
    robust_drift_REALTIME_DW.Speedfilter3_states[0L]) -
    robust_drift_REALTIME_P.Speedfilter3_DenCoef[2L] *
    robust_drift_REALTIME_DW.Speedfilter3_states[1L]) -
    robust_drift_REALTIME_P.Speedfilter3_DenCoef[3L] *
    robust_drift_REALTIME_DW.Speedfilter3_states[2L]) /
    robust_drift_REALTIME_P.Speedfilter3_DenCoef[0];

  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* Outputs for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  robust__UpCounterwithupperbound(robust_drift_REALTIME_B.SFunction_o2_i,
    &robust_drift_REALTIME_B.Saturation,
    &robust_drift_REALTIME_DW.UpCounterwithupperbound1,
    &robust_drift_REALTIME_P.UpCounterwithupperbound1,
    &robust_drift_REALTIME_PrevZCX.UpCounterwithupperbound1,
    robust_drift_REALTIME_P.UpCounterwithupperbound1_C0,
    robust_drift_REALTIME_P.UpCounterwithupperbound1_CMAX);

  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* End of Outputs for SubSystem: '<Root>/Up-Counter (with upper bound)1' */

  /* Outputs for Enabled SubSystem: '<Root>/SS controller robust2' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* Logic: '<Root>/Logical Operator9' */
  robust_drift_REALTIME_DW.SScontrollerrobust2_MODE =
    ((robust_drift_REALTIME_B.Saturation_o != 0.0) ||
     (robust_drift_REALTIME_B.Saturation != 0.0));
  if (robust_drift_REALTIME_DW.SScontrollerrobust2_MODE) {
    /* Gain: '<S25>/deg2rad' */
    deg2rad = robust_drift_REALTIME_P.deg2rad *
      robust_drift_REALTIME_B.Constant_j;

    /* Gain: '<S25>/deg2rad1' incorporates:
     *  Gain: '<S25>/deg2rad2'
     */
    gamma *= robust_drift_REALTIME_P.deg2rad;

    /* Gain: '<S25>/V2duty' incorporates:
     *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
     *  DiscreteTransferFcn: '<S11>/Speed filter 1'
     *  DiscreteTransferFcn: '<S11>/Speed filter 3'
     *  Gain: '<S25>/Input feedforward'
     *  Gain: '<S25>/State feedback'
     *  Gain: '<S25>/State feedforward	'
     *  Gain: '<S25>/deg2rad1'
     *  Gain: '<S25>/integral gain (???)'
     *  Sum: '<S25>/Sum'
     *  Sum: '<S25>/Sum2'
     */
    robust_drift_REALTIME_B.V2duty = (((((deg2rad * robust_drift_REALTIME_P.N_x
      [2] - (((robust_drift_REALTIME_P.Speedfilter1_NumCoef[0] *
               robust_drift_REALTIME_DW.Speedfilter1_tmp +
               robust_drift_REALTIME_P.Speedfilter1_NumCoef[1L] *
               robust_drift_REALTIME_DW.Speedfilter1_states[0L]) +
              robust_drift_REALTIME_P.Speedfilter1_NumCoef[2L] *
              robust_drift_REALTIME_DW.Speedfilter1_states[1L]) +
             robust_drift_REALTIME_P.Speedfilter1_NumCoef[3L] *
             robust_drift_REALTIME_DW.Speedfilter1_states[2L]) *
      robust_drift_REALTIME_P.deg2rad) *
      robust_drift_REALTIME_P.Statefeedback_Gain[2] + ((deg2rad *
      robust_drift_REALTIME_P.N_x[0] - gamma) *
      robust_drift_REALTIME_P.Statefeedback_Gain[0] + (deg2rad *
      robust_drift_REALTIME_P.N_x[1] - robust_drift_REALTIME_P.deg2rad * rad2deg)
      * robust_drift_REALTIME_P.Statefeedback_Gain[1])) + (deg2rad *
      robust_drift_REALTIME_P.N_x[3] -
      (((robust_drift_REALTIME_P.Speedfilter3_NumCoef[0] *
         robust_drift_REALTIME_DW.Speedfilter3_tmp +
         robust_drift_REALTIME_P.Speedfilter3_NumCoef[1L] *
         robust_drift_REALTIME_DW.Speedfilter3_states[0L]) +
        robust_drift_REALTIME_P.Speedfilter3_NumCoef[2L] *
        robust_drift_REALTIME_DW.Speedfilter3_states[1L]) +
       robust_drift_REALTIME_P.Speedfilter3_NumCoef[3L] *
       robust_drift_REALTIME_DW.Speedfilter3_states[2L]) *
      robust_drift_REALTIME_P.deg2rad) *
      robust_drift_REALTIME_P.Statefeedback_Gain[3]) +
      robust_drift_REALTIME_P.N_u * deg2rad) + robust_drift_REALTIME_P.Ki *
      robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE_k) *
      robust_drift_REALTIME_P.drv.V2duty;

    /* Sum: '<S25>/Sum1' */
    robust_drift_REALTIME_B.Sum1 = deg2rad - gamma;

    /* Step: '<S24>/Step' */
    if (robust_drift_REALTIME_M->Timing.t[0] < robust_drift_REALTIME_P.Step_Time)
    {
      rad2deg = robust_drift_REALTIME_P.Step_Y0;
    } else {
      rad2deg = robust_drift_REALTIME_P.Step_YFinal;
    }

    /* End of Step: '<S24>/Step' */

    /* Sum: '<S24>/Sum1' incorporates:
     *  Gain: '<S24>/deg2rad3'
     *  MATLAB Function: '<S27>/MATLAB Function1'
     */
    rtb_Sum = rad2deg - (rtb_Sum - rtb_Sum1_o) * 0.034 / 0.2 *
      robust_drift_REALTIME_P.deg2rad;

    /* Gain: '<S24>/V2duty1' incorporates:
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
     *  Gain: '<S24>/Proportional gain'
     *  Sum: '<S24>/Sum3'
     */
    robust_drift_REALTIME_B.V2duty1 =
      (robust_drift_REALTIME_P.Proportionalgain_Gain * rtb_Sum +
       robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE_o) *
      robust_drift_REALTIME_P.drv.V2duty;

    /* Gain: '<S24>/Integral gain' */
    robust_drift_REALTIME_B.Integralgain =
      robust_drift_REALTIME_P.Integralgain_Gain * rtb_Sum;
  }

  /* End of Outputs for SubSystem: '<Root>/SS controller robust2' */

  /* Outputs for Enabled SubSystem: '<Root>/Monostable1' */
  /* Outputs for Enabled SubSystem: '<Root>/Monostable1' */
  robust_drift_REALTIM_Monostable(robust_drift_REALTIME_B.Saturation,
    &robust_drift_REALTIME_B.Compare, &robust_drift_REALTIME_DW.Monostable1,
    &robust_drift_REALTIME_P.Monostable1, robust_drift_REALTIME_P.Monostable1_Tp);

  /* End of Outputs for SubSystem: '<Root>/Monostable1' */
  /* End of Outputs for SubSystem: '<Root>/Monostable1' */

  /* Outputs for Enabled SubSystem: '<Root>/Reference generator1' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Logic: '<Root>/Logical Operator7' incorporates:
   *  Constant: '<S8>/Constant'
   *  Logic: '<Root>/Logical Operator8'
   */
  if ((robust_drift_REALTIME_B.Saturation != 0.0) &&
      (!robust_drift_REALTIME_B.Compare)) {
    robust_drift_REALTIME_B.Constant = 5.0 / robust_drift_REALTIME_P.drv.duty2V;
  }

  /* End of Logic: '<Root>/Logical Operator7' */
  /* End of Outputs for SubSystem: '<Root>/Reference generator1' */

  /* Sum: '<Root>/Sum' */
  rtb_Sum = robust_drift_REALTIME_B.V2duty - robust_drift_REALTIME_B.Constant;

  /* DataTypeConversion: '<S23>/Data Type Conversion' incorporates:
   *  Sum: '<S14>/Plus'
   */
  rad2deg = floor(rtb_Sum + robust_drift_REALTIME_B.V2duty1);
  if (rtIsNaN(rad2deg) || rtIsInf(rad2deg)) {
    rad2deg = 0.0;
  } else {
    rad2deg = fmod(rad2deg, 65536.0);
  }

  /* DataTypeConversion: '<S23>/Data Type Conversion' */
  robust_drift_REALTIME_B.DataTypeConversion = rad2deg < 0.0 ? -(int16_T)
    (uint16_T)-rad2deg : (int16_T)(uint16_T)rad2deg;

  /* DataTypeConversion: '<S23>/Data Type Conversion1' incorporates:
   *  Gain: '<S22>/Gain'
   *  Sum: '<S14>/Plus1'
   */
  rad2deg = floor((rtb_Sum - robust_drift_REALTIME_B.V2duty1) *
                  robust_drift_REALTIME_P.Gain_Gain);
  if (rtIsNaN(rad2deg) || rtIsInf(rad2deg)) {
    rad2deg = 0.0;
  } else {
    rad2deg = fmod(rad2deg, 65536.0);
  }

  /* DataTypeConversion: '<S23>/Data Type Conversion1' */
  robust_drift_REALTIME_B.DataTypeConversion1 = rad2deg < 0.0 ? -(int16_T)
    (uint16_T)-rad2deg : (int16_T)(uint16_T)rad2deg;

  /* S-Function (sfun_BalRobTbx_Motors): '<S23>/S-Function' */

  /* S-Function Block: <S23>/S-Function */
  sfun_BalRobTbx_Motors_WrappedOutput
    (&robust_drift_REALTIME_B.DataTypeConversion,
     &robust_drift_REALTIME_B.DataTypeConversion1);

  /* S-Function (sfun_BalRobTbx_SerialPacketSend): '<S10>/S-Function' */
  /* S-Function Block: <S10>/S-Function */

  /*  Pack input signals to payload buffer  */
  {
    uint8_T *pAux = (uint8_T *)robust_drift_REALTIME_DW.SFunction_DWORK1[0];

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &robust_drift_REALTIME_B.TmpSignalConversionAtSFunctio_p[0], 2);
    pAux += 2;

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &robust_drift_REALTIME_B.TmpSignalConversionAtSFunctio_b[0], 8);
    pAux += 8;

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &robust_drift_REALTIME_B.TmpSignalConversionAtSFunctionI[0], 8);
    pAux += 8;

    /*  copy input signals to payload buffer  */
    memcpy(pAux, &robust_drift_REALTIME_B.DataTypeConversion2, 4);
  }

  /*  Perform COBS encoding  */
  cobsEncode(robust_drift_REALTIME_DW.SFunction_DWORK1[0], 22U,
             robust_drift_REALTIME_DW.SFunction_DWORK1[1]);

  /*  Add null terminator  */
  ((uint8_T *)robust_drift_REALTIME_DW.SFunction_DWORK1[1])[23U] = 0x00;

  /*  Send packet  */
  sfun_BalRobTbx_SerialPacketSend_WrappedOutput(2, (uint8_T*)
    robust_drift_REALTIME_DW.SFunction_DWORK1[1], 24U, 1, 65U, 66U, (boolean_T *)
    &robust_drift_REALTIME_DW.SFunction_DWORK2);

  /* Gain: '<S26>/Gain' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  robust_drift_REALTIME_B.Gain = robust_drift_REALTIME_P.deg2rad *
    robust_drift_REALTIME_B.DataTypeConversion2;

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE +=
    robust_drift_REALTIME_P.DiscreteTimeIntegrator_gainva_p *
    robust_drift_REALTIME_B.Gain;

  /* Update for DiscreteTransferFcn: '<S26>/LPF' */
  robust_drift_REALTIME_DW.LPF_states = robust_drift_REALTIME_DW.LPF_tmp;

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_states[2L] =
    robust_drift_REALTIME_DW.Speedfilter1_states[1L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_states[2L] =
    robust_drift_REALTIME_DW.Speedfilter3_states[1L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_states[1L] =
    robust_drift_REALTIME_DW.Speedfilter1_states[0L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_states[1L] =
    robust_drift_REALTIME_DW.Speedfilter3_states[0L];

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_states[0L] =
    robust_drift_REALTIME_DW.Speedfilter1_tmp;

  /* Update for DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_states[0L] =
    robust_drift_REALTIME_DW.Speedfilter3_tmp;

  /* Update for Enabled SubSystem: '<Root>/SS controller robust2' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (robust_drift_REALTIME_DW.SScontrollerrobust2_MODE) {
    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE_k +=
      robust_drift_REALTIME_P.DiscreteTimeIntegrator_gainval *
      robust_drift_REALTIME_B.Sum1;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE_o +=
      robust_drift_REALTIME_P.DiscreteTimeIntegrator_gainva_e *
      robust_drift_REALTIME_B.Integralgain;
  }

  /* End of Update for SubSystem: '<Root>/SS controller robust2' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  robust_drift_REALTIME_M->Timing.t[0] =
    ((time_T)(++robust_drift_REALTIME_M->Timing.clockTick0)) *
    robust_drift_REALTIME_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    robust_drift_REALTIME_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void robust_drift_REALTIME_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&robust_drift_REALTIME_M->solverInfo,
                          &robust_drift_REALTIME_M->Timing.simTimeStep);
    rtsiSetTPtr(&robust_drift_REALTIME_M->solverInfo, &rtmGetTPtr
                (robust_drift_REALTIME_M));
    rtsiSetStepSizePtr(&robust_drift_REALTIME_M->solverInfo,
                       &robust_drift_REALTIME_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&robust_drift_REALTIME_M->solverInfo,
                          (&rtmGetErrorStatus(robust_drift_REALTIME_M)));
    rtsiSetRTModelPtr(&robust_drift_REALTIME_M->solverInfo,
                      robust_drift_REALTIME_M);
  }

  rtsiSetSimTimeStep(&robust_drift_REALTIME_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&robust_drift_REALTIME_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(robust_drift_REALTIME_M, &robust_drift_REALTIME_M->Timing.tArray[0]);
  robust_drift_REALTIME_M->Timing.stepSize0 = 0.01;

  /* Start for S-Function (sfun_BalRobTbx_Pushbuttons): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function */
  sfun_BalRobTbx_Pushbuttons_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_Encoders): '<S15>/S-Function' */

  /* S-Function Block: <S15>/S-Function */
  sfun_BalRobTbx_Encoders_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_MPU6050): '<S17>/S-Function' */

  /* S-Function Block: <S17>/S-Function */
  sfun_BalRobTbx_MPU6050_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_Motors): '<S23>/S-Function' */

  /* S-Function Block: <S23>/S-Function */
  sfun_BalRobTbx_Motors_WrappedStart();

  /* Start for S-Function (sfun_BalRobTbx_SerialPacketSend): '<S10>/S-Function' */

  /* S-Function Block: <S10>/S-Function */

  /*  Allocate payload buffer  */
  robust_drift_REALTIME_DW.SFunction_DWORK1[0] = calloc(22U, sizeof(uint8_T));

  /*  Allocate packet buffer  */
  robust_drift_REALTIME_DW.SFunction_DWORK1[1] = calloc(24U, sizeof(uint8_T));

  /*  Set Tx Enable flag to false  */
  robust_drift_REALTIME_DW.SFunction_DWORK2 = false;

  /*  Invoke Start wrapped function  */
  sfun_BalRobTbx_SerialPacketSend_WrappedStart(2, 38400);
  robust_drift_REALTIME_PrevZCX.UpCounterwithupperbound1.UpCounterwithupperbound_Trig_ZC
    = POS_ZCSIG;
  robust_drift_REALTIME_PrevZCX.UpCounterwithupperbound.UpCounterwithupperbound_Trig_ZC
    = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE =
    robust_drift_REALTIME_P.DiscreteTimeIntegrator_IC_h;

  /* InitializeConditions for DiscreteTransferFcn: '<S26>/LPF' */
  robust_drift_REALTIME_DW.LPF_states =
    robust_drift_REALTIME_P.LPF_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_states[0] =
    robust_drift_REALTIME_P.Speedfilter1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_states[0] =
    robust_drift_REALTIME_P.Speedfilter3_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_states[1] =
    robust_drift_REALTIME_P.Speedfilter1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_states[1] =
    robust_drift_REALTIME_P.Speedfilter3_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 1' */
  robust_drift_REALTIME_DW.Speedfilter1_states[2] =
    robust_drift_REALTIME_P.Speedfilter1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S11>/Speed filter 3' */
  robust_drift_REALTIME_DW.Speedfilter3_states[2] =
    robust_drift_REALTIME_P.Speedfilter3_InitialStates;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)' */
  ro_UpCounterwithupperbound_Init(&robust_drift_REALTIME_B.Saturation_o,
    &robust_drift_REALTIME_DW.UpCounterwithupperbound,
    robust_drift_REALTIME_P.UpCounterwithupperbound_C0);

  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)' */
  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Monostable' */
  robust_drift_RE_Monostable_Init(&robust_drift_REALTIME_B.Compare_n,
    &robust_drift_REALTIME_DW.Monostable, &robust_drift_REALTIME_P.Monostable);

  /* End of SystemInitialize for SubSystem: '<Root>/Monostable' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Reference generator' */
  /* Start for Constant: '<S7>/Constant' */
  robust_drift_REALTIME_B.Constant_j = 0.1 / robust_drift_REALTIME_P.wheel.r *
    robust_drift_REALTIME_P.rad2deg;

  /* End of SystemInitialize for SubSystem: '<Root>/Reference generator' */

  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* SystemInitialize for Triggered SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  ro_UpCounterwithupperbound_Init(&robust_drift_REALTIME_B.Saturation,
    &robust_drift_REALTIME_DW.UpCounterwithupperbound1,
    robust_drift_REALTIME_P.UpCounterwithupperbound1_C0);

  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Up-Counter (with upper bound)1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/SS controller robust2' */
  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE_k =
    robust_drift_REALTIME_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
  robust_drift_REALTIME_DW.DiscreteTimeIntegrator_DSTATE_o =
    robust_drift_REALTIME_P.DiscreteTimeIntegrator_IC_d;

  /* SystemInitialize for Gain: '<S25>/V2duty' incorporates:
   *  Outport: '<S9>/u [duty]'
   */
  robust_drift_REALTIME_B.V2duty = robust_drift_REALTIME_P.uduty_Y0;

  /* SystemInitialize for Gain: '<S24>/V2duty1' incorporates:
   *  Outport: '<S9>/u [duty]1'
   */
  robust_drift_REALTIME_B.V2duty1 = robust_drift_REALTIME_P.uduty1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/SS controller robust2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Monostable1' */
  robust_drift_RE_Monostable_Init(&robust_drift_REALTIME_B.Compare,
    &robust_drift_REALTIME_DW.Monostable1, &robust_drift_REALTIME_P.Monostable1);

  /* End of SystemInitialize for SubSystem: '<Root>/Monostable1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Reference generator1' */
  /* SystemInitialize for Outport: '<S8>/Out[duty]' incorporates:
   *  Constant: '<S8>/Constant'
   */
  robust_drift_REALTIME_B.Constant = robust_drift_REALTIME_P.Outduty_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Reference generator1' */
}

/* Model terminate function */
void robust_drift_REALTIME_terminate(void)
{
  /* Terminate for S-Function (sfun_BalRobTbx_Pushbuttons): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function */
  sfun_BalRobTbx_Pushbuttons_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_Encoders): '<S15>/S-Function' */

  /* S-Function Block: <S15>/S-Function */
  sfun_BalRobTbx_Encoders_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_MPU6050): '<S17>/S-Function' */

  /* S-Function Block: <S17>/S-Function */
  sfun_BalRobTbx_MPU6050_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_Motors): '<S23>/S-Function' */

  /* S-Function Block: <S23>/S-Function */
  sfun_BalRobTbx_Motors_WrappedTerminate();

  /* Terminate for S-Function (sfun_BalRobTbx_SerialPacketSend): '<S10>/S-Function' */

  /* S-Function Block: <S10>/S-Function */

  /*  Release heap space  */
  free(robust_drift_REALTIME_DW.SFunction_DWORK1[0]);
  free(robust_drift_REALTIME_DW.SFunction_DWORK1[1]);

  /*  Set Tx Enable flag to false  */
  robust_drift_REALTIME_DW.SFunction_DWORK2 = false;

  /*  Invoke Terminate wrapped function  */
  sfun_BalRobTbx_SerialPacketSend_WrappedTerminate(2);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
