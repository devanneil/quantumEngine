#include "qVec.h"
//Include all function declarations with template values

// Integers
template qVec<int>::qVec(int size, int values[], int tSize);
template qVec<int>::qVec(int size);
template qVec<int>::qVec(const qVec<int>& src);
template qVec<int>::qVec(std::initializer_list<int> values);
template qVec<int>::~qVec();
template int qVec<int>::getSize() const;
template int* qVec<int>::valueOf();
template int qVec<int>::getValue(int ind) const;
template void qVec<int>::setValue(int ind, const int& value);
template int qVec<int>::dot(const qVec<int>& mult) const;
template int qVec<int>::dot(const qVec<double>& mult) const;
template int qVec<int>::dot(const qVec<long>& mult) const;
template int qVec<int>::dot(const qVec<float>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<int>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<double>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<long>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<float>& mult) const;
template qVec<int> qVec<int>::scale(const int) const;
template qVec<int> qVec<int>::scale(const double) const;
template qVec<int> qVec<int>::scale(const long) const;
template qVec<int> qVec<int>::scale(const float) const;
template qVec<int> qVec<int>::add(const qVec<int>& addend) const;
template qVec<int> qVec<int>::add(const qVec<double>& addend) const;
template qVec<int> qVec<int>::add(const qVec<long>& addend) const;
template qVec<int> qVec<int>::add(const qVec<float>& addend) const;
template qVec<int> qVec<int>::operator*(const int) const;
template qVec<int> qVec<int>::operator*(const double) const;
template qVec<int> qVec<int>::operator*(const long) const;
template qVec<int> qVec<int>::operator*(const float) const;
template qVec<int> qVec<int>::operator+(const qVec<int>& addend) const;
template qVec<int> qVec<int>::operator+(const qVec<double>& addend) const;
template qVec<int> qVec<int>::operator+(const qVec<long>& addend) const;
template qVec<int> qVec<int>::operator+(const qVec<float>& addend) const;

// Double
template qVec<double>::qVec(int size, double values[], int tSize);
template qVec<double>::qVec(int size);
template qVec<double>::qVec(const qVec<double>& src);
template qVec<double>::qVec(std::initializer_list<double> values);
template qVec<double>::~qVec();
template int qVec<double>::getSize() const;
template double* qVec<double>::valueOf();
template double qVec<double>::getValue(int ind) const;
template void qVec<double>::setValue(int ind, const double& value);
template double qVec<double>::dot(const qVec<int>& mult) const;
template double qVec<double>::dot(const qVec<double>& mult) const;
template double qVec<double>::dot(const qVec<long>& mult) const;
template double qVec<double>::dot(const qVec<float>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<int>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<double>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<long>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<float>& mult) const;
template qVec<double> qVec<double>::scale(const int) const;
template qVec<double> qVec<double>::scale(const double) const;
template qVec<double> qVec<double>::scale(const long) const;
template qVec<double> qVec<double>::scale(const float) const;
template qVec<double> qVec<double>::add(const qVec<int>& addend) const;
template qVec<double> qVec<double>::add(const qVec<double>& addend) const;
template qVec<double> qVec<double>::add(const qVec<long>& addend) const;
template qVec<double> qVec<double>::add(const qVec<float>& addend) const;
template qVec<double> qVec<double>::operator*(const int) const;
template qVec<double> qVec<double>::operator*(const double) const;
template qVec<double> qVec<double>::operator*(const long) const;
template qVec<double> qVec<double>::operator*(const float) const;
template qVec<double> qVec<double>::operator+(const qVec<int>& addend) const;
template qVec<double> qVec<double>::operator+(const qVec<double>& addend) const;
template qVec<double> qVec<double>::operator+(const qVec<long>& addend) const;
template qVec<double> qVec<double>::operator+(const qVec<float>& addend) const;

// Long
template qVec<long>::qVec(int size, long values[], int tSize);
template qVec<long>::qVec(int size);
template qVec<long>::qVec(const qVec<long>& src);
template qVec<long>::qVec(std::initializer_list<long> values);
template qVec<long>::~qVec();
template int qVec<long>::getSize() const;
template long* qVec<long>::valueOf();
template long qVec<long>::getValue(int ind) const;
template void qVec<long>::setValue(int ind, const long& value);
template long qVec<long>::dot(const qVec<int>& mult) const;
template long qVec<long>::dot(const qVec<double>& mult) const;
template long qVec<long>::dot(const qVec<long>& mult) const;
template long qVec<long>::dot(const qVec<float>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<int>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<double>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<long>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<float>& mult) const;
template qVec<long> qVec<long>::scale(const int) const;
template qVec<long> qVec<long>::scale(const double) const;
template qVec<long> qVec<long>::scale(const long) const;
template qVec<long> qVec<long>::scale(const float) const;
template qVec<long> qVec<long>::add(const qVec<int>& addend) const;
template qVec<long> qVec<long>::add(const qVec<double>& addend) const;
template qVec<long> qVec<long>::add(const qVec<long>& addend) const;
template qVec<long> qVec<long>::add(const qVec<float>& addend) const;
template qVec<long> qVec<long>::operator*(const int) const;
template qVec<long> qVec<long>::operator*(const double) const;
template qVec<long> qVec<long>::operator*(const long) const;
template qVec<long> qVec<long>::operator*(const float) const;
template qVec<long> qVec<long>::operator+(const qVec<int>& addend) const;
template qVec<long> qVec<long>::operator+(const qVec<double>& addend) const;
template qVec<long> qVec<long>::operator+(const qVec<long>& addend) const;
template qVec<long> qVec<long>::operator+(const qVec<float>& addend) const;

// Float
template qVec<float>::qVec(int size, float values[], int tSize);
template qVec<float>::qVec(int size);
template qVec<float>::qVec(const qVec<float>& src);
template qVec<float>::qVec(std::initializer_list<float> values);
template qVec<float>::~qVec();
template int qVec<float>::getSize() const;
template float* qVec<float>::valueOf();
template float qVec<float>::getValue(int ind) const;
template void qVec<float>::setValue(int ind, const float& value);
template float qVec<float>::dot(const qVec<int>& mult) const;
template float qVec<float>::dot(const qVec<double>& mult) const;
template float qVec<float>::dot(const qVec<long>& mult) const;
template float qVec<float>::dot(const qVec<float>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<int>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<double>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<long>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<float>& mult) const;
template qVec<float> qVec<float>::scale(const int) const;
template qVec<float> qVec<float>::scale(const double) const;
template qVec<float> qVec<float>::scale(const long) const;
template qVec<float> qVec<float>::scale(const float) const;
template qVec<float> qVec<float>::add(const qVec<int>& addend) const;
template qVec<float> qVec<float>::add(const qVec<double>& addend) const;
template qVec<float> qVec<float>::add(const qVec<long>& addend) const;
template qVec<float> qVec<float>::add(const qVec<float>& addend) const;
template qVec<float> qVec<float>::operator*(const int) const;
template qVec<float> qVec<float>::operator*(const double) const;
template qVec<float> qVec<float>::operator*(const long) const;
template qVec<float> qVec<float>::operator*(const float) const;
template qVec<float> qVec<float>::operator+(const qVec<int>& addend) const;
template qVec<float> qVec<float>::operator+(const qVec<double>& addend) const;
template qVec<float> qVec<float>::operator+(const qVec<long>& addend) const;
template qVec<float> qVec<float>::operator+(const qVec<float>& addend) const;


/**
 * @brief Constructs a qVec object with a specified size and initial values.
 * 
 * This constructor initializes a qVec object with a given size and optionally
 * fills it with initial values from an array. If the provided array has fewer
 * elements than the specified size, the remaining elements are initialized to zero.
 * 
 * @tparam T The type of the elements in the qVec.
 * @param size The size of the qVec, i.e., the number of elements it should hold.
 * @param values An array of initial values to fill into the qVec. Can be null if no initial values are provided.
 * @param tSize The number of valid elements in the values array. Should be less than or equal to size.
 */
template <typename T>
qVec<T>::qVec(int size, T values[], int tSize) {
    // Set the size of the qVec
    this->size = size;
    
    // Allocate memory for the values array based on the specified size
    this->values = new T[size];
    
    // Initialize elements of the qVec with values from the provided array
    for(int i = 0; i < size; i++) {
        // If the index is within the bounds of the provided values array, use the corresponding value
        if(i < tSize) {
            this->values[i] = values[i];
        }
        // If the index exceeds the bounds of the provided values array, initialize with zero
        else {
            this->values[i] = 0;
        }
    }
}
template <typename T>
qVec<T>::qVec(const qVec<T>& src) {
    // Set the size of the qVec
    this->size = src.getSize();
    
    // Allocate memory for the values array based on the specified size
    // This creates an array of type T with 'size' elements.
    this->values = new T[this->size];

    // Deep copy the values
    for (int i = 0; i < this->size; ++i) {
        values[i] = src.values[i];
    }
}
/**
 * @brief Constructs a qVec object with a specified size.
 * 
 * This constructor initializes the qVec object with the given size. It allocates
 * memory for the `values` array based on the specified size. The elements of the
 * array are not initialized and will contain indeterminate values until they are 
 * explicitly set.
 * 
 * @tparam T The type of the elements in the qVec.
 * @param size The size of the qVec, i.e., the number of elements it should hold.
 */
template <typename T>
qVec<T>::qVec(int size) {
    // Set the size of the qVec
    this->size = size;
    
    // Allocate memory for the values array based on the specified size
    // This creates an array of type T with 'size' elements.
    this->values = new T[size];

    // Fill values with 0
    for(int i = 0; i < size; i++) {
        values[i] = 0;
    }
}
template<typename T>
qVec<T>::qVec(std::initializer_list<T> list) {
    this->size = list.size();
    this->values = new T[this->size];
    size_t i = 0;
    for (auto value : list) {
        if (i >= size) break;
        values[i++] = value;
    }
}
/**
 * @brief Destructor for the qVec class.
 * 
 * This destructor cleans up the dynamically allocated memory used by the qVec object.
 * It is responsible for deallocating the memory allocated for the `values` array to
 * prevent memory leaks.
 * 
 * @tparam T The type of the elements in the qVec.
 */
template <typename T>
qVec<T>::~qVec() {
    //Calls clear function to delete vector
    this->clear();
}
/**
 * @brief Retrieves the size of the qVec object.
 * 
 * This function returns the number of elements in the qVec object. 
 * It provides a way to query the size of the `values` array managed by the qVec.
 * 
 * @tparam T The type of the elements in the qVec.
 * @return The size of the qVec, i.e., the number of elements it holds.
 */
template <typename T>
int qVec<T>::getSize() const{
    // Return the size of the qVec
    return size;
}
/**
 * @brief Provides access to the internal values array.
 * 
 * This function returns a pointer to the internal `values` array of the qVec object. 
 * It allows direct access to the array elements stored within the qVec.
 * 
 * @tparam T The type of the elements in the qVec.
 * @return A pointer to the internal array of values.
 */
template <typename T>
T* qVec<T>::valueOf(){
    // Return a pointer to the internal values array
    return this->values;
}
/**
 * @brief Retrieves the value at a specified index.
 * 
 * This function returns the value stored at the given index within the `values` array of the qVec object.
 * If the index is out of bounds, an `std::out_of_range` exception is thrown.
 * 
 * @tparam T The type of the elements in the qVec.
 * @param ind The index of the element to retrieve. Must be within the range [0, size-1].
 * @return The value at the specified index.
 * @throws std::out_of_range if the index is out of bounds.
 */
template <typename T>
T qVec<T>::getValue(int ind) const {
    if (ind >= 0 && ind < this->size) {
        return this->values[ind]; // Return the value at the specified index
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}

/**
 * @brief Sets the value at a specified index.
 * 
 * This function updates the value at the given index within the `values` array of the qVec object.
 * If the index is out of bounds, an `std::out_of_range` exception is thrown.
 * 
 * @tparam T The type of the elements in the qVec.
 * @param ind The index of the element to update. Must be within the range [0, size-1].
 * @param value The new value to set at the specified index.
 * @throws std::out_of_range if the index is out of bounds.
 */
template <typename T>
void qVec<T>::setValue(int ind, const T& value) {
    if (ind >= 0 && ind < this->size) {
        this->values[ind] = value; // Set the value at the specified index
    } else {
        throw std::out_of_range("Index is out of bounds"); // Index is out of range, throw exception
    }
}
/**
 * @brief Computes the dot product of the current vector with another vector.
 * 
 * The dot product is calculated as the sum of the products of the corresponding elements of the two vectors.
 * If the vectors are of different sizes, the function uses the size of the smaller vector.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the elements in the other qVec.
 * @param mult A constant reference to another qVec object of potentially different type H.
 * @return The dot product as a scalar of type T.
 */
template <typename T>
template <typename H>
T qVec<T>::dot(const qVec<H>& mult) const {
    int i = 0;
    T sum = 0;
    for(i = 0; i < mult.getSize(); i++){
        if(i < this->size) {
            sum += this->values[i] * mult.getValue(i);
        } else break;
    }
    return sum;
}

/**
 * @brief Computes the cross product of the current vector with another vector.
 * 
 * The cross product is defined only for 3-dimensional vectors. It results in a new vector that is perpendicular
 * to both of the input vectors. An exception is thrown if either of the vectors is not 3-dimensional.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the elements in the other qVec.
 * @param other A constant reference to another qVec object of potentially different type H.
 * @return A new qVec object of type T, representing the cross product of the two vectors.
 * @throws std::out_of_range if either vector is not of size 3.
 */
template <typename T>
template <typename H>
qVec<T> qVec<T>::cross(const qVec<H>& other) const {
    if (this->size != 3 || other.getSize() != 3) {
        throw std::out_of_range("Both vectors must be of size 3 for cross product.");
    }

    qVec<T> result(3); // Create a new vector of size 3 to store the result

    result[0] = this->values[1] * other[2] - this->values[2] * other[1];
    result[1] = this->values[2] * other[0] - this->values[0] * other[2];
    result[2] = this->values[0] * other[1] - this->values[1] * other[0];

    return result;
}

/**
 * @brief Scales the current vector by a given scalar value.
 * 
 * The resulting vector is a scaled version of the original vector, where each component is multiplied
 * by the scalar value.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the scalar value.
 * @param scale The scalar value of type H by which the vector will be scaled.
 * @return A new qVec object of type T, representing the scaled vector.
 */
template<typename T>
template<typename H> 
qVec<T> qVec<T>::scale(const H scale) const {
    qVec<T> newVec = qVec<T>(*this);
    for(size_t i = 0; i < newVec.getSize(); i++) {
        newVec[i] = this->getValue(i) * scale;
    }
    return newVec;
}

/**
 * @brief Multiplies the current vector by a scalar value using operator overloading.
 * 
 * This is a shorthand for the scale function, where the scalar value is provided as an argument.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the scalar value.
 * @param mult The scalar value of type H by which the vector will be multiplied.
 * @return A new qVec object of type T, representing the scaled vector.
 */
template <typename T>
template <typename H>
qVec<T> qVec<T>::operator*(const H mult) const{
    return this->scale(mult);
}

/**
 * @brief Adds another vector to the current vector.
 * 
 * The resulting vector is the sum of the two vectors, where each component of the resulting vector
 * is the sum of the corresponding components of the input vectors.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the elements in the other qVec.
 * @param addend A constant reference to another qVec object of potentially different type H to be added.
 * @return A new qVec object of type T, representing the sum of the two vectors.
 */
template <typename T>
template <typename H>
qVec<T> qVec<T>::add(const qVec<H>& addend) const {
    qVec<T> newVec = qVec<T>(*this);
    for(size_t i = 0; i < newVec.getSize(); i++) {
        newVec.values[i] += addend.getValue(i);
    }
    return newVec;
}

/**
 * @brief Adds another vector to the current vector using operator overloading.
 * 
 * This is a shorthand for the add function, where the vector to be added is provided as an argument.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the elements in the other qVec.
 * @param addend A constant reference to another qVec object of potentially different type H to be added.
 * @return A new qVec object of type T, representing the sum of the two vectors.
 */
template <typename T>
template <typename H>
qVec<T> qVec<T>::operator+(const qVec<H>& addend) const {
    return this->add(addend);
}

// Copy assignment operator
template <typename T>
template <typename H>
qVec<T>& qVec<T>::operator=(const qVec<H>& src) {
    if (this != &src) {  // Avoid self-assignment by checking if the object is being assigned to itself
        delete[] values; // Free the currently allocated memory to prevent memory leaks
        size = src.size; // Copy the size of the source vector
        values = new T[size]; // Allocate new memory for the values
        for (int i = 0; i < size; ++i) {
            values[i] = src.values[i]; // Copy each element from the source vector to the current vector
        }
    }
    return *this; // Return the current object to allow chaining of assignment operations
}
// Equality operator
template <typename T>
template <typename H>
bool qVec<T>::operator==(const qVec<H>& other) const {
    if (size != other.size) return false; // If sizes differ, vectors are not equal
    for (int i = 0; i < size; ++i) {
        if (values[i] != other.values[i]) return false; // If any element differs, vectors are not equal
    }
    return true; // Vectors are equal if all elements match
}

// Stream insertion operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const qVec<T>& vec) {
    os << "["; // Start of vector representation
    for (size_t i = 0; i < vec.getSize; ++i) {
        os << vec[i]; // Output each value
        if (i < vec.getSize() - 1) os << ", "; // Separate values with a comma, except the last one
    }
    os << "]"; // End of vector representation
    return os; // Return the stream object for chaining
}

// Clear method
template <typename T>
void qVec<T>::clear() {
    delete[] values; // Free the dynamically allocated memory
    size = 0; // Reset the size to 0
    values = nullptr; // Set the pointer to null to avoid dangling references
}
