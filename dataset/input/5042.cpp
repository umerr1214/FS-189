#include <cstdio> // For printf, scanf
// #include <iostream> // Not used, but often mixed with cstdio, which is a readability issue
// #include <string> // Not used for name, but std::string is idiomatic C++

// Using a fixed-size char array for name, which is less safe and flexible than std::string.
// Also, mixing C-style I/O with C++ struct definitions can be seen as less idiomatic.
struct Student {
    int id;
    char name[100]; // Fixed-size buffer, vulnerable to overflow and limits name length
    double gpa;
};

int main() {
    Student s;

    // Using C-style I/O functions (scanf, printf) instead of C++ iostreams (cin, cout).
    // While functional, this is generally considered less idiomatic and potentially less safe in C++.
    printf("Enter student ID: ");
    scanf("%d", &s.id); // No input validation

    printf("Enter student name (no spaces): ");
    // scanf with %s stops reading at the first whitespace. This means names with spaces
    // will be truncated, which is an efficiency/readability issue as it limits user input
    // and doesn't behave as expected for common names. It's also vulnerable to buffer overflows.
    scanf("%s", s.name); // Leaves newline in buffer, but no subsequent reads are affected here.

    printf("Enter student GPA: ");
    scanf("%lf", &s.gpa); // No input validation

    printf("\n--- Student Details ---\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    // Using a format specifier for GPA, which is less flexible than iostream formatting.
    printf("GPA: %.2f\n", s.gpa); // Unnecessarily formats GPA to 2 decimal places

    return 0;
}