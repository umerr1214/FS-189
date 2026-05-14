#include <iostream>
#include <string>

class Person {
protected:
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
        // Logical Error: This method only displays the student ID,
        // failing to display the inherited 'name' and 'age' as required by the question.
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    Student s("Bob Johnson", 22, "S67890");
    s.displayDetails();
    return 0;
}