#include "SongLibrary.h"
#include <istream>
#include <string>

/*
Function: SongLibrary()
Date Created: 4/2/23
Description: This constructor initializes the head of the list to NULL and sets the value of the attribute to sort by to title
Input Parameters: None
Returns: None
Pre: None
Post: a basic linked list is created
*/
SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

/*
Function: SongLibrary()
Date Created: 4/2/23
Description: This copy constructor assigns the sort attribute to the value of the other song library. Traverses through the other list and assigns each new song to the end of the list
Input Parameters: constant reference to another song library
Returns: None
Pre: None 
Post: None
*/
SongLibrary::SongLibrary(const SongLibrary& other) {
  
    sortAttribute = other.getSortAttribute();
    head = NULL;
  
    Song * currNode = other.head;

    while(currNode != NULL){
      Song * newSong = new Song(*currNode);
      addToEnd(newSong);
      currNode = currNode->getNext();
    }
  
}

/*
Function: ~SongLibrary()
Date Created: 4/2/23
Description: This destructor traverses through the linked list deleting each node and finally assigns head to NULL
Input Parameters: None
Returns: None
Pre: None
Post: None
*/
SongLibrary::~SongLibrary() {

  Song * currNode = head;
  Song * nextNode = NULL;
  while(currNode != NULL){
    nextNode = currNode->getNext();
    delete currNode;
    currNode = nextNode;
  }
  head = NULL;
}

/*
Function: getHead()
Date Created: 4/2/23
Description: This function returns the head of the list
Input Parameters: None
Returns: returns the pointer to the head of the list
Pre: None
Post: value of head is returned
*/
Song * SongLibrary::getHead() const {
	return head;
}

/*
Function: setHead()
Date Created: 4/2/23
Description: This function traverses through the list deleting each node and finally assigning head to the pointer being passed in for the new head value
Input Parameters: Song pointer for the new head
Returns: None
Pre: None
Post: head is successfully assigned
*/
void SongLibrary::setHead(Song * newHead) {
  
	if (head != NULL) {
    Song * currNode = head;
    while(currNode->getNext() != NULL){
      Song * nextNode = currNode->getNext();
      delete currNode;
      currNode = nextNode;
    }  
  }
  
	head = newHead;
}

/*
Function: getSortAttribute()
Date Created: 4/2/23
Description: returns the value of the sortAttribute
Input Parameters: None
Returns: the string of sortAttribute
Pre: None
Post: None
*/
string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

/*
Function: setSortAttribute()
Date Created: 4/2/23
Description: This function assigns the public variable of sortAttribute to the new value being passed in
Input Parameters: one string parameter for the new value
Returns: None
Pre: None
Post: the sortAttribute is successfully updated
*/
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

/*
Function: performLoad()
Date Created: 4/2/23
Description: This function first deletes the current list so it is empty before opening and reading in the new songs. While it is reading in each song, one dynamically allocated song is being created and is inserted via the perform insert song in order function
Input Parameters: one string parameter for the name of the file to open
Returns: None
Pre: None
Post: the file is read in and the list is filled with data
*/
void SongLibrary::performLoad(string filename) {
  
	ifstream inputFile;
  string line = "", title = "", artist = "", genre = "", ratingString = "";
  int rating = 0;

  Song * currNode = head;
  Song * nextNode = NULL;
  
  while(currNode != NULL){
    nextNode = currNode->getNext();
    currNode->setNext(NULL);
    delete currNode;
    currNode = nextNode;
  }
  head = NULL;
  
  inputFile.open(filename);
  if(inputFile.is_open()){
    cout << "file opened" << endl;
  }
  else{
    cout << "failed to open file" << endl;
  }
  while(getline(inputFile, line)){
    
    if(line.empty()){
      continue;
    }
    
    title = line;
    getline(inputFile, line);
    artist = line;
    getline(inputFile, line);
    genre = line;
    getline(inputFile, line);
    rating = stoi(line);

    Song * song = new Song(title, artist, genre, rating);
    
    performInsertSongInOrder(song);
  }
  
  inputFile.close();

}

/*
Function: performSave()
Date Created: 4/2/23
Description: This function opens the output file. Traverses through the list and outputs each attribute of the song to the file. 
Input Parameters: one string parameter for the name of the file
Returns: None
Pre: None
Post: the output file is filled with data
*/
void SongLibrary::performSave(string filename) {
	ofstream outputFile;
  Song * currNode = head;
  outputFile.open(filename);
  if(outputFile.is_open()){
    cout << "output filed opened" << endl;
  }
  else {
    cout << "failed to open file " << endl;
  }
  while(currNode != NULL){
    outputFile << currNode->getTitle() << endl;
    outputFile << currNode->getArtist() << endl;
    outputFile << currNode->getGenre() << endl;
    outputFile << currNode->getRating() << endl;
    outputFile << endl;
    currNode = currNode->getNext();
  }
  outputFile.close();
}

/*
Function: performSort()
Date Created: 4/2/23
Description: this function sorts the list by the given sortAttribute value
Input Parameters: None
Returns: None
Pre: None
Post: the list is sorted
*/
void SongLibrary::performSort() {
  
  SongLibrary tempLibrary;
  tempLibrary.setSortAttribute(getSortAttribute());

  Song* currNode = head;
  
    while (currNode != NULL) {
      Song * newSong = new Song(*currNode);
      tempLibrary.performInsertSongInOrder(newSong);
      currNode = currNode->getNext();
    }
  
  head = tempLibrary.head;
  tempLibrary.head = NULL;
  
}

/*
Function: performSearch()
Date Created: 4/2/23
Description: this function traverses through the list and looks for a node that has the same attribute value as the parameter. if the node is found, then it returns the node, if not returns NULL
Input Parameters: two string parameters for the search attribute and its value. 1 bool pointer for whether or not the node was found and an int pointer for the index
Returns: returns a pointer to a song object
Pre: a list is created to search for
Post: None
*/
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
  
  Song * currNode = head;
  int i = 0;
  
	  while(currNode != NULL){
    if(currNode->getStringAttributeValue(searchAttribute) == searchAttributeValue){
      *found = true;
      *index = i;
      return currNode;
    }
      i++;
      currNode = currNode->getNext();
  }
  
  *found = false;
  *index = -1;
	return NULL;
}

/*
Function: performInsertSonInOrder()
Date Created: 4/2/23
Description: This function inserts a song into the list in its sorted position based on its attribute value
Input Parameters: one song pointer
Returns: None
Pre: None
Post: the song is inserted in its correct position
*/
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {

	if(head == NULL){
    head = songToInsert;
  }
  else{
    Song * currSong = head;
    Song * prevSong = NULL;

    while(currSong != NULL && currSong->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute)){
      prevSong = currSong;
      currSong = currSong->getNext();
    }
    if(prevSong == NULL){
      songToInsert->setNext(head);
      head = songToInsert;
    }
    else{
      songToInsert->setNext(currSong);
      prevSong->setNext(songToInsert);
    }
  }
}

/*
Function: performRemoveSong()
Date Created: 4/2/23
Description: This function traverses through the list look for a song that has the same title as the songToRemoves title then it removes and deletes that node
Input Parameters: one song pointer
Returns: None
Pre: None 
Post: the song is successfully removed
*/
void SongLibrary::performRemoveSong(Song * songToRemove) {
  Song * currNode = head;
  Song * prevNode = NULL;
  if(head != NULL){
    currNode = head;
    if(head->getTitle() == songToRemove->getTitle()){
      head = head->getNext();
      delete currNode;
    }
    else{
      while(currNode != NULL && currNode->getTitle() != songToRemove->getTitle()){
        prevNode = currNode;
        currNode = currNode->getNext();
      }
      if(currNode != NULL){
        prevNode->setNext(currNode->getNext());
        delete currNode;
      }
    }
  }

}

/*
Function: performEditSong()
Date Created: 4/2/23
Description: This function traverses through the list and finds the song that matches the parameters song, if there is a match it looks for which attribute value was passed in and edits that value
Input Parameters: one song pointer, and two string variables for the attribute and its value
Returns: None
Pre: None
Post: the song is successfully edited
*/
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {
    Song * currNode = head;

    while(currNode != NULL){
      if(currNode->getTitle() == songToEdit->getTitle()){
        songToEdit = currNode;
        if(attribute == "title"){
          songToEdit->setTitle(newAttributeValue);
        }
        else if(attribute == "artist"){
          songToEdit->setArtist(newAttributeValue);
        }
        else if(attribute == "genre"){
          songToEdit->setGenre(newAttributeValue);
        }
        else if(attribute == "rating"){
          songToEdit->setRating(stoi(newAttributeValue));
        }
        else{
          cout << "unknown attribute";
          return;
        }
      }
      currNode = currNode->getNext();
    }
}

/*
Function: loadLibrary()
Date Created: 4/2/23
Description: This function prompts the user for the name of the file to open, grabs that value and calls performLoad on that value
Input Parameters: one reference to the songlibrary to work on
Returns: None
Pre: the SongLibrary to work on is initialized
Post: the text file is read from
*/
void SongLibrary::loadLibrary(SongLibrary & lib){
  string filename;
  cout << "enter song file name to open: " << endl;
  getline(cin, filename);
  lib.performLoad(filename);
}

/*
Function: saveLibrary()
Date Created: 4/2/23
Description: This function prompts the user for a string name for the file to write to. calls the performSave function to write the current library to the file
Input Parameters: one SongLibrary reference
Returns: None
Pre: None 
Post: the output file is written to
*/
void SongLibrary::saveLibrary(SongLibrary & lib){
  string filename;
  cout << "enter ../SaveLibrary.txt to write to the file: " << endl;
  getline(cin, filename);
  lib.performSave(filename);
}

/*
Function: displayLibrary()
Date Created: 4/2/23
Description: This function traverses the library displaying each song
Input Parameters: None
Returns: None
Pre: None
Post: the songs are output to the console
*/
void SongLibrary::displayLibrary(){
  cout << "--SONG LIBRARY--" << endl << endl;
  Song * currNode = head;
  while(currNode != NULL){
    currNode->displaySong();
    currNode = currNode->getNext();
  }
}

/*
Function: sortLibrary()
Date Created: 4/2/23
Description: This function prompts the user for a value to sort by, calls the member function to set the sort attribute value and then calls to sort the library
Input Parameters: one SongLibrary reference 
Returns: None
Pre: None
Post: the sort attribute is updated and the list is sorted
*/
void SongLibrary::sortLibrary(SongLibrary & lib){
  string attribute;
  cout << "enter attribute you would like to sort by: " << endl;
  getline(cin, attribute);
  lib.setSortAttribute(attribute);
  lib.performSort();
}

/*
Function: searchLibrary()
Date Created: 4/2/23
Description: This function prompts the user for the attribute to search for and its value, calls the performSearch member function and providing output on if the song was found or not
Input Parameters: one SongLibrary reference
Returns: None
Pre: None 
Post: the song is either output to the console or not
*/
void SongLibrary::searchLibrary(SongLibrary & lib) {
  string searchAttribute;
  string searchAttributeValue;
  bool foundSong;
  int index;
  cout << "Please enter the attribute you would like to search for: ";
  getline(cin, searchAttribute);
  cout <<  "now the value within that attribute: ";
  getline(cin, searchAttributeValue);
  Song * song = lib.performSearch(searchAttribute, searchAttributeValue, &foundSong, &index);
  if(song){
    cout << "found song at index: " << index << endl;
    cout << "title: " << song->getTitle() << endl;
    cout << "artist: " << song->getArtist() << endl;
    cout << "genre: " << song->getGenre() << endl;
    cout << "rating: " << song->getRating() << endl;
    cout << endl;
  }
  else{
    cout << "song not found with: " << searchAttributeValue << endl;
    return;
  }
}

/*
Function: insertSongInLibraryOrder
Date Created: 4/2/23
Description: Prompts the user for all song attributes and then proceeds to call a member function to insert the song in order
Input Parameters: one SongLibrary reference
Returns: None 
Pre: None
Post: the song is inserted in its correct position
*/
void SongLibrary::insertSongInLibraryOrder(SongLibrary& lib){
  string title = "", artist = "", genre = "";
  int rating = 0;
  Song * newSong = new Song();
  cout << "please enter song title: ";
  getline(cin, title);
  newSong->setTitle(title);
  cout << "please enter song artist: ";
  getline(cin, artist);
  newSong->setArtist(artist);
  cout << "please enter song genre: ";
  getline(cin, genre);
  newSong->setGenre(genre);
  cout << "please enter your song rating: ";
  cin >> rating;
  newSong->setRating(rating);

  lib.performInsertSongInOrder(newSong);

}

/*
Function: removeSongFromLibrary()
Date Created: 4/2/23
Description: Prompts the user for the title of the song they want to remove, sets the value of a Song pointer to that value, calls the member function with that song pointer as an argument
Input Parameters: one SongLibrary()
Returns: None
Pre: None
Post: the song is successfully removed
*/
void SongLibrary::removeSongFromLibrary(SongLibrary & lib){
  Song * newSong = new Song();
  string title;
  cout << "Please enter the title of the song you would like to remove: " << endl;
  cout << "Title: ";
  getline(cin, title);
  newSong->setTitle(title);
  lib.performRemoveSong(newSong);
  
}

/*
Function: editSongInLibrary()
Date Created: 4/2/23
Description: Prompts the user for the title of the song to edit, the attribute within that song and the new value of that attribute. proceeds to call the member function with those values passed as arguments
Input Parameters: one SongLibrary reference
Returns: None
Pre: None
Post: the song is successfully opened
*/
void SongLibrary::editSongInLibrary(SongLibrary & lib){
  Song * editedSong = new Song();
  string title;
  string attribute;
  string newAttributeValue;

  cout << "Enter first the title of the song you would like to edit: ";
  getline(cin, title);
  editedSong->setTitle(title);
  cout << "Next, enter the attribute of the song to edit: ";
  getline(cin, attribute);
  cout << "Finally enter the value of the attribute: ";
  getline(cin, newAttributeValue);
  lib.performEditSong(editedSong, attribute, newAttributeValue);

  delete editedSong;
}
void SongLibrary::UIdisplayQueue(SongLibrary & lib){
  cout << "Welcome to the your song queue, here is your current queue:" << endl;
  Queue q;
  q.displayQueue();
}

void SongLibrary::UIenqueue(SongLibrary & lib){
  Queue q;
  Song * newSong = new Song;
  string title = "";
  string artist = "";
  string genre = "";
  int rating = 0;
  cout << "to add a song to your queue please give below the title, artist, genre, and rating for the song" << endl;
  cout << "Title: ";
  cin >> title;
  cout << "Artist: ";
  cin >> title;
  cout << "Genre: ";
  cin >> title;
  cout << "Rating: ";
  cin >> title;
  newSong->setTitle(title);
  newSong->setArtist(artist);
  newSong->setGenre(genre);
  newSong->setRating(rating);
  q.enqueue(newSong);
}

void SongLibrary::UIdequeue(SongLibrary & lib){
  Queue q;
  Song * deletedSong = new Song;
  cout << "Removing the song from the front of your queue" << endl;
  deletedSong = q.dequeue();
  cout << "The song dequeued was: " << endl;
  deletedSong->displaySong();
}
void SongLibrary::UIisEmpty(SongLibrary & lib){
  Queue q;
  cout << "The state of your queue is(0 for False, 1 for True): " << endl;
  bool queueCheck = q.isEmpty();
  
  cout << queueCheck << endl;
}

void SongLibrary::UIpeek(SongLibrary & lib){
  Queue q;
  cout << "The item that will be played next from your queue is: " << endl;
  cout << q.peek();
}

void SongLibrary::UIclear(SongLibrary & lib){
  Queue q;
  cout << "Clearing the queue now..." << endl;
  q.clear();
  cout << "Your queue is now empty" << endl;
}

/*
Function: addToEnd()
Date Created: 4/2/23
Description: This function traverses through the list and inserts the new song at the end of the list
Input Parameters: one song pointer
Returns: None
Pre: None
Post: the song is inserted into the end of the list
*/
void SongLibrary::addToEnd(Song * newSong){

  if(head == NULL){
    head = newSong;
    return;
  }
  else{
    
    Song * currNode;
    currNode = head;
  
    while(currNode->getNext() != NULL){
      currNode = currNode->getNext(); 
    }
  
    currNode->setNext(newSong);
    newSong->setNext(NULL);
  }
}

void SongLibrary::destroyList(){
  Song * currNode = head;
	Song * nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->getNext();
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}
void SongLibrary::displayList(){
  Song * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		currNode->displaySong();
		// progress towards BC being false
		currNode = currNode->getNext();
	}
  cout << "<-tail->";
	cout << "NULL" << endl;

}

Song * SongLibrary::peek(){
  if (head != NULL){
    return head;
  }
  else{
    return NULL;
  }
}
	   	
Song * SongLibrary::deleteAtFront(){
  if(head != NULL){
    Song * nodeToDelete = head;
    head = head->getNext();
    if(head !=NULL){
      head->setPrev(NULL);
    }
    else{
      tail = NULL;
    }
    Song * tempSong = new Song;
    tempSong->setArtist(nodeToDelete->getArtist());
    tempSong->setTitle(nodeToDelete->getTitle());
    tempSong->setGenre(nodeToDelete->getGenre());
    tempSong->setRating(nodeToDelete->getRating());
    
    delete nodeToDelete;
    return tempSong;
  }
  else{
    return NULL;
  }
}
