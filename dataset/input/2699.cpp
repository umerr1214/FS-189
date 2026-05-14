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

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor (Deep Copy) - LOGICAL ERROR HERE
    MyString(const MyString& other) {
        length = other.length;
        // Logical error: Allocating 'length' bytes instead of 'length + 1'
        // This omits space for the null terminator, leading to potential buffer overflow
        // or undefined behavior when strcpy writes past the allocated memory.
        data = new char[length]; // Should be length + 1
        strcpy(data, other.data); // This will write past the allocated buffer if length > 0
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
    MyString s1("HelloWorld");
    MyString s2 = s1; // Calls copy constructor with logical error

    std::cout << "s1: " << s1.c_str() << ", Length: " << s1.getLength() << std::endl;
    std::cout << "s2: " << s2.c_str() << ", Length: " << s2.getLength() << std::endl; // s2 might show garbage or crash

    MyString s3("Short");
    MyString s4 = s3; // Another copy
    std::cout << "s3: " << s3.c_str() << ", Length: " << s3.getLength() << std::endl;
    std::cout << "s4: " << s4.c_str() << ", Length: " << s4.getLength() << std::endl; // s4 might show garbage or crash

    MyString s5(""); // Test empty string case
    MyString s6 = s5;
    std::cout << "s5: " << s5.c_str() << ", Length: " << s5.getLength() << std::endl;
    std::cout << "s6: " << s6.c_str() << ", Length: " << s6.getLength() << std::endl; // Should be fine for empty string

    return 0;
}