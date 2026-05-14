#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

class Student {
private:
    std::string name;
    int id;
    double grade;

public:
    // Default constructor: Readability/Efficiency issue - assigns in body
    Student() {
        // Inefficient: 'name' is default-constructed, then assigned.
        // Also, unnecessary use of 'this->'.
        this->name = "";
        this->id = 0;
        this->grade = 0.0;
    }

    // Parameterized constructor: Readability/Efficiency issue - passes string by value, assigns in body
    Student(std::string name_param, int id_param, double grade_param) { // 'name_param' is passed by value, incurring an unnecessary copy
        // Inefficient: 'name' is default-constructed, then assigned from 'name_param' (another copy/move).
        // Also, unnecessary use of 'this->'.
        this->name = name_param;
        this->id = id_param;
        this->grade = grade_param;
    }

    // Friend function to allow easy printing of Student objects
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "Name: " << s.name << ", ID: " << s.id << ", Grade: " << std::fixed << std::setprecision(1) << s.grade;
        return os;
    }
};

int main() {
    std::vector<Student> students;

    // Test default constructor
    students.push_back(Student());

    // Test parameterized constructor with valid data
    students.push_back(Student("Alice Johnson", 101, 95.5));
    students.push_back(Student("Bob Smith", 102, 88.0));

    // Additional students
    students.push_back(Student("Charlie Brown", 103, 75.0));
    students.push_back(Student("Diana Prince", 104, 82.3));

    std::cout << "--- Student List ---" << std::endl;
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Student " << i + 1 << ": " << students[i] << std::endl;
    }

    return 0;
}