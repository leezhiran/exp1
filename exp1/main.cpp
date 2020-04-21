#include <iostream>
#include <stdio.h>
#include "CIR.h"
#include "vector"
#include "map"
#define _USE_MATH_DEFINES
#include "math.h"
using namespace std;

int main() {
	CIR c(0,M_PI,double(10e-6));
	cout << c.f1();
}
