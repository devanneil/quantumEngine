#include<iostream>
#include"core/lib/qVec/qVec.h"
#include"core/lib/qMat/qMat.h"

using namespace std;
int main() {
    qVec<int> row1 = qVec<int>{1, 2, 3};
    qVec<int> row2 = qVec<int>{4, 5, 6};
    qVec<int> rows[] = {row1, row2};
    qMat<int> mat = qMat<int>(3, 2, rows, 2);
    return 0;
}