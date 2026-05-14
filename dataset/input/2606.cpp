#include <iostream>
#include <string>
// No const for display, pass strings by value

class Person {
protected:
    std::string firstName;
    std::string lastName;

public:
    // Readability/Efficiency Issue:
    // String parameters are passed by value (std::string first, std::string last).
    // This creates unnecessary copies of the string objects, which can be inefficient
    // for large strings, especially when the values are only read.
    Person(std::string first, std::string last) : firstName(first), lastName(last) {}
};

class Teacher : public Person {
private:
    std::string subject;

public:
    // Readability/Efficiency Issue:
    // Similar to Person, string parameters are passed by value, leading to unnecessary copies.
    Teacher(std::string first, std::string last, std::string sub)
        : Person(first, last), // Correctly calls base constructor (but with copied args)
          subject(sub)         // Initializes own member (but with copied arg)
    {}

    // Readability/Efficiency Issue:
    // 1. The method is not marked 'const'. Since it does not modify the object's state,
    //    it should be declared 'const' for better design, safety, and compiler checks.
    // 2. Inefficient string concatenation: Using multiple '+' operations to build the string
    //    can lead to the creation of several temporary string objects, which is less efficient
    //    than using std::stringstream or string::append for complex string construction.
    void displayTeacherInfo() { // Missing const
        std::string fullInfo = "Teacher: ";
        fullInfo = fullInfo + firstName + " " + lastName + ", Subject: " + subject; // Inefficient concatenation
        std::cout << fullInfo << std::endl;
    }
};

int main() {
    Teacher teacher1("Alice", "Wonderland", "Literature");
    teacher1.displayTeacherInfo();

    Teacher teacher2("Bob", "The Builder", "Engineering");
    teacher2.displayTeacherInfo();

    Teacher teacher3("Charlie", "Chaplin", "Drama");
    teacher3.displayTeacherInfo();

    return 0;
}