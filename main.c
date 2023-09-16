#include "matrix.h"
#include "ops.h"

int main()
{
    Matrix *a = matrix_create(3, 4);
    matrix_arange(a, 0, 1);
    matrix_print(a);
    ops_flatten(a);
    matrix_print(a);
   
    matrix_free(a);
    return 0;
}