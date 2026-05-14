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

    // Constructor with member initializer list
    Person(const std::string& initialName, int initialAge)
        : name(initialName), age(0) { // Initialize age to 0, then validate
        setAge(initialAge); // Use setter for validation
    }

    // Public methods to set details with validation and const-reference for string
    void setName(const std::string& newName) {
        name = newName;
    }

    // Robust setter with validation
    bool setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
            return true;
        }
        std::cerr << "Error: Age cannot be negative. Age not set." << std::endl;
        return false;
    }

    // Public methods to display details (getters are const-correct)
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Display method is const-correct
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

    // Constructor with member initializer list, calling base constructor
    Employee(const std::string& initialName, int initialAge, int initialID, double initialSalary)
        : Person(initialName, initialAge), employeeID(initialID), salary(0.0) { // Initialize salary to 0, then validate
        setSalary(initialSalary); // Use setter for validation
    }

    // Public methods to set specific details
    void setEmployeeID(int newID) {
        employeeID = newID;
    }

    // Robust setter with validation
    bool setSalary(double newSalary) {
        if (newSalary >= 0.0) {
            salary = newSalary;
            return true;
        }
        std::cerr << "Error: Salary cannot be negative. Salary not set." << std::endl;
        return false;
    }

    // Public methods to display specific details (getters are const-correct)
    int getEmployeeID() const {
        return employeeID;
    }

    double getSalary() const {
        return salary;
    }

    // Display method for Employee, including inherited details (const-correct)
    void displayEmployee() const {
        Person::displayPerson(); // Explicitly call base class display
        std::cout << ", Employee ID: " << employeeID << ", Salary: " << salary << std::endl;
    }
};

// Driver code for testing
int main() {
    std::cout << "--- Testing Correct Version (1797) ---" << std::endl;

    // Test case 1: Person object with valid data
    Person p1;
    p1.setName("Alice Wonderland");
    p1.setAge(30);
    std::cout << "Person 1 Details: ";
    p1.displayPerson();
    std::cout << std::endl;

    // Test case 2: Person object with invalid age
    Person p2;
    p2.setName("Bob The Builder");
    if (!p2.setAge(-5)) { // Attempt to set invalid age
        std::cout << "Person 2 Details (after invalid age attempt): ";
        p2.displayPerson(); // Should show default/previous age (0 in this case)
        std::cout << std::endl;
    }

    // Test case 3: Employee object with valid data
    Employee e1;
    e1.setName("Charlie Chaplin");
    e1.setAge(25);
    e1.setEmployeeID(1001);
    e1.setSalary(50000.0);
    std::cout << "Employee 1 Details: ";
    e1.displayEmployee();

    // Test case 4: Employee object with invalid salary
    Employee e2;
    e2.setName("Diana Prince");
    e2.setAge(40);
    e2.setEmployeeID(1002);
    if (!e2.setSalary(-15000.0)) { // Attempt to set invalid salary
        std::cout << "Employee 2 Details (after invalid salary attempt): ";
        e2.displayEmployee(); // Should show default/previous salary (0.0 in this case)
    }

    // Test case 5: Employee object with constructor, including invalid age/salary
    std::cout << "\nAttempting to create Employee with invalid age/salary via constructor:" << std::endl;
    Employee e3("Eve Adams", -20, 1003, -75000.0); // Constructor will use setters
    std::cout << "Employee 3 Details (constructor with invalid data): ";
    e3.displayEmployee();
    // The constructor's setAge(-20) will fail, age will remain 0.
    // The constructor's setSalary(-75000.0) will fail, salary will remain 0.0.

    std::cout << "Note: Validation messages indicate when invalid data is rejected." << std::endl;

    return 0;
}