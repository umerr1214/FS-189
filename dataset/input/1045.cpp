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

    // Copy Constructor
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        std::cout << "Copy Constructor invoked for: " << str << " (from " << other.str << ")" << std::endl;
    }

    // Assignment Operator
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
} // Missing semicolon here, causing a syntax error.

// Function that takes MyString by value (invokes copy constructor)
void demonstrateCopy(MyString s) {
    std::cout << "Inside demonstrateCopy function. Value: " << s.c_str() << std::endl;
}

int main() {
    std::cout << "--- Demonstrating MyString Class ---" << std::endl;

    // 1. Constructor invocation
    MyString s1("Hello");
    std::cout << "s1: " << s1.c_str() << std::endl;

    // 2. Copy Constructor invocation
    // Case A: Initialization using another object
    MyString s2 = s1; // Invokes copy constructor
    std::cout << "s2 (copy of s1): " << s2.c_str() << std::endl;

    // Case B: Passing by value to a function
    std::cout << "\nCalling demonstrateCopy(s1)..." << std::endl;
    demonstrateCopy(s1); // Invokes copy constructor
    std::cout << "Back in main after demonstrateCopy(s1)." << std::endl;

    // 3. Assignment Operator invocation
    MyString s3("World");
    std::cout << "s3: " << s3.c_str() << std::endl;

    std::cout << "\nAssigning s1 to s3 (s3 = s1)..." << std::endl;
    s3 = s1; // Invokes assignment operator
    std::cout << "s3 (after assignment from s1): " << s3.c_str() << std::endl;

    MyString s4; // Default constructor
    std::cout << "s4 (default): " << s4.c_str() << std::endl;
    std::cout << "\nAssigning s3 to s4 (s4 = s3)..." << std::endl;
    s4 = s3; // Invokes assignment operator
    std::cout << "s4 (after assignment from s3): " << s4.c_str() << std::endl;

    // Demonstrating self-assignment (should be handled without issues)
    std::cout << "\nDemonstrating self-assignment (s1 = s1)..." << std::endl;
    s1 = s1; // Invokes assignment operator, should do nothing
    std::cout << "s1 (after self-assignment): " << s1.c_str() << std::endl;

    std::cout << "\nModifying s1 to see independence of copies/assignments." << std::endl;
    s1.append(" C++");
    std::cout << "s1 (modified): " << s1.c_str() << std::endl;
    std::cout << "s2 (original copy): " << s2.c_str() << std::endl;
    std::cout << "s3 (original assignment): " << s3.c_str() << std::endl;
    std::cout << "s4 (original assignment): " << s4.c_str() << std::endl;

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}