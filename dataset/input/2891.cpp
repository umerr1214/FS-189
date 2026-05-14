#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point _startTime;
    std::chrono::nanoseconds _totalElapsedDuration; // Should accumulate, but will be assigned
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
            // LOGICAL ERROR: Assigns instead of accumulates.
            // This means _totalElapsedDuration will only hold the duration of the last completed run,
            // not the sum of all runs.
            _totalElapsedDuration = std::chrono::high_resolution_clock::now() - _startTime;
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
    Timer timer;
    std::cout << "Initial time: " << timer.getElapsedTimeMs() << "ms\n"; // Expected: 0

    // Test 1: Basic start/stop
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    timer.stop();
    std::cout << "After 100ms run: " << timer.getElapsedTimeMs() << "ms\n"; // Expected: ~100. Actual: ~100 (correct for this step)

    // Test 2: Reset and run again
    timer.reset().start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    timer.stop();
    std::cout << "After reset and 50ms run: " << timer.getElapsedTimeMs() << "ms\n"; // Expected: ~50. Actual: ~50 (correct for this step)

    // Test 3: Chaining with multiple start/stop cycles - this will expose the error
    timer.reset().start(); // Run 1 starts
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    timer.stop(); // Run 1 stops. _totalElapsedDuration becomes ~75ms.
    timer.start(); // Run 2 starts
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    timer.stop(); // Run 2 stops. LOGICAL ERROR: _totalElapsedDuration becomes ~25ms, overwriting ~75ms.
    std::cout << "After multiple runs (75ms + 25ms): " << timer.getElapsedTimeMs() << "ms\n"; // Expected: ~100. Actual: ~25.

    // Test 4: Starting an already running timer, stopping a stopped timer
    timer.reset().start();
    timer.start(); // Should not reset or affect current run
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    timer.stop();
    timer.stop(); // Should not affect already stopped timer
    std::cout << "After multiple start/stop (10ms): " << timer.getElapsedTimeMs() << "ms\n"; // Expected: ~10. Actual: ~10.

    return 0;
}