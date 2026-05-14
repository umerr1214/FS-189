#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    std::string name;
    double salary;

    Employee(std::string n, double s) : name(n), salary(s) {}
}; // ERROR: Missing semicolon here

class Manager : public Employee {
public:
    std::string department;

    Manager(std::string n, double s, std::string d) : Employee(n, s), department(d) {}
};

class Engineer : public Employee {
public:
    std::string specialization;

    Engineer(std::string n, double s, std::string spec) : Employee(n, s), specialization(spec) {}
};

int main() {
    // This program is expected to fail compilation due to a syntax error.
    // No runtime execution will occur.
    return 0;
}