#include <iostream>

// Function with a robustness issue: does not handle nullptr input
int customStrlen(const char* str) {
    // If str is nullptr, dereferencing *str will cause a segmentation fault
    // or other undefined behavior, leading to a crash.
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    // Test cases
    const char* s1 = "hello";
    const char* s2 = "";
    const char* s3 = "a";
    const char* s4 = "long string with spaces";
    const char* s5 = nullptr; // This input will trigger the robustness issue

    std::cout << "Testing with \"hello\": " << customStrlen(s1) << std::endl;
    std::cout << "Testing with \"\": " << customStrlen(s2) << std::endl;
    std::cout << "Testing with \"a\": " << customStrlen(s3) << std::endl;
    std::cout << "Testing with \"long string with spaces\": " << customStrlen(s4) << std::endl;
    // The following line will cause a runtime crash due to dereferencing nullptr
    std::cout << "Testing with nullptr: " << customStrlen(s5) << std::endl; 

    return 0; // This return might not be reached if the program crashes before it.
}