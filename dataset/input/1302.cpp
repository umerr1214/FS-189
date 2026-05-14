#include <iostream>
#include <vector>
#include <string>
#include <memory> // Not strictly needed for the error, but good practice for unique_ptr/shared_ptr

class Employee {
private:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    void setName(const std::string& newName) { this->name = newName; } // Setter to demonstrate independent modification
    std::string getName() const { return name; }
    int getId() const { return id; }
};

class Department {
private:
    std::string name;
    std::vector<Employee> employees; // Semantic Error: Stores Employee objects by value (copies)
                                     // This means department doesn't aggregate the 'independent' Employee objects,
                                     // but rather its own distinct copies.
public:
    Department(std::string name) : name(name) {}

    void addEmployee(const Employee& emp) { // Takes a const reference, but stores a copy
        employees.push_back(emp);
    }

    void displayStaff() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No staff currently." << std::endl;
        } else {
            for (const auto& emp : employees) {
                std::cout << "  - " << emp.getName() << " (ID: " << emp.getId() << ")" << std::endl;
            }
        }
    }
};

int main() {
    Employee emp1("Alice", 101); // An independent Employee object

    Department engineering("Engineering");
    engineering.addEmployee(emp1); // A copy of emp1 is made and stored in engineering department

    std::cout << "Initial department staff:" << std::endl;
    engineering.displayStaff();
    std::cout << std::endl;

    // Semantic Error Demonstration: Modify the original independent employee object
    emp1.setName("Alicia");
    std::cout << "Original employee emp1's name changed to: " << emp1.getName() << std::endl;
    std::cout << std::endl;

    std::cout << "Department staff after modifying original emp1:" << std::endl;
    // The department will still show "Alice" because it holds a copy, not a reference
    engineering.displayStaff();
    std::cout << std::endl;

    return 0;
}