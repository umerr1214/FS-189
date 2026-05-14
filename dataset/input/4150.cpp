#include <iostream>
#include <cstring> // Required for strcpy or other C-string functions if needed
#include <limits>  // Required for std::numeric_limits

// Syntax Error: Missing semicolon after struct definition
struct Student {
    char name[50];
    int studentID;
    float GPA;
} 

int main() {
    Student students[2];

    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter details for Student " << i + 1 << ":" << std::endl;
        std::cout << "Name: ";
        // Clear the input buffer before reading a line with spaces
        if (i == 0) { // Only needed for the first student if no prior numeric input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.getline(students[i].name, 50);
        
        std::cout << "Student ID: ";
        std::cin >> students[i].studentID;
        
        std::cout << "GPA: ";
        std::cin >> students[i].GPA;
        
        // Consume the rest of the line, including the newline, to prevent issues in the next iteration
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