#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int studentId;
    double gpa;

public:
    // Default constructor using member initializer list for proper initialization
    Student() : name(""), studentId(0), gpa(0.0) {}

    // Parameterized constructor using member initializer list and passing string by const reference for efficiency
    Student(const std::string& n, int id, double g)
        : name(n), studentId(id), gpa(g) {}

    // Public method to check scholarship eligibility - concise and direct implementation
    bool isEligibleForScholarship() const {
        return gpa >= 3.5;
    }

    // Helper getters for printing in driver
    std::string getName() const { return name; }
    int getStudentId() const { return studentId; }
    double getGpa() const { return gpa; }
};

int main() {
    // Test Case 1: Eligible student
    Student s1("Frank Green", 3001, 3.9);
    std::cout << "Student " << s1.getName() << " (ID: " << s1.getStudentId() << ") is eligible: " << (s1.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 2: Not eligible student
    Student s2("Hannah Black", 3002, 3.4);
    std::cout << "Student " << s2.getName() << " (ID: " << s2.getStudentId() << ") is eligible: " << (s2.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 3: Exactly eligible student
    Student s3("Ivan Blue", 3003, 3.5);
    std::cout << "Student " << s3.getName() << " (ID: " << s3.getStudentId() << ") is eligible: " << (s3.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 4: Default constructed student (not eligible)
    Student s4;
    std::cout << "Student " << s4.getName() << " (ID: " << s4.getStudentId() << ") is eligible: " << (s4.isEligibleForScholarship() ? "true" : "false") << std::endl;

    return 0;
}