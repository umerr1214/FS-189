#include <iostream>
#include <string>
#include <utility> // For std::move

// Base class Person
class Person {
protected: // Protected members allow derived classes access but prevent direct external access
    std::string name;
    int age;

public:
    // Constructor for Person using initializer list for efficient initialization
    Person(std::string n, int a) : name(std::move(n)), age(a) {
        // Optional: Basic validation for age
        if (age < 0) {
            std::cerr << "Warning: Age cannot be negative. Setting to 0." << std::endl;
            this->age = 0;
        }
    }

    // Virtual destructor is good practice for base classes, especially when polymorphism is involved
    virtual ~Person() = default;

    // Display method to show person's information
    void displayPersonInfo() const {
        std::cout << "Person Name: " << name << ", Age: " << age << std::endl;
    }

    // Optional: Getters for protected members
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
};

// Derived class Teacher
class Teacher : public Person {
protected: // Protected members for Teacher as well
    std::string subject;
    double salary;

public:
    // Constructor for Teacher, efficiently calling Person's constructor via initializer list
    // and initializing its own members using initializer list.
    Teacher(std::string n, int a, std::string s, double sal)
        : Person(std::move(n), a), // Calls base class constructor
          subject(std::move(s)),   // Initializes subject
          salary(sal) {            // Initializes salary
        // Optional: Basic validation for salary
        if (salary < 0.0) {
            std::cerr << "Warning: Salary cannot be negative. Setting to 0.0." << std::endl;
            this->salary = 0.0;
        }
    }

    // Override the display method to show all teacher-specific information
    void displayTeacherInfo() const {
        Person::displayPersonInfo(); // Call base class method to display inherited members
        std::cout << "Subject: " << subject << ", Salary: $" << salary << std::endl;
    }

    // Optional: Getters for protected members
    const std::string& getSubject() const { return subject; }
    double getSalary() const { return salary; }
};

int main() {
    std::cout << "--- Correct Version Demonstration ---" << std::endl;

    // Create a Person object
    Person person1("Alice Smith", 30);
    person1.displayPersonInfo();

    std::cout << std::endl;

    // Create a Teacher object, demonstrating proper constructor call
    Teacher teacher1("Bob Johnson", 45, "Computer Science", 85000.75);
    teacher1.displayTeacherInfo();

    std::cout << std::endl;

    // Demonstrate with invalid initial values to show constructor validation (optional but good)
    Person person2("Eve Brown", -10); // Age will be set to 0
    person2.displayPersonInfo();

    std::cout << std::endl;

    Teacher teacher2("David Lee", 50, "Mathematics", -5000.00); // Salary will be set to 0.0
    teacher2.displayTeacherInfo();

    return 0;
}