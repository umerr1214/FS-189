#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {}

    void displayPersonInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl // MISSING SEMICOLON HERE
    }
};

class Employee : public Person {
public:
    std::string employeeId;
    double salary;

    Employee(const std::string& n, int a, const std::string& id, double s)
        : Person(n, a), employeeId(id), salary(s) {}

    void displayEmployeeInfo() const {
        displayPersonInfo();
        std::cout << "Employee ID: " << employeeId << ", Salary: $" << salary << std::endl;
    }
};

class Manager : public Employee {
public:
    std::string department;
    int teamSize;

    Manager(const std::string& n, int a, const std::string& id, double s, const std::string& dept, int ts)
        : Employee(n, a, id, s), department(dept), teamSize(ts) {}

    void displayManagerInfo() const {
        displayEmployeeInfo();
        std::cout << "Department: " << department << ", Team Size: " << teamSize << std::endl;
    }
};

int main() {
    Person p("Alice", 30);
    std::cout << "--- Person Info ---" << std::endl;
    p.displayPersonInfo();

    Employee e("Bob", 35, "E101", 75000.0);
    std::cout << "\n--- Employee Info ---" << std::endl;
    e.displayEmployeeInfo();

    Manager m("Charlie", 40, "M201", 120000.0, "HR", 15);
    std::cout << "\n--- Manager Info ---" << std::endl;
    m.displayManagerInfo();

    return 0;
}