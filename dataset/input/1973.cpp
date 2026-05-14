#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int studentID;
    double gpa;
    static int totalStudents;

    Student(std::string n, int id, double g) : name(n), studentID(id), gpa(g) {
        // LOGICAL ERROR: totalStudents is not incremented here
    }

    void display() const {
        std::cout << "Name: " << name << ", ID: " << studentID << ", GPA: " << gpa << std::endl;
    }
};

// Initialize static member
int Student::totalStudents = 0;

int main() {
    Student s1("Alice", 101, 3.8);
    Student s2("Bob", 102, 3.5);
    Student s3("Charlie", 103, 3.9);


    std::cout << "Total students created: " << Student::totalStudents << std::endl;

    s1.display();
    s2.display();
    s3.display();

    return 0;
}