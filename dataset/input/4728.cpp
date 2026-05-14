#include <iostream>
// #include <string> // Semantic Error: Missing include for std::string

// Define the Student struct
struct Student {
    int id;
    std::string name; // std::string is an undeclared type without <string>
    double grade;
};

int main() {
    // Create an array of 3 Student structs
    Student students[3];

    // Populate their data
    students[0].id = 101;
    students[0].name = "Alice";
    students[0].grade = 95.5;

    students[1].id = 102;
    students[1].name = "Bob";
    students[1].grade = 88.0;

    students[2].id = 103;
    students[2].name = "Charlie";
    students[2].grade = 76.2;

    // Print the details of each student
    for (int i = 0; i < 3; ++i) {
        std::cout << "Student ID: " << students[i].id
                  << ", Name: " << students[i].name
                  << ", Grade: " << students[i].grade << std::endl;
    }

    return 0;
}