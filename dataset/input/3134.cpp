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
        }
    }

    std::string getName() const { return name; }
    int getGrade() const { return grade; }
    void setName(std::string n) { name = n; }

    // Readability / Efficiency Issue: Uses an unnecessary temporary variable 'oldGrade'
    // and a slightly verbose structure when a simpler direct assignment would suffice.
    void setGrade(int newGrade) {
        int oldGrade = this->grade; // Unnecessary variable; the grade is only assigned if valid.
                                    // If invalid, 'this->grade' is simply not changed,
                                    // making 'oldGrade' redundant.
        if (newGrade < 0 || newGrade > 100) {
            std::cerr << "Error: Invalid grade " << newGrade << ". Grade must be between 0 and 100." << std::endl;
            // No assignment to this->grade here, so 'oldGrade' is implicitly kept (because it was never changed).
            // This is functionally correct but less direct and efficient.
        } else {
            this->grade = newGrade; // Assignment only happens if valid.
        }
    }

    void printInfo() const {
        std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
    }
};

int main() {
    Student s1("Bob", 75);
    s1.printInfo();

    std::cout << "\nTest Case 1: Set valid grade (80)" << std::endl;
    s1.setGrade(80);
    s1.printInfo();

    std::cout << "\nTest Case 2: Set invalid grade (-5)" << std::endl;
    s1.setGrade(-5); // Expected: Error, Grade remains 80
    s1.printInfo();

    std::cout << "\nTest Case 3: Set invalid grade (105)" << std::endl;
    s1.setGrade(105); // Expected: Error, Grade remains 80
    s1.printInfo();

    std::cout << "\nTest Case 4: Set valid grade (0)" << std::endl;
    s1.setGrade(0);
    s1.printInfo();

    std::cout << "\nTest Case 5: Set valid grade (100)" << std::endl;
    s1.setGrade(100);
    s1.printInfo();

    return 0;
}