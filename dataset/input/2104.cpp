#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    int employeeId;
public:
    Employee(std::string n, int id) : name(n), employeeId(id) {}
    void displayInfo() {
        std::cout << "Employee Name: " << name << ", ID: " << employeeId << std::endl;
    }
    std::string getName() const { return name; }
    int getId() const { return employeeId; }
};

class Manager : public Employee {
private:
    std::string department // Missing semicolon here, causing a syntax error
public:
    Manager(std::string n, int id, std::string dept) : Employee(n, id), department(dept) {}
    void displayInfo() {
        std::cout << "Manager Name: " << getName() << ", ID: " << getId() << ", Department: " << department << std::endl;
    }
    std::string getDepartment() const { return department; }
};

class Engineer : public Employee {
private:
    std::string specialization;
public:
    Engineer(std::string n, int id, std::string spec) : Employee(n, id), specialization(spec) {}
    void displayInfo() {
        std::cout << "Engineer Name: " << getName() << ", ID: " << getId() << ", Specialization: " << specialization << std::endl;
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

    return 0;
}