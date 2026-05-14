#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
// SEMANTIC ERROR: Person constructor is private, preventing Employee from accessing it.
private: // Changed from public/protected to private
    Person(const std::string& name) : name(name) {
        std::cout << "Person constructor: " << this->name << std::endl;
    }
public:
    // A public factory method or just make the constructor protected/public
    static Person createPerson(const std::string& name) {
        return Person(name);
    }
    std::string getName() const { return name; }
};

class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // This constructor will cause a compilation error because it cannot access Person's private constructor
    Employee(const std::string& name, int employeeId, double salary)
        : Person::createPerson(name), employeeId(employeeId), salary(salary) { // This attempts to call a static factory, but base class initialization requires a constructor call. This line itself is a semantic error.
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
    // This will not compile due to the semantic error in Employee's constructor attempting to initialize Person
    // Manager manager("Alice Smith", 101, 75000.0, "Sales");
    // std::cout << "\nManager Details:" << std::endl;
    // std::cout << "Name: " << manager.getName() << std::endl;
    // std::cout << "Employee ID: " << manager.getEmployeeId() << std::endl;
    // std::cout << "Salary: " << manager.getSalary() << std::endl;
    // std::cout << "Department: " << manager.getDepartment() << std::endl;
    return 0;
}