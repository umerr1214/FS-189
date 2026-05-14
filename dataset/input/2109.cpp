#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr (modern C++ best practice for ownership)

class Employee {
private:
    std::string name;
    int employeeId;

public:
    // Constructor uses initializer list and passes string by const reference for efficiency
    Employee(const std::string& name, int employeeId)
        : name(name), employeeId(employeeId) {}

    // Virtual display method, marked const as it doesn't modify object state
    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", ID: " << employeeId;
    }

    // Virtual destructor for proper polymorphic cleanup
    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    std::string department;

public:
    // Constructor uses initializer list and passes string by const reference
    Manager(const std::string& name, int employeeId, const std::string& department)
        : Employee(name, employeeId), department(department) {}

    // Overrides base class method, marked const, and calls base method to avoid code duplication
    void displayInfo() const override {
        Employee::displayInfo(); // Call base class method for inherited info
        std::cout << ", Department: " << department;
    }
};

class Engineer : public Employee {
private:
    std::string specialization;

public:
    // Constructor uses initializer list and passes string by const reference
    Engineer(const std::string& name, int employeeId, const std::string& specialization)
        : Employee(name, employeeId), specialization(specialization) {}

    // Overrides base class method, marked const, and calls base method to avoid code duplication
    void displayInfo() const override {
        Employee::displayInfo(); // Call base class method for inherited info
        std::cout << ", Specialization: " << specialization;
    }
};

int main() {
    // Using std::vector of std::unique_ptr for proper memory management and polymorphism
    std::vector<std::unique_ptr<Employee>> staffMembers;

    // Create objects and add them to the vector using std::make_unique for safety
    staffMembers.push_back(std::make_unique<Employee>("John Doe", 101));
    staffMembers.push_back(std::make_unique<Manager>("Jane Smith", 202, "HR"));
    staffMembers.push_back(std::make_unique<Engineer>("Peter Jones", 303, "AI"));
    staffMembers.push_back(std::make_unique<Employee>("Alice Wonderland", 404));
    staffMembers.push_back(std::make_unique<Manager>("Bob The Builder", 505, "Construction"));
    staffMembers.push_back(std::make_unique<Engineer>("Charlie Chaplin", 606, "Comedy"));

    // Iterate and display information using polymorphism
    std::cout << "--- Displaying Staff Information ---" << std::endl;
    for (const auto& member : staffMembers) {
        member->displayInfo();
        std::cout << std::endl;
    }

    // std::unique_ptr automatically handles memory deallocation when they go out of scope,
    // ensuring no memory leaks and proper resource management.
    return 0;
}