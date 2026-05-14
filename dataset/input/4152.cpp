#include <iostream>
#include <cstring> // Required for strcpy if needed
#include <limits>  // Required for std::numeric_limits

struct Student {
    char name[50];
    int studentID;
    float GPA;
};

int main() {
    Student students[2];

    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter details for Student " << i + 1 << ":" << std::endl;
        
        std::cout << "Student ID: ";
        std::cin >> students[i].studentID;
        
        // Semantic error: Missing std::cin.ignore() after numeric input.
        // The leftover newline character from std::cin >> students[i].studentID
        // will be consumed by the subsequent std::cin.getline,
        // causing the name to be read as an empty string.
        std::cout << "Name: ";
        std::cin.getline(students[i].name, 50);
        
        std::cout << "GPA: ";
        std::cin >> students[i].GPA;
        
        // Consume the rest of the line, including the newline, for the next iteration's ID input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n--- Student Details ---" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Student " << i + 1 << ":" << std::endl;
        std::cout << "  Name: " << students[i].name << std::endl;
        std::cout << "  ID: " << students[i].studentID << std::endl;
        std::cout << "  GPA: " << students[i].GPA << std::endl;
    }

    return 0;
}