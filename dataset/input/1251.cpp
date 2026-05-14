#include <iostream>
#include <string>
#include <vector> // Although not used in this specific correct version, it's good practice to include what might be used.

class Employee {
protected:
    std::string name;
    std::string employeeId;

public:
    // Constructor taking const references for efficiency
    Employee(const std::string& name, const std::string& employeeId)
        : name(name), employeeId(employeeId) {}

    // Virtual method for runtime polymorphism, marked const as it doesn't modify the object
    virtual void displayInfo() const {
        std::cout << "Employee: " << name << ", ID: " << employeeId << '\n'; // Use '\n' for efficiency
    }
    
    // Virtual destructor for proper cleanup in polymorphic hierarchies
    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    std::string department;
    int teamSize;

public:
    // Constructor taking const references and initializing base class
    Manager(const std::string& name, const std::string& employeeId,
            const std::string& department, int teamSize)
        : Employee(name, employeeId), department(department), teamSize(teamSize) {}

    // Overrides displayInfo, marked const and using 'override' specifier for clarity and safety
    void displayInfo() const override {
        Employee::displayInfo(); // Call base class method to reuse logic
        std::cout << "  Department: " << department << ", Team Size: " << teamSize << '\n';
    }
};

int main() {
    // Create objects using smart pointers or on the stack
    Employee emp1("Alice Smith", "EMP-001");
    Manager mgr1("Bob Johnson", "MGR-001", "Engineering", 12);
    Manager mgr2("Carol White", "MGR-002", "Marketing", 7);

    // Use base class pointers for polymorphism
    std::vector<Employee*> staff;
    staff.push_back(&emp1);
    staff.push_back(&mgr1);
    staff.push_back(&mgr2);

    std::cout << "--- Company Staff Information ---\n";
    for (const auto& person : staff) {
        person->displayInfo();
        std::cout << '\n'; // Add an extra newline for better separation between entries
    }

    // Example of direct object calls
    std::cout << "--- Individual Information ---\n";
    emp1.displayInfo();
    mgr1.displayInfo();
    mgr2.displayInfo();

    return 0;
}