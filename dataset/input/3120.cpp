#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;
    double grade;

public:
    // Constructor to initialize members
    Student() : name(""), id(0), grade(0.0) {}

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for id
    int getId() const {
        return id;
    }

    // Setter for id
    void setId(int newId) {
        id = newId;
    }

    // Getter for grade - SEMANTIC ERROR HERE: Modifies state and is not const
    // A getter should typically not modify the object's state.
    // It should be declared 'const' to enforce this.
    double getGrade() { // Should be 'double getGrade() const {'
        grade += 0.1; // This getter modifies the grade!
        return grade;
    }

    // Setter for grade
    void setGrade(double newGrade) {
        grade = newGrade;
    }
};

int main() {
    Student s;
    std::cout << "Initial State:" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl; // grade becomes 0.1

    std::cout << "\nSetting values..." << std::endl;
    s.setName("Charlie");
    s.setId(303);
    s.setGrade(70.0);

    std::cout << "Current State (after setGrade(70.0)):" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl; // grade becomes 70.1
    std::cout << "Grade (again): " << s.getGrade() << std::endl; // grade becomes 70.2
    std::cout << "Grade (yet again): " << s.getGrade() << std::endl; // grade becomes 70.3

    std::cout << "\nChecking final grade:" << std::endl;
    std::cout << "Final Grade: " << s.getGrade() << std::endl; // grade becomes 70.4

    return 0;
}