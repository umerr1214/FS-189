#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

class Student : public Person {
public:
    std::string studentId;

    Student(std::string n, int a, std::string id) : Person(n, a), studentId(id) {}

    void display() const {
        Person::display();
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s("Alice", 20, "S12345");
    s.display();
    return 0;
}