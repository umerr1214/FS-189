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

    // Copy assignment operator with a syntax error
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data; // Free existing resource

        if (other.data) {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }

        return *this // MISSING SEMICOLON HERE
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