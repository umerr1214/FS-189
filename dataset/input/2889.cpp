#include <iostream>
#include <cstring> // For std::strlen, std::strcpy

class StringWrapper {
private:
    char* data;
    size_t length;

public:
    // Constructor: Handles nullptr and empty strings gracefully
    StringWrapper(const char* str = nullptr) : data(nullptr), length(0) {
        if (str != nullptr) {
            length = std::strlen(str);
            data = new char[length + 1]; // Allocate space for string + null terminator
            std::strcpy(data, str);      // Deep copy the string content
        } else {
            // If str is nullptr, initialize as an empty string
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }

    // Destructor: Releases dynamically allocated memory
    ~StringWrapper() {
        delete[] data;
        data = nullptr; // Good practice to nullify pointer after deletion
    }

    // Copy Constructor: Ensures deep copying of string data
    StringWrapper(const StringWrapper& other) : data(nullptr), length(other.length) {
        if (other.data != nullptr) { // Check if 'other' has valid data to copy
            data = new char[length + 1]; // Allocate new memory for the copy
            std::strcpy(data, other.data); // Deep copy the content
        } else {
            // If other's data is nullptr (e.g., an empty StringWrapper), initialize as empty
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }

    // Accessor for the string data
    const char* getString() const {
        return data; // Always points to a valid C-string (even if empty)
    }

    // Accessor for the string length (efficient, as it's stored)
    size_t getLength() const {
        return length;
    }
};

int main() {
    std::cout << "--- Testing Correct StringWrapper Implementation ---" << std::endl;

    // Test 1: Default constructor (nullptr input implicitly)
    StringWrapper s0;
    std::cout << "s0 (default): \"" << s0.getString() << "\", Length: " << s0.getLength() << std::endl;

    // Test 2: Constructor with valid string
    StringWrapper s1("Hello C++ World!");
    std::cout << "s1: \"" << s1.getString() << "\", Length: " << s1.getLength() << std::endl;

    // Test 3: Constructor with empty string
    StringWrapper s_empty("");
    std::cout << "s_empty: \"" << s_empty.getString() << "\", Length: " << s_empty.getLength() << std::endl;

    // Test 4: Constructor with nullptr explicitly
    StringWrapper s_null_explicit(nullptr);
    std::cout << "s_null_explicit: \"" << s_null_explicit.getString() << "\", Length: " << s_null_explicit.getLength() << std::endl;

    // Test 5: Copy constructor
    StringWrapper s2 = s1; // Invokes copy constructor
    std::cout << "s2 (copy of s1): \"" << s2.getString() << "\", Length: " << s2.getLength() << std::endl;

    // Test 6: Verify deep copy independence
    std::cout << "\nVerifying deep copy independence:" << std::endl;
    StringWrapper s3("Original String");
    StringWrapper s4 = s3; // Copy construction
    std::cout << "s3: \"" << s3.getString() << "\", s4: \"" << s4.getString() << "\"" << std::endl;
    
    // Demonstrate that s3 and s4 manage independent memory.
    // When temp_s is destructed, copied_temp remains valid.
    {
        StringWrapper temp_s("Temporary String");
        StringWrapper copied_temp = temp_s;
        std::cout << "Inside block - temp_s: \"" << temp_s.getString() << "\", copied_temp: \"" << copied_temp.getString() << "\"" << std::endl;
    } // temp_s goes out of scope and is destructed here.

    std::cout << "End of main. All StringWrapper objects will be destructed properly." << std::endl;

    return 0;
}