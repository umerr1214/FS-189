#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int employeeID;

    Employee(std::string name, int employeeID) : name(std::move(name)), employeeID(employeeID) {}

    void display() const {
        std::cout << "ID: " << employeeID << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::string departmentName;
    std::vector<Employee*> employees; // Aggregation using raw pointers

public:
    Department(std::string name) : departmentName(std::move(name)) {}

    void addEmployee(Employee* emp) {
        if (emp) {
            employees.push_back(emp);
        }
    }

    void listEmployees() const {
        std::cout << "Department: " << departmentName << std::endl;
        // LOGICAL ERROR: The condition is inverted or misused.
        // It checks if the department is NOT empty, and if so, incorrectly states it HAS NO employees.
        if (!employees.empty()) { // This condition is true when employees exist
            std::cout << "No employees in this department." << std::endl; // Incorrect message
        } else { // This block is only reached if employees.empty() is true
            // This part will correctly execute only if the department is actually empty,
            // otherwise, the above incorrect message is printed.
            for (const auto& emp : employees) {
                emp->display();
            }
        }
    }

    // In this aggregation setup, Department does not own Employee objects,
    // so it doesn't delete them. The client code is responsible for their lifetime.
    ~Department() {
        // No deletion needed here for this specific aggregation model
    }
};

int main() {
    // Create Employee objects on the stack (client owns them)
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department hr("Human Resources");
    hr.addEmployee(&emp1); // Add pointers to stack-allocated employees
    hr.addEmployee(&emp2);

    std::cout << "Listing employees in HR department (expected Alice, Bob, but will show logical error):" << std::endl;
    hr.listEmployees(); // This will incorrectly print "No employees..."

    Department sales("Sales");
    std::cout << "\nListing employees in Sales department (empty, will print correctly):" << std::endl;
    sales.listEmployees(); // This will correctly print "No employees..."

    return 0;
}