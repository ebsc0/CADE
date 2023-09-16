#ifndef OPS_H
#define OPS_H

#include "matrix.h"

Matrix* ops_multiply(Matrix* a, Matrix* b);
void ops_multiply_scalar(Matrix* matrix, float32 scalar);
Matrix* ops_add(Matrix* a, Matrix* b);
void ops_add_scalar(Matrix* matrix, float32 scalar);
Matrix* ops_transpose(Matrix* matrix);
void ops_flatten(Matrix* matrix);
bool ops_match(Matrix* a, Matrix* b);

#endif // OPS_H