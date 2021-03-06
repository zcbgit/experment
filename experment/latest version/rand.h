/* Declaration for random number related variables and routines */

# ifndef _RAND_H
# define _RAND_H

#ifdef __cplusplus
extern "C" {
#endif

/* # include "global.h" */

/* Variable declarations for the random number generator */
extern long double seed;
extern long double oldrand[55];
extern int jrand;
extern int rndcalcflag;
extern long double rndx1, rndx2;

/* Function declarations for the random number generator */
void randomize();
void warmup_random (long double seed);
void advance_random ();
long double randomperc();
int rnd (int low, int high);
long double rndreal (long double low, long double high);
void initrandomnormaldeviate();
long double noise (long double mu, long double sigma);
long double randomnormaldeviate();

#ifdef __cplusplus
}
#endif

# endif
