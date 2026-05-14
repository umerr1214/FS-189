#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int id;

public:
    // Default constructor - Logical error: 'id' initialized to -1 instead of 0
    Student() : name("Unknown"), id(-1) {}

    // Parameterized constructor
    Student(std::string name, int id) : name(name), id(id) {}

    // Getter methods
    std::string getName() const { return name; }
    int getId() const { return id; }
};

int main() {
    Student s1; // Default student
    Student s2("Bob", 202); // Parameterized student

    std::cout << "Student 1 Name: " << s1.getName() << ", ID: " << s1.getId() << std::endl;
    std::cout << "Student 2 Name: " << s2.getName() << ", ID: " << s2.getId() << std::endl;

    return 0;
}