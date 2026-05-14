#include <iostream>
#include <vector>
#include <strin> // SYNTAX ERROR: Typo for <string>
#include <algorithm>

class Employee { // SYNTAX ERROR: Missing semicolon after class definition
public:
    std::strin name; // SYNTAX ERROR: Typo for std::string
    int id;

    Employee(std::strin name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
    }
} // Missing semicolon here

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

    ~Team() {
        // Team does NOT own Employee memory, so no delete operations here
    }
};

void run_test_cases() {
    // Employees created on the stack
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    Team devTeam("Development");
    devTeam.addEmployee(&emp1);
    devTeam.addEmployee(&emp2);
    devTeam.addEmployee(&emp3);
    devTeam.addEmployee(&emp1); // Attempt to add duplicate

    std::cout << "--- Development Team ---\n";
    devTeam.displayTeam();
    std::cout << "\n";

    Team qaTeam("QA");
    qaTeam.addEmployee(&emp3); // Charlie can be in multiple teams
    // This line would cause issues due to the syntax errors if it ever compiled
    // qaTeam.addEmployee(Employee("David", 104));

    // std::cout << "--- QA Team ---\n";
    // qaTeam.displayTeam();
    // std::cout << "\n";
}

int main() {
    run_test_cases();
    return 0;
}