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
};

class Student : public Person {
public:
    std::string studentId;

    // Logical Error: The age passed to the Person constructor is hardcoded to 18,
    // ignoring the 'a' parameter provided to the Student constructor.
    Student(std::string n, int a, std::string id) : Person(n, 18), studentId(id) {}

    void display() const {
        Person::display();
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s("Bob", 22, "S67890"); // Expect age 22, but will get 18 due to logical error
    s.display();
    return 0;
}