#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    qMat<int> qMat = {{1, 2, 3}, {4, 5, 6}};
    qVec<int> qVec = {7, 8, 9};
    qMat.set(qVec, 1);
    qMat.setAt(5, 1, 1);
    cout << qMat + qMat << endl;
    return 0;
}

//NOTES
/*
*
*/