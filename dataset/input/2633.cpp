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

    // Logical Error: Intended to set data[index], but sets data[index + 1]
    void set(int index, int value) {
        if (index < 0 || index >= arraySize) {
            throw std::out_of_range("Index out of bounds for setting.");
        }
        // This check is to prevent an immediate crash in test cases,
        // highlighting the logical error (wrong index) rather than a semantic one (crash).
        if (index + 1 >= arraySize) {
            throw std::out_of_range("Logical error would cause out of bounds write at index+1 if not prevented.");
        }
        data[index + 1] = value; // This is the logical error
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
    std::cout << "--- Testing Logical Error: set() writes to index+1 ---" << std::endl;
    try {
        DynamicIntegerArray arr(5); // Size 5, indices 0-4
        std::cout << "Initial Array (size 5): ";
        arr.print();

        // Set operations for indices such that index+1 is still within bounds (0 to 3)
        arr.set(0, 10); // Intended data[0]=10, Actual data[1]=10
        std::cout << "After arr.set(0, 10): ";
        arr.print();

        arr.set(2, 30); // Intended data[2]=30, Actual data[3]=30
        std::cout << "After arr.set(2, 30): ";
        arr.print();

        std::cout << "Value at index 0: " << arr.get(0) << std::endl;
        std::cout << "Value at index 1: " << arr.get(1) << std::endl;
        std::cout << "Value at index 2: " << arr.get(2) << std::endl;
        std::cout << "Value at index 3: " << arr.get(3) << std::endl;
        std::cout << "Value at index 4: " << arr.get(4) << std::endl;

        // Attempting to set at index 4 (arraySize - 1) will trigger the specific check
        // to prevent a crash, making the logical error observable without crashing.
        try {
            arr.set(4, 50); // This would try to write to data[5], out of bounds
        } catch (const std::out_of_range& e) {
            std::cerr << "Caught expected error for set(4, 50): " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing correct behavior (no logical error for these cases) ---" << std::endl;
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