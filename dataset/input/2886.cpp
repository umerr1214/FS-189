#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* data;
    size_t length;

    StringWrapper(const char* str = nullptr) {
        if (str) {
            length = strlen(str);
            // SEMANTIC ERROR: Allocates 'length' bytes, but needs 'length + 1' for the null terminator.
            // This can lead to a buffer overflow when strcpy writes the null terminator
            // one byte past the allocated memory, causing heap corruption.
            data = new char[length]; // Should be new char[length + 1];
            if (length > 0) { // Only copy if there's actual data
                strcpy(data, str);
            } else { // Handle empty string case explicitly, though new char[0] is problematic
                data = new char[1]; // Allocate for null terminator
                data[0] = '\0';
            }
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy Constructor (intended to be deep copy)
    StringWrapper(const StringWrapper& other) {
        if (other.data) {
            length = other.length;
            // SEMANTIC ERROR: Same allocation error as in the primary constructor.
            data = new char[length]; // Should be new char[length + 1];
            if (length > 0) {
                strcpy(data, other.data);
            } else { // Handle empty string case explicitly
                data = new char[1];
                data[0] = '\0';
            }
        } else {
            data = nullptr;
            length = 0;
        }
    }

    void print() const {
        if (data) {
            std::cout << "String: \"" << data << "\", Length: " << length << std::endl;
        } else {
            std::cout << "String: (null), Length: " << length << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Testing Buffer Overflow (Semantic Error) ---" << std::endl;

    // Test case 1: Regular string
    StringWrapper s1("Hello"); // length = 5, allocates char[5]. strcpy will write 6 bytes.
    std::cout << "s1 created: ";
    s1.print(); // Might print "Hello" but memory after 'o' is corrupted.

    // Test case 2: Empty string
    StringWrapper s_empty(""); // length = 0, allocates char[1] correctly now.
    std::cout << "s_empty created: ";
    s_empty.print(); // Expected: String: "", Length: 0

    // Test case 3: Copy constructor
    StringWrapper s2 = s1; // Copies data from s1, potentially already corrupted.
    std::cout << "s2 copied from s1: ";
    s2.print(); // Likely prints the same as s1, possibly with further corruption.

    // Test case 4: A longer string to increase likelihood of visible corruption/crash
    StringWrapper long_str("This is a somewhat longer string."); // length = 33, allocates char[33]. strcpy writes 34 bytes.
    std::cout << "long_str created: ";
    long_str.print(); // Highly likely to show garbage after string or crash due to memory corruption.

    std::cout << "Program finished. Memory corruption may have occurred, or program might crash." << std::endl;
    return 0;
}