#include <iostream>
#include <cstring> // For std::strlen, std::strcpy, std::memcpy

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Parameterized Constructor
    StringWrapper(const char* str = "") {
        if (str == nullptr) {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        } else {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
    }

    // Copy Constructor
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Copy Assignment Operator
    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) { // Crucial self-assignment check
            delete[] data; // Deallocate old memory
            length = other.length;
            data = new char[length + 1]; // Allocate new memory
            std::strcpy(data, other.data); // Copy data
        }
        return *this;
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Helper to get C-style string (const-qualified for correctness)
    const char* c_str() const {
        return data;
    }

    // Helper to get length (const-qualified for correctness)
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
    s1 = s1; // This should now work correctly due to self-assignment check
    std::cout << "Result: " << s1.c_str() << std::endl;

    std::cout << "Test Case: Parameterized constructor (nullptr)" << std::endl;
    StringWrapper s_null(nullptr);
    std::cout << "Result: " << s_null.c_str() << std::endl;

    return 0;
}