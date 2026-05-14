#include <cstdio> // For printf

// Function to copy a C-style string from source to destination
// This version contains a semantic error: it fails to null-terminate the destination string.
void copyCString(const char* source, char* destination) {
    while (*source != '\0') { // Copies characters up to, but not including, the null terminator
        *destination = *source;
        destination++;
        source++;
    }
    // Semantic Error: Missing '*destination = '\0';' here.
    // The destination string is not null-terminated, leading to undefined behavior
    // when functions like printf("%s", ...) try to read it.
}

int main() {
    char source1[] = "Hello, World!";
    char destination1[50]; // Sufficient capacity assumed

    printf("Source 1: \"%s\"\n", source1);
    copyCString(source1, destination1);
    printf("Destination 1 (unterminated): \"%s\"\n", destination1); // Will likely print garbage after "Hello, World!" or crash

    char source2[] = "Short";
    char destination2[50];

    printf("Source 2: \"%s\"\n", source2);
    copyCString(source2, destination2);
    printf("Destination 2 (unterminated): \"%s\"\n", destination2); // Will likely print garbage after "Short" or crash

    char source3[] = ""; // Empty string
    char destination3[10];

    printf("Source 3: \"%s\"\n", source3);
    copyCString(source3, destination3);
    // For an empty string, destination[0] is not written, and if it's not pre-zeroed,
    // this can also lead to undefined behavior, though often it just prints empty if
    // the first byte is coincidentally zero.
    printf("Destination 3 (unterminated): \"%s\"\n", destination3);

    return 0;
}