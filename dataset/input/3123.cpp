#include <iostream>
#include <string>
#include <vector> // Included for completeness

class Student {
private:
    std::string name_;
    int id_;
    double grade_;

public:
    // Default constructor
    Student() : name_(""), id_(0), grade_(0.0) {}

    // Parameterized constructor
    Student(const std::string& name, int id, double grade)
        : name_(name), id_(id), grade_(grade) {
        // Basic validation in constructor for initial values
        if (id_ <= 0) id_ = 0; // Default to 0 or throw error
        if (grade_ < 0.0 || grade_ > 100.0) grade_ = 0.0; // Default to 0.0
    }

    // Getter for name (returns const reference for efficiency)
    const std::string& getName() const {
        return name_;
    }

    // Setter for name (takes const reference for efficiency, includes basic validation)
    void setName(const std::string& name) {
        if (!name.empty()) {
            name_ = name;
        } else {
            std::cerr << "Error: Student name cannot be empty. Keeping current name." << std::endl;
        }
    }

    // Getter for id
    int getId() const {
        return id_;
    }

    // Setter for id (includes basic validation)
    void setId(int id) {
        if (id > 0) {
            id_ = id;
        } else {
            std::cerr << "Error: Student ID must be positive. Keeping current ID." << std::endl;
        }
    }

    // Getter for grade
    double getGrade() const {
        return grade_;
    }

    // Setter for grade (includes basic validation)
    void setGrade(double grade) {
        if (grade >= 0.0 && grade <= 100.0) {
            grade_ = grade;
        } else {
            std::cerr << "Error: Grade must be between 0 and 100. Keeping current grade." << std::endl;
        }
    }
};

int main() {
    Student s; // Default constructor
    s.setName("Alice");
    s.setId(101);
    s.setGrade(95.5);

    std::cout << "Student 1 Initial Data:" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    std::cout << "\nAttempting to set invalid values (with validation):" << std::endl;
    s.setId(-5); // Invalid ID
    s.setGrade(105.0); // Invalid grade
    s.setName(""); // Empty name

    std::cout << "\nStudent 1 After Invalid Sets (values should remain unchanged if invalid):" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    Student s2("Bob", 202, 88.0); // Parameterized constructor
    std::cout << "\nStudent 2 Initial Data:" << std::endl;
    std::cout << "Name: " << s2.getName() << std::endl;
    std::cout << "ID: " << s2.getId() << std::endl;
    std::cout << "Grade: " << s2.getGrade() << std::endl;

    s2.setGrade(-10.0); // Another invalid grade
    std::cout << "\nStudent 2 After another invalid grade set:" << std::endl;
    std::cout << "Name: " << s2.getName() << std::endl;
    std::cout << "ID: " << s2.getId() << std::endl;
    std::cout << "Grade: " << s2.getGrade() << std::endl;

    Student s3("Charlie", -300, 110.0); // Invalid values in constructor
    std::cout << "\nStudent 3 (constructed with invalid data):" << std::endl;
    std::cout << "Name: " << s3.getName() << std::endl;
    std::cout << "ID: " << s3.getId() << std::endl;
    std::cout << "Grade: " << s3.getGrade() << std::endl;

    return 0;
}