#include <iostream>
#include <string>
#include <limits> // Included but not fully utilized for robustness, which is not the primary error category here.

int main() {
    std::string n1; // Poor variable name for first name
    std::string n2; // Poor variable name for last name
    int a;          // Poor variable name for age

    std::cout << "Enter your first name: ";
    std::getline(std::cin >> std::ws, n1); // Reads full first name, but variable name is uninformative.

    std::cout << "Enter your last name: ";
    std::getline(std::cin, n2); // Reads full last name.

    std::cout << "Enter your age: ";
    std::cin >> a; // No robustness for non-integer input, but the program is still mostly correct for valid input.

    // Inefficient and verbose string construction by concatenating multiple temporary strings
    std::string greeting_part1 = "Hello, ";
    std::string greeting_part2 = n1;
    std::string greeting_part3 = " ";
    std::string greeting_part4 = n2;
    std::string greeting_part5 = ", you are ";
    std::string greeting_part6 = std::to_string(a);
    std::string greeting_part7 = " years old.";
    std::string final_greeting = greeting_part1 + greeting_part2 + greeting_part3 + greeting_part4 + greeting_part5 + greeting_part6 + greeting_part7;

    std::cout << final_greeting << std::endl; // Uses std::endl, which flushes the buffer, potentially less efficient than '\n'.
    std::cout << std::endl; // Unnecessary extra newline for no functional purpose, impacting readability/efficiency.

    return 0;
}