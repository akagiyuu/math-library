#include "helper/option.h"
#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

struct Matrix *matrix_new(size_t row_count, size_t column_count)
{
	struct Matrix *result = malloc(sizeof(struct Matrix));
	result->data = malloc(row_count * column_count * sizeof(double));
	return result;
}

struct Matrix *matrix_clone(const struct Matrix *m)
{
	struct Matrix *result = matrix_new(m->row_count, m->column_count);

	for (size_t i = 0; i < m->row_count * m->column_count; i++) {
		result->data[i] = m->data[i];
	}

	return result;
}

double matrix_get(const struct Matrix *m, size_t row, size_t column)
{
	return m->data[row * m->column_count + column];
}

void matrix_set(struct Matrix *m, size_t row, size_t column, double value)
{
	m->data[row * m->column_count + column] = value;
}

void matrix_transposition(struct Matrix *m)
{
	for (size_t i = 0; i < m->row_count; i++) {
		for (size_t j = 0; j < m->column_count; j++) {
			matrix_set(m, j, i, matrix_get(m, i, j));
		}
	}
}

void matrix_scalar_multiply(struct Matrix *m, double scalar)
{
	for (size_t i = 0; i < m->row_count * m->column_count; i++) {
		m->data[i] *= scalar;
	}
}

bool matrix_inverse(struct Matrix *m);

struct Matrix *matrix_add(const struct Matrix *a, const struct Matrix *b)
{
	struct Matrix *result = matrix_clone(a);

	for (size_t i = 0; i < a->row_count * a->column_count; i++) {
		result->data[i] += b->data[i];
	}

	return result;
}

struct Matrix *matrix_subtract(const struct Matrix *a, const struct Matrix *b)
{
	struct Matrix *result = matrix_clone(a);

	for (size_t i = 0; i < a->row_count * a->column_count; i++) {
		result->data[i] -= b->data[i];
	}

	return result;
}

struct Matrix *matrix_multiply(const struct Matrix *a, const struct Matrix *b)
{
	if (a->column_count != b->row_count) {
		return NULL;
	}

	struct Matrix *result = matrix_new(a->row_count, b->column_count);
	for (size_t i = 0; i < a->row_count; i++) {
		for (size_t j = 0; j < b->column_count; j++) {
			double value = 0;
			for (size_t k = 0; k < a->column_count; k++) {
				value += matrix_get(a, i, k) * matrix_get(b, k, j);
			}
			matrix_set(result, i, j, value);
		}
	}

	return result;
}

double matrix_determinant(const struct Matrix *m);

Optional(double) matrix_trace(const struct Matrix *m)
{
	if (m->row_count != m->column_count) {
		return None(double);
	}

	double result = 0;
	for (size_t i = 0; i < m->row_count; i++) {
		result += matrix_get(m, i, i);
	}

	return Some(double, result);
}
