#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int grade;

public:
    Student(std::string n, int g) : name(n) {
        // For simplicity, directly initialize grade in constructor.
        // The error will be in the setGrade method.
        grade = g;
    }

    void setName(std::string n) {
        name = n;
    }

    // SEMANTIC ERROR: setGrade is marked const, but attempts to modify 'grade'.
    // A const method cannot modify member variables unless they are mutable.
    void setGrade(int newGrade) const {
        if (newGrade >= 0 && newGrade <= 100) {
            // This line will cause a compile-time error:
            // "assignment of member 'Student::grade' in read-only object"
            grade = newGrade;
        } else {
            std::cout << "Error: Grade must be between 0 and 100. Keeping old value.\n";
        }
    }

    void displayStudent() const {
        std::cout << "Student: " << name << ", Grade: " << grade << "\n";
    }

    int getGrade() const {
        return grade;
    }
};

int main() {
    std::string name;
    int initialGrade, invalidGrade, validGrade;

    std::cin >> name >> initialGrade >> invalidGrade >> validGrade;

    Student s(name, initialGrade);
    s.displayStudent();

    s.setGrade(invalidGrade);
    s.displayStudent();

    s.setGrade(validGrade);
    s.displayStudent();

    return 0;
}