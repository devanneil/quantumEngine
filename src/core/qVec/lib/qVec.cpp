#include "qVec.h"
template <class T>
qVec<T>::qVec(int size, T values[], int tSize) {
    if(size == tSize) this->values = values;
    else {
        int ind = 0;
        for(int i = 0; i < tSize; i++) {
            this->ind = i;
            this->values[ind] = values[ind];
        }
        while(ind < size) {
            this->values[ind] = 0;
        }
    }
}
template <class T>
qVec<T>::qVec(int size) {
    this->size = size;
    this->values = new T[size];
}
template <class T>
qVec<T>::~qVec() {
    delete(this->values);
}
template <class T>
int qVec<T>::getSize() {
    return size;
}
template <class T>
T* qVec<T>::valueOf() {
    return this->values;
}