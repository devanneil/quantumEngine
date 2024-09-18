#include <initializer_list>
#include <exception>
#include "../qVec/qVec.h"
#ifndef Q_MAT
#define Q_Mat

template<typename T>
class qMat {
    private:
    qVec<T>** rows;
    int nSize;
    int mSize;

    public:
    qMat(int n, int m);
    qMat(std::initializer_list<std::initializer_list<T>> values);
    ~qMat();

    int getnSize() const;
    int getmSize() const;
    qVec<T> get(int ind);

     friend std::ostream& operator<<(std::ostream& os, const qMat<T>& matrix) {
            os << "[ " << matrix.getnSize() << " " << matrix.getmSize() << " ]\n"; // Start of vector representation
            for (size_t i = 0; i < matrix.getnSize(); ++i) {
                qVec<T> vector = *matrix.rows[i];
                os << "{ ";
                for(size_t j = 0; j < matrix.getmSize(); j++){
                    os << vector[j] << " ";
                }
                os <<  "}";
                if(i < matrix.getnSize() - 1) os << "\n";
            }
            return os; // Return the stream object for chaining
        };
};


#endif