#pragma once
#include <string>
#include "PlaylistCollectionNode.h"
#include "PlaylistSongNode.h"
class SongCollection;
using namespace std;
class PlaylistCollection
{
public:
	PlaylistCollectionNode* head;
	int size;
	PlaylistCollection();
	void addPlaylist(string playlistName, Playlist* pointer);
	void deletePlaylist(string playlistName); // run with deletePlaylist in Playlist.h
	void viewPlaylist();
	void searchPlaylistbyName(string playlistName, SongCollection *songCollection);
	void removeDeletedSonginPlaylist(string songName);
	void reset();
	void returnPlaylistbySong(string songToBeSearch);
};

