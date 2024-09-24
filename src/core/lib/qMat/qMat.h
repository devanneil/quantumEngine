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
    qVec<T> get(int ind) const;
    T at(int n, int m) const;

    void set(const qVec<T>& vector, int ind);
    void setAt(const T value, int n, int m);

    template <typename H> qMat<T> add(const qMat<H>& addend) const;
    //TODO: Make all dis
    // template <typename H> qMat<T> sub(const qMat<H>& subtrahend);
    // template <typename H> qMat<T> scale (const H&);
    // template <typename H> qMat<T> multiply(const qMat<H>& factor);
    template <typename H> qMat<T> operator+(const qMat<H>& matrix) const {return this->add(matrix);};
    // template <tyoename H> qMat<T> operator-(const qMat<H>& matrix) const {return this->add(matrix.scale(-1))};
    // template <typename H> qMat<T> operator*(const qMat<H>& matrix) const {return this->multiply(matrix)};
    // template <typename H> qMat<T> operator*(const H& factor) const {return this->scale(factor)};
    // template <typename H> qMat<T> operator/(const H& quotient) const {return this->scale(1 / quotient)};
    // template <typename H> qMat<T> operator=(const qMat<H>& src);
    // template <typneame H> bool operator==(const qMat<H>& matrix) const;
    // qVec<T> operator[] (const int& ind) const {return get(ind)};
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