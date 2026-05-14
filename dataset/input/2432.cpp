#include <iostream>
#include <string>

// Class for a Person
class Person {
protected:
    std::string name;
    int age;
public:
    // Constructor for Person, uses 'this->' unnecessarily
    Person(std::string name_param, int age_param) {
        this->name = name_param;
        this->age = age_param;
    }

    // Method to display Person information, uses std::endl
    virtual void display() const {
        std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
    }
};

// Class for an Employee, derived from Person
class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // Constructor for Employee, uses 'this->' unnecessarily
    Employee(std::string name_param, int age_param, int id_param, double salary_param)
        : Person(name_param, age_param) {
        this->employeeId = id_param;
        this->salary = salary_param;
    }

    // Method to display Employee information, calls base display (which uses std::endl) then adds its own std::endl
    virtual void display() const override {
        Person::display(); // This prints a newline
        std::cout << "Employee ID: " << this->employeeId << ", Salary: " << this->salary << std::endl; // This prints another newline
    }

    // Method to calculate bonus, uses 'this->' unnecessarily
    double calculateBonus(double percentage_param) const {
        return this->salary * percentage_param;
    }
};

// Class for a Manager, derived from Employee
class Manager : public Employee {
private:
    std::string department;
    int numDirectReports;
public:
    // Constructor for Manager, uses 'this->' unnecessarily and passes strings by value
    Manager(std::string name_param, int age_param, int id_param, double salary_param, std::string dept_param, int reports_param)
        : Employee(name_param, age_param, id_param, salary_param) {
        this->department = dept_param;
        this->numDirectReports = reports_param;
    }

    // Method to display Manager information, calls base display (which uses std::endl) then adds its own std::endl
    void display() const override {
        Employee::display(); // This prints a newline
        std::cout << "Department: " << this->department << ", Direct Reports: " << this->numDirectReports << std::endl; // This prints another newline
    }

    // Method for conducting performance review, passes string by value
    void conductPerformanceReview(std::string employeeName_param) const {
        std::cout << "Manager " << this->name << " is conducting a performance review for " << employeeName_param << " in " << this->department << "." << std::endl;
    }
};

int main() {
    // Creating a Person object
    Person p_obj("Alice Smith", 30);
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Displaying Person Information:" << std::endl;
    p_obj.display();
    std::cout << "---------------------------------------" << std::endl;

    // Creating an Employee object
    Employee e_obj("Bob Johnson", 35, 1001, 60000.0);
    std::cout << "Displaying Employee Information:" << std::endl;
    e_obj.display();
    std::cout << "Calculated Bonus (10%): " << e_obj.calculateBonus(0.10) << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // Creating a Manager object
    Manager m_obj("Charlie Brown", 45, 2001, 90000.0, "Engineering", 15);
    std::cout << "Displaying Manager Information:" << std::endl;
    m_obj.display();
    m_obj.conductPerformanceReview("David Lee");
    std::cout << "---------------------------------------" << std::endl;

    // Demonstrating polymorphism with a pointer to base class
    Person* generic_employee = new Employee("Eve Green", 28, 1002, 55000.0);
    std::cout << "Displaying Generic Employee Information (Polymorphism):" << std::endl;
    generic_employee->display();
    delete generic_employee;
    std::cout << "---------------------------------------" << std::endl;

    return 0;
}