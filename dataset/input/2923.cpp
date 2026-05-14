#include <iostream>
#include <string>
// No <limits> header needed if we don't use numeric_limits for ignore

// Base class Person
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}
    Person() : name(""), age(0) {} // Default constructor
};

// Derived class Student
class Student : public Person {
private:
    std::string studentId;
    std::string major;

public:
    Student(const std::string& n, int a, const std::string& id, const std::string& m)
        : Person(n, a), studentId(id), major(m) {}

    void displayDetails() const {
        std::cout << "--- Student Details ---" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Major: " << major << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
};

int main() {
    std::string nameInput;
    int ageInput;
    std::string studentIdInput;
    std::string majorInput;

    std::cout << "Enter Person's Name: ";
    std::getline(std::cin, nameInput);

    std::cout << "Enter Person's Age: ";
    std::cin >> ageInput; // Robustness issue: No input validation for age.
                          // If non-integer, cin fails, ageInput might be 0, and fail flag set.

    // If cin failed for age, the fail flag is set. Subsequent reads might fail or skip.
    // Specifically, if a non-integer was entered for age, the input buffer still contains the invalid input
    // and the newline. The next getline will try to read from a failed stream, leading to an empty string
    // for studentIdInput and majorInput. This is a clear robustness issue.

    std::cout << "Enter Student ID: ";
    std::getline(std::cin, studentIdInput); // This will likely read an empty string or fail if cin is in a bad state

    std::cout << "Enter Student Major: ";
    std::getline(std::cin, majorInput); // This will also likely read an empty string or fail

    Student s(nameInput, ageInput, studentIdInput, majorInput);
    s.displayDetails();

    return 0;
}