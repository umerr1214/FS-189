#include <iostream>
#include <cstring> // For strlen and strcpy

class StringWrapper {
public:
    char* str;

    // Default constructor
    // Robustness Issue: Initializes 'str' to nullptr.
    // This state is not handled by the copy constructor, leading to a crash.
    StringWrapper() : str(nullptr) {
    }

    // Constructor from C-string
    StringWrapper(const char* s) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

    // Copy constructor (Robustness Issue: Does not handle nullptr 'other.str')
    StringWrapper(const StringWrapper& other) {
        // PROBLEM: If 'other.str' is nullptr (e.g., from default constructor),
        // calling std::strlen(other.str) results in undefined behavior or a crash.
        str = new char[std::strlen(other.str) + 1];
        std::strcpy(str, other.str);
    }

    // Destructor
    ~StringWrapper() {
        delete[] str;
    }

    // Helper to print the string
    const char* c_str() const {
        if (str == nullptr) {
            return "(nullptr)"; // For display purposes to indicate the problematic state
        }
        return str;
    }
};

int main() {
    // Test case 1: Default constructed object (str is nullptr)
    StringWrapper s1;
    std::cout << "s1 (default): " << s1.c_str() << std::endl;

    // Test case 2: Attempting to copy s1, which has a nullptr internal string.
    // This is expected to crash due to strlen(nullptr) in the copy constructor.
    std::cout << "Attempting to copy s1 (which has nullptr internal string)..." << std::endl;
    StringWrapper s2 = s1; // CRASH EXPECTED HERE

    // If the program somehow continues, this would be undefined behavior.
    std::cout << "s2 (copied from s1): " << s2.c_str() << std::endl;

    // These test cases would work correctly if the program didn't crash earlier
    StringWrapper s3("Hello");
    StringWrapper s4 = s3;
    std::cout << "s3: " << s3.c_str() << std::endl;
    std::cout << "s4 (copied from s3): " << s4.c_str() << std::endl;

    StringWrapper s5("");
    StringWrapper s6 = s5;
    std::cout << "s5: '" << s5.c_str() << "'" << std::endl;
    std::cout << "s6 (copied from s5): '" << s6.c_str() << "'" << std::endl;

    return 0;
}