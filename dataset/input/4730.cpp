#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

// Define the Student struct
struct Student {
    int id;
    std::string name;
    double grade;
};

int main() {
    // Create an array of 3 Student structs
    Student students[3];

    // Populate data for the first student - verbose assignment
    students[0].id = 101;
    students[0].name = "Alice Smith";
    students[0].grade = 95.50;

    // Populate data for the second student - verbose assignment
    students[1].id = 102;
    students[1].name = "Bob Johnson";
    students[1].grade = 88.75;

    // Populate data for the third student - verbose assignment
    students[2].id = 103;
    students[2].name = "Charlie Brown";
    students[2].grade = 72.00;

    // Print the details of each student - highly repetitive code
    // Student 1
    std::cout << "Student ID: " << students[0].id << std::endl;
    std::cout << "Name: " << students[0].name << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Grade: " << students[0].grade << std::endl;
    std::cout << std::endl; // Add a blank line

    // Student 2
    std::cout << "Student ID: " << students[1].id << std::endl;
    std::cout << "Name: " << students[1].name << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Grade: " << students[1].grade << std::endl;
    std::cout << std::endl; // Add a blank line

    // Student 3
    std::cout << "Student ID: " << students[2].id << std::endl;
    std::cout << "Name: " << students[2].name << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Grade: " << students[2].grade << std::endl;
    // No blank line after the last student as per expected output
    
    return 0;
}