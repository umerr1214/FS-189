#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name // SYNTAX ERROR: Missing semicolon here
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
    std::cout << "Grade: " << s.getGrade() << std::endl;

    std::cout << "\nSetting values..." << std::endl;
    s.setName("Alice");
    s.setId(101);
    s.setGrade(95.5);

    std::cout << "Current State:" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    return 0;
}