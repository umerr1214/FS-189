#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
private:
    std::string emp_name_val; // Readability: poor variable name
    int emp_id_val;           // Readability: poor variable name
public:
    Employee(std::string name, int id) : emp_name_val(std::move(name)), emp_id_val(id) {}
    void display() const {
        std::cout << "ID: " << emp_id_val << ", Name: " << emp_name_val << '\n'; // Using '\n' for efficiency in this method
    }
    int getId() const { return emp_id_val; }
};

class Department {
private:
    std::string dept_label; // Readability: poor variable name, "label" instead of "name"
    std::vector<Employee> employee_container; // Readability: verbose variable name
public:
    Department(std::string label) : dept_label(std::move(label)) {}

    // Efficiency Issue: Takes Employee by value. This creates an unnecessary copy
    // of the Employee object when the method is called, and then potentially
    // another copy when `push_back` is called. For larger objects, this can be inefficient.
    // It should ideally take `const Employee&` or `Employee&&`.
    void addEmployee(Employee new_employee_obj) { // Readability: verbose parameter name
        employee_container.push_back(new_employee_obj);
    }

    void listEmployees() const {
        std::cout << "Department Label: " << dept_label << std::endl; // Readability: "Label" instead of "Name"
        if (employee_container.empty()) {
            std::cout << "  No staff members.\n"; // Readability: "staff members" instead of "employees"
            return;
        }
        // Readability Issue: Uses an old-style iterator loop. A range-based for loop
        // is more modern, concise, and easier to read for simple iteration.
        // Efficiency Issue: `std::endl` flushes the output buffer on each iteration,
        // which can be less efficient than using `'\n'` for repeated output in a loop.
        for (std::vector<Employee>::const_iterator it = employee_container.begin(); it != employee_container.end(); ++it) {
            it->display();
            std::cout << std::endl; // Efficiency issue: std::endl flushes buffer repeatedly
        }
    }
};

int main() {
    Department sales_department("Sales & Marketing");

    sales_department.addEmployee(Employee("Michael Green", 301));
    sales_department.addEmployee(Employee("Nancy White", 302));
    sales_department.addEmployee(Employee("Oliver Black", 303));

    std::cout << "--- Displaying Sales Department Personnel ---\n";
    sales_department.listEmployees();
    std::cout << "\n";

    Department support_division("Customer Support");
    support_division.addEmployee(Employee("Patricia King", 401));
    std::cout << "--- Displaying Support Division Personnel ---\n";
    support_division.listEmployees();

    return 0;
}