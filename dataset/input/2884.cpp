#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;
    size_t length;

    StringWrapper(const char* str = nullptr) {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy Constructor (deep copy)
    StringWrapper(const StringWrapper& other) {
        if (other.data) {
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    void print() const {
        if (data) {
            std::cout << "String: \"" << data << "\", Length: " << length << std::endl;
        } else {
            std::cout << "String: (null), Length: " << length << std::endl;
        }
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    std::cout << "--- Attempting to compile (Syntax Error) ---" << std::endl;
    StringWrapper s1("Hello World");
    std::cout << "s1 created: ";
    s1.print();

    StringWrapper s2 = s1; // Test copy constructor
    std::cout << "s2 copied from s1: ";
    s2.print();

    StringWrapper s_empty;
    std::cout << "s_empty created: ";
    s_empty.print();

    std::cout << "This program contains a syntax error and will not compile." << std::endl;

    return 0;
}