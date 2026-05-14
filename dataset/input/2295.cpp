#include <iostream>
#include <cstring> // For strlen, strcpy
#include <string>  // For std::to_string

class StringWrapper {
private:
    char* data;
    size_t length;

    // Helper function for deep copy logic, handles nullptr source
    void deepCopy(const char* source) {
        if (source == nullptr) {
            data = nullptr;
            length = 0;
            return;
        }
        length = strlen(source);
        data = new char[length + 1]; // +1 for null terminator
        strcpy(data, source);
    }

public:
    // Constructor - Handles nullptr input gracefully
    StringWrapper(const char* str = nullptr) : data(nullptr), length(0) {
        std::cout << "Constructor: ";
        deepCopy(str);
        std::cout << (data ? data : "nullptr") << std::endl;
    }

    // Destructor - Frees dynamically allocated memory
    ~StringWrapper() {
        std::cout << "Destructor called for: " << (data ? data : "nullptr") << std::endl;
        delete[] data; // Free the allocated C-style string
        data = nullptr; // Good practice to nullify pointer after deletion
        length = 0;
    }

    // Copy Constructor - Performs a deep copy of the string data
    StringWrapper(const StringWrapper& other) : data(nullptr), length(0) {
        std::cout << "Copy Constructor: ";
        deepCopy(other.data); // Use helper for deep copy
        std::cout << (data ? data : "nullptr") << std::endl;
    }

    // Copy Assignment Operator - Handles self-assignment and deep copy
    StringWrapper& operator=(const StringWrapper& other) {
        std::cout << "Copy Assignment: ";
        if (this == &other) {
            std::cout << " (self-assignment) " << (data ? data : "nullptr") << std::endl;
            return *this;
        }

        // 1. Free existing resources to prevent memory leak
        delete[] data;
        data = nullptr;
        length = 0;

        // 2. Perform deep copy of the new data
        deepCopy(other.data);
        std::cout << (data ? data : "nullptr") << std::endl;
        return *this;
    }

    // Getter for the C-style string
    const char* c_str() const {
        return data ? data : ""; // Return empty string literal for nullptr to be safe
    }

    // Getter for the string length
    size_t size() const {
        return length;
    }
};

int main() {
    std::cout << "--- Test Case 1: Basic Construction and Copy ---" << std::endl;
    StringWrapper s1("Hello, C++");
    StringWrapper s2 = s1; // Calls copy constructor
    std::cout << "s1: '" << s1.c_str() << "' (len: " << s1.size() << ")" << std::endl;
    std::cout << "s2: '" << s2.c_str() << "' (len: " << s2.size() << ")" << std::endl;

    std::cout << "\n--- Test Case 2: Copy Assignment ---" << std::endl;
    StringWrapper s3("World");
    StringWrapper s4; // Default constructor (initializes to nullptr/empty)
    s4 = s3; // Calls copy assignment operator
    std::cout << "s3: '" << s3.c_str() << "' (len: " << s3.size() << ")" << std::endl;
    std::cout << "s4: '" << s4.c_str() << "' (len: " << s4.size() << ")" << std::endl;

    std::cout << "\n--- Test Case 3: Self-Assignment ---" << std::endl;
    s4 = s4; // Calls copy assignment (self-assignment handled)
    std::cout << "s4 after self-assignment: '" << s4.c_str() << "' (len: " << s4.size() << ")" << std::endl;

    std::cout << "\n--- Test Case 4: Construction with nullptr ---" << std::endl;
    StringWrapper s_null(nullptr);
    std::cout << "s_null: '" << s_null.c_str() << "' (len: " << s_null.size() << ")" << std::endl;

    std::cout << "\n--- Test Case 5: Copy from nullptr object ---" << std::endl;
    StringWrapper s_copy_null = s_null;
    std::cout << "s_copy_null: '" << s_copy_null.c_str() << "' (len: " << s_copy_null.size() << ")" << std::endl;

    std::cout << "\n--- Test Case 6: Short-lived objects ---" << std::endl;
    for (int i = 0; i < 3; ++i) {
        StringWrapper temp("Loop " + std::to_string(i));
        StringWrapper temp_copy = temp;
        std::cout << "  Temp " << i << ": '" << temp.c_str() << "', Copy " << i << ": '" << temp_copy.c_str() << "'" << std::endl;
    }

    std::cout << "\nEnd of main. All memory should be properly managed and deep copies successful." << std::endl;

    return 0;
}