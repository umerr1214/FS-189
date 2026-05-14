#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::remove_if, std::any_of
#include <utility>   // For std::move

class Professor {
public:
    std::string name;
    int id;

    Professor(std::string name, int id) : name(std::move(name)), id(id) {}

    // For comparison by ID (assuming ID is unique identifier)
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
    std::string departmentName;

public:
    Department(std::string name) : departmentName(std::move(name)) {}

    // Hires a professor, ensuring no duplicate IDs are added.
    void hireProfessor(const Professor& prof) {
        // Check for existing professor with the same ID using std::any_of for efficiency and readability
        if (std::any_of(professors.begin(), professors.end(),
                        [&prof](const Professor& p){ return p.id == prof.id; })) {
            std::cout << "Error: Professor with ID " << prof.id << " is already in the department." << std::endl;
            return;
        }
        professors.push_back(prof);
        std::cout << "Hired Professor " << prof.name << " (ID: " << prof.id << ") to " << departmentName << std::endl;
    }

    // Fires a professor by ID, returns true if fired, false otherwise, providing clear feedback.
    bool fireProfessor(int professorId) {
        // Use std::remove_if to logically remove the professor, then erase physically.
        auto it = std::remove_if(professors.begin(), professors.end(),
                                 [professorId](const Professor& p){ return p.id == professorId; });

        if (it != professors.end()) { // If 'it' is not the end, a professor was found and "removed"
            professors.erase(it, professors.end()); // Physically erase the professor(s)
            std::cout << "Fired Professor with ID " << professorId << " from " << departmentName << std::endl;
            return true;
        } else {
            std::cout << "Error: Professor with ID " << professorId << " not found in " << departmentName << "." << std::endl;
            return false;
        }
    }

    // Displays all professors in the department, handling empty list gracefully.
    void displayProfessors() const {
        std::cout << "\n--- " << departmentName << " Department Professors (" << professors.size() << ") ---" << std::endl;
        if (professors.empty()) {
            std::cout << "  No professors currently in this department." << std::endl;
        } else {
            for (const auto& prof : professors) {
                prof.display();
            }
        }
        std::cout << "--------------------------------------" << std::endl;
    }
};

int main() {
    Department csDept("Computer Science");

    // Hire professors for CS
    Professor p1("Alice Smith", 101);
    Professor p2("Bob Johnson", 102);
    Professor p3("Charlie Brown", 103);

    csDept.hireProfessor(p1);
    csDept.hireProfessor(p2);
    csDept.hireProfessor(p3);
    csDept.hireProfessor(p1); // Attempt to hire duplicate ID, should show error
    csDept.displayProfessors();

    // Fire professors from CS
    std::cout << "\n--- Firing professors from Computer Science ---" << std::endl;
    csDept.fireProfessor(102); // Fire existing
    csDept.fireProfessor(105); // Fire non-existent, should show error
    csDept.displayProfessors();

    // Check state of CS after more operations
    csDept.hireProfessor(Professor("Frank White", 104));
    csDept.displayProfessors();

    std::cout << "\n--- Firing remaining professors ---" << std::endl;
    csDept.fireProfessor(101);
    csDept.fireProfessor(103);
    csDept.fireProfessor(104);
    csDept.displayProfessors(); // Should be empty

    return 0;
}