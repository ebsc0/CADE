#include "matrix.h"

Matrix* matrix_create(uint8 row, uint8 col) 
{
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->col = col;
    matrix->row = row;
    matrix->data = (float32*)malloc(row * col * sizeof(float32));
    return matrix;
}

void matrix_free(Matrix* matrix)
{
    free(matrix->data);
    free(matrix);
}

void matrix_fill(Matrix* matrix, float32 fill_value)
{
    uint8 size = matrix->col * matrix->row;
    float32 *temp = (float32*)matrix;
    while(size-- > 0) *temp++ = fill_value;
}