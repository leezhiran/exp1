#pragma once
#include <vector>
#include <map>
#include <math.h>
using namespace std;
class Hermite
{
private:
	vector<pair<double, double> > points;
	vector<double> d;
public:

	double hermit_esti(double x);
	void init_1();
};

