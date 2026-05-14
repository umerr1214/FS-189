#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Student {
private:
    std::string name;
    int id;
    double gpa;

public:
    // Constructor
    Student(std::string name, int id, double gpa) : name(name), id(id) {
        setGpa(gpa); // Use setter for validation
    }

    // Getters
    std::string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    double getGpa() const {
        return gpa;
    }

    // Setters
    void setName(std::string newName) {
        name = newName;
    }

    void setId(int newId) {
        id = newId;
    }

    bool setGpa(double newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            gpa = newGpa;
            return true;
        }
        return false;
    }
}; // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Student s("Alice", 101, 3.5);
    std::cout << "Student: " << s.getName() << ", ID: " << s.getId() << ", GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    s.setGpa(3.8);
    std::cout << "Updated GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    s.setGpa(4.5); // Should fail
    std::cout << "Attempted GPA 4.5. Current GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    s.setGpa(-0.5); // Should fail
    std::cout << "Attempted GPA -0.5. Current GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    return 0;
}