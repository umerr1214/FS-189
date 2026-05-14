#include <string>
#include <iostream> // Required for std::cout, std::endl
#include <stdexcept> // Not directly used for crashing, but good practice for robust error handling

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    // Constructor to initialize all private members
    Student(int id, const std::string& n, const std::string& m)
        : studentID(id), name(n), major(m) {
        // No validation here, which is generally acceptable unless specified.
        // The robustness issue will be in setMajor.
    }

    // Public getter for studentID
    int getStudentID() const {
        return studentID;
    }

    // Public getter for name
    const std::string& getName() const {
        return name;
    }

    // Public getter for major
    const std::string& getMajor() const {
        return major;
    }

    // This method introduces a robustness issue.
    // It accepts a C-style string (char*) for the major.
    // It does not validate if 'newMajor' is a nullptr before dereferencing it,
    // which will cause a program crash (segmentation fault) if nullptr is passed.
    void setMajor(const char* newMajor) {
        // Robustness flaw: Directly assigns newMajor without checking for nullptr.
        // If newMajor is nullptr, std::string constructor will attempt to dereference it, causing a crash.
        major = newMajor; // This line is the source of the robustness issue
    }
};

int main() {
    // Create a student object
    Student s1(101, "Alice Smith", "Computer Science");

    // Print initial details
    std::cout << "Student ID: " << s1.getStudentID() << std::endl;
    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "Major: " << s1.getMajor() << std::endl;

    // Demonstrate a valid update to major
    std::cout << "\nUpdating major for s1 to 'Mathematics'..." << std::endl;
    s1.setMajor("Mathematics");
    std::cout << "New Major: " << s1.getMajor() << std::endl;

    // Trigger the robustness issue: pass nullptr to setMajor
    std::cout << "\nAttempting to set major with nullptr (CRASH EXPECTED):" << std::endl;
    s1.setMajor(nullptr); // This call will likely cause a segmentation fault

    // This line will not be reached if the program crashes as expected
    std::cout << "This line should not be printed if the program crashed." << std::endl;

    return 0; // Program might not reach here
}