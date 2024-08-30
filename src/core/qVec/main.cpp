#include<iostream>
#include"lib/qVec.h"

using namespace std;
int main() {
    qVec<int> vectorTest = qVec<int>(10);
    cout << vectorTest.getSize() << endl;
    return 0;
}