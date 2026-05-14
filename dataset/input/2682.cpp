#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentID;
    char grade;

public:
    // Default constructor
    Student() : studentName("N/A"), studentID(0), grade('F') {}

    // Parameterized constructor
    Student(std::string name, int id, char g) : studentName(name), studentID(id), grade(g) {}

    // Get methods
    std::string getStudentName() const { return studentName; }
    int getStudentID() const { return studentID; }
    // SEMANTIC ERROR: getGrade() returns int instead of char
    int getGrade() const { return grade; } 

    // Print method
    void printStudentDetails() const {
        std::cout << "Name: " << studentName << std::endl;
        std::cout << "ID: " << studentID << std::endl;
        std::cout << "Grade: " << grade << std::endl;
    }
};

int main() {
    Student s1("Charlie Brown", 303, 'C');
    std::cout << "Student Details:" << std::endl;
    s1.printStudentDetails();
    std::cout << std::endl;

    // Demonstrate the semantic error: calling getGrade() returns an int
    std::cout << "Retrieved Grade (int value): " << s1.getGrade() << std::endl;
    std::cout << "Retrieved Grade (char cast): " << static_cast<char>(s1.getGrade()) << std::endl;
    std::cout << std::endl;

    Student s2("Diana Prince", 404, 'A');
    std::cout << "Student Details:" << std::endl;
    s2.printStudentDetails();
    std::cout << std::endl;

    std::cout << "Retrieved Grade (int value): " << s2.getGrade() << std::endl;
    std::cout << "Retrieved Grade (char cast): " << static_cast<char>(s2.getGrade()) << std::endl;
    std::cout << std::endl;

    return 0;
}