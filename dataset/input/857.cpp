#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int nCr(int n, int r) {
    // Efficiency Issue: Computing factorial for every term is very inefficient O(N).
    // Total complexity O(N^3).
    // Formula `C = C * (line-i)/i` is O(N^2).
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void printPascalsTriangle(int n) {
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            cout << nCr(line, i) << " ";
        }
        cout << endl;
    }
}

int main() {
    printPascalsTriangle(5);
    return 0;
}
