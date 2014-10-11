#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
//#include "rand.h"

 /* boundaries of 25 functions. lower bound: boundaries[*][0] upper bound: boundaries[*][1] */
double boundaries[26][2] = {
	{0, 0}, {-100, 100}, {-100, 100}, {-100, 100}, {-100, 100}, {-100, 100}, {-100, 100}, {0, 600}, {-32, 32}, {-5, 5}, /* 1-9 */
	{-5, 5}, {-0.5, 0.5}, {-PI, PI}, {-5, 5}, {-100, 100}, {-5, 5}, {-5, 5}, {-5, 5}, {-5, 5}, {-5, 5}, /* 10-19 */
	{-5, 5}, {-5, 5}, {-5, 5}, {-5, 5}, {-5, 5}, {2, 5} /* 20-25 */
};   

/* min values of 25 functions */
double fmin[26] = {
	0, -450, -450, -450, -450, -310, 390, -180, -140, -330,  /* 1-9 */
	-330, 90, -460, -130, -300, 120, 120, 120, 10, 10, /* 10-19 */
	10, 360, 360, 360, 260, 260 /* 20-25 */
};	

int main()
{
	long double x[30];
	int i;

	srand((unsigned int)time(0));

	/* set_func(function_number, dimension), function_number: 1-25 */
	set_func(25, 30);

	for(i=0; i<30; i++)
		x[i] = 0;

	printf("\nfmin: %e\n", calc_benchmark_func(x));

	/* use unset_func() to free memory */
	unset_func();

	printf("\nDone!\n");
	getchar();

	return 0;
}