// jDE.cpp: implementation of the jDE class.
//
//////////////////////////////////////////////////////////////////////

#include "headfile.h"
#include "Data.h"
#include "FInterface.h"
#include "jDE.h"
#include <string>


double F_jDE[NVARS];                                               //每个个体的缩放因子数组
double CR_jDE[NVARS];                                              //每个个体的交叉因子数组

int Init_PARA_jDE()
{
	for (int i=0;i<NVARS;i++)
	{
		F_jDE[i] = Fl_jDE + random(0,1) * Fu_jDE;
		CR_jDE[i] = random(0,1);
	}
	return 0;
}

//参数自适应的差分进化算法
double jDE(int funnum,double low,double high)
{
	double xi[NVARS][D];                                  //解的位置向量
	double pBest_value[NVARS];                              //自身的历史最优解值
	int gBest_i;                                            //全局最优向量下标值

	int i,j;
	int k = 1;
	int p1,p2,p3;
	int general = -1;
	double Vtem[30],Utem[30]; //变异和交叉数组

// 	FILE *log;
// 	fopen_s(&log, "jDE_log.txt","a");

	if (Init_PARA_jDE())
		printf("参数自适应差分进化算法：参数设置失败！\n");


	srand((unsigned int)time(NULL));

	gBest_i = 0;//把全局最优跟自身历史最优解下标初始化为0
	for (i=0;i<NVARS;i++)
		for (j=0;j<D;j++)
			xi[i][j] = random(low,high);
	for (i=0;i<NVARS;i++)
	{
		pBest_value[i] = FunArray[funnum](xi[i],D);
		//pBest_value[i] = calc_benchmark_func(xi[i]);
		if (pBest_value[i] < pBest_value[gBest_i])
			gBest_i = i;
	}  
// 	double d =CalDistance(xi, gBest_i);
// 	fprintf(log, "%lf\t%le\n", d, pBest_value[gBest_i]);
	//printf("%lf\n", d);

	for (k=1;k<MAXGENS;k++)
	{
		for (i=0;i<NVARS;i++)
		{
			int randi = random_int(0,D);
			//产生变异向量下标
			p1 = random_int(0,NVARS);
			p2 = random_int(0,NVARS);
			while (p1==p2)
				p2 = random_int(0,NVARS);
			p3 = random_int(0,NVARS);
			while (p3==p1 || p3==p2)
				p3 = random_int(0,NVARS);
			if (random(0,1) < T_jDE)
				F_jDE[i] = Fl_jDE + random(0,1) * Fu_jDE;
			if (random(0,1) < T_jDE)
				CR_jDE[i] = random(0,1);
			for (j=0;j<D;j++)
			{
				Vtem[j] = xi[p1][j] + F_jDE[i]*(xi[p2][j] - xi[p3][j]);
				while (Vtem[j]<low || Vtem[j]>high)
					Vtem[j] = random(low,high);
				if (random(0,1) <= CR_jDE[i] || j==randi)
					Utem[j] = Vtem[j];
				else
					Utem[j] = xi[i][j];
			}
			double temp = FunArray[funnum](Utem,D);
			//long double temp = calc_benchmark_func(Utem);
			if (pBest_value[i] > temp)
			{
				for (j=0;j<D;j++)
					xi[i][j] = Utem[j];
				pBest_value[i] = temp;
			}
		}
		gBest_i = 0;
		for (i=0;i<NVARS;i++)
		{
			if (pBest_value[i] < pBest_value[gBest_i])
				gBest_i = i;
		}
// 		if (0 == k % 100) {
// 			d = CalDistance(xi, gBest_i);
// 			fprintf(log, "%lf\t%le\n", d, pBest_value[gBest_i]);
// 			//printf("%lf\n", d);
// 		}
	}

// 	fprintf(log, "\n");
// 	fclose(log);

	return pBest_value[gBest_i];
}

