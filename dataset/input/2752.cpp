#include <iostream>
#include <string>

// Person class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    // A public method to print for Person, for demonstration
    virtual void printDetails() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
}; // Missing semicolon here, which is a common syntax error

// Student class derived from Person
class Student : public Person {
private:
    int studentId;

public:
    Student(const std::string& n, int a, int id) : Person(n, a), studentId(id) {}

    // Method to print full details including studentId
    void printDetails() const override {
        Person::printDetails(); // Call base class method
        std::cout << ", Student ID: " << studentId << std::endl;
    }
};

int main() {
    // This code will not compile due to the syntax error
    Student s1("Alice Smith", 20, 1001);
    s1.printDetails();

    Student s2("Bob Johnson", 22, 1002);
    s2.printDetails();

    return 0;
}