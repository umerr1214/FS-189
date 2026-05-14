#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {}

    void displayPersonInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
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
    Manager originalManager("Charlie", 40, "M201", 120000.0, "HR", 15);

    std::cout << "--- Original Manager Info ---" << std::endl;
    originalManager.displayManagerInfo();

    // SEMANTIC ERROR: Object slicing occurs here.
    // The Manager object's data for 'department' and 'teamSize' is lost
    // when assigned to an Employee object by value.
    Employee slicedEmployee = originalManager;

    std::cout << "\n--- Sliced Employee Info (from Manager) ---" << std::endl;
    slicedEmployee.displayEmployeeInfo();
    // Note: slicedEmployee cannot call displayManagerInfo() as it's an Employee.
    // The semantic error is that the Manager-specific data is gone without warning (at compile time),
    // leading to unexpected loss of information.

    // To further illustrate, let's create a regular employee for comparison
    Employee regularEmployee("David", 28, "E102", 60000.0);
    std::cout << "\n--- Regular Employee Info ---" << std::endl;
    regularEmployee.displayEmployeeInfo();

    return 0;
}