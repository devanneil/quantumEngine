#include<iostream>
#include"core/lib/qMat/qMat.h"
using namespace std;

int main() {
    qMat<int> qMat_ = {{1, 2, 3}, {4, 5, 6}};
    qMat<int> qMat_2 = {{7, 8}, {9, 10}, {11, 12}};
    qVec<int> qVecTest = {1, 2, 3};
    cout << qMat_ << endl;
    cout << qMat_2 << endl;
    cout << qMat_.multiply(qMat_2) << endl;
    return 0;
}

//NOTES
/*
*
*/