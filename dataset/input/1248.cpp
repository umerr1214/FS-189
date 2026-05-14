#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}
    // Semantic Error: The 'virtual' keyword is missing.
    // This prevents polymorphic behavior when calling displayInfo() through base pointers/references.
    void displayInfo() const { // Not virtual
        std::cout << "Employee Name: " << name << ", ID: " << id << std::endl;
    }
};

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string n, int i, std::string d) : Employee(n, i), department(d) {}
    // This method hides (rather than overrides polymorphically) the base class displayInfo()
    // because the base method is not virtual.
    void displayInfo() const { // Not using 'override' because base is not virtual
        Employee::displayInfo(); // Explicitly call base method
        std::cout << "  Department: " << department << std::endl;
    }
};

int main() {
    Employee emp("Alice", 101);
    Manager mgr("Bob", 201, "Sales");

    std::cout << "--- Direct Calls ---" << std::endl;
    emp.displayInfo();
    mgr.displayInfo(); // Calls Manager's displayInfo directly
    std::cout << std::endl;

    std::cout << "--- Polymorphic Calls (via base pointer) ---" << std::endl;
    Employee* e1 = new Employee("Charlie", 301);
    Employee* e2 = new Manager("David", 401, "Marketing"); // Manager object, but pointed to by Employee*

    e1->displayInfo(); // Calls Employee::displayInfo()
    // Semantic Error: This will incorrectly call Employee::displayInfo() because
    // the base method is not virtual, preventing runtime polymorphism.
    e2->displayInfo();

    delete e1;
    delete e2;
    std::cout << std::endl;

    return 0;
}