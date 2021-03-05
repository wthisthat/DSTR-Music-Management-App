#pragma once
#include <string>
#include "Playlist.h"
using namespace std;
class PlaylistCollectionNode
{
public:
	string playlistName;
	Playlist* playlistPointer;
	PlaylistCollectionNode* next;
};

