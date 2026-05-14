#include <iostream>
#include <chrono>
#include <thread> // For std::this_thread::sleep_for

// Correct Version:
// 1. Uses `std::chrono::steady_clock` for accurate and monotonic time measurements,
//    suitable for measuring durations.
// 2. Employs `std::chrono::time_point` and `std::chrono::duration` for internal
//    storage, which are type-safe, expressive, and efficient.
// 3. Provides clear, concise logic and descriptive variable names.
// 4. `getElapsedTime()` correctly accounts for the currently running segment.
class Timer {
private:
    std::chrono::steady_clock::time_point start_time_;
    std::chrono::steady_clock::duration accumulated_duration_;
    bool is_running_;

public:
    Timer() : accumulated_duration_(std::chrono::steady_clock::duration::zero()), is_running_(false) {}

    Timer& start() {
        if (!is_running_) {
            start_time_ = std::chrono::steady_clock::now();
            is_running_ = true;
        }
        return *this;
    }

    Timer& stop() {
        if (is_running_) {
            accumulated_duration_ += (std::chrono::steady_clock::now() - start_time_);
            is_running_ = false;
        }
        return *this;
    }

    Timer& reset() {
        accumulated_duration_ = std::chrono::steady_clock::duration::zero();
        is_running_ = false;
        // No need to reset start_time_ if not running, as it will be set on next start()
        return *this;
    }

    long long getElapsedTime() const {
        std::chrono::steady_clock::duration current_total_duration = accumulated_duration_;
        if (is_running_) {
            current_total_duration += (std::chrono::steady_clock::now() - start_time_);
        }
        return std::chrono::duration_cast<std::chrono::milliseconds>(current_total_duration).count();
    }
};

int main() {
    Timer t;
    std::cout << "Timer created.\n";

    t.start();
    std::cout << "Timer started. Current elapsed: " << t.getElapsedTime() << " ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "After 100ms. Current elapsed: " << t.getElapsedTime() << " ms\n";
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
    std::cout << "Timer started for 50ms. Current elapsed: " << t.getElapsedTime() << " ms\n";
    t.stop();
    std::cout << "Timer stopped. Total elapsed: " << t.getElapsedTime() << " ms\n";

    return 0;
}