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

    // Destructor - SEMANTIC ERROR: Missing destructor leads to memory leaks
    // ~MyString() {
    //     std::cout << "Destructor invoked for: " << str << std::endl;
    //     delete[] str;
    // }

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
};

// Function that takes MyString by value (invokes copy constructor)
void demonstrateCopy(MyString s) {
    std::cout << "Inside demonstrateCopy function. Value: " << s.c_str() << std::endl;
    // The temporary 's' object will be destructed here.
    // Due to missing destructor, its dynamically allocated memory will not be freed.
}

void createAndDestroyStrings() {
    std::cout << "\n--- Inside createAndDestroyStrings function ---" << std::endl;
    MyString temp1("Temporary A"); // Memory for "Temporary A" is leaked
    MyString temp2("Temporary B"); // Memory for "Temporary B" is leaked
    std::cout << "temp1: " << temp1.c_str() << ", temp2: " << temp2.c_str() << std::endl;
    std::cout << "--- Exiting createAndDestroyStrings function ---" << std::endl;
}


int main() {
    std::cout << "--- Demonstrating MyString Class with Semantic Error (Missing Destructor) ---" << std::endl;

    // 1. Constructor invocation
    MyString s1("Hello"); // Memory for "Hello" is leaked
    std::cout << "s1: " << s1.c_str() << std::endl;

    // 2. Copy Constructor invocation
    MyString s2 = s1; // Memory for "Hello" (s2's copy) is leaked
    std::cout << "s2 (copy of s1): " << s2.c_str() << std::endl;

    // Case B: Passing by value to a function
    std::cout << "\nCalling demonstrateCopy(s1)..." << std::endl;
    demonstrateCopy(s1); // Invokes copy constructor, then temporary object's memory is leaked
    std::cout << "Back in main after demonstrateCopy(s1)." << std::endl;

    // 3. Assignment Operator invocation
    MyString s3("World"); // Memory for "World" is leaked
    std::cout << "s3: " << s3.c_str() << std::endl;

    std::cout << "\nAssigning s1 to s3 (s3 = s1)..." << std::endl;
    s3 = s1; // Assignment operator correctly deallocates s3's old memory and allocates new.
             // The old memory for "World" is freed. New memory for "Hello" is allocated for s3, and then leaked.
    std::cout << "s3 (after assignment from s1): " << s3.c_str() << std::endl;

    createAndDestroyStrings(); // More memory leaks here

    std::cout << "\n--- End of main ---" << std::endl;
    // All MyString objects (s1, s2, s3) in main will have their dynamically allocated memory leaked
    // because the destructor is missing.
    return 0;
}