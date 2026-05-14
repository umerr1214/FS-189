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

    // Copy constructor (deep copy - LOGICAL ERROR: missing +1 for null terminator)
    StringWrapper(const StringWrapper& other) {
        if (other.data) {
            // LOGICAL ERROR: Allocates strlen(other.data) bytes instead of strlen(other.data) + 1
            // This means there's no space for the null terminator, leading to a buffer overflow
            // when strcpy attempts to write it.
            data = new char[strlen(other.data)];
            strcpy(data, other.data); // Writes past allocated memory
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Assignment operator (correct deep copy)
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
};

// Main function to test
int main() {
    std::cout << "--- StringWrapper Test (Logical Error) ---" << std::endl;

    // Test Case 1: Short string - might not immediately crash but is corrupted
    StringWrapper s1("Short"); // Length 5
    std::cout << "s1: ";
    s1.print(); // Expected: "Short"

    StringWrapper s2 = s1; // Calls copy constructor with logical error
    std::cout << "s2 (copy of s1): ";
    s2.print(); // Actual: Might print "Short" but with memory corruption, or crash.

    // Test Case 2: Longer string to make buffer overflow more apparent
    std::cout << "\n--- Longer String Test ---" << std::endl;
    StringWrapper s3("LongerStringExample"); // Length 19
    std::cout << "s3: ";
    s3.print();

    StringWrapper s4 = s3; // Calls copy constructor with logical error
    std::cout << "s4 (copy of s3): ";
    s4.print(); // Actual: Likely to show corrupted data or crash due to writing past allocated buffer.

    std::cout << "\n--- End Test ---" << std::endl;
    return 0;
}