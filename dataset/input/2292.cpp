#include <iostream>
#include <cstring> // For strlen, strcpy, memcpy

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

    // Copy constructor (SEMANTIC ERROR: Fails to null-terminate the copied string)
    StringWrapper(const StringWrapper& other) {
        length = other.length;
        // Allocate exactly 'length' bytes, which is one byte too few for null termination.
        // Even if 'length + 1' was used, memcpy copies only 'length' characters,
        // leaving the last byte uninitialized or not explicitly set to '\0'.
        data = new char[length]; // Should be 'length + 1'
        std::memcpy(data, other.data, length); // Copies 'length' characters, but not the null terminator
        // Missing: data[length] = '\0';
    }

    // Assignment operator (correctly implemented deep copy for comparison)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data); // This correctly copies the null terminator
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
        // This line will cause undefined behavior when 'data' is not null-terminated,
        // as std::cout << char* expects a null-terminated string.
        std::cout << "String: \"" << data << "\" (Length reported: " << length << ", Actual C-string length: " << std::strlen(data) << ")" << std::endl;
    }
};

int main() {
    std::cout << "--- Test 1: Original String ---" << std::endl;
    StringWrapper s1("Hello");
    std::cout << "s1: "; s1.print(); // Should print "Hello" correctly

    std::cout << "\n--- Test 2: Copied String (Semantic Error) ---" << std::endl;
    StringWrapper s2 = s1; // Calls copy constructor with semantic error
    // The string 'data' in s2 is NOT null-terminated.
    // Printing it will lead to reading past allocated memory (Undefined Behavior).
    std::cout << "s2 (copy of s1): "; s2.print(); // Expect garbage or crash due to missing null terminator

    std::cout << "\n--- Test 3: Another Original String ---" << std::endl;
    StringWrapper s3("World!");
    std::cout << "s3: "; s3.print();

    std::cout << "\n--- Test 4: Copied String from s3 ---" << std::endl;
    StringWrapper s4 = s3; // Calls copy constructor with semantic error
    std::cout << "s4 (copy of s3): "; s4.print(); // Expect garbage or crash

    std::cout << "\n--- Test 5: Assignment Operator (Correct) ---" << std::endl;
    StringWrapper s5;
    s5 = s1; // Uses correctly implemented assignment operator
    std::cout << "s5 (assigned from s1): "; s5.print(); // Should print "Hello" correctly

    std::cout << "\nProgram finished. Expect undefined behavior (garbage output or crash) for copied strings." << std::endl;

    return 0;
}