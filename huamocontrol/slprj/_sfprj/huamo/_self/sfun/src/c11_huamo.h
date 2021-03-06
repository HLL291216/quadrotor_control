#ifndef __c11_huamo_h__
#define __c11_huamo_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_huamoInstanceStruct
#define typedef_SFc11_huamoInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_huamo;
  real_T c11_count;
  boolean_T c11_count_not_empty;
  real_T c11_x1_1;
  boolean_T c11_x1_1_not_empty;
  real_T c11_x2_1;
  boolean_T c11_x2_1_not_empty;
} SFc11_huamoInstanceStruct;

#endif                                 /*typedef_SFc11_huamoInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_huamo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_huamo_get_check_sum(mxArray *plhs[]);
extern void c11_huamo_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
