#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
public:
    char* data;
    size_t length;

    MyString(const char* s = nullptr) : data(nullptr), length(0) {
        if (s) {
            length = std::strlen(s);
            data = new char[length + 1];
            std::strcpy(data, s);
        }
    }

    // Deep Copy Constructor
    MyString(const MyString& other) : data(nullptr), length(other.length) {
        if (other.data) {
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
    }

    ~MyString() {
        delete[] data;
    }

    void print() const {
        if (data) {
            std::cout << data;
        } else {
            std::cout << "(empty)";
        }
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    MyString s1("Hello, World!");
    MyString s2 = s1; // Should invoke deep copy constructor

    std::cout << "Original string (s1): ";
    s1.print();
    std::cout << std::endl;

    std::cout << "Copied string (s2): ";
    s2.print();
    std::cout << std::endl;

    MyString s3; // Test default constructor
    std::cout << "Empty string (s3): ";
    s3.print();
    std::cout << std::endl;

    return 0;
}