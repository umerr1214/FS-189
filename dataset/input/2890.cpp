#include <iostream>
#include <chrono>
#include <thread>
#include <string>

// Typo: 'clas' instead of 'class'
clas Timer { // SYNTAX ERROR HERE
private:
    std::chrono::high_resolution_clock::time_point _startTime;
    std::chrono::nanoseconds _totalElapsedDuration;
    bool _isRunning;

public:
    Timer() : _totalElapsedDuration(0), _isRunning(false) {}

    Timer& start() {
        if (!_isRunning) {
            _startTime = std::chrono::high_resolution_clock::now();
            _isRunning = true;
        }
        return *this;
    }

    Timer& stop() {
        if (_isRunning) {
            _totalElapsedDuration += std::chrono::high_resolution_clock::now() - _startTime;
            _isRunning = false;
        }
        return *this;
    }

    Timer& reset() {
        _totalElapsedDuration = std::chrono::nanoseconds(0);
        _isRunning = false;
        return *this;
    }

    long long getElapsedTimeMs() const {
        std::chrono::nanoseconds currentDuration = _totalElapsedDuration;
        if (_isRunning) {
            currentDuration += std::chrono::high_resolution_clock::now() - _startTime;
        }
        return std::chrono::duration_cast<std::chrono::milliseconds>(currentDuration).count();
    }
};

int main() {
    // This code will not compile due to the syntax error in the Timer class definition.
    Timer timer;
    std::cout << "Initial time: " << timer.getElapsedTimeMs() << "ms\n";

    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    timer.stop();
    std::cout << "After 100ms run: " << timer.getElapsedTimeMs() << "ms\n";

    timer.reset().start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    timer.stop();
    std::cout << "After reset and 50ms run: " << timer.getElapsedTimeMs() << "ms\n";

    timer.reset().start();
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    timer.stop().reset().start();
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    timer.stop();
    std::cout << "After chained operations (75ms + 25ms): " << timer.getElapsedTimeMs() << "ms\n";

    return 0;
}