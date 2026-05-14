#include <iostream>
#include <string>
#include <vector> // Included for completeness, though not strictly used by Student class itself

class Student {
private:
    std::string _name;
    int _id;
    double _grade;

public:
    // Default constructor
    Student() : _name(""), _id(0), _grade(0.0) {}

    // Parameterized constructor
    Student(const std::string& name, int id, double grade)
        : _name(name), _id(id), _grade(grade) {}

    // Getter for name
    std::string getName() const {
        return _name;
    }

    // Setter for name - Lacks validation for empty string
    void setName(const std::string& name) {
        _name = name;
    }

    // Getter for id
    int getId() const {
        return _id;
    }

    // Setter for id - Lacks validation for negative or zero ID
    void setId(int id) {
        _id = id;
    }

    // Getter for grade
    double getGrade() const {
        return _grade;
    }

    // Setter for grade - Lacks validation for grade range (e.g., 0-100)
    void setGrade(double grade) {
        _grade = grade;
    }
};

int main() {
    Student s;
    s.setName("Alice");
    s.setId(101);
    s.setGrade(95.5);

    std::cout << "Student 1 Initial Data:" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    std::cout << "\nAttempting to set invalid values (no validation):" << std::endl;
    s.setId(-5); // Setting a negative ID
    s.setGrade(105.0); // Setting a grade outside 0-100
    s.setName(""); // Setting an empty name

    std::cout << "\nStudent 1 After Invalid Sets:" << std::endl;
    std::cout << "Name: " << (s.getName().empty() ? "[EMPTY]" : s.getName()) << std::endl;
    std::cout << "ID: " << s.getId() << std::endl;
    std::cout << "Grade: " << s.getGrade() << std::endl;

    Student s2("Bob", 202, 88.0);
    std::cout << "\nStudent 2 Initial Data:" << std::endl;
    std::cout << "Name: " << s2.getName() << std::endl;
    std::cout << "ID: " << s2.getId() << std::endl;
    std::cout << "Grade: " << s2.getGrade() << std::endl;

    s2.setGrade(-10.0); // Another invalid grade
    std::cout << "\nStudent 2 After another invalid grade set:" << std::endl;
    std::cout << "Name: " << s2.getName() << std::endl;
    std::cout << "ID: " << s2.getId() << std::endl;
    std::cout << "Grade: " << s2.getGrade() << std::endl;

    return 0;
}