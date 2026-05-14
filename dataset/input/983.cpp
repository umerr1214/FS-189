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
        // LOGICAL ERROR: Should be newGpa <= 4.0, but it's newGpa < 4.0, making 4.0 exclusive.
        if (newGpa >= 0.0 && newGpa < 4.0) { 
            gpa = newGpa;
            return true;
        }
        return false;
    }
};

int main() {
    Student s("Bob", 102, 3.9);
    std::cout << "Student: " << s.getName() << ", ID: " << s.getId() << ", GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    s.setGpa(3.0);
    std::cout << "Updated GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    // This should succeed, but will fail due to the logical error (4.0 is not set)
    bool success4_0 = s.setGpa(4.0);
    std::cout << "Attempted GPA 4.0. Success: " << (success4_0 ? "true" : "false") << ". Current GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;
    
    // This should fail
    bool success4_1 = s.setGpa(4.1);
    std::cout << "Attempted GPA 4.1. Success: " << (success4_1 ? "true" : "false") << ". Current GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    // This should fail
    bool success_neg = s.setGpa(-0.1);
    std::cout << "Attempted GPA -0.1. Success: " << (success_neg ? "true" : "false") << ". Current GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    return 0;
}