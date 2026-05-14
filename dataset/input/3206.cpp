#include <iostream>
#include <string>
#include <vector>
#include <utility> // For std::move
#include <algorithm> // For std::find, used inefficiently here

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

class Team {
private:
    std::vector<Employee*> teamMembers; // Manages pointers to Employee objects

public:
    Team() {
        // Default constructor, vector is empty.
    }

    // Readability / Efficiency Issue:
    // 1. Inefficient check for existence: A linear search (`for` loop) is performed
    //    before adding. If duplicates are allowed, this is redundant overhead.
    //    If duplicates are not allowed, for large teams, `std::set<Employee*>`
    //    or `std::unordered_set<Employee*>` would be more efficient for uniqueness checks.
    // 2. Verbose addition: Instead of simply using `teamMembers.push_back(emp);`,
    //    the vector is manually resized and then assigned, which is less idiomatic
    //    and potentially less efficient than `push_back`.
    void addEmployee(Employee* emp) {
        if (emp != nullptr) {
            // Readability/Efficiency Issue: Linear search for existence.
            // This is O(N) for each add operation.
            bool found = false;
            for (size_t i = 0; i < teamMembers.size(); ++i) {
                if (teamMembers[i] == emp) { // Checking pointer equality
                    found = true;
                    break;
                }
            }

            if (!found) {
                // Readability/Efficiency Issue: Manual resize and assign instead of push_back.
                teamMembers.resize(teamMembers.size() + 1);
                teamMembers[teamMembers.size() - 1] = emp;
                std::cout << "Added employee " << emp->name << " to team." << std::endl;
            } else {
                std::cout << "Employee " << emp->name << " is already in the team (pointer match)." << std::endl;
            }
        } else {
            std::cout << "Cannot add a null employee pointer." << std::endl;
        }
    }

    // Readability Issue: Uses a raw index-based for loop instead of a more modern
    // and readable range-based for loop.
    void displayTeam() const {
        std::cout << "\n--- Team Members ---" << std::endl;
        if (teamMembers.empty()) {
            std::cout << "No members in the team." << std::endl;
        } else {
            for (size_t i = 0; i < teamMembers.size(); ++i) { // Raw index loop
                if (teamMembers[i] != nullptr) { // Defensive check
                    teamMembers[i]->display();
                }
            }
        }
        std::cout << "--------------------" << std::endl;
    }

    // Destructor: Team does not own Employee memory, so no deletion.
    ~Team() {
        // No delete calls for teamMembers as Team does not own their memory.
    }
};

int main() {
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    Team devTeam;

    devTeam.addEmployee(&emp1);
    devTeam.addEmployee(&emp2);
    devTeam.addEmployee(&emp3);
    devTeam.addEmployee(&emp1); // Adding emp1 again to show the "already in team" message

    devTeam.displayTeam();

    // Employees are stack-allocated, no need to delete.
    return 0;
}