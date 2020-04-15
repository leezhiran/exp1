#include "Newton.h"
#include "iostream"
#include "vector"
#include "map"
using namespace std;
void Newton::init() {
	double argument, value;
	while (cin >> argument >> value) {
		this->points.push_back(make_pair(argument, value));
	}
	table = new double* [points.size() + 1];
	for (int i = 0; i < points.size() + 1; i++) {
		table[i] = new double[points.size() + 1];
	}

	vector<pair<double, double> >::iterator iter;
	int index = 0;
	for (iter = points.begin(); iter < points.end(); iter++) {
		table[0][index] = (iter->first);
		table[1][index] = iter->second;
		index++;
	}
	index = 1;
	for (int i = 2; i < points.size() + 1; i++) {
		for (int j = index; j < points.size(); j++) {
			table[i][j] = (table[i - 1][j] - table[i - 1][j - 1]) /
				(table[0][j] - table[0][j - 1 - (i - 2)]);
		}
		index += 1;
	}
}
void Newton::init1() {
	stage = 12;
	points.push_back(make_pair(0, 5));
	points.push_back(make_pair(10, 1));
	points.push_back(make_pair(20, 7.5));
	points.push_back(make_pair(30, 3));
	points.push_back(make_pair(40, 4.5));
	points.push_back(make_pair(50, 8.8));
	points.push_back(make_pair(60, 15.5));
	points.push_back(make_pair(70, 6.5));
	points.push_back(make_pair(80, -5));
	points.push_back(make_pair(90, -10));
	points.push_back(make_pair(100, -2));
	points.push_back(make_pair(110, 4.5));
	points.push_back(make_pair(120, 7));
	table = new double* [points.size() + 1];
	for (int i = 0; i < points.size() + 1; i++) {
		table[i] = new double[points.size() + 1];
	}

	vector<pair<double, double> >::iterator iter;
	int index = 0;
	for (iter = points.begin(); iter < points.end(); iter++) {
		table[0][index] = (iter->first);
		table[1][index] = iter->second;
		index++;
	}
	index = 1;
	for (int i = 2; i < points.size() + 1; i++) {
		for (int j = index; j < points.size(); j++) {
			table[i][j] = (table[i - 1][j] - table[i - 1][j - 1]) /
				(table[0][j] - table[0][j - 1 - (i - 2)]);
		}
		index += 1;
	}
}
double Newton::estimate(double x) {
	double ret=0;
	for (int i = 0; i < points.size(); i++) {
		double back=1;
		for (int j = 0; j < i; j++) {
			back *= (x - points.at(j).first);
		}
		double a = chashang(i);
		ret += back * chashang(i);
	}
	return ret;
}
double Newton::chashang( int stage) {
	return table[stage+1][stage];
}
/*
extern "C" {
	Newton n;
	void init_n() {
		n.init1();
	}
	void init_1() {
		n.init();
	}
	double esti_n(double x) {
		return n.estimate(x);
	}
}*/
