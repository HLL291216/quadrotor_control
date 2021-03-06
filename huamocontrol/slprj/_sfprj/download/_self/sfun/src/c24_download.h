#ifndef __c24_download_h__
#define __c24_download_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_downloadInstanceStruct
#define typedef_SFc24_downloadInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_download;
  real_T c24_altitude_basic;
  boolean_T c24_altitude_basic_not_empty;
  real_T c24_count;
  boolean_T c24_count_not_empty;
} SFc24_downloadInstanceStruct;

#endif                                 /*typedef_SFc24_downloadInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_download_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_download_get_check_sum(mxArray *plhs[]);
extern void c24_download_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
