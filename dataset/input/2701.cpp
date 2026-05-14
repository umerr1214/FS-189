#include <iostream>
#include <cstring> // For strlen, strcpy
#include <algorithm> // For std::min, std::max (not strictly needed for this version)

class MyString {
private:
    char* data;
    size_t len;

public:
    // Default constructor
    MyString() : data(nullptr), len(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor from C-style string
    // ROBUSTNESS ISSUE: Does not handle nullptr input for s.
    MyString(const char* s) {
        // If s is nullptr, strlen(s) will cause a crash.
        // This is a robustness issue as it doesn't gracefully handle invalid input.
        len = std::strlen(s);
        data = new char[len + 1];
        std::strcpy(data, s);
    }

    // Copy constructor (performs deep copy)
    MyString(const MyString& other) : len(other.len) {
        data = new char[len + 1];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Display string content
    void display() const {
        std::cout << data;
    }

    // Get length
    size_t getLength() const {
        return len;
    }
};

int main() {
    std::cout << "--- Testing MyString class (Robustness Issue) ---\n";

    // Test case 1: Normal string creation
    MyString s1("Hello");
    std::cout << "s1: ";
    s1.display();
    std::cout << " (Length: " << s1.getLength() << ")\n"; // Expected: Hello (Length: 5)

    // Test case 2: Copy constructor
    MyString s2 = s1;
    std::cout << "s2 (copy of s1): ";
    s2.display();
    std::cout << " (Length: " << s2.getLength() << ")\n"; // Expected: Hello (Length: 5)

    // Test case 3: Another normal string
    MyString s3("World");
    std::cout << "s3: ";
    s3.display();
    std::cout << " (Length: " << s3.getLength() << ")\n"; // Expected: World (Length: 5)

    // Test case 4: Empty string
    MyString s4("");
    std::cout << "s4 (empty): ";
    s4.display();
    std::cout << " (Length: " << s4.getLength() << ")\n"; // Expected: (Length: 0)

    std::cout << "\n--- Demonstrating Robustness Issue ---\n";
    // Test case 5: Constructing with a nullptr
    // This will cause a runtime crash due to strlen(nullptr)
    std::cout << "Attempting to create MyString from nullptr...\n";
    MyString s5(nullptr); // EXPECTED CRASH HERE
    std::cout << "s5: ";
    s5.display();
    std::cout << " (Length: " << s5.getLength() << ")\n";

    return 0;
}