#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

struct Student {
    std::string name;
    int id;
    float score;
};

int main() {
    Student s;

    // Prompt for ID first
    std::cout << "Enter student ID: ";
    std::cin >> s.id;

    // Prompt for score
    std::cout << "Enter student score: ";
    std::cin >> s.score;

    // Logical error: The newline character from the previous std::cin >> s.score;
    // remains in the input buffer. The subsequent std::getline will read this newline
    // immediately, resulting in an empty string for s.name.
    // To fix this, std::cin.ignore() should be used before std::getline.
    std::cout << "Enter student name: ";
    std::getline(std::cin, s.name);

    std::cout << "\n--- Student Details ---\n";
    std::cout << "Name: " << s.name << std::endl; // This will likely be empty
    std::cout << "ID: " << s.id << std::endl;
    std::cout << "Score: " << s.score << std::endl;

    return 0;
}