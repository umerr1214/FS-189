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

    // Copy Constructor (LOGICAL ERROR: Performs a shallow copy)
    MyString(const MyString& other) : data(other.data), length(other.length) {
        // This performs a shallow copy, copying the pointer 'data' directly.
        // Both objects will point to the same memory location.
        // This will lead to a double-free when both destructors are called,
        // as they attempt to delete the same memory twice.
    }

    // Getter for the string
    const char* c_str() const {
        return data;
    }

    // Length getter
    size_t size() const {
        return length;
    }
};

int main() {
    std::cout << "--- Testing MyString with Logical Error (Shallow Copy) ---" << std::endl;
    MyString s1("Original String");
    std::cout << "s1 (original): " << s1.c_str() << " at " << static_cast<void*>(const_cast<char*>(s1.c_str())) << std::endl;

    MyString s2 = s1; // Calls the shallow copy constructor
    std::cout << "s2 (copied from s1): " << s2.c_str() << " at " << static_cast<void*>(const_cast<char*>(s2.c_str())) << std::endl;

    std::cout << "Note: s1 and s2 data pointers are identical due to shallow copy." << std::endl;
    std::cout << "This program is expected to crash with a double-free error on exit." << std::endl;

    // Additional test to ensure the error consistently occurs
    MyString s3("Another String");
    MyString s4(s3);
    std::cout << "s3: " << s3.c_str() << " at " << static_cast<void*>(const_cast<char*>(s3.c_str())) << std::endl;
    std::cout << "s4: " << s4.c_str() << " at " << static_cast<void*>(const_cast<char*>(s4.c_str())) << std::endl;

    return 0; // Program expected to crash here when destructors are called
}