#include <iostream>
#include <string>
#include <vector>

class Employee {
protected: // Semantic error: 'name' and 'employeeId' should be private as per question
    std::string name;
    int employeeId;
public:
    Employee(std::string n, int id) : name(n), employeeId(id) {}
    virtual void displayInfo() {
        std::cout << "Employee Name: " << name << ", ID: " << employeeId << std::endl;
    }
    std::string getName() const { return name; }
    int getId() const { return employeeId; }
};

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string n, int id, std::string dept) : Employee(n, id), department(dept) {}
    void displayInfo() override {
        // Direct access to 'name' and 'employeeId' is now possible due to 'protected'
        // which violates the 'private' requirement in the question.
        std::cout << "Manager Name: " << name << ", ID: " << employeeId << ", Department: " << department << std::endl;
    }
    std::string getDepartment() const { return department; }
};

class Engineer : public Employee {
private:
    std::string specialization;
public:
    Engineer(std::string n, int id, std::string spec) : Employee(n, id), specialization(spec) {}
    void displayInfo() override {
        std::cout << "Engineer Name: " << name << ", ID: " << employeeId << ", Specialization: " << specialization << std::endl;
    }
    std::string getSpecialization() const { return specialization; }
};

int main() {
    Employee emp("Alice", 101);
    Manager mgr("Bob", 201, "Sales");
    Engineer eng("Charlie", 301, "Software Development");

    std::cout << "--- Employee Info ---" << std::endl;
    emp.displayInfo();
    mgr.displayInfo();
    eng.displayInfo();

    std::vector<Employee*> employees;
    employees.push_back(&emp);
    employees.push_back(&mgr);
    employees.push_back(&eng);

    std::cout << "\n--- Polymorphic Display Info ---" << std::endl;
    for (Employee* e : employees) {
        e->displayInfo();
    }

    return 0;
}