#include <iostream> // For std::cout, std::cin, std::endl, std::fixed, std::setprecision
#include <string>   // For std::string, std::getline
#include <limits>   // For std::numeric_limits
#include <iomanip>  // For std::fixed, std::setprecision

// Define the Student struct with its required members
struct Student {
    int studentID;
    std::string name;
    double gpa;
};

int main() {
    Student student; // Create an instance of Student

    // Prompt for student ID with robust input validation
    while (true) {
        std::cout << "Enter student ID (integer): ";
        std::cin >> student.studentID;

        if (std::cin.fail()) { // Check if the input operation failed (e.g., non-integer input)
            std::cout << "Invalid input. Please enter an integer for student ID.\n";
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard the invalid input from the buffer up to the next newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid integer input, exit the loop
        }
    }
    // Clear the input buffer after reading studentID to consume the leftover newline character,
    // preparing for the subsequent std::getline call.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Prompt for student name
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name);

    // Prompt for student GPA with robust input and range validation
    while (true) {
        std::cout << "Enter student GPA (double, e.g., 3.5): ";
        std::cin >> student.gpa;

        if (std::cin.fail()) { // Check for non-numeric input
            std::cout << "Invalid input. Please enter a valid number for GPA.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        } else if (student.gpa < 0.0 || student.gpa > 4.0) { // Check for valid GPA range
            std::cout << "GPA should be between 0.0 and 4.0. Please re-enter.\n";
            // No std::cin.clear() needed here as input was valid, but discard the line.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid numeric input within range, exit loop
        }
    }

    // Print all the student's information clearly and formatted
    std::cout << "\n--- Student Information ---\n";
    std::cout << "ID: " << student.studentID << '\n'; // Using '\n' for efficiency
    std::cout << "Name: " << student.name << '\n';
    // Use std::fixed and std::setprecision for consistent GPA output formatting
    std::cout << "GPA: " << std::fixed << std::setprecision(2) << student.gpa << '\n';

    return 0;
}