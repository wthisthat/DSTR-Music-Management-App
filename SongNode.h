#pragma once

#include <string>

using namespace std;
class SongNode
{
public:
	string title;
	string singer;
	string duration;
	SongNode* next;
};

