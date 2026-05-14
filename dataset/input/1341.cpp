#include <iostream>
#include <stdexcept> // For std::out_of_range
#include <algorithm> // For std::copy

class DynamicArray {
private:
    int* data;
    std::size_t size; // Use std::size_t for array sizes and indices

public:
    // Constructor
    explicit DynamicArray(std::size_t initialSize = 0) : data(nullptr), size(initialSize) {
        if (size > 0) {
            data = new int[size]{}; // Value-initializes all elements to 0
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
        data = nullptr;
        size = 0; // Reset size for clarity
    }

    // Copy Constructor (Rule of Three)
    DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
        if (size > 0) {
            data = new int[size];
            std::copy(other.data, other.data + other.size, data); // Deep copy
        }
    }

    // Copy Assignment Operator (Rule of Three)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) { // Handle self-assignment
            return *this;
        }

        // Deallocate existing memory
        delete[] data;

        // Allocate new memory and copy data
        size = other.size;
        data = nullptr; // Important to reset before new to avoid dangling pointer issues if new fails
        if (size > 0) {
            data = new int[size];
            std::copy(other.data, other.data + other.size, data); // Deep copy
        }
        return *this;
    }

    // Move Constructor (Rule of Five)
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; // Nullify source to prevent its destructor from deallocating
        other.size = 0;
    }

    // Move Assignment Operator (Rule of Five)
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) { // Handle self-assignment
            return *this;
        }

        delete[] data; // Deallocate current resources

        data = other.data; // Steal resources
        size = other.size;

        other.data = nullptr; // Nullify source
        other.size = 0;

        return *this;
    }

    // Method to set an element with robust bounds checking
    void setElement(std::size_t index, int value) {
        if (index >= size) { // Correct bounds checking for std::size_t
            throw std::out_of_range("Index out of bounds: " + std::to_string(index) + " for array of size " + std::to_string(size));
        }
        data[index] = value;
    }

    // Method to get an element (for testing purposes)
    int getElement(std::size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds: " + std::to_string(index) + " for array of size " + std::to_string(size));
        }
        return data[index];
    }

    // Method to get the size
    std::size_t getSize() const {
        return size;
    }
};

int main() {
    std::cout << "Test Case 1: Basic functionality and initialization" << std::endl;
    DynamicArray arr(5);
    arr.setElement(0, 10);
    arr.setElement(4, 50);

    for (std::size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << "Element at index " << i << ": " << arr.getElement(i) << std::endl;
    }

    std::cout << "\nTest Case 2: Out-of-bounds access handling" << std::endl;
    try {
        arr.setElement(5, 100);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest Case 3: Copy Constructor (Deep Copy)" << std::endl;
    DynamicArray originalArray(3);
    originalArray.setElement(0, 11);
    originalArray.setElement(1, 22);
    originalArray.setElement(2, 33);

    DynamicArray copiedArray = originalArray; // Calls copy constructor
    copiedArray.setElement(0, 99); // Modify copied array

    std::cout << "Original array elements: ";
    for (std::size_t i = 0; i < originalArray.getSize(); ++i) {
        std::cout << originalArray.getElement(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Copied array elements: ";
    for (std::size_t i = 0; i < copiedArray.getSize(); ++i) {
        std::cout << copiedArray.getElement(i) << " ";
    }
    std::cout << std::endl;
    // Expect originalArray[0] to still be 11, demonstrating deep copy

    std::cout << "\nTest Case 4: Copy Assignment Operator (Deep Copy)" << std::endl;
    DynamicArray anotherArray(2);
    anotherArray.setElement(0, 5);
    anotherArray.setElement(1, 10);

    anotherArray = originalArray; // Calls copy assignment operator
    anotherArray.setElement(0, 77); // Modify assigned array

    std::cout << "Original array elements: ";
    for (std::size_t i = 0; i < originalArray.getSize(); ++i) {
        std::cout << originalArray.getElement(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Assigned array elements: ";
    for (std::size_t i = 0; i < anotherArray.getSize(); ++i) {
        std::cout << anotherArray.getElement(i) << " ";
    }
    std::cout << std::endl;
    // Expect originalArray[0] to still be 11, demonstrating deep copy

    std::cout << "\nTest Case 5: Move Semantics" << std::endl;
    DynamicArray sourceArray(4);
    sourceArray.setElement(0, 1);
    sourceArray.setElement(1, 2);
    std::cout << "Source array before move: ";
    for (std::size_t i = 0; i < sourceArray.getSize(); ++i) {
        std::cout << sourceArray.getElement(i) << " ";
    }
    std::cout << std::endl;

    DynamicArray movedArray = std::move(sourceArray); // Calls move constructor
    std::cout << "Moved array after move (should have content): ";
    for (std::size_t i = 0; i < movedArray.getSize(); ++i) {
        std::cout << movedArray.getElement(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Source array after move (should be empty/null): Size = " << sourceArray.getSize() << std::endl;
    // Accessing sourceArray elements here would be undefined behavior, but size is 0.

    return 0;
}