#include <iostream>

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    DynamicArray(int s) : size(s) {
        if (s <= 0) {
            std::cout << "Warning: Array size must be positive. Setting size to 1." << std::endl;
            this->size = 1;
        }
        arr = new int[this->size];
        for (int i = 0; i < this->size; ++i) {
            arr[i] = 0; // Initialize elements to 0
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
        arr = nullptr;
    }

    // Method to set an element
    void setElement(int index, int value) {
        // Logical Error: The condition `index <= size` allows access to `arr[size]`,
        // which is one element past the end of the allocated array (valid indices are 0 to size-1).
        // It also does not explicitly handle negative indices before the general bounds check.
        if (index >= 0 && index <= size) { // Should be `index < size`
            arr[index] = value;
        } else {
            std::cout << "Error: Index " << index << " out of bounds for size " << size << "." << std::endl;
        }
    }

    // Helper method to print the array (for testing/demonstration)
    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray da(3); // Creates an array with valid indices 0, 1, 2
    da.setElement(0, 10);
    da.setElement(1, 20);
    da.setElement(2, 30); // Valid operation
    da.printArray(); // Expected: 10 20 30 

    // This call attempts to write to index 3, which is out of bounds for an array of size 3.
    // Due to the logical error in setElement, it will attempt to write to arr[3].
    da.setElement(3, 40); 
    da.printArray(); // Behavior is undefined after out-of-bounds write.

    // This call attempts to write to a negative index.
    da.setElement(-1, 50); // Will print an error message.
    da.printArray();

    return 0;
}