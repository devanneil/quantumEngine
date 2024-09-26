#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"
using namespace std;

int main() {
    qMat<int> qMat_ = {{1, 2, 3}, {4, 5, 6}};
    qMat<int> qMat_2 = qMat<int>(1, 1);
    cout << "Before assignment" << endl;
    qMat_2 = qMat_;
    cout << &qMat_ << endl;
    cout << &qMat_2 << endl;
    return 0;
}

//NOTES
/*
*
*/