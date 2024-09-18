#include "qMat.h"

template qMat<int>::qMat(int n, int m);
template qMat<int>::qMat(std::initializer_list<std::initializer_list<int>> values);
template qMat<int>::~qMat();
template int qMat<int>::getnSize() const;
template int qMat<int>::getmSize() const;
template qVec<int> qMat<int>::get(int ind);
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
        rows[i] = new qVec<T>(mSize, arr, a.size());
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