#include <initializer_list>
#include <exception>
#include <qVec.h>
#ifndef Q_MAT
#define Q_MAT

/**
 * @brief Matrix class for storing and manipulating 2D arrays of numeric values.
 * 
 * The `qMat` class represents a matrix and provides various operations such as addition, 
 * subtraction, scaling, and multiplication. It utilizes the `qVec` class for row 
 * operations and maintains a dynamic array of row vectors.
 * 
 * @tparam T The type of elements stored in the matrix. Types are int, float, double, and long
 */
template<typename T>
class qMat {
    private:
    qVec<T>** rows;
    int nSize;
    int mSize;

    public:
    qMat() {rows = nullptr, nSize = 0; mSize = 0;};
    qMat(int n, int m);
    qMat(std::initializer_list<std::initializer_list<T>> values);
    qMat(qMat<T>&& src);
    template<typename H>
    qMat(qMat<H> const &src);
#ifndef __linux__
    qMat(qMat<T> const &src);
#endif
    ~qMat();

    int getnSize() const;
    int getmSize() const;
    const qVec<T>& get(int ind) const;
    T at(int n, int m) const;

    void set(int ind, const qVec<T>& vector);
    void setAt(int n, int m, const T value);
    T* toArray();

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

    template <typename H> qMat<T>& operator=(const qMat<H>& src) {
        if ((void*)this != &src) {
            // Deallocate existing memory
            for (int i = 0; i < nSize; i++) {
                delete this->rows[i];
            }
            delete[] this->rows;

            // Allocate new memory and deep copy
            this->nSize = src.getnSize();
            this->mSize = src.getmSize();
            this->rows = new qVec<T>*[nSize];
            for (int i = 0; i < nSize; i++) {
                this->rows[i] = new qVec<T>(src.get(i)); // Using the copy constructor of qVec
            }
        }
        return *this;
    };
#ifndef __linux__
    qMat<T>& operator=(const qMat<T>& src){
        if ((void*)this != &src) {
            // Deallocate existing memory
            for (int i = 0; i < nSize; i++) {
                delete this->rows[i];
            }
            delete[] this->rows;

            // Allocate new memory and deep copy
            this->nSize = src.getnSize();
            this->mSize = src.getmSize();
            this->rows = new qVec<T>*[nSize];
            for (int i = 0; i < nSize; i++) {
                this->rows[i] = new qVec<T>(src.get(i)); // Using the copy constructor of qVec
            }
        }
        return *this;
    };
#endif
    template <typename H> bool operator==(const qMat<H>& matrix) const {
        if(this->nSize != matrix.nSize) return false;
        if(this->mSize != matrix.mSize) return false;
        for(int i = 0; i < this->nSize; i++) {
            if(this->rows[i] != matrix.rows[i]) return false;
        }
        return true;
    };
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