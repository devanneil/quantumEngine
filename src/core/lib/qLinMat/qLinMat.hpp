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
        {-ySin, yCos * xSin, yCos * xCos, 0},
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
        {-ySin, yCos * xSin, yCos * xCos, 0},
        {x, y, z, 1}};
    for(int i = 0; i < result.getnSize(); i++) {
        for(int j = 0; j < result.getmSize(); j++) {
            if(result[i][j] == 0.0) result[i][j] = 0;
        }
    }
    return result;
}
template<typename T> qMat<T> viewMatrix(qVec<T> from, qVec<T> to, qVec<T> upRef = qVec<float>{0.0, 0.0, 1.0}) {
    if(from.getSize() != 3 || to.getSize() != 3 || upRef.getSize() != 3) {
        throw std::invalid_argument("Vector must be size of 3!");
    }
    qVec<T> forward = to.sub(from).norm();
    qVec<T> right = forward.cross(upRef).norm();
    qVec<T> up = right.cross(forward).norm();

    qMat<T> result = {
        {right.getValue(0), up.getValue(0), -forward.getValue(0), 0},
        {right.getValue(1), up.getValue(1), -forward.getValue(1), 0},
        {right.getValue(2), up.getValue(2), -forward.getValue(2), 0},
        {-right.dot(from), -up.dot(from), forward.dot(from), 1}
    };
    return result;
}
inline qMat<float> projectionMatrix(float fov, float aspect, float near, float far) {
    float fovRad = fov * M_PI / 360;
    float tan = tanf(fovRad);

    qMat<float> result = {
        {1 / (aspect * tan), 0, 0, 0},
        {0, 1 / tan, 0, 0},
        {0, 0, (near + far) / (far - near), -1},
        {0, 0, (2 * near * far) / (far - near), 0}
    };

    return result;
}
#endif