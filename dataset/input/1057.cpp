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

pubic: // Syntax Error: Typo 'pubic' instead of 'public'
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
        for (int i = 0; i < _size; ++i) {
            std::cout << _data[i] << (i == _size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

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