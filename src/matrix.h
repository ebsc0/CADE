#ifndef MATRIX_H
#define MATRIX_H

#include "common.h"

typedef struct Matrix {
    uint8 row;
    uint8 col;
    float32 *data;
} Matrix;

Matrix* matrix_create(uint8 row, uint8 col);
void matrix_free(Matrix* matrix);
void matrix_fill(Matrix* matrix, float32 fill_value);

#endif // MATRIX_H