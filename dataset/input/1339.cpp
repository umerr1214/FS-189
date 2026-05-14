#include <iostream>
#include <stdexcept> // For potential exceptions, though not used for primary robustness issue here

class DynamicArray {
private:
    int* data;
    int currentSize;

public:
    // Constructor
    DynamicArray(int size) : data(nullptr), currentSize(0) {
        if (size <= 0) {
            std::cout << "Warning: Array size must be positive. Creating an empty array." << std::endl;
            // Or throw std::invalid_argument("Array size must be positive.");
            return;
        }
        currentSize = size;
        data = new int[currentSize];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = 0; // Initialize elements to 0
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
        data = nullptr;
    }

    // Method to set an element - LACKS BOUNDS CHECKING (Robustness Issue)
    void setElement(int index, int value) {
        // No bounds checking here - direct access, leading to undefined behavior
        // if index is out of range. This is a major robustness flaw.
        data[index] = value;
    }

    // Method to get an element (for testing purposes)
    int getElement(int index) const {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds in getElement.");
        }
        return data[index];
    }

    // Method to get the size (for testing purposes)
    int getSize() const {
        return currentSize;
    }

    // IMPORTANT ROBUSTNESS FLAW:
    // Missing Copy Constructor and Copy Assignment Operator (Rule of Three violation).
    // If a DynamicArray object is copied, it will result in a shallow copy,
    // leading to double-free errors when the copied objects are destroyed.
    // Example:
    // DynamicArray arr1(5);
    // DynamicArray arr2 = arr1; // Shallow copy
    // Both arr1 and arr2's destructors will try to delete the same 'data' pointer.
};

int main() {
    // Test Case 1: Basic functionality
    std::cout << "Test Case 1: Basic functionality and out-of-bounds write (Robustness Issue)" << std::endl;
    DynamicArray arr(5);
    arr.setElement(0, 10);
    arr.setElement(4, 50);
    std::cout << "Element at index 0: " << arr.getElement(0) << std::endl;
    std::cout << "Element at index 4: " << arr.getElement(4) << std::endl;

    // This will likely cause a crash or undefined behavior due to lack of bounds checking in setElement
    std::cout << "Attempting to write out of bounds (index 5)..." << std::endl;
    arr.setElement(5, 100); // Robustness Issue: No bounds check
    std::cout << "Value written to index 5 (may be garbage or crash program): " << arr.getElement(5) << std::endl; // This getElement will throw, but setElement didn't

    std::cout << "\nTest Case 2: Demonstrating Rule of Three violation (Robustness Issue)" << std::endl;
    DynamicArray originalArray(3);
    originalArray.setElement(0, 11);
    originalArray.setElement(1, 22);
    originalArray.setElement(2, 33);

    std::cout << "Original array elements: ";
    for (int i = 0; i < originalArray.getSize(); ++i) {
        std::cout << originalArray.getElement(i) << " ";
    }
    std::cout << std::endl;

    // This performs a shallow copy because copy constructor is implicitly generated
    // and just copies the pointer 'data'.
    DynamicArray copiedArray = originalArray;
    copiedArray.setElement(0, 99); // Modifies originalArray's data as well

    std::cout << "Copied array element at index 0 after modification: " << copiedArray.getElement(0) << std::endl;
    std::cout << "Original array element at index 0 (also changed due to shallow copy): " << originalArray.getElement(0) << std::endl;

    // When originalArray and copiedArray go out of scope, their destructors
    // will both try to delete the same memory, leading to a double-free error.
    // This is the primary robustness issue demonstrated here.

    return 0;
}