#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Student {
public:
    std::string name;
    int id;

    Student(std::string name, int id) : name(std::move(name)), id(id) {}

    // Destructor to show when Student objects are destroyed
    ~Student() {
        // std::cout << "DEBUG: Student " << name << " (ID: " << id << ") destroyed." << std::endl;
    }

    void display() const {
        std::cout << "  Student ID: " << id << ", Name: " << name << std::endl;
    }
};

class Course {
private:
    std::string courseName;
    std::vector<Student*> students; // Stores raw pointers to Student objects

public:
    Course(std::string name) : courseName(std::move(name)) {}

    // SEMANTIC ERROR: Missing a destructor to deallocate Student objects
    // This leads to a memory leak as Student objects allocated with 'new' are never deleted.
    /*
    ~Course() {
        for (Student* s : students) {
            delete s; // Correct cleanup would be here
        }
        students.clear();
    }
    */

    void addStudent(Student* student) { // Takes ownership of the dynamically allocated student
        if (student) {
            students.push_back(student);
        }
    }

    void displayStudents() const {
        std::cout << "Course: " << courseName << std::endl;
        if (students.empty()) {
            std::cout << "  No students enrolled." << std::endl;
            return;
        }
        for (const auto& s : students) {
            if (s) { // Guard against nullptr, though not strictly necessary in this example
                s->display();
            }
        }
    }
};

int main() {
    Course cppCourse("C++ Programming");

    // Dynamically allocate Student objects.
    // The Course class is intended to take ownership of these pointers.
    cppCourse.addStudent(new Student("Alice Smith", 101));
    cppCourse.addStudent(new Student("Bob Johnson", 102));
    cppCourse.addStudent(new Student("Charlie Brown", 103));

    cppCourse.displayStudents();

    // No 'delete' calls here, and no destructor in Course to handle them,
    // resulting in a memory leak.

    return 0;
}