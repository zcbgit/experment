//#include "StdAfx.h"
#include "FInterface.h"
#include "headfile.h"
#include <ppl.h>

using namespace Concurrency;

//获取测试函数地址
int loadfunction()
{
	FunArray[0] = &f1;
	FunArray[1] = &f2;
	FunArray[2] = &f3;
	FunArray[3] = &f4;
	FunArray[4] = &f5;
	FunArray[5] = &f6;
	FunArray[6] = &f7;
	FunArray[7] = &f8;
	FunArray[8] = &f9;
	FunArray[9] = &f10;
	FunArray[10] = &f11;
	FunArray[11] = &f12;
	FunArray[12] = &f13;
	
	return 0;
}

int arg_sigma(Algorithm_Type alg,int FunNum)
{
	int CalCounter;
	/* set_func(function_number, dimension), function_number: 1-25 */
	//set_func(FunNum, D);
	for (CalCounter=0;CalCounter<CALTIMES;CalCounter++)
		result[CalCounter] = alg(FunNum,range[FunNum][0],range[FunNum][1]) - fmin0[FunNum];
	/* use unset_func() to free memory */
	//unset_func();
	return 0;
}

double CalDistance(const double xi[NVARS][D], const int gBest_i)
{
	double distance=0;
	double dx;
	int i,j;
	for (i=0;i<NVARS;i++)
		for (j=0;j<D;j++) {
			dx = xi[gBest_i][j] - xi[i][j];
			distance += dx*dx;
		}
		distance =sqrt(distance)/(NVARS-1)/D;	
		return distance;
}