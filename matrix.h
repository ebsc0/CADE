/**
 * @file matrix.h
 * @author ebsco (e2baek@uwaterloo.ca)
 * @brief Matrix definition and methods.
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "common.h"

/**
 * @struct Matrix
 * @brief Matrix struct.
 * @var uint8 Matrix::row
 * number of rows of matrix
 * @var uint8 Matrix::col
 * number of cols of matrix
 * @var float32* Matrix::data
 * pointer pointing to data of matrix
 */
typedef struct Matrix {
    uint8 row;
    uint8 col;
    float32 *data;
} Matrix;

/**
 * @brief Create matrix.
 * 
 * Creates a matrix of size row x col in **row-major order**.
 * 
 * @param row number of rows of matrix
 * @param col number of columns of matrix
 * @return Matrix* pointer to Matrix type
 */
Matrix* matrix_create(uint8 row, uint8 col);

/**
 * @brief Free matrix.
 * 
 * Frees the allocated memory of the matrix.
 * 
 * @param matrix matrix to free
 */
void matrix_free(Matrix* matrix);

/**
 * @brief Print matrix.
 * 
 * Prints the matrix.
 * 
 * @param matrix matrix to print
 */
void matrix_print(Matrix* matrix);

/**
 * @brief Fill matrix with values from *start* with step size *step*.
 * 
 * Fills the matrix from *start* with step size *step* from left to right, row by row.
 * 
 * @param matrix matrix to fill
 * @param start starting value (included)
 * @param step step size
 */
void matrix_arange(Matrix* matrix, float32 start, float32 step);

/**
 * @brief Fill matrix with *fill_value*.
 * 
 * @param matrix matrix to fill
 * @param fill_value fill value
 */
void matrix_fill(Matrix* matrix, float32 fill_value);

/**
 * @brief Fill matrix with 0.
 * 
 * @param matrix matrix to fill
 */
void matrix_zeros(Matrix* matrix);

/**
 * @brief Fill matrix with 1.
 * 
 * @param matrix matrix to fill
 */
void matrix_ones(Matrix* matrix);

/**
 * @brief Fill matrix with random values.
 * 
 * Fills the matrix with random values ranging from (and including) the lower bound untill (and including) the upper bound.
 * This function uses the rand() function from stdlib.h library and may not be suitable for security applications.
 * 
 * @param matrix matrix to fill
 * @param lower lower bound (inclusive)
 * @param upper upper bound (inclusive)
 */
void matrix_rand(Matrix* matrix, uint8 lower, uint8 upper);

#endif // MATRIX_H