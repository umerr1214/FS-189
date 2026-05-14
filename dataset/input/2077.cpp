#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int studentId;
    double gpa;

public:
    // Default constructor
    Student() : name(""), studentId(0), gpa(0.0) {}

    // Parameterized constructor - LACKS GPA VALIDATION
    Student(std::string n, int id, double g) : name(n), studentId(id), gpa(g) {
        // No validation for gpa. This allows values like negative or excessively high
        // to be stored, which is a robustness issue as it permits an invalid object state.
    }

    // Public method to check scholarship eligibility
    bool isEligibleForScholarship() const {
        return gpa >= 3.5;
    }

    // Helper getters for printing in driver
    std::string getName() const { return name; }
    int getStudentId() const { return studentId; }
    double getGpa() const { return gpa; }
};

int main() {
    // Test Case 1: Valid student, eligible
    Student s1("Alice Smith", 1001, 3.8);
    std::cout << "Student " << s1.getName() << " (ID: " << s1.getStudentId() << ") is eligible: " << (s1.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 2: Student with a negative GPA (robustness issue: no validation)
    // While the method correctly returns false based on the formula, the stored GPA is nonsensical.
    Student s2("Bob Johnson", 1002, -1.0);
    std::cout << "Student " << s2.getName() << " (ID: " << s2.getStudentId() << ") is eligible: " << (s2.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 3: Student with an excessively high GPA (robustness issue: no validation)
    // Similarly, the method works, but the internal state is unrealistic.
    Student s3("Charlie Brown", 1003, 5.5);
    std::cout << "Student " << s3.getName() << " (ID: " << s3.getStudentId() << ") is eligible: " << (s3.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 4: Student not eligible with valid GPA
    Student s4("Diana Prince", 1004, 3.4);
    std::cout << "Student " << s4.getName() << " (ID: " << s4.getStudentId() << ") is eligible: " << (s4.isEligibleForScholarship() ? "true" : "false") << std::endl;

    return 0;
}