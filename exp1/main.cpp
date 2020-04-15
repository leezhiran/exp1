#include <iostream>
#include <stdio.h>
#include "lsm.h"
#include "vector"
#include "map"
using namespace std;

int main() {
	lsm l;
	l.init();
	cout << l.cacu_a() * 55 + l.cacu_b();
}
