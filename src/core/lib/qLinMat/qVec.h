#ifndef QVEC_H
#define QVEC_H

#include <stdexcept>
#include <ostream>
#include <initializer_list>
#include <math.h>
/**
 * @brief Vector for storing numeric values and performing operations.
 * 
 * The `qVec` class stores numeric types and supports various vector operations. 
 * It is designed to be used in conjunction with the `qMat` class for matrix row operations.
 * 
 * @tparam T The type stored in the vector (e.g., int, float, double).
 */
template <typename T>
class qVec {
    private:
        T* values;
        int size;

        void clear();
    public:
        qVec() {values = nullptr; size = 0;};
        qVec(int size);
        qVec(int size, T values[]);
        qVec(std::initializer_list<T> values);
        template<typename H>
        qVec(const qVec<H>& src);
#ifndef __linux__
        qVec(const qVec<T> &src);
#endif
        ~qVec();

        int getSize() const;
        T* valueOf();

        T getValue(int ind) const;
        void setValue(int ind, const T& value);

        float magnitude() const;
        qVec<T> norm() const;

        template<typename H> T dot(const qVec<H>& mult) const;
        template<typename H> qVec<T> cross(const qVec<H>& mult) const;
        template<typename H> qVec<T> scale(const H& scalar) const;
        template<typename H> qVec<T> add(const qVec<H>& addend) const;
        template<typename H> qVec<T> sub(const qVec<H>& subtrahend) const {return this->add(subtrahend.scale(-1));};
        template<typename H> qVec<T> operator*(const H& mult) const {return this->scale(mult);};
        template<typename H> qVec<T> operator+(const qVec<H>& addend) const {return this->add(addend);};
        template<typename H> qVec<T> operator-(const qVec<H>& subtrahend) const {return this->add(subtrahend.scale(-1));};
        template<typename H> qVec<T> operator/(const H divident) const {return this->scale((float)(1.0 / divident));};
        template<typename H> qVec<T>& operator=(const qVec<H>& src){
            if ((void*)this != &src) {  // Avoid self-assignment by checking if the object is being assigned to itself
                delete[] values; // Free the currently allocated memory to prevent memory leaks
                values = nullptr;
                size = src.size; // Copy the size of the source vector
                values = new T[size]; // Allocate new memory for the values
                for (int i = 0; i < size; ++i) {
                    values[i] = src.values[i]; // Copy each element from the source vector to the current vector
                }
            }
            return *this; // Return the current object to allow chaining of assignment operations
        };
        qVec<T>& operator=(const qVec<T>& src) {
            if ((void*)this != &src) {  // Avoid self-assignment by checking if the object is being assigned to itself
                delete[] values; // Free the currently allocated memory to prevent memory leaks
                values = nullptr;
                size = src.size; // Copy the size of the source vector
                values = new T[size]; // Allocate new memory for the values
                for (int i = 0; i < size; ++i) {
                    values[i] = src.values[i]; // Copy each element from the source vector to the current vector
                }
            }
            return *this; // Return the current object to allow chaining of assignment operations
        };
        template<typename H>bool operator==(const qVec<H>& other) const;
        T& operator[](const size_t index ) const { if(index >= 0 && index < size) return values[index]; else throw std::out_of_range("Index is out of bounds");};
        friend std::ostream& operator<<(std::ostream& os, const qVec<T>& vec) {
            os << "["; // Start of vector representation
            for (size_t i = 0; i < vec.getSize(); ++i) {
                os << vec[i]; // Output each value
                if (i < vec.getSize() - 1) os << ", "; // Separate values with a comma, except the last one
            }
            os << "]"; // End of vector representation
            return os; // Return the stream object for chaining
        };
};

#endif