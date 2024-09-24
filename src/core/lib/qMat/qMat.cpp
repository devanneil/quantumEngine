#include "qMat.h"

template qMat<int>::qMat(int n, int m);
template qMat<int>::qMat(std::initializer_list<std::initializer_list<int>> values);
template qMat<int>::~qMat();
template int qMat<int>::getnSize() const;
template int qMat<int>::getmSize() const;
template qVec<int> qMat<int>::get(int ind);
template int qMat<int>::at(int n, int m);
template void qMat<int>::set(qVec<int>& vector, int ind);
template void qMat<int>::setAt(int value, int n, int m);
//TODO: Fill in these functions, and build row operations function (no idea how tho)
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
qMat<T>::~qMat() {
    delete(this->rows);
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
qVec<T> qMat<T>::get(int ind) {
    if (ind >= 0 && ind < this->nSize) {
        return *this->rows[ind]; // Return the vector at the specified index
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}

template<typename T>
T qMat<T>::at(int n, int m) {
    return(get(n).getValue(m));
}
template<typename T>
void qMat<T>::set(qVec<T>& vector, int ind) {
    if (ind >= 0 && ind < this->nSize) {
        this->rows[ind] = &vector;
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
template<typename T> 
void qMat<T>::setAt(T value, int n, int m) {
    if (n >= 0 && n < this->nSize) {
        this->rows[n]->setValue(value, m);
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}