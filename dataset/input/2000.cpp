#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    std::string empName; // Slightly less descriptive name
    double empSalary;

public:
    // Readability/Efficiency Issue: Not using initializer list for empName and empSalary.
    // This leads to default construction of empName/empSalary, then assignment,
    // which is less efficient than direct initialization via initializer lists.
    Employee(std::string n, double s) { // Short, less descriptive parameter names
        empName = n; // Assignment
        empSalary = s; // Assignment
        // Redundant operation example: Could add a dummy print or calculation here
        if (empSalary < 0) { // Example of slightly verbose/redundant check if not enforced
            // This check isn't strictly necessary for the "issue" but adds to verbosity
        }
    }

    virtual void showInfo() const { // Less standard method name
        std::cout << "Worker: " << empName << ", Pay: $" << empSalary << std::endl; // Less standard output
    }
};

class Manager : public Employee {
private:
    std::string dept; // Short, less descriptive name

public:
    // Readability/Efficiency Issue: Not using initializer list for Employee base part and dept.
    Manager(std::string n, double s, std::string d) {
        empName = n; // Assignment to base member
        empSalary = s; // Assignment to base member
        dept = d; // Assignment
    }

    void showInfo() const override {
        std::cout << "Boss: " << empName << ", Pay: $" << empSalary
                  << ", Area: " << dept << std::endl;
    }
};

class Engineer : public Employee {
private:
    std::string spec; // Short, less descriptive name

public:
    // Readability/Efficiency Issue: Not using initializer list for Employee base part and spec.
    Engineer(std::string n, double s, std::string sp) {
        empName = n; // Assignment to base member
        empSalary = s; // Assignment to base member
        spec = sp; // Assignment
    }

    void showInfo() const override {
        std::cout << "Tech: " << empName << ", Pay: $" << empSalary
                  << ", Field: " << spec << std::endl;
    }
};

int main() {
    Employee e1("Alice Smith", 65000.0);
    Manager m1("Bob Johnson", 100000.0, "Marketing");
    Engineer eng1("Charlie Brown", 80000.0, "AI Research");

    std::cout << "--- Personnel Details ---" << std::endl;
    e1.showInfo();
    m1.showInfo();
    eng1.showInfo();

    // Demonstrate creating another object
    Employee e2("Diana Prince", 70000.0);
    e2.showInfo();

    return 0;
}