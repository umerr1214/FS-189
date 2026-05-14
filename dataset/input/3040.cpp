#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
public:
    Person(const std::string& name) : name(name) {
        std::cout << "Person constructor: " << this->name << std::endl;
    }
    std::string getName() const { return name; }
} // SYNTAX ERROR: Missing semicolon here

class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    Employee(const std::string& name, int employeeId, double salary)
        : Person(name), employeeId(employeeId), salary(salary) {
        std::cout << "Employee constructor: " << this->employeeId << ", " << this->salary << std::endl;
    }
    int getEmployeeId() const { return employeeId; }
    double getSalary() const { return salary; }
};

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(const std::string& name, int employeeId, double salary, const std::string& department)
        : Employee(name, employeeId, salary), department(department) {
        std::cout << "Manager constructor: " << this->department << std::endl;
    }
    std::string getDepartment() const { return department; }
};

int main() {
    Manager manager("Alice Smith", 101, 75000.0, "Sales");
    std::cout << "\nManager Details:" << std::endl;
    std::cout << "Name: " << manager.getName() << std::endl;
    std::cout << "Employee ID: " << manager.getEmployeeId() << std::endl;
    std::cout << "Salary: " << manager.getSalary() << std::endl;
    std::cout << "Department: " << manager.getDepartment() << std::endl;
    return 0;
}