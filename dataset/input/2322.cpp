#include <iostream>
#include <string>

class Person {
private: // SEMANTIC ERROR: Members are private
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    // Public getters provided for correct access
    std::string getName() const { return name; }
    int getAge() const { return age; }

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
        // SEMANTIC ERROR: Attempting to directly access private members 'name' and 'age'
        // inherited from the 'Person' base class. This violates encapsulation rules
        // and will result in a compilation error.
        std::cout << "Name: " << name << ", Age: " << age << std::endl; // Error here
        std::cout << "Subject: " << subject << ", Salary: " << salary << std::endl;
    }
};

int main() {
    // This code will not compile due to the semantic error in displayTeacher
    // Teacher teacher1("Alice Smith", 35, "Mathematics", 60000.0);
    // teacher1.displayTeacher();
    return 0;
}