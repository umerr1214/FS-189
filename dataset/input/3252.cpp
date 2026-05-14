#include <iostream>
#include <string>
#include <utility> // For std::move

class Song {
public:
    std::string title;
    std::string artist;

    Song(std::string t = "", std::string a = "") : title(std::move(t)), artist(std::move(a)) {}

    void display() const {
        std::cout << "\"" << title << "\" by " << artist;
    }
};

class Playlist {
private:
    Song* songs;
    int capacity;
    int count;

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Song* newSongs = new Song[newCapacity];
        for (int i = 0; i < count; ++i) {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
        capacity = newCapacity;
    }

public:
    Playlist() : songs(nullptr), capacity(0), count(0) {}
    ~Playlist() {
        // This destructor correctly deallocates memory for a single Playlist object.
        // However, due to missing copy constructor/assignment, multiple objects
        // might point to the same memory, leading to double-free.
        delete[] songs;
    }
    // SEMANTIC ERROR: Missing user-defined copy constructor and copy assignment operator.
    // The default compiler-generated versions perform shallow copies of 'songs' pointer,
    // violating the Rule of Three/Five for classes managing dynamic memory.
    // This will lead to multiple Playlist objects owning the same 'songs' array,
    // resulting in double-free errors when these objects are destructed.

    void addSong(const Song& song) {
        if (count == capacity) {
            resize();
        }
        songs[count++] = song;
    }

    bool removeSong(const std::string& title) {
        for (int i = 0; i < count; ++i) {
            if (songs[i].title == title) {
                for (int j = i; j < count - 1; ++j) {
                    songs[j] = songs[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
    }

    void displayPlaylist() const {
        if (count == 0) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        std::cout << "Playlist (" << count << " songs):\n";
        for (int i = 0; i < count; ++i) {
            std::cout << i + 1 << ". ";
            songs[i].display();
            std::cout << "\n";
        }
    }

    int getSongCount() const {
        return count;
    }
};

// Function to demonstrate the semantic error (shallow copy leading to double-free)
void testCopy(Playlist p) { // 'p' is copy-constructed from the argument, leading to shallow copy
    std::cout << "\nInside testCopy function:\n";
    p.displayPlaylist();
    // When 'p' goes out of scope, its destructor will be called,
    // attempting to delete the 'songs' array that is also owned by the original playlist object.
}

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong(Song("Song A", "Artist 1"));
    myPlaylist.addSong(Song("Song B", "Artist 2"));
    myPlaylist.addSong(Song("Song C", "Artist 3"));

    std::cout << "Original playlist:\n";
    myPlaylist.displayPlaylist();

    // This line invokes the default copy constructor (shallow copy).
    // 'myPlaylist' and 'anotherPlaylist' now point to the SAME dynamically allocated 'songs' array.
    Playlist anotherPlaylist = myPlaylist;
    std::cout << "\nCopied playlist (anotherPlaylist):\n";
    anotherPlaylist.displayPlaylist();

    std::cout << "\nModifying original playlist...\n";
    myPlaylist.addSong(Song("Song D", "Artist 4"));
    myPlaylist.removeSong("Song B");
    myPlaylist.displayPlaylist();

    // Due to shallow copy, 'anotherPlaylist' also reflects changes made to 'myPlaylist'
    // because they share the same underlying data. This is incorrect behavior for a deep copy.
    std::cout << "\nCopied playlist after original modified (will reflect changes due to shallow copy):\n";
    anotherPlaylist.displayPlaylist();

    std::cout << "\nCalling testCopy with original playlist (pass by value, invokes shallow copy constructor)...\n";
    testCopy(myPlaylist); // This function call will cause a double-free when 'p' is destructed.

    std::cout << "\nBack in main. Original playlist after testCopy:\n";
    myPlaylist.displayPlaylist(); // This line might crash if the double-free already occurred and corrupted memory.

    // When 'myPlaylist' and 'anotherPlaylist' go out of scope, their destructors will be called,
    // leading to further double-free errors as they both attempt to delete the same memory.

    return 0;
}