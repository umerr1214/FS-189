#include <iostream>
#include <vector>
#include <string>

class Course {
public:
    std::string name;
    std::string code;

    Course(const std::string& name, const std::string& code) : name(name), code(code) {
        // std::cout << "Course " << code << " created." << std::endl; // For debugging memory
    }

    ~Course() {
        // std::cout << "Course " << code << " destroyed." << std::endl; // For debugging memory
    }

    void display() const {
        std::cout << "  - " << code << ": " << name << std::endl;
    }
};

class Department {
private:
    std::string deptName;
    std::vector<Course*> courses; // Aggregation using raw pointers

public:
    Department(const std::string& name) : deptName(name) {}

    // Semantic Error: Missing a destructor to delete dynamically allocated Course* objects.
    // This leads to a memory leak when Department objects are destroyed.
    // Correct destructor would be:
    // ~Department() {
    //     for (Course* course : courses) {
    //         delete course;
    //     }
    //     courses.clear();
    // }

    // Add a course by creating a new Course object on the heap
    void addCourse(const std::string& name, const std::string& code) {
        courses.push_back(new Course(name, code)); // Department owns these dynamically allocated Course objects
    }

    void listCourses() const {
        std::cout << "Department: " << deptName << std::endl;
        if (courses.empty()) {
            std::cout << "  No courses in this department." << std::endl;
            return;
        }
        for (const auto* coursePtr : courses) { // Iterate through pointers
            coursePtr->display(); // Dereference to call display
        }
    }
};

int main() {
    { // Use a scope to ensure Department objects are destroyed and memory leak is detectable
        Department csDept("Computer Science");

        csDept.addCourse("Introduction to C++", "CS101");
        csDept.addCourse("Data Structures", "CS201");
        csDept.addCourse("Algorithms", "CS301");

        csDept.listCourses();

        Department mathDept("Mathematics");
        mathDept.addCourse("Calculus I", "MA101");
        mathDept.listCourses();
    } // csDept and mathDept are destroyed here, but their Course* objects are not deleted due to missing destructor.

    std::cout << "\nProgram finished. Check for memory leaks if using a tool." << std::endl;

    return 0;
}