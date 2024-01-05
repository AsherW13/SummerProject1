#include "Song.h"
#include <string>

/*
Function: convertToLowercase()
Date Created: 4/2/23
Description: This function takes in a string argument, and iterates through the string size and converts each element to lowercase
Input Parameters: one string variable
Returns: returns the string in lowercase
Pre: a non-empty string is created and passed in
Post: the string is output in all lowercase
*/
string convertToLowercase(string s) {
  for(int i = 0; i < s.size(); i++){
    s[i] = tolower(s[i]); 
  }
	return s;
}

/*
Function: Song()
Date Created: 4/2/23
Description: This DVC is used to assign a song to default values which are all empty strings plus the rating being assigned 1
Input Parameters: None
Returns: None
Pre: None
Post: a song is made
*/
Song::Song() {

  title = "";
  artist = "";
  genre = "";
  rating = 1;
  next = NULL;

}

/*
Function: Song()
Date Created: 4/2/23
Description: This EVC is used to assign a song the parameters that are being passed in, in lowercase
Input Parameters: song attributes
Returns: None
Pre: None
Post: a song is made
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
  
  title = convertToLowercase(titleParam);
  artist = convertToLowercase(artistParam);
  genre = convertToLowercase(genreParam);
  setRating(ratingParam);
  next = NULL;
  
}

/*
Function: Song()
Date Created: 4/2/23
Description: This Song copy constructor assigns the title of a song to the other songs attributes that is being passed in 
Input Parameters: a reference to another Song object
Returns: None
Pre: None
Post: the base song object is successfully assigned to the other song object
*/
Song::Song(const Song& other) {
  title = other.title;
  artist = other.artist;
  genre = other.genre;
  rating = other.rating;
  
	next = NULL;
}

/*
Function: getTitle()
Date Created: 4/2/23
Description: Returns the title of a song
Input Parameters: None
Returns: the title of a song
Pre: a song with a title exists
Post: the title is returned to the console for the user
*/
string Song::getTitle() {
	return title;
}

/*
Function: setTitle()
Date Created: 4/2/23
Description: This function sets the title to the parameter being passed in while converting to lowercase
Input Parameters: title of the new song
Returns: None
Pre: None
Post: a song is made with a title
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

/*
Function: getArtist()
Date Created: 4/2/23
Description: This function returns the artist name
Input Parameters: None
Returns: artist name
Pre: a song exists
Post: the artist name is returned to the console
*/
string Song::getArtist() {
	return artist;
}

/*
Function: setArtist()
Date Created: 4/2/23
Description: This function sets the artist to the parameter bing passed in while also converting the artist name to lowercase
Input Parameters: new artist name 
Returns: None
Pre: None
Post: a song is created with a new artist name
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

/*
Function: getGenre()
Date Created: 4/2/23
Description: this function returns the genre of a song
Input Parameters: None
Returns: returns the song genre
Pre: a song already exists
Post: the genre of a song is output to the console
*/
string Song::getGenre() {
	return genre;
}

/*
Function: setGenre()
Date Created: 4/2/23
Description: this function sets the genre of a song with the parameter being passed in while also converting to lowercase
Input Parameters: new genre name for a song
Returns: None
Pre: None
Post: a song is assigned a new genre name
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

/*
Function: getRating()
Date Created: 4/2/23
Description: this function returns the rating of a song
Input Parameters: None
Returns: the rating of a song
Pre: a song already exists
Post: the rating is output to the console
*/
int Song::getRating() {
	return rating;
}

/*
Function: setRating()
Date Created: 4/2/23
Description: this function checks to make sure the rating being passed in is within the min and max ratings and assigns it accordingly
Input Parameters: a new rating for a song
Returns: None
Pre: None
Post: a song is assigned a new rating
*/
void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

/*
Function: getNext()
Date Created: 4/2/23
Description: This function returns the next node that the function is being called on points to
Input Parameters: None
Returns: returns the next node
Pre: None
Post: the status of next is returned
*/
Song * Song::getNext() {
	return next;
}

/*
Function: setNext()
Date Created: 4/2/23
Description: This function takes in a song object and assigns the next of the object its being called on to that new node
Input Parameters: pointer of a song object for the new next pointer
Returns: None
Pre: None
Post: the next pointer is successfully changed
*/
void Song::setNext(Song * newNext) {
	next = newNext;
}

/*
Function: getPrev()
Date:
Description:
Input Parameters:
Returns:
Pre:
Post:
*/
Song * Song::getPrev() {
  return prev;
}

/*
Function: setPrev()
Date:
Description:
Input Parameters:
Returns:
Pre:
Post:
*/
void Song::setPrev(Song * newPrev){
  prev = newPrev;
}
/*
Function: getStringAttributeValue()
Date Created: 4/2/23
Description: This function has an if else code block that checks to see if the attribute is equal to one of the song attributes and returns that attribute. Returns an empty string if that attribute is not found
Input Parameters: string parametet for a song attribute
Returns: the appropriate song attribute or empty string
Pre: a song exists and the user is prompted to type an attribute
Post: the attribute or empty string is returned
*/
string Song::getStringAttributeValue(string attribute) {
  
	if(attribute == "title"){
    return getTitle();
  }
  else if(attribute == "artist"){
    return getArtist();
  }
  else if(attribute == "genre"){
    return getGenre();
  }
  else if(attribute == "rating"){
    return to_string(getRating());
  }
  else {
    return "";
  }
  
}

/*
Function: displaySong()
Date Created: 4/2/23
Description: this function displays all attributes of a song 
Input Parameters: None
Returns: None
Pre: a song exists to be output
Post: the song attributes are output to the console
*/
void Song::displaySong() {
  
cout << title << endl;
cout << artist<< endl;
cout << genre << endl;
cout << rating << endl;
cout << endl;
cout << endl;
  
}