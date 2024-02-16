#include "calculus.h"
#include "helper/option.h"
#include <math.h>
#include <stdio.h>

#define DELTA 1e-10
#define EPSILON 1e-5
#define N 1e5

Optional(double) lim(function f, double a)
{
	double left_lim = f(a - DELTA);
	double right_lim = f(a + DELTA);
	if (fabs(left_lim - right_lim) >= EPSILON) {
		return None(double);
	}

	return Some(double, (left_lim + right_lim) / 2.0);
}

Optional(double) derivative(function f, double x)
{
	if (fabs(f(x)) == INFINITY) {
		return None(double);
	}

	double right_lim = (f(x + DELTA) - f(x)) / DELTA;
	double left_lim = (f(x) - f(x - DELTA)) / DELTA;
	if (fabs(left_lim - right_lim) >= EPSILON) {
		return None(double);
	}

	return Some(double, (left_lim + right_lim) / 2.0);
}

Optional(double) integrate(function f, double a, double b)
{
	double delta_x = (b - a) / N;
	double result = (f(a) + f(b)) / 2;
	for (double x = a + delta_x; x < b; x += delta_x) {
		double current = f(x);
		if (fabs(current) == INFINITY) {
			return None(double);
		}
		result += f(x);
	}
	result *= delta_x;

	return Some(double, result);
}
