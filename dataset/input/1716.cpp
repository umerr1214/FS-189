#include <iostream>
#include <vector>
#include <memory>

class MediaItem {
public:
    virtual void play() = 0; // Pure virtual method
    virtual ~MediaItem() = default;
};

class AudioFile : public MediaItem {
public:
    void play() override {
        std::cout << "Playing audio file." << std::endl;
    }
};

class VideoFile : public MediaItem {
    // Semantic Error: VideoFile does not implement the pure virtual play() method,
    // making VideoFile an abstract class.
    // Therefore, it cannot be instantiated.
public:
    // void play() override {
    //     std::cout << "Playing video file." << std::endl;
    // }
};

int main() {
    std::vector<std::unique_ptr<MediaItem>> mediaItems;
    mediaItems.push_back(std::make_unique<AudioFile>());
    // Semantic Error: Attempting to instantiate an abstract class
    mediaItems.push_back(std::make_unique<VideoFile>()); 

    for (const auto& item : mediaItems) {
        item->play();
    }

    return 0;
}