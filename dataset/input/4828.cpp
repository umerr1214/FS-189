#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

struct Student {
    int studentID;
    std::string name;
    double gpa;
} // Syntax Error: Missing semicolon here

int main() {
    Student s;

    std::cout << "Enter student ID: ";
    std::cin >> s.studentID;

    // Clear the input buffer after reading an integer to prepare for getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter student name: ";
    std::getline(std::cin, s.name);

    std::cout << "Enter student GPA: ";
    std::cin >> s.gpa;

    std::cout << "\nStudent Information:\n";
    std::cout << "ID: " << s.studentID << std::endl;
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "GPA: " << s.gpa << std::endl;

    return 0;
}