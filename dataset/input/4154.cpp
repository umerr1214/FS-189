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

    // Readability/Efficiency Issue: Repetitive code for input for student 1
    std::cout << "Enter details for student 1:" << std::endl;
    // Clearing the buffer is necessary here to handle newline left by previous inputs
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "Name (max 49 chars): ";
    std::cin.getline(students[0].name, 50);
    std::cout << "Student ID: ";
    std::cin >> students[0].studentID;
    std::cout << "GPA: ";
    std::cin >> students[0].GPA;

    // Readability/Efficiency Issue: Repetitive code for input for student 2
    std::cout << "\nEnter details for student 2:" << std::endl;
    // Clearing the buffer is necessary here to handle newline left by previous inputs
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "Name (max 49 chars): ";
    std::cin.getline(students[1].name, 50);
    std::cout << "Student ID: ";
    std::cin >> students[1].studentID;
    std::cout << "GPA: ";
    std::cin >> students[1].GPA;

    // Print the details of both students
    std::cout << "\n--- Student Details ---" << std::endl;

    // Readability/Efficiency Issue: Repetitive code for output for student 1
    std::cout << "Student 1:" << std::endl;
    std::cout << "  Name: " << students[0].name << std::endl;
    std::cout << "  ID: " << students[0].studentID << std::endl;
    std::cout << "  GPA: " << students[0].GPA << std::endl;

    // Readability/Efficiency Issue: Repetitive code for output for student 2
    std::cout << "Student 2:" << std::endl;
    std::cout << "  Name: " << students[1].name << std::endl;
    std::cout << "  ID: " << students[1].studentID << std::endl;
    std::cout << "  GPA: " << students[1].GPA << std::endl;

    return 0;
}