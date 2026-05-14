#include <iostream>
#include <string>
#include <vector>

// Base class Person
class Person {
private:
    std::string name;
    int age;

public:
    // Default constructor
    Person() : name(""), age(0) {}

    // Constructor
    Person(const std::string& name_val, int age_val) : name(name_val), age(age_val) {}

    // Public methods to set details
    void setName(const std::string& newName) {
        name = newName;
    }

    // Robustness issue: Allows negative age without validation
    void setAge(int newAge) {
        age = newAge; // No validation for age
    }

    // Public methods to display details (getters for internal use, display for output)
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void displayPerson() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    int employeeID;
    double salary;

public:
    // Default constructor
    Employee() : Person(), employeeID(0), salary(0.0) {}

    // Constructor
    Employee(const std::string& name_val, int age_val, int id_val, double sal_val)
        : Person(name_val, age_val), employeeID(id_val), salary(sal_val) {}

    // Public methods to set specific details
    void setEmployeeID(int newID) {
        employeeID = newID;
    }

    // Robustness issue: Allows negative salary without validation
    void setSalary(double newSalary) {
        salary = newSalary; // No validation for salary
    }

    // Public methods to display specific details
    int getEmployeeID() const {
        return employeeID;
    }

    double getSalary() const {
        return salary;
    }

    // Display method for Employee, including inherited details
    void displayEmployee() const {
        displayPerson(); // Call base class display
        std::cout << ", Employee ID: " << employeeID << ", Salary: " << salary << std::endl;
    }
};

// Driver code for testing
int main() {
    std::cout << "--- Testing Robustness Issue (1795) ---" << std::endl;

    // Test case 1: Person with invalid age
    Person p1;
    p1.setName("Alice");
    p1.setAge(-5); // Setting a negative age
    std::cout << "Person 1 Details (invalid age): ";
    p1.displayPerson();
    std::cout << std::endl;

    // Test case 2: Employee with invalid age and salary
    Employee e1;
    e1.setName("Bob");
    e1.setAge(-10); // Setting a negative age
    e1.setEmployeeID(1001);
    e1.setSalary(-15000.0); // Setting a negative salary
    std::cout << "Employee 1 Details (invalid age and salary): ";
    e1.displayEmployee();

    // Test case 3: Employee created with invalid data via constructor
    Employee e2("Charlie", -25, 1002, -75000.0);
    std::cout << "Employee 2 Details (constructor with invalid data): ";
    e2.displayEmployee();

    std::cout << "Note: The program accepts and displays negative age/salary due to lack of validation." << std::endl;

    return 0;
}