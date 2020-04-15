#pragma once
#include <vector>
using namespace std;
class Newton
{
	int stage;
	double** table;
	vector<pair<double, double> > points;
private:
	double chashang(int stage);
public:
	void init();
	void init1();
	double estimate(double x);

};

