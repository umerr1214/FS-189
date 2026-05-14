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

    // Getters - SEMANTIC ERROR: Missing 'const' and returning non-const reference for name/id
    std::string& getName() { // Should be 'const std::string& getName() const'
        return name;
    }

    int& getId() { // Should be 'int getId() const' or 'const int& getId() const'
        return id;
    }

    double getGpa() { // Should be 'double getGpa() const'
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
};

int main() {
    Student s("Charlie", 103, 3.2);
    std::cout << "Initial Student: " << s.getName() << ", ID: " << s.getId() << ", GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    // Demonstrate semantic error: Modifying private data directly through non-const reference getter
    s.getName() = "Charles"; // This breaks encapsulation
    s.getId() = 200;       // This breaks encapsulation

    std::cout << "Modified via getter: " << s.getName() << ", ID: " << s.getId() << ", GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    s.setGpa(3.7);
    std::cout << "Updated GPA: " << std::fixed << std::setprecision(1) << s.getGpa() << std::endl;

    return 0;
}