#include <iostream>
#include <string>
// #include <limits> // Not used for this specific logical error

struct Student {
    int studentID;
    std::string name;
    double gpa;
};

int main() {
    Student s;

    std::cout << "Enter student ID: ";
    std::cin >> s.studentID;

    // Logical Error: Using operator>> for std::string name, which only reads
    // a single word and leaves any remaining characters (including spaces and newlines)
    // in the input buffer. If the user enters a multi-word name, only the first
    // word will be captured. Furthermore, if the input for GPA is then also
    // on the same line or includes remaining words, std::cin >> s.gpa will fail.
    std::cout << "Enter student name: ";
    std::cin >> s.name; // Should be std::getline(std::cin.ignore(), s.name); or similar

    std::cout << "Enter student GPA: ";
    std::cin >> s.gpa;

    std::cout << "\nStudent Information:\n";
    std::cout << "ID: " << s.studentID << std::endl;
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "GPA: " << s.gpa << std::endl;

    return 0;
}