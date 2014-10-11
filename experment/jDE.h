// jDE.h: interface for the jDE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDE_H__AD90D943_258E_4169_B566_A165083DDC30__INCLUDED_)
#define AFX_JDE_H__AD90D943_258E_4169_B566_A165083DDC30__INCLUDED_

#ifndef Fl_jDE
#define Fl_jDE 0.1                    //缩放因子最小值
#endif
#ifndef Fu_jDE
#define Fu_jDE 0.9                    //缩放因子最大值
#endif
#ifndef T_jDE
#define T_jDE 0.1                     //阈值
#endif

int Init_PARA_jDE();                                                   //初始化每个个体缩放、交叉因子
double jDE(int funnum,double low,double high); 

#endif // !defined(AFX_JDE_H__AD90D943_258E_4169_B566_A165083DDC30__INCLUDED_)
