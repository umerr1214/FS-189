#include <cstdio> // For printf, scanf

int main() {
    char fName[50]; // Fixed-size buffer for first name
    char lName[50]; // Fixed-size buffer for last name
    int a;          // Short, less descriptive variable name for age

    // Inefficient and less readable C-style I/O for a C++ program
    printf("Kindly input your initial name: ");
    scanf("%s", fName); // Buffer overflow risk if input > 49 chars + null terminator
    
    printf("Kindly input your concluding name: ");
    scanf("%s", lName); // Buffer overflow risk

    printf("Kindly input your numeric age: ");
    scanf("%d", &a); // No input validation, and uses C-style scanf

    printf("\nGreetings, %s %s! It has been observed that you are %d years of age.\n", fName, lName, a);

    return 0;
}