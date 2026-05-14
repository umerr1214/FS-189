#include <iostream>
// cstring is intentionally not included to force manual (less efficient) string operations.

class StringWrapper {
private:
    char* internalData; // Less descriptive variable name
    size_t currentLength; // Less descriptive variable name

    // Helper function for manual string length calculation (inefficient)
    size_t calculateStringLength(const char* s) const {
        if (!s) return 0;
        size_t len = 0;
        while (s[len] != '\0') { // Manual loop instead of std::strlen
            len++;
        }
        return len;
    }

    // Helper function for manual string copying (inefficient)
    void performStringCopy(char* destination, const char* source) {
        if (!destination || !source) return;
        size_t i = 0;
        while (source[i] != '\0') { // Manual loop instead of std::strcpy
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0'; // Ensure null termination
    }

public:
    // Constructor - Readability/Efficiency Issue: Manual operations, redundant checks
    StringWrapper(const char* inputStr = nullptr) : internalData(nullptr), currentLength(0) {
        if (inputStr != nullptr) {
            currentLength = calculateStringLength(inputStr); // Inefficient manual calculation
            if (currentLength > 0) { // Redundant check; new char[1] for '\0' is always needed
                internalData = new char[currentLength + 1];
                performStringCopy(internalData, inputStr); // Inefficient manual copy
            } else { // Explicitly handle empty string
                internalData = new char[1];
                internalData[0] = '\0';
            }
        } else { // Handle nullptr input by creating an empty string
            internalData = new char[1];
            internalData[0] = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] internalData;
        internalData = nullptr;
    }

    // Copy Constructor - Readability/Efficiency Issue: Manual operations, redundant checks
    StringWrapper(const StringWrapper& other) : internalData(nullptr), currentLength(other.currentLength) {
        if (other.internalData != nullptr) { // Check if 'other' has valid data
            if (currentLength > 0) { // Redundant check
                internalData = new char[currentLength + 1];
                performStringCopy(internalData, other.internalData); // Inefficient manual copy
            } else { // Explicitly handle empty string from other
                internalData = new char[1];
                internalData[0] = '\0';
            }
        } else { // This case implies 'other' was initialized as null/empty
            internalData = new char[1];
            internalData[0] = '\0';
        }
    }

    // Accessor for the string data
    const char* getString() const {
        return internalData ? internalData : "";
    }

    // Accessor for the string length - Efficiency Issue: Recalculates length every time
    size_t getLength() const {
        return calculateStringLength(internalData); // Inefficient: Should return 'currentLength' directly
    }
};

int main() {
    std::cout << "Testing StringWrapper with Readability/Efficiency Issues:" << std::endl;

    StringWrapper s1("Hello World");
    std::cout << "s1: \"" << s1.getString() << "\", Length: " << s1.getLength() << std::endl; // getLength is inefficient

    StringWrapper s2("");
    std::cout << "s2 (empty): \"" << s2.getString() << "\", Length: " << s2.getLength() << std::endl;

    StringWrapper s3(nullptr);
    std::cout << "s3 (nullptr): \"" << s3.getString() << "\", Length: " << s3.getLength() << std::endl;

    StringWrapper s4 = s1; // Copy constructor
    std::cout << "s4 (copy of s1): \"" << s4.getString() << "\", Length: " << s4.getLength() << std::endl;

    // Demonstrate deep copy (s1 and s4 are independent)
    std::cout << "s1 original: \"" << s1.getString() << "\"" << std::endl;

    return 0;
}