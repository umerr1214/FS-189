#include <iostream>
#include <string>
#include <iomanip>

// Base class Person
class Person {
private:
    std::string name;
    short age; // SEMANTIC ERROR: 'age' should be 'int' as per question, but is 'short'.
               // This compiles, but violates the type specification in the question.
               // It could lead to data loss for large age values (overflow).

public:
    void setDetails(const std::string& n, int a) { // Takes int as expected
        name = n;
        age = a; // Implicit conversion from int to short, potentially losing data
    }

    void displayDetails() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    int employeeID;
    double salary;

public:
    void setEmployeeDetails(int id, double s) {
        employeeID = id;
        salary = s;
    }

    // This method sets both Person and Employee details
    void setAllDetails(const std::string& n, int a, int id, double s) {
        setDetails(n, a); // Call base class method to set inherited details
        employeeID = id;
        salary = s;
    }

    void displayAllDetails() const {
        Person::displayDetails(); // Call base class method to display inherited details
        std::cout << ", Employee ID: " << employeeID << ", Salary: " << std::fixed << std::setprecision(2) << salary << std::endl;
    }
};

int main() {
    // Test Person
    Person p;
    p.setDetails("Alice", 30);
    std::cout << "Person Details: ";
    p.displayDetails();
    std::cout << std::endl;

    // Test Employee
    Employee e;
    e.setAllDetails("Bob", 25, 1001, 50000.50);
    std::cout << "Employee Details: ";
    e.displayAllDetails();

    Employee e2;
    e2.setAllDetails("Charlie", 40, 1002, 75000.75);
    std::cout << "Employee Details: ";
    e2.displayAllDetails();

    return 0;
}