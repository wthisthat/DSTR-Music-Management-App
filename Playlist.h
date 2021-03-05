#pragma once
#include <string>
#include "PlaylistSongNode.h"
class SongCollection;
using namespace std;
class Playlist
{
public:
	PlaylistSongNode* head;
	PlaylistSongNode* tail;
	int size;
	Playlist();
	void addSongsAtEnd(SongCollection* sc);
	void viewSongs();
	void removeSongs(string title);
	void playlistNavigation(); //if next ==NULL, select repeat/ end
	void deletePlaylist();
	bool searchSongInPlaylist(string songToBeSearch);
};

