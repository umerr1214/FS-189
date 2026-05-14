#include <cstdio> // For printf and scanf
#include <string>   // For std::string, though C-style char array could also be used

void solve() {
    char n[100]; // Name buffer
    int a;       // Age variable

    printf("Enter your name: ");
    scanf("%99s", n); // Reads a single word into char array, prevents buffer overflow up to 99 chars

    printf("Enter your age: ");
    scanf("%d", &a); // Reads an integer

    // Using printf for output
    printf("Hello, %s! You are %d years old.\n", n, a);
}

int main() {
    solve();
    return 0;
}