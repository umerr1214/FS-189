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
            data = new char[length + 1]; // Correctly allocates for null terminator
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

    // Copy Constructor (SEMANTIC ERROR: Potential off-by-one for null terminator)
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        // SEMANTIC ERROR: Allocates 'length' characters, but `strcpy` needs 'length + 1' for the null terminator.
        // If `other.length` is 0, it allocates 0 bytes, making `strcpy` to `data` undefined behavior.
        // If `other.length` is > 0, it allocates `length` bytes, but `strcpy` will write `length + 1` bytes,
        // leading to a buffer overflow.
        data = new char[length]; // Should be new char[length + 1];
        strcpy(data, other.data);
    }

    // Assignment Operator (Correct deep copy)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Deallocate old memory
        length = other.length;
        data = new char[length + 1]; // Correct allocation
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
    StringWrapper s2 = s1; // Calls the faulty copy constructor

    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl; // Might print "Hello" but memory is corrupted

    StringWrapper s_empty("");
    StringWrapper s_copy_empty = s_empty; // UB here, strcpy to 0-sized array

    std::cout << "s_empty: " << s_empty.getString() << std::endl;
    std::cout << "s_copy_empty: " << s_copy_empty.getString() << std::endl; // Likely crashes or prints garbage

    StringWrapper s3("World");
    s3 = s1; // Calls correct assignment operator

    std::cout << "s1: " << s1.getString() << std::endl;
    std::cout << "s2: " << s2.getString() << std::endl;
    std::cout << "s3: " << s3.getString() << std::endl;

    return 0;
}