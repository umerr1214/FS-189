#include <iostream>
#include <vector>
#include <string>

// No comments for readability
class Course {
public:
    std::string n; // Poor variable name: 'n' for name
    std::string cd; // Poor variable name: 'cd' for code

    // Parameters passed by value, then copied to members. Less efficient.
    Course(std::string name_param, std::string code_param) : n(name_param), cd(code_param) {}

    void display() const {
        std::cout << "  - " << cd << ": " << n << std::endl; // Inefficient: uses std::endl, which flushes
    }
};

class Department {
private:
    std::string d_n; // Poor variable name: 'd_n' for departmentName
    std::vector<Course> cs; // Poor variable name: 'cs' for courses

public:
    // Parameter passed by value, then copied. Less efficient.
    Department(std::string department_name_param) : d_n(department_name_param) {}

    // Efficiency Issue: Course object passed by value, causing an unnecessary copy.
    // Another copy happens when pushed into the vector.
    void addCourse(Course course) {
        cs.push_back(course);
    }

    void listCourses() const {
        std::cout << "Courses in " << d_n << ":" << std::endl; // Inefficient: uses std::endl

        if (cs.empty()) {
            std::cout << "  No courses available." << std::endl; // Inefficient: uses std::endl
            return;
        }

        // Readability Issue: Uses old-style indexed loop instead of more modern and readable range-based for loop.
        for (size_t i = 0; i < cs.size(); ++i) {
            cs[i].display();
        }
        std::cout << std::endl; // Adds an extra newline, also inefficient std::endl
    }
};

int main() {
    // Test Case 1: Empty department
    Department cs_dept("Computer Science");
    std::cout << "--- Test Case 1: Empty Department ---\n";
    cs_dept.listCourses();

    // Test Case 2: Department with courses
    Department math_dept("Mathematics");
    math_dept.addCourse(Course("Calculus I", "MATH101"));
    math_dept.addCourse(Course("Linear Algebra", "MATH201"));
    std::cout << "--- Test Case 2: Department with Courses ---\n";
    math_dept.listCourses();

    // Test Case 3: Adding more courses
    cs_dept.addCourse(Course("Introduction to Programming", "CS101"));
    cs_dept.addCourse(Course("Data Structures", "CS201"));
    std::cout << "--- Test Case 3: Computer Science Department ---\n";
    cs_dept.listCourses();

    return 0;
}