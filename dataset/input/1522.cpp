#include <iostream>
#include <cstring> // For strlen, strcpy, etc.

class StringWrapper {
private:
    char* str;

public:
    // Default constructor
    StringWrapper(const char* s = nullptr) : str(nullptr) {
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    // Deep Copy Constructor
    StringWrapper(const StringWrapper& other) : str(nullptr) {
        if (other.str != nullptr) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] str;
    }

    // Setter for modification (for testing independence)
    void setStr(const char* s) {
        delete[] str; // Free old memory
        str = nullptr;
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    // Getter
    const char* getStr() const {
        return str;
    }

    // Display for testing
    void display() const {
        if (str) {
            std::cout << "String: \"" << str << "\"" << std::endl;
        } else {
            std::cout << "String: (nullptr)" << std::endl;
        }
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    StringWrapper s1("Hello, Deep Copy!");
    std::cout << "s1: "; s1.display();

    StringWrapper s2 = s1; // Calls copy constructor
    std::cout << "s2 (copy of s1): "; s2.display();

    std::cout << "\nModifying s1..." << std::endl;
    s1.setStr("Modified String 1");
    std::cout << "s1 after modification: "; s1.display();
    std::cout << "s2 after s1 modification: "; s2.display(); // Should still be "Hello, Deep Copy!"

    StringWrapper s3("Another one");
    std::cout << "s3: "; s3.display();

    StringWrapper s4; // Default constructor
    std::cout << "s4: "; s4.display();
    
    std::cout << "\nEnd of main." << std::endl;
    return 0;
}