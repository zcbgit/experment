#ifdef __cplusplus
extern "C" {
#endif

#include "sub.h"

/* Global variables that you are required to initialize */
int nreal;                    /* number of real variables */
int nfunc;                    /* number of basic functions */
long double bound;            /* required for plotting the function profiles for nreal=2 */
int density;                  /* density of grid points for plotting for nreal=2 */

/* Global variables being used in evaluation of various functions */
/* These are initalized in file def2.c */
long double C;
long double global_bias;
long double *trans_x;
long double *basic_f;
long double *temp_x1;
long double *temp_x2;
long double *temp_x3;
long double *temp_x4;
long double *weight;
long double *sigma;
long double *lambda;
long double *bias;
long double *norm_x;
long double *norm_f;
long double **o;
long double **g;
long double ***l;

/* # ifdef f5 */
long double **A5;
long double *B5;
/* # endif */

/* # ifdef f12 */
long double **A;
long double **B;
long double *alpha;
/* # endif */

#ifdef __cplusplus
}
#endif