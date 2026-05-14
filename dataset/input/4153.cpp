#include <iostream>

// Define the Student structure
struct Student {
    char name[50];
    int studentID;
    float GPA;
};

int main() {
    // Create an array of 2 Student objects
    Student students[2];

    // Allow the user to input data for each student
    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter details for student " << i + 1 << ":" << std::endl;

        // Robustness Issue 1: Using cin >> for name.
        // This only reads a single word (token) and stops at whitespace.
        // It does not clear the input buffer, potentially leaving remaining words
        // or the newline character from previous inputs, which can interfere
        // with subsequent std::cin operations.
        std::cout << "Name (single word expected): ";
        std::cin >> students[i].name;

        // Robustness Issue 2: No input validation for studentID.
        // If non-numeric input is given, std::cin will enter a fail state.
        // Subsequent reads will fail, often leading to an infinite loop if in a loop,
        // or incorrect default values (e.g., 0) and failure to read further inputs.
        std::cout << "Student ID: ";
        std::cin >> students[i].studentID;

        // Robustness Issue 3: No input validation for GPA.
        // Same issue as studentID, leading to potential program instability or incorrect data.
        std::cout << "GPA: ";
        std::cin >> students[i].GPA;
    }

    // Print the details of both students
    std::cout << "\n--- Student Details ---" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Student " << i + 1 << ":" << std::endl;
        std::cout << "  Name: " << students[i].name << std::endl;
        std::cout << "  ID: " << students[i].studentID << std::endl;
        std::cout << "  GPA: " << students[i].GPA << std::endl;
    }

    return 0;
}