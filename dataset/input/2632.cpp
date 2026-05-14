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
        data = neew int[arraySize]; // Syntax error: misspelled 'new'
        for (int i = 0; i < arraySize; ++i) {
            data[i] = 0;
        }
    }

    ~DynamicIntegerArray() {
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

int main() {
    try {
        DynamicIntegerArray arr(5);
        arr.set(0, 10);
        arr.set(4, 50);
        std::cout << "Array contents: ";
        arr.print();
        std::cout << "Element at index 0: " << arr.get(0) << std::endl;
        std::cout << "Element at index 4: " << arr.get(4) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        DynamicIntegerArray arr0(0);
        std::cout << "Array of size 0 created." << std::endl;
        arr0.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        DynamicIntegerArray arrNeg(-1);
        std::cout << "Array of negative size created (should not happen)." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected error for negative size: " << e.what() << std::endl;
    }

    return 0;
}