#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Included but not heavily utilized, which is okay

// Using namespace std; for brevity, a readability concern in larger projects
using namespace std;

class Employee {
public:
    string nameOfEmployee; // Slightly verbose variable name
    int employeeIdNumber;  // Slightly verbose variable name

    Employee(string nm, int id) : nameOfEmployee(nm), employeeIdNumber(id) {}

    void showDetails() { // Method not marked const, even though it doesn't modify the object
        cout << "  ID: " << employeeIdNumber << ", Name: " << nameOfEmployee << endl;
    }
};

class Department {
public:
    string deptName;
    vector<Employee> employeeCollection; // Slightly less descriptive name for the collection

    Department(string dName) : deptName(dName) {}

    // Efficiency Issue: Takes Employee object by value, causing an unnecessary copy
    void addEmployee(Employee empObject) {
        employeeCollection.push_back(empObject); // Copying empObject here
        cout << "Employee added: " << empObject.nameOfEmployee << " (ID: " << empObject.employeeIdNumber << ")" << endl;
    }

    void listAllStaff() { // Method not marked const, even though it doesn't modify the object
        cout << "Staff in " << deptName << ":" << endl;
        if (employeeCollection.empty()) { // Basic check, but still not ideal without const
            cout << "  No staff members." << endl;
            return;
        }
        for (auto& staffMember : employeeCollection) { // Iterating with auto& is good, but `const auto&` would be better
            staffMember.showDetails();
        }
    }
};

int main() {
    Department operationsDept("Operations");

    cout << "--- Adding Staff Members ---" << endl;
    Employee e1("Grace Hopper", 201);
    operationsDept.addEmployee(e1); // e1 is copied
    operationsDept.addEmployee(Employee("Alan Turing", 202)); // Temporary object is copied
    Employee e3("Ada Lovelace", 203);
    operationsDept.addEmployee(e3); // e3 is copied
    cout << endl;

    cout << "--- Listing Staff Members ---" << endl;
    operationsDept.listAllStaff();
    cout << endl;

    return 0;
}