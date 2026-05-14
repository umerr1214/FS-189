#include <iostream> // For input/output operations
#include <string>   // For std::string
#include <vector>   // For std::vector
#include <iomanip>  // For std::fixed and std::setprecision

// Define the Student struct with its members
struct Student {
    int id;
    std::string name;
    double grade;
};

int main() {
    // Create a vector (dynamic array) of 3 Student structs and populate their data
    // Using an initializer list for concise and readable initialization
    std::vector<Student> students = {
        {101, "Alice Smith", 95.50},
        {102, "Bob Johnson", 88.75},
        {103, "Charlie Brown", 72.00}
    };

    // Set output formatting for grades once
    std::cout << std::fixed << std::setprecision(2);

    // Print the details of each student using a range-based for loop for readability
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& s = students[i]; // Use const reference for efficiency and safety
        std::cout << "Student ID: " << s.id << std::endl;
        std::cout << "Name: " << s.name << std::endl;
        std::cout << "Grade: " << s.grade << std::endl;
        if (i < students.size() - 1) {
            std::cout << std::endl; // Add a blank line between students
        }
    }

    return 0; // Indicate successful execution
}