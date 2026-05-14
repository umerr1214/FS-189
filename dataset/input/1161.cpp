#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

// Base class MediaItem
class MediaItem {
public:
    std::string title;

    // Constructor
    MediaItem(const std::string& t) : title(t) {}

    // Virtual function to be overridden by derived classes
    virtual void play() const { // Using const for functions that don't modify object state
        std::cout << "Playing generic media: " << title << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~MediaItem() = default; // Use = default for simple virtual destructors
};

// Derived class AudioFile
class AudioFile : public MediaItem {
public:
    // Constructor
    AudioFile(const std::string& title) : MediaItem(title) {}

    // Override the play function
    void play() const override {
        std::cout << "Playing audio: " << title << std::endl;
    }
};

// Derived class VideoFile
class VideoFile : public MediaItem {
public:
    std::string filename; // Specific attribute for video files

    // Constructor
    VideoFile(const std::string& title, const std::string& filename)
        : MediaItem(title), filename(filename) {}

    // Override the play function
    void play() const override {
        std::cout << "Playing video: " << filename << " (Title: " << title << ")" << std::endl;
    }
};

int main() {
    // Use std::vector of std::unique_ptr for polymorphic collection and automatic memory management (RAII)
    std::vector<std::unique_ptr<MediaItem>> mediaCollection;

    // Add various media items to the collection
    mediaCollection.push_back(std::make_unique<AudioFile>("The Sound of Silence"));
    mediaCollection.push_back(std::make_unique<VideoFile>("Nature's Beauty", "forest_walk.mp4"));
    mediaCollection.push_back(std::make_unique<AudioFile>("Morning Coffee Jazz"));
    mediaCollection.push_back(std::make_unique<VideoFile>("City Lights", "nyc_timelapse.mov"));

    std::cout << "--- Demonstrating Polymorphic Playback ---" << std::endl;
    // Iterate through the collection and call play() polymorphically
    for (const auto& item : mediaCollection) {
        item->play();
    }
    std::cout << "------------------------------------------" << std::endl;

    // std::unique_ptr automatically handles memory deallocation when they go out of scope.
    // No explicit 'delete' calls are needed.

    return 0;
}