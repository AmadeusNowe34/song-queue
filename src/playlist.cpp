#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

void addSong(Song** head, Song** tail, Song library[], int index) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (newSong == NULL) return;

    strcpy(newSong->title, library[index].title);
    strcpy(newSong->artist, library[index].artist);
    newSong->duration = library[index].duration;
    newSong->next = NULL;

    if (*head == NULL) {
        *head = *tail = newSong;
    } else {
        (*tail)->next = newSong;
        *tail = newSong;
    }
    printf("-> Added: %s by %s.\n", newSong->title, newSong->artist);
}

void playNext(Song** head, Song** tail) {
    if (*head == NULL) {
        printf("ERROR: The playlist is currently empty! Add some songs first.\n");
        return;
    }

    Song* temp = *head;
    printf("\n.'.'. Now Playing .'.'.\n");
    printf("-> Dequeued and Played: %s (%s).\n", temp->title, temp->artist);

    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    free(temp);
}

void viewPlaylist(Song* head) {
    if (head == NULL) {
        printf("\nPlaylist is empty.\n");
        return;
    }

    printf("\n.'.'. Current Playlist (Next Up is Song 1) .'.'.\n");
    Song* current = head;
    int count = 1;
    while (current != NULL) {
        printf("[%d] %s (%s) - %d sec\n", count++, current->title, current->artist, current->duration);
        current = current->next;
    }
    printf(".'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'\n");
}
void showTotalDuration(Song* head) {
    int total = 0;
    Song* current = head;
    while (current != NULL) {
        total += current->duration;
        current = current->next;
    }
    int min = total / 60;
    int sec = total % 60;
    printf("Total Duration: %d seconds (approx. %d min, %d sec)\n", total, min, sec);
}