// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
	if (n == 0)
		return 1;
	else
		return value* pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
	double res = pown(x, n) / fact(n);
	return res;
}

double expn(double x, uint16_t count) {
	double exp = calcItem(x, count);
	for (uint16_t i = count--; i > 0; count--, i--)
		exp += calcItem(x, count);
    return exp;
}

double sinn(double x, uint16_t count) {
	double sin = 0;
	for (uint16_t i = 0; i != count; count--) {
		if (count % 2 == 1)
			sin += calcItem(x, (2 * count - 1));
		else
			sin -= calcItem(x, (2 * count - 1));
	}
	return sin;
}

double cosn(double x, uint16_t count) {
	double cos = 0;
	for (uint16_t i = 0; i != count; count--) {
		if (count % 2 == 1)
			cos += calcItem(x, (2 * count - 2));
		else
			cos -= calcItem(x, (2 * count - 2));
	}
	return cos;
}
