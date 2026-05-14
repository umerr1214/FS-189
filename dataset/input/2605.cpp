#include <iostream>
#include <string>
#include <vector> // Included, but not strictly necessary for this problem, can be considered bloat or a minor robustness/efficiency point if not used.

class Person {
protected:
    std::string firstName;
    std::string lastName;

public:
    // A constructor that initializes members correctly
    Person(std::string first, std::string last) : firstName(first), lastName(last) {}

    // A default constructor for Person, which might be implicitly called or explicitly used.
    // Here, it initializes to empty strings.
    Person() : firstName(""), lastName("") {}
};

class Teacher : public Person {
private:
    std::string subject;

public:
    // Robustness Issue:
    // The Teacher constructor calls Person's default constructor (Person()), which initializes
    // firstName and lastName to empty strings. Then, it directly re-assigns the protected
    // members firstName and lastName in the constructor body. This bypasses the intended
    // initialization flow for these specific values through the Person base class constructor,
    // making the design less robust to potential side effects or complex logic in Person's
    // constructor, and is also inefficient due to double initialization/assignment.
    Teacher(std::string first, std::string last, std::string sub)
        : Person(), // Calls Person's default constructor, initializing base members to empty.
          subject(sub)
    {
        // Direct assignment to protected members, effectively overwriting what Person() did.
        this->firstName = first;
        this->lastName = last;
        // Also, passing strings by value (e.g., 'first', 'last', 'sub') in this and Person's
        // constructor leads to unnecessary copies, a minor efficiency/robustness concern for large strings.
    }

    void displayTeacherInfo() {
        // Robustness Issue:
        // The concatenation " " between firstName and lastName will always add a space,
        // even if firstName or lastName is an empty string. This results in an extra space
        // in the output (e.g., "Teacher: John , Subject: Math" or "Teacher:  Doe, Subject: Math"),
        // which is a minor output formatting robustness issue.
        std::cout << "Teacher: " << firstName << " " << lastName << ", Subject: " << subject << std::endl;
    }
};

int main() {
    Teacher teacher1("John", "Doe", "Math");
    teacher1.displayTeacherInfo();

    Teacher teacher2("Jane", "", "Physics"); // Test with empty last name
    teacher2.displayTeacherInfo();

    Teacher teacher3("", "Smith", "Chemistry"); // Test with empty first name
    teacher3.displayTeacherInfo();

    Teacher teacher4("", "", "Art"); // Test with both names empty
    teacher4.displayTeacherInfo();

    return 0;
}