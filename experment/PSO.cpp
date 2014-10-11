// PSO.cpp: implementation of the PSO class.
//
//////////////////////////////////////////////////////////////////////

#include "headfile.h"
#include "Data.h"
#include "FInterface.h"
#include "PSO.h"
#include <iostream>

using namespace std;

//��׼����Ⱥ�㷨
double PSO(int funnum,double low,double high)
{
	int i,j;
	int k = 1;
	long double xi[NVARS][D];                                  //���λ������
	long double vi[NVARS][D];                                  //����ٶ�����
	long double pBest_array[NVARS][D];                         //��������ʷ���Ž�λ������ֵ
	long double pBest_value[NVARS];                              //��������ʷ���Ž�ֵ
	int gBest_i;                                            //ȫ�����������±�ֵ
	FILE *log;
	fopen_s(&log, "PSO_log.txt","a");

	//��ʼ��
	gBest_i = 0;//��ȫ�����Ÿ�������ʷ���Ž��±��ʼ��Ϊ0
	srand((unsigned int)time(NULL));

	/* set_func(function_number, dimension), function_number: 1-25 */
	set_func(funnum + 1, D);

	for (i=0;i<NVARS;i++)
		for (j=0;j<D;j++)
		{
			pBest_array[i][j] = xi[i][j] = random(low,high);
			vi[i][j] = random(low,high);
		}
		for (i=0;i<NVARS;i++)
		{
			pBest_value[i] = FunArray[funnum](xi[i],D);
			if (pBest_value[i] < pBest_value[gBest_i])
				gBest_i = i;
		}
		double d =CalDistance(xi, gBest_i);
		fprintf(log, "%lf\t%le\n", d, pBest_value[gBest_i]);
		while (k < MAXGENS)
		{
			//���ӵ��ٶȸ��º�λ�ø���
			for (i=0;i<NVARS;i++)
				for (j=0;j<D;j++)
				{
					vi[i][j] = W_PSO*vi[i][j]+C1_PSO*random(0,1)*(pBest_array[i][j]-xi[i][j])+C2_PSO*random(0,1)*(pBest_array[gBest_i][j]-xi[i][j]);
					//�޶�����ٶ�ֵΪ100��15%
					if (vi[i][j] > high*0.15)
						vi[i][j] = high*0.15;
					else if (vi[i][j] < low*0.15)
						vi[i][j] = low*0.15;
					xi[i][j] += vi[i][j];
					//���кϷ��Ե���
					if (xi[i][j] > high)
						xi[i][j] = high;
					else if (xi[i][j] < low)
						xi[i][j] = low;
				}
				for (i=0;i<NVARS;i++)
				{
					double temp;
					temp = FunArray[funnum](xi[i],D);
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
				if (0 == k % 100) {
					d = CalDistance(xi, gBest_i);
					fprintf(log, "%lf\t%le\n", d, pBest_value[gBest_i]);
					//printf("%lf\n", d);
				}
		}
		fprintf(log, "\n");
		fclose(log);
		/* use unset_func() to free memory */
		unset_func();
		return pBest_value[gBest_i];
}