#ifndef __FInterface_h
#define __FInterface_h
#include "headfile.h"
#include "Data.h"
#include "TestFunction.h"
//��ȡ���Ժ�����ַ
int loadfunction();
//ѡ���ú����㷨�����FunNum������
int arg_sigma(Algorithm_Type alg,int FunNum);
//�������֮���ƽ������
double CalDistance(const long double xi[NVARS][D], const int gBest_i);
//��׼��ֽ����㷨
#include "DE.h"
// #ifndef F_DE
// #define F_DE 0.5                                                  //��������
// #endif
// #ifndef CR_DE
// #define CR_DE 0.3                                                 //��������
// #endif
// double DE(int funnum,double low,double high);

//�Ľ��Ͳ�ֽ����㷨
#include "SelfDE.h"
#include "jDE.h"
/*double ADE(int funnum,double low,double high);*/

//��������Ӧ�Ĳ�ֽ����㷨
//#include "SelfDE_F.h"
//#include "SelfDE_W_pb.h"
// #ifndef T1_selfDE
// #define T1_selfDE 0.1                                              //��������ѡ����ֵ
// #endif
// #ifndef T2_selfDE
// #define T2_selfDE 0.1                                              //��������ѡ����ֵ
// #endif
// double Fbest[NVARS];                                               //ÿ���������������
// double CRbest[NVARS];                                              //ÿ������Ľ�������
// double selfDE(int funnum,double low,double high);              

//��׼����Ⱥ�㷨
#include "PSO.h"
// #ifndef W_PSO
// #define W_PSO 0.5                                              //����ϵ��
// #endif
// #ifndef C1_PSO
// #define C1_PSO 2.0                                             //����ϵ��
// #endif
// #ifndef C2_PSO
// #define C2_PSO 2.0                                             //����ϵ��
// #endif
// double PSO(int funnum,double low,double high);                 

#endif
