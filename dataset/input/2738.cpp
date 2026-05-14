#include <iostream>
#include <string>
#include <vector>

// Base class Employee
class Employee {
protected:
    std::string employeeName; // Readability: overly verbose name
    int employeeId;
public:
    // Efficiency Issue: Passing strings by value, causing unnecessary copies.
    Employee(std::string employeeName, int employeeId) : employeeName(employeeName), employeeId(employeeId) {}
    
    // Readability Issue: Missing virtual destructor for a polymorphic base class.
    ~Employee() = default;

    // Readability Issue: Not marked const, even though it doesn't modify the object's state.
    // Made virtual to allow polymorphism, but derived classes miss 'override' and 'const'.
    virtual void printDetails() { // Missing const
        std::cout << "Name of employee: " << employeeName << ", ID number: " << employeeId;
    }
};

// Derived class Manager
class Manager : public Employee {
private:
    std::string deptName; // Readability: less descriptive name
public:
    // Efficiency Issue: Passing strings by value.
    Manager(std::string name, int id, std::string department)
        : Employee(name, id), deptName(department) {}

    // Readability Issue: Missing const and override keyword.
    // Readability/Efficiency Issue: Re-implements base class logic instead of calling base method.
    void printDetails() { // Missing const, missing override
        std::cout << "Name of employee: " << employeeName << ", ID number: " << employeeId; // Redundant base info print
        std::cout << ", Department area: " << deptName << std::endl;
    }
};

// Derived class Worker
class Worker : public Employee {
private:
    double ratePerHour; // Readability: less descriptive name
public:
    // Efficiency Issue: Passing strings by value.
    Worker(std::string name, int id, double hourlyRate)
        : Employee(name, id), ratePerHour(hourlyRate) {}

    // Readability Issue: Missing const and override keyword.
    // Readability/Efficiency Issue: Re-implements base class logic instead of calling base method.
    void printDetails() { // Missing const, missing override
        std::cout << "Name of employee: " << employeeName << ", ID number: " << employeeId; // Redundant base info print
        std::cout << ", Hourly rate for worker: " << ratePerHour << std::endl;
    }
};

int main() {
    std::vector<Employee*> staff;

    staff.push_back(new Manager("Sarah Connor", 1001, "Research & Development"));
    staff.push_back(new Worker("John Doe", 2002, 18.75));
    staff.push_back(new Manager("Jane Smith", 1003, "Human Resources"));
    staff.push_back(new Worker("Peter Jones", 2004, 22.50));

    std::cout << "--- Staff Details ---" << std::endl;
    for (Employee* emp : staff) {
        // This will correctly call the derived printDetails due to base being virtual,
        // but derived methods are not marked const/override which is a readability issue.
        emp->printDetails();
    }
    std::cout << "---------------------" << std::endl;

    // Cleanup (note: still has non-virtual destructor issue, which is a minor quality/robustness point)
    for (Employee* emp : staff) {
        delete emp;
    }

    return 0;
}