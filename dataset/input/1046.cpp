#include <iostream>
#include <cstring> // For strlen, strcpy

class MyString {
private:
    char* str;

public:
    // Default constructor
    MyString(const char* s = nullptr) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        std::cout << "Constructor invoked for: " << str << std::endl;
    }

    // Destructor
    ~MyString() {
        std::cout << "Destructor invoked for: " << str << std::endl;
        delete[] str;
    }

    // Copy Constructor - LOGICAL ERROR: Performs a shallow copy
    MyString(const MyString& other) {
        // This is a shallow copy! Both 'this->str' and 'other.str' will point to the same memory.
        // This will lead to double-free errors when both objects are destructed,
        // or incorrect behavior if one object modifies the shared memory.
        str = other.str;
        std::cout << "Copy Constructor (SHALLOW) invoked for: " << str << " (from " << other.str << ")" << std::endl;
    }

    // Assignment Operator (correctly implemented for deep copy)
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        delete[] str; // Deallocate old memory
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        std::cout << "Assignment Operator invoked for: " << str << " (from " << other.str << ")" << std::endl;
        return *this;
    }

    // Getter for the string
    const char* c_str() const {
        return str;
    }

    // Function to modify the string (for demonstration)
    void append(const char* suffix) {
        char* temp = new char[strlen(str) + strlen(suffix) + 1];
        strcpy(temp, str);
        strcat(temp, suffix);
        delete[] str;
        str = temp;
    }
};

// Function that takes MyString by value (invokes copy constructor)
void demonstrateCopy(MyString s) {
    std::cout << "Inside demonstrateCopy function. Value: " << s.c_str() << std::endl;
    // When 's' is destructed, it will attempt to delete the shared 'str' pointer.
    // This will lead to a double-free later when the original object is destructed.
}

int main() {
    std::cout << "--- Demonstrating MyString Class with Logical Error (Shallow Copy) ---" << std::endl;

    // 1. Constructor invocation
    MyString s1("Hello");
    std::cout << "s1: " << s1.c_str() << std::endl;

    // 2. Copy Constructor invocation (THIS WILL CAUSE A LOGICAL ERROR)
    MyString s2 = s1; // Invokes the shallow copy constructor
    std::cout << "s2 (copy of s1): " << s2.c_str() << std::endl;

    // At this point, s1.str and s2.str point to the SAME memory location.
    // Modifying s1 will also modify s2.
    std::cout << "\nModifying s1..." << std::endl;
    s1.append(" World");
    std::cout << "s1 (modified): " << s1.c_str() << std::endl;
    std::cout << "s2 (should be independent, but is affected): " << s2.c_str() << std::endl; // s2 is also "Hello World"

    // This will likely cause a double-free error when s1 and s2 go out of scope.
    // When s1 is destructed, it frees the memory.
    // When s2 is destructed, it tries to free the *same* memory again.

    std::cout << "\nCalling demonstrateCopy(s1)... (will also cause issues)" << std::endl;
    demonstrateCopy(s1); // Invokes shallow copy constructor for 's' parameter
    std::cout << "Back in main after demonstrateCopy(s1)." << std::endl;

    // 3. Assignment Operator invocation (this one is correct)
    MyString s3("Original");
    std::cout << "s3: " << s3.c_str() << std::endl;
    std::cout << "\nAssigning s1 to s3 (s3 = s1)..." << std::endl;
    s3 = s1; // Invokes the correctly implemented assignment operator
    std::cout << "s3 (after assignment from s1): " << s3.c_str() << std::endl;
    s1.append("!");
    std::cout << "s1 (modified again): " << s1.c_str() << std::endl;
    std::cout << "s3 (should be independent): " << s3.c_str() << std::endl; // s3 is "Hello World"

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}