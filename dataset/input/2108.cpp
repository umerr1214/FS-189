#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

using namespace std; // Readability Issue: Global using directive

class Employee {
private:
    string name;
    int employeeId;

public:
    // Efficiency Issue: Passing string by value, causes unnecessary copy
    Employee(string n, int id) : name(n), employeeId(id) {}

    // Readability Issue: Getters not marked const
    string getName() { return name; }
    int getId() { return employeeId; }

    // Readability Issue: displayInfo not marked const
    virtual void displayInfo() {
        cout << "Name: " << name << ", ID: " << employeeId;
    }

    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    string department;

public:
    // Efficiency Issue: Passing string by value
    Manager(string n, int id, string dept)
        : Employee(n, id), department(dept) {}

    // Readability/Efficiency Issue: Does not call base class displayInfo(),
    // instead duplicates logic by using getters to print inherited info.
    // Also, not marked const.
    void displayInfo() override { // Indentation slightly off here
        cout << "Name: " << getName() << ", ID: " << getId(); // Duplicated logic from Employee::displayInfo
        cout << ", Department: " << department;
    }
};

class Engineer : public Employee {
private:
    string specialization;

public:
    // Efficiency Issue: Passing string by value
    Engineer(string n, int id, string spec)
        : Employee(n, id), specialization(spec) {}

    // Readability/Efficiency Issue: Does not call base class displayInfo(),
    // instead duplicates logic by using getters to print inherited info.
    // Also, not marked const.
    void displayInfo() override { // Indentation slightly off here
        cout << "Name: " << getName() << ", ID: " << getId(); // Duplicated logic from Employee::displayInfo
        cout << ", Specialization: " << specialization;
    }
};

int main() {
    // Readability Issue: Short, less descriptive variable names
    vector<unique_ptr<Employee>> staff;

    staff.push_back(make_unique<Employee>("John Doe", 101));
    staff.push_back(make_unique<Manager>("Jane Smith", 202, "HR"));
    staff.push_back(make_unique<Engineer>("Peter Jones", 303, "AI"));
    staff.push_back(make_unique<Employee>("Alice Wonderland", 404));
    staff.push_back(make_unique<Manager>("Bob The Builder", 505, "Construction"));
    staff.push_back(make_unique<Engineer>("Charlie Chaplin", 606, "Comedy"));

    cout << "--- Displaying Staff Information ---" << endl;
    for (const auto& p : staff) { // 'p' is a short variable name
        p->displayInfo();
        cout << endl;
    }

    return 0;
}