#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "SongLibrary.h"

using namespace std;

class Queue : public SongLibrary {
    public:    
		// common queue operations
		// implementation provided
		void displayQueue();

		// implementations not provided
		void enqueue(Song *);
		Song * dequeue();
		void clear();
		bool isEmpty();
    Song * peek();

};

#endif
