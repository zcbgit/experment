// DE.h: interface for the DE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DE_H__F9A5F455_8DC6_4696_B6F4_CE1152030217__INCLUDED_)
#define AFX_DE_H__F9A5F455_8DC6_4696_B6F4_CE1152030217__INCLUDED_


//标准差分进化算法
#ifndef F_DE
#define F_DE 0.5                                                  //缩放因子
#endif
#ifndef CR_DE
#define CR_DE 0.3                                                 //交叉因子
#endif
double DE(int funnum,double low,double high);

#endif // !defined(AFX_DE_H__F9A5F455_8DC6_4696_B6F4_CE1152030217__INCLUDED_)
