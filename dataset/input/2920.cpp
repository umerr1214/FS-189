#include <iostream>
#include <string>

// Syntax Error: Missing semicolon after class definition
class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}
} // This line is missing a semicolon

class Student : public Person {
private:
    std::string studentId;

public:
    Student(std::string n, int a, std::string id)
        : Person(n, a), studentId(id) {}

    void displayDetails() {
        std::cout << "Student Name: " << name << std::endl;
        std::cout << "Student Age: " << age << std::endl;
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s("Alice Smith", 20, "S12345");
    s.displayDetails();
    return 0;
}