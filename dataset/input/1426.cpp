#include <iostream>

// Base class
class MediaItem {
public:
    void play() {
        std::cout << "Playing generic media item." << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

// Derived class 1
class AudioFile : public MediaItem {
public:
    void play() {
        std::cout << "Playing audio file." << std::endl;
    }
};

// Derived class 2
class VideoFile : public MediaItem {
public:
    void play() {
        std::cout << "Playing video file." << std::endl;
    }
};

int main() {
    AudioFile audio;
    VideoFile video;

    audio.play();
    video.play();

    return 0;
}