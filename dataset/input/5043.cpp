#include <iostream>   // For std::cin, std::cout, std::endl
#include <string>     // For std::string
#include <limits>     // For std::numeric_limits to clear input buffer reliably

// Define the Student struct as required
struct Student {
    int id;
    std::string name;
    double gpa;
};

int main() {
    Student s;

    std::cout << "Enter student ID: ";
    // Robust input loop for integer ID: handles non-numeric input by clearing error flags
    // and discarding invalid input, prompting the user to try again.
    while (!(std::cin >> s.id)) {
        std::cout << "Invalid input. Please enter an integer for ID: ";
        std::cin.clear(); // Clear the error flag on cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    // Consume the leftover newline character after reading the integer ID,
    // so that std::getline reads the actual name on the next line.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter student name: ";
    // Uses std::getline to read the entire line for the name, including spaces,
    // making it robust for multi-word names.
    std::getline(std::cin, s.name);

    std::cout << "Enter student GPA: ";
    // Robust input loop for double GPA: handles non-numeric input similarly to ID.
    while (!(std::cin >> s.gpa)) {
        std::cout << "Invalid input. Please enter a number for GPA: ";
        std::cin.clear(); // Clear the error flag on cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    // No need for std::cin.ignore() after the last numerical input as no further input is expected.

    std::cout << "\n--- Student Details ---\n";
    std::cout << "ID: " << s.id << std::endl;
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "GPA: " << s.gpa << std::endl;

    return 0;
}