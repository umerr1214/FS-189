#include <iostream>
#include <string>

class Person {
private: // Semantic Error: Changed from protected to private
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}
};

class Student : public Person {
private:
    std::string studentId;

public:
    Student(std::string n, int a, std::string id)
        : Person(n, a), studentId(id) {}

    void displayDetails() {
        // Semantic Error: Attempting to access private members 'name' and 'age'
        // from the base class 'Person'. Private members are not accessible to derived classes.
        std::cout << "Student Name: " << name << std::endl; // This line will cause a compile-time error
        std::cout << "Student Age: " << age << std::endl;  // This line will cause a compile-time error
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s("Charlie Brown", 21, "S98765");
    s.displayDetails();
    return 0;
}