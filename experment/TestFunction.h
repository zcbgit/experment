#ifndef __TestFunction_h
#define __TestFunction_h

#include <stdio.h>
#include<math.h>
#include<stdlib.h>

#define pi acos(-1.0)

inline double random(double low, double high)
{
	//return low + (high-low)*rand()/RAND_MAX;
	return ((double)(rand()%1000)/1000.0)*(high - low) + low;
}
inline int random_int(int low, int high)
{
	if(high>low)
		return low + rand()%(high-low);
	else
		return low;
}
////////////////////////////////////////////////////
inline double ff(double present[],int DIM)
{
	double x1 = present[0];
	double x2 = present[1];
	return -x1-x2-x1*x2;
}
//f = min f(x1,x2) = {[sin(sqrt((x1^2+x2^2))]^2 - 0.5} / [1 + 0.001*(x1^2+x2^2)]^2
inline double f0(double present[],int DIM)
{
	// min f(x1,x2) = {[sin(sqrt((x1^2+x2^2))]^2 - 0.5} / [1 + 0.001*(x1^2+x2^2)]^2
	double x1 = present[0];
	double x2 = present[1];
	double up = sin(sqrt(x1*x1 + x2*x2)) * sin(sqrt(x1*x1 + x2*x2)) -0.5;
	double down = (1 + 0.001*(x1*x1 + x2*x2)) * (1 + 0.001*(x1*x1 + x2*x2));
	return 0.5+up/down;
}
// f1 = sum(xi*xi) i=1,2,......,30
inline double f1(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		ret += x[d]*x[d];
	}
	delete []x;
	return ret;
}
// f2 = min(sum(|xi|) + multi(|xi|)) i=1,2,......,30
inline double f2(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	double sum = 0;
	double multi = 1;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		if(x[d]<0) x[d] = -x[d];
		sum += x[d];
		multi *= x[d];
	}
	delete []x;
	return ret=sum+multi;
}
// f3=sum(i=1,n)[sum(j=1,i : xj)]^2 n=30
inline double f3(double present[],int DIM)
{
	double* x = new double[DIM];
	int i,j,d;
	double ret = 0;
	double in = 0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
	}
	for(i=0;i<DIM;i++){
		in = 0;
		for(j=0;j<=i;j++)
			in += x[j];
		in = in*in;
		ret += in;
	}
	delete []x;
	return ret;
}
// f4 =	min max(|xi|) i=1,2......30
inline double f4(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double max = present[0];
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		if(x[d]<0) x[d]	= -x[d];
		if(max<x[d])
			max = x[d];
	}
	delete []x;
	return max;
}
// f5 = sum(1,n-1 : (100(Xi+1 - Xi^2)^2 + (Xi-1)^2))
inline double f5(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM-1;d++){
		x[d] = present[d];
		x[d+1] = present[d+1];
		ret += 100*(x[d+1]-x[d]*x[d])*(x[d+1]-x[d]*x[d]) + (x[d]-1)*(x[d]-1);
	}
	delete []x;
	return ret;
}
// f6 = sum(floor((xi+0.5)*(xi+0.5)) i=1,2,......,30
inline double f6(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	double t;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		t = floor((x[d]+0.5));
		ret += t*t;
	}
	delete []x;
	return ret;
}
// f7 = sum(1:n i*xi^4) + random[0,1)
inline double f7(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		ret += (d+1)*x[d]*x[d]*x[d]*x[d];
	}
	ret += random(0,1);
	delete []x;
	return ret;
}

// f8 = sum(-xi*sin(sqrt(|xi|))) i=1,2,......,30
inline double f8(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		ret += (-x[d])*sin(sqrt(fabs(x[d])));
	}
	delete []x;
	return ret;
}

inline double ff8(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		ret += (-x[d])*sin(sqrt(fabs(x[d])));
	}
	delete []x;
	return 418.9829*DIM-ret;
}
// f9 = sum(xi^2-10cos(2*pi*xi)+10) i=1,2,......,30
inline double f9(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		ret += (x[d]*x[d] -10*cos(2*pi*x[d])+10);
	}
	delete []x;
	return ret;
}
// f9 = sum(xi^2-10cos(2*pi*xi)+10) i=1,2,......,30
inline double ff9(double present[],int DIM)
{
	double* y = new double[DIM];
	int d;
	double ret = 0;
	for(d=0;d<DIM;d++){
		if(fabs(present[d])<0.5)
			y[d] = present[d];
		else{
			if(y[d]<0)
				y[d] = int(2*present[d]-0.5)/2.0;
			else
				y[d] = int(2*present[d]+0.5)/2.0;
		}
		ret += (y[d]*y[d] -10*cos(2*pi*y[d])+10);
	}
	delete []y;
	return ret;
}
// f10
inline double f10(double present[],int DIM)
{
	int i;
	double s1,s2,x;
	s1=s2=0;
	for(i=0;i<DIM;i++){
		x = present[i];
		s1+=x*x; s2+=cos(2*pi*x);
	}
	double ret = -20.0*exp(-0.2*sqrt(s1/DIM))-exp(s2/DIM)+20+exp(1.0);
	return ret;
}
// f11 = sum(xi*xi)/4000.0-multi(cos(xi/sqrt(i)))+1;
inline double f11(double present[],int DIM)
{
	double* x = new double[DIM];
	int d;
	double ret = 0;
	double sum = 0;
	double multi = 1.0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		sum += x[d]*x[d];
		multi *= (cos(x[d]/sqrt(d+1.0)));
	}
	ret = sum/4000.0 - multi +1;
	delete []x;
	return ret;
}
inline double U(double x, double a, double k, double m)
{
	if(x>a)
		return k*pow((x-a),m);
	else if(x<-a)
		return k*pow((-x-a),m);
	else
		return 0;
}
// f12
inline double f12(double present[],int DIM)
{
	double *x=new double[DIM],*y=new double[DIM];
	int d;
	double s1 = 0;
	double s2 = 0;
	double multi = 1.0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
		y[d] = 1.0 + (x[d]+1)/4.0;
	}
	for(d=0;d<DIM-1;d++){
		s1+=(y[d]-1)*(y[d]-1)*(1+10*sin(pi*y[d+1])*sin(pi*y[d+1]));
		s2+=U(x[d],10,100,4);
	}
	s1+=10*sin(pi*y[0])*sin(pi*y[0]); s1+=(y[DIM-1]-1)*(y[DIM-1]-1); s1=s1*pi/DIM;
	s2+=U(x[DIM-1],10,100,4);
	delete []x; delete []y;
	return s1 + s2;
}
// f13
inline double f13(double present[],int DIM)
{
	double *x=new double[DIM];
	int d;
	double s1 = 0;
	double s2 = 0;
	double multi = 1.0;
	for(d=0;d<DIM;d++){
		x[d] = present[d];
	}
	for(d=0;d<DIM-1;d++){
		s1+=(x[d]-1)*(x[d]-1)*(1+sin(3.0*pi*x[d+1])*sin(3.0*pi*x[d+1]));
		s2+=U(x[d],5,100,4);
	}
	s1+=sin(3.0*pi*x[0])*sin(3.0*pi*x[0]);
	s1+=(x[DIM-1]-1)*(x[DIM-1]-1)*(1+sin(2*pi*x[DIM-1])*sin(2*pi*x[DIM-1])); s1=s1/10.0;
	s2+=U(x[DIM-1],5,100,4);
	delete []x;
	return s1 + s2;
}
// f14
inline double f14(double present[],int DIM)
{
	double x1,x2;
	int j;
	double ret = 0;
	int a[2][25]={{-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,16,32},
					{-32,-32,-32,-32,-32,-16,-16,-16,-16,-16,0,0,0,0,0,16,16,16,16,16,32,32,32,32,32}};
	x1 = present[0];
	x2 = present[1];
	ret = 1.0/500;
	for(j=1;j<=25;j++){
		ret+=1/(j+pow(x1-a[0][j-1],6)+pow(x2-a[1][j-1],6));
	}
	ret = 1.0/ret;
	return ret;
}
// f15
inline double f15(double present[],int DIM)
{
	double* x = new double[4];
	int i,d;
	double ret = 0;
	double a[]={0.1957,0.1947,0.1735,0.1600,0.0844,0.0627,0.0456,0.0342,0.0323,0.0235,0.0246};
	double b[]={4,2,1,0.5,0.25,1.0/6,0.125,0.1,1.0/12,1.0/14,1.0/16};
	for(d=0;d<4;d++){
		x[d] = present[d];
	}
	for(i=0;i<11;i++)
		//ret += (a[i] - x[0]*(b[i]*b[i]+b[i]*x[1])/b[i]/b[i] + b[i]*x[2] + x[3])
		//      *(a[i] - x[0]*(b[i]*b[i]+b[i]*x[1])/b[i]/b[i] + b[i]*x[2] + x[3]);
		ret += (a[i] - x[0]*(b[i]*b[i]+b[i]*x[1])/(b[i]*b[i]+b[i]*x[2]+x[3]))
		      *(a[i] - x[0]*(b[i]*b[i]+b[i]*x[1])/(b[i]*b[i]+b[i]*x[2]+x[3]));
	delete []x;
	return ret;
}
// f16 = min 4*x1^2 - 2.1*x1^4 + x1^6/3 + x1*x2 -4*x2^2 +4*x2^4
inline double f16(double present[],int DIM)
{
	double x1 = present[0];
	double x2 = present[1];
	return 4*x1*x1 - 2.1*x1*x1*x1*x1 + x1*x1*x1*x1*x1*x1/3.0 + x1*x2 - 4*x2*x2 + 4*x2*x2*x2*x2;
}
// f17 = f(min) = (x2*x2 - 5.1*x1*x1/4/pi/pi + 5*x1/pi -6)^2 + 10*(1-1.0/8/pi)*cos(x1) + 10;
inline double f17(double present[],int DIM)
{
	double x1 = present[0];
	double x2 = present[1];
	return (x2*x2 - 5.1*x1*x1/4/pi/pi + 5*x1/pi -6)*(x2*x2 - 5.1*x1*x1/4/pi/pi + 5*x1/pi -6)
		 + 10*(1-1.0/8/pi)*cos(x1) + 10;
}
// f18 = min f(x1,x2) = (1+(x1+x2+1)^2*(19-14*x1+3*x1*x1-14*x2+6*x1*x2+3*x2*x2)) * (30+(2*x1-3*x2)^2*(18-32*x1+12*x1*x1+48*x2-36*x1*x2+27*x2*x2))
inline double f18(double present[],int DIM)
{
	double x1 = present[0];
	double x2 = present[1];
	return (1+(x1+x2+1)*(x1+x2+1)*(19-14*x1+3*x1*x1-14*x2+6*x1*x2+3*x2*x2))
		 * (30+(2*x1-3*x2)*(2*x1-3*x2)*(18-32*x1+12*x1*x1+48*x2-36*x1*x2+27*x2*x2));
}
// f19


//f19
inline double f19(double present[],int DIM)
{
	double a[10][4]={{4,4,4,4},{1,1,1,1},{8,8,8,8},{6,6,6,6},{3,7,3,7},
				{2,9,2,9},{5,5,3,3},{8,1,8,1},{6,2,6,2},{7,3.6,7,3.6}};
    double c[10]={0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5};

	int i; double* x = new double[DIM];
	double ret = 0;
	for(i=0;i<DIM;i++)
	{
		x[i] = present[i];
		ret+=sin(x[i])*pow(sin((i+1)*x[i]*x[i]/pi),20);
	}
	delete []x;
	return -ret;
}
//f20
inline double f20(double present[],int DIM)
{
	int i; double* x = new double[DIM];
	double ret = 0;
	for(i=0;i<DIM;i++)
	{
		x[i] = present[i];
		ret+=(pow(x[i],4)-16*x[i]*x[i]+5*x[i]);
	}
	delete []x;
	return ret/DIM;
}
// f21
inline double f21(double present[],int DIM)
{
	double a[10][4]={{4,4,4,4},{1,1,1,1},{8,8,8,8},{6,6,6,6},{3,7,3,7},
				{2,9,2,9},{5,5,3,3},{8,1,8,1},{6,2,6,2},{7,3.6,7,3.6}};
    double c[10]={0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5};

	int i,j;
	double *x=new double[4],ret,tmp;
	ret = 0;
	for(i=0;i<4;i++)
		x[i] = present[i];
	for(i=0;i<5;i++){
		tmp=0;
		for(j=0;j<4;j++){
			tmp += (x[j]-a[i][j])*(x[j]-a[i][j]);
		}
		ret += 1.0/(tmp+c[i]);
	}
	delete []x;
	return -ret;
}
// f22
inline double f22(double present[],int DIM)
{
	double a[10][4]={{4,4,4,4},{1,1,1,1},{8,8,8,8},{6,6,6,6},{3,7,3,7},
				{2,9,2,9},{5,5,3,3},{8,1,8,1},{6,2,6,2},{7,3.6,7,3.6}};
    double c[10]={0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5};
	int i,j;
	double *x=new double[4],ret,tmp;
	ret = 0;
	for(i=0;i<4;i++)
		x[i] = present[i];
	for(i=0;i<7;i++){
		tmp=0;
		for(j=0;j<4;j++){
			tmp += (x[j]-a[i][j])*(x[j]-a[i][j]);
		}
		ret += 1.0/(tmp+c[i]);
	}
	delete []x;
	return -ret;
}
// f23
inline double f23(double present[],int DIM)
{
	double a[10][4]={{4,4,4,4},{1,1,1,1},{8,8,8,8},{6,6,6,6},{3,7,3,7},
				{2,9,2,9},{5,5,3,3},{8,1,8,1},{6,2,6,2},{7,3.6,7,3.6}};
    double c[10]={0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5};
	int i,j;
	double *x=new double[4],ret,tmp;
	ret = 0;
	for(i=0;i<4;i++)
		x[i] = present[i];
	for(i=0;i<10;i++){
		tmp=0;
		for(j=0;j<4;j++){
			tmp += (x[j]-a[i][j])*(x[j]-a[i][j]);
		}
		ret += 1.0/(tmp+c[i]);
	}
	delete []x;
	return -ret;
}
// f24 function of f5 in CLPSO
inline double f24(double present[],int DIM)
{
	int i,k;
	double a=0.5,b=3; int KMAX=20;
	double s1,s2,t;
	s1=s2=0;
	for(i=0;i<DIM;i++){
		t = 0;
		for(k=0;k<=KMAX;k++)
			t+= pow(a,k)*cos(2*pi*pow(b,k)*(present[i]+0.5));
		s1+=t;
	}
	for(k=0;k<=KMAX;k++)
		s2+= pow(a,k)*cos(2*pi*pow(b,k)*0.5);
	return s1-DIM*s2;
}
/*
//////////////////////////////////////////////////////////
double ME[100][100];
double MTurn[100][100];
double MResult[100][100];
//create a single rotation matrix
void MRot(int i,int j, int DIM) {
	int k,m;
	for(k=0;k<DIM;k++) {
		for(m=0;m<DIM;m++) MTurn[k][m] = ME[k][m];
	}

	//draw a random angle
	double alpha = (rand()/(double)RAND_MAX - 0.5) * pi * 0.5;

	MTurn[j][j] = MTurn[i][i] = cos(alpha);
	MTurn[i][j] = MTurn[j][i] = sin(alpha);
	MTurn[j][i] = -MTurn[j][i];
}

void MulMatrix(int DIM) {
	int i,j,k;
	double** m = new double*[DIM];
	for(i=0;i<DIM;i++)
		m[i] = new double[DIM];
		
	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++) m[i][j] = 0;
	}

	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++) {
			for(k=0;k<DIM;k++) m[i][j] += MResult[i][k]*MTurn[k][j];
		}
	}

	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++) MResult[i][j] = m[i][j];
	}
	delete []m;
}

void createMatrix(int DIM, int print) {
	int i,j;

	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++) ME[i][j] = MResult[i][j] = 0;
		MResult[i][i] = ME[i][i] = 1;
		
	}

	for(i=1;i<DIM;i++) {
		MRot(0,i,DIM); //use MTurn[][], create a single rotation matrix
		MulMatrix(DIM); //use MResult[][] <- MRsult[][]*MTurn[][]
	}

	for(i=1;i<(DIM-1);i++) {
		MRot(i,DIM-1,DIM);
		MulMatrix(DIM);
	}
	if(print==1){
		for(i=0;i<DIM;i++) {
			for(j=0;j<DIM;j++) printf("%g ",MResult[i][j]);
			printf("\n");
		}
	}
}
// f8 = sum(-xi*sin(sqrt(|xi|))) i=1,2,......,30
inline double fr8(double present[],int DIM)
{
	double* x = new double[DIM];
	double* y = new double[DIM];
	int d,j;
	double ret = 0;
	for(d=0;d<DIM;d++)
		x[d] = present[d];
	for(d=0;d<DIM;d++){
		y[d] = 0;
		for(j=0;j<DIM;j++)
			y[d]+=MResult[d][j]*x[j];
		ret += (-y[d])*sin(sqrt(fabs(y[d])));
	}
	delete []x;
	delete []y;
	return ret;
}
inline double fr9(double present[],int DIM)
{
	double* x = new double[DIM];
	double* y = new double[DIM];
	int d,j;
	double ret = 0;
	for(d=0;d<DIM;d++)
		x[d] = present[d];
	for(d=0;d<DIM;d++){
		y[d] = 0;
		for(j=0;j<DIM;j++)
			y[d]+=MResult[d][j]*x[j];
		ret += (y[d]*y[d] -10*cos(2*pi*y[d])+10);
	}
	delete []x;
	delete []y;
	return ret;
}
inline double fr10(double present[],int DIM)
{
	int i,j;
	double s1,s2,y;
	s1=s2=0;
	for(i=0;i<DIM;i++){
		y=0;
		for(j=0;j<DIM;j++)
			y+=MResult[i][j]*present[j];
		s1+=y*y; s2+=cos(2*pi*y);
	}
	double ret = -20.0*exp(-0.2*sqrt(s1/DIM))-exp(s2/DIM)+20+exp(1.0);
	return ret;
}
// f11 = sum(xi*xi)/4000.0-multi(cos(xi/sqrt(i)))+1;
inline double fr11(double present[],int DIM)
{
	double* x = new double[DIM];
	double* y = new double[DIM];
	int d,j;
	double ret = 0;
	double sum = 0;
	double multi = 1.0;
	for(d=0;d<DIM;d++)
		x[d] = present[d];
	for(d=0;d<DIM;d++){
		y[d]=0;
		for(j=0;j<DIM;j++)
			y[d]+=MResult[d][j]*x[j];
		sum += y[d]*y[d];
		multi *= (cos(y[d]/sqrt(d+1.0)));
	}
	ret = sum/4000.0 - multi + 1;
	delete []x;
	delete []y;
	return ret;
}
*/
#endif