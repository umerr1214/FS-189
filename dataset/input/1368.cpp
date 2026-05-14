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

        // Semantic Error: Attempting to access private member 'socialSecurityNumber' from derived class
        // Private members are NOT accessible even in derived classes.
        std::cout << "Attempting to access private member 'socialSecurityNumber': " << socialSecurityNumber << std::endl;
    }
};

int main() {
    Student s("Charlie Green", 21, "111-22-3333", "S1003");

    std::cout << "--- Access from main function ---" << std::endl;
    std::cout << "Accessing public member 'name': " << s.name << std::endl; // Accessible (public)

    // Attempting to access protected member 'age' from main
    // This would also be a semantic error if uncommented:
    // std::cout << "Attempting to access protected member 'age': " << s.age << std::endl;
    std::cout << "Attempting to access protected member 'age': Not accessible directly from main (outside derived class)." << std::endl;

    // Attempting to access private member 'socialSecurityNumber' from main
    // This would also be a semantic error if uncommented:
    // std::cout << "Attempting to access private member 'socialSecurityNumber': " << s.socialSecurityNumber << std::endl;
    std::cout << "Attempting to access private member 'socialSecurityNumber': Not accessible directly from main." << std::endl;

    s.displayStudentInfo();

    return 0;
}