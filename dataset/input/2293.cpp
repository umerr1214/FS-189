#include <iostream>
#include <cstring> // For strlen, strcpy
#include <string>  // For std::to_string

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Constructor - Does not robustly handle nullptr input, leading to UB if `nullptr` is passed.
    // For this example, we default to an empty string to avoid immediate crash in main,
    // but the underlying vulnerability exists if `StringWrapper sw(nullptr);` is used.
    StringWrapper(const char* str = "") {
        if (str == nullptr) {
            str = ""; // Still, for basic functionality, we need a valid string.
        }
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        std::cout << "Constructor: " << data << std::endl;
    }

    // Destructor - Memory leak: `delete[] data;` is missing.
    ~StringWrapper() {
        // This line is intentionally commented out to introduce a memory leak.
        // delete[] data;
        std::cout << "Destructor called for: " << (data ? data : "nullptr") << " (memory not freed)" << std::endl;
    }

    // Copy Constructor - Deep Copy (assumes other.data is always valid, if it could be nullptr, it's UB)
    StringWrapper(const StringWrapper& other) {
        // If 'other.data' could somehow be nullptr (e.g., from a flawed constructor or move operation),
        // strlen(other.data) and strcpy(data, other.data) would be undefined behavior.
        // For this example, we assume `other.data` is valid due to the default constructor behavior.
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        std::cout << "Copy Constructor: " << data << std::endl;
    }

    // Copy Assignment Operator (for completeness, though not explicitly asked)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Frees existing memory, but the destructor itself leaks
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        std::cout << "Copy Assignment: " << data << std::endl;
        return *this;
    }

    const char* c_str() const {
        return data;
    }
    size_t size() const {
        return length;
    }
};

int main() {
    std::cout << "--- Testing StringWrapper with Robustness Issues ---" << std::endl;

    // Test Case 1: Basic construction and copy
    StringWrapper s1("HelloLeak");
    StringWrapper s2 = s1; // Calls copy constructor
    std::cout << "s1: " << s1.c_str() << ", s2: " << s2.c_str() << std::endl;

    // Test Case 2: Assignment
    StringWrapper s3("WorldLeak");
    StringWrapper s4; // Default constructor
    s4 = s3; // Calls copy assignment
    std::cout << "s3: " << s3.c_str() << ", s4: " << s4.c_str() << std::endl;

    // Test Case 3: Create multiple short-lived objects to demonstrate memory leak
    std::cout << "\nCreating and destroying several StringWrapper objects (expect memory leaks):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        StringWrapper temp("Loop" + std::to_string(i));
        StringWrapper temp_copy = temp;
        std::cout << "  Temp " << i << ": " << temp.c_str() << ", Copy " << i << ": " << temp_copy.c_str() << std::endl;
    }

    std::cout << "\nEnd of main. Memory leaks are expected due to the missing `delete[] data;` in the destructor." << std::endl;
    std::cout << "Additionally, the constructor and copy constructor are vulnerable to `nullptr` input strings for `strlen` and `strcpy`." << std::endl;

    return 0;
}