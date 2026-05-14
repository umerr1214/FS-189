#include <iostream>
#include <cstring> // Required for strcpy if needed, not for cin >> char_array
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
        std::cout << "Name (single word): "; // Logical error: std::cin >> only reads one word
        std::cin >> students[i].name; 
        
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
        // Logical error: Always prints details of students[0] instead of students[i]
        std::cout << "  Name: " << students[0].name << std::endl; 
        std::cout << "  ID: " << students[0].studentID << std::endl;
        std::cout << "  GPA: " << students[0].GPA << std::endl;
    }

    return 0;
}