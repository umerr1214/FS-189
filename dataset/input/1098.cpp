#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    // No default constructor for Person

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student : public Person {
public:
    std::string studentId;

    // Semantic Error: Student constructor fails to explicitly call a Person constructor.
    // Since Person only has a parameterized constructor and no default constructor,
    // this will result in a compilation error.
    Student(std::string n, int a, std::string id) : studentId(id) {
        // Base class Person's constructor is not called,
        // and its private members cannot be initialized here.
    }

    void display() const {
        // This method would cause undefined behavior if the object were created,
        // as base class members 'name' and 'age' would not be initialized.
        // However, the program won't compile due to the missing base constructor call.
        Person::display();
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s("Charlie", 21, "S98765");
    s.display();
    return 0;
}