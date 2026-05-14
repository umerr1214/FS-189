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
        // Accessible: public member 'name'
        std::cout << "Accessible: Student can access name (public): " << name << std::endl;

        // Accessible: protected member 'age'
        std::cout << "Accessible: Student can access age (protected): " << age << std::endl;

        // SEMANTIC ERROR: Attempting to access private member 'id' from a Student method
        std::cout << "Attempting to access id (private): " << id << std::endl;
    }
};

int main() {
    Student s("Alice", 20, 101);

    std::cout << "--- Outside Student Object ---" << std::endl;
    // Accessible: public member 'name'
    std::cout << "Accessible: Outside can access s.name (public): " << s.name << std::endl;

    // SEMANTIC ERROR: Attempting to access protected member 'age' from outside Student object
    std::cout << "Attempting to access s.age (protected): " << s.age << std::endl;

    // SEMANTIC ERROR: Attempting to access private member 'id' from outside Student object
    std::cout << "Attempting to access s.id (private): " << s.id << std::endl;

    s.demonstrateStudentAccess();

    return 0;
}