#include <initializer_list>
#include <exception>
#include "../qVec/qVec.h"
#ifndef Q_MAT
#define Q_MAT

template<typename T>
class qMat {
    private:
    qVec<T>** rows;
    int nSize;
    int mSize;

    public:
    qMat(int n, int m);
    qMat(std::initializer_list<std::initializer_list<T>> values);
    template<typename H>
    qMat(qMat<H> const &src);
    qMat(qMat<T> const &src);
    ~qMat();

    int getnSize() const;
    int getmSize() const;
    const qVec<T>& get(int ind) const;
    T at(int n, int m) const;

    void set(const qVec<T>& vector, int ind);
    void setAt(const T value, int n, int m);

    qMat<T> transpose() const;
    template <typename H> qMat<T> add(const qMat<H>& addend) const;
    template <typename H> qMat<T> sub(const qMat<H>& subtrahend) const {return this->add(subtrahend.scale(-1));};
    template <typename H> qMat<T> scale (const H& factor) const;
    template <typename H> qMat<T> multiply(const qMat<H>& factor) const;
    template <typename H> qMat<T> operator+(const qMat<H>& matrix) const {return this->add(matrix);};
    template <typename H> qMat<T> operator-(const qMat<H>& matrix) const {return this->add(matrix.scale(-1));};
    template <typename H> qMat<T> operator*(const qMat<H>& matrix) const {return this->multiply(matrix);};
    template <typename H> qMat<T> operator*(const H& factor) const {return this->scale(factor);};
    template <typename H> qMat<T> operator/(const H& divident) const {return this->scale((float)(1.0 / divident));};

    template <typename H> qMat<T>& operator=(const qMat<H>& src);
    qMat<T>& operator=(const qMat<T>& src);
    template <typename H> bool operator==(const qMat<H>& matrix) const;
    qVec<T>& operator[](int index);         // Non-const version
    const qVec<T>& operator[](int index) const; // Const version

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