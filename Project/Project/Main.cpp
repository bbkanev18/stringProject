// Include and Using::::::>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Header Files ::::::>
#include "FizzBuzz.h"
#include "HangMan.h"
#include "TickTackToe.h"
#include "MainFunctions.h"

// Structures ::::::>


// Functions - Declaration ::::::>
void gameMenu(string lock[]);

void mainMenu();

// Main ::::::>
int main()
{
	string lock[2] = { "lock","lock" };
	gameMenu(lock);
}

// Functions - Definition ::::::>
void gameMenu(string lock[])
{
	
	bool inLoop = true;
	while (inLoop)
	{
		system("CLS");

		titleMsg("Choose a game");
		cout << "Esc. Quit...\n1. FizzBuzz...\n2. Hangman...\n3. Tick Tack Toe...";
		//TODO add ticktacktoe option if it works :)

		switch (_getch())
		{
		case 27: // Esc.
			inLoop = false;
			break;
		case '1':
			f_main();
			break;
		case '2':
			h_main(lock);
			break;
		case '3':
			t_main();
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
		//TODO add an about us option
		//TODO add program info option


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