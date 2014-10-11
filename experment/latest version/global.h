/* Global variable and function definitions */

# ifndef _GLOBAL_H
# define _GLOBAL_H

/* Global Constants */
# define INF 1.0e99
# define EPS 1.0e-14
# define E  2.7182818284590452353602874713526625
# define PI 3.1415926535897932384626433832795029

/* Uncomment one of the lines corresponding to a particular function */
/* Function identifier */
/* # define f1 */
/* # define f2 */
/* # define f3 */
/* # define f4 */
/* # define f5 */
/* # define f6 */
/* # define f7 */
/* # define f8 */
/* # define f9 */
/* # define f10 */
/* # define f11 */
/* # define f12 */
/* # define f13 */
/* # define f14 */
/* # define f15 */
/* # define f16 */
/* # define f17 */
/* # define f18 */
/* # define f19 */
/* # define f20 */
/* # define f21 */
/* # define f22 */
/* # define f23 */
/* # define f24 */
/* # define f25 */

#ifdef __cplusplus
extern "C" {
#endif


/* Auxillary function declarations */
long double maximum (long double, long double);
long double minimum (long double, long double);
long double modulus (long double*, int);
long double dot (long double*, long double*, int);
long double mean (long double*, int);

/* Basic funcion declarations */
long double calc_ackley (long double*);
long double calc_rastrigin (long double*);
long double calc_weierstrass (long double*);
long double calc_griewank (long double*);
long double calc_sphere (long double*);
long double calc_schwefel (long double*);
long double calc_rosenbrock (long double *x);
long double nc_schaffer (long double, long double);
long double nc_rastrigin (long double*);

/* Utility function declarations */
void allocate_memory();
//void initialize();
void initialize_f1();
void initialize_f2();
void initialize_f3();
void initialize_f4();
void initialize_f5();
void initialize_f6();
void initialize_f7();
void initialize_f8();
void initialize_f9();
void initialize_f10();
void initialize_f11();
void initialize_f12();
void initialize_f13();
void initialize_f14();
void initialize_f15();
void initialize_f16();
void initialize_f17();
void initialize_f18();
void initialize_f19();
void initialize_f20();
void initialize_f21();
void initialize_f22();
void initialize_f23();
void initialize_f24();
void transform (long double*, int);
void transform_norm (int);
void calc_weight (long double*);
void free_memory();

/* Benchmark function declaration */
//long double calc_benchmark_func (long double*);
long double calc_benchmark_f1 (long double*);
long double calc_benchmark_f2 (long double*);
long double calc_benchmark_f3 (long double*);
long double calc_benchmark_f4 (long double*);
long double calc_benchmark_f5 (long double*);
long double calc_benchmark_f6 (long double*);
long double calc_benchmark_f7 (long double*);
long double calc_benchmark_f8 (long double*);
long double calc_benchmark_f9 (long double*);
long double calc_benchmark_f10 (long double*);
long double calc_benchmark_f11 (long double*);
long double calc_benchmark_f12 (long double*);
long double calc_benchmark_f13 (long double*);
long double calc_benchmark_f14 (long double*);
long double calc_benchmark_f15 (long double*);
long double calc_benchmark_f16 (long double*);
long double calc_benchmark_f17 (long double*);
long double calc_benchmark_f18 (long double*);
long double calc_benchmark_f19 (long double*);
long double calc_benchmark_f20 (long double*);
long double calc_benchmark_f21 (long double*);
long double calc_benchmark_f22 (long double*);
long double calc_benchmark_f23 (long double*);
long double calc_benchmark_f24 (long double*);
//void calc_benchmark_norm();
void calc_benchmark_norm_f15();
void calc_benchmark_norm_f16();
void calc_benchmark_norm_f17();
void calc_benchmark_norm_f18();
void calc_benchmark_norm_f19();
void calc_benchmark_norm_f20();
void calc_benchmark_norm_f21();
void calc_benchmark_norm_f22();
void calc_benchmark_norm_f23();
void calc_benchmark_norm_f24();

extern long double (*calc_benchmark_func)(long double*);

/* set which function to be used and its dimension */
void set_func(int func_number, int dimension);
void unset_func();

#ifdef __cplusplus
}
#endif

# endif
