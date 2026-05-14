#include <iostream>
#include <cstring> // For strlen, strcpy, memcpy

class MyString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    MyString(const char* s = nullptr) {
        if (s) {
            length = strlen(s);
            data = new char[length + 1];
            strcpy(data, s);
        } else {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Constructor (SEMANTIC ERROR: Forgets to null-terminate after memcpy)
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1]; // Allocates enough space for string + null terminator

        // SEMANTIC ERROR: Copies 'length' characters using memcpy,
        // but explicitly forgets to copy or set the null terminator at data[length].
        // This results in an unterminated C-style string, leading to undefined behavior
        // when functions like std::cout or other C-string utilities try to read it.
        memcpy(data, other.data, length);
        // Missing: data[length] = '\0';
    }

    // Getter for the string
    const char* c_str() const {
        return data;
    }

    // Length getter
    size_t size() const {
        return length;
    }
};

int main() {
    std::cout << "--- Testing MyString with Semantic Error (Unaligned Null Terminator) ---" << std::endl;

    MyString s1("Hello"); // Length 5
    MyString s2 = s1;     // Calls copy constructor
    // s2's internal data will contain "Hello" followed by an uninitialized byte.
    // When printed, it might show "Hello" followed by garbage characters, or just "Hello"
    // if the memory after happens to be zero, or could crash if it reads past valid memory.

    std::cout << "s1: " << s1.c_str() << " (len: " << s1.size() << ") at " << static_cast<void*>(const_cast<char*>(s1.c_str())) << std::endl;
    std::cout << "s2: " << s2.c_str() << " (len: " << s2.size() << ") at " << static_cast<void*>(const_cast<char*>(s2.c_str())) << std::endl;
    std::cout << "Note: s2.c_str() might print garbage after 'Hello' or cause issues due to missing null terminator." << std::endl;

    MyString empty_s; // Empty string, length 0, data[0] = '\0'
    MyString copied_empty_s = empty_s; // Copy constructor, memcpy(data, other.data, 0)
    // For an empty string, memcpy copies 0 bytes. data[0] remains uninitialized.
    // Accessing copied_empty_s.c_str() will return a pointer to uninitialized memory.
    std::cout << "empty_s: '" << empty_s.c_str() << "' (len: " << empty_s.size() << ") at " << static_cast<void*>(const_cast<char*>(empty_s.c_str())) << std::endl;
    std::cout << "copied_empty_s: '" << copied_empty_s.c_str() << "' (len: " << copied_empty_s.size() << ") at " << static_cast<void*>(const_cast<char*>(copied_empty_s.c_str())) << std::endl;
    std::cout << "Note: copied_empty_s.c_str() might print garbage or an empty string, but points to uninitialized memory." << std::endl;


    return 0;
}