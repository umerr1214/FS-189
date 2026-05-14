#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::any_of
#include <utility>   // For std::move

class Professor {
public:
    std::string name;
    int id;

    Professor(std::string name, int id) : name(std::move(name)), id(id) {}

    // For comparison by ID
    bool operator==(const Professor& other) const {
        return id == other.id;
    }

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::vector<Professor> professors;
    std::string deptName;

public:
    Department(std::string name) : deptName(std::move(name)) {}

    void hireProfessor(const Professor& prof) {
        // Simple check to prevent hiring same ID twice
        if (std::any_of(professors.begin(), professors.end(),
                        [&prof](const Professor& p){ return p.id == prof.id; })) {
            std::cout << "Error: Professor with ID " << prof.id << " already exists." << std::endl;
            return;
        }
        professors.push_back(prof);
        std::cout << "Hired Professor " << prof.name << " (ID: " << prof.id << ")" << std::endl;
    }

    // Robustness Issue: This method does not provide any explicit feedback (e.g., return bool or message)
    // if the professor with the given ID is not found. It silently does nothing in that case,
    // which can lead to incorrect assumptions by the calling code.
    void fireProfessor(int professorId) {
        auto it = professors.begin();
        while (it != professors.end()) {
            if (it->id == professorId) {
                it = professors.erase(it); // Erase and get the next valid iterator
                std::cout << "Fired Professor with ID " << professorId << std::endl;
                return; // Only fire one instance if found
            } else {
                ++it;
            }
        }
        // No message here if professor not found, which is the robustness issue.
    }

    void displayProfessors() const {
        std::cout << "\nDepartment: " << deptName << " Professors (" << professors.size() << "):" << std::endl;
        if (professors.empty()) {
            std::cout << "  No professors in this department." << std::endl;
            return;
        }
        for (const auto& prof : professors) {
            prof.display();
        }
    }
};

int main() {
    Department csDept("Computer Science");

    Professor p1("Alice Smith", 101);
    Professor p2("Bob Johnson", 102);
    Professor p3("Charlie Brown", 103);

    csDept.hireProfessor(p1);
    csDept.hireProfessor(p2);
    csDept.hireProfessor(p3);
    csDept.displayProfessors();

    std::cout << "\n--- Attempting to fire professors ---" << std::endl;
    csDept.fireProfessor(102); // Fire existing
    csDept.fireProfessor(105); // Fire non-existent (silent failure)
    csDept.displayProfessors();

    std::cout << "\n--- Firing another professor ---" << std::endl;
    csDept.fireProfessor(101);
    csDept.displayProfessors();

    std::cout << "\n--- Firing last professor ---" << std::endl;
    csDept.fireProfessor(103);
    csDept.displayProfessors(); // Should show empty department

    // Test hiring again after firing
    Professor p4("Diana Prince", 104);
    csDept.hireProfessor(p4);
    csDept.displayProfessors();

    return 0;
}