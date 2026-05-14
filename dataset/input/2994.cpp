#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;
public:
    static int totalStudents; // SEMANTIC ERROR: Declared but not defined

    Student(std::string n, int i) : name(n), id(i) {
        totalStudents++;
    }

    static int getTotalStudents() {
        return totalStudents;
    }
};

// Definition of static member outside the class is missing
// int Student::totalStudents = 0; // This line is required for linking

int main() {
    Student s1("Alice", 101);
    Student s2("Bob", 102);
    Student s3("Charlie", 103);

    std::cout << "Total students: " << Student::getTotalStudents() << std::endl;

    return 0;
}