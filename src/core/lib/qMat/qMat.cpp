#include "qMat.h"

template qMat<int>::qMat(int n, int m);
template qMat<int>::qMat(std::initializer_list<std::initializer_list<int>> values);
template qMat<int>::qMat(qMat<int> const &src);
template qMat<int>::~qMat();
template int qMat<int>::getnSize() const;
template int qMat<int>::getmSize() const;
template qVec<int>& qMat<int>::get(int ind) const;
template int qMat<int>::at(int n, int m) const;
template void qMat<int>::set(const qVec<int>& vector, int ind);
template void qMat<int>::setAt(const int value, int n, int m);
template qMat<int> qMat<int>::transpose();
template qMat<int> qMat<int>::add(const qMat<int>& addend) const;
template qMat<int> qMat<int>::add(const qMat<long>& addend) const;
template qMat<int> qMat<int>::add(const qMat<float>& addend) const;
template qMat<int> qMat<int>::add(const qMat<double>& addend) const;
template qMat<int> qMat<int>::scale(const int& factor) const;
template qMat<int> qMat<int>::scale(const long& factor) const;
template qMat<int> qMat<int>::scale(const float& factor) const;
template qMat<int> qMat<int>::scale(const double& factor) const;
template qMat<int>& qMat<int>::operator=(const qMat<int>&);

template<typename T> 
qMat<T>::qMat(int n, int m) {
    this->nSize = n;
    this->mSize = m;
    this->rows = new qVec<T>*[n];
    for(int i = 0; i < n; i++) {
        rows[i] = new qVec<T>(m);
    }
}
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
template<typename T>
qMat<T>::qMat(qMat<T> const &src) {
    this->nSize = src.getnSize();
    this->mSize = src.getmSize();
    this->rows = new qVec<T>*[nSize];
    for(int i = 0; i < nSize; i++) {
        rows[i] = new qVec<T>(src.get(i));
    }
}
template<typename T>
qMat<T>::~qMat() {
    for(int i = 0; i < nSize; i++) {
        delete(rows[i]);
    }
    delete[] this->rows;
}

template<typename T>
int qMat<T>::getnSize() const {
    return nSize;
}
template <typename T>
int qMat<T>::getmSize() const {
    return mSize;
}

template<typename T>
qVec<T>& qMat<T>::get(int ind) const {
    if (ind >= 0 && ind < this->nSize) {
        return *this->rows[ind]; // Return the vector at the specified index
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}

template<typename T>
T qMat<T>::at(int n, int m) const {
    return(get(n).getValue(m));
}
template<typename T>
void qMat<T>::set(const qVec<T>& vector, int ind) {
    if (ind >= 0 && ind < this->nSize) {
        for(int i = 0; i < this->mSize; i++) {
            if(i < vector.getSize()) {
                this->rows[ind]->setValue(vector.getValue(i), i);
            } else {
                this->rows[ind]->setValue(0, i);
            }
        }
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
template<typename T> 
void qMat<T>::setAt(const T value, int n, int m) {
    if (n >= 0 && n < this->nSize) {
        this->rows[n]->setValue(value, m);
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
template<typename T>
qMat<T> qMat<T>::transpose() {
    qMat<T> result(this->getmSize(), this->getnSize());
    for(int i = 0; i < mSize; i++) {
        qVec<T> row(nSize);
        for(int j = 0; j < nSize; j++) {
            row.setValue(this->get(j).getValue(i), j);
        }
        result.set(row, i);
    }
    return result;
}
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
        result.set(row, i);
    }

    return result;
}

template<typename T>
template<typename H>
qMat<T> qMat<T>::scale(const H& factor) const {
    qMat<T> result(this->nSize, this->mSize);
    for(int i = 0; i < this->nSize; i++) {
        result.set(this->get(i).scale(factor), i);
    }
    return result;
}

template <typename T>
template <typename H>
qMat<T>& qMat<T>::operator=(const qMat<H>& src) {
    if(this != &src) {
        // Avoid self-assignment
        // Step 1: Deallocate existing memory
        for (int i = 0; i < nSize; i++) {
            delete this->rows[i];  // Delete each qVec object
        }
        delete[] this->rows;  // Delete the array of row pointers
        // Step 2: Allocate new memory and deep copy
        this->nSize = src.getnSize();
        this->mSize = src.getmSize();
        this->rows = new qVec<T>*[nSize];  // Allocate new array for qVec pointers
        for (int i = 0; i < nSize; i++) {
            this->rows[i] = new qVec<T>(src.rows[i]);  // Deep copy each qVec<T> object
        }
    }
    return *this;
}
template<typename T>
qMat<T>& qMat<T>::operator=(const qMat<T>& src) {
    if(this != &src) {
        // Avoid self-assignment
        // Step 1: Deallocate existing memory
        for (int i = 0; i < nSize; i++) {
            delete this->rows[i];  // Delete each qVec object
        }
        delete[] this->rows;  // Delete the array of row pointers
        // Step 2: Allocate new memory and deep copy
        this->nSize = src.getnSize();
        this->mSize = src.getmSize();
        this->rows = new qVec<T>*[nSize];  // Allocate new array for qVec pointers
        for (int i = 0; i < nSize; i++) {
            this->rows[i] = new qVec<T>(src.get(i));  // Deep copy each qVec<T> object
        }
    }
    return *this;
}

template<typename T>
bool qMat<T>::operator==(const qMat<T>& matrix) const {
    if(this->nSize != matrix.nSize) return false;
    if(this->mSize != matrix.mSize) return false;
    for(int i = 0; i < this->nSize; i++) {
        if(this->rows[i] != matrix->rows[i]) return false;
    }
    return true;
}
