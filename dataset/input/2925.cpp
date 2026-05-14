#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

// Base class Person
class Person {
protected:
    std::string name;
    int age;

public:
    // Constructor for Person, uses const reference for string to avoid unnecessary copies
    Person(const std::string& n, int a) : name(n), age(a) {}
};

// Derived class Student
class Student : public Person {
private:
    std::string studentId;
    std::string major;

public:
    // Constructor for Student, calls Person's constructor and uses const references
    Student(const std::string& n, int a, const std::string& id, const std::string& m)
        : Person(n, a), studentId(id), major(m) {}

    // Method to display student details clearly
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
    std::string inputName;
    int inputAge;
    std::string inputStudentId;
    std::string inputMajor;

    std::cout << "Enter Person's Name: ";
    std::getline(std::cin, inputName);

    // Robust input for age
    while (true) {
        std::cout << "Enter Person's Age: ";
        std::cin >> inputAge;

        if (std::cin.fail() || inputAge < 0) { // Check for fail state and negative age
            std::cout << "Invalid age. Please enter a non-negative integer." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Valid input, consume the rest of the line (newline character)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // Exit the loop
        }
    }

    std::cout << "Enter Student ID: ";
    std::getline(std::cin, inputStudentId);

    std::cout << "Enter Student Major: ";
    std::getline(std::cin, inputMajor);

    // Create a Student object and display details
    Student student(inputName, inputAge, inputStudentId, inputMajor);
    student.displayDetails();

    return 0;
}