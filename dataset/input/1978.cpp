#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;

public:
    // Default constructor
    StringWrapper(const char* str = "") {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor (deep copy)
    StringWrapper(const StringWrapper& other) {
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Assignment operator (deep copy)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Free old memory
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
        return *this;
    }

    // Accessor
    const char* get() const {
        return data;
    }

    // For testing/output
    void print() const {
        std::cout << "StringWrapper content: \"" << (data ? data : "(null)") << "\"" << std::endl;
    }

// SYNTAX ERROR: Missing closing brace '}' for the StringWrapper class
// This will cause a compilation error.

// Main function to test (outside the malformed class)
int main() {
    std::cout << "--- StringWrapper Test (Syntax Error) ---" << std::endl;

    // The following lines would demonstrate the class functionality
    // if the class definition were syntactically correct.
    StringWrapper s1("Hello World");
    std::cout << "s1: ";
    s1.print();

    StringWrapper s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1): ";
    s2.print();

    std::cout << "\n--- End Test ---" << std::endl;
    return 0;
}