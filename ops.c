#include "ops.h"

Matrix* ops_multiply(Matrix* a, Matrix* b)
{
    if(a->col != b->row) return NULL;

    Matrix *c = matrix_create(a->row, b->col);
    matrix_zeros(c);

    /*
    https://en.wikipedia.org/wiki/Matrix_multiplication
    ex:
    a_4x2 = a00 a01 a10 a11 a20 a21 a30 a31
    b_2x3 = b00 b01 b02 b10 b11 b12
    c_4x3 = c00 c01 c02 c10 c11 c12 c20 c21 c22 c30 c31 c32

    c00 = a00*b00 + a01*b10
    c01 = a00*b01 + a01*b11
    c02 = a00*b02 + a01*b12
    c10 = a10*b00 + a11*b10
    c11 = a10*b01 + a11*b11
    c12 = a10*b02 + a11*b12
    c20 = a20*b00 + a21*b10
    c21 = a20*b01 + a21*b11
    c22 = a20*b02 + a21*b12
    c30 = a30*b00 + a31*b10
    c31 = a30*b01 + a31*b11
    c32 = a30*b02 + a31*b12
    
    a_mxn, b_nxp, c_mxp
    cij = sum_0->n(aik*bkj)
    i = 0, ..., m-1
    j = 0, ..., p-1
    */

    for(int i = 0; i < a->row; i++)
    {
        for(int j = 0; j < b->col; j++)
        {
            for(int n = 0; n < a->col; n++)
            {
                c->data[(i*b->col)+j] += a->data[(i*a->col)+n] * b->data[(n*b->col)+j];
            }
        }
    }
    return c;
}

void ops_multiply_scalar(Matrix* matrix, float32 scalar)
{
    for(int i = 0; i < matrix->row; i++)
    {
        for(int j = 0; j < matrix->col; j++)
        {
            matrix->data[(i*matrix->col)+j] *= scalar;
        }
    }
}

Matrix* ops_add(Matrix* a, Matrix* b)
{
    if(a->col != b->col || a->row != b->row) return NULL;

    Matrix *c = matrix_create(a->row, a->col);
    for(int i = 0; i < a->row; i++)
    {
        for(int j = 0; j < a->col; j++)
        {
            c->data[(i*a->col)+j] = a->data[(i*a->col)+j] + b->data[(i*b->col)+j];
        }
    }
    return c;
}

void ops_add_scalar(Matrix* matrix, float32 scalar)
{
    for(int i = 0; i < matrix->row; i++)
    {
        for(int j = 0; j < matrix->col; j++)
        {
            matrix->data[(i*matrix->col)+j] += scalar;
        }
    }
}

Matrix* ops_transpose(Matrix* matrix)
{
    Matrix *transpose = matrix_create(matrix->col, matrix->row);
    for(int i = 0; i < matrix->col; i++)
    {
        for(int j = 0; j < matrix->row; j++)
        {
            transpose->data[(i*matrix->row)+j] = matrix->data[(j*matrix->col)+i];
        }
    }
    return transpose;
}

void ops_flatten(Matrix* matrix)
{
    matrix->col = matrix->col * matrix->row;
    matrix->row = 1;
}

bool ops_match(Matrix* a, Matrix* b)
{
    if(a->col != b->col || a->row != b->row) return false;

    for(int i = 0; i < a->row; i++)
    {
        for(int j = 0; j < a->col; j++)
        {
            if(a->data[(i*a->col)+j] != b->data[(i*b->col)+j]) return false;
        }
    }
    return true;
}