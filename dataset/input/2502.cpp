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
    // Destructor commented out to avoid confusing output or crashes related to stack object destruction order
    // ~Professor() { std::cout << "  Professor object '" << name << "' (ID: " << id << ") destroyed." << std::endl; }
};

class Department {
private:
    std::vector<Professor*> professors; // Stores pointers to Professor objects
    std::string departmentName;

public:
    Department(std::string name) : departmentName(std::move(name)) {}

    // Semantic Error: Takes Professor by value, then stores a pointer to a temporary object.
    // The temporary 'p' is destroyed when hireProfessor returns, leaving a dangling pointer.
    void hireProfessor(Professor p) { // 'p' is a temporary copy on the stack
        professors.push_back(&p); // Storing address of temporary 'p'. This pointer will dangle.
        std::cout << "Hired Professor (semantically incorrect): " << p.name << " (ID: " << p.id << ")" << std::endl;
    }

    void fireProfessor(int professorId) {
        auto it = professors.begin();
        while (it != professors.end()) {
            // Dereferencing a potentially dangling pointer to check ID, leads to UB
            if (*it && (*it)->id == professorId) {
                std::cout << "Fired Professor with ID: " << professorId << std::endl;
                // Department does not own these objects (they were stack allocated temporaries),
                // so no `delete` call here. The error is the dangling pointer itself.
                it = professors.erase(it);
                return;
            }
            ++it;
        }
        std::cout << "Professor with ID " << professorId << " not found." << std::endl;
    }

    void displayProfessors() const {
        std::cout << "Department: " << departmentName << std::endl;
        if (professors.empty()) {
            std::cout << "  No professors in this department." << std::endl;
            return;
        }
        for (const auto& p_ptr : professors) {
            // Dereferencing dangling pointers here will lead to undefined behavior (crash or garbage output)
            if (p_ptr) {
                p_ptr->display(); // This is where the crash/garbage is expected
            } else {
                std::cout << "  (Invalid Professor pointer - null)" << std::endl;
            }
        }
    }

    // Destructor: No `delete` calls here because objects were not dynamically allocated
    // by the Department, thus Department does not own them. This is consistent with
    // aggregation, but the `hireProfessor` method makes it a semantic error by storing
    // pointers to temporary stack objects.
    ~Department() {
        professors.clear();
        std::cout << "Department '" << departmentName << "' destroyed." << std::endl;
    }
};

int main() {
    Department csDept("Computer Science");

    Professor p1("Alice Smith", 101); // p1 is on main's stack
    csDept.hireProfessor(p1); // A copy of p1 is made, its address stored, then copy destroyed.
                              // The pointer inside csDept.professors[0] now points to invalid memory.

    Professor p2("Bob Johnson", 102); // p2 is on main's stack
    csDept.hireProfessor(p2); // Same for p2.

    std::cout << "\n--- Current Professors (expecting issues) ---" << std::endl;
    csDept.displayProfessors(); // Dereferences dangling pointers here.

    std::cout << "\n--- Firing Professor 102 ---" << std::endl;
    csDept.fireProfessor(102); // Removes the dangling pointer, but the underlying Professor object (p2) is still valid in main scope.

    std::cout << "\n--- Professors After Firing (more issues) ---" << std::endl;
    csDept.displayProfessors();

    // p1, p2 are destroyed here as main exits.
    // The Department destructor also runs.
    return 0;
}