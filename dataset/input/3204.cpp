#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        // std::cout << "Employee " << name << " (ID: " << id << ") created at " << this << "\n";
    }

    ~Employee() {
        // std::cout << "Employee " << name << " (ID: " << id << ") destroyed at " << this << "\n";
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

    // SEMANTIC ERROR: Takes Employee by value, then stores a pointer to the temporary copy.
    // The temporary `emp` object is destroyed when the function returns,
    // making the stored pointer a dangling pointer.
    void addEmployee(Employee emp) { // Should be Employee* emp or const Employee& emp
        // std::cout << "  addEmployee called with emp at " << &emp << "\n";
        // Check for duplicates based on ID (using the temporary object's ID)
        auto it = std::find_if(members.begin(), members.end(),
                               [emp_id = emp.id](const Employee* existing_emp) {
                                   // This access `existing_emp->id` could be dangerous if previous adds were also dangling
                                   return existing_emp && existing_emp->id == emp_id;
                               });
        if (it == members.end()) {
            members.push_back(&emp); // Storing address of a temporary stack object. DANGLING POINTER.
        }
    }

    void displayTeam() const {
        std::cout << "Team: " << teamName << "\n";
        if (members.empty()) {
            std::cout << "  No members.\n";
        } else {
            for (const auto& member : members) {
                if (member) {
                    // Accessing through a dangling pointer will lead to undefined behavior
                    member->display();
                } else {
                    std::cout << "  (NULL member pointer)\n";
                }
            }
        }
    }

    ~Team() {
        // Team does NOT own Employee memory, so no delete operations here
    }
};

void run_test_cases() {
    // When these Employees are passed to addEmployee, copies are made.
    // The original objects remain on the stack here.
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    Team devTeam("Development");
    // Passing emp1 by value creates a temporary copy in addEmployee.
    // A pointer to this temporary copy is stored.
    // The temporary copy is destroyed at the end of addEmployee.
    // The pointer in devTeam.members now dangles.
    devTeam.addEmployee(emp1);
    devTeam.addEmployee(emp2);
    devTeam.addEmployee(emp3);

    std::cout << "--- Development Team (Attempting to display dangling pointers) ---\n";
    devTeam.displayTeam(); // This will likely crash or show garbage due to dangling pointers
    std::cout << "\n";

    // To make it even more obvious, let's add an employee directly constructed
    // as a temporary in the call.
    Team qaTeam("QA");
    qaTeam.addEmployee(Employee("David", 104)); // Pointer to temporary "David" stored, then temporary destroyed.
    std::cout << "--- QA Team (Attempting to display dangling pointers) ---\n";
    qaTeam.displayTeam(); // Will also likely crash/show garbage
    std::cout << "\n";
}

int main() {
    run_test_cases();
    return 0;
}