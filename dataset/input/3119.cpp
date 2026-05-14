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

    // Getter for grade
    double getGrade() const {
        return grade;
    }

    // Setter for grade - LOGICAL ERROR HERE
    void setGrade(double newGrade) {
        id = static_cast<int>(newGrade); // INCORRECT: Should be 'grade = newGrade;'
    }
};

int main() {
    Student s;
    std::cout << "Initial State:" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    std::cout << "\nSetting values..." << std::endl;
    s.setName("Bob");
    s.setId(202);
    s.setGrade(88.8); // This will incorrectly set ID to 88

    std::cout << "Current State (after setGrade(88.8)): " << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl; // Expected 202, actual 88
    std::cout << "Grade: " << s.getGrade() << std::endl; // Expected 88.8, actual 0.0 (unmodified)

    // Demonstrate the error clearly with another object
    std::cout << "\nFurther check with s2:" << std::endl;
    Student s2;
    s2.setGrade(75.0); // This will incorrectly set s2's ID to 75
    std::cout << "S2 ID after setGrade(75.0): " << s2.getId() << std::endl; // Should be 0, but is 75
    std::cout << "S2 Grade after setGrade(75.0): " << s2.getGrade() << std::endl; // Should be 75.0, but is 0.0

    return 0;
}