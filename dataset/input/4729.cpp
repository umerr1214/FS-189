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
    // Dynamically allocate an array of 3 Student structs
    Student* students = new Student[3];

    // Populate data for the first student
    students[0].id = 101;
    students[0].name = "Alice Smith";
    students[0].grade = 95.50;

    // Populate data for the second student
    students[1].id = 102;
    students[1].name = "Bob Johnson";
    students[1].grade = 88.75;

    // Populate data for the third student
    students[2].id = 103;
    students[2].name = "Charlie Brown";
    students[2].grade = 72.00;

    // Print the details of each student
    for (int i = 0; i < 3; ++i) {
        std::cout << "Student ID: " << students[i].id << std::endl;
        std::cout << "Name: " << students[i].name << std::endl;
        std::cout << std::fixed << std::setprecision(2); // Format grade to 2 decimal places
        std::cout << "Grade: " << students[i].grade << std::endl;
        if (i < 2) { // Add a blank line between students, but not after the last one
            std::cout << std::endl;
        }
    }

    // CRITICAL ROBUSTNESS ISSUE:
    // Memory leak: The dynamically allocated array 'students' is not deallocated
    // using 'delete[] students;'. This leads to a memory leak.

    return 0;
}