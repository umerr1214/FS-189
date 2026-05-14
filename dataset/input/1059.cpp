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
        // Semantic error: Memory leak. The old memory block pointed to by _data
        // is not deallocated before _data is reassigned to newData.
        // The line 'delete[] _data;' is missing here.
        _data = newData;
        _capacity = newCapacity;
    }

public:
    DynamicArray() : _data(nullptr), _size(0), _capacity(0) {}

    ~DynamicArray() {
        delete[] _data; // This only deallocates the final _data pointer, not previous leaked blocks
    }

    void add(int value) {
        if (_size == _capacity) {
            reallocate();
        }
        _data[_size++] = value;
    }

    void print() {
        std::cout << "Array elements: [";
        for (int i = 0; i < _size; ++i) {
            std::cout << _data[i] << (i == _size - 1 ? "" : ", ");
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
    arr.print();
    arr.add(40);
    arr.add(50);
    arr.print();
    std::cout << "Demonstrating lifecycle: Array goes out of scope and destructor is called." << std::endl;
    return 0;
}