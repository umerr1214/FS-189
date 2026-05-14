#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int grade;

public:
    // Constructor initializes name and validates initial grade
    Student(std::string n, int g = 0) : name(n) {
        if (g >= 0 && g <= 100) {
            grade = g;
        } else {
            grade = 0; // Default to a valid grade if initial is invalid
            std::cerr << "Warning: Initial grade " << g << " for " << name << " is invalid. Setting to 0." << std::endl;
        }
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Getter for grade
    int getGrade() const {
        return grade;
    }

    // Setter for name
    void setName(std::string n) {
        name = n;
    }

    // Setter for grade with validation
    void setGrade(int newGrade) {
        if (newGrade >= 0 && newGrade <= 100) {
            this->grade = newGrade;
        } else {
            // Correct behavior: print error and keep the current grade value
            std::cerr << "Error: Invalid grade " << newGrade << ". Grade must be between 0 and 100. Keeping old value (" << this->grade << ")." << std::endl;
        }
    }

    // Method to print student information
    void printInfo() const {
        std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
    }
};

int main() {
    Student s1("Charlie", 88);
    s1.printInfo();

    std::cout << "\nTest Case 1: Set valid grade (95)" << std::endl;
    s1.setGrade(95);
    s1.printInfo();

    std::cout << "\nTest Case 2: Set invalid grade (-1)" << std::endl;
    s1.setGrade(-1); // Expected: Error, Grade remains 95
    s1.printInfo();

    std::cout << "\nTest Case 3: Set invalid grade (101)" << std::endl;
    s1.setGrade(101); // Expected: Error, Grade remains 95
    s1.printInfo();

    std::cout << "\nTest Case 4: Set valid grade (0) - lower bound" << std::endl;
    s1.setGrade(0);
    s1.printInfo();

    std::cout << "\nTest Case 5: Set valid grade (100) - upper bound" << std::endl;
    s1.setGrade(100);
    s1.printInfo();

    std::cout << "\nTest Case 6: Initial student with invalid grade in constructor" << std::endl;
    Student s2("David", 120); // Initial grade is invalid
    s2.printInfo();

    std::cout << "\nTest Case 7: Initial student with valid grade in constructor" << std::endl;
    Student s3("Eve", 50);
    s3.printInfo();

    return 0;
}