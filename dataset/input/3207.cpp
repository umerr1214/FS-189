#include <iostream>
#include <string>
#include <vector>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    // Constructor to initialize Employee objects
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    // Method to display employee information
    void display() const {
        std::cout << "Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

class Team {
private:
    std::vector<Employee*> teamMembers; // Uses std::vector to manage Employee pointers

public:
    // Default constructor
    Team() = default;

    // Method to add an employee to the team.
    // The team stores a pointer but does NOT take ownership of the Employee* memory.
    // This means the caller is responsible for the Employee object's lifetime.
    void addEmployee(Employee* emp) {
        if (emp != nullptr) {
            teamMembers.push_back(emp); // Efficiently adds the pointer to the vector
            std::cout << "Added employee " << emp->name << " to team." << std::endl;
        } else {
            std::cout << "Cannot add a null employee pointer to the team." << std::endl;
        }
    }

    // Method to display all team members
    void displayTeam() const {
        std::cout << "\n--- Team Members ---" << std::endl;
        if (teamMembers.empty()) {
            std::cout << "No members in the team." << std::endl;
        } else {
            // Use a range-based for loop for clean and readable iteration
            for (const auto& emp : teamMembers) {
                if (emp != nullptr) { // Defensive check, though addEmployee ensures non-null
                    emp->display();
                }
            }
        }
        std::cout << "--------------------" << std::endl;
    }

    // Destructor: IMPORTANT!
    // As per the problem statement, the Team class does NOT own the memory
    // pointed to by its `Employee*` members. Therefore, it should NOT
    // delete these pointers in its destructor. The responsibility for
    // deleting heap-allocated Employee objects (if any) lies with the
    // code that created and owns them.
    ~Team() {
        // No delete calls here, as Team does not own the Employee objects.
    }

    // The default copy constructor, copy assignment operator, move constructor,
    // and move assignment operator are sufficient here because Team manages
    // non-owning raw pointers. They will perform shallow copies/moves of the
    // pointers, which is the correct behavior for non-owning references.
    // If Team owned the memory, custom implementations following the Rule of 5
    // would be necessary.
};

int main() {
    // --- Demonstrate with stack-allocated Employee objects ---
    // These objects are automatically managed and destroyed when main exits.
    // The Team class will store pointers to these stack objects.
    Employee emp1("Alice Johnson", 101);
    Employee emp2("Bob Smith", 102);
    Employee emp3("Charlie Brown", 103);

    Team devTeam;

    // Add employees to the team
    devTeam.addEmployee(&emp1);
    devTeam.addEmployee(&emp2);
    devTeam.addEmployee(&emp3);
    devTeam.addEmployee(nullptr); // Demonstrate handling of null pointers

    devTeam.displayTeam();

    // --- Demonstrate with dynamically allocated Employee objects ---
    // The `main` function (or the creator) is responsible for managing
    // the lifetime of these heap-allocated objects.
    Employee* emp4 = new Employee("Diana Prince", 104);
    devTeam.addEmployee(emp4);
    devTeam.displayTeam();

    // Clean up the dynamically allocated employee.
    // This is crucial because `Team` does not do it.
    delete emp4;
    emp4 = nullptr; // Good practice to nullify pointer after deletion

    // emp1, emp2, emp3 are stack-allocated and will be cleaned up automatically
    // when main() finishes.

    return 0;
}