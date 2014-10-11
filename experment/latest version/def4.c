/* Source file for various benchmark functions */
/* Hard-coded for every function. */
/* Some redundancy is present here and there */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# include "global.h"
# include "sub.h"
# include "rand.h"

long double (*calc_benchmark_func)(long double*);

//# ifdef f1
long double calc_benchmark_f1(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_sphere (trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f2
long double calc_benchmark_f2(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_schwefel (trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f3
long double calc_benchmark_f3(long double *x)
{
    int i;
    long double res;
    transform (x, 0);
    basic_f[0] = 0.0;
    for (i=0; i<nreal; i++)
    {
        basic_f[0] += trans_x[i]*trans_x[i]*pow(1.0e6,i/(nreal-1.0));
    }
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f4
long double calc_benchmark_f4(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_schwefel(trans_x)*(1.0 + 0.4*fabs(randomnormaldeviate()));
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f5
long double calc_benchmark_f5(long double *x)
{
    int i, j;
    long double res;
    basic_f[0] = -INF;
    for (i=0; i<nreal; i++)
    {
        res=0.0;
        for (j=0; j<nreal; j++)
        {
            res += A5[i][j]*x[j];
        }
        res = fabs(res-B5[i]);
        if (basic_f[0] < res)
        {
            basic_f[0] = res;
        }
    }
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f6
long double calc_benchmark_f6(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_rosenbrock(trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f7
long double calc_benchmark_f7(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_griewank(trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f8
long double calc_benchmark_f8(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_ackley(trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f9
long double calc_benchmark_f9(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_rastrigin(trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f10
long double calc_benchmark_f10(long double *x)
{
    long double res;
    transform (x, 0);
    basic_f[0] = calc_rastrigin(trans_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f11
long double calc_benchmark_f11(long double *x)
{
    int i;
    long double res;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 0);
    basic_f[0] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f12
long double calc_benchmark_f12(long double *x)
{
    long double res;
    long double sum1, sum2;
    int i, j;
    basic_f[0] = 0.0;
    for (i=0; i<nreal; i++)
    {
        sum1 = 0.0;
        sum2 = 0.0;
        for (j=0; j<nreal; j++)
        {
            sum1 += A[i][j]*sin(alpha[j]) + B[i][j]*cos(alpha[j]);
            sum2 += A[i][j]*sin(x[j]) + B[i][j]*cos(x[j]);
        }
        basic_f[0] += pow((sum1-sum2),2.0);
    }
    res = basic_f[0] + bias[0];
    return (res);
}
//# endif

//# ifdef f13
long double calc_benchmark_f13(long double *x)
{
    int i;
    long double temp;
    long double res;
    transform(x,0);
    res = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        res += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    res += (temp*temp)/4000.0 - cos(temp) + 1.0 + bias[0];
    return (res);
}
//# endif

//# ifdef f14
long double calc_benchmark_f14(long double *x)
{
    int i;
    long double temp1, temp2;
    long double res;
    transform(x,0);
    res = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        res += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    res += 0.5 + (temp1-0.5)/(pow(temp2,2.0)) + bias[0];
    return (res);
}
//# endif

//# ifdef f15
void calc_benchmark_norm_f15()
{
    int i;
    transform_norm (0);    norm_f[0] = calc_rastrigin(trans_x);
    transform_norm (1);    norm_f[1] = calc_rastrigin(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (2);    norm_f[2] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (3);    norm_f[3] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (4);    norm_f[4] = calc_griewank(trans_x);
    transform_norm (5);    norm_f[5] = calc_griewank(trans_x);
    transform_norm (6);    norm_f[6] = calc_ackley(trans_x);
    transform_norm (7);    norm_f[7] = calc_ackley(trans_x);
    transform_norm (8);    norm_f[8] = calc_sphere(trans_x);
    transform_norm (9);    norm_f[9] = calc_sphere(trans_x);
    return;
}

long double calc_benchmark_f15(long double *x)
{
    int i;
    long double res;
    transform (x, 0);    basic_f[0] = calc_rastrigin(trans_x);
    transform (x, 1);    basic_f[1] = calc_rastrigin(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 2);    basic_f[2] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 3);    basic_f[3] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 4);    basic_f[4] = calc_griewank(trans_x);
    transform (x, 5);    basic_f[5] = calc_griewank(trans_x);
    transform (x, 6);    basic_f[6] = calc_ackley(trans_x);
    transform (x, 7);    basic_f[7] = calc_ackley(trans_x);
    transform (x, 8);    basic_f[8] = calc_sphere(trans_x);
    transform (x, 9);    basic_f[9] = calc_sphere(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f16
void calc_benchmark_norm_f16()
{
    int i;
    transform_norm (0);    norm_f[0] = calc_rastrigin(trans_x);
    transform_norm (1);    norm_f[1] = calc_rastrigin(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (2);    norm_f[2] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (3);    norm_f[3] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (4);    norm_f[4] = calc_griewank(trans_x);
    transform_norm (5);    norm_f[5] = calc_griewank(trans_x);
    transform_norm (6);    norm_f[6] = calc_ackley(trans_x);
    transform_norm (7);    norm_f[7] = calc_ackley(trans_x);
    transform_norm (8);    norm_f[8] = calc_sphere(trans_x);
    transform_norm (9);    norm_f[9] = calc_sphere(trans_x);
    return;
}

long double calc_benchmark_f16(long double *x)
{
    int i;
    long double res;
    transform (x, 0);    basic_f[0] = calc_rastrigin(trans_x);
    transform (x, 1);    basic_f[1] = calc_rastrigin(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 2);    basic_f[2] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 3);    basic_f[3] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 4);    basic_f[4] = calc_griewank(trans_x);
    transform (x, 5);    basic_f[5] = calc_griewank(trans_x);
    transform (x, 6);    basic_f[6] = calc_ackley(trans_x);
    transform (x, 7);    basic_f[7] = calc_ackley(trans_x);
    transform (x, 8);    basic_f[8] = calc_sphere(trans_x);
    transform (x, 9);    basic_f[9] = calc_sphere(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f17
void calc_benchmark_norm_f17()
{
    int i;
    transform_norm (0);    norm_f[0] = calc_rastrigin(trans_x);
    transform_norm (1);    norm_f[1] = calc_rastrigin(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (2);    norm_f[2] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (3);    norm_f[3] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (4);    norm_f[4] = calc_griewank(trans_x);
    transform_norm (5);    norm_f[5] = calc_griewank(trans_x);
    transform_norm (6);    norm_f[6] = calc_ackley(trans_x);
    transform_norm (7);    norm_f[7] = calc_ackley(trans_x);
    transform_norm (8);    norm_f[8] = calc_sphere(trans_x);
    transform_norm (9);    norm_f[9] = calc_sphere(trans_x);
    return;
}

long double calc_benchmark_f17(long double *x)
{
    int i;
    long double res;
    transform (x, 0);    basic_f[0] = calc_rastrigin(trans_x);
    transform (x, 1);    basic_f[1] = calc_rastrigin(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 2);    basic_f[2] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 3);    basic_f[3] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 4);    basic_f[4] = calc_griewank(trans_x);
    transform (x, 5);    basic_f[5] = calc_griewank(trans_x);
    transform (x, 6);    basic_f[6] = calc_ackley(trans_x);
    transform (x, 7);    basic_f[7] = calc_ackley(trans_x);
    transform (x, 8);    basic_f[8] = calc_sphere(trans_x);
    transform (x, 9);    basic_f[9] = calc_sphere(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = 0.0;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    res = res*(1.0 + 0.2*fabs(randomnormaldeviate())) + global_bias;
    return (res);
}
//# endif

//# ifdef f18
void calc_benchmark_norm_f18()
{
    int i;
    transform_norm (0);    norm_f[0] = calc_ackley(trans_x);
    transform_norm (1);    norm_f[1] = calc_ackley(trans_x);
    transform_norm (2);    norm_f[2] = calc_rastrigin(trans_x);
    transform_norm (3);    norm_f[3] = calc_rastrigin(trans_x);
    transform_norm (4);    norm_f[4] = calc_sphere(trans_x);
    transform_norm (5);    norm_f[5] = calc_sphere(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (6);    norm_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (7);    norm_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (8);    norm_f[8] = calc_griewank(trans_x);
    transform_norm (9);    norm_f[9] = calc_griewank(trans_x);
    return;
}

long double calc_benchmark_f18(long double *x)
{
    int i;
    long double res;
    transform (x, 0);    basic_f[0] = calc_ackley(trans_x);
    transform (x, 1);    basic_f[1] = calc_ackley(trans_x);
    transform (x, 2);    basic_f[2] = calc_rastrigin(trans_x);
    transform (x, 3);    basic_f[3] = calc_rastrigin(trans_x);
    transform (x, 4);    basic_f[4] = calc_sphere(trans_x);
    transform (x, 5);    basic_f[5] = calc_sphere(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 6);    basic_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 7);    basic_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 8);    basic_f[8] = calc_griewank(trans_x);
    transform (x, 9);    basic_f[9] = calc_griewank(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f19
void calc_benchmark_norm_f19()
{
    int i;
    transform_norm (0);    norm_f[0] = calc_ackley(trans_x);
    transform_norm (1);    norm_f[1] = calc_ackley(trans_x);
    transform_norm (2);    norm_f[2] = calc_rastrigin(trans_x);
    transform_norm (3);    norm_f[3] = calc_rastrigin(trans_x);
    transform_norm (4);    norm_f[4] = calc_sphere(trans_x);
    transform_norm (5);    norm_f[5] = calc_sphere(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (6);    norm_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (7);    norm_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (8);    norm_f[8] = calc_griewank(trans_x);
    transform_norm (9);    norm_f[9] = calc_griewank(trans_x);
    return;
}

long double calc_benchmark_f19(long double *x)
{
    int i;
    long double res;
    transform (x, 0);    basic_f[0] = calc_ackley(trans_x);
    transform (x, 1);    basic_f[1] = calc_ackley(trans_x);
    transform (x, 2);    basic_f[2] = calc_rastrigin(trans_x);
    transform (x, 3);    basic_f[3] = calc_rastrigin(trans_x);
    transform (x, 4);    basic_f[4] = calc_sphere(trans_x);
    transform (x, 5);    basic_f[5] = calc_sphere(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 6);    basic_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 7);    basic_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 8);    basic_f[8] = calc_griewank(trans_x);
    transform (x, 9);    basic_f[9] = calc_griewank(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f20
void calc_benchmark_norm_f20()
{
    int i;
    transform_norm (0);    norm_f[0] = calc_ackley(trans_x);
    transform_norm (1);    norm_f[1] = calc_ackley(trans_x);
    transform_norm (2);    norm_f[2] = calc_rastrigin(trans_x);
    transform_norm (3);    norm_f[3] = calc_rastrigin(trans_x);
    transform_norm (4);    norm_f[4] = calc_sphere(trans_x);
    transform_norm (5);    norm_f[5] = calc_sphere(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (6);    norm_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (7);    norm_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (8);    norm_f[8] = calc_griewank(trans_x);
    transform_norm (9);    norm_f[9] = calc_griewank(trans_x);
    return;
}

long double calc_benchmark_f20(long double *x)
{
    int i;
    long double res;
    transform (x, 0);    basic_f[0] = calc_ackley(trans_x);
    transform (x, 1);    basic_f[1] = calc_ackley(trans_x);
    transform (x, 2);    basic_f[2] = calc_rastrigin(trans_x);
    transform (x, 3);    basic_f[3] = calc_rastrigin(trans_x);
    transform (x, 4);    basic_f[4] = calc_sphere(trans_x);
    transform (x, 5);    basic_f[5] = calc_sphere(trans_x);
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 6);    basic_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 7);    basic_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 8);    basic_f[8] = calc_griewank(trans_x);
    transform (x, 9);    basic_f[9] = calc_griewank(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f21
void calc_benchmark_norm_f21()
{
    int i;
    long double temp1, temp2, temp;
    transform_norm (0);
    norm_f[0] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (1);
    norm_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (2);    norm_f[2] = calc_rastrigin(trans_x);
    transform_norm (3);    norm_f[3] = calc_rastrigin(trans_x);
    transform_norm(4);
    norm_f[4] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform_norm(5);
    norm_f[5] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (6);    norm_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (7);    norm_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (8);    norm_f[8] = calc_griewank(trans_x);
    transform_norm (9);    norm_f[9] = calc_griewank(trans_x);
    return;
}

long double calc_benchmark_f21(long double *x)
{
    int i;
    long double temp1, temp2, temp;
    long double res;
    transform (x, 0);
    basic_f[0] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform (x, 1);
    basic_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform (x, 2);    basic_f[2] = calc_rastrigin(trans_x);
    transform (x, 3);    basic_f[3] = calc_rastrigin(trans_x);
    transform (x, 4);
    basic_f[4] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform(x, 5);
    basic_f[5] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 6);    basic_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 7);    basic_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 8);    basic_f[8] = calc_griewank(trans_x);
    transform (x, 9);    basic_f[9] = calc_griewank(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f22
void calc_benchmark_norm_f22()
{
    int i;
    long double temp1, temp2, temp;
    transform_norm (0);
    norm_f[0] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (1);
    norm_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (2);    norm_f[2] = calc_rastrigin(trans_x);
    transform_norm (3);    norm_f[3] = calc_rastrigin(trans_x);
    transform_norm(4);
    norm_f[4] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform_norm(5);
    norm_f[5] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (6);    norm_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (7);    norm_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (8);    norm_f[8] = calc_griewank(trans_x);
    transform_norm (9);    norm_f[9] = calc_griewank(trans_x);
    return;
}

long double calc_benchmark_f22(long double *x)
{
    int i;
    long double temp1, temp2, temp;
    long double res;
    transform (x, 0);
    basic_f[0] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform (x, 1);
    basic_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform (x, 2);    basic_f[2] = calc_rastrigin(trans_x);
    transform (x, 3);    basic_f[3] = calc_rastrigin(trans_x);
    transform (x, 4);
    basic_f[4] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform(x, 5);
    basic_f[5] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (x, 6);    basic_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 7);    basic_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (x, 8);    basic_f[8] = calc_griewank(trans_x);
    transform (x, 9);    basic_f[9] = calc_griewank(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# ifdef f23
void calc_benchmark_norm_f23()
{
    int i;
    long double temp1, temp2, temp;
    transform_norm (0);
    norm_f[0] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (1);
    norm_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (2);    norm_f[2] = calc_rastrigin(trans_x);
    transform_norm (3);    norm_f[3] = calc_rastrigin(trans_x);
    transform_norm(4);
    norm_f[4] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform_norm(5);
    norm_f[5] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (6);    norm_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (7);    norm_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (8);    norm_f[8] = calc_griewank(trans_x);
    transform_norm (9);    norm_f[9] = calc_griewank(trans_x);
    return;
}

long double calc_benchmark_f23(long double *x)
{
    int i;
    long double temp1, temp2, temp;
    long double res;
    int a;
    long double b;
    for (i=0; i<nreal; i++)
    {
        if (fabs(x[i]-o[0][i]) >= 0.5)
        {
            res = 2.0*x[i];
            a = res;
            b = fabs(res-a);
            if (b<0.5)
            {
                temp_x4[i] = a/2.0;
            }
            else
            {
                if (res<=0.0)
                {
                    temp_x4[i] = (a-1.0)/2.0;
                }
                else
                {
                    temp_x4[i] = (a+1.0)/2.0;
                }
            }
        }
        else
        {
            temp_x4[i] = x[i];
        }
    }
    transform (temp_x4, 0);
    basic_f[0] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[0] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform (temp_x4, 1);
    basic_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform (temp_x4, 2);    basic_f[2] = calc_rastrigin(trans_x);
    transform (temp_x4, 3);    basic_f[3] = calc_rastrigin(trans_x);
    transform (temp_x4, 4);
    basic_f[4] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[4] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform(temp_x4, 5);
    basic_f[5] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[5] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform (temp_x4, 6);    basic_f[6] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (temp_x4, 7);    basic_f[7] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform (temp_x4, 8);    basic_f[8] = calc_griewank(trans_x);
    transform (temp_x4, 9);    basic_f[9] = calc_griewank(trans_x);
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(temp_x4);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

//# if defined f24 || defined f25
void calc_benchmark_norm_f24()
{
    int i;
    long double temp1, temp2, temp;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    transform_norm (0);    norm_f[0] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);
    transform_norm (1);
    norm_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    norm_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    transform_norm (2);
    norm_f[2] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        norm_f[2] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    norm_f[2] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    transform_norm (3);    norm_f[3] = calc_ackley(trans_x);
    transform_norm (4);    norm_f[4] = calc_rastrigin(trans_x);
    transform_norm (5);    norm_f[5] = calc_griewank(trans_x);
    transform_norm (6);
    norm_f[6] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        norm_f[6] += nc_schaffer(trans_x[i], trans_x[i+1]);
    }
    norm_f[6] += nc_schaffer(trans_x[nreal-1], trans_x[0]);
    transform_norm(7);    norm_f[7] = nc_rastrigin(trans_x);
    transform_norm (8);
    norm_f[8] = 0.0;
    for (i=0; i<nreal; i++)
    {
        norm_f[8] += trans_x[i]*trans_x[i]*pow(1.0e6,i/(nreal-1.0));
    }
    transform_norm (9);    norm_f[9] = calc_sphere(trans_x)*(1.0 + 0.1*fabs(randomnormaldeviate()));
    return;
}

long double calc_benchmark_f24(long double *x)
{
    int i;
    long double temp1, temp2, temp;
    long double res;
    for (i=0; i<nreal; i++)
    {
        norm_x[i] = 0.0;
    }
    /* First function */
    transform (x, 0);    basic_f[0] = calc_weierstrass(trans_x) - calc_weierstrass(norm_x);

    /* Second function */
    transform (x, 1);
    basic_f[1] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp1 = pow((sin(sqrt(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0)))),2.0);
        temp2 = 1.0 + 0.001*(pow(trans_x[i],2.0)+pow(trans_x[i+1],2.0));
        basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));
    }
    temp1 = pow((sin(sqrt(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0)))),2.0);
    temp2 = 1.0 + 0.001*(pow(trans_x[nreal-1],2.0)+pow(trans_x[0],2.0));
    basic_f[1] += 0.5 + (temp1-0.5)/(pow(temp2,2.0));

    /* Third Function */
    transform (x, 2);
    basic_f[2] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        temp = 100.0*pow((trans_x[i]*trans_x[i]-trans_x[i+1]),2.0) + 1.0*pow((trans_x[i]-1.0),2.0);
        basic_f[2] += (temp*temp)/4000.0 - cos(temp) + 1.0;
    }
    temp = 100.0*pow((trans_x[nreal-1]*trans_x[nreal-1]-trans_x[0]),2.0) + 1.0*pow((trans_x[nreal-1]-1.0),2.0);
    basic_f[2] += (temp*temp)/4000.0 - cos(temp) + 1.0;

    transform (x, 3);    basic_f[3] = calc_ackley(trans_x);
    transform (x, 4);    basic_f[4] = calc_rastrigin(trans_x);
    transform (x, 5);    basic_f[5] = calc_griewank(trans_x);

    /* Seventh Function */
    transform (x, 6);
    basic_f[6] = 0.0;
    for (i=0; i<nreal-1; i++)
    {
        basic_f[6] += nc_schaffer(trans_x[i], trans_x[i+1]);
    }
    basic_f[6] += nc_schaffer(trans_x[nreal-1], trans_x[0]);

    transform (x, 7);    basic_f[7] = nc_rastrigin(trans_x);

    transform (x, 8);
    basic_f[8] = 0.0;
    for (i=0; i<nreal; i++)
    {
        basic_f[8] += trans_x[i]*trans_x[i]*pow(1.0e6,i/(nreal-1.0));
    }
    transform (x, 9);    basic_f[9] = (calc_sphere(trans_x))*(1.0 + 0.1*fabs(randomnormaldeviate()));
    for (i=0; i<nfunc; i++)
    {
        basic_f[i] *= C/norm_f[i];
    }
    calc_weight(x);
    res = global_bias;
    for (i=0; i<nfunc; i++)
    {
        res += weight[i]*(basic_f[i]+bias[i]);
    }
    return (res);
}
//# endif

void set_func(int n, int nvars)
{
    /* Assign nfunc and nreal in the begining */
    nfunc = 1;		/* For problems 1-14:  nfunc=1, and For problems 15-25: nfunc=10  */
	if(n >= 15)
		nfunc = 10;
    nreal = nvars;		/* number of variables, only 2, 10, 30, 50 variables are supported*/
	// seed  = 0.01;       /* should be within [0,1] */
    seed  = (rand()/(double)RAND_MAX);

	/* Call these routines to initialize random number generator */
    /* require for computing noise in some test problems */
    randomize();
    initrandomnormaldeviate();

    /* nreal and nfunc need to be initialized before calling these routines */
    /* Routine to allocate memory to global variables */
    allocate_memory();

    /* Routine the initalize global variables */
	/* 使用同一函数不必多次调用initialize() */
    // initialize();

    /* For test problems 15 to 25, we need to calculate a normalizing quantity */
    /* The line (54) below should be uncommented only for functions 15 to 25 */
    // calc_benchmark_norm();    /* Comment this line for functions 1 to 14 */
	switch(n)
	{
	case 1:
		initialize_f1();
		calc_benchmark_func = calc_benchmark_f1;
		break;
	case 2:
		initialize_f2();
		calc_benchmark_func = calc_benchmark_f2;
		break;
	case 3:
		initialize_f3();
		calc_benchmark_func = calc_benchmark_f3;
		break;
	case 4:
		initialize_f4();
		calc_benchmark_func = calc_benchmark_f4;
		break;
	case 5:
		initialize_f5();
		calc_benchmark_func = calc_benchmark_f5;
		break;
	case 6:
		initialize_f6();
		calc_benchmark_func = calc_benchmark_f6;
		break;
	case 7:
		initialize_f7();
		calc_benchmark_func = calc_benchmark_f7;
		break;
	case 8:
		initialize_f8();
		calc_benchmark_func = calc_benchmark_f8;
		break;
	case 9:
		initialize_f9();
		calc_benchmark_func = calc_benchmark_f9;
		break;
	case 10:
		initialize_f10();
		calc_benchmark_func = calc_benchmark_f10;
		break;
	case 11:
		initialize_f11();
		calc_benchmark_func = calc_benchmark_f11;
		break;
	case 12:
		initialize_f12();
		calc_benchmark_func = calc_benchmark_f12;
		break;
	case 13:
		initialize_f13();
		calc_benchmark_func = calc_benchmark_f13;
		break;
	case 14:
		initialize_f14();
		calc_benchmark_func = calc_benchmark_f14;
		break;
	case 15:
		initialize_f15();
		calc_benchmark_norm_f15();
		calc_benchmark_func = calc_benchmark_f15;
		break;
	case 16:
		initialize_f16();
		calc_benchmark_norm_f16();
		calc_benchmark_func = calc_benchmark_f16;
		break;
	case 17:
		initialize_f17();
		calc_benchmark_norm_f17();
		calc_benchmark_func = calc_benchmark_f17;
		break;
	case 18:
		initialize_f18();
		calc_benchmark_norm_f18();
		calc_benchmark_func = calc_benchmark_f18;
		break;
	case 19:
		initialize_f19();
		calc_benchmark_norm_f19();
		calc_benchmark_func = calc_benchmark_f19;
		break;
	case 20:
		initialize_f20();
		calc_benchmark_norm_f20();
		calc_benchmark_func = calc_benchmark_f20;
		break;
	case 21:
		initialize_f21();
		calc_benchmark_norm_f21();
		calc_benchmark_func = calc_benchmark_f21;
		break;
	case 22:
		initialize_f22();
		calc_benchmark_norm_f22();
		calc_benchmark_func = calc_benchmark_f22;
		break;
	case 23:
		initialize_f23();
		calc_benchmark_norm_f23();
		calc_benchmark_func = calc_benchmark_f23;
		break;
	case 24:
	case 25:
		initialize_f24();
		calc_benchmark_norm_f24();
		calc_benchmark_func = calc_benchmark_f24;
		break;
	}
}

void unset_func()
{
    /* Routine to free the memory allocated at run time */
    free_memory();
}