#include <qVec.h>
#include <qMat.h>
#include <cmath>
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
template<typename T> qMat<T> translationMatrix(T x, T y, T z) {
    qMat<T> result = qMat<T>(4,4);
    for(int i = 0; i < result.getnSize(); i++) {
        result[i][i] = 1;
    }
    result[3][0] = x;
    result[3][1] = y;
    result[3][2] = z;
    return result;
}
template<typename T> qMat<T> rotationMatrix(T xAngle, T yAngle, T zAngle) {
    float xRad = xAngle * M_PI / 180.0;
    float yRad = yAngle * M_PI / 180.0;
    float zRad = zAngle * M_PI / 180.0;
    float xCos = cosf(xRad);
    float xSin = sinf(xRad);
    float yCos = cosf(yRad);
    float ySin = sinf(yRad);
    float zCos = cosf(zRad);
    float zSin = sinf(zRad);
    qMat<T> result = {
        {zCos * yCos, zCos * ySin * xSin - zSin * xCos, zCos * ySin * xCos + zSin * xSin, 0},
        {zSin * yCos, zSin * ySin * xSin + zCos * xCos, zSin * ySin * xCos - zCos * xSin, 0},
        {-ySin, yCos * xSin, yCos * xSin, yCos * xCos},
        {0, 0, 0, 1}};
    for(int i = 0; i < result.getnSize(); i++) {
        for(int j = 0; j < result.getmSize(); j++) {
            if(result[i][j] == 0.0) result[i][j] = 0;
        }
    }
    return result;
}
template<typename T> qMat<T> transformMatrix(T x, T y, T z, T xAngle, T yAngle, T zAngle) {
    float xRad = xAngle * M_PI / 180.0;
    float yRad = yAngle * M_PI / 180.0;
    float zRad = zAngle * M_PI / 180.0;
    float xCos = cosf(xRad);
    float xSin = sinf(xRad);
    float yCos = cosf(yRad);
    float ySin = sinf(yRad);
    float zCos = cosf(zRad);
    float zSin = sinf(zRad);
    qMat<T> result = {
        {zCos * yCos, zCos * ySin * xSin - zSin * xCos, zCos * ySin * xCos + zSin * xSin, 0},
        {zSin * yCos, zSin * ySin * xSin + zCos * xCos, zSin * ySin * xCos - zCos * xSin, 0},
        {-ySin, yCos * xSin, yCos * xSin, yCos * xCos},
        {x, y, z, 1}};
    for(int i = 0; i < result.getnSize(); i++) {
        for(int j = 0; j < result.getmSize(); j++) {
            if(result[i][j] == 0.0) result[i][j] = 0;
        }
    }
    return result;
}

#endif