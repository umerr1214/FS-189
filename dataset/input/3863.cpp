#include <cstdio> // For printf

// Function to copy a C-style string from source to destination
// This version contains a logical error: it truncates the string by one character.
void copyCString(const char* source, char* destination) {
    int i = 0;
    // Logical Error: The loop condition 'source[i+1] != '\0'' causes the loop
    // to stop one character before the actual end of the source string.
    while (source[i] != '\0' && source[i+1] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Null-terminate the destination string
}

int main() {
    char source1[] = "Hello, World!";
    char destination1[50]; // Sufficient capacity assumed

    printf("Source 1: \"%s\"\n", source1);
    copyCString(source1, destination1);
    printf("Destination 1: \"%s\"\n", destination1); // Expected: "Hello, World!", Actual: "Hello, World"

    char source2[] = "C++ Programming";
    char destination2[50];

    printf("Source 2: \"%s\"\n", source2);
    copyCString(source2, destination2);
    printf("Destination 2: \"%s\"\n", destination2); // Expected: "C++ Programming", Actual: "C++ Programmin"

    char source3[] = "A"; // Single character string
    char destination3[10];

    printf("Source 3: \"%s\"\n", source3);
    copyCString(source3, destination3);
    printf("Destination 3: \"%s\"\n", destination3); // Expected: "A", Actual: "" (empty string)

    char source4[] = ""; // Empty string
    char destination4[10];

    printf("Source 4: \"%s\"\n", source4);
    copyCString(source4, destination4);
    printf("Destination 4: \"%s\"\n", destination4); // Expected: "", Actual: "" (correct for empty)

    return 0;
}