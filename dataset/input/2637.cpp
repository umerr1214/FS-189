#include <iostream>
#include <stdexcept> // For std::bad_alloc, std::invalid_argument, std::out_of_range

class DynamicIntegerArray {
private:
    int* _data;
    int _size;

public:
    // Constructor
    DynamicIntegerArray(int size) : _data(nullptr), _size(0) {
        if (size < 0) {
            throw std::invalid_argument("Array size cannot be negative.");
        }
        if (size == 0) {
            std::cout << "DynamicIntegerArray of size 0 created (no memory allocated)." << std::endl;
            return; // _data is nullptr, _size is 0, which is a valid empty state
        }

        try {
            _data = new int[size](); // Allocate and value-initialize elements to 0
            _size = size;
            std::cout << "DynamicIntegerArray of size " << _size << " created." << std::endl;
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            // Ensure object is in a valid (empty) state even after allocation failure
            _data = nullptr;
            _size = 0;
            throw; // Re-throw to indicate construction failed
        }
    }

    // Destructor
    ~DynamicIntegerArray() {
        if (_data != nullptr) {
            delete[] _data;
            _data = nullptr; // Good practice to nullify after delete
        }
        std::cout << "DynamicIntegerArray of size " << _size << " destroyed." << std::endl;
    }

    // Accessor for size
    int getSize() const { return _size; }

    // Element access (non-const)
    int& operator[](int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of bounds.");
        }
        return _data[index];
    }

    // Element access (const)
    const int& operator[](int index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of bounds (const).");
        }
        return _data[index];
    }

    // Print method for verification
    void print() const {
        if (_size <= 0 || _data == nullptr) {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (int i = 0; i < _size; ++i) {
            std::cout << _data[i] << (i == _size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::cout << "--- Test Case 1: Normal Allocation ---" << std::endl;
    try {
        DynamicIntegerArray arr(5);
        for (int i = 0; i < arr.getSize(); ++i) {
            arr[i] = (i + 1) * 100;
        }
        std::cout << "Array contents: ";
        arr.print();
    } catch (const std::exception& e) {
        std::cerr << "Error in Test Case 1: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Zero Size Allocation ---" << std::endl;
    try {
        DynamicIntegerArray arr(0);
        std::cout << "Array size: " << arr.getSize() << std::endl;
        std::cout << "Array contents: ";
        arr.print();
        // arr[0] = 99; // This would correctly throw std::out_of_range if uncommented
    } catch (const std::exception& e) {
        std::cerr << "Error in Test Case 2: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Negative Size Allocation ---" << std::endl;
    try {
        DynamicIntegerArray arr(-5); // Expected to throw std::invalid_argument
        std::cout << "Array size: " << arr.getSize() << std::endl;
        arr.print();
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Out of Bounds Access ---" << std::endl;
    try {
        DynamicIntegerArray arr(3);
        arr[0] = 1; arr[1] = 2; arr[2] = 3;
        std::cout << "Array contents: ";
        arr.print();
        std::cout << "Accessing arr[3]: " << arr[3] << std::endl; // Expected to throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 5: Out of Bounds Access (const) ---" << std::endl;
    try {
        const DynamicIntegerArray arr(2); // Const object
        std::cout << "Array contents: ";
        arr.print(); // Expected: [0, 0] (initialized by constructor)
        std::cout << "Accessing arr[2]: " << arr[2] << std::endl; // Expected to throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}