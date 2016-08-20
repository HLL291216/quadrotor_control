/*
 * File: download_private.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model download.
 *
 * Model version                        : 1.105
 * Real-Time Workshop file version      : 8.6 (R2014a) 27-Dec-2013
 * Real-Time Workshop file generated on : Mon Jun 27 17:19:18 2016
 * TLC version                          : 8.6 (Jan 30 2014)
 * C/C++ source code generated on       : Mon Jun 27 17:19:19 2016
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_download_private_h_
#define RTW_HEADER_download_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void download_Angle_hold_Start(DW_Angle_hold_download_T *localDW,
  P_Angle_hold_download_T *localP);
extern void download_Angle_hold(real_T rtu_Enable, real32_T rtu_Guidance_in,
  real32_T rtu_Guidance_in_i, real32_T rtu_Guidance_in_l, const real32_T
  rtu_Signal_back[3], const real32_T rtu_parameter_roll[5], const real32_T
  rtu_Signal_back_l[3], real32_T rtu_Guidance_in_o, const real32_T
  rtu_parameter_yaw[5], const real32_T rtu_alt_back[2], const real32_T
  rtu_parameter_alt[5], B_Angle_hold_download_T *localB,
  DW_Angle_hold_download_T *localDW, P_Angle_hold_download_T *localP);
extern void download_MATLABFunction2(real_T rtu_u, B_MATLABFunction2_download_T *
  localB);

#endif                                 /* RTW_HEADER_download_private_h_ */

/* [EOF] */
