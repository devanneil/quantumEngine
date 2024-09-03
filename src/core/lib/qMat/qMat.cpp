#include "qMat.h"
#include "../qVec/qVec.h"

template qMat<int>::qMat(int n, int m, qVec<int>[], int arrSize);
template qMat<int>::qMat(int n, int m);
template qMat<int>::~qMat();


template<typename T> 
qMat<T>::qMat(int n, int m, qVec<T>[], int arrSize) {

}

template<typename T>
qMat<T>::qMat(int n, int m) {

}

template<typename T>
qMat<T>::~qMat() {
    
}