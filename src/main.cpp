#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    //TODO: Test qVec
    qVec<int> testVec = qVec<int>({2, 3, 4});
    qVec<double> testVec2 = qVec<double>({5.0, 6.0, 6.0});
    //qVec<int> outVec = testVec.dot(testVec2);
    cout << testVec.cross(testVec2) << endl;
    return 0;
}