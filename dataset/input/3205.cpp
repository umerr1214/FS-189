#include <iostream>
#include <string>
#include <utility> // For std::move

const int MAX_TEAM_MEMBERS = 3; // Small fixed size to easily demonstrate robustness issue

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
    Employee* teamMembers[MAX_TEAM_MEMBERS]; // Fixed-size raw array for team members
    int currentSize; // Tracks the number of members currently in the team

public:
    Team() : currentSize(0) {
        // Initialize all pointers in the array to nullptr
        for (int i = 0; i < MAX_TEAM_MEMBERS; ++i) {
            teamMembers[i] = nullptr;
        }
    }

    // Robustness Issue: This method does not check if `currentSize` exceeds
    // `MAX_TEAM_MEMBERS`. If more than MAX_TEAM_MEMBERS employees are added,
    // it will attempt to write past the end of the `teamMembers` array,
    // leading to a buffer overflow and undefined behavior (e.g., crash, data corruption).
    void addEmployee(Employee* emp) {
        if (emp != nullptr) {
            // CRITICAL ROBUSTNESS FLAW: No bounds check here.
            // If currentSize >= MAX_TEAM_MEMBERS, this will write out of bounds.
            teamMembers[currentSize] = emp;
            currentSize++;
            std::cout << "Added employee " << emp->name << " to team." << std::endl;
        } else {
            std::cout << "Cannot add a null employee pointer." << std::endl;
        }
    }

    void displayTeam() const {
        std::cout << "\n--- Team Members ---" << std::endl;
        if (currentSize == 0) {
            std::cout << "No members in the team." << std::endl;
        } else {
            for (int i = 0; i < currentSize; ++i) {
                // Defensive check, though addEmployee ensures non-null if added
                if (teamMembers[i] != nullptr) {
                    teamMembers[i]->display();
                }
            }
        }
        std::cout << "--------------------" << std::endl;
    }

    // Destructor: The Team class does NOT own the memory of the Employee objects.
    // Therefore, it should NOT delete the pointers stored in `teamMembers`.
    // The responsibility for deleting heap-allocated Employee objects (if any)
    // lies with the code that created them.
    ~Team() {
        // No delete calls here, as per problem statement.
    }
};

int main() {
    // Create Employee objects on the stack.
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);
    Employee emp4("David", 104); // This employee will cause the buffer overflow

    Team devTeam;

    devTeam.addEmployee(&emp1);
    devTeam.addEmployee(&emp2);
    devTeam.addEmployee(&emp3);
    devTeam.addEmployee(&emp4); // This call will trigger the robustness issue

    devTeam.displayTeam(); // Output might be corrupted or the program might have crashed by now

    // emp1, emp2, emp3, emp4 are stack-allocated and will be cleaned up automatically.
    return 0;
}