#include "qVec.h"
//Include all function declarations with template values

// Integers
template qVec<int>::qVec(int size, int values[], int tSize);
template qVec<int>::qVec(int size);
template qVec<int>::qVec(const qVec<int>& src);
template qVec<int>::~qVec();
template int qVec<int>::getSize() const;
template int* qVec<int>::valueOf();
template int qVec<int>::getValue(int ind) const;
template void qVec<int>::setValue(int ind, const int& value);

// Double
template qVec<double>::qVec(int size, double values[], int tSize);
template qVec<double>::qVec(int size);
template qVec<double>::~qVec();
template int qVec<double>::getSize() const;
template double* qVec<double>::valueOf();
template double qVec<double>::getValue(int ind) const;
template void qVec<double>::setValue(int ind, const double& value);

// Long
template qVec<long>::qVec(int size, long values[], int tSize);
template qVec<long>::qVec(int size);
template qVec<long>::~qVec();
template int qVec<long>::getSize() const;
template long* qVec<long>::valueOf();
template long qVec<long>::getValue(int ind) const;
template void qVec<long>::setValue(int ind, const long& value);

// Float
template qVec<float>::qVec(int size, float values[], int tSize);
template qVec<float>::qVec(int size);
template qVec<float>::~qVec();
template int qVec<float>::getSize() const;
template float* qVec<float>::valueOf();



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

// Copy assignment operator
template <typename T>
qVec<T>& qVec<T>::operator=(const qVec<T>& src) {
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

// Move assignment operator
template <typename T>
qVec<T>& qVec<T>::operator=(qVec<T>&& src) noexcept {
    if (this != &src) { // Avoid self-assignment
        delete[] values; // Free the current resources
        size = src.size; // Transfer ownership of the source vector's resources
        values = src.values; // Move the source vector's resources to the current vector
        src.size = 0; // Set the source vector's size to 0
        src.values = nullptr; // Set the source vector's pointer to null to avoid double deletion
    }
    return *this; // Return the current object to allow chaining of assignment operations
}

// Equality operator
template <typename T>
bool qVec<T>::operator==(const qVec<T>& other) const {
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
    for (int i = 0; i < vec.size; ++i) {
        os << vec.values[i]; // Output each value
        if (i < vec.size - 1) os << ", "; // Separate values with a comma, except the last one
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
