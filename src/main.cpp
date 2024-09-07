#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    qVec<float> row1 = qVec<float>{311.7691, 180, 0};
    qVec<float> row2 = qVec<float>{0.6121, 0.2121, 0};
    cout << row1.cross(row2).scale((float)-1) << endl;
    return 0;
}

//NOTES
/*
cannot use += on qVec, will need to be implemented
qVec needs .norm() and .magnitude()
.cross() can return the lovely -0
.scale() returns a vector of the wrong type
*/