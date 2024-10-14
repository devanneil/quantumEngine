#include "qMat.h"
#ifndef QMAT
#define QMAT
template qMat<int>::qMat(int n, int m);
template qMat<int>::qMat(std::initializer_list<std::initializer_list<int>> values);
template qMat<int>::qMat(qMat<int> const &src);
template qMat<int>::qMat(qMat<long> const &src);
template qMat<int>::qMat(qMat<float> const &src);
template qMat<int>::qMat(qMat<double> const &src);
template qMat<int>::~qMat();
template int qMat<int>::getnSize() const;
template int qMat<int>::getmSize() const;
template const qVec<int>& qMat<int>::get(int ind) const;
template int qMat<int>::at(int n, int m) const;
template void qMat<int>::set(int ind, const qVec<int>& vector);
template void qMat<int>::setAt(int n, int m, const int value);
template int* qMat<int>::toArray();
template qMat<int> qMat<int>::transpose() const;
template qMat<int> qMat<int>::add(const qMat<int>& addend) const;
template qMat<int> qMat<int>::add(const qMat<long>& addend) const;
template qMat<int> qMat<int>::add(const qMat<float>& addend) const;
template qMat<int> qMat<int>::add(const qMat<double>& addend) const;
template qMat<int> qMat<int>::scale(const int& factor) const;
template qMat<int> qMat<int>::scale(const long& factor) const;
template qMat<int> qMat<int>::scale(const float& factor) const;
template qMat<int> qMat<int>::scale(const double& factor) const;
template qMat<int> qMat<int>::multiply(const qMat<int>& factor) const;
template qMat<int> qMat<int>::multiply(const qMat<long>& factor) const;
template qMat<int> qMat<int>::multiply(const qMat<float>& factor) const;
template qMat<int> qMat<int>::multiply(const qMat<double>& factor) const;
template qMat<int>& qMat<int>::operator=(const qMat<int>&);
template qMat<int>& qMat<int>::operator=(const qMat<long>&);
template qMat<int>& qMat<int>::operator=(const qMat<float>&);
template qMat<int>& qMat<int>::operator=(const qMat<double>&);
template qVec<int>& qMat<int>::operator[](int index);         // Non-const version
template const qVec<int>& qMat<int>::operator[](int index) const; // Const version

template qMat<long>::qMat(int n, int m);
template qMat<long>::qMat(std::initializer_list<std::initializer_list<long>> values);
template qMat<long>::qMat(qMat<int> const &src);
template qMat<long>::qMat(qMat<long> const &src);
template qMat<long>::qMat(qMat<float> const &src);
template qMat<long>::qMat(qMat<double> const &src);
template qMat<long>::~qMat();
template int qMat<long>::getnSize() const;
template int qMat<long>::getmSize() const;
template const qVec<long>& qMat<long>::get(int ind) const;
template long qMat<long>::at(int n, int m) const;
template void qMat<long>::set(int ind, const qVec<long>& vector);
template void qMat<long>::setAt(int n, int m, const long value);
template long* qMat<long>::toArray();
template qMat<long> qMat<long>::transpose() const;
template qMat<long> qMat<long>::add(const qMat<int>& addend) const;
template qMat<long> qMat<long>::add(const qMat<long>& addend) const;
template qMat<long> qMat<long>::add(const qMat<float>& addend) const;
template qMat<long> qMat<long>::add(const qMat<double>& addend) const;
template qMat<long> qMat<long>::scale(const int& factor) const;
template qMat<long> qMat<long>::scale(const long& factor) const;
template qMat<long> qMat<long>::scale(const float& factor) const;
template qMat<long> qMat<long>::scale(const double& factor) const;
template qMat<long> qMat<long>::multiply(const qMat<int>& factor) const;
template qMat<long> qMat<long>::multiply(const qMat<long>& factor) const;
template qMat<long> qMat<long>::multiply(const qMat<float>& factor) const;
template qMat<long> qMat<long>::multiply(const qMat<double>& factor) const;
template qMat<long>& qMat<long>::operator=(const qMat<int>&);
template qMat<long>& qMat<long>::operator=(const qMat<long>&);
template qMat<long>& qMat<long>::operator=(const qMat<float>&);
template qMat<long>& qMat<long>::operator=(const qMat<double>&);
template qVec<long>& qMat<long>::operator[](int index);         // Non-const version
template const qVec<long>& qMat<long>::operator[](int index) const; // Const version

template qMat<float>::qMat(int n, int m);
template qMat<float>::qMat(std::initializer_list<std::initializer_list<float>> values);
template qMat<float>::qMat(qMat<int> const &src);
template qMat<float>::qMat(qMat<long> const &src);
template qMat<float>::qMat(qMat<float> const &src);
template qMat<float>::qMat(qMat<double> const &src);
template qMat<float>::~qMat();
template int qMat<float>::getnSize() const;
template int qMat<float>::getmSize() const;
template const qVec<float>& qMat<float>::get(int ind) const;
template float qMat<float>::at(int n, int m) const;
template void qMat<float>::set(int ind, const qVec<float>& vector);
template void qMat<float>::setAt(int n, int m, const float value);
template float* qMat<float>::toArray();
template qMat<float> qMat<float>::transpose() const;
template qMat<float> qMat<float>::add(const qMat<int>& addend) const;
template qMat<float> qMat<float>::add(const qMat<long>& addend) const;
template qMat<float> qMat<float>::add(const qMat<float>& addend) const;
template qMat<float> qMat<float>::add(const qMat<double>& addend) const;
template qMat<float> qMat<float>::scale(const int& factor) const;
template qMat<float> qMat<float>::scale(const long& factor) const;
template qMat<float> qMat<float>::scale(const float& factor) const;
template qMat<float> qMat<float>::scale(const double& factor) const;
template qMat<float> qMat<float>::multiply(const qMat<int>& factor) const;
template qMat<float> qMat<float>::multiply(const qMat<long>& factor) const;
template qMat<float> qMat<float>::multiply(const qMat<float>& factor) const;
template qMat<float> qMat<float>::multiply(const qMat<double>& factor) const;
template qMat<float>& qMat<float>::operator=(const qMat<int>&);
template qMat<float>& qMat<float>::operator=(const qMat<long>&);
template qMat<float>& qMat<float>::operator=(const qMat<float>&);
template qMat<float>& qMat<float>::operator=(const qMat<double>&);
template qVec<float>& qMat<float>::operator[](int index);         // Non-const version
template const qVec<float>& qMat<float>::operator[](int index) const; // Const version

template qMat<double>::qMat(int n, int m);
template qMat<double>::qMat(std::initializer_list<std::initializer_list<double>> values);
template qMat<double>::qMat(qMat<int> const &src);
template qMat<double>::qMat(qMat<long> const &src);
template qMat<double>::qMat(qMat<float> const &src);
template qMat<double>::qMat(qMat<double> const &src);
template qMat<double>::~qMat();
template int qMat<double>::getnSize() const;
template int qMat<double>::getmSize() const;
template const qVec<double>& qMat<double>::get(int ind) const;
template double qMat<double>::at(int n, int m) const;
template void qMat<double>::set(int ind, const qVec<double>& vector);
template void qMat<double>::setAt(int n, int m, const double value);
template double* qMat<double>::toArray();
template qMat<double> qMat<double>::transpose() const;
template qMat<double> qMat<double>::add(const qMat<int>& addend) const;
template qMat<double> qMat<double>::add(const qMat<long>& addend) const;
template qMat<double> qMat<double>::add(const qMat<float>& addend) const;
template qMat<double> qMat<double>::add(const qMat<double>& addend) const;
template qMat<double> qMat<double>::scale(const int& factor) const;
template qMat<double> qMat<double>::scale(const long& factor) const;
template qMat<double> qMat<double>::scale(const float& factor) const;
template qMat<double> qMat<double>::scale(const double& factor) const;
template qMat<double> qMat<double>::multiply(const qMat<int>& factor) const;
template qMat<double> qMat<double>::multiply(const qMat<long>& factor) const;
template qMat<double> qMat<double>::multiply(const qMat<float>& factor) const;
template qMat<double> qMat<double>::multiply(const qMat<double>& factor) const;
template qMat<double>& qMat<double>::operator=(const qMat<int>&);
template qMat<double>& qMat<double>::operator=(const qMat<long>&);
template qMat<double>& qMat<double>::operator=(const qMat<float>&);
template qMat<double>& qMat<double>::operator=(const qMat<double>&);
template qVec<double>& qMat<double>::operator[](int index);         // Non-const version
template const qVec<double>& qMat<double>::operator[](int index) const; // Const version

/**
 * @brief Constructor that initializes a matrix with n rows and m columns.
 * 
 * Allocates memory for an array of `qVec<T>` pointers, each representing a row.
 * Each row is initialized as a vector of size `m`. Each value is initialized to 0.
 * 
 * @tparam T the type of the elements in the new matrix
 * @param n The number of rows.
 * @param m The number of columns.
 */
template<typename T> 
qMat<T>::qMat(int n, int m) {
    this->nSize = n;
    this->mSize = m;
    this->rows = new qVec<T>*[n];
    for(int i = 0; i < n; i++) {
        rows[i] = new qVec<T>(m);
    }
}
/**
 * @brief Constructor that initializes a matrix from a 2D initializer list.
 * 
 * Allocates memory for rows and columns based on the dimensions of the initializer list.
 * Copies values from the initializer list into the corresponding positions in the matrix.
 * 
 * @tparam T the type of the elements in the new matrix
 * @param values A 2D initializer list containing the matrix elements.
 */
template<typename T>
qMat<T>::qMat(std::initializer_list<std::initializer_list<T>> values) {
    this->nSize = values.size();
    this->mSize = values.begin()->size();
    this->rows = new qVec<T>*[this->nSize];
    int i = 0;
    for(auto a : values) {
        T arr[a.size()];
        std::copy(a.begin(), a.end(), arr);
        rows[i] = new qVec<T>(mSize, arr);
        i++;
    }
}
/**
 * @brief Copy constructor that initializes a matrix from another matrix of a potentially different type.
 * 
 * Performs a deep copy of the matrix, allocating new memory for each row.
 * 
 * @tparam T the type of the elements in the new matrix
 * @tparam H The type of the elements in the source matrix.
 * @param src A constant reference to the source matrix.
 */
template<typename T>
template<typename H>
qMat<T>::qMat(qMat<H> const &src) {
    this->nSize = src.getnSize();
    this->mSize = src.getmSize();
    this->rows = new qVec<T>*[nSize];
    for(int i = 0; i < nSize; i++) {
        rows[i] = new qVec<T>(src.get(i));
    }
}
/**
 * @brief Copy constructor that initializes a matrix from another matrix of the same type.
 * 
 * Performs a deep copy of the matrix, allocating new memory for each row.
 * 
 * @tparam T the type of the elements in the new matrix
 * @param src A constant reference to the source matrix.
 */
#ifndef __linux__
template<typename T>
qMat<T>::qMat(qMat<T> const &src) {
    this->nSize = src.getnSize();
    this->mSize = src.getmSize();
    this->rows = new qVec<T>*[nSize];
    for(int i = 0; i < nSize; i++) {
        rows[i] = new qVec<T>(src.get(i));
    }
}
#endif
/**
 * @brief Destructor that cleans up the dynamically allocated memory.
 * 
 * Frees the memory allocated for each row and the array of row pointers.
 */
template<typename T>
qMat<T>::~qMat() {
    for(int i = 0; i < nSize; i++) {
        delete(rows[i]);
    }
    delete[] this->rows;
}
/**
 * @brief Returns the number of rows in the matrix.
 * 
 * @return The number of rows (nSize).
 */
template<typename T>
int qMat<T>::getnSize() const {
    return nSize;
}
/**
 * @brief Returns the number of columns in the matrix.
 * 
 * @return The number of columns (mSize).
 */
template <typename T>
int qMat<T>::getmSize() const {
    return mSize;
}

/**
 * @brief Returns a constant reference to the row vector at the specified index.
 * 
 * If the index is out of range, throws an out_of_range exception.
 * 
 * @tparam T the type of the elements in the matrix
 * @param ind The index of the row.
 * @return A constant reference to the vector at the specified index.
 */
template<typename T>
const qVec<T>& qMat<T>::get(int ind) const {
    if (ind >= 0 && ind < this->nSize) {
        return *this->rows[ind]; // Return a const reference to the vector at the specified index
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
/**
 * @brief Returns the value at the specified row and column.
 * 
 * @tparam T the type of the elements in the matrix
 * @param n The row index.
 * @param m The column index.
 * @return The value at the specified row and column.
 */
template<typename T>
T qMat<T>::at(int n, int m) const {
    return(get(n).getValue(m));
}
/**
 * @brief Sets the specified row to the given vector.
 * 
 * If the vector is shorter than the row size, the remaining elements are set to 0.
 * If the index is out of range, throws an out_of_range exception.
 * 
 * @tparam T the type of the elements in the matrix
 * @param ind The index of the row to modify.
 * @param vector The vector to set as the new row.
 */
template<typename T>
void qMat<T>::set( int ind, const qVec<T>& vector) {
    if (ind >= 0 && ind < this->nSize) {
        for(int i = 0; i < this->mSize; i++) {
            if(i < vector.getSize()) {
                this->rows[ind]->setValue(i, vector.getValue(i));
            } else {
                this->rows[ind]->setValue(i, 0);
            }
        }
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
/**
 * @brief Sets the value at the specified row and column.
 * 
 * If the row index is out of range, throws an out_of_range exception.
 * 
 * @tparam T the type of the elements in the matrix
 * @param n The row index.
 * @param m The column index.
 * @param value The value to set.
 */
template<typename T> 
void qMat<T>::setAt(int n, int m, const T value) {
    if (n >= 0 && n < this->nSize) {
        this->rows[n]->setValue(m, value);
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
/**
 * @brief Returns the transpose of the matrix (compile-time constant version).
 * 
 * The transpose operation swaps the rows and columns of the matrix.
 * 
 * @return A new matrix that is the transpose of the current matrix.
 */
template<typename T>
qMat<T> qMat<T>::transpose() const{
    qMat<T> result(this->getmSize(), this->getnSize());
    for(int i = 0; i < mSize; i++) {
        qVec<T> row(nSize);
        for(int j = 0; j < nSize; j++) {
            row.setValue(j, this->get(j).getValue(i));
        }
        result.set(i, row);
    }
    return result;
}
/**
 * @brief Returns a pointer of an array composed of the matrixes values
 * 
 * @returns A pointer to the array of the matrixes values
 */
template<typename T>
T* qMat<T>::toArray() {
    T* values = new T[nSize*mSize];
    T* dest = values;
    for(int i = 0; i < nSize; i++) {
        std::copy(rows[i]->valueOf(), rows[i]->valueOf() + mSize, dest);
        dest += mSize;
    }
    return values;
}
/**
 * @brief Adds another matrix of potentially different type to this matrix.
 * 
 * The two matrices must have the same dimensions for the addition to work.
 * 
 * @tparam T the type of the elements in the matrix
 * @tparam H The type of the elements in the matrix being added.
 * @param addend The matrix to add.
 * @return A new matrix representing the sum of the two matrices.
 * @throws std::invalid_argument if the dimensions of the matrices do not match.
 */
template<typename T>
template<typename H>
qMat<T> qMat<T>::add(const qMat<H>& addend) const {
    // Check dimensions
    if (this->getnSize() != addend.getnSize() || this->getmSize() != addend.getmSize()) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");
    }

    qMat<T> result(this->getnSize(), this->getmSize());

    for(int i = 0; i < this->nSize; i++) {
        qVec<T> row = this->get(i).add(addend.get(i));
        result.set(i, row);
    }

    return result;
}

/**
 * @brief Scales the matrix by a scalar factor of potentially different type.
 * 
 * Multiplies each element of the matrix by the given factor.
 * 
 * @tparam T the type of the elements in the matrix
 * @tparam H The type of the scalar factor.
 * @param factor The scalar factor to multiply the matrix by.
 * @return A new matrix with each element scaled by the factor.
 */
template<typename T>
template<typename H>
qMat<T> qMat<T>::scale(const H& factor) const {
    qMat<T> result(this->nSize, this->mSize);
    for(int i = 0; i < this->nSize; i++) {
        result.set(i, this->get(i).scale(factor));
    }
    return result;
}
/**
 * @brief Multiplies this matrix with another matrix of potentially different type.
 * 
 * The number of columns in this matrix must match the number of rows in the factor matrix.
 * 
 * @tparam T the type of the elements in the matrix
 * @tparam H The type of the elements in the factor matrix.
 * @param factor The matrix to multiply this matrix by.
 * @return A new matrix that is the product of the two matrices.
 * @throws std::invalid_argument if the dimensions of the matrices are not compatible.
 */
template <typename T> 
template <typename H>
qMat<T> qMat<T>::multiply(const qMat<H>& factor) const {
    if(this->mSize != factor.getnSize()) {
        throw std::invalid_argument("Matrices must have compatible dimensions!");
    }
    qMat<H> tFactor(factor.transpose());
    qMat<T> result(this->getnSize(), factor.getmSize());
    for(int i = 0; i < result.getnSize(); i++) {
        for(int j = 0; j < result.getmSize(); j++) {
            result[i][j] = this->get(i).dot(tFactor.get(j));
        }
    }
    return result;
}
/**
 * @brief Subscript operator that returns a reference to the row vector at the specified index (non-const version).
 * 
 * If the index is out of range, throws an out_of_range exception.
 * 
 * @tparam T the type of the elements in the matrix
 * @param index The index of the row.
 * @return A reference to the vector at the specified index.
 */
template <typename T>
qVec<T>& qMat<T>::operator[](int index) {
    if (index < 0 || index >= nSize) {
        throw std::out_of_range("Index is out of bounds");
    }
    return *rows[index]; // Return a reference to the row
}

/**
 * @brief Subscript operator that returns a reference to the row vector at the specified index (const version).
 * 
 * If the index is out of range, throws an out_of_range exception.
 * 
 * @tparam T the type of the elements in the matrix
 * @param index The index of the row.
 * @return A reference to the vector at the specified index.
 */
template <typename T>
const qVec<T>& qMat<T>::operator[](int index) const {
    if (index < 0 || index >= nSize) {
        throw std::out_of_range("Index is out of bounds");
    }
    return *rows[index]; // Return a const reference to the row
}
#endif