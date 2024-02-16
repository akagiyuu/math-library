#include "helper/option.h"
#include <stdio.h>

struct Matrix {
	size_t row_count;
	size_t column_count;
	double *data;
};

struct Matrix *matrix_new(size_t row_count, size_t column_count);
struct Matrix *matrix_clone(const struct Matrix *m);
double matrix_get(const struct Matrix *m, size_t row, size_t column);
void matrix_set(struct Matrix *m, size_t row, size_t column, double value);
void matrix_transposition(struct Matrix *m);
void matrix_scalar_multiply(struct Matrix *m, double scalar);
bool matrix_inverse(struct Matrix *m);
struct Matrix *matrix_add(const struct Matrix *a, const struct Matrix *b);
struct Matrix *matrix_subtract(const struct Matrix *a, const struct Matrix *b);
struct Matrix *matrix_multiply(const struct Matrix *a, const struct Matrix *b);
double matrix_determinant(const struct Matrix *m);
Optional(double) matrix_trace(const struct Matrix *m);
