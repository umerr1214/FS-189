#include <iostream>
#include <string>

class Person {
public:
    std::string name;
protected:
    int age;
private:
    int id; // Private member

public:
    Person(std::string n, int a, int i) : name(n), age(a), id(i) {}

    void displayPersonName() const {
        std::cout << "Person Name: " << name << std::endl;
    }
};

class Student : public Person {
public:
    Student(std::string n, int a, int i) : Person(n, a, i) {}

    void demonstrateStudentAccess() {
        std::cout << "\n--- Inside Student Method ---" << std::endl;
        // Correctly accessing public member 'name'
        std::cout << "Accessible: Student can access name (public): " << name << std::endl;

        // Correctly accessing protected member 'age'
        std::cout << "Accessible: Student can access age (protected): " << age << std::endl;

        // LOGICAL ERROR: Claims 'id' is accessible, but it's private and cannot be accessed.
        // The program compiles because it's just printing a static string, not actually accessing 'id'.
        std::cout << "Demonstration Error: Student claims it can access id (private), but this is logically incorrect." << std::endl;
    }
};

int main() {
    Student s("Alice", 20, 101);

    std::cout << "--- Outside Student Object ---" << std::endl;
    // Correctly accessing public member 'name'
    std::cout << "Accessible: Outside can access s.name (public): " << s.name << std::endl;

    // LOGICAL ERROR: Claims 'age' is accessible from outside, but it's protected and cannot be.
    // The program compiles because it's just printing a static string, not actually accessing 's.age'.
    std::cout << "Demonstration Error: Outside claims it can access s.age (protected), but this is logically incorrect." << std::endl;

    // LOGICAL ERROR: Claims 'id' is accessible from outside, but it's private and cannot be.
    // The program compiles because it's just printing a static string, not actually accessing 's.id'.
    std::cout << "Demonstration Error: Outside claims it can access s.id (private), but this is logically incorrect." << std::endl;

    s.demonstrateStudentAccess();

    return 0;
}