#include <iostream>
#include <cstring>   // For std::strlen, std::strcpy
#include <algorithm> // For std::swap (used in copy-and-swap idiom for assignment)

class MyString {
private:
    char* data;
    size_t length;

public:
    // Default constructor
    MyString() : data(nullptr), length(0) {
        data = new char[1]; // Allocate for null terminator
        data[0] = '\0';
    }

    // Constructor from const char*
    MyString(const char* s) : data(nullptr), length(0) {
        if (s == nullptr) {
            data = new char[1]; // Initialize to an empty string for nullptr input
            data[0] = '\0';
            length = 0;
        } else {
            length = std::strlen(s);
            data = new char[length + 1]; // +1 for null terminator
            std::strcpy(data, s);
        }
    }

    // Copy Constructor (Deep Copy)
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1]; // Allocate new memory for the copy
        std::strcpy(data, other.data); // Copy content from 'other'
    }

    // Destructor
    ~MyString() {
        delete[] data; // Free allocated memory
        data = nullptr; // Good practice to nullify pointer after deletion
    }

    // Copy Assignment Operator (using copy-and-swap idiom for strong exception safety)
    // Parameter 'other' is passed by value, which implicitly calls the copy constructor.
    // This creates a temporary copy.
    MyString& operator=(MyString other) {
        // Swap the internal resources (data pointer and length) with the temporary object.
        // When 'other' goes out of scope, its destructor (now holding the old resources of *this)
        // will correctly deallocate the memory.
        std::swap(data, other.data);
        std::swap(length, other.length);
        return *this;
    }

    // Getter for string content
    const char* c_str() const {
        return data;
    }

    // Getter for string length
    size_t size() const {
        return length;
    }
};

// Function to demonstrate copy constructor when passing objects by value
void printAndCopy(MyString s) { // 's' is copied here (copy constructor called)
    std::cout << "  Inside printAndCopy function:\n";
    std::cout << "    Copied string: " << s.c_str() << " (length: " << s.size() << ")\n";
    // 's' goes out of scope here, its destructor is called
}

int main() {
    std::cout << "Testing MyString - Correct Version.\n";

    // Test Case 1: Constructor with C-style string
    MyString s1("Hello, World!");
    std::cout << "s1: " << s1.c_str() << " (length: " << s1.size() << ")\n";

    // Test Case 2: Copy Constructor
    MyString s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1): " << s2.c_str() << " (length: " << s2.size() << ")\n";

    // Modify s1 to show deep copy (s2 should remain unchanged)
    s1 = MyString("Modified s1"); // Reassigns s1, effectively modifying it
    std::cout << "s1 (modified): " << s1.c_str() << " (length: " << s1.size() << ")\n";
    std::cout << "s2 (should be unchanged): " << s2.c_str() << " (length: " << s2.size() << ")\n";

    // Test Case 3: Copy Assignment Operator
    MyString s3("Initial s3 value");
    std::cout << "s3 (initial): " << s3.c_str() << " (length: " << s3.size() << ")\n";
    s3 = s2; // Calls copy assignment operator
    std::cout << "s3 (assigned s2): " << s3.c_str() << " (length: " << s3.size() << ")\n";

    // Test Case 4: Empty string construction
    MyString s4("");
    std::cout << "s4 (empty): " << s4.c_str() << " (length: " << s4.size() << ")\n";

    // Test Case 5: Nullptr input construction (should result in empty string)
    MyString s5(nullptr);
    std::cout << "s5 (nullptr input): " << s5.c_str() << " (length: " << s5.size() << ")\n";

    // Test Case 6: Pass by value (demonstrates copy constructor for function arguments)
    std::cout << "\nCalling printAndCopy with s1:\n";
    printAndCopy(s1); // s1 is copied when passed to the function
    std::cout << "Back in main. s1 remains: " << s1.c_str() << " (length: " << s1.size() << ")\n";

    // Test Case 7: Self-assignment
    std::cout << "\nTesting self-assignment (s6 = s6):\n";
    MyString s6("Self-assign test");
    std::cout << "s6 before self-assign: " << s6.c_str() << "\n";
    s6 = s6; // Should work correctly due to copy-and-swap
    std::cout << "s6 after self-assign: " << s6.c_str() << "\n";

    std::cout << "\nMyString objects will now go out of scope and destruct.\n";

    return 0;
}