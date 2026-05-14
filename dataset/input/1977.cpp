#include <iostream>
#include <string>
#include <vector> // Included for demonstrating object lifecycle with containers

class Student {
private:
    std::string name;
    int studentID;
    double gpa;
    static int totalStudents; // Static member to track total student objects

public:
    // Constructor using initializer list for efficient member initialization
    // Uses const references for string parameters to avoid unnecessary copies
    Student(const std::string& name, int studentID, double gpa)
        : name(name), studentID(studentID), gpa(gpa) {
        totalStudents++; // Increment count when a new Student object is created
    }

    // Destructor to correctly decrement the totalStudents count when an object is destroyed
    ~Student() {
        totalStudents--;
    }

    // Public getters for read-only access to private members (const-correct)
    std::string getName() const { return name; }
    int getStudentID() const { return studentID; }
    double getGPA() const { return gpa; }

    // Static method to get the total number of students
    static int getTotalStudents() {
        return totalStudents;
    }

    // Method to display student information (const-correct)
    void displayStudent() const {
        std::cout << "Name: " << name << ", ID: " << studentID << ", GPA: " << gpa << std::endl;
    }
};

// Initialize static member outside the class definition
int Student::totalStudents = 0;

int main() {
    std::cout << "Initial total students: " << Student::getTotalStudents() << std::endl;

    Student s1("Alice", 101, 3.8);
    s1.displayStudent();
    std::cout << "After s1 created, total students: " << Student::getTotalStudents() << std::endl;

    { // Create a scope to demonstrate destructor calls
        Student s2("Bob", 102, 3.5);
        s2.displayStudent();
        Student s3("Charlie", 103, 3.9);
        s3.displayStudent();
        std::cout << "Inside block, after s2, s3 created, total students: " << Student::getTotalStudents() << std::endl;
    } // s2 and s3 go out of scope here, their destructors are called, decrementing totalStudents

    std::cout << "After block, total students: " << Student::getTotalStudents() << std::endl;

    Student s4("David", 104, 3.2);
    s4.displayStudent();
    std::cout << "After s4 created, total students: " << Student::getTotalStudents() << std::endl;

    // Demonstrate with a vector of students
    std::vector<Student> students_vec;
    students_vec.emplace_back("Eve", 105, 3.7); // Uses constructor directly
    students_vec.emplace_back("Frank", 106, 3.1);
    std::cout << "After adding 2 students to vector, total students: " << Student::getTotalStudents() << std::endl;

    // When students_vec goes out of scope at the end of main, destructors for Eve and Frank will be called.
    return 0;
}