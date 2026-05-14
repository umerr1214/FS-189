#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int id;
    double grade;

    // Default constructor: Correctly initializes members to default values
    Student() : name(""), id(0), grade(0.0) {}

    // Parameterized constructor: Logical error due to parameter shadowing.
    // The parameters 'name', 'id', 'grade' shadow the member variables 'this->name',
    // 'this->id', 'this->grade'. The assignments in the constructor body assign
    // parameters to themselves, leaving the member variables uninitialized by parameters.
    // Member variables 'name', 'id', 'grade' will retain their default-initialized values
    // (empty string, 0, 0.0) as they are not explicitly initialized in the initializer list.
    Student(std::string name, int id, double grade) {
        name = name; // Assigns parameter 'name' to itself
        id = id;     // Assigns parameter 'id' to itself
        grade = grade; // Assigns parameter 'grade' to itself
    }

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << std::endl;
    }
};

int main() {
    // Test default constructor
    Student s1;
    s1.display();

    // Test parameterized constructor with logical error
    Student s2("Alice", 101, 95.5);
    s2.display(); // Expected: Alice, 101, 95.5. Actual: , 0, 0.0

    Student s3("Bob", 202, 88.0);
    s3.display(); // Expected: Bob, 202, 88.0. Actual: , 0, 0.0

    return 0;
}