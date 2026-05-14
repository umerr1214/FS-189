#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

// Define the Student struct
struct Student {
    std::string name;
    int id;
    float score;
};

int main() {
    Student s;

    // Prompt for user input
    std::cout << "Enter student name (single word): ";
    std::cin >> s.name; // Robustness issue: will only read one word for name

    std::cout << "Enter student ID (integer): ";
    std::cin >> s.id; // Robustness issue: No input validation. If non-integer, cin fails and s.id might be 0 or garbage.

    std::cout << "Enter student score (float): ";
    std::cin >> s.score; // Robustness issue: No input validation. If non-float, cin fails and s.score might be 0.0f or garbage.

    // Print student details
    std::cout << "\n--- Student Details ---\n";
    std::cout << "Name: " << s.name << "\n";
    std::cout << "ID: " << s.id << "\n";
    std::cout << "Score: " << s.score << "\n";

    return 0;
}