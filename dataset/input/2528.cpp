#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int studentID;

public:
    // Default constructor
    // Readability/Efficiency Issue: Members are initialized by assignment in the body,
    // which means they are first default-constructed and then assigned, potentially
    // less efficient than using an initializer list. Inconsistent use of `this->`.
    Student()
    {
        this->name = "Unknown"; // Default-constructs name, then assigns "Unknown"
        studentID = 0;         // Inconsistent with this->name
    }

    // Parameterized constructor
    // Readability/Efficiency Issue: Passing `std::string n` by value causes an
    // unnecessary copy of the string argument. Then, `name = n;` causes another copy.
    // Poor parameter names (`n`, `id`). Inconsistent use of `this->`.
    Student(std::string n, int id) // 'n' is a copy of the argument string
    {
        name = n;                 // 'name' is assigned from 'n', another copy
        this->studentID = id;     // Inconsistent use of this->
    }

    // Destructor
    // Readability Issue: Using '\n' instead of std::endl. While sometimes
    // marginally more efficient (no flush), it's inconsistent with C++ standard
    // library practice for general output and can be less readable.
    ~Student() {
        std::cout << "Student " << name << " with ID " << studentID << " destroyed.\n";
    }

    // Accessors
    std::string getName() const { return name; }
    int getStudentID() const { return studentID; }
};

// Function to demonstrate object creation and destruction
void createAndDestroyStudentsInefficiently() {
    Student s1("Eve", 201); // "Eve" copied to n, then n copied to s1.name
    {
        Student s2("Frank", 202); // "Frank" copied to n, then n copied to s2.name
    } // s2 destroyed
    Student s3("Grace", 203); // "Grace" copied to n, then n copied to s3.name
} // s3 and s1 destroyed

int main() {
    Student defaultStudent; // Uses inefficient default constructor
    std::cout << "Default student created: " << defaultStudent.getName() << " (ID: " << defaultStudent.getStudentID() << ")" << std::endl;

    Student paramStudent("Heidi", 204); // Uses inefficient parameterized constructor
    std::cout << "Parameterized student created: " << paramStudent.getName() << " (ID: " << paramStudent.getStudentID() << ")" << std::endl;

    createAndDestroyStudentsInefficiently();

    return 0; // defaultStudent and paramStudent destroyed here
}