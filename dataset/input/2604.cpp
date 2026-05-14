#include <iostream>
#include <string>
#include <vector> // For simple resource demo

class Person {
protected:
    std::string firstName;
    std::string lastName;

public:
    Person(const std::string& first, const std::string& last)
        : firstName(first), lastName(last) {}

    // Semantic Error: Base class destructor is not virtual.
    // This can lead to undefined behavior (e.g., resource leaks)
    // if a derived class object is deleted through a base class pointer.
    ~Person() {
        // In a real scenario, if Person had resources or Teacher had resources,
        // only Person's destructor would be called, not Teacher's.
    }
};

class Teacher : public Person {
private:
    std::string subject;
    // Dummy dynamic resource to make the non-virtual destructor issue concrete
    std::vector<int>* grades; // A simple dynamic resource

public:
    Teacher(const std::string& first, const std::string& last, const std::string& subj)
        : Person(first, last), subject(subj) {
        grades = new std::vector<int>(); // Allocate resource
        grades->push_back(90); // Add some dummy data
    }

    void displayTeacherInfo() {
        std::cout << "Teacher: " << firstName << " " << lastName << ", Subject: " << subject << std::endl;
    }

    ~Teacher() {
        delete grades; // Deallocate resource
        grades = nullptr;
    }
};

int main() {
    Teacher teacher1("Alice", "Smith", "Physics");
    teacher1.displayTeacherInfo();

    Teacher teacher2("Bob", "Johnson", "Chemistry");
    teacher2.displayTeacherInfo();

    return 0;
}