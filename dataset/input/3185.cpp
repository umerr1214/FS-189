#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
public:
    char* data;
    size_t length;

    MyString(const char* s = nullptr) : data(nullptr), length(0) {
        if (s) {
            length = std::strlen(s);
            // LOGICAL ERROR: Allocating 'length' instead of 'length + 1' for the null terminator.
            data = new char[length]; // This is an off-by-one error.
            std::strcpy(data, s); // This will write past the allocated memory, leading to undefined behavior.
        }
    }

    // Deep Copy Constructor
    MyString(const MyString& other) : data(nullptr), length(other.length) {
        if (other.data) {
            // LOGICAL ERROR: Allocating 'length' instead of 'length + 1' for the null terminator.
            data = new char[length]; // This is an off-by-one error.
            std::strcpy(data, other.data); // This will write past the allocated memory, leading to undefined behavior.
        }
    }

    ~MyString() {
        delete[] data;
    }

    void print() const {
        if (data) {
            std::cout << data; // Likely to print garbage or crash due to missing null terminator or heap corruption.
        } else {
            std::cout << "(empty)";
        }
    }
};

int main() {
    MyString s1("Hello"); // This constructor call will have the logical error
    MyString s2 = s1;     // This copy constructor call will also have the logical error

    std::cout << "s1: ";
    s1.print();
    std::cout << std::endl;

    std::cout << "s2: ";
    s2.print();
    std::cout << std::endl;

    MyString s3("World"); // Another instance with the logical error
    std::cout << "s3: ";
    s3.print();
    std::cout << std::endl;

    MyString s4;
    std::cout << "s4 (empty): ";
    s4.print();
    std::cout << std::endl;

    return 0; // Program might crash here due to heap corruption during destruction
}