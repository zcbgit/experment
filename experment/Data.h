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

#define D      30                                            //����ά��Ϊ30
#define NVARS    30                                            //��Ⱥ��СΪ30
#define MAXGENS  10000                                         //����������ÿ����������������Ϊ300000
#define CALTIMES 30                                            //����30������ȡƽ��ֵ
#define FUNNUM   13                                            //��������
#define TRUE     1
#define FALSE    0
#define NULL     0
/*
extern double xi[NVARS][D];                                  //���λ������
extern double vi[NVARS][D];                                  //����ٶ�����
extern double pBest_array[NVARS][D];                         //�������ʷ���Ž�λ������ֵ
extern double pBest_value[NVARS];                              //�������ʷ���Ž�ֵ
extern double gBest;                                           //ȫ����������ֵ
extern int gBest_i;                                            //ȫ�����������±�ֵ
*/
extern double result[CALTIMES];                                //30�μ���Ľ��  
extern double range[FUNNUM][2];                                //����������ȡֵ��Χ
extern double fmin0[13];

extern double range1[26][2];
extern double fmin[26];

typedef double (*FUN)(double [],int);                          //���庯��ָ����
extern FUN FunArray[FUNNUM];                                   //�洢������ָ������

typedef double(*Algorithm_Type)(int funnum,double low,double high); //�㷨����ָ����

#endif // !defined(AFX_DATA_H__4B20BF0B_4149_4E24_9D67_E81D864794FF__INCLUDED_)
