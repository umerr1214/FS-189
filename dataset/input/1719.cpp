#include <iostream>
#include <memory> // For std::unique_ptr
#include <vector> // For storing unique_ptrs

// Base class MediaItem
class MediaItem {
public:
    // Virtual destructor is crucial for correct polymorphic destruction.
    // It ensures that the destructors of derived classes are called
    // when deleting objects through a base class pointer, preventing memory leaks.
    virtual ~MediaItem() {
        std::cout << "MediaItem destructor called." << std::endl;
    }

    // Pure virtual function makes MediaItem an abstract class.
    // Derived classes must implement this method.
    virtual void play() = 0;
};

// Derived class AudioFile
class AudioFile : public MediaItem {
public:
    // Explicitly override the base class destructor.
    ~AudioFile() override {
        std::cout << "AudioFile destructor called." << std::endl;
    }

    // Override the virtual play method, using 'override' for clarity and safety.
    void play() override {
        std::cout << "Playing audio file." << std::endl;
    }
};

// Derived class VideoFile
class VideoFile : public MediaItem {
public:
    // Explicitly override the base class destructor.
    ~VideoFile() override {
        std::cout << "VideoFile destructor called." << std::endl;
    }

    // Override the virtual play method, using 'override'.
    void play() override {
        std::cout << "Playing video file." << std::endl;
    }
};

int main() {
    std::cout << "--- Correct Version Test ---" << std::endl;

    // Use smart pointers (std::unique_ptr) for robust and automatic memory management.
    // This avoids manual new/delete and ensures resources are freed correctly.
    std::vector<std::unique_ptr<MediaItem>> mediaCollection;

    // Add instances of derived classes to the collection.
    mediaCollection.push_back(std::make_unique<AudioFile>());
    mediaCollection.push_back(std::make_unique<VideoFile>());

    // Iterate and call the polymorphic play method.
    for (const auto& item : mediaCollection) {
        item->play();
    }

    std::cout << "--- Objects going out of scope (destructors called) ---" << std::endl;
    // When 'mediaCollection' goes out of scope, unique_ptrs will automatically
    // delete the objects they manage. Due to the virtual destructor in MediaItem,
    // the correct derived class destructors will be called first, followed by the base class.

    return 0;
}