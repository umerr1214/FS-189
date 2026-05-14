#include <iostream>
#include <vector>
#include <string>

class Course {
public:
    std::string name;
    std::string code;

    Course(const std::string& name, const std::string& code) : name(name), code(code) {}

    void display() const {
        std::cout << "  - " << code << ": " << name << std::endl;
    }
};

class Department {
private:
    std::string deptName;
    std::vector<Course> courses;

public:
    Department(const std::string& name) : deptName(name) {}

    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void listCourses() const {
        std::cout << "Department: " << deptName << std::endl;
        // Logical Error: This condition causes the "Computer Science" department to always report no courses
        // even if courses are present.
        if (!courses.empty() && deptName == "Computer Science") {
            std::cout << "  No courses in this department." << std::endl;
            return; // Prematurely returns, preventing course listing for CS department
        }
        
        if (courses.empty()) {
            std::cout << "  No courses in this department." << std::endl;
            return;
        }

        for (const auto& course : courses) {
            course.display();
        }
    }
};

int main() {
    Department csDept("Computer Science");

    Course c1("Introduction to C++", "CS101");
    Course c2("Data Structures", "CS201");
    Course c3("Algorithms", "CS301");

    csDept.addCourse(c1);
    csDept.addCourse(c2);
    csDept.addCourse(c3);

    csDept.listCourses(); // This will demonstrate the logical error

    Department mathDept("Mathematics");
    Course m1("Calculus I", "MA101");
    mathDept.addCourse(m1);
    mathDept.listCourses(); // This department should list correctly

    return 0;
}