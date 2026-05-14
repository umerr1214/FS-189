#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int studentID;

public:
    // Default constructor
    Student() : name("Unknown"), studentID(0) {}

    // Parameterized constructor - LOGICAL ERROR: uses local variables with the same name
    Student(std::string n, int id) {
        std::string name = n; // This declares a local variable, not the member variable
        int studentID = id;   // This declares a local variable, not the member variable
        // The actual member variables `this->name` and `this->studentID` remain uninitialized
        // (for string, it defaults to empty; for int, it's garbage).
    }

    // Destructor
    ~Student() {
        std::cout << "Student " << name << " with ID " << studentID << " destroyed." << std::endl;
    }
};

int main() {
    Student s1; // Correctly initialized: name="Unknown", studentID=0
    Student s2("Alice", 101); // Incorrectly initialized: name="", studentID=garbage
    {
        Student s3("Bob", 102); // Incorrectly initialized: name="", studentID=garbage
    } // s3 destroyed here
    std::cout << "Main function ending." << std::endl;
    return 0;
}