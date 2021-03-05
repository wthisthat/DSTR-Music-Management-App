#include "SongCollection.h"
#include "PlaylistCollection.h"
#include <iostream>

using namespace std;
SongCollection::SongCollection() {
	this->size = 0;
	this->head = NULL;

}
void SongCollection::addSongAtBeginning(string title,string singer,string duration) {
	SongNode* current = head;
	bool flag = false;
	while (current != NULL) {
		if (current->title == title && current->singer == singer) {
			flag = true;
			break;
		}
		else {
			current = current->next;			
		}
	}
	if (flag==false) {
		SongNode* song = new SongNode; //create new object node for song
		song->title = title;
		song->singer = singer;
		song->duration = duration;
		song->next=head;
		head = song;
		size++;
		cout << "Song added succesfully."<<endl;
	}
	else {
		cout<<"Song already existed in song collection."<<endl;
	}
}

void SongCollection::deleteSong(string songToBeDelete,string singer, PlaylistCollection* pointer) {
	SongNode* toDelete = head, * prev = NULL;
	bool check = false;	
	if (toDelete == NULL)
		cout << "Empty song collection." << endl;
	else {
		while (toDelete != NULL) {
			if (toDelete->title == songToBeDelete && toDelete->singer == singer) {
				check = true;
				break; //search song first
			}
			prev = toDelete;
			toDelete = toDelete->next;
		}
	}
	if (check) {
		if (toDelete == head) {
			head = head->next;
			pointer->removeDeletedSonginPlaylist(songToBeDelete); //update in playlist
			delete toDelete;
			size--;
			cout << "Song deleted." << endl;
		}
		else
		{
			prev->next = toDelete->next;
			pointer->removeDeletedSonginPlaylist(songToBeDelete); //update in playlist
			delete toDelete;
			size--;
			cout << "Song deleted." << endl;
		}
	}
	else {
		cout << "Song not found!" << endl;
	}
}

void SongCollection::displaySong() { 
	SongNode* current = head;
	if (head == NULL) {
		cout << "No song exists in song collection." << endl;
	}
	else {
		while (current != NULL) {
			cout << "Title: " << current->title << "\t";
			cout << "Singer: " << current->singer << "\t";
			cout << "Duration: " << current->duration << endl; 
			current = current->next;
		}
	}
}

bool SongCollection::searchSong(string songToBeSearch) {
	SongNode* toSearch = head;
	bool check = false;
	if (toSearch == NULL)
		cout << "Empty song list." << endl;
	else {
		while (toSearch != NULL) {
			if (toSearch->title == songToBeSearch) {
				check = true;
				break; 
			}
			toSearch = toSearch->next;
		}
		if (check) {
			cout << "Song exists in song collection!" << endl;
			cout << "Singer: " << toSearch->singer << "\t";
			cout << "Duration: " << toSearch->duration << endl;
		}
		else {
			cout << "Song not exists in song collection!" << endl;
		}
	}
	return check;
}

void SongCollection::playlistSearch(PlaylistCollection* pointer) {
	displaySong();
	string songToBeSearch;
	bool check;
	cout<<"Enter song title to be searched in playlist: "<<endl;
	cin.ignore('1', '\n');
	getline(cin, songToBeSearch);
	check=searchSong(songToBeSearch);
	if(check){	
		pointer->returnPlaylistbySong(songToBeSearch);
	}
	else{
		cout << "No such song existed. " << endl;
	}

}

