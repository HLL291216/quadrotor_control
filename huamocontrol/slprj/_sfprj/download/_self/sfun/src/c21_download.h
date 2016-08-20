#ifndef __c21_download_h__
#define __c21_download_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc21_downloadInstanceStruct
#define typedef_SFc21_downloadInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_download;
} SFc21_downloadInstanceStruct;

#endif                                 /*typedef_SFc21_downloadInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_download_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_download_get_check_sum(mxArray *plhs[]);
extern void c21_download_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
