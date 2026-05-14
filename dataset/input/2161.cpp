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
     * @param name The name of the course.
     * @param code The unique code for the course.
     */
    Course(std::string name, std::string code)
        : name(std::move(name)), code(std::move(code)) {}

    /**
     * @brief Displays the course information to stdout.
     */
    void display() const {
        std::cout << "  - " << code << ": " << name << '\n';
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
     * @param name The name of the department.
     */
    Department(std::string name) : departmentName(std::move(name)) {}

    /**
     * @brief Adds a course to the department.
     * @param course The Course object to add. Passed by const reference to avoid copying.
     */
    void addCourse(const Course& course) {
        courses.push_back(course); // Course is copied into the vector
    }

    /**
     * @brief Lists all courses currently in the department.
     *        Contains a robustness issue that can cause a crash.
     */
    void listCourses() const {
        std::cout << "Courses in " << departmentName << ":\n";

        // ROBUSTNESS ISSUE: Accessing courses[0] without checking if the vector is empty.
        // This will lead to a crash (e.g., segmentation fault or std::out_of_range)
        // if the department has no courses when this method is called.
        std::cout << "  (First course in list: " << courses[0].name << ")\n";

        if (courses.empty()) {
            std::cout << "  No courses available.\n";
            return;
        }

        for (const Course& c : courses) {
            c.display();
        }
        std::cout << '\n';
    }
};

int main() {
    // Test Case 1: Empty department - This will trigger the robustness issue (crash)
    Department cs_dept("Computer Science");
    std::cout << "--- Test Case 1: Empty Department ---\n";
    cs_dept.listCourses(); // EXPECTED CRASH HERE

    // These test cases will not be reached if the program crashes above.
    // If the crash is handled or doesn't occur due to compiler specific behavior,
    // these would execute normally.
    Department math_dept("Mathematics");
    math_dept.addCourse(Course("Calculus I", "MATH101"));
    math_dept.addCourse(Course("Linear Algebra", "MATH201"));
    std::cout << "--- Test Case 2: Department with Courses ---\n";
    math_dept.listCourses();

    cs_dept.addCourse(Course("Introduction to Programming", "CS101"));
    cs_dept.addCourse(Course("Data Structures", "CS201"));
    std::cout << "--- Test Case 3: Computer Science Department (after adding courses) ---\n";
    cs_dept.listCourses();

    return 0;
}