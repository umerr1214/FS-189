#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr for heap objects

class Employee {
private:
    std::string name;
    int employeeId;

public:
    // Robustness Issue: Default constructor initializes members to default/potentially invalid values.
    // This allows creating objects in a state that might not be fully "ready" or valid,
    // and displayInfo() will print these potentially invalid values without checks.
    // An employeeId of 0 is often considered an invalid ID in real systems.
    Employee() : name(""), employeeId(0) {
        std::cout << "Employee default constructor called." << std::endl;
    }

    Employee(const std::string& n, int id) : name(n), employeeId(id) {
        std::cout << "Employee parameterized constructor called for " << name << "." << std::endl;
    }

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", ID: " << employeeId;
    }

    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    std::string department;

public:
    // Robustness Issue: Default constructor for Manager
    Manager() : Employee(), department("") { // Default department to empty string
        std::cout << "Manager default constructor called." << std::endl;
    }

    Manager(const std::string& n, int id, const std::string& dept)
        : Employee(n, id), department(dept) {
        std::cout << "Manager parameterized constructor called for " << n << "." << std::endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Department: " << department;
    }
};

class Engineer : public Employee {
private:
    std::string specialization;

public:
    // Robustness Issue: Default constructor for Engineer
    Engineer() : Employee(), specialization("") { // Default specialization to empty string
        std::cout << "Engineer default constructor called." << std::endl;
    }

    Engineer(const std::string& n, int id, const std::string& spec)
        : Employee(n, id), specialization(spec) {
        std::cout << "Engineer parameterized constructor called for " << n << "." << std::endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Specialization: " << specialization;
    }
};

int main() {
    // Robustness Issue Demonstration:
    // Creating an object with a default constructor and displaying its default/potentially invalid state.
    // The program doesn't prevent creating such objects or validate their state before display.
    Employee uninitializedEmployee;
    std::cout << "--- Displaying default-constructed Employee ---" << std::endl;
    uninitializedEmployee.displayInfo(); // Will print Name: , ID: 0, which might be an invalid state
    std::cout << std::endl << std::endl;

    std::cout << "--- Displaying initialized objects ---" << std::endl;
    std::vector<std::unique_ptr<Employee>> staffMembers;

    staffMembers.push_back(std::make_unique<Employee>("John Doe", 101));
    staffMembers.push_back(std::make_unique<Manager>("Jane Smith", 202, "HR"));
    staffMembers.push_back(std::make_unique<Engineer>("Peter Jones", 303, "AI"));

    for (const auto& member : staffMembers) {
        member->displayInfo();
        std::cout << std::endl;
    }

    // std::unique_ptr automatically handles memory deallocation.
    return 0;
}