#ifndef QVEC_H
#define QVEC_H

#include <stdexcept>
#include <ostream>
#include <initializer_list>
#include <iterator>
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
        qVec(qVec<T>&& src);
        template<typename H>
        qVec(const qVec<H>& src);
#ifndef __linux__
        qVec(const qVec<T> &src);
#endif
        ~qVec();

        int getSize() const;
        template<typename H>
        bool equals(const qVec<H> &src) const;
        template <typename H>
        void copy(const qVec<H> &src);

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
        template<typename H> qVec<T>& operator=(const qVec<H>& src);
        qVec<T>& operator=(const qVec<T>& src);
        template<typename H>bool operator==(const qVec<H>& other) const;
        template<typename H>bool operator!=(const qVec<H>& other) const;
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
        
        struct Iterator 
        {
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = T;
            using pointer           = T*;  // or also value_type*
            using reference         = T&;  // or also value_type&

            Iterator(pointer ptr) : values_ptr(ptr) {}

            reference operator*() const { return *values_ptr; }
            pointer operator->() { return values_ptr; }

            // Prefix increment
            Iterator& operator++() { values_ptr++; return *this; }  
            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.values_ptr == b.values_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.values_ptr != b.values_ptr; };     
            private:
            pointer values_ptr;
        };
        Iterator begin() { return Iterator(&values[0]); }
        Iterator end()   { return Iterator(&values[size]); }
};

#endif