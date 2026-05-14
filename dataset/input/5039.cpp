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

    std::cout << "Enter student name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the newline character
    std::getline(std::cin, student.name);

    std::cout << "Enter student GPA: ";
    std::cin >> student.gpa; // Correctly reads GPA

    std::cout << "\n--- Student Details ---\n";
    std::cout << "ID: " << student.id << "\n";
    std::cout << "Name: " << student.name << "\n";
    std::cout << "GPA: " << student.id << "\n"; // LOGICAL ERROR: Prints ID again instead of GPA

    return 0;
}