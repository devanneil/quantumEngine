#ifndef QVEC_H
#define QVEC_H

#include <stdexcept>
#include <ostream>
#include <initializer_list>

template <typename T>
class qVec {
    private:
        T* values;
        int size;

        void clear();
    public:
        qVec(int size, T values[], int tSize);
        qVec(int size);
        qVec(std::initializer_list<T> values);
        qVec<T>(const qVec<T>& src);
        ~qVec();

        int getSize() const;
        T* valueOf();

        T getValue(int ind) const;
        void setValue(int ind, const T& value);

        template<typename H> T dot(const qVec<H>& mult) const;
        template<typename H> qVec<T> cross(const qVec<H>& mult) const;
        
        template<typename H> qVec<T> operator*(const H mult) const;

        template<typename H>qVec<T>& operator=(const qVec<H>& src);
        template<typename H>qVec<T>& operator=(qVec<H>&& src) noexcept;
        template<typename H>bool operator==(const qVec<H>& other) const;
        friend std::ostream& operator<<(std::ostream& os, const qVec<T>& vec) {
            os << "["; // Start of vector representation
            for (size_t i = 0; i < vec.getSize(); ++i) {
                os << vec[i]; // Output each value
                if (i < vec.getSize() - 1) os << ", "; // Separate values with a comma, except the last one
            }
            os << "]"; // End of vector representation
            return os; // Return the stream object for chaining
        };
        T& operator[](size_t index) { return values[index]; }
        const T& operator[](size_t index) const { return values[index]; }
};

#endif