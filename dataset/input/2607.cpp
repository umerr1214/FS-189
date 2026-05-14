#include <iostream>
#include <string>
#include <sstream> // For efficient string building

class Person {
protected:
    std::string firstName;
    std::string lastName;

public:
    // Constructor uses const reference for string parameters to avoid unnecessary copies
    Person(const std::string& first, const std::string& last)
        : firstName(first), lastName(last) {}
};

class Teacher : public Person {
private:
    std::string subject;

public:
    // Constructor uses initializer list to correctly call the base class constructor
    // and initialize its own member.
    // Parameters are passed by const reference for efficiency.
    Teacher(const std::string& first, const std::string& last, const std::string& sub)
        : Person(first, last), // Correctly calls Person's constructor with initializer list
          subject(sub) {}      // Initializes own member with initializer list

    // Method to display teacher's info, marked const as it doesn't modify object state.
    // Uses stringstream for efficient and readable string construction, avoiding temporary string objects.
    void displayTeacherInfo() const {
        std::stringstream ss;
        ss << "Teacher: " << firstName << " " << lastName << ", Subject: " << subject;
        std::cout << ss.str() << std::endl;
    }
};

int main() {
    Teacher teacher1("Dr. Alan", "Turing", "Computer Science");
    teacher1.displayTeacherInfo();

    Teacher teacher2("Prof. Marie", "Curie", "Physics & Chemistry");
    teacher2.displayTeacherInfo();

    Teacher teacher3("Mr.", "Smith", "History");
    teacher3.displayTeacherInfo();

    // Test with empty names to ensure robust output formatting
    Teacher teacher4("Ms.", "", "Literature");
    teacher4.displayTeacherInfo();

    return 0;
}