#include <iostream>

// Base class
class MediaItem {
public:
    virtual void play() {
        std::cout << "Playing generic media item." << std::endl;
    }
};

// Derived class 1
class AudioFile : public MediaItem {
public:
    void play() override { // LOGICAL ERROR: Prints generic message instead of specific audio message
        std::cout << "Playing generic media item." << std::endl;
    }
};

// Derived class 2
class VideoFile : public MediaItem {
public:
    void play() override { // LOGICAL ERROR: Prints generic message instead of specific video message
        std::cout << "Playing generic media item." << std::endl;
    }
};

int main() {
    // Using polymorphism to demonstrate the logical error
    MediaItem* audioItem = new AudioFile();
    MediaItem* videoItem = new VideoFile();

    std::cout << "Calling play on AudioFile object via base pointer:" << std::endl;
    audioItem->play(); // Expected: "Playing audio file." Actual: "Playing generic media item."

    std::cout << "Calling play on VideoFile object via base pointer:" << std::endl;
    videoItem->play(); // Expected: "Playing video file." Actual: "Playing generic media item."

    delete audioItem;
    delete videoItem;

    return 0;
}