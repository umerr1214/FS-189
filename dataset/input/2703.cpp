#include <iostream>
#include <cstring> // For std::strlen, std::strcpy
#include <stdexcept> // For std::invalid_argument (optional, but good practice)

class MyString {
private:
    char* data;
    size_t len;

public:
    // Default constructor
    MyString() : data(nullptr), len(0) {
        data = new char[1]; // Allocate space for null terminator
        data[0] = '\0';
    }

    // Constructor from C-style string
    MyString(const char* s) : data(nullptr), len(0) {
        if (s == nullptr) {
            // Handle nullptr gracefully: create an empty string
            data = new char[1];
            data[0] = '\0';
            len = 0;
        } else {
            len = std::strlen(s);
            data = new char[len + 1]; // +1 for null terminator
            std::strcpy(data, s);
        }
    }

    // Copy constructor (performs deep copy)
    MyString(const MyString& other) : len(other.len) {
        data = new char[len + 1]; // +1 for null terminator
        std::strcpy(data, other.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
        data = nullptr; // Good practice to nullify pointer after deletion
    }

    // Display string content
    void display() const {
        std::cout << data;
    }

    // Get length
    size_t getLength() const {
        return len;
    }

    // Example method to get C-style string (for interoperability)
    const char* c_str() const {
        return data;
    }
};

int main() {
    std::cout << "--- Testing MyString class (Correct Version) ---\n";

    // Test case 1: Normal string creation
    MyString s1("Hello, C++!");
    std::cout << "s1: ";
    s1.display();
    std::cout << " (Length: " << s1.getLength() << ")\n"; // Expected: Hello, C++! (Length: 11)

    // Test case 2: Copy constructor
    MyString s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1): ";
    s2.display();
    std::cout << " (Length: " << s2.getLength() << ")\n"; // Expected: Hello, C++! (Length: 11)

    // Test case 3: Modify original, ensure copy is independent
    // (MyString currently doesn't have modification methods, but we can reassign)
    MyString s3("Deep Copy Test");
    std::cout << "s3: ";
    s3.display();
    std::cout << " (Length: " << s3.getLength() << ")\n"; // Expected: Deep Copy Test (Length: 14)

    // Test case 4: Empty string
    MyString s4("");
    std::cout << "s4 (empty): ";
    s4.display();
    std::cout << " (Length: " << s4.getLength() << ")\n"; // Expected: (Length: 0)

    // Test case 5: String from nullptr (should handle gracefully)
    MyString s5(nullptr);
    std::cout << "s5 (from nullptr): ";
    s5.display();
    std::cout << " (Length: " << s5.getLength() << ")\n"; // Expected: (Length: 0)

    // Test case 6: Default constructor
    MyString s6;
    std::cout << "s6 (default): ";
    s6.display();
    std::cout << " (Length: " << s6.getLength() << ")\n"; // Expected: (Length: 0)

    std::cout << "\n--- End of test ---\n";

    return 0;
}