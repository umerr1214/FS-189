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
    // No public method for SSN as it's private
}; // SYNTAX ERROR: Missing semicolon here

// A derived class to demonstrate access within a derived class
class Student : public Person {
public:
    Student(std::string n, int a, std::string s, std::string major) : Person(n, a, s) {
        // Derived class can access 'name' (public) and 'age' (protected)
        // but not 'ssn' (private)
    }

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
    // Attempting to access protected or private members directly will cause a compile-time error.
    // std::cout << "Inaccessible: Protected member 'age': " << p.age << std::endl;
    // std::cout << "Inaccessible: Private member 'ssn': " << p.ssn << std::endl;
    std::cout << "Note: Protected member 'age' is not accessible from outside the class." << std::endl;
    std::cout << "Note: Private member 'ssn' is not accessible from outside the class." << std::endl;

    Student s("Bob", 22, "987-65-4321", "Computer Science");
    s.demonstrateDerivedAccess();

    return 0;
}