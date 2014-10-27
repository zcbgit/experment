#include "headfile.h"
#include "Data.h"
#include "FInterface.h"
#include "SelfDE.h"

double SelfDE(int funnum,double low,double high)
{
	int i,j;
	int k = 1;
	int p1,p2,p3;
	double xi[NVARS][D];                                  //解的位置向量
	double pBest_value[NVARS];                              //自身的历史最优解值
	int gBest_i;                                            //全局最优向量下标值
	double Vtem[30],Utem[30];
	double F = Fmax_sDE;

// 	FILE *log;
// 	fopen_s(&log, "selfDE_log.txt","a");
	//初始化
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
 	double maxd =CalDistance(xi, gBest_i);
// 	fprintf(log, "%lf\n", maxd);
	//printf("%lf\n", maxd);
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
			for (j=0;j<D;j++)
			{
				Vtem[j] = xi[p1][j] + F*(xi[p2][j] - xi[p3][j]);
				while (Vtem[j]<low || Vtem[j]>high)
					Vtem[j] = random(low,high);
				if (random(0,1) <= CR_sDE || j==randi)
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

		double d = CalDistance(xi, gBest_i);
// 		if (d < 0.01)
// 		{
// 			printf("********");
// 		}
// 		if (d < 0.01 * maxd) {
// 			for (i=0;i<NVARS;i++) {
// 				if (i != gBest_i) {
// 					for (j=0;j<D;j++)
// 						xi[i][j] = random(low,high);
// 				}
// 			}
// 			d = CalDistance(xi, gBest_i);
// 			for (i=0;i<NVARS;i++)
// 			{
// 				pBest_value[i] = FunArray[funnum](xi[i],D);
// 				if (pBest_value[i] < pBest_value[gBest_i])
// 					gBest_i = i;
// 			}
// 		}
		if (d>0.4*maxd)
			F = 0.3+0.2*d/maxd;
		else
			F = 0.9 - d/maxd;
		if (0 == k % 100) {
			/*fprintf(log, "%lf\n", d);*/
			//printf("%lf\n", d);
		}
	}
// 	fprintf(log, "\n");
// 	fclose(log);

	return pBest_value[gBest_i];
}