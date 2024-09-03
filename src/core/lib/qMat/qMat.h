#include <memory>
#include <../qVec/qVec.h>
#ifndef Q_MAT
#define Q_Mat

template<typename T>
class qMat {
    private:
    std::unique_ptr<qVec<T>> rows;
    int nSize;
    int mSize;

    public:
    qMat(int n, int m, qVec<T>[], int arrSize);
    qMat(int n, int m);
    ~qMat();
};


#endif