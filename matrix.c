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

void matrix_print(Matrix* matrix)
{
    printf("[");
    for(int i = 0; i < matrix->row; i++)
    {
        printf("[");
        for(int j = 0; j < matrix->col; j++)
        {
            printf("%f", matrix->data[(i*matrix->col)+j]);
            if(j < matrix->col - 1) {printf(" ");}
        }
        printf("]");
        if(i < matrix->row - 1) {printf("\n");}
    }
    printf("]");
}

void matrix_arange(Matrix* matrix, float32 start, float32 step)
{
    uint8 size = matrix->col * matrix->row;
    float32 *temp = (float32*)(matrix->data);
    for(int i = 0; i < size; i++)
    {
        *temp++ = start + i*step;
    }
}

void matrix_fill(Matrix* matrix, float32 fill_value)
{
    uint8 size = matrix->col * matrix->row;
    float32 *temp = (float32*)(matrix->data);
    while(size-- > 0) *temp++ = fill_value;
}

void matrix_zeros(Matrix *matrix)
{
    matrix_fill(matrix, 0);
}

void matrix_ones(Matrix *matrix)
{
    matrix_fill(matrix, 1);
}

void matrix_rand(Matrix* matrix, uint8 lower, uint8 upper)
{
    for(int i = 0; i < matrix->row; i++)
    {
        for(int j = 0; j < matrix->col; j++)
        {
            matrix->data[(i*matrix->col)+j] = (rand() % (upper - lower)) + lower;
        }
    }
}