#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor from C-string
    MyString(const char* str) : length(0) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Accessor
    const char* c_str() const {
        return data;
    }

    size_t getLength() const {
        return length;
    }

    // Syntax error: Missing return type 'MyString&' for the operator=
    operator=(const MyString& other) { // ERROR: 'MyString&' is missing
        if (this == &other) {
            return *this;
        }
        
        delete[] data; // Free old memory
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        
        return *this;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3;

    std::cout << "s1: " << s1.c_str() << ", Length: " << s1.getLength() << std::endl;
    std::cout << "s2: " << s2.c_str() << ", Length: " << s2.getLength() << std::endl;

    // This line will cause a compilation error due to the syntax error in operator=
    // If it were to compile, it would assign s1 to s3.
    // s3 = s1; 

    // std::cout << "s3 after s3 = s1: " << s3.c_str() << ", Length: " << s3.getLength() << std::endl;

    // MyString s4("Test");
    // s4 = s4; // Self-assignment

    // std::cout << "s4 after self-assignment: " << s4.c_str() << ", Length: " << s4.getLength() << std::endl;

    // MyString s5("Long string");
    // MyString s6("Short");
    // s5 = s6; // Assign shorter to longer
    // std::cout << "s5 after s5 = s6: " << s5.c_str() << ", Length: " << s5.getLength() << std::endl;

    return 0;
}