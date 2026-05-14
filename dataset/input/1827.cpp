#include <iostream>
#include <cstring> // For strlen and strcpy
#include <algorithm> // For std::swap

class StringWrapper {
public:
    char* str;
    size_t length; // Store length for efficiency

    // Default constructor: Initializes to an empty string
    StringWrapper() : str(nullptr), length(0) {
        str = new char[1];
        str[0] = '\0';
    }

    // Constructor from C-string: Handles nullptr input
    StringWrapper(const char* s) : str(nullptr), length(0) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
            length = 0;
        } else {
            length = std::strlen(s);
            str = new char[length + 1];
            std::strcpy(str, s);
        }
    }

    // Copy constructor (Correct implementation: performs deep copy)
    StringWrapper(const StringWrapper& other) : str(nullptr), length(0) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Destructor: Releases dynamically allocated memory
    ~StringWrapper() {
        delete[] str;
    }

    // Assignment operator (Correct implementation: using copy-and-swap idiom for strong exception safety)
    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) { // Self-assignment check
            // Create a temporary copy using the copy constructor
            StringWrapper temp(other);
            // Swap resources (pointer and length)
            std::swap(str, temp.str);
            std::swap(length, temp.length);
            // 'temp' now holds the old resources of '*this' and will deallocate them
            // when 'temp' goes out of scope.
        }
        return *this;
    }

    // Helper to print the string
    const char* c_str() const {
        return str;
    }

    // Helper to get length
    size_t getLength() const {
        return length;
    }
};

int main() {
    // Test case 1: Default constructor
    StringWrapper s1;
    std::cout << "s1 (default): '" << s1.c_str() << "', length: " << s1.getLength() << std::endl;

    // Test case 2: Constructor from C-string
    StringWrapper s2("Hello C++");
    std::cout << "s2 (\"Hello C++\"): '" << s2.c_str() << "', length: " << s2.getLength() << std::endl;

    StringWrapper s3(""); // Empty string
    std::cout << "s3 (empty): '" << s3.c_str() << "', length: " << s3.getLength() << std::endl;

    // Test case 3: Copy constructor
    StringWrapper s4 = s2;
    std::cout << "s4 (copied from s2): '" << s4.c_str() << "', length: " << s4.getLength() << std::endl;

    // Verify deep copy by modifying original and checking copy
    s2.str[0] = 'J'; // Modify s2
    std::cout << "s2 (modified): '" << s2.c_str() << "', length: " << s2.getLength() << std::endl;
    std::cout << "s4 (should be unchanged): '" << s4.c_str() << "', length: " << s4.getLength() << std::endl;

    // Test case 4: Assignment operator
    StringWrapper s5("Original content");
    std::cout << "s5: '" << s5.c_str() << "', length: " << s5.getLength() << std::endl;
    s5 = s4; // Assign s4 to s5
    std::cout << "s5 (assigned from s4): '" << s5.c_str() << "', length: " << s5.getLength() << std::endl;
    std::cout << "s4 (should be unchanged): '" << s4.c_str() << "', length: " << s4.getLength() << std::endl;

    // Test case 5: Self-assignment (should be safe due to copy-and-swap)
    StringWrapper s6("Self-assign test");
    std::cout << "s6 before self-assignment: '" << s6.c_str() << "', length: " << s6.getLength() << std::endl;
    s6 = s6;
    std::cout << "s6 after self-assignment: '" << s6.c_str() << "', length: " << s6.getLength() << std::endl;

    // Test case 6: Copying an empty string
    StringWrapper s7 = s3;
    std::cout << "s7 (copied from s3 empty): '" << s7.c_str() << "', length: " << s7.getLength() << std::endl;

    return 0;
}