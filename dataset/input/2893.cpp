#include <iostream>
#include <chrono>
#include <thread> // For std::this_thread::sleep_for

// Robustness Issue:
// 1. Uses std::chrono::high_resolution_clock which is not guaranteed to be steady.
//    For measuring durations, std::chrono::steady_clock is generally preferred
//    to avoid issues with system time adjustments (e.g., NTP sync, daylight saving).
// 2. The getElapsedTime() method has a logical bug: when the timer is running,
//    it only returns the accumulated time from previous stop cycles, not including
//    the duration of the *current* active run. This leads to incorrect real-time reporting.
class Timer {
private:
    std::chrono::high_resolution_clock::time_point _startTime;
    std::chrono::high_resolution_clock::duration _accumulatedDuration;
    bool _isRunning;

public:
    Timer() : _accumulatedDuration(std::chrono::high_resolution_clock::duration::zero()), _isRunning(false) {}

    Timer& start() {
        if (!_isRunning) {
            _startTime = std::chrono::high_resolution_clock::now();
            _isRunning = true;
        }
        return *this;
    }

    Timer& stop() {
        if (_isRunning) {
            _accumulatedDuration += (std::chrono::high_resolution_clock::now() - _startTime);
            _isRunning = false;
        }
        return *this;
    }

    Timer& reset() {
        _accumulatedDuration = std::chrono::high_resolution_clock::duration::zero();
        _isRunning = false; // Ensure it's not running after reset
        return *this;
    }

    // Robustness Issue 2: This method incorrectly reports time when the timer is running.
    // It only returns the already accumulated duration, not the duration of the current active segment.
    long long getElapsedTime() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_accumulatedDuration).count();
    }
};

int main() {
    Timer t;
    std::cout << "Timer created.\n";

    t.start();
    std::cout << "Timer started. Current elapsed: " << t.getElapsedTime() << " ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "After 100ms. Current elapsed: " << t.getElapsedTime() << " ms\n"; // BUG: Should show ~100ms
    t.stop();
    std::cout << "Timer stopped. Total elapsed: " << t.getElapsedTime() << " ms\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "After 50ms. Total elapsed (should be same): " << t.getElapsedTime() << " ms\n";

    t.reset();
    std::cout << "Timer reset. Total elapsed: " << t.getElapsedTime() << " ms\n";

    // Chaining example
    t.start().reset().stop();
    std::cout << "Chaining start().reset().stop(). Total elapsed: " << t.getElapsedTime() << " ms\n";

    t.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    t.stop();
    std::cout << "Timer started for 200ms. Total elapsed: " << t.getElapsedTime() << " ms\n";

    t.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Timer started for 50ms. Current elapsed: " << t.getElapsedTime() << " ms\n"; // BUG: Should show ~250ms
    t.stop();
    std::cout << "Timer stopped. Total elapsed: " << t.getElapsedTime() << " ms\n";

    return 0;
}