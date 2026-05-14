#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Person {
protected:
    std::string name;
public:
    // Correct: Pass string by const reference to avoid unnecessary copies.
    Person(const std::string& n) : name(n) {
        std::cout << "Person constructor called for: " << name << std::endl;
    }
    // Correct: Member function is const as it does not modify the object's state.
    void displayPerson() const {
        std::cout << "Name: " << name;
    }
};

class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // Correct: All members initialized in the initializer list.
    // Base class constructor is called with const reference.
    Employee(const std::string& n, int id, double s)
        : Person(n), employeeId(id), salary(s) {
        std::cout << "Employee constructor called for ID: " << employeeId << ", Salary: " << std::fixed << std::setprecision(2) << salary << std::endl;
    }
    // Correct: Member function is const.
    // Uses std::fixed and std::setprecision for clear salary display.
    void displayEmployee() const {
        displayPerson();
        std::cout << ", Employee ID: " << employeeId << ", Salary: " << std::fixed << std::setprecision(2) << salary;
    }
};

class Manager : public Employee {
protected:
    std::string department;
public:
    // Correct: All members initialized in the initializer list.
    // Base class constructor and current class members use const references where appropriate.
    Manager(const std::string& n, int id, double s, const std::string& dept)
        : Employee(n, id, s), department(dept) {
        std::cout << "Manager constructor called for Department: " << department << std::endl;
    }
    // Correct: Member function is const.
    void displayManager() const {
        displayEmployee();
        std::cout << ", Department: " << department << std::endl;
    }
};

int main() {
    std::cout << "Creating a Manager object..." << std::endl;
    Manager mgr("Charlie Brown", 103, 92500.25, "HR");
    std::cout << "\nManager Details:" << std::endl;
    mgr.displayManager();
    return 0;
}