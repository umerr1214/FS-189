#include <iostream>
#include <string>
#include <vector> // Included for the driver

class Student {
private:
    std::string name;
    int id;

public:
    static int totalStudents; // Correct type for the counter

    // Parameterized constructor:
    // 1. 'name_param' passed by 'const std::string&' to avoid unnecessary string copies (efficient).
    // 2. Uses an initializer list for member initialization (efficient and idiomatic C++).
    Student(const std::string& name_param, int id_param) : name(name_param), id(id_param) {
        totalStudents++; // Increment static counter
    }

    // Static method to get the total number of students
    static int getTotalStudents() {
        return totalStudents;
    }

    // Optional: Getters for private members (good practice for encapsulation)
    const std::string& getName() const { return name; }
    int getId() const { return id; }
};

// Initialize static member outside the class definition (required for static members)
int Student::totalStudents = 0;

int main() {
    std::cout << "Initial total students: " << Student::getTotalStudents() << '\n'; // Expected: 0

    Student s1("Alice Wonderland", 201);
    std::cout << "After s1: " << Student::getTotalStudents() << '\n'; // Expected: 1

    Student s2("Bob The Builder", 202);
    Student s3("Charlie Chaplin", 203);
    std::cout << "After s2, s3: " << Student::getTotalStudents() << '\n'; // Expected: 3

    // Demonstrate efficiency with a long string passed by const reference
    std::string longName(500, 'Z'); // Create a string with 500 'Z's
    Student s_long_name(longName, 204); // Passed by const reference, no unnecessary copy
    std::cout << "After s_long_name: " << Student::getTotalStudents() << '\n'; // Expected: 4

    {
        Student s4("David Copperfield", 205);
        std::cout << "After s4 (in scope): " << Student::getTotalStudents() << '\n'; // Expected: 5
    } // s4 goes out of scope. totalStudents remains 5 (as per "objects created").

    std::cout << "After s4 out of scope: " << Student::getTotalStudents() << '\n'; // Expected: 5

    std::vector<Student> student_collection;
    student_collection.emplace_back("Eve Harrington", 206);
    student_collection.emplace_back("Frankenstein", 207);
    std::cout << "After vector additions: " << Student::getTotalStudents() << '\n'; // Expected: 7

    return 0;
}