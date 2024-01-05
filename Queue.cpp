#include "Queue.h"

/*
Function: displayQueue()
Date Created: 4/23/23
Description: This function displays the queue by running through the linked list until null is encountered.
Input Parameters: None
Returns: None
Pre: None 
Post: the numbers in the queue are output
*/
void Queue::displayQueue() {
	Song * currNode = getHead();
	
	while (currNode != NULL) {
		currNode->displaySong();
		// progress towards BC being false
		currNode = currNode->getNext();
	}
	cout << endl;
}

/*
Function: enqueue()
Date Created: 4/23/23
Description: This function adds a value into the queue by calling the linked list function addToEnd with the new value as an argument
Input Parameters: an integer for the new value
Returns: None
Pre: None
Post: the new node is entered to the back of the queue
*/
void Queue::enqueue(Song * newSong) {
  addToEnd(newSong);
}

/*
Function: dequeue()
Date Created: 4/23/23
Description: This function removes a value from the front of the queue by calling the linked list funtion deleteAtFront and returning its value.
Input Parameters: None
Returns: the value of the node being deleted
Pre: None
Post: the value is returned
*/
Song * Queue::dequeue() {
	return deleteAtFront();
}

/*
Function: clear()
Date Created: 4/23/23
Description: this function calls the linked list function destroy list to clear the stack of its values
Input Parameters: None
Returns: None 
Pre: None
Post: the stack is emptied
*/
void Queue::clear() {
  destroyList();
}

/*
Function: isEmpty()
Date Created: 4/23/23
Description: this function checks if head is not null and returns false if head is not empty and true if it is.
Input Parameters: None
Returns: returns the bool value of true or false
Pre: None
Post: the state of the stack or queue is returned
*/
bool Queue::isEmpty() {
	if(getHead() != NULL){
    return false;
  }
  return true;
}

Song * Queue::peek(){
  if (getHead() != NULL){
    return getHead();
  }
  else{
    return NULL;
  }
}

