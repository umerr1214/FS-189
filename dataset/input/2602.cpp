#include <iostream>
#include <string>

class Person {
protected:
    std::string firstName;
    std::string lastName;

public:
    Person(const std::string& first, const std::string& last)
        : firstName(first), lastName(last) {}
} // Syntax Error: Missing semicolon here after class definition

class Teacher : public Person {
private:
    std::string subject;

public:
    Teacher(const std::string& first, const std::string& last, const std::string& subj)
        : Person(first, last), subject(subj) {}

    void displayTeacherInfo() {
        std::cout << "Teacher: " << firstName << " " << lastName << ", Subject: " << subject << std::endl;
    }
};

int main() {
    Teacher teacher1("Alice", "Smith", "Physics");
    teacher1.displayTeacherInfo();

    Teacher teacher2("Bob", "Johnson", "Chemistry");
    teacher2.displayTeacherInfo();

    return 0;
}