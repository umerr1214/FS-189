#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    MyString(const char* s = nullptr) {
        if (s) {
            length = strlen(s);
            data = new char[length + 1];
            strcpy(data, s);
        } else {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor (deep copy)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Getter for the string
    const char* c_str() const {
        return data;
    }

    // Length getter
    size_t size() const {
        return length;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    MyString s1("Hello, World!");
    MyString s2 = s1; // Should use copy constructor
    MyString s3;      // Default constructor

    std::cout << "s1: " << s1.c_str() << std::endl;
    std::cout << "s2: " << s2.c_str() << std::endl;
    std::cout << "s3: " << s3.c_str() << std::endl;

    std::cout << "s1 data address: " << static_cast<void*>(const_cast<char*>(s1.c_str())) << std::endl;
    std::cout << "s2 data address: " << static_cast<void*>(const_cast<char*>(s2.c_str())) << std::endl;

    return 0;
}