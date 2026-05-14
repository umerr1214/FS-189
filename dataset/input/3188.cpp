#include <iostream>
#include <cstring> // For strlen
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
    MyString(const char* s) {
        if (s == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(s);
            data = new char[length + 1];
            // Efficiency Issue: Manual loop for copying characters instead of strcpy/memcpy
            for (size_t i = 0; i <= length; ++i) {
                data[i] = s[i];
            }
        }
    }

    // Deep Copy Constructor
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        // Efficiency Issue: Manual loop for copying characters instead of strcpy/memcpy
        for (size_t i = 0; i <= length; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        // Readability/Efficiency Issue: Manual deallocation, allocation, and copying
        // The copy-and-swap idiom would be more robust and concise.
        delete[] data; // Clean up old data
        length = other.length;
        data = new char[length + 1];
        // Efficiency Issue: Manual loop for copying characters instead of strcpy/memcpy
        for (size_t i = 0; i <= length; ++i) {
            data[i] = other.data[i];
        }
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
    s4 = s1; // Assignment
    std::cout << "s4 (assigned s1): '" << s4 << "' (length: " << s4.getLength() << ")" << std::endl;

    MyString s5("Another string");
    s5 = s5; // Self-assignment
    std::cout << "s5 (self-assigned): '" << s5 << "' (length: " << s5.getLength() << ")" << std::endl;

    MyString s6("Short");
    MyString s7("Very Long String That Will Be Assigned");
    s6 = s7;
    std::cout << "s6 (assigned s7): '" << s6 << "' (length: " << s6.getLength() << ")" << std::endl;

    std::cout << "--- End of tests ---" << std::endl;

    return 0;
}