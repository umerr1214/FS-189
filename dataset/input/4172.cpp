#include <iostream> // For std::cin, std::cout, std::endl
#include <string>
#include <cstdio>   // For printf

// This 'main' function has been renamed to 'student_main_logic' for testing purposes.
// In a typical standalone execution, this would be 'int main()'.
int student_main_logic() {
    std::string n; // Uninformative variable name
    int a;         // Uninformative variable name
    double h;      // Uninformative variable name

    std::cout << "Enter your name: " << std::endl; // Overuse of std::endl, which flushes the buffer unnecessarily.
    std::getline(std::cin, n);

    std::cout << "Enter your age: " << std::endl; // Overuse of std::endl.
    std::cin >> a;

    std::cout << "Enter your height (m): " << std::endl; // Overuse of std::endl.
    std::cin >> h;

    // Using printf for output, which is C-style and less C++ idiomatic than std::cout.
    // It requires converting std::string to C-style string (n.c_str()) and is less type-safe.
    // The format string (%.2f) also dictates specific precision, which might not always be desired.
    printf("\nGreetings, %s! You are %d years old and %.2f meters tall.\n", n.c_str(), a, h);

    return 0;
}