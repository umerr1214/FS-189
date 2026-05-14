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

    // Copy Constructor (LOGICAL ERROR: SHALLOW COPY)
    StringWrapper(const StringWrapper& other) {
        // This performs a shallow copy. Both 'this->data' and 'other.data' will point to the same memory.
        // This violates the requirement for independent memory management and will lead to a double-free error
        // when both the original and copied objects are destructed.
        this->data = other.data;
        this->length = other.length;
    }

    // Assignment Operator (Correct deep copy)
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
};

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2 = s1; // Calls the faulty copy constructor (shallow copy)

    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;

    StringWrapper s3("World");
    s3 = s1; // Calls correct assignment operator, but s1's data is shared with s2

    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;

    // Program will likely crash at the end of main due to double-free when s1 and s2 are destructed.

    return 0;
}