// Data.h: interface for the Data class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATA_H__4B20BF0B_4149_4E24_9D67_E81D864794FF__INCLUDED_)
#define AFX_DATA_H__4B20BF0B_4149_4E24_9D67_E81D864794FF__INCLUDED_
/* Global Constants */
# define INF 1.0e99
# define EPS 1.0e-14
# define E  2.7182818284590452353602874713526625
# define PI 3.1415926535897932384626433832795029

#define IS_PSO 1
#define IS_DE 2
#define IS_JDE 3
#define IS_SADE 4
#define CHOICE 2

#define D      30                                            //函数维度为30
#define NVARS    30                                            //种群大小为30
#define MAXGENS  10000                                         //迭代次数，每个函数总评估次数为300000
#define CALTIMES 30                                            //计算30次用于取平均值
#define FUNNUM   13                                            //函数个数
#define TRUE     1
#define FALSE    0
#define NULL     0
/*
extern double xi[NVARS][D];                                  //解的位置向量
extern double vi[NVARS][D];                                  //解的速度向量
extern double pBest_array[NVARS][D];                         //自身的历史最优解位置向量值
extern double pBest_value[NVARS];                              //自身的历史最优解值
extern double gBest;                                           //全局最优向量值
extern int gBest_i;                                            //全局最优向量下标值
*/
extern double result[CALTIMES];                                //30次计算的结果  
extern double range[FUNNUM][2];                                //函数变量的取值范围
extern double fmin0[13];

extern double range1[26][2];
extern double fmin[26];

typedef double (*FUN)(double [],int);                          //定义函数指针型
extern FUN FunArray[FUNNUM];                                   //存储函数的指针数组

typedef double(*Algorithm_Type)(int funnum,double low,double high); //算法函数指针型

#endif // !defined(AFX_DATA_H__4B20BF0B_4149_4E24_9D67_E81D864794FF__INCLUDED_)
