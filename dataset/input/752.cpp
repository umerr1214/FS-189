#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 3;
const int DAYS = 30;

void analyzeWeather(char weather[][DAYS]) {
    int totalR = 0, totalC = 0, totalS = 0;
    int maxRain = -1;
    int rainyMonth = -1;
    
    for (int i = 0; i < MONTHS; i++) {
        int r = 0, c = 0, s = 0;
        for (int j = 0; j < DAYS; j++) {
            // Logical Error: Using assignment '=' instead of equality '==' in conditions.
            // This modifies the array and makes every day 'S' (since assignments return the char value which is non-zero/true).
            // Actually, if we do `if (x = 'R')`, x becomes 'R', condition true.
            // But we have else-if.
            // The first `if` makes it 'R'.
            
            if (weather[i][j] = 'R') r++; 
            else if (weather[i][j] = 'C') c++; // Unreachable
            else if (weather[i][j] = 'S') s++; // Unreachable
        }
        cout << "Month " << i << ": R=" << r << " C=" << c << " S=" << s << endl;
        totalR += r;
        totalC += c;
        totalS += s;
        
        if (r > maxRain) {
            maxRain = r;
            rainyMonth = i;
        }
    }
    
    cout << "Total: R=" << totalR << " C=" << totalC << " S=" << totalS << endl;
    cout << "Month with most rain: " << rainyMonth << endl;
}

int main() {
    char weather[MONTHS][DAYS];
    // Init to 'S'
    for(int i=0; i<MONTHS; i++)
        for(int j=0; j<DAYS; j++)
            weather[i][j] = 'S';
            
    // Expected: All 'S', 0 Rainy.
    // Actual: All become 'R', 30 Rainy days per month.
    analyzeWeather(weather);
    return 0;
}
