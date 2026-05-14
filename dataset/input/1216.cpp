#include <iostream>
#include <string>

// Person class definition
class Person {
public:
    std::string name;
protected:
    int age;
private:
    int id;

public:
    Person(std::string n, int a, int i) : name(n), age(a), id(i) {}

    void displayPersonName() const {
        std::cout << "Person Name: " << name << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

// Student class definition
class Student : public Person {
public:
    Student(std:string n, int a, int i) : Person(n, a, i) {} // SYNTAX ERROR: std:string instead of std::string

    void demonstrateStudentAccess() {
        std::cout << "\n--- Inside Student Method ---" << std::endl;
        std::cout << "Accessible: Student can access name (public): " << name << std::endl;
        std::cout << "Accessible: Student can access age (protected): " << age << std::endl;
        // Private member 'id' is not accessible here
        std::cout << "Inaccessible: Student cannot access id (private)." << std::endl;
    }
};

int main() {
    Student s("Alice", 20, 101);

    std::cout << "--- Outside Student Object ---" << std::endl;
    std::cout << "Accessible: Outside can access s.name (public): " << s.name << std::endl;
    // Protected member 'age' is not accessible directly from outside
    std::cout << "Inaccessible: Outside cannot access s.age (protected)." << std::endl;
    // Private member 'id' is not accessible directly from outside
    std::cout << "Inaccessible: Outside cannot access s.id (private)." << std::endl;

    s.demonstrateStudentAccess();

    return 0;
}