#include <iostream>
#include <string>
#include <cstdio> // Required for printf

struct Student {
    std::string name;
    int id;
    float score;
};

int main() {
    Student s;

    std::cout << "Enter student name: ";
    std::getline(std::cin, s.name);

    std::cout << "Enter student ID: ";
    std::cin >> s.id;

    std::cout << "Enter student score: ";
    std::cin >> s.score;

    std::cout << "\n--- Student Details ---\n";
    // Semantic error: Using printf with %s format specifier for std::string directly.
    // printf expects a C-style string (char*), not a std::string object.
    // This compiles but leads to undefined behavior (e.g., crash or garbage output).
    // The correct way would be printf("Name: %s\n", s.name.c_str());
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("Score: %.2f\n", s.score);

    return 0;
}