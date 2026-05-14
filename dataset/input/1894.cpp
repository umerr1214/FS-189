#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Student {
public:
    std::string name;
    int id;

    Student(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "  Student ID: " << id << ", Name: " << name << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Course {
private:
    std::string courseName;
    std::vector<Student> students;

public:
    Course(std::string name) : courseName(std::move(name)) {}

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayStudents() const {
        std::cout << "Course: " << courseName << std::endl;
        if (students.empty()) {
            std::cout << "  No students enrolled." << std::endl;
            return;
        }
        for (const auto& s : students) {
            s.display();
        }
    }
};

int main() {
    Course cppCourse("C++ Programming");

    cppCourse.addStudent(Student("Alice Smith", 101));
    cppCourse.addStudent(Student("Bob Johnson", 102));
    cppCourse.addStudent(Student("Charlie Brown", 103));

    cppCourse.displayStudents();

    return 0;
}