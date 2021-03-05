#include "PlaylistCollection.h"
#include "PlaylistCollectionNode.h"
#include "Playlist.h"
#include "SongCollection.h"
#include <iostream>

using namespace std; 
PlaylistCollection::PlaylistCollection() {
	this->head = NULL;
	this->size = 0;
}

void PlaylistCollection::addPlaylist(string playlistName, Playlist* pointer) {
	PlaylistCollectionNode* current = head;
	bool flag = false;
	while (current != NULL) {
		if(current->playlistName == playlistName) {
			flag = true;
			break;
		}
		else {
			current = current->next;			
		}
	}
	if(flag==false){
		PlaylistCollectionNode * newPlaylistCollectionNode= new PlaylistCollectionNode;
		newPlaylistCollectionNode->playlistName = playlistName;
		newPlaylistCollectionNode->playlistPointer = pointer;
		newPlaylistCollectionNode->next = NULL;
		if (head == NULL)
			head = newPlaylistCollectionNode;
		else {
			PlaylistCollectionNode* last = head;			
			while (last->next != NULL) 
			{
				last = last->next;
			}
			last->next = newPlaylistCollectionNode;				
		}		
		cout << "Playlist created successfully." << endl;
		size++;
	}
	else{
		cout << "Playlist existed. " << endl;
	}
}

void PlaylistCollection::deletePlaylist(string playlistName) {
	PlaylistCollectionNode* toDelete = head, * prev = NULL;
	bool check = false;	
	while (toDelete != NULL) {
		if (toDelete->playlistName==playlistName) {
			check = true;
			break; //search playlist first
		}
		prev = toDelete;
		toDelete = toDelete->next;
	}
	if (check == true) {
		if (toDelete == head) {
			head = head->next;
			toDelete->playlistPointer->deletePlaylist();
			delete toDelete;
			size--;
			cout << "Playlist deleted." << endl;
		}
		else
		{
			prev->next = toDelete->next;
			toDelete->playlistPointer->deletePlaylist();
			delete toDelete;
			size--;
			cout << "Playlist deleted." << endl;
		}
	}
	else {
		cout << "Playlist not found!" << endl;
	}
}

void PlaylistCollection::viewPlaylist() {
	PlaylistCollectionNode* current = head;
	if (head == NULL) {
		cout << "No playlist exists." << endl;
	}
	else {
		while (current != NULL) {
			cout << "Name: " << current->playlistName << "\n";
			current = current->next;
		}
	}
}

void PlaylistCollection::searchPlaylistbyName(string playlistName, SongCollection* songCollection) {
	PlaylistCollectionNode* current = head;
	bool flag = false;
	string title;
	char option;
	while (current != NULL) {
		if (current->playlistName == playlistName) {
			flag = true;
			break;
		}
		else {
			current = current->next;
		}
	}
	if (flag) {
		cout << "Playlist exists." << endl;
		while (flag) {
			cout << "\n1. Add song \n2. View songs \n3. Remove song \n4. Playlist navigation \n5. Delete playlist\n6. Back to main menu " << endl;
			cout << "Enter your option: " ;
			cin >> option;
			switch (option) {
			case '1':
			{
				songCollection->displaySong();
				current->playlistPointer->addSongsAtEnd(songCollection);
				break;
			}
			case '2':
			{
				current->playlistPointer->viewSongs();
				cout << "Number of song: " << current->playlistPointer->size << endl;
				break;
			}
			case '3':
			{
				current->playlistPointer->viewSongs(); //display song in the playlist for the user 
				cout << "Enter song title: ";
				cin.ignore('1', '\n');
				getline(cin, title);
				current->playlistPointer->removeSongs(title); // then delete according to input
				break;
			}
			case '4':
			{
				current->playlistPointer->playlistNavigation();
				break;
			}
			case '5':
			{
				deletePlaylist(playlistName);
				flag = false;
				break;
			}
			case '6':
			{
				flag = false;
				break;
			}
			default:
				cout << "Wrong input." << endl;
			}
		}
	}
	else {
		cout << "Playlist does not exixts." << endl;
	}
}

void PlaylistCollection::removeDeletedSonginPlaylist(string songToBeRemove) {
	PlaylistCollectionNode* toSearch = head;
	bool check = false;
	if (toSearch == NULL)
		cout << "Empty playlist collection." << endl;
	else {
		while (toSearch != NULL) {
			if (toSearch->playlistPointer->searchSongInPlaylist(songToBeRemove)==true) {
				toSearch->playlistPointer->removeSongs(songToBeRemove);
			}
			toSearch = toSearch->next;
		}
	}
}

void PlaylistCollection::reset() {
	PlaylistCollectionNode* current = head;
	while (head != NULL) {
		current = current->next;
		head->playlistPointer->deletePlaylist();
		delete head;
		head = current;
	}
	cout << "Playlist collection reset." << endl;
	size = 0;
}

void PlaylistCollection::returnPlaylistbySong(string songToBeSearch) {
	PlaylistCollectionNode* toSearch = head;
	bool check = false;
	while (toSearch != NULL) {
		if (toSearch->playlistPointer->searchSongInPlaylist(songToBeSearch)==true) {
			cout << "Song existed in "<<toSearch->playlistName<<endl;
		}
		toSearch = toSearch->next;
	}
}