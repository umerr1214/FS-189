#include <string>
#include <iostream>

class Student {
private:
    std::string name; // ERROR: Missing semicolon here
    int id;

public:
    // Default constructor
    Student() : name("Unknown"), id(0) {}

    // Parameterized constructor
    Student(std::string name, int id) : name(name), id(id) {}

    // Getter methods
    std::string getName() const { return name; }
    int getId() const { return id; }
};

int main() {
    Student s1; // Default student
    Student s2("Alice", 101); // Parameterized student

    std::cout << "Student 1 Name: " << s1.getName() << ", ID: " << s1.getId() << std::endl;
    std::cout << "Student 2 Name: " << s2.getName() << ", ID: " << s2.getId() << std::endl;

    return 0;
}