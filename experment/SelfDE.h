#ifndef _SELF_DE_H
#define _SELF_DE_H

//����Ӧ��ֽ����㷨
#ifndef Fmin_sDE
#define Fmin_sDE 0.1                                               //�����������
#endif
#ifndef Fmax_sDE
#define Fmax_sDE 0.5                                              //��С��������
#endif
#ifndef CR_sDE
#define CR_sDE 0.1                                                 //��������
#endif
double SelfDE(int funnum,double low,double high);

#endif