#include <iostream>
#include <cstring> // For strlen, but not strcpy (demonstrates inefficiency)

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
            size_t len = std::strlen(str);
            data = new char[len + 1];
            // READABILITY / EFFICIENCY ISSUE: Inefficient and verbose manual character copy loop
            for (size_t i = 0; i <= len; ++i) { // Copy null terminator too
                data[i] = str[i];
            }
        }
    }

    // Deep copy constructor
    StringWrapper(const StringWrapper& other) : data(nullptr) {
        std::cout << "Copy constructor called for: " << (other.data ? other.data : "nullptr") << std::endl;
        if (other.data) {
            size_t len = std::strlen(other.data);
            data = new char[len + 1];
            // READABILITY / EFFICIENCY ISSUE: Inefficient and verbose manual character copy loop
            for (size_t i = 0; i <= len; ++i) { // Copy null terminator too
                data[i] = other.data[i];
            }
        }
    }

    // Destructor
    ~StringWrapper() {
        std::cout << "Destructor called for: " << (data ? data : "nullptr") << std::endl;
        delete[] data;
    }

    // Accessor
    const char* get() const {
        return data ? data : ""; // Return empty string for nullptr for easier printing
    }
};

int main() {
    std::cout << "--- Test Case 1: Basic construction and copy ---" << std::endl;
    StringWrapper original("Hello Cpp");
    StringWrapper copy = original;
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

    std::cout << "\n--- Test Case 3: Short string (demonstrates deep copy) ---" << std::endl;
    StringWrapper s_short("abc");
    StringWrapper s_short_copy = s_short;
    std::cout << "Short original: " << s_short.get() << std::endl;
    std::cout << "Short copy: " << s_short_copy.get() << std::endl;

    std::cout << "\nProgram finished." << std::endl;
    return 0;
}