#include <iostream>
#include <string>
#include <vector>
// No <algorithm> needed for this version.

// Represents a student with a name and an ID.
class Student {
public:
    std::string name;
    int id;

    // Constructor with less descriptive parameter names.
    // Efficiency Issue: Passes string by value and copies, instead of using std::move.
    Student(std::string n, int i) : name(n), id(i) {}

    // Method with a less standard name to display student information.
    void display_info() const {
        std::cout << "  - ID: " << id << ", Name: " << name << std::endl;
    }
};

// Represents a course that aggregates Student objects.
class Course {
private:
    std::string course_name; // Readability Issue: Inconsistent naming style (snake_case).
    std::vector<Student> student_list; // Readability Issue: Inconsistent naming style.

public:
    // Constructor with a less descriptive parameter name.
    // Efficiency Issue: Passes string by value and copies, instead of using std::move.
    Course(std::string c_name) : course_name(c_name) {}

    // Efficiency Issue: Passes Student object by value, causing an unnecessary copy.
    void addStudent(Student s) {
        student_list.push_back(s); // 's' is a copy here, then copied again into the vector.
        std::cout << "Student " << s.name << " (ID: " << s.id << ") added to " << course_name << "." << std::endl;
    }

    // Readability/Efficiency Issue: Uses an old-style indexed for loop instead of a range-based for loop.
    void displayStudents() const {
        std::cout << "\n--- Course Details for: " << course_name << " ---" << std::endl;
        if (student_list.empty()) {
            std::cout << "  No students currently enrolled." << std::endl;
        } else {
            std::cout << "Current Enrollment (" << student_list.size() << " students):" << std::endl;
            for (size_t i = 0; i < student_list.size(); ++i) { // Old-style indexed loop
                student_list[i].display_info(); // Calls less standard method name
            }
        }
        std::cout << "----------------------------------------" << std::endl;
    }
};

int main() {
    std::cout << "--- Testing Readability/Efficiency Issues ---" << std::endl;

    Course programmingCourse("Intro to C++");

    // Create student objects
    Student studentA("Eve Adams", 201);
    Student studentB("Frank Green", 202);
    Student studentC("Grace Hall", 203);

    // Add students (by value, creating copies)
    programmingCourse.addStudent(studentA);
    programmingCourse.addStudent(studentB);
    programmingCourse.addStudent(studentC);

    // Display students using inefficient loop
    programmingCourse.displayStudents();

    // Demonstrate with an empty course
    Course dataStructures("Data Structures");
    dataStructures.displayStudents();

    return 0;
}