#include <iostream>
#include <string>

// Readability / Efficiency Issue:
// - Strings passed by value in constructors, causing unnecessary copies (efficiency).
// - Overly verbose variable names and inconsistent formatting (readability).
// - Excessive use of 'this->' (readability).
// - Use of std::endl instead of '\n' for output (minor efficiency).

class Person
{
private:
    std::string person_name_member_variable;
    int person_age_member_variable;

public:
    // Efficiency Issue: std::string p_name_param and p_age_param are passed by value,
    // leading to unnecessary copies. Should ideally be const std::string&.
    Person(std::string p_name_param, int p_age_param)
    {
        this->person_name_member_variable = p_name_param; // Readability: Verbose assignment
        this->person_age_member_variable = p_age_param;   // Readability: Verbose assignment
    }

    void print_person_details_function() const // Readability: Verbose function name
    {
        std::cout << "Person's Name Is: " << this->person_name_member_variable << std::endl; // Efficiency: std::endl
        std::cout << "Person's Age Is: " << this->person_age_member_variable << std::endl;   // Efficiency: std::endl
    }
};

class Student : public Person
{
private:
    std::string student_id_member_variable;

public:
    // Efficiency Issue: string parameters passed by value
    Student(std::string student_name_param, int student_age_param, std::string student_identifier_param)
        : Person(student_name_param, student_age_param) // Constructor chaining is correct
    {
        this->student_id_member_variable = student_identifier_param; // Readability: Verbose assignment
    }

    void display_student_full_details_method() const // Readability: Verbose function name
    {
        this->print_person_details_function(); // Call base class method
        std::cout << "Student's Unique Identifier Is: " << this->student_id_member_variable << std::endl; // Efficiency: std::endl
    }
};

int main()
{
    // Inconsistent indentation here for readability issue
    Student
        first_student_object("Charlie Brown", 18, "SID_CB_2023_001"); // Readability: Verbose object name
    std::cout << "--- First Student's Information ---" << std::endl;
    first_student_object.display_student_full_details_method();

    std::cout << std::endl; // Extra std::endl for spacing

    Student second_student_object("Lucy Van Pelt", 19, "SID_LVP_2023_002");
    std::cout << "--- Second Student's Information ---" << std::endl;
    second_student_object.display_student_full_details_method();

    return 0;
}