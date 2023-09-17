#include "matrix.h"
#include "ops.h"

int main()
{
    Matrix *a = matrix_create(3, 3);
    matrix_arange(a, 0, 1);
    Matrix *k = matrix_create(2, 2);
    matrix_ones(k);

    Matrix *res = ops_maxpool2d(a, 2, 2);
    matrix_print(res);

    matrix_free(a);
    matrix_free(k);
    matrix_free(res);
    return 0;
}