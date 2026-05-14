#include <iostream>

// A function to print a 3x3 matrix
void pM(const int m[3][3], const std::string& t) {
std::cout << t << ":" << std::endl;
for (int i = 0; i < 3; ++i) {
for (int j = 0; j < 3; ++j) {
std::cout << m[i][j] << (j == 2 ? "" : " ");
}
std::cout << std::endl;
}
}

// Function to transpose a 3x3 matrix
void tM(int o[3][3], int t[3][3]) {
for (int r = 0; r < 3; ++r) {
for (int c = 0; c < 3; ++c) {
t[c][r] = o[r][c];
}
}
}

int main() {
int a[3][3]; // Original matrix
int b[3][3]; // Transposed matrix

std::cout << "Enter 9 elements:" << std::endl;
for (int x = 0; x < 3; ++x) {
for (int y = 0; y < 3; ++y) {
std::cin >> a[x][y];
}
}

tM(a, b);

pM(a, "Original");
pM(b, "Transposed");

return 0;
}