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

    // Destructor
    ~StringWrapper() {
        std::cout << "Destructor called for: " << (data ? data : "nullptr") << std::endl;
        delete[] data;
    }

    // Accessor
    const char* get() const {
        return data ? data : ""; // Return empty string for nullptr for easier printing
    }

    // Optional: Copy assignment operator for completeness (not strictly asked but good practice for resource management)
    StringWrapper& operator=(const StringWrapper& other) {
        std::cout << "Copy assignment operator called." << std::endl;
        if (this != &other) { // Handle self-assignment
            delete[] data; // Free existing resource
            data = nullptr; // Reset to nullptr
            if (other.data) {
                data = new char[std::strlen(other.data) + 1];
                std::strcpy(data, other.data);
            }
        }
        return *this;
    }
};

int main() {
    std::cout << "--- Test Case 1: Basic construction and copy ---" << std::endl;
    StringWrapper s1("Hello, World!");
    StringWrapper s2 = s1; // Calls deep copy constructor
    std::cout << "s1: " << s1.get() << std::endl;
    std::cout << "s2: " << s2.get() << std::endl;

    std::cout << "\n--- Test Case 2: Empty string and nullptr handling ---" << std::endl;
    StringWrapper s_empty("");
    StringWrapper s_null(nullptr);
    StringWrapper s_copy_empty = s_empty;
    StringWrapper s_copy_null = s_null;
    std::cout << "s_empty: " << s_empty.get() << std::endl;
    std::cout << "s_null: " << s_null.get() << std::endl;
    std::cout << "s_copy_empty: " << s_copy_empty.get() << std::endl;
    std::cout << "s_copy_null: " << s_copy_null.get() << std::endl;

    std::cout << "\n--- Test Case 3: Objects going out of scope ---" << std::endl;
    {
        StringWrapper temp_str("Temporary String");
        StringWrapper temp_copy = temp_str;
        std::cout << "Inside scope - temp_str: " << temp_str.get() << std::endl;
        std::cout << "Inside scope - temp_copy: " << temp_copy.get() << std::endl;
    } // temp_str and temp_copy destructors called here

    std::cout << "\nProgram finished. All memory should be properly managed." << std::endl;
    return 0;
}