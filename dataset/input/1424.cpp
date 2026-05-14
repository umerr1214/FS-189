#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if (though not used efficiently here)

class Employee {
public:
    int employee_id_val; // Inconsistent naming
    std::string employee_name_str; // Inconsistent naming

    Employee(int id_param, const std::string& name_param) : employee_id_val(id_param), employee_name_str(name_param) {
        // std::cout << "Employee " << employee_name_str << " (ID: " << employee_id_val << ") created.\n";
    }

    ~Employee() {
        // std::cout << "Employee " << employee_name_str << " (ID: " << employee_id_val << ") destroyed.\n";
    }

    void showEmployeeDetails() const { // Verbose method name
        std::cout << "  Employee ID: " << employee_id_val << " -- Employee Name: " << employee_name_str << ".\n";
    }
};

class Department {
private:
    std::string dept_name_val; // Inconsistent naming
    std::vector<Employee*> all_employees_in_dept; // Verbose variable name, raw pointers

public:
    Department(const std::string& name_of_dept) : dept_name_val(name_of_dept) {
        // std::cout << "Department " << dept_name_val << " created.\n";
    }

    // Proper destructor to clean up memory (unlike 1423.cpp)
    ~Department() {
        for (Employee* emp : all_employees_in_dept) {
            delete emp;
        }
        all_employees_in_dept.clear();
        // std::cout << "Department " << dept_name_val << " destroyed (employees deleted).\n";
    }

    // Disable copy constructor and assignment operator to prevent double-free issues with raw pointers
    Department(const Department&) = delete;
    Department& operator=(const Department&) = delete;

    void addEmployeeToDepartment(Employee* emp_ptr_to_add) { // Verbose method name
        if (emp_ptr_to_add != nullptr) {
            bool found_duplicate_flag = false; // Flag variable, less idiomatic C++
            for (size_t i = 0; i < all_employees_in_dept.size(); ++i) { // Manual loop instead of range-based for or std::find_if
                if (all_employees_in_dept[i]->employee_id_val == emp_ptr_to_add->employee_id_val) {
                    found_duplicate_flag = true;
                    break;
                }
            }
            if (!found_duplicate_flag) {
                all_employees_in_dept.push_back(emp_ptr_to_add);
                // std::cout << "Added employee " << emp_ptr_to_add->employee_name_str << " to " << dept_name_val << ".\n";
            } else {
                // std::cout << "Employee with ID " << emp_ptr_to_add->employee_id_val << " already exists in " << dept_name_val << ".\n";
                delete emp_ptr_to_add; // Delete if duplicate, shifting responsibility here.
            }
        } else {
            // std::cout << "Attempted to add a null employee pointer to " << dept_name_val << ".\n";
        }
    }

    Employee* locateEmployeeById(int search_id) const { // Verbose method name, inefficient search
        for (size_t i = 0; i < all_employees_in_dept.size(); ++i) { // Linear search
            if (all_employees_in_dept[i]->employee_id_val == search_id) {
                return all_employees_in_dept[i];
            }
        }
        return nullptr; // Not found
    }

    void displayAllDepartmentEmployees() const { // Verbose method name, slightly inconsistent output
        std::cout << "--- Department: " << dept_name_val << " ---\n";
        std::cout << "Number of employees currently: " << all_employees_in_dept.size() << "\n";
        if (all_employees_in_dept.empty()) {
            std::cout << "  No employees to show.\n";
        } else {
            for (const auto& individual_employee_pointer : all_employees_in_dept) { // Okay range-based loop, but inconsistent variable name
                individual_employee_pointer->showEmployeeDetails();
            }
        }
        std::cout << "--------------------------------\n";
    }
};

int main() {
    Department sales_dept("Sales Division");
    Employee* empA = new Employee(201, "David");
    Employee* empB = new Employee(202, "Eve");
    Employee* empC = new Employee(203, "Frank");

    sales_dept.addEmployeeToDepartment(empA);
    sales_dept.addEmployeeToDepartment(empB);
    sales_dept.addEmployeeToDepartment(empC);

    sales_dept.displayAllDepartmentEmployees();

    Employee* empD = new Employee(201, "Duplicate David"); // Same ID as empA
    sales_dept.addEmployeeToDepartment(empD); // This will be deleted by addEmployeeToDepartment

    Employee* found_emp = sales_dept.locateEmployeeById(202);
    if (found_emp != nullptr) {
        std::cout << "Found employee with ID 202: ";
        found_emp->showEmployeeDetails();
    } else {
        std::cout << "Employee with ID 202 not found.\n";
    }

    Employee* not_found_emp = sales_dept.locateEmployeeById(999);
    if (not_found_emp != nullptr) {
        std::cout << "Found employee with ID 999: ";
        not_found_emp->showEmployeeDetails();
    } else {
        std::cout << "Employee with ID 999 not found.\n";
    }

    // Create another department to show independent management
    Department marketing_dept("Marketing Team");
    Employee* empE = new Employee(301, "Grace");
    marketing_dept.addEmployeeToDepartment(empE);
    marketing_dept.displayAllDepartmentEmployees();

    return 0;
}