#include <iostream>
#include <string>

struct Student {
    std::string name;
    int id;
    float score;
} // ERROR: Missing semicolon here, which is a syntax error

int main() {
    Student s;

    std::cout << "Enter student name: ";
    std::getline(std::cin, s.name);

    std::cout << "Enter student ID: ";
    std::cin >> s.id;

    std::cout << "Enter student score: ";
    std::cin >> s.score;

    std::cout << "\n--- Student Details ---\n";
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "ID: " << s.id << std::endl;
    std::cout << "Score: " << s.score << std::endl;

    return 0;
}