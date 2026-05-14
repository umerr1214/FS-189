#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    StringWrapper() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor with const char*
    StringWrapper(const char* str) {
        if (str == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy constructor (deep copy)
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Assignment operator
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        return *this;
    }

    // Assignment operator from const char*
    StringWrapper& operator=(const char* str) {
        delete[] data;
        if (str == nullptr) {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
        return *this;
    }

    // Getter for string data
    const char* get() const {
        return data;
    }

    size_t size() const {
        return length;
    }

    void print() const {
        std::cout << "String: \"" << data << "\" (Length: " << length << ")" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    // This program is expected to fail compilation due to a syntax error.
    // The driver code below is illustrative and would not be executed.
    std::cout << "Attempting to create StringWrapper objects..." << std::endl;
    StringWrapper s1("Hello World");
    std::cout << "s1 created." << std::endl;
    s1.print();

    StringWrapper s2 = s1; // Copy constructor
    std::cout << "s2 created via copy constructor." << std::endl;
    s2.print();

    StringWrapper s3;
    s3 = "Programming"; // Assignment operator
    std::cout << "s3 assigned." << std::endl;
    s3.print();

    std::cout << "Program would continue if compiled successfully." << std::endl;

    return 0;
}