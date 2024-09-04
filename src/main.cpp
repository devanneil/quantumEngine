#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    //TODO: Test qVec
    qVec<int> testVec = qVec<int>({2, 3, 4});
    qVec<int> testVec2 = qVec<int>({5, 6, 6});
    qVec<int> outVec = testVec * 3;
    cout << outVec << endl;
    return 0;
}