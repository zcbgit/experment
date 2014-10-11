// PSO.h: interface for the PSO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSO_H__BE1A7B0F_ECED_4E03_895D_A990D0BBC76A__INCLUDED_)
#define AFX_PSO_H__BE1A7B0F_ECED_4E03_895D_A990D0BBC76A__INCLUDED_

#ifndef W_PSO
#define W_PSO 0.5                                              //惯性系数
#endif
#ifndef C1_PSO
#define C1_PSO 2.0                                             //加速系数
#endif
#ifndef C2_PSO
#define C2_PSO 2.0                                             //加速系数
#endif
double PSO(int funnum,double low,double high);                 


#endif // !defined(AFX_PSO_H__BE1A7B0F_ECED_4E03_895D_A990D0BBC76A__INCLUDED_)
