#include "Hermite.h"

#define N 10
double Hermite::hermit_esti(double x)
{
	double li, sum, y, gix[N], hix[N];
	for (int i = 0; i < N; i++)
	{
		li = 1.0; sum = 0.0;
		for (int j = 0; j < N; j++)
			if (j != i)
			{
				li = li * (x - points.at(j).first) / (points.at(i).first - points.at(j).first);   
				sum = sum + 1.0 / (points.at(i).first - points.at(j).first);
			}
		li *= li;
		gix[i] = (1.0 - 2.0 * (x - points.at(i).first) * sum) * li;
		hix[i] = (x - points.at(i).first) * li;
	}
	y = 0.0;
	for (int i = 0; i < N; i++) y = y + points.at(i).second * gix[i] + d.at(i) * hix[i];
	return y;

}
void Hermite::init_1() {
	points.push_back(make_pair(0.10, 0.904837));
	points.push_back(make_pair(0.20, 0.818731));
	points.push_back(make_pair(0.30, 0.740818));
	points.push_back(make_pair(0.40, 0.670320));
	points.push_back(make_pair(0.50, 0.606531));
	points.push_back(make_pair(0.60, 0.548812));
	points.push_back(make_pair(0.70, 0.496585));
	points.push_back(make_pair(0.80, 0.449329));
	points.push_back(make_pair(0.90, 0.406570));
	points.push_back(make_pair(1.00, 0.367879));
	d.push_back(-0.904837);
	d.push_back(-0.818731);
	d.push_back(-0.740818);
	d.push_back(-0.670320);
	d.push_back(-0.606531);
	d.push_back(-0.548812);
	d.push_back(-0.496585);
	d.push_back(-0.449329);
	d.push_back(-0.449329);
	d.push_back(-0.406570);
	d.push_back(-0.367879);
}/*
extern "C" {
	Hermite h;
	void init() {
		h.init_1();
	}
	double esti_n(double x) {
		return h.hermit_esti(x);
	}
}*/