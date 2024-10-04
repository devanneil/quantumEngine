#include <qVec.h>
#include <qMat.h>
#ifndef QLINMAT
#define QLINMAT
/**
 * @brief allows matrix to vector multiplication 
 * 
 * @note use matrixMultiply() to multiply a vector to a matrix
 * 
 * @param matrix to apply the vector to
 * @param vector to be applied to the matrix
 * 
 * @return qVec<T> result of the multiplication
 */
template <typename T, typename H>
qVec<T> vectorMultiply(const qVec<H>& vector, const qMat<T>& matrix) {
    // Ensure the matrix and vector dimensions match
    if (matrix.getmSize() != vector.getSize()) {
        throw std::invalid_argument("Matrix column size must match vector size.");
    }

    qVec<T> result(matrix.getmSize()); // Result vector has as many rows as the matrix

    for (int i = 0; i < matrix.getnSize(); ++i) {
        result[i] = vector.dot(matrix.get(i)); // Use the dot product with each row of the matrix
    }

    return result; // Return the resulting vector
}
/**
 * @brief allows matrix to vector multiplication 
 * 
 * @note use matrixMultiply() to multiply a vector to a matrix
 * 
 * @param matrix to apply the vector to
 * @param vector to be applied to the matrix
 * 
 * @return qVec<T> result of the multiplication
 */
template <typename T>
qVec<T> vectorMultiply(const qVec<T>& vector, const qMat<T>& matrix) {
    // Ensure the matrix and vector dimensions match
    if (matrix.getmSize() != vector.getSize()) {
        throw std::invalid_argument("Matrix column size must match vector size.");
    }

    qVec<T> result(matrix.getmSize()); // Result vector has as many rows as the matrix

    for (int i = 0; i < matrix.getnSize(); ++i) {
        result[i] = vector.dot(matrix.get(i)); // Use the dot product with each row of the matrix
    }

    return result; // Return the resulting vector
}
/**
 * @brief allows vector to matrix multiplication 
 * 
 * @note use vectorMultiply() to multiply a matrix to a vector
 * 
 * @param vector to be applied to the matrix
 * @param matrix to apply the vector to
 * 
 * @return qVec<T> result of the multiplication
 */
template <typename T, typename H>
qMat<T> matrixMultiply(qVec<T> vector, qMat<H> matrix) {

}
#endif