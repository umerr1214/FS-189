#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if

class Employee {
public:
    int id;
    std::string name;

    Employee(int id, const std::string& name) : id(id), name(name) {
        // std::cout << "Employee " << name << " (ID: " << id << ") created.\n";
    }

    ~Employee() {
        // std::cout << "Employee " << name << " (ID: " << id << ") destroyed.\n";
    }

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << "\n";
    }
};

class Department {
private:
    std::string name;
    std::vector<Employee*> employees; // Aggregating Employee pointers

public:
    Department(const std::string& name) : name(name) {
        // std::cout << "Department " << name << " created.\n";
    }

    // Robustness Issue: Destructor does NOT delete aggregated Employee objects, leading to memory leaks.
    ~Department() {
        // For this robustness issue, we intentionally omit deletion.
        // A correct implementation would iterate and delete each Employee* to prevent leaks.
        // For example:
        // for (Employee* emp : employees) {
        //     delete emp;
        // }
        // employees.clear();
        // std::cout << "Department " << name << " destroyed (employees NOT deleted).\n";
    }

    // Prevents accidental copying which would lead to double-free or dangling pointers
    // if deletion was present. For this specific memory leak issue, it's not the primary point,
    // but missing these would also be a robustness issue in a complete raw pointer solution.
    Department(const Department&) = delete;
    Department& operator=(const Department&) = delete;

    void addEmployee(Employee* emp) {
        if (emp) {
            // Check for duplicates based on ID
            auto it = std::find_if(employees.begin(), employees.end(),
                                   [emp](const Employee* existing_emp) {
                                       return existing_emp->id == emp->id;
                                   });
            if (it == employees.end()) {
                employees.push_back(emp);
                // std::cout << "Added employee " << emp->name << " to " << name << ".\n";
            } else {
                // std::cout << "Employee with ID " << emp->id << " already exists in " << name << ".\n";
            }
        }
    }

    void listEmployees() const {
        std::cout << "Department: " << name << " has " << employees.size() << " employees:\n";
        if (employees.empty()) {
            std::cout << "  No employees.\n";
        } else {
            for (const auto& emp : employees) {
                emp->display();
            }
        }
    }
};

int main() {
    Employee* emp1 = new Employee(101, "Alice");
    Employee* emp2 = new Employee(102, "Bob");
    Employee* emp3 = new Employee(103, "Charlie");

    {
        Department hr_dept("Human Resources");
        hr_dept.addEmployee(emp1);
        hr_dept.addEmployee(emp2);
        hr_dept.listEmployees();
    } // hr_dept goes out of scope, but emp1 and emp2 are NOT deleted. Memory leak occurs.

    {
        Department it_dept("IT");
        it_dept.addEmployee(emp3);
        it_dept.listEmployees();
    } // it_dept goes out of scope, but emp3 is NOT deleted. Memory leak occurs.

    // To prevent an actual leak in a simple test environment, we manually delete them here.
    // In a real application, this manual deletion would indicate a flaw in the Department's ownership management.
    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}