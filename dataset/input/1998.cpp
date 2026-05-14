#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    double salary;

public:
    Employee(std::string n, double s) : name(n), salary(s) {}

    std::string getName() const { return name; }
    double getSalary() const { return salary; }

    virtual void display() const {
        std::cout << "Name: " << name << ", Salary: " << salary << std::endl;
    }
};

class Manager : public Employee {
public:
    std::string department;

    Manager(std::string n, double s, std::string d) : Employee(n, s), department(d) {}
    
    void display() const override {
        std::cout << "Manager - ";
        Employee::display();
        std::cout << "  Department: " << department << std::endl;
    }
};

class Engineer : public Employee {
public:
    std::string specialization;

    Engineer(std::string n, double s, std::string spec) : Employee(n, s), specialization(spec) {}

    void display() const override {
        std::cout << "Engineer - ";
        Employee::display();
        std::cout << "  Specialization: " << specialization << std::endl;
    }
};

// Function that demonstrates object slicing (semantic error)
// Takes Employee by value, so derived-specific parts are "sliced off".
void printEmployeeDetails(Employee emp) { 
    std::cout << "Details from printEmployeeDetails (sliced):" << std::endl;
    emp.display(); // This will only call Employee::display(), losing derived info
}

int main() {
    Manager m("Alice", 75000.0, "HR");
    Engineer e("Bob", 60000.0, "Software");

    std::cout << "--- Original Objects ---" << std::endl;
    m.display();
    e.display();

    std::cout << "\n--- Sliced Objects ---" << std::endl;
    // Semantic error: object slicing occurs here
    printEmployeeDetails(m); // Manager object 'm' is sliced to an Employee object
    printEmployeeDetails(e); // Engineer object 'e' is sliced to an Employee object

    std::cout << "\nTo avoid slicing, pass by reference or pointer:\n";
    std::cout << "Correct call for Manager:\n";
    // This is how it should be done to avoid slicing:
    // void printEmployeeDetailsRef(const Employee& emp) { emp.display(); }
    // printEmployeeDetailsRef(m); 

    return 0;
}