#ifndef _SELF_DE_H
#define _SELF_DE_H

//自适应差分进化算法
#ifndef Fmin_sDE
#define Fmin_sDE 0.1                                               //最大缩放因子
#endif
#ifndef Fmax_sDE
#define Fmax_sDE 0.5                                              //最小缩放因子
#endif
#ifndef CR_sDE
#define CR_sDE 0.1                                                 //交叉因子
#endif
double SelfDE(int funnum,double low,double high);

#endif