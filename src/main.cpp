#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    qVec<float> row1 = qVec<float>{1, 1, 1};
    qVec<float> row2 = qVec<float>{0, 0, 0.0000000000000000001};
    cout << row1.norm() << endl;
    return 0;
}

//NOTES
/*
*
*/