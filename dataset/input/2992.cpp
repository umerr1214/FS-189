#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;
public:
    static int totalStudents;

    Student(std::string n, int i) : name(n), id(i) {
        totalStudents++;
    }

    static int getTotalStudents() {
        return totalStudents;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

// Definition of static member outside the class
int Student::totalStudents = 0;

int main() {
    Student s1("Alice", 101);
    Student s2("Bob", 102);
    Student s3("Charlie", 103);

    std::cout << "Total students: " << Student::getTotalStudents() << std::endl;

    return 0;
}