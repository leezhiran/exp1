#pragma once
#define _USE_MATH_DEFINES
#include "math.h"
#include "iostream"
using namespace std;
class CIR
{
private:
	double a,b;
	double p;
	int n;
	double f(double x) {
		return pow(M_E,x)*cos(x);
	}
public:
	double f1()	{
		double h = b - a;
		double t = ((b - a) / 2) * (f(a) + f(b));
		double tt = 1;
		int n=0;
		double tempout = t;
		for (int m = 1; abs((tt - t)) > p; m++)
		{
			t = tempout;
			h = 0.5 * h; 
			double temp = 0;
			for (int i = 1; i <= pow(2.0, (m - 1)); i++)
			{
				temp = temp + f(a + (2.0 * i - 1) * h);
			}
			n++;
			tt = 0.5 * t + h * temp;
			tempout = tt;

		}
		cout << n << endl;
		return tt;
	}
	CIR(double a, double b,double p) {
		this->a = a;
		this->b = b;
		this->p = p;
	}
};

