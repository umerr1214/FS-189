#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Constructor - Robustness Issue: Does not check for nullptr str before strlen
    // Calling std::strlen(nullptr) leads to undefined behavior, often a crash.
    StringWrapper(const char* str) : data(nullptr), length(0) {
        // ISSUE: If 'str' is nullptr, std::strlen(str) will cause a segmentation fault
        // or other undefined behavior, making the class fragile.
        length = std::strlen(str); // CRASH/UB if str is nullptr
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
        data = nullptr;
    }

    // Copy Constructor
    StringWrapper(const StringWrapper& other) : data(nullptr), length(other.length) {
        if (other.data) { // Check if 'other' has valid data to copy
            data = new char[length + 1];
            std::strcpy(data, other.data);
        } else {
            // Handle case where 'other' might be an empty/null-initialized StringWrapper
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }

    // Accessor for the string data
    const char* getString() const {
        return data ? data : ""; // Return empty string literal for nullptr to avoid UB in caller
    }

    // Accessor for the string length
    size_t getLength() const {
        return length;
    }
};

int main() {
    // Test case for robustness issue: passing nullptr to constructor
    try {
        std::cout << "Creating StringWrapper with a normal string:" << std::endl;
        StringWrapper s1("Hello Robustness");
        std::cout << "s1: \"" << s1.getString() << "\", Length: " << s1.getLength() << std::endl;

        std::cout << "\nAttempting to create StringWrapper with nullptr (EXPECTED CRASH/UB):" << std::endl;
        // This line will cause undefined behavior (likely a crash) due to strlen(nullptr)
        StringWrapper s_null(nullptr); 
        std::cout << "s_null: \"" << s_null.getString() << "\", Length: " << s_null.getLength() << std::endl; // This line might not be reached
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred before or during StringWrapper construction." << std::endl;
    }

    return 0;
}