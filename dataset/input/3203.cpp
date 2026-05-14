#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        // std::cout << "Employee " << name << " (ID: " << id << ") created.\n";
    }

    ~Employee() {
        // std::cout << "Employee " << name << " (ID: " << id << ") destroyed.\n";
    }

    void display() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
    }
};

class Team {
private:
    std::string teamName;
    std::vector<Employee*> members;

public:
    Team(std::string name) : teamName(std::move(name)) {}

    void addEmployee(Employee* emp) {
        if (emp) {
            auto it = std::find_if(members.begin(), members.end(),
                                   [emp](const Employee* existing_emp) { return existing_emp->id == emp->id; });
            if (it == members.end()) {
                members.push_back(emp);
            }
        }
    }

    void displayTeam() const {
        std::cout << "Team: " << teamName << "\n";
        if (members.empty()) {
            std::cout << "  No members.\n";
        } else {
            for (const auto& member : members) {
                if (member) {
                    member->display();
                }
            }
        }
    }

    // LOGICAL ERROR: The Team destructor attempts to delete members,
    // violating the problem's constraint that the team should not own their memory.
    ~Team() {
        // std::cout << "Team destructor called for " << teamName << ". Attempting to delete members.\n";
        for (Employee* member : members) {
            delete member; // This will cause a double-free if employees are stack-allocated
                           // or owned by another entity (like main's scope).
        }
        members.clear();
    }
};

void run_test_cases() {
    // Employees created on the stack. Their memory is managed by main's scope.
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    Team devTeam("Development");
    devTeam.addEmployee(&emp1);
    devTeam.addEmployee(&emp2);
    devTeam.addEmployee(&emp3);
    devTeam.addEmployee(&emp1); // Attempt to add duplicate

    std::cout << "--- Development Team (before end of scope) ---\n";
    devTeam.displayTeam();
    std::cout << "\n";

    // When devTeam goes out of scope, its destructor will be called,
    // attempting to delete emp1, emp2, emp3 which are stack-allocated.
    // This leads to undefined behavior/double-free.

    // Also demonstrate with a dynamically allocated employee.
    // If 'main' also tries to delete it, it's a double-free.
    // If 'main' doesn't, then Team "owns" it, which is against the prompt.
    Employee* dynamicEmp = new Employee("Frank", 106);
    Team opsTeam("Operations");
    opsTeam.addEmployee(dynamicEmp);
    std::cout << "--- Operations Team ---\n";
    opsTeam.displayTeam();
    std::cout << "\n";
    // If we uncomment 'delete dynamicEmp;' here, it would be deleted twice.
    // delete dynamicEmp;
}

int main() {
    run_test_cases(); // emp1, emp2, emp3 created and passed to devTeam.
                      // devTeam destructor called at end of run_test_cases.
                      // This will try to delete stack-allocated objects.
    return 0;
}