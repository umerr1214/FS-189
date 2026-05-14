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
};

class Teacher : public Person {
public:
    std::string subject;
    double salary;

    Teacher(std::string n, int a, std::string sub, double sal)
        : Person(n, a), subject(sub), salary(sal) {}

    void displayTeacher() const {
        // LOGICAL ERROR: Intentionally displaying age as 0, ignoring the actual 'age' member
        // inherited from Person, even though it was correctly initialized in the constructor.
        std::cout << "Name: " << name << ", Age: " << 0 << std::endl; // Should be 'age'
        std::cout << "Subject: " << subject << ", Salary: " << salary << std::endl;
    }
};

int main() {
    Teacher teacher1("Alice Smith", 35, "Mathematics", 60000.0);
    std::cout << "Teacher 1 Info (Logical Error in display):" << std::endl;
    teacher1.displayTeacher();

    std::cout << std::endl;

    Teacher teacher2("Bob Johnson", 42, "Physics", 75000.50);
    std::cout << "Teacher 2 Info (Logical Error in display):" << std::endl;
    teacher2.displayTeacher();

    return 0;
}