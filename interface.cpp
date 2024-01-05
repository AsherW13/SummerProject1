#include "interface.h"
#include <istream>
#include <string>

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Insert song in order" << endl;
	cout << "7) Remove song" << endl;
	cout << "8) Edit song" << endl;
  cout << "9) Exit" << endl;
  /*
	cout << "9) Display queue" << endl;
  cout << "10) Enqueue" << endl;
  cout << "11) Dequeue" << endl;
  cout << "12) Check if queue is empty" << endl;
  cout << "13) First item of queue" << endl;
  cout << "14) Clear the list" << endl;
  cout << "15) Exit" << endl;
  */
  
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

void executeUserChoice(int choice, SongLibrary& lib) {
	switch (choice) {
		case 1:
			lib.loadLibrary(lib);
			break;
		case 2:
			lib.saveLibrary(lib);
			break;
		case 3: 
			lib.displayLibrary();
			break;
		case 4:
			lib.sortLibrary(lib);
			break;
		case 5:
			lib.searchLibrary(lib);
			break;
		case 6:
			lib.insertSongInLibraryOrder(lib);
			break;
		case 7:
			lib.removeSongFromLibrary(lib);
			break;
		case 8:
			lib.editSongInLibrary(lib);
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}
