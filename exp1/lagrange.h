#pragma once
#include "map"
#include "vector"
#include "iostream"
using namespace std;
class lagrange {
	int stage;
	vector<pair<double, double> > points;
public:
	void lagrange_init();
	void lagrange_init_1();
	double interpolation_estimation(double x);
};
