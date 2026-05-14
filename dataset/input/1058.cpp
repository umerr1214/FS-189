#include <iostream>

class DynamicArray {
private:
    int* _data;
    int _size;
    int _capacity;

    void reallocate() {
        int newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < _size; ++i) {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }

public:
    DynamicArray() : _data(nullptr), _size(0), _capacity(0) {}

    ~DynamicArray() {
        delete[] _data;
    }

    void add(int value) {
        if (_size == _capacity) {
            reallocate();
        }
        _data[_size++] = value;
    }

    void print() {
        std::cout << "Array elements: [";
        // Logical error: The loop iterates up to _capacity instead of _size.
        // This will print uninitialized memory if _size < _capacity,
        // leading to incorrect output or potential runtime errors.
        for (int i = 0; i < _capacity; ++i) { // Should be 'i < _size'
            std::cout << _data[i] << (i == _capacity - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    DynamicArray arr;
    std::cout << "Adding elements..." << std::endl;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.print(); // Expected: [10, 20, 30]. Actual: [10, 20, 30, <garbage>] (if capacity is 4)
    arr.add(40);
    arr.add(50);
    arr.print(); // Expected: [10, 20, 30, 40, 50]. Actual: [10, 20, 30, 40, 50, <garbage>, <garbage>, <garbage>] (if capacity is 8)
    std::cout << "Demonstrating lifecycle: Array goes out of scope and destructor is called." << std::endl;
    return 0;
}