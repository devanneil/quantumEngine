#include "qMat.h"

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
template void qMat<int>::set(const qVec<int>& vector, int ind);
template void qMat<int>::setAt(const int value, int n, int m);
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
template<typename H>
qMat<T>::qMat(qMat<H> const &src) {
    this->nSize = src.getnSize();
    this->mSize = src.getmSize();
    this->rows = new qVec<T>*[nSize];
    for(int i = 0; i < nSize; i++) {
        rows[i] = new qVec<T>(src.get(i));
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
const qVec<T>& qMat<T>::get(int ind) const {
    if (ind >= 0 && ind < this->nSize) {
        return *this->rows[ind]; // Return a const reference to the vector at the specified index
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
#ifdef CONSTTRANSPOSE
constexpr template<typename T>
qMat<T> qMat<T>::transpose() const{
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
#else
template<typename T>
qMat<T> qMat<T>::transpose() const{
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
#endif
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

template <typename T>
template <typename H>
qMat<T>& qMat<T>::operator=(const qMat<H>& src) {
    if (this != static_cast<const void*>(&src)) {
        // Deallocate existing memory
        for (int i = 0; i < nSize; i++) {
            delete this->rows[i];
        }
        delete[] this->rows;

        // Allocate new memory and deep copy
        this->nSize = src.getnSize();
        this->mSize = src.getmSize();
        this->rows = new qVec<T>*[nSize];
        for (int i = 0; i < nSize; i++) {
            this->rows[i] = new qVec<T>(src.get(i)); // Using the copy constructor of qVec
        }
    }
    return *this;
}

template <typename T>
qMat<T>& qMat<T>::operator=(const qMat<T>& src) {
    if (this != &src) {
        // Deallocate existing memory
        for (int i = 0; i < nSize; i++) {
            delete this->rows[i];
        }
        delete[] this->rows;

        // Allocate new memory and deep copy
        this->nSize = src.getnSize();
        this->mSize = src.getmSize();
        this->rows = new qVec<T>*[nSize];
        for (int i = 0; i < nSize; i++) {
            this->rows[i] = new qVec<T>(src.get(i)); // Using the copy constructor of qVec
        }
    }
    return *this;
}

template<typename T>
template<typename H>
bool qMat<T>::operator==(const qMat<H>& matrix) const {
        if(this->nSize != matrix.nSize) return false;
    if(this->mSize != matrix.mSize) return false;
    for(int i = 0; i < this->nSize; i++) {
        if(this->rows[i] != matrix->rows[i]) return false;
    }
    return true;
}

template <typename T>
qVec<T>& qMat<T>::operator[](int index) {
    if (index < 0 || index >= nSize) {
        throw std::out_of_range("Index is out of bounds");
    }
    return *rows[index]; // Return a reference to the row
}

template <typename T>
const qVec<T>& qMat<T>::operator[](int index) const {
    if (index < 0 || index >= nSize) {
        throw std::out_of_range("Index is out of bounds");
    }
    return *rows[index]; // Return a const reference to the row
}
