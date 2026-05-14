#include <iostream>
#include <string>

// Person class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    virtual void printDetails() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// Student class derived from Person
class Student : public Person {
private:
    int studentId;

public:
    Student(const std::string& n, int a, int id) : Person(n, a), studentId(id) {}

    void printDetails() const override {
        Person::printDetails();
        std::cout << ", Student ID: " << studentId << std::endl;
    }
};

int main() {
    Person p1("Charlie Brown", 30);
    std::cout << "Details for p1: ";
    p1.printDetails();
    std::cout << std::endl;

    // Semantic Error: Attempting to access protected member 'name' directly from a non-derived class (main function).
    // This will result in a compilation error.
    std::cout << "Accessing name directly: " << p1.name << std::endl;

    Student s1("Diana Prince", 21, 1003);
    std::cout << "Details for s1: ";
    s1.printDetails();

    return 0;
}