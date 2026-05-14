#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 3;
const int DAYS = 30;

void analyzeWeather(char weather[][DAYS]) {
    // Robustness Issue: No validation of input characters.
    // It assumes only R, C, S are present.
    // If input contains 'X' or lower case 'r', it counts as nothing or might mess up if else logic was loose.
    // In this specific implementation, it just ignores them, which might be okay or bad depending on spec.
    // Spec says "designated as either...".
    // But let's say the array passed might be uninitialized.
    // Or NULL pointer check if passed as pointer.
    
    // Let's assume we read input here and fail to validate.
    
    int totalR = 0, totalC = 0, totalS = 0;
    
    for (int i = 0; i < MONTHS; i++) {
        int r = 0, c = 0, s = 0;
        for (int j = 0; j < DAYS; j++) {
            // Assume input is valid
            if (weather[i][j] == 'R') r++;
            else if (weather[i][j] == 'C') c++;
            else if (weather[i][j] == 'S') s++;
            // If 'r' or 'x', it's ignored.
        }
        // ...
    }
}

int main() {
    char weather[MONTHS][DAYS]; 
    // Uninitialized usage?
    // analyzeWeather(weather); // Garbage values
    return 0;
}
