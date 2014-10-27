// PSO.cpp: implementation of the PSO class.
//
//////////////////////////////////////////////////////////////////////

#include "headfile.h"
#include "Data.h"
#include "FInterface.h"
#include "PSO.h"
#include <iostream>

using namespace std;

//标准粒子群算法
double PSO(int funnum,double low,double high)
{
	int i,j;
	int k = 1;
	double xi[NVARS][D];                                  //解的位置向量
	double vi[NVARS][D];                                  //解的速度向量
	double pBest_array[NVARS][D];                         //自身的历史最优解位置向量值
	double pBest_value[NVARS];                              //自身的历史最优解值
	int gBest_i;                                            //全局最优向量下标值
// 	FILE *log;
// 	fopen_s(&log, "PSO_log.txt","a");

	//初始化
	gBest_i = 0;//把全局最优跟自身历史最优解下标初始化为0
	srand((unsigned int)time(NULL));

	for (i=0;i<NVARS;i++)
		for (j=0;j<D;j++)
		{
			pBest_array[i][j] = xi[i][j] = random(low,high);
			vi[i][j] = random(low,high);
		}
		for (i=0;i<NVARS;i++)
		{
			pBest_value[i] = FunArray[funnum](xi[i],D);
			//pBest_value[i] = calc_benchmark_func(xi[i]);
			if (pBest_value[i] < pBest_value[gBest_i])
				gBest_i = i;
		}
// 		double d =CalDistance(xi, gBest_i);
// 		fprintf(log, "%lf\t%le\n", d, pBest_value[gBest_i]);
		while (k < MAXGENS)
		{
			//粒子的速度更新和位置更新
			for (i=0;i<NVARS;i++)
				for (j=0;j<D;j++)
				{
					vi[i][j] = W_PSO*vi[i][j]+C1_PSO*random(0,1)*(pBest_array[i][j]-xi[i][j])+C2_PSO*random(0,1)*(pBest_array[gBest_i][j]-xi[i][j]);
					//限定最大速度值为100的15%
					if (vi[i][j] > high*0.15)
						vi[i][j] = high*0.15;
					else if (vi[i][j] < low*0.15)
						vi[i][j] = low*0.15;
					xi[i][j] += vi[i][j];
					//进行合法性调整
					if (xi[i][j] > high)
						xi[i][j] = high;
					else if (xi[i][j] < low)
						xi[i][j] = low;
				}
				for (i=0;i<NVARS;i++)
				{
					double temp = FunArray[funnum](xi[i],D);
					//long double temp = calc_benchmark_func(xi[i]);
					if (temp < pBest_value[i])
					{
						for (j=0;j<D;j++)
						{
							pBest_array[i][j] = xi[i][j];
							pBest_value[i] = temp;
						}
					}
				}
				gBest_i = 0;
				for (i=0;i<NVARS;i++)
				{
					if (pBest_value[i] < pBest_value[gBest_i])
						gBest_i = i;
				}
				k++;
// 				if (0 == k % 100) {
// 					d = CalDistance(xi, gBest_i);
// 					fprintf(log, "%lf\t%le\n", d, pBest_value[gBest_i]);
// 					//printf("%lf\n", d);
// 				}
		}
// 		fprintf(log, "\n");
// 		fclose(log);

		return pBest_value[gBest_i];
}
