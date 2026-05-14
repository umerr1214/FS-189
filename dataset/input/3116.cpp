#include <iostream>
#include <vector>
#include <string>
#include <cstdio> // For printf

class Employee {
public:
    std::string empName; // Less descriptive variable name
    int employeeID;    // Less descriptive variable name

    Employee(std::string name, int id) : empName(name), employeeID(id) {}

    void showDetails() { // Non-const method for displaying, not ideal
        std::cout << "Name: " << empName << ", ID: " << employeeID << std::endl;
    }
};

class Department {
private:
    std::vector<Employee> allEmployees; // Slightly less conventional naming

public:
    // Efficiency Issue: Takes Employee by value, causing an unnecessary copy
    void addEmployee(Employee newEmp) {
        allEmployees.push_back(newEmp); // Another copy happens here
    }

    // Readability/Efficiency Issue: Uses old-style for loop and printf
    void displayAllEmployees() { // Not const-qualified
        printf("Department Employees:\n");
        if (allEmployees.empty()) {
            printf("No employees in this department.\n");
            return;
        }
        for (size_t i = 0; i < allEmployees.size(); ++i) { // Old-style loop
            printf("Name: %s, ID: %d\n", allEmployees[i].empName.c_str(), allEmployees[i].employeeID); // C-style output
        }
    }
};

int main() {
    Department myDeptObject; // Slightly verbose variable name

    Employee firstEmployee("Alice", 101);
    Employee secondEmployee("Bob", 102);
    Employee thirdEmployee("Charlie", 103);

    myDeptObject.addEmployee(firstEmployee);
    myDeptObject.addEmployee(secondEmployee);
    myDeptObject.addEmployee(thirdEmployee);

    myDeptObject.displayAllEmployees();

    std::cout << "Demonstration complete." << std::endl; // Inconsistent output method

    return 0;
}