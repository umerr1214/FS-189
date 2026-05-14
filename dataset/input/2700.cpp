#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
private:
    char* data;
    int length;

public:
    // Constructor
    MyString(const char* s = "") {
        if (s == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = strlen(s);
            data = new char[length + 1];
            strcpy(data, s);
        }
    }

    // Destructor - SEMANTIC ERROR HERE
    ~MyString() {
        // Semantic error: Using 'delete' instead of 'delete[]' for a dynamically allocated array.
        // This leads to undefined behavior, potentially memory leaks, heap corruption, or crashes.
        delete data; // Should be delete[] data;
    }

    // Copy Constructor (Deep Copy) - Correct implementation
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Accessor for testing
    const char* c_str() const {
        return data;
    }

    int getLength() const {
        return length;
    }
};

int main() {
    MyString s1("FirstString");
    MyString s2 = s1; // Calls copy constructor
    MyString s3("SecondString"); // Another object

    std::cout << "s1: " << s1.c_str() << ", Length: " << s1.getLength() << std::endl;
    std::cout << "s2: " << s2.c_str() << ", Length: " << s2.getLength() << std::endl;
    std::cout << "s3: " << s3.c_str() << ", Length: " << s3.getLength() << std::endl;

    // When main exits, s1, s2, s3 destructors will be called.
    // The semantic error in the destructor will likely manifest here,
    // potentially causing a crash or memory corruption during program termination.

    return 0;
}