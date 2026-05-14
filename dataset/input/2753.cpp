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
    // Logical Error: The studentId is not initialized in the constructor's initializer list.
    // It will be default-initialized to 0, leading to incorrect output.
    Student(const std::string& n, int a, int id) : Person(n, a) {
        // studentId = id; // This line is missing, causing the logical error.
    }

    void printDetails() const override {
        Person::printDetails();
        std::cout << ", Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s1("Alice Smith", 20, 1001);
    std::cout << "Details for s1: ";
    s1.printDetails(); // Expected: Student ID: 1001, Actual: Student ID: 0

    Student s2("Bob Johnson", 22, 1002);
    std::cout << "Details for s2: ";
    s2.printDetails(); // Expected: Student ID: 1002, Actual: Student ID: 0

    return 0;
}