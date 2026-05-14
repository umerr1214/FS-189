#include <iostream>
#include <string>
#include <vector>

// Base class Person
class Person {
private:
    std::string nm_val; // Poor attribute naming for consistency
    int ag_val;         // Poor attribute naming

public:
    // Default constructor
    Person() : nm_val(""), ag_val(0) {}

    // Constructor
    Person(std::string name_in, int age_in) : nm_val(name_in), ag_val(age_in) {} // String by value

    // Public methods to set details - poor naming, string by value
    void set_name_val(std::string new_nm) { // Pass string by value, poor name
        nm_val = new_nm;
    }

    void set_age_val(int new_ag) { // Poor name
        ag_val = new_ag;
    }

    // Public methods to display details - poor naming, missing const
    std::string get_nm_val() { // Missing const
        return nm_val;
    }

    int get_ag_val() { // Missing const
        return ag_val;
    }

    void disp_person_info() { // Poor name, missing const
        std::cout << "Name: " << nm_val << ", Age: " << ag_val;
    }
};

// Derived class Employee
class Employee : public Person {
private:
    int emp_id;     // Poor attribute naming
    double sal_amt; // Poor attribute naming

public:
    // Default constructor
    Employee() : Person(), emp_id(0), sal_amt(0.0) {}

    // Constructor
    Employee(std::string name_in, int age_in, int id_in, double sal_in)
        : Person(name_in, age_in), emp_id(id_in), sal_amt(sal_in) {} // String by value in base

    // Public methods to set specific details - poor naming
    void set_emp_id(int new_id) { // Poor name
        emp_id = new_id;
    }

    void set_sal_amt(double new_sal) { // Poor name
        sal_amt = new_sal;
    }

    // Public methods to display specific details - poor naming, missing const
    int get_emp_id() { // Missing const
        return emp_id;
    }

    double get_sal_amt() { // Missing const
        return sal_amt;
    }

    // Display method for Employee, including inherited details - poor naming, missing const
    void disp_employee_data() { // Poor name, missing const
        disp_person_info(); // Call base class display (also missing const)
        std::cout << ", Employee ID: " << emp_id << ", Salary: " << sal_amt << std::endl;
    }
};

// Driver code for testing
int main() {
    std::cout << "--- Testing Readability / Efficiency Issue (1796) ---" << std::endl;

    // Test case 1: Person object
    Person p1;
    p1.set_name_val("Alice Smith");
    p1.set_age_val(30);
    std::cout << "Person 1 Details: ";
    p1.disp_person_info();
    std::cout << std::endl;

    // Test case 2: Employee object
    Employee e1;
    e1.set_name_val("Bob Johnson"); // Using poorly named base method
    e1.set_age_val(25);           // Using poorly named base method
    e1.set_emp_id(1001);
    e1.set_sal_amt(50000.0);
    std::cout << "Employee 1 Details: ";
    e1.disp_employee_data();

    // Test case 3: Employee object with constructor
    Employee e2("Charlie Brown", 40, 1002, 75000.0);
    std::cout << "Employee 2 Details (from constructor): ";
    e2.disp_employee_data();

    std::cout << "Note: Code uses non-descriptive names, passes strings by value, and lacks const-correctness." << std::endl;

    return 0;
}