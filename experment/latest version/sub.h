/* Test problem specific variable declarations */

# ifndef _SUB_H
# define _SUB_H

#ifdef __cplusplus
extern "C" {
#endif

/* Global variables that you are required to initialize */
extern int nreal;                    /* number of real variables */
extern int nfunc;                    /* number of basic functions */
extern long double bound;            /* required for plotting the function profiles for nreal=2 */
extern int density;                  /* density of grid points for plotting for nreal=2 */

/* Global variables being used in evaluation of various functions */
/* These are initalized in file def2.c */
extern long double C;
extern long double global_bias;
extern long double *trans_x;
extern long double *basic_f;
extern long double *temp_x1;
extern long double *temp_x2;
extern long double *temp_x3;
extern long double *temp_x4;
extern long double *weight;
extern long double *sigma;
extern long double *lambda;
extern long double *bias;
extern long double *norm_x;
extern long double *norm_f;
extern long double **o;
extern long double **g;
extern long double ***l;

/* # ifdef f5 */
extern long double **A5;
extern long double *B5;
/* # endif */

/* # ifdef f12 */
extern long double **A;
extern long double **B;
extern long double *alpha;
/* # endif */

#ifdef __cplusplus
}
#endif

# endif