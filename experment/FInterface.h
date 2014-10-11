#ifndef __FInterface_h
#define __FInterface_h
#include "headfile.h"
#include "Data.h"
#include "TestFunction.h"
//获取测试函数地址
int loadfunction();
//选择用何种算法计算第FunNum个函数
int arg_sigma(Algorithm_Type alg,int FunNum);
//计算个体之间的平均距离
double CalDistance(const long double xi[NVARS][D], const int gBest_i);
//标准差分进化算法
#include "DE.h"
// #ifndef F_DE
// #define F_DE 0.5                                                  //缩放因子
// #endif
// #ifndef CR_DE
// #define CR_DE 0.3                                                 //交叉因子
// #endif
// double DE(int funnum,double low,double high);

//改进型差分进化算法
#include "SelfDE.h"
#include "jDE.h"
/*double ADE(int funnum,double low,double high);*/

//参数自适应的差分进化算法
//#include "SelfDE_F.h"
//#include "SelfDE_W_pb.h"
// #ifndef T1_selfDE
// #define T1_selfDE 0.1                                              //缩放因子选择阈值
// #endif
// #ifndef T2_selfDE
// #define T2_selfDE 0.1                                              //交叉因子选择阈值
// #endif
// double Fbest[NVARS];                                               //每个个体的缩放因子
// double CRbest[NVARS];                                              //每个个体的交叉因子
// double selfDE(int funnum,double low,double high);              

//标准粒子群算法
#include "PSO.h"
// #ifndef W_PSO
// #define W_PSO 0.5                                              //惯性系数
// #endif
// #ifndef C1_PSO
// #define C1_PSO 2.0                                             //加速系数
// #endif
// #ifndef C2_PSO
// #define C2_PSO 2.0                                             //加速系数
// #endif
// double PSO(int funnum,double low,double high);                 

#endif
