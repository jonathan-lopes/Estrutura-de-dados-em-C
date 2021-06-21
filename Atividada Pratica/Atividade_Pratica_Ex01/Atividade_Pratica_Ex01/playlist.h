#pragma once
typedef struct playlist
{
	char nameBand[30];
	char nameMusic[30];
	char duration[7];
}Playlist;

typedef struct node* List;

#define PATH "C:\\Users\\Jonathan\\Music\\Playlist.txt"

List* createList();
void freeList(List* head);
int sizeList(List* head);
_Bool isEmpty(List* head);
int insertFist(List* head, Playlist music);
int insertFinal(List* head, Playlist music);
int insertMiddle(List* head, Playlist music, int pos);
int removeList(List* head, char music[]);
void printList(List* head);
int fileExists(const char* cpfileName);
void saveFile(List* head);
void removeFile();
void buffer();