#include "lsm.h"

double lsm::cacu_b() {
	double xi2 = 0, yi = 0, xi = 0, xiyi = 0;
	double b = 0;
	for (int i = 0; i < points.size(); i++) {
		xi2 += pow(points.at(i).first, 2);
		yi += points.at(i).second;
		xi += points.at(i).first;
		xiyi += points.at(i).first * points.at(i).second;
	}
	b = (xi2 * yi - xi * xiyi) / ((points.size()) * xi2 - pow(xi, 2));
	return b;
}

double lsm::cacu_a() {
	double xi2 = 0, yi = 0, xi = 0, xiyi = 0;
	double a = 0;
	for (int i = 0; i < points.size(); i++) {
		xi2 += pow(points.at(i).first, 2);
		yi += points.at(i).second;
		xi += points.at(i).first;
		xiyi += points.at(i).first * points.at(i).second;
	}
	a = (points.size() * xiyi - xi * yi) / (points.size() * xi2 - pow(xi,2));
	return a;
}
/*
extern "C" {
	lsm obj;
	double a, b;
	void init() {
		obj.init();
		 a = obj.cacu_a();
		 b = obj.cacu_b();
	}
	double get_line(double x) {
		return obj.cacu_a() * x + b;
	}
	
}*/
