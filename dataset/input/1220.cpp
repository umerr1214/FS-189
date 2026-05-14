#include <iostream>
#include <string>
// No headers for advanced data structures, but could add some for no reason.

// Readability / Efficiency Issue:
// - Inefficient string passing by value in constructors.
// - Redundant 'this->' usage.
// - Overly verbose and inconsistent naming for getter methods.
// - Unnecessary getter for a public member.
// - Using `std::endl` instead of `\n` for simple newlines, leading to unnecessary stream flushes.
class Person {
public:
    std::string name; // Public member
protected:
    int age; // Protected member
private:
    int id; // Private member

public:
    // Constructor: Passes strings by value (inefficient copy) and uses redundant 'this->'
    Person(std::string name_param, int age_param, int id_param) { // 'name_param' is copied
        this->name = name_param; // Redundant 'this->' and another copy
        this->age = age_param;
        this->id = id_param;
    }

    // Unnecessary getter for 'name' which is already public
    std::string getThePersonsName() const { return this->name; } // Redundant 'this->', verbose name

    // Getter for private 'id' with verbose name
    int getThePersonsIDValue() const { return id; }

    // Getter for protected 'age' with verbose name
    int getThePersonsAgeValue() const { return age; }
};

class Student : public Person {
public:
    std::string studentMajor; // Public member specific to Student

    // Constructor: Passes string by value (inefficient copy) and uses redundant 'this->'
    Student(std::string student_name, int student_age, int student_id, std::string student_major_field) // 'student_name' and 'student_major_field' are copied
        : Person(student_name, student_age, student_id) { // 'student_name' is copied again to Person's constructor
        this->studentMajor = student_major_field; // Redundant 'this->' and another copy
    }

    // Method to demonstrate member accessibility from within Student class with verbose output
    void showStudentInternalAccessDetails() {
        std::cout << "--- Inside Student method (showStudentInternalAccessDetails) ---" << std::endl; // Uses std::endl
        std::cout << "Accessible: Public Person::name = " << name << std::endl;
        std::cout << "Accessible: Protected Person::age = " << age << std::endl;
        // std::cout << "Inaccessible: Private Person::id" << std::endl; // Would be a compile-time error
        std::cout << "Accessible: Student::studentMajor = " << studentMajor << std::endl;
        std::cout << "Accessible: Person::getThePersonsIDValue() (via public method) = " << getThePersonsIDValue() << std::endl;
        std::cout << "Accessible: Person::getThePersonsAgeValue() (via public method) = " << getThePersonsAgeValue() << std::endl;
    }
};

// Function to demonstrate member accessibility from outside Student objects
void displayExternalStudentInfo(const Student& student_object_ref) { // Good: passes by const reference
    std::cout << "\n--- Outside Student object (displayExternalStudentInfo function) ---" << std::endl; // Uses std::endl
    std::cout << "Accessible: Public Student::name (inherited from Person) = " << student_object_ref.name << std::endl;
    // std::cout << "Inaccessible: Protected Person::age" << std::endl; // Would be a compile-time error
    // std::cout << "Inaccessible: Private Person::id" << std::endl; // Would be a compile-time error
    std::cout << "Accessible: Public Student::studentMajor = " << student_object_ref.studentMajor << std::endl;
    std::cout << "Accessible: Person::getThePersonsIDValue() (via public method) = " << student_object_ref.getThePersonsIDValue() << std::endl;
    std::cout << "Accessible: Person::getThePersonsAgeValue() (via public method) = " << student_object_ref.getThePersonsAgeValue() << std::endl;
}

int main() {
    Student jane("Jane Doe", 22, 205, "Physics");
    jane.showStudentInternalAccessDetails();
    displayExternalStudentInfo(jane);

    return 0;
}