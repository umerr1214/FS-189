#include <iostream> // For std::cout, std::cin, std::endl, std::ws
#include <string>   // For std::string
#include <limits>   // For std::numeric_limits
#include <ios>      // For std::streamsize

// Define the Student struct
struct Student {
    std::string name;
    int id;
    float score;
};

int main() {
    Student studentData; // Use a descriptive variable name

    // Prompt for user input for name (robustly handling spaces)
    std::cout << "Enter student name: ";
    // Use std::ws to consume any leading whitespace (like a leftover newline from a previous input, though not strictly needed here as it's the first input)
    std::getline(std::cin >> std::ws, studentData.name); 

    // Prompt for user input for ID with validation
    std::cout << "Enter student ID (integer): ";
    std::cin >> studentData.id;
    if (std::cin.fail()) {
        std::cerr << "Invalid input for ID. Please enter an integer.\n";
        std::cin.clear(); // Clear the error flags
        // Ignore the rest of the invalid line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Prompt for user input for score with validation
    std::cout << "Enter student score (float): ";
    std::cin >> studentData.score;
    if (std::cin.fail()) {
        std::cerr << "Invalid input for score. Please enter a floating-point number.\n";
        std::cin.clear(); // Clear the error flags
        // Ignore the rest of the invalid line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Print student details using clear messages and efficient newlines
    std::cout << "\n--- Student Details ---\n";
    std::cout << "Name: " << studentData.name << '\n';
    std::cout << "ID: " << studentData.id << '\n';
    std::cout << "Score: " << studentData.score << '\n';

    return 0; // Indicate successful execution
}