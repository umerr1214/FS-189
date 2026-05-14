#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits, though not used correctly here

// Define the Student struct
struct Student {
    int studentID = 0; // Initialize for deterministic behavior on input failure
    std::string name;
    double gpa = 0.0; // Initialize for deterministic behavior on input failure
};

int main() {
    Student student; // Create an instance of Student

    std::cout << "Enter student ID: ";
    std::cin >> student.studentID; // Reads integer, leaves newline in buffer

    // This std::getline will immediately read the leftover newline character
    // from the previous std::cin >> student.studentID; call.
    // As a result, 'student.name' will be an empty string, and the actual
    // name input from the user will be skipped.
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name); 

    std::cout << "Enter student GPA: ";
    // If the user then enters non-numeric input (e.g., the skipped 'John Doe' from test case),
    // std::cin will fail, set error flags, and student.gpa will retain its default value (0.0).
    std::cin >> student.gpa; 

    // Print all the student's information
    std::cout << "\n--- Student Information ---\n";
    std::cout << "ID: " << student.studentID << std::endl;
    std::cout << "Name: " << student.name << std::endl; // Will likely be empty
    std::cout << "GPA: " << student.gpa << std::endl;   // Might be 0.0 if previous input failed

    return 0;
}