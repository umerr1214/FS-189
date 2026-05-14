#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor from C-string
    MyString(const char* str) : length(0) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Accessor
    const char* c_str() const {
        return data;
    }

    size_t getLength() const {
        return length;
    }

    // Semantic error: Deleting old data BEFORE checking for self-assignment.
    // If 'this' and 'other' are the same object, 'data' points to 'other.data'.
    // Deleting 'data' here invalidates 'other.data', leading to use-after-free
    // when std::strcpy attempts to read from 'other.data' later.
    MyString& operator=(const MyString& other) {
        // PROBLEM: delete happens before self-assignment check.
        // If 'this' == '&other', then 'data' is the same pointer as 'other.data'.
        // Deleting 'data' here means 'other.data' is also deleted (and freed).
        delete[] data; // This line is moved too early!

        if (this == &other) { // Self-assignment check comes too late
            // At this point, 'data' (and 'other.data') has already been freed.
            // Returning *this means returning a corrupted object.
            return *this; 
        }

        length = other.length;
        data = new char[length + 1];
        // CRASH/UNDEFINED BEHAVIOR if self-assignment occurred,
        // because std::strcpy tries to read from 'other.data' which is freed memory.
        std::strcpy(data, other.data); 

        return *this;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3;

    std::cout << "s1: " << s1.c_str() << ", Length: " << s1.getLength() << std::endl;
    std::cout << "s2: " << s2.c_str() << ", Length: " << s2.getLength() << std::endl;

    s3 = s1; // This works fine as s3 and s1 are different objects.

    std::cout << "s3 after s3 = s1: " << s3.c_str() << ", Length: " << s3.getLength() << std::endl;

    MyString s4("Test string");
    std::cout << "s4 before self-assignment: " << s4.c_str() << ", Length: " << s4.getLength() << std::endl;
    s4 = s4; // This is where the semantic error (crash/UB) will likely manifest.
             // 'data' (which is s4.data) is deleted, then strcpy tries to read from s4.data.
    std::cout << "s4 after self-assignment: " << s4.c_str() << ", Length: " << s4.getLength() << std::endl; // Might not even reach here

    MyString s5("Another string");
    MyString s6("Value");
    s5 = s6; // This also works fine as s5 and s6 are different objects.
    std::cout << "s5 after s5 = s6: " << s5.c_str() << ", Length: " << s5.getLength() << std::endl;

    return 0;
}