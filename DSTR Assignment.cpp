// DSTR Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SongCollection.h"
#include "Playlist.h"
#include "PlaylistCollection.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{   

    bool exit = false;
    SongCollection * songCollection = new SongCollection;
    PlaylistCollection* playlistCollection = new PlaylistCollection;
    while (exit==false) {
        cout << "\nWelcome to Music Management Application." << endl;
        cout << "1. Song Collection \n2. Playlist \n3. Exit \nEnter your option:  "<<endl;
        char opt1;
        cin >> opt1;  
        switch (opt1) {
        case '1':     
            cout << "\n1. Add songs \n2. Display songs \n3. Delete songs \n4. Search song \n5. Playlist search \n6. Back to main menu" << endl;
            cout << "Enter your option: ";
            char opt2;
            cin >> opt2;
            switch (opt2) {
                case '1':
                {
                string songTitle, singer, duration;
                cout << "Please enter song name: " << endl;
                cin.ignore('1', '\n');
                getline(cin, songTitle);
                cout << "Please enter singer: " << endl;
                getline(cin, singer);
                cout << "Please enter duration (in seconds): " << endl;
                getline(cin, duration);
                songCollection->addSongAtBeginning(songTitle, singer, duration);
                break;
                }
                case '2':
                {
                    songCollection->displaySong();
                    cout << "Number of song: " << songCollection->size << endl;
                    break;
                }
                case '3':
                {
                    string songToBeDelete,singer;
                    cout << "Displaying all songs." << endl;
                    songCollection->displaySong();
                    cout << "Please enter song title: " << endl;
                    cin.ignore('1', '\n');
                    getline(cin, songToBeDelete);
                    cout << "Please enter singer: " << endl;
                    getline(cin, singer);
                    songCollection->deleteSong(songToBeDelete,singer,playlistCollection);
                    break;
                }
                case '4':
                {
                    string songToBeSearch;
                    cout << "Enter song title: " << endl;
                    cin.ignore('1', '\n');
                    getline(cin, songToBeSearch);
                    songCollection->searchSong(songToBeSearch);
                    break;
                }
                case '5':
                {
                    songCollection->playlistSearch(playlistCollection);
                    break;
                }
                case '6':
                    break;
                default:
                    cout << "Input Error." << endl;                           
            }
            break;
        case '2':
            cout << "\n1. Create playlist \n2. View playlist \n3. Select playlist \n4. Reset \n5. Back to main menu" << endl;
            cout << "Enter your option: ";
            char opt3;
            cin >> opt3;
            switch (opt3) {
            case '1': 
            {
                Playlist* playlist = new Playlist;
                string playlistName;
                cout << "Enter the name of the playlist: ";
                cin.ignore('1', '\n');
                getline(cin, playlistName);
                playlistCollection->addPlaylist(playlistName, playlist);
                break;
            }
            case '2':
            {
                playlistCollection->viewPlaylist();
                cout << "Number of playlist: " << playlistCollection->size << endl;
                break;
            }
            case '3':
            {
                string playlistName;
                playlistCollection->viewPlaylist();
                cout << "Enter the name of the playlist: ";
                cin.ignore('1', '\n');
                getline(cin, playlistName);
                playlistCollection->searchPlaylistbyName(playlistName, songCollection);
                break;
            }
            case '4':
                playlistCollection->reset();
                break;
            case '5':
                break;
            default:
                cout << "Input Error." << endl;
            }
            break;
        case '3':
            exit = true;
            break;
        default:
            cout << "Input Error." << endl;
        }
    }
}
