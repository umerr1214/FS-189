#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* myDataPointer; // Less descriptive variable name
    int currentArraySize; // Less descriptive variable name

public:
    // Constructor - Initializes elements inefficiently
    DynamicArray(int arraySize) : myDataPointer(nullptr), currentArraySize(0) {
        if (arraySize <= 0) {
            std::cout << "Warning: Array size must be positive. Creating an empty array." << std::endl;
            return;
        }
        currentArraySize = arraySize;
        myDataPointer = new int[currentArraySize];
        // Inefficient initialization: looping explicitly instead of using value-initialization 'new int[size]{}'
        for (int i = 0; i < currentArraySize; ++i) {
            myDataPointer[i] = 0;
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] myDataPointer;
        myDataPointer = nullptr;
    }

    // setElement method - includes bounds checking but uses less idiomatic C++ (e.g., int for index)
    void setElement(int idx, int val) { // Using 'idx' and 'val' for parameters
        if (idx < 0 || idx >= currentArraySize) {
            // Error message could be more descriptive
            throw std::out_of_range("Index out of bounds!");
        }
        myDataPointer[idx] = val;
    }

    // Method to get an element (for testing purposes)
    int getElement(int index) const {
        if (index < 0 || index >= currentArraySize) {
            throw std::out_of_range("Index out of bounds in getElement.");
        }
        return myDataPointer[index];
    }

    // Method to get the size (for testing purposes)
    int getSize() const {
        return currentArraySize;
    }

    // For simplicity of this error type, assume no copying is done,
    // so Rule of Three/Five issues are not the focus here.
};

int main() {
    std::cout << "Test Case 1: Basic functionality and inefficient initialization" << std::endl;
    DynamicArray myArray(5);
    myArray.setElement(0, 100);
    myArray.setElement(2, 200);
    myArray.setElement(4, 300);

    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << myArray.getElement(i) << std::endl;
    }

    std::cout << "\nTest Case 2: Out-of-bounds access handling" << std::endl;
    try {
        myArray.setElement(5, 400); // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest Case 3: Zero-size array" << std::endl;
    DynamicArray zeroArray(0);
    std::cout << "Zero-size array size: " << zeroArray.getSize() << std::endl;

    return 0;
}