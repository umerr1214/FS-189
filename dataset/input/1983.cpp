#include <iostream>
#include <cstring> // For strlen, strcpy
#include <algorithm> // For std::swap

class StringWrapper {
private:
    char* data;
    size_t len;

public:
    // Default Constructor
    StringWrapper() : data(nullptr), len(0) {
        // Initializes data to nullptr and len to 0, ensuring a valid state.
    }

    // Constructor
    StringWrapper(const char* s) : data(nullptr), len(0) { // Initialize members
        if (s != nullptr) {
            len = strlen(s);
            data = new char[len + 1]; // Allocate memory for string + null terminator
            strcpy(data, s);          // Copy the string
        }
    }

    // Copy Constructor - Performs deep copy as required
    StringWrapper(const StringWrapper& other) : data(nullptr), len(0) { // Initialize members
        if (other.data != nullptr) {
            len = other.len;
            data = new char[len + 1]; // Allocate new memory
            strcpy(data, other.data); // Deep copy the content
        }
    }

    // Destructor - Frees dynamically allocated memory
    ~StringWrapper() {
        if (data) {
            delete[] data;
            data = nullptr; // Good practice to nullify after delete
        }
    }

    // Copy Assignment Operator (Rule of 3/5) - Using copy-and-swap idiom for strong exception safety
    StringWrapper& operator=(StringWrapper other) { // 'other' is passed by value (copy constructor handles deep copy)
        std::swap(data, other.data); // Swap internal pointers
        std::swap(len, other.len);   // Swap lengths
        return *this;                // 'other's destructor will free the old data
    }

    // Accessor to get the C-style string
    const char* get() const {
        return data ? data : ""; // Return empty string literal for nullptr for safer access
    }

    // Accessor for string length
    size_t length() const {
        return len;
    }
};

int main() {
    // Test case 1: Basic construction and copy constructor
    StringWrapper s1("Hello C++");
    StringWrapper s2 = s1; // Copy constructor
    StringWrapper s3;       // Default constructor

    std::cout << "s1: " << s1.get() << " (len: " << s1.length() << ")" << std::endl;
    std::cout << "s2: " << s2.get() << " (len: " << s2.length() << ")" << std::endl;

    // Test case 2: Copy assignment operator
    s3 = s1;                // Copy assignment operator
    std::cout << "s3: " << s3.get() << " (len: " << s3.length() << ")" << std::endl;

    // Verify deep copy by checking independence (not directly possible to modify s1 via current interface,
    // but the underlying memory addresses would be different if we printed them)
    // The content is the same, but they are distinct memory allocations.

    // Test case 3: Construction with nullptr and copying
    StringWrapper s_null(nullptr);
    StringWrapper s_copied_null = s_null;
    StringWrapper s_assigned_null;
    s_assigned_null = s_null;

    std::cout << "s_null: '" << s_null.get() << "' (len: " << s_null.length() << ")" << std::endl;
    std::cout << "s_copied_null: '" << s_copied_null.get() << "' (len: " << s_copied_null.length() << ")" << std::endl;
    std::cout << "s_assigned_null: '" << s_assigned_null.get() << "' (len: " << s_assigned_null.length() << ")" << std::endl;

    // Test case 4: Self-assignment (handled correctly by copy-and-swap)
    s1 = s1;
    std::cout << "s1 after self-assignment: " << s1.get() << " (len: " << s1.length() << ")" << std::endl;

    // Test case 5: Chained assignment
    StringWrapper s4("Initial");
    s4 = s2 = StringWrapper("Chained String"); // s2 gets "Chained String", then s4 gets "Chained String"
    std::cout << "s4 after chained assignment: " << s4.get() << " (len: " << s4.length() << ")" << std::endl;
    std::cout << "s2 after chained assignment: " << s2.get() << " (len: " << s2.length() << ")" << std::endl;

    return 0;
}