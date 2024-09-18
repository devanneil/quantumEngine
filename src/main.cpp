#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    qMat<int> qMatTest = {{1, 2, 3, 0}, {4, 5, 6, 0}, {7, 8, 9, 0}};
    cout << qMatTest << endl;
    return 0;
}

//NOTES
/*
*
*/