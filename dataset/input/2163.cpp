#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

/**
 * @brief Represents a single academic course.
 */
class Course {
public:
    std::string name;
    std::string code;

    /**
     * @brief Constructs a new Course object.
     * @param name The name of the course. Passed by value and moved for efficient construction.
     * @param code The unique code for the course. Passed by value and moved for efficient construction.
     */
    Course(std::string name, std::string code)
        : name(std::move(name)), code(std::move(code)) {} // Use std::move for efficient string transfer

    /**
     * @brief Displays the course information to stdout.
     */
    void display() const {
        std::cout << "  - " << code << ": " << name << '\n'; // Use '\n' for efficient output (no unnecessary flush)
    }
};

/**
 * @brief Represents an academic department that manages a collection of courses.
 */
class Department {
private:
    std::string departmentName;
    std::vector<Course> courses; // Aggregation: Department manages Course objects

public:
    /**
     * @brief Constructs a new Department object.
     * @param name The name of the department. Passed by value and moved for efficient construction.
     */
    Department(std::string name) : departmentName(std::move(name)) {} // Use std::move

    /**
     * @brief Adds a course to the department.
     * @param course The Course object to add. Passed by const reference to avoid unnecessary copying.
     */
    void addCourse(const Course& course) {
        courses.push_back(course); // Course is copied into the vector from the const reference
    }

    /**
     * @brief Lists all courses currently in the department.
     *        Handles the case where no courses are present gracefully.
     */
    void listCourses() const {
        std::cout << "Courses in " << departmentName << ":\n"; // Use '\n'

        if (courses.empty()) {
            std::cout << "  No courses available.\n"; // Use '\n'
            return;
        }

        // Use range-based for loop for modern, readable, and concise iteration
        for (const Course& c : courses) {
            c.display();
        }
        std::cout << '\n'; // Add an extra newline for better output separation
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