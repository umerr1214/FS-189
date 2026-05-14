#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

struct Student {
    int studentID;
    std::string name;
    double gpa;
};

int main() {
    Student s;

    std::cout << "Enter student ID: ";
    std::cin >> s.studentID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Correctly clear buffer for name

    std::cout << "Enter student name: ";
    std::getline(std::cin, s.name); // Correctly read name

    std::cout << "Enter student GPA: ";
    std::cin >> s.gpa;
    // Semantic Error: The program does not check the state of std::cin after reading 'gpa'.
    // If the user enters non-numeric input for GPA (e.g., "abc"), std::cin will enter a
    // fail state, `s.gpa` will be left uninitialized (or 0), and subsequent operations
    // on `std::cin` might not work as expected. The program proceeds to print an
    // incorrect GPA (0) without indicating an input error, semantically misinterpreting
    // the user's input as a valid zero.
    // A robust solution would check `if (std::cin.fail())` and handle the error.

    std::cout << "\nStudent Information:\n";
    std::cout << "ID: " << s.studentID << std::endl;
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "GPA: " << s.gpa << std::endl; // Will print 0 if input failed

    return 0;
}