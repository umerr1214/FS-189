#include <iostream>
#include <cstring> // For strlen

class StringWrapper {
public:
    char* str;

    // Default constructor
    StringWrapper() {
        str = new char[1];
        str[0] = '\0';
    }

    // Constructor from C-string
    StringWrapper(const char* s) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

    // Copy constructor (Readability/Efficiency Issue: Inefficient manual copy loop)
    StringWrapper(const StringWrapper& other) {
        size_t len = std::strlen(other.str); // Calculate length once
        str = new char[len + 1];
        // PROBLEM: This manual character-by-character copy loop is less efficient
        // and less readable than using a standard library function like std::strcpy.
        // While 'len' is calculated once, the loop itself is a less optimal way
        // to copy a C-style string compared to optimized library functions.
        for (size_t i = 0; i <= len; ++i) { // Copies null terminator too
            str[i] = other.str[i];
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] str;
    }

    // Helper to print the string
    const char* c_str() const {
        return str;
    }
};

int main() {
    StringWrapper s1("Hello, World!");
    std::cout << "s1: " << s1.c_str() << std::endl;

    // Copy s1 to s2 using the copy constructor
    StringWrapper s2 = s1;
    std::cout << "s2 (copied from s1): " << s2.c_str() << std::endl;

    // Modify s1 to ensure deep copy and independent memory management
    // (This part works correctly, demonstrating deep copy, but the mechanism is inefficient)
    s1.str[0] = 'h';
    s1.str[7] = 'w';
    std::cout << "s1 (modified): " << s1.c_str() << std::endl;
    std::cout << "s2 (should be unchanged): " << s2.c_str() << std::endl;

    StringWrapper s3("");
    StringWrapper s4 = s3;
    std::cout << "s3 (empty): '" << s3.c_str() << "'" << std::endl;
    std::cout << "s4 (copied from s3): '" << s4.c_str() << "'" << std::endl;

    StringWrapper s5("Short");
    StringWrapper s6 = s5;
    std::cout << "s5: " << s5.c_str() << std::endl;
    std::cout << "s6 (copied from s5): " << s6.c_str() << std::endl;

    return 0;
}