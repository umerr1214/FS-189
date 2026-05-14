#include <iostream>
#include <string>

class Person {
public:
    std::string name;
protected:
    int age;
private:
    std::string socialSecurityNumber;

public:
    Person(std::string n, int a, std::string ssn) : name(n), age(a), socialSecurityNumber(ssn) {}

    void displayPersonInfo() {
        std::cout << "Person Name: " << name << std::endl;
        std::cout << "Person Age: " << age << std::endl;
        // Accessing socialSecurityNumber here is fine (within its own class)
        // std::cout << "Person SSN: " << socialSecurityNumber << std::endl;
    }

    std::string getSocialSecurityNumber() const {
        return socialSecurityNumber;
    }
};

class Student : public Person {
public:
    std::string studentId;

    Student(std::string n, int a, std::string ssn, std::string id)
        : Person(n, a, ssn), studentId(id) {}

    void displayStudentInfo() {
        std::cout << "\n--- Student Info (from Student class) ---" << std::endl;
        std::cout << "Accessing public member 'name': " << name << std::endl; // Accessible (public)
        std::cout << "Accessing protected member 'age': " << age << std::endl; // Accessible (protected in derived class)
        std::cout << "Student ID: " << studentId << std::endl;

        // Logical Error: The explanation below incorrectly states that socialSecurityNumber is accessible.
        // Private members are NOT accessible from derived classes.
        std::cout << "Attempting to access private member 'socialSecurityNumber': " << "Accessible from Student class because it's part of the base class." << std::endl;
        // Actual access would cause a semantic error:
        // std::cout << socialSecurityNumber << std::endl;
    }
};

int main() {
    Student s("Bob Johnson", 22, "987-65-4321", "S1002");

    std::cout << "--- Access from main function ---" << std::endl;
    std::cout << "Accessing public member 'name': " << s.name << std::endl; // Accessible (public)

    std::cout << "Attempting to access protected member 'age': Not accessible directly from main (outside derived class)." << std::endl;
    // s.age; // Would be a semantic error if uncommented

    std::cout << "Attempting to access private member 'socialSecurityNumber': Not accessible directly from main." << std::endl;
    // s.socialSecurityNumber; // Would be a semantic error if uncommented

    s.displayStudentInfo();

    return 0;
}