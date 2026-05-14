#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    double gpa;
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Student student;

    std::cout << "Enter student ID: ";
    std::cin >> student.id;

    std::cout << "Enter student name: ";
    std::cin.ignore(); // Consume the newline character left by std::cin >> id
    std::getline(std::cin, student.name);

    std::cout << "Enter student GPA: ";
    std::cin >> student.gpa;

    std::cout << "\n--- Student Details ---\n";
    std::cout << "ID: " << student.id << "\n";
    std::cout << "Name: " << student.name << "\n";
    std::cout << "GPA: " << student.gpa << "\n";

    return 0;
}