#include <string>    // Required for std::string
#include <iostream>  // Required for std::cout, std::endl

class Student {
private:
    // Private member variables as specified in the question
    int studentID;
    std::string name;
    std::string major;

public:
    // Constructor to set initial values for studentID, name, and major.
    // Uses an initializer list for efficient member initialization.
    // Passes string parameters by const reference (`const std::string&`) to avoid unnecessary copies.
    Student(int id, const std::string& n, const std::string& m)
        : studentID(id), name(n), major(m) {}

    // Public getter for studentID.
    // Marked `const` as it does not modify the object's state.
    int getStudentID() const {
        return studentID;
    }

    // Public getter for name.
    // Returns `const std::string&` to provide efficient, read-only access and avoid unnecessary string copies.
    // Marked `const` as it does not modify the object's state.
    const std::string& getName() const {
        return name;
    }

    // Public getter for major.
    // Returns `const std::string&` to provide efficient, read-only access and avoid unnecessary string copies.
    // Marked `const` as it does not modify the object's state.
    const std::string& getMajor() const {
        return major;
    }

    // As per the question, no direct setters for `studentID` or `name` are provided.
    // No setter for `major` is provided either, as it was not explicitly requested
    // and maintaining immutability (or controlled mutation) is generally good practice.
};

int main() {
    // Create multiple student objects to demonstrate the class functionality
    Student s1(301, "Eva Green", "Biology");
    Student s2(302, "Frank White", "Chemistry");
    Student s3(303, "Grace Black", "Mathematics");

    // Print details for student s1 using the public getters
    std::cout << "Student 1 Details:" << std::endl;
    std::cout << "ID: " << s1.getStudentID() << std::endl;
    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "Major: " << s1.getMajor() << std::endl;
    std::cout << std::endl; // Add an extra newline for better readability in output

    // Print details for student s2
    std::cout << "Student 2 Details:" << std::endl;
    std::cout << "ID: " << s2.getStudentID() << std::endl;
    std::cout << "Name: " << s2.getName() << std::endl;
    std::cout << "Major: " << s2.getMajor() << std::endl;
    std::cout << std::endl;

    // Print details for student s3
    std::cout << "Student 3 Details:" << std::endl;
    std::cout << "ID: " << s3.getStudentID() << std::endl;
    std::cout << "Name: " << s3.getName() << std::endl;
    std::cout << "Major: " << s3.getMajor() << std::endl;

    return 0; // Indicate successful program execution
}