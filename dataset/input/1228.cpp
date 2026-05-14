#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;
    size_t length;

    // Default constructor
    StringWrapper(const char* str = "") {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy constructor
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Helper to print string
    void print() const {
        std::cout << data << std::endl;
    }

    // Missing semicolon here, will cause syntax error
}

int main() {
    StringWrapper s1("Hello");
    std::cout << "s1: ";
    s1.print();

    StringWrapper s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1): ";
    s2.print();

    StringWrapper s3("World");
    std::cout << "s3: ";
    s3.print();

    return 0;
}