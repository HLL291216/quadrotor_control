/* Include files */

#include "huamo_sfun.h"
#include "huamo_sfun_debug_macros.h"
#include "c1_huamo.h"
#include "c2_huamo.h"
#include "c3_huamo.h"
#include "c4_huamo.h"
#include "c5_huamo.h"
#include "c6_huamo.h"
#include "c7_huamo.h"
#include "c8_huamo.h"
#include "c9_huamo.h"
#include "c10_huamo.h"
#include "c11_huamo.h"
#include "c24_huamo.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _huamoMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void huamo_initializer(void)
{
}

void huamo_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_huamo_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_huamo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_huamo_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3716432111U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(32705632U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3458484925U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1052440428U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3032799367U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3563626433U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4292155459U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3914054298U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_huamo_get_check_sum(mxArray *plhs[]);
          sf_c1_huamo_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_huamo_get_check_sum(mxArray *plhs[]);
          sf_c2_huamo_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_huamo_get_check_sum(mxArray *plhs[]);
          sf_c3_huamo_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_huamo_get_check_sum(mxArray *plhs[]);
          sf_c4_huamo_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_huamo_get_check_sum(mxArray *plhs[]);
          sf_c5_huamo_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_huamo_get_check_sum(mxArray *plhs[]);
          sf_c6_huamo_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_huamo_get_check_sum(mxArray *plhs[]);
          sf_c7_huamo_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_huamo_get_check_sum(mxArray *plhs[]);
          sf_c8_huamo_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_huamo_get_check_sum(mxArray *plhs[]);
          sf_c9_huamo_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_huamo_get_check_sum(mxArray *plhs[]);
          sf_c10_huamo_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_huamo_get_check_sum(mxArray *plhs[]);
          sf_c11_huamo_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_huamo_get_check_sum(mxArray *plhs[]);
          sf_c24_huamo_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(814460797U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(400623215U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1072597456U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1176453921U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(191083065U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1231820020U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3625914567U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1372462222U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_huamo_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "MKgyrIRcWIjpgJYdmMjFFE") == 0) {
          extern mxArray *sf_c1_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c1_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "MKgyrIRcWIjpgJYdmMjFFE") == 0) {
          extern mxArray *sf_c2_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c2_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "HfarRlBqnwn5Iwrz9bbiBF") == 0) {
          extern mxArray *sf_c3_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c3_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "6XIB52WzZ07HehAxfqoYzD") == 0) {
          extern mxArray *sf_c4_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c4_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "h6cLK3nlxsPPdvVX5FGGJG") == 0) {
          extern mxArray *sf_c5_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c5_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "WRxhKy2k596yFidD4ghfHD") == 0) {
          extern mxArray *sf_c6_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c6_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "0LhtBvTqnOKfrxgaWgdc1") == 0) {
          extern mxArray *sf_c7_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c7_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "5DGbA23OI3RFF8bW4Q7ak") == 0) {
          extern mxArray *sf_c8_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c8_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "9FViB67sIFUt1BHbkUyIsF") == 0) {
          extern mxArray *sf_c9_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c9_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "KOh2EPtcRoIrRSM7agySV") == 0) {
          extern mxArray *sf_c10_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c10_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "8rdrVox8Ia425SDWZjaad") == 0) {
          extern mxArray *sf_c11_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c11_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "JcO1oBNsEuk5TmU0h7YgNC") == 0) {
          extern mxArray *sf_c24_huamo_get_autoinheritance_info(void);
          plhs[0] = sf_c24_huamo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_huamo_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray *sf_c24_huamo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_huamo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_huamo_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "qG2yirEkZjm3TCLH05ZLU") == 0) {
          extern mxArray *sf_c1_huamo_third_party_uses_info(void);
          plhs[0] = sf_c1_huamo_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "qG2yirEkZjm3TCLH05ZLU") == 0) {
          extern mxArray *sf_c2_huamo_third_party_uses_info(void);
          plhs[0] = sf_c2_huamo_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "RzGKkSEFvysjJYXhxSTE9D") == 0) {
          extern mxArray *sf_c3_huamo_third_party_uses_info(void);
          plhs[0] = sf_c3_huamo_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "F7mEkMIvhZKKbDFGD73kJE") == 0) {
          extern mxArray *sf_c4_huamo_third_party_uses_info(void);
          plhs[0] = sf_c4_huamo_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sOAGdxzXmd4T2PZAWgNfPD") == 0) {
          extern mxArray *sf_c5_huamo_third_party_uses_info(void);
          plhs[0] = sf_c5_huamo_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "VMpGMnQAoGeew5uQ0caRzC") == 0) {
          extern mxArray *sf_c6_huamo_third_party_uses_info(void);
          plhs[0] = sf_c6_huamo_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "2KKXtjkr1XvsuGe3HYzcVE") == 0) {
          extern mxArray *sf_c7_huamo_third_party_uses_info(void);
          plhs[0] = sf_c7_huamo_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "92Py9utX0ww77qwzLcg3IH") == 0) {
          extern mxArray *sf_c8_huamo_third_party_uses_info(void);
          plhs[0] = sf_c8_huamo_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "pmkptcXfsuBntuiBSKBvdD") == 0) {
          extern mxArray *sf_c9_huamo_third_party_uses_info(void);
          plhs[0] = sf_c9_huamo_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "1O2Y1vokkVjRFqPdUSO4UG") == 0) {
          extern mxArray *sf_c10_huamo_third_party_uses_info(void);
          plhs[0] = sf_c10_huamo_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bO8yQndtcSgYudlpvj7S1") == 0) {
          extern mxArray *sf_c11_huamo_third_party_uses_info(void);
          plhs[0] = sf_c11_huamo_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "2y9rq7aaaxhTw88Z1LA2UD") == 0) {
          extern mxArray *sf_c24_huamo_third_party_uses_info(void);
          plhs[0] = sf_c24_huamo_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_huamo_updateBuildInfo_args_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "qG2yirEkZjm3TCLH05ZLU") == 0) {
          extern mxArray *sf_c1_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "qG2yirEkZjm3TCLH05ZLU") == 0) {
          extern mxArray *sf_c2_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "RzGKkSEFvysjJYXhxSTE9D") == 0) {
          extern mxArray *sf_c3_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "F7mEkMIvhZKKbDFGD73kJE") == 0) {
          extern mxArray *sf_c4_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sOAGdxzXmd4T2PZAWgNfPD") == 0) {
          extern mxArray *sf_c5_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "VMpGMnQAoGeew5uQ0caRzC") == 0) {
          extern mxArray *sf_c6_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "2KKXtjkr1XvsuGe3HYzcVE") == 0) {
          extern mxArray *sf_c7_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "92Py9utX0ww77qwzLcg3IH") == 0) {
          extern mxArray *sf_c8_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "pmkptcXfsuBntuiBSKBvdD") == 0) {
          extern mxArray *sf_c9_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "1O2Y1vokkVjRFqPdUSO4UG") == 0) {
          extern mxArray *sf_c10_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bO8yQndtcSgYudlpvj7S1") == 0) {
          extern mxArray *sf_c11_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "2y9rq7aaaxhTw88Z1LA2UD") == 0) {
          extern mxArray *sf_c24_huamo_updateBuildInfo_args_info(void);
          plhs[0] = sf_c24_huamo_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void huamo_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _huamoMachineNumber_ = sf_debug_initialize_machine(debugInstance,"huamo",
    "sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_huamoMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_huamoMachineNumber_,0);
}

void huamo_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_huamo_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("huamo", "huamo");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_huamo_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
