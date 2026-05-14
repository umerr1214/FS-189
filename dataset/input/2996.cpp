#include <iostream>
#include <string>
#include <vector> // Included for the driver

class Student {
private:
    std::string name;
    int id;

public:
    static int totalStudents;

    // Readability/Efficiency Issue:
    // 1. 'n' and 'i' are less descriptive parameter names.
    // 2. 'name' (std::string) is passed by value, causing an unnecessary copy (efficiency).
    // 3. Not using an initializer list for member initialization (less efficient and less idiomatic C++).
    // 4. Excessive use of 'this->' for member access (readability).
    Student(std::string n, int i) {
        this->name = n; // Assigns after default construction, less efficient than initializer list
        this->id = i;   // Assigns after default construction
        this->totalStudents++; // Redundant 'this->' for static member
    }

    // Static method to get the total number of students
    static int getTotalStudents() {
        return totalStudents;
    }

    // Getters also using unnecessary 'this->'
    std::string getName() const { return this->name; }
    int getId() const { return this->id; }
};

// Initialize static member outside the class definition
int Student::totalStudents = 0;

int main() {
    // Efficiency issue: std::endl flushes the buffer, which can be slower than '\n'.
    std::cout << "Initial count: " << Student::getTotalStudents() << std::endl; 

    Student s_obj1("Alice Smith", 101);
    std::cout << "Count after s_obj1: " << Student::getTotalStudents() << std::endl;

    Student s_obj2("Bob Johnson", 102);
    Student s_obj3("Charlie Brown", 103);
    std::cout << "Count after s_obj2, s_obj3: " << Student::getTotalStudents() << std::endl;

    // Demonstrate string copy inefficiency with a long name
    std::string veryLongName(1000, 'X'); // Create a string with 1000 'X's
    Student s_long_name(veryLongName, 200); // This involves copying the long string due to pass-by-value
    std::cout << "Count after s_long_name (with a very long name): " << Student::getTotalStudents() << std::endl;

    {
        Student s_obj4("David Lee", 104);
        std::cout << "Count after s_obj4 (in scope): " << Student::getTotalStudents() << std::endl;
    } // s_obj4 goes out of scope. totalStudents remains.

    std::cout << "Count after s_obj4 out of scope: " << Student::getTotalStudents() << std::endl;

    std::vector<Student> student_list;
    student_list.emplace_back("Eve Davis", 105);
    student_list.emplace_back("Frank White", 106);
    std::cout << "Count after vector additions: " << Student::getTotalStudents() << std::endl;

    return 0;
}