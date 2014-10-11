#include "headfile.h"
#include "Data.h"
#include "FInterface.h"

int main(int argc, char* argv[])
{
	int FunCounter;

	if (loadfunction())
	{
		printf("加载函数列表失败！\n");
		exit(1);
	}

	FILE *log;
	if (CHOICE == IS_PSO)
		fopen_s(&log, "PSOresult.txt","w");
	else if (CHOICE == IS_DE)
		fopen_s(&log, "DEresult.txt","w");
	else if (CHOICE == IS_JDE)
		fopen_s(&log, "jDEresult.txt","w");
	else if (CHOICE == IS_SADE)
		fopen_s(&log, "SaDEresult.txt","w");
	for (FunCounter=0;FunCounter<13;FunCounter++)
	{
		if (CHOICE == IS_PSO)
			arg_sigma(PSO,FunCounter);
		else if (CHOICE == IS_DE)
			arg_sigma(DE,FunCounter);
		else if (CHOICE == IS_JDE)
			arg_sigma(jDE,FunCounter);
		else if (CHOICE == IS_SADE)
			arg_sigma(SelfDE,FunCounter);

		printf("fun%d\n", FunCounter + 1);
		fprintf(log, "fun%d\n", FunCounter + 1);
		for (int i = 0;i < CALTIMES; i++) {
			printf("%.6e\n", result[i]);
			fprintf(log, "%.6e\n", result[i]);
		}

	}
	fclose(log);
	system("PAUSE");
}