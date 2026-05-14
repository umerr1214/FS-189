#include <string>
#include <vector>
#include <iostream>

class Employee {
public:
    int id;
    std::string name;

    Employee(int id, const std::string& name) : id(id), name(name) {}

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::string name;
    // Semantic Error: Storing raw pointers to Employee objects.
    // This design implies Department does not own the Employee objects,
    // leading to dangling pointers if objects are stack-allocated and go out of scope.
    std::vector<Employee*> employees;

public:
    Department(const std::string& name) : name(name) {}

    // Semantic Error: Takes a raw pointer, but Department does not manage the lifetime
    // of the pointed-to object. This can lead to dangling pointers or memory leaks
    // if not handled carefully by the caller.
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void listEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees." << std::endl;
            return;
        }
        for (const auto& emp_ptr : employees) {
            // Dereferencing a potentially dangling pointer, leading to Undefined Behavior.
            // Specifically, 'e3' goes out of scope before this function is called.
            emp_ptr->display();
        }
    }

    // A destructor would be needed if Department *owned* the Employee objects,
    // but with raw pointers, it's ambiguous and often leads to errors.
    // ~Department() {
    //     for (Employee* emp_ptr : employees) {
    //         delete emp_ptr; // This would be a double-free if objects are stack-allocated
    //     }
    // }
};

int main() {
    Department hr("Human Resources");

    Employee e1(101, "Alice Smith");
    Employee e2(102, "Bob Johnson");

    hr.addEmployee(&e1); // Pass address of stack-allocated object
    hr.addEmployee(&e2); // Pass address of stack-allocated object

    { // Introduce a scope to clearly demonstrate a dangling pointer
        Employee e3(103, "Charlie Brown");
        hr.addEmployee(&e3); // Pass address of stack-allocated object
    } // e3 is destroyed here, making the corresponding pointer in 'employees' dangling.

    hr.listEmployees(); // Accessing dangling pointer for e3, resulting in Undefined Behavior.

    return 0;
}