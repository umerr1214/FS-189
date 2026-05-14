#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

struct Student {
    int id;
    std::string name;
    double gpa;
};

int main() {
    Student s;

    std::cout << "Enter student ID: ";
    // This reads the integer ID but leaves the newline character in the input buffer.
    // If invalid input is provided (e.g., text), cin will enter a fail state,
    // and subsequent reads will also fail without proper error handling.
    std::cin >> s.id;

    std::cout << "Enter student name: ";
    // This getline will immediately read the leftover newline from the previous std::cin >> s.id;
    // if the user pressed Enter after the ID. This results in s.name being an empty string,
    // which is a robustness issue as it doesn't handle common user input patterns.
    // A robust solution would use std::cin.ignore() here.
    std::getline(std::cin, s.name);

    std::cout << "Enter student GPA: ";
    // Similar to ID, if invalid input is provided, cin will fail.
    // No error handling or input validation is present for any input.
    std::cin >> s.gpa;

    std::cout << "\n--- Student Details ---\n";
    std::cout << "ID: " << s.id << std::endl;
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "GPA: " << s.gpa << std::endl;

    return 0;
}