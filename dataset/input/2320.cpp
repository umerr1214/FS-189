#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Teacher : public Person {
public:
    std::string subject;
    double salary;

    Teacher(std::string n, int a, std::string sub, double sal)
        : Person(n, a), subject(sub), salary(sal) {}

    void displayTeacher() const {
        displayPerson(); // Call base class method to display person info
        std::cout << "Subject: " << subject << ", Salary: " << salary << std::endl;
    }
};

int main() {
    // This code will not compile due to the syntax error
    // Teacher teacher1("Alice Smith", 35, "Mathematics", 60000.0);
    // teacher1.displayTeacher();
    return 0;
}