#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
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
    void displayInfo() override { // Logical error: Manager's department is not displayed
        std::cout << "Manager Name: " << getName() << ", ID: " << getId() << std::endl;
        // The department member is not printed here, violating the requirement.
    }
    std::string getDepartment() const { return department; }
};

class Engineer : public Employee {
private:
    std::string specialization;
public:
    Engineer(std::string n, int id, std::string spec) : Employee(n, id), specialization(spec) {}
    void displayInfo() override {
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
    mgr.displayInfo(); // This will not show the department
    eng.displayInfo();

    return 0;
}