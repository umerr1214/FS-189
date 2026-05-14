#include <iostream>
#include <cstring> // For strlen, strcpy
#include <stdexcept> // Not directly used for crashing, but for context

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

    // Constructor from const char* - ROBUSTNESS ISSUE HERE
    MyString(const char* s) {
        // This is the robustness issue: if 's' is nullptr, std::strlen(s) will cause a segmentation fault.
        // The code does not check for nullptr, making it vulnerable to crashes with invalid input.
        length = std::strlen(s); // CRASHES if s is nullptr
        data = new char[length + 1];
        std::strcpy(data, s);
    }

    // Copy Constructor - Performs deep copy correctly
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy Assignment Operator - Included for completeness, also performs deep copy
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data; // Free old memory
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
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

int main() {
    std::cout << "Testing MyString with robustness issue (nullptr handling).\n";

    // Test case 1: Normal construction
    MyString s1("Hello");
    std::cout << "s1: " << s1.c_str() << " (length: " << s1.size() << ")\n";

    // Test case 2: Copy construction
    MyString s2 = s1;
    std::cout << "s2 (copy of s1): " << s2.c_str() << " (length: " << s2.size() << ")\n";

    // Test case 3: Assignment
    MyString s3("World");
    s3 = s1;
    std::cout << "s3 (assigned s1): " << s3.c_str() << " (length: " << s3.size() << ")\n";

    // Test case 4: Empty string
    MyString s4("");
    std::cout << "s4 (empty): " << s4.c_str() << " (length: " << s4.size() << ")\n";

    std::cout << "\nAttempting to construct with nullptr (EXPECTED CRASH/SEGFAULT):\n";
    // Test case 5: Construct with nullptr - This is where the robustness issue manifests
    // The program is expected to crash here due to strlen(nullptr) or strcpy(data, nullptr).
    MyString s5(nullptr); // This line will cause a crash
    std::cout << "s5 (nullptr): " << s5.c_str() << " (length: " << s5.size() << ")\n"; // This line is unlikely to be reached

    return 0;
}