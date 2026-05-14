#include <iostream>
#include <vector>
#include <memory> // Required for std::unique_ptr

// Base class MediaItem
class MediaItem {
public:
    // Virtual destructor to ensure proper cleanup of derived objects when deleted via a base pointer.
    virtual ~MediaItem() = default;

    // Virtual play method, marked const as it doesn't modify the object's state.
    virtual void play() const {
        std::cout << "Playing a generic media item.\n";
    }
};

// Derived class AudioFile
class AudioFile : public MediaItem {
public:
    // Override play method for audio files, marked const and using `override` keyword for clarity.
    void play() const override {
        std::cout << "Playing an audio file.\n";
    }
};

// Derived class VideoFile
class VideoFile : public MediaItem {
public:
    // Override play method for video files, marked const and using `override` keyword for clarity.
    void play() const override {
        std::cout << "Playing a video file.\n";
    }
};

// Function containing the solution logic to be tested by the driver
void test_solution() {
    // Using std::vector of std::unique_ptr for automatic memory management
    // and to store polymorphic objects.
    std::vector<std::unique_ptr<MediaItem>> media_collection;

    // Add different types of media items to the collection.
    media_collection.push_back(std::make_unique<MediaItem>());
    media_collection.push_back(std::make_unique<AudioFile>());
    media_collection.push_back(std::make_unique<VideoFile>());

    // Iterate through the collection and call the play method for each item.
    // Polymorphism ensures the correct derived play method is called.
    for (const auto& item : media_collection) {
        item->play();
    }
    // std::unique_ptr automatically handles memory deallocation when they go out of scope.
}

int main() {
    test_solution(); // Execute the solution logic
    return 0;
}