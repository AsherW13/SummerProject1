#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"
#include "Queue.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 9;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif