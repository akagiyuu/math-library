#include "solver.h"
#include "calculus.h"
#include <math.h>
#include <stdio.h>

#define EPSILON 1e-5
#define MAX_ITERATIONS 1e10

Optional(double) newton_method(function f, double initial_x)
{
	double x = initial_x;
    size_t iteration = 0;
    while(fabs(f(x)) > EPSILON) {
		double d_f = 0;
		if (!Unwrap(derivative(f, x), d_f)) {
			break;
		}

		x = x - f(x) / d_f;
        iteration += 1;
        if (iteration > MAX_ITERATIONS) {
            return None(double);
        }
	}

	return Some(double, x);
}
