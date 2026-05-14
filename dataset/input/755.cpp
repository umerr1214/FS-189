#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 3;
const int DAYS = 30;

void analyzeWeather(char weather[][DAYS]) {
    // Efficiency/Readability:
    // Calculating totals by iterating again? 
    // Or just code duplication.
    // Let's duplicate code excessively.
    
    int totalR = 0;
    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (weather[i][j] == 'R') totalR++;
        }
    }
    
    int totalC = 0;
    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (weather[i][j] == 'C') totalC++;
        }
    }
    
    int totalS = 0;
    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (weather[i][j] == 'S') totalS++;
        }
    }
    
    // And again for per-month stats
    for (int i = 0; i < MONTHS; i++) {
        int r = 0, c = 0, s = 0;
        for (int j = 0; j < DAYS; j++) {
            if (weather[i][j] == 'R') r++;
            if (weather[i][j] == 'C') c++;
            if (weather[i][j] == 'S') s++;
        }
        cout << "Month " << i << ": R=" << r << "..." << endl;
    }
}

int main() {
    return 0;
}
