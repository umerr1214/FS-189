#include <iostream>
#include <string>
#include <vector> // Included for the driver, not strictly for the class itself

class Student {
private:
    std::string name;
    // Robustness issue: Using 'short' for ID. This can lead to silent truncation
    // if an ID larger than SHRT_MAX (e.g., 32767) is provided.
    short id; 

public:
    // Robustness issue: Using 'short' for totalStudents. This counter can overflow
    // if more than SHRT_MAX students are created.
    static short totalStudents; 

    // Parameterized constructor. 'int i' is passed, which will be implicitly
    // converted to 'short id', demonstrating the truncation issue.
    Student(std::string n, int i) : name(n) {
        id = i; // Potential truncation here
        totalStudents++;
    }

    // Static method to get the total number of students
    static short getTotalStudents() {
        return totalStudents;
    }

    // Getter for id to demonstrate the truncation issue in main
    short getId() const { return id; }
};

// Initialize static member outside the class definition
short Student::totalStudents = 0;

int main() {
    std::cout << "Initial total students: " << Student::getTotalStudents() << '\n'; // Expected: 0

    Student s1("Alice", 101);
    std::cout << "After s1: " << Student::getTotalStudents() << '\n'; // Expected: 1

    Student s2("Bob", 102);
    Student s3("Charlie", 103);
    std::cout << "After s2, s3: " << Student::getTotalStudents() << '\n'; // Expected: 3

    // Demonstrate ID truncation: 40000 exceeds short max (typically 32767).
    // This will cause a silent wrap-around (e.g., 40000 -> -25536 on systems where short is 16-bit).
    Student s_trunc("TruncatedID", 40000); 
    std::cout << "Student s_trunc created with ID 40000. Stored ID: " << s_trunc.getId() << '\n'; 
    std::cout << "After s_trunc: " << Student::getTotalStudents() << '\n'; // Expected: 4

    // Further students to show counter increment
    Student s4("David", 104);
    Student s5("Eve", 105);
    std::cout << "After s4, s5: " << Student::getTotalStudents() << '\n'; // Expected: 6

    // The 'totalStudents' being a 'short' is a robustness issue itself,
    // as it could overflow if more than 32767 students were created.
    // This specific test case doesn't reach that limit, but the potential is there.

    return 0;
}