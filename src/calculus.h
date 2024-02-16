#include "helper/option.h"

typedef double (*function)(double);

Optional(double) lim(function f, double a);
Optional(double) derivative(function f, double x);
Optional(double) integrate(function f, double a, double b);
