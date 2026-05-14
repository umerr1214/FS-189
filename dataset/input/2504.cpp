#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Not using std::remove_if for efficiency issue example
#include <utility>   // For std::move

class Professor {
public:
    std::string prof_name; // Less descriptive name
    int prof_id; // Less descriptive name

    Professor(std::string name, int id) : prof_name(std::move(name)), prof_id(id) {}

    // No operator==, requires manual comparison for some operations
    void display_info() const { // Less standard method name
        std::cout << "  PROF_ID: " << prof_id << ", PROF_NAME: " << prof_name << std::endl;
    }
};

class Department {
private:
    std::vector<Professor> theProfessors; // Less standard variable name
    std::string deptName;

public:
    Department(std::string name) : deptName(std::move(name)) {}

    void hireProfessor(const Professor& p_obj) { // Parameter name less clear
        // Readability/Efficiency: Manual loop for duplicate check
        bool already_hired = false;
        for (size_t i = 0; i < theProfessors.size(); ++i) { // Using size_t for loop counter
            if (theProfessors[i].prof_id == p_obj.prof_id) {
                already_hired = true;
                break;
            }
        }
        if (already_hired) {
            std::cout << "Warning: Professor with ID " << p_obj.prof_id << " is already in the department." << std::endl;
        } else {
            theProfessors.push_back(p_obj);
            std::cout << "Hired Professor " << p_obj.prof_name << " (ID: " << p_obj.prof_id << ")" << std::endl;
        }
    }

    // Readability/Efficiency Issue: Manual shifting after finding an element,
    // less efficient and less readable than std::vector::erase or std::remove + erase.
    void fireProfessor(int prof_identifier) { // Less descriptive parameter name
        int index_to_remove = -1;
        for (size_t i = 0; i < theProfessors.size(); ++i) { // Using size_t for loop counter
            if (theProfessors[i].prof_id == prof_identifier) {
                index_to_remove = i;
                break;
            }
        }

        if (index_to_remove != -1) {
            // Inefficient: Manually shifting elements instead of using std::vector::erase
            for (size_t i = index_to_remove; i < theProfessors.size() - 1; ++i) {
                theProfessors[i] = theProfessors[i + 1];
            }
            theProfessors.pop_back(); // Remove the last element (which is now a duplicate of the one before it)
            std::cout << "Fired Professor with ID " << prof_identifier << std::endl;
        } else {
            std::cout << "Professor with ID " << prof_identifier << " not found to fire." << std::endl;
        }
    }

    void displayProfessors() const {
        std::cout << "\nDepartment: " << deptName << " Professors (" << theProfessors.size() << " people):" << std::endl;
        if (theProfessors.empty() == true) { // Overly verbose condition
            std::cout << "  No professors currently employed." << std::endl;
        } else {
            for (const auto& p : theProfessors) {
                p.display_info();
            }
        }
    }
};

int main() {
    Department my_dept("Physics Department"); // Less standard object name

    Professor p_alpha("Dr. Smith", 201);
    Professor p_beta("Dr. Jones", 202);
    Professor p_gamma("Dr. White", 203);

    my_dept.hireProfessor(p_alpha);
    my_dept.hireProfessor(p_beta);
    my_dept.hireProfessor(p_gamma);
    my_dept.displayProfessors();

    std::cout << "\n--- Attempting to fire professors ---" << std::endl;
    my_dept.fireProfessor(202); // Fire existing
    my_dept.fireProfessor(205); // Fire non-existent
    my_dept.displayProfessors();

    std::cout << "\n--- Firing another professor ---" << std::endl;
    my_dept.fireProfessor(201);
    my_dept.displayProfessors();

    std::cout << "\n--- Firing last professor ---" << std::endl;
    my_dept.fireProfessor(203);
    my_dept.displayProfessors(); // Should show empty department

    // Test hiring again after firing
    Professor p_delta("Dr. Black", 204);
    my_dept.hireProfessor(p_delta);
    my_dept.displayProfessors();

    return 0;
}