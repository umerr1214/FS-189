#include <iostream>
#include <string>
#include <vecotr> // Syntax Error: Typo in header name
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

    void fireProfessor(int professorId) {
        auto it = std::remove_if(professors.begin(), professors.end(),
                                 [professorId](const Professor& p) {
                                     return p.id == professorId;
                                 });
        if (it != professors.end()) {
            std::cout << "Fired Professor with ID: " << professorId << std::endl;
            professors.erase(it, professors.end());
        } else {
            std::cout << "Professor with ID " << professorId << " not found." << std::endl;
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

    csDept.hireProfessor(p1);
    csDept.hireProfessor(p2);

    std::cout << "\n--- Current Professors ---" << std::endl;
    csDept.displayProfessors();

    std::cout << "\n--- Firing Professor 102 ---" << std::endl;
    csDept.fireProfessor(102);

    std::cout << "\n--- Professors After Firing ---" << std::endl;
    csDept.displayProfessors();

    return 0;
}