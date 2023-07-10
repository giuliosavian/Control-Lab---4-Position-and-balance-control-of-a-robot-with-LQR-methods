/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: robust_drift_REALTIME_private.h
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

#ifndef RTW_HEADER_robust_drift_REALTIME_private_h_
#define RTW_HEADER_robust_drift_REALTIME_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "robust_drift_REALTIME.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void sfun_BalRobTbx_Pushbuttons_WrappedStart(void);
extern void sfun_BalRobTbx_Pushbuttons_WrappedOutput(uint8_T *, uint8_T *);
extern void sfun_BalRobTbx_Pushbuttons_WrappedTerminate(void);
extern void sfun_BalRobTbx_Encoders_WrappedStart(void);
extern void sfun_BalRobTbx_Encoders_WrappedOutput(int32_T *, int32_T *);
extern void sfun_BalRobTbx_Encoders_WrappedTerminate(void);
extern void sfun_BalRobTbx_MPU6050_WrappedStart(void);
extern void sfun_BalRobTbx_MPU6050_WrappedOutput(int16_T *, int16_T *);
extern void sfun_BalRobTbx_MPU6050_WrappedTerminate(void);
extern void sfun_BalRobTbx_Motors_WrappedStart(void);
extern void sfun_BalRobTbx_Motors_WrappedOutput(int16_T *, int16_T *);
extern void sfun_BalRobTbx_Motors_WrappedTerminate(void);
extern void sfun_BalRobTbx_SerialPacketSend_WrappedStart(int8_T serialPort,
  uint32_T baudRate);
extern void sfun_BalRobTbx_SerialPacketSend_WrappedOutput(int8_T serialPort,
  uint8_T *pPacketBuffer, uint32_T packetSize, boolean_T waitHostTxCmd, uint8_T
  txStartCmd, uint8_T txStopCmd, boolean_T *pTxEnable);
extern void sfun_BalRobTbx_SerialPacketSend_WrappedTerminate(int8_T serialPort);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift);
extern void robust_drift_RE_Monostable_Init(boolean_T *rty_Out,
  DW_Monostable_robust_drift_RE_T *localDW, P_Monostable_robust_drift_REA_T
  *localP);
extern void robust_drift_R_Monostable_Reset(DW_Monostable_robust_drift_RE_T
  *localDW, P_Monostable_robust_drift_REA_T *localP);
extern void robust_drift_Monostable_Disable(DW_Monostable_robust_drift_RE_T
  *localDW);
extern void robust_drift_REALTIM_Monostable(real_T rtu_Enable, boolean_T
  *rty_Out, DW_Monostable_robust_drift_RE_T *localDW,
  P_Monostable_robust_drift_REA_T *localP, real_T rtp_Tp);
extern void ro_UpCounterwithupperbound_Init(real_T *rty_Out,
  DW_UpCounterwithupperbound_ro_T *localDW, real_T rtp_C0);
extern void robust__UpCounterwithupperbound(uint8_T rtu_Trigger, real_T *rty_Out,
  DW_UpCounterwithupperbound_ro_T *localDW, P_UpCounterwithupperbound_rob_T
  *localP, ZCE_UpCounterwithupperbound_r_T *localZCE, real_T rtp_C0, real_T
  rtp_CMAX);

#endif                         /* RTW_HEADER_robust_drift_REALTIME_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
