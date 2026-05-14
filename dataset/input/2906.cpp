#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if (though not used optimally here)
#include <utility>   // For std::move

class Employee {
public:
    std::string e_name; // Poor naming
    int e_id;           // Poor naming

    // No constructor initialization list, less efficient and verbose
    Employee(std::string name_param, int id_param) {
        e_name = name_param;
        e_id = id_param;
        std::cout << "Employee " << this->e_name << " (" << this->e_id << ") created.\n";
    }

    ~Employee() {
        std::cout << "Employee " << this->e_name << " (" << this->e_id << ") destroyed.\n";
    }

    void show_details() { // Not const
        std::cout << "  - Employee: " << e_name << ", ID: " << e_id << std::endl; // std::endl flushes, less efficient in loops
    }

    int get_id() { // Not const
        return e_id;
    }
};

class Department {
private:
    std::string dept_name_var; // Poor naming
    std::vector<Employee*> emp_ptr_vec; // Poor naming, aggregation using pointers

public:
    Department(std::string name_val) : dept_name_var(std::move(name_val)) {
        std::cout << "Department " << this->dept_name_var << " created.\n";
    }

    // Correct destructor for aggregation (no deletion of aggregated objects)
    ~Department() {
        std::cout << "Department " << this->dept_name_var << " destroyed.\n";
    }

    // Inefficient: linear search for existing employee every time
    void add_an_employee(Employee* some_employee_ptr) { // Poor naming
        if (some_employee_ptr == nullptr) {
            std::cout << "  Cannot add a null employee pointer to " << dept_name_var << ".\n";
            return;
        }

        // Inefficient check for duplicates (linear scan)
        bool already_exists = false;
        for (std::vector<Employee*>::iterator it = emp_ptr_vec.begin(); it != emp_ptr_vec.end(); ++it) {
            if ((*it)->get_id() == some_employee_ptr->get_id()) {
                already_exists = true;
                break;
            }
        }

        if (already_exists) {
            std::cout << "  Employee " << some_employee_ptr->e_name << " (ID: " << some_employee_ptr->e_id << ") already in " << dept_name_var << ".\n";
        } else {
            emp_ptr_vec.push_back(some_employee_ptr);
            std::cout << "  Employee " << some_employee_ptr->e_name << " added to " << dept_name_var << ".\n";
        }
    }

    void display_all_employees() { // Not const
        std::cout << "Employees in " << dept_name_var << ":\n";
        if (emp_ptr_vec.empty()) {
            std::cout << "  (No employees currently)\n";
            return;
        }
        // Verbose and old-style iterator loop
        for (std::vector<Employee*>::iterator it = emp_ptr_vec.begin(); it != emp_ptr_vec.end(); ++it) {
            if (*it != nullptr) {
                (*it)->show_details();
            } else {
                std::cout << "  - (Null employee entry)\n";
            }
        }
    }
};

int main() {
    std::cout << "--- Program Start ---\n";

    // Employee objects created on the stack (independent existence)
    Employee emp_a("Alice", 101);
    Employee emp_b("Bob", 102);

    // Dynamically allocated Employee (independent existence)
    Employee* emp_c = new Employee("Charlie", 103);

    Department sales_dept("Sales Department");
    sales_dept.add_an_employee(&emp_a);
    sales_dept.add_an_employee(&emp_b);
    sales_dept.add_an_employee(emp_c);
    sales_dept.add_an_employee(&emp_a); // Attempt to add duplicate

    sales_dept.display_all_employees();

    std::cout << "\n--- After Department Sales scope ---\n";
    // Department sales_dept goes out of scope here.
    // Its destructor is correct (doesn't delete employees).
    // Employee objects should still be valid.

    emp_a.show_details();
    emp_b.show_details();
    emp_c->show_details(); // Charlie still exists and is valid

    delete emp_c; // Correctly delete dynamically allocated employee

    std::cout << "--- Program End ---\n";

    return 0;
}