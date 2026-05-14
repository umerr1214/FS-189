#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Student {
private:
    std::string name;
    int studentId;
    double gpa;

public:
    // Default constructor
    Student() : name("Unknown"), studentId(0), gpa(0.0) {}

    // Parameterized constructor
    Student(std::string n, int id, double g) : name(n), studentId(id), gpa(g) {}

    // Public method to check scholarship eligibility - Logical Error
    bool isEligibleForScholarship() {
        return gpa >= 3.0; // Incorrect condition: should be gpa >= 3.5
    }

    // Getters for testing purposes
    std::string getName() const { return name; }
    int getId() const { return studentId; }
    double getGpa() const { return gpa; }
};

int main() {
    std::cout << "--- Test Cases ---" << std::endl;

    // Test case 1: Default constructor
    Student s1;
    std::cout << "Student 1 (Default): Name=" << s1.getName() << ", ID=" << s1.getId() << ", GPA=" << std::fixed << std::setprecision(1) << s1.getGpa() << ", Eligible=" << (s1.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test case 2: Parameterized constructor (eligible, correct under question)
    Student s2("Alice", 101, 3.8);
    std::cout << "Student 2 (Alice): Name=" << s2.getName() << ", ID=" << s2.getId() << ", GPA=" << std::fixed << std::setprecision(1) << s2.getGpa() << ", Eligible=" << (s2.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test case 3: Parameterized constructor (not eligible under question, but eligible due to error)
    Student s3("Bob", 102, 3.4);
    std::cout << "Student 3 (Bob): Name=" << s3.getName() << ", ID=" << s3.getId() << ", GPA=" << std::fixed << std::setprecision(1) << s3.getGpa() << ", Eligible=" << (s3.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test case 4: Parameterized constructor (borderline eligible, correct under question)
    Student s4("Charlie", 103, 3.5);
    std::cout << "Student 4 (Charlie): Name=" << s4.getName() << ", ID=" << s4.getId() << ", GPA=" << std::fixed << std::setprecision(1) << s4.getGpa() << ", Eligible=" << (s4.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test case 5: Parameterized constructor (not eligible under question, but eligible due to error)
    Student s5("Diana", 104, 3.49);
    std::cout << "Student 5 (Diana): Name=" << s5.getName() << ", ID=" << s5.getId() << ", GPA=" << std::fixed << std::setprecision(2) << s5.getGpa() << ", Eligible=" << (s5.isEligibleForScholarship() ? "true" : "false") << std::endl;

    return 0;
}