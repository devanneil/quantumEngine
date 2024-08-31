#include<iostream>
#include"core/lib/qVec/qVec.h"

using namespace std;
int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    qVec<int> vectorTest = qVec<int>(10, values, 10);
    cout << vectorTest.getSize() << endl;
    int* newValue = vectorTest.valueOf();
    int newSize = vectorTest.getSize();
    vectorTest.setValue(5, 11);
    for(int i = 0; i < newSize; i++) {
        cout << newValue[i] << " ";
    }
    cout << endl;
    return 0;
}