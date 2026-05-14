#include <iostream>
#include <string>

class Student {
    private:
        std::string m_student_name; // Using m_ prefix for members
        int m_student_id;
        double m_student_gpa;

    public:
        // Default constructor - initializes in body (less efficient/consistent than initializer list)
        Student() {
            this->m_student_name = ""; // Excessive 'this->' usage
            this->m_student_id = 0;
            this->m_student_gpa = 0.0;
        }

        // Parameterized constructor - passes string by value (inefficient copy)
        Student(std::string p_name_param, int p_id_param, double p_gpa_param) { // std::string p_name_param is passed by value
            this->m_student_name = p_name_param; // Copy from parameter, excessive 'this->'
            this->m_student_id = p_id_param;
            this->m_student_gpa = p_gpa_param;
        }

        // Public method to check scholarship eligibility - overly verbose
        bool isEligibleForScholarship() const {
            bool result_of_check; // Unnecessary temporary variable
            if (this->m_student_gpa >= 3.5) { // Excessive 'this->'
                result_of_check = true;
            } else {
                result_of_check = false;
            }
            return result_of_check;
        }

        // Helper getters for printing in driver (also using 'this->' excessively and inconsistent naming)
        std::string getStudentName() const { return this->m_student_name; }
        int getStudentIdentifier() const { return this->m_student_id; }
        double getStudentGpaValue() const { return this->m_student_gpa; }
};

  int main() { // Inconsistent indentation for main
    // Test Case 1: Eligible student
    Student firstStudent("Emily White", 2001, 3.6);
    std::cout << "Student " << firstStudent.getStudentName() << " (ID: " << firstStudent.getStudentIdentifier() << ") is eligible: " << (firstStudent.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 2: Not eligible student
    Student secondStudent("George King", 2002, 3.2);
    std::cout << "Student " << secondStudent.getStudentName() << " (ID: " << secondStudent.getStudentIdentifier() << ") is eligible: " << (secondStudent.isEligibleForScholarship() ? "true" : "false") << std::endl;

    // Test Case 3: Default constructed student
    Student thirdStudent;
    std::cout << "Student " << thirdStudent.getStudentName() << " (ID: " << thirdStudent.getStudentIdentifier() << ") is eligible: " << (thirdStudent.isEligibleForScholarship() ? "true" : "false") << std::endl;

        return 0;
  }