#pragma once
#include <string>

using namespace std;
class PlaylistSongNode
{
public:
	string title;
	PlaylistSongNode* next;
	PlaylistSongNode* prev;
};

