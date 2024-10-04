#include "qVec.h"
//Include all function declarations with template values

// Integers
template qVec<int>::qVec(int size, int values[]);
template qVec<int>::qVec(int size);
template qVec<int>::qVec(const qVec<int>& src);
template qVec<int>::qVec(const qVec<long>& src);
template qVec<int>::qVec(const qVec<float>& src);
template qVec<int>::qVec(const qVec<double>& src);
template qVec<int>::qVec(std::initializer_list<int> values);
template qVec<int>::~qVec();
template int qVec<int>::getSize() const;
template int* qVec<int>::valueOf();
template int qVec<int>::getValue(int ind) const;
template void qVec<int>::setValue(int ind, const int& value);
template float qVec<int>::magnitude() const;
template qVec<int> qVec<int>::norm() const;
template int qVec<int>::dot(const qVec<int>& mult) const;
template int qVec<int>::dot(const qVec<double>& mult) const;
template int qVec<int>::dot(const qVec<long>& mult) const;
template int qVec<int>::dot(const qVec<float>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<int>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<double>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<long>& mult) const;
template qVec<int> qVec<int>::cross(const qVec<float>& mult) const;
template qVec<int> qVec<int>::scale(const int&) const;
template qVec<int> qVec<int>::scale(const double&) const;
template qVec<int> qVec<int>::scale(const long&) const;
template qVec<int> qVec<int>::scale(const float&) const;
template qVec<int> qVec<int>::add(const qVec<int>& addend) const;
template qVec<int> qVec<int>::add(const qVec<double>& addend) const;
template qVec<int> qVec<int>::add(const qVec<long>& addend) const;
template qVec<int> qVec<int>::add(const qVec<float>& addend) const;
// Long
template qVec<long>::qVec(int size, long values[]);
template qVec<long>::qVec(int size);
template qVec<long>::qVec(const qVec<int>& src);
template qVec<long>::qVec(const qVec<long>& src);
template qVec<long>::qVec(const qVec<float>& src);
template qVec<long>::qVec(const qVec<double>& src);
template qVec<long>::qVec(std::initializer_list<long> values);
template qVec<long>::~qVec();
template int qVec<long>::getSize() const;
template long* qVec<long>::valueOf();
template long qVec<long>::getValue(int ind) const;
template void qVec<long>::setValue(int ind, const long& value);
template float qVec<long>::magnitude() const;
template qVec<long> qVec<long>::norm() const;
template long qVec<long>::dot(const qVec<int>& mult) const;
template long qVec<long>::dot(const qVec<double>& mult) const;
template long qVec<long>::dot(const qVec<long>& mult) const;
template long qVec<long>::dot(const qVec<float>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<int>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<double>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<long>& mult) const;
template qVec<long> qVec<long>::cross(const qVec<float>& mult) const;
template qVec<long> qVec<long>::scale(const int&) const;
template qVec<long> qVec<long>::scale(const double&) const;
template qVec<long> qVec<long>::scale(const long&) const;
template qVec<long> qVec<long>::scale(const float&) const;
template qVec<long> qVec<long>::add(const qVec<int>& addend) const;
template qVec<long> qVec<long>::add(const qVec<double>& addend) const;
template qVec<long> qVec<long>::add(const qVec<long>& addend) const;
template qVec<long> qVec<long>::add(const qVec<float>& addend) const;
// Double
template qVec<double>::qVec(int size, double values[]);
template qVec<double>::qVec(int size);
template qVec<double>::qVec(const qVec<int>& src);
template qVec<double>::qVec(const qVec<long>& src);
template qVec<double>::qVec(const qVec<float>& src);
template qVec<double>::qVec(const qVec<double>& src);
template qVec<double>::qVec(std::initializer_list<double> values);
template qVec<double>::~qVec();
template int qVec<double>::getSize() const;
template double* qVec<double>::valueOf();
template double qVec<double>::getValue(int ind) const;
template void qVec<double>::setValue(int ind, const double& value);
template float qVec<double>::magnitude() const;
template qVec<double> qVec<double>::norm() const;
template double qVec<double>::dot(const qVec<int>& mult) const;
template double qVec<double>::dot(const qVec<double>& mult) const;
template double qVec<double>::dot(const qVec<long>& mult) const;
template double qVec<double>::dot(const qVec<float>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<int>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<double>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<long>& mult) const;
template qVec<double> qVec<double>::cross(const qVec<float>& mult) const;
template qVec<double> qVec<double>::scale(const int&) const;
template qVec<double> qVec<double>::scale(const double&) const;
template qVec<double> qVec<double>::scale(const long&) const;
template qVec<double> qVec<double>::scale(const float&) const;
template qVec<double> qVec<double>::add(const qVec<int>& addend) const;
template qVec<double> qVec<double>::add(const qVec<double>& addend) const;
template qVec<double> qVec<double>::add(const qVec<long>& addend) const;
template qVec<double> qVec<double>::add(const qVec<float>& addend) const;

// Float
template qVec<float>::qVec(int size, float values[]);
template qVec<float>::qVec(int size);
template qVec<float>::qVec(const qVec<int>& src);
template qVec<float>::qVec(const qVec<long>& src);
template qVec<float>::qVec(const qVec<float>& src);
template qVec<float>::qVec(const qVec<double>& src);
template qVec<float>::qVec(std::initializer_list<float> values);
template qVec<float>::~qVec();
template int qVec<float>::getSize() const;
template float* qVec<float>::valueOf();
template float qVec<float>::getValue(int ind) const;
template void qVec<float>::setValue(int ind, const float& value);
template float qVec<float>::magnitude() const;
template qVec<float> qVec<float>::norm() const;
template float qVec<float>::dot(const qVec<int>& mult) const;
template float qVec<float>::dot(const qVec<double>& mult) const;
template float qVec<float>::dot(const qVec<long>& mult) const;
template float qVec<float>::dot(const qVec<float>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<int>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<double>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<long>& mult) const;
template qVec<float> qVec<float>::cross(const qVec<float>& mult) const;
template qVec<float> qVec<float>::scale(const int&) const;
template qVec<float> qVec<float>::scale(const double&) const;
template qVec<float> qVec<float>::scale(const long&) const;
template qVec<float> qVec<float>::scale(const float&) const;
template qVec<float> qVec<float>::add(const qVec<int>& addend) const;
template qVec<float> qVec<float>::add(const qVec<double>& addend) const;
template qVec<float> qVec<float>::add(const qVec<long>& addend) const;
template qVec<float> qVec<float>::add(const qVec<float>& addend) const;


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
 */
template <typename T>
qVec<T>::qVec(int size, T values[]) {
    // Set the size of the qVec
    this->size = size;
    
    // Allocate memory for the values array based on the specified size
    this->values = new T[size];
    size_t tSize = *(&values + 1) - values;
    // Initialize elements of the qVec with values from the provided array
    for(int i = 0; i < size; i++) {
        // If the index is within the bounds of the provided values array, use the corresponding value
        if(i <= tSize) {
            this->values[i] = values[i];
        }
        // If the index exceeds the bounds of the provided values array, initialize with zero
        else {
            this->values[i] = 0;
        }
    }
}
template <typename T>
template <typename H>
qVec<T>::qVec(const qVec<H>& src) {
    // Set the size of the qVec
    this->size = src.getSize();
    
    // Allocate memory for the values array based on the specified size
    // This creates an array of type T with 'size' elements.
    this->values = new T[this->size];

    // Deep copy the values
    for (int i = 0; i < this->size; ++i) {
        this->values[i] = src.getValue(i);
    }
}
#ifndef __linux__
template<typename T>
qVec<T>::qVec(const qVec<T>& src) {
    // Set the size of the qVec
    this->size = src.getSize();
    
    // Allocate memory for the values array based on the specified size
    // This creates an array of type T with 'size' elements.
    this->values = new T[this->size];

    // Deep copy the values
    for (int i = 0; i < this->size; ++i) {
        this->values[i] = src.getValue(i);
    }
}
#endif
/**
 * @brief Constructs a qVec object with a specified size.
 * 
 * This constructor initializes the qVec object with the given size. It allocates
 * memory for the `values` array based on the specified size. The elements of the
 * array will be set to 0.
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
/**
 * @brief Constructs a qVec object from an initializer list.
 * 
 * This constructor allows a qVec object to be initialized using an initializer list.
 * It allocates memory for the `values` array based on the number of elements in the
 * list and deep copies the values from the initializer list into the qVec.
 * 
 * @tparam T The type of the elements in the qVec.
 * @param list An initializer list containing the values to initialize the qVec with.
 */
template<typename T>
qVec<T>::qVec(std::initializer_list<T> list) {
    // Set the size of the qVec based on the number of elements in the initializer list
    this->size = list.size();

    // Allocate memory for the values array based on the size of the initializer list
    this->values = new T[this->size];

    // Copy the elements from the initializer list into the values array
    std::copy(list.begin(), list.end(), this->values);
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
 * @brief Computes the magnitude (or length) of the vector.
 * 
 * The magnitude is calculated as the square root of the sum of the squares of the vector's components.
 * This function assumes that the components are of type T, and the result is returned as a float.
 * 
 * @tparam T The type of the elements in the qVec.
 * @return The magnitude of the vector as a float.
 */
template <typename T>
float qVec<T>::magnitude() const{
    T sum = 0;
    for(int i = 0; i < size; i++) {
        sum += values[i] * values[i];
    }
    return std::sqrt(static_cast<float>(sum));
}
/**
 * @brief Computes the normalized version of the vector.
 * 
 * The normalized vector is obtained by scaling the current vector by the reciprocal of its magnitude.
 * If the magnitude is zero, an exception is thrown to indicate that normalization cannot be performed.
 * The result is a new vector of the same type as the current vector but with a magnitude of 1.
 * 
 * @tparam T The type of the elements in the qVec.
 * @return A new qVec<T> instance representing the normalized vector.
 * @throws std::runtime_error If the magnitude of the vector is zero.
 */
template <typename T>
qVec<T> qVec<T>::norm() const{
    float mag = this->magnitude();
    if (mag == 0) {
        throw std::runtime_error("Cannot normalize a vector with zero magnitude.");
    }
    return this->scale(1.0f / mag);
}
/**
 * @brief Computes the dot product of this qVec and another qVec.
 * 
 * This function computes the dot product between the current qVec object 
 * and another qVec passed as a parameter. It ensures both vectors have the 
 * same size before performing the operation. The result is the sum of 
 * the element-wise products of the two vectors.
 * 
 * @tparam T The type of the elements in the qVec.
 * @tparam H The type of the elements in the other qVec.
 * @param mult The qVec object to compute the dot product with.
 * @return The dot product as a scalar value of type T.
 * @throws std::invalid_argument if the two qVec objects have different sizes.
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
 * @note use #def FLOATNORM to normalize float values close to 0.
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

#ifdef FLOATNORM
    // Adjust for negative zero only if T is a floating-point type
    if constexpr (std::is_floating_point<T>::value) {
        if (result[0] == 0.0) result[0] = 0.0;
        if (result[1] == 0.0) result[1] = 0.0;
        if (result[2] == 0.0) result[2] = 0.0;
    }
#endif
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
qVec<T> qVec<T>::scale(const H& scalar) const {
    qVec<T> newVec = qVec<T>(*this);
    for(size_t i = 0; i < newVec.getSize(); i++) {
        newVec[i] = this->getValue(i) * scalar;
    }
    return newVec;
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
 * @brief Compares two qVec objects for equality.
 * 
 * This operator checks whether the current qVec is equal to another qVec object.
 * It compares the size and elements of both vectors, returning true if all elements match.
 * 
 * @tparam T The type of the elements in the current qVec.
 * @tparam H The type of the elements in the other qVec.
 * @param other A constant reference to the other qVec to be compared.
 * @return true if both vectors are equal (same size and element values), false otherwise.
 */
template <typename T>
template <typename H>
bool qVec<T>::operator==(const qVec<H>& other) const {
    if (size != other.size) return false; // If sizes differ, vectors are not equal
    for (int i = 0; i < size; ++i) {
        if (values[i] != other.values[i]) return false; // If any element differs, vectors are not equal
    }
    return true; // Vectors are equal if all elements match
}

/**
 * @brief Stream insertion operator to print qVec.
 * 
 * This operator allows easy printing of the qVec object by inserting its contents into
 * an output stream. The vector is displayed in a comma-separated format enclosed in square brackets.
 * 
 * @tparam T The type of the elements in the qVec.
 * @param os The output stream to insert the vector into.
 * @param vec A constant reference to the qVec object to be printed.
 * @return The modified output stream with the qVec contents inserted.
 */
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

/**
 * @brief Clears the contents of the qVec.
 * 
 * This method frees the dynamically allocated memory used by the qVec and resets
 * the size to 0. The vector becomes empty, with its internal pointer set to null.
 */
template <typename T>
void qVec<T>::clear() {
    delete[] values; // Free the dynamically allocated memory
    size = 0; // Reset the size to 0
    values = nullptr; // Set the pointer to null to avoid dangling references
}
