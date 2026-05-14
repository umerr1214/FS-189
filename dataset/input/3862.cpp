#include <cstdio> // For printf

// Function to copy a C-style string from source to destination
// This version contains a syntax error in main.
void copyCString(const char* source, char* destination) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // Null-terminate the destination string
}

int main() {
    char source1[] = "Hello, World!";
    char destination1[50]; // Sufficient capacity assumed

    printf("Source 1: %s\n", source1);
    copyCString(source1, destination1);
    printf("Destination 1: %s\n", destination1) // Syntax error: Missing semicolon here

    char source2[] = "C++ Programming";
    char destination2[50];

    printf("Source 2: %s\n", source2);
    copyCString(source2, destination2);
    printf("Destination 2: %s\n", destination2);

    char source3[] = ""; // Empty string
    char destination3[10];

    printf("Source 3: \"%s\"\n", source3);
    copyCString(source3, destination3);
    printf("Destination 3: \"%s\"\n", destination3);

    return 0;
}