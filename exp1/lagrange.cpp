#include "lagrange.h"

inline void lagrange::lagrange_init() {
	cin >> stage;
	for (int i = 0; i < stage + 1; i++) {
		double x, fx;
		cin >> x >> fx;
		points.push_back(make_pair(x, fx));
	}
}

inline void lagrange::lagrange_init_1() {
	stage = 9;
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

}

inline double lagrange::interpolation_estimation(double x) {

	if (points.size() == 0) {
		cout << "Î´³õÊ¼»¯" << endl;
		return 0;
	}
	double ret = 0;
	double under = 1;
	for (int i = 0; i <= stage; i++) {
		double term = 1;
		for (int k = 0; k <= stage; k++) {
			if (k == i)
				continue;
			term *= ((x - points.at(k).first) / (points.at(i).first - points.at(k).first));
			under = (points.at(i).first - points.at(k).first);
		}
		ret += (term * points.at(i).second);
	}
	return ret;
}
/*
extern "C" {
	lagrange obj;

	void init() {
		printf("%d", 1);
		obj.lagrange_init_1();
	}
	double esti_n(double x) {
		return obj.interpolation_estimation(x);
	}
}*/