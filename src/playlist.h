#ifndef PLAYLIST_H
#define PLAYLIST_H

// Core Data Structure: The Song Node
typedef struct Song {
    char title[100];
    char artist[100];
    int duration;
    struct Song* next; // Pointer to the next song
} Song;

// Required Playlist Operations (Function Prototypes)
void addSong(Song** head, Song** tail, Song library[], int index);
void playNext(Song** head, Song** tail);
void viewPlaylist(Song* head);
void showTotalDuration(Song* head);

#endif