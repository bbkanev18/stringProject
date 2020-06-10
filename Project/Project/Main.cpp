// Include and Using::::::>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Header Files ::::::>
#include "FizzBuzz.h"
#include "HangMan.h"
#include "MainFunctions.h"

// Structures ::::::>


// Functions - Declaration ::::::>
void gameMenu();

void mainMenu();

// Main ::::::>
int main()
{
	gameMenu();
}

// Functions - Definition ::::::>
void gameMenu()
{
	bool inLoop = true;
	while (inLoop)
	{
		system("CLS");

		titleMsg("Choose a game");
		cout << "Esc. Quit...\n1. FizzBuzz...\n2. Hangman...\n";

		switch (_getch())
		{
		case 27: // Esc.
			inLoop = false;
			break;
		case '1':
			f_main();
			break;
		case '2':
			h_main();
			break;
		default:
			Msg();
			break;
		}


	}
}

void mainMenu()
{
	bool inLoop = true;
	while (inLoop)
	{
		system("CLS");

		titleMsg("Main Menu");
		cout << "Esc. Quit...\n1. Games...\n2. About us...\n3. Program Info...\n";

		switch (_getch())
		{
		case 27: // Esc.
			inLoop = false;
			break;
		case '1':
			f_main();
			break;
		default:
			Msg();
			break;
		}


	}
}