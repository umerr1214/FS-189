#include <iostream> // Required for std::cout, std::endl
#include <string>   // Required for std::string

class Student {
private:
    std::string name;    // Private member for student's name
    int studentID;       // Private member for student's ID

public:
    // Default constructor
    // Initializes name to "Unknown" and studentID to 0 using an initializer list.
    // This is the preferred and most efficient way to initialize members.
    Student() : name("Unknown"), studentID(0) {
        // Constructor body can be empty or used for additional setup if needed
    }

    // Parameterized constructor
    // Takes a const std::string& for name to avoid unnecessary copies and
    // an int for studentID. Uses an initializer list.
    Student(const std::string& name_param, int id_param)
        : name(name_param), studentID(id_param) {
        // Constructor body can be empty
    }

    // Destructor
    // Prints a message indicating the destruction of the Student object,
    // including its name and ID. Uses std::endl for immediate flushing.
    ~Student() {
        std::cout << "Student " << name << " with ID " << studentID << " destroyed." << std::endl;
    }

    // Accessor methods (optional, but good practice for private members)
    // Marked `const` as they do not modify the object's state.
    std::string getName() const { return name; }
    int getStudentID() const { return studentID; }
};

// Function to demonstrate object creation, scope, and destruction order
void createAndDestroyStudentsCorrectly() {
    std::cout << "--- Entering createAndDestroyStudentsCorrectly ---" << std::endl;
    Student s1("John Doe", 101); // Student object created on stack
    {
        // Inner block scope
        Student s2("Jane Smith", 102); // Another student object
        Student s3;                   // Default constructed student
        std::cout << "Inside block: s2 name=" << s2.getName() << ", s3 name=" << s3.getName() << std::endl;
    } // s3 and s2 are destroyed here (reverse order of creation)
    Student s4("Peter Jones", 104); // Another student object
    std::cout << "--- Exiting createAndDestroyStudentsCorrectly ---" << std::endl;
} // s4 and s1 are destroyed here (reverse order of creation)

int main() {
    std::cout << "--- Program Start ---" << std::endl;

    Student mainStudent("Main Student", 999); // Student object in main's scope

    createAndDestroyStudentsCorrectly(); // Call function to demonstrate object lifecycle

    std::cout << "--- Program End ---" << std::endl;
    return 0; // mainStudent is destroyed here (after main returns)
}