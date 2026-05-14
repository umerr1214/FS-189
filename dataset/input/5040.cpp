#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

struct Student {
    int id;
    std::string name;
    double gpa;
};

int main() {
    Student student;

    std::cout << "Enter student ID: ";
    std::cin >> student.id;

    // SEMANTIC ERROR: Using std::cin >> for name, which only reads a single word.
    // If the name has spaces, only the first word is captured by 'name'.
    // The rest of the input line remains in the buffer.
    std::cout << "Enter student name (e.g., John Doe): ";
    std::cin >> student.name; // This reads "Alice" if input is "Alice Smith"

    std::cout << "Enter student GPA: ";
    // This attempts to read the next token from the buffer.
    // If the name was "Alice Smith", 'name' got "Alice", and 'gpa' will now try to read "Smith".
    // "Smith" cannot be converted to a double, leading to std::cin entering a fail state.
    std::cin >> student.gpa;

    // Handle potential input failure for GPA
    if (std::cin.fail()) {
        std::cout << "(Input error for GPA detected. Setting GPA to 0.0)\n";
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining bad input
        student.gpa = 0.0; // Assign a default value as it wasn't read correctly
    } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume remaining newline after gpa
    }

    std::cout << "\n--- Student Details ---\n";
    std::cout << "ID: " << student.id << "\n";
    std::cout << "Name: " << student.name << "\n";
    std::cout << "GPA: " << student.gpa << "\n";

    return 0;
}