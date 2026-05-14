#include <iostream>
#include <string>
#include <vector> // Not strictly needed for this version, but often included.

// Readability/Efficiency Issue: using namespace std; is used globally.
using namespace std;

class Employee {
protected:
    string name;
    string employeeId;

public:
    // Readability/Efficiency Issue: Passing string parameters by value, incurring copies.
    Employee(string name, string employeeId)
        : name(name), employeeId(employeeId) {}

    virtual void displayInfo() const {
        // Readability/Efficiency Issue: Excessive use of std::endl, which flushes the buffer on each call.
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
    }
};

class Manager : public Employee {
private:
    string department;
    int teamSize;

public:
    // Readability/Efficiency Issue: Passing string parameters by value, incurring copies.
    Manager(string name, string employeeId, string department, int teamSize)
        : Employee(name, employeeId), department(department), teamSize(teamSize) {}

    // Overrides displayInfo to include manager-specific details
    void displayInfo() const override {
        // Readability/Efficiency Issue: Re-implementing base class logic instead of calling Employee::displayInfo().
        // This is redundant and less maintainable.
        cout << "Manager Name: " << name << endl;
        cout << "Manager ID: " << employeeId << endl;

        // Readability/Efficiency Issue: Multiple string concatenations and `endl` calls.
        // Building the string piecewise with `+` can be less efficient than a single output statement or stringstream.
        cout << "Manager Department: " + department + " (Team Size: " + to_string(teamSize) + ")" << endl;
        cout << "Special Note: Oversees operations." << endl; // Extra verbose line
    }
};

int main() {
    Employee emp1("Alice Wonderland", "EMP-001");
    Manager mgr1("Bob The Builder", "MGR-001", "Construction", 15);
    Manager mgr2("Charlie Chaplin", "MGR-002", "Entertainment", 5);

    cout << "--- Employee Details ---" << endl;
    emp1.displayInfo();
    cout << endl;

    cout << "--- Manager 1 Details ---" << endl;
    mgr1.displayInfo();
    cout << endl;

    cout << "--- Manager 2 Details ---" << endl;
    mgr2.displayInfo();
    cout << endl;

    return 0;
}