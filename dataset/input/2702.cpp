#include <iostream>
// No cstring for strlen/strcpy to demonstrate manual implementation
// No algorithm for min/max

class MyString {
private:
    char* data;
    size_t len;

    // Helper to manually calculate string length
    size_t manual_strlen(const char* s) const {
        if (!s) return 0; // Handle nullptr for robustness, even if the main issue is efficiency
        size_t count = 0;
        while (s[count] != '\0') {
            count++;
        }
        return count;
    }

    // Helper to manually copy string
    void manual_strcpy(char* dest, const char* src) const {
        if (!dest || !src) return; // Basic check
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    // Default constructor
    MyString() : data(nullptr), len(0) {
        data = new char[1];
        data[0] = '\0';
    }

    // Constructor from C-style string
    // EFFICIENCY ISSUE: Uses manual loops for strlen and strcpy.
    MyString(const char* s) {
        if (!s) { // Robustness check added, but the core issue is efficiency
            len = 0;
            data = new char[1];
            data[0] = '\0';
            return;
        }
        len = manual_strlen(s); // Inefficient: manual loop
        data = new char[len + 1];
        manual_strcpy(data, s); // Inefficient: manual loop
    }

    // Copy constructor (performs deep copy)
    // EFFICIENCY ISSUE: Uses manual loops for strlen and strcpy (via helpers).
    MyString(const MyString& other) {
        len = other.len; // Length is already known, but still using manual copy for data
        data = new char[len + 1];
        manual_strcpy(data, other.data); // Inefficient: manual loop
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Display string content
    // EFFICIENCY/READABILITY ISSUE: Prints character by character in a loop.
    void display() const {
        if (data) {
            size_t i = 0;
            while (data[i] != '\0') { // Inefficient: iterating char by char instead of std::cout << data
                std::cout << data[i];
                i++;
            }
        }
    }

    // Get length
    size_t getLength() const {
        return len;
    }
};

int main() {
    std::cout << "--- Testing MyString class (Readability / Efficiency Issue) ---\n";

    // Test case 1: Normal string creation
    MyString s1("Hello, World!");
    std::cout << "s1: ";
    s1.display();
    std::cout << " (Length: " << s1.getLength() << ")\n"; // Expected: Hello, World! (Length: 13)

    // Test case 2: Copy constructor
    MyString s2 = s1;
    std::cout << "s2 (copy of s1): ";
    s2.display();
    std::cout << " (Length: " << s2.getLength() << ")\n"; // Expected: Hello, World! (Length: 13)

    // Test case 3: Another normal string
    MyString s3("C++ Programming");
    std::cout << "s3: ";
    s3.display();
    std::cout << " (Length: " << s3.getLength() << ")\n"; // Expected: C++ Programming (Length: 15)

    // Test case 4: Empty string
    MyString s4("");
    std::cout << "s4 (empty): ";
    s4.display();
    std::cout << " (Length: " << s4.getLength() << ")\n"; // Expected: (Length: 0)

    // Test case 5: String from nullptr (should handle gracefully due to helper check, but still inefficient)
    MyString s5(nullptr);
    std::cout << "s5 (from nullptr): ";
    s5.display();
    std::cout << " (Length: " << s5.getLength() << ")\n"; // Expected: (Length: 0)

    std::cout << "\n--- End of test ---\n";

    return 0;
}