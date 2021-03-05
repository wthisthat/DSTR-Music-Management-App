#include "Playlist.h"
#include "SongCollection.h"
#include <iostream>
#include <string>
using namespace std;
Playlist::Playlist()
{
	this->size = 0;
	this->head = NULL;
	this->tail = NULL;

}
void Playlist::addSongsAtEnd(SongCollection* sc) {
	PlaylistSongNode* current = head;
	bool flag = false;
	string title;
	cout << "Enter song title: ";
	cin.ignore('1', '\n');
	getline(cin, title);
	if (sc->searchSong(title)) {
		while (current != NULL) {
			if (current->title == title) {
				flag = true;
				break;
			}
			else {
				current = current->next;
			}
		}
		if (flag == false) {
			PlaylistSongNode* newPlaylistSongNode = new PlaylistSongNode;
			newPlaylistSongNode->title = title;
			newPlaylistSongNode->next = NULL;
			newPlaylistSongNode->prev = tail;
			tail = newPlaylistSongNode;
			if (head == NULL) {//inserting to an empty list
				head = newPlaylistSongNode;
			}
			else {
				newPlaylistSongNode->prev->next = newPlaylistSongNode;
				
			}
			cout << "Song added successfully." << endl;
			size++;
		}
		else {
			cout << "Song already existed in playlist." << endl;
		}
	}
	else {
		cout << "Invalid song. Song does not exist in Song Collection." << endl;
	}
}
void Playlist::viewSongs() {
	PlaylistSongNode* current = head;
	if (head == NULL) {
		cout << "Empty playlist." << endl;
	}
	else {
		while (current != NULL) {
			cout << "Title: " << current->title <<"\n";
			current = current->next;
		}
	}
}

void Playlist::removeSongs(string title) {
	PlaylistSongNode* toDelete = head;
	bool check = false;	
	if (toDelete == NULL)
		cout << "Empty song list." << endl;
	else {
		while (toDelete != NULL) {
			if (toDelete->title == title) {
				check = true;
				break; //search song first
			}
			toDelete = toDelete->next;
		}
	}
	if (check) {
		if (toDelete->next == NULL && toDelete->prev == NULL) {
			delete toDelete;
			head = NULL;
			tail = NULL;
			size--;
			cout << "Song deleted in playlist." << endl;
		}
		else if (toDelete == head) {
			head->next->prev= NULL;
			head = head->next;
			delete toDelete;
			size--;
			cout << "Song deleted in playlist." << endl;
		}
		else if (toDelete == tail){
			tail->prev->next = NULL;
			tail = tail->prev;
			delete toDelete;
			size--;
			cout << "Song deleted in playlist." << endl;
		}
		else{
			toDelete->prev->next = toDelete->next;
			toDelete->next->prev = toDelete->prev;
			delete toDelete;
			size--;
		}	
	}
	else {
		cout << "Song not found!" << endl;
	}
}

void Playlist::playlistNavigation() {
	PlaylistSongNode* current = head;
	if (current == NULL) {
		cout << "Playlist is empty." << endl;
	}
	else{
		bool play = true;
		char option;
		while (play) {
			cout << "Current playing: " << current->title << endl;
			if (current == head) {
				cout << "\nEnter 1 to next song." << endl<<"Enter 5 to loop current song once." << endl << "Enter 0 to stop playing songs." << endl;
				cin >> option;
				switch (option) 
				{
				case '1':
					current = current->next;
					cout << "Next song is: " << current->title << endl;
					break;
				case '5': 
					cout << "Looping:" << current->title << endl;
					break;
				case '0':
					play = false;
					cout << "Playlist will be stopped." << endl;
					break;
				default:
					cout << "Wrong input." << endl;
				}
			}
			else if (current == tail)
			{
				cout << "Enter 2 to previous song."<<endl<<"Enter 3 to repeat the playlist."<<endl<< "Enter 5 to loop current song once." << endl<<
					"Enter 0 to stop playlist." << endl;
				cin >> option;
				switch (option) 
				{
				case '2':
					current = current->prev;
					cout << "Previous song is: " << current->title <<endl;
					break;
				case '3':
					current=head;
					cout<<"Repeating playlist"<<endl;
					break;
				case '5':
					cout << "Looping:" << current->title << endl;
					break;
				case '0':
					play = false;
					cout << "Playlist will be stopped." << endl;
					break;
				default:
					cout << "Wrong input." << endl;
				}

			}
			else {
				cout << "Enter 1 to next song." << endl << "Enter 2 to previous song." << endl << "Enter 5 to loop current song once." << endl<<
					"Enter 0 to stop playlist." << endl;
				cin >> option;
				switch(option)
				{
				case '1':
					current = current->next;
					cout << "Next song is: " << current->title << endl;
					break;
				case '2':
					current = current->prev;
					cout << "Previous song is: " << current->title <<endl;
					break;
				case '5':
					cout << "Looping:" << current->title << endl;
					break;
				case '0':
					play = false;
					cout << "Playlist will be stopped." << endl;
					break;
				default:
					cout << "Wrong input." << endl;
				}			
			}
		}
		cout << "Playlist stopped." << endl;
	}	
}

void Playlist::deletePlaylist() {
	PlaylistSongNode* current = head;
	while (head != NULL) {
		current = current->next;
		delete head;
		head = current;
	}
	size = 0;
}

bool Playlist::searchSongInPlaylist(string songToBeSearch) {
	PlaylistSongNode* toSearch = head;
	bool check = false;
	while (toSearch != NULL) {
		if (toSearch->title == songToBeSearch) {
			check = true;
			break;
		}
		toSearch = toSearch->next;
	}
	return check;
}