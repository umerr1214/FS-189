#include <string>
#include <iostream>

class Student {
private:
    std::string name;
public: // Semantic error: 'id' is declared public, violating the private access requirement.
    int id;

public:
    // Default constructor
    Student() : name("Unknown"), id(0) {}

    // Parameterized constructor
    Student(std::string name, int id) : name(name), id(id) {}

    // Getter for name (id can be accessed directly due to public declaration)
    std::string getName() const { return name; }
    // int getId() const { return id; } // No need for getter if public, but violates encapsulation.
};

int main() {
    Student s1; // Default student
    Student s2("Charlie", 303); // Parameterized student

    std::cout << "Student 1 Name: " << s1.getName() << ", ID: " << s1.id << std::endl; // Direct access to public 'id'
    std::cout << "Student 2 Name: " << s2.getName() << ", ID: " << s2.id << std::endl; // Direct access to public 'id'

    // Demonstrating the implication of public 'id': it can be modified directly
    s1.id = 999;
    std::cout << "Student 1 new ID: " << s1.id << std::endl;

    return 0;
}