#include <iostream>
#include <limits> // Required for std::numeric_limits

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

        // Clear the input buffer before reading string to handle leftover newlines
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Name (max 49 chars): ";
        std::cin.getline(students[i].name, 50);

        // Input validation loop for studentID
        std::cout << "Student ID: ";
        while (!(std::cin >> students[i].studentID)) {
            std::cout << "Invalid input. Please enter an integer for Student ID: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }

        // Input validation loop for GPA
        std::cout << "GPA: ";
        while (!(std::cin >> students[i].GPA)) {
            std::cout << "Invalid input. Please enter a floating-point number for GPA: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
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