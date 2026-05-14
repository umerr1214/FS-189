#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;

public:
    // Default constructor
    StringWrapper() : data(nullptr) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Constructor from C-style string
    StringWrapper(const char* str) : data(nullptr) {
        std::cout << "Constructor(const char*) called for: " << (str ? str : "nullptr") << std::endl;
        if (str) {
            data = new char[std::strlen(str) + 1];
            std::strcpy(data, str);
        }
    }

    // Deep copy constructor
    StringWrapper(const StringWrapper& other) : data(nullptr) {
        std::cout << "Copy constructor called for: " << (other.data ? other.data : "nullptr") << std::endl;
        if (other.data) {
            data = new char[std::strlen(other.data) + 1];
            std::strcpy(data, other.data);
        }
    }

    // Accessor
    const char* get() const {
        return data ? data : ""; // Return empty string for nullptr for easier printing
    }

    // ROBUSTNESS ISSUE: MISSING DESTRUCTOR
    // The dynamically allocated memory for 'data' is never freed,
    // leading to memory leaks.
    // ~StringWrapper() {
    //     std::cout << "Destructor called for: " << (data ? data : "nullptr") << std::endl;
    //     delete[] data;
    // }
};

// Function to demonstrate objects going out of scope
void test_function_scope() {
    StringWrapper s1("Hello");
    StringWrapper s2 = s1; // Calls copy constructor
    StringWrapper s3("World");
    std::cout << "s1 in scope: " << s1.get() << std::endl;
    std::cout << "s2 in scope: " << s2.get() << std::endl;
    std::cout << "s3 in scope: " << s3.get() << std::endl;
    // s1, s2, s3 go out of scope here, but their memory is not freed due to missing destructor.
}

int main() {
    std::cout << "--- Test Case 1: Basic construction and copy ---" << std::endl;
    StringWrapper original("First String");
    StringWrapper copy = original; // Deep copy constructor
    std::cout << "Original: " << original.get() << std::endl;
    std::cout << "Copy: " << copy.get() << std::endl;

    std::cout << "\n--- Test Case 2: Empty string and nullptr handling ---" << std::endl;
    StringWrapper empty_str("");
    StringWrapper null_str(nullptr);
    StringWrapper copy_empty = empty_str;
    StringWrapper copy_null = null_str;
    std::cout << "Empty String: " << empty_str.get() << std::endl;
    std::cout << "Null String: " << null_str.get() << std::endl;
    std::cout << "Copy Empty: " << copy_empty.get() << std::endl;
    std::cout << "Copy Null: " << copy_null.get() << std::endl;

    std::cout << "\n--- Test Case 3: Objects in function scope (demonstrates memory leak) ---" << std::endl;
    test_function_scope(); // Memory allocated here will leak

    std::cout << "\nProgram finished. Memory leaks expected due to missing destructor." << std::endl;
    return 0;
}