#include <iostream>
#include <cstring> // For std::strlen, std::strcpy

class StringWrapper {
private:
    char* data;
    size_t length;

    // Manual strlen for readability/efficiency issue
    size_t manual_strlen(const char* s) {
        size_t len = 0;
        if (s) { // Add a check to prevent crash on nullptr
            while (s[len] != '\0') {
                len++;
            }
        }
        return len;
    }

    // Manual strcpy for readability/efficiency issue
    void manual_strcpy(char* dest, const char* src) {
        if (!dest || !src) return; // Basic check
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    // Parameterized Constructor - uses manual string ops
    StringWrapper(const char* str = "") {
        if (str == nullptr) {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        } else {
            length = manual_strlen(str); // Inefficient: manual implementation
            data = new char[length + 1];
            manual_strcpy(data, str); // Inefficient: manual implementation
        }
    }

    // Copy Constructor - uses manual string ops
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        manual_strcpy(data, other.data); // Inefficient: manual implementation
    }

    // Copy Assignment Operator - Readability/Efficiency Issue: Redundant strlen, always reallocates
    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) {
            // Inefficient: Always reallocates memory even if current buffer is sufficient.
            // Also, `other.length` is already available, no need to call `manual_strlen(other.data)` again.
            delete[] data;
            length = manual_strlen(other.data); // Redundant strlen call, length is already available in other.length
            data = new char[length + 1];
            manual_strcpy(data, other.data); // Inefficient: manual implementation
        }
        return *this;
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Helper to get C-style string - Missing const
    char* c_str() { // Readability/Efficiency Issue: Should be 'const char* c_str() const'
        return data;
    }

    // Helper to get length
    size_t size() const {
        return length;
    }
};

int main() {
    std::cout << "Test Case: Parameterized constructor (valid string)" << std::endl;
    StringWrapper s1("Hello");
    std::cout << "Result: " << s1.c_str() << std::endl;

    std::cout << "Test Case: Copy constructor" << std::endl;
    StringWrapper s2 = s1;
    std::cout << "Result: " << s2.c_str() << std::endl;

    std::cout << "Test Case: Default constructor (empty string)" << std::endl;
    StringWrapper s3;
    std::cout << "Result: " << s3.c_str() << std::endl;

    std::cout << "Test Case: Copy assignment (normal)" << std::endl;
    StringWrapper s4("World");
    s3 = s4;
    std::cout << "Result: " << s3.c_str() << std::endl;

    std::cout << "Test Case: Assignment to empty string" << std::endl;
    StringWrapper s5("Short");
    StringWrapper s_empty;
    s5 = s_empty;
    std::cout << "Result: " << s5.c_str() << std::endl;

    std::cout << "Test Case: Assignment from longer to shorter" << std::endl;
    StringWrapper s6("VeryLongStringIndeed");
    s6 = s4; // "World"
    std::cout << "Result: " << s6.c_str() << std::endl;

    std::cout << "Test Case: Self-assignment (s1 = s1)" << std::endl;
    s1 = s1;
    std::cout << "Result: " << s1.c_str() << std::endl;

    std::cout << "Test Case: Parameterized constructor (nullptr)" << std::endl;
    StringWrapper s_null(nullptr);
    std::cout << "Result: " << s_null.c_str() << std::endl;

    return 0;
}