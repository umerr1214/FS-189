#include <iostream>

class DynamicArray {
private:
    int* arr // Missing semicolon here, causes a syntax error
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
        arr = nullptr; // Good practice to nullify pointer after deallocation
    }

    // Method to set an element
    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
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
    // This code will not compile due to the syntax error in the class definition.
    DynamicArray da(5);
    da.setElement(0, 10);
    da.setElement(2, 30);
    da.printArray(); // Intended output: 10 0 30 0 0
    return 0;
}