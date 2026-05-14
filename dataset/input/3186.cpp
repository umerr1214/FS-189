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

    // SEMANTIC ERROR: This is a shallow copy constructor, not a deep copy.
    // It copies the pointer 'data' directly instead of allocating new memory and copying content.
    // This leads to multiple MyString objects owning the same memory, causing double-free issues
    // when destructors are called.
    MyString(const MyString& other) : data(other.data), length(other.length) {
        // No new allocation here, just copying the pointer.
        // This violates the requirement for a deep copy.
    }

    ~MyString() {
        // This destructor will attempt to delete the same memory multiple times
        // if objects were created using the shallow copy constructor, leading to a double-free runtime error.
        delete[] data;
    }

    void print() const {
        if (data) {
            std::cout << data;
        } else {
            std::cout << "(empty)";
        }
    }
};

int main() {
    MyString s1("First String");
    MyString s2 = s1; // Invokes the shallow copy constructor. s1.data and s2.data point to the same memory.

    std::cout << "s1: ";
    s1.print();
    std::cout << std::endl;

    std::cout << "s2: ";
    s2.print();
    std::cout << std::endl;

    // If we were to modify s1, s2 would also be affected (not explicitly shown here, but a consequence).

    MyString s3("Another");
    MyString s4(s3); // Another shallow copy.

    std::cout << "s3: ";
    s3.print();
    std::cout << std::endl;

    std::cout << "s4: ";
    s4.print();
    std::cout << std::endl;

    // Upon exiting main, destructors for s4, s3, s2, s1 will be called.
    // s4 will delete the memory pointed to by s3.data.
    // Then s3 will try to delete the SAME memory again -> DOUBLE FREE.
    // The same will happen for s2 and s1.
    return 0; // Program will likely crash due to a double-free error.
}