#include <iostream>
#include <vector>
using namespace std;

void printPascalsTriangle(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++) {
            cout << C << " ";
            C = C * (line - i) / i;
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    printPascalsTriangle(n) // Syntax Error: Missing semicolon
    return 0;
}
