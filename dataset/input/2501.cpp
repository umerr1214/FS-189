#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Professor {
public:
    std::string name;
    int id;

    Professor(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "  Professor ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::vector<Professor> professors;
    std::string departmentName;

public:
    Department(std::string name) : departmentName(std::move(name)) {}

    void hireProfessor(const Professor& p) {
        professors.push_back(p);
        std::cout << "Hired Professor: " << p.name << " (ID: " << p.id << ")" << std::endl;
    }

    // Logical Error: This method always removes the last professor, regardless of the ID.
    void fireProfessor(int professorId) {
        if (!professors.empty()) {
            std::cout << "Attempting to fire Professor with ID: " << professorId << std::endl;
            // Incorrect logic: always remove the last element
            Professor removed_p = professors.back(); // Store before popping to print
            professors.pop_back();
            std::cout << "Fired a professor (incorrectly, always the last one, which was " << removed_p.name << " ID: " << removed_p.id << ")." << std::endl;
        } else {
            std::cout << "No professors to fire in this department." << std::endl;
        }
    }

    void displayProfessors() const {
        std::cout << "Department: " << departmentName << std::endl;
        if (professors.empty()) {
            std::cout << "  No professors in this department." << std::endl;
            return;
        }
        for (const auto& p : professors) {
            p.display();
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

    std::cout << "\n--- Current Professors ---" << std::endl;
    csDept.displayProfessors();

    std::cout << "\n--- Firing Professor 102 (Bob) ---" << std::endl;
    csDept.fireProfessor(102); // Should remove Bob (ID 102)

    std::cout << "\n--- Professors After Firing ---" << std::endl;
    csDept.displayProfessors();

    std::cout << "\n--- Trying to fire non-existent Professor 999 ---" << std::endl;
    csDept.fireProfessor(999); // Should do nothing or report not found

    std::cout << "\n--- Final Professors ---" << std::endl;
    csDept.displayProfessors();

    return 0;
}