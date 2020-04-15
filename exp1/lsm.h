#pragma once
#include "iostream"
#include "vector"
#include "map"
#include "vector"
#include "map"
#include "math.h"
using namespace std;
class lsm
{
private:
	vector<pair<double, double> > points;
public:
	void init() {
		points.push_back(make_pair(0, 68));
		points.push_back(make_pair(10, 67.1));
		points.push_back(make_pair(20, 66.4));
		points.push_back(make_pair(30, 65.6));
		points.push_back(make_pair(40, 64.6));
		points.push_back(make_pair(50, 61.8));
		points.push_back(make_pair(60, 61.0));
		points.push_back(make_pair(70, 60.8));
		points.push_back(make_pair(80, 60.4));
		points.push_back(make_pair(90, 60));
	}
	double cacu_b();
	double cacu_a();
};

