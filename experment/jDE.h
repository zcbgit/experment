// jDE.h: interface for the jDE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDE_H__AD90D943_258E_4169_B566_A165083DDC30__INCLUDED_)
#define AFX_JDE_H__AD90D943_258E_4169_B566_A165083DDC30__INCLUDED_

#ifndef Fl_jDE
#define Fl_jDE 0.1                    //����������Сֵ
#endif
#ifndef Fu_jDE
#define Fu_jDE 0.9                    //�����������ֵ
#endif
#ifndef T_jDE
#define T_jDE 0.1                     //��ֵ
#endif

int Init_PARA_jDE();                                                   //��ʼ��ÿ���������š���������
double jDE(int funnum,double low,double high); 

#endif // !defined(AFX_JDE_H__AD90D943_258E_4169_B566_A165083DDC30__INCLUDED_)
