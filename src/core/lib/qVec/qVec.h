#ifndef QVEC_H
#define QVEC_H

#include <stdexcept>
#include <ostream>

template <class T>
class qVec {
    private:
        T* values;
        int size;

        void clear();
    public:
        qVec(int size, T values[], int tSize);
        qVec(int size);
        qVec(const qVec<T>& src);
        ~qVec();

        int getSize() const;
        T* valueOf();

        T getValue(int ind) const;
        void setValue(int ind, const T& value);

        qVec<T>& operator=(const qVec<T>& src);
        qVec<T>& operator=(qVec<T>&& src) noexcept;
        bool operator==(const qVec<T>& other) const;
        friend std::ostream& operator<<(std::ostream& os, const qVec<T>& vec);
};

#endif