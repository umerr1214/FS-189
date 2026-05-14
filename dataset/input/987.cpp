#include <iostream>
#include <string>

class Person {
public:
    std::string name;
protected:
    int age;
private:
    std::string ssn;

public:
    Person(std::string n, int a, std::string s) : name(n), age(a), ssn(s) {}

    // Method to allow derived classes to access protected members (if needed for complex logic)
    int getAgeProtected() { return age; }
};

// A derived class to demonstrate access within a derived class
class Student : public Person {
public:
    Student(std::string n, int a, std::string s, std::string major) : Person(n, a, s) {}

    void demonstrateDerivedAccess() {
        std::cout << "--- Inside Derived Class (Student) ---" << std::endl;
        std::cout << "Accessible: Public member 'name': " << name << std::endl;
        std::cout << "Accessible: Protected member 'age': " << age << std::endl;
        // std::cout << "Inaccessible: Private member 'ssn': " << ssn << std::endl; // Would be a compile error
        std::cout << "Note: Private member 'ssn' is not accessible from a derived class." << std::endl;
    }
};

int main() {
    Person p("Alice", 30, "123-45-6789");

    std::cout << "--- Outside the Class (main function) ---" << std::endl;
    std::cout << "Accessible: Public member 'name': " << p.name << std::endl;
    // SEMANTIC ERROR: Attempting to access a protected member 'age' directly from outside the class.
    std::cout << "Attempting to access Protected member 'age': " << p.age << std::endl; // This line causes the semantic error.
    // std::cout << "Inaccessible: Private member 'ssn': " << p.ssn << std::endl; // Also a semantic error if uncommented
    std::cout << "Note: Private member 'ssn' is not accessible from outside the class." << std::endl;

    Student s("Bob", 22, "987-65-4321", "Computer Science");
    s.demonstrateDerivedAccess();

    return 0;
}