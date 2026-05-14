#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;

    // Constructor: Deep copy the C-style string
    StringWrapper(const char* s) {
        if (s == nullptr) {
            data = new char[1];
            data[0] = '\0';
        } else {
            size_t len = strlen(s);
            data = new char[len]; // LOGICAL ERROR: Should be len + 1 to include null terminator
            strcpy(data, s);      // This will write past the allocated memory for non-empty strings
        }
    }

    // Destructor: Release dynamically allocated memory
    ~StringWrapper() {
        delete[] data;
    }

    // Getter for the string
    const char* getString() const {
        return data;
    }
};

int main() {
    std::cout << "--- Test Case 1 ---" << std::endl;
    StringWrapper s1("Hello World");
    std::cout << "Wrapped string: " << s1.getString() << std::endl;

    std::cout << "--- Test Case 2 ---" << std::endl;
    StringWrapper s2("C++ Programming");
    std::cout << "Wrapped string: " << s2.getString() << std::endl;

    std::cout << "--- Test Case 3 ---" << std::endl;
    StringWrapper s3(""); // Test empty string
    std::cout << "Wrapped string: " << s3.getString() << std::endl;
    
    std::cout << "--- Test Case 4 ---" << std::endl;
    StringWrapper s4("Short");
    std::cout << "Wrapped string: " << s4.getString() << std::endl;

    return 0;
}