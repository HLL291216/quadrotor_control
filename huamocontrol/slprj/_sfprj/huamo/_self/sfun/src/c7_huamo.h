#ifndef __c7_huamo_h__
#define __c7_huamo_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_huamoInstanceStruct
#define typedef_SFc7_huamoInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_huamo;
  real_T c7_a;
  boolean_T c7_a_not_empty;
  real_T c7_count;
  boolean_T c7_count_not_empty;
} SFc7_huamoInstanceStruct;

#endif                                 /*typedef_SFc7_huamoInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_huamo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_huamo_get_check_sum(mxArray *plhs[]);
extern void c7_huamo_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
