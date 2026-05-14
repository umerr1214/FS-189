#include <iostream>
#include <stdexcept>

class DynamicIntegerArray {
private:
    int* data;
    int arraySize;

public:
    DynamicIntegerArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Array size cannot be negative.");
        }
        arraySize = size;
        data = new int[arraySize];
        for (int i = 0; i < arraySize; ++i) {
            data[i] = 0;
        }
    }

    // Semantic Error: Shallow copy constructor
    // It copies the pointer 'data' instead of allocating new memory and copying contents.
    // This leads to two DynamicIntegerArray objects owning the same memory,
    // resulting in a double-free when both destructors are called.
    DynamicIntegerArray(const DynamicIntegerArray& other) : arraySize(other.arraySize) {
        data = other.data; // Shallow copy of pointer - THIS IS THE SEMANTIC ERROR
        // Correct implementation would be:
        // data = new int[arraySize];
        // for (int i = 0; i < arraySize; ++i) {
        //     data[i] = other.data[i];
        // }
    }

    ~DynamicIntegerArray() {
        // This destructor will be called for both original and copied objects,
        // leading to double-free.
        delete[] data;
        data = nullptr;
    }

    int size() const {
        return arraySize;
    }

    int get(int index) const {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("Index out of bounds.");
        }
        data[index] = value;
    }

    void print() const {
        std::cout << "[";
        for (int i = 0; i < arraySize; ++i) {
            std::cout << data[i] << (i == arraySize - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

void testCopyConstructor() {
    std::cout << "--- Testing Semantic Error: Shallow Copy Constructor leading to Double-Free ---" << std::endl;
    DynamicIntegerArray originalArr(3);
    originalArr.set(0, 10);
    originalArr.set(1, 20);
    originalArr.set(2, 30);
    std::cout << "Original Array: ";
    originalArr.print();

    // Create a copy - this will trigger the shallow copy constructor
    DynamicIntegerArray copiedArr = originalArr;
    std::cout << "Copied Array: ";
    copiedArr.print();

    // Modify the copied array - this will also modify the original due to shallow copy
    copiedArr.set(0, 100);
    std::cout << "After modifying copiedArr[0] to 100:" << std::endl;
    std::cout << "Original Array: ";
    originalArr.print();
    std::cout << "Copied Array: ";
    copiedArr.print();

    // When originalArr and copiedArr go out of scope, their destructors will both try to delete the same 'data' pointer,
    // leading to a double-free, which is a semantic error and typically causes a crash.
    std::cout << "Both arrays will now go out of scope, triggering double-free..." << std::endl;
} // Destructors for copiedArr and originalArr are called here.

int main() {
    try {
        testCopyConstructor();
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing basic functionality (should be fine if no copy made) ---" << std::endl;
    try {
        DynamicIntegerArray arr(2);
        arr.set(0, 1);
        arr.set(1, 2);
        arr.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}