/**
 * @file ops.h
 * @author ebsco (e2baek@uwaterloo.ca)
 * @brief Operations on matrices.
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef OPS_H
#define OPS_H

#include "matrix.h"

/**
 * @brief Multiply two matrices.
 * 
 * Matrix multiplication algorithm naively implemented using forloops.
 * An improvement would be using Winograd algorithm or Strassen's algorithm.
 * col size of a must equal row size of b.
 * The resulting matrix will have the same row size as a and the same col size as b.
 * 
 * @param a matrix a
 * @param b matrix b
 * @return Matrix* pointer to Matrix a*b
 */
Matrix* ops_multiply(Matrix* a, Matrix* b);

/**
 * @brief Multiply matrix with scalar.
 * 
 * @param matrix matrix to multiply
 * @param scalar scalar value
 */
void ops_multiply_scalar(Matrix* matrix, float32 scalar);

/**
 * @brief Add two matrices.
 * 
 * The two matrices must be of same size.
 * The resulting matrix will not change in size. 
 * 
 * @param a matrix a
 * @param b matrix b
 * @return Matrix* pointer to Matrix a+b
 */
Matrix* ops_add(Matrix* a, Matrix* b);

/**
 * @brief Add matrix with scalar.
 * 
 * @param matrix matrix to add
 * @param scalar scalar value
 */
void ops_add_scalar(Matrix* matrix, float32 scalar);

/**
 * @brief Transpose matrix.
 * 
 * Transpose is the swapping of values along a diagonal axis.
 * The row size and col size of the matrix would swap.
 * 
 * @param matrix matrix to transpose
 * @return Matrix* pointer to transposed matrix
 */
Matrix* ops_transpose(Matrix* matrix);

/**
 * @brief Flatten matrix to 1-row x n-col matrix.
 * 
 * @param matrix matrix to flatten
 */
void ops_flatten(Matrix* matrix);

/**
 * @brief Reshape matrix into row x col matrix.
 * 
 * @param matrix matrix to reshape
 * @param row number of rows of new matrix
 * @param col number of cols of new matrix
 */
void ops_reshape(Matrix* matrix, uint8 row, uint8 col);

/**
 * @brief Check if two matrices match.
 * 
 * @param a matrix a
 * @param b matrix b
 * @return true matrices match
 * @return false matrices do not match
 */
bool ops_match(Matrix* a, Matrix* b);

/**
 * @brief Calculate the cross correlation matrix.
 * 
 * Cross-correlation of a 2D matrix with a 2D kernel is similar to the convolution of a 2D matrix with a 2D kernel.
 * The difference is, convolution rotates the kernel matrix by 180deg before performing the operation.
 * PyTorch uses cross-correlation for their Conv2D as it is simpler and has no effect on performance.
 * 
 * @param matrix input matrix
 * @param kernel kernel matrix
 * @return Matrix* cross correlation matrix
 */
Matrix* ops_xcorrelation2d(Matrix* matrix, Matrix* kernel);

/**
 * @brief Subsample matrix with maxpool.
 * 
 * Pooling is a subsampling technique where we attempt to capture the information of the matrix while reducing its dimension.
 * Max Pooling is taking the largest value of a region to represent that region in the subsampled space.
 * 
 * @param matrix input matrix
 * @param pool_row number of rows of pool
 * @param pool_col number of cols of pool
 * @return Matrix* 
 */
Matrix* ops_maxpool2d(Matrix* matrix, uint8 pool_row, uint8 pool_col);

#endif // OPS_H