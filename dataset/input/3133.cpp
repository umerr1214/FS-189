#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int grade; // Not explicitly initialized in constructor with validation

public:
    // Constructor initializes name and grade directly without validation
    Student(std::string n, int g) : name(n), grade(g) {}

    std::string getName() const { return name; }
    int getGrade() const { return grade; }
    void setName(std::string n) { name = n; }

    // Robustness Issue: Prints an error but still changes the grade to the invalid value,
    // violating the "keep the old value" requirement.
    void setGrade(int newGrade) {
        if (newGrade < 0 || newGrade > 100) {
            std::cerr << "Error: Invalid grade " << newGrade << ". Grade must be between 0 and 100." << std::endl;
            // FLAW: The grade is still updated to the invalid value here.
            this->grade = newGrade;
        } else {
            this->grade = newGrade;
        }
    }

    void printInfo() const {
        std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
    }
};

int main() {
    Student s1("Alice", 85);
    s1.printInfo(); // Initial state

    std::cout << "\nTest Case 1: Set valid grade (90)" << std::endl;
    s1.setGrade(90);
    s1.printInfo();

    std::cout << "\nTest Case 2: Set invalid grade (-10)" << std::endl;
    s1.setGrade(-10); // Expect error and grade to remain 90, but it will change to -10
    s1.printInfo();

    std::cout << "\nTest Case 3: Set invalid grade (110)" << std::endl;
    s1.setGrade(110); // Expect error and grade to remain -10, but it will change to 110
    s1.printInfo();

    std::cout << "\nTest Case 4: Set valid grade (0)" << std::endl;
    s1.setGrade(0);
    s1.printInfo();

    std::cout << "\nTest Case 5: Set valid grade (100)" << std::endl;
    s1.setGrade(100);
    s1.printInfo();

    // Demonstrate constructor's lack of validation
    std::cout << "\nTest Case 6: Initial student with invalid grade in constructor" << std::endl;
    Student s2("Bob", -50);
    s2.printInfo(); // Grade is initialized to -50 without warning/correction

    return 0;
}