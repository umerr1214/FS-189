#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Constructor
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

    // Copy Constructor (Deep Copy)
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Assignment Operator (Deep Copy)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Deallocate old memory
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        return *this;
    }

    // Getter
    const char* getString() const {
        return data;
    }

    size_t getLength() const {
        return length;
    }
}; // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2 = s1; // Calls copy constructor
    StringWrapper s3("World");
    s3 = s1; // Calls assignment operator

    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;

    return 0;
}