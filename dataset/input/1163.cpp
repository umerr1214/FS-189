#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;

    // Default constructor
    StringWrapper(const char* s = nullptr) : data(nullptr) {
        if (s) {
            data = new char[strlen(s) + 1];
            strcpy(data, s);
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy constructor
    StringWrapper(const StringWrapper& other) : data(nullptr) {
        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
    }

    // Helper to get C-string (for testing)
    const char* c_str() const {
        return data ? data : "";
    }

    // Copy assignment operator with a logical error: shallow copy and no self-assignment check
    StringWrapper& operator=(const StringWrapper& other) {
        // ERROR: No self-assignment check. If this == &other, 'data' will be deleted
        // before 'other.data' can be copied, leading to 'other.data' being invalid.

        delete[] data; // This is problematic for self-assignment and potential double-free.

        // ERROR: Shallow copy. Both 'this->data' and 'other.data' will point to the same memory.
        // When 'other' is destroyed, it will delete the memory, making 'this->data' a dangling pointer.
        // If 'this' is destroyed later, it will attempt to delete already freed memory (double-free).
        data = other.data; // This is the shallow copy

        return *this;
    }
};

void run_tests() {
    StringWrapper s1("Hello"); StringWrapper s2("World"); s1 = s2;
    std::cout << "s1: " << s1.c_str() << "\n";
    std::cout << "s2: " << s2.c_str() << "\n";

    StringWrapper s3("SelfAssign"); s3 = s3;
    std::cout << "s3: " << s3.c_str() << "\n";

    StringWrapper s4("Short"); StringWrapper s5("VeryLongString"); s4 = s5;
    std::cout << "s4: " << s4.c_str() << "\n";

    StringWrapper s6("AnotherLongString"); StringWrapper s7("Tiny"); s6 = s7;
    std::cout << "s6: " << s6.c_str() << "\n";

    StringWrapper s8("A"); StringWrapper s9("B"); StringWrapper s10("C"); s8 = s9 = s10;
    std::cout << "s8: " << s8.c_str() << "\n";
    std::cout << "s9: " << s9.c_str() << "\n";
    std::cout << "s10: " << s10.c_str() << "\n";
}

int main() {
    run_tests();
    return 0;
}