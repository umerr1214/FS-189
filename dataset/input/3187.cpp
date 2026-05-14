#include <iostream>
#include <cstring> // For strlen, strcpy
#include <algorithm> // For std::swap

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor from C-style string
    // Robustness Issue: Does not handle nullptr for s, leading to crash if nullptr is passed.
    MyString(const char* s) {
        // If s is nullptr, std::strlen(s) causes undefined behavior/crash.
        length = std::strlen(s);
        data = new char[length + 1];
        std::strcpy(data, s);
    }

    // Deep Copy Constructor
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Assignment Operator
    // Robustness Issue: Memory leak. Old 'data' is not deleted before re-allocation.
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this; // Handle self-assignment correctly
        }
        // Memory leak: The memory pointed to by 'data' before this assignment
        // is not deallocated, leading to a leak.
        length = other.length;
        data = new char[length + 1]; // Allocates new memory without freeing old
        std::strcpy(data, other.data);
        return *this;
    }

    // Accessor for C-style string
    const char* c_str() const {
        return data;
    }

    // Get length
    size_t size() const {
        return length;
    }

    size_t getLength() const {
        return length;
    }
};

// Global overloaded operator for output
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.c_str();
    return os;
}

int main() {
    // Test default constructor
    MyString s0;
    std::cout << "s0: '" << s0 << "' (length: " << s0.getLength() << ")" << std::endl;

    // Test constructor with C-style string
    MyString s1("Hello, World!");
    std::cout << "s1: '" << s1 << "' (length: " << s1.getLength() << ")" << std::endl;

    MyString s2("");
    std::cout << "s2: '" << s2 << "' (length: " << s2.getLength() << ")" << std::endl;

    // Test copy constructor
    MyString s3 = s1;
    std::cout << "s3 (copy of s1): '" << s3 << "' (length: " << s3.getLength() << ")" << std::endl;

    // Test copy assignment operator
    MyString s4("Initial string");
    std::cout << "s4 (initial): '" << s4 << "' (length: " << s4.getLength() << ")" << std::endl;
    s4 = s1; // Assignment (demonstrates memory leak for s4's old data)
    std::cout << "s4 (assigned s1): '" << s4 << "' (length: " << s4.getLength() << ")" << std::endl;

    MyString s5("Another string");
    s5 = s5; // Self-assignment (handled, but still has the leak vulnerability if not self-assignment)
    std::cout << "s5 (self-assigned): '" << s5 << "' (length: " << s5.getLength() << ")" << std::endl;

    MyString s6("Short");
    MyString s7("Very Long String That Will Be Assigned");
    s6 = s7; // Assignment (demonstrates memory leak for s6's old data)
    std::cout << "s6 (assigned s7): '" << s6 << "' (length: " << s6.getLength() << ")" << std::endl;

    // NOTE: Passing nullptr to MyString(const char* s) would crash the program.
    // MyString crash_string(nullptr); // This line is commented out to allow the driver to run.

    std::cout << "--- End of tests ---" << std::endl;

    return 0;
}