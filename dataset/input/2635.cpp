#include <iostream>
#include <stdexcept> // For std::bad_alloc (potentially caught by driver)

class DynamicIntegerArray {
private:
    int* _data;
    int _size;

public:
    DynamicIntegerArray(int size) : _size(size) {
        // Robustness Issue: Does not handle negative size gracefully (e.g., throws exception or sets to 0).
        // If size is negative, `new int[size]` is Undefined Behavior, often leading to std::bad_alloc or crash.
        // It also does not handle std::bad_alloc if memory allocation fails for valid sizes.
        _data = new int[size]; // Potential crash or unhandled bad_alloc
        for (int i = 0; i < _size; ++i) {
            _data[i] = 0; // Initialize elements
        }
        std::cout << "DynamicIntegerArray of size " << _size << " created." << std::endl;
    }

    ~DynamicIntegerArray() {
        if (_data != nullptr) { // Check to prevent issues if _data was never allocated or already freed
            delete[] _data;
            _data = nullptr;
        }
        std::cout << "DynamicIntegerArray of size " << _size << " destroyed." << std::endl;
    }

    int getSize() const { return _size; }

    int& operator[](int index) {
        if (index < 0 || index >= _size) {
            std::cerr << "Error: Index out of bounds!" << std::endl;
            // In a real robust app, this would throw std::out_of_range.
            // For this example, returning a static dummy to avoid crashing, but indicating error.
            static int dummy = -1;
            return dummy;
        }
        return _data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= _size) {
            std::cerr << "Error: Index out of bounds (const)!" << std::endl;
            static const int dummy = -1;
            return dummy;
        }
        return _data[index];
    }

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
    {
        DynamicIntegerArray arr(5);
        for (int i = 0; i < arr.getSize(); ++i) {
            arr[i] = (i + 1) * 10;
        }
        std::cout << "Array contents: ";
        arr.print();
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Zero Size Allocation ---" << std::endl;
    {
        // `new int[0]` returns a valid, non-null pointer, which is standard C++ behavior.
        // The class implicitly handles it, but doesn't treat it as a special case explicitly.
        DynamicIntegerArray arr(0);
        std::cout << "Array contents: ";
        arr.print();
        arr[0] = 99; // Should show error
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Negative Size Allocation (Robustness Issue) ---" << std::endl;
    {
        // This will likely cause a std::bad_alloc or crash, as `new int[-5]` is undefined behavior.
        // The class itself does not catch std::bad_alloc. The main function wraps it for demonstration.
        try {
            DynamicIntegerArray arr(-5); // Robustness Issue: No internal handling for negative size
            std::cout << "Array size: " << arr.getSize() << std::endl;
            arr.print();
        } catch (const std::bad_alloc& e) {
            std::cout << "Caught expected std::bad_alloc due to negative size: " << e.what() << std::endl;
        } catch (...) {
            std::cout << "Caught unexpected exception during negative size allocation." << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Out of Bounds Access ---" << std::endl;
    {
        DynamicIntegerArray arr(3);
        arr[0] = 1; arr[1] = 2; arr[2] = 3;
        std::cout << "Array contents: ";
        arr.print();
        std::cout << "Accessing arr[3]: " << arr[3] << std::endl;
        std::cout << "Accessing arr[-1]: " << arr[-1] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}