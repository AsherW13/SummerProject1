#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "Queue.h"


using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute;
    Song * tail;
	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); // NEW: copy constructor
		~SongLibrary();
		Song * getHead() const; // UPDATED: name
		void setHead(Song *); // UPDATED: name
		string getSortAttribute() const; // NEW: getter for sortAttribute
		void setSortAttribute(string); // NEW: setter for sortAttribute
		
		void performLoad(string);
		void performSave(string);
		void performSort(); // UPDATED: no parameter for sort attribute, using Song's sortAttribute member variable
		Song * performSearch(string, string, bool *, int *); // UPDATED: parameter list and return type
		void performInsertSongInOrder(Song *); // NEW: replaces addSong()
		void performRemoveSong(Song *); // UPDATED: parameter list
		void performEditSong(Song *, string, string); // UPDATED: parameter list

    // menu functions + helper functions
    void loadLibrary(SongLibrary&);
    void saveLibrary(SongLibrary&);
    void displayLibrary();
    void sortLibrary(SongLibrary&);
    void searchLibrary(SongLibrary&);
    void insertSongInLibraryOrder(SongLibrary&);
    void removeSongFromLibrary(SongLibrary&);
    void editSongInLibrary(SongLibrary&);

// queue operations:
    void UIdisplayQueue(SongLibrary&);
    void UIenqueue(SongLibrary&);
    void UIdequeue(SongLibrary&);
    void UIisEmpty(SongLibrary&);
    void UIpeek(SongLibrary&);
    void UIclear(SongLibrary&);
  
    void destroyList();
	  void displayList();

    Song * peek();
	  Song * deleteAtFront();
    void addToEnd(Song *);
};
#endif
