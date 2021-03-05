#pragma once
#include "SongNode.h"
#include "PlaylistCollection.h"
#include <string>

using namespace std;
class SongCollection
{
public:
	SongNode* head;
	int size;
	SongCollection(); 
	void addSongAtBeginning(string title,string singer,string duration);
	void displaySong();
	void deleteSong(string songToBeDelete,string singer,PlaylistCollection* pointer);
	void playlistSearch(PlaylistCollection* pointer);
	bool searchSong(string songToBeSearch);
};

