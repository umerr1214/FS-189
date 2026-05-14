#include <iostream>
#include <cctype> // For toupper, islower

// Function with robustness issue: does not handle nullptr input
void strToUpper(char* str) {
    // Missing: if (str == nullptr) return;
    char* ptr = str;
    while (*ptr != '\0') {
        if (std::islower(static_cast<unsigned char>(*ptr))) {
            *ptr = static_cast<char>(std::toupper(static_cast<unsigned char>(*ptr)));
        }
        ptr++;
    }
}

int main() {
    char myString1[] = "Hello World!";
    std::cout << "Original: \"" << myString1 << "\"" << std::endl;
    strToUpper(myString1);
    std::cout << "Uppercase: \"" << myString1 << "\"" << std::endl;

    char myString2[] = "this is a test.";
    std::cout << "Original: \"" << myString2 << "\"" << std::endl;
    strToUpper(myString2);
    std::cout << "Uppercase: \"" << myString2 << "\"" << std::endl;

    char myString3[] = "";
    std::cout << "Original: \"" << myString3 << "\"" << std::endl;
    strToUpper(myString3);
    std::cout << "Uppercase: \"" << myString3 << "\"" << std::endl;

    // This call is expected to cause a crash (segmentation fault)
    // due to dereferencing a null pointer.
    char* nullStr = nullptr;
    std::cout << "\nAttempting to process a nullptr string (EXPECTED CRASH)..." << std::endl;
    strToUpper(nullStr); // CRASH HERE for the robustness issue
    std::cout << "This line will not be reached if crash occurs as expected." << std::endl;

    return 0;
}