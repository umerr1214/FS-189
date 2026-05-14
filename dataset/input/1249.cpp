#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // For robustness issue explanation

class Employee {
protected:
    std::string name;
    std::string employeeId;

public:
    Employee(const std::string& name, const std::string& employeeId)
        : name(name), employeeId(employeeId) {}

    virtual void displayInfo() const {
        std::cout << "Employee: " << name << ", ID: " << employeeId << std::endl;
    }
};

class Manager : public Employee {
private:
    std::string department;
    std::vector<std::string> managedProjects;

public:
    Manager(const std::string& name, const std::string& employeeId,
            const std::string& department, const std::vector<std::string>& projects)
        : Employee(name, employeeId), department(department), managedProjects(projects) {}

    // Overrides displayInfo to include manager-specific details
    void displayInfo() const override {
        Employee::displayInfo(); // Call base class method
        std::cout << "  Department: " << department << std::endl;
        // Robustness Issue: Accessing managedProjects[0] without checking if the vector is empty.
        // If managedProjects is empty, this will cause a std::out_of_range exception or a crash.
        std::cout << "  First Project: " << managedProjects[0] << std::endl;
    }
};

int main() {
    Employee emp1("Alice", "E001");
    Manager mgr1("Bob", "M001", "Sales", {"Project Alpha", "Project Beta"});
    Manager mgr2("Carol", "M002", "HR", {}); // Manager with no projects - triggers robustness issue

    std::cout << "--- Displaying Employee Info ---" << std::endl;
    emp1.displayInfo();
    std::cout << std::endl;

    std::cout << "--- Displaying Manager 1 Info ---" << std::endl;
    mgr1.displayInfo();
    std::cout << std::endl;

    std::cout << "--- Displaying Manager 2 Info (Robustness Issue Expected) ---" << std::endl;
    try {
        mgr2.displayInfo(); // This call will likely crash or throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << " - Manager has no projects." << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred for Manager 2." << std::endl;
    }
    std::cout << std::endl;

    return 0;
}